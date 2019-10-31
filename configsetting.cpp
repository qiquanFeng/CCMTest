#include "configsetting.h"
#include "importtable.h"

enum _HisDB_DataIndex{
	_HisDB_Index_Voltage			=	0,
	_HisDB_Index_Signal				=	1,
	_HisDB_Index_Image				=	2,
	_HisDB_Index_Awb				=	3,
	_HisDB_Index_Element			=	4,
	_HisDB_Index_I2C					=	5,
	_HisDB_Index_LastModify		=	6,
	_HisDB_Index_MIPI					=	7,
	_HisDB_Index_LSC				=	8,
	_HisDB_Index_FLIP				=	9,
	_HisDB_Index_MIRROR			=	10,
	_HisDB_Index_Light			=	11,
	_HisDB_Index_WhitePanel		=	20,
	_HisDB_Index_AFAMTF6480	=	40,
	_HisDB_Index_Current				=	80,
	_HisDB_Index_MTFNear				=	85,
	_HisDB_Index_MTFFar				=	95,
	_HisDB_Index_OTPBurn				=	120,
	_HisDB_Index_DPCRule               =150,
	_HisDB_Index_AFBurn					=	170,
	_HisDB_Index_SaveLog					=	220,
	_HisDB_Index_BlackField				=	250,
	_HisDB_Index_ChipID					=	300,
	_HisDB_Index_MTKPDAF				=	350,
	_HisDB_Index_SFRFACA					=	365,
	_HisDB_Index_DucalCamera            = 375,
	_HisDB_Index_AFCLpNearBasic		=	390,
	_HisDB_Index_AFCLpNearTactics		=	420,
	_HisDB_Index_AFCLpMiddleBasic		=	425,
	_HisDB_Index_AFCLpMiddleTactics	=	455,
	_HisDB_Index_AFCLpFarBasic			=	460,
	_HisDB_Index_AFCLpFarTactics		=	490,
	_HisDB_Index_AFCSFRANearBasic		=	700,
	_HisDB_Index_AFCSFRANearTactics		=	730,
	_HisDB_Index_AFCSFRAMiddleBasic		=	735,
	_HisDB_Index_AFCSFRAMiddleTactics		=	765,
	_HisDB_Index_AFCSFRAFarBasic			=	770,
	_HisDB_Index_AFCSFRAFarTactics			=	800,
	_HisDB_Index_AFCMTFNearBasic			=	805,
	_HisDB_Index_AFCMTFNearTactics			=	835,
	_HisDB_Index_AFCMTFMiddleBasic			=	840,
	_HisDB_Index_AFCMTFMiddleTactics		=	870,
	_HisDB_Index_AFCMTFFarBasic				=	875,
	_HisDB_Index_AFCMTFFarTactics			=	910,
	_HisDB_Index_MTFFA								=	915,
	_HisDB_Index_AutoFA								=	945,
	_HisDB_Index_AutoFAB								=	946,
	_HisDB_Index_BigVision							=	975,
	_HisDB_Index_OS_Total							=	1025,
	_HisDB_Index_OS_Positive						=	1035,
	_HisDB_Index_OS_Negtive						=	1135,
	_HisDB_Index_OS_Short							=	1235,
	_HisDB_Index_OS_Open							=	1335,
	_HisDB_Index_OS_Ohm							=	1435,
	_HisDB_Index_LightSourceCheck				=	1535,
	_HisDB_Index_Shortcut				=	5000,    //5000~9999
	_HisDB_Index_PreviewI2c			=	10000,   //10000~19999
	_HisDB_Index_CustomI2cG1		=	20000,
	_HisDB_Index_CustomI2cG2		=	30000,
	_HisDB_Index_CustomI2cG3		=	40000,
	_HisDB_Index_CustomI2cG4		=	50000,
	_HisDB_Index_CurrentIndex		=	60000,
	_HisDB_Index_LightSpecification	=	1536
};

configsetting::configsetting(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, itemprocess* classItemProcess2)
	: QDockWidget(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), classItemProcess(classItemProcess2)
{
	ui.setupUi(this);
	inextflag=0;

	ui.spiCSLow_checkBox->setVisible(false);
	ui.spiLittleEndian_checkBox->setVisible(false);

	ui.OStabWidget->setTabEnabled(1, false);
	ui.OStabWidget->setTabEnabled(3, false);
	ui.OStabWidget->setTabEnabled(4, false);

	uiHardwareVersion	=	0;
	if(classPlatform.HisFX3isopen())	classPlatform.HisFX3GetHardwareVersion(&uiHardwareVersion);

	std::vector<std::string> vecList;
	QStringList listStr;

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32";
#endif

	RolongogetSensorAPIVersion getSensorAPIVersion = (RolongogetSensorAPIVersion)(strLibPath, "getSensorAPIVersion");
	RolongogetMotorList getMotorList = (RolongogetMotorList)(QLibrary::resolve(strLibPath, "getMotorList"));

	if(!(getSensorAPIVersion && getMotorList)){
		ui.statuslabel->setText(tr("Resolve HisCCMSensor DLL Function Fail"));
	}
	else
	{
		getMotorList(vecList);		
		QString strText;
		for(int i=0;	i<vecList.size();	++i){
			strText	=	vecList.at(i).c_str();
			listStr.append(strText);
		}
		listStr.sort();
		ui.motorcomboBox->addItems(listStr);
	}


#if (defined _WIN64) && (defined _DEBUG)
	strLibPath	=	QDir::currentPath() % "/HisCCMOTP64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	strLibPath	=	QDir::currentPath() % "/HisCCMOTP64";
#elif (defined _WIN32) && (defined _DEBUG)
	strLibPath	=	QDir::currentPath() % "/HisCCMOTP32D";
#else
	strLibPath	=	QDir::currentPath() % "/HisCCMOTP32";
#endif

	RolongoOTPAPIVersion getRolongoOTPAPIVersion = (RolongoOTPAPIVersion)(QLibrary::resolve(strLibPath, "getRolongoOTPAPIVersion"));
	RolongogetAFList getAFList = (RolongogetAFList)(QLibrary::resolve(strLibPath, "getAFList"));
	RolongogetOTPList getOTPList = (RolongogetOTPList)(QLibrary::resolve(strLibPath, "getOTPList"));
	RolongogetQualcommPDAFList getQualcommPDAFList = (RolongogetQualcommPDAFList)(QLibrary::resolve(strLibPath, "getQualcommPDAFList"));
	RolongogetSONYPDAFList  getSONYPDAFList = (RolongogetSONYPDAFList)(QLibrary::resolve(strLibPath, "getSONYPDAFList"));
	RolongogetDualCameraBurnList  getDualCameraBurnList = (RolongogetDualCameraBurnList)(QLibrary::resolve(strLibPath, "getDualCameraBurnList"));
	RolongogetHISIPDAFList getHisiPDAFList = (RolongogetQualcommPDAFList)(QLibrary::resolve(strLibPath, "getHISIPDAFList"));
	
	if(!(getRolongoOTPAPIVersion && getAFList && getOTPList && getQualcommPDAFList&&getSONYPDAFList&&getDualCameraBurnList)){
		ui.statuslabel->setText(tr("Resolve HisCCMOTP DLL Function Fail"));
	}
	else
	{
		listStr.clear();
		getAFList(vecList);
		for(int x=0;	x<vecList.size();	++x){
			listStr.append(vecList.at(x).c_str());
		}
		listStr.sort();
		ui.afBurnGetFunListcomboBox->addItems(listStr);
		ui.mtkpdafAFBurnGetFunListcomboBox->addItems(listStr);

		listStr.clear();
		getOTPList(vecList);
		for(int x=0;	x<vecList.size();	++x)
			listStr.append(vecList.at(x).c_str());
		listStr.sort();
		ui.otpBurnGetFunListcomboBox->addItems(listStr);

		listStr.clear();
		getOTPList(vecList);
		for(int x=0;	x<vecList.size();	++x)
		{
			if(vecList.at(x).find("DEADPIXEL")!=std::string::npos)
			{listStr.append(vecList.at(x).c_str());}
		}		
		listStr.sort();
		ui.dpcrulechoosecomboBox->addItems(listStr);

		getQualcommPDAFList(vecList);
		listStr.clear();
		for(int x=0;	x<vecList.size();	++x)
			listStr.append(vecList.at(x).c_str());
		listStr.sort();
		ui.qualcommpdafBurnGetFunListcomboBox->addItems(listStr);

		vecList.clear();
		getSONYPDAFList(vecList);
		listStr.clear();
		for(int x=0;	x<vecList.size();	++x)
			listStr.append(vecList.at(x).c_str());
		listStr.sort();
		ui.SONYpdafBurnGetFunListcomboBox->addItems(listStr);

		vecList.clear();
		getHisiPDAFList(vecList);
		listStr.clear();
		for(int x=0;	x<vecList.size();	++x)
			listStr.append(vecList.at(x).c_str());
		listStr.sort();
		ui.HISIpdafBurnGetFunListcomboBox->addItems(listStr);

		listStr.clear();
		getDualCameraBurnList(vecList);
		for(int x=0;	x<vecList.size();	++x)
			listStr.append(vecList.at(x).c_str());
		listStr.sort();
		ui.dualcameraBurnGetFunListcomboBox->addItems(listStr);
	    ui.dualcameraCoaxialityBurnGetFunListcomboBox->addItems(listStr);
	}

	float flVoltMin, flVoltMax;
	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_AVDD, bChannel1)){
		ui.avddVoltcheckBox->setText("AVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.avddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.avddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.avddVoltcheckBox->setVisible(false);
		ui.avddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_DVDD, bChannel1)){
		ui.dvddVoltcheckBox->setText("DVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.dvddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.dvddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.dvddVoltcheckBox->setVisible(false);
		ui.dvddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_DOVDD, bChannel1)){
		ui.dovddVoltcheckBox->setText("DOVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.dovddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.dovddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.dovddVoltcheckBox->setVisible(false);
		ui.dovddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_IIC, bChannel1)){
		ui.ioddVoltcheckBox->setText("IODD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.ioddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.ioddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.ioddVoltcheckBox->setVisible(false);
		ui.ioddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_AF, bChannel1)){
		ui.afVoltcheckBox->setText("AF(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.afVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.afVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.afVoltcheckBox->setVisible(false);
		ui.afVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_OTP, bChannel1)){
		ui.otpVoltcheckBox->setText("OTP(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.vfuseVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.vfuseVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.otpVoltcheckBox->setVisible(false);
		ui.vfuseVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_POW, bChannel1)){
		ui.powVoltcheckBox->setText("POW(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.powVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.powVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.powVoltcheckBox->setVisible(false);
		ui.powVolt_doubleSpinBox->setVisible(false);
	}

	if(!classPlatform.isWorkCurrentSupported(_HisFX3_Platform_VlotOn_POW, bChannel1)){
		ui.checkBox_workcurrent_pow->setVisible(false);
		ui.groupBox_workcurrent_pow->setVisible(false);
	}

	if(!classPlatform.isStandbyCurrentSupported(_HisFX3_Platform_VlotOn_POW, bChannel1)){
		ui.checkBox_standbycurrent_pow->setVisible(false);
		ui.groupBox_standbycurrent_pow->setVisible(false);
	}

	std::vector<unsigned int> vecProtocalList;
	classPlatform.getProtocalSupported(vecProtocalList, bChannel1);
	for(unsigned int x=0;	x<vecProtocalList.size();	++x)
	{
		ui.mipilanecomboBox->addItem(HISGLOBALUI::protocal2String(vecProtocalList.at(x)));
	}

	if((classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X) && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R3X)
	{
		ui.mipiSignallabel->setVisible(false);
		ui.mipiSignalcomboBox->setVisible(false);
	}

	classPlatform.getMCLKSupported(flVoltMin,flVoltMax);
	ui.mclk_doubleSpinBox->setMinimum(flVoltMin);
	ui.mclk_doubleSpinBox->setMaximum(flVoltMax);

	createAutoFANodeTable();
#if !(defined USE_EQUIPMENT_AFM_JSL_V1)
	ui.focusAdjusttabWidget->setTabEnabled(3, false);
#else
	ui.afaMarkgroupBox->setVisible(false);
#endif


	ui.tcptimeoutlabel->setVisible(false);
	ui.timeoutspinBox->setVisible(false);





	ui.tabWidgetBurn->removeTab(4);


	std::vector<_HisFX3_BaylorMode> vecDataFormat;
	classPlatform.getDataFormatSupported(vecDataFormat);
	for(unsigned int x=0;	x<vecDataFormat.size();	++x)
	{
		ui.baylorcomboBox->addItem(HISGLOBALUI::dataformat2String(vecDataFormat[x]));
	}
	
	if((classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5) && \
		(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X) && \
		(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R3X))
	{
		ui.v5Volt_label->setVisible(false);
		ui.v5Volt_comboBox->setVisible(false);
	}

	if((classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5) && \
		(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X))
	{
		ui.v12Volt_label->setVisible(false);
		ui.v12Volt_comboBox->setVisible(false);
	}



	//MTF
	ui.mfamtfaFBGradelabel->setVisible(true);//2017-11-09 Update
	ui.mfamtfaFBGradecomboBox->setVisible(true);//2017-11-09 Update
	ui.mfamtfaFBCenterSpecDlabel->setVisible(true);
	ui.mfamtfaFBCenterSpecDdoubleSpinBox->setVisible(true);
	ui.mfamtfaFBCenterSpecClabel->setVisible(true);
	ui.mfamtfaFBCenterSpecCdoubleSpinBox->setVisible(true);
	ui.mfamtfaFBCenterSpecBlabel->setVisible(true);
	ui.mfamtfaFBCenterSpecBdoubleSpinBox->setVisible(true);
	ui.mfamtfaFBCenterSpecElabel->setVisible(true);
	ui.mfamtfaFBCenterSpecEdoubleSpinBox->setVisible(true);
	//MTF
	connect(ui.mfamtfaFBGradecomboBox, SIGNAL(currentIndexChanged (const QString &)), this, SLOT(slotMTFFABinGradeChanged(const QString &)));
	ui.mfamtfaFBCenterSpeclabel->setText(tr("Grade A:"));	
	ui.mfamtfaFBCenterWeightlabel->setVisible(false);
	ui.mfamtfaFBCenterWeightdoubleSpinBox->setVisible(false);
	ui.mfamtfaFBAutoSearchcheckBox->setVisible(false);
	ui.mfamtfaFBGradeMultiplelabel->setVisible(false);
	ui.mfamtfaFBGradeMultipledoubleSpinBox->setVisible(false);

	//SFR
	ui.mfasfraCenterMTF50GBHlabel->setVisible(false);
	ui.mfasfraCenterMTF50GBHdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GBVlabel->setVisible(false);
	ui.mfasfraCenterMTF50GBVdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GCHlabel->setVisible(false);
	ui.mfasfraCenterMTF50GCHdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GCVlabel->setVisible(false);
	ui.mfasfraCenterMTF50GCVdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GDHlabel->setVisible(false);
	ui.mfasfraCenterMTF50GDHdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GDVlabel->setVisible(false);
	ui.mfasfraCenterMTF50GDVdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GEHlabel->setVisible(false);
	ui.mfasfraCenterMTF50GEHdoubleSpinBox->setVisible(false);
	ui.mfasfraCenterMTF50GEVlabel->setVisible(false);
	ui.mfasfraCenterMTF50GEVdoubleSpinBox->setVisible(false);
	ui.mfasfraGradeNumlabel->setVisible(false);
	ui.mfasfraGradeNumcomboBox->setVisible(false);

	


if(!classPlatform.getDDRSupported())
{
	ui.DDR3_checkBox->setVisible(false);
	ui.virtualChannel_checkBox->setVisible(false);
}


	connect(ui.commuProtocalcomboBox, SIGNAL(currentIndexChanged (const QString &)), this, SLOT(slotCommProtocalChange(const QString &)));
	connect(ui.mipilanecomboBox, SIGNAL(currentIndexChanged (const QString &)), this, SLOT(slotDataProtocalChange(const QString &)));

	bool bFullPin = false;
	bool bOS = classPlatform.isOpenShortSupported(&bFullPin);
	if(!bFullPin) {ui.osa_TestOpencheckBox->setChecked(false); ui.osa_TestOpencheckBox->hide(); }
	createOpenShortTable();

	createlpAFCTable(ui.lpAFCFartableWidget);
	createlpAFCTable(ui.lpAFCMiddletableWidget);
	createlpAFCTable(ui.lpAFCNeartableWidget);
	createlpAFCTable(ui.lpFAtableWidget);

	createSFRAAFCTable(ui.afcsfraNBtableWidget);
	changeAFCNearSFRABasicMethod(0);
	createSFRAAFCTable(ui.afcsfraMBtableWidget);
	changeAFCMiddleSFRABasicMethod(0);
	createSFRAAFCTable(ui.afcsfraFBtableWidget);
	changeAFCFarSFRABasicMethod(0);
	createSFRAAFCTable(ui.mfasfratableWidget);
	changeMFASFRABasicMethod(0);

	createMTFAFCTable(ui.afcmtfaNBtableWidget);
	createMTFAFCTable(ui.afcmtfaMBtableWidget);
	createMTFAFCTable(ui.afcmtfaFBtableWidget);
	createMTFAFCTable(ui.mfamtfaFBtableWidget);

	SetCHIPIDComoBox();

	connect(ui.savepreviewpushButton, SIGNAL(released()), this, SLOT(savepreviewinfo()));

	connect(ui.saveBlemishpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveColorpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveDefectivepixelpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveOCpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveShadingpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveVignettingpushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	connect(ui.saveDefectLinepushButton,	SIGNAL(released()),	this, SLOT(savewhitepanelinfo()));
	
	connect(ui.checkBox_workcurrent_dovdd,	SIGNAL(clicked(bool)), this, SLOT(dovddWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_workcurrent_dvdd,	SIGNAL(clicked(bool)), this, SLOT(dvddWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_workcurrent_avdd,	SIGNAL(clicked(bool)), this, SLOT(avddWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_workcurrent_af,	SIGNAL(clicked(bool)), this, SLOT(afWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_workcurrent_vfuse,	SIGNAL(clicked(bool)), this, SLOT(vfuseWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_workcurrent_pow,	SIGNAL(clicked(bool)), this, SLOT(powWorkCurrentOnOffchecked(bool)));
	connect(ui.checkBox_standbycurrent_dovdd,	SIGNAL(clicked(bool)), this, SLOT(dovddStandbyCurrentOnOffchecked(bool)));
	connect(ui.checkBox_standbycurrent_dvdd,	SIGNAL(clicked(bool)), this, SLOT(dvddStandbyCurrentOnOffchecked(bool)));
	connect(ui.checkBox_standbycurrent_avdd,	SIGNAL(clicked(bool)), this, SLOT(avddStandbyCurrentOnOffchecked(bool)));
	connect(ui.checkBox_standbycurrent_af,	SIGNAL(clicked(bool)), this, SLOT(afStandbyCurrentOnOffchecked(bool)));
	connect(ui.checkBox_standbycurrent_pow,	SIGNAL(clicked(bool)), this, SLOT(powStandbyCurrentOnOffchecked(bool)));
	connect(ui.button_save_workcurrent, SIGNAL(released()), this, SLOT(saveCurrent()));

	connect(ui.osa_TestPositivecheckBox,	SIGNAL(toggled(bool)), this, SLOT(slotOSPositiveOnOff(bool)));
	connect(ui.osa_TestNegtivecheckBox,	SIGNAL(toggled(bool)), this, SLOT(slotOSNegtiveOnOff(bool)));
	connect(ui.osa_TestShortcheckBox,	SIGNAL(toggled(bool)), this, SLOT(slotOSShortTestOnOff(bool)));
	connect(ui.osa_TestOhmcheckBox,	SIGNAL(toggled(bool)), this, SLOT(slotOSResistanceOnOff(bool)));
	connect(ui.osa_TestOpencheckBox,	SIGNAL(toggled(bool)), this, SLOT(slotOSOpenTestOnOff(bool)));
	connect(ui.osSavepushButton, SIGNAL(released()), this, SLOT(saveOpenShort()));
	connect(ui.osa_ChannelcomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeOSTableName(const QString &)));
	
	connect(ui.afcmtfaNTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFNearTactics()));
	connect(ui.afcmtfaMTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFMiddleTactics()));
	connect(ui.afcmtfaFTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFFarTactics()));
	connect(ui.afcmtfaNBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFNearBasic()));
	connect(ui.afcmtfaMBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFMiddleBasic()));
	connect(ui.afcmtfaFBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCMTFFarBasic()));
	connect(ui.mfamtfaFBSavepushButton, SIGNAL(released()), this, SLOT(saveMFAMTFBasic()));

	connect(ui.AE_DBClear_pushButton, SIGNAL(released()), this, SLOT(clearDB_AE()));
	connect(ui.FC_DBClear_pushButton, SIGNAL(released()), this, SLOT(clearDB_FC()));

	connect(ui.otpBurnGetCurrentPrapushButton, SIGNAL(released()), this, SLOT(otpBurn2UI()));
	connect(ui.otpBurnGetDefaultParapushButton, SIGNAL(released()), this, SLOT(getdefaultotpBurn()));
	connect(ui.otpBurnSavepushButton, SIGNAL(released()), this, SLOT(saveotpBurn()));
	connect(ui.lightSourceCheckpushButton, SIGNAL(released()), this, SLOT(saveLightSourceCheck()));
	connect(ui.LightSpecificationpushButton,SIGNAL(released()), this, SLOT(saveLightSpecification()));

	connect(ui.afburnSavepushButton, SIGNAL(released()), this, SLOT(saveAFBurn()));
	connect(ui.savelogSavepushButton, SIGNAL(released()), this, SLOT(saveSaveLog()));
	connect(ui.saveBlackFieldpushButton, SIGNAL(released()), this, SLOT(saveBlackField()));
	connect(ui.mtkpdafLibVersioncomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeMTKPDAFVersion(const QString &)));
	connect(ui.mtkpdafSavepushButton, SIGNAL(released()), this, SLOT(saveMTKPDAFBurn()));
	connect(ui.afclpfarSaveBasicpushButton, SIGNAL(released()), this, SLOT(saveAFCLpFarBasic()));
	connect(ui.afclpnearSaveBasicpushButton, SIGNAL(released()), this, SLOT(saveAFCLpNearBasic()));
	connect(ui.afclpmiddleSaveBasicpushButton, SIGNAL(released()), this, SLOT(saveAFCLpMiddleBasic()));
	connect(ui.lpmfaSaveBasicpushButton, SIGNAL(released()), this, SLOT(saveLpMFA()));
	connect(ui.afclpaNTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCLpNearTactics()));
	connect(ui.afclpaMTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCLpMiddleTactics()));
	connect(ui.afclpaFTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCLpFarTactics()));

	connect(ui.slaveReplacepushButton, SIGNAL(released()), this, SLOT(RelaceSlave()));
	connect(ui.blemishcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(BlemishAlgSwitch(int)));
	connect(ui.defectpixelcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(DefectPixelAlgSwitch(int)));
	connect(ui.shadingcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(ShadingAlgSwitch(int)));
	connect(ui.occomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(OCAlgSwitch(int)));
	connect(ui.colorcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(WPColorAlgSwitch(int)));
	connect(ui.chipIDcomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(CHIPIDSwitch(const QString &)));

	connect(ui.blackFieldAlgcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(BlackLightPixelAlgSwitch(int)));
	connect(ui.lightSourceCheckcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(LightSourceCheckSwitch(int)));
	
	connect(ui.afcsfraNBMethodcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeAFCNearSFRABasicMethod(int)));
	connect(ui.afcsfraMBMethodcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeAFCMiddleSFRABasicMethod(int)));
	connect(ui.afcsfraFBMethodcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeAFCFarSFRABasicMethod(int)));
	connect(ui.mfasfraMethodcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMFASFRABasicMethod(int)));
	connect(ui.afcsfraNBUseF2checkBox, SIGNAL(stateChanged(int)), this, SLOT(AFCNearSFRABasicFreq2Checked(int)));
	connect(ui.afcsfraMBUseF2checkBox, SIGNAL(stateChanged(int)), this, SLOT(AFCMiddleSFRABasicFreq2Checked(int)));
	connect(ui.afcsfraFBUseF2checkBox, SIGNAL(stateChanged(int)), this, SLOT(AFCFarSFRABasicFreq2Checked(int)));
	connect(ui.mfasfraUseF2checkBox, SIGNAL(stateChanged(int)), this, SLOT(MFASFRABasicFreq2Checked(int)));
	connect(ui.afcsfraNBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRANearBasic()));
	connect(ui.afcsfraMBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRAMiddleBasic()));
	connect(ui.afcsfraFBSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRAFarBasic()));
	connect(ui.mfasfraSavepushButton, SIGNAL(released()), this, SLOT(saveMFASFRABasic()));
	connect(ui.afcsfraNTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRANearTactics()));
	connect(ui.afcsfraMTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRAMiddleTactics()));
	connect(ui.afcsfraFTSavepushButton, SIGNAL(released()), this, SLOT(saveAFCSFRAFarTactics()));

	connect(ui.afaSavepushButton, SIGNAL(released()), this, SLOT(saveAutoFA()));
	connect(ui.bfaSavepushButton, SIGNAL(released()), this, SLOT(saveAutoFA_B()));
	connect(ui.afaChartTypecomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(slotAFAChartChange(const QString &)));
	connect(ui.customIICSavepushButton, SIGNAL(released()), this, SLOT(saveALLCustomIIC()));
	//connect(ui.selectpushButton, SIGNAL(released() ), this, SLOT(textSelected()));
	connect(ui.nestpushButton, SIGNAL(released() ), this, SLOT(nextSelected()));
	connect(ui.ospselectallcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotospSelectall(int)));
	connect(ui.ospnotselectcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotospnotSelectall(int)));
	connect(ui.ospcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotospallchange(int)));
	connect(ui.osNegitveDOVDDcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotOSNegtiveDOVDDAllChange(int)));

	connect(ui.osnselectallcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotosnSelectall(int)));
	connect(ui.osnnotselectcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotosnnotSelectall(int)));
	connect(ui.oscselectallcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotoscSelectall(int)));
	connect(ui.oscnotselectcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotoscnotSelectall(int)));

	connect(ui.ortselectallcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotortSelectall(int)));
	connect(ui.ortnotselectcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotortnotSelectall(int)));
	connect(ui.oocselectallcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotoocSelectall(int)));
	connect(ui.oocnotselectcheckBox, SIGNAL(stateChanged(int)), this, SLOT(slotoocnotSelectall(int)));
	connect(ui.dualcmsavepushButton, SIGNAL(released()), this, SLOT(saveducalcameraBurn()));

	connect(ui.qualcommpdafLibVersioncomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(slotqualcommPDAFVersionChange(const QString &)));
	connect(ui.pdtypecomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(slotqualcommPDAFsensortypeChange(const QString &)));
	connect(ui.pdafPlatformcomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotPDAFplatformChange(int)));

	connect(ui.dpcsavepushButton, SIGNAL(released()), this, SLOT(saveDPCLoadRule()));

	freshDB_AE();
	freshDB_FC();

	previewData2UI();
	ccmData2UI();
	whitepanel2UI();
	blackpanel2UI();
	lightSourceCheck2UI();
	LightSpecification2UI();
	otpBurn2UI();
	afBurn2UI();
	pdafBurn2UI();
	logData2UI();
	customIIC2UI();
	workCurrent2UI();
	standbyCurrent2UI();
	openshort2UI();
	afcMTFBasic2UI(0);
	afcMTFBasic2UI(1);
	afcMTFBasic2UI(2);
	afcMTFBasic2UI(3);
	afcMTFTactics2UI(0);
	afcMTFTactics2UI(1);
	afcMTFTactics2UI(2);
	afcSFRABasic2UI(0);
	afcSFRABasic2UI(1);
	afcSFRABasic2UI(2);
	afcSFRABasic2UI(3);
	afcSFRATactics2UI(0);
	afcSFRATactics2UI(1);
	afcSFRATactics2UI(2);
	afcLpBasic2UI(0);
	afcLpBasic2UI(1);
	afcLpBasic2UI(2);
	afcLpBasic2UI(3);
	afcLpATactics2UI(0);
	afcLpATactics2UI(1);
	afcLpATactics2UI(2);
	autoFA2UI();
	autoFA2UI_B();
	ducalcameraBurn2UI();
	getCurrentIndex();
	DPCRULE2UI();
}

configsetting::~configsetting()
{
	saveCurrentIndex();
	vectorListosp.clear();
	vectorListosn.clear();
	vectorListosc.clear();
	vectorListort.clear();
	vectorListooc.clear();
	vectorListcmbosp.clear();
}

void configsetting::previewData2UI()
{
	classItemProcess->getpreviewParameter(true, false);
	if(!itemshareData.previewParameter) return;

	ui.avddVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_AVDD * 0.1);
	ui.dvddVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_DVDD * 0.1);
	ui.dovddVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_DOVDD * 0.1);
	ui.ioddVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_IODD * 0.1);
	ui.afVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_AF * 0.1);
	ui.vfuseVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_VFuse * 0.1);
	ui.powVolt_doubleSpinBox->setValue(itemshareData.previewParameter->ucVolt_POW * 0.1);
	ui.v5Volt_comboBox->setCurrentIndex(itemshareData.previewParameter->ucVolt_5V);
	ui.v12Volt_comboBox->setCurrentIndex(itemshareData.previewParameter->ucVolt_12V);

	ui.avddVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_AVDD);
	ui.dvddVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_DVDD);
	ui.dovddVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_DOVDD);
	ui.ioddVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_IIC);
	ui.afVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_AF);
	ui.otpVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_OTP);
	ui.powVoltcheckBox->setChecked(itemshareData.previewParameter->uiVoltSetFlag & _HisFX3_Platform_VlotOn_POW);

	ui.resetcheckBox->setChecked(itemshareData.previewParameter->bIsSetRST);
	ui.resetcomboBox->setCurrentIndex(!itemshareData.previewParameter->bReset_ActiveLow);
	ui.pwdncheckBox->setChecked(itemshareData.previewParameter->bIsSetPWDN);
	ui.pwndcomboBox->setCurrentIndex(!itemshareData.previewParameter->bPWND_ActiveLow);
	ui.mclkcheckBox->setChecked(itemshareData.previewParameter->bIsSetMCLK);
	ui.mclk_doubleSpinBox->setValue(itemshareData.previewParameter->flMCLK);
	ui.mipilanecomboBox->setCurrentIndex(ui.mipilanecomboBox->findText(HISGLOBALUI::protocal2String(itemshareData.previewParameter->ucMIPILane), Qt::MatchFixedString));
	ui.mipiSignalcomboBox->setCurrentIndex(itemshareData.previewParameter->ucSignalMode - 1);

	ui.vsync_checkBox->setChecked(itemshareData.previewParameter->bDVP_VS_ActiveHigh);
	ui.dvpDataLinecomboBox->setCurrentIndex(itemshareData.previewParameter->ucDVP_LineFormat);
	ui.dvpPhaseShiftcomboBox->setCurrentIndex(itemshareData.previewParameter->ucDVP_PhaseShift);

	ui.outpueXVSXHScheckBox->setChecked(itemshareData.previewParameter->bOutputXSVS);
	ui.XHSspinBox->setValue(itemshareData.previewParameter->uiLVDS_XHS);
	ui.XVSpinBox->setValue(itemshareData.previewParameter->uiLVDS_XVS);
	ui.lvdsAlignL0checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x1);
	ui.lvdsAlignL1checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x2);
	ui.lvdsAlignL2checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x4);
	ui.lvdsAlignL3checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x8);
	ui.lvdsAlignL4checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x10);
	ui.lvdsAlignL5checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x20);
	ui.lvdsAlignL6checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x40);
	ui.lvdsAlignL7checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x80);
	ui.lvdsAlignL8checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x100);
	ui.lvdsAlignL9checkBox->setChecked(itemshareData.previewParameter->usLVDSAlign & 0x200);

	ui.baylorcomboBox->setCurrentIndex(ui.baylorcomboBox->findText(HISGLOBALUI::dataformat2String(itemshareData.previewParameter->ucDataFormat), Qt::MatchFixedString));
	ui.imageWidth_spinBox->setValue(itemshareData.previewParameter->iWidth);
	ui.imageHeight_spinBox->setValue(itemshareData.previewParameter->iHeight);
	ui.dummyTopspinBox->setValue(itemshareData.previewParameter->uiDummyTop);
	ui.dummyBottomspinBox->setValue(itemshareData.previewParameter->uiDummyBottom);
	ui.dummyLeftspinBox->setValue(itemshareData.previewParameter->uiDummyLeft);
	ui.dummyRightspinBox->setValue(itemshareData.previewParameter->uiDummyRight);

	ui.outputErrorFramecheckBox->setChecked(threadshareData.bOutputErrorFrame);

	ui.commuProtocalcomboBox->setCurrentIndex(itemshareData.previewParameter->ucCommProtocal);
	ui.iicIntervalTimespinBox->setValue(itemshareData.previewParameter->usI2CIntervalTime);
	ui.i2cspeedspinBox->setValue(itemshareData.previewParameter->usI2CSpeed);

	ui.ExposurecheckBox->setChecked(threadshareData.bIsexposure);
	if(threadshareData.bIsexposure)	ui.ExposurespinBox->setValue(threadshareData.flExposure);
	ui.AnalogGaincheckBox->setChecked(threadshareData.bSetGlobalGain);
	ui.AnalogGaindoubleSpinBox->setValue(threadshareData.flGlobalGainValue);
	ui.preivewWaitFramespinBox->setValue(threadshareData.usWaitPreviewDataTime);
	ui.interpolationcomboBox->setCurrentIndex(threadshareData.ucInterpolation);
	ui.grayImagecheckBox->setChecked(threadshareData.bGrayImage);

	ui.spiCSLow_checkBox->setChecked(itemshareData.previewParameter->bSPICSLow);
	ui.spiLittleEndian_checkBox->setChecked(itemshareData.previewParameter->bSPILittleEndian);
	ui.sensorACKcheckBox->setChecked(itemshareData.previewParameter->bCheckDeviceAck);
	ui.DDR3_checkBox->setChecked(itemshareData.previewParameter->bUseDDR);
	ui.virtualChannel_checkBox->setChecked(itemshareData.previewParameter->bVirtualChannel);
	ui.laneNumberspinBox->setValue(itemshareData.previewParameter->ucLaneNum);

	ui.previewi2cplainTextEdit->clear();
	QString strI2CItem, strSlave, strReg, strData, strType;;
	for(unsigned int x=0;	x<itemshareData.previewParameter->usI2CCount;	++x)
	{
		ROPLOW::hex2QString(strSlave, itemshareData.previewParameter->pucSlave[x], 0x08);
		ROPLOW::hex2QString(strReg, itemshareData.previewParameter->puiReg[x], (itemshareData.previewParameter->pusType[x] >> 8));
		ROPLOW::hex2QString(strData, itemshareData.previewParameter->pui64Data[x], (itemshareData.previewParameter->pusType[x] & 0xFF));
		ROPLOW::hex2QString(strType, itemshareData.previewParameter->pusType[x], 0x16);
		strI2CItem	=	strSlave % "," % strReg % "," % strData % "," % strType;
		ui.previewi2cplainTextEdit->appendPlainText(strI2CItem);
	}
}

int configsetting::savePreviewData()
{
	int iresult	=	0;

	if(ui.mipilanecomboBox->currentIndex() < 0)
	{
		ui.statuslabel->setText(tr("Interface Not Selected"));
		return HisFX3Error_Parameter;
	}

	if(ui.baylorcomboBox->currentIndex() < 0)
	{
		ui.statuslabel->setText(tr("Image Format Not Selected"));
		return HisFX3Error_Parameter;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QStringList strname, strvalue;
		QString strData;
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QSqlQuery query(stSqlDB);

			stSqlDB.transaction();
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "voltage");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "signal");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "image");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "mipi");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, \
				"platform", "awb");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, \
				"platform", "light");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, \
				"platform", "lsc");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "i2c");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "preview_i2c");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, \
				"platform", "sensor", "otheradd");
			stSqlDB.commit();

			stSqlDB.transaction();

			unsigned int uiIndex	=	_HisDB_Index_Voltage;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "dovdd", ui.dovddVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "dvdd", ui.dvddVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "avdd", ui.avddVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "af", ui.afVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "vfuse", ui.vfuseVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "iodd",ui.ioddVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "pow", ui.powVolt_doubleSpinBox->value() *10.0);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "v5", ui.v5Volt_comboBox->currentIndex());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "v12", ui.v12Volt_comboBox->currentIndex());
			unsigned int uiVoltFlag = 0x0;
			if(ui.avddVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_AVDD;
			if(ui.dvddVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_DVDD;
			if(ui.dovddVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_DOVDD;
			if(ui.ioddVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_IIC;
			if(ui.afVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_AF;
			if(ui.otpVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_OTP;
			if(ui.powVoltcheckBox->isChecked()) uiVoltFlag |= _HisFX3_Platform_VlotOn_POW;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "voltage", QVariant(), "voltflag", uiVoltFlag);

			uiIndex	=	_HisDB_Index_Signal;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "signal", QVariant(), "reset_activedlow", (ui.resetcomboBox->currentIndex())?(0):(1));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "signal", QVariant(), "pwnd_activedlow", (ui.pwndcomboBox->currentIndex())?(0):(1));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "signal", QVariant(), "mclk", ui.mclk_doubleSpinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "signal", (ui.resetcheckBox->isChecked())?(1):(0), "signalflag", (ui.pwdncheckBox->isChecked())?(1):(0), (ui.mclkcheckBox->isChecked())?(1):(0));

			uiIndex	=	_HisDB_Index_Image;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "data_format", ui.baylorcomboBox->currentText());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "width",ui.imageWidth_spinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "height", ui.imageHeight_spinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "dummy_left", ui.dummyLeftspinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "dummy_right", ui.dummyRightspinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "dummy_top", ui.dummyTopspinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "image", QVariant(), "dummy_bottom", ui.dummyBottomspinBox->value());

			uiIndex	=	_HisDB_Index_MIPI;
			strname.clear(); strvalue.clear();
			strname.append("dvpdataline");strvalue.append(QString::number(ui.dvpDataLinecomboBox->currentIndex()));
			strname.append("dvpps");strvalue.append(QString::number(ui.dvpPhaseShiftcomboBox->currentIndex()));
			ROPLOW::jointconfigstring(strData, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "mipi", strData, "lane", HISGLOBALUI::protocal2UInt(ui.mipilanecomboBox->currentText()), (ui.vsync_checkBox->isChecked())?("high"):("low"));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "mipi", QVariant(), "lvds_outputxhsvhs", (ui.outpueXVSXHScheckBox->isChecked())?("true"):("false"));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "mipi", QVariant(), "xhsvhs_value", ui.XHSspinBox->value(), ui.XVSpinBox->value());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "mipi", QVariant(), "signal mode", ui.mipiSignalcomboBox->currentIndex()+1);
			unsigned short usLVDSAlign = 0x0;
			if(ui.lvdsAlignL0checkBox->isChecked()) usLVDSAlign |= 0x1;
			if(ui.lvdsAlignL1checkBox->isChecked()) usLVDSAlign |= 0x2;
			if(ui.lvdsAlignL2checkBox->isChecked()) usLVDSAlign |= 0x4;
			if(ui.lvdsAlignL3checkBox->isChecked()) usLVDSAlign |= 0x8;
			if(ui.lvdsAlignL4checkBox->isChecked()) usLVDSAlign |= 0x10;
			if(ui.lvdsAlignL5checkBox->isChecked()) usLVDSAlign |= 0x20;
			if(ui.lvdsAlignL6checkBox->isChecked()) usLVDSAlign |= 0x40;
			if(ui.lvdsAlignL7checkBox->isChecked()) usLVDSAlign |= 0x80;
			if(ui.lvdsAlignL8checkBox->isChecked()) usLVDSAlign |= 0x100;
			if(ui.lvdsAlignL9checkBox->isChecked()) usLVDSAlign |= 0x200;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "mipi", QVariant(), "lvds_align_set", usLVDSAlign);

			uiIndex	=	_HisDB_Index_Light;
			strname.clear();	strvalue.clear();
			strname.append("exposureswitch");
			if(ui.ExposurecheckBox->isChecked())	strvalue.append("open");
			else	strvalue.append("close");
			strname.append("exposurevalue");strvalue.append(QString::number(ui.ExposurespinBox->value(), 'f', 2));

			strname.append("analoggainswitch");
			if(ui.AnalogGaincheckBox->isChecked())	strvalue.append("open");
			else	strvalue.append("close");
			strname.append("analoggainvalue");strvalue.append(QString::number(ui.AnalogGaindoubleSpinBox->value()));
			strname.append("waitdata");strvalue.append(ui.preivewWaitFramespinBox->cleanText());
			strname.append("outputerrorframe");strvalue.append((ui.outputErrorFramecheckBox->isChecked())?("true"):("false"));
			strname.append("interpolation"); strvalue.append(QString::number(ui.interpolationcomboBox->currentIndex()));
			strname.append("tograyimage"); strvalue.append((ui.grayImagecheckBox->isChecked())?("1"):("0"));
			ROPLOW::jointconfigstring(strData, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "light", strData);
		
			uiIndex		=	_HisDB_Index_I2C;
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "i2c",ui.iicIntervalTimespinBox->value(), "speed", ui.i2cspeedspinBox->value(), ui.commuProtocalcomboBox->currentIndex());

			strname.clear(); strvalue.clear();
			strname.append("spicslow"); strvalue.append((ui.spiCSLow_checkBox->isChecked())?("1"):("0"));
			strname.append("spilittileendian"); strvalue.append((ui.spiLittleEndian_checkBox->isChecked())?("1"):("0"));
			strname.append("checkdeviceack"); strvalue.append((ui.sensorACKcheckBox->isChecked())?("1"):("0"));
			strname.append("ddr3"); strvalue.append((ui.DDR3_checkBox->isChecked())?("1"):("0"));
			strname.append("virtualchannel"); strvalue.append((ui.virtualChannel_checkBox->isChecked())?("1"):("0"));
			strname.append("lanenumber"); strvalue.append(ui.laneNumberspinBox->cleanText());
			ROPLOW::jointconfigstring(strData, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "sensor", "otheradd", strData);

			uiIndex	=	_HisDB_Index_PreviewI2c;
			QString strtext	=	ui.previewi2cplainTextEdit->toPlainText() % "\n";
			QString strdata, strdata2;
			int iindex1, iindex2, iindex3, imax, imin;
			if(strtext.size() > 9)
			{
				QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
				if(lines.size() > 0)
				{
					int isize	=	lines.size();
					for(int i=0;	i<isize;	++i)
					{
						strdata	=	lines.at(i);
						strdata	=	strdata.toLower();
						if(strdata.count("0x") > 3 && strdata.count(",") > 2)
						{
							iindex1 = strdata.indexOf("/");
							iindex2	=	strdata.indexOf("\\");
							iindex3	=	strdata.indexOf(";");
							if((iindex1 < 0 || iindex1 > 9) && (iindex2 < 0 || iindex2 > 9) && (iindex3 < 0 || iindex3 > 9))
							{
								strdata2	=	"";
								imax			=	(iindex1 > iindex2)?(iindex1):(iindex2);
								imax			=	(iindex3 > imax)?(iindex3):(imax);
								if(imax > 0){
									imin	=	0xFFFF;
									imin	=	(iindex1 < 0)?(imin):((iindex1<imin)?(iindex1):(imin));
									imin	=	(iindex2 < 0)?(imin):((iindex2<imin)?(iindex2):(imin));
									imin	=	(iindex3 < 0)?(imin):((iindex3<imin)?(iindex3):(imin));
									strdata2	=	strdata.right(strdata.size() - imin -1);
									strdata2	=	strdata2.trimmed();
									strdata		=	strdata.left(imin);
									strdata		=	strdata.trimmed();
									strdata		=	strdata.remove(" ");
									strdata		=	strdata.remove("\t");
									strdata		=	strdata.remove("\r");
									if(strdata.count("0x") == 4 && strdata.count(",") == 3){
										HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "platform", "sensor", "preview_i2c",QVariant(), QVariant(), strdata, QVariant(), strdata2);
									}
								}
								else
								{
									strdata		=	strdata.trimmed();
									strdata		=	strdata.remove(" ");
									strdata		=	strdata.remove("\t");
									strdata		=	strdata.remove("\r");
									if(strdata.count("0x") == 4 && strdata.count(",") == 3){
										HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "platform", "sensor", "preview_i2c",QVariant(), QVariant(), strdata, QVariant(), strdata2);
									}
								}
							}
						}
					}
				}
			}

			stSqlDB.commit();

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::ccmData2UI()
{
	classItemProcess->getccmhardwareParameter(true, false);
	if(!itemshareData.ccmhardwareParameter) return;

	ui.projectlineEdit->setText(itemshareData.ccmhardwareParameter->projectname);
	//ui.machinetypelineEdit->setText(itemshareData.ccmhardwareParameter->machinetype);
	ui.sensorlineEdit->setText(itemshareData.ccmhardwareParameter->sensortype);
	ui.is4CellcheckBox->setChecked(itemshareData.ccmhardwareParameter->b4Cell);
	ui.powerONcomboBox->setCurrentIndex(ui.powerONcomboBox->findText(HISGLOBALUI::poweron2String(itemshareData.ccmhardwareParameter->uiSensorFactory), Qt::MatchFixedString));
	ui.lenslineEdit->setText(itemshareData.ccmhardwareParameter->lenstype);
	ui.motorcomboBox->setCurrentIndex(ui.motorcomboBox->findText(itemshareData.ccmhardwareParameter->motortype, Qt::MatchFixedString));
	ui.checkFrameRightcheckBox->setChecked(itemshareData.ccmhardwareParameter->bCheckFrameRight);
	ui.EESlaveEdit->setText(QString::number(itemshareData.ccmhardwareParameter->ucEESlave, 16));
	ui.opddoubleSpinBox->setValue(itemshareData.ccmhardwareParameter->dopd);
	ui.wdrdoubleSpinBox->setValue(itemshareData.ccmhardwareParameter->dwdr);
	ui.actualdoubleSpinBox->setValue(itemshareData.ccmhardwareParameter->dactual);
}

int configsetting::saveCCMData()
{
	int iresult	=	0;
	if(ui.projectlineEdit->text().trimmed().isEmpty())
	{
		ui.statuslabel->setText(tr("Project Name Not Set"));
		return HisFX3Error_Parameter;
	}
// 	if(ui.machinetypelineEdit->text().trimmed().isEmpty())
// 	{
// 		ui.statuslabel->setText(tr("Machine type Not Set"));
// 		return HisFX3Error_Parameter;
// 	}
	if(ui.sensorlineEdit->text().trimmed().isEmpty())
	{
		ui.statuslabel->setText(tr("Sensor Type Not Set"));
		return HisFX3Error_Parameter;
	}

	if(ui.motorcomboBox->currentIndex() < 0)
	{
		ui.statuslabel->setText(tr("Driver IC Not Selected"));
		return HisFX3Error_Parameter;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "platform", "ccm", "element");

			unsigned int uiIndex	=	_HisDB_Index_Element;
			stSqlDB.transaction();

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "project_name", ui.projectlineEdit->text().trimmed());
			//HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "machinetype", ui.machinetypelineEdit->text().trimmed());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "sensor_type", ui.sensorlineEdit->text().trimmed(), (unsigned int)(ui.is4CellcheckBox->isChecked()));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "lens_type", ui.lenslineEdit->text().trimmed());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "motor_type", ui.motorcomboBox->currentText().trimmed());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "ee_slave", ui.EESlaveEdit->text().trimmed());
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "sensorfactory", HISGLOBALUI::poweron2UInt(ui.powerONcomboBox->currentText()), (unsigned int)(ui.checkFrameRightcheckBox->isChecked()));

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "opd", QVariant(ui.opddoubleSpinBox->value()));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "wdr", QVariant(ui.wdrdoubleSpinBox->value()));
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "platform", "ccm", "element", QVariant(), "actual", QVariant(ui.actualdoubleSpinBox->value()));
			stSqlDB.commit();

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::savepreviewinfo()
{
	int iresult	=	savePreviewData();
	if(iresult) QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	previewData2UI();

	if(iresult = saveCCMData()) QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	ccmData2UI();
}

void configsetting::whitepanel2UI()
{
	classItemProcess->getwhitePanelColorParameter(true);
	classItemProcess->getwhitePanelOCParameter(true);
	classItemProcess->getwhitePanelDefectLineParameter(true);
	classItemProcess->getwhitePanelDefectPixelParameter(true);
	classItemProcess->getwhitePanelShadingParameter(true);
	classItemProcess->getwhitePanelVignettingParameter(true);
	classItemProcess->getBlemishParameter(true);

	if(itemshareData.blemishParameter)
	{
		ui.blemishRangelineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHA.blemish_flrange));
		ui.blemishHighPassspinBox->setValue(itemshareData.blemishParameter->stBlemishHA.blemish_ihighpass);
		ui.blemishLowPassspinBox->setValue(itemshareData.blemishParameter->stBlemishHA.blemish_ilowpass);
		ui.blemishAmplitudespinBox->setValue(itemshareData.blemishParameter->stBlemishHA.blemish_iamplitude);
		ui.blemishDevspinBox->setValue(itemshareData.blemishParameter->stBlemishHA.blemish_idev);
		ui.blemishA_Corner_lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHA.blemish_corner));

		ui.blemishhbMoveDefectcheckBox->setChecked(itemshareData.blemishParameter->stBlemishHB.blemishhb_RemoveDefectPixel);
		ui.blmeishBCenterRangelineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Range, 'f', 2));
		ui.blmeishBFramespinBox->setValue(itemshareData.blemishParameter->stBlemishHB.frames);
		ui.blmeishBZone3XspinBox->setValue(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3X);
		ui.blmeishBZone3YspinBox->setValue(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Y);
		ui.blmeishBZ1R1lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[0], 'f', 4));
		ui.blmeishBZ1R2lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[1], 'f', 4));
		ui.blmeishBZ1R3lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[2], 'f', 4));
		ui.blmeishBZ1R4lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[3], 'f', 4));
		ui.blmeishBZ1R5lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[4], 'f', 4));
		ui.blmeishBZ1R6lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[5], 'f', 4));
		ui.blmeishBZ1R7lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[6], 'f', 4));
		ui.blmeishBZ1R8lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[7], 'f', 4));
		ui.blmeishBZ1R9lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[8], 'f', 4));
		ui.blmeishBZ1R10lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[9], 'f', 4));
		ui.blmeishBZ1R11lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[10], 'f', 4));
		ui.blmeishBZ1R12lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[11], 'f', 4));
		ui.blmeishBZ1R13lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[12], 'f', 4));
		ui.blmeishBZ1R14lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[13], 'f', 4));
		ui.blmeishBZ1R15lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone1Spec[14], 'f', 4));
		ui.blmeishBZ2R1lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[0], 'f', 4));
		ui.blmeishBZ2R2lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[1], 'f', 4));
		ui.blmeishBZ2R3lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[2], 'f', 4));
		ui.blmeishBZ2R4lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[3], 'f', 4));
		ui.blmeishBZ2R5lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[4], 'f', 4));
		ui.blmeishBZ2R6lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[5], 'f', 4));
		ui.blmeishBZ2R7lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[6], 'f', 4));
		ui.blmeishBZ2R8lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[7], 'f', 4));
		ui.blmeishBZ2R9lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[8], 'f', 4));
		ui.blmeishBZ2R10lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[9], 'f', 4));
		ui.blmeishBZ2R11lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[10], 'f', 4));
		ui.blmeishBZ2R12lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[11], 'f', 4));
		ui.blmeishBZ2R13lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[12], 'f', 4));
		ui.blmeishBZ2R14lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[13], 'f', 4));
		ui.blmeishBZ2R15lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone2Spec[14], 'f', 4));
		ui.blmeishBZ3R1lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[0], 'f', 4));
		ui.blmeishBZ3R2lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[1], 'f', 4));
		ui.blmeishBZ3R3lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[2], 'f', 4));
		ui.blmeishBZ3R4lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[3], 'f', 4));
		ui.blmeishBZ3R5lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[4], 'f', 4));
		ui.blmeishBZ3R6lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[5], 'f', 4));
		ui.blmeishBZ3R7lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[6], 'f', 4));
		ui.blmeishBZ3R8lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[7], 'f', 4));
		ui.blmeishBZ3R9lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[8], 'f', 4));
		ui.blmeishBZ3R10lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[9], 'f', 4));
		ui.blmeishBZ3R11lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[10], 'f', 4));
		ui.blmeishBZ3R12lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[11], 'f', 4));
		ui.blmeishBZ3R13lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[12], 'f', 4));
		ui.blmeishBZ3R14lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[13], 'f', 4));
		ui.blmeishBZ3R15lineEdit->setText(QString::number(itemshareData.blemishParameter->stBlemishHB.blemishhb_Zone3Spec[14], 'f', 4));

		ui.blemishhcAreaMindoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.flAreaMin);
		ui.blemishhcFramespinBox->setValue(itemshareData.blemishParameter->stBlemishHC.frames);
		ui.blemishhcAreaMaxdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.flAreaMax);
		ui.blemishhcEdgeZonedoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.flEdgeZone);
		ui.blemishhcCornerZonedoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.flCornerZone);
		ui.blemishhcTuningdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.flTuning);
		ui.blemishhcZ1BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[0].flLux);
		ui.blemishhcZ2BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[1].flLux);
		ui.blemishhcZ3BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[2].flLux);
		ui.blemishhcZ4BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[3].flLux);
		ui.blemishhcZ5BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[4].flLux);
		ui.blemishhcZ6BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[5].flLux);
		ui.blemishhcZ7BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[6].flLux);
		ui.blemishhcZ8BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[7].flLux);
		ui.blemishhcZ9BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[8].flLux);
		ui.blemishhcZ10BdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[9].flLux);
		ui.blemishhcEdgeBdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[10].flLux);
		ui.blemishhcCornerBdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHC.stSpec[11].flLux);

		ui.blemishdRawInfolineEdit->setText(itemshareData.blemishParameter->stBlemishHD.strRawInfo);
		ui.blemishdOptionlineEdit->setText(itemshareData.blemishParameter->stBlemishHD.strOptionBin);
		ui.blemishdMaxEdgeDiffdoubleSpinBox->setValue(itemshareData.blemishParameter->stBlemishHD.dflMaxEdgeDiff);

		ui.blemishcomboBox->setCurrentIndex(itemshareData.blemishParameter->blemishAlg);
		BlemishAlgSwitch(itemshareData.blemishParameter->blemishAlg);
	}

	if(itemshareData.wpOCParameter)
	{
		ui.ocPixelRatiolineEdit->setText(QString::number(itemshareData.wpOCParameter->stAlgHA.oc_flpixelratio));
		ui.ocDeviationlineEdit->setText(QString::number(itemshareData.wpOCParameter->stAlgHA.oc_fldeviation, 'f', 0));

		ui.ochbSizeRatiodoubleSpinBox->setValue(itemshareData.wpOCParameter->stAlgHB.oc_flpixelratio);
		ui.ochbDevspinBox->setValue(itemshareData.wpOCParameter->stAlgHB.oc_fldeviation);

		ui.occomboBox->setCurrentIndex(itemshareData.wpOCParameter->opticalcenterAlg);
	}

	if(itemshareData.wpShadingParameter)
	{
		ui.shadingHAROIWdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHA.flRatioW);
		ui.shadingHAROIHdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHA.flRatioH);
		ui.shadingHAMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHA.flShadingSpecMin);
		ui.shadingHAMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHA.flShadingSpecMax);
		ui.shadingHADevdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHA.flShadingSpecDev);
		if(itemshareData.wpShadingParameter->stShadingConfigHA.imgChannel == _HisCCMAlg_ImageBuffer_Channel_R) ui.shadingHAChannelcomboBox->setCurrentIndex(0);
		else if(itemshareData.wpShadingParameter->stShadingConfigHA.imgChannel == _HisCCMAlg_ImageBuffer_Channel_Gr) ui.shadingHAChannelcomboBox->setCurrentIndex(1);
		else if(itemshareData.wpShadingParameter->stShadingConfigHA.imgChannel == _HisCCMAlg_ImageBuffer_Channel_Gb) ui.shadingHAChannelcomboBox->setCurrentIndex(1);
		else if(itemshareData.wpShadingParameter->stShadingConfigHA.imgChannel == _HisCCMAlg_ImageBuffer_Channel_B) ui.shadingHAChannelcomboBox->setCurrentIndex(2);
		else ui.shadingHAChannelcomboBox->setCurrentIndex(3);

		ui.shadingHBMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flShadingSpecMin);
		ui.shadingHBMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flShadingSpecMax);
		ui.shadingHBDevdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flShadingSpecDev);
		ui.shadingHBYYOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flYYOffset);
		ui.shadingHBRGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecRGMin);
		ui.shadingHBRGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecRGMax);
		ui.shadingHBRGOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flRGOffset);
		ui.shadingHBBGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecBGMin);
		ui.shadingHBBGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecBGMax);
		ui.shadingHBBGOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flBGOffset);
		ui.shadingHBPPMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecPPMin);
		ui.shadingHBPPMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flSpecPPMax);
		ui.shadingHBPPOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHB.flPPOffset);

		ui.shadinghcRawBinlineEdit->setText(itemshareData.wpShadingParameter->stShadingConfigHC.strRawInfo);
		ui.shadinghcLightBinlineEdit->setText(itemshareData.wpShadingParameter->stShadingConfigHC.strLightSource);
		ui.shadinghcTuneGainBinlineEdit->setText(itemshareData.wpShadingParameter->stShadingConfigHC.strTuneGain);
		ui.shadinghcYMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flYMin);
		ui.shadinghcYMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flYMax);
		ui.shadinghcYOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flYOffset);
		ui.shadinghcRGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flRGMin);
		ui.shadinghcRGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flRGMax);
		ui.shadinghcRGOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flRGOffset);
		ui.shadinghcBGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flBGMin);
		ui.shadinghcBGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flBGMax);
		ui.shadinghcBGOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flBGOffset);
		ui.shadinghcPPMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flPPMin);
		ui.shadinghcPPMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flPPMax);
		ui.shadinghcPPOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flPPOffset);
		ui.shadinghcCornerMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flCornerMin);
		ui.shadinghcCornerMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flCornerMax);
		ui.shadinghcCornerOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flCornerOffset);
		ui.shadinghcVignetMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flVignetMin);
		ui.shadinghcVignetMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flVignetMax);
		ui.shadinghcVignetOffsetdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHC.flVignetOffset);

		ui.shadinghdBlockWspinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.usBlockW);
		ui.shadinghdBlockHspinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.usBlockH);
		ui.shadinghdPPYMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_YMin);
		ui.shadinghdPPYMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_YMax);
		ui.shadinghdPPRGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_RGMin);
		ui.shadinghdPPRGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_RGMax);
		ui.shadinghdPPBGMindoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_BGMin);
		ui.shadinghdPPBGMaxdoubleSpinBox->setValue(itemshareData.wpShadingParameter->stShadingConfigHD.flPP_BGMax);

		//******************** fengqiquan 2018/01/16 *******************
		ui.doubleSpinBox_LscRoiSize->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_fRoiSize);
		ui.spinBox_LscBlackLevel->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_iBlackLevel);
		ui.doubleSpinBox_LscDiff->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_fYDiff);

		ui.doubleSpinBox_Y1->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY1_min);
		ui.doubleSpinBox_Y1_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY1_max);
		ui.doubleSpinBox_Y2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY2_min);
		ui.doubleSpinBox_Y2_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY2_max);
		ui.doubleSpinBox_Y3->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY3_min);
		ui.doubleSpinBox_Y3_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY3_max);
		ui.doubleSpinBox_Y4->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY4_min);
		ui.doubleSpinBox_Y4_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY4_max);
		ui.doubleSpinBox_Y6->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY6_min);
		ui.doubleSpinBox_Y6_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY6_max);
		ui.doubleSpinBox_Y7->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY7_min);
		ui.doubleSpinBox_Y7_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY7_max);
		ui.doubleSpinBox_Y8->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY8_min);
		ui.doubleSpinBox_Y8_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY8_max);
		ui.doubleSpinBox_Y9->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY9_min);
		ui.doubleSpinBox_Y9_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingY9_max);

		ui.doubleSpinBox_R1->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR1_min);
		ui.doubleSpinBox_R1_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR1_max);
		ui.doubleSpinBox_R2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR2_min);
		ui.doubleSpinBox_R2_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR2_max);
		ui.doubleSpinBox_R3->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR3_min);
		ui.doubleSpinBox_R3_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR3_max);
		ui.doubleSpinBox_R4->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR4_min);
		ui.doubleSpinBox_R4_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR4_max);
		ui.doubleSpinBox_R6->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR6_min);
		ui.doubleSpinBox_R6_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR6_max);
		ui.doubleSpinBox_R7->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR7_min);
		ui.doubleSpinBox_R7_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR7_max);
		ui.doubleSpinBox_R8->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR8_min);
		ui.doubleSpinBox_R8_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR8_max);
		ui.doubleSpinBox_R9->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR9_min);
		ui.doubleSpinBox_R9_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingR9_max);

		ui.doubleSpinBox_B1->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB1_min);
		ui.doubleSpinBox_B1_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB1_max);
		ui.doubleSpinBox_B2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB2_min);
		ui.doubleSpinBox_B2_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB2_max);
		ui.doubleSpinBox_B3->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB3_min);
		ui.doubleSpinBox_B3_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB3_max);
		ui.doubleSpinBox_B4->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB4_min);
		ui.doubleSpinBox_B4_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB4_max);
		ui.doubleSpinBox_B6->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB6_min);
		ui.doubleSpinBox_B6_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB6_max);
		ui.doubleSpinBox_B7->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB7_min);
		ui.doubleSpinBox_B7_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB7_max);
		ui.doubleSpinBox_B8->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB8_min);
		ui.doubleSpinBox_B8_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB8_max);
		ui.doubleSpinBox_B9->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB9_min);
		ui.doubleSpinBox_B9_2->setValue(itemshareData.wpShadingParameter->stShadingConfigHE.qs_ShadingB9_max);
		
		//**************************   2019/01/26  ************************************
		ui.spinBox_ShadingF_ROIWNumber->setValue(itemshareData.wpShadingParameter->stShadingConfigHF.iROIWNumber_AlgF);
		ui.spinBox_ShadingF_ROIHNumber->setValue(itemshareData.wpShadingParameter->stShadingConfigHF.iROIHNumber_AlgF);
		ui.doubleSpinBox_ShadingF_Spec->setValue(itemshareData.wpShadingParameter->stShadingConfigHF.fMinMaxRatioSpec_AlgF);



		ui.shadingcomboBox->setCurrentIndex(itemshareData.wpShadingParameter->shadingAlg);
		ShadingAlgSwitch(itemshareData.wpShadingParameter->shadingAlg);
	}

	if(itemshareData.wpColorParameter)
	{
		ui.colorRangelineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flcenterrange));
		ui.colorIdealAlineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flideala));
		ui.colorIdealBlineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flidealb));
		ui.colorAberrlineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flaberration));
		ui.colorFallofflineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flfalloff));
		ui.colorSymlineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_flsym));
		ui.colorUniformlineEdit->setText(QString::number(itemshareData.wpColorParameter->stAlgHA.color_fluniform));
		ui.colorBlocksspinBox->setValue(itemshareData.wpColorParameter->stAlgHA.color_iwithblocks);

		ui.whitecolorhbCenterRatiodoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flCenterRatio);
		ui.whitecolorhbGMinspinBox->setValue(itemshareData.wpColorParameter->stAlgHB.ucGMin);
		ui.whitecolorhbGMaxspinBox->setValue(itemshareData.wpColorParameter->stAlgHB.ucGMax);
		ui.whitecolorhbCenterRGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flRGMin);
		ui.whitecolorhbCenterRGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flRGMax);
		ui.whitecolorhbCenterBGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flBGMin);
		ui.whitecolorhbCenterBGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flBGMax);
		ui.whitecolorhbCCRGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flCCRGMin);
		ui.whitecolorhbCCRGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flCCRGMax);
		ui.whitecolorhbCCBGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flCCBGMin);
		ui.whitecolorhbCCBGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flCCBGMax);
		ui.whitecolorhbCornerPPRGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flConerPP_RGMin);
		ui.whitecolorhbCornerPPRGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flConerPP_RGMax);
		ui.whitecolorhbCornerPPBGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flConerPP_BGMin);
		ui.whitecolorhbCornerPPBGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flConerPP_BGMax);
		ui.whitecolorhbROINumWspinBox->setValue(itemshareData.wpColorParameter->stAlgHB.ucROINumW);
		ui.whitecolorhbROINumHspinBox->setValue(itemshareData.wpColorParameter->stAlgHB.ucROINumH);
		ui.whitecolorhbALLPPRGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flAllPP_RGMin);
		ui.whitecolorhbALLPPRGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flAllPP_RGMax);
		ui.whitecolorhbALLPPBGMindoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flAllPP_BGMin);
		ui.whitecolorhbALLPPBGMaxdoubleSpinBox->setValue(itemshareData.wpColorParameter->stAlgHB.flAllPP_BGMax);

		ui.colorcomboBox->setCurrentIndex(itemshareData.wpColorParameter->colorAlg);
	}

	if(itemshareData.wpDefectPixelParameter)
	{
		ui.defectpixelRatiolineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_fldefect));
		ui.woundpixelRatiolineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_flwound));
		ui.deadpixelRatiolineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_fldead));
		ui.dpblocksspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_iwidthblocks);
		ui.defectpixelScorespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ucdefectscore);
		ui.woundpixelScorespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ucwoundscore);
		ui.deadpixelScorespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ucdeadscore);
		ui.clusterScorespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_iclusterscore);
		ui.defectpixelCountlineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ispecdefect));
		ui.woundpixelCountlineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ispecwound));
		ui.deadpixelCountlineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ispecdead));
		ui.totalpixelScorelineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_itotalscore));
		ui.clusterCountlineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_ispeccluster));
		ui.clusterMaxScorelineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHA.defectpixel_iclustermaxscore));

		ui.defectpixelhbDefectMindoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flDefectMin);
		ui.defectpixelhbDefectMaxdoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flDefectMax);
		ui.defectpixelhbWoundMindoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flWoundMin);
		ui.defectpixelhbWoundMaxdoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flWoundMax);
		ui.defectpixelhbDeadMindoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flDeadMin);
		ui.defectpixelhbDeadMaxdoubleSpinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.flDeadMax);
		ui.defectpixelhbCenterRangelineEdit->setText(QString::number(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_flCenterRange, 'f', 4));
		ui.defectpixelhbBlockSizespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiBlockSize);
		ui.defectpixelhbPerChannelcheckBox->setChecked(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_bPerChannel);
		ui.defectpixelhbCenterDefectSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterDefectSingle);
		ui.defectpixelhbCenterWoundSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterWoundSingle);
		ui.defectpixelhbCenterDeadSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterDeadSingle);
		ui.defectpixelhbCenterDefectClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterDefectClusterMax);
		ui.defectpixelhbCenterWoundClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterWoundClusterMax);
		ui.defectpixelhbCenterDeadClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiCenterDeadClusterMax);
		ui.defectpixelhbEdgeDefectSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeDefectSingle);
		ui.defectpixelhbEdgeWoundSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeWoundSingle);
		ui.defectpixelhbEdgeDeadSinglespinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeDeadSingle);
		ui.defectpixelhbEdgeDefectClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeDefectClusterMax);
		ui.defectpixelhbEdgeWoundClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeWoundClusterMax);
		ui.defectpixelhbEdgeDeadClusterspinBox->setValue(itemshareData.wpDefectPixelParameter->stAlgHB.defectpixelhb_uiEdgeDeadClusterMax);
	    ui.saveDefectPixelCalImagecheckBox->setChecked(itemshareData.wpDefectPixelParameter->bSaveDefectPixelCalImage);
		ui.defectpixelcomboBox->setCurrentIndex(itemshareData.wpDefectPixelParameter->defectpixelAlg);
		DefectPixelAlgSwitch(itemshareData.wpDefectPixelParameter->defectpixelAlg);
	}

	if(itemshareData.wpDefectLineParameter)
	{
		ui.defectlineSpecRlineEdit->setText(QString::number(itemshareData.wpDefectLineParameter->stAlgHA.line_flspec_r));
		ui.defectlineSpecGlineEdit->setText(QString::number(itemshareData.wpDefectLineParameter->stAlgHA.line_flspec_g));
		ui.defectlineSpecBlineEdit->setText(QString::number(itemshareData.wpDefectLineParameter->stAlgHA.line_flspec_b));

		ui.linecomboBox->setCurrentIndex(itemshareData.wpDefectLineParameter->defectlineAlg);
	}

	if(itemshareData.wpVignetingParameter)
	{
		ui.vignettingHAR1WspinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.uiROIW);
		ui.vignettingHAR1HspinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.uiROIH);
		ui.vignettingHAR2MindoubleSpinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.flSpecR2Min);
		ui.vignettingHAR2MaxdoubleSpinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.flSpecR2Max);
		ui.vignettingHAR3MindoubleSpinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.flSpecR3Min);
		ui.vignettingHAR3MaxdoubleSpinBox->setValue(itemshareData.wpVignetingParameter->stVignettingConfigHA.flSpecR3Max);

		ui.vignettingcomboBox->setCurrentIndex(itemshareData.wpVignetingParameter->vignettingAlg);
	}
}

int configsetting::saveWhitePanel()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "whitepanel");

			unsigned int uiIndex	=	_HisDB_Index_WhitePanel;
			stSqlDB.transaction();

			//(roi1w:32)(roi1h:32)
			//(specr2min:0.9)(specr2max:1.1)
			//(specr3min:0.9)(specr3max:1.1)
			strname.clear();	strvalue.clear();
			strname.append("roi1w");	strvalue.append(ui.vignettingHAR1WspinBox->text());
			strname.append("roi1w");	strvalue.append(ui.vignettingHAR1HspinBox->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("specr2min");	strvalue.append(ui.vignettingHAR2MindoubleSpinBox->text());
			strname.append("specr2max");	strvalue.append(ui.vignettingHAR2MaxdoubleSpinBox->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("specr3min");	strvalue.append(ui.vignettingHAR3MindoubleSpinBox->text());
			strname.append("specr3max");	strvalue.append(ui.vignettingHAR3MaxdoubleSpinBox->text());
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "vignettingha", itemsuffix2, key, value1);

			//(channel:y)(roiw:0.2)(roih:0.2)
			//(specmin:0.5)(specmax:0.8)(specdev:0.05)
			strname.clear();	strvalue.clear();
			strname.append("channel");	strvalue.append(ui.shadingHAChannelcomboBox->currentText().toLower());
			strname.append("roiw");			strvalue.append(ui.shadingHAROIWdoubleSpinBox->text());
			strname.append("roih");			strvalue.append(ui.shadingHAROIHdoubleSpinBox->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("specmin");	strvalue.append(ui.shadingHAMindoubleSpinBox->text());
			strname.append("specmax");	strvalue.append(ui.shadingHAMaxdoubleSpinBox->text());
			strname.append("specdev");	strvalue.append(ui.shadingHADevdoubleSpinBox->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandingha", itemsuffix2, key);

			//(rgmin:0.0)(rgmax:4.0)(bgmin:0.0)(bgmax:4.0)
			//(specmin:50.0)(specmax:80.0)(specdev:5.0)
			//(ppmin:0.0)(ppmax:4.0)(bgoffset:0.0)(rgoffset:0.0)(ppoffset:0.0)(yyoffset:0.0)
			strname.clear();	strvalue.clear();
			strname.append("rgmin");	strvalue.append(ui.shadingHBRGMindoubleSpinBox->text());
			strname.append("rgmax");	strvalue.append(ui.shadingHBRGMaxdoubleSpinBox->text());
			strname.append("bgmin");	strvalue.append(ui.shadingHBBGMindoubleSpinBox->text());
			strname.append("bgmax");	strvalue.append(ui.shadingHBBGMaxdoubleSpinBox->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("specmin");	strvalue.append(ui.shadingHBMindoubleSpinBox->text());
			strname.append("specmax");	strvalue.append(ui.shadingHBMaxdoubleSpinBox->text());
			strname.append("specdev");	strvalue.append(ui.shadingHBDevdoubleSpinBox->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("ppmin");		strvalue.append(ui.shadingHBPPMindoubleSpinBox->text());
			strname.append("ppmax");		strvalue.append(ui.shadingHBPPMaxdoubleSpinBox->text());
			strname.append("bgoffset");	strvalue.append(ui.shadingHBBGOffsetdoubleSpinBox->text());
			strname.append("rgoffset");	strvalue.append(ui.shadingHBRGOffsetdoubleSpinBox->text());
			strname.append("ppoffset");	strvalue.append(ui.shadingHBPPOffsetdoubleSpinBox->text());
			strname.append("yyoffset");	strvalue.append(ui.shadingHBYYOffsetdoubleSpinBox->text());
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandinghb", itemsuffix2, key, value1);

			//shandinghc
			//(rawinfo:)(lightsource:)
			//(tunegain:)
			//(yymin:)(yymax:)(bgmin:)(bgmax:)(rgmin:)(rgmax:)
			//(ppmin:0.0)(ppmax:4.0)(cornermin:)(cornermax:)(vignetmin:)(vignetmax:)
			strname.clear();	strvalue.clear();
			strname.append("rawinfo");	strvalue.append(ui.shadinghcRawBinlineEdit->text());
			strname.append("lightsource");	strvalue.append(ui.shadinghcLightBinlineEdit->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("tunegain");	strvalue.append(ui.shadinghcTuneGainBinlineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("yymin");		strvalue.append(ui.shadinghcYMindoubleSpinBox->cleanText());
			strname.append("yymax");		strvalue.append(ui.shadinghcYMaxdoubleSpinBox->cleanText());
			strname.append("yyoffset");		strvalue.append(ui.shadinghcYOffsetdoubleSpinBox->cleanText());
			strname.append("rgmin");		strvalue.append(ui.shadinghcRGMindoubleSpinBox->cleanText());
			strname.append("rgmax");		strvalue.append(ui.shadinghcRGMaxdoubleSpinBox->cleanText());
			strname.append("rgoffset");		strvalue.append(ui.shadinghcRGOffsetdoubleSpinBox->cleanText());
			strname.append("bgmin");		strvalue.append(ui.shadinghcBGMindoubleSpinBox->cleanText());
			strname.append("bgmax");		strvalue.append(ui.shadinghcBGMaxdoubleSpinBox->cleanText());
			strname.append("bgoffset");		strvalue.append(ui.shadinghcBGOffsetdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("ppmin");				strvalue.append(ui.shadinghcPPMindoubleSpinBox->cleanText());
			strname.append("ppmax");				strvalue.append(ui.shadinghcPPMaxdoubleSpinBox->cleanText());
			strname.append("ppoffset");			strvalue.append(ui.shadinghcPPOffsetdoubleSpinBox->cleanText());
			strname.append("cornermin");		strvalue.append(ui.shadinghcCornerMindoubleSpinBox->cleanText());
			strname.append("cornermax");		strvalue.append(ui.shadinghcCornerMaxdoubleSpinBox->cleanText());
			strname.append("corneroffset");	strvalue.append(ui.shadinghcCornerOffsetdoubleSpinBox->cleanText());
			strname.append("vignetmin");		strvalue.append(ui.shadinghcVignetMindoubleSpinBox->cleanText());
			strname.append("vignetmax");		strvalue.append(ui.shadinghcVignetMaxdoubleSpinBox->cleanText());
			strname.append("vignetoffset");		strvalue.append(ui.shadinghcVignetOffsetdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandinghc", itemsuffix2, key, value1, reserve);

			//shandinghd
			//(blockw:17)(blockh:15)
			//(ppymin:0.3)(ppymax:0.6)(pprgmin:0.3)(pprgmax:0.6)(ppbgmin:0.3)(ppbgmax:0.6)
			strname.clear();	strvalue.clear();
			strname.append("blockw");	strvalue.append(ui.shadinghdBlockWspinBox->cleanText());
			strname.append("blockh");	strvalue.append(ui.shadinghdBlockHspinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("ppymin");	strvalue.append(ui.shadinghdPPYMindoubleSpinBox->cleanText());
			strname.append("ppymax");	strvalue.append(ui.shadinghdPPYMaxdoubleSpinBox->cleanText());
			strname.append("pprgmin");	strvalue.append(ui.shadinghdPPRGMindoubleSpinBox->cleanText());
			strname.append("pprgmax");	strvalue.append(ui.shadinghdPPRGMaxdoubleSpinBox->cleanText());
			strname.append("ppbgmin");	strvalue.append(ui.shadinghdPPBGMindoubleSpinBox->cleanText());
			strname.append("ppbgmax");	strvalue.append(ui.shadinghdPPBGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandinghd", itemsuffix2, key);

			//shandingh_e   ******fengqiquan 2018/01/16 Add
			//(blockw:17)(blockh:15)
			//(ppymin:0.3)(ppymax:0.6)(pprgmin:0.3)(pprgmax:0.6)(ppbgmin:0.3)(ppbgmax:0.6)

			strname.clear();	strvalue.clear();
			strname.append("qs_diff");	strvalue.append(ui.doubleSpinBox_LscDiff->cleanText());
			strname.append("qs_roisize");	strvalue.append(ui.doubleSpinBox_LscRoiSize->cleanText());
			strname.append("qs_blc");	strvalue.append(ui.spinBox_LscBlackLevel->cleanText());

			strname.append("qs_yshading_lt_min");	strvalue.append(ui.doubleSpinBox_Y1->cleanText());
			strname.append("qs_yshading_lt_max");	strvalue.append(ui.doubleSpinBox_Y1_2->cleanText());
			strname.append("qs_yshading_rt_min");	strvalue.append(ui.doubleSpinBox_Y3->cleanText());
			strname.append("qs_yshading_rt_max");	strvalue.append(ui.doubleSpinBox_Y3_2->cleanText());
			strname.append("qs_yshading_lb_min");	strvalue.append(ui.doubleSpinBox_Y7->cleanText());
			strname.append("qs_yshading_lb_max");	strvalue.append(ui.doubleSpinBox_Y7_2->cleanText());
			strname.append("qs_yshading_rb_min");	strvalue.append(ui.doubleSpinBox_Y9->cleanText());
			strname.append("qs_yshading_rb_max");	strvalue.append(ui.doubleSpinBox_Y9_2->cleanText());
			strname.append("qs_yshading_t_min");	strvalue.append(ui.doubleSpinBox_Y2->cleanText());
			strname.append("qs_yshading_t_max");	strvalue.append(ui.doubleSpinBox_Y2_2->cleanText());
			strname.append("qs_yshading_l_min");	strvalue.append(ui.doubleSpinBox_Y4->cleanText());
			strname.append("qs_yshading_l_max");	strvalue.append(ui.doubleSpinBox_Y4_2->cleanText());
			strname.append("qs_yshading_r_min");	strvalue.append(ui.doubleSpinBox_Y6->cleanText());
			strname.append("qs_yshading_r_max");	strvalue.append(ui.doubleSpinBox_Y6_2->cleanText());
			strname.append("qs_yshading_b_min");	strvalue.append(ui.doubleSpinBox_Y8->cleanText());
			strname.append("qs_yshading_b_max");	strvalue.append(ui.doubleSpinBox_Y8_2->cleanText());

			strname.append("qs_rshading_lt_min");	strvalue.append(ui.doubleSpinBox_R1->cleanText());
			strname.append("qs_rshading_lt_max");	strvalue.append(ui.doubleSpinBox_R1_2->cleanText());
			strname.append("qs_rshading_rt_min");	strvalue.append(ui.doubleSpinBox_R3->cleanText());
			strname.append("qs_rshading_rt_max");	strvalue.append(ui.doubleSpinBox_R3_2->cleanText());
			strname.append("qs_rshading_lb_min");	strvalue.append(ui.doubleSpinBox_R7->cleanText());
			strname.append("qs_rshading_lb_max");	strvalue.append(ui.doubleSpinBox_R7_2->cleanText());
			strname.append("qs_rshading_rb_min");	strvalue.append(ui.doubleSpinBox_R9->cleanText());
			strname.append("qs_rshading_rb_max");	strvalue.append(ui.doubleSpinBox_R9_2->cleanText());
			strname.append("qs_rshading_t_min");	strvalue.append(ui.doubleSpinBox_R2->cleanText());
			strname.append("qs_rshading_t_max");	strvalue.append(ui.doubleSpinBox_R2_2->cleanText());
			strname.append("qs_rshading_l_min");	strvalue.append(ui.doubleSpinBox_R4->cleanText());
			strname.append("qs_rshading_l_max");	strvalue.append(ui.doubleSpinBox_R4_2->cleanText());
			strname.append("qs_rshading_r_min");	strvalue.append(ui.doubleSpinBox_R6->cleanText());
			strname.append("qs_rshading_r_max");	strvalue.append(ui.doubleSpinBox_R6_2->cleanText());
			strname.append("qs_rshading_b_min");	strvalue.append(ui.doubleSpinBox_R8->cleanText());
			strname.append("qs_rshading_b_max");	strvalue.append(ui.doubleSpinBox_R8_2->cleanText());

			strname.append("qs_bshading_lt_min");	strvalue.append(ui.doubleSpinBox_B1->cleanText());
			strname.append("qs_bshading_lt_max");	strvalue.append(ui.doubleSpinBox_B1_2->cleanText());
			strname.append("qs_bshading_rt_min");	strvalue.append(ui.doubleSpinBox_B3->cleanText());
			strname.append("qs_bshading_rt_max");	strvalue.append(ui.doubleSpinBox_B3_2->cleanText());
			strname.append("qs_bshading_lb_min");	strvalue.append(ui.doubleSpinBox_B7->cleanText());
			strname.append("qs_bshading_lb_max");	strvalue.append(ui.doubleSpinBox_B7_2->cleanText());
			strname.append("qs_bshading_rb_min");	strvalue.append(ui.doubleSpinBox_B9->cleanText());
			strname.append("qs_bshading_rb_max");	strvalue.append(ui.doubleSpinBox_B9_2->cleanText());
			strname.append("qs_bshading_t_min");	strvalue.append(ui.doubleSpinBox_B2->cleanText());
			strname.append("qs_bshading_t_max");	strvalue.append(ui.doubleSpinBox_B2_2->cleanText());
			strname.append("qs_bshading_l_min");	strvalue.append(ui.doubleSpinBox_B4->cleanText());
			strname.append("qs_bshading_l_max");	strvalue.append(ui.doubleSpinBox_B4_2->cleanText());
			strname.append("qs_bshading_r_min");	strvalue.append(ui.doubleSpinBox_B6->cleanText());
			strname.append("qs_bshading_r_max");	strvalue.append(ui.doubleSpinBox_B6_2->cleanText());
			strname.append("qs_bshading_b_min");	strvalue.append(ui.doubleSpinBox_B8->cleanText());
			strname.append("qs_bshading_b_max");	strvalue.append(ui.doubleSpinBox_B8_2->cleanText());

			

			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandinghe", itemsuffix2, key);


			//****************   2018/01/16  End *********************************
			//******************** 2019/01/26 start ******************************


			strname.clear();	strvalue.clear();
			strname.append("roiwnumber");	strvalue.append(ui.spinBox_ShadingF_ROIWNumber->cleanText());
			strname.append("roihnumber");	strvalue.append(ui.spinBox_ShadingF_ROIHNumber->cleanText());
			strname.append("mindivmax");	strvalue.append(ui.doubleSpinBox_ShadingF_Spec->cleanText());

			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "shandinghf", itemsuffix2, key);
			//********************* 2019/01/26 end ********************************




			//(deviation:10.0)
			//(pixelratio:0.09)
			strname.clear();	strvalue.clear();
			strname.append("deviation");	strvalue.append(ui.ocDeviationlineEdit->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("pixelratio");
			strvalue.append(ui.ocPixelRatiolineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "opticalcenter", itemsuffix2, key);

			//****************************************** OC ALG B ****************************
			//(deviation:10.0)
			//(pixelratio:0.09)
			strname.clear();	strvalue.clear();
			strname.append("deviation");	strvalue.append(ui.ochbDevspinBox->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("pixelratio");
			strvalue.append(ui.ochbSizeRatiodoubleSpinBox->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "opticalcenterhb", itemsuffix2, key);

			//(defectratio:0.1)(woundratio:0.2)(defectscore:1)(woundscore:2)(deadscore:3)
			//(clusterscore:50)(widthblocks:180)(deadratio:0.3)
			//(defectspec:20)(woundspec:20)(deadspec:20)
			//(totalscorespec:1000)(clusterspec:0)(clustermaxscore:20)
			strname.clear();	strvalue.clear();
			strname.append("defectratio");		strvalue.append(ui.defectpixelRatiolineEdit->text());
			strname.append("woundratio");		strvalue.append(ui.woundpixelRatiolineEdit->text());
			strname.append("defectscore");		strvalue.append(ui.defectpixelScorespinBox->cleanText());
			strname.append("woundscore");	strvalue.append(ui.woundpixelScorespinBox->cleanText());
			strname.append("deadscore");		strvalue.append(ui.deadpixelScorespinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("clusterscore");	strvalue.append(ui.clusterScorespinBox->cleanText());
			strname.append("widthblocks");		strvalue.append(ui.dpblocksspinBox->cleanText());
			strname.append("deadratio");			strvalue.append(ui.deadpixelRatiolineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("defectspec");	strvalue.append(ui.defectpixelCountlineEdit->text());
			strname.append("woundspec");	strvalue.append(ui.woundpixelCountlineEdit->text());
			strname.append("deadspec");	strvalue.append(ui.deadpixelCountlineEdit->text());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("totalscorespec");	strvalue.append(ui.totalpixelScorelineEdit->text());
			strname.append("clusterspec");			strvalue.append(ui.clusterCountlineEdit->text());
			strname.append("clustermaxscore");strvalue.append(ui.clusterMaxScorelineEdit->text());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "defectpixel", itemsuffix2, key, value1, reserve);

			//(defectmin:-0.3)(defectmax:0.3)(woundmin:-0.3)(woundmax:0.3)(deadmin:-0.3)(deadmax:0.3)(centerrange:0.7)(blocksize:11)(perchannel:true)
			//(centerdefectsingle:1000)(centerwoundsingle:100)(centerdeadsingle:100)(centerdefectclustersize:4)(centerwoundclustersize:3)(centerdeadclustersize:2)
			//(edgedefectsingle:1000)(edgewoundsingle:100)(edgedeadsingle:100)(edgedefectclustersize:4)(edgewoundclustersize:3)(edgedeadclustersize:2)
			strname.clear();	strvalue.clear();
			strname.append("defectmin");		strvalue.append(ui.defectpixelhbDefectMindoubleSpinBox->cleanText());
			strname.append("defectmax");		strvalue.append(ui.defectpixelhbDefectMaxdoubleSpinBox->cleanText());
			strname.append("woundmin");		strvalue.append(ui.defectpixelhbWoundMindoubleSpinBox->cleanText());
			strname.append("woundmax");		strvalue.append(ui.defectpixelhbWoundMaxdoubleSpinBox->cleanText());
			strname.append("deadmin");		strvalue.append(ui.defectpixelhbDeadMindoubleSpinBox->cleanText());
			strname.append("deadmax");		strvalue.append(ui.defectpixelhbDeadMaxdoubleSpinBox->cleanText());
			strname.append("centerrange");	strvalue.append(ui.defectpixelhbCenterRangelineEdit->text());
			strname.append("blocksize");			strvalue.append(QString::number(ui.defectpixelhbBlockSizespinBox->value()));
			strname.append("perchannel");		strvalue.append((ui.defectpixelhbPerChannelcheckBox->isChecked())?("true"):("false"));
			strname.append("savedefectcalimage");		strvalue.append((ui.saveDefectPixelCalImagecheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("centerdefectsingle");	strvalue.append(QString::number(ui.defectpixelhbCenterDefectSinglespinBox->value()));
			strname.append("centerwoundsingle");	strvalue.append(QString::number(ui.defectpixelhbCenterWoundSinglespinBox->value()));
			strname.append("centerdeadsingle");	strvalue.append(QString::number(ui.defectpixelhbCenterDeadSinglespinBox->value()));
			strname.append("centerdefectclustersize");	strvalue.append(QString::number(ui.defectpixelhbCenterDefectClusterspinBox->value()));
			strname.append("centerwoundclustersize");	strvalue.append(QString::number(ui.defectpixelhbCenterWoundClusterspinBox->value()));
			strname.append("centerdeadclustersize");	strvalue.append(QString::number(ui.defectpixelhbCenterDeadClusterspinBox->value()));
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("edgedefectsingle");	strvalue.append(QString::number(ui.defectpixelhbEdgeDefectSinglespinBox->value()));
			strname.append("edgewoundsingle");	strvalue.append(QString::number(ui.defectpixelhbEdgeWoundSinglespinBox->value()));
			strname.append("edgedeadsingle");		strvalue.append(QString::number(ui.defectpixelhbEdgeDeadSinglespinBox->value()));
			strname.append("edgedefectclustersize");	strvalue.append(QString::number(ui.defectpixelhbEdgeDefectClusterspinBox->value()));
			strname.append("edgewoundclustersize");	strvalue.append(QString::number(ui.defectpixelhbEdgeWoundClusterspinBox->value()));
			strname.append("edgedeadclustersize");		strvalue.append(QString::number(ui.defectpixelhbEdgeDeadClusterspinBox->value()));
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "defectpixelhb", itemsuffix2, key, value1);

			//(spec_r:0.03)(spec_g:0.03)(spec_b:0.03)
			strname.clear();	strvalue.clear();
			strname.append("spec_r");		strvalue.append(ui.defectlineSpecRlineEdit->text());
			strname.append("spec_g");	strvalue.append(ui.defectlineSpecGlineEdit->text());
			strname.append("spec_b");	strvalue.append(ui.defectlineSpecBlineEdit->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "defectline", itemsuffix2);

			//(range:0.9)(filter:12,24)
			//(amplitude:70)(dev:43)(cornerspec:0.15)
			strname.clear();	strvalue.clear();
			strname.append("range");	strvalue.append(ui.blemishRangelineEdit->text());
			strname.append("filter");		strvalue.append(QString::number(ui.blemishHighPassspinBox->value()) % "," % QString::number(ui.blemishLowPassspinBox->value()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("amplitude");	strvalue.append(QString::number(ui.blemishAmplitudespinBox->value()));
			strname.append("dev");				strvalue.append(QString::number(ui.blemishDevspinBox->value()));
			strname.append("cornerspec");	strvalue.append(ui.blemishA_Corner_lineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "blemish", itemsuffix2, key);

			//(z1r1:0.1)(z1r2:0.1)
			//(z2r1:0.1)(z2r2:0.1)
			//(z3r1:0.1)(z3r2:0.1)
			//(zone1range:0.2)(zone3x:300)(zone3y:300)(removedefect:false)(frame:1)
			strname.clear();	strvalue.clear();
			strname.append("zone1range");		strvalue.append(ui.blmeishBCenterRangelineEdit->text());
			strname.append("zone3x");			strvalue.append(QString::number(ui.blmeishBZone3XspinBox->value()));
			strname.append("zone3y");			strvalue.append(QString::number(ui.blmeishBZone3YspinBox->value()));
			strname.append("removedefect");	strvalue.append((ui.blemishhbMoveDefectcheckBox->isChecked())?("true"):("false"));
			strname.append("frame");		strvalue.append(ui.blmeishBFramespinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("z1r1");		strvalue.append(ui.blmeishBZ1R1lineEdit->text());
			strname.append("z1r2");		strvalue.append(ui.blmeishBZ1R2lineEdit->text());
			strname.append("z1r3");		strvalue.append(ui.blmeishBZ1R3lineEdit->text());
			strname.append("z1r4");		strvalue.append(ui.blmeishBZ1R4lineEdit->text());
			strname.append("z1r5");		strvalue.append(ui.blmeishBZ1R5lineEdit->text());
			strname.append("z1r6");		strvalue.append(ui.blmeishBZ1R6lineEdit->text());
			strname.append("z1r7");		strvalue.append(ui.blmeishBZ1R7lineEdit->text());
			strname.append("z1r8");		strvalue.append(ui.blmeishBZ1R8lineEdit->text());
			strname.append("z1r9");		strvalue.append(ui.blmeishBZ1R9lineEdit->text());
			strname.append("z1r10");	strvalue.append(ui.blmeishBZ1R10lineEdit->text());
			strname.append("z1r11");	strvalue.append(ui.blmeishBZ1R11lineEdit->text());
			strname.append("z1r12");	strvalue.append(ui.blmeishBZ1R12lineEdit->text());
			strname.append("z1r13");	strvalue.append(ui.blmeishBZ1R13lineEdit->text());
			strname.append("z1r14");	strvalue.append(ui.blmeishBZ1R14lineEdit->text());
			strname.append("z1r15");	strvalue.append(ui.blmeishBZ1R15lineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("z2r1");	strvalue.append(ui.blmeishBZ2R1lineEdit->text());
			strname.append("z2r2");	strvalue.append(ui.blmeishBZ2R2lineEdit->text());
			strname.append("z2r3");	strvalue.append(ui.blmeishBZ2R3lineEdit->text());
			strname.append("z2r4");	strvalue.append(ui.blmeishBZ2R4lineEdit->text());
			strname.append("z2r5");	strvalue.append(ui.blmeishBZ2R5lineEdit->text());
			strname.append("z2r6");	strvalue.append(ui.blmeishBZ2R6lineEdit->text());
			strname.append("z2r7");strvalue.append(ui.blmeishBZ2R7lineEdit->text());
			strname.append("z2r8");strvalue.append(ui.blmeishBZ2R8lineEdit->text());
			strname.append("z2r9");strvalue.append(ui.blmeishBZ2R9lineEdit->text());
			strname.append("z2r10");strvalue.append(ui.blmeishBZ2R10lineEdit->text());
			strname.append("z2r11");strvalue.append(ui.blmeishBZ2R11lineEdit->text());
			strname.append("z2r12");strvalue.append(ui.blmeishBZ2R12lineEdit->text());
			strname.append("z2r13");strvalue.append(ui.blmeishBZ2R13lineEdit->text());
			strname.append("z2r14");strvalue.append(ui.blmeishBZ2R14lineEdit->text());
			strname.append("z2r15");strvalue.append(ui.blmeishBZ2R15lineEdit->text());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("z3r1");strvalue.append(ui.blmeishBZ3R1lineEdit->text());
			strname.append("z3r2");strvalue.append(ui.blmeishBZ3R2lineEdit->text());
			strname.append("z3r3");strvalue.append(ui.blmeishBZ3R3lineEdit->text());
			strname.append("z3r4");strvalue.append(ui.blmeishBZ3R4lineEdit->text());
			strname.append("z3r5");strvalue.append(ui.blmeishBZ3R5lineEdit->text());
			strname.append("z3r6");strvalue.append(ui.blmeishBZ3R6lineEdit->text());
			strname.append("z3r7");strvalue.append(ui.blmeishBZ3R7lineEdit->text());
			strname.append("z3r8");strvalue.append(ui.blmeishBZ3R8lineEdit->text());
			strname.append("z3r9");strvalue.append(ui.blmeishBZ3R9lineEdit->text());
			strname.append("z3r10");strvalue.append(ui.blmeishBZ3R10lineEdit->text());
			strname.append("z3r11");strvalue.append(ui.blmeishBZ3R11lineEdit->text());
			strname.append("z3r12");strvalue.append(ui.blmeishBZ3R12lineEdit->text());
			strname.append("z3r13");strvalue.append(ui.blmeishBZ3R13lineEdit->text());
			strname.append("z3r14");strvalue.append(ui.blmeishBZ3R14lineEdit->text());
			strname.append("z3r15");strvalue.append(ui.blmeishBZ3R15lineEdit->text());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "blemishhb", itemsuffix2, key, value1, reserve);

			//(lsc:false)(wb:false)
			strname.clear(); strvalue.clear();
			strname.append("minarea");strvalue.append(ui.blemishhcAreaMindoubleSpinBox->cleanText());
			strname.append("maxarea");strvalue.append(ui.blemishhcAreaMaxdoubleSpinBox->cleanText());
			strname.append("edgezone");strvalue.append(ui.blemishhcEdgeZonedoubleSpinBox->cleanText());
			strname.append("cornerzone");strvalue.append(ui.blemishhcCornerZonedoubleSpinBox->cleanText());
			strname.append("tuning");strvalue.append(ui.blemishhcTuningdoubleSpinBox->cleanText());
			strname.append("frame");strvalue.append(ui.blemishhcFramespinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear(); strvalue.clear();
			strname.append("z1b");strvalue.append(ui.blemishhcZ1BdoubleSpinBox->cleanText());
			strname.append("z2b");strvalue.append(ui.blemishhcZ2BdoubleSpinBox->cleanText());
			strname.append("z3b");strvalue.append(ui.blemishhcZ3BdoubleSpinBox->cleanText());
			strname.append("z4b");strvalue.append(ui.blemishhcZ4BdoubleSpinBox->cleanText());
			strname.append("z5b");strvalue.append(ui.blemishhcZ5BdoubleSpinBox->cleanText());
			strname.append("z6b");strvalue.append(ui.blemishhcZ6BdoubleSpinBox->cleanText());
			strname.append("z7b");strvalue.append(ui.blemishhcZ7BdoubleSpinBox->cleanText());
			strname.append("z8b");strvalue.append(ui.blemishhcZ8BdoubleSpinBox->cleanText());
			strname.append("z9b");strvalue.append(ui.blemishhcZ9BdoubleSpinBox->cleanText());
			strname.append("z10b");strvalue.append(ui.blemishhcZ10BdoubleSpinBox->cleanText());
			strname.append("zdgeb");strvalue.append(ui.blemishhcEdgeBdoubleSpinBox->cleanText());
			strname.append("cornerb");strvalue.append(ui.blemishhcCornerBdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "blemishhc", itemsuffix2, key);

			//blemish d
			//(rawinfo:)
			strname.clear(); strvalue.clear();
			strname.append("rawinfo");strvalue.append(ui.blemishdRawInfolineEdit->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			//(rawinfo:)
			strname.clear(); strvalue.clear();
			strname.append("optbin");strvalue.append(ui.blemishdOptionlineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear(); strvalue.clear();
			strname.append("maxedgediff");strvalue.append(ui.blemishdMaxEdgeDiffdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "blemishhd", itemsuffix2, key, value1);

			//(a:0.0)(b:0.0)(centerrange:0.08)(widthblocks:32)
			//(uniform:2.8)(aberration:1.0)(sym:1.0)(falloff:3.0)
			strname.clear();strvalue.clear();
			strname.append("a");strvalue.append(ui.colorIdealAlineEdit->text());
			strname.append("b");strvalue.append(ui.colorIdealBlineEdit->text());
			strname.append("centerrange");strvalue.append(ui.colorRangelineEdit->text());
			strname.append("widthblocks");strvalue.append(QString::number(ui.colorBlocksspinBox->value()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("uniform");strvalue.append(ui.colorUniformlineEdit->text());
			strname.append("aberration");strvalue.append(ui.colorAberrlineEdit->text());
			strname.append("sym");strvalue.append(ui.colorSymlineEdit->text());
			strname.append("falloff");strvalue.append(ui.colorFallofflineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "color", itemsuffix2, key);

			//color hb
			//(centerratio:0.1)(gmin:170)(gmax:180)(rgmin:0.6)(rgmax:0.7)(bgmin:0.6)(bgmax:0.7)
			//(ccrgmin:0.9)(ccrgmax:1.1)(ccbgmin:0.9)(ccbgmax:1.1)
			//(cpprgmin:0.9)(cpprgmax:1.1)(cppbgmin:0.9)(cppbgmax:1.1)
			//(roinumw:17)(roinumh:13)(apprgmin:0.9)(apprgmax:1.1)(appbgmin:0.9)(appbgmax:1.1)
			strname.clear();strvalue.clear();
			strname.append("centerratio");strvalue.append(ui.whitecolorhbCenterRatiodoubleSpinBox->cleanText());
			strname.append("gmin");strvalue.append(ui.whitecolorhbGMinspinBox->cleanText());
			strname.append("gmax");strvalue.append(ui.whitecolorhbGMaxspinBox->cleanText());
			strname.append("rgmin");strvalue.append(ui.whitecolorhbCenterRGMindoubleSpinBox->cleanText());
			strname.append("rgmax");strvalue.append(ui.whitecolorhbCenterRGMaxdoubleSpinBox->cleanText());
			strname.append("bgmin");strvalue.append(ui.whitecolorhbCenterBGMindoubleSpinBox->cleanText());
			strname.append("bgmax");strvalue.append(ui.whitecolorhbCenterBGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("ccrgmin");strvalue.append(ui.whitecolorhbCCRGMindoubleSpinBox->cleanText());
			strname.append("ccrgmax");strvalue.append(ui.whitecolorhbCCRGMaxdoubleSpinBox->cleanText());
			strname.append("ccbgmin");strvalue.append(ui.whitecolorhbCCBGMindoubleSpinBox->cleanText());
			strname.append("ccbgmax");strvalue.append(ui.whitecolorhbCCBGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("cpprgmin");strvalue.append(ui.whitecolorhbCornerPPRGMindoubleSpinBox->cleanText());
			strname.append("cpprgmax");strvalue.append(ui.whitecolorhbCornerPPRGMaxdoubleSpinBox->cleanText());
			strname.append("cppbgmin");strvalue.append(ui.whitecolorhbCornerPPBGMindoubleSpinBox->cleanText());
			strname.append("cppbgmax");strvalue.append(ui.whitecolorhbCornerPPBGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("roinumw");strvalue.append(ui.whitecolorhbROINumWspinBox->cleanText());
			strname.append("roinumh");strvalue.append(ui.whitecolorhbROINumHspinBox->cleanText());
			strname.append("apprgmin");strvalue.append(ui.whitecolorhbALLPPRGMindoubleSpinBox->cleanText());
			strname.append("apprgmax");strvalue.append(ui.whitecolorhbALLPPRGMaxdoubleSpinBox->cleanText());
			strname.append("appbgmin");strvalue.append(ui.whitecolorhbALLPPBGMindoubleSpinBox->cleanText());
			strname.append("appbgmax");strvalue.append(ui.whitecolorhbALLPPBGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "colorhb", itemsuffix2, key, value1, reserve);

			//
			//
			//(opticalcenteralg:a)(defectpixelalg:a)(defectlinealg:a)
			//(belmishalg:a)(coloralg:a)(shadingalg:a)(vignettingalg:a)
			strname.clear();strvalue.clear();
			strname.append("opticalcenteralg");
			if(ui.occomboBox->currentIndex() == 1){
				strvalue.append("b");
			}
			else if(ui.occomboBox->currentIndex() == 2){
				strvalue.append("c");
			}
			else if(ui.occomboBox->currentIndex() == 3){
				strvalue.append("d");
			}else{
				strvalue.append("a");
			}
				
			strname.append("defectpixelalg");
			if(ui.defectpixelcomboBox->currentIndex() == 0)	strvalue.append("a");
			else	strvalue.append("b");
			strname.append("defectlinealg");strvalue.append("a");
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("belmishalg");
			if(ui.blemishcomboBox->currentIndex() == 0)	strvalue.append("a");
			else if(ui.blemishcomboBox->currentIndex() == 1)	strvalue.append("b");
			else if(ui.blemishcomboBox->currentIndex() == 3)	strvalue.append("d");
			else strvalue.append("c");

			strname.append("coloralg");
			if(ui.colorcomboBox->currentIndex() == 0) strvalue.append("a");
			else strvalue.append("b");

			strname.append("shadingalg");
			if(ui.shadingcomboBox->currentIndex() == 0)	strvalue.append("a");
			else if(ui.shadingcomboBox->currentIndex() == 1)	strvalue.append("b");
			else if(ui.shadingcomboBox->currentIndex() == 2)	strvalue.append("c");
			else if(ui.shadingcomboBox->currentIndex() == 3)	strvalue.append("d");
			else if(ui.shadingcomboBox->currentIndex() == 4)	strvalue.append("e");
			else	strvalue.append("f");
			strname.append("vignettingalg");strvalue.append("a");
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "whitepanel", "total", itemsuffix2, key, value1, reserve);
			
			stSqlDB.commit();
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::blackpanel2UI()
{
	classItemProcess->getblackfieldParameter(true);

	if(itemshareData.blackfieldParameter)
	{
		ui.blackFieldLightDefspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.ui8LightPixelDef);
		ui.blackFieldClusterDefspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiClusterDef);
		ui.blackFieldCenterRatiospinBox->setValue(itemshareData.blackfieldParameter->stAlgA.ui8CenterRatio);
		ui.blackFieldCenterPixelspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiSpecCenterPixel);
		ui.blackFieldAroundPixelspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiSpecAroundPixel);
		ui.blackFieldCenterClusterspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiSpecCenterCluster);
		ui.blackFieldAroundClusterspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiSpecAroundCluster);
		ui.blackFieldMaxClusterspinBox->setValue(itemshareData.blackfieldParameter->stAlgA.uiSpecMaxCluster);

		ui.blackhbBlackLevelspinBox->setValue(itemshareData.blackfieldParameter->stAlgB.ucBlackLevel);
		ui.blackhbRGMindoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flRGMin);
		ui.blackhbRGMaxdoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flRGMax);
		ui.blackhbBGMindoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flBGMin);
		ui.blackhbBGMaxdoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flBGMax);
		ui.blackhbPPMindoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flPPMin);
		ui.blackhbPPMaxdoubleSpinBox->setValue(itemshareData.blackfieldParameter->stAlgB.flPPMax);

		ui.spinBox_bf_blc->setValue(itemshareData.blackfieldParameter->stAlgC.ucBlackLevel);
		ui.spinBox_bf_threshold->setValue(itemshareData.blackfieldParameter->stAlgC.flThreshold);
		ui.spinBox_bf_spec->setValue(itemshareData.blackfieldParameter->stAlgC.flChannelMax);
		ui.spinBox_bf_cellspec->setValue(itemshareData.blackfieldParameter->stAlgC.flCellMax);

		ui.blackFieldAlgcomboBox->setCurrentIndex(itemshareData.blackfieldParameter->ui8BlackFiledAlg);
		BlackLightPixelAlgSwitch(itemshareData.blackfieldParameter->ui8BlackFiledAlg);
	}

}

int configsetting::saveBlackPanel()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "blackfield");

			unsigned int uiIndex	=	_HisDB_Index_BlackField;

			//(lightdefine:30)(clusterdefine:6)(centerratio:50)
			//(centerlightspec:70)(arounglightspce:43)
			//(centerclusterspec:10)(aroundclusterspec:10)(maxclusterspec:10)
			strname.clear();strvalue.clear();
			strname.append("lightdefine");strvalue.append(QString::number(ui.blackFieldLightDefspinBox->value()));
			strname.append("clusterdefine");strvalue.append(QString::number(ui.blackFieldClusterDefspinBox->value()));
			strname.append("centerratio");strvalue.append(QString::number(ui.blackFieldCenterRatiospinBox->value()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("centerlightspec");strvalue.append(QString::number(ui.blackFieldCenterPixelspinBox->value()));
			strname.append("arounglightspce");strvalue.append(QString::number(ui.blackFieldAroundPixelspinBox->value()));
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("centerclusterspec");strvalue.append(QString::number(ui.blackFieldCenterClusterspinBox->value()));
			strname.append("aroundclusterspec");strvalue.append(QString::number(ui.blackFieldAroundClusterspinBox->value()));
			strname.append("maxclusterspec");strvalue.append(QString::number(ui.blackFieldMaxClusterspinBox->value()));
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "blackfield", "alga", itemsuffix2, key, value1);

			//blackfield hb
			//(blacklevel:0)
			//(rgmin:)(rgmax:)(bgmin:)(bgmax:)(ppmin:)(ppmax:)
			strname.clear();strvalue.clear();
			strname.append("blacklevel");	strvalue.append(ui.blackhbBlackLevelspinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("rgmin");	strvalue.append(ui.blackhbRGMindoubleSpinBox->cleanText());
			strname.append("rgmax");	strvalue.append(ui.blackhbRGMaxdoubleSpinBox->cleanText());
			strname.append("bgmin");	strvalue.append(ui.blackhbBGMindoubleSpinBox->cleanText());
			strname.append("bgmax");	strvalue.append(ui.blackhbBGMaxdoubleSpinBox->cleanText());
			strname.append("ppmin");	strvalue.append(ui.blackhbPPMindoubleSpinBox->cleanText());
			strname.append("ppmax");	strvalue.append(ui.blackhbPPMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "blackfield", "algb", itemsuffix2, key);

			strname.clear();strvalue.clear();
			strname.append("blacklevel");	strvalue.append(ui.spinBox_bf_blc->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("threshold");	strvalue.append(ui.spinBox_bf_threshold->cleanText());
			strname.append("channelspec");	strvalue.append(ui.spinBox_bf_spec->cleanText());
			strname.append("cellspec");	strvalue.append(ui.spinBox_bf_cellspec->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "blackfield", "algc", itemsuffix2, key);

			//(alg:a)(digitalgain:1)(analoggain:1)(framesleep:500)
			strname.clear(); strvalue.clear();
			strname.append("alg");
			if(ui.blackFieldAlgcomboBox->currentIndex() == 0)	strvalue.append("a");
			else if(ui.blackFieldAlgcomboBox->currentIndex() == 1) strvalue.append("b");
			else if(ui.blackFieldAlgcomboBox->currentIndex() == 2) strvalue.append("c");

			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "blackfield", "total", itemsuffix2);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::otpBurn2UI()
{
	classItemProcess->getotpburnParameter(true, false);
	if(!itemshareData.otpburnParameter) return;

	ui.otpBurncheckBox->setChecked(itemshareData.otpburnParameter->bburn);
	ui.otpLightCorrectcheckBox->setChecked(itemshareData.otpburnParameter->bLightCorrect);
	ui.burnopticalcentercheckBox->setChecked(itemshareData.otpburnParameter->bBurnOpticalCenter);
	ui.otpCheckOnlyDatacheckBox->setChecked(itemshareData.otpburnParameter->bOnlyCheckData);
	ui.otpBurnFrameSleepspinBox->setValue(itemshareData.otpburnParameter->uiFrameSleep);
	ui.otpBurnLuxMinspinBox->setValue(itemshareData.otpburnParameter->uiLuxMin);
	ui.otpBurnLuxMaxspinBox->setValue(itemshareData.otpburnParameter->uiLuxMax);
	ui.otpBurnOBspinBox->setValue(itemshareData.otpburnParameter->uiDark);

	if(itemshareData.otpburnParameter->uiBlockSize == 5)	ui.otpBurnBlockSizecomboBox->setCurrentIndex(0);
	else if(itemshareData.otpburnParameter->uiBlockSize == 7)	ui.otpBurnBlockSizecomboBox->setCurrentIndex(1);
	else if(itemshareData.otpburnParameter->uiBlockSize == 9)	ui.otpBurnBlockSizecomboBox->setCurrentIndex(2);
	else	ui.otpBurnBlockSizecomboBox->setCurrentIndex(3);

	ui.otpBurnLightRlineEdit->setText(QString::number(itemshareData.otpburnParameter->dflLightCoeR));
	ui.otpBurnLightBlineEdit->setText(QString::number(itemshareData.otpburnParameter->dflLightCoeB));
	ui.otpBurnMIDlineEdit->setText(QString::number(itemshareData.otpburnParameter->uiMID, 16));
	ui.otpBurnLENSIDlineEdit->setText(QString::number(itemshareData.otpburnParameter->uiLENSID, 16));
	ui.otpBurnVCMIDlineEdit->setText(QString::number(itemshareData.otpburnParameter->uiVCMID, 16));
	ui.otpBurnDRIVERIDlineEdit->setText(QString::number(itemshareData.otpburnParameter->uiDRIVERICID, 16));
	ui.otpBurnCenterRangelineEdit->setText(QString::number(itemshareData.otpburnParameter->flRangeRatio));
	ui.otpBurnLSCShadingMinlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_LuxShadingMin));
	ui.otpBurnLSCShadingMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_LuxShadingMax));
	ui.otpBurnLSCCornerUniformlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_LuxShadingUniform));
	ui.otpBurnLSCSymmMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_LuxSymmMax));
	ui.otpBurnLSCCenterRGrMinlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_CenterR2GrMin));
	ui.otpBurnLSCCenterRGrMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_CenterR2GrMax));
	ui.otpBurnLSCCenterBGrMinlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_CenterB2GrMin));
	ui.otpBurnLSCCenterBGrMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_CenterB2GrMax));
	ui.otpBurnLSCR2Gr2CenterMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_WB2CenterMax_R2Gr));
	ui.otpBurnLSCB2Gr2CenterMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->flLSC_WB2CenterMax_B2Gr));
	ui.OCXDeviationMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->iOCXDeviationMax));
	ui.OCYDeviationMaxlineEdit->setText(QString::number(itemshareData.otpburnParameter->iOCYDeviationMax));

	ui.otpBurnGetFunListcomboBox->setCurrentIndex(ui.otpBurnGetFunListcomboBox->findText(itemshareData.otpburnParameter->strFunctionChoose));
	
	QString reserve	=	itemshareData.otpburnParameter->pairConfig.remove("(");
	reserve	=	reserve.replace(")", "\n");
	ui.otpBurnplainTextEdit->setPlainText(reserve);
}

int configsetting::saveOtpBurnData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "sensor", "otpburn");

			unsigned int uiIndex	=	_HisDB_Index_OTPBurn;

			//(burn:true)(onlycheckdata:true)(sleep:1000)(luxmin:118)(luxmax:138)(lsc_shadinguniform:0.3)(blocksize:5)(curfun:OV8858_INTEL_SENSOR_RULE1)
			//(mid:0x01)(lensid:0x01)(vcmid:0x01)(driverid:0x01)(centerrange:0.2)(lightcomp_b:1.0)((lightcomp_r:1.0))
			//(lsc_shadingmin:0.1)(lsc_shadingmax:0.2)(lsc_luxsymm:0.05)(lsc_centerr2grmin:0.5)(lsc_centerr2grmax:1.5)---
			//---(lsc_centerb2grmin:0.5)(lsc_centerb2grmax:1.5)(lsc_b2gr2centermax:0.5)(lsc_r2gr2centermax:1.5)
			//paint text
			strname.clear();	strvalue.clear();
			strname.append("burn");	strvalue.append((ui.otpBurncheckBox->isChecked())?("true"):("false"));
			strname.append("light_correct");	strvalue.append((ui.otpLightCorrectcheckBox->isChecked())?("true"):("false"));
			strname.append("burnOpticalCenter");	strvalue.append((ui.burnopticalcentercheckBox->isChecked())?("true"):("false"));
			strname.append("onlycheckdata");	strvalue.append((ui.otpCheckOnlyDatacheckBox->isChecked())?("true"):("false"));
			strname.append("curfun");	strvalue.append(ui.otpBurnGetFunListcomboBox->currentText().toLower());
			strname.append("sleep");	strvalue.append(QString::number(ui.otpBurnFrameSleepspinBox->value()));
			strname.append("ob");	strvalue.append(QString::number(ui.otpBurnOBspinBox->value()));
			strname.append("luxmin");	strvalue.append(QString::number(ui.otpBurnLuxMinspinBox->value()));
			strname.append("luxmax");	strvalue.append(QString::number(ui.otpBurnLuxMaxspinBox->value()));
			strname.append("lsc_shadinguniform");strvalue.append(ui.otpBurnLSCCornerUniformlineEdit->text());
			strname.append("blocksize");
			if(ui.otpBurnBlockSizecomboBox->currentIndex() == 0)	strvalue.append("5");
			else if(ui.otpBurnBlockSizecomboBox->currentIndex() == 1)	strvalue.append("7");
			else if(ui.otpBurnBlockSizecomboBox->currentIndex() == 2)	strvalue.append("9");
			else	strvalue.append("11");
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("mid");strvalue.append("0x" % ui.otpBurnMIDlineEdit->text());
			strname.append("lensid");strvalue.append("0x" % ui.otpBurnLENSIDlineEdit->text());
			strname.append("vcmid");strvalue.append("0x" % ui.otpBurnVCMIDlineEdit->text());
			strname.append("driverid");strvalue.append("0x" % ui.otpBurnDRIVERIDlineEdit->text());
			strname.append("centerrange");strvalue.append(ui.otpBurnCenterRangelineEdit->text());
			strname.append("lightcomp_b");strvalue.append(ui.otpBurnLightBlineEdit->text());
			strname.append("lightcomp_r");strvalue.append(ui.otpBurnLightRlineEdit->text());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("lsc_shadingmin");strvalue.append(ui.otpBurnLSCShadingMinlineEdit->text());
			strname.append("lsc_shadingmax");strvalue.append(ui.otpBurnLSCShadingMaxlineEdit->text());
			strname.append("lsc_luxsymm");strvalue.append(ui.otpBurnLSCSymmMaxlineEdit->text());
			strname.append("lsc_centerr2grmin");strvalue.append(ui.otpBurnLSCCenterRGrMinlineEdit->text());
			strname.append("lsc_centerr2grmax");strvalue.append(ui.otpBurnLSCCenterRGrMaxlineEdit->text());
			strname.append("lsc_centerb2grmin");strvalue.append(ui.otpBurnLSCCenterBGrMinlineEdit->text());
			strname.append("lsc_centerb2grmax");strvalue.append(ui.otpBurnLSCCenterBGrMaxlineEdit->text());
			strname.append("lsc_b2gr2centermax");strvalue.append(ui.otpBurnLSCB2Gr2CenterMaxlineEdit->text());
			strname.append("lsc_r2gr2centermax");strvalue.append(ui.otpBurnLSCR2Gr2CenterMaxlineEdit->text());
			strname.append("ocxdeviationmax");strvalue.append(ui.OCXDeviationMaxlineEdit->text());
			strname.append("ocydeviationmax");strvalue.append(ui.OCYDeviationMaxlineEdit->text());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			reserve	=	ui.otpBurnplainTextEdit->toPlainText();
			reserve	=	reserve.trimmed();
			reserve	=	reserve.remove("\r");
			reserve	=	reserve.remove("\t");
			//reserve	=	reserve.remove(" ");
			reserve	=	reserve.replace("\n", ")(");
			reserve.append(")");
			reserve.prepend("(");
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "sensor", "otpburn", QVariant(), itemsuffix2, key, value1, reserve);
			
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::afBurn2UI()
{
	classItemProcess->getafburnParameter(true, false);
	if(!itemshareData.afburnParameter) return;

	ui.afBurnGetFunListcomboBox->setCurrentIndex(ui.afBurnGetFunListcomboBox->findText(itemshareData.afburnParameter->strFunctionChoose));
	ui.afburnDelayspinBox->setValue(itemshareData.afburnParameter->uiFrameDelay);
	ui.afburnMachinespinBox->setValue(itemshareData.afburnParameter->uiMachineCode);
	ui.afburnNearcheckBox->setChecked(itemshareData.afburnParameter->bNear);
	ui.afburnNearOffsetspinBox->setValue(itemshareData.afburnParameter->iNearMotorOffset);
	ui.afburnNearMinspinBox->setValue(itemshareData.afburnParameter->iNearMotorMin);
	ui.afburnNearMaxspinBox->setValue(itemshareData.afburnParameter->iNearMotorMax);

	ui.afburnMiddlecheckBox->setChecked(itemshareData.afburnParameter->bMiddle);
	ui.afburnMiddleOffsetspinBox->setValue(itemshareData.afburnParameter->iMiddleMotorOffset);
	ui.afburnMiddleMinspinBox->setValue(itemshareData.afburnParameter->iMiddleMotorMin);
	ui.afburnMiddleMaxspinBox->setValue(itemshareData.afburnParameter->iMiddleMotorMax);

	ui.afburnInfinitecheckBox->setChecked(itemshareData.afburnParameter->bInfinite);
	ui.afburnFarOffsetspinBox->setValue(itemshareData.afburnParameter->iFarMotorOffset);
	ui.afburnFarMinspinBox->setValue(itemshareData.afburnParameter->iFarMotorMin);
	ui.afburnFarMaxspinBox->setValue(itemshareData.afburnParameter->iFarMotorMax);

	ui.checkBox_ReCal->setChecked(itemshareData.afburnParameter->bRecalCheck);
	ui.spinBox_AfRecalSpec->setValue(itemshareData.afburnParameter->iRecalSpec);
	ui.NearInfSub_spinBox->setValue(itemshareData.afburnParameter->MotorSub);
}

int configsetting::saveAfBurnData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "afburn");

			unsigned int uiIndex	=	_HisDB_Index_AFBurn;

			//(framedelay:500)(machine:0)(curfun:rule)
			//(nearaf:on)(nearoffset:0)(nearmin:0)(nearmax:1023)
			//(middleaf:on)(middleoffset:0)(middlemin:0)(middlemax:1023)
			//(infiniteaf:on)(faroffset:0)(farmin:0)(farmax:1023)
			strname.clear();	strvalue.clear();
			strname.append("framedelay");strvalue.append(ui.afburnDelayspinBox->cleanText());
			strname.append("machine");strvalue.append(ui.afburnMachinespinBox->cleanText());
			strname.append("curfun");strvalue.append(ui.afBurnGetFunListcomboBox->currentText().toLower());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("nearaf");		strvalue.append((ui.afburnNearcheckBox->isChecked())?("on"):("off"));
			strname.append("nearoffset");strvalue.append(ui.afburnNearOffsetspinBox->cleanText());
			strname.append("nearmin");	strvalue.append(ui.afburnNearMinspinBox->cleanText());
			strname.append("nearmax");	strvalue.append(ui.afburnNearMaxspinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("middleaf");		strvalue.append((ui.afburnMiddlecheckBox->isChecked())?("on"):("off"));
			strname.append("middleoffset");strvalue.append(ui.afburnMiddleOffsetspinBox->cleanText());
			strname.append("middlemin");	strvalue.append(ui.afburnMiddleMinspinBox->cleanText());
			strname.append("middlemax");	strvalue.append(ui.afburnMiddleMaxspinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("infiniteaf");	strvalue.append((ui.afburnInfinitecheckBox->isChecked())?("on"):("off"));
			strname.append("faroffset");	strvalue.append(ui.afburnFarOffsetspinBox->cleanText());
			strname.append("farmin");		strvalue.append(ui.afburnFarMinspinBox->cleanText());
			strname.append("farmax");		strvalue.append(ui.afburnFarMaxspinBox->cleanText());
			
			strname.append("recalaf");		strvalue.append((ui.checkBox_ReCal->isChecked())?("on"):("off"));
			strname.append("recalspec");		strvalue.append(ui.spinBox_AfRecalSpec->cleanText());
			strname.append("subnearinf");	strvalue.append (ui.NearInfSub_spinBox->cleanText());

			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "afburn",  QVariant(), itemsuffix2, key, value1, reserve);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::pdafBurn2UI()
{
	classItemProcess->getpdafParameter(true, false);
	if(!itemshareData.pdafParameter) return;

	ui.mtkpdafBlackMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO7Sleep);
	ui.mtkpdafRelayMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO3Sleep);
	ui.mtkpdaf15CMMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO6Sleep);
	ui.mtkpdafWhiteMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO8Sleep);
	ui.mtkpdafNearMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO5Sleep);
	ui.mtkpdaf6CMMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO4Sleep);
	ui.mtkpdafInfiniteMoveSleepspinBox->setValue(itemshareData.pdafParameter->uiIO9Sleep);
	ui.mtkpdafMotorSleepspinBox->setValue(itemshareData.pdafParameter->uiMotorSleep);

	ui.pdafPlatformcomboBox->setCurrentIndex(itemshareData.pdafParameter->ucPlatform);
	this->slotPDAFplatformChange(itemshareData.pdafParameter->ucPlatform);
	ui.mtkpdafAFBurnGetFunListcomboBox->setCurrentIndex(ui.mtkpdafAFBurnGetFunListcomboBox->findText(itemshareData.pdafParameter->strAFChoose.toUpper()));
	ui.mtkpdafStep1White2NearcheckBox->setChecked(itemshareData.pdafParameter->bWhiteMove2NearFocus);

	QString strVersion	=	QString::number(itemshareData.pdafParameter->usVersion[3]) % "." % QString::number(itemshareData.pdafParameter->usVersion[2]) % "." % \
		QString::number(itemshareData.pdafParameter->usVersion[1]) % "." % QString::number(itemshareData.pdafParameter->usVersion[0]);
	if(itemshareData.pdafParameter->usVersion[3]==3&&itemshareData.pdafParameter->usVersion[0]==525)
	{
		strVersion	=	QString::number(itemshareData.pdafParameter->usVersion[3]) % "." % QString::number(itemshareData.pdafParameter->usVersion[2]) % "." % \
			QString::number(itemshareData.pdafParameter->usVersion[1]) % ".0" % QString::number(itemshareData.pdafParameter->usVersion[0]);
	}
	ui.mtkpdafLibVersioncomboBox->setCurrentIndex(ui.mtkpdafLibVersioncomboBox->findText(strVersion));
	
	changeMTKPDAFVersion(strVersion);

	ui.mtkpdafBurnGetFunListcomboBox->setCurrentIndex(ui.mtkpdafBurnGetFunListcomboBox->findText(itemshareData.pdafParameter->strPDAFChoose.toUpper()));
	char cVersion	=	itemshareData.pdafParameter->cVersion.toAscii();
	ui.qualcommpdafLibVersioncomboBox->setCurrentIndex(ui.qualcommpdafLibVersioncomboBox->findText(QString::fromAscii(&cVersion, 1)));
	ui.qualcommpdafBurnGetFunListcomboBox->setCurrentIndex(ui.qualcommpdafBurnGetFunListcomboBox->findText(itemshareData.pdafParameter->strQualcommChoose));
	ui.qualcommpdafKVerifycheckbox->setChecked(itemshareData.pdafParameter->bQualcommpdafverify);
	ui.qualcommpdafKVerifyOffestspinBox->setValue(itemshareData.pdafParameter->usQualcommkverifyoffest);
	ui.qualcomverifyDACshiftCntspinBox->setValue(itemshareData.pdafParameter->usVerifyDACShiftCount);
	ui.qualcommverifyVCMSTEPspinBox->setValue(itemshareData.pdafParameter->usDACMoveStep);
	ui.MTFDropStopcheckbox->setChecked(itemshareData.pdafParameter->bPDAFVerifyMTFDropStop);
	ui.qualcommSTEP2AEcheckBox->setChecked(itemshareData.pdafParameter->bQualcomm50CMexp);
	ui.qualcomm50cmAEroiwspinBox->setValue(itemshareData.pdafParameter->usAutoExpsoureROIW);
	ui.qualcomm50cmAEroihspinBox->setValue(itemshareData.pdafParameter->usAutoExposureROIH);
	ui.cdafmtfroiWspinBox->setValue(itemshareData.pdafParameter->usCDAFmtfROIW);
	ui.cdafmtfroiHspinBox->setValue(itemshareData.pdafParameter->usCDAFmtfROIH);
	ui.qualcomm2pdblacklevelspinBox->setValue(itemshareData.pdafParameter->usSensorBlackLevel);	
	ui.qualcommpdaf50cmdealyspinBox->setValue(itemshareData.pdafParameter->us50CMEVDelayTime);
	ui.qualcomverifyDACshiftCntspinBox->setValue(itemshareData.pdafParameter->usVerifyDACShiftCount);
	ui.qualcommverifyVCMSTEPspinBox->setValue(itemshareData.pdafParameter->usDACMoveStep);
	ui.MTFDropStopcheckbox->setChecked(itemshareData.pdafParameter->bPDAFVerifyMTFDropStop); 
	ui.sony25pdafSPCcheckBox->setChecked(itemshareData.pdafParameter->bSONY258MTKCal); 
	ui.SONYpdafBurnGetFunListcomboBox->setCurrentIndex(ui.SONYpdafBurnGetFunListcomboBox->findText(itemshareData.pdafParameter->strSONYPDAFChoose));
	ui.qualcommgainmapformatcomboBox->setCurrentIndex((itemshareData.pdafParameter->strQualcommGainMapStruct=="1D")?1:0);
	ui.qualcommgainmapsizespinBox->setValue(itemshareData.pdafParameter->usQualcommGainMapSize);
	ui.sonyspcgainsizespinBox->setValue(itemshareData.pdafParameter->usSonySPCTableSize);
	ui.sonydccwindowcomboBox->setCurrentIndex(itemshareData.pdafParameter->ucSonyDCCWindow);
	ui.sonysensormodecomboBox->setCurrentIndex(itemshareData.pdafParameter->ucSonySensorMode);
	ui.dccverifyspecdoubleSpinBox->setValue(itemshareData.pdafParameter->dDCCVerifySpec);
	ui.mtkv2step1sizespinBox->setValue(itemshareData.pdafParameter->usMTKV2Step1dataSize);
	ui.mtkv2step2sizespinBox->setValue(itemshareData.pdafParameter->usMTKV2Step2dataSize);
	ui.mtkstep2verifycheckBox->setChecked(itemshareData.pdafParameter->bEnableMTKStep2Verify); 
	ui.pdtypecomboBox->setCurrentIndex(itemshareData.pdafParameter->ucpdafsensortype);

	ui.HISIpdafBurnGetFunListcomboBox->setCurrentIndex(ui.HISIpdafBurnGetFunListcomboBox->findText(itemshareData.pdafParameter->strHISIPDAFChoose.toUpper()));
}

int configsetting::savePDAFBurnData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QString strVersion	=	ui.mtkpdafLibVersioncomboBox->currentText();
			unsigned short usVersion[4] = {0};
			if(!strVersion.isEmpty()){
				strname	=	strVersion.split(".");
				if(strname.size() == 4){
					usVersion[3]	=	strname.at(0).toUShort();
					usVersion[2]	=	strname.at(1).toUShort();
					usVersion[1]	=	strname.at(2).toUShort();
					usVersion[0]	=	strname.at(3).toUShort();
				}
			}

			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "mtkpdaf");

			unsigned int uiIndex	=	_HisDB_Index_MTKPDAF;

			//(qualcommchoose:3m2)(afchoose:3m2)(pdafchoose:3m2)(version3:2)(version2:0)(version1:0)(version0:299)
			//(blacksleep:1000)(whitesleep:1000)(6cmsleep:1000)(relaysleep:1000)(nearsleep:1000)(infinitesleep:1000)(15cmsleep:1000)
			//(motorsleep:1000(white2near:true)(platform:MTK)(qualcommversion:J)(coefkdiff:20)
			strname.clear();strvalue.clear();
			strname.append("qualcommchoose");strvalue.append(ui.qualcommpdafBurnGetFunListcomboBox->currentText().toLower());
			strname.append("afchoose");strvalue.append(ui.mtkpdafAFBurnGetFunListcomboBox->currentText().toLower());
			strname.append("pdafchoose");strvalue.append(ui.mtkpdafBurnGetFunListcomboBox->currentText().toLower());
			strname.append("version3");strvalue.append(QString::number(usVersion[3]));
			strname.append("version2");strvalue.append(QString::number(usVersion[2]));
			strname.append("version1");strvalue.append(QString::number(usVersion[1]));
			strname.append("version0");strvalue.append(QString::number(usVersion[0]));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("blacksleep");strvalue.append(QString::number(ui.mtkpdafBlackMoveSleepspinBox->value()));
			strname.append("whitesleep");strvalue.append(QString::number(ui.mtkpdafWhiteMoveSleepspinBox->value()));
			strname.append("6cmsleep");strvalue.append(QString::number(ui.mtkpdaf6CMMoveSleepspinBox->value()));
			strname.append("relaysleep");strvalue.append(QString::number(ui.mtkpdafRelayMoveSleepspinBox->value()));
			strname.append("nearsleep");strvalue.append(QString::number(ui.mtkpdafNearMoveSleepspinBox->value()));
			strname.append("infinitesleep");strvalue.append(QString::number(ui.mtkpdafInfiniteMoveSleepspinBox->value()));
			strname.append("15cmsleep");strvalue.append(QString::number(ui.mtkpdaf15CMMoveSleepspinBox->value()));
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("motorsleep");strvalue.append(QString::number(ui.mtkpdafMotorSleepspinBox->value()));
			strname.append("white2near");strvalue.append((ui.mtkpdafStep1White2NearcheckBox->isChecked())?("true"):("false"));
			strname.append("platform");strvalue.append(ui.pdafPlatformcomboBox->currentText());
			strname.append("qualcommversion");strvalue.append(ui.qualcommpdafLibVersioncomboBox->currentText());
			//strname.append("coefkdiff");strvalue.append(ui.qualcommpdafCoefKspinBox->cleanText());
			strname.append("pdafverify");strvalue.append((ui.qualcommpdafKVerifycheckbox->isChecked())?("true"):("false"));
			strname.append("pdafverifyoffest");strvalue.append(ui.qualcommpdafKVerifyOffestspinBox->cleanText());
			strname.append("pdafstep2_50cmatuoexposure");strvalue.append((ui.qualcommSTEP2AEcheckBox->isChecked())?("true"):("false"));
			strname.append("KVerify_DACShiftSTEP");strvalue.append(ui.qualcomverifyDACshiftCntspinBox->cleanText());
			strname.append("KVerify_VCMSTEP");strvalue.append(ui.qualcommverifyVCMSTEPspinBox->cleanText());
			strname.append("pdafverifyMTFdropstop");strvalue.append((ui.MTFDropStopcheckbox->isChecked())?("true"):("false"));
			strname.append("pdafstep2_50cmAEROIW");strvalue.append(ui.qualcomm50cmAEroiwspinBox->cleanText());
			strname.append("pdafstep2_50cmAEROIH");strvalue.append(ui.qualcomm50cmAEroiwspinBox->cleanText());
			strname.append("CDAFmtfsearchROIW");strvalue.append(ui.cdafmtfroiWspinBox->cleanText());
			strname.append("CDAFmtfsearchROIH");strvalue.append(ui.cdafmtfroiHspinBox->cleanText());
			strname.append("pdafstep2_50cmEVdelaytime");strvalue.append(ui.qualcommpdaf50cmdealyspinBox->cleanText());
			strname.append("qualcommgainmapformat");strvalue.append(ui.qualcommgainmapformatcomboBox->currentText());
			strname.append("qualcommgainmapsize");strvalue.append(ui.qualcommgainmapsizespinBox->cleanText());
			strname.append("qualcommpdsensortype"); strvalue.append(QString::number(ui.pdtypecomboBox->currentIndex()));
			strname.append("qualcommpdsensorblacklevel"); strvalue.append(QString::number(ui.qualcomm2pdblacklevelspinBox->value()));
			strname.append("sony258_pdafspccal");strvalue.append((ui.sony25pdafSPCcheckBox->isChecked())?("true"):("false"));
			strname.append("sonypdafchoose");strvalue.append(ui.SONYpdafBurnGetFunListcomboBox->currentText().toLower());
			strname.append("sonydccwindow");strvalue.append(ui.sonydccwindowcomboBox->currentText());
			strname.append("sonyspctablesize");strvalue.append(ui.sonyspcgainsizespinBox->cleanText());
			strname.append("sonysensormode");strvalue.append(ui.sonysensormodecomboBox->currentText());
			strname.append("dccverifyspec");strvalue.append(ui.dccverifyspecdoubleSpinBox->cleanText());
			strname.append("mtkv2step1datasize");strvalue.append(ui.mtkv2step1sizespinBox->cleanText());
			strname.append("mtkv2step2datasize");strvalue.append(ui.mtkv2step2sizespinBox->cleanText());
			strname.append("mtkstep2verify");strvalue.append((ui.mtkstep2verifycheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "mtkpdaf",  QVariant(), itemsuffix2, key, value1);

			strname.clear();strvalue.clear();
			strname.append("hisipdafchoose");strvalue.append(ui.HISIpdafBurnGetFunListcomboBox->currentText().toLower());
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "mtkpdaf",  QVariant(), itemsuffix2, key, value1);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::logData2UI()
{
	classItemProcess->getsavelogParameter(true, false);
	if(!itemshareData.savelogParameter) return;

	if(itemshareData.savelogParameter->ucSerialNumberSource == _His_SerialNumber_Vision) ui.snFromVisionradioButton->setChecked(true);
	else if(itemshareData.savelogParameter->ucSerialNumberSource == _His_SerialNumber_OTP) ui.snFromOTPradioButton->setChecked(true);
	else if(itemshareData.savelogParameter->ucSerialNumberSource == _His_SerialNumber_Chip) ui.snFromChipradioButton->setChecked(true);
	else ui.snFromTextradioButton->setChecked(true);

	ui.snFormatlineEdit->setText(itemshareData.savelogParameter->strSerialNumberFormat);

	if(itemshareData.savelogParameter->ucSerialNumberSource == _His_SerialNumber_Chip)
	{
		ui.chipIDplainTextEdit->setPlainText(itemshareData.savelogParameter->strCHIPIDIIC);
		ui.chipIDcomboBox->setCurrentIndex(ui.chipIDcomboBox->findText(itemshareData.savelogParameter->strChipIDSensorType));
	}

}

int configsetting::saveLogData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "other", "savelog");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "other", "chipid");

			unsigned int uiIndex	=	_HisDB_Index_ChipID;

			//(snsource:text)(snformat:*)
			strname.clear();strvalue.clear();
			strname.append("snsource");
			if(ui.snFromOTPradioButton->isChecked())				strvalue.append("otp");
			else if(ui.snFromVisionradioButton->isChecked())	strvalue.append("vision");
			else if(ui.snFromChipradioButton->isChecked())		strvalue.append("chip");
			else		strvalue.append("text");
			strname.append("snformat");	strvalue.append((ui.snFormatlineEdit->text().isEmpty())?("*"):(ui.snFormatlineEdit->text()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "other", "savelog",  QVariant(), itemsuffix2);

			strname.clear();	strvalue.clear();
			strname.append("sensor");	strvalue.append(ui.chipIDcomboBox->currentText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "other", "chipid",  "total", itemsuffix2);

			QString strtext	=	ui.chipIDplainTextEdit->toPlainText() % "\n";
			QString strdata;
			if(strtext.size() > 9)
			{
				QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
				if(lines.size() > 0)
				{
					int isize	=	lines.size();
					for(int i=0;	i<isize;	++i)
					{
						strdata	=	lines.at(i);
						strdata	=	strdata.toLower();
						strdata		=	strdata.trimmed();
						strdata		=	strdata.remove(" ");
						strdata		=	strdata.remove("\t");
						strdata		=	strdata.remove("\r");
						if(strdata.count("0x") > 2 && strdata.count(",") > 3 && (strdata.contains("sleep") || strdata.contains("write") || strdata.contains("read"))){
								HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "other", "chipid",  "iic", QVariant(), QVariant(), strdata);
						}
					}
				}
			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::customIIC2UI()
{
	classItemProcess->getCustomIICGParameter(true, 1, false);
	classItemProcess->getCustomIICGParameter(true, 2, false);
	classItemProcess->getCustomIICGParameter(true, 3, false);
	classItemProcess->getCustomIICGParameter(true, 4, false);

	if(itemshareData.customIICG1Parameter)
	{
		QString strText;
		for(unsigned int x=0;	x<itemshareData.customIICG1Parameter->usCount;	++x)
		{
			strText	=	strText % "0x" % QString::number(itemshareData.customIICG1Parameter->pucSlave[x], 16) % ",0x" % QString::number(itemshareData.customIICG1Parameter->puiAddr[x], 16) % \
				",0x" % QString::number(itemshareData.customIICG1Parameter->puiData[x], 16) % ",0x" % QString::number(itemshareData.customIICG1Parameter->pusType[x], 16) % "\n";
			ui.customIICG1plainTextEdit->setPlainText(strText);
		}
	}

	if(itemshareData.customIICG2Parameter)
	{
		QString strText;
		for(unsigned int x=0;	x<itemshareData.customIICG2Parameter->usCount;	++x)
		{
			strText	=	strText % "0x" % QString::number(itemshareData.customIICG2Parameter->pucSlave[x], 16) % ",0x" % QString::number(itemshareData.customIICG2Parameter->puiAddr[x], 16) % \
				",0x" % QString::number(itemshareData.customIICG2Parameter->puiData[x], 16) % ",0x" % QString::number(itemshareData.customIICG2Parameter->pusType[x], 16) % "\n";
			ui.customIICG2plainTextEdit->setPlainText(strText);
		}
	}

	if(itemshareData.customIICG3Parameter)
	{
		QString strText;
		for(unsigned int x=0;	x<itemshareData.customIICG3Parameter->usCount;	++x)
		{
			strText	=	strText % "0x" % QString::number(itemshareData.customIICG3Parameter->pucSlave[x], 16) % ",0x" % QString::number(itemshareData.customIICG3Parameter->puiAddr[x], 16) % \
				",0x" % QString::number(itemshareData.customIICG3Parameter->puiData[x], 16) % ",0x" % QString::number(itemshareData.customIICG3Parameter->pusType[x], 16) % "\n";
			ui.customIICG3plainTextEdit->setPlainText(strText);
		}
	}

	if(itemshareData.customIICG4Parameter)
	{
		QString strText;
		for(unsigned int x=0;	x<itemshareData.customIICG4Parameter->usCount;	++x)
		{
			strText	=	strText % "0x" % QString::number(itemshareData.customIICG4Parameter->pucSlave[x], 16) % ",0x" % QString::number(itemshareData.customIICG4Parameter->puiAddr[x], 16) % \
				",0x" % QString::number(itemshareData.customIICG4Parameter->puiData[x], 16) % ",0x" % QString::number(itemshareData.customIICG4Parameter->pusType[x], 16) % "\n";
			ui.customIICG4plainTextEdit->setPlainText(strText);
		}
	}
}

int configsetting::saveCustomIICData(unsigned int uiGroup)
{
	int iresult	=	0;
	QString strKey;
	QPlainTextEdit* pstEdit;
	unsigned int uiIndex;
	if(uiGroup == 1){ strKey	=	"customiicg1"; pstEdit	=	ui.customIICG1plainTextEdit; uiIndex = _HisDB_Index_CustomI2cG1; }
	else if(uiGroup == 2){ strKey	=	"customiicg2"; pstEdit	=	ui.customIICG2plainTextEdit; uiIndex = _HisDB_Index_CustomI2cG2; }
	else if(uiGroup == 3){ strKey	=	"customiicg3"; pstEdit	=	ui.customIICG3plainTextEdit; uiIndex = _HisDB_Index_CustomI2cG3; }
	else { strKey	=	"customiicg4"; pstEdit	=	ui.customIICG4plainTextEdit; uiIndex = _HisDB_Index_CustomI2cG4; }

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "platform", strKey, "custom_i2c");

			QString strtext	=	pstEdit->toPlainText() % "\n";
			QString strdata, strdata2;
			int iindex1, iindex2, iindex3, imax, imin;
			if(strtext.size() > 9)
			{
				QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
				if(lines.size() > 0)
				{
					int isize	=	lines.size();
					for(int i=0;	i<isize;	++i)
					{
						strdata	=	lines.at(i);
						strdata	=	strdata.toLower();
						if(strdata.count("0x") > 3 && strdata.count(",") > 2){
							iindex1 = strdata.indexOf("/");
							iindex2	=	strdata.indexOf("\\");
							iindex3	=	strdata.indexOf(";");
							if((iindex1 < 0 || iindex1 > 9) && (iindex2 < 0 || iindex2 > 9) && (iindex3 < 0 || iindex3 > 9)){
								strdata2	=	"";
								imax			=	(iindex1 > iindex2)?(iindex1):(iindex2);
								imax			=	(iindex3 > imax)?(iindex3):(imax);
								if(imax > 0){
									imin	=	0xFFFF;
									imin	=	(iindex1 < 0)?(imin):((iindex1<imin)?(iindex1):(imin));
									imin	=	(iindex2 < 0)?(imin):((iindex2<imin)?(iindex2):(imin));
									imin	=	(iindex3 < 0)?(imin):((iindex3<imin)?(iindex3):(imin));
									strdata2	=	strdata.right(strdata.size() - imin -1);
									strdata2	=	strdata2.trimmed();
									strdata		=	strdata.left(imin);
									strdata		=	strdata.trimmed();
									strdata		=	strdata.remove(" ");
									strdata		=	strdata.remove("\t");
									strdata		=	strdata.remove("\r");
									if(strdata.count("0x") == 4 && strdata.count(",") == 3){
										HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "platform", strKey,  "custom_i2c", QVariant(), QVariant(), strdata, QVariant(), strdata2);
									}
								}
								else{
									strdata		=	strdata.trimmed();
									strdata		=	strdata.remove(" ");
									strdata		=	strdata.remove("\t");
									strdata		=	strdata.remove("\r");
									if(strdata.count("0x") == 4 && strdata.count(",") == 3){
										HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "platform", strKey,  "custom_i2c", QVariant(), QVariant(), strdata, QVariant(), strdata2);
									}
								}
							}
						}
					}
				}
			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::workCurrent2UI()
{
	classItemProcess->getworkcurrentParameter(true, false);
	if(!itemshareData.workcurrentParameter) return;

	ui.checkBox_workcurrent_dovdd->setChecked(itemshareData.workcurrentParameter->btestDOVDD);
	ui.spec_workcurrent_dovdd_min->setValue(itemshareData.workcurrentParameter->flSpecDOVDDMin);
	ui.spec_workcurrent_dovdd_max->setValue(itemshareData.workcurrentParameter->flSpecDOVDDMax);

	ui.checkBox_workcurrent_dvdd->setChecked(itemshareData.workcurrentParameter->btestDVDD);
	ui.spec_workcurrent_dvdd_min->setValue(itemshareData.workcurrentParameter->flSpecDVDDMin);
	ui.spec_workcurrent_dvdd_max->setValue(itemshareData.workcurrentParameter->flSpecDVDDMax);

	ui.checkBox_workcurrent_avdd->setChecked(itemshareData.workcurrentParameter->btestAVDD);
	ui.spec_workcurrent_avdd_min->setValue(itemshareData.workcurrentParameter->flSpecAVDDMin);
	ui.spec_workcurrent_avdd_max->setValue(itemshareData.workcurrentParameter->flSpecAVDDMax);

	ui.checkBox_workcurrent_af->setChecked(itemshareData.workcurrentParameter->btestAF);
	ui.spec_workcurrent_af_min->setValue(itemshareData.workcurrentParameter->flSpecAFMin);
	ui.spec_workcurrent_af_max->setValue(itemshareData.workcurrentParameter->flSpecAFMax);

	ui.checkBox_workcurrent_vfuse->setChecked(itemshareData.workcurrentParameter->btestVFUSE);
	ui.spec_workcurrent_vfuse_min->setValue(itemshareData.workcurrentParameter->flSpecVFUSEMin);
	ui.spec_workcurrent_vfuse_max->setValue(itemshareData.workcurrentParameter->flSpecVFUSEMax);

	ui.checkBox_workcurrent_pow->setChecked(itemshareData.workcurrentParameter->btestPOW);
	ui.spec_workcurrent_pow_min->setValue(itemshareData.workcurrentParameter->flSpecPOWMin);
	ui.spec_workcurrent_pow_max->setValue(itemshareData.workcurrentParameter->flSpecPOWMax);

	ui.checkBox_workcurrent_total->setChecked(itemshareData.workcurrentParameter->btestTotal);
	ui.spec_workcurrent_total_min->setValue(itemshareData.workcurrentParameter->flTotalMin);
	ui.spec_workcurrent_total_max->setValue(itemshareData.workcurrentParameter->flTotalMax);
}

int configsetting::saveWorkCurrentData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "workcurrent");

			unsigned int uiIndex	=	_HisDB_Index_Current;

			//(dovdd:on)(dovddmin:0.3)(dovddmax:50.9)(total:on)(totalmin:10.0)(totalmax:20.0)
			//(dvdd:on)(dvddmin:0.3)(dvddmax:50.9)
			//(avdd:on)(avddmin:0.3)(avddmax:50.9)
			//(af:on)(afmin:0.3)(afmax:50.9)(vfuse:on)(vfusemin:0.3)(vfusemax:50.9)
			strname.clear();strvalue.clear();
			strname.append("dovdd");strvalue.append((ui.checkBox_workcurrent_dovdd->isChecked())?("on"):("off"));
			strname.append("dovddmin");strvalue.append(ui.spec_workcurrent_dovdd_min->cleanText());
			strname.append("dovddmax");strvalue.append(ui.spec_workcurrent_dovdd_max->cleanText());
			strname.append("total");strvalue.append((ui.checkBox_workcurrent_total->isChecked())?("on"):("off"));
			strname.append("totalmin");strvalue.append(ui.spec_workcurrent_total_min->cleanText());
			strname.append("totalmax");strvalue.append(ui.spec_workcurrent_total_max->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("dvdd");strvalue.append((ui.checkBox_workcurrent_dvdd->isChecked())?("on"):("off"));
			strname.append("dvddmin");strvalue.append(ui.spec_workcurrent_dvdd_min->cleanText());
			strname.append("dvddmax");strvalue.append(ui.spec_workcurrent_dvdd_max->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("avdd");strvalue.append((ui.checkBox_workcurrent_avdd->isChecked())?("on"):("off"));
			strname.append("avddmin");strvalue.append(ui.spec_workcurrent_avdd_min->cleanText());
			strname.append("avddmax");strvalue.append(ui.spec_workcurrent_avdd_max->cleanText());

			if(classPlatform.isWorkCurrentSupported(_HisFX3_Platform_VlotOn_POW, bBoxChannel1))
			{
				strname.append("pow");strvalue.append((ui.checkBox_workcurrent_pow->isChecked())?("on"):("off"));
				strname.append("powmin");strvalue.append(ui.spec_workcurrent_pow_min->cleanText());
				strname.append("powmax");strvalue.append(ui.spec_workcurrent_pow_max->cleanText());
			}

			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("af");strvalue.append((ui.checkBox_workcurrent_af->isChecked())?("on"):("off"));
			strname.append("afmin");strvalue.append(ui.spec_workcurrent_af_min->cleanText());
			strname.append("afmax");strvalue.append(ui.spec_workcurrent_af_max->cleanText());
			strname.append("vfuse"); strvalue.append((ui.checkBox_workcurrent_vfuse->isChecked())?("on"):("off"));
			strname.append("vfusemin");strvalue.append(ui.spec_workcurrent_vfuse_min->cleanText());
			strname.append("vfusemax");strvalue.append(ui.spec_workcurrent_vfuse_max->cleanText());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "workcurrent",  QVariant(), itemsuffix2, key, value1, reserve);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::standbyCurrent2UI()
{
	classItemProcess->getstandbycurrentParameter(true, false);
	if(!itemshareData.standbycurrentParameter) return;

	ui.checkBox_standbycurrent_pwnd->setChecked(itemshareData.standbycurrentParameter->bPWND);
	ui.checkBox_standbycurrent_reset->setChecked(itemshareData.standbycurrentParameter->bReset);
	ui.checkBox_standbycurrent_mclk->setChecked(itemshareData.standbycurrentParameter->bMCLK);
	ui.checkBox_standbycurrent_dvddDown->setChecked(itemshareData.standbycurrentParameter->bDVDDDown);
	ui.spinBox_standbycurrent_delay->setValue(itemshareData.standbycurrentParameter->uiDelay);

	ui.checkBox_standbycurrent_dovdd->setChecked(itemshareData.standbycurrentParameter->btestDOVDD);
	ui.spec_standbycurrent_dovdd_min->setValue(itemshareData.standbycurrentParameter->flSpecDOVDDMin);
	ui.spec_standbycurrent_dovdd_max->setValue(itemshareData.standbycurrentParameter->flSpecDOVDDMax);

	ui.checkBox_standbycurrent_dvdd->setChecked(itemshareData.standbycurrentParameter->btestDVDD);
	ui.spec_standbycurrent_dvdd_min->setValue(itemshareData.standbycurrentParameter->flSpecDVDDMin);
	ui.spec_standbycurrent_dvdd_max->setValue(itemshareData.standbycurrentParameter->flSpecDVDDMax);

	ui.checkBox_standbycurrent_avdd->setChecked(itemshareData.standbycurrentParameter->btestAVDD);
	ui.spec_standbycurrent_avdd_min->setValue(itemshareData.standbycurrentParameter->flSpecAVDDMin);
	ui.spec_standbycurrent_avdd_max->setValue(itemshareData.standbycurrentParameter->flSpecAVDDMax);

	ui.checkBox_standbycurrent_af->setChecked(itemshareData.standbycurrentParameter->btestAF);
	ui.spec_standbycurrent_af_min->setValue(itemshareData.standbycurrentParameter->flSpecAFMin);
	ui.spec_standbycurrent_af_max->setValue(itemshareData.standbycurrentParameter->flSpecAFMax);

	ui.checkBox_standbycurrent_pow->setChecked(itemshareData.standbycurrentParameter->btestPOW);
	ui.spec_standbycurrent_pow_min->setValue(itemshareData.standbycurrentParameter->flSpecPOWMin);
	ui.spec_standbycurrent_pow_max->setValue(itemshareData.standbycurrentParameter->flSpecPOWMax);

	ui.checkBox_standbycurrent_total->setChecked(itemshareData.standbycurrentParameter->btestTotal);
	ui.spec_standbycurrent_total_min->setValue(itemshareData.standbycurrentParameter->flTotalMin);
	ui.spec_standbycurrent_total_max->setValue(itemshareData.standbycurrentParameter->flTotalMax);

}

int configsetting::saveStandbyCurrentData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "standbycurrent");

			unsigned int uiIndex	=	_HisDB_Index_Current;

			//(dovdd:on)(dovddmin:0.3)(dovddmax:50.9)(dovddgrade:0)(pwnd:on)(reset:off)(mclk:on)(dvdddown:off)(delay:5000)
			//(dvdd:on)(dvddmin:0.3)(dvddmax:50.9)(dvddgrade:0)(total:on)(totalmin:10.0)(totalmax:20.0)
			//(avdd:on)(avddmin:0.3)(avddmax:50.9)(avddgrade:0)
			//(af:on)(afmin:0.3)(afmax:50.9)(afgrade:0)
			strname.clear();strvalue.clear();
			strname.append("dovdd");strvalue.append((ui.checkBox_standbycurrent_dovdd->isChecked())?("on"):("off"));
			strname.append("dovddmin");strvalue.append(ui.spec_standbycurrent_dovdd_min->cleanText());
			strname.append("dovddmax");strvalue.append(ui.spec_standbycurrent_dovdd_max->cleanText());
			strname.append("pwnd");strvalue.append((ui.checkBox_standbycurrent_pwnd->isChecked())?("on"):("off"));
			strname.append("reset");strvalue.append((ui.checkBox_standbycurrent_reset->isChecked())?("on"):("off"));
			strname.append("mclk");strvalue.append((ui.checkBox_standbycurrent_mclk->isChecked())?("on"):("off"));
			strname.append("dvdddown");strvalue.append((ui.checkBox_standbycurrent_dvddDown->isChecked())?("on"):("off"));
			strname.append("delay");strvalue.append(QString::number(ui.spinBox_standbycurrent_delay->value()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("dvdd");strvalue.append((ui.checkBox_standbycurrent_dvdd->isChecked())?("on"):("off"));
			strname.append("dvddmin");strvalue.append(ui.spec_standbycurrent_dvdd_min->cleanText());
			strname.append("dvddmax");strvalue.append(ui.spec_standbycurrent_dvdd_max->cleanText());
			strname.append("total");strvalue.append((ui.checkBox_standbycurrent_total->isChecked())?("on"):("off"));
			strname.append("totalmin");strvalue.append(ui.spec_standbycurrent_total_min->cleanText());
			strname.append("totalmax");strvalue.append(ui.spec_standbycurrent_total_max->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("avdd");strvalue.append((ui.checkBox_standbycurrent_avdd->isChecked())?("on"):("off"));
			strname.append("avddmin");strvalue.append(ui.spec_standbycurrent_avdd_min->cleanText());
			strname.append("avddmax");strvalue.append(ui.spec_standbycurrent_avdd_max->cleanText());

			if(classPlatform.isStandbyCurrentSupported(_HisFX3_Platform_VlotOn_POW, bBoxChannel1))
			{
				strname.append("pow");strvalue.append((ui.checkBox_standbycurrent_pow->isChecked())?("on"):("off"));
				strname.append("powmin");strvalue.append(ui.spec_standbycurrent_pow_min->cleanText());
				strname.append("powmax");strvalue.append(ui.spec_standbycurrent_pow_max->cleanText());
			}

			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("af");strvalue.append((ui.checkBox_standbycurrent_af->isChecked())?("on"):("off"));
			strname.append("afmin");strvalue.append(ui.spec_standbycurrent_af_min->cleanText());
			strname.append("afmax");strvalue.append(ui.spec_standbycurrent_af_max->cleanText());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "standbycurrent",  QVariant(), itemsuffix2, key, value1, reserve);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::openshort2UI()
{
	classItemProcess->getOSParameter(true, false);
	if(!itemshareData.openshortParameter) {
		changeOSTableName(ui.osa_ChannelcomboBox->currentText());
		return;
	}

	ui.osa_TestPositivecheckBox->setChecked(itemshareData.openshortParameter->bTestPositive);
	ui.osa_TestNegtivecheckBox->setChecked(itemshareData.openshortParameter->bTestNegtive);
	ui.osa_TestShortcheckBox->setChecked(itemshareData.openshortParameter->bTestShort);
	ui.osa_TestOpencheckBox->setChecked(itemshareData.openshortParameter->bTestOpen);
	ui.osa_TestOhmcheckBox->setChecked(itemshareData.openshortParameter->bTestOhm);
	ui.osa_ChannelcomboBox->setCurrentIndex(itemshareData.openshortParameter->ucOSSwitch);
	ui.osPositiveDelayspinBox->setValue(itemshareData.openshortParameter->usPositiveDelay);
	ui.osNegtiveDelayspinBox->setValue(itemshareData.openshortParameter->usNegtiveDelay);
	ui.osShortDelayspinBox->setValue(itemshareData.openshortParameter->usShortDelay);
	ui.osOpenDelayspinBox->setValue(itemshareData.openshortParameter->usOpenDelay);
	ui.osOHMDelayspinBox->setValue(itemshareData.openshortParameter->usOhmDelay);

	changeOSTableName(ui.osa_ChannelcomboBox->currentText());

	QString strGND;
	bool bFullPin = false;
	classPlatform.isOpenShortSupported(&bFullPin);
	for(unsigned int x=0;	x<itemshareData.openshortParameter->vectorPositive.size();	++x)
	{
		for(unsigned int row=0; row < ui.osPositivetableWidget->rowCount();	++row){
			if(ui.osPositivetableWidget->verticalHeaderItem(row)->text() != QString::fromAscii(itemshareData.openshortParameter->vectorPositive.at(x).strName)) continue;
			QCheckBox* pstTest	=	(QCheckBox*)ui.osPositivetableWidget->cellWidget(row, 0);
			QComboBox* pstIn		=	(QComboBox*)ui.osPositivetableWidget->cellWidget(row, 1);
			QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osPositivetableWidget->cellWidget(row, 2);
			QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osPositivetableWidget->cellWidget(row, 3);
			pstTest->setChecked(itemshareData.openshortParameter->vectorPositive.at(x).bTest);

			if(bFullPin)
				strGND	=	QString::fromAscii(itemshareData.openshortParameter->vectorPositive.at(x).strGNDName);
			else
				strGND	=	(itemshareData.openshortParameter->vectorPositive.at(x).bAGND)?("AGND"):("DGND");
			pstIn->setCurrentIndex(pstIn->findText(strGND));
			pstSpecMin->setValue(itemshareData.openshortParameter->vectorPositive.at(x).flSpecMin);
			pstSpecMax->setValue(itemshareData.openshortParameter->vectorPositive.at(x).flSpecMax);
		}
	}

	for(unsigned int x=0;	x<itemshareData.openshortParameter->vectorNegtive.size(); ++x)
	{
		for(unsigned int row=0; row < ui.osNegtivetableWidget->rowCount();	++row){
			if(ui.osNegtivetableWidget->verticalHeaderItem(row)->text() != QString::fromAscii(itemshareData.openshortParameter->vectorNegtive.at(x).strName)) continue;
			QCheckBox* pstTest	=	(QCheckBox*)ui.osNegtivetableWidget->cellWidget(row, 0);
			QComboBox* pstDOVDD = (QComboBox*)ui.osNegtivetableWidget->cellWidget(row, 1);
			QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osNegtivetableWidget->cellWidget(row, 2);
			QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osNegtivetableWidget->cellWidget(row, 3);
			pstTest->setChecked(itemshareData.openshortParameter->vectorNegtive.at(x).bTest);
			pstDOVDD->setCurrentIndex(pstDOVDD->findText(QString::fromAscii(itemshareData.openshortParameter->vectorNegtive.at(x).strDOVDDName)));
			pstSpecMin->setValue(itemshareData.openshortParameter->vectorNegtive.at(x).flSpecMin);
			pstSpecMax->setValue(itemshareData.openshortParameter->vectorNegtive.at(x).flSpecMax);
		}
	}

	for(unsigned int x=0;	x<itemshareData.openshortParameter->vectorShort.size();	++x)
	{
		for(unsigned int row=0; row < ui.osShorttableWidget->rowCount();	++row){
			if(ui.osShorttableWidget->verticalHeaderItem(row)->text() != QString::fromAscii(itemshareData.openshortParameter->vectorShort.at(x).strName)) continue;
			QCheckBox* pstTest	=	(QCheckBox*)ui.osShorttableWidget->cellWidget(row, 0);
			QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osShorttableWidget->cellWidget(row, 1);
			pstTest->setChecked(itemshareData.openshortParameter->vectorShort.at(x).bTest);
			
			pstSpecMin->setValue(itemshareData.openshortParameter->vectorShort.at(x).flShortSpec);
		}
	}

	for(unsigned int x=0;	x<itemshareData.openshortParameter->vectorOpen.size();	++x)
	{
		for(unsigned int row=0; row < ui.osOpentableWidget->rowCount();	++row){
			if(ui.osOpentableWidget->verticalHeaderItem(row)->text() != QString::fromAscii(itemshareData.openshortParameter->vectorOpen.at(x).strName)) continue;
			QCheckBox* pstTest	=	(QCheckBox*)ui.osOpentableWidget->cellWidget(row, 0);
			QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osOpentableWidget->cellWidget(row, 1);
			pstTest->setChecked(itemshareData.openshortParameter->vectorOpen.at(x).bTest);
			pstSpecMax->setValue(itemshareData.openshortParameter->vectorOpen.at(x).flOpenSpec);
		}
	}

	for(unsigned int x=0;	x<itemshareData.openshortParameter->vectorOhm.size();	++x)
	{
		QCheckBox* pstTest	=	(QCheckBox*)ui.osOHMtableWidget->cellWidget(x, 0);
		QComboBox* pstIn		=	(QComboBox*)ui.osOHMtableWidget->cellWidget(x, 1);
		QComboBox* pstOut		=	(QComboBox*)ui.osOHMtableWidget->cellWidget(x, 2);
		QDoubleSpinBox* pstSpecMin	=	(QDoubleSpinBox*)ui.osOHMtableWidget->cellWidget(x, 3);
		QDoubleSpinBox* pstSpecMax	=	(QDoubleSpinBox*)ui.osOHMtableWidget->cellWidget(x, 4);
		pstTest->setChecked(true);
		//vectorListort.push_back(pstTest);
		pstIn->setCurrentIndex(pstIn->findText(QString::fromAscii(itemshareData.openshortParameter->vectorOhm.at(x).str1stName)));
		pstOut->setCurrentIndex(pstOut->findText(QString::fromAscii(itemshareData.openshortParameter->vectorOhm.at(x).str2ndName)));
		pstSpecMin->setValue(itemshareData.openshortParameter->vectorOhm.at(x).flSpecMin);
		pstSpecMax->setValue(itemshareData.openshortParameter->vectorOhm.at(x).flSpecMax);
	}

	
}

int configsetting::saveOpenShortData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "openshort");

			unsigned int uiIndex	=	_HisDB_Index_OS_Total;
			stSqlDB.transaction();

			//(positive:true)(negtive:true)(short:true)(ohm:true)
			//(channel:mipi)(positivedelay:12)(negtivedelay:12)(shortdelay:12)(ohmdelay:12)
			strname.clear(); strvalue.clear();
			strname.append("positive");strvalue.append((ui.osa_TestPositivecheckBox->isChecked())?("true"):("false"));
			strname.append("negtive");strvalue.append((ui.osa_TestNegtivecheckBox->isChecked())?("true"):("false"));
			strname.append("short");strvalue.append((ui.osa_TestShortcheckBox->isChecked())?("true"):("false"));
			strname.append("open");strvalue.append((ui.osa_TestOpencheckBox->isChecked())?("true"):("false"));
			strname.append("ohm");strvalue.append((ui.osa_TestOhmcheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear(); strvalue.clear();
			strname.append("channel");strvalue.append(ui.osa_ChannelcomboBox->currentText());
			strname.append("positivedelay");strvalue.append(ui.osPositiveDelayspinBox->cleanText());
			strname.append("negtivedelay");strvalue.append(ui.osNegtiveDelayspinBox->cleanText());
			strname.append("shortdelay");strvalue.append(ui.osShortDelayspinBox->cleanText());
			strname.append("opendelay");strvalue.append(ui.osOpenDelayspinBox->cleanText());
			strname.append("ohmdelay");strvalue.append(ui.osOHMDelayspinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "openshort",  "total", itemsuffix2, key);

			//positive
			//(test:true)(name:dvdd)(in:dgnd)
			//(specmin:200)(specmax:600)
			uiIndex	=	_HisDB_Index_OS_Positive;
			for(unsigned int row=0; row < ui.osPositivetableWidget->rowCount();	++row){
				QCheckBox* pstTest	=	(QCheckBox*)ui.osPositivetableWidget->cellWidget(row, 0);
				QComboBox* pstIn		=	(QComboBox*)ui.osPositivetableWidget->cellWidget(row, 1);
				QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osPositivetableWidget->cellWidget(row, 2);
				QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osPositivetableWidget->cellWidget(row, 3);
				strname.clear(); strvalue.clear();
				strname.append("test");strvalue.append((pstTest->isChecked())?("true"):("false"));
				strname.append("name");strvalue.append(ui.osPositivetableWidget->verticalHeaderItem(row)->text());
				strname.append("in");strvalue.append(pstIn->currentText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear(); strvalue.clear();
				strname.append("specmin");strvalue.append(QString::number(pstSpecMin->value()));
				strname.append("specmax");strvalue.append(QString::number(pstSpecMax->value()));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				if(ui.osPositivetableWidget->verticalHeaderItem(row)->text() == "...") continue;
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", "openshort",  "positive", itemsuffix2, key);
			}

			//negtive
			//(test:true)(name:dvdd)(out:dovdd)
			//(specmin:200)(specmax:600)
			uiIndex	=	_HisDB_Index_OS_Negtive;
			for(unsigned int row=0; row < ui.osNegtivetableWidget->rowCount();	++row)
			{
				QCheckBox* pstTest	=	(QCheckBox*)ui.osNegtivetableWidget->cellWidget(row, 0);
				QComboBox* pstDOVDD	=	(QComboBox*)ui.osNegtivetableWidget->cellWidget(row, 1);
				QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osNegtivetableWidget->cellWidget(row, 2);
				QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osNegtivetableWidget->cellWidget(row, 3);
				strname.clear(); strvalue.clear();
				strname.append("test");strvalue.append((pstTest->isChecked())?("true"):("false"));
				strname.append("name");strvalue.append(ui.osNegtivetableWidget->verticalHeaderItem(row)->text());
				strname.append("out");strvalue.append(pstDOVDD->currentText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear(); strvalue.clear();
				strname.append("specmin");strvalue.append(QString::number(pstSpecMin->value()));
				strname.append("specmax");strvalue.append(QString::number(pstSpecMax->value()));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				if(ui.osNegtivetableWidget->verticalHeaderItem(row)->text() == "...") continue;
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", "openshort",  "negtive", itemsuffix2, key);
			}

			//short
			//(test:true)(name:dvdd)
			//(specmin:200)
			uiIndex	=	_HisDB_Index_OS_Short;
			for(unsigned int row=0; row < ui.osShorttableWidget->rowCount();	++row)
			{
				QCheckBox* pstTest	=	(QCheckBox*)ui.osShorttableWidget->cellWidget(row, 0);
				QSpinBox* pstSpecMin	=	(QSpinBox*)ui.osShorttableWidget->cellWidget(row, 1);
				strname.clear(); strvalue.clear();
				strname.append("test");strvalue.append((pstTest->isChecked())?("true"):("false"));
				strname.append("name");strvalue.append(ui.osShorttableWidget->verticalHeaderItem(row)->text());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear(); strvalue.clear();
				strname.append("specmin");strvalue.append(QString::number(pstSpecMin->value()));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				if(ui.osShorttableWidget->verticalHeaderItem(row)->text() == "...") continue;
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", "openshort",  "short", itemsuffix2, key);
			}

			//open
			//(test:true)(name:dvdd)
			//(specmax:200)
			uiIndex	=	_HisDB_Index_OS_Open;
			for(unsigned int row=0; row < ui.osOpentableWidget->rowCount();	++row)
			{
				QCheckBox* pstTest		=	(QCheckBox*)ui.osOpentableWidget->cellWidget(row, 0);
				QSpinBox* pstSpecMax	=	(QSpinBox*)ui.osOpentableWidget->cellWidget(row, 1);
				strname.clear(); strvalue.clear();
				strname.append("test");strvalue.append((pstTest->isChecked())?("true"):("false"));
				strname.append("name");strvalue.append(ui.osOpentableWidget->verticalHeaderItem(row)->text());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear(); strvalue.clear();
				strname.append("specmax");strvalue.append(QString::number(pstSpecMax->value()));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				if(ui.osOpentableWidget->verticalHeaderItem(row)->text() == "...") continue;
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", "openshort",  "open", itemsuffix2, key);
			}

			//ohm
			//(test:true)(inname:dgnd)(outname:io2)
			//(specmin:0.0)(specmax:5.0)
			uiIndex	=	_HisDB_Index_OS_Ohm;
			for(unsigned int row=0; row < ui.osOHMtableWidget->rowCount();	++row)
			{
				QCheckBox* pstTest		=	(QCheckBox*)ui.osOHMtableWidget->cellWidget(row, 0);
				QComboBox* pstIn			=	(QComboBox*)ui.osOHMtableWidget->cellWidget(row, 1);
				QComboBox* pstOut		=	(QComboBox*)ui.osOHMtableWidget->cellWidget(row, 2);
				QDoubleSpinBox* pstSpecMin	=	(QDoubleSpinBox*)ui.osOHMtableWidget->cellWidget(row, 3);
				QDoubleSpinBox* pstSpecMax	=	(QDoubleSpinBox*)ui.osOHMtableWidget->cellWidget(row, 4);
				strname.clear(); strvalue.clear();
				strname.append("test");strvalue.append((pstTest->isChecked())?("true"):("false"));
				strname.append("inname");strvalue.append(pstIn->currentText());
				strname.append("outname");strvalue.append(pstOut->currentText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear(); strvalue.clear();
				strname.append("specmin");strvalue.append(QString::number(pstSpecMin->value()));
				strname.append("specmax");strvalue.append(QString::number(pstSpecMax->value()));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				if(!pstTest->isChecked()) continue;
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", "openshort",  "ohm", itemsuffix2, key);
			}

			stSqlDB.commit();
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::saveOpenShort()
{
	int iresult = saveOpenShortData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	openshort2UI();
}

void configsetting::createOpenShortTable()
{
	if(!bBoxChannel1)
	{
		ui.osa_ChannelcomboBox->removeItem(1);
	}
	vectorListosp.clear();
	vectorListosn.clear();
	vectorListosc.clear();
	vectorListooc.clear();
	//vectorListcmbosp.clear();
	std::vector<std::string> vecOSPositiveGND;
	classPlatform.getOSPositiveGNDPinName(0, vecOSPositiveGND);
	QStringList strOSPositiveGNDList;
	for(unsigned int x=0;	x<vecOSPositiveGND.size(); ++x)
		strOSPositiveGNDList.push_back(QString::fromStdString(vecOSPositiveGND[x]));
	ui.ospcomboBox->addItems(strOSPositiveGNDList);

	std::vector<std::string> vecOSNegtiveDOVDD;
	classPlatform.getOSNegtiveDOVDDPinName(0, vecOSNegtiveDOVDD);
	QStringList strOSNegtiveDOVDDList;
	for(unsigned int x=0;	x<vecOSNegtiveDOVDD.size(); ++x)
		strOSNegtiveDOVDDList.push_back(QString::fromStdString(vecOSNegtiveDOVDD[x]));
	ui.osNegitveDOVDDcomboBox->addItems(strOSNegtiveDOVDDList);

	for(unsigned int row=0; row < ui.osPositivetableWidget->rowCount();	++row)
	{
		QCheckBox* pstTest	=	new QCheckBox();
		ui.osPositivetableWidget->setCellWidget(row, 0,  pstTest);
		pstTest->setChecked(true);
		QComboBox* pstChannel	=	new QComboBox();
		ui.osPositivetableWidget->setCellWidget(row, 1,  pstChannel);
		pstChannel->addItems(strOSPositiveGNDList);
		//if (row	==0)
		//{
		//	ui.ospcomboBox->addItems(strOSPositiveGNDList);			
		//}
		
		QSpinBox* pstSpecMin	=	new QSpinBox();
		ui.osPositivetableWidget->setCellWidget(row, 2,  pstSpecMin);
		pstSpecMin->setRange(0, 4000);
		pstSpecMin->setSingleStep(1);
		pstSpecMin->setValue(200);
		QSpinBox* pstSpecMax	=	new QSpinBox();
		ui.osPositivetableWidget->setCellWidget(row, 3,  pstSpecMax);
		pstSpecMax->setRange(0, 4000);
		pstSpecMax->setSingleStep(1);
		pstSpecMax->setValue(800);
		vectorListosp.push_back(pstTest);
		vectorListcmbosp.push_back(pstChannel);
	}

	for(unsigned int row=0; row < ui.osNegtivetableWidget->rowCount();	++row)
	{
		QCheckBox* pstTest	=	new QCheckBox();
		ui.osNegtivetableWidget->setCellWidget(row, 0,  pstTest);
		pstTest->setChecked(true);

		QComboBox* pstChannel	=	new QComboBox();
		ui.osNegtivetableWidget->setCellWidget(row, 1,  pstChannel);
		pstChannel->addItems(strOSNegtiveDOVDDList);

		QSpinBox* pstSpecMin	=	new QSpinBox();
		ui.osNegtivetableWidget->setCellWidget(row, 2,  pstSpecMin);
		pstSpecMin->setRange(0, 4000);
		pstSpecMin->setSingleStep(1);
		pstSpecMin->setValue(200);
		QSpinBox* pstSpecMax	=	new QSpinBox();
		ui.osNegtivetableWidget->setCellWidget(row, 3,  pstSpecMax);
		pstSpecMax->setRange(0, 4000);
		pstSpecMax->setSingleStep(1);
		pstSpecMax->setValue(800);
		vectorListosn.push_back(pstTest);
	}

	for(unsigned int row=0; row < ui.osShorttableWidget->rowCount();	++row){
		QCheckBox* pstTest	=	new QCheckBox();
		ui.osShorttableWidget->setCellWidget(row, 0,  pstTest);
		pstTest->setChecked(true);
		QSpinBox* pstSpecMin	=	new QSpinBox();
		ui.osShorttableWidget->setCellWidget(row, 1,  pstSpecMin);
		pstSpecMin->setRange(0, 4000);
		pstSpecMin->setSingleStep(1);
		pstSpecMin->setValue(200);
		vectorListosc.push_back(pstTest);
	}

	for(unsigned int row=0; row < ui.osOpentableWidget->rowCount();	++row)
	{
		QCheckBox* pstTest	=	new QCheckBox();
		ui.osOpentableWidget->setCellWidget(row, 0,  pstTest);
		pstTest->setChecked(true);
		QSpinBox* pstSpecMax	=	new QSpinBox();
		ui.osOpentableWidget->setCellWidget(row, 1,  pstSpecMax);
		pstSpecMax->setRange(0, 4000);
		pstSpecMax->setSingleStep(1);
		pstSpecMax->setValue(1500);
		vectorListooc.push_back(pstTest);
	}
	vectorListort.clear();
	for(unsigned int row=0; row < ui.osOHMtableWidget->rowCount();	++row){
		QCheckBox* pstTest	=	new QCheckBox();
		ui.osOHMtableWidget->setCellWidget(row, 0,  pstTest);
		vectorListort.push_back(pstTest);
		QComboBox* pstLine1	=	new QComboBox();
		ui.osOHMtableWidget->setCellWidget(row, 1,  pstLine1);
		QComboBox* pstLine2	=	new QComboBox();
		ui.osOHMtableWidget->setCellWidget(row, 2,  pstLine2);
		QDoubleSpinBox* pstSpecMin	=	new QDoubleSpinBox();
		ui.osOHMtableWidget->setCellWidget(row, 3,  pstSpecMin);
		pstSpecMin->setRange(0.0, 4000.0);
		pstSpecMin->setSingleStep(0.1);
		pstSpecMin->setValue(0.0);
		QDoubleSpinBox* pstSpecMax	=	new QDoubleSpinBox();
		ui.osOHMtableWidget->setCellWidget(row, 4,  pstSpecMax);
		pstSpecMax->setRange(0.0, 4000.0);
		pstSpecMax->setSingleStep(0.1);
		pstSpecMax->setValue(8.0);
	}
}

void configsetting::changeOSTableName(const QString & text)
{
	vectorListcmbosp.clear();
	std::vector<std::string> vecOSPin, vecOSPinCopy, vecOSPositiveGND, vecOSNegtiveDOVDD;
	if(text == "DVP")
	{	
		classPlatform.getOSPinNameList(1, vecOSPin);
		classPlatform.getOSPositiveGNDPinName(1, vecOSPositiveGND);
		classPlatform.getOSNegtiveDOVDDPinName(1, vecOSNegtiveDOVDD);
	}
	else
	{
		classPlatform.getOSPinNameList(0, vecOSPin);
		classPlatform.getOSPositiveGNDPinName(0, vecOSPositiveGND);
		classPlatform.getOSNegtiveDOVDDPinName(0, vecOSNegtiveDOVDD);
	}

	vecOSPinCopy.assign(vecOSPin.begin(), vecOSPin.end());
	removeOSPin(vecOSPinCopy, "DGND");
	removeOSPin(vecOSPinCopy, "AGND");
	int iIndex;
	for(iIndex = 0; iIndex < vecOSPinCopy.size(); ++iIndex)
	{
		ui.osPositivetableWidget->verticalHeaderItem(iIndex)->setText(QString::fromStdString(vecOSPinCopy.at(iIndex)));
		ui.osPositivetableWidget->showRow(iIndex);
	}

	for(; iIndex < ui.osPositivetableWidget->rowCount(); ++iIndex)
	{
		ui.osPositivetableWidget->verticalHeaderItem(iIndex)->setText("...");
		ui.osPositivetableWidget->hideRow(iIndex);
	}

	QStringList strOSPositiveGNDList;
	for(unsigned int x=0;	x<vecOSPositiveGND.size(); ++x)
		strOSPositiveGNDList.push_back(QString::fromStdString(vecOSPositiveGND[x]));

	QStringList strOSNegtiveDOVDDList;
	for(unsigned int x=0;	x<vecOSNegtiveDOVDD.size(); ++x)
		strOSNegtiveDOVDDList.push_back(QString::fromStdString(vecOSNegtiveDOVDD[x]));

	for(iIndex =0; iIndex < ui.osPositivetableWidget->rowCount(); ++iIndex)
	{
		QComboBox* pstGND		=	(QComboBox*)ui.osPositivetableWidget->cellWidget(iIndex, 1);
		pstGND->clear();
		pstGND->addItems(strOSPositiveGNDList);
		vectorListcmbosp.push_back(pstGND);
	}

	vecOSPinCopy.assign(vecOSPin.begin(), vecOSPin.end());
	removeOSPin(vecOSPinCopy, "DGND");
	removeOSPin(vecOSPinCopy, "AGND");
	removeOSPin(vecOSPinCopy, "DOVDD");
	removeOSPin(vecOSPinCopy, "AVDD");
	removeOSPin(vecOSPinCopy, "DVDD");
	removeOSPin(vecOSPinCopy, "AF");
	removeOSPin(vecOSPinCopy, "POW");
	removeOSPin(vecOSPinCopy, "OTP");
	removeOSPin(vecOSPinCopy, "VFUSE");
	removeOSPin(vecOSPinCopy, "5V");
	for(iIndex = 0; iIndex < vecOSPinCopy.size(); ++iIndex)
	{
		ui.osNegtivetableWidget->verticalHeaderItem(iIndex)->setText(QString::fromStdString(vecOSPinCopy.at(iIndex)));
		ui.osNegtivetableWidget->showRow(iIndex);
	}

	for(; iIndex < ui.osNegtivetableWidget->rowCount(); ++iIndex)
	{
		ui.osNegtivetableWidget->verticalHeaderItem(iIndex)->setText("...");
		ui.osNegtivetableWidget->hideRow(iIndex);
	}

	for(iIndex =0; iIndex < ui.osNegtivetableWidget->rowCount(); ++iIndex)
	{
		QComboBox* pstNegtive		=	(QComboBox*)ui.osNegtivetableWidget->cellWidget(iIndex, 1);
		pstNegtive->clear();
		pstNegtive->addItems(strOSNegtiveDOVDDList);
	}

	vecOSPinCopy.assign(vecOSPin.begin(), vecOSPin.end());
	for(iIndex = 0; iIndex < vecOSPinCopy.size(); ++iIndex)
	{
		ui.osShorttableWidget->verticalHeaderItem(iIndex)->setText(QString::fromStdString(vecOSPinCopy.at(iIndex)));
		ui.osShorttableWidget->showRow(iIndex);
	}

	for(; iIndex < ui.osShorttableWidget->rowCount(); ++iIndex)
	{
		ui.osShorttableWidget->verticalHeaderItem(iIndex)->setText("...");
		ui.osShorttableWidget->hideRow(iIndex);
	}

	vecOSPinCopy.assign(vecOSPin.begin(), vecOSPin.end());
	for(iIndex = 0; iIndex < vecOSPinCopy.size(); ++iIndex)
	{
		ui.osOpentableWidget->verticalHeaderItem(iIndex)->setText(QString::fromStdString(vecOSPinCopy.at(iIndex)));
		ui.osOpentableWidget->showRow(iIndex);
	}

	for(; iIndex < ui.osOpentableWidget->rowCount(); ++iIndex)
	{
		ui.osOpentableWidget->verticalHeaderItem(iIndex)->setText("...");
		ui.osOpentableWidget->hideRow(iIndex);
	}

	vecOSPinCopy.assign(vecOSPin.begin(), vecOSPin.end());
	QStringList listName = osPinList2QStringList(vecOSPinCopy);

	for(unsigned int row=0; row < ui.osOHMtableWidget->rowCount();	++row)
	{
		QComboBox* pstLine1	=	(QComboBox*)ui.osOHMtableWidget->cellWidget(row, 1);
		pstLine1->clear();
		pstLine1->addItems(listName);
		pstLine1->setCurrentIndex(0);
		QComboBox* pstLine2	=	(QComboBox*)ui.osOHMtableWidget->cellWidget(row, 2);
		pstLine2->clear();
		pstLine2->addItems(listName);
		pstLine2->setCurrentIndex(2);
	}
	ui.ospcomboBox->clear();
	ui.ospcomboBox->addItems(strOSPositiveGNDList);
	ui.osNegitveDOVDDcomboBox->clear();
	ui.osNegitveDOVDDcomboBox->addItems(strOSNegtiveDOVDDList);
}

void configsetting::createMTFAFCTable(QTableWidget* pstTable)
{
	for(unsigned int row=0; row < pstTable->rowCount();	++row){
		QCheckBox* pstTest	=	new QCheckBox();
		pstTable->setCellWidget(row, 0,  pstTest);
		QComboBox* pstBlockCount	=	new QComboBox();
		pstBlockCount->addItem("2");
		pstBlockCount->addItem("4");
		pstBlockCount->setCurrentIndex(1);
		pstTable->setCellWidget(row, 1,  pstBlockCount);
		QDoubleSpinBox* pstFOV	=	new QDoubleSpinBox();
		pstFOV->setRange(0.05, 0.95);
		pstFOV->setDecimals(3);
		pstFOV->setValue(0.7);
		pstTable->setCellWidget(row, 2,  pstFOV);
		QSpinBox* pstAngle	=	new QSpinBox();
		pstTable->setCellWidget(row, 3,  pstAngle);
		pstAngle->setRange(0, 179);

		QDoubleSpinBox* pstWeight	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 4,  pstWeight);
		pstWeight->setRange(0.0, 1.0);
		pstWeight->setDecimals(2);

		QDoubleSpinBox* pstSpec	=	new QDoubleSpinBox();
		pstSpec->setRange(0.0, 1.0);
		pstSpec->setDecimals(3);
		pstSpec->setValue(0.5);
		pstTable->setCellWidget(row, 5,  pstSpec);

		QDoubleSpinBox* pstSpecB =	new QDoubleSpinBox();
		pstSpecB->setRange(0.0, 1.0);
		pstSpecB->setDecimals(3);
		pstSpecB->setValue(0.5);
		pstTable->setCellWidget(row, 6,  pstSpecB);

		QDoubleSpinBox* pstSpecUniform	=	new QDoubleSpinBox();
		pstSpecUniform->setRange(0.0, 1.0);
		pstSpecUniform->setDecimals(3);
		pstSpecUniform->setValue(0.5);
		pstTable->setCellWidget(row, 7,  pstSpecUniform);

		//************** 2018.04.11 fengqiquan Add **************
		QDoubleSpinBox* pstSpecHorizontal	=	new QDoubleSpinBox();
		pstSpecHorizontal->setRange(0.0, 1.0);
		pstSpecHorizontal->setDecimals(3);
		pstTable->setCellWidget(row, 8,  pstSpecHorizontal);

		QDoubleSpinBox* pstSpecVertical	=	new QDoubleSpinBox();
		pstSpecVertical->setRange(0.0, 1.0);
		pstSpecVertical->setDecimals(3);
		pstTable->setCellWidget(row, 9,  pstSpecVertical);
		//******************************************
		if(pstTable == ui.mfamtfaFBtableWidget){
#if (defined USE_MANUAL_LENS_BIN)
			QDoubleSpinBox* pstSpecB	=	new QDoubleSpinBox();
			pstSpecB->setRange(0.0, 1.0);
			pstSpecB->setDecimals(3);
			pstSpecB->setValue(0.5);
			pstTable->setCellWidget(row, 7,  pstSpecB);
			QDoubleSpinBox* pstSpecC	=	new QDoubleSpinBox();
			pstSpecC->setRange(0.0, 1.0);
			pstSpecC->setDecimals(3);
			pstSpecC->setValue(0.5);
			pstTable->setCellWidget(row, 8,  pstSpecC);
			QDoubleSpinBox* pstSpecD	=	new QDoubleSpinBox();
			pstSpecD->setRange(0.0, 1.0);
			pstSpecD->setDecimals(3);
			pstSpecD->setValue(0.5);
			pstTable->setCellWidget(row, 9,  pstSpecD);
			QDoubleSpinBox* pstSpecE	=	new QDoubleSpinBox();
			pstSpecE->setRange(0.0, 1.0);
			pstSpecE->setDecimals(3);
			pstSpecE->setValue(0.5);
			pstTable->setCellWidget(row, 10,  pstSpecE);

			QDoubleSpinBox* pstSpec_H	=	new QDoubleSpinBox();
			pstSpec_H->setRange(0.0, 1.0);
			pstSpec_H->setDecimals(3);
			pstSpec_H->setValue(0.5);
			pstTable->setCellWidget(row, 11,  pstSpec_H);

			QDoubleSpinBox* pstSpec_V	=	new QDoubleSpinBox();
			pstSpec_V->setRange(0.0, 1.0);
			pstSpec_V->setDecimals(3);
			pstSpec_V->setValue(0.5);
			pstTable->setCellWidget(row, 12,  pstSpec_V);
#endif
		}
	}

	if(pstTable == ui.mfamtfaFBtableWidget){
#if (defined USE_MANUAL_LENS_BIN)
		QStringList listHorizontalHeader;
		listHorizontalHeader << tr("Test") << tr("ROI Numbers") << tr("FOV") << tr("Angle") << tr("Weight") << tr("Grade A") << \
			tr("Spec(U)") << tr("Grade B") << tr("Grade C") << tr("Grade D") << tr("Grade E") << tr("Spec_H") << tr("Sepc_V");
		pstTable->setHorizontalHeaderLabels(listHorizontalHeader);
		pstTable->hideColumn(6);
		pstTable->hideColumn(4);
#else
		pstTable->hideColumn(7);
		pstTable->hideColumn(8);
		pstTable->hideColumn(9);
		pstTable->hideColumn(10);
#endif
	}
}

void configsetting::afcMTFBasic2UI(unsigned char uctype)
{
	QString strItemName;
	QTableWidget* afcTableWidget;
	QComboBox *afcmtfaBAlgComboBox;
	QSpinBox *afcmtfaBROIWSpinBox, *afcmtfaBROIHSpinBox;
	QDoubleSpinBox *afcmtfaBCenterSpecdoubleSpinBox,*afcmtfaBCenterSpecdoubleSpinBox_2, *afcmtfaBCenterWeightdoubleSpinBox,\
		*afcmtfaBCenterSpecdoubleSpinBox_H,*afcmtfaBCenterSpecdoubleSpinBox_V;
	QCheckBox *afcmtfaBAutoSearchcheckBox;
	_mtfAFCParameter* mtfafcParameter;

	if(uctype == 0){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName	=	"afcmtfnear";
		afcTableWidget				=	ui.afcmtfaNBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaNBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaNBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaNBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaNBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaNBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaNBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2=  ui.afcmtfaNBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaNBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaNBAutoSearchcheckBox;
		mtfafcParameter										=	itemshareData.mtfnearafcParameter;
		if(!mtfafcParameter) return;
	}
	else if(uctype == 1){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName	=	"afcmtfmiddle";
		afcTableWidget				=	ui.afcmtfaMBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaMBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaMBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaMBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaMBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaMBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaMBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2	=	ui.afcmtfaMBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaMBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaMBAutoSearchcheckBox;
		mtfafcParameter										=	itemshareData.mtfmiddleafcParameter;
		if(!mtfafcParameter) return;
	}
	else if(uctype == 2){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName		=	"afcmtffar";
		afcTableWidget				=	ui.afcmtfaFBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaFBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaFBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaFBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaFBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaFBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaFBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2	=	ui.afcmtfaFBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaFBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaFBAutoSearchcheckBox;
		mtfafcParameter										=	itemshareData.mtffarafcParameter;
		if(!mtfafcParameter) return;
	}
	else{
		classItemProcess->getmtffaParameter(true, false);
		strItemName	=	"mtfmfa";
		afcTableWidget				=	ui.mfamtfaFBtableWidget;
		afcmtfaBAlgComboBox	=	ui.mfamtfaFBAlgComboBox;

		afcmtfaBROIWSpinBox	=	ui.mfamtfaFBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.mfamtfaFBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.mfamtfaFBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H=ui.mfamtfaFBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V=ui.mfamtfaFBCenterSpecdoubleSpinBox_V;

		afcmtfaBCenterWeightdoubleSpinBox	=	ui.mfamtfaFBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.mfamtfaFBAutoSearchcheckBox;
		if(!itemshareData.mtffaParameter) return;
	}

	for(unsigned int row=0; row < afcTableWidget->rowCount();	++row){
		((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(false);
	}

	if(uctype > 2)
	{
		afcmtfaBAlgComboBox->setCurrentIndex(itemshareData.mtffaParameter->stMTFBasic.algswitch-1);
		afcmtfaBROIWSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.iblockwith);
		afcmtfaBROIHSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.iblockheight);
		afcmtfaBCenterSpecdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flcenterspec);
		afcmtfaBCenterSpecdoubleSpinBox_H->setValue(itemshareData.mtffaParameter->stMTFBasic_Ex.flHcenterspec);
		afcmtfaBCenterSpecdoubleSpinBox_V->setValue(itemshareData.mtffaParameter->stMTFBasic_Ex.flVcenterspec);
		afcmtfaBCenterWeightdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flcenterweight);
		afcmtfaBAutoSearchcheckBox->setChecked(itemshareData.mtffaParameter->stMTFBasic.bAutoSeartchROI);
		ui.mfamtfaFBGradeMultipledoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flGradeMultiple);
#if (defined USE_MANUAL_LENS_BIN)
		ui.mfamtfaFBGradecomboBox->setCurrentIndex(ui.mfamtfaFBGradecomboBox->findText(QString::number(itemshareData.mtffaParameter->stMTFBasic.ucGrade)));
		ui.mfamtfaFBCenterSpecBdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flCenterGradeB);
		ui.mfamtfaFBCenterSpecCdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flCenterGradeC);
		ui.mfamtfaFBCenterSpecDdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flCenterGradeD);
		ui.mfamtfaFBCenterSpecEdoubleSpinBox->setValue(itemshareData.mtffaParameter->stMTFBasic.flCenterGradeE);
#endif

		for(int row = 0; row < itemshareData.mtffaParameter->vectorMTFItem.size();++row)
		{
			((QComboBox*)afcTableWidget->cellWidget(row, 1))->setCurrentIndex(((QComboBox*)afcTableWidget->cellWidget(row, 1))->findText(QString::number(itemshareData.mtffaParameter->vectorMTFItem.at(row).ucBlockCount)));
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flFOV);
			((QSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flAngle);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flWeight);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flSpec);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flSpecUniform);
#if (defined USE_MANUAL_LENS_BIN)
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 9))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flGradeD);
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 8))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flGradeC);
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 7))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flGradeB);
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 10))->setValue(itemshareData.mtffaParameter->vectorMTFItem.at(row).flGradeE);
#endif
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 11))->setValue(itemshareData.mtffaParameter->vectorMTFItem_Ex.at(row).flHSpec);
			((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 12))->setValue(itemshareData.mtffaParameter->vectorMTFItem_Ex.at(row).flVSpec);
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
	}
	else
	{
		afcmtfaBAlgComboBox->setCurrentIndex(mtfafcParameter->stMTFBasic.algswitch-1);
		afcmtfaBROIWSpinBox->setValue(mtfafcParameter->stMTFBasic.iblockwith);
		afcmtfaBROIHSpinBox->setValue(mtfafcParameter->stMTFBasic.iblockheight);
		afcmtfaBCenterSpecdoubleSpinBox->setValue(mtfafcParameter->stMTFBasic.flcenterspec);
		afcmtfaBCenterSpecdoubleSpinBox_H->setValue(mtfafcParameter->stMTFBasic_Ex.flHcenterspec);
		afcmtfaBCenterSpecdoubleSpinBox_V->setValue(mtfafcParameter->stMTFBasic_Ex.flVcenterspec);
		afcmtfaBCenterSpecdoubleSpinBox_2->setValue(mtfafcParameter->stMTFBasic.flCenterGradeB);
		afcmtfaBCenterWeightdoubleSpinBox->setValue(mtfafcParameter->stMTFBasic.flcenterweight);
		afcmtfaBAutoSearchcheckBox->setChecked(mtfafcParameter->stMTFBasic.bAutoSeartchROI);

		for(int row = 0; row < mtfafcParameter->vectorMTFItem.size();	++row)
		{
			((QComboBox*)afcTableWidget->cellWidget(row, 1))->setCurrentIndex(((QComboBox*)afcTableWidget->cellWidget(row, 1))->findText(QString::number(mtfafcParameter->vectorMTFItem.at(row).ucBlockCount)));
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(mtfafcParameter->vectorMTFItem.at(row).flFOV);
			((QSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(mtfafcParameter->vectorMTFItem.at(row).flAngle);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(mtfafcParameter->vectorMTFItem.at(row).flWeight);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(mtfafcParameter->vectorMTFItem.at(row).flSpec);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(mtfafcParameter->vectorMTFItem.at(row).flSpecUniform);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->setValue(mtfafcParameter->vectorMTFItem.at(row).flGradeB);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->setValue(mtfafcParameter->vectorMTFItem_Ex.at(row).flHSpec);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->setValue(mtfafcParameter->vectorMTFItem_Ex.at(row).flVSpec);
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
	}
}

int configsetting::saveAFCMTFBasicData(unsigned char uctype)
{
	int iresult	=	0;

	QString strItemName;
	QTableWidget* afcTableWidget;
	QComboBox *afcmtfaBAlgComboBox;
	QSpinBox *afcmtfaBROIWSpinBox, *afcmtfaBROIHSpinBox;
	QDoubleSpinBox *afcmtfaBCenterSpecdoubleSpinBox,*afcmtfaBCenterSpecdoubleSpinBox_2, *afcmtfaBCenterWeightdoubleSpinBox,\
		*afcmtfaBCenterSpecdoubleSpinBox_H,*afcmtfaBCenterSpecdoubleSpinBox_V;
	QCheckBox *afcmtfaBAutoSearchcheckBox;
	int uiIndex;

	if(uctype == 0){
		uiIndex	=	_HisDB_Index_AFCMTFNearBasic;
		strItemName	=	"afcmtfnear";
		afcTableWidget				=	ui.afcmtfaNBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaNBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaNBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaNBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaNBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaNBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaNBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2=ui.afcmtfaNBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaNBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaNBAutoSearchcheckBox;
	}
	else if(uctype == 1){
		uiIndex	=	_HisDB_Index_AFCMTFMiddleBasic;
		strItemName	=	"afcmtfmiddle";
		afcTableWidget				=	ui.afcmtfaMBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaMBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaMBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaMBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaMBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaMBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaMBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2=	ui.afcmtfaMBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaMBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaMBAutoSearchcheckBox;
	}
	else if(uctype == 2){
		uiIndex	=	_HisDB_Index_AFCMTFFarBasic;
		strItemName		=	"afcmtffar";
		afcTableWidget				=	ui.afcmtfaFBtableWidget;
		afcmtfaBAlgComboBox	=	ui.afcmtfaFBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.afcmtfaFBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.afcmtfaFBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.afcmtfaFBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.afcmtfaFBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.afcmtfaFBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterSpecdoubleSpinBox_2=ui.afcmtfaFBCenterSpecdoubleSpinBox_2;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.afcmtfaFBCenterWeightdoubleSpinBox;
		afcmtfaBAutoSearchcheckBox				=	ui.afcmtfaFBAutoSearchcheckBox;
	}
	else{
		uiIndex	=	_HisDB_Index_MTFFA;
		strItemName	=	"mtfmfa";
		afcTableWidget				=	ui.mfamtfaFBtableWidget;
		afcmtfaBAlgComboBox	=	ui.mfamtfaFBAlgComboBox;
		afcmtfaBROIWSpinBox	=	ui.mfamtfaFBROIWSpinBox;
		afcmtfaBROIHSpinBox	=	ui.mfamtfaFBROIHSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox	=	ui.mfamtfaFBCenterSpecdoubleSpinBox;
		afcmtfaBCenterSpecdoubleSpinBox_H	=	ui.mfamtfaFBCenterSpecdoubleSpinBox_H;
		afcmtfaBCenterSpecdoubleSpinBox_V	=	ui.mfamtfaFBCenterSpecdoubleSpinBox_V;
		afcmtfaBCenterWeightdoubleSpinBox	=	ui.mfamtfaFBCenterWeightdoubleSpinBox;	
		afcmtfaBAutoSearchcheckBox				=	ui.mfamtfaFBAutoSearchcheckBox;
	}

#if (defined USE_MANUAL_LENS_BIN)
	if(uctype == 3)
	{
		bool bError = false;
		if(ui.mfamtfaFBCenterSpecdoubleSpinBox->value() <= ui.mfamtfaFBCenterSpecBdoubleSpinBox->value())
			bError = true;
		if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 3 && \
			ui.mfamtfaFBCenterSpecBdoubleSpinBox->value() <= ui.mfamtfaFBCenterSpecCdoubleSpinBox->value())
			bError = true;
		if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 4 && \
			ui.mfamtfaFBCenterSpecCdoubleSpinBox->value() <= ui.mfamtfaFBCenterSpecDdoubleSpinBox->value())
			bError = true;
		if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 5 && \
			ui.mfamtfaFBCenterSpecDdoubleSpinBox->value() <= ui.mfamtfaFBCenterSpecEdoubleSpinBox->value())
			bError = true;

		if(bError){
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("中心规格的大小顺序不正确。"));
			return HisFX3Error_Parameter;
		}

		for(unsigned int row=0; row <afcTableWidget->rowCount();	++row){
			if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked()){
				if(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 5))->value() <= ((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 7))->value())
					bError = true;
				if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 3 && \
					((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 7))->value() <= ((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 8))->value())
					bError = true;
				if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 4 && \
					((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 8))->value() <= ((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 9))->value())
					bError = true;
				if(ui.mfamtfaFBGradecomboBox->currentText().toUInt() > 5 && \
					((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 9))->value() <= ((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 10))->value())
					bError = true;

				if(bError){
					ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("周边规格的大小顺序不正确。"));
					return HisFX3Error_Parameter;
				}
			}
		}
	}
#endif

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "basic");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "fovitem");

			/************basic**************/
			//(algswitch:0)(roiw:y)(roih:100)(centerspec:0.5)(centerweight:1.0)(autoseartch:true)(grademultiple:1.2)
			strname.clear();strvalue.clear();
			strname.append("algswitch");strvalue.append(QString::number(afcmtfaBAlgComboBox->currentIndex() + 1));
			strname.append("roiw");strvalue.append(afcmtfaBROIWSpinBox->cleanText());
			strname.append("roih");strvalue.append(afcmtfaBROIHSpinBox->cleanText());
			strname.append("centerspec");strvalue.append(afcmtfaBCenterSpecdoubleSpinBox->cleanText());
			strname.append("centerspec_h");strvalue.append(afcmtfaBCenterSpecdoubleSpinBox_H->cleanText());
			strname.append("centerspec_v");strvalue.append(afcmtfaBCenterSpecdoubleSpinBox_V->cleanText());
			strname.append("centerweight");strvalue.append(afcmtfaBCenterWeightdoubleSpinBox->cleanText());
			strname.append("autoseartch");strvalue.append((afcmtfaBAutoSearchcheckBox->isChecked())?("true"):("false"));
			if(uctype == 3){
				strname.append("grademultiple");strvalue.append(ui.mfamtfaFBGradeMultipledoubleSpinBox->cleanText());
			}
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			key.clear();
#if (defined USE_MANUAL_LENS_BIN)
			if(uctype == 3)
			{
				//(gradecount:4)(grade_d:0.1)(grade_c:0.1)(grade_b:0.1)(grade_e:0.1)
				strname.clear();strvalue.clear();
				strname.append("gradecount");strvalue.append(ui.mfamtfaFBGradecomboBox->currentText());
				strname.append("grade_d");strvalue.append(ui.mfamtfaFBCenterSpecDdoubleSpinBox->cleanText());
				strname.append("grade_c");strvalue.append(ui.mfamtfaFBCenterSpecCdoubleSpinBox->cleanText());
				strname.append("grade_b");strvalue.append(ui.mfamtfaFBCenterSpecBdoubleSpinBox->cleanText());
				strname.append("grade_e");strvalue.append(ui.mfamtfaFBCenterSpecEdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(key, strname, strvalue);
			}else{
				strname.clear();strvalue.clear();
				strname.append("grade_b");strvalue.append(afcmtfaBCenterSpecdoubleSpinBox_2->cleanText());
				ROPLOW::jointconfigstring(key, strname, strvalue);
			}
#endif
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "basic", itemsuffix2, key);

			stSqlDB.transaction();
			for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
			{
				/************fovitem**************/
				//(blockcount:4)(fov:0.5)(angle:0)(weight:1.0)
				//(spec:0.5)(specuniform:0.5)
				if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked())
				{
					strname.clear();strvalue.clear();
					strname.append("blockcount");strvalue.append(((QComboBox*)afcTableWidget->cellWidget(row, 1))->currentText());
					strname.append("fov");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->cleanText());
					strname.append("angle");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 3))->cleanText());
					strname.append("weight");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->cleanText());
					ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

					strname.clear();strvalue.clear();
					strname.append("spec");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->cleanText());
					strname.append("specuniform");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->cleanText());
					strname.append("grade_b");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->cleanText());
					
					

					ROPLOW::jointconfigstring(key, strname, strvalue);

					value1.clear();

					if(uctype == 3){
						//(grade_d:0.1)(grade_c:0.1)(grade_b:0.1)(grade_e:0.1)
						strname.clear();strvalue.clear();
						strname.append("grade_d");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 9))->cleanText());
						strname.append("grade_c");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 8))->cleanText());
						strname.append("grade_b");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 7))->cleanText());
						strname.append("grade_e");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 10))->cleanText());
						strname.append("spec_h");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 11))->cleanText());
						strname.append("spec_v");strvalue.append(((QDoubleSpinBox*)ui.mfamtfaFBtableWidget->cellWidget(row, 12))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);
					}else{
						strname.clear();strvalue.clear();
						strname.append("spec_h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->cleanText());
						strname.append("spec_v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);
					}

					HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "fovitem", itemsuffix2, key, value1);
				}
			}
			stSqlDB.commit();

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::afcMTFTactics2UI(unsigned char uctype)
{
	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QSpinBox *afcmtfaTStartMotorMinSpinBox, *afcmtfaTStartMotorMaxSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox, *afcmtfaTStartMotorDefdoubleSpinBox;
	QCheckBox *afcsfraTUseDBcheckBox,  *afcsfraTCurveFittingcheckBox, *afcsfraTLinearBackcheckBox, *afcmtfaTTestStartMotorcheckBox;
	_mtfAFCParameter* mtfafcParameter;

	if(uctype == 0){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName	=	"afcmtfnear";
		afcsfraTTacticscomboBox				=	ui.afcmtfaNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaNTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaNTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaNTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaNTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaNTStartMotorMaxSpinBox;
		mtfafcParameter								=	itemshareData.mtfnearafcParameter;
		if(!mtfafcParameter) return;
	}
	else if(uctype == 1){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName	=	"afcmtfmiddle";
		afcsfraTTacticscomboBox				=	ui.afcmtfaMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaMTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaMTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaMTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaMTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaMTStartMotorMaxSpinBox;
		mtfafcParameter								=	itemshareData.mtfmiddleafcParameter;
		if(!mtfafcParameter) return;
	}
	else if(uctype == 2){
		classItemProcess->getmtfAFCCAParameter(uctype, true, false);
		strItemName		=	"afcmtffar";
		afcsfraTTacticscomboBox				=	ui.afcmtfaFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaFTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaFTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaFTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaFTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaFTStartMotorMaxSpinBox;
		mtfafcParameter								=	itemshareData.mtffarafcParameter;
		if(!mtfafcParameter) return;
	}
	else{
		strItemName	=	"afcmtffa";
	}

	afcsfraTMaxStepsSpinBox->setValue(mtfafcParameter->stTacticsBasic.usMaxSteps);
	afcsfraTStepDelaysSpinBox->setValue(mtfafcParameter->stTacticsBasic.usStepDelay);
	afcsfraTMotorStartSpinBox->setValue(mtfafcParameter->stTacticsBasic.sMotorStart);
	afcsfraTMotorEndSpinBox->setValue(mtfafcParameter->stTacticsBasic.sMotorEnd);
	afcsfraTMotorMinSpinBox->setValue(mtfafcParameter->stTacticsBasic.sMotorSpecMin);
	afcsfraTMotorMaxSpinBox->setValue(mtfafcParameter->stTacticsBasic.sMotorSpecMax);
	afcsfraTBigStepSpinBox->setValue(mtfafcParameter->stTacticsBasic.ucBigStep);
	afcsfraTMiddleStepSpinBox->setValue(mtfafcParameter->stTacticsBasic.ucMiddleStep);
	afcsfraTSmallStepSpinBox->setValue(mtfafcParameter->stTacticsBasic.ucSmallStep);
	afcsfraTCurveDefdoubleSpinBox->setValue(mtfafcParameter->stTacticsBasic.flCurveValidDef);
	afcsfraTFalloffDefdoubleSpinBox->setValue(mtfafcParameter->stTacticsBasic.flCurveFalloffDef);
	afcsfraTTacticscomboBox->setCurrentIndex(mtfafcParameter->stTacticsBasic.ucTactics);
	afcsfraTValueChoosecomboBox->setCurrentIndex(mtfafcParameter->stTacticsBasic.ucValueChoose);
	afcsfraTValueTypecomboBox->setCurrentIndex(mtfafcParameter->stTacticsBasic.ucValueTypeChoose);
	afcsfraTUseDBcheckBox->setChecked(mtfafcParameter->stTacticsBasic.bDataBase);
	afcsfraTCurveFittingcheckBox->setChecked(mtfafcParameter->stTacticsBasic.bCurveFitting);
	afcsfraTLinearBackcheckBox->setChecked(mtfafcParameter->stTacticsBasic.bLinearBack);
	afcmtfaTTestStartMotorcheckBox->setChecked(mtfafcParameter->stTacticsBasic.bTestStartMotor);
	afcmtfaTStartMotorDefdoubleSpinBox->setValue(mtfafcParameter->stTacticsBasic.flStartMotorDevDef);
	afcmtfaTStartMotorMinSpinBox->setValue(mtfafcParameter->stTacticsBasic.sStartMotorMin);
	afcmtfaTStartMotorMaxSpinBox->setValue(mtfafcParameter->stTacticsBasic.sStartMotorMax);
}

int configsetting::saveAFCMTFTacticsData(unsigned char uctype)
{
	int iresult	=	0;

	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QSpinBox *afcmtfaTStartMotorMinSpinBox, *afcmtfaTStartMotorMaxSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox, *afcmtfaTStartMotorDefdoubleSpinBox;
	QCheckBox *afcsfraTUseDBcheckBox, *afcsfraTCurveFittingcheckBox, *afcsfraTLinearBackcheckBox, *afcmtfaTTestStartMotorcheckBox;
	int uiIndex;

	if(uctype == 0){
		uiIndex	=	_HisDB_Index_AFCMTFNearTactics;
		strItemName	=	"afcmtfnear";
		afcsfraTTacticscomboBox				=	ui.afcmtfaNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaNTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaNTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaNTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaNTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaNTStartMotorMaxSpinBox;
	}
	else if(uctype == 1){
		uiIndex	=	_HisDB_Index_AFCMTFMiddleTactics;
		strItemName	=	"afcmtfmiddle";
		afcsfraTTacticscomboBox				=	ui.afcmtfaMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaMTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaMTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaMTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaMTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaMTStartMotorMaxSpinBox;
	}
	else if(uctype == 2){
		uiIndex	=	_HisDB_Index_AFCMTFFarTactics;
		strItemName		=	"afcmtffar";
		afcsfraTTacticscomboBox				=	ui.afcmtfaFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcmtfaFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcmtfaFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcmtfaFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcmtfaFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcmtfaFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcmtfaFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcmtfaFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcmtfaFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcmtfaFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcmtfaFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcmtfaFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcmtfaFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcmtfaFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcmtfaFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcmtfaFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcmtfaFTLinearBackcheckBox;
		afcmtfaTTestStartMotorcheckBox	=	ui.afcmtfaFTTestStartMotorcheckBox;
		afcmtfaTStartMotorDefdoubleSpinBox	=	ui.afcmtfaFTStartMotorDefdoubleSpinBox;
		afcmtfaTStartMotorMinSpinBox		=	ui.afcmtfaFTStartMotorMinSpinBox;
		afcmtfaTStartMotorMaxSpinBox		=	ui.afcmtfaFTStartMotorMaxSpinBox;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "statics");

			/************statics**************/
			//(tactics:0)(usedb:true)(maxstep:10)(stepdelay:500)(valuechoose:0)(valuetype:0)
			//(motorstart:0)(motorend:1023)(motormin:0)(motormax:1023)(bigstep:20)(middlestep:10)(smallstep:5)
			//(curvedef:0.2)(falloffdef:0.1)(linearback:true)(teststartmotor:true)(startmotordef:0.05)(startmotormin:0)(startmotormax:1023)
			strname.clear();strvalue.clear();
			strname.append("tactics");strvalue.append(QString::number(afcsfraTTacticscomboBox->currentIndex()));
			strname.append("usedb");strvalue.append((afcsfraTUseDBcheckBox->isChecked())?("true"):("false"));
			strname.append("fitting");strvalue.append((afcsfraTCurveFittingcheckBox->isChecked())?("true"):("false"));			
			strname.append("maxstep");strvalue.append(afcsfraTMaxStepsSpinBox->cleanText());
			strname.append("stepdelay");strvalue.append(afcsfraTStepDelaysSpinBox->cleanText());
			strname.append("valuechoose");strvalue.append(QString::number(afcsfraTValueChoosecomboBox->currentIndex()));
			strname.append("valuetype");strvalue.append(QString::number(afcsfraTValueTypecomboBox->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("motorstart");strvalue.append(afcsfraTMotorStartSpinBox->cleanText());
			strname.append("motorend");strvalue.append(afcsfraTMotorEndSpinBox->cleanText());
			strname.append("motormin");strvalue.append(afcsfraTMotorMinSpinBox->cleanText());
			strname.append("motormax");strvalue.append(afcsfraTMotorMaxSpinBox->cleanText());
			strname.append("bigstep");strvalue.append(afcsfraTBigStepSpinBox->cleanText());
			strname.append("middlestep");strvalue.append(afcsfraTMiddleStepSpinBox->cleanText());
			strname.append("smallstep");strvalue.append(afcsfraTSmallStepSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			//(curvedef:0.2)(falloffdef:0.1)(linearback:true)(teststartmotor:true)(startmotordef:0.05)(startmotormin:0)(startmotormax:1023)
			strname.clear();strvalue.clear();
			strname.append("curvedef");strvalue.append(afcsfraTCurveDefdoubleSpinBox->cleanText());
			strname.append("falloffdef");strvalue.append(afcsfraTFalloffDefdoubleSpinBox->cleanText());
			strname.append("linearback");strvalue.append((afcsfraTLinearBackcheckBox->isChecked())?("true"):("false"));
			strname.append("teststartmotor");strvalue.append((afcmtfaTTestStartMotorcheckBox->isChecked())?("true"):("false"));
			strname.append("startmotordef");strvalue.append(afcmtfaTStartMotorDefdoubleSpinBox->cleanText());
			strname.append("startmotormin");strvalue.append(afcmtfaTStartMotorMinSpinBox->cleanText());
			strname.append("startmotormax");strvalue.append(afcmtfaTStartMotorMaxSpinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", strItemName,  "statics", itemsuffix2, key, value1);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::createSFRAAFCTable(QTableWidget* pstTable)
{
	for(unsigned int row=0; row < pstTable->rowCount();	++row){
		QCheckBox* pstTest	=	new QCheckBox();
		pstTable->setCellWidget(row, 0,  pstTest);
		QComboBox* pstBlockCount	=	new QComboBox();
		pstBlockCount->addItem("2");
		pstBlockCount->addItem("4");
		pstBlockCount->setCurrentIndex(1);
		pstTable->setCellWidget(row, 1,  pstBlockCount);
		QDoubleSpinBox* pstFOV	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 2,  pstFOV);
		pstFOV->setRange(0.05, 0.95);
		pstFOV->setDecimals(3);
		pstFOV->setValue(0.7);
		QSpinBox* pstAngle	=	new QSpinBox();
		pstTable->setCellWidget(row, 3,  pstAngle);
		pstAngle->setRange(0, 179);
		QDoubleSpinBox* pstWeight	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 4,  pstWeight);
		pstWeight->setRange(0.0, 1.0);
		pstWeight->setDecimals(2);
		QDoubleSpinBox* pstMTF50H	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 5,  pstMTF50H);
		pstMTF50H->setRange(0.0, 1.0);
		pstMTF50H->setDecimals(3);
		pstMTF50H->setValue(0.3);
		QDoubleSpinBox* pstMTF50V	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 6,  pstMTF50V);
		pstMTF50V->setRange(0.0, 1.0);
		pstMTF50V->setDecimals(3);
		pstMTF50V->setValue(0.3);
		QDoubleSpinBox* pstMTF50U	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 7,  pstMTF50U);
		pstMTF50U->setRange(0.0, 1.0);
		pstMTF50U->setDecimals(3);
		pstMTF50U->setValue(0.3);
		QDoubleSpinBox* pstFreq1H	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 8,  pstFreq1H);
		pstFreq1H->setRange(0.0, 1.0);
		pstFreq1H->setDecimals(3);
		pstFreq1H->setValue(0.3);
		QDoubleSpinBox* pstFreq1V	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 9,  pstFreq1V);
		pstFreq1V->setRange(0.0, 1.0);
		pstFreq1V->setDecimals(3);
		pstFreq1V->setValue(0.3);
		QDoubleSpinBox* pstFreq1U	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 10,  pstFreq1U);
		pstFreq1U->setRange(0.0, 1.0);
		pstFreq1U->setDecimals(3);
		pstFreq1U->setValue(0.3);
		QDoubleSpinBox* pstFreq2H	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 11,  pstFreq2H);
		pstFreq2H->setRange(0.0, 1.0);
		pstFreq2H->setDecimals(3);
		pstFreq2H->setValue(0.3);
		QDoubleSpinBox* pstFreq2V	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 12,  pstFreq2V);
		pstFreq2V->setRange(0.0, 1.0);
		pstFreq2V->setDecimals(3);
		pstFreq2V->setValue(0.3);
		QDoubleSpinBox* pstFreq3U	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 13,  pstFreq3U);
		pstFreq3U->setRange(0.0, 1.0);
		pstFreq3U->setDecimals(3);
		pstFreq3U->setValue(0.3);

		if(pstTable == ui.mfasfratableWidget){
#if (defined USE_MANUAL_LENS_BIN)
			QDoubleSpinBox* pstMTF50GBH	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 14,  pstMTF50GBH);
			pstMTF50GBH->setRange(0.0, 1.0);
			pstMTF50GBH->setDecimals(3);
			pstMTF50GBH->setValue(0.3);
			QDoubleSpinBox* pstMTF50GBV	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 15,  pstMTF50GBV);
			pstMTF50GBV->setRange(0.0, 1.0);
			pstMTF50GBV->setDecimals(3);
			pstMTF50GBV->setValue(0.3);
			QDoubleSpinBox* pstMTF50GCH	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 16,  pstMTF50GCH);
			pstMTF50GCH->setRange(0.0, 1.0);
			pstMTF50GCH->setDecimals(3);
			pstMTF50GCH->setValue(0.3);
			QDoubleSpinBox* pstMTF50GCV	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 17,  pstMTF50GCV);
			pstMTF50GCV->setRange(0.0, 1.0);
			pstMTF50GCV->setDecimals(3);
			pstMTF50GCV->setValue(0.3);
			QDoubleSpinBox* pstMTF50GDH	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 18,  pstMTF50GDH);
			pstMTF50GDH->setRange(0.0, 1.0);
			pstMTF50GDH->setDecimals(3);
			pstMTF50GDH->setValue(0.3);
			QDoubleSpinBox* pstMTF50GDV	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 19,  pstMTF50GDV);
			pstMTF50GDV->setRange(0.0, 1.0);
			pstMTF50GDV->setDecimals(3);
			pstMTF50GDV->setValue(0.3);
			QDoubleSpinBox* pstMTF50GEH	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 20,  pstMTF50GEH);
			pstMTF50GEH->setRange(0.0, 1.0);
			pstMTF50GEH->setDecimals(3);
			pstMTF50GEH->setValue(0.3);
			QDoubleSpinBox* pstMTF50GEV	=	new QDoubleSpinBox();
			pstTable->setCellWidget(row, 21,  pstMTF50GEV);
			pstMTF50GEV->setRange(0.0, 1.0);
			pstMTF50GEV->setDecimals(3);
			pstMTF50GEV->setValue(0.3);
#endif
		}
	}

	if(pstTable == ui.mfasfratableWidget)
	{
#if (defined USE_MANUAL_LENS_BIN)
		QStringList listHorizontalHeader;
		listHorizontalHeader << tr("Test") << tr("ROI Numbers") <<"FOV" << tr("Angle") << tr("Weight") << tr("Grade A-H") << tr("Grade A-V") << \
			tr("MTF50-U") << tr("Freq1-H") << tr("Freq1-V") << tr("Freq1-U") << tr("Freq2-H") << tr("Freq2-V") << tr("Freq2-U") << \
			tr("Grade B-H") << tr("Grade B-V") << tr("Grade C-H") << tr("Grade C-V") << tr("Grade D-H") << tr("Grade D-V") << \
			tr("Grade E-H") << tr("Grade E-V");
		pstTable->setHorizontalHeaderLabels(listHorizontalHeader);
		pstTable->hideColumn(4);		
		pstTable->hideColumn(7);
		pstTable->hideColumn(8);
		pstTable->hideColumn(9);
		pstTable->hideColumn(10);
		pstTable->hideColumn(11);
		pstTable->hideColumn(12);
		pstTable->hideColumn(13);
#else	
		pstTable->hideColumn(14);
		pstTable->hideColumn(15);
		pstTable->hideColumn(16);
		pstTable->hideColumn(17);
		pstTable->hideColumn(18);
		pstTable->hideColumn(19);
		pstTable->hideColumn(20);
		pstTable->hideColumn(21);
#endif
	}
}

void configsetting::afcSFRABasic2UI(unsigned char uctype)
{
	QString strItemName;
	QTableWidget* afcTableWidget;
	QComboBox *afcsfraBMethodcomboBox, *afcsfraBChannelcomboBox;
	QSpinBox *afcsfraBFOVOffsetSpinBox, *afcsfraBContrastSpinBox, *afcsfraBROIWSpinBox, *afcsfraBROIHSpinBox, *afcsfraBF1SpinBox, *afcsfraBF2SpinBox;
	QSpinBox *afcsfraBBlockSideMinSpinBox, *afcsfraBBlockSideMaxSpinBox;
	QDoubleSpinBox *afcsfraBCenterWeightdoubleSpinBox, *afcsfraBCenterMTF50HdoubleSpinBox, *afcsfraBCenterMTF50VdoubleSpinBox;
	QDoubleSpinBox *afcsfraBCenterF1HdoubleSpinBox, *afcsfraBCenterF1VdoubleSpinBox, *afcsfraBCenterF2HdoubleSpinBox, *afcsfraBCenterF2VdoubleSpinBox;
	QCheckBox *afcsfraBUseF2checkBox, *afcsfraBOnlyInnercheckBox;
	_SFRAFCCAParameter* sfrafcParameter;

	if(uctype == 0){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName	=	"afcsfranear";
		afcTableWidget	=	ui.afcsfraNBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraNBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraNBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraNBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraNBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraNBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraNBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraNBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraNBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraNBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraNBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraNBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraNBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraNBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraNBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraNBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraNBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraNBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraNBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraNBOnlyInnercheckBox;
		sfrafcParameter							=	itemshareData.sfrnearafcParameter;
		if(!sfrafcParameter)	return;
	}
	else if(uctype == 1){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName	=	"afcsframiddle";
		afcTableWidget	=	ui.afcsfraMBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraMBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraMBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraMBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraMBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraMBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraMBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraMBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraMBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraMBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraMBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraMBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraMBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraMBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraMBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraMBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraMBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraMBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraMBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraMBOnlyInnercheckBox;
		sfrafcParameter							=	itemshareData.sfrmiddleafcParameter;
		if(!sfrafcParameter)	return;
	}
	else if(uctype == 2){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName		=	"afcsfrafar";
		afcTableWidget	=	ui.afcsfraFBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraFBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraFBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraFBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraFBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraFBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraFBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraFBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraFBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraFBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraFBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraFBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraFBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraFBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraFBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraFBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraFBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraFBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraFBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraFBOnlyInnercheckBox;
		sfrafcParameter							=	itemshareData.sfrfarafcParameter;
		if(!sfrafcParameter)	return;
	}
	else{
		classItemProcess->getSFRMFACAParameter(true, false);
		strItemName	=	"sframfa";
		afcTableWidget	=	ui.mfasfratableWidget;
		afcsfraBMethodcomboBox	=	ui.mfasfraMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.mfasfraChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.mfasfraFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.mfasfraContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.mfasfraROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.mfasfraROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.mfasfraF1SpinBox;
		afcsfraBF2SpinBox	=	ui.mfasfraF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.mfasfraCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.mfasfraCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.mfasfraCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.mfasfraCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.mfasfraCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.mfasfraCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.mfasfraCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.mfasfraUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.mfasfraBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.mfasfraBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.mfasfraOnlyInnercheckBox;
		if(!itemshareData.sfrfacaParameter) return;
	}

	for(unsigned int row=0; row < afcTableWidget->rowCount();	++row){
		((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(false);
	}

	if(uctype > 2)
	{
		afcsfraBFOVOffsetSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.usFOVOffset);
		afcsfraBBlockSideMinSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.usMarkSideMin);
		afcsfraBBlockSideMaxSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.usMarkSideMax);
		afcsfraBContrastSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.ucMinCantrast);
		afcsfraBROIWSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.iROIWidth);
		afcsfraBROIHSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.iROIHeght);
		afcsfraBF1SpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.uc1stFreq);
		afcsfraBF2SpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.uc2ndFreq);
		afcsfraBOnlyInnercheckBox->setChecked(itemshareData.sfrfacaParameter->stSFRBasic.bOnlyInner);
		afcsfraBCenterWeightdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterWeight);
		afcsfraBCenterMTF50HdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50SpecH);
		afcsfraBCenterMTF50VdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50SpecV);
		afcsfraBCenterF1HdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecH);
		afcsfraBCenterF1VdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecV);
		afcsfraBCenterF2HdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecH);
		afcsfraBCenterF2VdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecV);
		afcsfraBMethodcomboBox->setCurrentIndex(itemshareData.sfrfacaParameter->stSFRBasic.ucMethod);
		afcsfraBUseF2checkBox->setChecked(itemshareData.sfrfacaParameter->stSFRBasic.b2ndFreq);
		if(itemshareData.sfrfacaParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_R) afcsfraBChannelcomboBox->setCurrentIndex(1);
		else if(itemshareData.sfrfacaParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gr) afcsfraBChannelcomboBox->setCurrentIndex(2);
		else if(itemshareData.sfrfacaParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gb) afcsfraBChannelcomboBox->setCurrentIndex(2);
		else if(itemshareData.sfrfacaParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_B) afcsfraBChannelcomboBox->setCurrentIndex(3);
		else afcsfraBChannelcomboBox->setCurrentIndex(0);
		ui.mfasfraGradeMultipledoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flGradeMultiple);
#if (defined USE_MANUAL_LENS_BIN)
		ui.mfasfraCenterMTF50GBHdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeBH);
		ui.mfasfraCenterMTF50GBVdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeBV);
		ui.mfasfraCenterMTF50GCHdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeCH);
		ui.mfasfraCenterMTF50GCVdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeCV);
		ui.mfasfraCenterMTF50GDHdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeDH);
		ui.mfasfraCenterMTF50GDVdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeDV);
		ui.mfasfraCenterMTF50GEHdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeEH);
		ui.mfasfraCenterMTF50GEVdoubleSpinBox->setValue(itemshareData.sfrfacaParameter->stSFRBasic.flCenterMTF50GradeEV);
		ui.mfasfraGradeNumcomboBox->setCurrentIndex(ui.mfasfraGradeNumcomboBox->findText(QString::number(itemshareData.sfrfacaParameter->stSFRBasic.ucGradeCount)));
#endif

		for(int row = 0; row < itemshareData.sfrfacaParameter->vectorSFRItem.size(); ++row)
		{
			((QComboBox*)afcTableWidget->cellWidget(row, 1))->setCurrentIndex(((QComboBox*)afcTableWidget->cellWidget(row, 1))->findText(QString::number(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).ucBlockCount)));
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flFOV);
			((QSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flAngle);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flWeight);		
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50SpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50SpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50SpecUnifH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl1stFreqSpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl1stFreqSpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 10))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl1stFreqSpecUnifH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 11))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl2ndFreqSpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 12))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl2ndFreqSpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 13))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).fl2ndFreqSpecUnifH);
#if (defined USE_MANUAL_LENS_BIN)
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 14))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeBH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 15))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeBV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 16))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeCH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 17))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeCV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 18))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeDH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 19))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeDV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 20))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeEH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 21))->setValue(itemshareData.sfrfacaParameter->vectorSFRItem.at(row).flMTF50GradeEV);
#endif
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
	}
	else
	{
		afcsfraBFOVOffsetSpinBox->setValue(sfrafcParameter->stSFRBasic.usFOVOffset);
		afcsfraBBlockSideMinSpinBox->setValue(sfrafcParameter->stSFRBasic.usMarkSideMin);
		afcsfraBBlockSideMaxSpinBox->setValue(sfrafcParameter->stSFRBasic.usMarkSideMax);
		afcsfraBContrastSpinBox->setValue(sfrafcParameter->stSFRBasic.ucMinCantrast);
		afcsfraBROIWSpinBox->setValue(sfrafcParameter->stSFRBasic.iROIWidth);
		afcsfraBROIHSpinBox->setValue(sfrafcParameter->stSFRBasic.iROIHeght);
		afcsfraBF1SpinBox->setValue(sfrafcParameter->stSFRBasic.uc1stFreq);
		afcsfraBF2SpinBox->setValue(sfrafcParameter->stSFRBasic.uc2ndFreq);
		afcsfraBOnlyInnercheckBox->setChecked(sfrafcParameter->stSFRBasic.bOnlyInner);
		afcsfraBCenterWeightdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenterWeight);
		afcsfraBCenterMTF50HdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenterMTF50SpecH);
		afcsfraBCenterMTF50VdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenterMTF50SpecV);
		afcsfraBCenterF1HdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenter1stFreqSpecH);
		afcsfraBCenterF1VdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenter1stFreqSpecV);
		afcsfraBCenterF2HdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenter2ndFreqSpecH);
		afcsfraBCenterF2VdoubleSpinBox->setValue(sfrafcParameter->stSFRBasic.flCenter2ndFreqSpecV);
		afcsfraBMethodcomboBox->setCurrentIndex(sfrafcParameter->stSFRBasic.ucMethod);
		afcsfraBUseF2checkBox->setChecked(sfrafcParameter->stSFRBasic.b2ndFreq);
		if(sfrafcParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_R) afcsfraBChannelcomboBox->setCurrentIndex(1);
		else if(sfrafcParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gr) afcsfraBChannelcomboBox->setCurrentIndex(2);
		else if(sfrafcParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gb) afcsfraBChannelcomboBox->setCurrentIndex(2);
		else if(sfrafcParameter->stSFRBasic.ucChannel == _HisCCMAlg_ImageBuffer_Channel_B) afcsfraBChannelcomboBox->setCurrentIndex(3);
		else afcsfraBChannelcomboBox->setCurrentIndex(0);

		for(int row = 0; row < sfrafcParameter->vectorSFRItem.size(); ++row)
		{
			((QComboBox*)afcTableWidget->cellWidget(row, 1))->setCurrentIndex(((QComboBox*)afcTableWidget->cellWidget(row, 1))->findText(QString::number(sfrafcParameter->vectorSFRItem.at(row).ucBlockCount)));
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(sfrafcParameter->vectorSFRItem.at(row).flFOV);
			((QSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(sfrafcParameter->vectorSFRItem.at(row).flAngle);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(sfrafcParameter->vectorSFRItem.at(row).flWeight);			
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(sfrafcParameter->vectorSFRItem.at(row).flMTF50SpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(sfrafcParameter->vectorSFRItem.at(row).flMTF50SpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->setValue(sfrafcParameter->vectorSFRItem.at(row).flMTF50SpecUnifH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl1stFreqSpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl1stFreqSpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 10))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl1stFreqSpecUnifH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 11))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl2ndFreqSpecH);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 12))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl2ndFreqSpecV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 13))->setValue(sfrafcParameter->vectorSFRItem.at(row).fl2ndFreqSpecUnifH);
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
		
	}

}

int configsetting::saveAFCSFRABasicData(unsigned char uctype)
{
	int iresult	=	0;

	QString strItemName;
	QTableWidget* afcTableWidget;
	QComboBox *afcsfraBMethodcomboBox, *afcsfraBChannelcomboBox;
	QSpinBox *afcsfraBFOVOffsetSpinBox, *afcsfraBContrastSpinBox, *afcsfraBROIWSpinBox, *afcsfraBROIHSpinBox, *afcsfraBF1SpinBox, *afcsfraBF2SpinBox;
	QSpinBox *afcsfraBBlockSideMinSpinBox, *afcsfraBBlockSideMaxSpinBox;
	QDoubleSpinBox *afcsfraBCenterWeightdoubleSpinBox, *afcsfraBCenterMTF50HdoubleSpinBox, *afcsfraBCenterMTF50VdoubleSpinBox;
	QDoubleSpinBox *afcsfraBCenterF1HdoubleSpinBox, *afcsfraBCenterF1VdoubleSpinBox, *afcsfraBCenterF2HdoubleSpinBox, *afcsfraBCenterF2VdoubleSpinBox;
	QCheckBox *afcsfraBUseF2checkBox, *afcsfraBOnlyInnercheckBox;
	int uiIndex;

	if(uctype == 0){
		uiIndex	=	_HisDB_Index_AFCSFRANearBasic;
		strItemName	=	"afcsfranear";
		afcTableWidget	=	ui.afcsfraNBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraNBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraNBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraNBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraNBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraNBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraNBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraNBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraNBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraNBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraNBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraNBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraNBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraNBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraNBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraNBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraNBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraNBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraNBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraNBOnlyInnercheckBox;
	}
	else if(uctype == 1){
		uiIndex	=	_HisDB_Index_AFCSFRAMiddleBasic;
		strItemName	=	"afcsframiddle";
		afcTableWidget	=	ui.afcsfraMBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraMBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraMBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraMBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraMBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraMBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraMBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraMBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraMBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraMBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraMBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraMBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraMBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraMBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraMBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraMBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraMBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraMBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraMBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraMBOnlyInnercheckBox;
	}
	else if(uctype == 2){
		uiIndex	=	_HisDB_Index_AFCSFRAFarBasic;
		strItemName		=	"afcsfrafar";
		afcTableWidget	=	ui.afcsfraFBtableWidget;
		afcsfraBMethodcomboBox	=	ui.afcsfraFBMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.afcsfraFBChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.afcsfraFBFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.afcsfraFBContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.afcsfraFBROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.afcsfraFBROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.afcsfraFBF1SpinBox;
		afcsfraBF2SpinBox	=	ui.afcsfraFBF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.afcsfraFBCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.afcsfraFBCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.afcsfraFBCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.afcsfraFBCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.afcsfraFBCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.afcsfraFBCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.afcsfraFBCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.afcsfraFBUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.afcsfraFBBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.afcsfraFBBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.afcsfraFBOnlyInnercheckBox;
	}
	else{
		uiIndex	=	_HisDB_Index_SFRFACA;
		strItemName	=	"sframfa";
		afcTableWidget	=	ui.mfasfratableWidget;
		afcsfraBMethodcomboBox	=	ui.mfasfraMethodcomboBox;
		afcsfraBChannelcomboBox	=	ui.mfasfraChannelcomboBox;
		afcsfraBFOVOffsetSpinBox	=	ui.mfasfraFOVOffsetSpinBox;
		afcsfraBContrastSpinBox	=	ui.mfasfraContrastSpinBox;
		afcsfraBROIWSpinBox	=	ui.mfasfraROIWSpinBox;
		afcsfraBROIHSpinBox	=	ui.mfasfraROIHSpinBox;
		afcsfraBF1SpinBox	=	ui.mfasfraF1SpinBox;
		afcsfraBF2SpinBox	=	ui.mfasfraF2SpinBox;
		afcsfraBCenterWeightdoubleSpinBox	=	ui.mfasfraCenterWeightdoubleSpinBox;
		afcsfraBCenterMTF50HdoubleSpinBox	=	ui.mfasfraCenterMTF50HdoubleSpinBox;
		afcsfraBCenterMTF50VdoubleSpinBox	=	ui.mfasfraCenterMTF50VdoubleSpinBox;
		afcsfraBCenterF1HdoubleSpinBox	=	ui.mfasfraCenterF1HdoubleSpinBox;
		afcsfraBCenterF1VdoubleSpinBox	=	ui.mfasfraCenterF1VdoubleSpinBox;
		afcsfraBCenterF2HdoubleSpinBox	=	ui.mfasfraCenterF2HdoubleSpinBox;
		afcsfraBCenterF2VdoubleSpinBox	=	ui.mfasfraCenterF2VdoubleSpinBox;
		afcsfraBUseF2checkBox	=	ui.mfasfraUseF2checkBox;
		afcsfraBBlockSideMinSpinBox	=	ui.mfasfraBlockSideMinSpinBox;
		afcsfraBBlockSideMaxSpinBox	=	ui.mfasfraBlockSideMaxSpinBox;
		afcsfraBOnlyInnercheckBox		=	ui.mfasfraOnlyInnercheckBox;
	}

#if (defined USE_MANUAL_LENS_BIN)
	if(uctype == 3)
	{
		bool bError = false;
		if(ui.mfasfraCenterMTF50HdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GBHdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 3 && \
			ui.mfasfraCenterMTF50GBHdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GCHdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 4 && \
			ui.mfasfraCenterMTF50GCHdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GDHdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 5 && \
			ui.mfasfraCenterMTF50GDHdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GEHdoubleSpinBox->value())
			bError = true;

		if(ui.mfasfraCenterMTF50VdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GBVdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 3 && \
			ui.mfasfraCenterMTF50GBVdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GCVdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 4 && \
			ui.mfasfraCenterMTF50GCVdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GDVdoubleSpinBox->value())
			bError = true;
		if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 5 && \
			ui.mfasfraCenterMTF50GDVdoubleSpinBox->value() <= ui.mfasfraCenterMTF50GEVdoubleSpinBox->value())
			bError = true;

		if(bError){
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("中心规格的大小顺序不正确。"));
			return HisFX3Error_Parameter;
		}

		for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
		{
			if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked())
			{
				if(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 14))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 3 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 14))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 16))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 4 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 16))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 18))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 5 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 18))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 20))->value())
					bError = true;

				if(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 15))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 3 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 15))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 17))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 4 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 17))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 19))->value())
					bError = true;
				if(ui.mfasfraGradeNumcomboBox->currentText().toUInt() > 5 && \
					((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 19))->value() <= ((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 21))->value())
					bError = true;

				if(bError){
					ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("周边规格的大小顺序不正确。"));
					return HisFX3Error_Parameter;
				}
			}
		}
	}
#endif

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "basic");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "fovitem");

			if(uctype > 2)
			{
				/************basic**************/
				//(method:0)(channel:y)(fovoffset:100)(sidemin:60)(sidemax:120)(mincontrast:20)(weight:1.0)
				//(roiw:48)(roih:64)(usefreq2:true)(freq1:4)(freq2:8)(onlyinner:false)(gradecount:4)
				strname.clear();strvalue.clear();
				strname.append("method");strvalue.append(QString::number(afcsfraBMethodcomboBox->currentIndex()));
				strname.append("channel");strvalue.append(afcsfraBChannelcomboBox->currentText().toLower());
				strname.append("fovoffset");strvalue.append(afcsfraBFOVOffsetSpinBox->cleanText());
				strname.append("sidemin");strvalue.append(afcsfraBBlockSideMinSpinBox->cleanText());
				strname.append("sidemax");strvalue.append(afcsfraBBlockSideMaxSpinBox->cleanText());
				strname.append("mincontrast");strvalue.append(afcsfraBContrastSpinBox->cleanText());
				strname.append("weight");strvalue.append(afcsfraBCenterWeightdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("roiw");strvalue.append(afcsfraBROIWSpinBox->cleanText());
				strname.append("roih");strvalue.append(afcsfraBROIHSpinBox->cleanText());
				strname.append("usefreq2");strvalue.append((afcsfraBUseF2checkBox->isChecked())?("true"):("false"));
				strname.append("freq1");strvalue.append(afcsfraBF1SpinBox->cleanText());
				strname.append("freq2");strvalue.append(afcsfraBF2SpinBox->cleanText());
				strname.append("onlyinner");strvalue.append((afcsfraBOnlyInnercheckBox->isChecked())?("true"):("false"));
				strname.append("grademultiple");	strvalue.append(ui.mfasfraGradeMultipledoubleSpinBox->cleanText());
#if (defined USE_MANUAL_LENS_BIN)
				strname.append("gradecount"); strvalue.append(ui.mfasfraGradeNumcomboBox->currentText());
#endif
				ROPLOW::jointconfigstring(key, strname, strvalue);

				//(mtf50h:0.0)(mtf50v:0.0)(grade_b_h:0.1)(grade_b_v:0.1)
				//(f1spech:0.0)(f1specv:0.0)(f2spech:0.0)(f2specv:0.0)
				strname.clear();strvalue.clear();
				strname.append("mtf50h");strvalue.append(afcsfraBCenterMTF50HdoubleSpinBox->cleanText());
				strname.append("mtf50v");strvalue.append(afcsfraBCenterMTF50VdoubleSpinBox->cleanText());
#if (defined USE_MANUAL_LENS_BIN)
				strname.append("grade_b_h");strvalue.append(ui.mfasfraCenterMTF50GBHdoubleSpinBox->cleanText());
				strname.append("grade_b_v");strvalue.append(ui.mfasfraCenterMTF50GBVdoubleSpinBox->cleanText());
				strname.append("grade_c_h");strvalue.append(ui.mfasfraCenterMTF50GCHdoubleSpinBox->cleanText());
				strname.append("grade_c_v");strvalue.append(ui.mfasfraCenterMTF50GCVdoubleSpinBox->cleanText());
				strname.append("grade_d_h");strvalue.append(ui.mfasfraCenterMTF50GDHdoubleSpinBox->cleanText());
				strname.append("grade_d_v");strvalue.append(ui.mfasfraCenterMTF50GDVdoubleSpinBox->cleanText());
				strname.append("grade_e_h");strvalue.append(ui.mfasfraCenterMTF50GEHdoubleSpinBox->cleanText());
				strname.append("grade_e_v");strvalue.append(ui.mfasfraCenterMTF50GEVdoubleSpinBox->cleanText());
#endif
				ROPLOW::jointconfigstring(value1, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("f1spech");strvalue.append(afcsfraBCenterF1HdoubleSpinBox->cleanText());
				strname.append("f1specv");strvalue.append(afcsfraBCenterF1VdoubleSpinBox->cleanText());
				strname.append("f2spech");strvalue.append(afcsfraBCenterF2HdoubleSpinBox->cleanText());
				strname.append("f2specv");strvalue.append(afcsfraBCenterF2VdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(reserve, strname, strvalue);
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "basic", itemsuffix2, key, value1, reserve);

				stSqlDB.transaction();
				for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
				{
					/************fovitem**************/
					//(blockcount:4)(fov:0.3)(angle:0)(weight:1.0)
					//(mtf50h:0.0)(mtf50v:0.0)(mtf50u:0.0)(grade_b_h:0.1)(grade_b_v:0.1)
					//(f1spech:0.0)(f1specv:0.0)(f1specu:0.0)
					//(f2spech:0.0)(f2specv:0.0)(f2specu:0.0)
					if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked())
					{
						strname.clear();strvalue.clear();
						strname.append("blockcount");strvalue.append(((QComboBox*)afcTableWidget->cellWidget(row, 1))->currentText());
						strname.append("fov");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->cleanText());
						strname.append("angle");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 3))->cleanText());
						strname.append("weight");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->cleanText());
						ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("mtf50h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->cleanText());
						strname.append("mtf50v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->cleanText());
						strname.append("mtf50u");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->cleanText());
#if (defined USE_MANUAL_LENS_BIN)
						strname.append("grade_b_h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 14))->cleanText());
						strname.append("grade_b_v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 15))->cleanText());
						strname.append("grade_c_h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 16))->cleanText());
						strname.append("grade_c_v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 17))->cleanText());
						strname.append("grade_d_h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 18))->cleanText());
						strname.append("grade_d_v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 19))->cleanText());
						strname.append("grade_e_h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 20))->cleanText());
						strname.append("grade_e_v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 21))->cleanText());
#endif
						ROPLOW::jointconfigstring(key, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("f1spech");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->cleanText());
						strname.append("f1specv");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->cleanText());
						strname.append("f1specu");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 10))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("f2spech");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 11))->cleanText());
						strname.append("f2specv");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 12))->cleanText());
						strname.append("f2specu");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 13))->cleanText());
						ROPLOW::jointconfigstring(reserve, strname, strvalue);
						HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "fovitem", itemsuffix2, key, value1, reserve);
					}
				}
				stSqlDB.commit();
			}
			else
			{
				/************basic**************/
				//(method:0)(channel:y)(fovoffset:100)(sidemin:60)(sidemax:120)(mincontrast:20)(weight:1.0)
				//(roiw:48)(roih:64)(usefreq2:true)(freq1:4)(freq2:8)(onlyinner:false)(gradecount:4)
				strname.clear();strvalue.clear();
				strname.append("method");strvalue.append(QString::number(afcsfraBMethodcomboBox->currentIndex()));
				strname.append("channel");strvalue.append(afcsfraBChannelcomboBox->currentText().toLower());
				strname.append("fovoffset");strvalue.append(afcsfraBFOVOffsetSpinBox->cleanText());
				strname.append("sidemin");strvalue.append(afcsfraBBlockSideMinSpinBox->cleanText());
				strname.append("sidemax");strvalue.append(afcsfraBBlockSideMaxSpinBox->cleanText());
				strname.append("mincontrast");strvalue.append(afcsfraBContrastSpinBox->cleanText());
				strname.append("weight");strvalue.append(afcsfraBCenterWeightdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("roiw");strvalue.append(afcsfraBROIWSpinBox->cleanText());
				strname.append("roih");strvalue.append(afcsfraBROIHSpinBox->cleanText());
				strname.append("usefreq2");strvalue.append((afcsfraBUseF2checkBox->isChecked())?("true"):("false"));
				strname.append("freq1");strvalue.append(afcsfraBF1SpinBox->cleanText());
				strname.append("freq2");strvalue.append(afcsfraBF2SpinBox->cleanText());
				strname.append("onlyinner");strvalue.append((afcsfraBOnlyInnercheckBox->isChecked())?("true"):("false"));
				ROPLOW::jointconfigstring(key, strname, strvalue);

				//(mtf50h:0.0)(mtf50v:0.0)(grade_b_h:0.1)(grade_b_v:0.1)
				//(f1spech:0.0)(f1specv:0.0)(f2spech:0.0)(f2specv:0.0)
				strname.clear();strvalue.clear();
				strname.append("mtf50h");strvalue.append(afcsfraBCenterMTF50HdoubleSpinBox->cleanText());
				strname.append("mtf50v");strvalue.append(afcsfraBCenterMTF50VdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(value1, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("f1spech");strvalue.append(afcsfraBCenterF1HdoubleSpinBox->cleanText());
				strname.append("f1specv");strvalue.append(afcsfraBCenterF1VdoubleSpinBox->cleanText());
				strname.append("f2spech");strvalue.append(afcsfraBCenterF2HdoubleSpinBox->cleanText());
				strname.append("f2specv");strvalue.append(afcsfraBCenterF2VdoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(reserve, strname, strvalue);
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "basic", itemsuffix2, key, value1, reserve);

				stSqlDB.transaction();
				for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
				{
					/************fovitem**************/
					//(blockcount:4)(fov:0.3)(angle:0)(weight:1.0)
					//(mtf50h:0.0)(mtf50v:0.0)(mtf50u:0.0)(grade_b_h:0.1)(grade_b_v:0.1)
					//(f1spech:0.0)(f1specv:0.0)(f1specu:0.0)
					//(f2spech:0.0)(f2specv:0.0)(f2specu:0.0)
					if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked())
					{
						strname.clear();strvalue.clear();
						strname.append("blockcount");strvalue.append(((QComboBox*)afcTableWidget->cellWidget(row, 1))->currentText());
						strname.append("fov");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 2))->cleanText());
						strname.append("angle");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 3))->cleanText());
						strname.append("weight");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 4))->cleanText());
						ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("mtf50h");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 5))->cleanText());
						strname.append("mtf50v");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 6))->cleanText());
						strname.append("mtf50u");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 7))->cleanText());
						ROPLOW::jointconfigstring(key, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("f1spech");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 8))->cleanText());
						strname.append("f1specv");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 9))->cleanText());
						strname.append("f1specu");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 10))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("f2spech");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 11))->cleanText());
						strname.append("f2specv");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 12))->cleanText());
						strname.append("f2specu");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 13))->cleanText());
						ROPLOW::jointconfigstring(reserve, strname, strvalue);
						HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "fovitem", itemsuffix2, key, value1, reserve);
					}
				}
				stSqlDB.commit();
			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::afcSFRATactics2UI(unsigned char uctype)
{
	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox;
	QCheckBox *afcsfraTCurveFittingcheckBox, *afcsfraTUseDBcheckBox, *afcsfraTLinearBackcheckBox;
	_SFRAFCCAParameter* sfrafcParameter;

	if(uctype == 0){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName	=	"afcsfranear";
		afcsfraTTacticscomboBox				=	ui.afcsfraNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraNTLinearBackcheckBox;
		sfrafcParameter								=	itemshareData.sfrnearafcParameter;
		if(!sfrafcParameter) return;
	}
	else if(uctype == 1){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName	=	"afcsframiddle";
		afcsfraTTacticscomboBox				=	ui.afcsfraMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraMTLinearBackcheckBox;
		sfrafcParameter								=	itemshareData.sfrmiddleafcParameter;
		if(!sfrafcParameter) return;
	}
	else if(uctype == 2){
		classItemProcess->getsfrAFCCAParameter(uctype, true, false);
		strItemName		=	"afcsfrafar";
		afcsfraTTacticscomboBox				=	ui.afcsfraFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraFTLinearBackcheckBox;
		sfrafcParameter								=	itemshareData.sfrfarafcParameter;
		if(!sfrafcParameter) return;
	}
	else{
		strItemName	=	"sfrafa";

	}

	/************statics**************/
	//(tactics:0)(usedb:true)(maxstep:10)(stepdelay:500)(valuechoose:0)(valuetype:0)
	//(motorstart:0)(motorend:1023)(motormin:0)(motormax:1023)(bigstep:20)(middlestep:10)(smallstep:5)
	//(curvedef:0.2)(falloffdef:0.1)(linearback:true)
	afcsfraTMaxStepsSpinBox->setValue(sfrafcParameter->stTacticsBasic.usMaxSteps);
	afcsfraTStepDelaysSpinBox->setValue(sfrafcParameter->stTacticsBasic.usStepDelay);
	afcsfraTMotorStartSpinBox->setValue(sfrafcParameter->stTacticsBasic.sMotorStart);
	afcsfraTMotorEndSpinBox->setValue(sfrafcParameter->stTacticsBasic.sMotorEnd);
	afcsfraTMotorMinSpinBox->setValue(sfrafcParameter->stTacticsBasic.sMotorSpecMin);
	afcsfraTMotorMaxSpinBox->setValue(sfrafcParameter->stTacticsBasic.sMotorSpecMax);
	afcsfraTBigStepSpinBox->setValue(sfrafcParameter->stTacticsBasic.ucBigStep);
	afcsfraTMiddleStepSpinBox->setValue(sfrafcParameter->stTacticsBasic.ucMiddleStep);
	afcsfraTSmallStepSpinBox->setValue(sfrafcParameter->stTacticsBasic.ucSmallStep);
	afcsfraTCurveDefdoubleSpinBox->setValue(sfrafcParameter->stTacticsBasic.flCurveValidDef);
	afcsfraTFalloffDefdoubleSpinBox->setValue(sfrafcParameter->stTacticsBasic.flCurveFalloffDef);
	afcsfraTTacticscomboBox->setCurrentIndex(sfrafcParameter->stTacticsBasic.ucTactics);
	afcsfraTValueChoosecomboBox->setCurrentIndex(sfrafcParameter->stTacticsBasic.ucValueChoose);
	afcsfraTValueTypecomboBox->setCurrentIndex(sfrafcParameter->stTacticsBasic.ucValueTypeChoose);
	afcsfraTUseDBcheckBox->setChecked(sfrafcParameter->stTacticsBasic.bDataBase);
	afcsfraTCurveFittingcheckBox->setChecked(sfrafcParameter->stTacticsBasic.bCurveFitting);
	afcsfraTLinearBackcheckBox->setChecked(sfrafcParameter->stTacticsBasic.bLinearBack);
}

int configsetting::saveAFCSFRATacticsData(unsigned char uctype)
{
	int iresult	=	0;

	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox;
	QCheckBox *afcsfraTCurveFittingcheckBox, *afcsfraTUseDBcheckBox, *afcsfraTLinearBackcheckBox;
	int uiIndex;

	if(uctype == 0){
		uiIndex	=	_HisDB_Index_AFCSFRANearTactics;
		strItemName	=	"afcsfranear";
		afcsfraTTacticscomboBox				=	ui.afcsfraNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraNTLinearBackcheckBox;
	}
	else if(uctype == 1){
		uiIndex	=	_HisDB_Index_AFCSFRAMiddleTactics;
		strItemName	=	"afcsframiddle";
		afcsfraTTacticscomboBox				=	ui.afcsfraMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraMTLinearBackcheckBox;
	}
	else if(uctype == 2){
		uiIndex	=	_HisDB_Index_AFCSFRAFarTactics;
		strItemName		=	"afcsfrafar";
		afcsfraTTacticscomboBox				=	ui.afcsfraFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afcsfraFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afcsfraFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afcsfraFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afcsfraFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afcsfraFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afcsfraFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afcsfraFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afcsfraFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afcsfraFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afcsfraFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afcsfraFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afcsfraFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afcsfraFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afcsfraFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afcsfraFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afcsfraFTLinearBackcheckBox;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "statics");

			/************statics**************/
			//(tactics:0)(usedb:true)(maxstep:10)(stepdelay:500)(valuechoose:0)(valuetype:0)
			//(motorstart:0)(motorend:1023)(motormin:0)(motormax:1023)(bigstep:20)(middlestep:10)(smallstep:5)
			//(curvedef:0.2)(falloffdef:0.1)(linearback:true)
			strname.clear();strvalue.clear();
			strname.append("tactics");strvalue.append(QString::number(afcsfraTTacticscomboBox->currentIndex()));
			strname.append("usedb");strvalue.append((afcsfraTUseDBcheckBox->isChecked())?("true"):("false"));
			strname.append("fitting");strvalue.append((afcsfraTCurveFittingcheckBox->isChecked())?("true"):("false"));
			strname.append("maxstep");strvalue.append(afcsfraTMaxStepsSpinBox->cleanText());
			strname.append("stepdelay");strvalue.append(afcsfraTStepDelaysSpinBox->cleanText());
			strname.append("valuechoose");strvalue.append(QString::number(afcsfraTValueChoosecomboBox->currentIndex()));
			strname.append("valuetype");strvalue.append(QString::number(afcsfraTValueTypecomboBox->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("motorstart");strvalue.append(afcsfraTMotorStartSpinBox->cleanText());
			strname.append("motorend");strvalue.append(afcsfraTMotorEndSpinBox->cleanText());
			strname.append("motormin");strvalue.append(afcsfraTMotorMinSpinBox->cleanText());
			strname.append("motormax");strvalue.append(afcsfraTMotorMaxSpinBox->cleanText());
			strname.append("bigstep");strvalue.append(afcsfraTBigStepSpinBox->cleanText());
			strname.append("middlestep");strvalue.append(afcsfraTMiddleStepSpinBox->cleanText());
			strname.append("smallstep");strvalue.append(afcsfraTSmallStepSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			//(curvedef:0.2)(falloffdef:0.1)(linearback:true)
			strname.clear();strvalue.clear();
			strname.append("curvedef");strvalue.append(afcsfraTCurveDefdoubleSpinBox->cleanText());
			strname.append("falloffdef");strvalue.append(afcsfraTFalloffDefdoubleSpinBox->cleanText());
			strname.append("linearback");strvalue.append((afcsfraTLinearBackcheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", strItemName,  "statics", itemsuffix2, key, value1);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::createlpAFCTable(QTableWidget* pstTable)
{
	for(unsigned int row=0; row < pstTable->rowCount();	++row){
		QCheckBox* pstTest	=	new QCheckBox();
		pstTable->setCellWidget(row, 0,  pstTest);
		QDoubleSpinBox* pstDistance	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 1,  pstDistance);
		pstDistance->setRange(0.01, 3.0);
		pstDistance->setDecimals(2);
		QSpinBox* pstAngle	=	new QSpinBox();
		pstTable->setCellWidget(row, 2,  pstAngle);
		pstAngle->setRange(0, 89);
		QDoubleSpinBox* pstWeight	=	new QDoubleSpinBox();
		pstTable->setCellWidget(row, 3,  pstWeight);
		pstWeight->setRange(0.0, 1.0);
		pstWeight->setDecimals(2);
		QSpinBox* pstSpecHori	=	new QSpinBox();
		pstTable->setCellWidget(row, 4,  pstSpecHori);
		pstSpecHori->setRange(1, 9999);
		pstSpecHori->setValue(600);
		QSpinBox* pstSpecVec	=	new QSpinBox();
		pstTable->setCellWidget(row, 5,  pstSpecVec);
		pstSpecVec->setRange(1, 9999);
		pstSpecVec->setValue(600);
		QSpinBox* pstSpecUniform	=	new QSpinBox();
		pstTable->setCellWidget(row, 6,  pstSpecUniform);
		pstSpecUniform->setRange(1, 9999);
		pstSpecUniform->setValue(200);
		QSpinBox* pstLpMin	=	new QSpinBox();
		pstTable->setCellWidget(row, 7,  pstLpMin);
		pstLpMin->setRange(1, 9999);
		pstLpMin->setValue(400);
		QSpinBox* pstLpMax	=	new QSpinBox();
		pstTable->setCellWidget(row, 8,  pstLpMax);
		pstLpMax->setRange(1, 9999);
		pstLpMax->setValue(1100);
		QSpinBox* pstLpNum	=	new QSpinBox();
		pstTable->setCellWidget(row, 9,  pstLpNum);
		pstLpNum->setRange(2, 18);
		pstLpNum->setValue(6);
		QSpinBox* pstThresold	=	new QSpinBox();
		pstTable->setCellWidget(row, 10,  pstThresold);
		pstThresold->setRange(10,150);
		pstThresold->setValue(45);
		QSpinBox* pstOffset	=	new QSpinBox();
		pstTable->setCellWidget(row, 11,  pstOffset);
		pstOffset->setRange(-9999, 9999);
		pstOffset->setValue(0);
	}
}

void configsetting::afcLpBasic2UI(unsigned char uctype)
{
	QDoubleSpinBox *afclpMarkFMindoubleSpinBox, *afclpMarkFMaxdoubleSpinBox;
	QSpinBox *afclpMarkPLMinspinBox, *afclpMarkPLMaxspinBox, *afclpMarkAnglespinBox, *afclpLPWPMinspinBox, *afclpLPWPMaxspinBox;
	QSpinBox *afclpLPHPMinspinBox, *afclpLPHPMaxspinBox, *afclpLPDisDevspinBox, *afclpLPHExpandspinBox, *afclpFramesspinBox;
	QString strItemName;
	QTableWidget* afcTableWidget;
	_lpAFCParameter* lpafcParameter;

	if(uctype == 0){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName	=	"afclpnear";
		afclpMarkFMindoubleSpinBox	=	ui.afclpnearMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpnearMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpnearMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpnearMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpnearMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpnearLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpnearLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpnearLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpnearLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpnearLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpnearLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpnearFramesspinBox;
		afcTableWidget					=	ui.lpAFCNeartableWidget;
		lpafcParameter					=	itemshareData.lpnearafcParameter;
		if(!lpafcParameter) return;
	}
	else if(uctype == 1){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName	=	"afclpmiddle";
		afclpMarkFMindoubleSpinBox	=	ui.afclpmiddleMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpmiddleMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpmiddleMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpmiddleMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpmiddleMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpmiddleLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpmiddleLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpmiddleLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpmiddleLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpmiddleLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpmiddleLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpmiddleFramesspinBox;
		afcTableWidget					=	ui.lpAFCMiddletableWidget;
		lpafcParameter					=	itemshareData.lpmiddleafcParameter;
		if(!lpafcParameter) return;
	}
	else if(uctype == 2){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName	=	"afclpfar";
		afclpMarkFMindoubleSpinBox	=	ui.afclpfarMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpfarMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpfarMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpfarMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpfarMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpfarLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpfarLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpfarLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpfarLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpfarLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpfarLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpfarFramesspinBox;
		afcTableWidget					=	ui.lpAFCFartableWidget;
		lpafcParameter					=	itemshareData.lpfarafcParameter;
		if(!lpafcParameter) return;
	}
	else{
		classItemProcess->getlpFAParameter(true, false);
		strItemName	=	"lpmfa";
		afclpMarkFMindoubleSpinBox	=	ui.lpmfaMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.lpmfaMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.lpmfaMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.lpmfaMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.lpmfaMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.lpmfaLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.lpmfaLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.lpmfaLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.lpmfaLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.lpmfaLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.lpmfaLPHExpandspinBox;
		afcTableWidget					=	ui.lpFAtableWidget;
		if(!itemshareData.lpmfaParameter) return;
	}

	for(unsigned int row=0; row < afcTableWidget->rowCount();	++row){
		((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(false);
	}

	if(uctype > 2)
	{
		afclpMarkFMindoubleSpinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.dflConstMarkFMin);
		afclpMarkFMaxdoubleSpinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.dflConstMarkFMax);
		afclpMarkPLMinspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstMarkPMin);
		afclpMarkPLMaxspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstMarkPMax);
		afclpLPWPMinspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstLPWMin);
		afclpLPWPMaxspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstLPWMax);
		afclpLPHPMinspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstLPHMin);
		afclpLPHPMaxspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstLPHMax);
		afclpMarkAnglespinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.dflConstMarkAngle);
		afclpLPDisDevspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usFOVDisDev);
		afclpLPHExpandspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.usConstExpandH);
		afclpFramesspinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.ucFrames);
		ui.lpmfaGradeMultipledoubleSpinBox->setValue(itemshareData.lpmfaParameter->stLpBasic.flGradeMultiple);

		for(int row=0; row < itemshareData.lpmfaParameter->vectorLpItem.size();	++row)
		{
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 1))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flFOV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flWeight);
			((QSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flAngle);
			((QSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flSpecHor);
			((QSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flSpecVec);
			((QSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flSpecUniform);
			((QSpinBox*)afcTableWidget->cellWidget(row, 7))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).usLPMin);
			((QSpinBox*)afcTableWidget->cellWidget(row, 8))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).usLPMax);
			((QSpinBox*)afcTableWidget->cellWidget(row, 9))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).ucConstLPNum);
			((QSpinBox*)afcTableWidget->cellWidget(row, 10))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).ucConstThresholdB8);
			((QSpinBox*)afcTableWidget->cellWidget(row, 11))->setValue(itemshareData.lpmfaParameter->vectorLpItem.at(row).flValueOffset);
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
	}
	else
	{
		afclpMarkFMindoubleSpinBox->setValue(lpafcParameter->stLpBasic.dflConstMarkFMin);
		afclpMarkFMaxdoubleSpinBox->setValue(lpafcParameter->stLpBasic.dflConstMarkFMax);
		afclpMarkPLMinspinBox->setValue(lpafcParameter->stLpBasic.usConstMarkPMin);
		afclpMarkPLMaxspinBox->setValue(lpafcParameter->stLpBasic.usConstMarkPMax);
		afclpLPWPMinspinBox->setValue(lpafcParameter->stLpBasic.usConstLPWMin);
		afclpLPWPMaxspinBox->setValue(lpafcParameter->stLpBasic.usConstLPWMax);
		afclpLPHPMinspinBox->setValue(lpafcParameter->stLpBasic.usConstLPHMin);
		afclpLPHPMaxspinBox->setValue(lpafcParameter->stLpBasic.usConstLPHMax);
		afclpMarkAnglespinBox->setValue(lpafcParameter->stLpBasic.dflConstMarkAngle);
		afclpLPDisDevspinBox->setValue(lpafcParameter->stLpBasic.usFOVDisDev);
		afclpLPHExpandspinBox->setValue(lpafcParameter->stLpBasic.usConstExpandH);
		afclpFramesspinBox->setValue(lpafcParameter->stLpBasic.ucFrames);

		for(int row=0; row < lpafcParameter->vectorLpItem.size();	++row)
		{
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 1))->setValue(lpafcParameter->vectorLpItem.at(row).flFOV);
			((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 3))->setValue(lpafcParameter->vectorLpItem.at(row).flWeight);
			((QSpinBox*)afcTableWidget->cellWidget(row, 2))->setValue(lpafcParameter->vectorLpItem.at(row).flAngle);
			((QSpinBox*)afcTableWidget->cellWidget(row, 4))->setValue(lpafcParameter->vectorLpItem.at(row).flSpecHor);
			((QSpinBox*)afcTableWidget->cellWidget(row, 5))->setValue(lpafcParameter->vectorLpItem.at(row).flSpecVec);
			((QSpinBox*)afcTableWidget->cellWidget(row, 6))->setValue(lpafcParameter->vectorLpItem.at(row).flSpecUniform);
			((QSpinBox*)afcTableWidget->cellWidget(row, 7))->setValue(lpafcParameter->vectorLpItem.at(row).usLPMin);
			((QSpinBox*)afcTableWidget->cellWidget(row, 8))->setValue(lpafcParameter->vectorLpItem.at(row).usLPMax);
			((QSpinBox*)afcTableWidget->cellWidget(row, 9))->setValue(lpafcParameter->vectorLpItem.at(row).ucConstLPNum);
			((QSpinBox*)afcTableWidget->cellWidget(row, 10))->setValue(lpafcParameter->vectorLpItem.at(row).ucConstThresholdB8);
			((QSpinBox*)afcTableWidget->cellWidget(row, 11))->setValue(lpafcParameter->vectorLpItem.at(row).flValueOffset);
			((QCheckBox*)afcTableWidget->cellWidget(row, 0))->setChecked(true);
		}
	}

}

int configsetting::saveAFCLpBasicData(unsigned char uctype)
{
	int iresult	=	0;

	QDoubleSpinBox *afclpMarkFMindoubleSpinBox, *afclpMarkFMaxdoubleSpinBox;
	QSpinBox *afclpMarkPLMinspinBox, *afclpMarkPLMaxspinBox, *afclpMarkAnglespinBox, *afclpLPWPMinspinBox, *afclpLPWPMaxspinBox;
	QSpinBox *afclpLPHPMinspinBox, *afclpLPHPMaxspinBox, *afclpLPDisDevspinBox, *afclpLPHExpandspinBox, *afclpFramesspinBox;
	QString strItemName;
	int uiIndex;
	QTableWidget* afcTableWidget;

	if(uctype == 0){
		strItemName	=	"afclpnear";
		uiIndex	=	_HisDB_Index_AFCLpNearBasic;
		afclpMarkFMindoubleSpinBox	=	ui.afclpnearMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpnearMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpnearMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpnearMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpnearMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpnearLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpnearLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpnearLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpnearLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpnearLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpnearLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpnearFramesspinBox;
		afcTableWidget					=	ui.lpAFCNeartableWidget;
	}
	else if(uctype == 1){
		strItemName	=	"afclpmiddle";
		uiIndex	=	_HisDB_Index_AFCLpMiddleBasic;
		afclpMarkFMindoubleSpinBox	=	ui.afclpmiddleMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpmiddleMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpmiddleMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpmiddleMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpmiddleMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpmiddleLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpmiddleLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpmiddleLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpmiddleLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpmiddleLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpmiddleLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpmiddleFramesspinBox;
		afcTableWidget					=	ui.lpAFCMiddletableWidget;
	}
	else if(uctype == 2){
		strItemName	=	"afclpfar";
		uiIndex	=	_HisDB_Index_AFCLpFarBasic;
		afclpMarkFMindoubleSpinBox	=	ui.afclpfarMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.afclpfarMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.afclpfarMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.afclpfarMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.afclpfarMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.afclpfarLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.afclpfarLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.afclpfarLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.afclpfarLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.afclpfarLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.afclpfarLPHExpandspinBox;
		afclpFramesspinBox			=	ui.afclpfarFramesspinBox;
		afcTableWidget					=	ui.lpAFCFartableWidget;
	}
	else{
		strItemName	=	"lpmfa";
		uiIndex	=	_HisDB_Index_AFCLpFarBasic;
		afclpMarkFMindoubleSpinBox	=	ui.lpmfaMarkFMindoubleSpinBox;
		afclpMarkFMaxdoubleSpinBox	=	ui.lpmfaMarkFMaxdoubleSpinBox;
		afclpMarkPLMinspinBox		=	ui.lpmfaMarkPLMinspinBox;
		afclpMarkPLMaxspinBox		=	ui.lpmfaMarkPLMaxspinBox;
		afclpMarkAnglespinBox		=	ui.lpmfaMarkAnglespinBox;
		afclpLPWPMinspinBox		=	ui.lpmfaLPWPMinspinBox;
		afclpLPWPMaxspinBox		=	ui.lpmfaLPWPMaxspinBox;
		afclpLPHPMinspinBox			=	ui.lpmfaLPHPMinspinBox;
		afclpLPHPMaxspinBox		=	ui.lpmfaLPHPMaxspinBox;
		afclpLPDisDevspinBox		=	ui.lpmfaLPDisDevspinBox;
		afclpLPHExpandspinBox	=	ui.lpmfaLPHExpandspinBox;
		afcTableWidget					=	ui.lpFAtableWidget;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "basic");
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "fovitem");

			if(uctype > 2)
			{
				/************basic**************/
				//(markfmin:0.3)(markfmax:0.7)(markplmin:50)(markplmax:100)(grademultiple:1.2)
				//(lpwmin:100)(lpwmax:300)(lphmin:12)(lphmax:50)
				//(markangle:45)(lpdisdev:50)(lphexpand:5)(frameaverage:1)
				strname.clear();	strvalue.clear();
				strname.append("markfmin");	strvalue.append(afclpMarkFMindoubleSpinBox->cleanText());
				strname.append("markfmax");strvalue.append(afclpMarkFMaxdoubleSpinBox->cleanText());
				strname.append("markplmin");strvalue.append(afclpMarkPLMinspinBox->cleanText());
				strname.append("markplmax");strvalue.append(afclpMarkPLMaxspinBox->cleanText());
				strname.append("grademultiple");strvalue.append(ui.lpmfaGradeMultipledoubleSpinBox->cleanText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("lpwmin");strvalue.append(afclpLPWPMinspinBox->cleanText());
				strname.append("lpwmax");strvalue.append(afclpLPWPMaxspinBox->cleanText());
				strname.append("lphmin");strvalue.append(afclpLPHPMinspinBox->cleanText());
				strname.append("lphmax");strvalue.append(afclpLPHPMaxspinBox->cleanText());
				ROPLOW::jointconfigstring(key, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("markangle");strvalue.append(afclpMarkAnglespinBox->cleanText());
				strname.append("lpdisdev");strvalue.append(afclpLPDisDevspinBox->cleanText());
				strname.append("lphexpand");strvalue.append(afclpLPHExpandspinBox->cleanText());
				ROPLOW::jointconfigstring(value1, strname, strvalue);
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "basic", itemsuffix2, key, value1);

				stSqlDB.transaction();
				for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
				{
					/************fovitem**************/
					//(fov:0.3)(angle:0)(weight:1.0)
					//(spech:900)(specv:900)(specu:200)
					//(lpmin:400)(lpmax:1100)
					//(lpnum:6)(threshold:20)(offset:0)
					if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked()){
						strname.clear();strvalue.clear();
						strname.append("fov");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 1))->cleanText());
						strname.append("angle");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 2))->cleanText());
						strname.append("weight");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 3))->cleanText());
						ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("spech");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 4))->cleanText());
						strname.append("specv");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 5))->cleanText());
						strname.append("specu");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 6))->cleanText());
						ROPLOW::jointconfigstring(key, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("lpmin");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 7))->cleanText());
						strname.append("lpmax");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 8))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("lpnum");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 9))->cleanText());
						strname.append("threshold");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 10))->cleanText());
						strname.append("offset");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 11))->cleanText());
						ROPLOW::jointconfigstring(reserve, strname, strvalue);
						HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "fovitem", itemsuffix2, key, value1, reserve);
					}
				}
				stSqlDB.commit();
			}
			else
			{
				/************basic**************/
				//(markfmin:0.3)(markfmax:0.7)(markplmin:50)(markplmax:100)(grademultiple:1.2)
				//(lpwmin:100)(lpwmax:300)(lphmin:12)(lphmax:50)
				//(markangle:45)(lpdisdev:50)(lphexpand:5)(frameaverage:1)
				strname.clear();	strvalue.clear();
				strname.append("markfmin");	strvalue.append(afclpMarkFMindoubleSpinBox->cleanText());
				strname.append("markfmax");strvalue.append(afclpMarkFMaxdoubleSpinBox->cleanText());
				strname.append("markplmin");strvalue.append(afclpMarkPLMinspinBox->cleanText());
				strname.append("markplmax");strvalue.append(afclpMarkPLMaxspinBox->cleanText());
				strname.append("frameaverage");strvalue.append(afclpFramesspinBox->cleanText());
				ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("lpwmin");strvalue.append(afclpLPWPMinspinBox->cleanText());
				strname.append("lpwmax");strvalue.append(afclpLPWPMaxspinBox->cleanText());
				strname.append("lphmin");strvalue.append(afclpLPHPMinspinBox->cleanText());
				strname.append("lphmax");strvalue.append(afclpLPHPMaxspinBox->cleanText());
				ROPLOW::jointconfigstring(key, strname, strvalue);

				strname.clear();strvalue.clear();
				strname.append("markangle");strvalue.append(afclpMarkAnglespinBox->cleanText());
				strname.append("lpdisdev");strvalue.append(afclpLPDisDevspinBox->cleanText());
				strname.append("lphexpand");strvalue.append(afclpLPHExpandspinBox->cleanText());
				ROPLOW::jointconfigstring(value1, strname, strvalue);
				HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "basic", itemsuffix2, key, value1);

				stSqlDB.transaction();
				for(unsigned int row=0; row <afcTableWidget->rowCount();	++row)
				{
					/************fovitem**************/
					//(fov:0.3)(angle:0)(weight:1.0)
					//(spech:900)(specv:900)(specu:200)
					//(lpmin:400)(lpmax:1100)
					//(lpnum:6)(threshold:20)(offset:0)
					if(((QCheckBox*)afcTableWidget->cellWidget(row, 0))->isChecked()){
						strname.clear();strvalue.clear();
						strname.append("fov");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 1))->cleanText());
						strname.append("angle");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 2))->cleanText());
						strname.append("weight");strvalue.append(((QDoubleSpinBox*)afcTableWidget->cellWidget(row, 3))->cleanText());
						ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("spech");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 4))->cleanText());
						strname.append("specv");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 5))->cleanText());
						strname.append("specu");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 6))->cleanText());
						ROPLOW::jointconfigstring(key, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("lpmin");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 7))->cleanText());
						strname.append("lpmax");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 8))->cleanText());
						ROPLOW::jointconfigstring(value1, strname, strvalue);

						strname.clear();strvalue.clear();
						strname.append("lpnum");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 9))->cleanText());
						strname.append("threshold");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 10))->cleanText());
						strname.append("offset");strvalue.append(((QSpinBox*)afcTableWidget->cellWidget(row, 11))->cleanText());
						ROPLOW::jointconfigstring(reserve, strname, strvalue);
						HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex++, "algorithm", strItemName,  "fovitem", itemsuffix2, key, value1, reserve);
					}
				}
				stSqlDB.commit();
			}
			
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "afburn",  QVariant(), itemsuffix2, key, value1, reserve);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::afcLpATactics2UI(unsigned char uctype)
{
	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox;
	QCheckBox *afcsfraTCurveFittingcheckBox, *afcsfraTUseDBcheckBox, *afcsfraTLinearBackcheckBox;
	_lpAFCParameter* lpafcParameter;

	if(uctype == 0){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName	=	"afclpnear";
		afcsfraTTacticscomboBox				=	ui.afclpaNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaNTLinearBackcheckBox;
		lpafcParameter								=	itemshareData.lpnearafcParameter;
		if(!lpafcParameter) return;
	}
	else if(uctype == 1){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName	=	"afclpmiddle";
		afcsfraTTacticscomboBox				=	ui.afclpaMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaMTLinearBackcheckBox;
		lpafcParameter								=	itemshareData.lpmiddleafcParameter;
		if(!lpafcParameter) return;
	}
	else if(uctype == 2){
		classItemProcess->getLpAFCParameter(uctype, true, false);
		strItemName		=	"afclpfar";
		afcsfraTTacticscomboBox				=	ui.afclpaFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaFTLinearBackcheckBox;
		lpafcParameter								=	itemshareData.lpfarafcParameter;
		if(!lpafcParameter) return;
	}
	else{
		strItemName	=	"afclpfa";
	}

	afcsfraTMaxStepsSpinBox->setValue(lpafcParameter->stTacticsBasic.usMaxSteps);
	afcsfraTStepDelaysSpinBox->setValue(lpafcParameter->stTacticsBasic.usStepDelay);
	afcsfraTMotorStartSpinBox->setValue(lpafcParameter->stTacticsBasic.sMotorStart);
	afcsfraTMotorEndSpinBox->setValue(lpafcParameter->stTacticsBasic.sMotorEnd);
	afcsfraTMotorMinSpinBox->setValue(lpafcParameter->stTacticsBasic.sMotorSpecMin);
	afcsfraTMotorMaxSpinBox->setValue(lpafcParameter->stTacticsBasic.sMotorSpecMax);
	afcsfraTBigStepSpinBox->setValue(lpafcParameter->stTacticsBasic.ucBigStep);
	afcsfraTMiddleStepSpinBox->setValue(lpafcParameter->stTacticsBasic.ucMiddleStep);
	afcsfraTSmallStepSpinBox->setValue(lpafcParameter->stTacticsBasic.ucSmallStep);
	afcsfraTCurveDefdoubleSpinBox->setValue(lpafcParameter->stTacticsBasic.flCurveValidDef);
	afcsfraTFalloffDefdoubleSpinBox->setValue(lpafcParameter->stTacticsBasic.flCurveFalloffDef);
	afcsfraTTacticscomboBox->setCurrentIndex(lpafcParameter->stTacticsBasic.ucTactics);
	afcsfraTValueChoosecomboBox->setCurrentIndex(lpafcParameter->stTacticsBasic.ucValueChoose);
	afcsfraTValueTypecomboBox->setCurrentIndex(lpafcParameter->stTacticsBasic.ucValueTypeChoose);
	afcsfraTUseDBcheckBox->setChecked(lpafcParameter->stTacticsBasic.bDataBase);
	afcsfraTCurveFittingcheckBox->setChecked(lpafcParameter->stTacticsBasic.bCurveFitting);
	afcsfraTLinearBackcheckBox->setChecked(lpafcParameter->stTacticsBasic.bLinearBack);
}

int configsetting::saveAFCLpATacticsData(unsigned char uctype)
{
	int iresult	=	0;

	QString strItemName;
	QComboBox *afcsfraTTacticscomboBox, *afcsfraTValueChoosecomboBox, *afcsfraTValueTypecomboBox;
	QSpinBox *afcsfraTMaxStepsSpinBox, *afcsfraTStepDelaysSpinBox, *afcsfraTMotorStartSpinBox, *afcsfraTMotorEndSpinBox;
	QSpinBox *afcsfraTMotorMinSpinBox, *afcsfraTMotorMaxSpinBox, *afcsfraTBigStepSpinBox, *afcsfraTMiddleStepSpinBox, *afcsfraTSmallStepSpinBox;
	QDoubleSpinBox *afcsfraTFalloffDefdoubleSpinBox, *afcsfraTCurveDefdoubleSpinBox;
	QCheckBox *afcsfraTCurveFittingcheckBox,  *afcsfraTUseDBcheckBox, *afcsfraTLinearBackcheckBox;
	int uiIndex;

	if(uctype == 0){
		uiIndex	=	_HisDB_Index_AFCLpNearTactics;
		strItemName	=	"afclpnear";
		afcsfraTTacticscomboBox				=	ui.afclpaNTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaNTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaNTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaNTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaNTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaNTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaNTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaNTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaNTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaNTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaNTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaNTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaNTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaNTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaNTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaNTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaNTLinearBackcheckBox;
	}
	else if(uctype == 1){
		uiIndex	=	_HisDB_Index_AFCLpMiddleTactics;
		strItemName	=	"afclpmiddle";
		afcsfraTTacticscomboBox				=	ui.afclpaMTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaMTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaMTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaMTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaMTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaMTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaMTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaMTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaMTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaMTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaMTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaMTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaMTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaMTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaMTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaMTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaMTLinearBackcheckBox;
	}
	else if(uctype == 2){
		uiIndex	=	_HisDB_Index_AFCLpFarTactics;
		strItemName		=	"afclpfar";
		afcsfraTTacticscomboBox				=	ui.afclpaFTTacticscomboBox;
		afcsfraTValueChoosecomboBox	=	ui.afclpaFTValueChoosecomboBox;
		afcsfraTValueTypecomboBox			=	ui.afclpaFTValueTypecomboBox;
		afcsfraTMaxStepsSpinBox				=	ui.afclpaFTMaxStepsSpinBox;
		afcsfraTStepDelaysSpinBox			=	ui.afclpaFTStepDelaysSpinBox;
		afcsfraTMotorStartSpinBox				=	ui.afclpaFTMotorStartSpinBox;
		afcsfraTMotorEndSpinBox				=	ui.afclpaFTMotorEndSpinBox;
		afcsfraTMotorMinSpinBox				=	ui.afclpaFTMotorMinSpinBox;
		afcsfraTMotorMaxSpinBox				=	ui.afclpaFTMotorMaxSpinBox;
		afcsfraTBigStepSpinBox					=	ui.afclpaFTBigStepSpinBox;
		afcsfraTMiddleStepSpinBox			=	ui.afclpaFTMiddleStepSpinBox;
		afcsfraTSmallStepSpinBox				=	ui.afclpaFTSmallStepSpinBox;
		afcsfraTFalloffDefdoubleSpinBox	=	ui.afclpaFTFalloffDefdoubleSpinBox;
		afcsfraTCurveDefdoubleSpinBox	=	ui.afclpaFTCurveDefdoubleSpinBox;
		afcsfraTUseDBcheckBox				=	ui.afclpaFTUseDBcheckBox;
		afcsfraTCurveFittingcheckBox		=	ui.afclpaFTCurveFittingcheckBox;
		afcsfraTLinearBackcheckBox			=	ui.afclpaFTLinearBackcheckBox;
	}

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", strItemName, "statics");

			/************statics**************/
			//(tactics:0)(usedb:true)(maxstep:10)(stepdelay:500)(valuechoose:0)(valuetype:0)
			//(motorstart:0)(motorend:1023)(motormin:0)(motormax:1023)(bigstep:20)(middlestep:10)(smallstep:5)
			//(curvedef:0.2)(falloffdef:0.1)(linearback:true)
			strname.clear();strvalue.clear();
			strname.append("tactics");strvalue.append(QString::number(afcsfraTTacticscomboBox->currentIndex()));
			strname.append("usedb");strvalue.append((afcsfraTUseDBcheckBox->isChecked())?("true"):("false"));
			strname.append("fitting");strvalue.append((afcsfraTCurveFittingcheckBox->isChecked())?("true"):("false"));
			strname.append("maxstep");strvalue.append(afcsfraTMaxStepsSpinBox->cleanText());
			strname.append("stepdelay");strvalue.append(afcsfraTStepDelaysSpinBox->cleanText());
			strname.append("valuechoose");strvalue.append(QString::number(afcsfraTValueChoosecomboBox->currentIndex()));
			strname.append("valuetype");strvalue.append(QString::number(afcsfraTValueTypecomboBox->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("motorstart");strvalue.append(afcsfraTMotorStartSpinBox->cleanText());
			strname.append("motorend");strvalue.append(afcsfraTMotorEndSpinBox->cleanText());
			strname.append("motormin");strvalue.append(afcsfraTMotorMinSpinBox->cleanText());
			strname.append("motormax");strvalue.append(afcsfraTMotorMaxSpinBox->cleanText());
			strname.append("bigstep");strvalue.append(afcsfraTBigStepSpinBox->cleanText());
			strname.append("middlestep");strvalue.append(afcsfraTMiddleStepSpinBox->cleanText());
			strname.append("smallstep");strvalue.append(afcsfraTSmallStepSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("curvedef");strvalue.append(afcsfraTCurveDefdoubleSpinBox->cleanText());
			strname.append("falloffdef");strvalue.append(afcsfraTFalloffDefdoubleSpinBox->cleanText());
			strname.append("linearback");strvalue.append((afcsfraTLinearBackcheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(value1, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", strItemName,  "statics", itemsuffix2, key, value1);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::autoFA2UI()
{
	classItemProcess->getGereralAFAParameter(true, false);
	if(!itemshareData.afaBasicStacticsParameter) return;

	ui.afaTacticscomboBox->setCurrentIndex(itemshareData.afaBasicStacticsParameter->ucTactics);
	ui.afaDirectioncomboBox->setCurrentIndex(itemshareData.afaBasicStacticsParameter->ucDirection);
	if(itemshareData.afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A) ui.afaChartTypecomboBox->setCurrentIndex(ui.afaChartTypecomboBox->findText("MTF-A"));
	else if(itemshareData.afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B) ui.afaChartTypecomboBox->setCurrentIndex(ui.afaChartTypecomboBox->findText("MTF-B"));
	else if(itemshareData.afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A) ui.afaChartTypecomboBox->setCurrentIndex(ui.afaChartTypecomboBox->findText("SFR-A"));
	else if(itemshareData.afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_LP_A) ui.afaChartTypecomboBox->setCurrentIndex(ui.afaChartTypecomboBox->findText("TV Line-A"));
	
	ui.afaValueChoosecomboBox->setCurrentIndex(itemshareData.afaBasicStacticsParameter->ucValueChoose);
	ui.afaValueTypecomboBox->setCurrentIndex(itemshareData.afaBasicStacticsParameter->ucValueTypeChoose);
	ui.afa1stUnderSpinMethodcomboBox->setCurrentIndex(itemshareData.afaBasicStacticsParameter->uc1stCWMode);
	ui.afa1stUnderSpinAnglespinBox->setValue(itemshareData.afaBasicStacticsParameter->fl1stCWAngle);
	ui.afa1stUnderSpinLaserdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->fl1stCWLaser);
	ui.afaBestOffsetdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->fltoBestAngOffset);
	ui.afaSFRABlockMarkspinBox->setValue(itemshareData.afaBasicStacticsParameter->ucSFRAMarkBlockCount);

#ifdef USE_AFC_Fitting
	ui.afaMarkMinAreaSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkMinArea);
	ui.afaMarkMaxAreaSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkMaxArea);
	ui.afaMarkMinLengthSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkMinLength);
	ui.afaMarkMaxLengthSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkMaxLength);
	ui.afaMarkTargetDistSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkTargetDistance);
	ui.afaMarkStepDistSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dflMarkStepDistance);
#endif

	ui.afaDatabasecheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bDataBase);
	ui.afaDBOffsetdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flDBAngleOffset);
	ui.afaEveryUpcheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bUpCheckEveryStep);
	ui.afaEvertUpDisdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flEveryUpDis);
	ui.afaRetryTimespinBox->setValue(itemshareData.afaBasicStacticsParameter->ucLastRetryTime);
	ui.afaRetryAngledoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flLastRetryAngle);
	ui.afaLastUpcheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bUpCheck);
	ui.afaMTFMarkRangeXdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flMTFBMarkRangeX);
	ui.afaXYReversalcheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bXYReversal);
	ui.afaMTFMarkRangeYdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flMTFBMarkRangeY);
	ui.afaMTFMarkRangeYMaxdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flMTFBMarkRangeYMax);
	ui.afaLastUnderSpinAnglespinBox->setValue(itemshareData.afaBasicStacticsParameter->uiUnderSpinAngle);
	ui.afaUnderSpinMindoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flUnderSpinDValueMin);
	ui.afaUnderSpinMaxdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flUnderSpinDValueMax);
	ui.afaLasercheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bUseLaser);
	ui.afaVisioncheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bVision);
	ui.afaMarkcheckBox->setChecked(itemshareData.afaBasicStacticsParameter->bUseMark);
	ui.afaLensAnglespinBox->setValue(itemshareData.afaBasicStacticsParameter->dfllensIncludedAngle);
	ui.afaRingAnglespinBox->setValue(itemshareData.afaBasicStacticsParameter->dflringIncludedAngle);
	ui.afaLensPitchdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->dfllenspitch);
	ui.afaLeafNumspinBox->setValue(itemshareData.afaBasicStacticsParameter->uclensleafs);
	ui.afaRingNumspinBox->setValue(itemshareData.afaBasicStacticsParameter->ucclaw);
	ui.afaMaxStepspinBox->setValue(itemshareData.afaBasicStacticsParameter->ussteplimit);
	ui.afaStepDelayspinBox->setValue(itemshareData.afaBasicStacticsParameter->usoperatedelay);
	ui.afaCurveValiddoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstPeakDefValue);
	ui.afaCurveFalloffdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstPeakDefFall);
	ui.afaMaxAngleCCWspinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstMaxAngleCCW);
	ui.afaMaxAngleCWspinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstMaxAngleCW);
	ui.afaLaserMindoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstLaserMin);
	ui.afaLaserMaxdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstLaserMax);
	ui.afaMarkMindoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstMarkDisMin);
	ui.afaMarkMaxdoubleSpinBox->setValue(itemshareData.afaBasicStacticsParameter->flConstMarkDisMax);
	ui.timeoutspinBox->setValue(itemshareData.iSocketReceiveTimeOut);
	ui.afaNodeNumspinBox->setValue(itemshareData.afaBasicStacticsParameter->ucVNodeNum);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(0, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[0]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(0, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[0]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(1, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[1]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(1, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[1]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(2, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[2]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(2, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[2]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(3, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[3]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(3, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[3]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(4, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[4]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(4, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[4]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(5, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[5]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(5, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[5]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(6, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[6]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(6, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[6]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(7, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[7]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(7, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[7]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(8, 0))->setValue(itemshareData.afaBasicStacticsParameter->flVNode[8]);
	((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(8, 1))->setValue(itemshareData.afaBasicStacticsParameter->flVAngle[8]);
}

int configsetting::saveAutoFAData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "equipment", "afarolongo");

			unsigned int uiIndex	=	_HisDB_Index_AutoFA;

			//(tactics:0)(direction:0)(chart:10)(valuechoose:0)(valuetype:0)(undermethod:0)(underangle:30)(underlaser:0.5)(bestoffset:0.0)(sfrmarkblock:5)
			//(database:true)(dboffset:0.0)(evyup:true)(evyupdis:3.0)(retrytime:3)(retryangle:3.0)(lastup:true)(lastupdis:3.0)(lastunderangle:0)(underdevmin:0.3)(underdevmax:0.6)
			//(laser:true)(vision:true)(mark:true)(lensangle:60)(ringangle:50)(lenspitch:0.25)(lensnum:3)(ringnum:3)
			//(maxstep:20)(stepdelay:650)(curvevalid:0.3)(curvefall:0.05)(maxccw:120)(maxcw:120)(minlaser:0.0)(maxlaser:0.0)(minmark:0.0)(maxmark:0.0)
			//(nodenum:4)(n1value:0.1)(n1angle:0.1)(n2value:0.1)(n2angle:0.1)(n3value:0.1)(n3angle:0.1)(n4value:0.1)(n4angle:0.1)(n5value:0.1)(n5angle:0.1)(n6value:0.1)(n6angle:0.1)(n7value:0.1)(n7angle:0.1)(n8value:0.1)(n8angle:0.1)(n9value:0.1)(n9angle:0.1)
			strname.clear();strvalue.clear();
			strname.append("tactics");strvalue.append(QString::number(ui.afaTacticscomboBox->currentIndex()));
			strname.append("direction");strvalue.append(QString::number(ui.afaDirectioncomboBox->currentIndex()));
			strname.append("chart");
			if(ui.afaChartTypecomboBox->currentText() == "MTF-A") strvalue.append(QString::number(_HisCCMAlg_Rolongo_Chart_MTF_A));
			else if(ui.afaChartTypecomboBox->currentText() == "MTF-B") strvalue.append(QString::number(_HisCCMAlg_Rolongo_Chart_MTF_B));
			else if(ui.afaChartTypecomboBox->currentText() == "SFR-A") strvalue.append(QString::number(_HisCCMAlg_Rolongo_Chart_SFR_A));
			else strvalue.append(QString::number(_HisCCMAlg_Rolongo_Chart_LP_A));
			strname.append("valuechoose");strvalue.append(QString::number(ui.afaValueChoosecomboBox->currentIndex()));
			strname.append("valuetype");strvalue.append(QString::number(ui.afaValueTypecomboBox->currentIndex()));
			strname.append("undermethod");strvalue.append(QString::number(ui.afa1stUnderSpinMethodcomboBox->currentIndex()));
			strname.append("underangle");strvalue.append(ui.afa1stUnderSpinAnglespinBox->cleanText());
			strname.append("underlaser");strvalue.append(ui.afa1stUnderSpinLaserdoubleSpinBox->cleanText());
			strname.append("bestoffset");strvalue.append(ui.afaBestOffsetdoubleSpinBox->cleanText());
			strname.append("sfrmarkblock");strvalue.append(ui.afaSFRABlockMarkspinBox->cleanText());
#ifdef USE_AFC_Fitting
			strname.append("sfrmarkminarea");strvalue.append(ui.afaMarkMinAreaSpinBox->cleanText());
			strname.append("sfrmarkmaxarea");strvalue.append(ui.afaMarkMaxAreaSpinBox->cleanText());
			strname.append("sfrmarkminlength");strvalue.append(ui.afaMarkMinLengthSpinBox->cleanText());
			strname.append("sfrmarkmaxlength");strvalue.append(ui.afaMarkMaxLengthSpinBox->cleanText());
			strname.append("sfrmarktargetdist");strvalue.append(ui.afaMarkTargetDistSpinBox->cleanText());
			strname.append("sfrmarkstepdist");strvalue.append(ui.afaMarkStepDistSpinBox->cleanText());
#endif
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("database");strvalue.append((ui.afaDatabasecheckBox->isChecked())?("true"):("false"));
			strname.append("dboffset");strvalue.append(ui.afaDBOffsetdoubleSpinBox->cleanText());
			strname.append("evyup");strvalue.append((ui.afaEveryUpcheckBox->isChecked())?("true"):("false"));
			strname.append("evyupdis");strvalue.append(ui.afaEvertUpDisdoubleSpinBox->cleanText());
			strname.append("retrytime");strvalue.append(ui.afaRetryTimespinBox->cleanText());
			strname.append("retryangle");strvalue.append(ui.afaRetryAngledoubleSpinBox->cleanText());
			strname.append("lastup");strvalue.append((ui.afaLastUpcheckBox->isChecked())?("true"):("false"));
			strname.append("lastunderangle");strvalue.append(ui.afaLastUnderSpinAnglespinBox->cleanText());
			strname.append("underdevmin");strvalue.append(ui.afaUnderSpinMindoubleSpinBox->cleanText());
			strname.append("underdevmax");strvalue.append(ui.afaUnderSpinMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("laser");strvalue.append((ui.afaLasercheckBox->isChecked())?("true"):("false"));
			strname.append("vision");strvalue.append((ui.afaVisioncheckBox->isChecked())?("true"):("false"));
			strname.append("mark");strvalue.append((ui.afaMarkcheckBox->isChecked())?("true"):("false"));
			strname.append("lensangle");strvalue.append(ui.afaLensAnglespinBox->cleanText());
			strname.append("ringangle");strvalue.append(ui.afaRingAnglespinBox->cleanText());
			strname.append("lenspitch");strvalue.append(ui.afaLensPitchdoubleSpinBox->cleanText());
			strname.append("lensnum");strvalue.append(ui.afaLeafNumspinBox->cleanText());
			strname.append("ringnum");strvalue.append(ui.afaRingNumspinBox->cleanText());
			strname.append("mtfbmarkx");strvalue.append(ui.afaMTFMarkRangeXdoubleSpinBox->cleanText());
			strname.append("xyreversal");strvalue.append((ui.afaXYReversalcheckBox->isChecked())?("true"):("false"));
			strname.append("mtfbmarky");strvalue.append(ui.afaMTFMarkRangeYdoubleSpinBox->cleanText());
			strname.append("mtfbmarkymax");strvalue.append(ui.afaMTFMarkRangeYMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(value1, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("maxstep");strvalue.append(ui.afaMaxStepspinBox->cleanText());
			strname.append("stepdelay");strvalue.append(ui.afaStepDelayspinBox->cleanText());
			strname.append("curvevalid");strvalue.append(ui.afaCurveValiddoubleSpinBox->cleanText());
			strname.append("curvefall");strvalue.append(ui.afaCurveFalloffdoubleSpinBox->cleanText());
			strname.append("maxccw");strvalue.append(ui.afaMaxAngleCCWspinBox->cleanText());
			strname.append("maxcw");strvalue.append(ui.afaMaxAngleCWspinBox->cleanText());
			strname.append("minlaser");strvalue.append(ui.afaLaserMindoubleSpinBox->cleanText());
			strname.append("maxlaser");strvalue.append(ui.afaLaserMaxdoubleSpinBox->cleanText());
			strname.append("minmark");strvalue.append(ui.afaMarkMindoubleSpinBox->cleanText());
			strname.append("maxmark");strvalue.append(ui.afaMarkMaxdoubleSpinBox->cleanText());
			strname.append("tcptimeoutlimit");strvalue.append(ui.timeoutspinBox->cleanText());
			ROPLOW::jointconfigstring(reserve, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("nodenum");strvalue.append(ui.afaNodeNumspinBox->cleanText());
			for(unsigned int x=1; x<10;	++x){
				strname.append("n" % QString::number(x) % "value");strvalue.append(((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(x-1, 0))->cleanText());
				strname.append("n" % QString::number(x) % "angle");strvalue.append(((QDoubleSpinBox*)ui.afaNodetableWidget->cellWidget(x-1, 1))->cleanText());
			}
			ROPLOW::jointconfigstring(note, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "equipment", "afarolongo",  QVariant(), itemsuffix2, key, value1, reserve, note);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::autoFA2UI_B()
{
	classItemProcess->getGereralAFAParameter_B(true, false);
	if(!itemshareData.bfaBasicStacticsParameter) return;

	ui.comboBox_AFChartType->setCurrentIndex(itemshareData.bfaBasicStacticsParameter->iChartType);
	ui.comboBox_Strategy->setCurrentIndex(itemshareData.bfaBasicStacticsParameter->iStrategy);
	ui.spinBox_FAMarkMinArea->setValue(itemshareData.bfaBasicStacticsParameter->dflMinArea);
	ui.spinBox_FAMarkMaxArea->setValue(itemshareData.bfaBasicStacticsParameter->dflMaxArea);
	ui.spinBox_FAMarkMinLength->setValue(itemshareData.bfaBasicStacticsParameter->dflMinLength);
	ui.spinBox_FAMarkMaxLength->setValue(itemshareData.bfaBasicStacticsParameter->dflMaxLength);
	ui.spinBox_FAMarkTargetDistance->setValue(itemshareData.bfaBasicStacticsParameter->dflTargetDistance);
	ui.spinBox_FARingOffset->setValue(itemshareData.bfaBasicStacticsParameter->dflFocusRingOffset);
	ui.spinBox_FALensRatio->setValue(itemshareData.bfaBasicStacticsParameter->dflLensRatioRing);
	ui.spinBox_FARingMoveZ->setValue(itemshareData.bfaBasicStacticsParameter->dflLensMoveDistanceZ);
	ui.spinBox_FAUnderspinAngle->setValue(itemshareData.bfaBasicStacticsParameter->dflUnderspinAngle);
	ui.spinBox_FAStepNode->setValue(itemshareData.bfaBasicStacticsParameter->dflStepNode);
}

int configsetting::saveAutoFAData_B()
{
	int iresult	=	0;
	
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "equipment", "bfarolongo");

			unsigned int uiIndex	=	_HisDB_Index_AutoFAB;

			strname.clear();strvalue.clear();
			strname.append("charttype");strvalue.append(QString::number(ui.comboBox_AFChartType->currentIndex()));
			strname.append("strategy");strvalue.append(QString::number(ui.comboBox_Strategy->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("minarea");strvalue.append(ui.spinBox_FAMarkMinArea->cleanText());
			strname.append("maxarea");strvalue.append(ui.spinBox_FAMarkMaxArea->cleanText());
			strname.append("minlength");strvalue.append(ui.spinBox_FAMarkMinLength->cleanText());
			strname.append("maxlength");strvalue.append(ui.spinBox_FAMarkMaxLength->cleanText());
			strname.append("targetdistance");strvalue.append(ui.spinBox_FAMarkTargetDistance->cleanText());
			strname.append("ringoffset");strvalue.append(ui.spinBox_FARingOffset->cleanText());
			strname.append("lensratioring");strvalue.append(ui.spinBox_FALensRatio->cleanText());
			strname.append("movedistance_z");strvalue.append(ui.spinBox_FARingMoveZ->cleanText());
			strname.append("underspinangle");strvalue.append(ui.spinBox_FAUnderspinAngle->cleanText());
			strname.append("stepnode");strvalue.append(ui.spinBox_FAStepNode->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "equipment", "bfarolongo",  QVariant(), itemsuffix2, key, value1, reserve, note);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}
	
	return iresult;
}

void configsetting::RelaceSlave()
{
	QString strNewSlave	=	ui.slaveReplacelineEdit->text();
	if(strNewSlave.size() != 2 || strNewSlave == "00"){
		ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("请先设置新的SLAVE地址(eg: 0F)"));
		return;
	}

	// 	QRegExp slaveRegExp("[0-9][A-F][a-f]");
	// 	QRegExpValidator slaveRegExpValidator(slaveRegExp);
	// 	int iInputPos	=	0;
	// 	if(slaveRegExpValidator.validate(strNewSlave, iInputPos) != QValidator::Acceptable){
	// 		ui.statuslabel->setText(QTextCodec::codecForName("GBK")->toUnicode("请先设置正确的SLAVE地址(eg: 0F)"));
	// 		return;
	// 	}

	strNewSlave	=	strNewSlave.toLower();
	strNewSlave	=	strNewSlave.prepend("0x");

	QString strtext		=	ui.previewi2cplainTextEdit->toPlainText() % "\n";
	QString strdata, strdata2;
	int iindex1, iindex2;
	unsigned int uiSlaveCount[8]	=	{0};
	unsigned char ucSlaveList[8]	=	{0};
	unsigned int uiSlaveListCount	=	0;
	if(strtext.size() > 9){
		QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
		if(lines.size() > 0){
			int isize	=	lines.size();
			for(int i=0;	i<isize;	++i){
				strdata	=	lines.at(i);
				strdata	=	strdata.toLower();
				if(strdata.count("0x") > 3 && strdata.count(",") > 2 && strdata.left(2) == "0x"){
					iindex1 = strdata.indexOf(",");
					strdata	=	strdata.left(iindex1);
					strdata	=	strdata.remove("0x");
					unsigned char ucSlave	=	strdata.toUInt(0, 16);
					if(ucSlave){
						bool bexist = false;
						for(unsigned int x=0;	x<uiSlaveListCount;	++x){
							if(ucSlaveList[x] == ucSlave){
								bexist	=	true;
								iindex2	=	x;
								break;
							}
						}

						if(bexist){
							++uiSlaveCount[iindex2];
						}
						else{
							if(uiSlaveListCount < 8){
								ucSlaveList[uiSlaveListCount]	=	ucSlave;
								uiSlaveCount[uiSlaveListCount]	=	1;
								++uiSlaveListCount;
							}
						}
					}
				}
			}
		}
	}

	if(uiSlaveListCount){
		unsigned char ucOldSlave;
		unsigned int uiMax	=	0;
		for(unsigned int x=0;	x<uiSlaveListCount;	++x){
			if(uiSlaveCount[x] > uiMax){
				uiMax			=	uiSlaveCount[x];
				ucOldSlave	=	ucSlaveList[x];
			}
		}

		QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
		int isize	=	lines.size();
		for(int i=0;	i<isize;	++i){
			strdata	=	lines.at(i);
			strdata	=	strdata.toLower();
			if(strdata.count("0x") > 3 && strdata.count(",") > 2 && strdata.left(2) == "0x"){
				iindex1		= strdata.indexOf(",");
				strdata2	=	strdata.left(iindex1);
				strdata2	=	strdata2.remove("0x");
				unsigned char ucSlave	=	strdata2.toUInt(0, 16);
				if(ucSlave == ucOldSlave){
					strdata	=	strdata.right(strdata.size() - iindex1);
					strdata	=	strdata.prepend(strNewSlave);
					lines.replace(i, strdata);
				}
			}
		}
		strtext	=	lines.join("\n");
		ui.previewi2cplainTextEdit->setPlainText(strtext);
	}
}

void configsetting::CHIPIDSwitch(const QString & strItem)
{
	QStringList strList;
	QString strKey	=	strItem.toLower();
	if(strKey == "other")	return;

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
		if (!templatedb.open()){
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("打开数据库HisFX3Rolongo失败"));
			return;
		}

		QSqlQuery query(templatedb);
		query.prepare("SELECT value FROM chipid WHERE classfy='chipid' AND item='" % strKey % "' ORDER BY id ASC" );
		query.exec();

		while (query.next()){
			QString strData	=	query.value(0).toString();
			strList.append(strData);
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("queryrolongo");

	ui.chipIDplainTextEdit->setPlainText(strList.join("\n"));
}

void configsetting::SetCHIPIDComoBox()
{
	QStringList strList;

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
		if (!templatedb.open()){
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("打开数据库HisFX3Rolongo失败"));
			return;
		}

		QSqlQuery query(templatedb);
		query.prepare("SELECT item FROM chipid WHERE classfy='chipid' ORDER BY id ASC" );
		query.exec();

		while (query.next()){
			QString strData	=	query.value(0).toString();
			strData	=	strData.toUpper();
			if(!strList.contains(strData))	strList.append(strData);
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("queryrolongo");

	strList.sort();
	ui.chipIDcomboBox->addItems(strList);
	ui.chipIDcomboBox->insertItem(0, "OTHER");
}

void configsetting::savewhitepanelinfo()
{
	int iresult = saveWhitePanel();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	whitepanel2UI();
}

void configsetting::saveCurrent()
{
	int iresult = saveWorkCurrentData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Work Current Parameter Fail"));
	workCurrent2UI();

	iresult = saveStandbyCurrentData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Standby Current Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	standbyCurrent2UI();
}

void configsetting::saveAFBurn()
{
	int iresult = saveAfBurnData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	afBurn2UI();
}

void configsetting::saveMTKPDAFBurn()
{
	int iresult = savePDAFBurnData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	pdafBurn2UI();
}

void configsetting::createAutoFANodeTable()
{
	for(unsigned int row=0; row < ui.afaNodetableWidget->rowCount();	++row){
		QDoubleSpinBox* pstScore	=	new QDoubleSpinBox();
		pstScore->setRange(0.01, 3000.0);
		pstScore->setDecimals(3);
		pstScore->setValue(3000.0);
		ui.afaNodetableWidget->setCellWidget(row, 0,  pstScore);
		QDoubleSpinBox* pstAngle	=	new QDoubleSpinBox();
		pstAngle->setRange(0.5, 720.0);
		pstAngle->setDecimals(2);
		pstAngle->setValue(2.0);
		ui.afaNodetableWidget->setCellWidget(row, 1,  pstAngle);		
	}
}

void configsetting::saveAutoFA()
{
	int iresult = saveAutoFAData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	autoFA2UI();
}

void configsetting::saveAutoFA_B()
{
	int iresult = saveAutoFAData_B();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	autoFA2UI_B();
}

void configsetting::saveSaveLog()
{
	int iresult = saveLogData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	logData2UI();
}

void configsetting::getdefaultotpBurn()
{
	_HisCCMOTP_Config stotpConfig;
	stotpConfig.strproject	=	(ui.projectlineEdit->text()).toAscii().data();
	stotpConfig.strsensor	=	(ui.sensorlineEdit->text()).toAscii().data();
	stotpConfig.strFunctionChoose	=	(ui.otpBurnGetFunListcomboBox->currentText()).toAscii().data();

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP32";
#endif

	RolongoOTPAPIVersion getRolongoOTPAPIVersion = (RolongoOTPAPIVersion)(QLibrary::resolve(strLibPath, "getRolongoOTPAPIVersion"));
	Rolongogetdefaultconfig getdefaultconfig = (Rolongogetdefaultconfig)(QLibrary::resolve(strLibPath, "getdefaultconfig"));

	if(!(getRolongoOTPAPIVersion && getdefaultconfig)){
		ui.statuslabel->setText(tr("Resolve HisCCMOTP DLL Function Fail"));
		return;
	}
	else
	{
		int iresult	=	getdefaultconfig(&stotpConfig);
		if(iresult){
			ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("专案名称不匹配"));
			return;
		}
	}

	QString strText;
	for(int x=0;	x<stotpConfig.vectorPair.size(); ++x){
		strText = strText % stotpConfig.vectorPair.at(x).strkey.c_str() % ":" % stotpConfig.vectorPair.at(x).strvalue.c_str() % "\n";
	}
	ui.otpBurnplainTextEdit->setPlainText(strText);

	ui.otpBurncheckBox->setChecked(stotpConfig.bburn);
	ui.otpLightCorrectcheckBox->setChecked(stotpConfig.bLightCorrect);
	ui.otpCheckOnlyDatacheckBox->setChecked(stotpConfig.bOnlyCheckBurnData);
	ui.otpBurnLuxMinspinBox->setValue(stotpConfig.uiLuxMin);
	ui.otpBurnLuxMaxspinBox->setValue(stotpConfig.uiLuxMax);
	ui.otpBurnOBspinBox->setValue(stotpConfig.uiDark);
	ui.otpBurnFrameSleepspinBox->setValue(stotpConfig.uiFrameSleep);
	ui.otpBurnCenterRangelineEdit->setText(QString::number(stotpConfig.flRangeRatio, 'f', 6));
	ui.otpBurnLSCShadingMinlineEdit->setText(QString::number(stotpConfig.flLSC_LuxShadingMin, 'f', 6));
	ui.otpBurnLSCShadingMaxlineEdit->setText(QString::number(stotpConfig.flLSC_LuxShadingMax, 'f', 6));
	ui.otpBurnLSCSymmMaxlineEdit->setText(QString::number(stotpConfig.flLSC_LuxSymmMax, 'f', 6));
	ui.otpBurnLSCCenterRGrMinlineEdit->setText(QString::number(stotpConfig.flLSC_CenterR2GrMin, 'f', 6));
	ui.otpBurnLSCCenterRGrMaxlineEdit->setText(QString::number(stotpConfig.flLSC_CenterR2GrMax, 'f', 6));
	ui.otpBurnLSCCenterBGrMinlineEdit->setText(QString::number(stotpConfig.flLSC_CenterB2GrMin, 'f', 6));
	ui.otpBurnLSCCenterBGrMaxlineEdit->setText(QString::number(stotpConfig.flLSC_CenterB2GrMax, 'f', 6));
	ui.otpBurnLSCB2Gr2CenterMaxlineEdit->setText(QString::number(stotpConfig.flLSC_WB2CenterMax_B2Gr, 'f', 6));
	ui.otpBurnLSCR2Gr2CenterMaxlineEdit->setText(QString::number(stotpConfig.flLSC_WB2CenterMax_R2Gr, 'f', 6));
	ui.otpBurnLightRlineEdit->setText(QString::number(stotpConfig.dflLightCoeR, 'f', 6));
	ui.otpBurnLightBlineEdit->setText(QString::number(stotpConfig.dflLightCoeB, 'f', 6));
	ui.otpBurnLSCCornerUniformlineEdit->setText(QString::number(stotpConfig.flLSC_LuxShadingUniform, 'f', 6));
	ui.otpBurnMIDlineEdit->setText(QString::number(stotpConfig.uiMID, 16));
	ui.otpBurnLENSIDlineEdit->setText(QString::number(stotpConfig.uiLENSID, 16));
	ui.otpBurnVCMIDlineEdit->setText(QString::number(stotpConfig.uiVCMID, 16));
	ui.otpBurnDRIVERIDlineEdit->setText(QString::number(stotpConfig.uiDRIVERICID, 16));
	if(stotpConfig.uiBlockSize == 5)
		ui.otpBurnBlockSizecomboBox->setCurrentIndex(0);
	else if(stotpConfig.uiBlockSize == 7)
		ui.otpBurnBlockSizecomboBox->setCurrentIndex(1);
	else if(stotpConfig.uiBlockSize == 9)
		ui.otpBurnBlockSizecomboBox->setCurrentIndex(2);
	else
		ui.otpBurnBlockSizecomboBox->setCurrentIndex(3);
}

void configsetting::saveotpBurn()
{
	int iresult = saveOtpBurnData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	otpBurn2UI();
}

void configsetting::saveBlackField()
{
	int iresult = saveBlackPanel();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	blackpanel2UI();
}

int configsetting::saveLightSourceCheckExec()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "lightsourcecheck");

			unsigned int uiIndex	=	_HisDB_Index_LightSourceCheck;

			//(roiw:0.2)(roih:0.2)
			//(rgmin:0.3)(rgmax:0.6)(bgmin:0.3)(bgmax:0.6)(gmin:180.0)(gmax:190.0)
			strname.clear();strvalue.clear();
			strname.append("roiw");strvalue.append(ui.lightschaROIWdoubleSpinBox->cleanText());
			strname.append("roih");strvalue.append(ui.lightschaROIHdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("rgmin");strvalue.append(ui.lightschaRGMindoubleSpinBox->cleanText());
			strname.append("rgmax");strvalue.append(ui.lightschaRGMaxdoubleSpinBox->cleanText());
			strname.append("bgmin");strvalue.append(ui.lightschaBGMindoubleSpinBox->cleanText());
			strname.append("bgmax");strvalue.append(ui.lightschaBGMaxdoubleSpinBox->cleanText());
			strname.append("gmin");strvalue.append(ui.lightschaGMindoubleSpinBox->cleanText());
			strname.append("gmax");strvalue.append(ui.lightschaGMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "lightsourcecheck", "alga", itemsuffix2, key);

			//(rawinfo:)
			//(rgmin:0.3)(rgmax:0.6)(bgmin:0.3)(bgmax:0.6)(ppmin:180.0)(ppmax:190.0)
			strname.clear();strvalue.clear();
			strname.append("rawinfo");	strvalue.append(ui.lightschbRawInfolineEdit->text());
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("rgmin");strvalue.append(ui.lightschbRGMindoubleSpinBox->cleanText());
			strname.append("rgmax");strvalue.append(ui.lightschbRGMaxdoubleSpinBox->cleanText());
			strname.append("bgmin");strvalue.append(ui.lightschbBGMindoubleSpinBox->cleanText());
			strname.append("bgmax");strvalue.append(ui.lightschbBGMaxdoubleSpinBox->cleanText());
			strname.append("ppmin");strvalue.append(ui.lightschbPPMindoubleSpinBox->cleanText());
			strname.append("ppmax");strvalue.append(ui.lightschbPPMaxdoubleSpinBox->cleanText());
			ROPLOW::jointconfigstring(key, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "lightsourcecheck", "algb", itemsuffix2, key);

			//(alg:0)
			strname.clear(); strvalue.clear();
			strname.append("alg"); strvalue.append(QString::number(ui.lightSourceCheckcomboBox->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "lightsourcecheck", "total", itemsuffix2);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::lightSourceCheck2UI()
{
	classItemProcess->getlsCheckParameter(true);

	if(itemshareData.lightsourcecheckParameter)
	{
		ui.lightschaROIWdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flROIW);
		ui.lightschaROIHdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flROIH);
		ui.lightschaRGMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flRGMin);
		ui.lightschaRGMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flRGMax);
		ui.lightschaBGMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flBGMin);
		ui.lightschaBGMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flBGMax);
		ui.lightschaGMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flGMin);
		ui.lightschaGMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgA.flGMax);

		ui.lightschbRawInfolineEdit->setText(itemshareData.lightsourcecheckParameter->stAlgB.strRawInfo);
		ui.lightschbRGMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flRGMin);
		ui.lightschbRGMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flRGMax);
		ui.lightschbBGMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flBGMin);
		ui.lightschbBGMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flBGMax);
		ui.lightschbPPMindoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flPPMin);
		ui.lightschbPPMaxdoubleSpinBox->setValue(itemshareData.lightsourcecheckParameter->stAlgB.flPPMax);

		ui.lightSourceCheckcomboBox->setCurrentIndex(itemshareData.lightsourcecheckParameter->ucAlg);
		LightSourceCheckSwitch(itemshareData.lightsourcecheckParameter->ucAlg);
	}
}

void configsetting::saveLightSourceCheck()
{
	int iresult = saveLightSourceCheckExec();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	lightSourceCheck2UI();
}

int configsetting::saveLightSpecificationData()
{
	int iresult	=	0;
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item,"algorithm", "lightspacification");
		unsigned int uiIndex	=	_HisDB_Index_LightSpecification;

		//(hardware:3%)(correct:0.25%)
		strname.clear();strvalue.clear();
		strname.append("hardware");strvalue.append(ui.LightHardwaredoubleSpinBox->cleanText());
		strname.append("correct");strvalue.append(ui.LightCorrectdoubleSpinBox_2->cleanText());
		ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

		HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "lightspacification", "spacification", itemsuffix2);

		stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;		
}

void configsetting::LightSpecification2UI()
{
	classItemProcess->getlsSpecificationParameter(true);
	if(itemshareData.lightSpecificationParameter){
		ui.LightHardwaredoubleSpinBox->setValue(itemshareData.lightSpecificationParameter->HardwareSpecification);
		ui.LightCorrectdoubleSpinBox_2->setValue(itemshareData.lightSpecificationParameter->CorrectSpecification);
	}
}

void configsetting::saveLightSpecification()
{
	int iresult = saveLightSpecificationData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	LightSpecification2UI();
}

void configsetting::freshDB_AE()
{
	ui.AE_DB01_checkBox->setChecked(false);
	ui.AE_DB02_checkBox->setChecked(false);
	ui.AE_DB03_checkBox->setChecked(false);
	ui.AE_DB04_checkBox->setChecked(false);
	ui.AE_DB05_checkBox->setChecked(false);
	ui.AE_DB06_checkBox->setChecked(false);
	ui.AE_DB07_checkBox->setChecked(false);
	ui.AE_DB08_checkBox->setChecked(false);
	ui.AE_DB09_checkBox->setChecked(false);
	ui.AE_DB10_checkBox->setChecked(false);
	ui.AE_DB11_checkBox->setChecked(false);
	ui.AE_DB12_checkBox->setChecked(false);
	ui.AE_DB13_checkBox->setChecked(false);
	ui.AE_DB14_checkBox->setChecked(false);
	ui.AE_DB15_checkBox->setChecked(false);
	ui.AE_DB16_checkBox->setChecked(false);
	ui.AE_DB17_checkBox->setChecked(false);
	ui.AE_DB18_checkBox->setChecked(false);
	ui.AE_DB19_checkBox->setChecked(false);
	ui.AE_DB20_checkBox->setChecked(false);
	ui.AE_DB21_checkBox->setChecked(false);
	ui.AE_DB22_checkBox->setChecked(false);
	ui.AE_DB23_checkBox->setChecked(false);
	ui.AE_DB24_checkBox->setChecked(false);
	ui.AE_DB25_checkBox->setChecked(false);
	ui.AE_DB26_checkBox->setChecked(false);
	ui.AE_DB27_checkBox->setChecked(false);
	ui.AE_DB28_checkBox->setChecked(false);
	ui.AE_DB29_checkBox->setChecked(false);
	ui.AE_DB30_checkBox->setChecked(false);
	ui.AE_DB31_checkBox->setChecked(false);
	ui.AE_DB32_checkBox->setChecked(false);
	ui.AE_DB33_checkBox->setChecked(false);
	ui.AE_DB34_checkBox->setChecked(false);
	ui.AE_DB35_checkBox->setChecked(false);
	ui.AE_DB36_checkBox->setChecked(false);
	ui.AE_DB37_checkBox->setChecked(false);
	ui.AE_DB38_checkBox->setChecked(false);
	ui.AE_DB39_checkBox->setChecked(false);
	ui.AE_DB40_checkBox->setChecked(false);
	ui.AE_DB41_checkBox->setChecked(false);
	ui.AE_DB42_checkBox->setChecked(false);
	ui.AE_DB43_checkBox->setChecked(false);
	ui.AE_DB44_checkBox->setChecked(false);
	ui.AE_DB45_checkBox->setChecked(false);

	ui.AE_DB01_label->clear();
	ui.AE_DB02_label->clear();
	ui.AE_DB03_label->clear();
	ui.AE_DB04_label->clear();
	ui.AE_DB05_label->clear();
	ui.AE_DB06_label->clear();
	ui.AE_DB07_label->clear();
	ui.AE_DB08_label->clear();
	ui.AE_DB09_label->clear();
	ui.AE_DB10_label->clear();
	ui.AE_DB11_label->clear();
	ui.AE_DB12_label->clear();
	ui.AE_DB13_label->clear();
	ui.AE_DB14_label->clear();
	ui.AE_DB15_label->clear();
	ui.AE_DB16_label->clear();
	ui.AE_DB17_label->clear();
	ui.AE_DB18_label->clear();
	ui.AE_DB19_label->clear();
	ui.AE_DB20_label->clear();
	ui.AE_DB21_label->clear();
	ui.AE_DB22_label->clear();
	ui.AE_DB23_label->clear();
	ui.AE_DB24_label->clear();
	ui.AE_DB25_label->clear();
	ui.AE_DB26_label->clear();
	ui.AE_DB27_label->clear();
	ui.AE_DB28_label->clear();
	ui.AE_DB29_label->clear();
	ui.AE_DB30_label->clear();
	ui.AE_DB31_label->clear();
	ui.AE_DB32_label->clear();
	ui.AE_DB33_label->clear();
	ui.AE_DB34_label->clear();
	ui.AE_DB35_label->clear();
	ui.AE_DB36_label->clear();
	ui.AE_DB37_label->clear();
	ui.AE_DB38_label->clear();
	ui.AE_DB39_label->clear();
	ui.AE_DB40_label->clear();
	ui.AE_DB41_label->clear();
	ui.AE_DB42_label->clear();
	ui.AE_DB43_label->clear();
	ui.AE_DB44_label->clear();
	ui.AE_DB45_label->clear();

	bool bparsesuccess	=	true;
	for(int w=0;	w<1;	++w){
		QSqlDatabase cdatadb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
		cdatadb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
		if (!cdatadb.open()){
			bparsesuccess	=	false;
			break;
		}

		QSqlQuery query(cdatadb);
		query.prepare("SELECT value1,value3 FROM datatablemanage WHERE tabletype='autoexposure'" );
		query.exec();
		while (query.next()){
			if(query.value(0).toString() == "autoexposure1")
					ui.AE_DB01_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure2")
				ui.AE_DB02_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure3")
				ui.AE_DB03_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure4")
				ui.AE_DB04_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure5")
				ui.AE_DB05_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure6")
				ui.AE_DB06_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure7")
				ui.AE_DB07_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure8")
				ui.AE_DB08_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure9")
				ui.AE_DB09_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure10")
				ui.AE_DB10_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure11")
				ui.AE_DB11_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure12")
				ui.AE_DB12_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure13")
				ui.AE_DB13_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure14")
				ui.AE_DB14_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure15")
				ui.AE_DB15_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure16")
				ui.AE_DB16_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure17")
				ui.AE_DB17_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure18")
				ui.AE_DB18_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure19")
				ui.AE_DB19_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure20")
				ui.AE_DB20_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure21")
				ui.AE_DB21_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure22")
				ui.AE_DB22_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure23")
				ui.AE_DB23_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure24")
				ui.AE_DB24_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure25")
				ui.AE_DB25_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure26")
				ui.AE_DB26_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure27")
				ui.AE_DB27_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure28")
				ui.AE_DB28_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure29")
				ui.AE_DB29_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure30")
				ui.AE_DB30_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure31")
				ui.AE_DB31_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure32")
				ui.AE_DB32_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure33")
				ui.AE_DB33_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure34")
				ui.AE_DB34_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure35")
				ui.AE_DB35_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure36")
				ui.AE_DB36_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure37")
				ui.AE_DB37_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure38")
				ui.AE_DB38_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure39")
				ui.AE_DB39_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure40")
				ui.AE_DB40_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure41")
				ui.AE_DB41_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure42")
				ui.AE_DB42_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure43")
				ui.AE_DB43_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure44")
				ui.AE_DB44_label->setText(query.value(1).toString());
			else if(query.value(0).toString() == "autoexposure45")
				ui.AE_DB45_label->setText(query.value(1).toString());
		}

		cdatadb.close();
	}

	QSqlDatabase::removeDatabase("querydata");
}

void configsetting::freshDB_FC()
{
	
}

void configsetting::clearDB_AE()
{
	bool bparsesuccess	=	true;
	for(int w=0;	w<1;	++w){
		QSqlDatabase cdatadb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
		cdatadb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
		if (!cdatadb.open()){
			bparsesuccess	=	false;
			break;
		}

		QSqlQuery query(cdatadb);
		QCheckBox* pstCheck;
		QString strIndex;

		for(unsigned int x=1;	x<46;	++x){
			switch (x){
			case 1:
				pstCheck	=	ui.AE_DB01_checkBox;
				break;
			case 2:
				pstCheck	=	ui.AE_DB02_checkBox;
				break;
			case 3:
				pstCheck	=	ui.AE_DB03_checkBox;
				break;
			case 4:
				pstCheck	=	ui.AE_DB04_checkBox;
				break;
			case 5:
				pstCheck	=	ui.AE_DB05_checkBox;
				break;
			case 6:
				pstCheck	=	ui.AE_DB06_checkBox;
				break;
			case 7:
				pstCheck	=	ui.AE_DB07_checkBox;
				break;
			case 8:
				pstCheck	=	ui.AE_DB08_checkBox;
				break;
			case 9:
				pstCheck	=	ui.AE_DB09_checkBox;
				break;
			case 10:
				pstCheck	=	ui.AE_DB10_checkBox;
				break;
			case 11:
				pstCheck	=	ui.AE_DB11_checkBox;
				break;
			case 12:
				pstCheck	=	ui.AE_DB12_checkBox;
				break;
			case 13:
				pstCheck	=	ui.AE_DB13_checkBox;
				break;
			case 14:
				pstCheck	=	ui.AE_DB14_checkBox;
				break;
			case 15:
				pstCheck	=	ui.AE_DB15_checkBox;
				break;
			case 16:
				pstCheck	=	ui.AE_DB16_checkBox;
				break;
			case 17:
				pstCheck	=	ui.AE_DB17_checkBox;
				break;
			case 18:
				pstCheck	=	ui.AE_DB18_checkBox;
				break;
			case 19:
				pstCheck	=	ui.AE_DB19_checkBox;
				break;
			case 20:
				pstCheck	=	ui.AE_DB20_checkBox;
				break;
			case 21:
				pstCheck	=	ui.AE_DB21_checkBox;
				break;
			case 22:
				pstCheck	=	ui.AE_DB22_checkBox;
				break;
			case 23:
				pstCheck	=	ui.AE_DB23_checkBox;
				break;
			case 24:
				pstCheck	=	ui.AE_DB24_checkBox;
				break;
			case 25:
				pstCheck	=	ui.AE_DB25_checkBox;
				break;
			case 26:
				pstCheck	=	ui.AE_DB26_checkBox;
				break;
			case 27:
				pstCheck	=	ui.AE_DB27_checkBox;
				break;
			case 28:
				pstCheck	=	ui.AE_DB28_checkBox;
				break;
			case 29:
				pstCheck	=	ui.AE_DB29_checkBox;
				break;
			case 30:
				pstCheck	=	ui.AE_DB30_checkBox;
				break;
			case 31:
				pstCheck	=	ui.AE_DB31_checkBox;
				break;
			case 32:
				pstCheck	=	ui.AE_DB32_checkBox;
				break;
			case 33:
				pstCheck	=	ui.AE_DB33_checkBox;
				break;
			case 34:
				pstCheck	=	ui.AE_DB34_checkBox;
				break;
			case 35:
				pstCheck	=	ui.AE_DB35_checkBox;
				break;
			case 36:
				pstCheck	=	ui.AE_DB36_checkBox;
				break;
			case 37:
				pstCheck	=	ui.AE_DB37_checkBox;
				break;
			case 38:
				pstCheck	=	ui.AE_DB38_checkBox;
				break;
			case 39:
				pstCheck	=	ui.AE_DB39_checkBox;
				break;
			case 40:
				pstCheck	=	ui.AE_DB40_checkBox;
				break;
			case 41:
				pstCheck	=	ui.AE_DB41_checkBox;
				break;
			case 42:
				pstCheck	=	ui.AE_DB42_checkBox;
				break;
			case 43:
				pstCheck	=	ui.AE_DB43_checkBox;
				break;
			case 44:
				pstCheck	=	ui.AE_DB44_checkBox;
				break;
			case 45:
				pstCheck	=	ui.AE_DB45_checkBox;
				break;
			default:
				break;
			}

			strIndex	=	"autoexposure" % QString::number(x);

			if(pstCheck->isChecked()){
				query.prepare("UPDATE datatablemanage SET value3=:value3,value5=:value5,value6=:value6 WHERE value1=:value1");
				query.bindValue(":value1", strIndex);
				query.bindValue(":value3", "");
				query.bindValue(":value5", "");
				query.bindValue(":value6", "");
				query.exec();

				query.prepare("DELETE FROM " % strIndex);
				query.exec();
			}
		}

		cdatadb.close();
	}

	QSqlDatabase::removeDatabase("querydata");

	freshDB_AE();

	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("清理数据库完成"));
}

void configsetting::clearDB_FC()
{
	bool bparsesuccess	=	true;
	for(int w=0;	w<1;	++w){
		QSqlDatabase cdatadb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
		cdatadb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
		if (!cdatadb.open()){
			bparsesuccess	=	false;
			break;
		}

		QSqlQuery query(cdatadb);

		if(ui.NearAFCDBcheckBox->isChecked()){
			query.prepare("DELETE FROM afcnearalldbc1");
			query.prepare("DELETE FROM afcnearalldbc2");
			query.exec();
		}

		if(ui.MiddleAFCDBcheckBox->isChecked()){
			query.prepare("DELETE FROM afcmiddlealldbc1");
			query.prepare("DELETE FROM afcmiddlealldbc2");
			query.exec();
		}

		if(ui.FarFCDBcheckBox->isChecked()){
			query.prepare("DELETE FROM afcfaralldbc1");
			query.prepare("DELETE FROM afcfaralldbc2");
			query.exec();
		}

		if(ui.autoFADBcheckBox->isChecked()){
			query.prepare("DELETE FROM autofadb");
			query.exec();
		}

		cdatadb.close();
	}

	QSqlDatabase::removeDatabase("querydata");

	freshDB_FC();

	ui.statuslabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("清理数据库完成"));
}

int configsetting::saveCurrentIndex()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item | _HISINLINEDB_FLAG_itemsuffix1, "algorithm", "tableindex", "total");

			unsigned int uiIndex	=	_HisDB_Index_CurrentIndex;
			strname.clear();	strvalue.clear();
			strname.append("mainindex");strvalue.append(QString::number(ui.tabWidgetmain->currentIndex()));
			strname.append("faindex");strvalue.append(QString::number(ui.focusAdjusttabWidget->currentIndex()));
			strname.append("afcindex");strvalue.append(QString::number(ui.tabWidgetAFC->currentIndex()));
			strname.append("afcmtfindex");strvalue.append(QString::number(ui.tabWidgetAFCMTF->currentIndex()));
			strname.append("afcsfrindex");strvalue.append(QString::number(ui.tabWidgetAFCSFRA->currentIndex()));
			strname.append("afctvlineindex");strvalue.append(QString::number(ui.tabWidgetAFCTVLINE->currentIndex()));
			strname.append("whiteblackindex");strvalue.append(QString::number(ui.tabWidgetWhite->currentIndex()));
			strname.append("blackindex");strvalue.append(QString::number(ui.tabWidgetBlack->currentIndex()));
			strname.append("currentos");strvalue.append(QString::number(ui.tabWidgetCurrentOS->currentIndex()));
			strname.append("burn");strvalue.append(QString::number(ui.tabWidgetBurn->currentIndex()));
			strname.append("lightsourceindex");strvalue.append(QString::number(ui.lightSourcetabWidget->currentIndex()));
			strname.append("archive");strvalue.append(QString::number(ui.tabWidgetArchive->currentIndex()));
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "tableindex",  "total", itemsuffix2);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::getCurrentIndex()
{
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString strData;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			query.prepare("SELECT itemsuffix2 FROM " % itemshareData.currentTableName % \
				" WHERE classfy='algorithm' AND item='tableindex' AND itemsuffix1='total'" );
			query.exec();

			while (query.next())
			{
				strData	=	query.value(0).toString();
				ROPLOW::patchconfigstring(strData, strname, strvalue);
				for(int x=0;	x<strname.size();	++x){
					if(strname.at(x) == "mainindex")	ui.tabWidgetmain->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "faindex")	ui.focusAdjusttabWidget->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "afcindex")	ui.tabWidgetAFC->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "afcmtfindex")	ui.tabWidgetAFCMTF->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "afcsfrindex")	ui.tabWidgetAFCSFRA->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "afctvlineindex")	ui.tabWidgetAFCTVLINE->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "whiteblackindex")	ui.tabWidgetWhite->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "blackindex")	ui.tabWidgetBlack->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "currentos")	ui.tabWidgetCurrentOS->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "burn")	ui.tabWidgetBurn->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "lightsourceindex")	ui.lightSourcetabWidget->setCurrentIndex(strvalue.at(x).toInt());
					else if(strname.at(x) == "archive")	ui.tabWidgetArchive->setCurrentIndex(strvalue.at(x).toInt());
				}

			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
}

void configsetting::nextSelected()
{
	textSelected();
	if (selectstr != ui.selectregisterlineEdit->text())
	{
		selectstr = ui.selectregisterlineEdit->text();
		inextflag=0;
	}
	int isize	=	selectresult.size();
	if (isize	==0)
	{
		return;
	}
	if (inextflag <isize)
	{
		setCursorPos(selectresult.at(inextflag),6);
		inextflag++;
	}
	else
	{
		setCursorPos(selectresult.at(inextflag%isize),6);
		inextflag++;
	}
}

void configsetting::textSelected()
{
	QString strtext	=	ui.previewi2cplainTextEdit->toPlainText()/* % "\n"*/;
	QStringList strTheList = strtext.split(",");
	QString selectstr	=	ui.selectregisterlineEdit->text();
	selectresult.clear();
	if (selectstr.isEmpty())
	{
		QMessageBox::warning(this, tr("warning"), tr("please input text"));
		return;
	}
	for(int x=0;	x<strTheList.size();	++x)
	{
		if(strTheList.at(x).contains(selectstr, Qt::CaseInsensitive))
		{
			
			selectresult.push_back(x/3);
		}
	}
	if (selectresult.size()<1)
	{
		QMessageBox::warning(this, tr("warning"), tr("can not find"));
	} 
	//else
	//{
	//	setCursorPos(selectresult.at(0),5);
	//}
	
	//ui.selectresultspinBox->setValue(selectresult.size());

	//selectresult.clear();
}

void configsetting::setCursorPos(int row,int col)
{
	const QTextBlock block = ui.previewi2cplainTextEdit->document()->findBlockByLineNumber(row);
	//if(block.isValid())
	//{
	//	QTextCursor cursor = ui.previewi2cplainTextEdit->textCursor();
	//	cursor.setPosition(block.position()+col);
	//	ui.previewi2cplainTextEdit->setTextCursor(cursor);
	//	cursor.setPosition(block.position()+col+6,QTextCursor::KeepAnchor);
	//	ui.previewi2cplainTextEdit->setTextCursor(cursor);
	//	ui.previewi2cplainTextEdit->ensureCursorVisible();
	//}

	QTextEdit::ExtraSelection selection;
	 QList<QTextEdit::ExtraSelection> extraSelections;
	QColor lineColor = QColor(Qt::yellow).lighter(120);

	selection.format.setBackground(lineColor);
	selection.format.setProperty(QTextFormat::FullWidthSelection, true);
	selection.cursor = ui.previewi2cplainTextEdit->textCursor();
	selection.cursor.setPosition(block.position()+col);
	ui.previewi2cplainTextEdit->setTextCursor(selection.cursor);
	//selection.cursor.clearSelection();
	extraSelections.append(selection);
	ui.previewi2cplainTextEdit->setExtraSelections(extraSelections);
}

void configsetting::slotospSelectall(int state)
{
	if(state == Qt::Checked)
	{
		for(unsigned int x=0;	x<vectorListosp.size();	++x)
		{

			vectorListosp.at(x)->setChecked(true);

		}
		if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
		{
		 	ui.ospnotselectcheckBox->setChecked(false);
		}
	}


}
void configsetting::slotospnotSelectall(int state)
{
	if(state == Qt::Checked)
	{
		for(unsigned int x=0;	x<vectorListosp.size();	++x)
		{
			vectorListosp.at(x)->setChecked(false);

		}
		if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
		{
		 	ui.ospselectallcheckBox->setChecked(false);
		}
	}


	
}
void configsetting::slotospallchange(int index)
{
	for(unsigned int x=0;	x<vectorListcmbosp.size();	++x)
	{
		vectorListcmbosp.at(x)->setCurrentIndex(index);

	}

}

void configsetting::slotosnSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListosn.size();	++x)
		{

			vectorListosn.at(x)->setChecked(true);

		}
		if (ui.osnnotselectcheckBox->isChecked() && ui.osnselectallcheckBox->isChecked())
		{
		 	ui.osnnotselectcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospnotselectcheckBox->setChecked(false);
	// 	}
}
void configsetting::slotosnnotSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListosn.size();	++x)
		{
			vectorListosn.at(x)->setChecked(false);

		}
		if (ui.osnnotselectcheckBox->isChecked() && ui.osnselectallcheckBox->isChecked())
		{
			ui.osnselectallcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospselectallcheckBox->setChecked(false);
	// 	}

}

void configsetting::slotoscSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListosc.size();	++x)
		{

			vectorListosc.at(x)->setChecked(true);

		}
		if (ui.oscnotselectcheckBox->isChecked() && ui.oscselectallcheckBox->isChecked())
		{
			ui.oscnotselectcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospnotselectcheckBox->setChecked(false);
	// 	}
}
void configsetting::slotoscnotSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListosc.size();	++x)
		{
			vectorListosc.at(x)->setChecked(false);

		}
		if (ui.oscnotselectcheckBox->isChecked() && ui.oscselectallcheckBox->isChecked())
		{
			ui.oscselectallcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospselectallcheckBox->setChecked(false);
	// 	}

}

void configsetting::slotortSelectall(int state)
{
	if(state == Qt::Checked)
	{
		
		for(unsigned int x=0;	x<vectorListort.size();	++x)
		{

			vectorListort.at(x)->setChecked(true);

		}
		if (ui.ortnotselectcheckBox->isChecked() && ui.ortselectallcheckBox->isChecked())
		{
			ui.ortnotselectcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospnotselectcheckBox->setChecked(false);
	// 	}
}
void configsetting::slotortnotSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListort.size();	++x)
		{
			vectorListort.at(x)->setChecked(false);

		}
		if (ui.ortnotselectcheckBox->isChecked() && ui.ortselectallcheckBox->isChecked())
		{
			ui.ortselectallcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospselectallcheckBox->setChecked(false);
	// 	}

}
void configsetting::slotoocSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListooc.size();	++x)
		{

			vectorListooc.at(x)->setChecked(true);

		}
		if (ui.ortnotselectcheckBox->isChecked() && ui.oocselectallcheckBox->isChecked())
		{
			ui.oocnotselectcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospnotselectcheckBox->setChecked(false);
	// 	}
}
void configsetting::slotoocnotSelectall(int state)
{
	if(state == Qt::Checked)
	{

		for(unsigned int x=0;	x<vectorListooc.size();	++x)
		{
			vectorListooc.at(x)->setChecked(false);

		}
		if (ui.oocnotselectcheckBox->isChecked() && ui.oocselectallcheckBox->isChecked())
		{
			ui.oocselectallcheckBox->setChecked(false);
		}
	}
	// 	if (ui.ospnotselectcheckBox->isChecked() && ui.ospselectallcheckBox->isChecked())
	// 	{
	// 		ui.ospselectallcheckBox->setChecked(false);
	// 	}

}

void configsetting::ducalcameraBurn2UI()
{
	classItemProcess->getdualcameraParameter(true, false);
	if(!itemshareData.dualCameraParameter) return;

	ui.ducalcameraBurncheckBox->setChecked(itemshareData.dualCameraParameter->bburn);
	ui.ducalcameraCheckOnlyDatacheckBox->setChecked(itemshareData.dualCameraParameter->bOnlyCheckData);
	ui.dualcameraBurnGetFunListcomboBox->setCurrentIndex(ui.dualcameraBurnGetFunListcomboBox->findText(itemshareData.dualCameraParameter->strDualCameraBurnChoose.toUpper()));
	ui.chart2lenspositiondoubleSpinBox->setValue(itemshareData.dualCameraParameter->dChart2lensDistance_Rotation);
	ui.focuslengthdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dFocusLength_Rotation);
	ui.cycledistancehorizontaldoubleSpinBox->setValue(itemshareData.dualCameraParameter->dCycleDistanceHorizontal_Rotation);
	ui.cycledistanceverticaldoubleSpinBox->setValue(itemshareData.dualCameraParameter->dCycleDistanceVertical_Rotation);
	ui.MaxTiltXspecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxTiltX);
	ui.MaxTiltYspecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxTiltY);
	ui.MaxRotationspecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxRotation);
	ui.MinTiltXSpecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMinTiltX);
	ui.MinTiltYSpecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMinTiltY);
	ui.MinRotationSpecdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMinRotation);
	ui.cameracenteroffestxdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dCameraCenterXShift);
	ui.cameracenteroffestydoubleSpinBox->setValue(itemshareData.dualCameraParameter->dCameraCenterYShift);

	ui.ducalcameracoaxialityBurncheckBox->setChecked(itemshareData.dualCameraParameter->bCoaxialityburn);
	ui.ducalcameracoaxialityCheckOnlyDatacheckBox->setChecked(itemshareData.dualCameraParameter->bCoaxialityOnlyCheckData);
	ui.dualcameraCoaxialityBurnGetFunListcomboBox->setCurrentIndex(ui.dualcameraCoaxialityBurnGetFunListcomboBox->findText(itemshareData.dualCameraParameter->strDualCameraCoaxialityBurnChoose.toUpper()));
	ui.dualcmcenterdistancedoubleSpinBox->setValue(itemshareData.dualCameraParameter->dDualCameraCenterDistance);
	ui.squareHorizontaldisdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dSquare_HorizontalDistance);
	ui.squareVerticaldisdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dSquare_VerticalDistance);
	ui.testdistancedoubleSpinBox->setValue(itemshareData.dualCameraParameter->dCoaxialityTestDistance);
	ui.MaxAngleXdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxAngleX);
	ui.MaxAngleYdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxAngleY);
	ui.MaxAngleZdoubleSpinBox->setValue(itemshareData.dualCameraParameter->dMaxAngleZ);
	ui.MaxXShiftspinBox->setValue(itemshareData.dualCameraParameter->iMaxShiftX);
	ui.MaxYShiftspinBox->setValue(itemshareData.dualCameraParameter->iMaxShiftY);
	ui.maincameracolorcheckBox->setChecked(itemshareData.dualCameraParameter->bMainCameraColorSensor);
	ui.subcameracolorcheckBox->setChecked(itemshareData.dualCameraParameter->bSubCameraColorSensor);
}


int configsetting::saveducalcameraBurnData()
{
	int iresult	=	0;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "ducalcameraburn");

			unsigned int uiIndex	=	_HisDB_Index_DucalCamera;

			strname.clear();	strvalue.clear();
			strname.append("burn");	strvalue.append((ui.ducalcameraBurncheckBox->isChecked())?("true"):("false"));
			strname.append("onlycheckdata");	strvalue.append((ui.ducalcameraCheckOnlyDatacheckBox->isChecked())?("true"):("false"));
			strname.append("burnrule");	strvalue.append(ui.dualcameraBurnGetFunListcomboBox->currentText().toLower());
			strname.append("chart2lensposition");	strvalue.append(QString::number(ui.chart2lenspositiondoubleSpinBox->value()));
			strname.append("Focuslength");	strvalue.append(QString::number(ui.focuslengthdoubleSpinBox->value()));
			strname.append("cycledishorizontal");	strvalue.append(QString::number(ui.cycledistancehorizontaldoubleSpinBox->value()));
			strname.append("cycledisvertical");	strvalue.append(QString::number(ui.cycledistanceverticaldoubleSpinBox->value()));
			strname.append("maxtiltXspec");	strvalue.append(QString::number(ui.MaxTiltXspecdoubleSpinBox->value()));
			strname.append("maxtiltYspec");	strvalue.append(QString::number(ui.MaxTiltYspecdoubleSpinBox->value()));
			strname.append("maxrotationspec");	strvalue.append(QString::number(ui.MaxRotationspecdoubleSpinBox->value()));
			strname.append("mintiltXspec");	strvalue.append(QString::number(ui.MinTiltXSpecdoubleSpinBox->value()));
			strname.append("mintiltYspec");	strvalue.append(QString::number(ui.MinTiltYSpecdoubleSpinBox->value()));
			strname.append("minrotationspec");	strvalue.append(QString::number(ui.MinRotationSpecdoubleSpinBox->value()));
			strname.append("cameracenterxoffest");	strvalue.append(QString::number(ui.cameracenteroffestxdoubleSpinBox->value()));
			strname.append("cameracenteryoffest");	strvalue.append(QString::number(ui.cameracenteroffestydoubleSpinBox->value()));		
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

			strname.clear();strvalue.clear();
			strname.append("coaxialityburn");	strvalue.append((ui.ducalcameracoaxialityBurncheckBox->isChecked())?("true"):("false"));
			strname.append("coaxialityonlycheckdata");	strvalue.append((ui.ducalcameracoaxialityCheckOnlyDatacheckBox->isChecked())?("true"):("false"));
			strname.append("coaxialityburnrule");	strvalue.append(ui.dualcameraCoaxialityBurnGetFunListcomboBox->currentText().toLower());
			strname.append("dualcameracenterdistance");strvalue.append(QString::number(ui.dualcmcenterdistancedoubleSpinBox->value()));
			strname.append("square_horizontaldistance");strvalue.append(QString::number(ui.squareHorizontaldisdoubleSpinBox->value()));
			strname.append("square_verticaldistance");strvalue.append(QString::number(ui.squareVerticaldisdoubleSpinBox->value()));
			strname.append("coaxialitytestdistance");strvalue.append(QString::number(ui.testdistancedoubleSpinBox->value()));
			strname.append("maxspecx");strvalue.append(QString::number(ui.MaxAngleXdoubleSpinBox->value()));
			strname.append("maxspecy");strvalue.append(QString::number(ui.MaxAngleYdoubleSpinBox->value()));
			strname.append("maxspecz");strvalue.append(QString::number(ui.MaxAngleZdoubleSpinBox->value()));
			strname.append("maxshiftx");strvalue.append(QString::number(ui.MaxXShiftspinBox->value()));
			strname.append("maxshifty");	strvalue.append(QString::number(ui.MaxYShiftspinBox->value()));
			strname.append("bmaincameracolorsensor");	strvalue.append((ui.maincameracolorcheckBox->isChecked())?("true"):("false"));
			strname.append("bsubcameracolorsensor");	strvalue.append((ui.subcameracolorcheckBox->isChecked())?("true"):("false"));
			ROPLOW::jointconfigstring(key, strname, strvalue);

			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "ducalcameraburn",  QVariant(), itemsuffix2, key, value1);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else{
		iresult	=	HisCCMError_Database;
	}

	return iresult;
}

void configsetting::saveducalcameraBurn()
{
	int iresult = saveducalcameraBurnData();
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	ducalcameraBurn2UI();
}

void 	configsetting::slotqualcommPDAFVersionChange(const QString &strVersion)
{
	if(strVersion=="L")
	{
		ui.qualcommgainmapformatcomboBox->setVisible(false);
		ui.gainmapformatlabel->setVisible(false);
		ui.qualcommSTEP2AEcheckBox->setVisible(false);
		ui.qualcommstep2delaytimelabel->setVisible(false);
		ui.qualcommpdaf50cmdealyspinBox->setVisible(false);
		ui.qualcomexproilabel->setVisible(false);
		ui.qualcomm50cmAEroiwspinBox->setVisible(false);
		ui.qualcomm50cmAEroihspinBox->setVisible(false);
		ui.pdtypelabel->setVisible(true);
		ui.pdtypecomboBox->setVisible(true);
		QString strSensorType=ui.pdtypecomboBox->currentText();
		if(strSensorType=="Sparse PD sensor")
		{
			ui.qualcomm2pdblacklevellabel->setVisible(false);
			ui.qualcomm2pdblacklevelspinBox->setVisible(false);
		}
		else if(strSensorType=="Dual-photodiode sensor")
		{
			ui.qualcomm2pdblacklevellabel->setVisible(true);
			ui.qualcomm2pdblacklevelspinBox->setVisible(true);
		}	
	}
	else
	{
		ui.qualcommgainmapformatcomboBox->setVisible(true);
		ui.gainmapformatlabel->setVisible(true);
		ui.qualcommSTEP2AEcheckBox->setVisible(true);
		ui.qualcommstep2delaytimelabel->setVisible(true);
		ui.qualcommpdaf50cmdealyspinBox->setVisible(true);
		ui.qualcomexproilabel->setVisible(true);
		ui.qualcomm50cmAEroiwspinBox->setVisible(true);
		ui.qualcomm50cmAEroihspinBox->setVisible(true);
		ui.pdtypelabel->setVisible(false);
		ui.pdtypecomboBox->setVisible(false);
		ui.qualcomm2pdblacklevellabel->setVisible(false);
		ui.qualcomm2pdblacklevelspinBox->setVisible(false);
	}
}

void configsetting::slotqualcommPDAFsensortypeChange(const QString &strtype)
{
	if(strtype=="Sparse PD sensor")
	{
		ui.qualcomm2pdblacklevellabel->setVisible(false);
		ui.qualcomm2pdblacklevelspinBox->setVisible(false);
	}
	else if(strtype=="Dual-photodiode sensor")
	{
		ui.qualcomm2pdblacklevellabel->setVisible(true);
		ui.qualcomm2pdblacklevelspinBox->setVisible(true);
	}	
}

void configsetting::slotPDAFplatformChange(int index) // 0 MTK 1: qualcomm 2 sony
{
	if(index==0)
	{
		ui.qualcommgroupBox->setVisible(false);
		ui.sonygroupBox->setVisible(false);
		ui.mtkgroupBox->setVisible(true);
		ui.step2verifygroupBox->setVisible(true);
		ui.hisigroupBox->setVisible(false);
	}
	else if(index==1)
	{
		ui.qualcommgroupBox->setVisible(true);
		ui.sonygroupBox->setVisible(false);
		ui.mtkgroupBox->setVisible(false);
		ui.step2verifygroupBox->setVisible(true);
		ui.hisigroupBox->setVisible(false);
	}
	else if(index==2)
	{
		ui.qualcommgroupBox->setVisible(false);
		ui.sonygroupBox->setVisible(true);
		ui.mtkgroupBox->setVisible(false);
		ui.step2verifygroupBox->setVisible(false);
		ui.hisigroupBox->setVisible(false);
	}
	else if(index==3)
	{
		ui.qualcommgroupBox->setVisible(false);
		ui.sonygroupBox->setVisible(false);
		ui.mtkgroupBox->setVisible(false);
		ui.step2verifygroupBox->setVisible(false);
		ui.hisigroupBox->setVisible(true);
	}
}


void configsetting::saveDPCLoadRule()
{
	int iresult=0;
	//QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;
			QSqlQuery query(stSqlDB);
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy | _HISINLINEDB_FLAG_item, "algorithm", "dpcloadrule");

			unsigned int uiIndex	=	_HisDB_Index_DPCRule;

			strname.clear();	strvalue.clear();
			strname.append("dpcrule");	strvalue.append(ui.dpcrulechoosecomboBox->currentText().toLower());
		
			ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, uiIndex, "algorithm", "dpcloadrule", QVariant(), itemsuffix2);

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
	else
	{
		iresult	=	HisCCMError_Database;
	}
	if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
	else ui.statuslabel->setText(tr("Save Parameter Success"));
	DPCRULE2UI();
}

void configsetting::DPCRULE2UI()
{
	classItemProcess->getDPCParameter(true, false);
	if(!itemshareData.dpcParameter) return;
	ui.dpcrulechoosecomboBox->setCurrentIndex(ui.dpcrulechoosecomboBox->findText(itemshareData.dpcParameter->strDPCRuleChoose.toUpper()));
}