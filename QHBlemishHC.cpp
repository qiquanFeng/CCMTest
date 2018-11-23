#include "QHBlemishHC.h"
#include <QListWidgetItem>
#include <QTime>
#include <QSqlDatabase>
#include <QDir>
#include <QStringBuilder>
#include <QSqlQuery>
#include "qoplow.h"

QHBlemishHC::QHBlemishHC(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC)
	: QDockWidget(parent), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC)
{
	ui.setupUi(this);

	pucShow	=	0;
	uiSelectIndex	=	0xFFFFFFFF;
	flStartX = flStartY = flEndX = flEndY = -1.0f;
	bPress	=	false;
	bDrawValid	=	true;

	connect(ui.blemishhcSavepushButton, SIGNAL(released()), this, SLOT(slotSave()));
	connect(ui.blemishhcGetImagepushButton, SIGNAL(released()), this, SLOT(slotGetImage()));
	connect(ui.blemishhcNormalTestpushButton, SIGNAL(released()), this, SLOT(slotNormalTest()));
	connect(ui.blemishhcDebugpushButton, SIGNAL(released()), this, SLOT(slotDebugTest()));
	connect(ui.blemishhcLooppushButton, SIGNAL(released()), this, SLOT(slotLoopBlemish()));
	
}

QHBlemishHC::~QHBlemishHC()
{
	HisReleaseMalloc(pucShow);
}

void QHBlemishHC::mousePressEvent ( QMouseEvent * event )
{
	if(event->button() == Qt::LeftButton && pucShow){
		int ix	=	event->x();
		int iy	=	event->y();
		ix		=	max(ix, 0);
		iy		=	max(iy, 0);
		bool bIsIn	=	false;
		if(ix > ui.blemishhclabel->x() && ix < ui.blemishhclabel->x() + ui.blemishhclabel->size().width() && \
			iy > ui.blemishhclabel->y() && iy < ui.blemishhclabel->y() + ui.blemishhclabel->size().height())
			bIsIn	=	true;

		bPress	=	false;
		flStartX = flStartY = flEndX = flEndY = -1.0f;

		if(bIsIn){
			bPress	=	true;
			flStartX	=	((double)(ix) - ui.blemishhclabel->x()) /ui.blemishhclabel->size().width();
			flStartY	=	((double)(iy) - ui.blemishhclabel->y()) /ui.blemishhclabel->size().height();
			flStartX	=	max(flStartX, 0.0f);
			flStartY	=	max(flStartY, 0.0f);
			flStartX	=	min(flStartX, 1.0f);
			flStartY	=	min(flStartY, 1.0f);
		}
	}

	QDockWidget::mousePressEvent(event);
}

void QHBlemishHC::mouseReleaseEvent ( QMouseEvent * event )
{
	if(event->button() == Qt::LeftButton && bPress && pucShow){
		int ix	=	event->x();
		int iy	=	event->y();
		ix		=	max(ix, 0);
		iy		=	max(iy, 0);
		bool bIsIn	=	false;
		if(ix > ui.blemishhclabel->x() && ix < ui.blemishhclabel->x() + ui.blemishhclabel->size().width() && \
			iy > ui.blemishhclabel->y() && iy < ui.blemishhclabel->y() + ui.blemishhclabel->size().height())
			bIsIn	=	true;

		if(bIsIn){
			bPress	=	false;
			flEndX	=	((double)(ix) - ui.blemishhclabel->x()) /ui.blemishhclabel->size().width();
			flEndY	=	((double)(iy) - ui.blemishhclabel->y()) /ui.blemishhclabel->size().height();
			flEndX	=	max(flEndX, 0.0f);
			flEndY	=	max(flEndY, 0.0f);
			flEndX	=	min(flEndX, 1.0f);
			flEndY	=	min(flEndY, 1.0f);
			drawSelectROI(flEndX, flEndY);
		}
		else{
			bPress	=	false;
			flStartX = flStartY = flEndX = flEndY = -1.0f;
		}
	}

	QDockWidget::mouseReleaseEvent(event);
}

void QHBlemishHC::mouseMoveEvent ( QMouseEvent * event )
{
	if(bPress && pucShow){
		int ix	=	event->x();
		int iy	=	event->y();
		ix		=	max(ix, 0);
		iy		=	max(iy, 0);
		bool bIsIn	=	false;
		if(ix > ui.blemishhclabel->x() && ix < ui.blemishhclabel->x() + ui.blemishhclabel->size().width() && \
			iy > ui.blemishhclabel->y() && iy < ui.blemishhclabel->y() + ui.blemishhclabel->size().height())
			bIsIn	=	true;

		drawLock.lockForWrite();
		bool bValid = bDrawValid;
		drawLock.unlock();

		if(bIsIn && bValid){
			float flNowX	=	((double)(ix) - ui.blemishhclabel->x()) /ui.blemishhclabel->size().width();
			float flNowY	=	((double)(iy) - ui.blemishhclabel->y()) /ui.blemishhclabel->size().height();
			flNowX	=	max(flNowX, 0.0f);
			flNowY	=	max(flNowY, 0.0f);
			flNowX	=	min(flNowX, 1.0f);
			flNowY	=	min(flNowY, 1.0f);
			drawSelectROI(flNowX, flNowY);
		}
	}

	QDockWidget::mouseMoveEvent(event);
}

void QHBlemishHC::keyPressEvent (QKeyEvent * event)
{
	if(event->key() == Qt::Key_Right && vecBlemish.size() > 0 && pucShow){
		if(uiSelectIndex == 0xFFFFFFFF) uiSelectIndex	=	0;
		drawImage();
		if(vecBlemish.at(uiSelectIndex).uiSpecIndex < 10)
			ShowInformation(tr("Brightness: ") % QString::number(vecBlemish.at(uiSelectIndex).flLux, 'f', 6) % tr("    Color:") % \
				QString::number(vecBlemish.at(uiSelectIndex).flColor, 'f', 6) % tr("   Spec Zone:") % QString::number(vecBlemish.at(uiSelectIndex).uiSpecIndex+1));
		else
			ShowInformation(tr("Brightness: ") % QString::number(vecBlemish.at(uiSelectIndex).flLux, 'f', 6) % tr("    Color:") % \
				QString::number(vecBlemish.at(uiSelectIndex).flColor, 'f', 6) % tr("   Spec Zone: Edge"));
		++uiSelectIndex;
		if(uiSelectIndex >= vecBlemish.size()) uiSelectIndex = 0;	
	}

	QDockWidget::keyPressEvent(event);
}

void QHBlemishHC::ShowInformation(QString info)
{
	QListWidgetItem* plistitem	=	new QListWidgetItem(info.prepend((QTime::currentTime()).toString("hh:mm:ss.zzz   ")), ui.blemishhclistWidget);
	if(ui.blemishhclistWidget->count() > 5000){
		plistitem		=	ui.blemishhclistWidget->takeItem(0);
		delete plistitem;
		plistitem	=	0;
	}
	ui.blemishhclistWidget->scrollToBottom();
}

void QHBlemishHC::slotLoopBlemish()
{
	if(vecBlemish.size() > 0 && pucShow){
		if(uiSelectIndex == 0xFFFFFFFF) uiSelectIndex	=	0;
		drawImage();
		if(vecBlemish.at(uiSelectIndex).uiSpecIndex < 10)
			ShowInformation(tr("Brightness: ") % QString::number(vecBlemish.at(uiSelectIndex).flLux, 'f', 6) % tr("    Color:") % \
			QString::number(vecBlemish.at(uiSelectIndex).flColor, 'f', 6) % tr("   Spec Zone:") % QString::number(vecBlemish.at(uiSelectIndex).uiSpecIndex+1));
		else if(vecBlemish.at(uiSelectIndex).uiSpecIndex == 10)
			ShowInformation(tr("Brightness: ") % QString::number(vecBlemish.at(uiSelectIndex).flLux, 'f', 6) % tr("    Color:") % \
			QString::number(vecBlemish.at(uiSelectIndex).flColor, 'f', 6) % tr("   Spec Zone: Edge"));	
		else
			ShowInformation(tr("Brightness: ") % QString::number(vecBlemish.at(uiSelectIndex).flLux, 'f', 6) % tr("    Color:") % \
			QString::number(vecBlemish.at(uiSelectIndex).flColor, 'f', 6) % tr("   Spec Zone: Corner"));	
		++uiSelectIndex;
		if(uiSelectIndex >= vecBlemish.size()) uiSelectIndex = 0;	
	}

}

void QHBlemishHC::slotSave()
{
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return;
		}

		QStringList strname, strvalue;
		QString itemsuffix2, key;
		QSqlQuery query(customdb);

		query.prepare("DELETE FROM " % strTableName %  " WHERE classfy=:classfy AND item=:item AND itemsuffix1=:itemsuffix1");
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "whitepanel");
		query.bindValue(":itemsuffix1", "blemishhc");
		query.exec();

		//(lsc:false)(wb:false)
		strname.clear(); strvalue.clear();
		strname.append("minarea");
		strvalue.append(ui.blemishhcAreaMindoubleSpinBox->cleanText());
		strname.append("maxarea");
		strvalue.append(ui.blemishhcAreaMaxdoubleSpinBox->cleanText());
		strname.append("edgezone");
		strvalue.append(ui.blemishhcEdgeZonedoubleSpinBox->cleanText());
		strname.append("cornerzone");
		strvalue.append(ui.blemishhcCornerZonedoubleSpinBox->cleanText());
		strname.append("tuning");
		strvalue.append(ui.blemishhcTuningdoubleSpinBox->cleanText());
		ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

		strname.clear(); strvalue.clear();
		strname.append("z1b");
		strvalue.append(ui.blemishhcZ1BdoubleSpinBox->cleanText());
		strname.append("z2b");
		strvalue.append(ui.blemishhcZ2BdoubleSpinBox->cleanText());
		strname.append("z3b");
		strvalue.append(ui.blemishhcZ3BdoubleSpinBox->cleanText());
		strname.append("z4b");
		strvalue.append(ui.blemishhcZ4BdoubleSpinBox->cleanText());
		strname.append("z5b");
		strvalue.append(ui.blemishhcZ5BdoubleSpinBox->cleanText());
		strname.append("z6b");
		strvalue.append(ui.blemishhcZ6BdoubleSpinBox->cleanText());
		strname.append("z7b");
		strvalue.append(ui.blemishhcZ7BdoubleSpinBox->cleanText());
		strname.append("z8b");
		strvalue.append(ui.blemishhcZ8BdoubleSpinBox->cleanText());
		strname.append("z9b");
		strvalue.append(ui.blemishhcZ9BdoubleSpinBox->cleanText());
		strname.append("z10b");
		strvalue.append(ui.blemishhcZ10BdoubleSpinBox->cleanText());
		strname.append("zdgeb");
		strvalue.append(ui.blemishhcEdgeBdoubleSpinBox->cleanText());
		strname.append("cornerb");
		strvalue.append(ui.blemishhcCornerBdoubleSpinBox->cleanText());
		ROPLOW::jointconfigstring(key, strname, strvalue);

		query.prepare("INSERT INTO " % strTableName %"(classfy,item,itemsuffix1,itemsuffix2,key,value,reserve) VALUES(:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve)");
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "whitepanel");
		query.bindValue(":itemsuffix1", "blemishhc");
		query.bindValue(":itemsuffix2", itemsuffix2);
		query.bindValue(":key", key);
		query.bindValue(":value", "");
		query.bindValue(":reserve", "");
		query.exec();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
}

void QHBlemishHC::slotGetImage()
{
	//hao
// 	if(!getpreviewflag()){
// 		ShowInformation(tr("The sensor is not previewing"));
// 		return;
// 	}

	HisReleaseMalloc(pucShow);

	uiSelectIndex	=	0xFFFFFFFF;
	flStartX = flStartY = flEndX = flEndY = -1.0f;
	bPress	=	false;

	iWidth	=	itemshareData.previewParameter->iWidth;
	iHeight	=	itemshareData.previewParameter->iHeight;
	ucDataFormat	=	itemshareData.previewParameter->ucDataFormat;

	unsigned char* pucImage	=	(unsigned char*)_aligned_malloc(iWidth *iHeight, _HisCacheLine_Aligned);
	pucShow		=	(unsigned char*)_aligned_malloc(iWidth *iHeight *3, _HisCacheLine_Aligned);
	if(!pucImage || !pucShow){
		ShowInformation(tr("malloc buffer fail"));
		HisReleaseMalloc(pucShow);
		HisReleaseMalloc(pucImage);
		return;
	}

	int iresult = globalFunPointer.GetFreshframe(pucShow, iWidth *iHeight *3, _FrameType_RGB24, true);
	if(iresult){
		ShowInformation(tr("Grab frame fail"));
		HisReleaseMalloc(pucShow);
		HisReleaseMalloc(pucImage);
		return;
	}

	for(unsigned int x=0;	x<iWidth *iHeight; ++x){
		pucImage[x]		=	((int)(pucShow[x*3 + 0] *0.299f +pucShow[x*3 + 1] *0.587f + pucShow[x*3 + 2] *0.114f)) & 0xFF;
	}

	classAlgorithm.contrastenhance(pucImage, iWidth, iHeight);

	for(unsigned int x=0;	x<iWidth *iHeight; ++x){
		pucShow[x*3] =pucShow[x*3+1] =pucShow[x*3+2] =pucImage[x];
	}

	HisReleaseMalloc(pucImage);

	QImage image2(pucShow, iWidth, iHeight, iWidth*3, QImage::Format_RGB888);
	ui.blemishhclabel->setPixmap(QPixmap::fromImage(image2));
}

void QHBlemishHC::slotNormalTest()
{
	//hao
// 	if(!getpreviewflag()){
// 		ShowInformation(tr("The sensor is not previewing"));
// 		return;
// 	}

	if(!pucShow){
		ShowInformation(tr("Please Get Image First"));
		return;
	}

	whitepanel_BlemishHC(false);
}

void QHBlemishHC::drawSelectROI(float flNowX, float flNowY)
{
	if(flNowX < 0.0f || flNowX == flStartX || flNowY == flStartY) return;

	drawLock.lockForWrite();
	bDrawValid	=	false;
	drawLock.unlock();
	
	RECT stROI;
	stROI.left			=	min(flStartX, flNowX) *iWidth;
	stROI.right		=	max(flStartX, flNowX) *iWidth;
	stROI.top			=	min(flStartY, flNowY) *iHeight;
	stROI.bottom	=	max(flStartY, flNowY) *iHeight;

	unsigned char* pucImage	=	(unsigned char*)_aligned_malloc(iWidth *iHeight *3, _HisCacheLine_Aligned);
	memcpy(pucImage, pucShow, iWidth *iHeight *3);
	QImage image2(pucImage, iWidth, iHeight, iWidth*3, QImage::Format_RGB888);

	QPainter painer(&image2);
	QPen thePen		=	painer.pen();
	thePen.setStyle(Qt::SolidLine);
	thePen.setWidth(5);

	thePen.setColor(QColor::fromRgb(0,255,0));
	painer.setPen(thePen);

	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	ui.blemishhclabel->setPixmap(QPixmap::fromImage(image2));
	HisReleaseMalloc(pucImage);

	drawLock.lockForWrite();
	bDrawValid	=	true;
	drawLock.unlock();
}

void QHBlemishHC::drawImage()
{
	unsigned char* pucImage	=	(unsigned char*)_aligned_malloc(iWidth *iHeight *3, _HisCacheLine_Aligned);
	memcpy(pucImage, pucShow, iWidth *iHeight *3);
	QImage image2(pucImage, iWidth, iHeight, iWidth*3, QImage::Format_RGB888);

	QPainter painer(&image2);
	QPen thePen		=	painer.pen();
	thePen.setStyle(Qt::SolidLine);
	thePen.setWidth(5);

	for(unsigned int x=0;	x<vecBlemish.size();	++x){
		QColor stColor = (x==uiSelectIndex)?(QColor::fromRgb(255, 0, 0)):(QColor::fromRgb(255,255,0));
		thePen.setColor(stColor);
		painer.setPen(thePen);
		painer.drawRect(vecBlemish.at(x).stROI.left, vecBlemish.at(x).stROI.top, vecBlemish.at(x).stROI.right-vecBlemish.at(x).stROI.left, \
			vecBlemish.at(x).stROI.bottom-vecBlemish.at(x).stROI.top);
	}

	thePen.setColor(QColor::fromRgb(0,255,0));
	painer.setPen(thePen);
	RECT stROI;
	stROI.left	=	iHeight * ui.blemishhcEdgeZonedoubleSpinBox->value() *0.5;
	stROI.top	=	iHeight * ui.blemishhcEdgeZonedoubleSpinBox->value() *0.5;
	stROI.right	=	iWidth - stROI.left;
	stROI.bottom	=	iHeight - stROI.top;
	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	int iX	=	iWidth *ui.blemishhcCornerZonedoubleSpinBox->value() *0.5;
	int iY	=	iHeight *ui.blemishhcCornerZonedoubleSpinBox->value() *0.5;
	stROI.left			=	0;
	stROI.top			=	0;
	stROI.right		=	stROI.left + iX;
	stROI.bottom	=	stROI.top + iY;
	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	stROI.left			=	iWidth - iX;
	stROI.top			=	0;
	stROI.right		=	iWidth;
	stROI.bottom	=	stROI.top + iY;
	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	stROI.left			=	0;
	stROI.top			=	iHeight-iY;
	stROI.right		=	iX;
	stROI.bottom	=	iHeight;
	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	stROI.left			=	iWidth - iX;
	stROI.top			=	iHeight-iY;
	stROI.right		=	iWidth;
	stROI.bottom	=	iHeight;
	painer.drawRect(stROI.left, stROI.top, stROI.right-stROI.left, stROI.bottom-stROI.top);

	ui.blemishhclabel->setPixmap(QPixmap::fromImage(image2));
	HisReleaseMalloc(pucImage);
}

void QHBlemishHC::slotDebugTest()
{
	//hao
// 	if(!getpreviewflag()){
// 		ShowInformation(tr("The sensor is not previewing"));
// 		return;
// 	}

	if(!pucShow){
		ShowInformation(tr("Please Get Image First"));
		return;
	}

	if(flEndX < 0.0){
		ShowInformation(tr("Please select blemish first with mouse"));
		return;
	}

	whitepanel_BlemishHC(true);
}

int QHBlemishHC::whitepanel_BlemishHC(bool bDebug)
{
	paraFromUI();

	unsigned char* pucRGB24 = (unsigned char*)_aligned_malloc(iWidth *iHeight *3, _HisCacheLine_Aligned);
	unsigned char* pucR	=	(unsigned char*)_aligned_malloc(iWidth *iHeight, _HisCacheLine_Aligned);
	unsigned char* pucG	=	(unsigned char*)_aligned_malloc(iWidth *iHeight, _HisCacheLine_Aligned);
	unsigned char* pucB	=	(unsigned char*)_aligned_malloc(iWidth *iHeight, _HisCacheLine_Aligned);
	int iresult;
	if(!(pucRGB24 && pucR && pucG && pucB)) {
		HisReleaseMalloc(pucRGB24);
		HisReleaseMalloc(pucR);
		HisReleaseMalloc(pucG);
		HisReleaseMalloc(pucB);
		ShowInformation(tr("malloc buffer fail"));
		return HisFX3Error_MallocBuffer;
	}

	_HisFX3_BaylorMode ucDataFormat8;
	ROPLOW::BaylorXForamt2Baloy8(ucDataFormat, ucDataFormat8);

	if(ucDataFormat >= HisYUV8_422_YUYV){
		if(iresult = globalFunPointer.GetFreshframe(pucRGB24,iWidth *iHeight *3, _FrameType_RGB24, true)){
			HisReleaseMalloc(pucRGB24);
			HisReleaseMalloc(pucR);
			HisReleaseMalloc(pucG);
			HisReleaseMalloc(pucB);
			ShowInformation(tr("Grab frame fail"));
			return iresult;
		}
	}
	else{
		if(iresult = globalFunPointer.GetFreshframe(pucR, iWidth *iHeight, _FrameType_Raw | _FrameType_ALL_ADD_ORIGINAL, true)){
			HisReleaseMalloc(pucRGB24);
			HisReleaseMalloc(pucR);
			HisReleaseMalloc(pucG);
			HisReleaseMalloc(pucB);
			ShowInformation(tr("Grab frame fail"));
			return iresult;
		}

		classAlgorithm.HisCCMBarlor2RGB24(pucR, pucRGB24,iWidth, iHeight, ucDataFormat8, threadshareData.ucInterpolation);
	}

	ROPLOW::extractrgb24(pucRGB24, pucR, pucG, pucB,iWidth, iHeight);
	
	vecBlemish.clear();
	std::vector<_HisCCMAlg_BlemishHC_Blemish> vecContainer;
	if(bDebug)
		iresult = classAlgorithm.HisCCMWhitePanel_BlemishHC(pucR, pucG, pucB,iWidth, iHeight, stSpec, \
			vecContainer, cflEdgeSide, cflCornerZone, cflMinArea, cflMaxArea, true, cdflTuning, false, true);
	else
		iresult = classAlgorithm.HisCCMWhitePanel_BlemishHC(pucR, pucG, pucB,iWidth, iHeight, stSpec, \
			vecBlemish, cflEdgeSide, cflCornerZone, cflMinArea, cflMaxArea, false, cdflTuning, false, true);
	
	HisReleaseMalloc(pucRGB24);
	HisReleaseMalloc(pucR);
	HisReleaseMalloc(pucG);
	HisReleaseMalloc(pucB);

	if(iresult){
		ShowInformation(tr("HisCCMWhitePanel_BlemishHC return error: 0x") % QString::number(iresult, 16));
		return 0;
	}

	if(bDebug)
	{
		RECT stROI;
		stROI.left			=	min(flStartX, flEndX) *iWidth;
		stROI.right		=	max(flStartX, flEndX) *iWidth;
		stROI.top			=	min(flStartY, flEndY) *iHeight;
		stROI.bottom	=	max(flStartY, flEndY) *iHeight;

		if(stROI.right - stROI.left > 100){
			stROI.left	-=	100;
			stROI.right += 100;
		}
		else{
			int iData	=	stROI.right - stROI.left;
			stROI.left		-=	iData;
			stROI.right	+=	iData;
		}

		if(stROI.bottom - stROI.top > 100){
			stROI.top	-=	100;
			stROI.bottom += 100;
		}
		else{
			int iData	=	stROI.bottom - stROI.top;
			stROI.top			-=	iData;
			stROI.bottom	+=	iData;
		}

		for(unsigned int x=0;	x<vecContainer.size();	++x){
			if(vecContainer.at(x).flLux < 0.0015) continue;
			int iCenterX	=	(vecContainer.at(x).stROI.left + vecContainer.at(x).stROI.right) /2;
			int iCenterY	=	(vecContainer.at(x).stROI.top + vecContainer.at(x).stROI.bottom) /2;

			if(iCenterX < stROI.left || iCenterX > stROI.right || iCenterY < stROI.top || iCenterY > stROI.bottom) continue;
			vecBlemish.push_back(vecContainer.at(x));
		}
	}

	uiSelectIndex	=	0xFFFFFFFF;
	drawImage();

	return 0;
}

void QHBlemishHC::getConfig(QString strTable)
{
	strTableName	=	strTable;

	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return;
		}

		QStringList strname, strvalue;
		QString strData, strData2;
		QSqlQuery query(customdb);

		query.prepare("SELECT itemsuffix2,key,value,reserve FROM " % strTableName % \
			" WHERE classfy='algorithm' AND item='whitepanel' AND itemsuffix1='blemishhc' ORDER BY id ASC" );
		query.exec();
		//(minarea:0.1)(maxarea:0.1)(edgezone:0.05)(tuning:2.0)(lsc:false)(wb:false)
		//(z1b:0.009)(z2b:0.009)(z3b:0.009)(z4b:0.009)(z5b:0.009)(z6b:0.009)(z7b:0.009)(z8b:0.009)(z9b:0.009)(z10b:0.009)(zdgeb:0.009)
		while (query.next()){
			for(int y=0;	y<4;	++y){
				strData	=	query.value(y).toString();
				ROPLOW::patchconfigstring(strData, strname, strvalue);
				for(int x=0;	x<strname.size();	++x){
					if(strname.at(x) == "minarea") ui.blemishhcAreaMindoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "maxarea") ui.blemishhcAreaMaxdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "edgezone") ui.blemishhcEdgeZonedoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "cornerzone") ui.blemishhcCornerZonedoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "tuning") ui.blemishhcTuningdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z1b") ui.blemishhcZ1BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z2b") ui.blemishhcZ2BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z3b") ui.blemishhcZ3BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z4b") ui.blemishhcZ4BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z5b") ui.blemishhcZ5BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z6b") ui.blemishhcZ6BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z7b") ui.blemishhcZ7BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z8b") ui.blemishhcZ8BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z9b") ui.blemishhcZ9BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "z10b") ui.blemishhcZ10BdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "zdgeb") ui.blemishhcEdgeBdoubleSpinBox->setValue(strvalue.at(x).toFloat());
					else if(strname.at(x) == "cornerb") ui.blemishhcCornerBdoubleSpinBox->setValue(strvalue.at(x).toFloat());
				}
			}
		}

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
}

void QHBlemishHC::paraFromUI()
{
	cflEdgeSide	=	ui.blemishhcEdgeZonedoubleSpinBox->value();
	cflCornerZone	=	ui.blemishhcCornerZonedoubleSpinBox->value();
	cflMinArea	=	ui.blemishhcAreaMindoubleSpinBox->value();
	cflMaxArea	=	ui.blemishhcAreaMaxdoubleSpinBox->value();
	cdflTuning	=	ui.blemishhcTuningdoubleSpinBox->value();
	stSpec[0].flLux	=	ui.blemishhcZ1BdoubleSpinBox->value();
	stSpec[1].flLux	=	ui.blemishhcZ2BdoubleSpinBox->value();
	stSpec[2].flLux	=	ui.blemishhcZ3BdoubleSpinBox->value();
	stSpec[3].flLux	=	ui.blemishhcZ4BdoubleSpinBox->value();
	stSpec[4].flLux	=	ui.blemishhcZ5BdoubleSpinBox->value();
	stSpec[5].flLux	=	ui.blemishhcZ6BdoubleSpinBox->value();
	stSpec[6].flLux	=	ui.blemishhcZ7BdoubleSpinBox->value();
	stSpec[7].flLux	=	ui.blemishhcZ8BdoubleSpinBox->value();
	stSpec[8].flLux	=	ui.blemishhcZ9BdoubleSpinBox->value();
	stSpec[9].flLux	=	ui.blemishhcZ10BdoubleSpinBox->value();
	stSpec[10].flLux	=	ui.blemishhcEdgeBdoubleSpinBox->value();
	stSpec[11].flLux	=	ui.blemishhcCornerBdoubleSpinBox->value();
}