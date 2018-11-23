#include "QHDrawTEstItem.h"

QHDrawTEstItem::QHDrawTEstItem(_global_itemexec& itemshareData2,bool bShow,QWidget *parent)
	: QDockWidget(parent),itemshareData(itemshareData2)
{
	ui.setupUi(this);
}

QHDrawTEstItem::~QHDrawTEstItem()
{

}

void QHDrawTEstItem::slotTotalTestTime(unsigned int uiTime)
{
	this->setWindowTitle(tr("Test Item Panel") % "(" % QString::number(uiTime) % "ms)");
}

void QHDrawTEstItem::drawitem()
{

	int iwidth	=	180, iheight = 1200, iGap = 5;
	QPixmap itemmap(iwidth, iheight);
	itemmap.fill(QColor::fromRgb(240, 240, 240));
	QPainter painter(&itemmap);

	painter.setPen(Qt::SolidLine);
	painter.setPen(QColor::fromRgb(0,0,0));

	QBrush labelbrush(QColor::fromRgb(0,255,0), Qt::SolidPattern);
	QFont labelfont("Arial");
	labelfont.setBold(true);
	int ifontsize			=	23;
	int iminifontsize	=	3;

	// 	QBrush timebrush(QColor::fromRgb(255,255,255), Qt::SolidPattern);
	QFont timefont("Arial");
	timefont.setBold(true);

	QRect textrect, timerect;
	QString diaplaytext;

	itemshareData.itemstatusLock.lockForRead();

	unsigned char ucitemCount	=	(itemshareData.itemstatusList.size() > 10)?(itemshareData.itemstatusList.size()):(10);
	ucitemCount	=	(ucitemCount > 30)?(30):(ucitemCount);
	if(ucitemCount > 15){
		ifontsize	=	static_cast<int>(static_cast<float>(15*23) / static_cast<float>(ucitemCount));
		iGap	=	0;
	}
	int irect		=	iheight / ucitemCount - iGap;
	ucitemCount	=	(ucitemCount > itemshareData.itemstatusList.size())?(itemshareData.itemstatusList.size()):(ucitemCount);

	textrect.setRect (0, 0, iwidth, irect);
	labelfont.setPointSize(ifontsize);
	timefont.setPointSize(ifontsize/ 2);

	for(unsigned char uci=0;	uci < ucitemCount	;++uci){
		switch (itemshareData.itemstatusList[uci].ucstatus){
		case _His_ItemStatus_NG:
			labelbrush.setColor(QColor::fromRgb(255,0,0));
			break;
		case _His_ItemStatus_PASS:
			labelbrush.setColor(QColor::fromRgb(0,255,0));
			break;
		case _His_ItemStatus_Testing:
		default:
			labelbrush.setColor(QColor::fromRgb(255,255,0));
			break;
		}

		painter.setBrush(labelbrush);
		painter.setFont(labelfont);

		diaplaytext	=	HISCCMSHORTCUT::item2displaytext(itemshareData.itemstatusList[uci].usitem);

		painter.drawRect(textrect);
		painter.drawText(textrect, QPainter::Antialiasing | Qt::AlignCenter, diaplaytext);

		if(itemshareData.itemstatusList[uci].ustime != 0xFFFFFFFF){
			// 		painter.setBrush(timebrush);
			painter.setFont(timefont);
			timerect.setBottomRight(textrect.bottomRight());
			timerect.setLeft(textrect.left() + (textrect.right() - textrect.left()) *2 /3);
			timerect.setTop(textrect.top() + (textrect.bottom() - textrect.top()) *2 /3);
			// 		painter.drawRect(timerect);
			painter.drawText(timerect, QPainter::Antialiasing | Qt::AlignCenter, QString::number(itemshareData.itemstatusList[uci].ustime, 10) % "ms");
		}

		textrect.moveTop(textrect.bottom() + iGap);
	}

	itemshareData.itemstatusLock.unlock();

	ui.itemlabel->setPixmap(itemmap);
}
