#include "QHOpModeSwitch.h"

QHOpModeSwitch::QHOpModeSwitch(QWidget *parent)
{
	ui.setupUi(this);

	ui.modecomboBox->setCurrentIndex(hisglobalparameter.stOperatorMode.ucMode);

	if(hisglobalparameter.stOperatorMode.ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A)
		ui.chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("MTF"));
	else if(hisglobalparameter.stOperatorMode.ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A)
		ui.chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("SFR"));
	else
		ui.chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("TV Line"));

	ui.saveLogcheckBox->setChecked(hisglobalparameter.stOperatorMode.bSaveLog);
	ui.showTotalResultcheckBox->setChecked(hisglobalparameter.stOperatorMode.bShowTotalResult);

	if(hisglobalparameter.stOperatorMode.ucChartType_B == _HisCCMAlg_Rolongo_Chart_MTF_A)
		ui.B_chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("MTF"));
	else if(hisglobalparameter.stOperatorMode.ucChartType_B == _HisCCMAlg_Rolongo_Chart_SFR_A)
		ui.B_chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("SFR"));
	else
		ui.B_chartTypecomboBox->setCurrentIndex(ui.chartTypecomboBox->findText("TV Line"));

	ui.B_scenccomboBox->setCurrentIndex(hisglobalparameter.stOperatorMode.ucPlugScene);
	ui.B_PlugInterfacecomboBox->setCurrentIndex(hisglobalparameter.stOperatorMode.ucPlugInterface);
	ui.B_Plug2ndNamecomboBox->setCurrentIndex(ui.B_Plug2ndNamecomboBox->findText(QString::fromAscii(hisglobalparameter.stOperatorMode.strPlug2ndName)));
	ui.B_PlugMindoubleSpinBox->setValue(hisglobalparameter.stOperatorMode.flPlugMin);
	ui.B_PlugMaxdoubleSpinBox->setValue(hisglobalparameter.stOperatorMode.flPlugMax);

	connect(ui.okpushButton, SIGNAL(released()), this, SLOT(clickOK()));
	connect(ui.cancelpushButton, SIGNAL(released()), this, SLOT(clickCancel()));
	connect(ui.modecomboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(OperatorModeChange(int)));

	if(!hisglobalparameter.stOperatorMode.u8TcpIpType) ui.localradioButton->setChecked(true);
	else ui.ipV4radioButton->setChecked(true);

	QStringList listIp;
	listIp.push_back(QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 24) & 0xFF));
	listIp.push_back(QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 16) & 0xFF));
	listIp.push_back(QString::number((hisglobalparameter.stOperatorMode.u32IpV4 >> 8) & 0xFF));
	listIp.push_back(QString::number(hisglobalparameter.stOperatorMode.u32IpV4 & 0xFF));
	ui.ipv4lineEdit->setText(listIp.join("."));

	ui.portspinBox->setValue(hisglobalparameter.stOperatorMode.u16SocketPort);

	if(hisglobalparameter.stOperatorMode.ucMode==0)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(hisglobalparameter.stOperatorMode.ucMode==1)
	{
		ui.manualmodeAgroupBox->setVisible(true);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(hisglobalparameter.stOperatorMode.ucMode==3)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(true);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(hisglobalparameter.stOperatorMode.ucMode==2 ||hisglobalparameter.stOperatorMode.ucMode==4)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(true);
	}
	
}

void QHOpModeSwitch::OperatorModeChange(int Index)
{
	if(Index==0)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(Index==1)
	{
		ui.manualmodeAgroupBox->setVisible(true);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(Index==3)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(true);
		ui.ipsetgroupBox->setVisible(false);
	}
	else if(Index==2 ||Index==4)
	{
		ui.manualmodeAgroupBox->setVisible(false);
		ui.manualmodeBgroupBox->setVisible(false);
		ui.ipsetgroupBox->setVisible(true);
	}

}


QHOpModeSwitch::~QHOpModeSwitch()
{

}

void QHOpModeSwitch::clickOK()
{
	saveSlaveModeConfig();
	saveManualModeAConfig();
	saveManualModeBConfig();

	hisglobalparameter.stOperatorMode.ucMode					=	ui.modecomboBox->currentIndex();

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "operator mode", QVariant(), QVariant(), "choose mode");
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 20, "global", "operator mode", QVariant(), QVariant(), "choose mode", hisglobalparameter.stOperatorMode.ucMode);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}

	this->done(QDialog::Accepted);
}

void QHOpModeSwitch::clickCancel()
{
	this->done(QDialog::Rejected);
}

void QHOpModeSwitch::saveSlaveModeConfig()
{
	QStringList listIp	=	ui.ipv4lineEdit->text().split(".");
	quint32 ui32Ip		=	listIp.at(0).toUInt();
	ui32Ip	=	(ui32Ip <<8) | listIp.at(1).toUInt();
	ui32Ip	=	(ui32Ip <<8) | listIp.at(2).toUInt();
	ui32Ip	=	(ui32Ip <<8) | listIp.at(3).toUInt();

	quint8 u8Type = 0;
	if(ui.ipV4radioButton->isChecked()) u8Type = 2;

	QStringList listname, listvalue;
	listname.append("type");
	listvalue.append(QString::number(u8Type));
	listname.append("ipv4");
	listvalue.append(QString::number(ui32Ip));
	listname.append("socket");
	listvalue.append(ui.portspinBox->cleanText());

	hisglobalparameter.stOperatorMode.u8TcpIpType		=	u8Type;
	hisglobalparameter.stOperatorMode.u32IpV4			=	ui32Ip;
	hisglobalparameter.stOperatorMode.u16SocketPort	=	ui.portspinBox->value();

	//(type:0)(ipv4:0)(socket:0)
	QString strValue;
	ROPLOW::jointconfigstring(strValue, listname, listvalue);

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "slave mode", QVariant(), QVariant(), "tcpip");
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 22, "global", "slave mode", QVariant(), QVariant(), "tcpip", strValue);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}
}

void QHOpModeSwitch::saveManualModeAConfig()
{
	if(ui.chartTypecomboBox->currentText() == "MTF")
		hisglobalparameter.stOperatorMode.ucChartType	=	_HisCCMAlg_Rolongo_Chart_MTF_A;
	else if(ui.chartTypecomboBox->currentText() == "SFR")
		hisglobalparameter.stOperatorMode.ucChartType	=	_HisCCMAlg_Rolongo_Chart_SFR_A;
	else
		hisglobalparameter.stOperatorMode.ucChartType	=	_HisCCMAlg_Rolongo_Chart_LP_A;

	hisglobalparameter.stOperatorMode.bSaveLog					=	ui.saveLogcheckBox->isChecked();
	hisglobalparameter.stOperatorMode.bShowTotalResult	=	ui.showTotalResultcheckBox->isChecked();
	

	QString itemsuffix1 ;
	QStringList strname, strvalue;
	//(chart:16)(savelog:true)(totalresult:true)
	strname.clear(); strvalue.clear();
	strname.append("chart");				strvalue.append(QString::number(hisglobalparameter.stOperatorMode.ucChartType));
	strname.append("savelog");			strvalue.append((hisglobalparameter.stOperatorMode.bSaveLog)?("true"):("false"));
	strname.append("totalresult");		strvalue.append((hisglobalparameter.stOperatorMode.bShowTotalResult)?("true"):("false"));
	ROPLOW::jointconfigstring(itemsuffix1, strname, strvalue);

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item, "opmode", "manual-a-1");
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 25, "opmode", "manual-a-1", itemsuffix1);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}

}

void QHOpModeSwitch::saveManualModeBConfig()
{
	if(ui.chartTypecomboBox->currentText() == "MTF")
		hisglobalparameter.stOperatorMode.ucChartType_B	=	_HisCCMAlg_Rolongo_Chart_MTF_A;
	else if(ui.chartTypecomboBox->currentText() == "SFR")
		hisglobalparameter.stOperatorMode.ucChartType_B	=	_HisCCMAlg_Rolongo_Chart_SFR_A;
	else
		hisglobalparameter.stOperatorMode.ucChartType_B	=	_HisCCMAlg_Rolongo_Chart_LP_A;

	hisglobalparameter.stOperatorMode.flPlugMin				=	ui.B_PlugMindoubleSpinBox->value();
	hisglobalparameter.stOperatorMode.flPlugMax				=	ui.B_PlugMaxdoubleSpinBox->value();
	hisglobalparameter.stOperatorMode.ucPlugInterface	=	ui.B_PlugInterfacecomboBox->currentIndex();
	sprintf(hisglobalparameter.stOperatorMode.strPlug2ndName, "%s", ui.B_Plug2ndNamecomboBox->currentText().toAscii().data());
	hisglobalparameter.stOperatorMode.ucPlugScene		=	ui.B_scenccomboBox->currentIndex();


	QString itemsuffix1 ;
	QStringList strname, strvalue;
	//(chart:16)(min:5.0)(max:800.0)(interface:0)(pin:DVDD)(scene:0)
	strname.append("chart");				strvalue.append(QString::number(hisglobalparameter.stOperatorMode.ucChartType_B));
	strname.append("min");					strvalue.append(ui.B_PlugMindoubleSpinBox->cleanText());
	strname.append("max");					strvalue.append(ui.B_PlugMaxdoubleSpinBox->cleanText());
	strname.append("interface");				strvalue.append(QString::number(hisglobalparameter.stOperatorMode.ucPlugInterface));
	strname.append("pin");					strvalue.append(ui.B_Plug2ndNamecomboBox->currentText());
	strname.append("scene");				strvalue.append(QString::number(hisglobalparameter.stOperatorMode.ucPlugScene));
	ROPLOW::jointconfigstring(itemsuffix1, strname, strvalue);

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item, "opmode", "manual-b-1");
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 25, "opmode", "manual-b-1", itemsuffix1);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}

}

