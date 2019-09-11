#include "hardwareop.h"
#include "QTextCodec.h"
#include <Windows.h>
#include "HisFX3Platform.h"
#include <QMessageBox>
#include <QStringBuilder>
#include <QFileDialog>

hardwareop::hardwareop(QWidget *parent,bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC)
	: QDockWidget(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC)
{
	ui.setupUi(this);

	int iresult;
	float flVoltMin, flVoltMax;
	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_AVDD, bChannel1)){
		ui.avddVolt_checkBox->setText("AVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.avddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.avddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.avddVolt_checkBox->setVisible(false);
		ui.avddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_DVDD, bChannel1)){
		ui.dvddVolt_checkBox->setText("DVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.dvddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.dvddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.dvddVolt_checkBox->setVisible(false);
		ui.dvddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_DOVDD, bChannel1)){
		ui.dovddVolt_checkBox->setText("DOVDD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.dovddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.dovddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.dovddVolt_checkBox->setVisible(false);
		ui.dovddVolt_doubleSpinBox->setVisible(false);
	}

	if(0/*classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_IIC, bChannel1)*/){
		ui.ioddVolt_checkBox->setText("IODD(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.ioddVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.ioddVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.ioddVolt_checkBox->setVisible(false);
		ui.ioddVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_AF, bChannel1)){
		ui.afVolt_checkBox->setText("AF(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.afVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.afVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.afVolt_checkBox->setVisible(false);
		ui.afVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_OTP, bChannel1)){
		ui.vfuseVolt_checkBox->setText("OTP(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.vfuseVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.vfuseVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.vfuseVolt_checkBox->setVisible(false);
		ui.vfuseVolt_doubleSpinBox->setVisible(false);
	}

	if(classPlatform.getVoltageSupported(flVoltMin, flVoltMax, _HisFX3_Platform_VlotOn_POW, bChannel1)){
		ui.powVolt_checkBox->setText("POW(0~" % QString::number(flVoltMax, 'f', 1) % "V)");
		ui.powVolt_doubleSpinBox->setMinimum(flVoltMin);
		ui.powVolt_doubleSpinBox->setMaximum(flVoltMax);
	}
	else{
		ui.powVolt_checkBox->setVisible(false);
		ui.powVolt_doubleSpinBox->setVisible(false);
	}

	std::vector<unsigned int> vecProtocalList;
	classPlatform.getProtocalSupported(vecProtocalList, bChannel1);
	for(unsigned int x=0;	x<vecProtocalList.size();	++x)
	{
		ui.mipiLanecomboBox->addItem(HISGLOBALUI::protocal2String(vecProtocalList.at(x)));
	}

	classPlatform.getMCLKSupported(flVoltMin, flVoltMax);
	ui.mclk_doubleSpinBox->setMinimum(flVoltMin);
	ui.mclk_doubleSpinBox->setMaximum(flVoltMax);

	if(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R2R3 && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5 && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R3X)
	{
		ui.searchSlave_pushButton->setVisible(false);
	}

	ui.spiCSLowcheckBox->setVisible(false);
	ui.spiLittleEndiancheckBox->setVisible(false);

	if(classPlatform.getCommunicationProtocalSupported(_HisFX3_CommProtocal_SPI, bBoxChannel1))
	{
		ui.communicatetypecomboBox->addItem("SPI");
	}

#ifdef _DEBUG
	ui.communicatetypecomboBox->addItem("OS IIC");
	ui.communicatetypecomboBox->addItem("Current IIC");
#endif

	ui.communicatetypecomboBox->setCurrentIndex(0);
	connect(ui.communicatetypecomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(slotChangeCommuProtocal(const QString &)));

	if(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5 && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X)
	{
		ui.vol12Vlabel->setVisible(false);
		ui.vol12VcomboBox->setVisible(false);
	}

	if(classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5 && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R5X && \
		classPlatform.getCurrentPlatformType() != _HisFX3_Platform_Type_R3X)
	{
		ui.vol5Vlabel->setVisible(false);
		ui.vol5VcomboBox->setVisible(false);
	}

#ifndef _DEBUG
	ui.batchEETypelabel->setVisible(false);
	ui.batchEETypecomboBox->setVisible(false);
	ui.batchTestpushButton->setVisible(false);
#endif


	unsigned int uiIOStatus;
	if(bBoxChannel1) iresult = classPlatform.HisFX3IO_OutPortRead(uiIOStatus, 0xFF);
	else iresult = classPlatform.HisFX3IO_OutPortRead_S2(uiIOStatus, 0xFF);
	if(!iresult)
	{
		if(uiIOStatus & 0x01) ui.GPIOOut0checkBox->setChecked(true);
		if(uiIOStatus & 0x02) ui.GPIOOut1checkBox->setChecked(true);
		if(uiIOStatus & 0x04) ui.GPIOOut2checkBox->setChecked(true);
		if(uiIOStatus & 0x08) ui.GPIOOut3checkBox->setChecked(true);
	}

	connect(ui.voltMeasurepushButton, SIGNAL(released()), this, SLOT(slotMeasureVolt()));
	connect(ui.voltreadpushButton, SIGNAL(released()), this, SLOT(freshVoltage()));
	connect(ui.vlotsetpushButton, SIGNAL(released()), this, SLOT(setVoltage()));
	connect(ui.resethighpushButton, SIGNAL(released()), this, SLOT(resethigh()));
	connect(ui.resetlowpushButton, SIGNAL(released()), this, SLOT(resetlow()));
	connect(ui.pwndhighpushButton, SIGNAL(released()), this, SLOT(pwndhigh()));
	connect(ui.pwndlowpushButton, SIGNAL(released()), this, SLOT(pwndlow()));
	connect(ui.setmclkpushButton, SIGNAL(released()), this, SLOT(setmclk()));
	connect(ui.readmclkpushButton, SIGNAL(released()), this, SLOT(freshmclk()));
	connect(ui.setLanepushButton, SIGNAL(released()), this, SLOT(setlane()));
	connect(ui.readLanepushButton, SIGNAL(released()), this, SLOT(freshlane()));
	connect(ui.i2creadpushButton, SIGNAL(released()), this, SLOT(readi2c()));
	connect(ui.i2cwritepushButton, SIGNAL(released()), this, SLOT(writei2c()));
	connect(ui.i2cbatchpushButton, SIGNAL(released()), this, SLOT(batchwritei2c()));
	connect(ui.i2cbatchRead_pushButton, SIGNAL(released()), this, SLOT(batchreadi2c()));
	connect(ui.GPIOOut0checkBox, SIGNAL(stateChanged(int)), this, SLOT(changgpio0(int)));
	connect(ui.GPIOOut1checkBox, SIGNAL(stateChanged(int)), this, SLOT(changgpio1(int)));
	connect(ui.GPIOOut2checkBox, SIGNAL(stateChanged(int)), this, SLOT(changgpio2(int)));
	connect(ui.GPIOOut3checkBox, SIGNAL(stateChanged(int)), this, SLOT(changgpio3(int)));
	connect(ui.getGPIO_pushButton, SIGNAL(released()), this, SLOT(readGPIOStatus()));
	connect(ui.searchSlave_pushButton, SIGNAL(released()), this, SLOT(searchSlave()));
	connect(ui.binOpenpushButton, SIGNAL(released()), this, SLOT(openBIN()));
	connect(ui.binSavepushButton, SIGNAL(released()), this, SLOT(saveBIN()));
	connect(ui.binWritepushButton, SIGNAL(released()), this, SLOT(writeBIN()));
	connect(ui.binReadpushButton, SIGNAL(released()), this, SLOT(readBIN()));
	connect(ui.binDataCreratepushButton, SIGNAL(released()), this, SLOT(binDataCreate()));
	connect(ui.binData00epushButton, SIGNAL(released()), this, SLOT(binDataCreate0()));
	connect(ui.binDataFFpushButton, SIGNAL(released()), this, SLOT(binDataCreate0xFF()));
	connect(ui.binDataFFpushButton, SIGNAL(released()), this, SLOT(binDataCreate0xFF()));
	
	connect(ui.batchIICModecomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotBatchIICModeChange(int)));
	connect(ui.batchFormatpushButton, SIGNAL(released()), this, SLOT(slotBatchFormat()));
	connect(ui.batchTestpushButton, SIGNAL(released()), this, SLOT(slotBatchTest()));

	freshVoltage();
	freshmclk();

	
	unsigned short usi2cspeed;
	if(iresult	=	globalFunPointer.GetHisFX3IICSpeed(&usi2cspeed)){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取I2C速率失败"));
	}
	else{
		ui.i2cspeedspinBox->setValue(usi2cspeed);
	}

	ui.binSavecheckBox->setVisible(false);

}

hardwareop::~hardwareop()
{
}

void hardwareop::slotMeasureVolt()
{
	float fldovdd=0.0f, flavdd=0.0f, fldvdd=0.0f, flvfuse=0.0f, flaf=0.0f, flPOW = 0.0f;
	int iresult	=	globalFunPointer.MeasureHisFX3Voltage(&fldovdd, &flavdd, &fldvdd, &flaf, &flvfuse, &flPOW);
	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("测量电压值失败"));
	}
	else{
		ui.avddVolt_doubleSpinBox->setValue(flavdd);
		ui.dvddVolt_doubleSpinBox->setValue(fldvdd);
		ui.dovddVolt_doubleSpinBox->setValue(fldovdd);
		ui.afVolt_doubleSpinBox->setValue(flaf);
		ui.vfuseVolt_doubleSpinBox->setValue(flvfuse);
		ui.powVolt_doubleSpinBox->setValue(flPOW);
	}
}

void hardwareop::freshVoltage()
{
	float fldovdd=0.0f, flavdd=0.0f, fldvdd=0.0f, flvfuse=0.0f, flaf=0.0f, flIODD = 0.0f, flPOW = 0.0f;
	int iresult	=	globalFunPointer.GetHisFX3Voltage(&fldovdd, &flavdd, &fldvdd, &flaf, &flvfuse, &flPOW, &flIODD);
	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取dovdd,avdd,dvdd电压信息失败"));
	}
	else{
		ui.avddVolt_doubleSpinBox->setValue(flavdd);
		ui.dvddVolt_doubleSpinBox->setValue(fldvdd);
		ui.dovddVolt_doubleSpinBox->setValue(fldovdd);
		ui.afVolt_doubleSpinBox->setValue(flaf);
		ui.vfuseVolt_doubleSpinBox->setValue(flvfuse);
		ui.ioddVolt_doubleSpinBox->setValue(flIODD);
		ui.powVolt_doubleSpinBox->setValue(flPOW);
	}
}

void hardwareop::setVoltage()
{
	float flavdd			=	ui.avddVolt_doubleSpinBox->value();
	float fldvdd			=	ui.dvddVolt_doubleSpinBox->value();
	float fldovdd		=	ui.dovddVolt_doubleSpinBox->value();
	float flaf				=	ui.afVolt_doubleSpinBox->value();
	float flvfuse		=	ui.vfuseVolt_doubleSpinBox->value();
	float flPOW	=	ui.powVolt_doubleSpinBox->value();
	float flIODD	=	ui.ioddVolt_doubleSpinBox->value();

	unsigned int uiFlag	=	0;
	if(ui.avddVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_AVDD;
	if(ui.dvddVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_DVDD;
	if(ui.dovddVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_DOVDD;
	//if(ui.ioddVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_IIC;
	if(ui.afVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_AF;
	if(ui.vfuseVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_OTP;
	if(ui.powVolt_checkBox->isChecked()) uiFlag |= _HisFX3_Platform_VlotOn_POW;

	int iresult	=	globalFunPointer.SetHisFX3Voltage(fldovdd, flavdd, fldvdd, flaf, flvfuse, flPOW, flIODD, uiFlag, 1.0f);
	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置dovdd, dvdd, avdd, af, vfuse电压失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置dovdd, dvdd, avdd, af, vfuse电压成功"));

	if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5) || \
		(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5X) || \
		(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R3X))
	{
		if(iresult = classPlatform.HisFX3Set5V12V(ui.vol5VcomboBox->currentIndex(), ui.vol12VcomboBox->currentIndex()))
			showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置5V, 12V电压失败"));
	}
}

void hardwareop::resethigh()
{
	int iresult	=	globalFunPointer.PullHisFX3RESET(true);
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉高RESET失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉高RESET成功"));
}

void hardwareop::resetlow()
{
	int iresult	=	globalFunPointer.PullHisFX3RESET(false);
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉低RESET失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉低RESET成功"));
}

void hardwareop::pwndhigh()
{
	int iresult	=	globalFunPointer.PullHisFX3PWND(true);
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉高PWND失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉高PWND成功"));
}

void hardwareop::pwndlow()
{
	int iresult	=	globalFunPointer.PullHisFX3PWND(false);
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉低PWND失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("拉低PWND成功"));
}

void hardwareop::freshmclk()
{
	float flmclk;
	int iresult	=	globalFunPointer.GetHisFX3MCLK(&flmclk);
	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取当前mclk失败"));
		return;
	}
	ui.mclk_doubleSpinBox->setValue(flmclk);
}

void hardwareop::setmclk()
{
	float flmclk	=	ui.mclk_doubleSpinBox->value();
	if(globalFunPointer.SetHisFX3MCLK(flmclk))	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定mclk失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定mclk成功"));
}

void hardwareop::freshlane()
{
	ui.mipiLanecomboBox->setCurrentIndex(-1);
	unsigned char uclane;
	int iresult	=	globalFunPointer.GetHisFX3Lane(&uclane);
	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取当前lane失败"));
		return;
	}

	ui.mipiLanecomboBox->setCurrentIndex(ui.mipiLanecomboBox->findText(HISGLOBALUI::protocal2String(uclane)));
}

void hardwareop::setlane()
{
	int iresult	=	globalFunPointer.SetHisFX3Lane(HISGLOBALUI::protocal2UInt(ui.mipiLanecomboBox->currentText()));
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定lane失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定lane成功"));
}

void hardwareop::readi2c()
{
	ui.datalineEdit->clear();
	unsigned short usspeed	=	ui.i2cspeedspinBox->value();

	int iresult;
	bool bSPI			=	(ui.communicatetypecomboBox->currentText() == "SPI");
	bool bOS			=	(ui.communicatetypecomboBox->currentText() == "OS IIC");
	bool bCurrent	=	(ui.communicatetypecomboBox->currentText() == "Current IIC");

	if(bSPI){
		if(iresult	=	globalFunPointer.SetHisFX3SPISpeed(usspeed)){
			showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定SPI 速率失败"));
			return;
		}
	}
	else{
		if(iresult	=	globalFunPointer.SetHisFX3IICSpeed(usspeed)){
			showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定I2C 速率失败"));
			return;
		}
	}

	unsigned char ucslave;
	unsigned int uireg;
	unsigned int uidata;
	unsigned __int64 ui64data;
	QString strtext;

	strtext	=	ui.slavelineEdit->text();
	strtext	=	strtext.remove(" ");
	if(strtext.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能为空"));
		return;
	}

	bool bok;
	uidata		=	0x0;
	strtext		=	strtext.toLower();
	uidata		=	strtext.toUInt(&bok, 16);
	if(!uidata){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能为0"));
		return;
	}
	else if(uidata	> 0xFF){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能大于0xff"));
		return;
	}
	ucslave	=	static_cast<unsigned char>(uidata);

	strtext	=	ui.reglineEdit->text();
	strtext	=	strtext.remove(" ");
	if(strtext.size() < 1  && (ui.i2ctypecomboBox->currentIndex() < 6 || ui.i2ctypecomboBox->currentIndex() > 8)){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("reg 不能为空"));
		return;
	}

	strtext		=	strtext.toLower();
	uireg		=	strtext.toUInt(&bok, 16);

	ui64data	=	0xFFFFFFFFFFFFFFFF;
	uidata		=	0xFFFFFFFF;
	unsigned short ustype;
	switch (ui.i2ctypecomboBox->currentIndex()){
	case 0:
		ustype	=	0x0808;
		break;
	case 1:
		ustype	=	0x0816;
		break;
	case 2:
		ustype	=	0x1608;
		break;
	case 3:
		ustype	=	0x1616;
		break;
	case 4:
		ustype	=	0x1632;
		break;
	case 5:
		ustype	=	0x1664;
		break;
	case 6:
		ustype	=	0x0864;
		break;
	case 7:
		ustype	=	0x0008;
		break;
	case 8:
		ustype	=	0x0016;
		break;
	case 9:
		ustype	=	0x0032;
		break;
	default:
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("I2C 读取类型选择不正确"));
		return;
		break;
	}

	if(bSPI)
		iresult	=	globalFunPointer.HisFX3ReadSPI(ucslave, uireg, &ui64data, ustype, ui.spiCSLowcheckBox->isChecked(), ui.spiLittleEndiancheckBox->isChecked());
	else if(bOS){
		unsigned int uiTempData;
		iresult	=	classPlatform.HisFX3ReadOSIIC(ucslave, uireg, &uiTempData, 0x1632);
		ui64data	=	uiTempData;
	}
	else if(bCurrent)
	{
		unsigned long long uiTempData;
		iresult	=	classPlatform.HisFX3ReadI2C(ucslave, uireg, &uiTempData, ustype);
		ui64data	=	uiTempData;
	}
	else
		iresult	=	globalFunPointer.ReadHisFX3IIC(ucslave, uireg, &ui64data, ustype);

	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("读取失败"));
		return;
	}

	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("读取成功"));
	ui.datalineEdit->setText(QString::number(ui64data, 16));
}

void hardwareop::writei2c()
{
	unsigned short usspeed	=	ui.i2cspeedspinBox->value();

	int iresult;
	bool bSPI			=	(ui.communicatetypecomboBox->currentText() == "SPI");
	bool bOS			=	(ui.communicatetypecomboBox->currentText() == "OS IIC");
	bool bCurrent	=	(ui.communicatetypecomboBox->currentText() == "Current IIC");

	if(bSPI){
		if(iresult	=	globalFunPointer.SetHisFX3SPISpeed(usspeed)){
			showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定SPI 速率失败"));
			return;
		}
	}
	else{
		if(iresult	=	globalFunPointer.SetHisFX3IICSpeed(usspeed)){
			showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设定I2C 速率失败"));
			return;
		}
	}

	unsigned char ucslave;
	unsigned short ustype;
	unsigned int uireg;
	unsigned __int64 ui64data;
	QString strtext;

	strtext	=	ui.slavelineEdit->text();
	strtext	=	strtext.remove(" ");
	if(strtext.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能为空"));
		return;
	}

	bool bok;
	ui64data	=	0x0;
	strtext		=	strtext.toLower();
	ui64data	=	strtext.toUInt(&bok, 16);
	if(!ui64data){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能为0"));
		return;
	}
	else if(ui64data	> 0xFF){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("slave 不能大于0xff"));
		return;
	}
	ucslave	=	static_cast<unsigned char>(ui64data);

	strtext	=	ui.reglineEdit->text();
	strtext	=	strtext.remove(" ");
	if(strtext.size() < 1 && (ui.i2ctypecomboBox->currentIndex() < 6 || ui.i2ctypecomboBox->currentIndex() > 8)){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("reg 不能为空"));
		return;
	}
	strtext		=	strtext.toLower();
	uireg		=	strtext.toUInt(&bok, 16);

	strtext	=	ui.datalineEdit->text();
	strtext	=	strtext.remove(" ");
	if(strtext.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("data 不能为空"));
		return;
	}
	strtext			=	strtext.toLower();
	ui64data		=	strtext.toULongLong(&bok, 16);
	
	switch (ui.i2ctypecomboBox->currentIndex()){
	case 0:
		ustype	=	0x0808;
		break;
	case 1:
		ustype	=	0x0816;
		break;
	case 2:
		ustype	=	0x1608;
		break;
	case 3:
		ustype	=	0x1616;
		break;
	case 4:
		ustype	=	0x1632;
		break;
	case 5:
		ustype	=	0x1664;
		break;
	case 6:
		ustype	=	0x0864;
		break;
	case 7:
		ustype	=	0x0008;
		break;
	case 8:
		ustype	=	0x0016;
		break;
	case 9:
		ustype	=	0x0032;
		break;
	default:
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("I2C 读取类型选择不正确"));
		return;
		break;
	}

#ifdef _HisFX3_Platform_SUBLVDS
	funsetprotocal(bSPI?_HisFX3_CommProtocal_SPI:_HisFX3_CommProtocal_I2C);
#endif

	if(bSPI)
		iresult	=	globalFunPointer.HisFX3WriteSPI(ucslave, uireg, ui64data, ustype, ui.spiCSLowcheckBox->isChecked(), ui.spiLittleEndiancheckBox->isChecked());
	else if(bOS)
		iresult	=	classPlatform.HisFX3WriteOSIIC(ucslave, uireg, ui64data, 0x1632);
	else if(bCurrent)
		iresult	=	classPlatform.HisFX3WriteIIC(ucslave, uireg, ui64data, ustype);
	else
		iresult	=	globalFunPointer.WriteHisFX3IIC(ucslave, uireg, ui64data, ustype, true);

	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("写入I2C 失败"));
	}
	else{
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("写入I2C 成功"));
	}
}

void hardwareop::batchwritei2c()
{
	if(ui.batchIICModecomboBox->currentIndex() == 1)
		batchwritei2c_Hardware();
	else if(ui.batchIICModecomboBox->currentIndex() == 0)
		batchwritei2c_NotHardware();
}

void hardwareop::batchwritei2c_Hardware()
{
	QString strtext	=	ui.plainTextEdit->toPlainText();
	if(strtext.size() < 9){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不正确"));
		return;
	}

	QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
	if(lines.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不够"));
		return;
	}

	unsigned int uiCount	=	lines.size();
	unsigned char ucSlaveList[8192];
	unsigned int uiRegList[8192];
	unsigned int uiDataList[8192];
	unsigned short usTypeList[8192];

	QStringList strlist1;
	QString strdata, strtemp;
	unsigned char ucslave;
	unsigned int uireg;
	unsigned int uidata;
	unsigned short ustype;
	bool bok;
	QElapsedTimer classTime;
	classTime.start();

	for(int i=0;	i<uiCount;	++i)
	{
		strdata	=	lines.at(i);
		strlist1	=	strdata.split(",", QString::SkipEmptyParts);
		if(strlist1.size() != 4){
			showinformation(strdata % (QTextCodec::codecForName( "GBK")->toUnicode("格式不正确")));
			return;
		}

		for(int j=0;	j<4;	++j){
			strtemp	=	strlist1.at(j);
			strtemp	=	strtemp.remove(" ");
			strtemp	=	strtemp.remove("\r");
			strtemp	=	strtemp.remove("\t");
			strtemp	=	strtemp.toLower();
			strtemp	=	strtemp.remove("0x");
			if(strtemp.size() < 1){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
				return;
			}

			switch (j){
			case 0:
				ucslave	=	strtemp.toUInt(&bok, 16);
				break;
			case 1:
				uireg	=	strtemp.toUInt(&bok, 16);
				break;
			case 2:
				uidata	=	strtemp.toUInt(&bok, 16);
				break;
			case 3:
			default:
				ustype	=	strtemp.toUShort(&bok, 16);
				if(ustype != 0x1608 && ustype != 0x1616 && ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1632){
					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
					return;
				}
				break;
			}
		}

		ucSlaveList[i]	=	ucslave;
		uiRegList[i]		=	uireg;
		uiDataList[i]	=	uidata;
		usTypeList[i]	=	ustype;
	}

	int iresult	=	globalFunPointer.BatchWriteHisFX3IICNoLimit(uiCount, ucSlaveList, uiRegList, uiDataList, usTypeList, ui.batchDelayspinBox->value());
	if(iresult){
		showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("批量写入失败"));
		return;
	}

	showinformation(tr("Write Success") % "(" % QString::number(classTime.elapsed()) % "ms)");
}

void hardwareop::batchwritei2c_NotHardware()
{
	QString strtext	=	ui.plainTextEdit->toPlainText();
	if(strtext.size() < 9){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不正确"));
		return;
	}

	QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
	if(lines.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不够"));
		return;
	}

	QStringList strlist1;
	QString strdata, strtemp;
	unsigned char ucslave;
	unsigned int uireg;
	unsigned int uidata;
	unsigned short ustype;
	bool bok;

	QElapsedTimer classTime;
	classTime.start();

	int isize	=	lines.size();
	for(int i=0;	i<isize;	++i){
		strdata	=	lines.at(i);
		strlist1	=	strdata.split(",", QString::SkipEmptyParts);
		if(strlist1.size() != 4){
			showinformation(strdata % (QTextCodec::codecForName( "GBK")->toUnicode("格式不正确")));
			return;
		}

		for(int j=0;	j<4;	++j){
			strtemp	=	strlist1.at(j);
			strtemp	=	strtemp.remove(" ");
			strtemp	=	strtemp.remove("\r");
			strtemp	=	strtemp.remove("\t");
			strtemp	=	strtemp.toLower();
			strtemp	=	strtemp.remove("0x");
			if(strtemp.size() < 1){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
				return;
			}

			switch (j){
			case 0:
				ucslave	=	strtemp.toUInt(&bok, 16);
// 				if(!ucslave){
// 					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
// 					return;
// 				}
				break;
			case 1:
				uireg	=	strtemp.toUInt(&bok, 16);
				break;
			case 2:
				uidata	=	strtemp.toUInt(&bok, 16);
				break;
			case 3:
			default:
				ustype	=	strtemp.toUShort(&bok, 16);
				if(ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1608 && ustype != 0x1616 && ustype != 0x1632){
					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
					return;
				}
				break;
			}
		}

		if(ucslave){
			int iresult;
// 			iresult	=	globalFunPointer.WriteHisFX3IIC(ucslave, uireg, uidata, ustype, true);
			if(ui.batchProtocalcomboBox->currentText() == "SPI")
				iresult	=	classPlatform.HisFX3WriteSPI(ucslave, uireg, uidata, ustype);
			else
				iresult	=	globalFunPointer.WriteHisFX3IIC(ucslave, uireg, uidata, ustype, true);
			if(iresult){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("写入失败"));
				return;
			}
		}
		else
			::Sleep(uidata);
	}

	showinformation(tr("Write Success") % "(" % QString::number(classTime.elapsed()) % "ms)");
}

void hardwareop::batchreadi2c()
{
	if(ui.batchIICModecomboBox->currentIndex() == 1)
		batchreadi2c_Hardware();
	else if(ui.batchIICModecomboBox->currentIndex() == 0)
		batchreadi2c_NotHardware();
}

void hardwareop::batchreadi2c_Hardware()
{
	QString strtext	=	ui.plainTextEdit->toPlainText();
	if(strtext.size() < 9){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不正确"));
		return;
	}

	QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
	if(lines.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不够"));
		return;
	}

	unsigned int uiCount	=	lines.size();
	unsigned char ucSlaveList[8192];
	unsigned int uiRegList[8192];
	unsigned int uiDataList[8192];
	unsigned short usTypeList[8192];

	QStringList strlistresult;
	QStringList strlist1;
	QString strdata, strtemp;
	unsigned char ucslave;
	unsigned int uireg;
	//unsigned int uidata;
	unsigned short ustype;
	bool bok;

	QElapsedTimer classTime;
	classTime.start();

	for(int i=0;	i<uiCount;	++i){
		strdata	=	lines.at(i);
		strlist1	=	strdata.split(",", QString::SkipEmptyParts);
		if(strlist1.size() != 4 && strlist1.size() != 3){
			showinformation(strdata % (QTextCodec::codecForName( "GBK")->toUnicode("格式不正确")));
			return;
		}

		for(int j=0;	j<strlist1.size();	++j){
			strtemp	=	strlist1.at(j);
			strtemp	=	strtemp.remove(" ");
			strtemp	=	strtemp.remove("\r");
			strtemp	=	strtemp.remove("\t");
			strtemp	=	strtemp.toLower();
			strtemp	=	strtemp.remove("0x");
			if(strtemp.size() < 1){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
				return;
			}

			switch (j){
			case 0:
				ucslave	=	strtemp.toUInt(&bok, 16);
				break;
			case 1:
				uireg	=	strtemp.toUInt(&bok, 16);
				break;
			case 2:
				if(strlist1.size() == 3){
					ustype	=	strtemp.toUShort(&bok, 16);
					if(ustype != 0x1608 && ustype != 0x1616 && ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1632){
						showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
						return;
					}
				}
				break;
			case 3:
			default:
				ustype	=	strtemp.toUShort(&bok, 16);
				if(ustype != 0x1608 && ustype != 0x1616 && ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1632){
					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
					return;
				}
				break;
			}
		}

		ucSlaveList[i]	=	ucslave;
		uiRegList[i]		=	uireg;
		usTypeList[i]	=	ustype;
	}

	int iresult	=	globalFunPointer.BatchReadHisFX3IICNoLimit(uiCount, ucSlaveList, uiRegList, uiDataList, usTypeList, ui.batchDelayspinBox->value());
	if(iresult){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量读取失败"));
		return;
	}

	for(int i=0;	i<uiCount;	++i){
		strlist1.clear();
		strlist1.append("0x" % QString::number(static_cast<qulonglong>(ucSlaveList[i]), 16));
		strlist1.append("0x" % QString::number(static_cast<qulonglong>(uiRegList[i]), 16));
		strlist1.append("0x" % QString::number(static_cast<qulonglong>(uiDataList[i]), 16));
		strlist1.append("0x" % QString::number(static_cast<qulonglong>(usTypeList[i]), 16));
		strdata	=	strlist1.join(",");
		strlistresult.append(strdata);
	}

	strdata	=	strlistresult.join("\n");
	ui.plainTextEdit->setPlainText(strdata);

	showinformation("Read Success(" % QString::number(classTime.elapsed()) % "ms)");
}

void hardwareop::batchreadi2c_NotHardware()
{
	QString strtext	=	ui.plainTextEdit->toPlainText();
	if(strtext.size() < 9){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不正确"));
		return;
	}

	QStringList lines = strtext.split("\n", QString::SkipEmptyParts);
	if(lines.size() < 1){
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("批量数据不够"));
		return;
	}

	QStringList strlist1;
	QStringList strlistresult;
	QString strdata, strtemp;
	unsigned char ucslave;
	unsigned int uireg;
	unsigned __int64 uidata;
	unsigned short ustype;
	bool bok;

	QElapsedTimer classTime;
	classTime.start();

	int isize	=	lines.size();
	for(int i=0;	i<isize;	++i)
	{
		strdata	=	lines.at(i);
		strlist1	=	strdata.split(",", QString::SkipEmptyParts);
		if(strlist1.size() != 4 && strlist1.size() != 3){
			showinformation(strdata % (QTextCodec::codecForName( "GBK")->toUnicode("格式不正确")));
			return;
		}

		for(int j=0;	j<strlist1.size();	++j){
			strtemp	=	strlist1.at(j);
			strtemp	=	strtemp.remove(" ");
			strtemp	=	strtemp.remove("\r");
			strtemp	=	strtemp.remove("\t");
			strtemp	=	strtemp.toLower();
			strtemp	=	strtemp.remove("0x");
			if(strtemp.size() < 1){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
				return;
			}

			switch (j){
			case 0:
				ucslave	=	strtemp.toUInt(&bok, 16);
				// 				if(!ucslave){
				// 					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
				// 					return;
				// 				}
				break;
			case 1:
				uireg	=	strtemp.toUInt(&bok, 16);
				break;
			case 2:
				if(strlist1.size() == 3){
					ustype	=	strtemp.toUShort(&bok, 16);
					if(ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1608 && ustype != 0x1616 && ustype != 0x1632){
						showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
						return;
					}
				}
				break;
			case 3:
			default:
				ustype	=	strtemp.toUShort(&bok, 16);
				if(ustype != 0x0808 && ustype != 0x0816 && ustype != 0x1608 && ustype != 0x1616 && ustype != 0x1632){
					showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("格式不正确"));
					return;
				}
				break;
			}
		}

		if(ucslave){
			int iresult	=	globalFunPointer.ReadHisFX3IIC(ucslave, uireg, &uidata, ustype);
			if(iresult){
				showinformation(strdata % QTextCodec::codecForName( "GBK")->toUnicode("读取失败"));
				return;
			}
			strlist1.clear();
			strlist1.append("0x" % QString::number(static_cast<qulonglong>(ucslave), 16));
			strlist1.append("0x" % QString::number(static_cast<qulonglong>(uireg), 16));
			strlist1.append("0x" % QString::number(static_cast<qulonglong>(uidata), 16));
			strlist1.append("0x" % QString::number(static_cast<qulonglong>(ustype), 16));
			strdata	=	strlist1.join(",");
			strlistresult.append(strdata);
		}
	}

	strdata	=	strlistresult.join("\n");
	ui.plainTextEdit->setPlainText(strdata);

	showinformation("Read Success(" % QString::number(classTime.elapsed()) % "ms)");
}

void hardwareop::slotBatchTest()
{
	if(ui.batchEETypecomboBox->currentText() == "DW9807")
	{

	}
}

void hardwareop::showinformation(QString strinfo)
{
	ui.infolabel->setText(strinfo);
}

void hardwareop::seti2cinfo(unsigned char ucslave, unsigned short ustype)
{
	ui.slavelineEdit->setText(QString::number(static_cast<unsigned int>(ucslave), 16));
	switch (ustype){
	case 0x0808:
		ui.i2ctypecomboBox->setCurrentIndex(0);
		break;
	case 0x0816:
		ui.i2ctypecomboBox->setCurrentIndex(1);
		break;
	case 0x1608:
		ui.i2ctypecomboBox->setCurrentIndex(2);
		break;
	case 0x1616:
		ui.i2ctypecomboBox->setCurrentIndex(3);
		break;
	case 0x1632:
		ui.i2ctypecomboBox->setCurrentIndex(4);
		break;
	default:
		ui.i2ctypecomboBox->setCurrentIndex(-1);
		break;
	}
}

void hardwareop::changgpio0(int state)
{
	int iresult	=	0;
	if(bBoxChannel1)
		iresult	=	classPlatform.HisFX3IO_OutPortWrite((state == Qt::Checked)?(0x01):(0x00), 0x01);
	else
		iresult	=	classPlatform.HisFX3IO_OutPortWrite_S2((state == Qt::Checked)?(0x01):(0x00), 0x01);
	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 成功"));
}

void hardwareop::changgpio1(int state)
{
	int iresult	=	0;
	if(bBoxChannel1)
		iresult	=	classPlatform.HisFX3IO_OutPortWrite((state == Qt::Checked)?(0x02):(0x00), 0x02);
	else
		iresult	=	classPlatform.HisFX3IO_OutPortWrite_S2((state == Qt::Checked)?(0x02):(0x00), 0x02);
	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 成功"));
}

void hardwareop::changgpio2(int state)
{
	int iresult	=	0;
	if(bBoxChannel1)
		iresult	=	classPlatform.HisFX3IO_OutPortWrite((state == Qt::Checked)?(0x04):(0x00), 0x04);
	else
		iresult	=	classPlatform.HisFX3IO_OutPortWrite_S2((state == Qt::Checked)?(0x04):(0x00), 0x04);
	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 成功"));
}

void hardwareop::changgpio3(int state)
{
	int iresult	=	0;
	if(bBoxChannel1)
		iresult	=	classPlatform.HisFX3IO_OutPortWrite((state == Qt::Checked)?(0x08):(0x00), 0x08);
	else
		iresult	=	classPlatform.HisFX3IO_OutPortWrite_S2((state == Qt::Checked)?(0x08):(0x00), 0x08);
	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("设置GPIO 成功"));
}

void hardwareop::readGPIOStatus()
{
	unsigned int uiStatus;
	int iresult;
	if(bBoxChannel1)
		iresult	=	classPlatform.HisFX3IO_InPortRead(uiStatus, 0xFF);
	else
		iresult	=	classPlatform.HisFX3IO_InPortRead_S2(uiStatus, 0xFF);

	if(iresult)	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取GPIO 失败"));
	else	showinformation(QTextCodec::codecForName( "GBK")->toUnicode("获取GPIO 成功"));

	if(!iresult)
	{
		ui.GPIOIn0checkBox->setChecked(uiStatus & 0x01);
		ui.GPIOIn1checkBox->setChecked(uiStatus & 0x02);
	}
}


void hardwareop::searchSlave()
{
	if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("搜索设备地址"), \
		QTextCodec::codecForName( "GBK")->toUnicode("如果您已经设置好正确的电压和MCLK.\n并且确定要执行搜索，请选择\"是\""), \
		QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
	{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("正在搜索，请等待..."));
		QVector<unsigned char> vectorP1R1;
		QVector<unsigned char> vectorP1R0;
		QVector<unsigned char> vectorP0R0;
		QVector<unsigned char> vectorP0R1;
		QVector<unsigned char>* pVector;
		bool bPWDN, bRESET;
		for(unsigned int y=0;	y<4;	++y){
			switch(y){
			case 0:
				bPWDN	=	true;
				bRESET	=	true;
				pVector	=	&vectorP1R1;
				break;
			case 1:
				bPWDN	=	true;
				bRESET	=	false;
				pVector	=	&vectorP1R0;
				break;
			case 2:
				bPWDN	=	false;
				bRESET	=	false;
				pVector	=	&vectorP0R0;
				break;
			case 3:
			default:
				bPWDN	=	false;
				bRESET	=	true;
				pVector	=	&vectorP0R1;
				break;
			}

			globalFunPointer.PullHisFX3RESET(bRESET);
			::Sleep(50);
			globalFunPointer.PullHisFX3PWND(bPWDN);
			::Sleep(50);

			for(unsigned int x=1;	x<256;	x+=2){
				if(!globalFunPointer.GetHisFX3SlaveResponse(x))		pVector->push_back((unsigned char)(x));
			}
		}

		unsigned int uiMax	=	0;
		if(vectorP0R0.size() > uiMax){
			uiMax	=	vectorP0R0.size();
			bPWDN	=	false;
			bRESET	=	false;
			pVector	=	&vectorP0R0;
		}
		if(vectorP0R1.size() > uiMax){
			uiMax	=	vectorP0R1.size();
			bPWDN	=	false;
			bRESET	=	true;
			pVector	=	&vectorP0R1;
		}
		if(vectorP1R0.size() > uiMax){
			uiMax	=	vectorP1R0.size();
			bPWDN	=	true;
			bRESET	=	false;
			pVector	=	&vectorP1R0;
		}
		if(vectorP1R1.size() > uiMax){
			uiMax	=	vectorP1R1.size();
			bPWDN	=	true;
			bRESET	=	true;
			pVector	=	&vectorP1R1;
		}

		if(!uiMax){
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("搜索结果"), \
				QTextCodec::codecForName( "GBK")->toUnicode("抱歉，没有搜索到任何有效设备地址\n\n请确认电压和MCLK是否正常配置!!!"));
			return;
		}

		unsigned int uiCount	=	0;
		if(vectorP0R0.size() == uiMax) ++uiCount;
		if(vectorP0R1.size() == uiMax) ++uiCount;
		if(vectorP1R0.size() == uiMax) ++uiCount;
		if(vectorP1R1.size() == uiMax) ++uiCount;

		if(uiCount < 3){
			QString strText, strPWND, strRESET;
			for(unsigned int x=0;	x<pVector->size(); ++x)
				strText	=	strText % "0x" % QString::number((pVector->at(x) & 0xFE), 16) % ", ";
			strText	=	QTextCodec::codecForName( "GBK")->toUnicode("有效设备地址：\n") % strText;
			ui.infolabel->setText(strText);
			if(bPWDN)	strPWND	=	QTextCodec::codecForName( "GBK")->toUnicode("PWDN--低电平有效");
			else	strPWND	=	QTextCodec::codecForName( "GBK")->toUnicode("PWDN--高电平有效");
			if(bRESET)	strRESET	=	QTextCodec::codecForName( "GBK")->toUnicode("RESET--低电平有效");
			else	strRESET	=	QTextCodec::codecForName( "GBK")->toUnicode("RESET--高电平有效");
			strText	=	strText % strPWND % strRESET;
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("搜索结果"), strText);
		}
		else{
			QString strText;
			for(unsigned int x=0;	x<pVector->size(); ++x)
				strText	=	strText % "0x" % QString::number((pVector->at(x) & 0xFE), 16) % ", ";
			strText	=	QTextCodec::codecForName( "GBK")->toUnicode("有效设备地址：\n") % strText;
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("搜索结果"), strText);
			ui.infolabel->setText(strText);
		}
	}
}

void hardwareop::openBIN()
{
	int iAddrByte = 2, iDataByte = 1;
	if(ui.binTypecomboBox->currentText() == "0x0808"){
		iAddrByte	=	1;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x0816"){
		iAddrByte	=	1;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1608"){
		iAddrByte	=	2;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1616"){
		iAddrByte	=	2;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1632"){
		iAddrByte	=	2;
		iDataByte	=	4;
	}

	QString strPath	=	QFileDialog::getOpenFileName(NULL, "OPEN BIN", "/home", "BIN(*.bin)");
	showinformation(strPath);
	if(strPath.contains(".bin", Qt::CaseInsensitive)){
		FILE*hFile	=	fopen(strPath.toAscii().data(), "rb");
		if(hFile != NULL){
			unsigned int* puiAddr			=	new unsigned int[10240];
			unsigned char* pucRead		=	new unsigned char[10240];
			unsigned int* puiData			=	new unsigned int[10240];
			unsigned int uiIICCount	=	0;
			uiIICCount	=	fread(pucRead,sizeof(unsigned char),10240,hFile);
			if(uiIICCount){
				ui.binCountspinBox->setValue(uiIICCount);
				unsigned int uiStartAddr	=	ui.binRegStartlineEdit->text().toUInt(0, 16);
				unsigned int uiRegAdd	=	ui.binRegAddspinBox->value();
				for(unsigned int x=0;	x<uiIICCount;	++x)
					puiAddr[x]	=	uiStartAddr + uiRegAdd *x;

				if(iDataByte == 4){
					uiIICCount /=	4;
					for(unsigned int x=0;	x<uiIICCount;	++x){
						puiData[x]	=	pucRead[x*4] *16777216 + pucRead[x*4+1] *65536 + pucRead[x*4+2] *256 + pucRead[x*4+3];
					}
				}
				else if(iDataByte == 2){
					uiIICCount /=	2;
					for(unsigned int x=0;	x<uiIICCount; ++x){
						puiData[x]	=	pucRead[x*2] *256 + pucRead[x*2+1];
					}
				}
				else{
					for(unsigned int x=0;	x<uiIICCount;	++x){
						puiData[x]	=	pucRead[x];
					}
				}
				toBinPainText(puiAddr, puiData, uiIICCount);
			}
			HisReleaseNewB(puiAddr);
			HisReleaseNewB(pucRead);
			HisReleaseNewB(puiData);
			fclose(hFile);
		}
	}
}

void hardwareop::saveBIN()
{
	int iAddrByte = 2, iDataByte = 1;
	if(ui.binTypecomboBox->currentText() == "0x0808"){
		iAddrByte	=	1;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x0816"){
		iAddrByte	=	1;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1608"){
		iAddrByte	=	2;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1616"){
		iAddrByte	=	2;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1632"){
		iAddrByte	=	2;
		iDataByte	=	4;
	}

	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];
	unsigned char* pucWrite	=	new unsigned char[10240];

	unsigned int uiIICCount	=	0;
	analysisBinPainText(puiAddr, puiData, uiIICCount);
	if(!uiIICCount){
		HisReleaseNewB(puiAddr);
		HisReleaseNewB(puiData);
		HisReleaseNewB(pucWrite);
		return;
	}

	if(iDataByte == 4){
		for(unsigned int x=0;	x<uiIICCount;	++x){
			pucWrite[x*4]		=	(puiData[x] >>24) & 0xFF;
			pucWrite[x*4+1]		=	(puiData[x] >>16) & 0xFF;
			pucWrite[x*4+2]		=	(puiData[x] >>8) & 0xFF;
			pucWrite[x*4+3]	=	puiData[x] & 0xFF;
		}
		uiIICCount	*=	4;
	}
	else if(iDataByte == 2){
		for(unsigned int x=0;	x<uiIICCount;	++x){
			pucWrite[x*2]		=	(puiData[x] >>8) & 0xFF;
			pucWrite[x*2+1]	=	puiData[x] & 0xFF;
		}
		uiIICCount	*=	2;
	}
	else{
		for(unsigned int x=0;	x<uiIICCount;	++x){
			pucWrite[x]	=	puiData[x];
		}
	}

	QString strPath	=	QFileDialog::getSaveFileName(NULL, "SAVE BIN", "/home", "BIN(*.bin)");
	showinformation(strPath);
	if(strPath.contains(".bin", Qt::CaseInsensitive)){
		FILE*hFile	=	fopen(strPath.toAscii().data(), "wb");
		if(hFile != NULL){
			fwrite(pucWrite, sizeof(unsigned char), uiIICCount, hFile);
			fclose(hFile);
		}
	}

	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
	HisReleaseNewB(pucWrite);
}

void hardwareop::writeBIN()
{
	unsigned short usType	=	0x1608;
	int iAddrByte = 2, iDataByte = 1;
	if(ui.binTypecomboBox->currentText() == "0x0808"){
		iAddrByte	=	1;
		iDataByte	=	1;
		usType	=	0x0808;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x0816"){
		iAddrByte	=	1;
		iDataByte	=	2;
		usType	=	0x0816;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1608"){
		iAddrByte	=	2;
		iDataByte	=	1;
		usType	=	0x1608;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1616"){
		iAddrByte	=	2;
		iDataByte	=	2;
		usType	=	0x1616;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1632"){
		iAddrByte	=	2;
		iDataByte	=	4;
		usType	=	0x1632;
	}

	unsigned char ucSlave	=	ui.binSlavelineEdit->text().toUInt(0, 16);
	if(!ucSlave){
		return;
	}

	unsigned short usDelay	=	ui.binDelayspinBox->value();

	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];
	unsigned char* pucSlave	=	new unsigned char[10240];
	unsigned short* pusType	=	new unsigned short[10240];

	unsigned int uiIICCount	=	0;
	analysisBinPainText(puiAddr, puiData, uiIICCount);
	if(!uiIICCount){
		HisReleaseNewB(puiAddr);
		HisReleaseNewB(puiData);
		HisReleaseNewB(pucSlave);
		HisReleaseNewB(pusType);
		return;
	}

	for(unsigned int x=0;	x<uiIICCount;	++x){
		pucSlave[x]	=	ucSlave;
		pusType[x]	=	usType;
	}

	int iresult	=	globalFunPointer.BatchWriteHisFX3IICNoLimit(uiIICCount, pucSlave, puiAddr, puiData, pusType, usDelay);
	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
	HisReleaseNewB(pucSlave);
	HisReleaseNewB(pusType);

	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("写入IIC失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("写入IIC成功"));
}

void hardwareop::readBIN()
{
	unsigned short usType	=	0x1608;
	int iAddrByte = 2, iDataByte = 1;
	if(ui.binTypecomboBox->currentText() == "0x0808"){
		iAddrByte	=	1;
		iDataByte	=	1;
		usType	=	0x0808;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x0816"){
		iAddrByte	=	1;
		iDataByte	=	2;
		usType	=	0x0816;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1608"){
		iAddrByte	=	2;
		iDataByte	=	1;
		usType	=	0x1608;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1616"){
		iAddrByte	=	2;
		iDataByte	=	2;
		usType	=	0x1616;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1632"){
		iAddrByte	=	2;
		iDataByte	=	4;
		usType	=	0x1632;
	}

	unsigned char ucSlave	=	ui.binSlavelineEdit->text().toUInt(0, 16);
	if(!ucSlave){
		return;
	}

	unsigned short usDelay	=	ui.binDelayspinBox->value();
	unsigned int uiIICCount	=	ui.binCountspinBox->value();
	if(!uiIICCount || uiIICCount > 10240){
		return;
	}

	unsigned int uiStartAddr	=	ui.binRegStartlineEdit->text().toUInt(0, 16);

	unsigned int uiRegAdd	=	ui.binRegAddspinBox->value();

	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];
	unsigned char* pucSlave	=	new unsigned char[10240];
	unsigned short* pusType	=	new unsigned short[10240];

	for(unsigned int x=0;	x<uiIICCount;	++x){
		pucSlave[x]	=	ucSlave;
		pusType[x]	=	usType;
		puiAddr[x]	=	uiStartAddr + x *uiRegAdd;
	}

	int iresult	=	globalFunPointer.BatchReadHisFX3IICNoLimit(uiIICCount, pucSlave, puiAddr, puiData, pusType, usDelay);
	if(iresult)
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("读取IIC失败"));
	else
		showinformation(QTextCodec::codecForName( "GBK")->toUnicode("读取IIC成功"));


	toBinPainText(puiAddr, puiData, uiIICCount);

	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
	HisReleaseNewB(pucSlave);
	HisReleaseNewB(pusType);
}

void hardwareop::analysisBinPainText(unsigned int* puiAddr, unsigned int* puiData, unsigned int& uiCount)
{
	uiCount	=	0;
	QString strtext	=	ui.binplainTextEdit->toPlainText();
	QStringList lines = strtext.split("\n", QString::SkipEmptyParts);

	QStringList strlist1;
	QString strdata, strtemp;
	unsigned int uireg, uidata;

	for(int i=0;	i<lines.size();	++i){
		strdata	=	lines.at(i);
		strlist1	=	strdata.split(",", QString::SkipEmptyParts);
		if(strlist1.size() != 2) continue;

		for(int j=0;	j<2;	++j){
			strtemp	=	strlist1.at(j);
			strtemp	=	strtemp.remove(" ");
			strtemp	=	strtemp.remove("\r");
			strtemp	=	strtemp.remove("\t");
			strtemp	=	strtemp.toLower();
			strtemp	=	strtemp.remove("0x");
			if(strtemp.size() < 1) break;

			switch (j){
			case 0:	
				uireg	=	strtemp.toUInt(0, 16);
				break;
			default:
				uidata	=	strtemp.toUInt(0, 16);
				*puiAddr	=	uireg;
				++puiAddr;
				*puiData	=	uidata;
				++puiData;
				++uiCount;
				break;
			}
		}
	}

}

void hardwareop::toBinPainText(unsigned int* puiAddr, unsigned int* puiData, unsigned int uiCount)
{
	int iAddrByte = 2, iDataByte = 1;
	if(ui.binTypecomboBox->currentText() == "0x0808"){
		iAddrByte	=	1;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x0816"){
		iAddrByte	=	1;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1608"){
		iAddrByte	=	2;
		iDataByte	=	1;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1616"){
		iAddrByte	=	2;
		iDataByte	=	2;
	}
	else 	if(ui.binTypecomboBox->currentText() == "0x1632"){
		iAddrByte	=	2;
		iDataByte	=	4;
	}

	unsigned int uiAddr, uiData;
	QString strText, strReg, strData;
	for(unsigned int x=0;	x<uiCount;	++x){
		if(iAddrByte == 2)	uiAddr	=	puiAddr[x] & 0xFFFF;
		else uiAddr	=	puiAddr[x] & 0xFF;

		if(iDataByte == 4)	uiData	=	puiData[x];
		else if(iDataByte == 2) uiData = puiData[x] & 0xFFFF;
		else uiData	=	puiData[x] & 0xFF;

		strReg	=	QString::number(uiAddr, 16);
		strData	=	QString::number(uiData, 16);
		changeHexStrLength(strReg, iAddrByte *2);
		changeHexStrLength(strData, iDataByte *2);
		strText	=	strText % "0x" % strReg % "," % "0x" % strData % "\n";
	}
	ui.binplainTextEdit->setPlainText(strText);
}

void hardwareop::binDataCreate()
{
	unsigned int uiIICCount	=	ui.binCountspinBox->value();
	if(!uiIICCount || uiIICCount > 10240){
		return;
	}

	unsigned int uiStartAddr	=	ui.binRegStartlineEdit->text().toUInt(0, 16);
	unsigned int uiRegAdd	=	ui.binRegAddspinBox->value();
	unsigned int uiData	=	0;
	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];

	for(unsigned int x=0;	x<uiIICCount;	++x){
		puiAddr[x]	=	uiStartAddr + x *uiRegAdd;
		puiData[x]	= uiData++;
	}

	toBinPainText(puiAddr, puiData, uiIICCount);

	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
}

void hardwareop::binDataCreate0()
{
	unsigned int uiIICCount	=	ui.binCountspinBox->value();
	if(!uiIICCount || uiIICCount > 10240){
		return;
	}

	unsigned int uiStartAddr	=	ui.binRegStartlineEdit->text().toUInt(0, 16);
	unsigned int uiRegAdd	=	ui.binRegAddspinBox->value();
	unsigned int uiData	=	0;
	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];

	for(unsigned int x=0;	x<uiIICCount;	++x){
		puiAddr[x]	=	uiStartAddr + x *uiRegAdd;
		puiData[x]	= 0x0;
	}

	toBinPainText(puiAddr, puiData, uiIICCount);

	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
}

void hardwareop::binDataCreate0xFF()
{
	unsigned int uiIICCount	=	ui.binCountspinBox->value();
	if(!uiIICCount || uiIICCount > 10240){
		return;
	}

	unsigned int uiStartAddr	=	ui.binRegStartlineEdit->text().toUInt(0, 16);
	unsigned int uiRegAdd	=	ui.binRegAddspinBox->value();
	unsigned int uiData	=	0;
	unsigned int* puiAddr			=	new unsigned int[10240];
	unsigned int* puiData			=	new unsigned int[10240];

	for(unsigned int x=0;	x<uiIICCount;	++x){
		puiAddr[x]	=	uiStartAddr + x *uiRegAdd;
		puiData[x]	= 0xFF;
	}

	toBinPainText(puiAddr, puiData, uiIICCount);

	HisReleaseNewB(puiAddr);
	HisReleaseNewB(puiData);
}