#include "jsl_controlpanel.h"
#include "globaldefine.h"


#if (defined USE_EQUIPMENT_AFM_JSL_V2)
jsl_controlpanel::jsl_controlpanel(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	labAxis1=new QLabel(tr("Axis1(Y)"));
	labAxis2=new QLabel(tr("Axis2(X)"));
	labAxis3=new QLabel(tr("Axis3(Z)"));
	labAxis4=new QLabel(tr("Axis4(X&)"));
	labAxis5=new QLabel(tr("Axis5(Y&)"));

	leAxis1=new QSpinBox();leAxis1->setMaximum(1000000);leAxis1->setMinimum(-1000000);
	leAxis2=new QSpinBox();leAxis2->setMaximum(1000000);leAxis2->setMinimum(-1000000);
	leAxis3=new QSpinBox();leAxis3->setMaximum(1000000);leAxis3->setMinimum(-1000000);
	leAxis4=new QSpinBox();leAxis4->setMaximum(1000000);leAxis4->setMinimum(-1000000);
	leAxis5=new QSpinBox();leAxis5->setMaximum(1000000);leAxis5->setMinimum(-1000000);

	butReset=new QPushButton(tr("Reset"));
	butInstall=new QPushButton(tr("Install"));
	butFocus=new QPushButton(tr("MoveToFocus"));
	butAxis1Move=new QPushButton(tr("Move"));
	butAxis2Move=new QPushButton(tr("Move"));
	butAxis3Move=new QPushButton(tr("Move"));
	butAxis4Move=new QPushButton(tr("Move"));
	butAxis5Move=new QPushButton(tr("Move"));
	butAxis1Org=new QPushButton(tr("ORG"));butAxis1Org->setDisabled(true);
	butAxis2Org=new QPushButton(tr("ORG"));butAxis2Org->setDisabled(true);
	butAxis3Org=new QPushButton(tr("ORG"));butAxis3Org->setDisabled(true);
	butAxis4Org=new QPushButton(tr("ORG"));
	butAxis5Org=new QPushButton(tr("ORG"));

	connect(butAxis1Move,SIGNAL(clicked()),this,SLOT(slot_Axis1_Move()));
	connect(butAxis2Move,SIGNAL(clicked()),this,SLOT(slot_Axis2_Move()));
	connect(butAxis3Move,SIGNAL(clicked()),this,SLOT(slot_Axis3_Move()));
	connect(butAxis4Move,SIGNAL(clicked()),this,SLOT(slot_Axis4_Move()));
	connect(butAxis5Move,SIGNAL(clicked()),this,SLOT(slot_Axis5_Move()));
	connect(butAxis4Org,SIGNAL(clicked()),this,SLOT(slot_Axis4_org()));
	connect(butAxis5Org,SIGNAL(clicked()),this,SLOT(slot_Axis5_org()));
	connect(butReset,SIGNAL(clicked()),this,SLOT(slot_Reset()));
	connect(butInstall,SIGNAL(clicked()),this,SLOT(slot_Install()));
	connect(butFocus,SIGNAL(clicked()),this,SLOT(slot_Focus()));

	vLayout=new QVBoxLayout();
	QHBoxLayout *hLayout1=new QHBoxLayout();
	QHBoxLayout *hLayout2=new QHBoxLayout();
	QHBoxLayout *hLayout3=new QHBoxLayout();
	QHBoxLayout *hLayout4=new QHBoxLayout();
	QHBoxLayout *hLayout5=new QHBoxLayout();
	QHBoxLayout *hLayout6=new QHBoxLayout();

	hLayout1->addWidget(labAxis1,1);
	hLayout1->addWidget(leAxis1);
	hLayout1->addWidget(butAxis1Move);
	hLayout1->addWidget(butAxis1Org);
	hLayout1->addStretch(5);

	hLayout2->addWidget(labAxis2,1);
	hLayout2->addWidget(leAxis2);
	hLayout2->addWidget(butAxis2Move);
	hLayout2->addWidget(butAxis2Org);
	hLayout2->addStretch(5);

	hLayout3->addWidget(labAxis3,1);
	hLayout3->addWidget(leAxis3);
	hLayout3->addWidget(butAxis3Move);
	hLayout3->addWidget(butAxis3Org);
	hLayout3->addStretch(5);

	hLayout4->addWidget(labAxis4,1);
	hLayout4->addWidget(leAxis4);
	hLayout4->addWidget(butAxis4Move);
	hLayout4->addWidget(butAxis4Org);
	hLayout4->addStretch(5);

	hLayout5->addWidget(labAxis5,1);
	hLayout5->addWidget(leAxis5);
	hLayout5->addWidget(butAxis5Move);
	hLayout5->addWidget(butAxis5Org);
	hLayout5->addStretch(5);

	hLayout6->addWidget(butReset);
	hLayout6->addWidget(butInstall);
	hLayout6->addWidget(butFocus);
	hLayout6->addStretch(5);

	vLayout->addLayout(hLayout1);
	vLayout->addLayout(hLayout2);
	vLayout->addLayout(hLayout3);
	vLayout->addLayout(hLayout4);
	vLayout->addLayout(hLayout5);
	vLayout->addLayout(hLayout6);
	
	
	tabIoStatus=new QTableWidget(1,8);
	tabIoStatus->setHorizontalHeaderLabels(QStringList()<<"Bit0"<<"Bit1"<<"Bit2"<<"Bit3"<<"Bit4"<<"Bit5"<<"Bit6"<<"Bit7");
	tabIoStatus->setVerticalHeaderLabels(QStringList()<<tr("IO"));
	tabIoStatus->horizontalHeader()->hide();
	tabIoStatus->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	tabIoStatus->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	tabIoStatus->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
	tabIoStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (int i=0;i<tabIoStatus->columnCount();i++)
	{
		tabIoStatus->setItem(0,i,new QTableWidgetItem(QString("Bit%1").arg(i)));
		QTableWidgetItem *item=tabIoStatus->item(0,i);
		item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
		item->setBackground(QBrush(QColor(0,255,0,255)));
		QFont font;
		font.setBold(true);
		item->setFont(font);
	}

	connect(tabIoStatus,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(slot_IOdoubleClick(int, int)));
	//*************Axis Status****************
	tabAxisStatus=new QTableWidget(5,5);
	tabAxisStatus->setHorizontalHeaderLabels(QStringList()<<tr("Status")<<tr("ELP")<<tr("ELN")<<tr("ORG")<<tr("Pos"));
	tabAxisStatus->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	tabAxisStatus->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	tabAxisStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tabAxisStatus->setSelectionMode(QAbstractItemView::NoSelection);

	for (int i=0;i<tabAxisStatus->rowCount();i++)
	{
		for (int j=0;j<tabAxisStatus->columnCount();j++)
		{
			QTableWidgetItem *item=new QTableWidgetItem();
			item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

			if(j==tabAxisStatus->columnCount()-1){
				QFont font;
				font.setBold(true);
				item->setFont(font);
				item->setText("0");
			}else{
				item->setBackground(QColor(0,255,0,255));
			}
			
			tabAxisStatus->setItem(i,j,item);
		}
	}
	
	//*****************************
	tabAxisStatus->setFixedHeight(180);
	vLayout->addWidget(tabAxisStatus);
	tabIoStatus->setFixedHeight(80);
	vLayout->addWidget(tabIoStatus,10);
	vLayout->addStretch(10);
	setLayout(vLayout);
	//setStyleSheet("QLabel{background-color:red;border:1px solid black;}");
	m_nTimerID=startTimer(100);


}


jsl_controlpanel::~jsl_controlpanel()
{

}


void jsl_controlpanel::timerEvent(QTimerEvent *e){
	if(e->timerId()==m_nTimerID){
		//************  IO ****************************
		for (int i=0;i<tabIoStatus->rowCount();i++)
		{
			for (int j=0;j<tabIoStatus->columnCount();j++)
			{
				short status=dmc_read_outbit(0,j);
				QTableWidgetItem *item=tabIoStatus->item(i,j);
				if(status){
					item->setBackgroundColor(QColor(255,0,0,255));
				}else{
					item->setBackgroundColor(QColor(0,255,0,255));
				}

				tabIoStatus->setItem(i,j,item);
			}
		}
		
		//********************* Axis *******************************
		for (int i=0;i<tabAxisStatus->rowCount();i++)
		{
			WORD usAxisStatus,usMoveStatus;
			usAxisStatus=dmc_axis_io_status(0,i);
			usMoveStatus=dmc_check_done(0,i);
			LONG lPos=dmc_get_position(0,i);

			QTableWidgetItem *item=tabAxisStatus->item(i,0);
			if(usMoveStatus){
				item->setBackgroundColor(QColor(0,255,0,255));
			}else{
				item->setBackgroundColor(QColor(255,255,0,255));
			}
			tabAxisStatus->setItem(i,0,item);

			//****************  ELP ********************
			item=tabAxisStatus->item(i,1);
			if(usAxisStatus&0x02){
				item->setBackgroundColor(QColor(255,0,0,255));
			}else{
				item->setBackgroundColor(QColor(255,255,255,255));
			}
			tabAxisStatus->setItem(i,1,item);

			//****************  ELN ********************
			item=tabAxisStatus->item(i,2);
			if(usAxisStatus&0x04){
				item->setBackgroundColor(QColor(255,0,0,255));
			}else{
				item->setBackgroundColor(QColor(255,255,255,255));
			}
			tabAxisStatus->setItem(i,2,item);

			//****************  ORG ********************
			item=tabAxisStatus->item(i,3);
			if(usAxisStatus&0x10){
				item->setBackgroundColor(QColor(0,255,0,255));
			}else{
				item->setBackgroundColor(QColor(255,255,255,255));
			}
			tabAxisStatus->setItem(i,3,item);

			//****************  POS ********************
			item=tabAxisStatus->item(i,4);
			item->setText(QString::number(lPos));
			tabAxisStatus->setItem(i,4,item);


		}

	}
}

void jsl_controlpanel::slot_IOdoubleClick(int row, int column){
	QTableWidgetItem *item=tabIoStatus->item(row,column);
	if(item->backgroundColor().green()==255){
		dmc_write_outbit(0,column,1);
	}else if(item->backgroundColor().red()==255){
		dmc_write_outbit(0,column,0);
	}
}

void jsl_controlpanel::slot_Axis1_Move(){
	globalLeisaiMotion.axis_Move(0,0,leAxis1->value(),0);
}
void jsl_controlpanel::slot_Axis2_Move(){
	globalLeisaiMotion.axis_Move(0,0,leAxis2->value(),0);
}
void jsl_controlpanel::slot_Axis3_Move(){
	globalLeisaiMotion.axis_Move(0,0,leAxis3->value(),0);
}
void jsl_controlpanel::slot_Axis4_Move(){
	globalLeisaiMotion.axis_Move(0,0,leAxis4->value(),0);
}
void jsl_controlpanel::slot_Axis5_Move(){
	globalLeisaiMotion.axis_Move(0,0,leAxis5->value(),0);
}
void jsl_controlpanel::slot_Axis4_org(){
	dmc_set_homemode(0,3,0,1,0,0);
	dmc_set_profile(0,3,0,10000,0.1,0.1,0);
	dmc_home_move(0,3);
}
void jsl_controlpanel::slot_Axis5_org(){
	dmc_set_homemode(0,4,0,1,0,0);
	dmc_set_profile(0,4,0,10000,0.1,0.1,0);
	dmc_home_move(0,4);
}
void jsl_controlpanel::slot_Reset(){
	dmc_write_outbit(0,2,1);

	dmc_set_profile(0,2,0,50000,0.1,0.1,0);
	dmc_pmove(0,2,80000,0);

	WORD usMoveStatus=dmc_check_done(0,2);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,2);
		Sleep(30);
	}

	slot_Axis4_org();
	slot_Axis5_org();

	dmc_set_profile(0,0,0,50000,0.1,0.1,0);
	dmc_pmove(0,0,0,1);
	dmc_set_profile(0,1,0,50000,0.1,0.1,0);
	dmc_pmove(0,1,90000,1);

}
void jsl_controlpanel::slot_Install(){
	dmc_write_outbit(0,2,1);

	dmc_set_profile(0,2,0,50000,0.1,0.1,0);
	dmc_pmove(0,2,80000,0);

	WORD usMoveStatus=dmc_check_done(0,2);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,2);
		Sleep(30);
	}

	slot_Axis4_org();
	slot_Axis5_org();

	dmc_set_profile(0,0,0,50000,0.1,0.1,0);
	dmc_pmove(0,0,0,1);
	dmc_set_profile(0,1,0,50000,0.1,0.1,0);
	dmc_pmove(0,1,0,1);

	usMoveStatus=dmc_check_done(0,0);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,0);
		Sleep(30);
	}
	usMoveStatus=dmc_check_done(0,1);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,1);
		Sleep(30);
	}

	dmc_set_profile(0,2,0,50000,0.1,0.1,0);
	dmc_pmove(0,2,-3000,1);

	usMoveStatus=dmc_check_done(0,2);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,2);
		Sleep(30);
	}

	dmc_write_outbit(0,2,0);

}

void jsl_controlpanel::slot_Focus(){

	dmc_set_profile(0,2,0,50000,0.1,0.1,0);
	dmc_pmove(0,2,50000,0);

	WORD usMoveStatus=dmc_check_done(0,2);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,2);
		Sleep(30);
	}

	slot_Axis4_org();
	slot_Axis5_org();

	dmc_set_profile(0,0,0,50000,0.1,0.1,0);
	dmc_pmove(0,0,0,1);
	dmc_set_profile(0,1,0,50000,0.1,0.1,0);
	dmc_pmove(0,1,-98000,1);

	usMoveStatus=dmc_check_done(0,0);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,0);
		Sleep(30);
	}
	usMoveStatus=dmc_check_done(0,1);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,1);
		Sleep(30);
	}

	dmc_set_profile(0,2,0,50000,0.1,0.1,0);
	dmc_pmove(0,2,20000,1);

	usMoveStatus=dmc_check_done(0,2);
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(0,2);
		Sleep(30);
	}


}

#endif