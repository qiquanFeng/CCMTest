#include "importtable.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QTextCodec>

importtable::importtable(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.tableListcomboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(tableSelectedChanged(const QString &)));
	connect(ui.pathpushButton, SIGNAL(released()), this, SLOT(findfile()));
	connect(ui.refeshpushButton, SIGNAL(released()), this, SLOT(refeshtablelist()));
	connect(ui.importpushButton, SIGNAL(released()), this, SLOT(import()));
	connect(ui.cancelpushButton, SIGNAL(released()), this, SLOT(close()));
}

importtable::~importtable()
{

}

void importtable::findfile()
{
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), ui.databasePathlineEdit->text(), "*.*");
	if(!dir.isEmpty())
		ui.databasePathlineEdit->setText(dir);
}

void importtable::refeshtablelist()
{
	ui.tableListcomboBox->clear();
	ui.infolabel->setText("");

	for(int w=0;	w<1;	++w){
		QSqlDatabase thirdpartdb = QSqlDatabase::addDatabase("QSQLITE", "thirdpart");
		thirdpartdb.setDatabaseName(ui.databasePathlineEdit->text());

		if (!thirdpartdb.open()){
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("创建数据库连接失败"));
		}
		else{
			ui.infolabel->setText(QTextCodec::codecForName( "GBK")->toUnicode("创建数据库连接成功"));
			ui.tableListcomboBox->addItems(thirdpartdb.tables());
			ui.tableRenamelineEdit->setText(ui.tableListcomboBox->currentText());
			ui.infolabel->setText(ui.databasePathlineEdit->text());
		}
	}

	QSqlDatabase::removeDatabase("thirdpart");

	bool bchange	=	false;
	for(int x=0;	x<ui.tableListcomboBox->count();	++x){
		if(ui.tableListcomboBox->itemText(x) == "global"){
			ui.tableListcomboBox->removeItem(x);
			bchange	=	true;
		}
	}

	if(bchange && ui.tableListcomboBox->count() > 0){
		ui.tableListcomboBox->setCurrentIndex(0);
		ui.tableRenamelineEdit->setText(ui.tableListcomboBox->itemText(0));
	}
}

void importtable::import()
{
	QString strPath				=	ui.databasePathlineEdit->text();
	QString strTableName	=	ui.tableListcomboBox->currentText();
	QString strReName		=	ui.tableRenamelineEdit->text();

	strPath					=	strPath.trimmed();
	strTableName		=	strTableName.trimmed();
	strReName			=	strReName.trimmed();

	if(strPath.size() > 3 && strTableName.size() > 0 && strReName.size() > 0){
		emit execimport(strPath, strTableName, strReName);
	}

	this->deleteLater();
}

void importtable::tableSelectedChanged(const QString & text)
{
	ui.tableRenamelineEdit->setText(text);
}
