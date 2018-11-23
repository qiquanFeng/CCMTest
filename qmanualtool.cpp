#include "qmanualtool.h"
#include <QTextCodec>
#include <QString>
#include <QStringBuilder>
#include <QPushButton>

qmanualtool::qmanualtool(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC)
	: QDockWidget(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC)
{
	ui.setupUi(this);

	bCount=false;
	connect(ui.motorTestButton,SIGNAL(pressed()),this,SLOT(MotorTest()));
	connect(ui.motorClearCount,SIGNAL(pressed()),this,SLOT(ClearMotorCount()));
	motorThread=new thread1(this);

	luxTimer.setSingleShot(false);
	luxTimer.setInterval(200);
	if(luxTimer.isActive())
		luxTimer.stop();
	connect(&luxTimer, SIGNAL(timeout()), this, SLOT(updateExposruetime()));
	connect(ui.exposureTimehorizontalSlider, SIGNAL(sliderPressed()), this, SLOT(startUpdateExposruetime()));
	connect(ui.exposureTimehorizontalSlider, SIGNAL(sliderReleased()), this, SLOT(stopUpdateExposruetime()));
	connect(ui.exposurepushButton, SIGNAL(released()), this, SLOT(setExposreValue()));

	motorTimer.setSingleShot(false);
	motorTimer.setInterval(200);
	if(motorTimer.isActive())
		motorTimer.stop();
	connect(&motorTimer, SIGNAL(timeout()), this, SLOT(updateMotorPos()));
	connect(ui.motorhorizontalSlider, SIGNAL(sliderPressed()), this, SLOT(startUpdateMotorPos()));
	connect(ui.motorhorizontalSlider, SIGNAL(sliderReleased()), this, SLOT(stopUpdateMotorPos()));
	connect(ui.motorpushButton, SIGNAL(released()), this, SLOT(setMotorValue()));

	globalGainTimer.setSingleShot(false);
	globalGainTimer.setInterval(200);
	if(globalGainTimer.isActive())
		globalGainTimer.stop();
	connect(&globalGainTimer, SIGNAL(timeout()), this, SLOT(updateGlobalGain()));
	connect(ui.globalGainhorizontalSlider, SIGNAL(sliderPressed()), this, SLOT(startUpdateGlobalGain()));
	connect(ui.globalGainhorizontalSlider, SIGNAL(sliderReleased()), this, SLOT(stopUpdateGlobalGain()));
	connect(ui.globalGainpushButton, SIGNAL(released()), this, SLOT(setGlobalGainValue()));

	connect(ui.BeginpushButton, SIGNAL(released()), this, SLOT(startRealtime()));
	connect(ui.StoppushButton, SIGNAL(released()), this, SLOT(StopRealtime()));

	bExposureFlag = bMotorFlag = bGlobalGainFlag = false;

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32";
#endif

	getSensorAPIVersion = (RolongogetSensorAPIVersion)(strLibPath, "getSensorAPIVersion");
	getExposureTime = (RolongogetExposureTime)(QLibrary::resolve(strLibPath, "getExposureTime"));
	getMotor = (RolongogetMotor)(QLibrary::resolve(strLibPath, "getMotor"));
	setExposureTime	=	(RolongosetExposureTime)(QLibrary::resolve(strLibPath, "setExposureTime"));
	setMotor	=	(RolongosetMotor)(QLibrary::resolve(strLibPath, "setMotor"));
	getGlobalGain = (RolongogetGlobalGain)(QLibrary::resolve(strLibPath, "getGlobalGain"));
	setGlobalGain	=	(RolongosetGlobalGain)(QLibrary::resolve(strLibPath, "setGlobalGain"));

	if(!(getSensorAPIVersion && getExposureTime && getMotor && setExposureTime && \
		setMotor&& getGlobalGain && setGlobalGain)){
		ui.infolabel->setText(tr("Resolve HisCCMSensor DLL Function Fail"));
	}
	else
	{
		unsigned int uivalue = 0, uimin = 0, uimax =0;
		int iresult	=	getExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
			uivalue, uimin, uimax, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult){
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("获取当前曝光值失败"));
			bExposureFlag		=	false;
		}
		else{
			bExposureFlag		=	true;
			ui.exposureTimehorizontalSlider->setMinimum(uimin);
			ui.exposureTimehorizontalSlider->setMaximum((uimax>20000)?(20000):(uimax));
			ui.exposureTimehorizontalSlider->setValue(uivalue);
			ui.exposurespinBox->setValue(uivalue);
		}

		int ivalue = 0, imin = 0, imax = 0;
		iresult	=	getMotor((itemshareData.ccmhardwareParameter->motortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
			(itemshareData.ccmhardwareParameter->projectname.toAscii()).data(), \
			ivalue, imin, imax, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult){
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("获取马达信息失败"));
			bMotorFlag		=	false;
		}
		else{
			bMotorFlag		=	true;
			ui.motorhorizontalSlider->setMinimum(imin);
			ui.motorhorizontalSlider->setMaximum(imax);
			ui.motorhorizontalSlider->setValue(ivalue);
			ui.motorspinBox->setValue(ivalue);
		}

		float flGain, flMin,  flMax;
		iresult	=	getGlobalGain((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
			flGain, flMin, flMax, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult){
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("获取Global GAIN信息失败"));
			bGlobalGainFlag		=	false;
		}
		else
		{
			bGlobalGainFlag		=	true;
			ui.globalGainhorizontalSlider->setMinimum(flMin * 100.0);
			ui.globalGainhorizontalSlider->setMaximum(flMax *100.0);
			ui.globalGainhorizontalSlider->setValue(flGain *100.0);
			ui.globalGaindoubleSpinBox->setMinimum(flMin);
			ui.globalGaindoubleSpinBox->setMaximum(flMax);
			ui.globalGaindoubleSpinBox->setValue(flGain);
		}
	}
	
	ui.LeftspinBox->setValue(static_cast<int>(itemshareData.previewParameter->iWidth/2 -100));
	ui.RightspinBox->setValue(static_cast<int>(itemshareData.previewParameter->iWidth/2 +100));
	ui.TopspinBox->setValue(static_cast<int>(itemshareData.previewParameter->iHeight/2 -100));
	ui.BottomspinBox->setValue(static_cast<int>(itemshareData.previewParameter->iHeight/2 +100));
}

qmanualtool::~qmanualtool()
{
	emit stopLuxMonitor();

	if(luxTimer.isActive())
		luxTimer.stop();
	if(motorTimer.isActive())
		motorTimer.stop();
	if(globalGainTimer.isActive())
		globalGainTimer.stop();
}

void qmanualtool::setExposreValue()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bExposureFlag		=	false;
		return;
	}

	if(!bExposureFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	unsigned int uivalue	=	ui.exposurespinBox->value();
	ui.exposureTimehorizontalSlider->setValue(uivalue);
	int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
		uivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(uivalue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(uivalue));
	}
}

void qmanualtool::updateExposruetime()
{
	unsigned int uivalue	=	ui.exposureTimehorizontalSlider->value();
	ui.exposurespinBox->setValue(uivalue);
	int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
		uivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(uivalue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(uivalue));
	}
}

void qmanualtool::startUpdateExposruetime()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bExposureFlag		=	false;
		return;
	}

	if(!bExposureFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	luxTimer.start();
}

void qmanualtool::stopUpdateExposruetime()
{
	if(bExposureFlag){
		if(luxTimer.isActive())
			luxTimer.stop();

		QTimer::singleShot(500, this, SLOT(updateExposruetime()));
	}
}

void qmanualtool::setMotorValue()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bMotorFlag		=	false;
		return;
	}

	if(!bMotorFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	int ivalue	=	ui.motorspinBox->value();
	ui.motorhorizontalSlider->setValue(ivalue);
	int iresult	=	setMotor((itemshareData.ccmhardwareParameter->motortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
		(itemshareData.ccmhardwareParameter->projectname.toAscii()).data(), \
		ivalue,globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置失败: ") % QString::number(ivalue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置成功: ") % QString::number(ivalue));
	}
}

void qmanualtool::updateMotorPos()
{
	int ivalue	=	ui.motorhorizontalSlider->value();
	ui.motorspinBox->setValue(ivalue);
	int iresult	=	setMotor((itemshareData.ccmhardwareParameter->motortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
		(itemshareData.ccmhardwareParameter->projectname.toAscii()).data(), \
		ivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置失败: ") % QString::number(ivalue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置成功: ") % QString::number(ivalue));
	}
}

void qmanualtool::startUpdateMotorPos()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bMotorFlag		=	false;
		return;
	}

	if(!bMotorFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	motorTimer.start();
}

void qmanualtool::stopUpdateMotorPos()
{
	if(bMotorFlag){
		if(motorTimer.isActive())
			motorTimer.stop();

		QTimer::singleShot(500, this, SLOT(updateMotorPos()));
	}
}

void qmanualtool::setGlobalGainValue()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		return;
	}

	if(!bGlobalGainFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	float flvalue	=	ui.globalGaindoubleSpinBox->value();
	ui.globalGainhorizontalSlider->setValue(flvalue *100.0);
	int iresult	=	setGlobalGain((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave,  \
		flvalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定Global GAIN失败: ") % QString::number(flvalue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定Global GAIN成功: ") % QString::number(flvalue));
	}
}

void qmanualtool::updateGlobalGain()
{
	int ivalue		=	ui.globalGainhorizontalSlider->value();
	float flValue	=	ivalue *0.01;
	ui.globalGaindoubleSpinBox->setValue(flValue);
	int iresult	=	setGlobalGain((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave,  \
		flValue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定Global GAIN失败: ") % QString::number(flValue));
	}
	else{
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定Global GAIN成功: ") % QString::number(flValue));
	}
}

void qmanualtool::startUpdateGlobalGain()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		return;
	}

	if(!bGlobalGainFlag){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未成功获取参考值"));
		return;
	}

	globalGainTimer.start();
}

void qmanualtool::stopUpdateGlobalGain()
{
	if(bGlobalGainFlag)
	{
		if(globalGainTimer.isActive())
			globalGainTimer.stop();

		QTimer::singleShot(500, this, SLOT(updateGlobalGain()));
	}
}

 void qmanualtool::luxMonitorResult(float flY,float flR, float flG, float flB, float flR2G, float flB2G, float flMTF)
 {
	ui.YLabelInfo->setText(QString::number(flY, 'f', 3));
	ui.RLabelInfo->setText(QString::number(flR, 'f', 3));
	ui.GLabelInfo->setText(QString::number(flG, 'f', 3));
	ui.BLabelInfo->setText(QString::number(flB, 'f', 3));
	ui.R2GLabelInfo->setText(QString::number(flR2G, 'f', 3));
	ui.B2GLabelInfo->setText(QString::number(flB2G, 'f', 3));
	ui.MTFLabelInfo->setText(QString::number(flMTF, 'f', 3));
 }

 void qmanualtool::startRealtime()
 {
	 unsigned int uiTop =0,uiBottom =0, uiLeft	=0, uiRight	=0;
	 unsigned int uiTimer	=	200;
	 unsigned int uiFlag	=	0;
	 ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode \
		 ("   "));
	 if (ui.ColorcheckBox->isChecked() == false && ui.MtfcheckBox->isChecked() == false \
		 && ui.BrightnesscheckBox->isChecked() == false)
	 {
		 ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode \
			 ("请至少勾选 亮度 解析力 颜色其中一项"));
	 }
	 uiTop	=	ui.TopspinBox->value();
	 uiBottom	=	ui.BottomspinBox->value();
	 uiLeft	=	ui.LeftspinBox->value();
	 uiRight	=	ui.RightspinBox->value();
	 if (uiTop >= uiBottom || uiLeft >= uiRight || uiTop < 0 || uiBottom <0 || \
		 uiLeft < 0 || uiRight < 0 || uiTop >= itemshareData.previewParameter->iHeight || uiBottom > itemshareData.previewParameter->iHeight || \
		 uiLeft >= itemshareData.previewParameter->iWidth || uiRight > itemshareData.previewParameter->iWidth)
	 {
		 ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode \
			 ("请正确输入ROI参数"));
		 return;
	 }
	 if (ui.ColorcheckBox->isChecked())
	 {
		 uiFlag+=	100;
	 }
	 if (ui.BrightnesscheckBox->isChecked())
	 {
		 uiFlag+=	10;
	 }
	 if (ui.MtfcheckBox->isChecked())
	 {
		 uiFlag+=	1;
	 }
	//ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("Flag: ") % QString::number(uiFlag));
	emit startLuxMonitor(uiLeft, uiRight, uiTop, uiBottom, uiTimer, uiFlag);
 }

 void qmanualtool::StopRealtime()
 {
	emit stopLuxMonitor();
 }

 void qmanualtool::MotorTest(){
	 bCount=!bCount;
	 if(bCount){
		 ui.motorTestButton->setStyleSheet("background-color:green");
	 }else{
		 ui.motorTestButton->setStyleSheet("background-color:red");
	 }

	 motorThread->start();
	 motorThread->exit();
 }

 void qmanualtool::ClearMotorCount(){
	 if(bCount){
		 ui.infolabel->setText(QString::fromLocal8Bit("请先停止计数"));
		 return ;
	 }
	 QSqlDatabase dbLotSN = QSqlDatabase::addDatabase("QSQLITE", "dbLotSN");
	 dbLotSN.setDatabaseName("JSL_OtpCount");
	 if (!dbLotSN.open()){
		 return ;
	 }

	 QSqlQuery query(dbLotSN);
	 query.prepare("update CurrentBurnLotSN set LotSN='"+QString::number(0)+"' where 1" );
	 if(!query.exec()){
		 return ;
	 }
	 ui.motorTestButton->setText(QString::number(0));
 }
 
 thread1::thread1(QObject* parent):QThread(parent){
	 moveToThread(this);
 }
 thread1::~thread1(){

 }
 void thread1::run(){
	qmanualtool *manualtool=(qmanualtool*)parent();
	_threadshareData& threadshareData= manualtool-> threadshareData;
	_global_itemexec& itemshareData= manualtool-> itemshareData;

	int nCount=0;
	 //*****  Create Database Table ***************
	QSqlDatabase dbLotSN = QSqlDatabase::addDatabase("QSQLITE", "dbLotSN");
	//dbLotSN.setDatabaseName(QDir::currentPath() + "/JSL_OtpCount");
	dbLotSN.setDatabaseName("JSL_OtpCount");
	if (!dbLotSN.open()){
		return ;
	}

	QSqlQuery query(dbLotSN);
	query.prepare("select LotSN from CurrentBurnLotSN where 1");
	if(!query.exec()){
		return ;
	}
	query.next();
	nCount=query.value(0).toInt();
	

	for (int i=0;i<200;i++)
	{
		if(!manualtool->bCount||nCount>=manualtool->ui.motorTestspinBox->value())
			return ;
#if 1
		int ivalue	=	1023;
		int iresult	=	manualtool->setMotor((itemshareData.ccmhardwareParameter->motortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
			(itemshareData.ccmhardwareParameter->projectname.toAscii()).data(), \
			ivalue,manualtool->globalFunPointer.ReadHisFX3IIC, manualtool->globalFunPointer.WriteHisFX3IIC, manualtool->globalFunPointer.SetHisFX3IICSpeed, manualtool->globalFunPointer.PullHisFX3RESET, manualtool->globalFunPointer.PullHisFX3PWND, \
			manualtool->globalFunPointer.PageWriteHisFX3IIC, manualtool->globalFunPointer.PageReadHisFX3IIC, manualtool->globalFunPointer.HisFX3PageWriteSPI, manualtool->globalFunPointer.HisFX3PageReadSPI);
		if(iresult){
			manualtool->ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置失败: ") % QString::number(ivalue));
		}
		else{
			manualtool->ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置成功: ") % QString::number(ivalue));
		}

		Sleep(1000);
		//this->sleep(1);

		ivalue	=	0;
		iresult	=	manualtool->setMotor((itemshareData.ccmhardwareParameter->motortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
			(itemshareData.ccmhardwareParameter->projectname.toAscii()).data(), \
			ivalue,manualtool->globalFunPointer.ReadHisFX3IIC, manualtool->globalFunPointer.WriteHisFX3IIC, manualtool->globalFunPointer.SetHisFX3IICSpeed, manualtool->globalFunPointer.PullHisFX3RESET, manualtool->globalFunPointer.PullHisFX3PWND, \
			manualtool->globalFunPointer.PageWriteHisFX3IIC, manualtool->globalFunPointer.PageReadHisFX3IIC, manualtool->globalFunPointer.HisFX3PageWriteSPI, manualtool->globalFunPointer.HisFX3PageReadSPI);
		
		if(iresult){
			manualtool->ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置失败: ") % QString::number(ivalue));
		}
		else{
			manualtool->ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定马达位置成功: ") % QString::number(ivalue));
		}
#endif

		Sleep(1000);
		
		query.prepare("select LotSN from CurrentBurnLotSN where 1");
		if(!query.exec()){
			return ;
		}
		query.next();
		nCount=query.value(0).toInt();

		query.prepare("update CurrentBurnLotSN set LotSN='"+QString::number(++nCount)+"' where 1" );
		if(!query.exec()){
			return ;
		}
		manualtool->ui.motorTestButton->setText(QString::number(nCount));
	}
	

	
 }
