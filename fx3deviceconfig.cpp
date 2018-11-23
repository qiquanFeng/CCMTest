#include "fx3deviceconfig.h"
#include <QSqlDatabase>
#include <QDir>
#include <QSqlQuery>
#include <QMessageBox>
#include <QStringBuilder>


fx3deviceconfig::fx3deviceconfig(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.savepushButton, SIGNAL(released()), this, SLOT(saveConfig()));
	connect(ui.setGrabberParameterpushButton, SIGNAL(released()), this, SLOT(slotSetGrabberParameter()));
	connect(ui.choosePlatformpushButton, SIGNAL(released()), this, SLOT(slotChoosePlatform()));

	ui.fpgaDelayspinBox->setValue(hisglobalparameter.ucFPGAUploadDelay);
	ui.packetSizespinBox->setValue(hisglobalparameter.ucFX3PacketSize);
	ui.platformChoosecomboBox->setCurrentIndex(hisglobalparameter.ucChoosePlatform);
}

fx3deviceconfig::~fx3deviceconfig()
{

}

void fx3deviceconfig::setConfig(bool bOpen1, unsigned int GrabberCount,unsigned char ucIndex1, unsigned int uiSerial1[4], unsigned int uiSerial2[40], QString strFreidlyName1)
{
	ucIndex				=	ucIndex1;
	bOpen					=	bOpen1;
	strFreidlyName	=	strFreidlyName1;
	memcpy(uiSerialChoose, uiSerial1, sizeof(unsigned int) *4);
	memcpy(uiSerialNow, uiSerial2, sizeof(unsigned int) *40);

	if(ucIndex == 1){
		ui.pos1radioButton->setChecked(true);
	}
	else if(ucIndex == 2){
		ui.pos2radioButton->setChecked(true);
	}
	else if(ucIndex == 3){
		ui.pos3radioButton->setChecked(true);
	}
	else if(ucIndex == 4){
		ui.pos4radioButton->setChecked(true);
	}

	for(int i=0;i<GrabberCount;i++)
	{
		ui.connectgrabbersncomboBox->addItem(QString::number(uiSerialNow[0+4*i]) % "." % QString::number(uiSerialNow[1+4*i]) % "." % \
		QString::number(uiSerialNow[2+4*i]) % "." % QString::number(uiSerialNow[3+4*i]));
	}

	if(ucIndex >=1 && ucIndex <= 4){
		ui.serialNumberlabel->setText(QString::number(uiSerialChoose[0]) % "." % QString::number(uiSerialChoose[1]) % "." % \
			QString::number(uiSerialChoose[2]) % "." % QString::number(uiSerialChoose[3]));
	}
	else if(bOpen){
		ui.serialNumberlabel->setText(QString::number(uiSerialNow[0]) % "." % QString::number(uiSerialNow[1]) % "." % \
			QString::number(uiSerialNow[2]) % "." % QString::number(uiSerialNow[3]));
	}
}

void fx3deviceconfig::saveConfig()
{
	unsigned int uiChoose	=	0;
	if(ui.pos1radioButton->isChecked())			uiChoose	=	1;
	else if(ui.pos2radioButton->isChecked())	uiChoose = 2;
	else if(ui.pos3radioButton->isChecked())	uiChoose = 3;
	else if(ui.pos4radioButton->isChecked())	uiChoose = 4;
	int iGrabberChooseIndex=ui.connectgrabbersncomboBox->currentIndex();

	if(uiChoose >= 1 && uiChoose <= 4 && !bOpen){
		QMessageBox::information(this, tr("ERROR"), tr("The grabber is not opening. \nPlease open grabber first, and back to execute binding."));
		return;
	}

	//save db
	bool bsucess	= true;

	for(int w=0;	w<1;	++w)
	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open()){
			bsucess = false;
			break;
		}

		QSqlQuery query(templatedb);
		query.prepare("DELETE FROM global WHERE classfy=:classfy AND item=:item");
		query.bindValue(":classfy", "global");
		query.bindValue(":item", "fx3");
		query.exec();

		if(uiChoose >= 1 && uiChoose <= 4){
			query.prepare("INSERT INTO global(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
			query.bindValue(":id", 14);
			query.bindValue(":classfy", "global");
			query.bindValue(":item", "fx3");
			query.bindValue(":itemsuffix1", uiChoose);
			query.bindValue(":itemsuffix2", uiSerialNow[iGrabberChooseIndex*4+0]);
			query.bindValue(":key", uiSerialNow[iGrabberChooseIndex*4+1]);
			query.bindValue(":value", uiSerialNow[iGrabberChooseIndex*4+2]);
			query.bindValue(":reserve", uiSerialNow[iGrabberChooseIndex*4+3]);
			query.bindValue(":note", strFreidlyName);
			query.exec();
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");

	if(!bsucess){
		QMessageBox::warning(this, tr("warning"), tr("open HisFX3Template db fail"));
		return;
	}

	QMessageBox::information(this, tr("info"), tr("please restart program to make the change valid."));

	this->deleteLater();
}

void fx3deviceconfig::slotSetGrabberParameter()
{
	hisglobalparameter.ucFPGAUploadDelay	=	ui.fpgaDelayspinBox->value();
	hisglobalparameter.ucFX3PacketSize		=	ui.packetSizespinBox->value();
	classPlatform.setBulkTransformSize(64 *1024 * hisglobalparameter.ucFX3PacketSize);
	if(classPlatform.HisFX3isopen())
	{
		classPlatform.setUSBSpeed(hisglobalparameter.ucFPGAUploadDelay);
	}

	//save db
	bool bsucess	= true;

	for(int w=0;	w<1;	++w)
	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open()){
			bsucess = false;
			break;
		}

		QSqlQuery query(templatedb);
		query.prepare("DELETE FROM global WHERE classfy=:classfy AND item=:item");
		query.bindValue(":classfy", "global");
		query.bindValue(":item", "grabberparameter");
		query.exec();

		query.prepare("INSERT INTO global(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
		query.bindValue(":id", 15);
		query.bindValue(":classfy", "global");
		query.bindValue(":item", "grabberparameter");
		query.bindValue(":itemsuffix1", hisglobalparameter.ucFPGAUploadDelay);
		query.bindValue(":itemsuffix2", hisglobalparameter.ucFX3PacketSize);
		query.bindValue(":key", QVariant());
		query.bindValue(":value", QVariant());
		query.bindValue(":reserve", QVariant());
		query.bindValue(":note", QVariant());
		query.exec();

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");

	if(!bsucess){
		QMessageBox::warning(this, tr("warning"), tr("open HisFX3Template db fail"));
		return;
	}

	this->deleteLater();
}

void fx3deviceconfig::slotChoosePlatform()
{
	hisglobalparameter.ucChoosePlatform	=	ui.platformChoosecomboBox->currentIndex();

	//save db
	bool bsucess	= true;

	for(int w=0;	w<1;	++w)
	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open()){
			bsucess = false;
			break;
		}

		QSqlQuery query(templatedb);
		query.prepare("DELETE FROM global WHERE classfy=:classfy AND item=:item");
		query.bindValue(":classfy", "global");
		query.bindValue(":item", "chooseplatform");
		query.exec();

		query.prepare("INSERT INTO global(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
		query.bindValue(":id", 16);
		query.bindValue(":classfy", "global");
		query.bindValue(":item", "chooseplatform");
		query.bindValue(":itemsuffix1", hisglobalparameter.ucChoosePlatform);
		query.bindValue(":itemsuffix2", QVariant());
		query.bindValue(":key", QVariant());
		query.bindValue(":value", QVariant());
		query.bindValue(":reserve", QVariant());
		query.bindValue(":note", QVariant());
		query.exec();

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");

	if(!bsucess){
		QMessageBox::warning(this, tr("warning"), tr("open HisFX3Template db fail"));
		return;
	}

	QMessageBox::information(this, tr("info"), tr("please restart program to make the change valid."));

	this->deleteLater();
}