#include "qconfigmanage.h"
#include <QSqlDatabase>
#include <QDir>
#include <QMessageBox>
#include <QTextCodec>
#include <QStringBuilder>
#include <QSqlError>
#include <QFileDialog>
#include <QSqlQuery>
#include <QTextStream>
#include <QInputDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "QDebug"
#include "windows.h"

qconfigmanage::qconfigmanage(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QWidget* techArea = new QWidget;
	techArea->setObjectName("techarea");
	techArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	techArea->setLayout(new QVBoxLayout(techArea));
	ui.configList_scrollArea->setWidget(techArea);
	scrollLay = techArea->layout();

	connect(ui.selectALL_checkBox, SIGNAL(stateChanged(int)), this, SLOT(seletALL(int)));
	connect(ui.selectNone_checkBox, SIGNAL(stateChanged(int)), this, SLOT(seletNone(int)));
	connect(ui.import_pushButton, SIGNAL(released()), this, SLOT(importConfig()));
	connect(ui.export_pushButton, SIGNAL(released()), this, SLOT(exportConfig()));
	connect(ui.new_pushButton, SIGNAL(released()), this, SLOT(createConfig()));
	connect(ui.rename_pushButton, SIGNAL(released()), this, SLOT(renameConfig()));
	connect(ui.delete_pushButton, SIGNAL(released()), this, SLOT(deleteConfig()));
	connect(ui.serachlineEdit, SIGNAL(textChanged ( const QString &) ), this, SLOT(textSelected( const QString &)));
	
	QDir classDir;
	strDefaultCSVDir	=	QDir::currentPath() % "/csvconfig";
	classDir.mkpath(strDefaultCSVDir);

	timerSearch.setSingleShot(false);
	timerSearch.setInterval(200);
	if(timerSearch.isActive())	timerSearch.stop();
	connect(&timerSearch, SIGNAL(timeout()), this, SLOT(slotSearchText()));

	freshConfigList();
}

qconfigmanage::~qconfigmanage()
{
	for(unsigned int x=0;	x<vectorList.size();	++x){
		scrollLay->removeWidget(vectorList.at(x));
		delete vectorList.at(x);
	}
	vectorList.clear();
}

void qconfigmanage::freshConfigList()
{
	for(unsigned int x=0;	x<vectorList.size();	++x){
		scrollLay->removeWidget(vectorList.at(x));
		delete vectorList.at(x);
	}
	vectorList.clear();
	ui.selectALL_checkBox->setChecked(false);
	ui.selectNone_checkBox->setChecked(false);

	QStringList strConfigList;
	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		strConfigList	=	customdb.tables();
		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
	if(!bparsesuccess)
		return;

	strConfigList.sort();
	QString strSearchKey = ui.serachlineEdit->text().trimmed();

	for(unsigned int x=0;	x<strConfigList.size();	++x){
		if(strConfigList.at(x) != "global" && (strSearchKey.isEmpty() || strConfigList.at(x).contains(strSearchKey, Qt::CaseInsensitive))){
			QCheckBox* pstBox	=	new QCheckBox(strConfigList.at(x));
			scrollLay->addWidget(pstBox);
			vectorList.push_back(pstBox);
		}
	}
	
}

void qconfigmanage::exportConfig()
{
	QStringList strSelectList;
	for(unsigned int x=0;	x<vectorList.size();	++x){
		if(vectorList.at(x)->isChecked())
			strSelectList.push_back(vectorList.at(x)->text());
	}

	if(strSelectList.isEmpty()){
		QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告"), QTextCodec::codecForName( "GBK")->toUnicode("没有选择任何参数，\n无法执行导出任务!!!"));
		return;
	}

	bool bXML = ui.importXMLradioButton->isChecked();
	bool bTxt	  =	ui.importTxtradioButton->isChecked();

	if(bXML){
		QString strCSVDir	=	QFileDialog::getExistingDirectory(this, QTextCodec::codecForName( "GBK")->toUnicode("请选择导出目录"), \
			strDefaultCSVDir, QFileDialog::ShowDirsOnly);
		if(!strCSVDir.isEmpty()){
			for(unsigned int x=0;	x<strSelectList.size();	++x){
				toXML(strSelectList.at(x), strCSVDir);
			}
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("参数导出到XML格式完成!!!"));
		}
	}
	else if(bTxt)
	{
		QString strCSVDir	=	QFileDialog::getExistingDirectory(this, QTextCodec::codecForName( "GBK")->toUnicode("请选择导出目录"), \
			strDefaultCSVDir, QFileDialog::ShowDirsOnly);
		if(!strCSVDir.isEmpty()){
			for(unsigned int x=0;	x<strSelectList.size();	++x){
				toCSV(strSelectList.at(x), strCSVDir);
			}
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("参数导出到TXT格式完成!!!"));
		}
	}
	else{
// 		ui.info_label->setText(QTextCodec::codecForName( "GBK")->toUnicode("您选择了导出到数据库，现在准备导出..."));
		QString strPath	=	QFileDialog::getOpenFileName(this, QTextCodec::codecForName( "GBK")->toUnicode("请选择导出目的数据库"));
		if(!strPath.isEmpty() && isDatabase(strPath) && !isSameFile(strPath)){
			for(unsigned int x=0;	x<strSelectList.size();	++x){
				toDataBase(strPath, strSelectList.at(x));
			}
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("参数导出到数据库完成!!!"));
		}
	}
}

void qconfigmanage::importConfig()
{
	if(ui.importXMLradioButton->isChecked()){
		QStringList strSelectList	=	 QFileDialog::getOpenFileNames(this, QTextCodec::codecForName( "GBK")->toUnicode("请选择要导入的文件"), \
			strDefaultCSVDir, "Rolongo XML (*.xml)");
		for(unsigned int x=0;	x<strSelectList.size();	++x){
			if(isTheXML(strSelectList.at(x))){
				fromXML(strSelectList.at(x));
			}
		}

		QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
			QTextCodec::codecForName( "GBK")->toUnicode("导入完成!!!"));
		freshConfigList();
	}
	else if(ui.importTxtradioButton->isChecked()){
		QStringList strSelectList	=	 QFileDialog::getOpenFileNames(this, QTextCodec::codecForName( "GBK")->toUnicode("请选择要导入的文件"), \
			strDefaultCSVDir, "Rolongo TXT (*.txt)");
		for(unsigned int x=0;	x<strSelectList.size();	++x){
			if(isTheCSV(strSelectList.at(x))){
				fromCSV(strSelectList.at(x));
			}
		}

		QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
			QTextCodec::codecForName( "GBK")->toUnicode("导入完成!!!"));
		freshConfigList();
	}
	else{

	}
}

void qconfigmanage::renameConfig()
{
	QStringList strSelectList;
	for(unsigned int x=0;	x<vectorList.size();	++x){
		if(vectorList.at(x)->isChecked())
			strSelectList.push_back(vectorList.at(x)->text());
	}

	if(strSelectList.isEmpty()){
		QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告，只能选择一个参数"), QTextCodec::codecForName( "GBK")->toUnicode("没有选择任何参数，\n无法执行重命名任务!!!"));
		return;
	}

	if(strSelectList.size() != 1){
		QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告，只能选择一个参数"), QTextCodec::codecForName( "GBK")->toUnicode("选择过多参数，\n无法执行重命名任务!!!"));
		return;
	}

	QString strNewName = QInputDialog::getText(this, QTextCodec::codecForName( "GBK")->toUnicode("请输入新名称"), \
		QTextCodec::codecForName( "GBK")->toUnicode("名称只能有0~9,a~z,A~Z,_组成，不能用数字开头"));
	strNewName.trimmed();

	if(!strNewName.isEmpty()){
		bool bparsesuccess	=	true;
		for(unsigned int  w=0;	w<1;	++w){
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

			if (!customdb.open()){
				QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
				bparsesuccess	=	false;
				break;
			}

			QSqlQuery query(customdb);
			query.prepare("ALTER TABLE " % strSelectList.at(0) % " RENAME TO " % strNewName);
			query.exec();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("custom");

		QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
			QTextCodec::codecForName( "GBK")->toUnicode("重命名完成!!!"));
		freshConfigList();
	}
}

void qconfigmanage::createConfig()
{
	if(ui.plainradioButton->isChecked())
	{
		QString strNewName = QInputDialog::getText(this, QTextCodec::codecForName( "GBK")->toUnicode("请输入新名称"), \
			QTextCodec::codecForName( "GBK")->toUnicode("名称只能有0~9,a~z,A~Z,_组成，不能用数字开头"));
		strNewName.trimmed();

		if(!strNewName.isEmpty()){
			bool bparsesuccess	=	true;
			for(unsigned int  w=0;	w<1;	++w){
				QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
				customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

				if (!customdb.open()){
					QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
					bparsesuccess	=	false;
					break;
				}

				QSqlQuery query(customdb);

				query.exec("create table " % strNewName % " (id int,classfy TEXT, item TEXT, itemsuffix1 TEXT,itemsuffix2 TEXT, key TEXT,value TEXT, reserve TEXT,note TEXT)");

				customdb.close();
			}

			QSqlDatabase::removeDatabase("custom");

			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("复制创建完成!!!"));
			freshConfigList();
		}
	}
	else
	{
		QStringList strSelectList;
		for(unsigned int x=0;	x<vectorList.size();	++x){
			if(vectorList.at(x)->isChecked())
				strSelectList.push_back(vectorList.at(x)->text());
		}

		if(strSelectList.isEmpty()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告，只能选择一个参数"), QTextCodec::codecForName( "GBK")->toUnicode("没有选择任何参数，\n无法执行重命名任务!!!"));
			return;
		}

		if(strSelectList.size() != 1){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告，只能选择一个参数"), QTextCodec::codecForName( "GBK")->toUnicode("选择过多参数，\n无法执行重命名任务!!!"));
			return;
		}

		QString strNewName = QInputDialog::getText(this, QTextCodec::codecForName( "GBK")->toUnicode("请输入新名称"), \
			QTextCodec::codecForName( "GBK")->toUnicode("名称只能有0~9,a~z,A~Z,_组成，不能用数字开头"));
		strNewName.trimmed();

		if(!strNewName.isEmpty()){
			bool bparsesuccess	=	true;
			for(unsigned int  w=0;	w<1;	++w){
				QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
				customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

				if (!customdb.open()){
					QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
					bparsesuccess	=	false;
					break;
				}

				QSqlQuery query(customdb);
				query.exec("create table " % strNewName % " as select * from " % strSelectList.at(0) % " ORDER BY id ASC");

				customdb.close();
			}

			QSqlDatabase::removeDatabase("custom");

			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("重复制创建完成!!!"));
			freshConfigList();
		}
	}
}

void qconfigmanage::deleteConfig()
{
	QStringList strSelectList;
	for(unsigned int x=0;	x<vectorList.size();	++x){
		if(vectorList.at(x)->isChecked())
			strSelectList.push_back(vectorList.at(x)->text());
	}

	if(strSelectList.isEmpty()){
		QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("警告"), QTextCodec::codecForName( "GBK")->toUnicode("没有选择任何参数，\n无法执行删除任务!!!"));
		return;
	}

	QString strText	=	strSelectList.join("\n");
	strText = QTextCodec::codecForName( "GBK")->toUnicode("确定删除：\n") % strText;

	if(QMessageBox::question(this, QTextCodec::codecForName( "GBK")->toUnicode("确认删除???"), strText, \
		QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes){
			for(unsigned int x=0;	x<strSelectList.size();	++x){
				deleteTable(strSelectList.at(x), QDir::currentPath() % "/HisFX3Custom");
			}
			QMessageBox::information(this, QTextCodec::codecForName( "GBK")->toUnicode("信息"), \
				QTextCodec::codecForName( "GBK")->toUnicode("删除完成!!!"));
			freshConfigList();
	}
}

void qconfigmanage::toXML(QString strTableName, QString strCSVDir)
{
	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w)
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		QString strFile = strCSVDir % "/" % strTableName % ".xml";
		QFile classFile(strFile);
		if(!classFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建文件失败"), strFile);
			break;
		}

		QXmlStreamWriter xmlWriter(&classFile);
		xmlWriter.writeStartDocument();
		xmlWriter.writeStartElement("Rolongo");
		xmlWriter.writeStartElement("MainSection");

		QSqlQuery query(customdb);
		query.prepare("SELECT id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note FROM " % strTableName % " ORDER BY id ASC" );
		query.exec();
		QString strElement;
		unsigned int uiID	=	0;

		while (query.next())
		{
			xmlWriter.writeStartElement("DBIndex" % QString::number(uiID++));

			for(unsigned int x=0;	x<8;	++x)
			{
				switch (x)
				{
				case 0: strElement = "id";	break;
				case 1: strElement = "classfy";	break;
				case 2: strElement = "item";	break;
				case 3: strElement = "itemsuffix1";	break;
				case 4: strElement = "itemsuffix2";	break;
				case 5: strElement = "key";	break;
				case 6: strElement = "value";	break;
				case 7:
				default:	strElement = "reserve";	break;
				}

				xmlWriter.writeStartElement(strElement);
				xmlWriter.writeCharacters (query.value(x).toString());
				xmlWriter.writeEndElement();
			}

			xmlWriter.writeEndElement();
		}

		xmlWriter.writeEndElement();
		xmlWriter.writeEndElement();
		xmlWriter.writeEndDocument();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
}

void qconfigmanage::toCSV(QString strTableName, QString strCSVDir)
{
	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		QString strFile = strCSVDir % "/" % strTableName % ".txt";
		QFile classFile(strFile);
		if(!classFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建文件失败"), strFile);
			break;
		}

		QTextStream ts (&classFile);

		QSqlQuery query(customdb);
		query.prepare("SELECT id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note FROM " % strTableName % " ORDER BY id ASC" );
		query.exec();

		while (query.next()){
			for(unsigned int x=0;	x<8;	++x){
				ts << query.value(x).toString() << "\t";
			}
			ts <<query.value(8).toString() << "\n";
		}

		classFile.close();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
}

void qconfigmanage::toDataBase(QString strDesPath, QString strTableName)
{
	QString strSrcPath	=	QDir::currentPath() % "/HisFX3Custom";
	if(isTableConflic(strTableName, strDesPath)){
		bool bReplace;
		if(QMessageBox::question(this, strTableName % QTextCodec::codecForName( "GBK")->toUnicode("已存在，是否替换???"), \
			QTextCodec::codecForName( "GBK")->toUnicode("替换请选择 \"是\"!!!\n\n不替换请选择\"否\"!!!"), \
			QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) bReplace = true;
		else bReplace = false;

		if(!bReplace) return;
		bool bDrop	=	deleteTable(strTableName, strDesPath);
		if(!bDrop){
			QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("删除原有参数失败"), strTableName);
			return;
		}
	}
	
	createAndCopyTable(strDesPath, strSrcPath, strTableName);
}

void qconfigmanage::createAndCopyTable(QString strDesDataBase, QString strSrcDatabase, QString strTableName)
{
	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(strDesDataBase);

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}
		QSqlQuery query(customdb);
		query.prepare("ATTACH '" % strSrcDatabase % "' AS thirddb");
		query.exec();

		query.prepare("create table " % strTableName % " as select * from thirddb." % strTableName % " ORDER BY id ASC");
		query.exec();

		query.prepare("DETACH thirddb");
		query.exec();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
}

bool qconfigmanage::isDatabase(QString strPath)
{
	QFile calssFile(strPath);
	if(!calssFile.open (QIODevice::ReadOnly | QIODevice::Text)){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("打开文件失败"), strPath);
		return false;
	}

	if(calssFile.size() < 6){
		calssFile.close();
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("类型错误"), QTextCodec::codecForName( "GBK")->toUnicode("此文件不是数据库文件"));
		return false;
	}

	QTextStream ts (&calssFile);
	QString strText	=	ts.read(6);
	calssFile.close();
	if(strText != "SQLite"){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("类型错误"), QTextCodec::codecForName( "GBK")->toUnicode("此文件不是数据库文件"));
		return false;
	}

	return true;
}

bool qconfigmanage::isSameFile(QString strPath)
{
	QString strScr	=	QDir::currentPath() % "/HisFX3Custom";
	if(strScr == strPath){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("路径冲突"), QTextCodec::codecForName( "GBK")->toUnicode("源文件和目的文件是同一个文件"));
		return true;
	}
	return false;
}

bool qconfigmanage::isTableExist(QString strTableName, QString strDataBase)
{
	if(strDataBase.isEmpty())
		strDataBase	=	QDir::currentPath() % "/HisFX3Custom";

	QStringList strConfigList;
	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(strDataBase);

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		strConfigList	=	customdb.tables();
		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
	if(!bparsesuccess)
		return false;
	return strConfigList.contains(strTableName);
}

bool qconfigmanage::isTableConflic(QString strTableName, QString str3rdBasePath)
{
	bool bExst1	=	isTableExist(strTableName, str3rdBasePath);
	bool bExst2	=	isTableExist(strTableName);
	if(bExst1 && bExst2) return true;
	if(!bExst1 && !bExst2) return true;
	return false;
}

bool qconfigmanage::deleteTable(QString strTableName, QString strDataBase)
{
	if(strDataBase.isEmpty())
		strDataBase	=	QDir::currentPath() % "/HisFX3Custom";

	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(strDataBase);

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与数据库的连接失败"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		QSqlQuery query(customdb);
		query.exec("drop table " % strTableName);
		query.exec();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
	if(!bparsesuccess)	return false;
	return true;
}

bool qconfigmanage::isTheCSV(QString strPath)
{
	QFile classFile(strPath);
	if(!classFile.open (QIODevice::ReadOnly | QIODevice::Text)){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("打开文件失败"), strPath);
		return false;
	}

	QTextStream ts (&classFile);
	QString strErrorText;
	bool bError	=	false;

	while(!ts.atEnd()){
		QStringList line = ts.readLine().split('\t');
		if(line.size() != 9){
			bError	=	true;
			qDebug() << "line count" << line.size();
			for(unsigned int x=0;	x<line.count();	++x)
			{
				qDebug() << x << ":" << line[x];
			}
			strErrorText	=	line.join("\t");
			break;
		}
	}

	classFile.close();
	if(bError){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("格式错误"), QTextCodec::codecForName( "GBK")->toUnicode("此CSV文件不符合Rolongo格式") % "\n\n" % strErrorText);
		return false;
	}
	return true;
}

bool qconfigmanage::isTheXML(QString strPath)
{
	QFile classFile(strPath);
	if(!classFile.open (QIODevice::ReadOnly | QIODevice::Text)){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("打开文件失败"), strPath);
		return false;
	}

	QXmlStreamReader xml(&classFile);
	bool bRolongo	=	false, bMain = false;

	while(!xml.atEnd()){
		if(xml.readNextStartElement())
		{
			if(xml.name() == "Rolongo") bRolongo = true;
			else if(xml.name() == "MainSection") bMain = true;

			if(bRolongo && bMain) break;
		}
		
	}

	if(!bRolongo || !bMain){
		QMessageBox::critical(this, QTextCodec::codecForName( "GBK")->toUnicode("格式错误"), QTextCodec::codecForName( "GBK")->toUnicode("此XML文件不符合Rolongo格式") % "\n\n" );
		return false;
	}
	return true;
}

void qconfigmanage::fromCSV(QString strCSV)
{
	QDir classDir(strCSV);
	QString strTableName	=	classDir.dirName();
	strTableName	=	strTableName.remove(".txt", Qt::CaseInsensitive);
	ui.info_label->setText(strTableName);
	bool bCopy	=	true;
	bool bReplace = false;
	if(isTableExist(strTableName)){
		if(QMessageBox::question(this, strTableName % QTextCodec::codecForName( "GBK")->toUnicode("已存在，是否替换???"), \
			QTextCodec::codecForName( "GBK")->toUnicode("替换请选择 \"是\"!!!\n\n不替换请选择\"否\"!!!"), \
			QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) bReplace = true; 
		else bReplace = false;
	}

	if(!bCopy)
		return;
	if(bReplace)
		deleteTable(strTableName, QDir::currentPath() % "/HisFX3Custom");

	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		QFile classFile(strCSV);
		if(!classFile.open(QIODevice::ReadOnly | QIODevice::Text)){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("打开文件失败"), strCSV);
			break;
		}

		QTextStream ts (&classFile);

		QSqlQuery query(customdb);

		query.exec("create table " % strTableName % " (id int,classfy varchar(128), "
			"item varchar(128), itemsuffix1 varchar(128),"
			"itemsuffix2 varchar(128), key varchar(128),"
			"value varchar(128), reserve varchar(128),"
			"note varchar(128))");

		customdb.transaction();

		QString req;
		QStringList line;
		while(!ts.atEnd()){
			req.clear();
			req = "INSERT INTO " % strTableName %  " VALUES(";
			line = ts.readLine().split('\t');
			for(unsigned int i=0; i<line.size();++i){
				req.append("'");
				req.append(line.at(i));
				req.append("'");
				req.append(",");
			}
			req.chop(1); 
			req.append(");");

//			query.prepare(req);
			query.exec(req);
		}

		customdb.commit();

		classFile.close();
		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
}

void qconfigmanage::fromXML(QString strCSV)
{
	QDir classDir(strCSV);
	QString strTableName	=	classDir.dirName();
	strTableName	=	strTableName.remove(".xml", Qt::CaseInsensitive);
	ui.info_label->setText(strTableName);
	bool bCopy	=	true;
	bool bReplace = false;
	if(isTableExist(strTableName)){
		if(QMessageBox::question(this, strTableName % QTextCodec::codecForName( "GBK")->toUnicode("已存在，是否替换???"), \
			QTextCodec::codecForName( "GBK")->toUnicode("替换请选择 \"是\"!!!\n\n不替换请选择\"否\"!!!"), \
			QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) bReplace = true; 
		else bReplace = false;
	}

	if(!bCopy)
		return;
	if(bReplace)
		deleteTable(strTableName, QDir::currentPath() % "/HisFX3Custom");

	bool bparsesuccess	=	true;
	for(unsigned int  w=0;	w<1;	++w)
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "custom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");

		if (!customdb.open()){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("创建与HisFX3Custom.s3db的连接"), (customdb.lastError()).text());
			bparsesuccess	=	false;
			break;
		}

		QFile classFile(strCSV);
		if(!classFile.open(QIODevice::ReadOnly | QIODevice::Text)){
			QMessageBox::warning(this, QTextCodec::codecForName( "GBK")->toUnicode("打开文件失败"), strCSV);
			break;
		}

		QXmlStreamReader xml(&classFile);

		QSqlQuery query(customdb);

		query.exec("create table " % strTableName % " (id int,classfy TEXT, "
			"item TEXT, itemsuffix1 TEXT,"
			"itemsuffix2 TEXT, key TEXT,"
			"value TEXT, reserve TEXT,"
			"note TEXT)");

		customdb.transaction();

		QString req;
		QStringList line;
		bool bMainSectionStart = false;
		QString id, classfy, item, itemsuffix1, itemsuffix2, key, value, reserve, note, strDBIndex;
		while(!xml.atEnd())
		{
			if(xml.readNextStartElement())
			{
				if(xml.name() == "MainSection") bMainSectionStart = true;
				else if(xml.name() == "OtherSection") break;

				if(bMainSectionStart)
				{
					if(xml.name() == "id") id = xml.readElementText();
					else if(xml.name() == "classfy") classfy = xml.readElementText();
					else if(xml.name() == "item") item = xml.readElementText();
					else if(xml.name() == "itemsuffix1") itemsuffix1 = xml.readElementText();
					else if(xml.name() == "itemsuffix2") itemsuffix2 = xml.readElementText();
					else if(xml.name() == "key") key = xml.readElementText();
					else if(xml.name() == "value") value = xml.readElementText();
					else if(xml.name() == "reserve") reserve = xml.readElementText();

// 					qDebug() << xml.name();

					if(xml.name().contains("DBIndex"))
					{
						if(!strDBIndex.isEmpty())
						{
							req.clear();
							req = "INSERT INTO " % strTableName %  " VALUES('" % id % "','"  % classfy % "','"  % item % "','"  % itemsuffix1 % "','"  % itemsuffix2 % "','"  % key % "','"  % value % "','"  % reserve % "','"  % note % "');" ;
							query.exec(req);
// 							qDebug() << req;
							id.clear(); classfy.clear(); item.clear(); itemsuffix1.clear(); itemsuffix2.clear(); key.clear(); value.clear(); reserve.clear(); note.clear(); 
						}

						strDBIndex	=	xml.name().toString();
					}
				}
			}

		}

		if(!id.isEmpty() || !classfy.isEmpty() || !item.isEmpty() || !itemsuffix1.isEmpty() || !itemsuffix2.isEmpty() || !key.isEmpty() || !value.isEmpty() || !reserve.isEmpty() || !note.isEmpty())
		{
			req.clear();
			req = "INSERT INTO " % strTableName %  " VALUES('" % id % "','"  % classfy % "','"  % item % "','"  % itemsuffix1 % "','"  % itemsuffix2 % "','"  % key % "','"  % value % "','"  % reserve % "','"  % note % "');" ;
			query.exec(req);
			id.clear(); classfy.clear(); item.clear(); itemsuffix1.clear(); itemsuffix2.clear(); key.clear(); value.clear(); reserve.clear(); note.clear(); 
		}

		customdb.commit();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("custom");
}

void qconfigmanage::textSelected( const QString &)
{
	if(!timerSearch.isActive()) 
	{
		strOrignalText = ui.serachlineEdit->text();
		classTime.start();
		timerSearch.start(200);
	}
}

void qconfigmanage::slotSearchText()
{
	if(classTime.elapsed() < 500)
	{
		if(strOrignalText != ui.serachlineEdit->text()) {
			strOrignalText	=	ui.serachlineEdit->text();
			classTime.restart();
		}
	}
	else
	{
		timerSearch.stop();
		freshConfigList();		
	}

}