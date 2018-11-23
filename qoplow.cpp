#include "qoplow.h"
#include <QFile>
#include <QTextStream>
#include <QStringBuilder>
#include <QPainter>
#include <QLabel>
#include <stdlib.h>
#include "inc/BlackBeardDll.h"


#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#define PIXEL_G(x,y,w,h) ( ((y)*(w)+(x))*3 +1)
// qoplow::qoplow(void)
// {
// }
// 
// 
// qoplow::~qoplow(void)
// {
// }

bool AFCMTFDataItemSortLittle(_HisCCMAlg_AFC_MTF_DataItem& item1, _HisCCMAlg_AFC_MTF_DataItem& item2)
{
	return item1.sMotorStep < item2.sMotorStep;
}

namespace ROPLOW
{
	int ReadRawBuffer(const wchar_t* pwstrPath, unsigned char* pucData, unsigned int uiDesSize)
	{
		FILE *file = _wfopen(pwstrPath, L"rb");
		if(file == NULL) return HisCCMError_OpenFile;
		size_t sizeread = fread(pucData, sizeof(unsigned char), uiDesSize, file);
		fclose(file);
		return (sizeread != uiDesSize)?(HisCCMError_ReadFile):(0);
	}

	int saveRaw8(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData)
	{
		QString strText	= "[" % QString::number(uiWidth) % "x" % QString::number(uiHeight) % "]";
		switch(uiFormat){
		case HisBaylor8_BGGR:
		case HisBaylor10_BGGR:
		case HisBaylor12_BGGR:
			strdir	=	strdir % "/" % strname % strText % "[BGGR][BIT8].raw";
			break;
		case HisBaylor8_RGGB:
		case HisBaylor10_RGGB:
		case HisBaylor12_RGGB:
			strdir	=	strdir % "/" % strname % strText % "[RGGB][BIT8].raw";
			break;
		case HisBaylor8_GRBG:
		case HisBaylor10_GRBG:
		case HisBaylor12_GRBG:
			strdir	=	strdir % "/" % strname % strText % "[GRBG][BIT8].raw";
			break;
		case HisBaylor8_GBRG:
		case HisBaylor10_GBRG:
		case HisBaylor12_GBRG:
			strdir	=	strdir % "/" % strname % strText % "[GBRG][BIT8].raw";
			break;
		case HisBaylor8_MONO:
		case HisBaylor10_MONO:
		case HisBaylor12_MONO:
			strdir	=	strdir % "/" % strname % strText % "[MONO][BIT8].raw";
			break;
		default:
			break;
		}

		QFile classFile(strdir);
		if(classFile.open(QIODevice::WriteOnly)){
			classFile.resize(0);
			classFile.seek(0);
			if(classFile.write((char*)(pvData), uiWidth*uiHeight) == -1){
				classFile.close();
				return HisCCMError_WriteFile;
			}
			classFile.close();
		}
		else
			return HisCCMError_CreateFile;

		return 0;
	}

	void GetMeanFrom10BitBayer(unsigned short *pRaw,int width,int height,int l,int t,int w,int h,sBayerColorDouble *mean,_HisFX3_BaylorMode ucDataFormat)
	{
		int x,y,xOffset,yOffset;
		long sum[4];
		float meanCh[4];
		int count[4];
		int offset[4];
		int i;
		for(i=0;i<4;i++) 
		{sum[i]=0;count[i]=0;}

		offset[0]=((l+0)&1)|(((t+0)&1)<<1);
		offset[1]=((l+1)&1)|(((t+0)&1)<<1);
		offset[2]=((l+0)&1)|(((t+1)&1)<<1);
		offset[3]=((l+1)&1)|(((t+1)&1)<<1);

		for(y=t;y<(t+h);y+=2)
		{
			yOffset=y*width;
			for(x=l;x<(l+w);x+=2)
			{
				xOffset=yOffset+x;
				sum[offset[0]]+=(long)pRaw[xOffset+0];count[offset[0]]++;
				sum[offset[1]]+=(long)pRaw[xOffset+1];count[offset[1]]++;
			}
			yOffset+=width;
			for(x=l;x<(l+w);x+=2)
			{
				xOffset=yOffset+x;
				sum[offset[2]]+=(long)pRaw[xOffset+0];count[offset[2]]++;
				sum[offset[3]]+=(long)pRaw[xOffset+1];count[offset[3]]++;
			}
		}

		for(i=0;i<4;i++) 
			meanCh[i]=(double)sum[i]/(double)count[i];
		if(ucDataFormat==HisBaylor8_BGGR || ucDataFormat==HisBaylor10_BGGR || ucDataFormat==HisBaylor12_BGGR) {mean->R=meanCh[3];mean->Gr=meanCh[2];mean->Gb=meanCh[1];mean->B=meanCh[0];}
		else if(ucDataFormat==HisBaylor8_RGGB || ucDataFormat==HisBaylor10_RGGB || ucDataFormat==HisBaylor12_RGGB) {mean->R=meanCh[0];mean->Gr=meanCh[1];mean->Gb=meanCh[2];mean->B=meanCh[3];}
		else if(ucDataFormat==HisBaylor8_GBRG || ucDataFormat==HisBaylor10_GBRG || ucDataFormat==HisBaylor12_GBRG) {mean->R=meanCh[2];mean->Gr=meanCh[3];mean->Gb=meanCh[0];mean->B=meanCh[1];}
		else if(ucDataFormat==HisBaylor8_GRBG || ucDataFormat==HisBaylor10_GRBG || ucDataFormat==HisBaylor12_GRBG) {mean->R=meanCh[1];mean->Gr=meanCh[0];mean->Gb=meanCh[3];mean->B=meanCh[2];}
		else if(ucDataFormat==HisBaylor8_MONO || ucDataFormat==HisBaylor10_MONO || ucDataFormat==HisBaylor12_MONO) {mean->R=mean->Gr=mean->Gb=mean->B=meanCh[0];}
	}

	int saveRaw10(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData)
	{
		QString strText	= "[" % QString::number(uiWidth) % "x" % QString::number(uiHeight) % "]";
		switch(uiFormat){
		case HisBaylor8_BGGR:
		case HisBaylor10_BGGR:
		case HisBaylor12_BGGR:
			strdir	=	strdir % "/" % strname % strText % "[BGGR][BIT10].raw";
			break;
		case HisBaylor8_RGGB:
		case HisBaylor10_RGGB:
		case HisBaylor12_RGGB:
			strdir	=	strdir % "/" % strname % strText % "[RGGB][BIT10].raw";
			break;
		case HisBaylor8_GRBG:
		case HisBaylor10_GRBG:
		case HisBaylor12_GRBG:
			strdir	=	strdir % "/" % strname % strText % "[GRBG][BIT10].raw";
			break;
		case HisBaylor8_GBRG:
		case HisBaylor10_GBRG:
		case HisBaylor12_GBRG:
			strdir	=	strdir % "/" % strname % strText % "[GBRG][BIT10].raw";
			break;
		case HisBaylor8_MONO:
		case HisBaylor10_MONO:
		case HisBaylor12_MONO:
			strdir	=	strdir % "/" % strname % strText % "[MONO][BIT10].raw";
			break;
		default:
			return HisFX3Error_Parameter;
			break;
		}

		QFile classFile(strdir);
		if(classFile.open(QIODevice::WriteOnly)){
			classFile.resize(0);
			classFile.seek(0);
			if(classFile.write((char*)(pvData), uiWidth*uiHeight*2) == -1){
				classFile.close();
				return HisCCMError_WriteFile;
			}
			classFile.close();
		}
		else
			return HisCCMError_CreateFile;

		return 0;
	}

	int saveRaw12(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData)
	{
		QString strText	= "[" % QString::number(uiWidth) % "x" % QString::number(uiHeight) % "]";
		switch(uiFormat){
		case HisBaylor8_BGGR:
		case HisBaylor10_BGGR:
		case HisBaylor12_BGGR:
			strdir	=	strdir % "/" % strname % strText % "[BGGR][BIT12].raw";
			break;
		case HisBaylor8_RGGB:
		case HisBaylor10_RGGB:
		case HisBaylor12_RGGB:
			strdir	=	strdir % "/" % strname % strText % "[RGGB][BIT12].raw";
			break;
		case HisBaylor8_GRBG:
		case HisBaylor10_GRBG:
		case HisBaylor12_GRBG:
			strdir	=	strdir % "/" % strname % strText % "[GRBG][BIT12].raw";
			break;
		case HisBaylor8_GBRG:
		case HisBaylor10_GBRG:
		case HisBaylor12_GBRG:
			strdir	=	strdir % "/" % strname % strText % "[GBRG][BIT12].raw";
			break;
		case HisBaylor8_MONO:
		case HisBaylor10_MONO:
		case HisBaylor12_MONO:
			strdir	=	strdir % "/" % strname % strText % "[MONO][BIT12].raw";
			break;
		default:
			return HisFX3Error_Parameter;
			break;
		}

		QFile classFile(strdir);
		if(classFile.open(QIODevice::WriteOnly)){
			classFile.resize(0);
			classFile.seek(0);
			if(classFile.write((char*)(pvData), uiWidth*uiHeight*2) == -1){
				classFile.close();
				return HisCCMError_WriteFile;
			}
			classFile.close();
		}
		else
			return HisCCMError_CreateFile;

		return 0;
	}



	float getSFRValueofFreq(double* pdflSFRValue, int iSFRCurveLen, unsigned char ucFreq)
	{
		unsigned int uiLowIndex	=	(iSFRCurveLen - 1) /ucFreq;
		double dflLowValue			=	*(pdflSFRValue + uiLowIndex);
		double dflHighValue			=	*(pdflSFRValue + (uiLowIndex+1));
		double dflRatio				=	static_cast<double>(iSFRCurveLen - 1) /static_cast<double>(ucFreq) - static_cast<double>(uiLowIndex);
		return static_cast<float>(dflLowValue - (dflLowValue-dflHighValue)*dflRatio);
	}

	void DawSFRFACABar(int iGroupCount, QImage& imageBackgound, bool b2Freq, float* pflF1Value, float* pflF2Value, float* pflF1Spec, \
		float* pflF2Spec, float flWeight, float flMaxWeight, bool bTotalResult)
	{
		imageBackgound.load(":/Resources/bar_backgound.png", "PNG");
		QImage imageGreen(":/Resources/bar_green.png", "PNG");
		QImage imageRed(":/Resources/bar_red.png", "PNG");
		QImage imageBlue(":/Resources/bar_blue.png", "PNG");

		const int ciTotalWidth			=	imageBackgound.width();
		const int ciInitBarWidth		=	imageGreen.width();
		const int ciIntiBarHeight		=	imageGreen.height();
		const int ciBackBottom		=	40;
		const int ciBackTop				=	40;
		const int ciTextRectHeight		=	20;

		int iBlockCount		=	(iGroupCount <<2) + 1;
		int iBarWidth;
		if(b2Freq)
			iBarWidth			=	ciTotalWidth / ((iBlockCount<<1) + (iGroupCount<<1) +(iGroupCount<<1) +3);
		else
			iBarWidth			=	ciTotalWidth / (iBlockCount + iGroupCount +((iGroupCount+1)>>1) +1);
		iBarWidth				=	min(iBarWidth, ciInitBarWidth);

		if(iBarWidth != ciInitBarWidth){
			imageGreen	=	imageGreen.scaled(iBarWidth, ciIntiBarHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
			imageRed		=	imageRed.scaled(iBarWidth, ciIntiBarHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
			imageBlue		=	imageBlue.scaled(iBarWidth, ciIntiBarHeight, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		}

		QPainter painer(&imageBackgound);
		QPen	thePen	=	painer.pen();
		thePen.setStyle(Qt::DotLine);
		thePen.setWidth(4);

		QFont theFont	=	painer.font();
		theFont.setFamily("arial");

		//draw bar chart
		thePen.setColor(QColor::fromRgb(0,0,0));
		painer.setPen(thePen);

		theFont.setPixelSize(iBarWidth /2);
		theFont.setBold(false);
		painer.setFont(theFont);

		QRect rectImage;
		QRect rectText;
		QLine lineSpec;
		QRect rectSpec;
		QImage* ptheImage;
		QString strText;
		float flMax, flMin, flMaxU, flMinU;
		unsigned int uiIndex;
		int w;

		rectImage.setLeft(0);
		rectImage.setTop(ciBackTop);
		rectImage.setBottom(imageBackgound.height() - ciBackBottom);
		rectImage.setRight(rectImage.left() + iBarWidth -1);

		rectText.setLeft(0);
		rectText.setTop(ciBackTop);
		rectText.setWidth(iBarWidth);
		rectText.setHeight(ciTextRectHeight);

		for(unsigned int y=0;	y<iGroupCount;	++y){
			flMaxU	=	0.0f;
			flMinU	=	2.0f;
			for(unsigned int x=0;	x<4;	++x){
				uiIndex	=	y *16 +x*4;
				flMax	=	maxv4(pflF1Value[uiIndex], pflF1Value[uiIndex+1], pflF1Value[uiIndex+2], pflF1Value[uiIndex+3]);
				flMin		=	minv4(pflF1Value[uiIndex], pflF1Value[uiIndex+1], pflF1Value[uiIndex+2], pflF1Value[uiIndex+3]);
				flMaxU	=	max(flMaxU, flMax);
				flMinU	=	min(flMinU, flMin);
				
				ptheImage	=	(flMin < pflF1Spec[y*2])?(&imageRed):(&imageGreen);
				w	=	static_cast<int>((1.0f - flMin) *static_cast<float>(ciIntiBarHeight));
				rectImage.setTop(w + ciBackTop);
				painer.drawImage(rectImage,  *ptheImage);

				rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
				strText	=	QString::number(flMin, 'f', 2);
				painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

				w	=	static_cast<int>((1.0f - pflF1Spec[y*2]) *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
				lineSpec.setLine(rectImage.left(), w, rectImage.right(), w);

				painer.drawLine(lineSpec);
				rectImage.moveLeft(rectImage.left() + iBarWidth);
			}

			flMax	=	flMaxU	-	flMinU;
			ptheImage	=	(flMax > pflF1Spec[y*2+1])?(&imageRed):(&imageGreen);

			flMin	=	1.0f - flMax;
			w	=	static_cast<int>((1.0f - flMin) *static_cast<float>(ciIntiBarHeight));
			rectImage.setTop(w + ciBackTop);

			painer.drawImage(rectImage,  *ptheImage);

			rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
			strText	=	QString::number(flMax, 'f', 2);
			painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

			w	=	static_cast<int>(pflF1Spec[y*2+1] *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
			lineSpec.setLine(rectImage.left(), w, rectImage.right(), w);
			painer.drawLine(lineSpec);

			rectImage.moveLeft(rectImage.left() + iBarWidth + (iBarWidth>>1));
		}

		//draw center value
		uiIndex	=	iGroupCount *16;
		flMax	=	maxv4(pflF1Value[uiIndex], pflF1Value[uiIndex+1], pflF1Value[uiIndex+2], pflF1Value[uiIndex+3]);
		flMin		=	minv4(pflF1Value[uiIndex], pflF1Value[uiIndex+1], pflF1Value[uiIndex+2], pflF1Value[uiIndex+3]);
		ptheImage	=	(flMin < pflF1Spec[iGroupCount *2])?(&imageRed):(&imageGreen);
		w	=	static_cast<int>((1.0f - flMin) *static_cast<float>(ciIntiBarHeight));
		rectImage.setTop(w + ciBackTop);
		painer.drawImage(rectImage,  *ptheImage);

		rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
		strText	=	QString::number(flMin, 'f', 2);
		painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

		w	=	static_cast<int>((1.0f - pflF1Spec[iGroupCount *2]) *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
		lineSpec.setLine(rectImage.left(), w, rectImage.right(), w);
		painer.drawLine(lineSpec);
		rectImage.moveLeft(rectImage.left() + iBarWidth);

		//draw weight value
		if(flMaxWeight > flWeight){
			w	=	static_cast<int>((1.0f - flMaxWeight) *static_cast<float>(ciIntiBarHeight));
			rectImage.setTop(w + ciBackTop);
			painer.drawImage(rectImage,  imageBlue);
		}

		ptheImage	=	(!bTotalResult)?(&imageRed):(&imageGreen);
		w	=	static_cast<int>((1.0f - flWeight) *static_cast<float>(ciIntiBarHeight));
		rectImage.setTop(w + ciBackTop);
		painer.drawImage(rectImage,  *ptheImage);

		rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
		strText	=	QString::number(flWeight, 'f', 2);
		painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

		if(b2Freq){

		}

		//draw spec text
// 		rectText.setLeft(0);
// 		rectText.setTop(imageBackgound.height() - ciBackBottom);
// 		rectText.setWidth(iBarWidth*5);
// 		rectText.setHeight(ciBackBottom);
// 
// 		rectImage	=	rectText;
// 		rectImage.moveBottom(imageBackgound.height()-1);
// 
// 		thePen.setColor(QColor::fromRgb(255,128, 0));
// 		painer.setPen(thePen);
// 
// 		theFont.setPixelSize(iBarWidth *3 /4);
// 		theFont.setBold(true);
// 		painer.setFont(theFont);
// 
// 		for(int i=0;	i<iGroupCount;	++i){
// 			strText	=	QString::number(itemshareData.mtffaParameter->stcircleinfo.at(i).flspecvalue, 'f', 3) % \
// 				" | " %  QString::number(itemshareData.mtffaParameter->stcircleinfo.at(i).flspecunifom, 'f', 3);
// 
// 			painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);
// 
// 			rectText.moveLeft(rectText.left() + iBarWidth *6);
// 		}
// 
// 		rectText.setWidth(iBarWidth);
// 		strText	=	QString::number(itemshareData.mtffaParameter->flcenterspecvalue, 'f', 2);
// 		painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);
	}

	void BaylorXForamt2Baloy8(_HisFX3_BaylorMode& before, _HisFX3_BaylorMode& after)
	{
		switch (before){
		case HisBaylor12_BGGR:
		case HisBaylor10_BGGR: after = HisBaylor8_BGGR;	break;
		case HisBaylor12_RGGB:
		case HisBaylor10_RGGB: after = HisBaylor8_RGGB;	break;
		case HisBaylor12_GRBG:
		case HisBaylor10_GRBG: after = HisBaylor8_GRBG;	break;
		case HisBaylor12_GBRG:
		case HisBaylor10_GBRG: after = HisBaylor8_GBRG;	break;
		case HisBaylor12_MONO:
		case HisBaylor10_MONO: after = HisBaylor8_MONO;	break;
		default: after = before; break;
		}
	}

	void FastResize2(unsigned char* pucBefore, unsigned char* pucAfter, unsigned int uiWidth, unsigned int uiHeight)
	{
		for(unsigned int y=0;	y<uiHeight;	y+=2){
			for(unsigned int x=0;	x<uiWidth;	x+=2){
				*pucAfter	=	*pucBefore;
				++pucAfter;
				pucBefore	+=	2;
			}
			pucBefore	+=	uiWidth;
		}
	}

	void AFALpItemDataInitial(std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItemData, std::vector<_HisCCMAlg_LPItem_Info>& vectorItemInfo, double& dflAbsAngle)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		vectorItemData.at(uiIndex).dflAbsAngle			=	dflAbsAngle;
		vectorItemData.at(uiIndex).flWeightValue		=	0.0f;
		vectorItemData.at(uiIndex).ucStatus				=	0x0;
		vectorItemData.at(uiIndex).uiMarkDistance	=	0;

		unsigned int uiFOVSize	=	vectorItemInfo.size();
		vectorItemData.at(uiIndex).vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			vectorItemData.at(uiIndex).vectorFOV.at(x).flFOV		=	vectorItemInfo.at(x).flFOV;
			vectorItemData.at(uiIndex).vectorFOV.at(x).flAngle	=	vectorItemInfo.at(x).flAngle;
			vectorItemData.at(uiIndex).vectorFOV.at(x).flSpecHor	=	vectorItemInfo.at(x).flSpecHor;
			vectorItemData.at(uiIndex).vectorFOV.at(x).flSpecVec	=	vectorItemInfo.at(x).flSpecVec;
			vectorItemData.at(uiIndex).vectorFOV.at(x).flSpecUniform	=	vectorItemInfo.at(x).flSpecUniform;
			vectorItemData.at(uiIndex).vectorFOV.at(x).flWeight		=	vectorItemInfo.at(x).flWeight;
			vectorItemData.at(uiIndex).vectorFOV.at(x).ucStatus	=	0x0;
			memset(vectorItemData.at(uiIndex).vectorFOV.at(x).stLpValue, 0, sizeof(_HisCCMAlg_Resolution) *4);
		}
	}

	void AFAItemDataAdd(std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItemData, RECT& stROI, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex)
	{
		std::vector<_HisCCMAlg_AFA_LP_DataItem>::iterator theiterator = vectorItemData.end() - 1;
		std::vector<_HisCCMAlg_AFA_LP_DataItem_FOV>::iterator foviterator = theiterator->vectorFOV.begin() + uiFOVIndex;

		if(stROI.right - stROI.left > stROI.bottom - stROI.top){
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	1;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}
		else{
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	0;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}

		if(uiROIIndex == 3){
			float flmax	=	maxv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			float flmin		=	minv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			foviterator->flUniformValue	=	flmax - flmin;
		}
	}

	void AFCLpItemDataInitial(std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItemData, std::vector<_HisCCMAlg_LPItem_Info>& vectorItemInfo, int& iMotor)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		std::vector<_HisCCMAlg_AFC_LP_DataItem>::iterator theiterator = vectorItemData.begin() + uiIndex;
		theiterator->sMotorStep			=	iMotor;
		theiterator->flWeightValue		=	0.0f;
		theiterator->ucStatus				=	0x0;
		theiterator->dflMarkDistance	=	0.0;
		theiterator->ucFlag					=	0x0;

		unsigned int uiFOVSize	=	vectorItemInfo.size();
		theiterator->vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			theiterator->vectorFOV.at(x).flFOV		=	vectorItemInfo.at(x).flFOV;
			theiterator->vectorFOV.at(x).flAngle	=	vectorItemInfo.at(x).flAngle;
			theiterator->vectorFOV.at(x).flSpecHor	=	vectorItemInfo.at(x).flSpecHor;
			theiterator->vectorFOV.at(x).flSpecVec	=	vectorItemInfo.at(x).flSpecVec;
			theiterator->vectorFOV.at(x).flSpecUniform	=	vectorItemInfo.at(x).flSpecUniform;
			theiterator->vectorFOV.at(x).flWeight		=	vectorItemInfo.at(x).flWeight;
			theiterator->vectorFOV.at(x).ucStatus	=	0x0;
			memset(theiterator->vectorFOV.at(x).stLpValue, 0, sizeof(_HisCCMAlg_Resolution) *4);
			memset(theiterator->vectorFOV.at(x).stValueLine, 0, sizeof(RECT) *4);
			memset(theiterator->vectorFOV.at(x).stMinLine, 0, sizeof(RECT) *4);
			memset(theiterator->vectorFOV.at(x).stMaxLine, 0, sizeof(RECT) *4);
			memset(theiterator->vectorFOV.at(x).stBlock, 0, sizeof(RECT) *4);
		}
	}

	void AFCItemDataAdd(std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItemData, RECT& stROI,  RECT& stValueLine,  \
		RECT& stMaxLine,  RECT& stMinLine, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex)
	{
		std::vector<_HisCCMAlg_AFC_LP_DataItem>::iterator theiterator = vectorItemData.end() - 1;
		std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV>::iterator foviterator = theiterator->vectorFOV.begin() + uiFOVIndex;

		if(stROI.right - stROI.left > stROI.bottom - stROI.top){
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	1;
			foviterator->stLpValue[uiROIIndex].flValue				+=	dflValue;
		}
		else{
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	0;
			foviterator->stLpValue[uiROIIndex].flValue				+=	dflValue;
		}

		foviterator->stBlock[uiROIIndex].left		+=	stROI.left;
		foviterator->stBlock[uiROIIndex].right		+=	stROI.right;
		foviterator->stBlock[uiROIIndex].top		+=	stROI.top;
		foviterator->stBlock[uiROIIndex].bottom	+=	stROI.bottom;

		foviterator->stValueLine[uiROIIndex].left			+=	stValueLine.left;
		foviterator->stValueLine[uiROIIndex].right		+=	stValueLine.right;
		foviterator->stValueLine[uiROIIndex].top			+=	stValueLine.top;
		foviterator->stValueLine[uiROIIndex].bottom	+=	stValueLine.bottom;

		foviterator->stMinLine[uiROIIndex].left		+=	stMinLine.left;
		foviterator->stMinLine[uiROIIndex].right		+=	stMinLine.right;
		foviterator->stMinLine[uiROIIndex].top		+=	stMinLine.top;
		foviterator->stMinLine[uiROIIndex].bottom	+=	stMinLine.bottom;

		foviterator->stMaxLine[uiROIIndex].left		+=	stMaxLine.left;
		foviterator->stMaxLine[uiROIIndex].right		+=	stMaxLine.right;
		foviterator->stMaxLine[uiROIIndex].top		+=	stMaxLine.top;
		foviterator->stMaxLine[uiROIIndex].bottom	+=	stMaxLine.bottom;

/*
		foviterator->stBlock[uiROIIndex]	=	stROI;
		foviterator->stValueLine[uiROIIndex]	=	stValueLine;
		foviterator->stMinLine[uiROIIndex]	=	stMinLine;
		foviterator->stMaxLine[uiROIIndex]	=	stMaxLine;

		if(uiROIIndex == 3){
			float flmax	=	maxv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			float flmin		=	minv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			foviterator->flUniformValue	=	flmax - flmin;
		}
*/
	}

	void AFCItemDataAdd(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, RECT& stROI,  RECT& stValueLine,  \
		RECT& stMaxLine,  RECT& stMinLine, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex)
	{
		std::vector<_HisAutoFA_Rolongo_DataItem>::iterator theiterator = vectorItemData.end() - 1;
		std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV>::iterator foviterator = theiterator->vectorLPFOV.begin() + uiFOVIndex;

		if(stROI.right - stROI.left > stROI.bottom - stROI.top){
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	1;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}
		else{
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	0;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}

		foviterator->stBlock[uiROIIndex]	=	stROI;
		foviterator->stValueLine[uiROIIndex]	=	stValueLine;
		foviterator->stMinLine[uiROIIndex]	=	stMinLine;
		foviterator->stMaxLine[uiROIIndex]	=	stMaxLine;

		if(uiROIIndex == 3){
			float flmax	=	maxv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			float flmin		=	minv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			foviterator->flUniformValue	=	flmax - flmin;
		}
	}

	void AFCSFRHAItemDataInitial(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorItemData, _SFRAFCCAParameter* pstParameter, int& iMotor)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>::iterator theiterator = vectorItemData.begin() + uiIndex;
		theiterator->sMotorStep			=	iMotor;
		theiterator->flWeightValue		=	0.0f;
		theiterator->ucStatus				=	0x0;
		theiterator->dflMarkDistance	=	0.0;
		theiterator->ucFlag					=	0x0;
		theiterator->flCenterWeight	=	pstParameter->stSFRBasic.flCenterWeight;
		theiterator->b2ndFreq				=	pstParameter->stSFRBasic.b2ndFreq;
		theiterator->ucMethod				=	pstParameter->stSFRBasic.ucMethod;
		theiterator->flCenterMTF50SpecH				=	pstParameter->stSFRBasic.flCenterMTF50SpecH;
		theiterator->flCenterMTF50SpecV				=	pstParameter->stSFRBasic.flCenterMTF50SpecV;
		theiterator->flCenter1stFreqSpecH			=	pstParameter->stSFRBasic.flCenter1stFreqSpecH;
		theiterator->flCenter1stFreqSpecV				=	pstParameter->stSFRBasic.flCenter1stFreqSpecV;
		theiterator->flCenter2ndFreqSpecH			=	pstParameter->stSFRBasic.flCenter2ndFreqSpecH;
		theiterator->flCenter2ndFreqSpecV			=	pstParameter->stSFRBasic.flCenter2ndFreqSpecV;

		memset(&(theiterator->stSFRCenterMTF50), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(theiterator->stSFRCenterFreq1), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(theiterator->stSFRCenterFreq2), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(theiterator->stCenterBlock), 0, sizeof(_SFRBlackROI4));

		unsigned int uiFOVSize	=	pstParameter->vectorSFRItem.size();
		theiterator->vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			theiterator->vectorFOV.at(x).ucStatus	=	0x0;
			theiterator->vectorFOV.at(x).flMTF50UnifH	=	0.0f;
			theiterator->vectorFOV.at(x).flMTF50UnifV	=	0.0f;
			theiterator->vectorFOV.at(x).flFreq1UnifH	=	0.0f;
			theiterator->vectorFOV.at(x).flFreq1UnifV	=	0.0f;
			theiterator->vectorFOV.at(x).flFreq2UnifH	=	0.0f;
			theiterator->vectorFOV.at(x).flFreq2UnifV	=	0.0f;

			theiterator->vectorFOV.at(x).flFOV		=	pstParameter->vectorSFRItem.at(x).flFOV;
			theiterator->vectorFOV.at(x).flAngle		=	pstParameter->vectorSFRItem.at(x).flAngle;
			theiterator->vectorFOV.at(x).flWeight		=	pstParameter->vectorSFRItem.at(x).flWeight;
			theiterator->vectorFOV.at(x).flMTF50SpecH		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecH;
			theiterator->vectorFOV.at(x).flMTF50SpecV		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecV;
			theiterator->vectorFOV.at(x).fl1stFreqSpecH		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecH;
			theiterator->vectorFOV.at(x).fl1stFreqSpecV		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecV;
			theiterator->vectorFOV.at(x).fl2ndFreqSpecH		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecH;
			theiterator->vectorFOV.at(x).fl2ndFreqSpecV		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecV;
			theiterator->vectorFOV.at(x).flMTF50SpecUnifH		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecUnifH;
			theiterator->vectorFOV.at(x).flMTF50SpecUnifV		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecUnifV;
			theiterator->vectorFOV.at(x).fl1stFreqSpecUnifH		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifH;
			theiterator->vectorFOV.at(x).fl1stFreqSpecUnifV		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifV;
			theiterator->vectorFOV.at(x).fl2ndFreqSpecUnifH		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifH;
			theiterator->vectorFOV.at(x).fl2ndFreqSpecUnifV		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifV;
			memset(theiterator->vectorFOV.at(x).stSFRMTF50, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(theiterator->vectorFOV.at(x).stSFRFreq1, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(theiterator->vectorFOV.at(x).stSFRFreq2, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(theiterator->vectorFOV.at(x).stBlock, 0, sizeof(_SFRBlackROI4) *4);
		}
	}

	void MFASFRHAItemDataInitial(_HisCCMAlg_AFC_SFRHA_DataItem& stItemData, _SFRFACAParameter* pstParameter)
	{
		stItemData.flWeightValue		=	0.0f;
		stItemData.flCenterWeight	=	0.0f;
		stItemData.ucStatus				=	0x0;
		stItemData.dflMarkDistance	=	0.0;
		stItemData.ucFlag					=	0x0;
		stItemData.b2ndFreq				=	pstParameter->stSFRBasic.b2ndFreq;
		stItemData.ucMethod				=	pstParameter->stSFRBasic.ucMethod;
		stItemData.flCenterMTF50SpecH				=	pstParameter->stSFRBasic.flCenterMTF50SpecH;
		stItemData.flCenterMTF50SpecV				=	pstParameter->stSFRBasic.flCenterMTF50SpecV;
		stItemData.flCenter1stFreqSpecH			=	pstParameter->stSFRBasic.flCenter1stFreqSpecH;
		stItemData.flCenter1stFreqSpecV				=	pstParameter->stSFRBasic.flCenter1stFreqSpecV;
		stItemData.flCenter2ndFreqSpecH			=	pstParameter->stSFRBasic.flCenter2ndFreqSpecH;
		stItemData.flCenter2ndFreqSpecV			=	pstParameter->stSFRBasic.flCenter2ndFreqSpecV;

		memset(&(stItemData.stSFRCenterMTF50), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(stItemData.stSFRCenterFreq1), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(stItemData.stSFRCenterFreq2), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
		memset(&(stItemData.stCenterBlock), 0, sizeof(_SFRBlackROI4));

		unsigned int uiFOVSize	=	pstParameter->vectorSFRItem.size();
		stItemData.vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			stItemData.vectorFOV.at(x).ucStatus	=	0x0;
			stItemData.vectorFOV.at(x).flMTF50UnifH	=	0.0f;
			stItemData.vectorFOV.at(x).flMTF50UnifV	=	0.0f;
			stItemData.vectorFOV.at(x).flFreq1UnifH	=	0.0f;
			stItemData.vectorFOV.at(x).flFreq1UnifV	=	0.0f;
			stItemData.vectorFOV.at(x).flFreq2UnifH	=	0.0f;
			stItemData.vectorFOV.at(x).flFreq2UnifV	=	0.0f;

			stItemData.vectorFOV.at(x).flFOV		=	pstParameter->vectorSFRItem.at(x).flFOV;
			stItemData.vectorFOV.at(x).flAngle		=	pstParameter->vectorSFRItem.at(x).flAngle;
			stItemData.vectorFOV.at(x).flWeight		=	pstParameter->vectorSFRItem.at(x).flWeight;
			stItemData.vectorFOV.at(x).flMTF50SpecH		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecH;
			stItemData.vectorFOV.at(x).flMTF50SpecV		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecV;
			stItemData.vectorFOV.at(x).fl1stFreqSpecH		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecH;
			stItemData.vectorFOV.at(x).fl1stFreqSpecV		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecV;
			stItemData.vectorFOV.at(x).fl2ndFreqSpecH		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecH;
			stItemData.vectorFOV.at(x).fl2ndFreqSpecV		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecV;
			stItemData.vectorFOV.at(x).flMTF50SpecUnifH		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecUnifH;
			stItemData.vectorFOV.at(x).flMTF50SpecUnifV		=	pstParameter->vectorSFRItem.at(x).flMTF50SpecUnifV;
			stItemData.vectorFOV.at(x).fl1stFreqSpecUnifH		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifH;
			stItemData.vectorFOV.at(x).fl1stFreqSpecUnifV		=	pstParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifV;
			stItemData.vectorFOV.at(x).fl2ndFreqSpecUnifH		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifH;
			stItemData.vectorFOV.at(x).fl2ndFreqSpecUnifV		=	pstParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifV;
			memset(stItemData.vectorFOV.at(x).stSFRMTF50, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(stItemData.vectorFOV.at(x).stSFRFreq1, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(stItemData.vectorFOV.at(x).stSFRFreq2, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
			memset(stItemData.vectorFOV.at(x).stBlock, 0, sizeof(_SFRBlackROI4) *4);
		}
	}

	void AFCMTFItemDataInitial(std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorItemData, _mtfAFCParameter* pstParameter, int& iMotor)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		std::vector<_HisCCMAlg_AFC_MTF_DataItem>::iterator theiterator = vectorItemData.begin() + uiIndex;
		theiterator->sMotorStep			=	iMotor;
		theiterator->flWeightValue		=	0.0f;	
		theiterator->ucStatus				=	0x0;
		theiterator->dflMarkDistance	=	0.0;
		theiterator->ucFlag					=	0x0;
		theiterator->flCenterValue		=	0.0f;
		theiterator->flCenterWeight	=	pstParameter->stMTFBasic.flcenterweight;
		theiterator->flCenterSpec		=	pstParameter->stMTFBasic.flcenterspec;
		theiterator->flCenterGradeB		=	pstParameter->stMTFBasic.flCenterGradeB;
		memset(&(theiterator->stCenterBlock), 0, sizeof(RECT));

		unsigned int uiFOVSize	=	pstParameter->vectorMTFItem.size();
		theiterator->vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			theiterator->vectorFOV.at(x).ucStatus	=	0x0;
			theiterator->vectorFOV.at(x).ucBlockCount		=	pstParameter->vectorMTFItem.at(x).ucBlockCount;
			theiterator->vectorFOV.at(x).flFOV			=	pstParameter->vectorMTFItem.at(x).flFOV;
			theiterator->vectorFOV.at(x).flAngle		=	pstParameter->vectorMTFItem.at(x).flAngle;
			theiterator->vectorFOV.at(x).flWeight		=	pstParameter->vectorMTFItem.at(x).flWeight;
			theiterator->vectorFOV.at(x).flSpec		=	pstParameter->vectorMTFItem.at(x).flSpec;
			theiterator->vectorFOV.at(x).flGradeB   =	pstParameter->vectorMTFItem.at(x).flGradeB;
			theiterator->vectorFOV.at(x).flSpecUniform		=	pstParameter->vectorMTFItem.at(x).flSpecUniform;

			theiterator->vectorFOV.at(x).flUniformValue	=	0.0f;
			memset(theiterator->vectorFOV.at(x).flValue, 0, sizeof(float) *4);
			memset(theiterator->vectorFOV.at(x).stBlock, 0, sizeof(RECT) *4);
		}
	}

	void MFAMTFItemDataInitial(_HisCCMAlg_AFC_MTF_DataItem& stItemData, _mtffaParameter* pstParameter)
	{
		stItemData.sMotorStep			=	0;
		stItemData.flWeightValue		=	0.0f;	
		stItemData.ucStatus				=	0x0;
		stItemData.dflMarkDistance	=	0.0;
		stItemData.ucFlag					=	0x0;
		stItemData.flCenterValue		=	0.0f;
		stItemData.flCenterWeight		=	pstParameter->stMTFBasic.flcenterweight;
		stItemData.flCenterSpec		=	pstParameter->stMTFBasic.flcenterspec;
		stItemData.ucGrade				=	pstParameter->stMTFBasic.ucGrade;
		stItemData.flCenterGradeD		=	pstParameter->stMTFBasic.flCenterGradeD;
		stItemData.flCenterGradeC		=	pstParameter->stMTFBasic.flCenterGradeC;
		stItemData.flCenterGradeB		=	pstParameter->stMTFBasic.flCenterGradeB;
		stItemData.flCenterGradeE			=	pstParameter->stMTFBasic.flCenterGradeE;
		memset(&(stItemData.stCenterBlock), 0, sizeof(RECT));

		unsigned int uiFOVSize	=	pstParameter->vectorMTFItem.size();
		stItemData.vectorFOV.resize(uiFOVSize);
		for(unsigned int x=0;	x<uiFOVSize;	++x){
			stItemData.vectorFOV.at(x).ucStatus	=	0x0;
			stItemData.vectorFOV.at(x).ucBlockCount		=	pstParameter->vectorMTFItem.at(x).ucBlockCount;
			stItemData.vectorFOV.at(x).flFOV			=	pstParameter->vectorMTFItem.at(x).flFOV;
			stItemData.vectorFOV.at(x).flAngle		=	pstParameter->vectorMTFItem.at(x).flAngle;
			stItemData.vectorFOV.at(x).flWeight		=	pstParameter->vectorMTFItem.at(x).flWeight;
			stItemData.vectorFOV.at(x).flSpec		=	pstParameter->vectorMTFItem.at(x).flSpec;
			stItemData.vectorFOV.at(x).flSpecUniform		=	pstParameter->vectorMTFItem.at(x).flSpecUniform;
			stItemData.vectorFOV.at(x).flGradeD		=	pstParameter->vectorMTFItem.at(x).flGradeD;
			stItemData.vectorFOV.at(x).flGradeC		=	pstParameter->vectorMTFItem.at(x).flGradeC;
			stItemData.vectorFOV.at(x).flGradeB			=	pstParameter->vectorMTFItem.at(x).flGradeB;
			stItemData.vectorFOV.at(x).flGradeE			=	pstParameter->vectorMTFItem.at(x).flGradeE;

			stItemData.vectorFOV.at(x).flUniformValue	=	0.0f;
			memset(stItemData.vectorFOV.at(x).flValue, 0, sizeof(float) *4);
			memset(stItemData.vectorFOV.at(x).stBlock, 0, sizeof(RECT) *4);
		}
	}

	void LpMFAItemDataAdd(_HisCCMAlg_AFC_LP_DataItem& stItemData, RECT& stROI, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex)
	{
		std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV>::iterator foviterator = stItemData.vectorFOV.begin() + uiFOVIndex;

		if(stROI.right - stROI.left > stROI.bottom - stROI.top){
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	1;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}
		else{
			foviterator->stLpValue[uiROIIndex].ucOrientation	=	0;
			foviterator->stLpValue[uiROIIndex].flValue				=	dflValue;
		}

		foviterator->stBlock[uiROIIndex]	=	stROI;

		if(uiROIIndex == 3){
			float flmax	=	maxv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			float flmin		=	minv4(foviterator->stLpValue[0].flValue, foviterator->stLpValue[1].flValue, foviterator->stLpValue[2].flValue, foviterator->stLpValue[3].flValue);
			foviterator->flUniformValue	=	flmax - flmin;
		}
	}

	void saveMTFHAAFCCurve2File(std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorItemData, \
		_mtfAFCParameter* pstParameter, QString& strPath)
	{
		std::vector<_HisCCMAlg_AFC_MTF_DataItem> vectorItemDataCopy(vectorItemData.size());
		vectorItemDataCopy.assign(vectorItemData.begin(), vectorItemData.end());
		std::sort(vectorItemDataCopy.begin(), vectorItemDataCopy.end(), AFCMTFDataItemSortLittle);

		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);

		QTextStream out(&classFile);
		for(unsigned int x=0;	x<vectorItemDataCopy.size(); ++x){
			out << QString::number(vectorItemDataCopy.at(x).sMotorStep) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemDataCopy.size(); ++x){
			out << QString::number(vectorItemDataCopy.at(x).flWeightValue) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemDataCopy.size(); ++x){
			out <<QString::number(vectorItemDataCopy.at(x).flCenterValue) << ",";
		}
		out << "\n";

		for(unsigned int w=0;	w<pstParameter->vectorMTFItem.size(); ++w){
			for(unsigned int y=0; y<pstParameter->vectorMTFItem.at(w).ucBlockCount;	++y){
				for(unsigned int x=0;	x<vectorItemDataCopy.size(); ++x){
					out <<QString::number(vectorItemDataCopy.at(x).vectorFOV.at(w).flValue[y]) << ",";
				}
				out << "\n";
			}
		}		

		classFile.close();
	}

	void savebin(QString strDir, QString strFileName, unsigned char* pucData, unsigned int uiLength, unsigned int uiOffset, bool bAddTime)
	{
		if(strDir.isEmpty()) strDir	=	QDir::currentPath();

		if(bAddTime){
			SYSTEMTIME stTime;
			::GetSystemTime(&stTime);
			char strText[64];
			sprintf(strText, "%04d-%02d-%02d %02d-%02d-%02d", stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond);
			strFileName		=	strDir % "/" % strFileName % strText % ".bin";
		}
		else{
			strFileName		=	strDir % "/" % strFileName % ".bin";
		}

		FILE* fileSave = fopen(strFileName.toAscii().data(), "wb");
		if(fileSave){
			fwrite(pucData+uiOffset, sizeof(unsigned char), uiLength, fileSave);
			fclose(fileSave);
		}
	}

	void showImageLable(QString strPath, int iWidth, int iHeight, unsigned int uiDataFormat)
	{
		if(uiDataFormat >= HisBaylor8_BGGR && uiDataFormat <= HisBaylor8_GBRG){
			QFile classFile(strPath);
			unsigned char* pucRaw8	=	(unsigned char*)_aligned_malloc(iWidth *iHeight, _HisCacheLine_Aligned);
			unsigned char* pucRGB24	=	(unsigned char*)_aligned_malloc(iWidth *iHeight *3, _HisCacheLine_Aligned);
			if(!pucRaw8 || !pucRGB24){
				HisReleaseMalloc(pucRaw8);
				HisReleaseMalloc(pucRGB24);
				return;
			}

			bool bresult = true;
			if(classFile.open(QIODevice::ReadOnly)){
				classFile.seek(0);
				if(classFile.read((char*)(pucRaw8), iWidth *iHeight) != iWidth *iHeight)	bresult	=	false;
				classFile.close();
				if(bresult){
					classAlgorithm.HisCCMBarlor2RGB24(pucRaw8, pucRGB24, iWidth, iHeight, uiDataFormat, 0);
					QImage theImage(pucRGB24, iWidth, iHeight, QImage::Format_RGB888);
					QLabel* ptheLable	=	new QLabel();
					ptheLable->setPixmap(QPixmap::fromImage(theImage));
					ptheLable->show();
				}
			}

			HisReleaseMalloc(pucRaw8);
			HisReleaseMalloc(pucRGB24);
		}
	}

	unsigned int getAFACameraNextExposureTime(unsigned int uiNowEt, QString& strPath, unsigned char* pucBuffer, int iCenterX, int iCenterY)
	{
		return 0;

	}
	int BlackStripesDetected(unsigned char *pucRGB24,unsigned int iScanBoxSize,int Width, int Height,RECT &sBlock)
	{
		int xstart=(Width>>1)-(iScanBoxSize>>1);
		int ystart=(Height>>1)-(iScanBoxSize>>1);
		int vertical_sum1=0,vertical_sum2=0;
		UCHAR pixel=0;
		float 	 vmax_f=0.0f, vmax_r=0.0f,vmax_value=0.0f;
		int vertical_line1=-1,vertical_line2=-1;
		float code_variation=0.5;
		//vertical
		for(int i=xstart; i<xstart+iScanBoxSize-1;i++)
		{
			for(int j=ystart; j<ystart+iScanBoxSize; j++)
			{
				pixel = pucRGB24[PIXEL_G(i,j,Width,Height)];
				vertical_sum1 += pixel;
				pixel = pucRGB24[PIXEL_G(i+3,j,Width,Height)];
				vertical_sum2 += pixel;
			}
			//falling
			if(vmax_f < (vertical_sum1 - vertical_sum2)) 
			{
				vmax_f = (float)abs(vertical_sum1 - vertical_sum2);
				if(vmax_f >= (Height/2)*code_variation ) vertical_line1 = i; 
			}
			//rising
			if(vmax_r < (vertical_sum2 - vertical_sum1)) 
			{
				vmax_r = (float)abs(vertical_sum1 - vertical_sum2);
				if(vmax_r >= (Height/2)*code_variation ) 
				{
					vertical_line2 = i;
					vmax_value = vmax_r;
				}
			}
			vertical_sum1 = vertical_sum2 = 0;
		}
		if((vertical_line1==-1) ||(vertical_line2==-1) )
		{
			return 0;
		}
		int StripesWidth=abs(vertical_line2-vertical_line1);
		sBlock.left=(vertical_line1)-int(StripesWidth*0.65);
		sBlock.right=(vertical_line1)+int(StripesWidth*0.65);
		sBlock.top=(Height>>1)-int(StripesWidth*0.85);
		sBlock.bottom=(Height>>1)+int(StripesWidth*0.85);
#ifdef _DEBUG
		int iROIW=sBlock.right-sBlock.left;
		int iROIH=sBlock.bottom-sBlock.top;
		UCHAR *pROIY=new UCHAR[iROIW*iROIH];
		for(int j=0;j<iROIH;j++)
		{
			for(int i=0;i<iROIW;i++)
			{
				int index=((sBlock.top+j)*Width+(sBlock.left+i))*3;
				pROIY[j*iROIW+i]=UCHAR(((pucRGB24[index]) *299 + (pucRGB24[index+1]) *587 + (pucRGB24[index+2]) *114)/1000.0f);
			}
		}
		saveRaw8("./","StripesROIY",HisBaylor8_RGGB,iROIW,iROIH,pROIY);
		delete []pROIY;
#endif
		return TRUE;
	}
	void savequalcomAWBLSCData(QString strserialnumber,CalibrationDataStruct stCalData,ImageBlcokData stBlockData,QString strPath)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
		QTextStream out(&classFile);
		if(classFile.size()<3)
		{
			out <<"SN,TIME,RG,BG,";
			//R
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"R("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//GR
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"Gr("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//GB
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"Gb("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//B
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"B("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			out<<"\n";
		}
		out <<strserialnumber%","%QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")%",";
		out <<QString::number(stCalData.AWB[0]/1023.0f,'f',3)%",";
		out <<QString::number(stCalData.AWB[1]/1023.0f,'f',3)%",";

		//R
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stBlockData.R_LSC[17*j+i],'f',3)%",";
			}
		}
		//GR
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stBlockData.Gr_LSC[17*j+i],'f',3)%",";
			}
		}
		//GB
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stBlockData.Gb_LSC[17*j+i],'f',3)%",";
			}
		}
		//B
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stBlockData.B_LSC[17*j+i],'f',3)%",";
			}
		}
		out<<"\n";

		out<<",,,BurnData,";
		//R
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.R_LSC[17*j+i])%",";
			}
		}
		//GR
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.Gr_LSC[17*j+i])%",";
			}
		}
		//GB
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.Gb_LSC[17*j+i])%",";
			}
		}
		//B
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.B_LSC[17*j+i])%",";
			}
		}
		out<<"\n";

		classFile.close();
	}

	void savequalcomAWBLSCprocessData(QString strserialnumber,CalibrationprocessDataStruct stCalData,QString strPath)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
		QTextStream out(&classFile);
		if(classFile.size()<3)
		{
			out <<"SN,TIME,RG,BG,";
			//R
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"R("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//GR
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"Gr("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//GB
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"Gb("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			//B
			for(int j=0;j<13;j++)
			{
				for(int i=0;i<17;i++)
				{
					out<<"B("%QString::number(j+1)%"_"%QString::number(i+1)%"),";
				}
			}
			out<<"\n";
		}
		out <<strserialnumber%","%QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")%",";
		out <<QString::number(stCalData.AWB[0],'f',3)%",";
		out <<QString::number(stCalData.AWB[1],'f',3)%",";

		//R
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.R_LSC[17*j+i],'f',3)%",";
			}
		}
		//GR
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.Gr_LSC[17*j+i],'f',3)%",";
			}
		}
		//GB
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.Gb_LSC[17*j+i],'f',3)%",";
			}
		}
		//B
		for(int j=0;j<13;j++)
		{
			for(int i=0;i<17;i++)
			{
				out<<QString::number(stCalData.B_LSC[17*j+i],'f',3)%",";
			}
		}
		out<<"\n";

		classFile.close();
	}

	int QualcommAWBLSCCaculation(unsigned char *pRaw, unsigned int uiBayerFormat,int iWidth, int iHeight, int iBlackLevel,CalibrationDataStruct &stCalData,ImageBlcokData &stBlockData)
	{
		int iresult=0;
		int iCFA_Pattern=GBRG_PATTERN;
		if(uiBayerFormat==HisBaylor8_BGGR || uiBayerFormat==HisBaylor10_BGGR)  iCFA_Pattern=BGGR_PATTERN;
		else if(uiBayerFormat==HisBaylor8_RGGB || uiBayerFormat==HisBaylor10_RGGB)  iCFA_Pattern=RGGB_PATTERN;
		else if(uiBayerFormat==HisBaylor8_GRBG || uiBayerFormat==HisBaylor10_GRBG)  iCFA_Pattern=GRBG_PATTERN;
		else if(uiBayerFormat==HisBaylor8_GBRG || uiBayerFormat==HisBaylor10_GBRG)  iCFA_Pattern=GBRG_PATTERN;
		bool bMode9x7 = false; //true-9x7, false-17x13
		iresult = LensCorrectionLib(pRaw, iWidth, iHeight,iCFA_Pattern, iBlackLevel, iBlackLevel,iBlackLevel, iBlackLevel,bMode9x7,  &stCalData,&stBlockData);
		return iresult;
	}

	void bylorraw8average(unsigned __int8* pui8raw8, int iwidth, int iheight, unsigned int uidataformat, RECT strange, double& dflR, double& dflB, double& dflGr, double& dflGb)
	{
		dflR	=	dflB	=	dflGr	=	dflGb	=0.0;
		strange.left				=	((strange.left >>1) <<1);
		strange.right			=	((strange.right >>1) <<1);
		strange.top				=	((strange.top >>1) <<1);
		strange.bottom		=	((strange.bottom >>1) <<1);
		register unsigned __int32 ui32L11 = 0;
		register unsigned __int32 ui32L12 = 0;
		register unsigned __int32 ui32L21 = 0;
		register unsigned __int32 ui32L22 = 0;

		LONG	x;
		unsigned __int8* pui8Line	=	pui8raw8 + (strange.top *iwidth + strange.left);
		unsigned __int8* pui8Data;
		for(LONG y=strange.top;	y<strange.bottom;	y+=2){
			pui8Data	=	pui8Line;
			pui8Line		+=	iwidth;
			for(x=strange.left;	x<strange.right;	x+=2){
				ui32L11		=	ui32L11 + static_cast<unsigned __int32>(*pui8Data);
				ui32L12		=	ui32L12 + static_cast<unsigned __int32>(*(pui8Data+1));
				pui8Data	+=	2;
			}

			pui8Data	=	pui8Line;
			pui8Line		+=	iwidth;
			for(x=strange.left;	x<strange.right;	x+=2){
				ui32L21		=	ui32L21 + static_cast<unsigned __int32>(*pui8Data);
				ui32L22		=	ui32L22 + static_cast<unsigned __int32>(*(pui8Data+1));
				pui8Data	+=	2;
			}
		}

		x	=	(((strange.right-strange.left) * (strange.bottom-strange.top)) >>2);
		switch (uidataformat){
		case HisBaylor8_BGGR:
		case HisBaylor10_BGGR:
			dflB		=	static_cast<double>(ui32L11) / static_cast<double>(x);
			dflGb	=	static_cast<double>(ui32L12) / static_cast<double>(x);
			dflGr	=	static_cast<double>(ui32L21) / static_cast<double>(x);
			dflR		=	static_cast<double>(ui32L22) / static_cast<double>(x);
			break;
		case HisBaylor8_RGGB:
		case HisBaylor10_RGGB:
			dflR		=	static_cast<double>(ui32L11) / static_cast<double>(x);
			dflGr	=	static_cast<double>(ui32L12) / static_cast<double>(x);
			dflGb	=	static_cast<double>(ui32L21) / static_cast<double>(x);
			dflB		=	static_cast<double>(ui32L22) / static_cast<double>(x);
			break;
		case HisBaylor8_GRBG:
		case HisBaylor10_GRBG:
			dflGr	=	static_cast<double>(ui32L11) / static_cast<double>(x);
			dflR		=	static_cast<double>(ui32L12) / static_cast<double>(x);
			dflB		=	static_cast<double>(ui32L21) / static_cast<double>(x);
			dflGb	=	static_cast<double>(ui32L22) / static_cast<double>(x);
			break;
		case HisBaylor8_GBRG:
		case HisBaylor10_GBRG:
		default:
			dflGb	=	static_cast<double>(ui32L11) / static_cast<double>(x);
			dflB		=	static_cast<double>(ui32L12) / static_cast<double>(x);
			dflR		=	static_cast<double>(ui32L21) / static_cast<double>(x);
			dflGr	=	static_cast<double>(ui32L22) / static_cast<double>(x);
			break;
		}
	}


	int ParseINIFile(QString strDir,wchar_t *KeyName, unsigned int *RegAddr, unsigned int *RegData, int &i2CCnt)
	{
		int iresult=0;
		FILE			*fp;
		unsigned short	wRegAddr = 0;
		unsigned short	wRegData = 0;
		int				tmp_idata=0;
		BOOL			Register_end =FALSE;
		int				data=0;
		int               I2CIndex=0;

		wchar_t	tmp_cmd[512]={0};
		wchar_t	tmp_data[512]={0};
		wchar_t	linebufIn[512*2];
		bool	bwrite_start=false;

		if (fopen_s(&fp,strDir.toLatin1().data(),"r") != 0)
		{
			//Fail
			iresult = HisCCMError_ReadFile;
			return iresult;
		}


		memset(linebufIn, 0, sizeof(wchar_t)*512*2);

		while (fgetws(linebufIn, 512*2, fp))	
		{
			memset(tmp_cmd, 0, sizeof(wchar_t)*512);  
			swscanf_s(linebufIn,L"%s",tmp_cmd,_countof(tmp_cmd));
			if((0 == wcscmp(KeyName,tmp_cmd))) 
			{

				if (bwrite_start == false) 
				{
					bwrite_start = true;
				}
			}
			else if((0 == wcscmp(L"[END]",tmp_cmd)) && bwrite_start == true) 
			{
				bwrite_start = false;
				break;
			}
			//-------------------------------------------------
			if(true == bwrite_start)
			{	
				for (int i=0;i<4;i++)	//
				{
					linebufIn[i] = towupper(linebufIn[i]); 
				}

				if (linebufIn[0] == '0' && linebufIn[1] == 'X') 
				{
					swscanf_s(linebufIn,L"%hx%hx",&wRegAddr,&wRegData);
					RegAddr[I2CIndex]=wRegAddr;
					RegData[I2CIndex]=wRegData;
					I2CIndex++;
				}
				memset(linebufIn, 0, sizeof(wchar_t)*512*2);
			}//end bWrite
		}
		fclose(fp);
		i2CCnt=I2CIndex;
		return iresult;
	}
	 void saveCDAFVerifyCure(int iVerifyStep,int *iDAC,float *fmtf50, float *fmtf50smooth,QString& strPath,QString sSerialnumber)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
		QTextStream out(&classFile);
		out <<sSerialnumber%","%QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")%",DAC,";
		for(int i=0;i<iVerifyStep;i++)
		{
			out << QString::number(iDAC[i]) << ",";
		}
		out << "\n";
		out << ",,mtf50,";
		for(int i=0;i<iVerifyStep;i++)
		{
			out << QString::number(fmtf50[i],'f',3) << ",";
		}
		out << "\n";
		out << ",,mtf50smooth,";
		for(int i=0;i<iVerifyStep;i++)
		{
			out << QString::number(fmtf50smooth[i],'f',3) << ",";
		}
		out << "\n\n";

		classFile.close();
	}
}

