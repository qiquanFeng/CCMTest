#include "QHManualModeA.h"
#include "qoplow.h"

QHManualModeA::QHManualModeA(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC)
	: QDialog(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC)
{
	ui.setupUi(this);

	ui.blemishcheckBox->setVisible(false);
	ui.occheckBox->setVisible(false);
	ui.defectPixelcheckBox->setVisible(false);
	ui.colorcheckBox->setVisible(false);
	ui.shadingcheckBox->setVisible(false);
	ui.vignettingcheckBox->setVisible(false);
	ui.linecheckBox->setVisible(false);

	luxTimer.setSingleShot(false);
	luxTimer.setInterval(200);
	if(luxTimer.isActive())
		luxTimer.stop();
	connect(&luxTimer, SIGNAL(timeout()), this, SLOT(updateExposruetime()));
	connect(ui.exposureTimehorizontalSlider, SIGNAL(sliderPressed()), this, SLOT(startUpdateExposruetime()));
	connect(ui.exposureTimehorizontalSlider, SIGNAL(sliderReleased()), this, SLOT(stopUpdateExposruetime()));
	connect(ui.exposurepushButton, SIGNAL(released()), this, SLOT(setExposreValue()));

	connect(ui.savepushButton, SIGNAL(released()), this, SLOT(saveConfig()));
	connect(ui.scenecomboBox, SIGNAL(currentIndexChanged (int)), this, SLOT(slotSceneChanged(int)));

	ui.delayspinBox->setValue(itemshareData.stManualModeA.usDelay);

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
	setExposureTime = (RolongosetExposureTime)(QLibrary::resolve(strLibPath, "setExposureTime"));

	if(!(getSensorAPIVersion && getExposureTime && setExposureTime)){
		ui.infolabel->setText(tr("Resolve HisCCMSensor DLL Function Fail"));
	}
	else
	{
		unsigned int uivalue = 0, uimin = 0, uimax =0;
		int iresult	=	getExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, uivalue, uimin, uimax, globalFunPointer.ReadHisFX3IIC, \
			globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult){
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("获取当前曝光值失败"));
			bExposureFlag		=	false;
		}
		else{
			bExposureFlag		=	true;
			ui.exposureTimehorizontalSlider->setMinimum(uimin);
			ui.exposureTimehorizontalSlider->setMaximum((uimax>20000)?(20000):(uimax));
			setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, itemshareData.stManualModeA.uiExposureValue_FA, globalFunPointer.ReadHisFX3IIC, \
				globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
				globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
			ui.exposureTimehorizontalSlider->setValue(itemshareData.stManualModeA.uiExposureValue_FA);
			ui.exposurespinBox->setValue(itemshareData.stManualModeA.uiExposureValue_FA);
		}
	}

}

QHManualModeA::~QHManualModeA()
{

}

void QHManualModeA::saveConfig()
{
	itemshareData.stManualModeA.usDelay	=	ui.delayspinBox->value();

	saveManualModeAConfig();

	QMessageBox::information(this, tr("Information"), tr("Save Success!!!"));
}


void QHManualModeA::setExposreValue()
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bExposureFlag		=	false;
		return;
	}

	unsigned int uivalue	=	ui.exposurespinBox->value();
	ui.exposureTimehorizontalSlider->setValue(uivalue);
	int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, uivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
		globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(uivalue));
	}
	else{
		if(ui.scenecomboBox->currentIndex() == 0) itemshareData.stManualModeA.uiExposureValue_FA	=	uivalue;
		else if(ui.scenecomboBox->currentIndex() == 1) itemshareData.stManualModeA.uiExposureValue_NearFC	=	uivalue;
		else if(ui.scenecomboBox->currentIndex() == 2) itemshareData.stManualModeA.uiExposureValue_FarFC	=	uivalue;
		else itemshareData.stManualModeA.uiExposureValue_WhiteField	=	uivalue;
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(uivalue));
	}
}

void QHManualModeA::updateExposruetime()
{
	unsigned int uivalue	=	ui.exposureTimehorizontalSlider->value();
	ui.exposurespinBox->setValue(uivalue);
	int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, uivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
		globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(uivalue));
	}
	else{
		if(ui.scenecomboBox->currentIndex() == 0) itemshareData.stManualModeA.uiExposureValue_FA	=	uivalue;
		else if(ui.scenecomboBox->currentIndex() == 1) itemshareData.stManualModeA.uiExposureValue_NearFC	=	uivalue;
		else if(ui.scenecomboBox->currentIndex() == 2) itemshareData.stManualModeA.uiExposureValue_FarFC	=	uivalue;
		else itemshareData.stManualModeA.uiExposureValue_WhiteField	=	uivalue;
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(uivalue));
	}
}

void QHManualModeA::startUpdateExposruetime()
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

void QHManualModeA::stopUpdateExposruetime()
{
	if(bExposureFlag){
		if(luxTimer.isActive())
			luxTimer.stop();

		QTimer::singleShot(500, this, SLOT(updateExposruetime()));
	}
}

void QHManualModeA::slotSceneChanged(int iIndex)
{
	if(!threadshareData.GetHisPreviewflag()){
		ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		bExposureFlag		=	false;
		return;
	}

	if(iIndex == 0){
		ui.exposurespinBox->setValue(itemshareData.stManualModeA.uiExposureValue_FA);
		ui.exposureTimehorizontalSlider->setValue(itemshareData.stManualModeA.uiExposureValue_FA);
		int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave,  itemshareData.stManualModeA.uiExposureValue_FA, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
			globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult)
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_FA));	
		else
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_FA));		
	}
	else if(iIndex == 1){
		ui.exposurespinBox->setValue(itemshareData.stManualModeA.uiExposureValue_NearFC);
		ui.exposureTimehorizontalSlider->setValue(itemshareData.stManualModeA.uiExposureValue_NearFC);
		int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave,  itemshareData.stManualModeA.uiExposureValue_NearFC, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
			globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult)
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_NearFC));	
		else
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_NearFC));		
	}
	else if(iIndex == 2){
		ui.exposurespinBox->setValue(itemshareData.stManualModeA.uiExposureValue_FarFC);
		ui.exposureTimehorizontalSlider->setValue(itemshareData.stManualModeA.uiExposureValue_FarFC);
		int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave,  itemshareData.stManualModeA.uiExposureValue_FarFC, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
			globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult)
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_FarFC));	
		else
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_FarFC));		
	}
	else{
		ui.exposurespinBox->setValue(itemshareData.stManualModeA.uiExposureValue_WhiteField);
		ui.exposureTimehorizontalSlider->setValue(itemshareData.stManualModeA.uiExposureValue_WhiteField);
		int iresult	=	setExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, itemshareData.stManualModeA.uiExposureValue_NearFC, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, \
			globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
			globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
		if(iresult)
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值失败: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_WhiteField));	
		else
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("设定曝光值成功: ") % QString::number(itemshareData.stManualModeA.uiExposureValue_WhiteField));		
	}

	ui.blemishcheckBox->setVisible(iIndex==3);
	ui.occheckBox->setVisible(iIndex==3);
	ui.defectPixelcheckBox->setVisible(iIndex==3);
	ui.colorcheckBox->setVisible(iIndex==3);
	ui.shadingcheckBox->setVisible(iIndex==3);
	ui.vignettingcheckBox->setVisible(iIndex==3);
	ui.linecheckBox->setVisible(iIndex==3);

}

void QHManualModeA::saveManualModeAConfig()
{
	QString itemsuffix1,itemsuffix2,key,value1,reserve ;
	QStringList strname, strvalue;

	//(delay:500)
	//(fafevalue:1)
	//(wpfevalue:1)
	//(nearfcfevalue:1)
	//(farfcfevalue:1)
	strname.clear(); strvalue.clear();
	strname.append("delay");				strvalue.append(QString::number(itemshareData.stManualModeA.usDelay));
	ROPLOW::jointconfigstring(itemsuffix1, strname, strvalue);

	strname.clear(); strvalue.clear();
	strname.append("fafevalue");				strvalue.append(QString::number(itemshareData.stManualModeA.uiExposureValue_FA));
	ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

	strname.clear(); strvalue.clear();
	strname.append("farfcfevalue");				strvalue.append(QString::number(itemshareData.stManualModeA.uiExposureValue_FarFC));
	ROPLOW::jointconfigstring(key, strname, strvalue);

	strname.clear(); strvalue.clear();
	strname.append("wpfevalue");				strvalue.append(QString::number(itemshareData.stManualModeA.uiExposureValue_WhiteField));
	strname.append("blemish");					strvalue.append(((ui.blemishcheckBox->isChecked())?("1"):("0")));
	strname.append("oc");							strvalue.append(((ui.occheckBox->isChecked())?("1"):("0")));
	strname.append("shading");					strvalue.append(((ui.shadingcheckBox->isChecked())?("1"):("0")));
	strname.append("vignet");						strvalue.append(((ui.vignettingcheckBox->isChecked())?("1"):("0")));
	strname.append("color");						strvalue.append(((ui.colorcheckBox->isChecked())?("1"):("0")));
	strname.append("dpixel");						strvalue.append(((ui.defectPixelcheckBox->isChecked())?("1"):("0")));
	strname.append("line");							strvalue.append(((ui.linecheckBox->isChecked())?("1"):("0")));
	ROPLOW::jointconfigstring(value1, strname, strvalue);

	strname.clear(); strvalue.clear();
	strname.append("nearfcfevalue");				strvalue.append(QString::number(itemshareData.stManualModeA.uiExposureValue_NearFC));
	ROPLOW::jointconfigstring(reserve, strname, strvalue);


	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			HISDBCUSTOM::deleteItem(stSqlDB, itemshareData.currentTableName, _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item, "opmode", "manual-a-2");
			HISDBCUSTOM::insertItem(stSqlDB, itemshareData.currentTableName, 0, "opmode", "manual-a-2", itemsuffix1, itemsuffix2, key, value1, reserve);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
}

