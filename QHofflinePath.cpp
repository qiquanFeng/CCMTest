#include "QHofflinePath.h"
#include <QListWidgetItem>
#include <QTime>
#include <QSqlDatabase>
#include <QDir>
#include <QStringBuilder>
#include <QSqlQuery>
#include "qoplow.h"
#include <QFileDialog>
QHofflinePath::QHofflinePath(QWidget *parent,QString tablename,QString& filename2,bool Readsamepicture)
	: QDialog(parent),Qfilename(filename2)
{
	ui.setupUi(this);
	strTableName	=	tablename;
	Qfilename	=	filename2;
	bReadsamepicture	=	Readsamepicture;
	connect(ui.savepushButton, SIGNAL(released()), this, SLOT(slotSave()));
	connect(ui.offlineopenpushButton, SIGNAL(released()), this, SLOT(slotOpenpath()));
	paraToUI();
}

QHofflinePath::~QHofflinePath()
{

}
void QHofflinePath::paraToUI()
{
	ui.offlinepathlineEdit->setText(Qfilename);
	ui.readsamepicturecheckBox->setChecked(bReadsamepicture);
}

void QHofflinePath::slotSave()
{
	Qfilename	=	ui.offlinepathlineEdit->text();
	bReadsamepicture	=	ui.readsamepicturecheckBox->isChecked() ? true:false;
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return;
		}

		QStringList strname, strvalue;
		QString itemsuffix2, key;
		QSqlQuery query(customdb);

		query.prepare("DELETE FROM " % strTableName %  " WHERE id=:id AND classfy=:classfy AND item=:item AND itemsuffix1=:itemsuffix1");
		query.bindValue(":id",100);
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "offline");
		query.bindValue(":itemsuffix1", "paramater");
		query.exec();

		//(lsc:false)(wb:false)
		strname.clear(); strvalue.clear();
		strname.append("offlinepath");
		strvalue.append(ui.offlinepathlineEdit->text());
		strname.append("readsamepicture");
		strvalue.append(ui.readsamepicturecheckBox->isChecked()? "true":"false");
		ROPLOW::jointconfigstring(key, strname, strvalue);

		query.prepare("INSERT INTO " % strTableName %"(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve)");
		query.bindValue(":id", 100);
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "offline");
		query.bindValue(":itemsuffix1", "paramater");
		query.bindValue(":itemsuffix2", "");
		query.bindValue(":key", key);
		query.bindValue(":value", "");
		query.bindValue(":reserve", "");
		query.exec();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
	this->done(QDialog::Accepted);
}
void QHofflinePath::slotOpenpath()
{
	if (Qfilename.isEmpty())
	{
		Qfilename = QFileDialog::getOpenFileName(this, "Open File", "/home", "Images (*.raw *.bmp *.jpg *.jpeg *.png *.tiff)");
	} 
	else
	{
		Qfilename = QFileDialog::getOpenFileName(this, "Open File", Qfilename , "Images (*.raw *.bmp *.jpg *.jpeg *.png *.tiff)");
	}

	ui.offlinepathlineEdit->setText(Qfilename);

}

