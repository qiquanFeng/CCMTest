#include "jsl_logindialog.h"
#include "QHMainWindow.h"

using namespace rapidjson;

jsl_loginDialog::jsl_loginDialog(QWidget *parent):QDialog(parent)
{
	ui.setupUi(this);
	m_plabLogin=new QLabel(QString::fromLocal8Bit("流转卡号："));
	m_plineLogin=new QLineEdit();
	m_pbutSubmit=new QPushButton(QString::fromLocal8Bit("提交"));
	m_pbutQuit=new QPushButton(QString::fromLocal8Bit("退出"));
	m_pHLayout=new QHBoxLayout();
	
	m_pHLayout->addWidget(m_plabLogin);
	m_pHLayout->addWidget(m_plineLogin,5);
	m_pHLayout->addWidget(m_pbutSubmit);
	m_pHLayout->addWidget(m_pbutQuit);

	setLayout(m_pHLayout);
	setFixedHeight(50);

	connect(m_pbutQuit,SIGNAL(clicked()),this,SLOT(slot_onQuit()));
	connect(m_pbutSubmit,SIGNAL(clicked()),this,SLOT(slot_onSubmit()));
}

jsl_loginDialog::~jsl_loginDialog()
{
	
}

void jsl_loginDialog::slot_onQuit(){
	qApp->quit();
	//qApp->exit();
}

void jsl_loginDialog::slot_onSubmit(){
	if(m_plineLogin->text().isEmpty()){
		QMessageBox::about(this,QString::fromLocal8Bit("请输入流转卡号"),QString::fromLocal8Bit("请输入流转卡号"));
		return ;
	}
	SetLotSN(m_plineLogin->text());
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
	query.bindValue(":name",m_plineLogin->text());
	if(!query.exec()){
		QMessageBox::warning(this,"Error",query.lastError().text());
	}

	if(!query.next()){
		query.prepare("Create Table ["+m_plineLogin->text()+"] (ChipID varchar(1,50) not null primary key,LotSN varchar(1,50) not null,\
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

		query.prepare("Insert into CurrentBurnLotSN values('"+m_plineLogin->text()+"')" );
		if(!query.exec()){
			QMessageBox::warning(this,"Error",query.lastError().text());
		}

	}else{
		query.prepare("update CurrentBurnLotSN set LotSN='"+m_plineLogin->text()+"' where 1" );
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
	if(ledit->text().isEmpty()||ledit->text().length()==0){
		if(!global_ioc_x)global_ioc_x=-1;
	}else{
		global_ioc_x=1;
	}

	ledit->clear();
}
void jsl_bindSerialNumber::setSerialNumber(QString str){
	strSN=str;
}
void jsl_bindSerialNumber::slotReturn(){
	
	memset(global_strSN,0,1024);
	if(ledit->text().isEmpty()||ledit->text().length()==0){
		return;
	}
	sprintf(global_strSN,"%s",ledit->text().toLatin1().data());

	this->close();
}
int jsl_bindSerialNumber::init(SOCKET &sockClient,char *pcIP, int nPort){
	int result=0;

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err)return 0;
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return -1;
	}

	//***********************  
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr(pcIP);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(nPort);

	unsigned long ul = 1;
	ioctlsocket(sockClient, FIONBIO, &ul);

	if (::connect(sockClient, (sockaddr*)&addrSrv, sizeof(sockaddr))) {
		fd_set writefds,expectfds;
		struct timeval tv;
		tv.tv_sec = 2;
		tv.tv_usec = 0;
		FD_ZERO(&writefds);
		FD_ZERO(&expectfds);
		FD_SET(sockClient,&writefds);
		FD_SET(sockClient,&expectfds);
		result = select(0, NULL, &writefds, &expectfds, &tv);
	}

	if(result>0){
		ul = 0;
		ioctlsocket(sockClient, FIONBIO, &ul);
		result=0;
	}else{
		closesocket(sockClient);
		result=-1;
	}

	return result;
}
int jsl_bindSerialNumber::commit(IN SOCKET &sock,IN char *pucSendBuff,OUT char *pucRecvBuff){
	int iresult = -1;
	char pcSendBuff[8912] = { 0 };
	char pcRecvBuff[8912] = { 0 };

	sprintf(pcSendBuff, "POST /api/action2? HTTP/1.1\n\
Host: 192.168.10.15:8000\n\
Connection: keep-alive\n\
Content-Length: %d\n\
Accept: */*\n\
Content-Type: application/json\n\
Accept-Encoding: gzip, deflate\n\
Accept-Language: zh-CN,zh;q=0.9\n\
\n%s",strlen(pucSendBuff),pucSendBuff);

	int len=send(sock, pcSendBuff, strlen(pcSendBuff), 0);

	len=recv(sock, pcRecvBuff, 8912, 0);
	if(len<=0)
		return -1;

	for (int i = 0; i < len; i++)
	{
		if (*(pcRecvBuff + i) == 0x0d) {
			if (*(pcRecvBuff + i + 1) == 0x0a)
				if (*(pcRecvBuff + i + 2) == 0x0d)
					if (*(pcRecvBuff + i + 3) == 0x0a)
						sprintf(pucRecvBuff, "%s", pcRecvBuff + i);
		}
	}

	Document doc;
	doc.Parse(pucRecvBuff);

	if (doc.IsArray()) {
		Value &rootObj = doc.GetArray()[0];
		assert(rootObj.IsObject());
		if (rootObj.HasMember("DoResult")) {
			if (rootObj["DoResult"].IsBool())
				iresult = 0;
		}
	}
	else {
		const Value &rootObj = doc.GetObjectW();
		assert(rootObj.IsObject());
		if (rootObj.HasMember("ErrorCode")) {
			iresult = -1;
		}
	}
	return 0;
}
int jsl_bindSerialNumber::clean(SOCKET* pSocket){
	return closesocket(*pSocket); 
}