#include "jsl_burnstate.h"
#include "itemprocess.h"
#include "shellapi.h"

jsl_burnState::jsl_burnState(int configtype,QWidget *parent)
	: QDockWidget(parent),parentWid(parent)
{

	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("数据统计"));

#if 1
	//QShortcutList
	//Qt::FramelessWindowHint
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setWindowOpacity(1);
	label=new QLabel();
	lab_Count=new QLabel();
	QPushButton *butExport=new QPushButton(QString::fromLocal8Bit("批号切换"));
	connect(butExport,SIGNAL(pressed()),this,SLOT(slot_BurnDataExport()));

	QWidget *burnWidget=new QWidget();
	burnWidget->setWindowTitle(QString::fromLocal8Bit("烧录面板"));
	vlayout=new QVBoxLayout;
	label->setText(QString::fromLocal8Bit("流程卡号:")+GetLotSN());
	lab_Count->setText(QString::fromLocal8Bit("数据显示："));
	lab_Count->setHidden(true);
	burnWidget->setStyleSheet("color:rgb(0,0,150);border:1px solid black;font: 105 20pt 'Agency FB';");
	vlayout->addWidget(label);
	vlayout->addWidget(lab_Count);
	vlayout->addWidget(butExport);
	burnWidget->setLayout(vlayout);

	
#endif
	widget=new QWidget();
	hlayout=new QHBoxLayout();
	tab=new QTableWidget(24,5);
	hlayout->addWidget(tab,5);
	widget->setLayout(hlayout);

	QTabWidget *tabwidget=new QTabWidget();
	tabwidget->addTab(burnWidget,QString::fromLocal8Bit("烧录计数"));
	tabwidget->addTab(widget,QString::fromLocal8Bit("小时计数"));
	setWidget(tabwidget);
	
	QStringList headlist;
	headlist<<QString::fromLocal8Bit("工号")<<QString::fromLocal8Bit("计划数")<<\
		QString::fromLocal8Bit("产出数")<<QString::fromLocal8Bit("不良数")<<QString::fromLocal8Bit("达成率");
	tab->setHorizontalHeaderLabels(headlist);
	

	headlist.clear();
	headlist<<"0:00~0:59"<<"1:00~1:59"<<"2:00~2:59"<<"3:00~3:59"<<"4:00~4:59"<<"5:00~5:59"<<"6:00~6:59"<<"7:00~7:59"<<"8:00~8:59"<<"9:00~9:59"<<"10:00~10:59"<<"11:00~11:59"\
		<<"12:00~12:59"<<"13:00~13:59"<<"14:00~14:59"<<"15:00~15:59"<<"16:00~16:59"<<"17:00~17:59"<<"18:00~18:59"<<"19:00~19:59"<<"20:00~20:59"<<"21:00~21:59"<<"22:00~22:59"<<"23:00~23:59";
	tab->setVerticalHeaderLabels(headlist);

	tab->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tab->setSelectionMode(QAbstractItemView::SingleSelection); 
	tab->setSelectionBehavior(QAbstractItemView::SelectRows);

	//**************** NgTable ******************
	NgTab=new QTableWidget(24,23);
	NgTab->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	NgTab->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//NgTab->setAttribute(Qt::WA_DeleteOnClose);
	NgTab->setWindowFlags(Qt::WindowStaysOnTopHint);

	QString str=QString::fromLocal8Bit("调焦<<近焦<<中焦<<远焦<<开短路<<工作电流<<待机电流<<出图<<脏污<<死点<<光心<<暗角<<光晕<<颜色<<线条<<亮点<<OTP烧录<<OTP检测<<AF烧录<<AF检测<<PDAF烧录<<PDAF检测<<其它");
	QStringList list=str.split("<<");
	NgTab->setHorizontalHeaderLabels(list);
	NgTab->setVerticalHeaderLabels(QStringList()<<"0:00~0:59"<<"1:00~1:59"<<"2:00~2:59"<<"3:00~3:59"<<"4:00~4:59"<<"5:00~5:59"<<"6:00~6:59"<<"7:00~7:59"<<"8:00~8:59"<<"9:00~9:59"<<"10:00~10:59"<<"11:00~11:59"\
		<<"12:00~12:59"<<"13:00~13:59"<<"14:00~14:59"<<"15:00~15:59"<<"16:00~16:59"<<"17:00~17:59"<<"18:00~18:59"<<"19:00~19:59"<<"20:00~20:59"<<"21:00~21:59"<<"22:00~22:59"<<"23:00~23:59");
	
	connect(NgTab,SIGNAL(itemSelectionChanged()),this,SLOT(slot_ShowNgTableSelect()));

	//**************** Plot *********************
	plot=new QCustomPlot();
	hlayout->addWidget(plot,5);
	plot->xAxis->setLabel(QString::fromLocal8Bit("时段"));
	plot->yAxis->setLabel(QString::fromLocal8Bit("达成率"));
	plot->xAxis->setRange(0,24);
	plot->yAxis->setRange(0,3);
	plot->xAxis->setSubTicks(true);
	
	plot->addGraph();
	plot->legend->setVisible(false);
	plot->graph(0)->setName("达成率");
	plot->setInteractions(QCP::iSelectOther | QCP::iSelectPlottables | QCP::iSelectItems |  QCP::iSelectAxes );
	plot->xAxis->setSelectedLabelColor(QColor(255, 0, 0));
	plot->graph(0)->setSelectable(QCP::stMultipleDataRanges);
	
	connect(tab,SIGNAL(cellChanged(int ,int)),this,SLOT(slot_UpdatePlot(int ,int)));
	connect(tab,SIGNAL(itemDoubleClicked(QTableWidgetItem *)),this,SLOT(slot_ShowNgData(QTableWidgetItem *)));
	//**************************
	QStringList listOK,listNG;
	ROPLOW::getFocusDataFromDB(QDate::currentDate(),listOK,listNG);
	slot_ToPanel(listOK,listNG);
}

jsl_burnState::~jsl_burnState()
{
	

}

void jsl_burnState::slot_UpdatePlot(int row,int col){
	QVector<qreal> key;
	QVector<qreal> val;
	val.push_back(1);
	key.push_back(0);

	for (int r=0;r<tab->rowCount();r++)
	{
		if(tab->item(r,4)!=NULL){
			val.push_back(tab->item(r,2)->text().toDouble()/tab->item(r,1)->text().toDouble());
			key.push_back(r+1);
		}
	}
	plot->graph(0)->setData(key,val);
	plot->replot();
}

void jsl_burnState::slot_ToPanel(QStringList listOK,QStringList listNG){
	for (int i=0;i<listOK.size();i++)
	{
		tab->setItem(i,0,new QTableWidgetItem(""));
		tab->setItem(i,1,new QTableWidgetItem("100"));
		tab->setItem(i,2,new QTableWidgetItem(listOK.at(i)));
		tab->setItem(i,3,new QTableWidgetItem(listNG.at(i)));
		tab->setItem(i,4,new QTableWidgetItem(QString::number(listOK.at(i).toDouble()/100,'f',2)+"%"));
	}


	emit slot_UpdatePlot(1,1);
}

QString jsl_burnState::GetLotSN(){
	QSqlDatabase sqlDatabase=QSqlDatabase::addDatabase("QSQLITE","db");
	sqlDatabase.setDatabaseName("JSL_OtpCount");
	if (!sqlDatabase.open()){
		QMessageBox::warning(this,"DataBase Open Fail!","DataBase Open Fail!");
	}

	QSqlQuery query(sqlDatabase);
	query.prepare("select LotSN from CurrentBurnLotSN where 1");
	if(!query.exec()){
		QMessageBox::warning(this,"Error",query.lastError().text());
	}

	if(!query.next()){
		return "";
	}

	sqlDatabase.removeDatabase("db");
	sqlDatabase.close();

	return query.value(0).toString();
	

}

int jsl_burnState::GetLotNum(){
	int iResult=0;
	QSqlDatabase sqlDatabase=QSqlDatabase::addDatabase("QSQLITE","db2");
	sqlDatabase.setDatabaseName("JSL_OtpCount");
	if (!sqlDatabase.open()){
		QMessageBox::warning(this,"DataBase Open Fail!","DataBase Open Fail!");
	}

	QSqlQuery query(sqlDatabase);
	QString sql="select count(ChipID) from ["+GetLotSN()+"] where 1";
	query.prepare(sql);
	if(query.exec()){
		if(query.next())
			iResult=query.value(0).toInt();
	}

	sqlDatabase.removeDatabase("db2");
	sqlDatabase.close();
	return iResult;
}

void jsl_burnState::slotBurnCount(){
	label->setText(QString::fromLocal8Bit("流程卡号:")+GetLotSN());
	lab_Count->setText(QString::fromLocal8Bit("数据显示"));
}

void jsl_burnState::mouseDoubleClickEvent(QMouseEvent *event){
	/*if (event->button()==Qt::LeftButton)
	{
		loginDlg->exec();
	}*/
}

void jsl_burnState::mouseMoveEvent(QMouseEvent *event){
	//event->pos();
}

void jsl_burnState::slot_ShowNgData(QTableWidgetItem *item){
	if(item->column()==3){
		for (int r=0;r<24;r++)
		{
			QString strbegin=QString("%1:00:00").arg(r);
			QString strend=QString("%1:59:59").arg(r);
			QList<int> key,value;
			ROPLOW::getFocusDataFromDB(QDate::currentDate(),strbegin,strend,key,value);
			for (int i=0;i<key.size();i++)
			{
				int ngType=key.at(i);
				switch(ngType){
				case 1:
					NgTab->setItem(r,0,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 2:
					NgTab->setItem(r,1,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 3:
					NgTab->setItem(r,2,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 4:
					NgTab->setItem(r,3,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 5:
					NgTab->setItem(r,4,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 6:
					NgTab->setItem(r,5,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 7:
					NgTab->setItem(r,6,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 8:
					NgTab->setItem(r,7,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 9:
					NgTab->setItem(r,8,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 10:
					NgTab->setItem(r,9,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 11:
					NgTab->setItem(r,10,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 12:
					NgTab->setItem(r,11,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 13:
					NgTab->setItem(r,12,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 14:
					NgTab->setItem(r,13,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 15:
					NgTab->setItem(r,14,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 16:
					NgTab->setItem(r,15,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 17:
					NgTab->setItem(r,16,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 18:
					NgTab->setItem(r,17,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 19:
					NgTab->setItem(r,18,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 20:
					NgTab->setItem(r,19,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 21:
					NgTab->setItem(r,20,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 22:
					NgTab->setItem(r,21,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				case 23:
					NgTab->setItem(r,22,new QTableWidgetItem(QString::number(value.at(i))));
					break;
				}
			}

		}

		

		NgTab->show();
	}
}

void jsl_burnState::slot_ShowNgTableSelect(){
	QList<QTableWidgetItem*> listItem=NgTab->selectedItems();
	double dSum=0,dAve=0;
	for (int i=0;i<listItem.size();i++)
	{
		dSum+=listItem.at(i)->text().toDouble();
	}
	if(dSum)
		dAve=dSum/listItem.size();
	NgTab->setWindowTitle(QString("Sum=%1,Ave=%2").arg(dSum).arg(dAve));
}

void jsl_burnState::enterEvent(QEvent *evt){
	
}

void jsl_burnState::leaveEvent(QEvent *evt){

}

void jsl_burnState::slot_test(QqrealList key){
	QMessageBox::warning(this,"test",QString("size:%1").arg(key.size()));
}

void jsl_burnState::slot_BurnDataExport(){
	jsl_bindSerialNumber wid(1);
	wid.exec();
	slotBurnCount();




	/*QString strPath=QFileDialog::getSaveFileName(this,"","",QString::fromLocal8Bit("逗号分隔文件|*.csv"));
	if(strPath.isEmpty()){
		QMessageBox::warning(this,QString::fromLocal8Bit("未填写要保存的文件名"),QString::fromLocal8Bit("请填写要保存的文件名！"));
		return ;
	}*/
		
	/*QDir dir;
	dir.mkdir("savelog");
	QString strPath=QString("%1/savelog/%2.csv").arg(QDir::currentPath()).arg(GetLotSN());
	
	QSqlDatabase sqlDatabase=QSqlDatabase::addDatabase("QSQLITE","db2");
	sqlDatabase.setDatabaseName("JSL_OtpCount");
	if (!sqlDatabase.open()){
		QMessageBox::warning(this,"DataBase Open Fail!","DataBase Open Fail!");
	}

	QSqlQuery query(sqlDatabase);
	QString sql="select * from ["+GetLotSN()+"] where 1";
	query.prepare(sql);
	if(query.exec()){
		QFile file(strPath);
		if(!file.open(QIODevice::ReadWrite)){
			QMessageBox::warning(this,"Error","Create File Fail!");
			return ;
		}

		file.write("ChipID,LotSN,UnitRG,UnitBG,UnitG,Note\n");
		while(query.next()){
			QString strNote;
			if(query.value(5).toInt()>1){
				strNote=QString("'%1%1%1%1%1%1%1%1").arg(query.value(5).toInt());
			}
			QString strTemp=QString("#%1,%2,%3,%4,%5,%6\n").arg(query.value(0).toString()).arg(query.value(1).toString())\
				.arg(query.value(2).toInt()).arg(query.value(3).toInt()).arg(query.value(4).toInt()).arg(strNote);

			file.write(strTemp.toLatin1());
		}

		file.close();
	}

	sqlDatabase.removeDatabase("db2");
	sqlDatabase.close();

	ShellExecute(0, L"open", strPath.toStdWString().data(), 0, 0, 1); 
	qApp->exit();*/
}