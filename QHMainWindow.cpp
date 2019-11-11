#include "QHMainWindow.h"
#include  < MMSystem.h >
#pragma comment(lib, "winmm.lib")

void QHthreadShortcut::finish()
{
	emit finished();
}

void QHthreadShortcut::slotHotPlugInLoop()
{
	const int ciLoopIntenal	=	20;
#define _CODE_slotHotPlugInLoop_EXIT	{ if(hisglobalparameter.stOperatorMode.ucMode == 3) QTimer::singleShot(ciLoopIntenal, this, SLOT(slotHotPlugInLoop())); return; }

	if(threadshareDataC1.GetHisTestingflag() || threadshareDataC1.GetHisPreviewflag() || threadshareDataC2.GetHisTestingflag() || threadshareDataC2.GetHisPreviewflag())
		_CODE_slotHotPlugInLoop_EXIT

	if(!HISMANUALMODE::isModuleHotPlugIn())
		_CODE_slotHotPlugInLoop_EXIT

	if(!itemshareDataC1.shortcutgather.size())
	{
		HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
		HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
	}
	HISCCMSHORTCUT::eraseKeyItem(itemshareDataC1.shortcutgather, '~');

	
	_shoutCutDetail stDetail;
	stDetail.ucloopTime = 1;
	stDetail.usItemfail	=	0;
	stDetail.usItem		=	clearresultitem;
	stDetail.ucClickTime	=	1;
	stDetail.shortcutKey	=	'~';
	stDetail.ucItemIndex	=	1;
	itemshareDataC1.shortcutgather.push_back(stDetail);

	stDetail.usItem			=	startpreviewitem;
	stDetail.ucItemIndex	=	2;
	itemshareDataC1.shortcutgather.push_back(stDetail);

	stDetail.usItem			=	manualmodebloop1;
	stDetail.ucItemIndex	=	3;
	itemshareDataC1.shortcutgather.push_back(stDetail);

	emit signalExecKeyshortcutC1('~', 1);
}

void QHthreadShortcut::slotExecKeyshortcut(char key, unsigned char uctimer)
{
	if(classPlatform.getCameraCountSupported() != 2)
	{
		emit signalExecKeyshortcutC1(key, uctimer);
		return;
	}

#define _slotExecKeyshortcut_WAIT_TIMEOUT		40000

	threadshareDataC1.SetHisTestingflag(true);
	threadshareDataC2.SetHisTestingflag(true);

	QMutexLocker lockerC1(&itemshareDataC1.mutexItemExec);
	QMutexLocker lockerC2(&itemshareDataC2.mutexItemExec);

	int iNextItemIndexC1, iNextItemIndexC2, iresultc1, iresultc2;
	QElapsedTimer timeC1, timeC2;
	unsigned int uiIndexAdd	=	1;
	unsigned short usItemFail;
	bool bC1	=	true, bC2 = true, bRunC1 = false, bRunC2 = false;
	while(bC1 || bC2)
	{
		bC1	=	bC2 = false;
		if((iNextItemIndexC1 = HISCCMSHORTCUT::getNextTestItemTwoChannel(itemshareDataC1.shortcutgather, key, uctimer, uiIndexAdd)) >= 0){
			bRunC1	=	bC1	=	true;
			threadshareDataC1.setSlotItemExecStatus(true, HisCCMError_Result);
			emit signalNativeItemExecC1(itemshareDataC1.shortcutgather.at(iNextItemIndexC1));
			timeC1.start();
		}

		if((iNextItemIndexC2 = HISCCMSHORTCUT::getNextTestItemTwoChannel(itemshareDataC2.shortcutgather, key, uctimer, uiIndexAdd)) >= 0){
			bRunC2	=bC2	=	true;
			threadshareDataC2.setSlotItemExecStatus(true, HisCCMError_Result);
			emit signalNativeItemExecC2(itemshareDataC2.shortcutgather.at(iNextItemIndexC2));
			timeC2.start();
		}

		if(!(bC1 || bC2)) break;

		if(bC1)
		{
			while(threadshareDataC1.getSlotItemExecStatus(iresultc1) && !timeC1.hasExpired(_slotExecKeyshortcut_WAIT_TIMEOUT)){ Sleep(40); }
		}

		if(bC2)
		{
			while(threadshareDataC2.getSlotItemExecStatus(iresultc2) && !timeC2.hasExpired(_slotExecKeyshortcut_WAIT_TIMEOUT)){ Sleep(40); }
		}

		usItemFail	=	0;
		if(bC1 && iresultc1 && itemshareDataC1.shortcutgather.at(iNextItemIndexC1).usItemfail) usItemFail	=	itemshareDataC1.shortcutgather.at(iNextItemIndexC1).usItemfail;
		else if(bC2 && iresultc2 && itemshareDataC2.shortcutgather.at(iNextItemIndexC2).usItemfail) usItemFail	=	itemshareDataC2.shortcutgather.at(iNextItemIndexC2).usItemfail;

		if(usItemFail)
		{
			int iFailIndex	=	HISCCMSHORTCUT::getNextTestItemTwoChannelFail(itemshareDataC1.shortcutgather, itemshareDataC2.shortcutgather, key, uctimer, uiIndexAdd, usItemFail);
			if(iFailIndex < 0){ 
				_shoutCutDetail stItem;
				stItem.usItem	=	usItemFail;
				stItem.usItemfail	=	0;
				stItem.ucloopTime	=	1;
				stItem.shortcutKey	=	key;
				stItem.bDualCamera	=	true;
				stItem.ucClickTime		=	uctimer;
				stItem.ucItemIndex		=	0xFF;
				if(bRunC1)	emit signalNativeItemExecC1(stItem);
				if(bRunC2)	emit signalNativeItemExecC2(stItem);
				break;
			}
			else{
				uiIndexAdd	=	iFailIndex;
			}
		}
		else
		{
			uiIndexAdd++;
		}

	}

	threadshareDataC1.SetHisTestingflag(false);
	threadshareDataC2.SetHisTestingflag(false);
}

QHMainWindow::QHMainWindow(QWidget *parent)
	: QMainWindow(parent),loginDlg(this),windowc1(this,0,true, threadshareDataC1, itemshareDataC1, globalFunPointerC1,true),\
	windowc2(this,0,false, threadshareDataC2, itemshareDataC2, globalFunPointerC2),m_threadKey(new thread_Key(this))
{
	cu8TimeResolution = 0;
	ui.setupUi(this);

	//windowc1=HisFX3CCMTest(this,0,true, threadshareDataC1, itemshareDataC1, globalFunPointerC1);
	//windowc2=HisFX3CCMTest(this,0,false, threadshareDataC2, itemshareDataC2, globalFunPointerC2);

	QHBoxLayout * pstLayoutH = new QHBoxLayout(ui.centralWidget);
	pstLayoutH->setContentsMargins(0,0,0,0);
	pstLayoutH->setSpacing(3);

	pstLayoutH->addWidget(&windowc1);

	QFrame *line = new QFrame();
	line->setObjectName(QString::fromUtf8("line"));
	line->setGeometry(QRect(190, 90, 3, 61));
	line->setFrameShape(QFrame::VLine);
	line->setFrameShadow(QFrame::Sunken);
	pstLayoutH->addWidget(line);

	pstLayoutH->addWidget(&windowc2);

	//set windows icon
	QIcon icon;

	icon.addFile(QString::fromUtf8(":/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);

	this->setWindowIcon(icon);

	connect(ui.disableconfigaction, SIGNAL(triggered()), this, SLOT(DisableConfigSetting()));
	connect(ui.actionChange_Password, SIGNAL(triggered()), this, SLOT(changePassword()));
	connect(ui.csvManageaction, SIGNAL(triggered()), this, SLOT(ShowConfigManageDialog()));
	connect(ui.actionConfig_Content_Table, SIGNAL(triggered()), this, SLOT(slotConfigContentTable()));
	connect(ui.actionChoose_OperatorMode, SIGNAL(triggered()), this, SLOT(slotChooseOpMode()));
	connect(ui.showItem2EndResultaction, SIGNAL(triggered(bool)), this, SLOT(showItem2EndResultRegion(bool)));
	connect(ui.showEndResult2Imageaction, SIGNAL(triggered(bool)), this, SLOT(showEndResult2ImageRegion(bool)));
	connect(ui.actionSave_Lock_UI, SIGNAL(triggered()), this, SLOT(slotSave_LockUI()));
	connect(ui.actionReset_UI_Layout, SIGNAL(triggered()), this, SLOT(slotResetUILayout()));
	connect(ui.actionPanel_moveable, SIGNAL(triggered(bool)), this, SLOT(slotPanelMoveable(bool)));
	connect(ui.actionImage_Show, SIGNAL(triggered()), this, SLOT(slotImageShowDialog()));
	connect(ui.enableDebugModeaction, SIGNAL(triggered(bool)), this, SLOT(DebugModeSwitch(bool)));
	connect(ui.actionSave_Text_Info_To_Local, SIGNAL(triggered(bool)), this, SLOT(slotSaveTextInfoToLocal(bool)));
	connect(ui.actionCoordinate_Convertion, SIGNAL(triggered()), this, SLOT(CoorConvertTool()));
	connect(ui.actionRepeated_Test, SIGNAL(triggered()), this, SLOT(slotRepeatedTest()));
	connect(ui.actionComputer_Compatibility_Test, SIGNAL(triggered()), this, SLOT(slotCompterCompatibilityTest()));
	connect(ui.actionChoose_Grabber, SIGNAL(triggered()), this, SLOT(FX3DeviceConfig()));
	connect(ui.actionUpdate_FPGA_FW, SIGNAL(triggered()), this, SLOT(UpdateFPGAFW()));
	connect(ui.currentCalaction, SIGNAL(triggered()), this, SLOT(currentSelfCal()));
	connect(ui.actionVoltage_Calibration, SIGNAL(triggered()), this, SLOT(voltageSelfCal()));
	connect(ui.OSCalibrationaction, SIGNAL(triggered()), this, SLOT(OSSelfCal()));
	connect(ui.simpleChineseaction, SIGNAL(triggered(bool)), this, SLOT(chooseSimpleChinenes(bool)));
	connect(ui.englishaction, SIGNAL(triggered(bool)), this, SLOT(chooseEnglish(bool)));
	connect(ui.actionShortcut, SIGNAL(triggered()), this, SLOT(slotShortcutConfig()));
	connect(ui.actionVersion, SIGNAL(triggered()), this, SLOT(slotVersionShow()));
	connect(ui.actionHelp, SIGNAL(triggered()), this, SLOT(slotExecHelpFile()));
	connect(ui.actionFont, SIGNAL(triggered()), this, SLOT(slotFontSetting()));
	//************ 2018.04.19 ADD *************
	connect(ui.actionSOP, SIGNAL(triggered()), this, SLOT(slotShowSOP()));
	connect(ui.actionJsl_to_csv,SIGNAL(triggered()),this,SLOT(slotJsvDecode()));


	connect(this, SIGNAL(information(QString)), windowc1.classTextPanel, SLOT(ShowInformation(QString)));
	connect(this, SIGNAL(information(QString)), windowc2.classTextPanel, SLOT(ShowInformation(QString)));

	memset(b2ndClick, 0, sizeof(bool) *36);
	int iresult;
	
	bool bShowChannel1 = true, bShowChannel2 = true;
	getglobalParameter(bShowChannel1, bShowChannel2);

	if(hisglobalparameter.ucChoosePlatform == 1) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_UVC);
	else if(hisglobalparameter.ucChoosePlatform == 2) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_RTSPM);
	else if(hisglobalparameter.ucChoosePlatform == 3) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_HDMI);

	connect(&classTcpClient, SIGNAL(signalCloseExe()), this, SLOT(slotCloseExe()));
	connect(&classTcpClient, SIGNAL(signalPDAF50cmFinish()), this, SLOT(slotPDAF50cmFinish()));
	connect(&classTcpClient, SIGNAL(signalShortcutExe()), this, SLOT(slotSlaveShortcutExe()));

	connect(windowc1.itemprocessworker, SIGNAL(signalwriteItemResult(quint64, quint8)), &classTcpClient, SLOT(writeItemResult(quint64, quint8)));
	connect(windowc2.itemprocessworker, SIGNAL(signalwriteItemResult(quint64, quint8)), &classTcpClient, SLOT(writeItemResult(quint64, quint8)));
	connect(&classTcpClient, SIGNAL(signalItemExec(quint8, quint16, QString, quint64, quint8)), windowc1.itemprocessworker, SLOT(slotItemExec(quint8, quint16, QString, quint64, quint8)));
	connect(&classTcpClient, SIGNAL(signalItemExec(quint8, quint16, QString, quint64, quint8)), windowc2.itemprocessworker, SLOT(slotItemExec(quint8, quint16, QString, quint64, quint8)));
	connect(windowc1.itemprocessworker, SIGNAL(signalWritePDAF50cm(quint8)), &classTcpClient, SLOT(writePDAF50cm(quint8)));
	connect(windowc2.itemprocessworker, SIGNAL(signalWritePDAF50cm(quint8)), &classTcpClient, SLOT(writePDAF50cm(quint8)));
	connect(windowc1.itemprocessworker, SIGNAL(signalwriteItemResult(unsigned short, quint8, bool)), &classTcpClient, SLOT(writeItemResult(unsigned short, quint8, bool)));
	connect(windowc2.itemprocessworker, SIGNAL(signalwriteItemResult(unsigned short, quint8, bool)), &classTcpClient, SLOT(writeItemResult(unsigned short, quint8, bool)));
	connect(windowc1.itemprocessworker, SIGNAL(signalwriteMasterItemExec(unsigned short, unsigned char, quint8,  bool)), &classTcpClient, SLOT(writeMasterItemExec(unsigned short, unsigned char, quint8, bool)));
	connect(windowc2.itemprocessworker, SIGNAL(signalwriteMasterItemExec(unsigned short, unsigned char, quint8,  bool)), &classTcpClient, SLOT(writeMasterItemExec(unsigned short, unsigned char, quint8, bool)));
	connect(&classTcpClient, SIGNAL(signalMasterExeFinish(unsigned short, unsigned char, quint8)), this, SLOT(slotMasterExeFinish(unsigned short, unsigned char, quint8)));

	getOperateModeConfig();
	/*if(hisglobalparameter.stOperatorMode.ucMode != 2){
		jsl_loginDialog loginDlg;
		loginDlg.exec();
	}*/

	 
	if(hisglobalparameter.stOperatorMode.ucMode == 2) //slave mode
	{
		if(hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8){	
			classTcpClient.setSocketIndex(hisglobalparameter.ucGrabberIndex);
			quint32 u32Ip4	=	0x7F000001;
			if(hisglobalparameter.stOperatorMode.u8TcpIpType) u32Ip4 = hisglobalparameter.stOperatorMode.u32IpV4;
			iresult	=	classTcpClient.connectToHost(u32Ip4, hisglobalparameter.stOperatorMode.u16SocketPort);
			if(iresult){
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("连接主机失败：0x") % QString::number(iresult, 16));
				windowc1.drawTcpIpStatus(false);
				windowc2.drawTcpIpStatus(false);
			}
			else{
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("连接主机成功"));
				windowc1.drawTcpIpStatus(true);
				windowc2.drawTcpIpStatus(true);
			}
		}
		else{
			emit information(QTextCodec::codecForName( "GBK")->toUnicode("无法开启【从机模式】，因为没有绑定工装"));
		}
	}
	else if(hisglobalparameter.stOperatorMode.ucMode ==4) //Master mode
	{
		if(hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 4)
		{
			quint32 u32Ip4	=	0x7F000001;
			if(hisglobalparameter.stOperatorMode.u8TcpIpType) {u32Ip4 = hisglobalparameter.stOperatorMode.u32IpV4;}
			QString strIPAddress=QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 24) & 0xFF)+"."+QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 16) & 0xFF)+
				"."+QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 8) & 0xFF)+"."+QString::number(hisglobalparameter.stOperatorMode.u32IpV4 & 0xFF);
			QString strIPaddress_Port="IP:"+strIPAddress+"_Port:"+QString::number(hisglobalparameter.stOperatorMode.u16SocketPort);
			if(m_MyTCPServer.listen(strIPAddress,hisglobalparameter.stOperatorMode.u16SocketPort))
			{
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("启动TCP_Server失败：") %strIPaddress_Port);
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("确认IP地址是否与PC物理地址一致，端口是否被占用") );
			}
			else
			{
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("启动TCP_Server成功")%strIPaddress_Port);
				windowc1.drawTcpIpStatus(false);
				windowc2.drawTcpIpStatus(false);
			}
		}
		else
		{
			emit information(QTextCodec::codecForName( "GBK")->toUnicode("无法开启【TCP服务器模式】，因为没有绑定工装"));
		}
	}

	if(hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
	{
		iresult	=	classPlatform.HisFX3OpenDevice(0, 0, hisglobalparameter.strFreindlyName.toAscii().data(), 0xFF, hisglobalparameter.uiGrabberSerial, hisglobalparameter.ucFPGAUploadDelay);
	}
	else
	{
	   iresult	=	classPlatform.HisFX3OpenDevice(0, 0, 0, 0xFF, 0, hisglobalparameter.ucFPGAUploadDelay);
	}
	  classPlatform.setBulkTransformSize(64 *1024 *hisglobalparameter.ucFX3PacketSize); 
	if(iresult){
		windowc1.updateDevicestatus(false);
		windowc2.updateDevicestatus(false);
		if(hisglobalparameter.stOperatorMode.ucMode == 2 && hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
			classTcpClient.writeGrabberStatus(0x0);
		hisglobalparameter.setrunflag(false);
		emit information(tr("Open grabber failed."));
		emit information(GetHisFX3ErrorInfo(iresult));
	}
	else
	{
		emit information(tr("Open grabber succeeded."));
		windowc1.updateDevicestatus(true);
		windowc2.updateDevicestatus(true);
		if(hisglobalparameter.stOperatorMode.ucMode == 2 && hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
			classTcpClient.writeGrabberStatus(0x1);
		hisglobalparameter.setrunflag(true);
#if (defined _HisFX3_Platform_MIPI_R2R3) || (defined _HisFX3_Platform_MIPI_R4)
		unsigned int uiHardKey[4];
		if(!classPlatform.HisFX3GetHardwareKey(uiHardKey)){
			_HisFX3_Voltage_Calibration stCalData;
			if(!ROPLOW::voltageCalFromDB(uiHardKey, &stCalData, 1)){
				classPlatform.HisFX3SetVoltageCalData(&stCalData);
				emit information(tr("Set voltage calibration data succeeded."));
			}

#if(defined _HisFX3_Platform_MIPI_R4)
			if(!ROPLOW::voltageCalFromDB(uiHardKey, &stCalData, 2)){
				classPlatform.HisFX3SetVoltageCalData_S2(&stCalData);
				emit information(tr("Set voltage calibration data(channel 2) succeeded."));
			}
#endif

		}
#endif
	}

	if(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_UnKnowed)
	{
		QHChooseGrabberType classPlatformType(0);
		classPlatformType.exec();
		if(classPlatformType.platformType == _HisFX3_Platform_Type_UnKnowed) emit deleteLater();
		classPlatform.setCurrentPlatformType(classPlatformType.platformType);
	}

	if(classPlatform.getCameraCountSupported() == 2)
	{
		 windowc1.setVisible(bShowChannel1); 
		 ui.actionShow_Channel_1->setChecked(bShowChannel1);
		 windowc2.setVisible(bShowChannel2); 
		 ui.actionShow_Channel_2->setChecked(bShowChannel2);
	}
	else
	{
		windowc1.setVisible(true); 
		ui.actionShow_Channel_1->setChecked(true);
		windowc2.setVisible(false); 
		ui.actionShow_Channel_2->setChecked(false);
	}

	restoreUI();

	creatMenuAction();

	windowc1.opModeSwitch_UI(hisglobalparameter.stOperatorMode.ucMode);
	windowc2.opModeSwitch_UI(hisglobalparameter.stOperatorMode.ucMode);

	connect(this,  SIGNAL(signalExecKeyshortcutC1(char, unsigned char)), windowc1.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));
	connect(this,  SIGNAL(signalExecKeyshortcutC2(char, unsigned char)), windowc2.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));

	QThread* shortcutthread = new QThread;
	shortcutthread->setStackSize(10240);
	shortcutworker = new QHthreadShortcut();
	shortcutworker->moveToThread(shortcutthread);
	connect(shortcutworker, SIGNAL(finished()), shortcutthread, SLOT(quit()));
	connect(shortcutworker, SIGNAL(finished()), shortcutworker, SLOT(deleteLater()));
	connect(shortcutthread, SIGNAL(finished()), shortcutthread, SLOT(deleteLater()));
	connect(this, SIGNAL(finish()), shortcutworker, SLOT(finish()));
	connect(shortcutworker,  SIGNAL(signalNativeItemExecC1(const _shoutCutDetail&)), windowc1.itemprocessworker, SLOT(slotNativeItemExec(const _shoutCutDetail&)));
	connect(shortcutworker,  SIGNAL(signalExecKeyshortcutC1(char, unsigned char)), windowc1.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));
	connect(shortcutworker,  SIGNAL(signalNativeItemExecC2(const _shoutCutDetail&)), windowc2.itemprocessworker, SLOT(slotNativeItemExec(const _shoutCutDetail&)));
	connect(shortcutworker,  SIGNAL(signalExecKeyshortcutC2(char, unsigned char)), windowc2.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));
	connect(windowc1.itemprocessworker, SIGNAL(signalPlugInDetect()), shortcutworker, SLOT(slotHotPlugInLoop()));
	shortcutthread->start(QThread::NormalPriority);







#if (defined USE_EQUIPMENT_AFM_JSL_V1)
	if(iresult = _His_P8102_Init()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：打开运动控制卡失败, 请确认连接再重启程序"));
		emit information(GetHisFX3ErrorInfo(iresult));
		windowc1.updateCOMstatus(false);
	}
	else{
		windowc1.updateCOMstatus(true);
	}
#endif

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	//globalLeisaiMotion=new leisaiMotion("./leisai.ini",3,1,2,4,0);
	if(!globalLeisaiMotion.m_bBoardStatus){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：打开运动控制卡失败, 请确认连接再重启程序"));
		emit information(GetHisFX3ErrorInfo(iresult));
		windowc1.updateCOMstatus(false);
	}
	else{
		windowc1.updateCOMstatus(true);
	}
#endif

#if (defined USE_EQUIPMENT_JSL_RRT_V1)
	classMotion.SetWorkDirectory(QDir::currentPath() % "/MotionDLL/DMC3000");
	if(iresult = classMotion.OpenDevice(_QHMOTIONCARDTYPE_LEISAI_DMC3000)){
		emit information("open dmc3400 fail");
		emit information(classMotion.GetLastError());
		windowc1.updateCOMstatus(false);
		windowc2.updateCOMstatus(false);
	}
	else
	{
		if(iresult = classMotion.DownloadConfigFile(0, QDir::currentPath() % "/MotionDLL/DMC3000/DMC3400.ini")){
			emit information("download config file fail");
			emit information(classMotion.GetLastError());
			windowc1.updateCOMstatus(false);
			windowc2.updateCOMstatus(false);
		}
		else{
			classMotion.SetMoveCurve(0, 0, 200, 3000, 0.1, 0.1);
			classMotion.SetMoveCurve(0, 1, 200, 3000, 0.1, 0.1);
			classMotion.SetMoveCurve(0, 2, 200, 3000, 0.1, 0.1);
			classMotion.SetMoveCurve(0, 3, 200, 3000, 0.1, 0.1);
			windowc1.updateCOMstatus(true);
			windowc2.updateCOMstatus(true);
			classMotion.IOWriteOutBit(0, 0, 0,1);	Sleep(20);	
			classMotion.IOWriteOutBit(0,0, 1,1);	Sleep(20);
			classMotion.IOWriteOutBit(0,0, 3,1);	Sleep(20);
			classMotion.IOWriteOutBit(0,0, 4,1);	Sleep(20);
			classMotion.IOWriteOutBit(0,0, 5,1);	Sleep(20);
			classMotion.IOWriteOutBit(0,0, 6,1);	Sleep(20);
		}	
	}
#endif

#if (defined USE_EQUIPMENT_GB_AFBURN)
	classMotion.SetWorkDirectory(QDir::currentPath() % "/MotionDLL/IO0640");
	if(iresult = classMotion.OpenDevice(_QHMOTIONCARDTYPE_LEISAI_IO0640)){
		emit information("open IO0640 fail");
		emit information(classMotion.GetLastError());
		windowc1.updateCOMstatus(false);
		windowc2.updateCOMstatus(false);
	}
	else
	{
		windowc1.updateCOMstatus(true);
		windowc2.updateCOMstatus(true);
		classMotion.IOWriteOutBit(0, 0, 4,1);	Sleep(20);	
		classMotion.IOWriteOutBit(0,0, 5,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 7,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 8,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 6,1);	Sleep(20);
	}
#endif

#if (defined USE_EQUIPMENT_GB_PDAF)
	classMotion.SetWorkDirectory(QDir::currentPath() % "/MotionDLL/IO0640");
	if(iresult = classMotion.OpenDevice(_QHMOTIONCARDTYPE_LEISAI_IO0640)){
		emit information("open IO0640 fail");
		emit information(classMotion.GetLastError());
		windowc1.updateCOMstatus(false);
		windowc2.updateCOMstatus(false);
	}
	else
	{
		windowc1.updateCOMstatus(true);
		windowc2.updateCOMstatus(true);
		classMotion.IOWriteOutBit(0, 0, 7,1);	Sleep(20);	
		classMotion.IOWriteOutBit(0,0, 8,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 4,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 3,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 5,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 6,1);	Sleep(20);
		classMotion.IOWriteOutBit(0,0, 9,1);	Sleep(20);
	}
#endif



	if(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_UVC  && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_HDMI && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_RTSPM)
		QTimer::singleShot(300, this, SLOT(registerEvent()));

	if(hisglobalparameter.stOperatorMode.ucMode == 3)
		QTimer::singleShot(300, shortcutworker, SLOT(slotHotPlugInLoop()));

	TIMECAPS tc;
	if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) == TIMERR_NOERROR) 
	{
		if(classPlatform.getCameraCountSupported() == 2)
		{
			if(hisglobalparameter.stOperatorMode.ucMode != 2)
				cu8TimeResolution = min(max(tc.wPeriodMin, 6), tc.wPeriodMax);
		}
		else
		{
			if(hisglobalparameter.stOperatorMode.ucMode != 2)
				cu8TimeResolution = min(max(tc.wPeriodMin, 3), tc.wPeriodMax);
		}

		if(cu8TimeResolution) timeBeginPeriod(cu8TimeResolution); 
	}

}

QHMainWindow::~QHMainWindow()
{
	if(cu8TimeResolution) timeEndPeriod(cu8TimeResolution);

	if(hDeviceNote)
		UnregisterDeviceNotification(hDeviceNote);


#ifdef USE_EQUIPMENT_AFM_JSL_V1
	_His_P8102_Close();
#endif

	if(classPlatform.HisFX3CloseDevice()){
		OutputDebugStringA("close fx3 device fail");
	}

}

void QHMainWindow::closeEvent(QCloseEvent *event)
{
	threadshareDataC1.SetHisPreviewflag(false);
	threadshareDataC2.SetHisPreviewflag(false);
	hisglobalparameter.setrunflag(false);
	hisglobalparameter.setfaflag(false);
	QMutexLocker locker(&itemshareDataC1.mutexItemExec);
	QMutexLocker lockerC2(&itemshareDataC2.mutexItemExec);

	if(hisglobalparameter.stOperatorMode.ucMode == 3)
	{
		hisglobalparameter.stOperatorMode.ucMode	=	0xFF;
		Sleep(200);
	}






	classMotion.CloseDevice();

	bool bIs	=	true;
	DWORD uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC1.flaglock.lockForRead();
		if(!(threadshareDataC1.brawrun || threadshareDataC1.brenderrun || threadshareDataC1.brgbrun)){
			threadshareDataC1.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC1.flaglock.unlock();
		::Sleep(10);
	}

	windowc1.close();

	bIs	=	true;
	uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC2.flaglock.lockForRead();
		if(!(threadshareDataC2.brawrun || threadshareDataC2.brenderrun || threadshareDataC2.brgbrun)){
			threadshareDataC2.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC2.flaglock.unlock();
		::Sleep(10);
	}

	windowc2.close();

	if(classPlatform.HisFX3CloseDevice()){
		OutputDebugStringA("close fx3 device fail");
	}

	emit finish();

	QMainWindow::closeEvent(event);
}

void QHMainWindow::registerEvent()
{
	GUID CYUSBDRV_GUID = {0xae18aa60, 0x7f6a, 0x11d4, 0x97, 0xdd, 0x0, 0x1, 0x2, 0x29, 0xb9, 0x59};
	DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;
	ZeroMemory( &NotificationFilter, sizeof(NotificationFilter) );
	NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	NotificationFilter.dbcc_classguid = CYUSBDRV_GUID;
	hDeviceNote = RegisterDeviceNotification(this->winId(), &NotificationFilter,DEVICE_NOTIFY_WINDOW_HANDLE);
	if (!hDeviceNote){
		emit information(tr("RegisterDeviceNotification  fail"));
	}
}

bool QHMainWindow::winEvent (MSG * message, long * result)
{
	if (message->message==WM_DEVICECHANGE && (message->wParam == DBT_DEVICEARRIVAL || message->wParam == DBT_DEVICEREMOVECOMPLETE)){
		PDEV_BROADCAST_HDR pHdr = (PDEV_BROADCAST_HDR)(message->lParam);
		PDEV_BROADCAST_DEVICEINTERFACE hDeveceInterface;
		if (pHdr->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE){
			hDeveceInterface	=	(PDEV_BROADCAST_DEVICEINTERFACE)pHdr;
			wchar_t strKeyChar[50];
			swprintf_s(strKeyChar,	49, L"ae18aa60-7f6a-11d4-97dd-00010229b959");
			if (wcsstr(hDeveceInterface->dbcc_name, strKeyChar)){
				bool bopen = classPlatform.HisFX3isopen();
				if(bopen){
					if(!(classPlatform.HisFX3isstart() || classPlatform.HisFX3isstart_S2())){
						if(classPlatform.HisFX3SlaveResponds(0x99) == HisFX3Error_USBDataOut) bopen = false;
					}
				}

				if(message->wParam == DBT_DEVICEARRIVAL){
					if(!bopen)		QTimer::singleShot(0, this, SLOT(closefx3slot2()));
				}
				else{
					if(!bopen)		QTimer::singleShot(0, this, SLOT(closefx3slot()));
				}
				return true;
			}
		}
	}

	return false;
}

void QHMainWindow::keyPressEvent(QKeyEvent* event)
{
	int key	=	event->key();
	
	mutexKey.lock();
	if(key!=Qt::Key_NumLock)
		m_vecTemp.append(key);
	mutexKey.unlock();

	if(m_vecTemp.size()==1)
		m_threadKey->start();

	QMainWindow::keyPressEvent(event);
}

void QHMainWindow::keyPressEvent_Ex(Qt::Key key)
{
	if((key == Qt::Key_Return || key == Qt::Key_Enter || key == Qt::Key_Space) && hisglobalparameter.getfaflag()){
		hisglobalparameter.setfaflag(false);
		// 		return;
	}
	else if((key == Qt::Key_Return || key == Qt::Key_Enter) && !hisglobalparameter.getfaflag()){

		windowc1.ClickExecbutton();
// 		ClickExecbutton();
// 		classButtonExec->ui.seriallineEdit->setFocus();
	}
	else if (((key >= Qt::Key_0 && key<=Qt::Key_9) || (key>=Qt::Key_A && key<=Qt::Key_Z) || (key>96 && key<123))){
		if(key>64 && key<91)	key	=	(Qt::Key)(int(key)+32);
		if(hisglobalparameter.getfaflag()){
			hisglobalparameter.setfaflag(false);
			::Sleep(200);
		}

		if(classPlatform.getCameraCountSupported() == 2)
		{
			if(!itemshareDataC1.shortcutgather.size())
			{
				HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
				HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
			}
			if(!itemshareDataC2.shortcutgather.size())
			{
				HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC2.currentTableName, itemshareDataC2.shortcutgather, false);
				HISCCMSHORTCUT::setShortcutSync(itemshareDataC2.shortcutgather);
			}

			if(!HISCCMSHORTCUT::isKeyValidTwoChannel(key, 1, itemshareDataC1.shortcutgather, itemshareDataC2.shortcutgather) && \
				!HISCCMSHORTCUT::isKeyValidTwoChannel(key, 2, itemshareDataC1.shortcutgather, itemshareDataC2.shortcutgather))
			{
				return;
			}
			
			unsigned int uiIndex	=	(key < 58)?(key - 48):(key-87);
			unsigned char ucClicktimer	=	 b2ndClick[uiIndex] +1;
			if(!HISCCMSHORTCUT::isKeyValidTwoChannel(key, ucClicktimer, itemshareDataC1.shortcutgather, itemshareDataC2.shortcutgather))
			{
				ucClicktimer = (ucClicktimer == 2)?(1):(2);
			}

			if(itemshareDataC1.mutexItemExec.tryLock(30))
			{
				if(itemshareDataC2.mutexItemExec.tryLock(30)){
					itemshareDataC1.mutexItemExec.unlock();
					itemshareDataC2.mutexItemExec.unlock();
					emit signalExecKeyshortcutC1(key, ucClicktimer);
					emit signalExecKeyshortcutC2(key, ucClicktimer);
					b2ndClick[uiIndex]	=	!b2ndClick[uiIndex];
				}
				else{
					itemshareDataC1.mutexItemExec.unlock();
				}
			}
	
		}
		else
		{
			if(!itemshareDataC1.shortcutgather.size())
			{
				HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
				HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
			}

			unsigned int uiIndex	=	(key < 58)?(key - 48):(key-87);
			unsigned char ucClicktimer	=	 (b2ndClick[uiIndex])?(2):(1);
			if(!HISCCMSHORTCUT::isKeyValidOneChannel(key, ucClicktimer, itemshareDataC1.shortcutgather))
			{
				ucClicktimer	=	 (b2ndClick[uiIndex])?(1):(2);
				if(!HISCCMSHORTCUT::isKeyValidOneChannel(key, ucClicktimer, itemshareDataC1.shortcutgather)){
					return;
				}
			}

			if(itemshareDataC1.mutexItemExec.tryLock(30)){
				itemshareDataC1.mutexItemExec.unlock();
				b2ndClick[uiIndex]	=	!(b2ndClick[uiIndex]);
				emit signalExecKeyshortcutC1(key, ucClicktimer);	

			}
		}
	
	}
/*
	else if(key >= Qt::Key_Left && key <= Qt::Key_Down && stImageShowPolicy.ucMode == 1 && hisglobalparameter.ucSodokuMode == 1){
		switch (stImageShowPolicy.ucSodokuPos){
		case 7: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	4;
			break;
		case 8: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	7;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	9;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	5;
			break;
		case 9: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	6;
			break;
		case 4: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	5;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	7;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	1;
			break;
		case 5: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	4;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	6;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	2;
			break;
		case 6: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	5;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	9;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	3;
			break;
		case 1: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	2;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	4;
			break;
		case 2: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	1;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	3;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	5;
			break;
		default:
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	2;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	6;
			break;
		}
		threadshareData.flaglock.lockForWrite();
		threadshareData.stImageShowPolicy.ucSodokuPos = stImageShowPolicy.ucSodokuPos;
		threadshareData.flaglock.unlock();
	}
*/
}

void QHMainWindow::mouseDoubleClickEvent(QMouseEvent * event)
{
	QMainWindow::mouseDoubleClickEvent(event);
}

void QHMainWindow::creatMenuAction()
{









	if(classPlatform.getCameraCountSupported() == 2)
	{
		connect(ui.actionShow_Channel_1, SIGNAL(toggled(bool)), this, SLOT(slotShowChannel1(bool)));
		connect(ui.actionShow_Channel_2, SIGNAL(toggled(bool)), this, SLOT(slotShowChannel2(bool)));
	}
	else
	{
		ui.actionShow_Channel_1->setVisible(false);
		ui.actionShow_Channel_2->setVisible(false);
	}



}

void QHMainWindow::openfx3slot()
{
	if(hisglobalparameter.ucChoosePlatform == 1) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_UVC);
	else if(hisglobalparameter.ucChoosePlatform == 2) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_RTSPM);
	else if(hisglobalparameter.ucChoosePlatform == 3) classPlatform.setCurrentPlatformType(_HisFX3_Platform_Type_HDMI);

	int iresult;
	if(hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 4)
		iresult	=	classPlatform.HisFX3OpenDevice(0, 0, hisglobalparameter.strFreindlyName.toAscii().data(), 0xFF, hisglobalparameter.uiGrabberSerial, hisglobalparameter.ucFPGAUploadDelay);
	else
		iresult	=	classPlatform.HisFX3OpenDevice(0, 0, 0, 0xFF, 0, hisglobalparameter.ucFPGAUploadDelay);
	classPlatform.setBulkTransformSize(64 *1024 *hisglobalparameter.ucFX3PacketSize);
	//item.u32usbstatus	=	iresult;
	if(iresult){
		windowc1.updateDevicestatus(false);
		windowc2.updateDevicestatus(false);
		if(hisglobalparameter.stOperatorMode.ucMode == 2 && hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
			classTcpClient.writeGrabberStatus(0x0);
		hisglobalparameter.setrunflag(false);
		emit information(tr("Open USB3.0 grabber failed."));
		emit information(GetHisFX3ErrorInfo(iresult));
	}
	else{
		emit information(tr("Open USB3.0 grabber succeeded."));
		windowc1.updateDevicestatus(true);
		windowc2.updateDevicestatus(true);
		if(hisglobalparameter.stOperatorMode.ucMode == 2 && hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
			classTcpClient.writeGrabberStatus(0x1);
		hisglobalparameter.setrunflag(true);
#if (defined _HisFX3_Platform_MIPI_R2R3) || (defined _HisFX3_Platform_MIPI_R4)
		unsigned int uiHardKey[4];
		if(!classPlatform.HisFX3GetHardwareKey(uiHardKey)){
			_HisFX3_Voltage_Calibration stCalData;
			if(!ROPLOW::voltageCalFromDB(uiHardKey, &stCalData, 1)){
				classPlatform.HisFX3SetVoltageCalData(&stCalData);
				emit information(tr("Set voltage calibration data succeeded."));
			}

#if (defined _HisFX3_Platform_MIPI_R4)
			if(!ROPLOW::voltageCalFromDB(uiHardKey, &stCalData, 2)){
				classPlatform.HisFX3SetVoltageCalData_S2(&stCalData);
				emit information(tr("Set voltage calibration data(channel 2) succeeded."));
			}
#endif

		}
#endif
	}
}

void QHMainWindow::closefx3slot()
{
	emit information(QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备 被移除"));
	threadshareDataC1.SetHisPreviewflag(false);
	threadshareDataC2.SetHisPreviewflag(false);

	hisglobalparameter.setrunflag(false);
	hisglobalparameter.setfaflag(false);
	QMutexLocker locker(&itemshareDataC1.mutexItemExec);
	QMutexLocker lockerc2(&itemshareDataC2.mutexItemExec);


	classPlatform.HisFX3CloseDevice();

	bool bIs	=	true;
	DWORD uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC1.flaglock.lockForRead();
		if(!(threadshareDataC1.brawrun || threadshareDataC1.brenderrun || threadshareDataC1.brgbrun)){
			threadshareDataC1.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC1.flaglock.unlock();
		::Sleep(10);
	}

	bIs	=	true;
	uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC2.flaglock.lockForRead();
		if(!(threadshareDataC2.brawrun || threadshareDataC2.brenderrun || threadshareDataC2.brgbrun)){
			threadshareDataC2.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC2.flaglock.unlock();
		::Sleep(10);
	}

	windowc1.updateDevicestatus(false);
	itemshareDataC1.clear();
	windowc2.updateDevicestatus(false);
	itemshareDataC2.clear();
	if(hisglobalparameter.stOperatorMode.ucMode == 2 && hisglobalparameter.ucGrabberIndex >=1 && hisglobalparameter.ucGrabberIndex <= 8)
		classTcpClient.writeGrabberStatus(0x0);
}

void QHMainWindow::closefx3slot2()
{
	DWORD uistarttime	=	GetTickCount();
	emit information(QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备 被发现"));
	threadshareDataC1.SetHisPreviewflag(false);
	threadshareDataC2.SetHisPreviewflag(false);

	hisglobalparameter.setrunflag(false);
	hisglobalparameter.setfaflag(false);
	QMutexLocker locker(&itemshareDataC1.mutexItemExec);
	QMutexLocker lockerc2(&itemshareDataC2.mutexItemExec);

	classPlatform.HisFX3CloseDevice();

	bool bIs	=	true;
	DWORD uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC1.flaglock.lockForRead();
		if(!(threadshareDataC1.brawrun || threadshareDataC1.brenderrun || threadshareDataC1.brgbrun)){
			threadshareDataC1.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC1.flaglock.unlock();
		::Sleep(10);
	}

	bIs	=	true;
	uistart	=	GetTickCount();
	while(GetTickCount() < uistart + _ThreadExit_TimeOut){
		threadshareDataC2.flaglock.lockForRead();
		if(!(threadshareDataC2.brawrun || threadshareDataC2.brenderrun || threadshareDataC2.brgbrun)){
			threadshareDataC2.flaglock.unlock();
			bIs	=	false;
			break;
		}
		threadshareDataC2.flaglock.unlock();
		::Sleep(10);
	}

	emit information(QTextCodec::codecForName( "GBK")->toUnicode("等待初始化........"));
	DWORD uiendtime	=	GetTickCount();
	if(uiendtime < uistarttime + _USB30FPGA_INIT_MAXTIME)
		QTimer::singleShot(uistarttime + _USB30FPGA_INIT_MAXTIME - uiendtime, this, SLOT(openfx3slot()));
	else
		QTimer::singleShot(0, this, SLOT(openfx3slot()));
}

int QHMainWindow::getglobalParameter(bool& bShowChannel1, bool& bShowChannel2)
{
	QStringList strname, strvalue;
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			return HisCCMError_Database;

		QSqlQuery query(templatedb);

		query.prepare("SELECT key, value FROM global WHERE classfy='global' AND item='ui'" );
		query.exec();
		while (query.next())
		{
			if(query.value(0).toString() == "show item to end result") hisglobalparameter.bShowItem2EndResult = (query.value(1).toString() == "true");
			else if(query.value(0).toString() == "show result to image") hisglobalparameter.bShowResult2Image = (query.value(1).toString() == "true");
			else if(query.value(0).toString() == "drawtactistics") hisglobalparameter.ucStatisticsDrawType = query.value(1).toString().toUInt();
			else if(query.value(0).toString() == "show ccmtest channel 1") { bShowChannel1 = (query.value(1).toString() == "true"); }
			else if(query.value(0).toString() == "show ccmtest channel 2") { bShowChannel2 = (query.value(1).toString() == "true"); }
		}

		query.prepare("SELECT value FROM global WHERE classfy='global' AND item='configsetting' AND key='password'" );
		query.exec();
		while (query.next()){
			hisglobalparameter.strPassword	=	query.value(0).toString();
		}

		query.prepare("SELECT value FROM global WHERE classfy='global' AND item='debug' AND key='savetextinfo2local'" );
		query.exec();
		while (query.next()){
			hisglobalparameter.bSaveTextInfo2Local	=	query.value(0).toUInt();
			ui.actionSave_Text_Info_To_Local->setChecked(hisglobalparameter.bSaveTextInfo2Local);
		}

		if(!hisglobalparameter.stOperatorMode.bSlaveFromArgv)
		{
			query.prepare("SELECT itemsuffix1,itemsuffix2,key,value,reserve,note FROM global WHERE item='fx3' AND classfy='global'" );
			query.exec();
			while (query.next()){
				hisglobalparameter.ucGrabberIndex		=	query.value(0).toUInt();
				hisglobalparameter.uiGrabberSerial[0]	=	query.value(1).toUInt();
				hisglobalparameter.uiGrabberSerial[1]	=	query.value(2).toUInt();
				hisglobalparameter.uiGrabberSerial[2]	=	query.value(3).toUInt();
				hisglobalparameter.uiGrabberSerial[3]	=	query.value(4).toUInt();
				hisglobalparameter.strFreindlyName		=	query.value(5).toString();
				if(hisglobalparameter.ucGrabberIndex > 8)	hisglobalparameter.ucGrabberIndex = 0;
			}
		}

		query.prepare("SELECT itemsuffix1,itemsuffix2,key,value,reserve,note FROM global WHERE item='grabberparameter' AND classfy='global'" );
		query.exec();
		while (query.next())
		{
			hisglobalparameter.ucFPGAUploadDelay	=	query.value(0).toUInt() & 0xFF;
			hisglobalparameter.ucFX3PacketSize		=	query.value(1).toUInt() & 0xFF;
		}

		query.prepare("SELECT itemsuffix1,itemsuffix2,key,value,reserve,note FROM global WHERE item='chooseplatform' AND classfy='global'" );
		query.exec();
		while (query.next())
		{
			hisglobalparameter.ucChoosePlatform	=	query.value(0).toUInt() & 0xFF;
		}

		query.prepare("SELECT itemsuffix2 FROM global WHERE classfy='global' AND item='imageshow' AND itemsuffix1='config'");
		query.exec();
		while (query.next()){
			QString strData = query.value(0).toString();
			ROPLOW::patchconfigstring(strData, strname, strvalue);
			//(aspectratio:0)(scalemode:0)(sodokumode:0)(cross:0)
			for(unsigned int x=0;	x<strname.size(); ++x){
				if(strname.at(x) == "aspectratio") hisglobalparameter.ucAspectRatio = strvalue.at(x).toUInt() & 0xFF;
				else if(strname.at(x) == "scalemode") hisglobalparameter.ucScaleMode = strvalue.at(x).toUInt() & 0xFF;
				else if(strname.at(x) == "sodokumode") hisglobalparameter.ucSodokuMode = strvalue.at(x).toUInt() & 0xFF;
				else if(strname.at(x) == "cross") hisglobalparameter.bPaintCross = strvalue.at(x).toUInt();
				else if(strname.at(x) == "square") hisglobalparameter.bPaintSquare = strvalue.at(x).toUInt();
				else if(strname.at(x) == "squresizex") hisglobalparameter.iSquaresizex = strvalue.at(x).toInt();
				else if(strname.at(x) == "squresizey") hisglobalparameter.iSquaresizey = strvalue.at(x).toInt();
			}
		}

		query.prepare("SELECT value FROM global WHERE classfy='global' AND item='slave mode' AND key='tcpip'");
		query.exec();
		while (query.next()){
			QString strData = query.value(0).toString();
			ROPLOW::patchconfigstring(strData, strname, strvalue);
			//(type:0)(ipv4:0)(socket:0)
			for(unsigned int x=0;	x<strname.size(); ++x){
				if(strname.at(x) == "type") hisglobalparameter.stOperatorMode.u8TcpIpType = strvalue.at(x).toUInt() & 0xFF;
				else if(strname.at(x) == "ipv4") hisglobalparameter.stOperatorMode.u32IpV4 = strvalue.at(x).toUInt();

				else if(strname.at(x) == "socket") hisglobalparameter.stOperatorMode.u16SocketPort = strvalue.at(x).toUInt() & 0xFFFF;

			}
		}

		query.prepare("SELECT item,itemsuffix1,itemsuffix2,key,value,reserve,note FROM global WHERE classfy='fontonimage'" );
		query.exec();
		while (query.next())
		{
			//(mtfsize:0)(mtfbold:1)(sfrsize:0)(sfrbold:1)
			//(tvlinesize:0)(tvlinebold:1)(othersize:0)(otherbold:1)
			for(unsigned int w=0;	w<2;	++w)
			{
				QString strData = query.value(w).toString();
				ROPLOW::patchconfigstring(strData, strname, strvalue);
				for(unsigned int x=0;	x<strname.size(); ++x)
				{
					if(strname.at(x) == "mtfsize") hisglobalparameter.stForivate.ucImageMTFFontSize = strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "mtfbold") hisglobalparameter.stForivate.bImageMTFFontBold	=	strvalue.at(x).toUInt();
					else if(strname.at(x) == "sfrsize") hisglobalparameter.stForivate.ucImageSFRFontSize = strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "sfrbold") hisglobalparameter.stForivate.bImageSFRFontBold	=	strvalue.at(x).toUInt();
					else if(strname.at(x) == "tvlinesize") hisglobalparameter.stForivate.ucImageTVLineFontSize = strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "tvlinebold") hisglobalparameter.stForivate.bImageTVLineFontBold	=	strvalue.at(x).toUInt();
					else if(strname.at(x) == "othersize") hisglobalparameter.stForivate.ucImageOtherFontSize = strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "otherbold") hisglobalparameter.stForivate.bImageOtherFontBold	=	strvalue.at(x).toUInt();
				}
			}
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");

	return 0;
}

void QHMainWindow::getOperateModeConfig()
{
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			query.prepare("SELECT itemsuffix1 FROM global WHERE classfy='opmode' AND item='manual-a-1'" );
			query.exec();

			//(chart:16)(savelog:true)(totalresult:true)
			while (query.next()){
				QString strData	=	query.value(0).toString();
				ROPLOW::patchconfigstring(strData, strname, strvalue);
				for(int x=0;	x<strname.size();	++x){
					if(strname.at(x) == "savelog")	hisglobalparameter.stOperatorMode.bSaveLog	=	(strvalue.at(x) == "true");
					else if(strname.at(x) == "totalresult")	hisglobalparameter.stOperatorMode.bShowTotalResult	=	(strvalue.at(x) == "true");
					else if(strname.at(x) == "chart")	hisglobalparameter.stOperatorMode.ucChartType	=	strvalue.at(x).toUInt() & 0xFF;
				}
			}

			query.prepare("SELECT itemsuffix1 FROM global WHERE classfy='opmode' AND item='manual-b-1'" );
			query.exec();

			//(chart:16)(min:5.0)(max:800.0)(interface:0)(pin:DVDD)(scene:0)
			while (query.next())
			{
				QString strData	=	query.value(0).toString();
				ROPLOW::patchconfigstring(strData, strname, strvalue);
				for(int x=0;	x<strname.size();	++x){
					if(strname.at(x) == "chart")	hisglobalparameter.stOperatorMode.ucChartType_B	=	strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "min") hisglobalparameter.stOperatorMode.flPlugMin			=	strvalue.at(x).toFloat();
					else if(strname.at(x) == "max") hisglobalparameter.stOperatorMode.flPlugMax		=	strvalue.at(x).toFloat();
					else if(strname.at(x) == "interface")	hisglobalparameter.stOperatorMode.ucPlugInterface	=	strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "scene")	hisglobalparameter.stOperatorMode.ucPlugScene	=	strvalue.at(x).toUInt() & 0xFF;
					else if(strname.at(x) == "pin") sprintf(hisglobalparameter.stOperatorMode.strPlug2ndName, "%s", strvalue.at(x).toAscii().data());
				}
			}

			if(!hisglobalparameter.stOperatorMode.bSlaveFromArgv)
			{
				query.prepare("SELECT value FROM global WHERE classfy='global' AND item='operator mode' AND key='choose mode'");
				query.exec();
				while (query.next()){
					hisglobalparameter.stOperatorMode.ucMode	=	query.value(0).toUInt() & 0xFF;
				}
			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}
}

void QHMainWindow::slotPanelMoveable(bool bChecked)
{
	if(this->isVisible()){
		if(!HISGLOBALUI::isUnlocked()) return;
	}

	if(bChecked){
		QDockWidget::DockWidgetFeatures dockFeature	=	windowc1.classButtonExec->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc1.classButtonExec->setFeatures(dockFeature);
		dockFeature	=	windowc1.classInfoPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc1.classInfoPanel->setFeatures(dockFeature);
		dockFeature	=	windowc1.classTextPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc1.classTextPanel->setFeatures(dockFeature);
		dockFeature	=	windowc1.classDrawTestItem->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc1.classDrawTestItem->setFeatures(dockFeature);
		dockFeature	=	windowc1.classStatisPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc1.classStatisPanel->setFeatures(dockFeature);
		//*******  2018.04.16 add ***************
		
	}
	else{
		QDockWidget::DockWidgetFeatures dockFeature	=	windowc1.classButtonExec->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc1.classButtonExec->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc1.classButtonExec->setFeatures(dockFeature);
		dockFeature	=	windowc1.classInfoPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc1.classInfoPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc1.classInfoPanel->setFeatures(dockFeature);
		dockFeature	=	windowc1.classTextPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc1.classTextPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc1.classTextPanel->setFeatures(dockFeature);

		dockFeature	=	windowc1.classDrawTestItem->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc1.classDrawTestItem->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc1.classDrawTestItem->setFeatures(dockFeature);

		dockFeature	=	windowc1.classStatisPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc1.classStatisPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc1.classStatisPanel->setFeatures(dockFeature);
	}

	if(bChecked){
		QDockWidget::DockWidgetFeatures dockFeature	=	windowc2.classButtonExec->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc2.classButtonExec->setFeatures(dockFeature);
		dockFeature	=	windowc2.classInfoPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc2.classInfoPanel->setFeatures(dockFeature);
		dockFeature	=	windowc2.classTextPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc2.classTextPanel->setFeatures(dockFeature);
		dockFeature	=	windowc2.classDrawTestItem->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc2.classDrawTestItem->setFeatures(dockFeature);
		dockFeature	=	windowc2.classStatisPanel->features();
		dockFeature	|=	QDockWidget::DockWidgetMovable;
		dockFeature	|=	QDockWidget::DockWidgetClosable;
		dockFeature	|=	QDockWidget::DockWidgetFloatable;
		windowc2.classStatisPanel->setFeatures(dockFeature);
	}
	else{
		QDockWidget::DockWidgetFeatures dockFeature	=	windowc2.classButtonExec->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc2.classButtonExec->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc2.classButtonExec->setFeatures(dockFeature);
		dockFeature	=	windowc2.classInfoPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc2.classInfoPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc2.classInfoPanel->setFeatures(dockFeature);
		dockFeature	=	windowc2.classTextPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc2.classTextPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc2.classTextPanel->setFeatures(dockFeature);

		dockFeature	=	windowc2.classDrawTestItem->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc2.classDrawTestItem->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc2.classDrawTestItem->setFeatures(dockFeature);

		dockFeature	=	windowc2.classStatisPanel->features();
		dockFeature	&=	(~QDockWidget::DockWidgetMovable);
		dockFeature	&=	(~QDockWidget::DockWidgetClosable);
		if(!windowc2.classStatisPanel->isFloating()) dockFeature	&=	(~QDockWidget::DockWidgetFloatable);
		windowc2.classStatisPanel->setFeatures(dockFeature);
	}

}

void QHMainWindow::restoreUI()
{
	QByteArray geometry, windowState;
	bool bConfig = false;

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplateui");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			return;

		QSqlQuery query(templatedb);
		query.prepare("SELECT geometry,windowState FROM ui WHERE classfy='restorestatus' AND item='QHMainWindow'" );
		query.exec();


		while (query.next()){
			bConfig = true;
			geometry				= query.value(0).toByteArray();
			windowState		= query.value(1).toByteArray();
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplateui");

	if(bConfig){
		restoreGeometry(geometry);
		restoreState(windowState);
	}

	slotPanelMoveable(false);
	ui.actionPanel_moveable->setChecked(false);
}

void QHMainWindow::slotVersionShow()
{
	QString strpath, strtext, strName;
	for(int x=0;	x<8;	++x)
	{
		switch (x){
		case 0:
			strpath		=	QCoreApplication::applicationFilePath();
			strName	=	"HisFX3CCMTest";
			break;
		case 1:
			strName	=	"HisFX3Platform ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3Platform64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3Platform32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3Platform64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3Platform32.dll";
#endif
#endif
			break;
		case 2:
			strName	=	"HisCCMSensor ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisCCMSensor64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisCCMSensor32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisCCMSensor64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisCCMSensor32.dll";
#endif
#endif
			break;
		case 3:
			strName	=	"HisFX3License ";
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3License64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3License32.dll";
#endif
			break;
		case 4:
			strName	=	"HisCCMOTP ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisCCMOTP64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisCCMOTP32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisCCMOTP64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisCCMOTP32.dll";
#endif
#endif
			break;
		case 5:
			strName	=	"HisFX3Log ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3Log64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3Log32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3Log64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3Log32.dll";
#endif
#endif
			break;
		case 6:
			strName	=	"HisFX3CCMAlg ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3CCMAlg64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3CCMAlg32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\HisFX3CCMAlg64.dll";
#else
			strpath	=	QDir::currentPath() % "\\HisFX3CCMAlg32.dll";
#endif
#endif
			break;
		default:
			strName	=	"RolongoImageTestAlg ";
#ifdef _DEBUG
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\RolongoImageTestAlg64D.dll";
#else
			strpath	=	QDir::currentPath() % "\\RolongoImageTestAlg32D.dll";
#endif
#else
#ifdef _WIN64
			strpath	=	QDir::currentPath() % "\\RolongoImageTestAlg64.dll";
#else
			strpath	=	QDir::currentPath() % "\\RolongoImageTestAlg32.dll";
#endif
#endif
			break;
		}

		DWORD dwsize, dwtemp = 0;
		wchar_t* pstrunicode	=	0;
#ifdef UNICODE
		pstrunicode	=	new wchar_t[strpath.size() + 1];
		strpath.toWCharArray(pstrunicode);
		pstrunicode[strpath.size()]	=	L'\0';
		dwsize		=	GetFileVersionInfoSizeExW(FILE_VER_GET_LOCALISED|FILE_VER_GET_NEUTRAL, pstrunicode, &dwtemp);
#else
		dwsize		=	GetFileVersionInfoSizeExA(FILE_VER_GET_LOCALISED|FILE_VER_GET_NEUTRAL, strpath.toAscii().data(), &dwtemp);
#endif

		unsigned short usversion[4]	=	{0xffff};
		bool bPass	=	false;
		VS_FIXEDFILEINFO* lpBuffer  = 0;

		if(dwsize){
			void* pdata	=	malloc(dwsize+1);
#ifdef UNICODE
			BOOL bresult	=	GetFileVersionInfoExW(FILE_VER_GET_LOCALISED|FILE_VER_GET_NEUTRAL, pstrunicode, dwtemp, dwsize, (LPVOID)(pdata));
#else
			BOOL bresult	=	GetFileVersionInfoExA(FILE_VER_GET_LOCALISED|FILE_VER_GET_NEUTRAL, strpath.toAscii().data(), dwtemp, dwsize, (LPVOID)(pdata));
#endif
			if(bresult){
				UINT   size      = 0;
#ifdef UNICODE
				bresult	=	VerQueryValueW(pdata, L"\\", (LPVOID *)&lpBuffer, &size);
#else
				bresult	=	VerQueryValueA(pdata, "\\", (LPVOID *)&lpBuffer, &size);
#endif
				if(bresult && size && lpBuffer){
					usversion[0]	=	(lpBuffer->dwFileVersionMS >> 16);
					usversion[1]	=	(lpBuffer->dwFileVersionMS & 0x00ffff);
					usversion[2]	=	(lpBuffer->dwFileVersionLS >> 16);
					usversion[3]	=	(lpBuffer->dwFileVersionLS & 0x00ffff);
					bPass	=	true;
				}
			}
			free(pdata);
		}

		if(pstrunicode){
			delete[] pstrunicode;
			pstrunicode	=	0;
		}

		strtext	=	strtext  % strName % tr("Ver: ") % QString::number(usversion[0]) % "." % QString::number(usversion[1]) % "." % \
			QString::number(usversion[2]) % "." % QString::number(usversion[3]) % "\n\n";
	}

	unsigned int uihardversion	=	0;
	unsigned short usOSVersion = 0, usFX3Version = 0;
	if(classPlatform.HisFX3isopen())
	{
		classPlatform.HisFX3GetHardwareVersion(&uihardversion);
		classPlatform.HisFX3GetOSVersion(&usOSVersion);
		classPlatform.HisFX3GetFX3Version(&usFX3Version);
	}

	strtext	=	strtext %  "FPGA " % tr("Ver: ") % QString::number((uihardversion & 0x0000ffff), 10);
	strtext	=	strtext %  "\n\nOS " % tr("Ver: ") % QString::number(usOSVersion);
	strtext	=	strtext %  "\n\nFX3 " % tr("Ver: ") % QString::number(usFX3Version);

	QLabel* pstVersionLabel	=	new QLabel(strtext, this, Qt::Dialog| Qt::Window);
	QFont stFont	=	pstVersionLabel->font();
	stFont.setBold(true);
	stFont.setPointSize(12);
	pstVersionLabel->setWindowTitle(tr("Version"));
	pstVersionLabel->setFont(stFont);
	pstVersionLabel->setAttribute(Qt::WA_DeleteOnClose);
	pstVersionLabel->show();
	pstVersionLabel->raise();
	pstVersionLabel->activateWindow();
}

void QHMainWindow::FX3DeviceConfig()
{
	if(!HISGLOBALUI::isUnlocked()) return;
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	fx3deviceconfig* classfx3deviceconfig	=	new fx3deviceconfig(this);
	classfx3deviceconfig->setAttribute(Qt::WA_DeleteOnClose);
	classfx3deviceconfig->show();
	classfx3deviceconfig->raise();
	classfx3deviceconfig->activateWindow();

	bool bOpen	=	classPlatform.HisFX3isopen();
	unsigned int uiHWSerialNow[40]={0};
	unsigned int iGrbberCount=1;
	if(bOpen) 
	{
		classPlatform.HisFX3GetHardwareKey(uiHWSerialNow);
		//classPlatform.getHardwareKeyList(uiHWSerialNow,iGrbberCount);
	}
	/*else 
	{
		if(!classPlatform.HisFX3OpenDevice())
		{
			classPlatform.getHardwareKeyList(uiHWSerialNow,iGrbberCount);
			bOpen=true;
		}
	}*/
	classfx3deviceconfig->setConfig(bOpen,iGrbberCount, hisglobalparameter.ucGrabberIndex, hisglobalparameter.uiGrabberSerial, uiHWSerialNow, hisglobalparameter.strFreindlyName);
}

void QHMainWindow::UpdateFPGAFW()
{
	if(!classPlatform.HisFX3isopen()){
		QMessageBox::critical(this, tr("ERROR"), tr("The grabber is not opening. Please open the grabber first."));
		return;
	}

	if(windowc1.threadshareData.GetHisTestingflag()){
		QMessageBox::critical(this, tr("ERROR"), tr("Test is running. Please do it again after the test finished."));
		return;
	}

	if(windowc2.threadshareData.GetHisTestingflag()){
		QMessageBox::critical(this, tr("ERROR"), tr("Test is running. Please do it again after the test finished."));
		return;
	}

	if(!HISGLOBALUI::isUnlocked()) return;

	updatefirewaredialog* classupdatefireware	=	new updatefirewaredialog(this);
	classupdatefireware->setAttribute(Qt::WA_DeleteOnClose);
	classupdatefireware->show();
	classupdatefireware->raise();
	classupdatefireware->activateWindow();
}

void QHMainWindow::currentSelfCal()
{
	if(!HISGLOBALUI::isUnlocked()) return;

	if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("电流自校正"), \
		QTextCodec::codecForName( "GBK")->toUnicode("请确认工装上面没有连接任何转板\n此校正过程大概需要4~5分钟\n确定开始校正请选择\"是\""), \
		QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
	{
			unsigned int uiKey[4];
			_HisFX3_Current_Calibration stCalData;

			int iresult	=	classPlatform.HisFX3CurrentCalibration(uiKey, &stCalData);
			if(iresult){
				QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正过程出错"), QString::fromWCharArray(classPlatform.GetLastError()));
				return;
			}

#define CURRENTCALIBRATIONDATA_Save2LocalFile

#ifdef CURRENTCALIBRATIONDATA_Save2LocalFile
			//work current
			{
				QFile classFileDOVDD("current_work_dovdd.txt");
				classFileDOVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outDOVDD(&classFileDOVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outDOVDD << stCalData.flWorkDOVDD[x] << "f,";

				QFile classFileDVDD("current_work_dvdd.txt");
				classFileDVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outDVDD(&classFileDVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outDVDD << stCalData.flWorkDVDD[x] << "f,";

				QFile classFileAVDD("current_work_avdd.txt");
				classFileAVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outAVDD(&classFileAVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outAVDD << stCalData.flWorkAVDD[x] << "f,";

				QFile classFileAF("current_work_af.txt");
				classFileAF.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outAF(&classFileAF);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outAF << stCalData.flWorkAF[x] << "f,";

				QFile classFilePOW("current_work_pow.txt");
				classFilePOW.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outPOW(&classFilePOW);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outPOW << stCalData.flWorkPOW[x] << "f,";

				QFile classFileOTP("current_work_otp.txt");
				classFileOTP.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outOTP(&classFileOTP);
				for(unsigned int x=0;	x< 100; ++x)
					outOTP << stCalData.flWorkOTP[x] << "f,";
			}
			

			//standby current
			{
				QFile classFileDOVDD("current_standby_dovdd.txt");
				classFileDOVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outDOVDD(&classFileDOVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outDOVDD << stCalData.flStandbyDOVDD[x] << "f,";

				QFile classFileDVDD("current_standby_dvdd.txt");
				classFileDVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outDVDD(&classFileDVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outDVDD << stCalData.flStandbyDVDD[x] << "f,";

				QFile classFileAVDD("current_standby_avdd.txt");
				classFileAVDD.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outAVDD(&classFileAVDD);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outAVDD << stCalData.flStandbyAVDD[x] << "f,";

				QFile classFileAF("current_standby_af.txt");
				classFileAF.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outAF(&classFileAF);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outAF << stCalData.flStandbyAF[x] << "f,";

				QFile classFilePOW("current_standby_pow.txt");
				classFilePOW.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream outPOW(&classFilePOW);
				for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
					outPOW << stCalData.flStandbyPOW[x] << "f,";
			}
			

#else
			if(iresult = ROPLOW::currentCal2DB(uiKey, &stCalData, 1)){
				QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("保存数据出错"), QTextCodec::codecForName( "GBK")->toUnicode("保存校正数据出错"));
				return;
			}
#endif

			if(classPlatform.getCameraCountSupported() >= 2)
			{
				iresult	=	classPlatform.HisFX3CurrentCalibration_S2(uiKey, &stCalData);
				if(iresult){
					QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正过程出错"), QString::fromWCharArray(classPlatform.GetLastError()));
					return;
				}

#ifdef CURRENTCALIBRATIONDATA_Save2LocalFile

				//work current
				{
					QFile classFileDOVDD("current_work_dovdd_s2.txt");
					classFileDOVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outDOVDD(&classFileDOVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outDOVDD << stCalData.flWorkDOVDD[x] << "f,";

					QFile classFileDVDD("current_work_dvdd_s2.txt");
					classFileDVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outDVDD(&classFileDVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outDVDD << stCalData.flWorkDVDD[x] << "f,";

					QFile classFileAVDD("current_work_avdd_s2.txt");
					classFileAVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outAVDD(&classFileAVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outAVDD << stCalData.flWorkAVDD[x] << "f,";

					QFile classFileAF("current_work_af_s2.txt");
					classFileAF.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outAF(&classFileAF);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outAF << stCalData.flWorkAF[x] << "f,";

					QFile classFilePOW("current_work_pow_s2.txt");
					classFilePOW.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outPOW(&classFilePOW);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outPOW << stCalData.flWorkPOW[x] << "f,";

					QFile classFileOTP("current_work_otp_s2.txt");
					classFileOTP.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outOTP(&classFileOTP);
					for(unsigned int x=0;	x< 100; ++x)
						outOTP << stCalData.flWorkOTP[x] << "f,";
				}


				//standby current
				{
					QFile classFileDOVDD("current_standby_dovdd_s2.txt");
					classFileDOVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outDOVDD(&classFileDOVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outDOVDD << stCalData.flStandbyDOVDD[x] << "f,";

					QFile classFileDVDD("current_standby_dvdd_s2.txt");
					classFileDVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outDVDD(&classFileDVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outDVDD << stCalData.flStandbyDVDD[x] << "f,";

					QFile classFileAVDD("current_standby_avdd_s2.txt");
					classFileAVDD.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outAVDD(&classFileAVDD);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outAVDD << stCalData.flStandbyAVDD[x] << "f,";

					QFile classFileAF("current_standby_af_s2.txt");
					classFileAF.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outAF(&classFileAF);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outAF << stCalData.flStandbyAF[x] << "f,";

					QFile classFilePOW("current_standby_pow_s2.txt");
					classFilePOW.open(QIODevice::WriteOnly | QIODevice::Text);
					QTextStream outPOW(&classFilePOW);
					for(unsigned int x=0;	x< _HisFX3V2_CURRENTCAL_COUNT; ++x)
						outPOW << stCalData.flStandbyPOW[x] << "f,";
				}

#else

				if(iresult = ROPLOW::currentCal2DB(uiKey, &stCalData, 2)){
					QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("保存数据出错"), QTextCodec::codecForName( "GBK")->toUnicode("保存校正数据出错"));
					return;
				}

#endif
			}

			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正完成"), \
				QTextCodec::codecForName( "GBK")->toUnicode("校正成功!!!"));
	}
}

void QHMainWindow::voltageSelfCal()
{
	if(!HISGLOBALUI::isUnlocked()) return;

	if(QMessageBox::question(this, tr("Voltage Calibration"), \
		tr("Please make sure there is not any circuit board connected before starting.\nThe process may take 4~5 minites.\nIf everything is ok, please click \"YES\" to strart"), \
		QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
			unsigned int uiKey[4];
			_HisFX3_Voltage_Calibration stCalData;

			int iresult	=	classPlatform.HisFX3VlotageCalibration(uiKey, &stCalData);
			if(iresult){
				QMessageBox::information(this, tr("ERROR"), QString::fromWCharArray(classPlatform.GetLastError()));
				return;
			}

			if(iresult = ROPLOW::voltageCal2DB(uiKey, &stCalData, 1)){
				QMessageBox::information(this, tr("ERROR"), tr("Save calibration data failed."));
				return;
			}

#if (defined _HisFX3_Platform_MIPI_R4)
			if(iresult	=	classPlatform.HisFX3VlotageCalibration_S2(uiKey, &stCalData)){
				QMessageBox::information(this, tr("ERROR"), QString::fromWCharArray(classPlatform.GetLastError()));
				return;
			}

			if(iresult = ROPLOW::voltageCal2DB(uiKey, &stCalData, 2)){
				QMessageBox::information(this, tr("ERROR"), tr("Save calibration data failed."));
				return;
			}
#endif

			QMessageBox::information(this, tr("SUCCESS"), tr("Voltage calibration succeeded."));
	}
}

void QHMainWindow::OSSelfCal()
{
	if(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5 && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R2R3)
		return;

	if(!HISGLOBALUI::isUnlocked()) return;

	if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("OS自校正"), \
		QTextCodec::codecForName( "GBK")->toUnicode("请确认工装上面没有连接任何转板\n继续请选择\"是\""), \
		QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
	{
			int iresult;
			if(iresult	=	classPlatform.HisFX3R2OSSwitch(true)){
				QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正过程出错"), QString::fromWCharArray(classPlatform.GetLastError()));
				return;
			}

			if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("OS自校正"), \
				QTextCodec::codecForName( "GBK")->toUnicode("现在请插上校正板\n此过程大概需要5~6分钟\n继续请选择\"是\""), \
				QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
					unsigned int uiKey[4];
					const unsigned int uiMaxItems	=	2500;
					_HisFX3R2_OSCal_Item stCal[uiMaxItems];
					unsigned int uiItemCount	=	0;
					
					if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5) || \
						(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5X))
					{
						HISPLATFORMOS::fillCalibrationItemR5(stCal, uiItemCount);
					}
					else if(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R2R3)
					{
						HISPLATFORMOS::fillCalibrationItemR3(stCal, uiItemCount);
					}
					else
					{
						emit information(tr("The OS Calibration Is Not Supported."));
						return;
					}
					
					_HisFX3R2_OSCal_Item* stCal2	=	stCal + uiItemCount;
					_HisFX3R2_OSCal_Item* stCal3	=	stCal + uiItemCount *2;
					_HisFX3R2_OSCal_Item* stCal4	=	stCal + uiItemCount *3;
					_HisFX3R2_OSCal_Item* stCal5	=	stCal + uiItemCount *4;

					memcpy(stCal2, stCal, sizeof(_HisFX3R2_OSCal_Item) *uiItemCount);
					memcpy(stCal3, stCal, sizeof(_HisFX3R2_OSCal_Item) *uiItemCount);
					memcpy(stCal4, stCal, sizeof(_HisFX3R2_OSCal_Item) *uiItemCount);
					memcpy(stCal5, stCal, sizeof(_HisFX3R2_OSCal_Item) *uiItemCount);

					if(iresult = classPlatform.HisFX3R2OSCalibration(uiKey, stCal, uiItemCount *5)){
						QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正过程出错"), QString::fromWCharArray(classPlatform.GetLastError()));
						return;
					}

					std::vector<float> vectorsort(5);
					bool bOK	=	true;
					for(unsigned int x=0;	x<uiItemCount;	++x){
						vectorsort.at(0)	=	stCal[x].flOffset;
						vectorsort.at(1)	=	stCal2[x].flOffset;
						vectorsort.at(2)	=	stCal3[x].flOffset;
						vectorsort.at(3)	=	stCal4[x].flOffset;
						vectorsort.at(4)	=	stCal5[x].flOffset;
						std::sort(vectorsort.begin(), vectorsort.end());
						stCal[x].flOffset	=	(vectorsort.at(1) + vectorsort.at(2) + vectorsort.at(3)) /3.0;
						if(fabsf(stCal[x].flOffset > 80.0f)) bOK = false;
					}

					if(!bOK){
						QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校准失败"), QTextCodec::codecForName( "GBK")->toUnicode("校准数据异常\n请重新校准!!!"));
						return;
					}

					if(iresult = HISPLATFORMOS::OSCal2DB(uiKey, stCal, uiItemCount)){
						QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("保存数据出错"), QTextCodec::codecForName( "GBK")->toUnicode("保存校正数据出错"));
						return;
					}

					if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("OS自校正"), \
						QTextCodec::codecForName( "GBK")->toUnicode("现在把校正板从工装上拔掉\n继续请选择\"是\""), \
						QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
							classPlatform.HisFX3R2OSSwitch(true);
					}

					QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("校正完成"), \
						QTextCodec::codecForName( "GBK")->toUnicode("校正成功!!!"));
			}
	}
}

void QHMainWindow::slotShortcutConfig()
{
	QString strTableC1, strTableC2;

	if(classPlatform.getCameraCountSupported() == 2)
	{
		if(!HISDBCUSTOM::isTableExist(itemshareDataC1.currentTableName)){
			emit information(tr("Please choose config table first"));
			return;
		}

		if(!itemshareDataC1.shortcutgather.size())	
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
		}

		if(!HISDBCUSTOM::isTableExist(itemshareDataC2.currentTableName)){
			emit information(tr("Please choose config table first"));
			return;
		}

		if(!itemshareDataC2.shortcutgather.size())	
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC2.currentTableName, itemshareDataC2.shortcutgather, false);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC2.shortcutgather);
		}

		strTableC1	=	itemshareDataC1.currentTableName;
		strTableC2	=	itemshareDataC2.currentTableName;
	}
	else
	{
		if(!HISDBCUSTOM::isTableExist(itemshareDataC1.currentTableName)){
			emit information(tr("Please choose config table first"));
			return;
		}

		if(!itemshareDataC1.shortcutgather.size())	
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
		}

		strTableC1	=	itemshareDataC1.currentTableName;
	}

	QHShortcut classShortcut(this, (classPlatform.getCameraCountSupported() == 2)?(2):(0), strTableC1, strTableC2);
	classShortcut.exec();
}

void QHMainWindow::slotCompterCompatibilityTest()
{
	int iDelayMin = 10, iDelayMax = 200, iSkip = 10;
	const int iLoopTime = 20;
	const int ciSizeType	=	2;
	float flErrorRate[ciSizeType][iLoopTime] = {0};
	float flErrorRead[ciSizeType][iLoopTime] = {0};
	bool bOK[ciSizeType][iLoopTime] = {0};
	unsigned int uiNeedDelay[iLoopTime] = {0};
	unsigned int uiOKCount = 0;
	const float cflErrorLimit			=	0.0001f;
	const float cflReadErrorLimit	=	0.0001f;

	unsigned int uiTotalTask	=	ciSizeType *iLoopTime;
	unsigned int uiProcessPercent   = 0, uiProcessIndex = 0, uiProcessBefore = 0;
	DWORD dwConsole = AllocConsole();
	HANDLE handleWirte = 0;
	wchar_t wstrFile[256];
	if(dwConsole) {  handleWirte	=	GetStdHandle(STD_OUTPUT_HANDLE); swprintf(wstrFile, L"开始测试...\n"); WriteConsoleW(handleWirte, wstrFile, wcslen(wstrFile), NULL, NULL); }

#define _CODE_TESTCOMPABILITY_PROCESS_UPDATE {++uiProcessIndex; uiProcessPercent=uiProcessIndex*100/uiTotalTask; \
	if(uiProcessPercent>uiProcessBefore && handleWirte) {uiProcessBefore=uiProcessPercent; swprintf(wstrFile, L"兼容性测试已完成：%d%%\n", uiProcessPercent); WriteConsoleW(handleWirte, wstrFile, wcslen(wstrFile), NULL, NULL);} }
#define _CODE_TESTCOMPABILITY_PROCESS_EXIT {if(handleWirte) {CloseHandle(handleWirte);}  if(dwConsole) {FreeConsole();}}

	char strText[128];
	for(unsigned int w=0;	w<ciSizeType;	++w)
	{
		if(w == 0)	classPlatform.setBulkTransformSize(2 *1024 *1024);
		else if(w == 1)	classPlatform.setBulkTransformSize(1 *1024 *1024);
		else if(w == 2)	classPlatform.setBulkTransformSize(1 *512 *1024);
// 		else if(w == 3)	classPlatform.setBulkTransformSize(1 *1024 *1024);
// 		else if(w == 4)	classPlatform.setBulkTransformSize(1 *512 *1024);
// 		else if(w == 5)	classPlatform.setBulkTransformSize(1 *256 *1024);

		for(unsigned int x=0;	x<iLoopTime;	++x)
		{
			int iDelay	=	iDelayMin + x*iSkip;
			classPlatform.setUSBSpeed(iDelay);
			sprintf_s(strText, 128, "delay: %d, type:%d", iDelay, w);
			OutputDebugStringA(strText);
			classPlatform.testComputerCompatibility(&(flErrorRate[w][x]), &(flErrorRead[w][x]));
			if((flErrorRate[w][x] < cflErrorLimit) && (flErrorRead[w][x] < cflReadErrorLimit)) bOK[w][x] = true; 

			_CODE_TESTCOMPABILITY_PROCESS_UPDATE
			if(handleWirte)
			{
				swprintf(wstrFile, L"类型：%d   延时：%d   丢包率：%f  读IIC失败率:%f \n", w, iDelayMin+x*iSkip, flErrorRate[w][x], flErrorRead[w][x]);
				WriteConsoleW(handleWirte, wstrFile, wcslen(wstrFile), NULL, NULL);
			}
		}

	}

	_CODE_TESTCOMPABILITY_PROCESS_EXIT

	for(unsigned int x=0;	x<iLoopTime;	++x)
	{
		bool bIs = true;
		for(unsigned int w=0;	w<ciSizeType;	++w)
		{
			bIs = bIs && bOK[w][x];
		}

		if(bIs)
		{
			uiNeedDelay[uiOKCount]	=	iDelayMin + x *iSkip;
			uiOKCount++;
		}
	}

	if(uiOKCount == 0) emit information(tr("The Computer's Compatibility is Very Bad."));
	else
	{
		unsigned int uiBestDelay = 0;
		QStringList listResult;
		for(unsigned int x=0;	x<uiOKCount;	++x)
		{
			if(!uiBestDelay && uiNeedDelay[x] >= 20) { uiBestDelay = uiNeedDelay[x]; }
			listResult.push_back(QString::number(uiNeedDelay[x]));
		}

		if(!uiBestDelay) uiBestDelay = uiNeedDelay[0];
		emit information(tr("Good Delay Setting: ") % listResult.join(", "));
	}
	
}

void QHMainWindow::slotJsvDecode(){
	QStringList list = QFileDialog::getOpenFileNames(this, "select .jsv file", "", "Binary File(*.jsv)");
	for (int i = 0; i < list.size(); i++)
	{
		QFile file(list.at(i));
		file.open(QIODevice::ReadOnly);
		QByteArray buff=file.readAll();
		file.close();

		QByteArray jsvMD5 = buff.right(32);
		buff.resize(buff.size() - 32);

		QCryptographicHash md(QCryptographicHash::Md5);
		md.addData(buff);
		QByteArray calMD5 = md.result();
		calMD5=calMD5.toHex();

		bool bb = (calMD5 == jsvMD5);
		if (!bb) {
			QMessageBox::warning(this, "Error", "jsv File Error!");
			return;
		}

		QString str = list.at(i);
		str = str.remove(".jsv");

		QFile fileCSV(str+"_output_.csv");
		fileCSV.open(QIODevice::WriteOnly);
		fileCSV.write(buff);
		fileCSV.close();
		QMessageBox::information(this, "success", "jsv to csv, success!");

	}
}

thread_Key::thread_Key(QObject *parent/* =0 */):QThread(parent),m_parent((QHMainWindow*)parent){

}

thread_Key::~thread_Key(){

}

void thread_Key::run(){
	::OutputDebugString(L"SOFIA:Start Run");

	QTime time = QTime::currentTime();
	while (QTime::currentTime() < time.addMSecs(500)) {

	}

	QString str;
	str.append("SOFIA:");
	for (int i=0;i<m_parent->m_vecTemp.size();i++)
	{
		str.append(QString::number(m_parent->m_vecTemp.at(i)));
		str.append("|");
	}
	
	OutputDebugString(str.toStdWString().data());

	m_parent->mutexKey.lock();
	if(m_parent->m_vecTemp.size()>1){
		m_parent->m_vecTemp.clear();
		m_parent->mutexKey.unlock();
		::OutputDebugString(L"SOFIA: Key number > 1");
		return;
	}
		

	Qt::Key key=(Qt::Key)m_parent->m_vecTemp.at(0);
	m_parent->m_vecTemp.clear();
	m_parent->mutexKey.unlock();

	m_parent->keyPressEvent_Ex(key);
	
	::OutputDebugString(L"SOFIA:Start Run End");
}