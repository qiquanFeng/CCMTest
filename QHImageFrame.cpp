#include "QHImageFrame.h"
#include <QPainter>
#include <QDEBUG>
#include "qoplow.h"

QHImageFrame::QHImageFrame(QWidget *parent, Qt::WindowFlags f)
	: QFrame(parent, f)
{
	setContentsMargins(0,0,0,0);
	iDrawType		=	0xFFFFFF;
	imageSingle	=	0;
}

QHImageFrame::~QHImageFrame()
{
	HisReleaseNewO(imageSingle);
}

void QHImageFrame::paintEvent(QPaintEvent *event)
{
	switch (getDrawType())
	{
	case -100:
		{
			QPainter painter(this);
			bool bImage	=	false;
			RECT stCutROI;
			int iDrawImageOffsetLeft, iDrawImageOffsetTop;
			threadshareData->pixmaplock.lockForRead();
// 			if(threadshareData->pixmaplock.tryLockForRead(100))
// 			{
				if(threadshareData->pucDrawImageRGB24)
				{
					bImage	=	true;
					stCutROI = threadshareData->stDrawImageROI;
					iDrawImageOffsetLeft	=	threadshareData->iDrawImageOffsetLeft;
					iDrawImageOffsetTop	=	threadshareData->iDrawImageOffsetTop;

					QImage image1(threadshareData->pucDrawImageRGB24, threadshareData->iDrawImageWidth, threadshareData->iDrawImageHeight, \
						(threadshareData->iDrawImageWidth <<1) +threadshareData->iDrawImageWidth, QImage::Format_RGB888);
					painter.drawImage(this->rect(), image1, QRect(0,0, threadshareData->iDrawImageWidth, threadshareData->iDrawImageHeight), Qt::ColorOnly);
				}
			
				threadshareData->pixmaplock.unlock();
// 			}

			if(bImage)
			{
				itemshareData->drawLock.lockForRead();
				itemdrawList.assign(itemshareData->itemdrawList.begin(), itemshareData->itemdrawList.end());
				itemshareData->drawLock.unlock();

				LONG lshowW	=	this->width();
				LONG lshowH		=	this->height();
				QPen thePen		=	painter.pen();

				if(itemdrawList.size())
				{
					RECT stblock;					
					QFont	painfont	=	painter.font();
					hisglobalparameter.flagLocker.lockForRead();
					painfont.setBold(hisglobalparameter.stForivate.bImageFontBold);
					painfont.setPointSize(hisglobalparameter.stForivate.ucImageFontSize);
					hisglobalparameter.flagLocker.unlock();			
					painfont.setFamily("arial");				
					painter.setFont(painfont);

					for(std::vector<_itemDraw>::iterator theIterator=itemdrawList.begin(); theIterator != itemdrawList.end(); theIterator++)
					{
						thePen.setColor(theIterator->stcolor);
						thePen.setStyle(Qt::SolidLine);
						painter.setPen(thePen);
						switch (theIterator->uctype)
						{
						case HisDrawType_Block:
							if(ROPLOW::scaleImageShowBlock(theIterator->strinfo.stblock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.drawRect(stblock.left, stblock.top, stblock.right-stblock.left, stblock.bottom-stblock.top);
// 							stblock	=	theIterator->strinfo.stblock;
							break;
						case HisDrawType_Line:
							if(ROPLOW::scaleImageShowBlock(theIterator->strinfo.stblock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.drawLine(stblock.left, stblock.top, stblock.right, stblock.bottom);
							break;
						case HisDrawType_Dashline:
							thePen.setStyle(Qt::DashLine);
							painter.setPen(thePen);
							if(ROPLOW::scaleImageShowBlock(theIterator->strinfo.stblock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.drawLine(stblock.left, stblock.top, stblock.right, stblock.bottom);
							painter.setPen(Qt::SolidLine);
							break;
						case HisDrawType_Text:
							if(ROPLOW::scaleImageShowBlock(theIterator->idata[0], theIterator->idata[1], stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.drawText(stblock.left, stblock.top, QString::fromAscii(theIterator->strinfo.strtext));
							break;
						case HisDrawType_Rectfill:
							if(ROPLOW::scaleImageShowBlock(theIterator->strinfo.stblock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.fillRect(stblock.left, stblock.top, stblock.right-stblock.left, stblock.bottom-stblock.top, theIterator->stcolor);
							break;
						case HisDrawType_Ellipse:
							if(ROPLOW::scaleImageShowBlock(theIterator->strinfo.stblock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
								painter.drawEllipse(stblock.left, stblock.top, stblock.right-stblock.left, stblock.bottom-stblock.top);
							break;
						default:
							break;
						}
					}
				}
				
				if(hisglobalparameter.bPaintCross || hisglobalparameter.bPaintSquare)
				{
					thePen.setColor(QColor::fromRgb(255, 255, 255));
					thePen.setStyle(Qt::SolidLine);
					thePen.setWidth(1);
					painter.setPen(thePen);

					if(hisglobalparameter.bPaintCross)
					{
						painter.drawLine(0, (lshowH >>1),lshowW, (lshowH >>1));
						painter.drawLine((lshowW >>1), 0, (lshowW >>1), lshowH);
					}

					if(hisglobalparameter.bPaintSquare)
					{
						RECT stblock, stSrcBlock;
						stSrcBlock.left			=	((threadshareData->uiWidth - hisglobalparameter.iSquaresizex) >>1);
						stSrcBlock.top			=	((threadshareData->uiHeight - hisglobalparameter.iSquaresizey) >>1);
						stSrcBlock.right		=	stSrcBlock.left + hisglobalparameter.iSquaresizex;
						stSrcBlock.bottom	=	stSrcBlock.top + hisglobalparameter.iSquaresizey;
						if(ROPLOW::scaleImageShowBlock(stSrcBlock, stblock, lshowW, lshowH, stCutROI, iDrawImageOffsetLeft, iDrawImageOffsetTop))
							painter.drawRect(stblock.left, stblock.top, stblock.right-stblock.left, stblock.bottom-stblock.top);
					}
				}
		
			}		

		}
		break;
	case -200:
		{
			if(imageSingle)
			{
				QPainter painter1(this);
				painter1.drawImage(this->rect(), *imageSingle, imageSingle->rect(), Qt::ColorOnly);
			}
			else
			{
				setDrawType(-100);
			}
		}
		break;
	case -10:
		{
			QPainter painter(this);
			painter.fillRect(this->rect(), QColor::fromRgb(240, 240, 240));
		}
		QFrame::paintEvent(event);
		break;
	case 0:
		{
			
			QImage image1(":/Resources/passimage.png", "PNG");
			QPainter painter(this);
			painter.drawImage(this->rect(), image1, image1.rect(), Qt::ColorOnly);
		}
		break;
	case 254:
		{
			QImage image1(":/Resources/passimage_2.png", "PNG");
			QPainter painter(this);
			painter.drawImage(this->rect(), image1, image1.rect(), Qt::ColorOnly);
		}
		break;

	case HisCCMError_Result:
		{
			QImage image1(":/Resources/ngimage.png", "PNG");
			QPainter painter(this);
			painter.drawImage(this->rect(), image1, image1.rect(), Qt::ColorOnly);
		}
		break;
	default:
		QFrame::paintEvent(event);
		break;
	}

	
}

void QHImageFrame::DrawFrame(int itype)
{
	int ret=getDrawType();
	if(ret != -200)
	{
		setDrawType(itype);

		//updateGeometry();
		update(contentsRect());
	}
}

void QHImageFrame::slotDrawAnotherSingle(QImage image1, unsigned int uiTimeOut)
{
	setDrawType(-200);
	HisReleaseNewO(imageSingle);

	imageSingle	=	new QImage();
	if(!imageSingle) { setDrawType(-100); return; }

	*imageSingle	=	image1.copy(image1.rect());

	uiTimeOut = max(10, uiTimeOut);
	if(uiTimeOut != 0xFFFFFFFF)
		QTimer::singleShot(uiTimeOut, this, SLOT(backToNormalMode()));

	update(contentsRect());
}
