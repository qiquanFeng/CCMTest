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
	hlayout5->addWidget(m_pbutCommit);
	hlayout5->addWidget(m_pbutQuit);

	vlayout->addLayout(hlayout1);
	vlayout->addLayout(hlayout2);
	vlayout->addLayout(hlayout3);
	vlayout->addLayout(hlayout4);
	vlayout->addLayout(hlayout5);

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
	if(m_pleLot->text().isEmpty()){
		QMessageBox::about(this,QString::fromLocal8Bit("请输入流转卡号"),QString::fromLocal8Bit("请输入流转卡号"));
		return ;
	}
	SetLotSN(m_pleLot->text());
	QDir::current().mkdir("OtpLog");

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

jsl_bindSerialNumber::jsl_bindSerialNumber(QWidget *parent):QDialog(parent),ledit(new QLineEdit)
{
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
	char *post1=(char*)malloc(8192);
	char *post2=(char*)malloc(8192);
		
	sprintf(post1,"{\n\
				  \"JsonData\":[\n\
				  {\n\
				  \"SN\": \"%s\",\n\
				  \"SensorID\": \"%s\",\n\
				  \"Process\": \"TJ\"\n\
				  }\n\
				  ],\n\
				  \"OrgId\": 33,\n\
				  \"ActionName\": \"xiaozhi.Action.MES.External.ProcessCheck\",\n\
				  \"ActionAssembly\": \"xiaozhi.Action.MES\"\n\
				  }",ledit->text().toLatin1().data(),this->strSN.toLatin1().data()); //  防过站检查

	sprintf(post2,"{\n\
				  \"JsonData\":[\n\
				  {\n\
				  \"IsCheck\":0,\
				  \"IsOK\":1,\
				  \"NGMessage\":\"MES001\",\
				  \"Operator\":\"22628\",\
				  \"Line\": \"line001\",\n\
				  \"WorkStation\": \"TJ1\",\n\
				  \"Process\": \"TJ\",\n\
				  \"IP\": \"192.168.10.237\",\n\
				  \"MAC\": \"11:11:11:11:11\",\n\
				  \"DocNo\": \"z-97017-190725-001@1\",\n\
				  \"SN\": \"20190923000000001\",\n\
				  \"SensorID\": \"ID20190923000000001\",\n\
				  \"TestData\": \"Center_left,30;Center_right,30;FOV1,0.3452\"\n\
				  }\n\
				  ],\n\
				  \"OrgId\": 33,\n\
				  \"ActionName\": \"xiaozhi.Action.MES.External.AddProcessRd\",\n\
				  \"ActionAssembly\": \"xiaozhi.Action.MES\"\n\
				  }");


	



	std::string str=post(std::string(post1));
	emit information(QTextCodec::codecForName("GBK")->toUnicode(str.c_str()));

	if(QString::fromStdString(str).lastIndexOf("true")<0){
		emit information("Error:mes check fail!");
		global_ioc_x=-1;
		this->close();
		return;
	}
	
	str=post(std::string(post2));
	emit information(QTextCodec::codecForName("GBK")->toUnicode(str.c_str()));
	
	memset(global_strSN,0,1024);
	if(ledit->text().isEmpty()||ledit->text().length()==0){
		return;
	}
	sprintf(global_strSN,"%s",ledit->text().toLatin1().data());

	free(post1);
	free(post2);
	
	global_ioc_x=1;
	ledit->clear();
	this->close();

}