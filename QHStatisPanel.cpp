#include "QHStatisPanel.h"
#include <QMenu>

QHStatisPanel::QHStatisPanel(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC,_global_itemexec& itemshare)
	: QDockWidget(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC),itemshareData(itemshare)
{
	ui.setupUi(this);
	connect(ui.statisticsinfolabel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tactistics_customMenuRequested(QPoint)));

}

QHStatisPanel::~QHStatisPanel()
{

}


void QHStatisPanel::drawStatisticsImage()
{
	if(ui.statisticsinfolabel->height() +80 > ui.statisticsinfolabel->width())
	{
		int iWdith = ui.statisticsinfolabel->width()-4;
		int iHeight	=	ui.statisticsinfolabel->height()-4;
		if(iWdith < 80)	iWdith = 200;
		if(iHeight < 150)	iHeight =480;
		_HisFX3Global_TestStatistics* pstDrawData	=	&(threadshareData.stStatisticsHistory);
		if(hisglobalparameter.ucStatisticsDrawType == 1) pstDrawData	=	&(threadshareData.stStatisticsNow);

		float flOKPercent		=	0.0f;
		if(pstDrawData->uiALL){
			flOKPercent	=	pstDrawData->uiPASS *100.0 /pstDrawData->uiALL;
		}

		unsigned int uiValidUPH	=	0;
		unsigned int uiValidPicCount	=	0;
		for(unsigned int x=0;	x<6;	++x){
			if(threadshareData.ucUPH10m[x] > 3){
				++uiValidUPH;
				uiValidPicCount	+=	threadshareData.ucUPH10m[x];
			}
		}

		unsigned int uiUPH	=	0;
		if(uiValidUPH > 2){
			uiUPH	=	(unsigned int)(uiValidPicCount *6.0 /uiValidUPH +0.5);
		}

		int iHeightItemCount	=	4;
		if(pstDrawData->uiFA)	++iHeightItemCount;
		if(pstDrawData->uiAFCNear)	++iHeightItemCount;
		if(pstDrawData->uiAFCMiddle)	++iHeightItemCount;
		if(pstDrawData->uiAFCFar)	++iHeightItemCount;
		if(pstDrawData->uiOS)	++iHeightItemCount;
		if(pstDrawData->uiWorkCurrent)	++iHeightItemCount;
		if(pstDrawData->uiStandbyCurrent)	++iHeightItemCount;
		if(pstDrawData->uiPreview)	++iHeightItemCount;
		if(pstDrawData->uiBlemish)	++iHeightItemCount;
		if(pstDrawData->uiDefectPixel)	++iHeightItemCount;
		if(pstDrawData->uiOC)	++iHeightItemCount;
		if(pstDrawData->uiShading)	++iHeightItemCount;
		if(pstDrawData->uiVignetting)	++iHeightItemCount;
		if(pstDrawData->uiColor)	++iHeightItemCount;
		if(pstDrawData->uiLine)	++iHeightItemCount;
		if(pstDrawData->uiLightPixel)	++iHeightItemCount;
		if(pstDrawData->uiOTPBurn)	++iHeightItemCount;
		if(pstDrawData->uiOTPBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiAFBurn)	++iHeightItemCount;
		if(pstDrawData->uiAFBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiPDAFBurn)	++iHeightItemCount;
		if(pstDrawData->uiPDAFBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiOther)	++iHeightItemCount;

		int iItemHeight	=	iHeight /iHeightItemCount;
		iItemHeight	=	min(iItemHeight, 20);

		QRect stNameRect, stNumRect;
		stNameRect.setLeft(0);
		stNameRect.setTop(0);
		stNameRect.setWidth(iWdith - 50);
		stNameRect.setHeight(iItemHeight);

		stNumRect.setLeft(stNameRect.width());
		stNumRect.setTop(0);
		stNumRect.setRight(iWdith - 1);
		stNumRect.setHeight(iItemHeight);

		QPixmap backImage(iWdith, iHeight);
		backImage.fill(QColor::fromRgb(240, 240, 240));
		QPainter painer(&backImage);

		QColor colorBlack	=	QColor::fromRgb(0, 0,0);
		QColor colorGreen	=	QColor::fromRgb(0, 255, 0);
		QColor colorRed		=	QColor::fromRgb(255, 0, 0);
		QColor colorYellow	=	QColor::fromRgb(255, 128, 0);
		QPen	thePen	=	painer.pen();
		// 	thePen.setStyle(Qt::DotLine);
		// 	thePen.setWidth(4);
		// 	thePen.setColor(QColor::fromRgb(0,0,0));
		// 	painer.setPen(thePen);

		QFont theFont	=	painer.font();
		theFont.setFamily("Microsoft Tai Le");
		theFont.setPixelSize(15);
		theFont.setBold(true);
		painer.setFont(theFont);

		ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorYellow, QTextCodec::codecForName( "GBK")->toUnicode("良率："), QString::number(flOKPercent, 'f', 1));
		ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorYellow, "UPH:", QString::number(uiUPH));
		ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorBlack, "Total:", QString::number(pstDrawData->uiALL));
		ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorGreen, "OK:", QString::number(pstDrawData->uiPASS));
		
		if(pstDrawData->uiFA) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("调焦："), QString::number(pstDrawData->uiFA));
		if(pstDrawData->uiAFCNear) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("近焦AFC："), QString::number(pstDrawData->uiAFCNear));
		if(pstDrawData->uiAFCMiddle) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("中焦AFC："), QString::number(pstDrawData->uiAFCMiddle));
		if(pstDrawData->uiAFCFar) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("远焦AFC："), QString::number(pstDrawData->uiAFCFar));
		if(pstDrawData->uiOS){ 
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("开短路："), QString::number(pstDrawData->uiOS));
		}
		if(pstDrawData->uiWorkCurrent) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("工作电流："), QString::number(pstDrawData->uiWorkCurrent));
		if(pstDrawData->uiStandbyCurrent) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("待机电流："), QString::number(pstDrawData->uiStandbyCurrent));
		if(pstDrawData->uiPreview) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("出图："), QString::number(pstDrawData->uiPreview));
		if(pstDrawData->uiBlemish) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("污点："), QString::number(pstDrawData->uiBlemish));
		if(pstDrawData->uiDefectPixel) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("坏点："), QString::number(pstDrawData->uiDefectPixel));
		if(pstDrawData->uiOC) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("光学中心："), QString::number(pstDrawData->uiOC));
		if(pstDrawData->uiShading) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Shading:", QString::number(pstDrawData->uiShading));
		if(pstDrawData->uiVignetting) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Vignetting:", QString::number(pstDrawData->uiVignetting));
		if(pstDrawData->uiColor) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Color:", QString::number(pstDrawData->uiColor));
		if(pstDrawData->uiLine) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("线条："), QString::number(pstDrawData->uiLine));
		if(pstDrawData->uiLightPixel) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("亮点："), QString::number(pstDrawData->uiLightPixel));
		if(pstDrawData->uiOTPBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP烧录："), QString::number(pstDrawData->uiOTPBurn));
		if(pstDrawData->uiOTPBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP检测："), QString::number(pstDrawData->uiOTPBurnCheck));
		if(pstDrawData->uiAFBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF烧录："), QString::number(pstDrawData->uiAFBurn));
		if(pstDrawData->uiAFBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF检测："), QString::number(pstDrawData->uiAFBurnCheck));
		if(pstDrawData->uiPDAFBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF烧录："), QString::number(pstDrawData->uiPDAFBurn));
		if(pstDrawData->uiPDAFBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF检测："), QString::number(pstDrawData->uiPDAFBurnCheck));
		if(pstDrawData->uiOther) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("其他："), QString::number(pstDrawData->uiOther));

		ui.statisticsinfolabel->setPixmap(backImage);
	}
	else
	{
		int iWdith = ui.statisticsinfolabel->width()-4;
		int iHeight	=	ui.statisticsinfolabel->height()-4;
		if(iWdith < 150)	iWdith = 480;
		if(iHeight < 80)		iHeight =200;
		_HisFX3Global_TestStatistics* pstDrawData	=	&(threadshareData.stStatisticsHistory);
		if(hisglobalparameter.ucStatisticsDrawType == 1) pstDrawData	=	&(threadshareData.stStatisticsNow);

		float flOKPercent		=	0.0f;
		if(pstDrawData->uiALL){
			flOKPercent	=	pstDrawData->uiPASS *100.0 /pstDrawData->uiALL;
		}

		unsigned int uiValidUPH	=	0;
		unsigned int uiValidPicCount	=	0;
		for(unsigned int x=0;	x<6;	++x){
			if(threadshareData.ucUPH10m[x] > 3){
				++uiValidUPH;
				uiValidPicCount	+=	threadshareData.ucUPH10m[x];
			}
		}

		unsigned int uiUPH	=	0;
		if(uiValidUPH > 2){
			uiUPH	=	(unsigned int)(uiValidPicCount *6.0 /uiValidUPH +0.5);
		}

		int iHeightItemCount	=	4;
		if(pstDrawData->uiFA)	++iHeightItemCount;
		if(pstDrawData->uiAFCNear)	++iHeightItemCount;
		if(pstDrawData->uiAFCMiddle)	++iHeightItemCount;
		if(pstDrawData->uiAFCFar)	++iHeightItemCount;
		if(pstDrawData->uiOS)	++iHeightItemCount;
		if(pstDrawData->uiWorkCurrent)	++iHeightItemCount;
		if(pstDrawData->uiStandbyCurrent)	++iHeightItemCount;
		if(pstDrawData->uiPreview)	++iHeightItemCount;
		if(pstDrawData->uiBlemish)	++iHeightItemCount;
		if(pstDrawData->uiDefectPixel)	++iHeightItemCount;
		if(pstDrawData->uiOC)	++iHeightItemCount;
		if(pstDrawData->uiShading)	++iHeightItemCount;
		if(pstDrawData->uiVignetting)	++iHeightItemCount;
		if(pstDrawData->uiColor)	++iHeightItemCount;
		if(pstDrawData->uiLine)	++iHeightItemCount;
		if(pstDrawData->uiLightPixel)	++iHeightItemCount;
		if(pstDrawData->uiOTPBurn)	++iHeightItemCount;
		if(pstDrawData->uiOTPBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiAFBurn)	++iHeightItemCount;
		if(pstDrawData->uiAFBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiPDAFBurn)	++iHeightItemCount;
		if(pstDrawData->uiPDAFBurnCheck)	++iHeightItemCount;
		if(pstDrawData->uiOther)	++iHeightItemCount;

		if(iHeightItemCount > 8){
			int iItemHeight;
			if(((iHeightItemCount >>1) <<1) == iHeightItemCount) iItemHeight	=	iHeight /(iHeightItemCount >>1);
			else iItemHeight	=	iHeight /((iHeightItemCount >>1) +1);
			iItemHeight	=	min(iItemHeight, 20);
			const int ciGap = 25;

			QRect stNameRect, stNumRect, stNameRectR, stNumRectR;
			stNameRect.setLeft(0);
			stNameRect.setTop(0);
			stNameRect.setWidth(iWdith/2 - 50 -ciGap);
			stNameRect.setHeight(iItemHeight);

			stNameRectR.setLeft(iWdith/2 +ciGap);
			stNameRectR.setTop(0);
			stNameRectR.setWidth(iWdith/2 - 50 -ciGap);
			stNameRectR.setHeight(iItemHeight);

			stNumRect.setLeft(stNameRect.width());
			stNumRect.setTop(0);
			stNumRect.setRight(iWdith/2 - 1 -ciGap);
			stNumRect.setHeight(iItemHeight);

			stNumRectR.setLeft(iWdith/2 + stNameRectR.width() +ciGap);
			stNumRectR.setTop(0);
			stNumRectR.setRight(iWdith - 1);
			stNumRectR.setHeight(iItemHeight);

			QPixmap backImage(iWdith, iHeight);
			backImage.fill(QColor::fromRgb(240, 240, 240));
			QPainter painer(&backImage);

			QColor colorBlack	=	QColor::fromRgb(0, 0,0);
			QColor colorGreen	=	QColor::fromRgb(0, 255, 0);
			QColor colorRed		=	QColor::fromRgb(255, 0, 0);
			QColor colorYellow	=	QColor::fromRgb(255, 128, 0);
			QPen	thePen	=	painer.pen();
			// 	thePen.setStyle(Qt::DotLine);
			// 	thePen.setWidth(4);
			// 	thePen.setColor(QColor::fromRgb(0,0,0));
			// 	painer.setPen(thePen);

			QFont theFont	=	painer.font();
			theFont.setFamily("Microsoft Tai Le");
			theFont.setPixelSize(15);
			theFont.setBold(true);
			painer.setFont(theFont);

			bool bLeft = true;

			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorYellow, QTextCodec::codecForName( "GBK")->toUnicode("良率："), QString::number(flOKPercent, 'f', 1));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorYellow, "UPH:", QString::number(uiUPH));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorBlack, "Total:", QString::number(pstDrawData->uiALL));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorGreen, "OK:", QString::number(pstDrawData->uiPASS));
			if(pstDrawData->uiFA){
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("调焦："), QString::number(pstDrawData->uiFA));
				else ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("调焦："), QString::number(pstDrawData->uiFA));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiAFCNear) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("近焦AFC："), QString::number(pstDrawData->uiAFCNear));
				else ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("近焦AFC："), QString::number(pstDrawData->uiAFCNear));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiAFCMiddle) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("中焦AFC："), QString::number(pstDrawData->uiAFCMiddle));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("中焦AFC："), QString::number(pstDrawData->uiAFCMiddle));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiAFCFar) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("远焦AFC："), QString::number(pstDrawData->uiAFCFar));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("远焦AFC："), QString::number(pstDrawData->uiAFCFar));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiOS) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("开短路："), QString::number(pstDrawData->uiOS));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("开短路："), QString::number(pstDrawData->uiOS));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiWorkCurrent) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("工作电流："), QString::number(pstDrawData->uiWorkCurrent));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("工作电流："), QString::number(pstDrawData->uiWorkCurrent));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiStandbyCurrent) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("待机电流："), QString::number(pstDrawData->uiStandbyCurrent));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("待机电流："), QString::number(pstDrawData->uiStandbyCurrent));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiPreview) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("出图："), QString::number(pstDrawData->uiPreview));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("出图："), QString::number(pstDrawData->uiPreview));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiBlemish) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("污点："), QString::number(pstDrawData->uiBlemish));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("污点："), QString::number(pstDrawData->uiBlemish));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiDefectPixel) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("坏点："), QString::number(pstDrawData->uiDefectPixel));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("坏点："), QString::number(pstDrawData->uiDefectPixel));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiOC) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("光学中心："), QString::number(pstDrawData->uiOC));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("光学中心："), QString::number(pstDrawData->uiOC));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiShading) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Shading:", QString::number(pstDrawData->uiShading));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, "Shading:", QString::number(pstDrawData->uiShading));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiVignetting) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Vignetting:", QString::number(pstDrawData->uiVignetting));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, "Vignetting:", QString::number(pstDrawData->uiVignetting));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiColor) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Color:", QString::number(pstDrawData->uiColor));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, "Color:", QString::number(pstDrawData->uiColor));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiLine) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("线条："), QString::number(pstDrawData->uiLine));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("线条："), QString::number(pstDrawData->uiLine));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiLightPixel) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("亮点："), QString::number(pstDrawData->uiLightPixel));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("亮点："), QString::number(pstDrawData->uiLightPixel));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiOTPBurn) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP烧录："), QString::number(pstDrawData->uiOTPBurn));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP烧录："), QString::number(pstDrawData->uiOTPBurn));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiOTPBurnCheck) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP检测："), QString::number(pstDrawData->uiOTPBurnCheck));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP检测："), QString::number(pstDrawData->uiOTPBurnCheck));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiAFBurn) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF烧录："), QString::number(pstDrawData->uiAFBurn));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF烧录："), QString::number(pstDrawData->uiAFBurn));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiAFBurnCheck){
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF检测："), QString::number(pstDrawData->uiAFBurnCheck));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF检测："), QString::number(pstDrawData->uiAFBurnCheck));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiPDAFBurn) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF烧录："), QString::number(pstDrawData->uiPDAFBurn));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF烧录："), QString::number(pstDrawData->uiPDAFBurn));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiPDAFBurnCheck) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF检测："), QString::number(pstDrawData->uiPDAFBurnCheck));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF检测："), QString::number(pstDrawData->uiPDAFBurnCheck));
				bLeft	=	!bLeft;
			}
			if(pstDrawData->uiOther) {
				if(bLeft)	ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("其他："), QString::number(pstDrawData->uiOther));
				else	ROPLOW::drawStatisticsItem(painer, thePen, stNameRectR, stNumRectR, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("其他："), QString::number(pstDrawData->uiOther));
				bLeft	=	!bLeft;
			}

			ui.statisticsinfolabel->setPixmap(backImage);

		}
		else{
			int iItemHeight	=	iHeight /iHeightItemCount;
			iItemHeight	=	min(iItemHeight, 20);

			QRect stNameRect, stNumRect;
			stNameRect.setLeft(0);
			stNameRect.setTop(0);
			stNameRect.setWidth(iWdith - 50);
			stNameRect.setHeight(iItemHeight);

			stNumRect.setLeft(stNameRect.width());
			stNumRect.setTop(0);
			stNumRect.setRight(iWdith - 1);
			stNumRect.setHeight(iItemHeight);

			QPixmap backImage(iWdith, iHeight);
			backImage.fill(QColor::fromRgb(240, 240, 240));
			QPainter painer(&backImage);

			QColor colorBlack	=	QColor::fromRgb(0, 0,0);
			QColor colorGreen	=	QColor::fromRgb(0, 255, 0);
			QColor colorRed		=	QColor::fromRgb(255, 0, 0);
			QColor colorYellow	=	QColor::fromRgb(255, 128, 0);
			QPen	thePen	=	painer.pen();
			// 	thePen.setStyle(Qt::DotLine);
			// 	thePen.setWidth(4);
			// 	thePen.setColor(QColor::fromRgb(0,0,0));
			// 	painer.setPen(thePen);

			QFont theFont	=	painer.font();
			theFont.setFamily("Microsoft Tai Le");
			theFont.setPixelSize(15);
			theFont.setBold(true);
			painer.setFont(theFont);

			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorYellow, QTextCodec::codecForName( "GBK")->toUnicode("良率："), QString::number(flOKPercent, 'f', 1));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorYellow, "UPH:", QString::number(uiUPH));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorBlack, "Total:", QString::number(pstDrawData->uiALL));
			ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorGreen, "OK:", QString::number(pstDrawData->uiPASS));
			if(pstDrawData->uiFA) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("调焦："), QString::number(pstDrawData->uiFA));
			if(pstDrawData->uiAFCNear) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("近焦AFC："), QString::number(pstDrawData->uiAFCNear));
			if(pstDrawData->uiAFCMiddle) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("中焦AFC："), QString::number(pstDrawData->uiAFCMiddle));
			if(pstDrawData->uiAFCFar) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("远焦AFC："), QString::number(pstDrawData->uiAFCFar));
			if(pstDrawData->uiOS) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("开短路："), QString::number(pstDrawData->uiOS));
			if(pstDrawData->uiWorkCurrent) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("工作电流："), QString::number(pstDrawData->uiWorkCurrent));
			if(pstDrawData->uiStandbyCurrent) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("待机电流："), QString::number(pstDrawData->uiStandbyCurrent));
			if(pstDrawData->uiPreview) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("出图："), QString::number(pstDrawData->uiPreview));
			if(pstDrawData->uiBlemish) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("污点："), QString::number(pstDrawData->uiBlemish));
			if(pstDrawData->uiDefectPixel) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("坏点："), QString::number(pstDrawData->uiDefectPixel));
			if(pstDrawData->uiOC) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("光学中心："), QString::number(pstDrawData->uiOC));
			if(pstDrawData->uiShading) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Shading:", QString::number(pstDrawData->uiShading));
			if(pstDrawData->uiVignetting) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Vignetting:", QString::number(pstDrawData->uiVignetting));
			if(pstDrawData->uiColor) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, "Color:", QString::number(pstDrawData->uiColor));
			if(pstDrawData->uiLine) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("线条："), QString::number(pstDrawData->uiLine));
			if(pstDrawData->uiLightPixel) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("亮点："), QString::number(pstDrawData->uiLightPixel));
			if(pstDrawData->uiOTPBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP烧录："), QString::number(pstDrawData->uiOTPBurn));
			if(pstDrawData->uiOTPBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("OTP检测："), QString::number(pstDrawData->uiOTPBurnCheck));
			if(pstDrawData->uiAFBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF烧录："), QString::number(pstDrawData->uiAFBurn));
			if(pstDrawData->uiAFBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("AF检测："), QString::number(pstDrawData->uiAFBurnCheck));
			if(pstDrawData->uiPDAFBurn) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF烧录："), QString::number(pstDrawData->uiPDAFBurn));
			if(pstDrawData->uiPDAFBurnCheck) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("PDAF检测："), QString::number(pstDrawData->uiPDAFBurnCheck));
			if(pstDrawData->uiOther) ROPLOW::drawStatisticsItem(painer, thePen, stNameRect, stNumRect, iItemHeight, colorBlack, colorRed, QTextCodec::codecForName( "GBK")->toUnicode("其他："), QString::number(pstDrawData->uiOther));

			ui.statisticsinfolabel->setPixmap(backImage);
		}

	}

}

void QHStatisPanel::switchTactisticsShow(unsigned char ucType)
{
	hisglobalparameter.ucStatisticsDrawType	=	ucType;
	drawStatisticsImage();
}

void QHStatisPanel::clearTactisticsData(unsigned char ucType)
{
	if(ucType == 0){ //clear now
		threadshareData.stStatisticsHistory.uiALL	-=	threadshareData.stStatisticsNow.uiALL;
		threadshareData.stStatisticsHistory.uiPASS	-=	threadshareData.stStatisticsNow.uiPASS;
		threadshareData.stStatisticsHistory.uiFA	-=	threadshareData.stStatisticsNow.uiFA;
		threadshareData.stStatisticsHistory.uiAFCNear	-=	threadshareData.stStatisticsNow.uiAFCNear;
		threadshareData.stStatisticsHistory.uiAFCMiddle	-=	threadshareData.stStatisticsNow.uiAFCMiddle;
		threadshareData.stStatisticsHistory.uiAFCFar	-=	threadshareData.stStatisticsNow.uiAFCFar;
		threadshareData.stStatisticsHistory.uiOS	-=	threadshareData.stStatisticsNow.uiOS;
		threadshareData.stStatisticsHistory.uiWorkCurrent	-=	threadshareData.stStatisticsNow.uiWorkCurrent;
		threadshareData.stStatisticsHistory.uiStandbyCurrent	-=	threadshareData.stStatisticsNow.uiStandbyCurrent;
		threadshareData.stStatisticsHistory.uiPreview	-=	threadshareData.stStatisticsNow.uiPreview;
		threadshareData.stStatisticsHistory.uiBlemish	-=	threadshareData.stStatisticsNow.uiBlemish;
		threadshareData.stStatisticsHistory.uiDefectPixel	-=	threadshareData.stStatisticsNow.uiDefectPixel;
		threadshareData.stStatisticsHistory.uiOC	-=	threadshareData.stStatisticsNow.uiOC;
		threadshareData.stStatisticsHistory.uiShading	-=	threadshareData.stStatisticsNow.uiShading;
		threadshareData.stStatisticsHistory.uiVignetting	-=	threadshareData.stStatisticsNow.uiVignetting;
		threadshareData.stStatisticsHistory.uiColor	-=	threadshareData.stStatisticsNow.uiColor;
		threadshareData.stStatisticsHistory.uiLine	-=	threadshareData.stStatisticsNow.uiLine;
		threadshareData.stStatisticsHistory.uiLightPixel	-=	threadshareData.stStatisticsNow.uiLightPixel;
		threadshareData.stStatisticsHistory.uiOTPBurn	-=	threadshareData.stStatisticsNow.uiOTPBurn;
		threadshareData.stStatisticsHistory.uiOTPBurnCheck	-=	threadshareData.stStatisticsNow.uiOTPBurnCheck;
		threadshareData.stStatisticsHistory.uiAFBurn	-=	threadshareData.stStatisticsNow.uiAFBurn;
		threadshareData.stStatisticsHistory.uiAFBurnCheck	-=	threadshareData.stStatisticsNow.uiAFBurnCheck;
		threadshareData.stStatisticsHistory.uiPDAFBurn	-=	threadshareData.stStatisticsNow.uiPDAFBurn;
		threadshareData.stStatisticsHistory.uiPDAFBurnCheck	-=	threadshareData.stStatisticsNow.uiPDAFBurnCheck;
		threadshareData.stStatisticsHistory.uiOther	-=	threadshareData.stStatisticsNow.uiOther;
		threadshareData.stStatisticsNow.clear();
	}
	else if(ucType == 1){ //clear history
		threadshareData.stStatisticsHistory	=	threadshareData.stStatisticsNow;
	}
	else{ //clear all;
		threadshareData.stStatisticsHistory.clear();
		threadshareData.stStatisticsNow.clear();
	}

	ROPLOW::SetStatisticsToDB(threadshareData.stStatisticsHistory, bBoxChannel1);
	drawStatisticsImage();
}

void QHStatisPanel::enableTactistics()
{
	threadshareData.stStatisticsHistory.bEnable = true;
}

void QHStatisPanel::disableTactistics()
{
	threadshareData.stStatisticsHistory.bEnable = false;
}

void QHStatisPanel::tactistics_customMenuRequested(QPoint pos)
{
	QMenu menu(this);

	QAction* showNowAct	=	new QAction(tr("&Show This Time Statistic Data"), this);
	connect(showNowAct, SIGNAL(triggered()), this, SLOT(showNowTactisticsData()));
	menu.addAction(showNowAct);

	QAction* showALLAct	=	new QAction(tr("&Show Total Statistic Data"), this);
	connect(showALLAct, SIGNAL(triggered()), this, SLOT(showHistoryTactisticsData()));
	menu.addAction(showALLAct);

	QAction* clearNowAct	=	new QAction(tr("&Clear This Time Statistic Data"), this);
	connect(clearNowAct, SIGNAL(triggered()), this, SLOT(clearNowTactisticsData()));
	menu.addAction(clearNowAct);

	QAction* clearHistoryAct	=	new QAction(tr("&Clear History Statistic Data"), this);
	connect(clearHistoryAct, SIGNAL(triggered()), this, SLOT(clearHistoryTactisticsData()));
	menu.addAction(clearHistoryAct);

	QAction* clearALLAct	=	new QAction(tr("&Clear Total Statistic Data"), this);
	connect(clearALLAct, SIGNAL(triggered()), this, SLOT(clearALLTactisticsData()));
	menu.addAction(clearALLAct);

	QAction* enableAct	=	new QAction(tr("&Enable Statistics"), this);
	connect(enableAct, SIGNAL(triggered()), this, SLOT(enableTactistics()));
	menu.addAction(enableAct);

	QAction* disableAct	=	new QAction(tr("&Disable Statistics"), this);
	connect(disableAct, SIGNAL(triggered()), this, SLOT(disableTactistics()));
	menu.addAction(disableAct);

	menu.exec(QCursor::pos());
}