#include "QHShortcut.h"
#include "../HisFX3CCMTest/QHTextItemEdit.h"

QHShortcut::QHShortcut(QWidget *parent, int iMode, QString tableName1, QString tableName2)
	: QDialog(parent), tableNameC1(tableName1), tableNameC2(tableName2), ciModeChannel(iMode)
{
	ui.setupUi(this);

	if(HISDBCUSTOM::isTableExist(tableName1) && (ciModeChannel == 2 || ciModeChannel == 0))	
	{
		HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, tableNameC1, listShortcutC1, true);
		HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
	}
	if(HISDBCUSTOM::isTableExist(tableName2) && (ciModeChannel == 2 || ciModeChannel == 1))	
	{
		HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, tableNameC2, listShortcutC2, false);
		HISCCMSHORTCUT::setShortcutSync(itemshareDataC2.shortcutgather);
	}

	QStringList listKey	=	HISCCMSHORTCUT::getListALLItemKey();
	globalgetListWantedTestItem(allitemList, listKey);

	fillUIPointer();
	fillouttestitem();

	if(ciModeChannel != 2)
	{
		for(unsigned int x=0; x<_His_ConfigSetting_MaxClickItems; ++x)
		{
			c2itemcheckBox[x]->setVisible(false);
			c2itemlineEdit[x]->setVisible(false);
			c2editpushButton[x]->setVisible(false);
			c1itemcheckBox[x]->setVisible(false);
		}
		ui.channel1label->setVisible(false);
		ui.channel2label->setVisible(false);
		ui.addInfo2label->setVisible(false);
	}

	for(unsigned int x=0;	x< _His_ConfigSetting_MaxClickItems; ++x)
	{
		connect(scitemcomboBox[x], SIGNAL(activated(const QString&)), this, SLOT(slotscitemchangego(const QString&)));
		connect(c1editpushButton[x], SIGNAL(released()), this, SLOT(sloteditShotcutExeC1()));
		connect(c2editpushButton[x], SIGNAL(released()), this, SLOT(sloteditShotcutExeC2()));
	}

	for(unsigned int x=0;	x< _His_ConfigSetting_MaxClickItems-1; ++x)
	{
		connect(scitemAddpushButton[x], SIGNAL(released()), this, SLOT(slotinsertShotcutExe()));
	}

	for(unsigned int x=0;	x<_His_ConfigSetting_MaxShortcut;	++x)
	{
		connect(sccheckBox[x], SIGNAL(stateChanged(int)), this, SLOT(slotKeyOnOff(int)));
	}

	connect(ui.scsavepushButton, SIGNAL(released()), this, SLOT(scsavebutton()));
	connect(ui.scchoosecomboBox, SIGNAL(activated(int)),  this, SLOT(slotsceditchange(int)));
	connect(ui.scclickcomboBox, SIGNAL(activated(int)),  this, SLOT(slotsceditchange(int)));
// 	connect(ui.defaultShortcutpushButton, SIGNAL(released()), this, SLOT(SetDefaultShortcut()));

	listShortcutKey(ciModeChannel); 
	if(ui.scchoosecomboBox->count()) shortcutinfotointerface(ciModeChannel, str2Key(ui.scchoosecomboBox->currentText()), ui.scclickcomboBox->currentIndex() + 1);
}

QHShortcut::~QHShortcut()
{
	

}

void QHShortcut::closeEvent(QCloseEvent *event)
{
	itemshareDataC1.itemparameterLock.lockForWrite();
	itemshareDataC1.shortcutgather.clear();
	itemshareDataC1.itemparameterLock.unlock();

	itemshareDataC2.itemparameterLock.lockForWrite();
	itemshareDataC2.shortcutgather.clear();
	itemshareDataC2.itemparameterLock.unlock();

	QDialog::closeEvent(event);
}

void QHShortcut::fillUIPointer()
{
	sccheckBox[0]	=	ui.scbutcheckBox;
	sccheckBox[1]	=	ui.scnum0checkBox;
	sccheckBox[2]	=	ui.scnum1checkBox;
	sccheckBox[3]	=	ui.scnum2checkBox;
	sccheckBox[4]	=	ui.scnum3checkBox;
	sccheckBox[5]	=	ui.scnum4checkBox;
	sccheckBox[6]	=	ui.scnum5checkBox;
	sccheckBox[7]	=	ui.scnum6checkBox;
	sccheckBox[8]	=	ui.scnum7checkBox;
	sccheckBox[9]	=	ui.scnum8checkBox;
	sccheckBox[10]	=	ui.scnum9checkBox;
	sccheckBox[11]	=	ui.scalphaAcheckBox;
	sccheckBox[12]	=	ui.scalphaBcheckBox;
	sccheckBox[13]	=	ui.scalphaCcheckBox;
	sccheckBox[14]	=	ui.scalphaDcheckBox;
	sccheckBox[15]	=	ui.scalphaEcheckBox;
	sccheckBox[16]	=	ui.scalphaFcheckBox;
	sccheckBox[17]	=	ui.scalphaGcheckBox;
	sccheckBox[18]	=	ui.scalphaHcheckBox;
	sccheckBox[19]	=	ui.scalphaIcheckBox;
	sccheckBox[20]	=	ui.scalphaJcheckBox;
	sccheckBox[21]	=	ui.scalphaKcheckBox;
	sccheckBox[22]	=	ui.scalphaLcheckBox;
	sccheckBox[23]	=	ui.scalphaMcheckBox;
	sccheckBox[24]	=	ui.scalphaNcheckBox;
	sccheckBox[25]	=	ui.scalphaOcheckBox;
	sccheckBox[26]	=	ui.scalphaPcheckBox;
	sccheckBox[27]	=	ui.scalphaQcheckBox;
	sccheckBox[28]	=	ui.scalphaRcheckBox;
	sccheckBox[29]	=	ui.scalphaScheckBox;
	sccheckBox[30]	=	ui.scalphaTcheckBox;
	sccheckBox[31]	=	ui.scalphaUcheckBox;
	sccheckBox[32]	=	ui.scalphaVcheckBox;
	sccheckBox[33]	=	ui.scalphaWcheckBox;
	sccheckBox[34]	=	ui.scalphaXcheckBox;
	sccheckBox[35]	=	ui.scalphaYcheckBox;
	sccheckBox[36]	=	ui.scalphaZcheckBox;

	scitemAddpushButton[0]			=		ui.scitemAdd1pushButton;
	scitemAddpushButton[1]			=		ui.scitemAdd2pushButton;
	scitemAddpushButton[2]			=		ui.scitemAdd3pushButton;
	scitemAddpushButton[3]			=		ui.scitemAdd4pushButton;
	scitemAddpushButton[4]			=		ui.scitemAdd5pushButton;
	scitemAddpushButton[5]			=		ui.scitemAdd6pushButton;
	scitemAddpushButton[6]			=		ui.scitemAdd7pushButton;
	scitemAddpushButton[7]			=		ui.scitemAdd8pushButton;
	scitemAddpushButton[8]			=		ui.scitemAdd9pushButton;
	scitemAddpushButton[9]			=		ui.scitemAdd10pushButton;
	scitemAddpushButton[10]		=		ui.scitemAdd11pushButton;
	scitemAddpushButton[11]		=		ui.scitemAdd12pushButton;
	scitemAddpushButton[12]		=		ui.scitemAdd13pushButton;
	scitemAddpushButton[13]		=		ui.scitemAdd14pushButton;
	scitemAddpushButton[14]		=		ui.scitemAdd15pushButton;
	scitemAddpushButton[15]		=		ui.scitemAdd16pushButton;
	scitemAddpushButton[16]		=		ui.scitemAdd17pushButton;
	scitemAddpushButton[17]		=		ui.scitemAdd18pushButton;
	scitemAddpushButton[18]		=		ui.scitemAdd19pushButton;
	scitemAddpushButton[19]		=		ui.scitemAdd20pushButton;
	scitemAddpushButton[20]		=		ui.scitemAdd21pushButton;
	scitemAddpushButton[21]		=		ui.scitemAdd22pushButton;
	scitemAddpushButton[22]		=		ui.scitemAdd23pushButton;
	scitemAddpushButton[23]		=		ui.scitemAdd24pushButton;
	scitemAddpushButton[24]		=		ui.scitemAdd25pushButton;
	scitemAddpushButton[25]		=		ui.scitemAdd26pushButton;
	scitemAddpushButton[26]		=		ui.scitemAdd27pushButton;
	scitemAddpushButton[27]		=		ui.scitemAdd28pushButton;
	scitemAddpushButton[28]		=		ui.scitemAdd29pushButton;
	scitemAddpushButton[29]		=		ui.scitemAdd30pushButton;
	scitemAddpushButton[30]		=		ui.scitemAdd31pushButton;
	scitemAddpushButton[31]		=		ui.scitemAdd32pushButton;
	scitemAddpushButton[32]		=		ui.scitemAdd33pushButton;
	scitemAddpushButton[33]		=		ui.scitemAdd34pushButton;
	scitemAddpushButton[34]		=		ui.scitemAdd35pushButton;
	scitemAddpushButton[35]		=		ui.scitemAdd36pushButton;
	scitemAddpushButton[36]		=		ui.scitemAdd37pushButton;
	scitemAddpushButton[37]		=		ui.scitemAdd38pushButton;
	scitemAddpushButton[38]		=		ui.scitemAdd39pushButton;
	
	scitemcheckBox[0]			=		ui.scitem1checkBox;
	scitemcheckBox[1]			=		ui.scitem2checkBox;
	scitemcheckBox[2]			=		ui.scitem3checkBox;
	scitemcheckBox[3]			=		ui.scitem4checkBox;
	scitemcheckBox[4]			=		ui.scitem5checkBox;
	scitemcheckBox[5]			=		ui.scitem6checkBox;
	scitemcheckBox[6]			=		ui.scitem7checkBox;
	scitemcheckBox[7]			=		ui.scitem8checkBox;
	scitemcheckBox[8]			=		ui.scitem9checkBox;
	scitemcheckBox[9]			=		ui.scitem10checkBox;
	scitemcheckBox[10]		=		ui.scitem11checkBox;
	scitemcheckBox[11]		=		ui.scitem12checkBox;
	scitemcheckBox[12]		=		ui.scitem13checkBox;
	scitemcheckBox[13]		=		ui.scitem14checkBox;
	scitemcheckBox[14]		=		ui.scitem15checkBox;
	scitemcheckBox[15]		=		ui.scitem16checkBox;
	scitemcheckBox[16]		=		ui.scitem17checkBox;
	scitemcheckBox[17]		=		ui.scitem18checkBox;
	scitemcheckBox[18]		=		ui.scitem19checkBox;
	scitemcheckBox[19]		=		ui.scitem20checkBox;
	scitemcheckBox[20]		=		ui.scitem21checkBox;
	scitemcheckBox[21]		=		ui.scitem22checkBox;
	scitemcheckBox[22]		=		ui.scitem23checkBox;
	scitemcheckBox[23]		=		ui.scitem24checkBox;
	scitemcheckBox[24]		=		ui.scitem25checkBox;
	scitemcheckBox[25]		=		ui.scitem26checkBox;
	scitemcheckBox[26]		=		ui.scitem27checkBox;
	scitemcheckBox[27]		=		ui.scitem28checkBox;
	scitemcheckBox[28]		=		ui.scitem29checkBox;
	scitemcheckBox[29]		=		ui.scitem30checkBox;
	scitemcheckBox[30]		=		ui.scitem31checkBox;
	scitemcheckBox[31]		=		ui.scitem32checkBox;
	scitemcheckBox[32]		=		ui.scitem33checkBox;
	scitemcheckBox[33]		=		ui.scitem34checkBox;
	scitemcheckBox[34]		=		ui.scitem35checkBox;
	scitemcheckBox[35]		=		ui.scitem36checkBox;
	scitemcheckBox[36]		=		ui.scitem37checkBox;
	scitemcheckBox[37]		=		ui.scitem38checkBox;
	scitemcheckBox[38]		=		ui.scitem39checkBox;
	scitemcheckBox[39]		=		ui.scitem40checkBox;

	scitemcomboBox[0]		=		ui.scitem1comboBox;
	scitemcomboBox[1]		=		ui.scitem2comboBox;
	scitemcomboBox[2]		=		ui.scitem3comboBox;
	scitemcomboBox[3]		=		ui.scitem4comboBox;
	scitemcomboBox[4]		=		ui.scitem5comboBox;
	scitemcomboBox[5]		=		ui.scitem6comboBox;
	scitemcomboBox[6]		=		ui.scitem7comboBox;
	scitemcomboBox[7]		=		ui.scitem8comboBox;
	scitemcomboBox[8]		=		ui.scitem9comboBox;
	scitemcomboBox[9]		=		ui.scitem10comboBox;
	scitemcomboBox[10]		=		ui.scitem11comboBox;
	scitemcomboBox[11]		=		ui.scitem12comboBox;
	scitemcomboBox[12]		=		ui.scitem13comboBox;
	scitemcomboBox[13]		=		ui.scitem14comboBox;
	scitemcomboBox[14]		=		ui.scitem15comboBox;
	scitemcomboBox[15]		=		ui.scitem16comboBox;
	scitemcomboBox[16]		=		ui.scitem17comboBox;
	scitemcomboBox[17]		=		ui.scitem18comboBox;
	scitemcomboBox[18]		=		ui.scitem19comboBox;
	scitemcomboBox[19]		=		ui.scitem20comboBox;
	scitemcomboBox[20]		=		ui.scitem21comboBox;
	scitemcomboBox[21]		=		ui.scitem22comboBox;
	scitemcomboBox[22]		=		ui.scitem23comboBox;
	scitemcomboBox[23]		=		ui.scitem24comboBox;
	scitemcomboBox[24]		=		ui.scitem25comboBox;
	scitemcomboBox[25]		=		ui.scitem26comboBox;
	scitemcomboBox[26]		=		ui.scitem27comboBox;
	scitemcomboBox[27]		=		ui.scitem28comboBox;
	scitemcomboBox[28]		=		ui.scitem29comboBox;
	scitemcomboBox[29]		=		ui.scitem30comboBox;
	scitemcomboBox[30]		=		ui.scitem31comboBox;
	scitemcomboBox[31]		=		ui.scitem32comboBox;
	scitemcomboBox[32]		=		ui.scitem33comboBox;
	scitemcomboBox[33]		=		ui.scitem34comboBox;
	scitemcomboBox[34]		=		ui.scitem35comboBox;
	scitemcomboBox[35]		=		ui.scitem36comboBox;
	scitemcomboBox[36]		=		ui.scitem37comboBox;
	scitemcomboBox[37]		=		ui.scitem38comboBox;
	scitemcomboBox[38]		=		ui.scitem39comboBox;
	scitemcomboBox[39]		=		ui.scitem40comboBox;

	c1itemcheckBox[0]			=		ui.c1item1checkBox;
	c1itemcheckBox[1]			=		ui.c1item2checkBox;
	c1itemcheckBox[2]			=		ui.c1item3checkBox;
	c1itemcheckBox[3]			=		ui.c1item4checkBox;
	c1itemcheckBox[4]			=		ui.c1item5checkBox;
	c1itemcheckBox[5]			=		ui.c1item6checkBox;
	c1itemcheckBox[6]			=		ui.c1item7checkBox;
	c1itemcheckBox[7]			=		ui.c1item8checkBox;
	c1itemcheckBox[8]			=		ui.c1item9checkBox;
	c1itemcheckBox[9]			=		ui.c1item10checkBox;
	c1itemcheckBox[10]		=		ui.c1item11checkBox;
	c1itemcheckBox[11]		=		ui.c1item12checkBox;
	c1itemcheckBox[12]		=		ui.c1item13checkBox;
	c1itemcheckBox[13]		=		ui.c1item14checkBox;
	c1itemcheckBox[14]		=		ui.c1item15checkBox;
	c1itemcheckBox[15]		=		ui.c1item16checkBox;
	c1itemcheckBox[16]		=		ui.c1item17checkBox;
	c1itemcheckBox[17]		=		ui.c1item18checkBox;
	c1itemcheckBox[18]		=		ui.c1item19checkBox;
	c1itemcheckBox[19]		=		ui.c1item20checkBox;
	c1itemcheckBox[20]		=		ui.c1item21checkBox;
	c1itemcheckBox[21]		=		ui.c1item22checkBox;
	c1itemcheckBox[22]		=		ui.c1item23checkBox;
	c1itemcheckBox[23]		=		ui.c1item24checkBox;
	c1itemcheckBox[24]		=		ui.c1item25checkBox;
	c1itemcheckBox[25]		=		ui.c1item26checkBox;
	c1itemcheckBox[26]		=		ui.c1item27checkBox;
	c1itemcheckBox[27]		=		ui.c1item28checkBox;
	c1itemcheckBox[28]		=		ui.c1item29checkBox;
	c1itemcheckBox[29]		=		ui.c1item30checkBox;
	c1itemcheckBox[30]		=		ui.c1item31checkBox;
	c1itemcheckBox[31]		=		ui.c1item32checkBox;
	c1itemcheckBox[32]		=		ui.c1item33checkBox;
	c1itemcheckBox[33]		=		ui.c1item34checkBox;
	c1itemcheckBox[34]		=		ui.c1item35checkBox;
	c1itemcheckBox[35]		=		ui.c1item36checkBox;
	c1itemcheckBox[36]		=		ui.c1item37checkBox;
	c1itemcheckBox[37]		=		ui.c1item38checkBox;
	c1itemcheckBox[38]		=		ui.c1item39checkBox;
	c1itemcheckBox[39]		=		ui.c1item40checkBox;

	c1itemlineEdit[0]				=		ui.c1item1lineEdit;
	c1itemlineEdit[1]				=		ui.c1item2lineEdit;
	c1itemlineEdit[2]				=		ui.c1item3lineEdit;
	c1itemlineEdit[3]				=		ui.c1item4lineEdit;
	c1itemlineEdit[4]				=		ui.c1item5lineEdit;
	c1itemlineEdit[5]				=		ui.c1item6lineEdit;
	c1itemlineEdit[6]				=		ui.c1item7lineEdit;
	c1itemlineEdit[7]				=		ui.c1item8lineEdit;
	c1itemlineEdit[8]				=		ui.c1item9lineEdit;
	c1itemlineEdit[9]				=		ui.c1item10lineEdit;
	c1itemlineEdit[10]			=		ui.c1item11lineEdit;
	c1itemlineEdit[11]			=		ui.c1item12lineEdit;
	c1itemlineEdit[12]			=		ui.c1item13lineEdit;
	c1itemlineEdit[13]			=		ui.c1item14lineEdit;
	c1itemlineEdit[14]			=		ui.c1item15lineEdit;
	c1itemlineEdit[15]			=		ui.c1item16lineEdit;
	c1itemlineEdit[16]			=		ui.c1item17lineEdit;
	c1itemlineEdit[17]			=		ui.c1item18lineEdit;
	c1itemlineEdit[18]			=		ui.c1item19lineEdit;
	c1itemlineEdit[19]			=		ui.c1item20lineEdit;
	c1itemlineEdit[20]			=		ui.c1item21lineEdit;
	c1itemlineEdit[21]			=		ui.c1item22lineEdit;
	c1itemlineEdit[22]			=		ui.c1item23lineEdit;
	c1itemlineEdit[23]			=		ui.c1item24lineEdit;
	c1itemlineEdit[24]			=		ui.c1item25lineEdit;
	c1itemlineEdit[25]			=		ui.c1item26lineEdit;
	c1itemlineEdit[26]			=		ui.c1item27lineEdit;
	c1itemlineEdit[27]			=		ui.c1item28lineEdit;
	c1itemlineEdit[28]			=		ui.c1item29lineEdit;
	c1itemlineEdit[29]			=		ui.c1item30lineEdit;
	c1itemlineEdit[30]			=		ui.c1item31lineEdit;
	c1itemlineEdit[31]			=		ui.c1item32lineEdit;
	c1itemlineEdit[32]			=		ui.c1item33lineEdit;
	c1itemlineEdit[33]			=		ui.c1item34lineEdit;
	c1itemlineEdit[34]			=		ui.c1item35lineEdit;
	c1itemlineEdit[35]			=		ui.c1item36lineEdit;
	c1itemlineEdit[36]			=		ui.c1item37lineEdit;
	c1itemlineEdit[37]			=		ui.c1item38lineEdit;
	c1itemlineEdit[38]			=		ui.c1item39lineEdit;
	c1itemlineEdit[39]			=		ui.c1item40lineEdit;

	c1editpushButton[0]		=		ui.c1edit1pushButton;
	c1editpushButton[1]		=		ui.c1edit2pushButton;
	c1editpushButton[2]		=		ui.c1edit3pushButton;
	c1editpushButton[3]		=		ui.c1edit4pushButton;
	c1editpushButton[4]		=		ui.c1edit5pushButton;
	c1editpushButton[5]		=		ui.c1edit6pushButton;
	c1editpushButton[6]		=		ui.c1edit7pushButton;
	c1editpushButton[7]		=		ui.c1edit8pushButton;
	c1editpushButton[8]		=		ui.c1edit9pushButton;
	c1editpushButton[9]		=		ui.c1edit10pushButton;
	c1editpushButton[10]		=		ui.c1edit11pushButton;
	c1editpushButton[11]		=		ui.c1edit12pushButton;
	c1editpushButton[12]		=		ui.c1edit13pushButton;
	c1editpushButton[13]		=		ui.c1edit14pushButton;
	c1editpushButton[14]		=		ui.c1edit15pushButton;
	c1editpushButton[15]		=		ui.c1edit16pushButton;
	c1editpushButton[16]		=		ui.c1edit17pushButton;
	c1editpushButton[17]		=		ui.c1edit18pushButton;
	c1editpushButton[18]		=		ui.c1edit19pushButton;
	c1editpushButton[19]		=		ui.c1edit20pushButton;
	c1editpushButton[20]		=		ui.c1edit21pushButton;
	c1editpushButton[21]		=		ui.c1edit22pushButton;
	c1editpushButton[22]		=		ui.c1edit23pushButton;
	c1editpushButton[23]		=		ui.c1edit24pushButton;
	c1editpushButton[24]		=		ui.c1edit25pushButton;
	c1editpushButton[25]		=		ui.c1edit26pushButton;
	c1editpushButton[26]		=		ui.c1edit27pushButton;
	c1editpushButton[27]		=		ui.c1edit28pushButton;
	c1editpushButton[28]		=		ui.c1edit29pushButton;
	c1editpushButton[29]		=		ui.c1edit30pushButton;
	c1editpushButton[30]		=		ui.c1edit31pushButton;
	c1editpushButton[31]		=		ui.c1edit32pushButton;
	c1editpushButton[32]		=		ui.c1edit33pushButton;
	c1editpushButton[33]		=		ui.c1edit34pushButton;
	c1editpushButton[34]		=		ui.c1edit35pushButton;
	c1editpushButton[35]		=		ui.c1edit36pushButton;
	c1editpushButton[36]		=		ui.c1edit37pushButton;
	c1editpushButton[37]		=		ui.c1edit38pushButton;
	c1editpushButton[38]		=		ui.c1edit39pushButton;
	c1editpushButton[39]		=		ui.c1edit40pushButton;

	c2itemcheckBox[0]			=		ui.c2item1checkBox;
	c2itemcheckBox[1]			=		ui.c2item2checkBox;
	c2itemcheckBox[2]			=		ui.c2item3checkBox;
	c2itemcheckBox[3]			=		ui.c2item4checkBox;
	c2itemcheckBox[4]			=		ui.c2item5checkBox;
	c2itemcheckBox[5]			=		ui.c2item6checkBox;
	c2itemcheckBox[6]			=		ui.c2item7checkBox;
	c2itemcheckBox[7]			=		ui.c2item8checkBox;
	c2itemcheckBox[8]			=		ui.c2item9checkBox;
	c2itemcheckBox[9]			=		ui.c2item10checkBox;
	c2itemcheckBox[10]		=		ui.c2item11checkBox;
	c2itemcheckBox[11]		=		ui.c2item12checkBox;
	c2itemcheckBox[12]		=		ui.c2item13checkBox;
	c2itemcheckBox[13]		=		ui.c2item14checkBox;
	c2itemcheckBox[14]		=		ui.c2item15checkBox;
	c2itemcheckBox[15]		=		ui.c2item16checkBox;
	c2itemcheckBox[16]		=		ui.c2item17checkBox;
	c2itemcheckBox[17]		=		ui.c2item18checkBox;
	c2itemcheckBox[18]		=		ui.c2item19checkBox;
	c2itemcheckBox[19]		=		ui.c2item20checkBox;
	c2itemcheckBox[20]		=		ui.c2item21checkBox;
	c2itemcheckBox[21]		=		ui.c2item22checkBox;
	c2itemcheckBox[22]		=		ui.c2item23checkBox;
	c2itemcheckBox[23]		=		ui.c2item24checkBox;
	c2itemcheckBox[24]		=		ui.c2item25checkBox;
	c2itemcheckBox[25]		=		ui.c2item26checkBox;
	c2itemcheckBox[26]		=		ui.c2item27checkBox;
	c2itemcheckBox[27]		=		ui.c2item28checkBox;
	c2itemcheckBox[28]		=		ui.c2item29checkBox;
	c2itemcheckBox[29]		=		ui.c2item30checkBox;
	c2itemcheckBox[30]		=		ui.c2item31checkBox;
	c2itemcheckBox[31]		=		ui.c2item32checkBox;
	c2itemcheckBox[32]		=		ui.c2item33checkBox;
	c2itemcheckBox[33]		=		ui.c2item34checkBox;
	c2itemcheckBox[34]		=		ui.c2item35checkBox;
	c2itemcheckBox[35]		=		ui.c2item36checkBox;
	c2itemcheckBox[36]		=		ui.c2item37checkBox;
	c2itemcheckBox[37]		=		ui.c2item38checkBox;
	c2itemcheckBox[38]		=		ui.c2item39checkBox;
	c2itemcheckBox[39]		=		ui.c2item40checkBox;

	c2itemlineEdit[0]			=		ui.c2item1lineEdit; 
	c2itemlineEdit[1]			=		ui.c2item2lineEdit; 
	c2itemlineEdit[2]			=		ui.c2item3lineEdit; 
	c2itemlineEdit[3]			=		ui.c2item4lineEdit; 
	c2itemlineEdit[4]			=		ui.c2item5lineEdit; 
	c2itemlineEdit[5]			=		ui.c2item6lineEdit; 
	c2itemlineEdit[6]			=		ui.c2item7lineEdit; 
	c2itemlineEdit[7]			=		ui.c2item8lineEdit; 
	c2itemlineEdit[8]			=		ui.c2item9lineEdit; 
	c2itemlineEdit[9]			=		ui.c2item10lineEdit;
	c2itemlineEdit[10]		=		ui.c2item11lineEdit;
	c2itemlineEdit[11]		=		ui.c2item12lineEdit;
	c2itemlineEdit[12]		=		ui.c2item13lineEdit;
	c2itemlineEdit[13]		=		ui.c2item14lineEdit;
	c2itemlineEdit[14]		=		ui.c2item15lineEdit;
	c2itemlineEdit[15]		=		ui.c2item16lineEdit;
	c2itemlineEdit[16]		=		ui.c2item17lineEdit;
	c2itemlineEdit[17]		=		ui.c2item18lineEdit;
	c2itemlineEdit[18]		=		ui.c2item19lineEdit;
	c2itemlineEdit[19]		=		ui.c2item20lineEdit;
	c2itemlineEdit[20]		=		ui.c2item21lineEdit;
	c2itemlineEdit[21]		=		ui.c2item22lineEdit;
	c2itemlineEdit[22]		=		ui.c2item23lineEdit;
	c2itemlineEdit[23]		=		ui.c2item24lineEdit;
	c2itemlineEdit[24]		=		ui.c2item25lineEdit;
	c2itemlineEdit[25]		=		ui.c2item26lineEdit;
	c2itemlineEdit[26]		=		ui.c2item27lineEdit;
	c2itemlineEdit[27]		=		ui.c2item28lineEdit;
	c2itemlineEdit[28]		=		ui.c2item29lineEdit;
	c2itemlineEdit[29]		=		ui.c2item30lineEdit;
	c2itemlineEdit[30]		=		ui.c2item31lineEdit;
	c2itemlineEdit[31]		=		ui.c2item32lineEdit;
	c2itemlineEdit[32]		=		ui.c2item33lineEdit;
	c2itemlineEdit[33]		=		ui.c2item34lineEdit;
	c2itemlineEdit[34]		=		ui.c2item35lineEdit;
	c2itemlineEdit[35]		=		ui.c2item36lineEdit;
	c2itemlineEdit[36]		=		ui.c2item37lineEdit;
	c2itemlineEdit[37]		=		ui.c2item38lineEdit;
	c2itemlineEdit[38]		=		ui.c2item39lineEdit;
	c2itemlineEdit[39]		=		ui.c2item40lineEdit;

	c2editpushButton[0]			=		ui.c2edit1pushButton; 
	c2editpushButton[1]			=		ui.c2edit2pushButton; 
	c2editpushButton[2]			=		ui.c2edit3pushButton; 
	c2editpushButton[3]			=		ui.c2edit4pushButton; 
	c2editpushButton[4]			=		ui.c2edit5pushButton; 
	c2editpushButton[5]			=		ui.c2edit6pushButton; 
	c2editpushButton[6]			=		ui.c2edit7pushButton; 
	c2editpushButton[7]			=		ui.c2edit8pushButton; 
	c2editpushButton[8]			=		ui.c2edit9pushButton; 
	c2editpushButton[9]			=		ui.c2edit10pushButton;
	c2editpushButton[10]		=		ui.c2edit11pushButton;
	c2editpushButton[11]		=		ui.c2edit12pushButton;
	c2editpushButton[12]		=		ui.c2edit13pushButton;
	c2editpushButton[13]		=		ui.c2edit14pushButton;
	c2editpushButton[14]		=		ui.c2edit15pushButton;
	c2editpushButton[15]		=		ui.c2edit16pushButton;
	c2editpushButton[16]		=		ui.c2edit17pushButton;
	c2editpushButton[17]		=		ui.c2edit18pushButton;
	c2editpushButton[18]		=		ui.c2edit19pushButton;
	c2editpushButton[19]		=		ui.c2edit20pushButton;
	c2editpushButton[20]		=		ui.c2edit21pushButton;
	c2editpushButton[21]		=		ui.c2edit22pushButton;
	c2editpushButton[22]		=		ui.c2edit23pushButton;
	c2editpushButton[23]		=		ui.c2edit24pushButton;
	c2editpushButton[24]		=		ui.c2edit25pushButton;
	c2editpushButton[25]		=		ui.c2edit26pushButton;
	c2editpushButton[26]		=		ui.c2edit27pushButton;
	c2editpushButton[27]		=		ui.c2edit28pushButton;
	c2editpushButton[28]		=		ui.c2edit29pushButton;
	c2editpushButton[29]		=		ui.c2edit30pushButton;
	c2editpushButton[30]		=		ui.c2edit31pushButton;
	c2editpushButton[31]		=		ui.c2edit32pushButton;
	c2editpushButton[32]		=		ui.c2edit33pushButton;
	c2editpushButton[33]		=		ui.c2edit34pushButton;
	c2editpushButton[34]		=		ui.c2edit35pushButton;
	c2editpushButton[35]		=		ui.c2edit36pushButton;
	c2editpushButton[36]		=		ui.c2edit37pushButton;
	c2editpushButton[37]		=		ui.c2edit38pushButton;
	c2editpushButton[38]		=		ui.c2edit39pushButton;
	c2editpushButton[39]		=		ui.c2edit40pushButton;

	scitemspinBox[0]			=		ui.scitem1spinBox; 
	scitemspinBox[1]			=		ui.scitem2spinBox; 
	scitemspinBox[2]			=		ui.scitem3spinBox; 
	scitemspinBox[3]			=		ui.scitem4spinBox; 
	scitemspinBox[4]			=		ui.scitem5spinBox; 
	scitemspinBox[5]			=		ui.scitem6spinBox; 
	scitemspinBox[6]			=		ui.scitem7spinBox; 
	scitemspinBox[7]			=		ui.scitem8spinBox; 
	scitemspinBox[8]			=		ui.scitem9spinBox; 
	scitemspinBox[9]			=		ui.scitem10spinBox;
	scitemspinBox[10]		=		ui.scitem11spinBox;
	scitemspinBox[11]		=		ui.scitem12spinBox;
	scitemspinBox[12]		=		ui.scitem13spinBox;
	scitemspinBox[13]		=		ui.scitem14spinBox;
	scitemspinBox[14]		=		ui.scitem15spinBox;
	scitemspinBox[15]		=		ui.scitem16spinBox;
	scitemspinBox[16]		=		ui.scitem17spinBox;
	scitemspinBox[17]		=		ui.scitem18spinBox;
	scitemspinBox[18]		=		ui.scitem19spinBox;
	scitemspinBox[19]		=		ui.scitem20spinBox;
	scitemspinBox[20]		=		ui.scitem21spinBox;
	scitemspinBox[21]		=		ui.scitem22spinBox;
	scitemspinBox[22]		=		ui.scitem23spinBox;
	scitemspinBox[23]		=		ui.scitem24spinBox;
	scitemspinBox[24]		=		ui.scitem25spinBox;
	scitemspinBox[25]		=		ui.scitem26spinBox;
	scitemspinBox[26]		=		ui.scitem27spinBox;
	scitemspinBox[27]		=		ui.scitem28spinBox;
	scitemspinBox[28]		=		ui.scitem29spinBox;
	scitemspinBox[29]		=		ui.scitem30spinBox;
	scitemspinBox[30]		=		ui.scitem31spinBox;
	scitemspinBox[31]		=		ui.scitem32spinBox;
	scitemspinBox[32]		=		ui.scitem33spinBox;
	scitemspinBox[33]		=		ui.scitem34spinBox;
	scitemspinBox[34]		=		ui.scitem35spinBox;
	scitemspinBox[35]		=		ui.scitem36spinBox;
	scitemspinBox[36]		=		ui.scitem37spinBox;
	scitemspinBox[37]		=		ui.scitem38spinBox;
	scitemspinBox[38]		=		ui.scitem39spinBox;
	scitemspinBox[39]		=		ui.scitem40spinBox;

	scitemngcomboBox[0]		=		ui.scitem1ngcomboBox; 
	scitemngcomboBox[1]		=		ui.scitem2ngcomboBox; 
	scitemngcomboBox[2]		=		ui.scitem3ngcomboBox; 
	scitemngcomboBox[3]		=		ui.scitem4ngcomboBox; 
	scitemngcomboBox[4]		=		ui.scitem5ngcomboBox; 
	scitemngcomboBox[5]		=		ui.scitem6ngcomboBox; 
	scitemngcomboBox[6]		=		ui.scitem7ngcomboBox; 
	scitemngcomboBox[7]		=		ui.scitem8ngcomboBox; 
	scitemngcomboBox[8]		=		ui.scitem9ngcomboBox; 
	scitemngcomboBox[9]		=		ui.scitem10ngcomboBox;
	scitemngcomboBox[10]		=		ui.scitem11ngcomboBox;
	scitemngcomboBox[11]		=		ui.scitem12ngcomboBox;
	scitemngcomboBox[12]		=		ui.scitem13ngcomboBox;
	scitemngcomboBox[13]		=		ui.scitem14ngcomboBox;
	scitemngcomboBox[14]		=		ui.scitem15ngcomboBox;
	scitemngcomboBox[15]		=		ui.scitem16ngcomboBox;
	scitemngcomboBox[16]		=		ui.scitem17ngcomboBox;
	scitemngcomboBox[17]		=		ui.scitem18ngcomboBox;
	scitemngcomboBox[18]		=		ui.scitem19ngcomboBox;
	scitemngcomboBox[19]		=		ui.scitem20ngcomboBox;
	scitemngcomboBox[20]		=		ui.scitem21ngcomboBox;
	scitemngcomboBox[21]		=		ui.scitem22ngcomboBox;
	scitemngcomboBox[22]		=		ui.scitem23ngcomboBox;
	scitemngcomboBox[23]		=		ui.scitem24ngcomboBox;
	scitemngcomboBox[24]		=		ui.scitem25ngcomboBox;
	scitemngcomboBox[25]		=		ui.scitem26ngcomboBox;
	scitemngcomboBox[26]		=		ui.scitem27ngcomboBox;
	scitemngcomboBox[27]		=		ui.scitem28ngcomboBox;
	scitemngcomboBox[28]		=		ui.scitem29ngcomboBox;
	scitemngcomboBox[29]		=		ui.scitem30ngcomboBox;
	scitemngcomboBox[30]		=		ui.scitem31ngcomboBox;
	scitemngcomboBox[31]		=		ui.scitem32ngcomboBox;
	scitemngcomboBox[32]		=		ui.scitem33ngcomboBox;
	scitemngcomboBox[33]		=		ui.scitem34ngcomboBox;
	scitemngcomboBox[34]		=		ui.scitem35ngcomboBox;
	scitemngcomboBox[35]		=		ui.scitem36ngcomboBox;
	scitemngcomboBox[36]		=		ui.scitem37ngcomboBox;
	scitemngcomboBox[37]		=		ui.scitem38ngcomboBox;
	scitemngcomboBox[38]		=		ui.scitem39ngcomboBox;
	scitemngcomboBox[39]		=		ui.scitem40ngcomboBox;
}

void QHShortcut::fillouttestitem()
{
	for(unsigned int x=0;	x<_His_ConfigSetting_MaxClickItems;	++x)
	{
		scitemngcomboBox[x]->addItem(QTextCodec::codecForName( "GBK")->toUnicode("À≥–Ú÷¥––"));
		for(QList<_TestItem_Basic_Info>::iterator theiterator = allitemList.begin(); theiterator != allitemList.end(); theiterator++){
			scitemcomboBox[x]->addItem(theiterator->strDescripName);
			scitemngcomboBox[x]->addItem(theiterator->strDescripName);
		}
	}
}

void QHShortcut::scsavebutton()
{
	QString strItemText = ui.scchoosecomboBox->currentText();
	QString strTimeText = ui.scclickcomboBox->currentText();
	saveshortcutinfo();
	ui.scchoosecomboBox->setCurrentIndex(ui.scchoosecomboBox->findText(strItemText));
	ui.scclickcomboBox->setCurrentIndex(ui.scclickcomboBox->findText(strTimeText));

	slotsceditchange(0);
}

void QHShortcut::saveshortcutinfo()
{
	HISCCMSHORTCUT::saveShortcutSync(ui.dualSynccheckBox->isChecked());

	if(ui.scchoosecomboBox->count() > 0)
	{
		char cKey	=	'=';
		if(ui.scchoosecomboBox->currentText().size() == 1)	cKey	=	ui.scchoosecomboBox->currentText().toLower().at(0).toAscii();
		iterfacetoshortcutinfo(ciModeChannel, cKey, ui.scclickcomboBox->currentIndex() +1);
	}

	QString classfy, item, itemsuffix1, itemsuffix2, key, value1, reserve, note;

#define _HisDB_Index_Shortcut		5000

	for(unsigned int w=0;	w<1;	++w)
	{
		bool bdelete = false;
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryconsole");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		for(unsigned int t=0;	t<2;	++t)
		{
			unsigned int uiindex	=	_HisDB_Index_Shortcut;
			QString tableName = (t==0)?(tableNameC1):(tableNameC2);
			QShortcutList& listShortcut	=	(t==0)?(listShortcutC1):(listShortcutC2);

			if(tableName.isEmpty()) continue;

			if (!customdb.open()){
				QMessageBox::critical(this, tr("ERROR"), tr("open file failed: ") % tableNameC1);
				continue;
			}

			QSqlQuery query(customdb);
			QString strData, strData2;
			QStringList strlist;

			if(bdelete && tableNameC1 != tableNameC2) bdelete = false;

			if(!bdelete){
				query.prepare("DELETE FROM " % tableName % " WHERE classfy='shortcut' OR classfy='shortcut1' OR classfy='shortcut2'" );
				query.exec();
				bdelete	=	true;
			}

			customdb.transaction();

			for(unsigned int x=0;	x<listShortcut.size();	++x)
			{
				qDebug() << "shortcut" << x << listShortcut[x].shortcutKey;

				if(!isKeyChecked(listShortcut[x].shortcutKey)) continue;

				qDebug() << "insert";

				query.prepare("INSERT INTO " % tableName % "(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve,note) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve,:note)");
				query.bindValue(":id", uiindex++);
				if(t)
					query.bindValue(":classfy", (listShortcut[x].bDualCamera)?(QVariant("shortcut2")):(QVariant("shortcut")));
				else
					query.bindValue(":classfy", (listShortcut[x].bDualCamera)?(QVariant("shortcut1")):(QVariant("shortcut")));
				query.bindValue(":item", QVariant());
				query.bindValue(":itemsuffix1", QVariant(QChar::fromAscii(listShortcut[x].shortcutKey)));
				query.bindValue(":itemsuffix2", QVariant((listShortcut[x].ucClickTime == 1)?("first_click"):("second_click")));
				query.bindValue(":key", QVariant(listShortcut[x].ucItemIndex));
				query.bindValue(":value", QVariant(HISGLOBALSHORTCUT::getSaveNameFromId(allitemList, listShortcut[x].usItem) % listShortcut[x].strAddInfo));
				if(listShortcut[x].usItemfail == 0)
					query.bindValue(":reserve", QVariant(listShortcut[x].ucloopTime));
				else
					query.bindValue(":reserve", QVariant(QString::number(listShortcut[x].ucloopTime) % "(false:" % HISGLOBALSHORTCUT::getSaveNameFromId(allitemList, listShortcut[x].usItemfail) % ")"));
				query.bindValue(":note", QVariant());
				query.exec();
			}

			customdb.commit();

			customdb.close();
		}

	}

	QSqlDatabase::removeDatabase("queryconsole");

	QMessageBox::information(this, tr("INFO"), tr("Save Success"));


}

void QHShortcut::shortcutinfotointerface(int iChannel, char cKey, int iClickTime)
{
	if(iChannel == 2)
	{
		int iNextItemIndex, iTemp, iIndexAdd = 1, iUIIndex = 0;
		bool bC1	=	true, bC2 = true;
		while(bC1 || bC2)
		{
			bC1	=	bC2 = false;
			if((iNextItemIndex = HISCCMSHORTCUT::getNextTestItemTwoChannel(listShortcutC1, cKey, iClickTime, iIndexAdd)) >= 0){
				bC1	=	true;
				scitemcheckBox[iUIIndex]->setChecked(true);
				scitemcomboBox[iUIIndex]->setCurrentIndex(scitemcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcutC1[iNextItemIndex].usItem)));
				c1itemlineEdit[iUIIndex]->setText(listShortcutC1[iNextItemIndex].strAddInfo);
				scitemspinBox[iUIIndex]->setValue(listShortcutC1[iNextItemIndex].ucloopTime);
				iTemp	=	scitemngcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcutC1[iNextItemIndex].usItemfail));
				iTemp	=	max(iTemp, 0);
				scitemngcomboBox[iUIIndex]->setCurrentIndex(iTemp);		
			}

			if((iNextItemIndex = HISCCMSHORTCUT::getNextTestItemTwoChannel(listShortcutC2, cKey, iClickTime, iIndexAdd)) >= 0){
				bC2	=	true;
				c2itemlineEdit[iUIIndex]->setText(listShortcutC2[iNextItemIndex].strAddInfo);				
				if(!bC1){
					scitemcheckBox[iUIIndex]->setChecked(true);
					scitemcomboBox[iUIIndex]->setCurrentIndex(scitemcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcutC2[iNextItemIndex].usItem)));
					scitemspinBox[iUIIndex]->setValue(listShortcutC2[iNextItemIndex].ucloopTime);
					iTemp	=	scitemngcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcutC2[iNextItemIndex].usItemfail));
					iTemp	=	max(iTemp, 0);
					scitemngcomboBox[iUIIndex]->setCurrentIndex(iTemp);
				}

			}

			if(bC1 || bC2){
				c1itemcheckBox[iUIIndex]->setChecked(bC1);
				c2itemcheckBox[iUIIndex]->setChecked(bC2);
				if(bC1 && !bC2) c2itemlineEdit[iUIIndex]->setText(c1itemlineEdit[iUIIndex]->text());
				if(bC2 && !bC1) c1itemlineEdit[iUIIndex]->setText(c2itemlineEdit[iUIIndex]->text());
				++iUIIndex;
				++iIndexAdd;
			}

		}

		for(; iUIIndex < _His_ConfigSetting_MaxClickItems; ++iUIIndex){
			scitemcheckBox[iUIIndex]->setChecked(false);
		}
	}
	else
	{
		QShortcutList& listShortcut = (iChannel == 0)?(listShortcutC1):(listShortcutC2);
		int iNextItemIndex, iTemp, iIndexAdd = 1, iUIIndex = 0;
		while((iNextItemIndex = HISCCMSHORTCUT::getNextTestItemOneChannel(listShortcut, cKey, iClickTime, iIndexAdd++)) >= 0){
			scitemcheckBox[iUIIndex]->setChecked(true);
			scitemcomboBox[iUIIndex]->setCurrentIndex(scitemcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcut[iNextItemIndex].usItem)));
			c1itemlineEdit[iUIIndex]->setText(listShortcut[iNextItemIndex].strAddInfo);
			scitemspinBox[iUIIndex]->setValue(listShortcut[iNextItemIndex].ucloopTime);
			iTemp	=	scitemngcomboBox[iUIIndex]->findText(HISGLOBALSHORTCUT::getDecripeNameFromId(allitemList, listShortcut[iNextItemIndex].usItemfail));
			iTemp	=	max(iTemp, 0);
			scitemngcomboBox[iUIIndex]->setCurrentIndex(iTemp);
			++iUIIndex;
		}

		for(; iUIIndex < _His_ConfigSetting_MaxClickItems; ++iUIIndex){
			scitemcheckBox[iUIIndex]->setChecked(false);
		}
	}

	ui.dualSynccheckBox->setChecked(HISCCMSHORTCUT::getShortcutSync());
}

void QHShortcut::iterfacetoshortcutinfo(int iChannel, char cKey, int iClickTime)
{
	_shoutCutDetail stItem;
	stItem.shortcutKey = cKey;
	stItem.ucClickTime	=	iClickTime;

	if(iChannel == 2)
	{
		int iNextItemIndex, iIndexAdd = 1, iUIIndex = 0;
		bool bLoop	=	true;
		while(bLoop){
			bLoop	=	false;
			for(int x=0;	x<listShortcutC1.size();	++x){
				if(listShortcutC1[x].shortcutKey == cKey && listShortcutC1[x].ucClickTime == iClickTime && listShortcutC1[x].bDualCamera){
					bLoop = true;
					iNextItemIndex	=	x;
					break;
				}
			}
			if(bLoop) listShortcutC1.removeAt(iNextItemIndex);
		}

		bLoop	=	true;
		while(bLoop){
			bLoop	=	false;
			for(int x=0;	x<listShortcutC2.size();	++x){
				if(listShortcutC2[x].shortcutKey == cKey && listShortcutC2[x].ucClickTime == iClickTime && listShortcutC2[x].bDualCamera){
					bLoop = true;
					iNextItemIndex	=	x;
					break;
				}
			}
			if(bLoop) listShortcutC2.removeAt(iNextItemIndex);
		}

		stItem.bDualCamera	=	true;
		for(unsigned int x=0;	x<_His_ConfigSetting_MaxClickItems;	++x){
			if(!scitemcheckBox[x]->isChecked()) continue;
			if(!c1itemcheckBox[x]->isChecked() && !c2itemcheckBox[x]->isChecked()) continue;
			stItem.usItem			=	HISGLOBALSHORTCUT::getIdFromDescripeName(allitemList, scitemcomboBox[x]->currentText());
			stItem.ucloopTime	=	scitemspinBox[x]->value();
			if(scitemngcomboBox[x]->currentIndex() == 0)
				stItem.usItemfail	=	0;
			else
				stItem.usItemfail		=	HISGLOBALSHORTCUT::getIdFromDescripeName(allitemList, scitemngcomboBox[x]->currentText());
			stItem.ucItemIndex		=	iIndexAdd++;

			if(c1itemcheckBox[x]->isChecked()){
				stItem.strAddInfo		=	c1itemlineEdit[x]->text();
				listShortcutC1.push_back(stItem);
			}

			if(c2itemcheckBox[x]->isChecked()){
				stItem.strAddInfo		=	c2itemlineEdit[x]->text();
				listShortcutC2.push_back(stItem);
			}
		}
	}
	else
	{
		QShortcutList& listShortcut = (iChannel == 0)?(listShortcutC1):(listShortcutC2);
		int iNextItemIndex, iIndexAdd = 1, iUIIndex = 0;
		bool bLoop	=	true;
		while(bLoop){
			bLoop	=	false;
			for(int x=0;	x<listShortcut.size();	++x){
				if(listShortcut[x].shortcutKey == cKey && listShortcut[x].ucClickTime == iClickTime && !listShortcut[x].bDualCamera){
					bLoop = true;
					iNextItemIndex	=	x;
					break;
				}
			}
			if(bLoop) listShortcut.removeAt(iNextItemIndex);
		}

		stItem.bDualCamera	=	false;
		for(unsigned int x=0;	x<_His_ConfigSetting_MaxClickItems;	++x){
			if(!scitemcheckBox[x]->isChecked()) continue;
			stItem.usItem			=	HISGLOBALSHORTCUT::getIdFromDescripeName(allitemList, scitemcomboBox[x]->currentText());
			stItem.strAddInfo		=	c1itemlineEdit[x]->text();
			stItem.ucloopTime	=	scitemspinBox[x]->value();
			if(scitemngcomboBox[x]->currentIndex() == 0)
				stItem.usItemfail	=	0;
			else
				stItem.usItemfail		=	HISGLOBALSHORTCUT::getIdFromDescripeName(allitemList, scitemngcomboBox[x]->currentText());
			stItem.ucItemIndex		=	iIndexAdd++;
			listShortcut.push_back(stItem);
		}


	}

}

void QHShortcut::slotscitemchangego(const QString& text)
{
	QComboBox* pstsensder	=	 qobject_cast<QComboBox*>(sender());
	unsigned int iUIIndex;
	for(unsigned int x =0; x< _His_ConfigSetting_MaxClickItems; ++x)
	{
		if(pstsensder == scitemcomboBox[x]) {iUIIndex = x; break; }
	}

	if(ciModeChannel == 2)
	{
		QString strEditInfo			=	HISGLOBALSHORTCUT::getEditInfoFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
		QString strSaveName		=	HISGLOBALSHORTCUT::getSaveNameFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
		c1itemlineEdit[iUIIndex]->setText(strEditInfo);
		c2itemlineEdit[iUIIndex]->setText(strEditInfo);
		if(!strEditInfo.isEmpty()){
			if(c1itemcheckBox[iUIIndex]->isChecked()){
				QHTextItemEdit itemexeItemEdit(this,strSaveName,strEditInfo, true);
				itemexeItemEdit.setWindowTitle(tr("Channel 1"));
				if(itemexeItemEdit.exec() == QDialog::Accepted)
					c1itemlineEdit[iUIIndex]->setText(itemexeItemEdit.strNewAddInfo);
			}

			if(c2itemcheckBox[iUIIndex]->isChecked()){
				QHTextItemEdit itemexeItemEdit(this,strSaveName,strEditInfo, false);
				itemexeItemEdit.setWindowTitle(tr("Channel 2"));
				if(itemexeItemEdit.exec() == QDialog::Accepted)
					c2itemlineEdit[iUIIndex]->setText(itemexeItemEdit.strNewAddInfo);
			}
		}

	}
	else
	{
		QString strEditInfo			=	HISGLOBALSHORTCUT::getEditInfoFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
		QString strSaveName		=	HISGLOBALSHORTCUT::getSaveNameFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
		c1itemlineEdit[iUIIndex]->setText(strEditInfo);
		if(!strEditInfo.isEmpty()){
			QHTextItemEdit itemexeItemEdit(this,strSaveName,strEditInfo);
			if(itemexeItemEdit.exec() == QDialog::Accepted)
				c1itemlineEdit[iUIIndex]->setText(itemexeItemEdit.strNewAddInfo);
		}
	}
}

void QHShortcut::sloteditShotcutExeC1()
{
	QPushButton* pstsensder	=	 qobject_cast<QPushButton*>(sender());
	unsigned int iUIIndex;
	for(unsigned int x =0; x< _His_ConfigSetting_MaxClickItems; ++x)
	{
		if(pstsensder == c1editpushButton[x]) {iUIIndex = x; break; }
	}

	QString strSaveName		=	HISGLOBALSHORTCUT::getSaveNameFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
	QString strEditInfo			=	c1itemlineEdit[iUIIndex]->text();

	if(!strEditInfo.isEmpty())
	{
		QHTextItemEdit itemexeItemEdit(this,strSaveName,strEditInfo, true);
		if(itemexeItemEdit.exec() == QDialog::Accepted)
			c1itemlineEdit[iUIIndex]->setText(itemexeItemEdit.strNewAddInfo);
	}
}

void QHShortcut::sloteditShotcutExeC2()
{
	QPushButton* pstsensder	=	 qobject_cast<QPushButton*>(sender());
	unsigned int iUIIndex;
	for(unsigned int x =0; x< _His_ConfigSetting_MaxClickItems; ++x)
	{
		if(pstsensder == c2editpushButton[x]) {iUIIndex = x; break; }
	}

	QString strSaveName		=	HISGLOBALSHORTCUT::getSaveNameFromDescripeName(allitemList, scitemcomboBox[iUIIndex]->currentText());
	QString strEditInfo			=	c2itemlineEdit[iUIIndex]->text();

	if(!strEditInfo.isEmpty())
	{
		QHTextItemEdit itemexeItemEdit(this,strSaveName,strEditInfo, false);
		if(itemexeItemEdit.exec() == QDialog::Accepted)
			c2itemlineEdit[iUIIndex]->setText(itemexeItemEdit.strNewAddInfo);
	}
}

void QHShortcut::slotinsertShotcutExe()
{
	QPushButton* pstsensder	=	 qobject_cast<QPushButton*>(sender());
	int iIndex;
	for(int x =0; x< _His_ConfigSetting_MaxClickItems-1; ++x)
	{
		if(pstsensder == scitemAddpushButton[x]) {iIndex = x; break; }
	}

	for(int x=_His_ConfigSetting_MaxClickItems-1;	x>iIndex+1; --x){
		scitemcheckBox[x]->setChecked(scitemcheckBox[x-1]->isChecked());
		scitemcomboBox[x]->setCurrentIndex(scitemcomboBox[x-1]->currentIndex());
		c1itemcheckBox[x]->setChecked(c1itemcheckBox[x-1]->isChecked());
		c1itemlineEdit[x]->setText(c1itemlineEdit[x-1]->text());
		c2itemcheckBox[x]->setChecked(c2itemcheckBox[x-1]->isChecked());
		c2itemlineEdit[x]->setText(c2itemlineEdit[x-1]->text());
		scitemspinBox[x]->setValue(scitemspinBox[x-1]->value());	
		scitemngcomboBox[x]->setCurrentIndex(scitemngcomboBox[x-1]->currentIndex());
	}

	scitemcheckBox[iIndex+1]->setChecked(false);
}

void QHShortcut::listShortcutKey(int iChannel)
{
	unsigned int uiCount	=	0;
	char key[60];
	bool bExist;

	if(iChannel == 0)
	{
		for(int x=0;	x<listShortcutC1.size();	++x)
		{
			if(listShortcutC1[x].bDualCamera) continue;
			bExist	=	false;
			for(unsigned int i=0;	i<uiCount;	++i){
				if(listShortcutC1[x].shortcutKey == key[i]) { bExist = true; break; }
			}
			if(!bExist) key[uiCount++]	=	listShortcutC1[x].shortcutKey;
		}
	}
	else if(iChannel == 1)
	{
		for(int x=0;	x<listShortcutC2.size();	++x)
		{
			if(listShortcutC2[x].bDualCamera) continue;
			bExist	=	false;
			for(unsigned int i=0;	i<uiCount;	++i){
				if(listShortcutC2[x].shortcutKey == key[i]) { bExist = true; break; }
			}
			if(!bExist) key[uiCount++]	=	listShortcutC2[x].shortcutKey;
		}
	}
	else
	{
		for(int x=0;	x<listShortcutC1.size();	++x)
		{
			if(!listShortcutC1[x].bDualCamera) continue;
			bExist	=	false;
			for(unsigned int i=0;	i<uiCount;	++i){
				if(listShortcutC1[x].shortcutKey == key[i]) { bExist = true; break; }
			}
			if(!bExist) key[uiCount++]	=	listShortcutC1[x].shortcutKey;
		}

		for(int x=0;	x<listShortcutC2.size();	++x)
		{
			if(!listShortcutC2[x].bDualCamera) continue;
			bExist	=	false;
			for(unsigned int i=0;	i<uiCount;	++i){
				if(listShortcutC2[x].shortcutKey == key[i]) { bExist = true; break; }
			}
			if(!bExist) key[uiCount++]	=	listShortcutC2[x].shortcutKey;
		}
	}

	for(unsigned int x=0;	x<uiCount;	++x)
	{
		if(key[x] == '=') sccheckBox[0]->setChecked(true);
		else if(key[x] >= '0' && key[x] <= '9')	sccheckBox[(key[x]-'0') +1]->setChecked(true);
		else if(key[x] >= 'a' && key[x] <= 'z')	sccheckBox[(key[x]-'a') +11]->setChecked(true);
	}

	freshValidKeyComboBox(key, uiCount);
}

void QHShortcut::freshValidKeyComboBox(char* key, unsigned int uiCount, char prekey)
{
	ui.scchoosecomboBox->clear();
	QStringList keyList, numList, alphaList;

	for(unsigned int x=0;	x<uiCount;	++x)
	{
		if(key[x] == '=') keyList.push_back(tr("Button"));
	}

	for(unsigned int x=0;	x<uiCount;	++x)
	{
		if(key[x] >= '0' && key[x] <= '9') numList.push_back(QString::fromAscii(key+x, 1));
	}

	for(unsigned int x=0;	x<uiCount;	++x)
	{
		if(key[x] >= 'a' && key[x] <= 'z') {char upkey = key[x] -32;  alphaList.push_back(QString::fromAscii(&upkey, 1));}
	}

	numList.sort();
	alphaList.sort();
	keyList.append(numList);
	keyList.append(alphaList);

	ui.scchoosecomboBox->addItems(keyList);

	if(keyList.count() >0 && prekey != '[')
	{
		QString theStr	=	key2Str(prekey);
		ui.scchoosecomboBox->setCurrentIndex(ui.scchoosecomboBox->findText(theStr));
	}
}

void QHShortcut::slotKeyOnOff(int state)
{
	QCheckBox* pstsensder	=	 qobject_cast<QCheckBox*>(sender());
	unsigned int iUIIndex;
	for(unsigned int x =0; x< _His_ConfigSetting_MaxClickItems; ++x)
	{
		if(pstsensder == sccheckBox[x]) {iUIIndex = x; break; }
	}

	if(state == Qt::Checked)
	{
		char keyList[60];
		unsigned int uiCount	=	0;
		for(unsigned int x=0;	x<ui.scchoosecomboBox->count();	++x)
		{
			keyList[uiCount++]	=	str2Key(ui.scchoosecomboBox->itemText(x));
		}

		keyList[uiCount++]	=	str2Key(sccheckBox[iUIIndex]->text());
		freshValidKeyComboBox(keyList, uiCount, keyList[uiCount-1]);
		shortcutinfotointerface(ciModeChannel, keyList[uiCount-1], ui.scclickcomboBox->currentIndex()+1);
	}
	else
	{
		int iIndex	=	ui.scchoosecomboBox->findText(sccheckBox[iUIIndex]->text());
		if(iIndex >= 0) {
			ui.scchoosecomboBox->removeItem(iIndex);
			shortcutinfotointerface(ciModeChannel, str2Key(ui.scchoosecomboBox->currentText()), ui.scclickcomboBox->currentIndex() + 1);
		}
	}

}

void QHShortcut::slotsceditchange(int index)
{
	char key	=	str2Key(ui.scchoosecomboBox->currentText());
	shortcutinfotointerface(ciModeChannel, key, ui.scclickcomboBox->currentIndex() + 1);
}

bool QHShortcut::isKeyChecked(char key)
{
	if(key == '=')
	{
		return sccheckBox[0]->isChecked();
	}
	else if(key >= '0' && key <= '9')
	{
		return sccheckBox[(key - '0') +1]->isChecked();
	}
	else if(key >= 'a' && key <= 'z')
	{
		return sccheckBox[(key - 'a') +11]->isChecked();
	}

	return false;
}
