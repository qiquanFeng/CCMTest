#include "qitemexetool.h"
#include <QTextCodec>
#include <QPushButton>
 #include <QStringBuilder>
#include <QIcon>
#include <QSqlDatabase>
#include <QDir>
#include <QSqlQuery>
// #include "inc/versionswitch.h"
// #include "inc/HisFX3Platform.h"
#include "itemGlobalHeader.h"

// typedef void (qitemexetool::*itemexetoolitemslot)();


qitemexetool::qitemexetool(QWidget *parent, QStringList& listKey2)
	: QDockWidget(parent), listKey(listKey2)
{
	ui.setupUi(this);
	initAllItem();
	createItemTable();

}

qitemexetool::~qitemexetool()
{

}

void qitemexetool::initAllItem()
{
	QList<_TestItem_Basic_Info> itemList;
	globalgetListWantedTestItem(itemList, listKey);
	for(QList<_TestItem_Basic_Info>::iterator theiterator = itemList.begin(); theiterator != itemList.end(); theiterator++)
	{
		testitem_pushback(theiterator->uiID,theiterator->strSaveName, theiterator->strDescripName, theiterator->strType, theiterator->strEditInfo, theiterator->strHelpInfo);
	}
}

void qitemexetool::createItemTable()
{
	QWidget * contents = new QWidget(this);
	QHBoxLayout * hlayout = new QHBoxLayout(contents);

	QVBoxLayout * vlayout1 = new QVBoxLayout();
	for(unsigned int x=0;	x<listitem.size();	++x){
		QPushButton* pstButtonItem	=	new QPushButton();
		pstButtonItem->setText(listitem[x].strItemShowText);
		pstButtonItem->setMaximumHeight(20);
		pstButtonItem->setMinimumHeight(20);

		switch (x){
		case 0: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe0()));	break;
		case 1: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe1()));	break;
		case 2: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe2()));	break;
		case 3: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe3()));	break;
		case 4: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe4()));	break;
		case 5: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe5()));	break;
		case 6: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe6()));	break;
		case 7: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe7()));	break;
		case 8: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe8()));	break;
		case 9: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe9()));	break;
		case 10: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe10()));	break;
		case 11: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe11()));	break;
		case 12: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe12()));	break;
		case 13: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe13()));	break;
		case 14: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe14()));	break;
		case 15: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe15()));	break;
		case 16: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe16()));	break;
		case 17: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe17()));	break;
		case 18: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe18()));	break;
		case 19: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe19()));	break;
		case 20: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe20()));	break;
		case 21: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe21()));	break;
		case 22: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe22()));	break;
		case 23: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe23()));	break;
		case 24: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe24()));	break;
		case 25: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe25()));	break;
		case 26: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe26()));	break;
		case 27: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe27()));	break;
		case 28: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe28()));	break;
		case 29: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe29()));	break;
		case 30: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe30()));	break;
		case 31: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe31()));	break;
		case 32: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe32()));	break;
		case 33: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe33()));	break;
		case 34: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe34()));	break;
		case 35: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe35()));	break;
		case 36: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe36()));	break;
		case 37: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe37()));	break;
		case 38: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe38()));	break;
		case 39: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe39()));	break;
		case 40: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe40()));	break;
		case 41: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe41()));	break;
		case 42: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe42()));	break;
		case 43: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe43()));	break;
		case 44: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe44()));	break;
		case 45: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe45()));	break;
		case 46: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe46()));	break;
		case 47: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe47()));	break;
		case 48: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe48()));	break;
		case 49: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe49()));	break;
		case 50: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe50()));	break;
		case 51: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe51()));	break;
		case 52: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe52()));	break;
		case 53: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe53()));	break;
		case 54: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe54()));	break;
		case 55: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe55()));	break;
		case 56: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe56()));	break;
		case 57: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe57()));	break;
		case 58: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe58()));	break;
		case 59: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe59()));	break;
		case 60: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe60()));	break;
		case 61: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe61()));	break;
		case 62: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe62()));	break;
		case 63: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe63()));	break;
		case 64: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe64()));	break;
		case 65: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe65()));	break;
		case 66: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe66()));	break;
		case 67: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe67()));	break;
		case 68: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe68()));	break;
		case 69: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe69()));	break;
		case 70: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe70()));	break;
		case 71: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe71()));	break;
		case 72: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe72()));	break;
		case 73: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe73()));	break;
		case 74: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe74()));	break;
		case 75: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe75()));	break;
		case 76: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe76()));	break;
		case 77: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe77()));	break;
		case 78: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe78()));	break;
		case 79: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe79()));	break;
		case 80: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe80()));	break;
		case 81: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe81()));	break;
		case 82: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe82()));	break;
		case 83: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe83()));	break;
		case 84: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe84()));	break;
		case 85: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe85()));	break;
		case 86: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe86()));	break;
		case 87: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe87()));	break;
		case 88: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe88()));	break;
		case 89: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe89()));	break;
		case 90: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe90()));	break;
		case 91: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe91()));	break;
		case 92: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe92()));	break;
		case 93: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe93()));	break;
		case 94: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe94()));	break;
		case 95: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe95()));	break;
		case 96: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe96()));	break;
		case 97: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe97()));	break;
		case 98: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe98()));	break;
		case 99: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe99()));	break;
		case 100: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe100()));	break;
		case 101: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe101()));	break;
		case 102: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe102()));	break;
		case 103: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe103()));	break;
		case 104: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe104()));	break;
		case 105: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe105()));	break;
		case 106: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe106()));	break;
		case 107: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe107()));	break;
		case 108: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe108()));	break;
		case 109: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe109()));	break;
		case 110: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe110()));	break;
		case 111: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe111()));	break;
		case 112: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe112()));	break;
		case 113: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe113()));	break;
		case 114: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe114()));	break;
		case 115: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe115()));	break;
		case 116: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe116()));	break;
		case 117: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe117()));	break;
		case 118: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe118()));	break;
		case 119: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe119()));	break;
		case 120: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe120()));	break;
		case 121: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe121()));	break;
		case 122: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe122()));	break;
		case 123: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe123()));	break;
		case 124: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe124()));	break;
		case 125: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe125()));	break;
		case 126: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe126()));	break;
		case 127: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe127()));	break;
		case 128: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe128()));	break;
		case 129: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe129()));	break;
		case 130: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe130()));	break;
		case 131: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe131()));	break;
		case 132: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe132()));	break;
		case 133: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe133()));	break;
		case 134: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe134()));	break;
		case 135: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe135()));	break;
		case 136: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe136()));	break;
		case 137: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe137()));	break;
		case 138: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe138()));	break;
		case 139: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe139()));	break;
		case 140: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe140()));	break;
		case 141: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe141()));	break;
		case 142: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe142()));	break;
		case 143: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe143()));	break;
		case 144: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe144()));	break;
		case 145: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe145()));	break;
		case 146: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe146()));	break;
		case 147: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe147()));	break;
		case 148: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe148()));	break;
		case 149: connect(pstButtonItem, SIGNAL(released()), this, SLOT(itemexe149()));	break;
		default: break;
		}

		vlayout1->addWidget(pstButtonItem);
	}
// 	vlayout1->setSizeConstraint(QLayout::SetFixedSize);
	hlayout->addLayout(vlayout1);

	QVBoxLayout * vlayout2 = new QVBoxLayout();
	for(unsigned int x=0;	x<listitem.size();	++x){
		QLineEdit* pstEdit	=	new QLineEdit();
		pstEdit->setMaximumHeight(20);
		pstEdit->setMinimumHeight(20);
		pstEdit->setMaximumWidth(60);
		pstEdit->setText(listitem[x].strAddInfo);
		listitem[x].pstEdit	=	pstEdit;
		vlayout2->addWidget(pstEdit);
	}
// 	vlayout2->setSizeConstraint(QLayout::SetFixedSize);
	hlayout->addLayout(vlayout2);

	QVBoxLayout * vlayout4 = new QVBoxLayout();
	for(unsigned int x=0;	x<listitem.size();	++x)
	{
		QPushButton* pstButtonEdit	=	new QPushButton(QIcon(":/Resources/edit.png"), "");
		pstButtonEdit->setMaximumWidth(32);
		pstButtonEdit->setMaximumHeight(20);
		pstButtonEdit->setMinimumHeight(20);
		switch (x)
		{
		case 0: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe0()));	break;
		case 1: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe1()));	break;
		case 2: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe2()));	break;
		case 3: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe3()));	break;
		case 4: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe4()));	break;
		case 5: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe5()));	break;
		case 6: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe6()));	break;
		case 7: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe7()));	break;
		case 8: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe8()));	break;
		case 9: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe9()));	break;
		case 10: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe10()));	break;
		case 11: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe11()));	break;
		case 12: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe12()));	break;
		case 13: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe13()));	break;
		case 14: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe14()));	break;
		case 15: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe15()));	break;
		case 16: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe16()));	break;
		case 17: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe17()));	break;
		case 18: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe18()));	break;
		case 19: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe19()));	break;
		case 20: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe20()));	break;
		case 21: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe21()));	break;
		case 22: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe22()));	break;
		case 23: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe23()));	break;
		case 24: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe24()));	break;
		case 25: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe25()));	break;
		case 26: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe26()));	break;
		case 27: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe27()));	break;
		case 28: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe28()));	break;
		case 29: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe29()));	break;
		case 30: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe30()));	break;
		case 31: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe31()));	break;
		case 32: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe32()));	break;
		case 33: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe33()));	break;
		case 34: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe34()));	break;
		case 35: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe35()));	break;
		case 36: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe36()));	break;
		case 37: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe37()));	break;
		case 38: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe38()));	break;
		case 39: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe39()));	break;
		case 40: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe40()));	break;
		case 41: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe41()));	break;
		case 42: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe42()));	break;
		case 43: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe43()));	break;
		case 44: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe44()));	break;
		case 45: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe45()));	break;
		case 46: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe46()));	break;
		case 47: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe47()));	break;
		case 48: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe48()));	break;
		case 49: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe49()));	break;
		case 50: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe50()));	break;
		case 51: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe51()));	break;
		case 52: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe52()));	break;
		case 53: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe53()));	break;
		case 54: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe54()));	break;
		case 55: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe55()));	break;
		case 56: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe56()));	break;
		case 57: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe57()));	break;
		case 58: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe58()));	break;
		case 59: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe59()));	break;
		case 60: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe60()));	break;
		case 61: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe61()));	break;
		case 62: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe62()));	break;
		case 63: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe63()));	break;
		case 64: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe64()));	break;
		case 65: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe65()));	break;
		case 66: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe66()));	break;
		case 67: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe67()));	break;
		case 68: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe68()));	break;
		case 69: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe69()));	break;
		case 70: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe70()));	break;
		case 71: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe71()));	break;
		case 72: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe72()));	break;
		case 73: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe73()));	break;
		case 74: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe74()));	break;
		case 75: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe75()));	break;
		case 76: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe76()));	break;
		case 77: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe77()));	break;
		case 78: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe78()));	break;
		case 79: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe79()));	break;
		case 80: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe80()));	break;
		case 81: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe81()));	break;
		case 82: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe82()));	break;
		case 83: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe83()));	break;
		case 84: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe84()));	break;
		case 85: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe85()));	break;
		case 86: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe86()));	break;
		case 87: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe87()));	break;
		case 88: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe88()));	break;
		case 89: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe89()));	break;
		case 90: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe90()));	break;
		case 91: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe91()));	break;
		case 92: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe92()));	break;
		case 93: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe93()));	break;
		case 94: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe94()));	break;
		case 95: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe95()));	break;
		case 96: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe96()));	break;
		case 97: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe97()));	break;
		case 98: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe98()));	break;
		case 99: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe99()));	break;
		case 100: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe100()));	break;
		case 101: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe101()));	break;
		case 102: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe102()));	break;
		case 103: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe103()));	break;
		case 104: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe104()));	break;
		case 105: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe105()));	break;
		case 106: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe106()));	break;
		case 107: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe107()));	break;
		case 108: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe108()));	break;
		case 109: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe109()));	break;
		case 110: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe110()));	break;
		case 111: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe111()));	break;
		case 112: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe112()));	break;
		case 113: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe113()));	break;
		case 114: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe114()));	break;
		case 115: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe115()));	break;
		case 116: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe116()));	break;
		case 117: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe117()));	break;
		case 118: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe118()));	break;
		case 119: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe119()));	break;
		case 120: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe120()));	break;
		case 121: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe121()));	break;
		case 122: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe122()));	break;
		case 123: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe123()));	break;
		case 124: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe124()));	break;
		case 125: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe125()));	break;
		case 126: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe126()));	break;
		case 127: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe127()));	break;
		case 128: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe128()));	break;
		case 129: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe129()));	break;
		case 130: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe130()));	break;
		case 131: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe131()));	break;
		case 132: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe132()));	break;
		case 133: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe133()));	break;
		case 134: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe134()));	break;
		case 135: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe135()));	break;
		case 136: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe136()));	break;
		case 137: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe137()));	break;
		case 138: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe138()));	break;
		case 139: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe139()));	break;
		case 140: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe140()));	break;
		case 141: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe141()));	break;
		case 142: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe142()));	break;
		case 143: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe143()));	break;
		case 144: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe144()));	break;
		case 145: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe145()));	break;
		case 146: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe146()));	break;
		case 147: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe147()));	break;
		case 148: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe148()));	break;
		case 149: connect(pstButtonEdit, SIGNAL(released()), this, SLOT(editexe149()));	break;
		default: break;
		}

		vlayout4->addWidget(pstButtonEdit);
// 		vlayout4->setSizeConstraint(QLayout::SetFixedSize);
		hlayout->addLayout(vlayout4);
	}
	QVBoxLayout * vlayout3 = new QVBoxLayout();
	for(unsigned int x=0;	x<listitem.size();	++x){
		QPushButton* pstButtonHelp	=	new QPushButton(QIcon(":/Resources/help32.png"), "");
		pstButtonHelp->setMaximumWidth(32);
		pstButtonHelp->setMaximumHeight(20);
		pstButtonHelp->setMinimumHeight(20);

		switch (x){
		case 0: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe0()));	break;
		case 1: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe1()));	break;
		case 2: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe2()));	break;
		case 3: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe3()));	break;
		case 4: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe4()));	break;
		case 5: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe5()));	break;
		case 6: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe6()));	break;
		case 7: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe7()));	break;
		case 8: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe8()));	break;
		case 9: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe9()));	break;
		case 10: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe10()));	break;
		case 11: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe11()));	break;
		case 12: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe12()));	break;
		case 13: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe13()));	break;
		case 14: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe14()));	break;
		case 15: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe15()));	break;
		case 16: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe16()));	break;
		case 17: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe17()));	break;
		case 18: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe18()));	break;
		case 19: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe19()));	break;
		case 20: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe20()));	break;
		case 21: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe21()));	break;
		case 22: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe22()));	break;
		case 23: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe23()));	break;
		case 24: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe24()));	break;
		case 25: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe25()));	break;
		case 26: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe26()));	break;
		case 27: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe27()));	break;
		case 28: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe28()));	break;
		case 29: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe29()));	break;
		case 30: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe30()));	break;
		case 31: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe31()));	break;
		case 32: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe32()));	break;
		case 33: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe33()));	break;
		case 34: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe34()));	break;
		case 35: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe35()));	break;
		case 36: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe36()));	break;
		case 37: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe37()));	break;
		case 38: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe38()));	break;
		case 39: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe39()));	break;
		case 40: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe40()));	break;
		case 41: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe41()));	break;
		case 42: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe42()));	break;
		case 43: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe43()));	break;
		case 44: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe44()));	break;
		case 45: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe45()));	break;
		case 46: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe46()));	break;
		case 47: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe47()));	break;
		case 48: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe48()));	break;
		case 49: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe49()));	break;
		case 50: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe50()));	break;
		case 51: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe51()));	break;
		case 52: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe52()));	break;
		case 53: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe53()));	break;
		case 54: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe54()));	break;
		case 55: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe55()));	break;
		case 56: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe56()));	break;
		case 57: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe57()));	break;
		case 58: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe58()));	break;
		case 59: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe59()));	break;
		case 60: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe60()));	break;
		case 61: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe61()));	break;
		case 62: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe62()));	break;
		case 63: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe63()));	break;
		case 64: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe64()));	break;
		case 65: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe65()));	break;
		case 66: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe66()));	break;
		case 67: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe67()));	break;
		case 68: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe68()));	break;
		case 69: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe69()));	break;
		case 70: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe70()));	break;
		case 71: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe71()));	break;
		case 72: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe72()));	break;
		case 73: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe73()));	break;
		case 74: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe74()));	break;
		case 75: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe75()));	break;
		case 76: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe76()));	break;
		case 77: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe77()));	break;
		case 78: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe78()));	break;
		case 79: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe79()));	break;
		case 80: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe80()));	break;
		case 81: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe81()));	break;
		case 82: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe82()));	break;
		case 83: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe83()));	break;
		case 84: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe84()));	break;
		case 85: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe85()));	break;
		case 86: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe86()));	break;
		case 87: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe87()));	break;
		case 88: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe88()));	break;
		case 89: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe89()));	break;
		case 90: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe90()));	break;
		case 91: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe91()));	break;
		case 92: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe92()));	break;
		case 93: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe93()));	break;
		case 94: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe94()));	break;
		case 95: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe95()));	break;
		case 96: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe96()));	break;
		case 97: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe97()));	break;
		case 98: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe98()));	break;
		case 99: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe99()));	break;
		case 100: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe100()));	break;
		case 101: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe101()));	break;
		case 102: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe102()));	break;
		case 103: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe103()));	break;
		case 104: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe104()));	break;
		case 105: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe105()));	break;
		case 106: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe106()));	break;
		case 107: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe107()));	break;
		case 108: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe108()));	break;
		case 109: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe109()));	break;
		case 110: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe110()));	break;
		case 111: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe111()));	break;
		case 112: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe112()));	break;
		case 113: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe113()));	break;
		case 114: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe114()));	break;
		case 115: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe115()));	break;
		case 116: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe116()));	break;
		case 117: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe117()));	break;
		case 118: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe118()));	break;
		case 119: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe119()));	break;
		case 120: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe120()));	break;
		case 121: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe121()));	break;
		case 122: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe122()));	break;
		case 123: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe123()));	break;
		case 124: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe124()));	break;
		case 125: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe125()));	break;
		case 126: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe126()));	break;
		case 127: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe127()));	break;
		case 128: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe128()));	break;
		case 129: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe129()));	break;
		case 130: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe130()));	break;
		case 131: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe131()));	break;
		case 132: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe132()));	break;
		case 133: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe133()));	break;
		case 134: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe134()));	break;
		case 135: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe135()));	break;
		case 136: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe136()));	break;
		case 137: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe137()));	break;
		case 138: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe138()));	break;
		case 139: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe139()));	break;
		case 140: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe140()));	break;
		case 141: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe141()));	break;
		case 142: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe142()));	break;
		case 143: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe143()));	break;
		case 144: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe144()));	break;
		case 145: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe145()));	break;
		case 146: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe146()));	break;
		case 147: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe147()));	break;
		case 148: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe148()));	break;
		case 149: connect(pstButtonHelp, SIGNAL(released()), this, SLOT(helpexe149()));	break;
		default: break;
		}

		vlayout3->addWidget(pstButtonHelp);

	}
// 	vlayout3->setSizeConstraint(QLayout::SetFixedSize);
	hlayout->addLayout(vlayout3);

// 	hlayout->setSizeConstraint(QLayout::SetFixedSize);
	
	ui.scrollArea->setWidget(contents);
}

void qitemexetool::testitem_pushback(unsigned short usItem, QString strItem, QString strItemShowText, QString strType, QString strAddInfo, QString strHelpInfo)
{
	_QItemToolItemTestInfo stItem;
	stItem.usItem					=	usItem;
	stItem.strItem					=	strItem;
	stItem.strItemShowText	=	strItemShowText;
	stItem.strAddInfo				=	strAddInfo;
	stItem.strHelpInfo			=	strHelpInfo;
	stItem.strType					=	strType;
	listitem.push_back(stItem);
}

void qitemexetool::itemtheexe(int iindex)
{
	listitem[iindex].strAddInfo	=	listitem[iindex].pstEdit->text().trimmed();
	emit itemdebugsignal(listitem[iindex].usItem, listitem[iindex].strAddInfo);
}

void qitemexetool::helptheexe(int iindex)
{
	QMessageBox::information(this, listitem[iindex].strItemShowText,listitem[iindex].strHelpInfo);
}

void qitemexetool::edittheexe(int iindex)
{
	index=	iindex;
	if (listitem[iindex].strAddInfo	== "")
	{
		return;
	}

	QHTextItemEdit itemexeItemEdit(this,listitem[iindex].strItem,listitem[iindex].pstEdit->text());
	if(itemexeItemEdit.exec() == QDialog::Accepted)
		listitem[iindex].pstEdit->setText(itemexeItemEdit.strNewAddInfo);

}

