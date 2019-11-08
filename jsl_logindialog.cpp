#include "jsl_logindialog.h"
#include "QHMainWindow.h"

using namespace rapidjson;

jsl_loginDialog::jsl_loginDialog(QWidget *parent):QDialog(parent)
{
	ui.setupUi(this);
	m_plabLogin=new QLabel(QTextCodec::codecForName("GBK")->toUnicode("流转号:"));
	m_plabSta=new QLabel(QTextCodec::codecForName("GBK")->toUnicode("工站号:"));
	m_plabJob=new QLabel(QTextCodec::codecForName("GBK")->toUnicode("员工号:"));
	m_plabLine=new QLabel(QTextCodec::codecForName("GBK")->toUnicode("线别:"));

	m_pleLot=new QLineEdit();
	m_pleSta=new QLineEdit();
	m_pleJob=new QLineEdit();
	m_pleLine=new QLineEdit();

	m_pbutCommit=new QPushButton(QString::fromLocal8Bit("提交"));
	m_pbutQuit=new QPushButton(QString::fromLocal8Bit("退出"));

	QVBoxLayout *vlayout=new QVBoxLayout;
	QHBoxLayout *hlayout1=new QHBoxLayout;
	QHBoxLayout *hlayout2=new QHBoxLayout;
	QHBoxLayout *hlayout3=new QHBoxLayout;
	QHBoxLayout *hlayout4=new QHBoxLayout;
	QHBoxLayout *hlayout5=new QHBoxLayout;

	hlayout1->addWidget(m_plabLogin,2);
	hlayout1->addWidget(m_pleLot);
	hlayout2->addWidget(m_plabSta,2);
	hlayout2->addWidget(m_pleSta);
	hlayout3->addWidget(m_plabJob,2);
	hlayout3->addWidget(m_pleJob);
	hlayout4->addWidget(m_plabLine,2);
	hlayout4->addWidget(m_pleLine);
	//hlayout5->addWidget(m_pbutCommit);
	hlayout5->addWidget(m_pbutQuit);

	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);
	vlayout->addLayout(hlayout3);
	vlayout->addLayout(hlayout4);
	//vlayout->addLayout(hlayout5);

	setLayout(vlayout);
	connect(m_pbutQuit,SIGNAL(clicked()),this,SLOT(slot_onQuit()));

	connect(m_pleLine,SIGNAL(returnPressed()),this,SLOT(slot_onCommit()));

	connect(m_pleLot,SIGNAL(returnPressed()),this,SLOT(slot_changePos1()));
	connect(m_pleSta,SIGNAL(returnPressed()),this,SLOT(slot_changePos2()));
	connect(m_pleJob,SIGNAL(returnPressed()),this,SLOT(slot_changePos3()));

}

jsl_loginDialog::~jsl_loginDialog()
{
	
}

void jsl_loginDialog::slot_onQuit(){
	qApp->quit();
	//qApp->exit();
}

void jsl_loginDialog::slot_onCommit(){
	if(m_pleLot->text().isEmpty()||m_pleSta->text().isEmpty()||m_pleJob->text().isEmpty()||m_pleLine->text().isEmpty()){
		QMessageBox::about(this,QString::fromLocal8Bit("数据填写不完整"),QString::fromLocal8Bit("数据填写不完整"));
		return ;
	}
	SetLotSN(m_pleLot->text());
	QDir::current().mkdir("OtpLog");

	//************************** Create Json *******************************
	QFile filejson("MES_Config.json");
	if(!filejson.open(QIODevice::ReadWrite)){
		QMessageBox::warning(this,"Error",QTextCodec::codecForName("GBK")->toUnicode("错误：读取 C:/Mes_config.json Fail!！"));
	}
	
	//QMessageBox::warning(this,"Error",pucBuffer);

	rapidjson::Document doc;
	doc.Parse(filejson.readAll().data());
	filejson.close();
	if(doc.HasParseError()){
		QMessageBox::warning(this,"Error",QTextCodec::codecForName("GBK")->toUnicode("错误：解析Mes_config.json失败！"));
	}

	if(doc.HasMember("Process")){
		sprintf(global_strProcess,"%s",doc["Process"].GetString());
	}else{
		QMessageBox::warning(this,"Error",QTextCodec::codecForName("GBK")->toUnicode("错误：解析Mes_config.json Process时失败！"));
	}
		
	sprintf(global_strLotNumber,"%s",m_pleLot->text().toLatin1().data());
	sprintf(global_strStaNumber,"%s",m_pleSta->text().toLatin1().data());
	sprintf(global_strJobNumber,"%s",m_pleJob->text().toLatin1().data());
	sprintf(global_strLineNumber,"%s",m_pleLine->text().toLatin1().data());

	//*****  Create Database Table ***************
	QSqlDatabase dbLotSN = QSqlDatabase::addDatabase("QSQLITE", "dbLotSN");
	//dbLotSN.setDatabaseName(QDir::currentPath() + "/JSL_OtpCount");
	dbLotSN.setDatabaseName("JSL_OtpCount");
	if (!dbLotSN.open()){
		QMessageBox::warning(this,"DataBase Open Fail!","DataBase Open Fail!");
		return ;
	}

	QSqlQuery query(dbLotSN);
	//********************* tab1 **************
	query.prepare("select * from sqlite_master where type = 'table' and name=:name");
	query.bindValue(":name",m_pleLot->text());
	if(!query.exec()){
		QMessageBox::warning(this,"Error",query.lastError().text());
	}

	if(!query.next()){
		query.prepare("Create Table ["+m_pleLot->text()+"] (ChipID varchar(1,50) not null primary key,LotSN varchar(1,50) not null,\
															UnitRG int not null,UnitBG int not null,UnitG int not null,Note int not null)" );

		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}
	}
	
	//***************** tab2 **************
	query.prepare("select * from sqlite_master where type = 'table' and name=:name");
	query.bindValue(":name","CurrentBurnLotSN");
	if(!query.exec()){
		QMessageBox::warning(this,"Error",query.lastError().text());
	}

	if(!query.next()){
		query.prepare("Create Table [CurrentBurnLotSN] (LotSN varchar(1,30) not null primary key)" );
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}

		query.prepare("Insert into CurrentBurnLotSN values('"+m_pleLot->text()+"')" );
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}

	}else{
		query.prepare("update CurrentBurnLotSN set LotSN='"+m_pleLot->text()+"' where 1" );
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}
	}

	query.clear();
	dbLotSN.close();
	QSqlDatabase::removeDatabase("dbLotSN");
	
	emit sig_reLotSN();
	close();
}

jsl_bindSerialNumber::jsl_bindSerialNumber(int nType,QWidget *parent):QDialog(parent),ledit(new QLineEdit),m_nType(nType)
{
	setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);

	if(nType){
		setWindowTitle(QTextCodec::codecForName("GBK")->toUnicode("请扫描流程卡号"));
	}else{
		setWindowTitle(QTextCodec::codecForName("GBK")->toUnicode("请扫描产品二维码"));
	}

	m_sock=NULL;
	QHBoxLayout *layout=new QHBoxLayout();
	setLayout(layout);

	layout->addWidget(ledit);
	connect(ledit,SIGNAL(returnPressed()),this,SLOT(slotReturn()));
}

jsl_bindSerialNumber::~jsl_bindSerialNumber()
{

}

void jsl_bindSerialNumber::closeEvent(QCloseEvent *evt){
	/*if(ledit->text().isEmpty()||ledit->text().length()==0){
		if(!global_ioc_x)global_ioc_x=-1;
	}else{
		global_ioc_x=1;
	}*/

	//ledit->clear();
}
void jsl_bindSerialNumber::setSerialNumber(QString str){
	strSN=str;
}
void jsl_bindSerialNumber::slotReturn(){
	if(m_nType){
		//*****  Create Database Table ***************
		QSqlDatabase dbLotSN = QSqlDatabase::addDatabase("QSQLITE", "dbLotSN");
		//dbLotSN.setDatabaseName(QDir::currentPath() + "/JSL_OtpCount");
		dbLotSN.setDatabaseName("JSL_OtpCount");
		if (!dbLotSN.open()){
			QMessageBox::warning(this,"DataBase Open Fail!","DataBase Open Fail!");
			return ;
		}


		QSqlQuery query(dbLotSN);
		//********************* tab1 **************
		query.prepare("select * from sqlite_master where type = 'table' and name=:name");
		query.bindValue(":name",ledit->text());
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}

		if(!query.next()){
			query.prepare("Create Table ["+ledit->text()+"] (ChipID varchar(1,50) not null primary key,LotSN varchar(1,50) not null,\
																UnitRG int not null,UnitBG int not null,UnitG int not null,Note int not null)" );

			if(!query.exec()){
				QMessageBox::warning(this,"Error",query.lastError().text());
			}
		}
	
		//***************** tab2 **************
		query.prepare("select * from sqlite_master where type = 'table' and name=:name");
		query.bindValue(":name","CurrentBurnLotSN");
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}

		if(!query.next()){
			query.prepare("Create Table [CurrentBurnLotSN] (LotSN varchar(1,30) not null primary key)" );
			if(!query.exec()){
				QMessageBox::warning(this,"Error",query.lastError().text());
			}

			query.prepare("Insert into CurrentBurnLotSN values('"+ledit->text()+"')" );
			if(!query.exec()){
				QMessageBox::warning(this,"Error",query.lastError().text());
			}

		}else{
			query.prepare("update CurrentBurnLotSN set LotSN='"+ledit->text()+"' where 1" );
			if(!query.exec()){
				QMessageBox::warning(this,"Error",query.lastError().text());
			}
		}

		query.clear();
		dbLotSN.close();
		QSqlDatabase::removeDatabase("dbLotSN");

		memset(global_strLotNumber,0,1024);
		sprintf(global_strLotNumber,"%s",ledit->text().toLatin1().data());

		ledit->clear();
		this->close();
		return ;
	}

	memset(global_strSN,0,1024);
	sprintf(global_strSN,"%s",ledit->text().toLatin1().data());
	emit information(ledit->text());

	memset(global_strSN,0,1024);
	if(ledit->text().isEmpty()||ledit->text().length()==0){
		return;
	}
	sprintf(global_strSN,"%s",ledit->text().toLatin1().data());

	
	global_ioc_x=1;
	ledit->clear();
	this->close();
}

//*********************************************************
jsl_debugBurn::jsl_debugBurn(QWidget *parent /* = 0 */):QDialog(parent){
	box1=new QSpinBox();
	box2=new QSpinBox();
	box3=new QSpinBox();
	box4=new QSpinBox();
	butCommit=new QPushButton(tr("Commit"));

	box1->setRange(0,0xFFFF);
	box2->setRange(0,0xFFFF);
	box3->setRange(0,0xFFFF);
	box4->setRange(0,0xFFFF);

	QVBoxLayout *vlayout=new QVBoxLayout;
	vlayout->addWidget(box1);
	vlayout->addWidget(box2);
	vlayout->addWidget(box3);
	vlayout->addWidget(box4);
	vlayout->addWidget(butCommit);

	this->setLayout(vlayout);
	connect(butCommit,SIGNAL(pressed()),this,SLOT(slot_onCommit()));
}

jsl_debugBurn::~jsl_debugBurn(){

}

void jsl_debugBurn::slot_onCommit(){
	debugBurnValue1=box1->value();
	debugBurnValue2=box2->value();
	debugBurnValue3=box3->value();
	debugBurnValue4=box4->value();

	global_ioc_x=1;
	close();
}

void jsl_debugBurn::closeEvent(QCloseEvent *evt){


}

