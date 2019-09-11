#include "hisfx3ccmtest.h"
#include "hardwareop.h"
#include "qoplow.h"
#include "qitemexetool.h"
#include "QHofflinePath.h"
#include "QHMainWindow.h"


int iflag	=0;
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#ifdef _HisFX3_Platform_Jigboard
#include "JigboardFunction.h"
#endif

renderframe::renderframe(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, QHImageFrame& imageframeC, QScrollBar& horizontalScrollBarC, QScrollBar& verticalScrollBarC)
	:bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), imageframe(imageframeC), horizontalScrollBar(horizontalScrollBarC), verticalScrollBar(verticalScrollBarC)
{

}

void renderframe::finish()
{
	emit finished();
}

void renderframe::startpreview()
{
	threadshareData.flaglock.lockForWrite();
	threadshareData.brenderrun	=	true;
	threadshareData.flaglock.unlock();

	unsigned char* pucDrawImageRGB24 = 0;
	int iDrawImageWidth = 0, iDrawImageHeight = 0;
	RECT stDrawImageROI;
	int iDrawImageOffsetLeft, iDrawImageOffsetTop;

	unsigned char *pucExchange, *pucRGB24;
	unsigned __int64 ui64PreIndex = 0, ui64TheIndex, uifpsindex=0;
	unsigned int uiCount;
	DWORD dwend, dwstart	=	GetTickCount();
	unsigned char ucScaleMode;

	threadshareData.flaglock.lockForRead();
	LONG lWidth		=	threadshareData.uiWidth;
	LONG lHeight		=	threadshareData.uiHeight;
	threadshareData.flaglock.unlock();
	int lLine		=	(lWidth <<1) +lWidth;
	_imageShowPolicy stImageShowPolicy;

	while(threadshareData.GetHisPreviewflag())
	{
		uiCount	=	_Thread_Wait_Times;
		while(--uiCount)
		{
#ifdef _HisFX3_Platform_Jigboard
			if(hisglobalparameter.Jig_bRefreshImage){
				hisglobalparameter.Jig_bRefreshImage	=	false;
				break;
			}
#endif
			threadshareData.flaglock.lockForRead();
			ui64TheIndex	=	threadshareData.ui64RGB2Index;
			threadshareData.flaglock.unlock();
			if(ui64TheIndex > ui64PreIndex)	break;
			if(!threadshareData.GetHisPreviewflag()) { uiCount =0; break; }
			Sleep(3);
		}

		if(!uiCount)
		{
			if(!threadshareData.GetHisPreviewflag())	break;
			continue;
		}

		threadshareData.flaglock.lockForRead();
		stImageShowPolicy = threadshareData.stImageShowPolicy;
#ifdef _HisFX3_Platform_Jigboard
		lWidth		=	threadshareData.uiWidth;
		lHeight		=	threadshareData.uiHeight;
		lLine			=	(lWidth <<1) +lWidth;
#endif
		threadshareData.flaglock.unlock();

		if(!(imageframe.size().width() && imageframe.size().height())) continue;

		if(imageframe.size().width() != iDrawImageWidth || imageframe.size().height() != iDrawImageHeight)
		{
			HisReleaseMalloc(pucDrawImageRGB24);
			iDrawImageWidth	=	imageframe.width();
			iDrawImageHeight	=	imageframe.height();
			pucDrawImageRGB24 = (unsigned char*)_aligned_malloc(iDrawImageWidth *iDrawImageHeight *3, _HisCacheLine_Aligned);

			if(!pucDrawImageRGB24) {
				iDrawImageWidth	=	iDrawImageHeight	=	0;
				emit information("_aligned_malloc pucDrawImageRGB24 fail");
				continue;
			}
		}

		iDrawImageOffsetLeft		=iDrawImageOffsetTop	=0;
		ucScaleMode	=	hisglobalparameter.ucScaleMode;
		pucRGB24	=	0;
		if(threadshareData.GetBlemishEnhanceShowFlag())
		{
			pucRGB24	=	(unsigned char*)HisAlignedMalloc(lWidth *lHeight *3);
		}
		QHisFX3MallocAlignedManage classpucRGB24(pucRGB24);

		threadshareData.rgb2lock.lockForRead();		
		if(pucRGB24) // blemish enhance
		{
			unsigned char* pucSrc = threadshareData.pucRGB2, *pucDes = pucRGB24;
			unsigned int uiPixel	=	lWidth *lHeight;
			RECT stTempBlock;
			stTempBlock.left	=	stTempBlock.top	=	0;		stTempBlock.right = lWidth; stTempBlock.bottom = lHeight;
			classAlgorithm.rgb24tograybit8(pucSrc, pucDes, lWidth, lHeight, stTempBlock);
			classAlgorithm.contrastenhance(pucRGB24, lWidth, lHeight);
			pucDes	=	pucRGB24 +lWidth *lHeight *3 -1;
			pucSrc		=	pucRGB24 + lWidth *lHeight -1;
			for(unsigned int x=0;	x<uiPixel;	++x)
			{
				*pucDes	=	*(pucDes-1) = *(pucDes -2) = *pucSrc;
				--pucSrc;
				pucDes	-=	3;
			}

			ucScaleMode	=	3;
		}
		else
		{
			pucRGB24	=	threadshareData.pucRGB2;
		}

		if(stImageShowPolicy.ucMode == 0) //fit size
		{
			classAlgorithm.resizeImageFrame(pucRGB24, lWidth, lHeight, pucDrawImageRGB24, iDrawImageWidth, iDrawImageHeight, ucScaleMode, iDrawImageOffsetLeft, iDrawImageOffsetTop, hisglobalparameter.ucAspectRatio);
			
 			stDrawImageROI.left = stDrawImageROI.top = 0;
 			stDrawImageROI.right = lWidth;		stDrawImageROI.bottom = lHeight;
		}
 		else if(stImageShowPolicy.ucMode == 1)  //soduku
 		{
 			int iSodoX, iSodoY;
 			int iSodoW = lWidth /3, iSodoH = lHeight /3;
 			switch (stImageShowPolicy.ucSodokuPos){
 			case 7: iSodoX = 0; iSodoY = 0; break;
 			case 8: iSodoX = iSodoW; iSodoY = 0; break;
 			case 9: iSodoX = lWidth - iSodoW; iSodoY = 0; break;
 			case 4: iSodoX = 0; iSodoY = iSodoH; break;
 			case 5: iSodoX = iSodoW; iSodoY = iSodoH; break;
 			case 6: iSodoX = lWidth - iSodoW; iSodoY = iSodoH; break;
 			case 1: iSodoX = 0; iSodoY = lHeight -iSodoH; break;
 			case 2: iSodoX = iSodoW; iSodoY = lHeight -iSodoH; break;
 			default: iSodoX = lWidth - iSodoW; iSodoY = lHeight -iSodoH; break;
 			}
 			stDrawImageROI.left	=	iSodoX; stDrawImageROI.right = iSodoX +iSodoW;
 			stDrawImageROI.top	=	iSodoY; stDrawImageROI.bottom = iSodoY +iSodoH;
 			classAlgorithm.resizeImageFrameSodu(pucRGB24, lWidth, lHeight, stDrawImageROI, pucDrawImageRGB24, iDrawImageWidth, iDrawImageHeight, ucScaleMode);
 		}
 		else if(stImageShowPolicy.ucMode == 2)  //1.0x
 		{
 			stDrawImageROI.left = horizontalScrollBar.value(); stDrawImageROI.right		    = min(stDrawImageROI.left + iDrawImageWidth, lWidth);
 			stDrawImageROI.top = verticalScrollBar.value();     stDrawImageROI.bottom		= min(stDrawImageROI.top + iDrawImageHeight, lHeight);
 			memset(pucDrawImageRGB24, 240, iDrawImageHeight *iDrawImageWidth *3);
 			unsigned char* pucSrcLine	=  (pucRGB24 + stDrawImageROI.top *lLine + (stDrawImageROI.left << 1) +stDrawImageROI.left);
 			unsigned char* pucDesLine	=	pucDrawImageRGB24;	
 			unsigned int uiDesLineByte	= (iDrawImageWidth << 1) + iDrawImageWidth;
 			unsigned int uiCopyLineByte	=	uiDesLineByte;
 			if(iDrawImageHeight > lHeight) pucDesLine += (((iDrawImageHeight - lHeight) >>1) *uiDesLineByte);
 			if(iDrawImageWidth > lWidth) {pucDesLine += (((iDrawImageWidth - lWidth) >>1) *3);  uiCopyLineByte = lLine; }
 			for(int y=stDrawImageROI.top; y<stDrawImageROI.bottom; ++y){
 				memcpy(pucDesLine, pucSrcLine, uiCopyLineByte);
 				pucDesLine	+=	uiDesLineByte;
 				pucSrcLine	+=	lLine;
 			}
 			if(iDrawImageWidth > lWidth) iDrawImageOffsetLeft = ((iDrawImageWidth - lWidth) >>1);
 			if(iDrawImageHeight > lHeight) iDrawImageOffsetTop = ((iDrawImageHeight - lHeight) >>1);
 		}
 		else if(stImageShowPolicy.ucMode == 3)  //2.0x
 		{
  			stDrawImageROI.left = (horizontalScrollBar.value() >>1); stDrawImageROI.right	  = min(stDrawImageROI.left + (iDrawImageWidth >>1), lWidth);
  			stDrawImageROI.top = (verticalScrollBar.value() >>1); stDrawImageROI.bottom	  = min(stDrawImageROI.top + (iDrawImageHeight >>1), lHeight);
 			memset(pucDrawImageRGB24, 240, iDrawImageHeight *iDrawImageWidth *3);
 			classAlgorithm.resizeImageFrameSodu(pucRGB24, lWidth, lHeight, stDrawImageROI, pucDrawImageRGB24, iDrawImageWidth, iDrawImageHeight, ucScaleMode);
 			if(iDrawImageWidth > (lWidth <<1)) iDrawImageOffsetLeft = ((iDrawImageWidth - (lWidth <<1)) >>1);
 			if(iDrawImageHeight > (lHeight <<1)) iDrawImageOffsetTop = ((iDrawImageHeight - (lHeight <<1)) >>1);
 		}
 		else
 		{
 			stDrawImageROI.left = (horizontalScrollBar.value() >>2); stDrawImageROI.right	  = min(stDrawImageROI.left + (iDrawImageWidth >>2), lWidth);
 			stDrawImageROI.top = (verticalScrollBar.value() >>2); stDrawImageROI.bottom	  = min(stDrawImageROI.top + (iDrawImageHeight >>2), lHeight);
 			classAlgorithm.resizeImageFrameSodu(pucRGB24, lWidth, lHeight, stDrawImageROI, pucDrawImageRGB24, iDrawImageWidth, iDrawImageHeight, ucScaleMode);
 			if(iDrawImageWidth > (lWidth <<2)) iDrawImageOffsetLeft = ((iDrawImageWidth - (lWidth <<2)) >>1);
 			if(iDrawImageHeight > (lHeight <<2)) iDrawImageOffsetTop = ((iDrawImageHeight - (lHeight <<2)) >>1);
 		}
		threadshareData.rgb2lock.unlock();

/*
 		if(threadshareData.GetBlemishEnhanceShowFlag())
 		{
 			unsigned char* pucSrc = pucDrawImageRGB24, *pucDes = pucDrawImageRGB24;
 			unsigned int uiPixel	=	iDrawImageHeight *iDrawImageWidth;
			RECT stTempBlock;
			stTempBlock.left	=	stTempBlock.top	=	0;		stTempBlock.right = iDrawImageWidth; stTempBlock.bottom = iDrawImageHeight;
			classAlgorithm.rgb24tograybit8(pucSrc, pucDes, iDrawImageWidth, iDrawImageHeight, stTempBlock);
 			classAlgorithm.contrastenhance(pucDrawImageRGB24, iDrawImageWidth, iDrawImageHeight);
 			pucDes	=	pucDrawImageRGB24 +iDrawImageWidth *iDrawImageHeight *3 -1;
 			pucSrc		=	pucDrawImageRGB24 + iDrawImageWidth *iDrawImageHeight -1;
 			for(unsigned int x=0;	x<uiPixel;	++x)
 			{
 				*pucDes	=	*(pucDes-1) = *(pucDes -2) = *pucSrc;
 				--pucSrc;
 				pucDes	-=	3;
 			}
 		}
*/
 
 		threadshareData.pixmaplock.lockForWrite();
 		if(iDrawImageWidth != threadshareData.iDrawImageWidth || iDrawImageHeight != threadshareData.iDrawImageHeight)
 		{
 			HisReleaseMalloc(threadshareData.pucDrawImageRGB24);
 			threadshareData.iDrawImageWidth	=	iDrawImageWidth;
 			threadshareData.iDrawImageHeight	=	iDrawImageHeight;
 			threadshareData.pucDrawImageRGB24 = (unsigned char*)_aligned_malloc(iDrawImageWidth *iDrawImageHeight *3, _HisCacheLine_Aligned);
 		}
 
 		if(threadshareData.pucDrawImageRGB24)
 		{
 			pucExchange	=	threadshareData.pucDrawImageRGB24;
 			threadshareData.pucDrawImageRGB24	=	pucDrawImageRGB24;
 			pucDrawImageRGB24	=	pucExchange;
 			threadshareData.iDrawImageOffsetLeft	=	iDrawImageOffsetLeft;
 			threadshareData.iDrawImageOffsetTop	=	iDrawImageOffsetTop;
 			threadshareData.stDrawImageROI		=	stDrawImageROI;
 		}
 
 		threadshareData.pixmaplock.unlock();
 
 		emit drawframe(-100);
 
 		++uifpsindex;
 		dwend	=	GetTickCount();
 		if(dwend	> 1000 + dwstart){
 			emit updatefps(0.0f, 0.0f, uifpsindex *1000.0f / (float)(dwend-dwstart), 0xFF00);
 			dwstart		=	dwend;
 			uifpsindex	=	0;
 		}
 
 		ui64PreIndex	=	ui64TheIndex;
	}

 	emit drawframe(-10);
 
  	HisReleaseMalloc(pucDrawImageRGB24);
  
  	threadshareData.flaglock.lockForWrite();
  	threadshareData.brenderrun	=	false;
  	threadshareData.flaglock.unlock();
}

improveraw::improveraw(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC)
	:bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC)
{

}

void improveraw::finish()
{
	emit finished();
}

void improveraw::startpreview()
{
	threadshareData.flaglock.lockForWrite();
	threadshareData.brawrun	=	true;
	threadshareData.flaglock.unlock();

	unsigned char *pucExchange;
	unsigned __int64 ui64PreIndex = 0, ui64TheIndex, uifpsindex=0, ui64NowfpsIndex, uiUploadfpsindex=0;
	unsigned int uiCount, uiawbframe=0;
	DWORD dwend, dwstart	=	GetTickCount();
	unsigned char ucBlackLevel	=	0;
	int errorcode;
	bool bMirror = false, bFlip = false;

	while(threadshareData.GetHisPreviewflag())
	{
		uiCount	=	_Thread_Wait_Times;
		while(--uiCount)
		{
			if(bBoxChannel1 && !(classPlatform.HisFX3GrabFrame(0, 0, ui64TheIndex)))
			{
				if(ui64TheIndex > ui64PreIndex)	
				{
					break;
				}
			}
			else if(!bBoxChannel1 && !(classPlatform.HisFX3GrabFrame_S2(0, 0, ui64TheIndex))){
				if(ui64TheIndex > ui64PreIndex)	break;
			}

			Sleep(5);
			if(!threadshareData.GetHisPreviewflag())	{ uiCount = 0; break; }
		}

		if(!uiCount)
		{
			if(!threadshareData.GetHisPreviewflag())	break;
			continue;
		}

		if(bBoxChannel1)
			errorcode	=	classPlatform.HisFX3GrabFrame(&(threadshareData.pucRaw1), threadshareData.uiRawBufByte, ui64TheIndex, 0);
		else
			errorcode	=	classPlatform.HisFX3GrabFrame_S2(&(threadshareData.pucRaw1), threadshareData.uiRawBufByte, ui64TheIndex, 0);

 		if(errorcode)
		{
			emit information(GetHisFX3ErrorInfo(errorcode));
			if(!threadshareData.GetHisPreviewflag())
				break;
			else
				continue;
		}

		/***********************operate raw1 buffer********************/
		threadshareData.GetDSPMirrorFlip(bMirror, bFlip);
		if(bMirror)	classAlgorithm.mirror(threadshareData.pucRaw1, threadshareData.uiWidth, threadshareData.uiHeight, (_HisFX3_BaylorMode)threadshareData.ucFormat);
		if(bFlip)	classAlgorithm.flip(threadshareData.pucRaw1, threadshareData.uiWidth, threadshareData.uiHeight, (_HisFX3_BaylorMode)threadshareData.ucFormat);

		ucBlackLevel	=	threadshareData.GetDSPBlackLevel();
		if(ucBlackLevel)
			classAlgorithm.subblacklevel(threadshareData.pucRaw1, ucBlackLevel, threadshareData.uiWidth *threadshareData.uiHeight, threadshareData.ucFormat);

		if(threadshareData.GetDSPLSCFlag())
		{
			errorcode = classAlgorithm.HisCCMLSCHA_ImportTemplate(threadshareData.pucRaw1, threadshareData.uiWidth, \
				threadshareData.uiHeight, static_cast<_HisFX3_BaylorMode>(threadshareData.ucFormat), threadshareData.wstrLSCTemplatePath, bBoxChannel1);
			if(errorcode)
				emit information(GetHisFX3ErrorInfo(errorcode) % "---LSC");
		}

		if(threadshareData.GetDSPAWBFlag())
		{
			switch (threadshareData.ucAWB_Method)
			{
			case 0: //rolongo auto
				if(!uiawbframe || uiawbframe > threadshareData.ucAWB_RefreshRate){
					uiawbframe	=	1;
					classAlgorithm.HisCCMGetAWBGain(threadshareData.pucRaw1,threadshareData.uiWidth,threadshareData.uiHeight,threadshareData.ucFormat, \
						threadshareData.flAWB_GainB, threadshareData.flAWB_GainR);
				}
				else
					++uiawbframe;
				if(threadshareData.bUseSensorAWBGain && uiawbframe == 1)
				{
#if (defined _WIN64) && (defined _DEBUG)
					QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64D";
#elif (defined _WIN64) && !(defined _DEBUG)
					QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64";
#elif (defined _WIN32) && (defined _DEBUG)
					QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32D";
#else
					QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32";
#endif

					RolongosetAWBGain setAWBGain = (RolongosetAWBGain)(QLibrary::resolve(strLibPath, "setAWBGain"));
					RolongogetAWBGain getAWBGain = (RolongogetAWBGain)(QLibrary::resolve(strLibPath, "getAWBGain"));
					if(!setAWBGain || !getAWBGain)
					{
						emit information(strLibPath % " Load setAWBGain/getAWBGain Failed");
					}
					else
					{
						float flGainR, flGainG, flGainB, flGainMin, flGainMax;
						if(errorcode = getAWBGain((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
							flGainR, flGainB, flGainG, flGainMin, flGainMax,  globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
							globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI))
							emit information("Get " % itemshareData.ccmhardwareParameter->sensortype % " WB Gain Fail");
						else
						{
// 							emit information("flAWB_GainR: " % QString::number(threadshareData.flAWB_GainR, 'f', 4));
// 							emit information("flAWB_GainB: " % QString::number(threadshareData.flAWB_GainB, 'f', 4));
// 							emit information("flGainR: " % QString::number(flGainR, 'f', 4));
// 							emit information("flGainG: " % QString::number(flGainG, 'f', 4));
// 							emit information("flGainB: " % QString::number(flGainB, 'f', 4));
							flGainR	*=	threadshareData.flAWB_GainR;
							flGainB		*=	threadshareData.flAWB_GainB;
							flGainMin	=	flGainG; flGainMin = min(flGainMin, flGainR); flGainMin = min(flGainMin, flGainB);
							flGainR	/=	flGainMin;
							flGainG	/=	flGainMin;
							flGainB		/=	flGainMin;

// 							emit information("flGainR New: " % QString::number(flGainR, 'f', 4));
// 							emit information("flGainG New: " % QString::number(flGainG, 'f', 4));
// 							emit information("flGainB New: " % QString::number(flGainB, 'f', 4));
							
							if(errorcode = setAWBGain((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), itemshareData.previewParameter->ucSlave, \
								flGainR, true, flGainB, true, flGainG, true,  globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
								globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI))
								emit information("Set " % itemshareData.ccmhardwareParameter->sensortype % " WB Gain Fail");
						}
					}
				}
				else if(!threadshareData.bUseSensorAWBGain)
				{
					classAlgorithm.HisCCMSetAWBGain(threadshareData.pucRaw1, threadshareData.uiWidth, threadshareData.uiHeight, \
						threadshareData.ucFormat, threadshareData.flAWB_GainB, threadshareData.flAWB_GainR);
				}
				break;
			case 1: //rolongo manual
				if(!threadshareData.bUseSensorAWBGain)
				{
					classAlgorithm.HisCCMSetAWBGain(threadshareData.pucRaw1, threadshareData.uiWidth, threadshareData.uiHeight, \
						threadshareData.ucFormat, threadshareData.flAWB_GainB, threadshareData.flAWB_GainR);
				}
				break;
			default:
				break;
			}
		}

		/***************************************************************/

		threadshareData.flaglock.lockForWrite();
		threadshareData.ui64Raw1Index	=	ui64TheIndex;
		pucExchange	=	threadshareData.pucRawX;
		threadshareData.flaglock.unlock();

		if(pucExchange)
		{
			classAlgorithm.copyframebuffer(threadshareData.pucRaw1, pucExchange, threadshareData.uiRawBufByte);
			threadshareData.flaglock.lockForWrite();
			threadshareData.pucRawX	=	0;
			threadshareData.flaglock.unlock();
		}

		if(!threadshareData.raw2lock.tryLockForWrite(500))
		{
			emit information(QTextCodec::codecForName( "GBK")->toUnicode("无法实现数据交换RAW"));
			if(!threadshareData.GetHisPreviewflag())
				break;
			else
				continue;
		}

		pucExchange						=	threadshareData.pucRaw1;
		threadshareData.pucRaw1	=	threadshareData.pucRaw2;
		threadshareData.pucRaw2	=	pucExchange;
		threadshareData.raw2lock.unlock();

		dwend	=	GetTickCount();
		if(dwend	> 1000 + dwstart){
			ui64NowfpsIndex	=	globalFunPointer.getSensorFrameIndex();
			emit updatefps((ui64NowfpsIndex-uifpsindex) *1000.0f / (float)(dwend-dwstart), (ui64TheIndex-uiUploadfpsindex) *1000.0f / (float)(dwend-dwstart), 0.0f, 0xFF);
			dwstart				=	dwend;
			uifpsindex			=	ui64NowfpsIndex;
			uiUploadfpsindex	=	ui64TheIndex;
		}

		threadshareData.flaglock.lockForWrite();
		threadshareData.ui64Raw2Index =ui64PreIndex	=	ui64TheIndex;
		threadshareData.flaglock.unlock();
	}

	threadshareData.flaglock.lockForWrite();
	threadshareData.brawrun	=	false;
	threadshareData.flaglock.unlock();

}

improvergb24::improvergb24(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC)
	:bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC)
{

}

void improvergb24::finish()
{
	emit finished();
}

void improvergb24::startpreview()
{
	threadshareData.flaglock.lockForWrite();
	threadshareData.brgbrun	=	true;
	threadshareData.flaglock.unlock();

	unsigned char *pucExchange;
	unsigned __int64 ui64PreIndex = 0, ui64TheIndex;
	unsigned int uiCount;

	unsigned char *pucRaw8	=	0;

	while(threadshareData.GetHisPreviewflag())
	{
		uiCount	=	_Thread_Wait_Times;
		while(--uiCount)
		{
			threadshareData.flaglock.lockForRead();
			ui64TheIndex	=	threadshareData.ui64Raw2Index;
			threadshareData.flaglock.unlock();
			if(ui64TheIndex > ui64PreIndex) break;
			if(!threadshareData.GetHisPreviewflag()) { uiCount = 0; break;}
			Sleep(5);
		}

		if(!uiCount)
		{
			if(!threadshareData.GetHisPreviewflag())	break;
			continue;
		}

#if 1
		threadshareData.raw2lock.lockForRead();
		threadshareData.RawX2RGB24(threadshareData.pucRaw2,  threadshareData.pucRGB1, itemshareData.ccmhardwareParameter->b4Cell, \
			itemshareData.ccmhardwareParameter->sensortype);
		threadshareData.raw2lock.unlock();
#else
		switch (threadshareData.ucFormat)
		{
		case HisBaylor10_BGGR:
		case HisBaylor10_RGGB:
		case HisBaylor10_GRBG:
		case HisBaylor10_GBRG:
			{
				bool b4Cell = itemshareData.ccmhardwareParameter->b4Cell;
				if(b4Cell && itemshareData.ccmhardwareParameter->sensortype.contains("ov20880", Qt::CaseInsensitive))
				{
#ifdef _WIN64
					b4Cell = false;
					emit information(tr("The OV20880 lib of 4Cell convert to baylor do not support x64 version"));
#else
					QString strLibPath = QDir::currentPath() % "/4Cell/OV/x86/OV4CellLib";
					fun_ov4c_get_version ov4c_get_version	=	(fun_ov4c_get_version)(QLibrary::resolve(strLibPath, "ov4c_get_version"));
					fun_ov4c_set_i2c_callback ov4c_set_i2c_callback	=	(fun_ov4c_set_i2c_callback)(QLibrary::resolve(strLibPath, "ov4c_set_i2c_callback"));
					fun_ov4c_init ov4c_init	=	(fun_ov4c_init)(QLibrary::resolve(strLibPath, "ov4c_init"));
					fun_ov4c_20880_transform_bayer_raw10 ov4c_20880_transform_bayer_raw10	=	(fun_ov4c_20880_transform_bayer_raw10)(QLibrary::resolve(strLibPath, "ov4c_20880_transform_bayer_raw10"));
					fun_ov4c_release ov4c_release	=	(fun_ov4c_release)(QLibrary::resolve(strLibPath, "ov4c_release"));
					if(ov4c_get_version && ov4c_set_i2c_callback && ov4c_init && ov4c_20880_transform_bayer_raw10 && ov4c_release)
					{					
						int version = ov4c_get_version();
						emit information(tr("OV 4Cell Library Version: ") % QString::number(version));

						// set sensor I2C callback
						int ret = ov4c_set_i2c_callback(0, itemshareData.previewParameter->ucSlave, (ov4c_i2c_callback)OV4Cell_ReadReg_CallbackC1);			
						if (ret != 0)
						{
							b4Cell = false;
							emit information("ov4c_set_i2c_callback return: " % QString::number(ret));
						}
						else
						{
							ROI_PARA roi_para;
							// input x,y coordinates of each roi
							// all x/y/w/h should be multiple of 4, if not, library will auto truncate to multiple of 4
							// if roi_x_num * roi_y_num = 1
							// x[0] coordinates range: [0, 5120-roi.w]
							// y[0] coordinates range: [0, 3840-roi.h]
							// for example, transform whole image:
							roi_para.w = 5120;
							roi_para.h = 3840;		// all rois use same size
							roi_para.roi_x_num = 1;
							roi_para.roi_y_num = 1;
							roi_para.x[0] = 0;		roi_para.y[0] = 0;

							// init library
							// if roi number(roi_x_num*roi_y_num) is changed, should init again
							ret = ov4c_init(&roi_para);
							if (ret != 0)
							{
								b4Cell = false;
								emit information("ov4c_init return: " % QString::number(ret));
								// release library
								ov4c_release();
							}
							else
							{
								unsigned char* pucTempBaylor = (unsigned char*)HisAlignedMalloc(roi_para.w*roi_para.roi_x_num*roi_para.h*roi_para.roi_y_num *2);
								QHisFX3MallocAlignedManage classpucTempBaylor(pucTempBaylor);

								ret = ov4c_20880_transform_bayer_raw10((unsigned short*)threadshareData.pucRaw2, (unsigned short*)pucTempBaylor, &roi_para);
								if(ret != 0)
								{
									b4Cell = false;
									emit information("ov4c_20880_transform_bayer_raw10 return: " % QString::number(ret));
									// release library
									ov4c_release();
								}
								else
								{
									if(threadshareData.ucInterpolation == 1)
									{
										threadshareData.raw2lock.lockForRead();
										classAlgorithm.HisCCMBarlor2RGB24(pucTempBaylor, threadshareData.pucRGB1, threadshareData.uiWidth, \
											threadshareData.uiHeight & 0xFFFFFFFE, threadshareData.ucFormat, threadshareData.ucInterpolation);
										threadshareData.raw2lock.unlock();
									}
									else
									{
										if(pucRaw8 == NULL){
											pucRaw8	=	(unsigned char*)_aligned_malloc(threadshareData.uiWidth*threadshareData.uiHeight, _HisCacheLine_Aligned);
											if(pucRaw8 == NULL){
												emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：申请内存。无法生成RGB图片"));
												break;
											}
										}
										threadshareData.raw2lock.lockForRead();
										classAlgorithm.raw10toraw8((unsigned short*)(pucTempBaylor), pucRaw8, threadshareData.uiWidth & 0xFFFFFFFE, threadshareData.uiHeight);
										threadshareData.raw2lock.unlock();
										classAlgorithm.HisCCMBarlor2RGB24(pucRaw8, threadshareData.pucRGB1, threadshareData.uiWidth & 0xFFFFFFFE, \
											threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
									}
								}

								memcpy(threadshareData.pucRGB1 + 5120 *3840 *3, threadshareData.pucRGB1 + 5120 *3839 *3, 5120 *3);

								// release library
								ov4c_release();
							}
						}
					}
					else
					{
						b4Cell = false;
						emit information(tr("Load OV20880 4cell conversion function fail"));
					}
#endif
				}
				else
				{
					b4Cell	=	false;
				}

				if(!b4Cell)
				{
					if(threadshareData.ucInterpolation == 1)
					{
						threadshareData.raw2lock.lockForRead();
						classAlgorithm.HisCCMBarlor2RGB24(threadshareData.pucRaw2, threadshareData.pucRGB1, threadshareData.uiWidth, \
							threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
						threadshareData.raw2lock.unlock();
					}
					else
					{
						if(pucRaw8 == NULL){
							pucRaw8	=	(unsigned char*)_aligned_malloc(threadshareData.uiWidth*threadshareData.uiHeight, _HisCacheLine_Aligned);
							if(pucRaw8 == NULL){
								emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：申请内存。无法生成RGB图片"));
								break;
							}
						}
						threadshareData.raw2lock.lockForRead();
						classAlgorithm.raw10toraw8((unsigned short*)(threadshareData.pucRaw2), pucRaw8, threadshareData.uiWidth, threadshareData.uiHeight);
						threadshareData.raw2lock.unlock();
						classAlgorithm.HisCCMBarlor2RGB24(pucRaw8, threadshareData.pucRGB1, threadshareData.uiWidth, \
							threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
					}
				}			
			}
			break;
		case HisBaylor12_BGGR:
		case HisBaylor12_RGGB:
		case HisBaylor12_GRBG:
		case HisBaylor12_GBRG:
			if(threadshareData.ucInterpolation == 1)
			{
				threadshareData.raw2lock.lockForRead();
				classAlgorithm.HisCCMBarlor2RGB24(threadshareData.pucRaw2, threadshareData.pucRGB1, threadshareData.uiWidth, \
					threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
				threadshareData.raw2lock.unlock();
			}
			else
			{
				if(pucRaw8 == NULL){
					pucRaw8	=	(unsigned char*)_aligned_malloc(threadshareData.uiWidth*threadshareData.uiHeight, _HisCacheLine_Aligned);
					if(pucRaw8 == NULL){
						emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：申请内存。无法生成RGB图片"));
						break;
					}
				}
				threadshareData.raw2lock.lockForRead();
				classAlgorithm.raw12toraw8((unsigned short*)(threadshareData.pucRaw2), pucRaw8, threadshareData.uiWidth, threadshareData.uiHeight);
				threadshareData.raw2lock.unlock();
				classAlgorithm.HisCCMBarlor2RGB24(pucRaw8, threadshareData.pucRGB1, threadshareData.uiWidth, \
					threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
			}
			break;
		case HisBaylor10_MONO:
			{
				threadshareData.raw2lock.lockForRead();
				unsigned short* pusSrc = (unsigned short*)threadshareData.pucRaw2;
				unsigned char* pucDes	=	threadshareData.pucRGB1;
				unsigned int uiP	=	threadshareData.uiHeight *threadshareData.uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = ((*pusSrc >>2) & 0xFF);
					pucDes += 3;
					++pusSrc;
				}
				threadshareData.raw2lock.unlock();
			}
			break;
		case HisBaylor12_MONO:
			{
				threadshareData.raw2lock.lockForRead();
				unsigned short* pusSrc = (unsigned short*)threadshareData.pucRaw2;
				unsigned char* pucDes	=	threadshareData.pucRGB1;
				unsigned int uiP	=	threadshareData.uiHeight *threadshareData.uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = ((*pusSrc >>4) & 0xFF);
					pucDes += 3;
					++pusSrc;
				}
				threadshareData.raw2lock.unlock();
			}
			break;
		case HisYUV8_422_YUYV:
		case HisYUV8_422_UYVY:
		case HisYUV8_422_YVYU:
		case HisYUV8_422_VYUY:
			threadshareData.raw2lock.lockForRead();
			if(threadshareData.bGrayImage)
			{
				unsigned char* pucSrc	=	threadshareData.pucRaw2, *pucDes = threadshareData.pucRGB1;
				if((threadshareData.ucFormat == HisYUV8_422_UYVY) || (threadshareData.ucFormat == HisYUV8_422_VYUY)) ++pucSrc;
				unsigned int uiPixel = threadshareData.uiWidth *threadshareData.uiHeight;
				for(unsigned int x=0;	x<uiPixel; ++x)
				{
					*(pucDes+2) = *(pucDes+1) = *pucDes =*pucSrc;
					pucDes += 3;
					pucSrc+=2;
				}
			}
			else
			{			
				classAlgorithm.HisCCMYUV2RGB24(threadshareData.pucRaw2, threadshareData.pucRGB1, threadshareData.uiWidth, \
					threadshareData.uiHeight, threadshareData.ucFormat/*, _HisFX3_YUVCVTRGB_BT709*/);
			}
			threadshareData.raw2lock.unlock();
			break;
		case HisRGB_RGB24:
			threadshareData.raw2lock.lockForRead();
			classAlgorithm.copyframebuffer(threadshareData.pucRaw2, threadshareData.pucRGB1, threadshareData.uiWidth *threadshareData.uiHeight *3);
			threadshareData.raw2lock.unlock();
			break;
		case HisBaylor8_MONO:
			{
				threadshareData.raw2lock.lockForRead();
				unsigned char* pucDes	=	threadshareData.pucRGB1, *pucSrc = threadshareData.pucRaw2;
				unsigned int uiP	=	threadshareData.uiHeight *threadshareData.uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = *pucSrc++;
					pucDes += 3;
				}
				threadshareData.raw2lock.unlock();
			}
			break;
		case HisBaylor8_BGGR:
		case HisBaylor8_RGGB:
		case HisBaylor8_GRBG:
		case HisBaylor8_GBRG:
		default:
			threadshareData.raw2lock.lockForRead();
			classAlgorithm.HisCCMBarlor2RGB24(threadshareData.pucRaw2, threadshareData.pucRGB1, threadshareData.uiWidth, \
				threadshareData.uiHeight, threadshareData.ucFormat, threadshareData.ucInterpolation);
			threadshareData.raw2lock.unlock();
			break;
		}

#endif

		/**********************improve rgb1********************/
		/**********************************************************/

		if(!threadshareData.rgb2lock.tryLockForWrite(1000))
		{
			emit information(QTextCodec::codecForName( "GBK")->toUnicode("无法实现数据交换RGB24"));
			if(!threadshareData.GetHisPreviewflag())
				break;
			else
				continue;
		}

		pucExchange							=	threadshareData.pucRGB1;
		threadshareData.pucRGB1	=	threadshareData.pucRGB2;
		threadshareData.pucRGB2	=	pucExchange;
		threadshareData.rgb2lock.unlock();

		threadshareData.flaglock.lockForWrite();
		threadshareData.ui64RGB2Index	=ui64PreIndex=	ui64TheIndex;
		threadshareData.flaglock.unlock();
	}

	threadshareData.flaglock.lockForWrite();
	threadshareData.brgbrun	=	false;
	threadshareData.flaglock.unlock();

	HisReleaseMalloc(pucRaw8);
}


HisFX3CCMTest::HisFX3CCMTest(QWidget *parent, Qt::WFlags flags,bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, \
	_globalFunctionPointer& globalFunPointerC,bool bLogin)
	: QMainWindow(parent, flags), bBoxChannel1(bChannel1), threadshareData(threadshareDataC), itemshareData(itemshareDataC), globalFunPointer(globalFunPointerC), \
	b2ndClick(false),wids(new jsl_bindSerialNumber),m_sock(NULL)
{
	QThread::currentThread()->setPriority(QThread::NormalPriority);
	ui.setupUi(this);
	ui.imageframe->threadshareData	=	&threadshareData;
	ui.imageframe->itemshareData		=	&itemshareData;


	

#if !(defined USE_EQUIPMENT_GB_AFBURN) && !(defined USE_EQUIPMENT_GB_PDAF) && !(defined USE_EQUIPMENT_GB_AFBURN) && \
	!(defined USE_EQUIPMENT_AFM_JSL_V1)&& !(defined USE_EQUIPMENT_AFM_JSL_V2)
	ui.COMlabel->setVisible(false);
#endif

	ui.COM2label->setVisible(false);

	setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
	setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

	setTabPosition(Qt::LeftDockWidgetArea, QTabWidget::North);
	setTabPosition(Qt::RightDockWidgetArea, QTabWidget::North);
	setTabPosition(Qt::TopDockWidgetArea, QTabWidget::West);
	setTabPosition(Qt::BottomDockWidgetArea, QTabWidget::West);

	getglobalParameter();
	createToolbar();

	drawproject();
	getManualModeAConfig();

	classButtonExec	=	new QHButtonExec(this);
	connect(classButtonExec->ui.seriallineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(serialNumtextChanged(const QString &)));
	connect(classButtonExec->ui.execpushButton, SIGNAL(released()), this, SLOT(ClickExecbutton()));
	connect(classButtonExec->ui.focusAdjustpushButton, SIGNAL(released()), this, SLOT(slotButtonFA()));
	connect(classButtonExec->ui.whitePanelpushButton, SIGNAL(released()), this, SLOT(slotButtonWhiteField()));
	connect(classButtonExec->ui.farFCpushButton, SIGNAL(released()), this, SLOT(slotButtonFarFC()));
	connect(classButtonExec->ui.nearFCpushButton, SIGNAL(released()), this, SLOT(slotButtonNearFC()));

	

	//********************** ADD 2017/12/11*********
	QHMainWindow *p_Parent=(QHMainWindow*)parent;
	p_Parent->getOperateModeConfig();
	
	//************************ 2017/12/11 ADD **********************
	if(hisglobalparameter.stOperatorMode.ucMode != 2&&bChannel1){ //slave mode
		jsl_loginDialog dlgLogin;
		dlgLogin.exec();
	}
	//**************************************************************

		

	//**********************************************
	

	classInfoPanel	=	new QHInfoPanel();
	classInfoPanel->hisglobalparameter	=	&hisglobalparameter;

	classStatisPanel	=	new QHStatisPanel(this, bChannel1, threadshareData,itemshareData);

	classTextPanel	=	new QHTextInfoPanel(this, bBoxChannel1, &(hisglobalparameter.bSaveTextInfo2Local));
	connect(this, SIGNAL(information(QString)), classTextPanel, SLOT(ShowInformation(QString)));
	connect(classTextPanel->ui.listinfowidge,  SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(TextInfoDoubleClicked(QListWidgetItem*)));
	
	classDrawTestItem	=	new QHDrawTEstItem(itemshareData,false, this);
	
	restoreUI();

// 	qDebug() << "opModeSwitch_UI" << hisglobalparameter.stOperatorMode.ucMode;
// 
// 	opModeSwitch_UI(hisglobalparameter.stOperatorMode.ucMode);
	
	getmacAddress();
	ROPLOW::GetStatisticsFromDB(threadshareData.stStatisticsHistory, bBoxChannel1);

	connect(ui.configaction, SIGNAL(triggered()), this, SLOT(ShowConfigDialog()));
	connect(ui.enableOfflineaction, SIGNAL(triggered(bool)), this, SLOT(offlineModeSwitch(bool)));
	connect(ui.actionset_path,SIGNAL(triggered()),this,SLOT(offlineSetPath()));
	connect(ui.actionBlemish_C_Tuning, SIGNAL(triggered()), this, SLOT(slotBlemishTuningTool()));
	connect(ui.imageshowPolicycomboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotImageShowPolicyChange(int)));
	connect(ui.actionManual_Mode_A, SIGNAL(triggered()), this, SLOT(slotManualModeAConfig()));
	connect(ui.actionShow_Operation_Panel, SIGNAL(triggered()), this, SLOT(slotShowOperationPanel()));
	connect(ui.actionShow_Info_Panel, SIGNAL(triggered()), this, SLOT(slotShowInfoPanel()));
	connect(ui.actionShow_Statis_Panel, SIGNAL(triggered()), this, SLOT(slotShowStatisPanel()));
	connect(ui.actionShow_Text_Panel, SIGNAL(triggered()), this, SLOT(slotShowTextPanel()));
	connect(ui.actionShoactionShow_TestItem, SIGNAL(triggered()), this, SLOT(slotTestItem()));
	connect(ui.actionImage, SIGNAL(triggered()), this, SLOT(slotImageDebug()));
	connect(ui.actionJsv_to_csv,SIGNAL(triggered()),this,SLOT(slotJsvDecode()));

	if(!hisglobalparameter.bShowItem2EndResult)	ui.showItem2EndResultaction->setChecked(false);
	if(!hisglobalparameter.bShowResult2Image)	ui.showEndResult2Imageaction->setChecked(false);


	//create thread
	QThread* improverawthread = new QThread;
	improverawthread->setStackSize(131072);
	improveraw* improverawworker = new improveraw(bBoxChannel1, threadshareData, itemshareData, globalFunPointer);
	improverawworker->moveToThread(improverawthread);
	connect(improverawworker, SIGNAL(updatefps(float, float, float, unsigned int)), this, SLOT(updatefps(float, float, float, unsigned int)));
	connect(improverawworker, SIGNAL(finished()), improverawthread, SLOT(quit()));
	connect(improverawworker, SIGNAL(finished()), improverawworker, SLOT(deleteLater()));
	connect(improverawthread, SIGNAL(finished()), improverawthread, SLOT(deleteLater()));
	connect(this, SIGNAL(finish()), improverawworker, SLOT(finish()));
	connect(improverawworker, SIGNAL(information(QString)), classTextPanel, SLOT(ShowInformation(QString)));
	improverawthread->start(QThread::HighPriority);

	QThread* improvergb24thread = new QThread;
	improvergb24thread->setStackSize(131072);
	improvergb24* improvergb24worker = new improvergb24(bBoxChannel1, threadshareData, itemshareData);
	improvergb24worker->moveToThread(improvergb24thread);
	connect(improvergb24worker, SIGNAL(finished()), improvergb24thread, SLOT(quit()));
	connect(improvergb24worker, SIGNAL(finished()), improvergb24worker, SLOT(deleteLater()));
	connect(improvergb24thread, SIGNAL(finished()), improvergb24thread, SLOT(deleteLater()));
	connect(this, SIGNAL(finish()), improvergb24worker, SLOT(finish()));
	connect(improvergb24worker, SIGNAL(information(QString)), classTextPanel, SLOT(ShowInformation(QString)));
	improvergb24thread->start(QThread::HighPriority);

	QThread* renderframethread = new QThread;
	renderframethread->setStackSize(131072);
	renderframe* renderframeworker = new renderframe(bBoxChannel1, threadshareData, itemshareData, *ui.imageframe, *ui.horizontalScrollBar, *ui.verticalScrollBar);
	renderframeworker->moveToThread(renderframethread);
	connect(renderframeworker, SIGNAL(updatefps(float, float, float, unsigned int)), this, SLOT(updatefps(float, float, float, unsigned int)));
	connect(renderframeworker, SIGNAL(drawframe(int)), ui.imageframe, SLOT(DrawFrame(int)));
	connect(renderframeworker, SIGNAL(finished()), renderframethread, SLOT(quit()));
	connect(renderframeworker, SIGNAL(finished()), renderframeworker, SLOT(deleteLater()));
	connect(renderframethread, SIGNAL(finished()), renderframethread, SLOT(deleteLater()));
	connect(this, SIGNAL(finish()), renderframeworker, SLOT(finish()));
	connect(renderframeworker, SIGNAL(information(QString)), classTextPanel, SLOT(ShowInformation(QString)));
	renderframethread->start(QThread::NormalPriority);

	QThread* itemprocessthread = new QThread;
	itemprocessthread->setStackSize(5242880);
	itemprocessworker = new itemprocess(bBoxChannel1, threadshareData, itemshareData, globalFunPointer, *ui.imageframe, \
		*ui.horizontalScrollBar, *ui.verticalScrollBar, *classButtonExec->ui.seriallineEdit,this);

	//******************************** 2017/12/11 ***************
	//QHMainWindow *p_Parent=(QHMainWindow*)parent;
	//p_Parent->getOperateModeConfig();
	connect(itemprocessworker,SIGNAL(sig_serialnumberbind(QString)),this,SLOT(showBindWid(QString)));
	connect(itemprocessworker,SIGNAL(sig_messtatusupdate(QString,QString)),this,SLOT(updateSN(QString,QString)));

	if(bLogin&&bChannel1){
		burnState=new jsl_burnState(hisglobalparameter.stOperatorMode.ucMode,this);
		burnState->slotBurnCount();
	}else{
		burnState=new jsl_burnState(2,this);
	}

	burnState->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
	
	if(hisglobalparameter.stOperatorMode.ucMode == 2)
		burnState->setVisible(false);
	addDockWidget(Qt::BottomDockWidgetArea,burnState);
	
	connect(itemprocessworker,SIGNAL(sigCountToPanel(QStringList,QStringList)),burnState,SLOT(slot_ToPanel(QStringList,QStringList)));
	connect(itemprocessworker,SIGNAL(sigBurnCount()),burnState,SLOT(slotBurnCount()));
	//************************************************************

	itemprocessworker->moveToThread(itemprocessthread);
	connect(itemprocessworker, SIGNAL(finished()), itemprocessthread, SLOT(quit()));
	connect(itemprocessworker, SIGNAL(finished()), itemprocessworker, SLOT(deleteLater()));
	connect(itemprocessthread, SIGNAL(finished()), itemprocessthread, SLOT(deleteLater()));
	connect(itemprocessworker, SIGNAL(enablebutton(bool)), this, SLOT(enablebutton(bool)));
	connect(itemprocessworker, SIGNAL(updateresult()), classDrawTestItem, SLOT(drawitem()));
	connect(itemprocessworker, SIGNAL(startpreview()), improverawworker, SLOT(startpreview()));
	connect(itemprocessworker, SIGNAL(startpreview()), renderframeworker, SLOT(startpreview()));
	connect(itemprocessworker, SIGNAL(startpreview()), improvergb24worker, SLOT(startpreview()));
	connect(itemprocessworker, SIGNAL(showresult(int)), this, SLOT(showEndresult(int)));
	connect(itemprocessworker, SIGNAL(signalshowitem2endresult(unsigned short, unsigned char, unsigned int)), this, SLOT(showItemStatus2EndResult(unsigned short, unsigned char, unsigned int)));
	connect(itemprocessworker, SIGNAL(plotpainter(unsigned int)), this, SLOT(painterplot(unsigned int)));
	connect(itemprocessworker, SIGNAL(enableinfotimer(unsigned int)), this, SLOT(enableinfotimer(unsigned int)));
	connect(itemprocessworker, SIGNAL(execsaveimage(QString, QString, unsigned char, unsigned char)), this, SLOT(execsaveimage(QString, QString, unsigned char, unsigned char)));
	connect(itemprocessworker, SIGNAL(signaldrawframe(int)), ui.imageframe, SLOT(DrawFrame(int)));
	connect(itemprocessworker, SIGNAL(drawTactistics()), classStatisPanel, SLOT(drawStatisticsImage()));
	
	connect(itemprocessworker, SIGNAL(information(QString)), classTextPanel, SLOT(ShowInformation(QString)));
	connect(itemprocessworker, SIGNAL(signalDrawAnotherSingle(QImage, unsigned int)), ui.imageframe, SLOT(slotDrawAnotherSingle(QImage, unsigned int)));
	connect(itemprocessworker, SIGNAL(signalBackToNormalMode()), ui.imageframe, SLOT(backToNormalMode()));
	connect(itemprocessworker, SIGNAL(signalTotalTestTime(unsigned int)), classDrawTestItem, SLOT(slotTotalTestTime(unsigned int)));
	connect(itemprocessworker, SIGNAL(signalMessageBox(int)), this, SLOT(slotMessageBox(int)));
	connect(this, SIGNAL(keyshortcutPress(char, unsigned char)), itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));
	itemprocessworker->getccmhardwareParameter(false);
	connect(this, SIGNAL(finish()), itemprocessworker, SLOT(finish()));
	itemprocessthread->start(QThread::HighestPriority);

	wheelvcmTimer.setSingleShot(false);
	wheelvcmTimer.setInterval(200);
	if(wheelvcmTimer.isActive())	wheelvcmTimer.stop();
	connect(&wheelvcmTimer, SIGNAL(timeout()), this, SLOT(slotWheelVCMTimer()));

	luxmonitorTimer.setSingleShot(false);
	if(luxmonitorTimer.isActive())	luxmonitorTimer.stop();
	connect(&luxmonitorTimer, SIGNAL(timeout()), this, SLOT(calculateLuxMonitor()));
	connect(itemprocessworker, SIGNAL(signalopenoffline(bool)), this, SLOT(slotoffline(bool)));
	connect(itemprocessworker, SIGNAL(signalopenofflineb(bool)), this, SLOT(slotofflineb(bool)));
// 	connect(ui.imagelabel, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuRequested(QPoint)));

	int iresult = 0;


	this->setFocus();

	slotImageShowPolicyChange(threadshareData.stImageShowPolicy.ucMode);

	QTimer::singleShot(5, classStatisPanel, SLOT(drawStatisticsImage()));
	//if(hisglobalparameter.stOperatorMode.ucMode == 2)
	//	QTimer::singleShot(20, this, SLOT(slotTcpConnect()));
	getofflineflag();
	getofflineparamater();

	if (threadshareData.bOfflineMode)
	{
		ui.enableOfflineaction->setChecked(true);
		threadshareData.bOfflineMode	=	true;
		offlineModeSwitch(true);
	}
}

HisFX3CCMTest::~HisFX3CCMTest()
{	

}

void HisFX3CCMTest::keyPressEvent(QKeyEvent* event)
{
// 	int key	=	event->key();
// 	emit information("HisFX3CCMTest  keyPressEvent:" % QString::number(key));
// 	QMainWindow::keyPressEvent(event);
// 	return;

	threadshareData.flaglock.lockForRead();
	_imageShowPolicy stImageShowPolicy = threadshareData.stImageShowPolicy;
	threadshareData.flaglock.unlock();

	int key	=	event->key();

	if(stImageShowPolicy.ucMode == 1 && hisglobalparameter.ucSodokuMode == 0 && key >= Qt::Key_1 && key <= Qt::Key_9){
		threadshareData.flaglock.lockForWrite();
		threadshareData.stImageShowPolicy.ucSodokuPos = key - Qt::Key_0;
		threadshareData.flaglock.unlock();
	}
	else if(key >= Qt::Key_Left && key <= Qt::Key_Down && stImageShowPolicy.ucMode == 1 && hisglobalparameter.ucSodokuMode == 1){
		switch (stImageShowPolicy.ucSodokuPos){
		case 7: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	4;
			break;
		case 8: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	7;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	9;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	5;
			break;
		case 9: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	6;
			break;
		case 4: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	5;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	7;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	1;
			break;
		case 5: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	4;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	6;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	8;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	2;
			break;
		case 6: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	5;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	9;
			else if(key == Qt::Key_Down) stImageShowPolicy.ucSodokuPos	=	3;
			break;
		case 1: 
			if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	2;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	4;
			break;
		case 2: 
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	1;
			else if(key == Qt::Key_Right) stImageShowPolicy.ucSodokuPos	=	3;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	5;
			break;
		default:
			if(key == Qt::Key_Left) stImageShowPolicy.ucSodokuPos	=	2;
			else if(key == Qt::Key_Up) stImageShowPolicy.ucSodokuPos	=	6;
			break;
		}
		threadshareData.flaglock.lockForWrite();
		threadshareData.stImageShowPolicy.ucSodokuPos = stImageShowPolicy.ucSodokuPos;
		threadshareData.flaglock.unlock();
	}

	QMainWindow::keyPressEvent(event);
}


void HisFX3CCMTest::close()
{
	emit finish();
}

void HisFX3CCMTest::resizeEvent (QResizeEvent * event)
{
/*
	bool bPreview = threadshareData.GetHisPreviewflag();

	switch (ui.imageshowPolicycomboBox->currentIndex())
	{
	case 2: //1.0X
		if(threadshareData.GetHisPreviewflag())
		{
			ui.horizontalScrollBar->setValue(0);
			ui.verticalScrollBar->setValue(0);
			ui.horizontalScrollBar->setMaximum(itemshareData.previewParameter->iWidth - ui.imageframe->width());
			ui.verticalScrollBar->setMaximum(itemshareData.previewParameter->iHeight - ui.imageframe->height());
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	case 3: //2.0X
		if(threadshareData.GetHisPreviewflag())
		{
			ui.horizontalScrollBar->setValue(0);
			ui.verticalScrollBar->setValue(0);
			ui.horizontalScrollBar->setMaximum((itemshareData.previewParameter->iWidth <<1) - ui.imageframe->width());
			ui.verticalScrollBar->setMaximum((itemshareData.previewParameter->iHeight <<1) - ui.imageframe->height());
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	case 4: //4.0X
		if(threadshareData.GetHisPreviewflag())
		{
			ui.horizontalScrollBar->setValue(0);
			ui.verticalScrollBar->setValue(0);
			ui.horizontalScrollBar->setMaximum((itemshareData.previewParameter->iWidth <<2) - ui.imageframe->width());
			ui.verticalScrollBar->setMaximum((itemshareData.previewParameter->iHeight <<2) - ui.imageframe->height());
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	default:
		break;
	}
*/

	QMainWindow::resizeEvent(event);
}

void HisFX3CCMTest::wheelEvent (QWheelEvent * event )
{
	int ix	=	event->x()	-	mainToolBar->size().width();
	int iy	=	event->y()	-	ui.menuBar->size().height();
	ix		=	max(ix, 0);
	iy		=	max(iy, 0);
	bool bIsIn	=	false;
	if(ix > ui.imageframe->x() && ix < ui.imageframe->x() + ui.imageframe->size().width() && \
		iy > ui.imageframe->y() && iy < ui.imageframe->y() + ui.imageframe->size().height())
		bIsIn	=	true;
	if(!bIsIn) {
		QMainWindow::wheelEvent(event);
		return;
	}

	if(threadshareData.GetHisPreviewflag())
	{
		itemshareData.itemparameterLock.lockForWrite();
		if(!itemshareData.ccmhardwareParameter->motortype.isEmpty() && \
			QString::compare(itemshareData.ccmhardwareParameter->motortype, "no", Qt::CaseInsensitive) != 0){
				int iDec	=	(event->buttons() == Qt::MidButton)?(3):(1);
				itemshareData.iWheelPosition	=	(event->delta() > 0)?(itemshareData.iWheelPosition+iDec):(itemshareData.iWheelPosition-iDec);
				if(!wheelvcmTimer.isActive()) wheelvcmTimer.start();
		}
		itemshareData.itemparameterLock.unlock();
	}

	QMainWindow::wheelEvent(event);
}

void HisFX3CCMTest::mouseDoubleClickEvent(QMouseEvent * event)
{
	int ix	=	event->x()	-	mainToolBar->size().width();
	int iy	=	event->y()	-	ui.menuBar->size().height();
	ix		=	max(ix, 0);
	iy		=	max(iy, 0);
	bool bIsIn	=	false;
// 	emit information("x: " % QString::number(ix)% "   y:" % QString::number(iy));
// 	emit information("lable x: " % QString::number(ui.imagelabel->x()) % "  label y:" %  QString::number(ui.imagelabel->y())); 
	if(ix > ui.imageframe->x() && ix < ui.imageframe->x() + ui.imageframe->size().width() && \
		iy > ui.imageframe->y() && iy < ui.imageframe->y() + ui.imageframe->size().height())
		bIsIn	=	true;
	if(!bIsIn)	{
// 		emit information("out");
		QMainWindow::mouseDoubleClickEvent(event);
		return;
	}

// 	emit information("in");

	if(hisglobalparameter.getfaflag()){
		hisglobalparameter.setfaflag(false);
		::Sleep(180);
	}

	if(!classPlatform.HisFX3isopen()){
		emit information(tr("The Grabber Has Not Been Opened Yet, Please Open First."));
		return;
	}

	if(!itemshareData.shortcutgather.size())
	{
		int iresult	=	HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareData.currentTableName, itemshareData.shortcutgather, bBoxChannel1);
		if(iresult){
			emit information("Get shortcut config fail: 0x" % QString::number(iresult, 16));
			return;
		}
		HISCCMSHORTCUT::setShortcutSync(itemshareData.shortcutgather);
	}

	char key = (bBoxChannel1)?('~'):(';');
	HISCCMSHORTCUT::eraseKeyItem(itemshareData.shortcutgather, key);

	QStringList listName, listValue;
	_shoutCutDetail stShortCutItem;
	stShortCutItem.bDualCamera = (classPlatform.getCameraCountSupported() == 2);
	
	if(threadshareData.GetHisPreviewflag()){
		stShortCutItem.shortcutKey	=	key;
		stShortCutItem.ucClickTime	=	1;
		stShortCutItem.usItem		=	stoppreviewitem;
		stShortCutItem.ucloopTime	=	1;
		stShortCutItem.ucItemIndex	=	1;
		stShortCutItem.usItemfail	=	0;
		itemshareData.shortcutgather.push_back(stShortCutItem);

		stShortCutItem.shortcutKey	=	key;
		stShortCutItem.ucClickTime	=	1;
		stShortCutItem.usItem		=	showresultitem;
		stShortCutItem.ucloopTime	=	1;
		stShortCutItem.ucItemIndex	=	2;
		stShortCutItem.usItemfail	=	0;
		listName.append("notsavelog");
		listValue.append((hisglobalparameter.stOperatorMode.ucMode == 1 && !hisglobalparameter.stOperatorMode.bSaveLog)?("true"):("false"));
		listName.append("notshowtotalresult");
		listValue.append((hisglobalparameter.stOperatorMode.ucMode == 1 && !hisglobalparameter.stOperatorMode.bShowTotalResult)?("true"):("false"));
		ROPLOW::jointconfigstring(stShortCutItem.strAddInfo, listName, listValue);
		itemshareData.shortcutgather.push_back(stShortCutItem);
	}
	else{
		stShortCutItem.shortcutKey	=	key;
		stShortCutItem.ucClickTime	=	1;
		stShortCutItem.usItem		=	clearresultitem;
		stShortCutItem.ucloopTime	=	1;
		stShortCutItem.ucItemIndex	=	1;
		stShortCutItem.usItemfail		=	0;
		itemshareData.shortcutgather.push_back(stShortCutItem);

		stShortCutItem.shortcutKey	=	key;
		stShortCutItem.ucClickTime	=	1;
		stShortCutItem.usItem		=	startpreviewitem;
		stShortCutItem.ucloopTime	=	1;
		stShortCutItem.ucItemIndex	=	2;
		stShortCutItem.usItemfail	=	0;
		itemshareData.shortcutgather.push_back(stShortCutItem);

		stShortCutItem.shortcutKey	=	key;
		stShortCutItem.ucClickTime	=	1;
		stShortCutItem.usItem		=	getserialnumberitem;
		stShortCutItem.ucloopTime	=	1;
		stShortCutItem.ucItemIndex	=	3;
		stShortCutItem.usItemfail	=	0;
		itemshareData.shortcutgather.push_back(stShortCutItem);
	}

	emit keyshortcutPress(key, 1);

	QMainWindow::mouseDoubleClickEvent(event);
}

void HisFX3CCMTest::restoreUI()
{
	QByteArray geometry, windowState;
	bool bConfig = false;

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplateui");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			return;

		QSqlQuery query(templatedb);
		if(bBoxChannel1)
			query.prepare("SELECT geometry,windowState FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC1'" );
		else
			query.prepare("SELECT geometry,windowState FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC2'" );
		query.exec();


		while (query.next()){
			bConfig = true;
			geometry				= query.value(0).toByteArray();
			windowState		= query.value(1).toByteArray();
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplateui");

	if(bConfig){
		restoreGeometry(geometry);
		restoreState(windowState);
	}
	else{
		addDockWidget(Qt::RightDockWidgetArea, classButtonExec);
		splitDockWidget(classButtonExec, classInfoPanel, Qt::Vertical);
		tabifyDockWidget(classInfoPanel, classStatisPanel);
		addDockWidget(Qt::LeftDockWidgetArea, classDrawTestItem);
		addDockWidget(Qt::BottomDockWidgetArea, classTextPanel);
		
	}

}


void HisFX3CCMTest::customMenuRequested(QPoint pos)
{
	// 	if(!GetHisPreviewflag())
	// 		return;
	mouse_ptx	=	static_cast<double>(pos.x()) / static_cast<double>(ui.imageframe->size().width());
	mouse_pty	=	static_cast<double>(pos.y()) / static_cast<double>(ui.imageframe->size().height());
	QMenu menu(this);

	QAction* addAct	=	new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&添加调试信息"), this);
	connect(addAct, SIGNAL(triggered()), this, SLOT(adddebugpoint()));
	menu.addAction(addAct);

	addAct	=	new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&移除调试信息"), this);
	connect(addAct, SIGNAL(triggered()), this, SLOT(removedebugpoint()));
	menu.addAction(addAct);

	menu.exec(QCursor::pos());
}
void HisFX3CCMTest::offlineSetPath()
{
	if(!HISGLOBALUI::isUnlocked()) return;
	getofflineparamater();

	QHofflinePath* classoffline	=	new QHofflinePath(this, itemshareData.currentTableName,itemshareData.offlinepath,itemshareData.breadsamepicture);
	//emit information(QString::number(itemshareData.breadsamepicture == true? 1:0));
	if(classoffline->exec() == QDialog::Accepted)

		itemshareData.offlinepath	=	classoffline->Qfilename;
	itemshareData.breadsamepicture	=	classoffline->bReadsamepicture;
	bool bIs	=	(itemshareData.offlinepath.size() < 5)?(false):(true);
	if(bIs)
	{
		if(itemshareData.offlinepath.contains(".jpg", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".jpeg", Qt::CaseInsensitive) || \
			itemshareData.offlinepath.contains(".png", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".tiff", Qt::CaseInsensitive)){
				QImage classImage(itemshareData.offlinepath);
				int iIndex	=	itemshareData.offlinepath.lastIndexOf(".");
				QString strNewFileName = itemshareData.offlinepath.left(iIndex) % ".bmp";
				classImage.save(strNewFileName, 0, 100);
				itemshareData.offlinepath = strNewFileName;
		}


		wchar_t wstrPath[256];
		itemshareData.offlinepath.toWCharArray(wstrPath);
		wstrPath[itemshareData.offlinepath.size()]	=	L'\0';
		int iresult	=	classPlatform.HisFX3SetOffLineMode(true, itemshareData.offlinepath.toLatin1().data());
		if(iresult){
			bIs	=	false;
			QMessageBox::warning(this, "ERROR", QString(classPlatform.GetLastError()));
			emit information(QString(classPlatform.GetLastError()));
		}
	}

}
void HisFX3CCMTest::slotofflineb(bool bChecked)
{
	if(!bChecked)
	{
		threadshareData.bOfflineMode	=	false;
		classPlatform.HisFX3SetOffLineMode(false, NULL);
		itemshareData.itemparameterLock.lockForWrite();
		if (itemshareData.previewParameter){
			HisReleaseNewB(itemshareData.previewParameter->pusType);
			HisReleaseNewB(itemshareData.previewParameter->pui64Data);
			HisReleaseNewB(itemshareData.previewParameter->puiReg);
			HisReleaseNewB(itemshareData.previewParameter->pucSlave);
			HisReleaseNewO(itemshareData.previewParameter);
		}
		itemshareData.itemparameterLock.unlock();
		return;
	}

	ui.enableOfflineaction->setChecked(true);
	threadshareData.bOfflineMode	=	true;
	
	bool bIs	=	(itemshareData.offlinepath.size() < 5)?(false):(true);
	if(bIs)
	{
		itemshareData.flagLock.lockForWrite();
		itemshareData.ucOfflineloadimage	=2;
		itemshareData.flagLock.unlock();
		if(itemshareData.offlinepath.contains(".jpg", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".jpeg", Qt::CaseInsensitive) || \
			itemshareData.offlinepath.contains(".png", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".tiff", Qt::CaseInsensitive)){
				QImage classImage(itemshareData.offlinepath);
				int iIndex	=	itemshareData.offlinepath.lastIndexOf(".");
				QString strNewFileName = itemshareData.offlinepath.left(iIndex) % ".bmp";
				classImage.save(strNewFileName, 0, 100);
				itemshareData.offlinepath = strNewFileName;
		}
		char *strPath=itemshareData.offlinepath.toLatin1().data();
		//wstrPath[itemshareData.offlinepath.size()]	=	L'\0';
		int iresult;
		if(bBoxChannel1)
			iresult	=	classPlatform.HisFX3SetOffLineMode(true, strPath);
		else
			iresult	=	classPlatform.HisFX3SetOffLineMode_S2(true, strPath);
		if(iresult){
			bIs	=	false;
			QMessageBox::warning(this, "ERROR", QString(classPlatform.GetLastError()));
			emit information(QString(classPlatform.GetLastError()));
		}
		else
		{
			itemshareData.flagLock.lockForWrite();
			itemshareData.ucOfflineloadimage	=1;
			itemshareData.flagLock.unlock();
		}
	}
	else
	{
		itemshareData.flagLock.lockForWrite();
		itemshareData.ucOfflineloadimage	=2;
		itemshareData.flagLock.unlock();
	}

}
void HisFX3CCMTest::slotoffline(bool bChecked)
{
	if(!bChecked)
	{
		threadshareData.bOfflineMode	=	false;
		classPlatform.HisFX3SetOffLineMode(false, NULL);
		itemshareData.itemparameterLock.lockForWrite();
		if (itemshareData.previewParameter){
			HisReleaseNewB(itemshareData.previewParameter->pusType);
			HisReleaseNewB(itemshareData.previewParameter->pui64Data);
			HisReleaseNewB(itemshareData.previewParameter->puiReg);
			HisReleaseNewB(itemshareData.previewParameter->pucSlave);
			HisReleaseNewO(itemshareData.previewParameter);
		}
		itemshareData.itemparameterLock.unlock();
		return;
	}

	ui.enableOfflineaction->setChecked(true);
	threadshareData.bOfflineMode	=	true;
	if (itemshareData.offlinepath.isEmpty())
	{
		itemshareData.offlinepath = QFileDialog::getOpenFileName(this, "Open File", "/home", "Images (*.raw *.bmp *.jpg *.jpeg *.png)");
	} 
	else
	{
		itemshareData.offlinepath = QFileDialog::getOpenFileName(this, "Open File", itemshareData.offlinepath , "Images (*.raw *.bmp *.jpg *.jpeg *.png)");
	}


	bool bIs	=	(itemshareData.offlinepath.size() < 5)?(false):(true);
	if(bIs)
	{
		itemshareData.flagLock.lockForWrite();
		itemshareData.ucOfflineloadimage	=2;
		itemshareData.flagLock.unlock();
		if(itemshareData.offlinepath.contains(".jpg", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".jpeg", Qt::CaseInsensitive) || \
			itemshareData.offlinepath.contains(".png", Qt::CaseInsensitive) || itemshareData.offlinepath.contains(".tiff", Qt::CaseInsensitive)){
				QImage classImage(itemshareData.offlinepath);
				int iIndex	=	itemshareData.offlinepath.lastIndexOf(".");
				QString strNewFileName = itemshareData.offlinepath.left(iIndex) % ".bmp";
				classImage.save(strNewFileName, 0, 100);
				itemshareData.offlinepath = strNewFileName;
		}
		wchar_t wstrPath[256];
		//itemshareData.offlinepath.toWCharArray(wstrPath);
		//wstrPath[itemshareData.offlinepath.size()]	=	L'\0';
		int iresult;
		if(bBoxChannel1)
			iresult	=	classPlatform.HisFX3SetOffLineMode(true, itemshareData.offlinepath.toLatin1().data());
		else
			iresult	=	classPlatform.HisFX3SetOffLineMode_S2(true, itemshareData.offlinepath.toLatin1().data());
		if(iresult){
			bIs	=	false;
			QMessageBox::warning(this, "ERROR", QString(classPlatform.GetLastError()));
			emit information(QString(classPlatform.GetLastError()));
		}
		else
		{
			itemshareData.flagLock.lockForWrite();
			itemshareData.ucOfflineloadimage	=1;
			itemshareData.flagLock.unlock();
		}
	}
	else
	{
		itemshareData.flagLock.lockForWrite();
		itemshareData.ucOfflineloadimage	=2;
		itemshareData.flagLock.unlock();
	}

}
void HisFX3CCMTest::offlineModeSwitch(bool bChecked)
{
	saveofflineflag(bChecked);
	if(!bChecked){		
		threadshareData.bOfflineMode	=	false;
		if(bBoxChannel1)
			classPlatform.HisFX3SetOffLineMode(false, NULL);
		else
			classPlatform.HisFX3SetOffLineMode_S2(false, NULL);
		itemshareData.itemparameterLock.lockForWrite();
		if (itemshareData.previewParameter){
			HisReleaseNewB(itemshareData.previewParameter->pusType);
			HisReleaseNewB(itemshareData.previewParameter->pui64Data);
			HisReleaseNewB(itemshareData.previewParameter->puiReg);
			HisReleaseNewB(itemshareData.previewParameter->pucSlave);
			HisReleaseNewO(itemshareData.previewParameter);
		}
		itemshareData.itemparameterLock.unlock();
		return;
	}
	threadshareData.bOfflineMode	=	true;
}

void HisFX3CCMTest::slotImageShowPolicyChange(int index)
{
	bool bPreview = threadshareData.GetHisPreviewflag();

	threadshareData.flaglock.lockForWrite();
	threadshareData.stImageShowPolicy.ucMode = index;
	switch (threadshareData.stImageShowPolicy.ucMode)
	{
	case 0: //fit size
		ui.horizontalScrollBar->setVisible(false);
		ui.verticalScrollBar->setVisible(false);
		break;
	case 1: //sodoku
		ui.horizontalScrollBar->setVisible(false);
		ui.verticalScrollBar->setVisible(false);
		threadshareData.stImageShowPolicy.ucSodokuPos = 5; 
		break;
	case 2: //1.0X
		ui.horizontalScrollBar->setVisible(true);
		ui.verticalScrollBar->setVisible(true);
		if(bPreview)
		{
			ui.horizontalScrollBar->setMaximum(max((int)itemshareData.previewParameter->iWidth - ui.imageframe->width(), 0));
			ui.verticalScrollBar->setMaximum(max((int)itemshareData.previewParameter->iHeight - ui.imageframe->height(), 0));
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	case 3: //2.0X
		ui.horizontalScrollBar->setVisible(true);
		ui.verticalScrollBar->setVisible(true);
		if(bPreview)
		{
			ui.horizontalScrollBar->setMaximum(max((int)(itemshareData.previewParameter->iWidth <<1) - ui.imageframe->width(), 0));
			ui.verticalScrollBar->setMaximum(max((int)(itemshareData.previewParameter->iHeight <<1) - ui.imageframe->height(), 0));
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	default: //4.0X
		ui.horizontalScrollBar->setVisible(true);
		ui.verticalScrollBar->setVisible(true);
		if(bPreview)
		{
			ui.horizontalScrollBar->setMaximum(max((int)(itemshareData.previewParameter->iWidth <<2) - ui.imageframe->width(), 0));
			ui.verticalScrollBar->setMaximum(max((int)(itemshareData.previewParameter->iHeight <<2) - ui.imageframe->height(), 0));
			ui.horizontalScrollBar->setValue((ui.horizontalScrollBar->maximum() >>1));
			ui.verticalScrollBar->setValue((ui.verticalScrollBar->maximum() >>1));
		}
		break;
	}
	threadshareData.flaglock.unlock();
//	ui.imageframe->setFocus();
}

void HisFX3CCMTest::slotManualModeAConfig()
{
	if(itemshareData.currentTableName.isEmpty()){
		emit information(tr("Please Choose Config File First"));
		return;
	}

	if(!classPlatform.HisFX3isopen()){
		emit information(tr("The grabber has not been opened, please open the grabber first."));
		return;
	}

	if(!threadshareData.GetHisPreviewflag()){
		emit information(tr("The sensor is not previewing, please Start Preview first."));
		return;
	}

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32";
#endif

	RolongogetSensorAPIVersion getSensorAPIVersion = (RolongogetSensorAPIVersion)(strLibPath, "getSensorAPIVersion");
	RolongogetExposureTime getExposureTime = (RolongogetExposureTime)(QLibrary::resolve(strLibPath, "getExposureTime"));

	if(!(getSensorAPIVersion && getExposureTime)){
		emit information(tr("Resolve HisCCMOTP DLL Function Fail"));
		return;
	}

	unsigned int uivalue, uimin, uimax;
	int iresult;
	iresult	=	getExposureTime((itemshareData.ccmhardwareParameter->sensortype.toAscii()).data(), \
		itemshareData.previewParameter->ucSlave, uivalue, uimin, uimax, globalFunPointer.ReadHisFX3IIC, \
		globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		emit information(tr("Can not get the exposure time: 0x") % QString::number(iresult, 16));
// 		return;
	}

	QHManualModeA* classManualModeA	=	new QHManualModeA(this, bBoxChannel1, threadshareData, itemshareData, globalFunPointer);
	classManualModeA->setAttribute(Qt::WA_DeleteOnClose);
	classManualModeA->show();
	classManualModeA->raise();
	classManualModeA->activateWindow();
}

void HisFX3CCMTest::slotBlemishTuningTool()
{
	if(!HISGLOBALUI::isUnlocked()) return;

	if(!threadshareData.GetHisPreviewflag()){
		emit information(tr("Sensor has not previewed yet."));
		return;
	}	

	QHBlemishHC* classBlemishHC	=	new QHBlemishHC(this, bBoxChannel1, threadshareData, itemshareData, globalFunPointer);
	classBlemishHC->getConfig(itemshareData.currentTableName);

	itemshareData.itemparameterLock.lockForWrite();
	HisReleaseNewO(itemshareData.blemishParameter);
	itemshareData.itemparameterLock.unlock();

	classBlemishHC->setAttribute(Qt::WA_DeleteOnClose);
	classBlemishHC->show();
	classBlemishHC->raise();
	classBlemishHC->activateWindow();
}

void HisFX3CCMTest::slotImageDebug()
{
	if(!HISGLOBALUI::isUnlocked()) return;

	QHImageDebug* classImageDebug	=	new QHImageDebug(this, bBoxChannel1);

	classImageDebug->setAttribute(Qt::WA_DeleteOnClose);
	classImageDebug->show();
	classImageDebug->raise();
	classImageDebug->activateWindow();
}

void HisFX3CCMTest::slotTcpConnect()
{

}

void HisFX3CCMTest::TextInfoDoubleClicked(QListWidgetItem * item)
{
	if(hisglobalparameter.bDebugMode){
		QString strText	=	item->text();
		int iIndex	=	strText.indexOf("(ROI:");
		if(iIndex > 0){
			strText	=	strText.right(strText.size() - iIndex -5);
			iIndex	=	strText.indexOf(")");
			if(iIndex >=0){
				strText	=	strText.left(iIndex);
				if(strText.count(",") == 3){
					RECT stROI;
					iIndex				=	strText.indexOf(",");
					QString strTemp	=	strText.left(iIndex);
					strText				=	strText.right(strText.size() -iIndex -1);
					stROI.left			=	strTemp.toInt();
					iIndex				=	strText.indexOf(",");
					strTemp			=	strText.left(iIndex);
					strText				=	strText.right(strText.size() -iIndex -1);
					stROI.top			=	strTemp.toInt();
					iIndex				=	strText.indexOf(",");
					strTemp			=	strText.left(iIndex);
					strText				=	strText.right(strText.size() -iIndex -1);
					stROI.right		=	strTemp.toInt();
					stROI.bottom	=	strText.toInt();

					itemshareData.drawLock.lockForWrite();
					int ilastcount	=	itemshareData.itemdrawList.size();
					itemshareData.itemdrawList.resize(ilastcount + 1);
					std::vector<_itemDraw>::iterator theIterator	=	itemshareData.itemdrawList.begin() +ilastcount;
					theIterator->usitem								=	debugitem;
					theIterator->uctype								=	HisDrawType_Block;
					theIterator->stcolor								=	QColor::fromRgb(0,0,255);
					theIterator->strinfo.stblock					=	stROI;
					itemshareData.drawLock.unlock();
				}
			}
		}
	}
}

void HisFX3CCMTest::adddebugpoint()
{
	if(!threadshareData.GetHisPreviewflag() || threadshareData.stImageShowPolicy.ucMode == 0){
		hisglobalparameter.mouse_ptx	=	mouse_ptx;
		hisglobalparameter.mouse_pty	=	mouse_pty;
	}
	else{
		mouse_ptx	=	mouse_ptx * static_cast<double>(ui.imageframe->size().width());
		mouse_pty	=	mouse_pty * static_cast<double>(ui.imageframe->size().height());

		mouse_ptx	=	mouse_ptx + static_cast<double>(ui.horizontalScrollBar->value());
		mouse_pty	=	mouse_pty + static_cast<double>(ui.verticalScrollBar->value());

		mouse_ptx	=	mouse_ptx / static_cast<double>(itemshareData.previewParameter->iWidth);
		mouse_pty	=	mouse_pty / static_cast<double>(itemshareData.previewParameter->iHeight);

		hisglobalparameter.mouse_ptx	=	mouse_ptx;
		hisglobalparameter.mouse_pty	=	mouse_pty;
	}
}

void HisFX3CCMTest::removedebugpoint()
{
	hisglobalparameter.mouse_ptx	=	0.0;
	hisglobalparameter.mouse_pty	=	0.0;
}

void HisFX3CCMTest::ManualMultiButtonExec(unsigned int uiFlag) //0:FA 1:White Field 2:Near FC 3:Far FC
{
	if(hisglobalparameter.getfaflag()){
		if(uiFlag == 0) return;
		hisglobalparameter.setfaflag(false);
		::Sleep(200);
	}
	else if(threadshareData.GetHisTestingflag()){
		emit information(tr("Testing..."));
		return;
	}

	if(!itemshareData.shortcutgather.size())
	{
		int iresult	=	HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareData.currentTableName, itemshareData.shortcutgather, bBoxChannel1);
		if(iresult){
			emit information("Get shortcut config fail: 0x" % QString::number(iresult, 16));
			return;
		}
		HISCCMSHORTCUT::setShortcutSync(itemshareData.shortcutgather);
	}

	char key = (bBoxChannel1)?('~'):(';');
	HISCCMSHORTCUT::eraseKeyItem(itemshareData.shortcutgather, key);

	_shoutCutDetail stShortCutItem;
	stShortCutItem.shortcutKey	=	key;
	stShortCutItem.ucClickTime	=	1;
	stShortCutItem.ucloopTime	=	1;
	stShortCutItem.usItemfail		=	0;
	stShortCutItem.ucItemIndex	=	1;
	stShortCutItem.bDualCamera = (classPlatform.getCameraCountSupported() == 2);
	if(uiFlag == 0){ //FA
		if(itemshareData.stManualModeA.uiExposureValue_FA)
		{
			stShortCutItem.usItem	=	exposureitem;
			_scotherInfo otherInfo = {0};
			otherInfo.uidata[0]	=	itemshareData.stManualModeA.uiExposureValue_FA;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		switch (hisglobalparameter.stOperatorMode.ucChartType){
		case _HisCCMAlg_Rolongo_Chart_MTF_A: stShortCutItem.usItem = mtffaitem;  break;
		case _HisCCMAlg_Rolongo_Chart_SFR_A: stShortCutItem.usItem = sfrfacaitem;  break;
		default: stShortCutItem.usItem = lpmfaitem;  break;
		}
		stShortCutItem.strAddInfo.clear();
		itemshareData.shortcutgather.push_back(stShortCutItem);
	}
	else if(uiFlag == 1){ //White Field
		_scotherInfo otherInfo = {0};

		if(itemshareData.stManualModeA.uiExposureValue_WhiteField)
		{
			stShortCutItem.usItem	=	exposureitem;
			otherInfo.uidata[0]	=	itemshareData.stManualModeA.uiExposureValue_WhiteField;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;

			stShortCutItem.usItem	=	sleepitem;
			memset(&otherInfo,0, sizeof(_scotherInfo));
			otherInfo.idata[0]		=	itemshareData.stManualModeA.usDelay;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		stShortCutItem.usItem	=	imageprocessitem;
		memset(&otherInfo,0, sizeof(_scotherInfo));
		otherInfo.ucdata[0]		=	0xc0;
		globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
		itemshareData.shortcutgather.push_back(stShortCutItem);
		++stShortCutItem.ucItemIndex;

		if(itemshareData.stManualModeA.bBlemishON)
		{
			stShortCutItem.usItem = whitepanelitem_blemish;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bOCON)
		{
			stShortCutItem.usItem = whitepanelitem_oc;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bColorON)
		{
			stShortCutItem.usItem = whitepanelitem_color;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bDefectPixelON)
		{
			stShortCutItem.usItem = whitepanelitem_pixel;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bShadingON)
		{
			stShortCutItem.usItem = whitepanelitem_shading;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bVignetON)
		{
			stShortCutItem.usItem = whitepanelitem_vignetting;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		if(itemshareData.stManualModeA.bLineON)
		{
			stShortCutItem.usItem = whitepanelitem_line;
			stShortCutItem.strAddInfo.clear();
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}
	}
	else if(uiFlag == 2){ //Near FC
		_scotherInfo otherInfo = {0};
		if(itemshareData.stManualModeA.uiExposureValue_NearFC)
		{
			stShortCutItem.usItem	=	exposureitem;		
			otherInfo.uidata[0]	=	itemshareData.stManualModeA.uiExposureValue_NearFC;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;

			stShortCutItem.usItem	=	sleepitem;
			memset(&otherInfo,0, sizeof(_scotherInfo));
			otherInfo.idata[0]	=	itemshareData.stManualModeA.usDelay;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}

		switch (hisglobalparameter.stOperatorMode.ucChartType){
		case _HisCCMAlg_Rolongo_Chart_MTF_A: stShortCutItem.usItem = mtffcnearitem;  break;
		case _HisCCMAlg_Rolongo_Chart_SFR_A: stShortCutItem.usItem = sfrnearafcitem;  break;
		default: stShortCutItem.usItem = lpnearafcitem;  break;
		}
		memset(&otherInfo,0, sizeof(_scotherInfo));
		otherInfo.idata[0]	=	255;
		globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
		itemshareData.shortcutgather.push_back(stShortCutItem);
	}
	else if(uiFlag == 3){ //Far FC
		_scotherInfo otherInfo = {0};

		if(itemshareData.stManualModeA.uiExposureValue_FarFC)
		{
			stShortCutItem.usItem	=	exposureitem;
			otherInfo.uidata[0]	=	itemshareData.stManualModeA.uiExposureValue_FarFC;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;

			stShortCutItem.usItem	=	sleepitem;
			memset(&otherInfo,0, sizeof(_scotherInfo));
			otherInfo.idata[0]	=	itemshareData.stManualModeA.usDelay;
			globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
			itemshareData.shortcutgather.push_back(stShortCutItem);
			++stShortCutItem.ucItemIndex;
		}


		switch (hisglobalparameter.stOperatorMode.ucChartType){
		case _HisCCMAlg_Rolongo_Chart_MTF_A: stShortCutItem.usItem = mtffcinfiniteitem;  break;
		case _HisCCMAlg_Rolongo_Chart_SFR_A: stShortCutItem.usItem = sfrfarafcitem;  break;
		default: stShortCutItem.usItem = lpfarafcitem;  break;
		}
		memset(&otherInfo,0, sizeof(_scotherInfo));
		otherInfo.idata[0]	=	255;
		globalgetShortcutAddInfoString(stShortCutItem.usItem, stShortCutItem.strAddInfo, otherInfo);
		itemshareData.shortcutgather.push_back(stShortCutItem);
	}

	emit keyshortcutPress(key, 1);
}

void HisFX3CCMTest::ClickExecbutton()
{

	if(threadshareData.GetHisTestingflag()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("正在测试或调试中......"));
		return;
	}

	if(hisglobalparameter.getfaflag())
	{
		hisglobalparameter.setfaflag(false);
		::Sleep(200);
// 		bool b2tClick	=	b2ndClick;
//  		b2ndClick	=	!b2ndClick;
//  		if(b2tClick)
//  			ui.execpushButton->setText(QTextCodec::codecForName( "GBK")->toUnicode("开始"));
//  		else
//  			ui.execpushButton->setText(QTextCodec::codecForName( "GBK")->toUnicode("结束"));
// 		return;
	}

	if(!itemshareDataC1.shortcutgather.size())
	{
		HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareData.currentTableName, itemshareData.shortcutgather, bBoxChannel1);
		HISCCMSHORTCUT::setShortcutSync(itemshareData.shortcutgather);
	}

	bool b2tClick	=	b2ndClick;
	unsigned char ucClickTime	=	(b2tClick)?(2):(1);

	bool bkey	=	false;
	if(HISCCMSHORTCUT::isKeyValidOneChannel('=', ucClickTime, itemshareData.shortcutgather))
	{
		bkey	=	true;
	}

	if(!bkey)
	{
		ucClickTime	=	(ucClickTime==2)?(1):(2);
		if(HISCCMSHORTCUT::isKeyValidOneChannel('=', ucClickTime, itemshareData.shortcutgather)) bkey = true;
	}

	if(!bkey) return;

	if(itemshareData.mutexItemExec.tryLock(30)){
		itemshareData.mutexItemExec.unlock();
		if(ucClickTime == 2)	classButtonExec->ui.execpushButton->setText(tr("START"));
		else	classButtonExec->ui.execpushButton->setText(tr("STOP"));
		b2ndClick	=	!b2ndClick;
		emit keyshortcutPress('=', ucClickTime);
	}
	else{
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("正忙，请稍后......."));
		return;
	}
}

void HisFX3CCMTest::ShowConfigDialog()
{
	if(!HISGLOBALUI::isUnlocked()) return;

	if(threadshareData.GetHisTestingflag()){
		QMessageBox::warning(this, tr("Warning"), tr("The test process is going, Please try later."));
		return;
	}

	if(threadshareData.GetHisPreviewflag()){
		QMessageBox::warning(this, tr("Warning"), tr("The Sensor preview is on, Please try later."));
		return;
	}

	if(!hisglobalparameter.mutexDatabase.tryLock(50))
	{
		QMessageBox::warning(0, tr("ERROR"), tr("Database is being operated on other place, please try again later"));
		return;
	}

	if(!HISDBCUSTOM::isCustomCanOpen()) return;

	hisglobalparameter.mutexDatabase.unlock();
	if(!HISDBCUSTOM::isTableExist(itemshareData.currentTableName)) {
		QMessageBox::warning(this, tr("Warning"),  itemshareData.currentTableName % tr(" Is Invalid"));
		return;
	}

	ui.configaction->setEnabled(true);

	configsetting* conflgclass	=	new configsetting(this, bBoxChannel1, threadshareData, itemshareData, itemprocessworker);
	conflgclass->setAttribute(Qt::WA_DeleteOnClose);
	conflgclass->show();
	conflgclass->raise();
	conflgclass->activateWindow();
	connect(conflgclass, SIGNAL(destroyed()), this, SLOT(EnableConfigMenu()));
	itemshareData.flagLock.lockForWrite();
	itemshareData.bdatabasevalid	=	false;
	itemshareData.flagLock.unlock();
}

void HisFX3CCMTest::EnableConfigMenu()
{
	itemshareData.clear();
	drawproject();
	emit information(QTextCodec::codecForName( "GBK")->toUnicode("参数更新完毕"));

	itemshareData.flagLock.lockForWrite();
	itemshareData.bdatabasevalid	=	true;
	itemshareData.flagLock.unlock();
	ui.configaction->setEnabled(true);
}

int HisFX3CCMTest::getglobalParameter()
{
	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	QString strClassfy = (bBoxChannel1)?("globalc1"):("globalc2");

	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			return HisCCMError_Database;

		QSqlQuery query(templatedb);
		query.prepare("SELECT value FROM global WHERE classfy='" % strClassfy % "' AND item='project' AND key='name'" );
		query.exec();

		while (query.next()){
			QString strData	=	query.value(0).toString();
			itemshareData.currentTableName	=	strData;
			ui.configlabel->setText(strData);
		}

		query.prepare("SELECT itemsuffix2 FROM global WHERE classfy='" % strClassfy % "' AND item='imageshow' AND itemsuffix1='mode'");
		query.exec();
		while (query.next()){
			threadshareData.stImageShowPolicy.ucMode = query.value(0).toUInt();
			ui.imageshowPolicycomboBox->setCurrentIndex(threadshareData.stImageShowPolicy.ucMode);
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");

	return 0;
}

void HisFX3CCMTest::getManualModeAConfig()
{
	if(itemshareData.currentTableName.isEmpty()) return;

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBCUSTOM::addDB(stSqlDB);
		if(bDB){
			QString strData;
			QStringList strname, strvalue;
			QSqlQuery query(stSqlDB);
			query.prepare("SELECT itemsuffix1,itemsuffix2,key,value,reserve FROM " % itemshareData.currentTableName % \
				" WHERE classfy='opmode' AND item='manual-a-2' ORDER BY id ASC" );
			query.exec();

			//(delay:500)
			//(fafevalue:1)
			//(wpfevalue:1)(blemish:1)(oc:0)(shading:0)(vignet:0)(color:0)(dpixel:0)(line:0)
			//(nearfcfevalue:1)
			//(farfcfevalue:1)
			while (query.next())
			{
				for(int y=0;	y<5;	++y){
					strData	=	query.value(y).toString();
					ROPLOW::patchconfigstring(strData, strname, strvalue);
					for(int x=0;	x<strname.size();	++x){
						if(strname.at(x) == "fafevalue")	itemshareData.stManualModeA.uiExposureValue_FA	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "wpfevalue")	itemshareData.stManualModeA.uiExposureValue_WhiteField	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "nearfcfevalue")	itemshareData.stManualModeA.uiExposureValue_NearFC	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "farfcfevalue")	itemshareData.stManualModeA.uiExposureValue_FarFC	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "delay")		itemshareData.stManualModeA.usDelay	=	strvalue.at(x).toUInt() & 0xFFFF;
						else if(strname.at(x) == "blemish")	itemshareData.stManualModeA.bBlemishON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "oc")			itemshareData.stManualModeA.bOCON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "shading")	itemshareData.stManualModeA.bShadingON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "vignet")	itemshareData.stManualModeA.bVignetON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "color")		itemshareData.stManualModeA.bColorON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "dpixel")	itemshareData.stManualModeA.bDefectPixelON	=	strvalue.at(x).toUInt();
						else if(strname.at(x) == "line")		itemshareData.stManualModeA.bLineON	=	strvalue.at(x).toUInt();
					}
				}
			}

			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBCUSTOM::removeDB();
	}
}

void HisFX3CCMTest::createToolbar()
{
	mainToolBar = new QToolBar(this);
// 	mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
	if(bBoxChannel1)
		this->addToolBar(Qt::LeftToolBarArea, mainToolBar);
	else
		this->addToolBar(Qt::RightToolBarArea, mainToolBar);
	mainToolBar->setMovable(false);

	chooseprojectAction = new QAction(QIcon(":/Resources/chooseprojects.png"), tr("Choose Config"), this);
	connect(chooseprojectAction, SIGNAL(triggered()), this, SLOT(chooseconfigs()));
	mainToolBar->addAction(chooseprojectAction);

	saveimageAction = new QAction(QIcon(":/Resources/saveimage.png"), tr("Save Image"), this);
	connect(saveimageAction, SIGNAL(triggered()), this, SLOT(manulsaveImage()));
	mainToolBar->addAction(saveimageAction);

	QAction* hardwareopAction	=	new QAction(QIcon(":/Resources/IIC.png"), tr("IIC&Voltage"), this);
	connect(hardwareopAction, SIGNAL(triggered()), this, SLOT(HardwareSetting()));
	mainToolBar->addAction(hardwareopAction);

	QAction *manualtoolAction		=	new QAction(QIcon(":/Resources/tool.png"), tr("Exposure&Focus"), this);
	connect(manualtoolAction, SIGNAL(triggered()), this, SLOT(ShowManualTool()));
	mainToolBar->addAction(manualtoolAction);

	QAction *itemexeAction		=	new QAction(QIcon(":/Resources/itemexe.png"), tr("Item Execute"), this);
	connect(itemexeAction, SIGNAL(triggered()), this, SLOT(showItemExeTool()));
	mainToolBar->addAction(itemexeAction);

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	QAction *IOControlAction		=	new QAction(QString::fromLocal8Bit("IO控制"), this);
	connect(IOControlAction, SIGNAL(triggered()), (QHMainWindow*)parent(), SLOT(slotShowIOControl()));
	mainToolBar->addAction(IOControlAction);
#endif
	QAction *helpAction		=	new QAction(QIcon(":/Resources/Help.png"), QString::fromLocal8Bit("作业指导书"), this);
	connect(helpAction, SIGNAL(triggered()), (QHMainWindow*)parent(), SLOT(slotShowSOP()));
	mainToolBar->addAction(helpAction);

}

void HisFX3CCMTest::chooseconfigs()
{
	if(threadshareData.GetHisTestingflag()){
		QMessageBox::warning(this, tr("Warning"), tr("The test process is going, Please try later."));
		return;
	}

	if(threadshareData.GetHisPreviewflag()){
		QMessageBox::warning(this, tr("Warning"), tr("The Sensor preview is on, Please try later."));
		return;
	}

	if(!hisglobalparameter.mutexDatabase.tryLock(50))
	{
		QMessageBox::warning(0, tr("ERROR"), tr("Database is being operated on other place, please try again later"));
		return;
	}

	if(!HISDBCUSTOM::isCustomCanOpen()) return;
	hisglobalparameter.mutexDatabase.unlock();

	if(!hisglobalparameter.mutexOperate.tryLock(50))
	{
		QMessageBox::warning(0, tr("ERROR"), tr("Operation Conflict"));
		return;
	}

	hisglobalparameter.mutexOperate.unlock();
	QMutexLocker locker1(&hisglobalparameter.mutexOperate);

	cchooseconfigs classchoose	(this, itemshareData.currentTableName);
	if(classchoose.exec() == QDialog::Accepted && classchoose.strCurrenSelect != itemshareData.currentTableName)
	{
		itemshareData.clear();
		itemshareData.currentTableName	=	classchoose.strCurrenSelect;
		hisglobalparameter.mutexDatabase.lock();
		QString strClassfy = (bBoxChannel1)?("globalc1"):("globalc2");
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, strClassfy, "project", QVariant(), QVariant(), "name");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 22, strClassfy, "project", QVariant(), QVariant(), "name", itemshareData.currentTableName);
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}

		hisglobalparameter.mutexDatabase.unlock();
		emit information(QTextCodec::codecForName("GBK")->toUnicode("切换配置文档：") % itemshareData.currentTableName);

		getManualModeAConfig();
		drawproject();
	}

}

void HisFX3CCMTest::manulsaveImage()
{
	saveimageAction->setEnabled(false);
	if(saveimageDir.isEmpty())
		saveimageDir	=	QDir::currentPath();
	saveimage* classsaveImage	=	new saveimage(this, saveimageDir);
	classsaveImage->setAttribute(Qt::WA_DeleteOnClose);
	connect(classsaveImage, SIGNAL(destroyed()), this, SLOT(EnableSaveImage()));
	connect(classsaveImage, SIGNAL(execsave(QString, QString, unsigned char, unsigned char)), this, SLOT(execsaveimage(QString, QString, unsigned char, unsigned char)));
	classsaveImage->show();
	classsaveImage->raise();
	classsaveImage->activateWindow();
}

void HisFX3CCMTest::EnableSaveImage()
{
	saveimageAction->setEnabled(true);
}

void HisFX3CCMTest::execsaveimage(QString strdir, QString strname, unsigned char ucimageformat, unsigned char ucimagesrc)
{
	saveimageDir	=	strdir;
	strdir	=	strdir % "/" % strname;
	switch (ucimageformat){
	case _His_CCM_SaveImage_Type_Raw8:	strdir	=	strdir % ".raw";	break;
	case _His_CCM_SaveImage_Type_Raw10:	strdir	=	strdir % ".raw";	break;
	case _His_CCM_SaveImage_Type_Raw12:	strdir	=	strdir % ".raw";	break;
	case _His_CCM_SaveImage_Type_BMP:		strdir	=	strdir % ".bmp";	break;
	case _His_CCM_SaveImage_Type_JPEG:	strdir	=	strdir % ".jpeg";	break;
	case _His_CCM_SaveImage_Type_PNG:
	default:		strdir	=	strdir % ".png";	break;
	}
	bool bresult	=	true;

	if(ucimagesrc == _His_CCM_SaveImage_Src_ImageArea){
		QPixmap screenmap	=	QPixmap::grabWindow(ui.imageframe->winId());
		bresult	=	screenmap.save(strdir, 0, 100);
	}
	else if(ucimagesrc == _His_CCM_SaveImage_Src_AppArea){
		QPixmap screenmap	=	QPixmap::grabWindow(this->winId());
		bresult	=	screenmap.save(strdir, 0, 100);
	}
	else if(ucimagesrc == _His_CCM_SaveImage_Src_ScreenArea){
		QPixmap screenmap	=	QPixmap::grabWindow(QApplication::desktop()->winId());
		bresult	=	screenmap.save(strdir, 0, 100);
	}
	else{
		threadshareData.flaglock.lockForRead();
		unsigned int uiWidth			=	threadshareData.uiWidth;
		unsigned int uiHeight			=	threadshareData.uiHeight;
		unsigned char ucFormat		=	threadshareData.ucFormat;
		threadshareData.flaglock.unlock();

		if(bresult	=	threadshareData.GetHisPreviewflag())
		{

			if(ucimageformat == _His_CCM_SaveImage_Type_Raw8 || \
				ucimageformat == _His_CCM_SaveImage_Type_Raw10 || \
				ucimageformat == _His_CCM_SaveImage_Type_Raw12)
			{ //raw8, raw10, yuv
				unsigned int uibugbyte = (ucimageformat==_His_CCM_SaveImage_Type_Raw10 || ucimageformat==_His_CCM_SaveImage_Type_Raw12 || (ucFormat >= HisYUV8_422_YUYV  && ucFormat <= HisYUV8_420P))?(uiWidth*uiHeight*2):(uiWidth*uiHeight);
				unsigned __int8* pui8Frame	=	(unsigned __int8*)_aligned_malloc(uibugbyte, _HisCacheLine_Aligned);
				if(pui8Frame == NULL){
					bresult		=	false;
					emit information(QTextCodec::codecForName( "GBK")->toUnicode("申请内存失败"));
				}
				else
				{
					_HisFX3_FrameType enFrameType	=	_FrameType_Raw;
					if(ucimageformat==_His_CCM_SaveImage_Type_Raw10) enFrameType	=	_FrameType_Raw10;
					else if(ucimageformat==_His_CCM_SaveImage_Type_Raw12) enFrameType	=	_FrameType_Raw12;

					if(globalFunPointer.GetFreshframe(pui8Frame, uibugbyte, enFrameType, true)){
						bresult	=	false;
						emit information(QTextCodec::codecForName( "GBK")->toUnicode("获取帧数据失败"));
					}
					else
					{
						QString strTexe1	=	"[BIT8]";
						if(ucimageformat==_His_CCM_SaveImage_Type_Raw10)	strTexe1	=	"[BIT10]";
						else if(ucimageformat==_His_CCM_SaveImage_Type_Raw12)	strTexe1	=	"[BIT12]";

						QString strText	=	"[" % QString::number(uiWidth) % "x" % QString::number(uiHeight) % "]";
						switch(ucFormat){
						case HisBaylor8_BGGR:
						case HisBaylor12_BGGR:
						case HisBaylor10_BGGR:	strdir	=	strdir.replace(".raw", strText % "[BGGR]" % strTexe1 % ".raw");	break;
						case HisBaylor8_RGGB:
						case HisBaylor12_RGGB:
						case HisBaylor10_RGGB:	strdir	=	strdir.replace(".raw", strText % "[RGGB]" % strTexe1 % ".raw");	break;
						case HisBaylor8_GRBG:
						case HisBaylor12_GRBG:
						case HisBaylor10_GRBG:	strdir	=	strdir.replace(".raw", strText % "[GRBG]" % strTexe1 % ".raw");	break;
						case HisBaylor8_GBRG:
						case HisBaylor12_GBRG:
						case HisBaylor10_GBRG:	strdir	=	strdir.replace(".raw", strText % "[GBRG]" % strTexe1 % ".raw");	break;
						case HisBaylor8_MONO:
						case HisBaylor12_MONO:
						case HisBaylor10_MONO:	strdir	=	strdir.replace(".raw", strText % "[MONO]" % strTexe1 % ".raw");	break;
						case HisYUV8_422_YUYV:			strdir	=	strdir.replace(".raw", strText % "[YUYV422][BIT8].raw");	break;
						case HisYUV8_422_UYVY:			strdir	=	strdir.replace(".raw", strText % "[UYVY422][BIT8].raw");	break;
						case HisYUV8_422_YVYU:			strdir	=	strdir.replace(".raw", strText % "[YVYU422][BIT8].raw");	break;
						case HisYUV8_422_VYUY:			strdir	=	strdir.replace(".raw", strText % "[VYUY422][BIT8].raw");	break;
						default:		break;
						}

						QFile classFile(strdir);
						if(classFile.open(QIODevice::WriteOnly)){
							classFile.resize(0);
							classFile.seek(0);
							if(classFile.write((char*)(pui8Frame), uibugbyte) == -1)	bresult	=	false;
							classFile.close();
						}
						else	bresult	=	false;						
					}

				}

				HisReleaseMalloc(pui8Frame);
			}
			else{ //bmp, jpeg, png
				unsigned __int8* pui8RGB24	=	(unsigned __int8*)_aligned_malloc(uiWidth*uiHeight*3, _HisCacheLine_Aligned);
				if(!pui8RGB24){
					bresult		=	false;
					emit information(QTextCodec::codecForName( "GBK")->toUnicode("申请内存失败"));
				}
				else{
					if(globalFunPointer.GetFreshframe(pui8RGB24, uiWidth*uiHeight*3, _FrameType_RGB24, true)){
						bresult	=	false;
						emit information(QTextCodec::codecForName( "GBK")->toUnicode("获取帧数据失败"));
					}
					else{
						QImage image2(pui8RGB24, uiWidth, uiHeight, (uiWidth <<1) + uiWidth, QImage::Format_RGB888);
						bresult	=	image2.save(strdir, 0, 100);
					}
				}

				HisReleaseMalloc(pui8RGB24);
			}

		}

	}

	if(bresult)	emit information(strdir % QTextCodec::codecForName( "GBK")->toUnicode("   保存成功"));
	else			emit information(strdir % QTextCodec::codecForName( "GBK")->toUnicode("   保存失败"));

	threadshareData.flaglock.lockForWrite();
	threadshareData.bSavingImage	=	false;
	threadshareData.flaglock.unlock();

}

void HisFX3CCMTest::HardwareSetting()
{
	unsigned int uihardversion	=	0;
	if(!classPlatform.HisFX3isopen()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备还未打开"));
		return;
	}
	else
	{
		classPlatform.HisFX3GetHardwareVersion(&uihardversion);
	}
		

	hardwareop* classhardwareop	=	new hardwareop(this, bBoxChannel1, threadshareData, itemshareData, globalFunPointer);
	classhardwareop->setAttribute(Qt::WA_DeleteOnClose);
	classhardwareop->show();
	classhardwareop->raise();
	classhardwareop->activateWindow();

	if(bBoxChannel1) classhardwareop->setWindowTitle(tr("Hardware Operation Panel-1"));
	else classhardwareop->setWindowTitle(tr("Hardware Operation Panel-2"));

	itemshareData.itemparameterLock.lockForRead();
	if(itemshareData.previewParameter){
		classhardwareop->seti2cinfo(itemshareData.previewParameter->ucSlave, itemshareData.previewParameter->usI2CMode);
	}
	itemshareData.itemparameterLock.unlock();
}

void HisFX3CCMTest::updateDevicestatus(bool bConnect)
{
	QPixmap pixmap1;
	if(bConnect)	pixmap1.load(":/Resources/Green.png", "PNG");
	else	pixmap1.load(":/Resources/Red.png", "PNG");

	if(hisglobalparameter.ucGrabberIndex){
		QRectF stRect;
		stRect.setLeft(0);
		stRect.setRight(0);
		stRect.setWidth(pixmap1.width());
		stRect.setHeight(pixmap1.height());
		QPainter painter(&pixmap1);
		QFont thefont =	painter.font();
		thefont.setFamily("arial");
		thefont.setBold(true);
		thefont.setPixelSize(20);
		painter.setFont(thefont);
		painter.drawText(stRect, Qt::AlignVCenter | Qt::AlignHCenter, QString::number(hisglobalparameter.ucGrabberIndex));
	}

	ui.fx3label->setPixmap(pixmap1);
}

void HisFX3CCMTest::showItemStatus2EndResult(unsigned short usitem, unsigned char ucstatus, unsigned int ustime)
{
	bool bFA = (ucstatus & 0x80)?(true):(false);
	QPixmap pixmap1(130, 100);
	QPainter painter(&pixmap1);
	painter.setPen(Qt::SolidLine);
	painter.setPen(QColor::fromRgb(0,0,0));

	QFont labelfont("Microsoft Tai Le");
	labelfont.setBold(true);
	QFont timefont("Microsoft Tai Le");
	timefont.setBold(true);

	QRect textrect, timerect;
	textrect.setRect (0, 0, 130, 100);

	if(bFA)
	{
#if (defined USE_MANUAL_LENS_BIN)
		labelfont.setPointSize(30);
		painter.setFont(labelfont);
		ucstatus &= 0x7F;
		QString diaplaytext;
		switch (ucstatus){
		case 5: diaplaytext = "A"; pixmap1.fill(QColor::fromRgb(0, 255, 0)); break; //green 1
		case 4: diaplaytext = "B"; pixmap1.fill(QColor::fromRgb(255, 255, 0)); break; //yellow 2
		case 3: diaplaytext = "C"; pixmap1.fill(QColor::fromRgb(0, 0, 220)); break; //blue 3
		case 2: diaplaytext = "D"; pixmap1.fill(QColor::fromRgb(0, 255, 255)); break; //cyan 4
		case 1: diaplaytext = "E"; pixmap1.fill(QColor::fromRgb(230, 0, 230)); break; //purple 5
		default: diaplaytext = "NG"; pixmap1.fill(QColor::fromRgb(255, 0, 0)); break; //red 0
		}
		painter.drawText(textrect, QPainter::Antialiasing | Qt::AlignCenter, diaplaytext);
#else
		labelfont.setPointSize(18);
		painter.setFont(labelfont);
		ucstatus &= 0x7F;
		QString diaplaytext	=	HISCCMSHORTCUT::item2displaytext(usitem);
		if(usitem == mtffaitem) diaplaytext = "MTF\n";
		else if(usitem == sfrfacaitem) diaplaytext = "SFR\n";
		else if(usitem == lpmfaitem) diaplaytext = "LP\n";

		switch (ucstatus){
		case 5: pixmap1.fill(QColor::fromRgb(0, 255, 0)); diaplaytext += "OK2"; break; //green 1
		case 4: pixmap1.fill(QColor::fromRgb(255, 255, 0)); diaplaytext += "OK1"; break; //yellow 2
		default: pixmap1.fill(QColor::fromRgb(255, 0, 0)); diaplaytext += "NG"; break; //red 0
		}
		painter.drawText(textrect, QPainter::Antialiasing | Qt::AlignCenter, diaplaytext);
#endif
	}
	else
	{
		if(ucstatus != _His_ItemStatus_PASS && ucstatus != _His_ItemStatus_NG) return;

		if(ucstatus == _His_ItemStatus_PASS)		pixmap1.fill(QColor::fromRgb(0, 255, 0));
		else	pixmap1.fill(QColor::fromRgb(255, 0, 0));

		labelfont.setPointSize(18);
		painter.setFont(labelfont);
		QString diaplaytext	=	HISCCMSHORTCUT::item2displaytext(usitem);
		painter.drawText(textrect, QPainter::Antialiasing | Qt::AlignCenter, diaplaytext);
	}

	if(ustime != 0xFFFFFFFF){
		painter.setFont(timefont);
		timerect.setBottomRight(textrect.bottomRight());
		timerect.setLeft(textrect.left() + (textrect.right() - textrect.left()) *2 /3);
		timerect.setTop(textrect.top() + (textrect.bottom() - textrect.top()) *2 /3);
		painter.drawText(timerect, QPainter::Antialiasing | Qt::AlignCenter, QString::number(ustime, 10) % "ms");
	}

	classButtonExec->ui.resultlabel->setPixmap(pixmap1);
}

void HisFX3CCMTest::showEndresult(int istatus)
{
	if(istatus == 0){
		QPixmap pixmap1(":/Resources/pass.png", "PNG");
		classButtonExec->ui.resultlabel->setPixmap(pixmap1);
	}
	else if(istatus == -1){
		QPixmap pixmap1(":/Resources/testing.png", "PNG");
		classButtonExec->ui.resultlabel->setPixmap(pixmap1);
	}
	else{
		QPixmap pixmap1(":/Resources/ng.png", "PNG");
		classButtonExec->ui.resultlabel->setPixmap(pixmap1);
	}
}

void HisFX3CCMTest::testsignalslot(char key, unsigned char uctimer)
{
	qDebug()<<"test emit execshortcut";
}
void HisFX3CCMTest::drawproject()
{

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bparsesuccess	=	true;

	for(int w=0;	w<1;	++w)
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open())
		{
			bparsesuccess	=	false;
			break;
		}

		QSqlQuery query(customdb);
		query.prepare("SELECT key,value FROM " % itemshareData.currentTableName % " WHERE classfy='platform' AND item='ccm' AND itemsuffix1='element' ORDER BY id ASC" );
		query.exec();
		QString strData;

		while (query.next())
		{
			strData	=	query.value(0).toString();
			strData	=	strData.trimmed();
			strData	=	strData.toLower();
			if(strData == "project_name")
			{
				strData	=	query.value(1).toString();
				if (!strData.isEmpty() && !itemshareData.currentTableName.isEmpty())
				{
					strData	=	itemshareData.currentTableName % " / " % strData;
					ui.configlabel->setText(strData);
				}	
			}
		}

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
}

void HisFX3CCMTest::painterplot(unsigned int uiType)
{
	if(uiType == 1){
		itemshareData.plotLock.lockForRead();
		classInfoPanel->drawBarChartSlef(itemshareData.vecBarChartItem, itemshareData.dflBarChartYMin, itemshareData.dflBarChartYMax);
		itemshareData.plotLock.unlock();
	}
	else if(uiType == 2){
		itemshareData.plotLock.lockForRead();
		classInfoPanel->drawCurve(itemshareData.vecCurvePoint, itemshareData.vecCurveLineColor, itemshareData.vecCurveLegend, \
			itemshareData.dflCurveYMin, itemshareData.dflCurveYMax, itemshareData.dflCurveXMin, itemshareData.dflCurveXMax, \
			itemshareData.bCurveXScaleAuto, itemshareData.ucCurveType);
		itemshareData.plotLock.unlock();
	}
	else{
		classInfoPanel->ui.drawcurveqwtPlot->setVisible(false);
		// 		classInfoPanel->ui.drawinfoqwtPlot->setVisible(false);
		classInfoPanel->ui.drawinfolabel->setVisible(true);
		QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
		QPixmap temppixmap;
		itemshareData.plotLock.lockForRead();
		if(classInfoPanel->ui.drawinfolabel->height() > classInfoPanel->ui.drawinfolabel->width())
			temppixmap	=	QPixmap::fromImage(itemshareData.plotimage.transformed(rotationMatrix, Qt::FastTransformation));
		else
			temppixmap	=	QPixmap::fromImage(itemshareData.plotimage);
		classInfoPanel->ui.drawinfolabel->setPixmap(temppixmap);
		itemshareData.plotLock.unlock();
	}
}

void HisFX3CCMTest::slotWheelVCMTimer()
{
	itemshareData.itemparameterLock.lockForWrite();
	int iWheel = itemshareData.iWheelPosition;
	itemshareData.iWheelPosition	=	0;
	QString strDriverIC	=	itemshareData.ccmhardwareParameter->motortype;
	QString strProject	=	itemshareData.ccmhardwareParameter->projectname;
	itemshareData.itemparameterLock.unlock();

	if(iWheel == 0) {
		wheelvcmTimer.stop();
		return;
	}

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMSensor32";
#endif

	RolongogetSensorAPIVersion getSensorAPIVersion = (RolongogetSensorAPIVersion)(strLibPath, "getSensorAPIVersion");
	RolongogetMotor getMotor = (RolongogetMotor)(QLibrary::resolve(strLibPath, "getMotor"));
	RolongosetMotor setMotor = (RolongosetMotor)(QLibrary::resolve(strLibPath, "setMotor"));

	if(!(getSensorAPIVersion && getMotor && setMotor)){
		emit information(tr("Resolve HisCCMSensor DLL Function Fail"));
		return;
	}

	int ivalue = 0, imin = 0, imax = 0;
	int iresult	= getMotor((strDriverIC.toAscii()).data(), 0x0, (strProject.toAscii()).data(), \
		ivalue, imin, imax, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI);
	if(iresult){
		emit information(tr("Get Current Motor Dec Failed: 0x") % QString::number(iresult, 16));
		return;
	}

	ivalue	+=	iWheel *5;
	ivalue	=	max(imin, ivalue);
	ivalue	=	min(imax, ivalue);
	if(iresult = setMotor((strDriverIC.toAscii()).data(), 0x0, (strProject.toAscii()).data(), \
		ivalue, globalFunPointer.ReadHisFX3IIC, globalFunPointer.WriteHisFX3IIC, globalFunPointer.SetHisFX3IICSpeed, globalFunPointer.PullHisFX3RESET, globalFunPointer.PullHisFX3PWND, \
		globalFunPointer.PageWriteHisFX3IIC, globalFunPointer.PageReadHisFX3IIC, globalFunPointer.HisFX3PageWriteSPI, globalFunPointer.HisFX3PageReadSPI)){
			emit information(tr("Set Motor Dec Failed: 0x") % QString::number(iresult, 16));
	}
	else{
		emit information(tr("Motor Move To ") % QString::number(ivalue));
	}
}

void HisFX3CCMTest::enablebutton(bool benable)
{
	classButtonExec->ui.execpushButton->setEnabled(benable);
}

void HisFX3CCMTest::getmacAddress()
{
	hisglobalparameter.maxAddress.clear();
	PIP_ADAPTER_ADDRESSES AdapterAddresses = 0;
	ULONG OutBufferLength = 0;
	ULONG RetVal = 0;   

	for (int i = 0; i < 5; ++i) {
		RetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_SKIP_MULTICAST|GAA_FLAG_INCLUDE_GATEWAYS,0, AdapterAddresses, &OutBufferLength);
		if (RetVal != ERROR_BUFFER_OVERFLOW) 
			break;
		if (AdapterAddresses) 
			HeapFree(GetProcessHeap(), 0, AdapterAddresses);
		AdapterAddresses = (PIP_ADAPTER_ADDRESSES)HeapAlloc(GetProcessHeap(), 0, OutBufferLength);
		if (!AdapterAddresses) {
			RetVal = GetLastError();
			break;
		}
	}

	char strtext[100];
	if (RetVal == NO_ERROR) {
		PIP_ADAPTER_ADDRESSES AdapterList = AdapterAddresses;
		while (AdapterList) {
			if(AdapterList->PhysicalAddressLength == 6 && AdapterList->IfType == IF_TYPE_ETHERNET_CSMACD && \
				wcsstr(AdapterList->Description, L"Bluetooth") == 0){
					sprintf_s(strtext, 99, "%02X-%02X-%02X-%02X-%02X-%02X", AdapterList->PhysicalAddress[0], AdapterList->PhysicalAddress[1], \
						AdapterList->PhysicalAddress[2], AdapterList->PhysicalAddress[3], AdapterList->PhysicalAddress[4], AdapterList->PhysicalAddress[5]);
					hisglobalparameter.maxAddress	=	QString::fromAscii(strtext);
					OutputDebugStringA((hisglobalparameter.maxAddress.toAscii()).data());
			}
			AdapterList = AdapterList->Next;
		}
	}

	if (AdapterAddresses) 
		HeapFree(GetProcessHeap(), 0, AdapterAddresses);
	AdapterAddresses	=	0;
}

void HisFX3CCMTest::enableinfotimer(unsigned int uiflag)
{
	uiInfoflag	=	uiflag;
	if(uiflag)
	{
		QTimer::singleShot(0, this, SLOT(loopshowinfo()));
	}
}

void HisFX3CCMTest::loopshowinfo()
{
	QString strText;
	QStringList strname, strvalue;
	while(globalFunPointer.vectorHisCCMOTPInfoW->size()){
		strText	=	QString::fromWCharArray(globalFunPointer.vectorHisCCMOTPInfoW->begin()->c_str());
		if(strText.contains("command_showimage:")){
			strText	=	strText.remove("command_showimage:");
			emit information(strText);
			ROPLOW::patchconfigstring(strText, strname, strvalue);
			unsigned int uiFormat=0, uiWidth=0, uiHeight=0;
			QString strPath;
			for(unsigned int x=0;	x<strname.size();	++x){
				emit information(strname.at(x));
				emit information(strvalue.at(x));
				if(strname.at(x) == "format")	uiFormat	=	strvalue.at(x).toUInt();
				else if(strname.at(x) == "width")	uiWidth	=	strvalue.at(x).toUInt();
				else if(strname.at(x) == "height")	uiHeight	=	strvalue.at(x).toUInt();
				else if(strname.at(x) == "path") strPath = strvalue.at(x);
			}

			if(uiFormat > 0 && uiWidth > 0 && uiHeight > 0 && strPath.size() > 4){
				ROPLOW::showImageLable(strPath, uiWidth, uiHeight, uiFormat);
			}
		}
		else if(strText.contains("command_updateotpburnlightcoef:")){
			//(lightcomp_b:1.000000)(lightcomp_r:1.000000)
			strText	=	strText.remove("command_updateotpburnlightcoef:");
			emit information(strText);
			ROPLOW::patchconfigstring(strText, strname, strvalue);
			if(ROPLOW::UpdateOtpBurnParameter(itemshareData.currentTableName, strname, strvalue)){
				emit information(QTextCodec::codecForName( "GBK")->toUnicode("错误：更新OTP烧录光源系数失败!!!!!!!!!!!!"));
			}
		}
		else if(strText.contains("command_messagebox:")){
			strText	=	strText.remove("command_messagebox:");
			QMessageBox::information(this, "INFO", strText);
		}
		else{
			emit information(strText);
		}
		globalFunPointer.vectorHisCCMOTPInfoW->erase(globalFunPointer.vectorHisCCMOTPInfoW->begin());
	}
	if(uiInfoflag)
		QTimer::singleShot(10, this, SLOT(loopshowinfo()));
}

void HisFX3CCMTest::serialNumtextChanged(const QString & text)
{
	threadshareData.strSerialNumber	=	text;
}

void HisFX3CCMTest::ShowManualTool()
{
	if(!classPlatform.HisFX3isopen()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备还未打开"));
		return;
	}
	if(!threadshareData.GetHisPreviewflag()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		return;
	}


	qmanualtool* classmanualtool	=	new qmanualtool(this, bBoxChannel1, threadshareData, itemshareData, globalFunPointer);
	connect(this, SIGNAL(luxMonitorResult(float, float, float, float, float, float, float)), classmanualtool, SLOT(luxMonitorResult(float, float, float, float, float, float, float)));
	connect(classmanualtool, SIGNAL(startLuxMonitor(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)), this, SLOT(startLuxMonitor(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)));
	connect(classmanualtool, SIGNAL(stopLuxMonitor()), this, SLOT(stopLuxMonitor()));
	classmanualtool->setAttribute(Qt::WA_DeleteOnClose);
	classmanualtool->show();
	classmanualtool->raise();
	classmanualtool->activateWindow();
}

void HisFX3CCMTest::calculateLuxMonitor()
{
	//调用检测 MTF RGB
	//亮度
	float flY	=0;
	float flR	=0;
	float flG	=0;
	float flB	=0;
	float flR2G	=0;
	float flB2G	=0;
	float flMTF	=0;
	int		iColorFlag	=static_cast<int>(uiRealTimeFlag/100);
	int		iMtfFlag	=static_cast<int>(uiRealTimeFlag%10);
	int		iBrightnessFlag	=static_cast<int>((uiRealTimeFlag%100)/10);
	//emit information(QTextCodec::codecForName( "GBK")->toUnicode("iColorFlag=") % QString::number(iColorFlag) % QString::number(iBrightnessFlag) % QString::number(iMtfFlag));

	if(!threadshareData.GetHisPreviewflag())	
		return ;
	int iwidth		=	itemshareData.previewParameter->iWidth;
	int iheight	=	itemshareData.previewParameter->iHeight;

	unsigned char* pucrgb	=	(unsigned char*)_aligned_malloc(iwidth *iheight *3, _HisCacheLine_Aligned);
	if(!pucrgb)	
		return ;

	int iresult	=	globalFunPointer.GetFreshframe(pucrgb, iwidth *iheight *3, _FrameType_RGB24, true);
	if(iresult)
	{
		HisReleaseMalloc(pucrgb);
		return ;
	}
	if (iBrightnessFlag)
	{
		iresult	=	classAlgorithm.HisCCMBrightness(pucrgb, iwidth, iheight, stRectRealTime, flY);
		if(iresult)
		{
			HisReleaseMalloc(pucrgb);
			return ;		
		}
	}
	if (iColorFlag)
	{
		unsigned int uiSumG = 0, uiSumR = 0, uiSumB = 0;
		unsigned int uiWidthByte	=	itemshareData.previewParameter->iWidth *3;
		unsigned char* pucLine	=	pucrgb + (stRectRealTime.top *uiWidthByte + stRectRealTime.left *3);
		unsigned char* pucData;
		for(LONG y=stRectRealTime.top;	y<stRectRealTime.bottom;	++y)
		{
			pucData	=	pucLine;
			pucLine	+=	uiWidthByte;
			for(LONG x=stRectRealTime.left;	x<stRectRealTime.right;	++x)
			{
				uiSumR	+=	(unsigned int)(*pucData);
				++pucData;
				uiSumG	+=	(unsigned int)(*pucData);
				++pucData;
				uiSumB	+=	(unsigned int)(*pucData);
				++pucData;
			}
		}

		flR	=	(double)(uiSumR) / (double)((stRectRealTime.right-stRectRealTime.left) *(stRectRealTime.bottom - stRectRealTime.top));
		flG	=	(double)(uiSumG) / (double)((stRectRealTime.right-stRectRealTime.left) *(stRectRealTime.bottom - stRectRealTime.top));
		flB	=	(double)(uiSumB) / (double)((stRectRealTime.right-stRectRealTime.left) *(stRectRealTime.bottom - stRectRealTime.top));
		if (flG	<=1)
		{
			flB2G	=	0;
			flR2G	=	0;
		}
		flR2G	=	static_cast<float>(flR/flG);
		flB2G	=	static_cast<float>(flB/flG);
	}
	if (iMtfFlag)
	{
		iresult	=	classAlgorithm.HisCCMMTF(pucrgb, iwidth, iheight, stRectRealTime, _HisCCM_AlgID_MTF_hao_a, flMTF);
		if (iresult)
		{
			HisReleaseMalloc(pucrgb);
			return ;
		}
	}

	HisReleaseMalloc(pucrgb);

	emit luxMonitorResult(flY,flR,flG,flB,flR2G,flB2G,flMTF);
}
void HisFX3CCMTest::startLuxMonitor(unsigned int uiLeft, unsigned int uiRight, unsigned int uiTop, unsigned int uiBottom, unsigned int uiTimer, unsigned int uiFlag)
{
	if(luxmonitorTimer.isActive()){
		emit information(tr("Testing..."));
		return;
	}
	stRectRealTime.left		=	uiLeft;
	stRectRealTime.right	=	uiRight;
	stRectRealTime.top		=	uiTop;
	stRectRealTime.bottom	=	uiBottom;
	uiRealTimeFlag			=	uiFlag;
	//判断 工装 出图 测试中。。。
	if(!classPlatform.HisFX3isopen()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备还未打开"));
		return;
	}
	if(!threadshareData.GetHisPreviewflag()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("未点亮图像"));
		return;
	}
	if(threadshareData.GetHisTestingflag()){
		emit information(QTextCodec::codecForName( "GBK")->toUnicode("正在测试中......"));
		return;
	}
	luxmonitorTimer.setInterval(uiTimer);

	itemshareData.drawLock.lockForWrite();
	itemshareData.itemdrawList.resize(1);
	itemshareData.itemdrawList.at(0).uctype	=	HisDrawType_Block;
	itemshareData.itemdrawList.at(0).stcolor= QColor::fromRgb(255,255,0);
	itemshareData.itemdrawList.at(0).strinfo.stblock	=	stRectRealTime;
	itemshareData.drawLock.unlock();

	luxmonitorTimer.start();
	emit information(QTextCodec::codecForName( "GBK")->toUnicode("开始实时测试"));
}
void HisFX3CCMTest::showItemExeTool()
{
	// 	if(!classPlatform.HisFX3isopen()){
	// 		QMessageBox::information(this, "ERROR",QTextCodec::codecForName( "GBK")->toUnicode("USB3.0设备还未打开"));
	// 		return;
	// 	}

	if(!HISDBCUSTOM::isTableExist(itemshareData.currentTableName)){
		QMessageBox::information(this, tr("ERROR"), tr("Please choose config table first"));
		return;
	}

	QStringList listKey = HISCCMSHORTCUT::getListALLItemKey();

	qitemexetool* classitemexe	=	new qitemexetool(this, listKey);
	connect(classitemexe, SIGNAL(itemdebugsignal(unsigned short, QString)), this, SLOT(itemdebugslot(unsigned short, QString)));
	classitemexe->setAttribute(Qt::WA_DeleteOnClose);
	classitemexe->show();
	classitemexe->raise();
	classitemexe->activateWindow();
}

void HisFX3CCMTest::itemdebugslot(unsigned short usItem, QString strAddInfo)
{
	if(hisglobalparameter.getfaflag()){
		hisglobalparameter.setfaflag(false);
		::Sleep(300);
	}

	if(threadshareData.GetHisTestingflag())
	{
		QMessageBox::information(this, tr("ERROR"),tr("Testing , Please try Later"));
		return;
	}

	if(!itemshareData.shortcutgather.size())
	{
		int iresult	=	HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareData.currentTableName, itemshareData.shortcutgather, bBoxChannel1);
		if(iresult){
			emit information("Get shortcut config fail: 0x" % QString::number(iresult, 16));
			return;
		}
		HISCCMSHORTCUT::setShortcutSync(itemshareData.shortcutgather);
	}

	char key = (bBoxChannel1)?('~'):(';');
	HISCCMSHORTCUT::eraseKeyItem(itemshareData.shortcutgather, key);

	_shoutCutDetail stDetail;
	stDetail.ucloopTime = 1;
	stDetail.usItemfail	=	0;
	stDetail.usItem		=	usItem;
	stDetail.ucClickTime	=	1;
	stDetail.shortcutKey	=	key;
	stDetail.ucItemIndex	=	1;
	stDetail.strAddInfo		=	strAddInfo;
	stDetail.bDualCamera = (classPlatform.getCameraCountSupported() == 2);
	itemshareData.shortcutgather.push_back(stDetail);
	emit keyshortcutPress(key, 1);
}

int HisFX3CCMTest::getofflineparamater()
{
	itemshareData.itemparameterLock.lockForRead();

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	itemshareData.itemparameterLock.unlock();
	itemshareData.itemparameterLock.lockForWrite();

	for(int w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return HisCCMError_Database;
			break;
		}

		QSqlQuery query(customdb);
		query.prepare("SELECT key FROM " % itemshareData.currentTableName % " WHERE classfy='algorithm' AND item='offline' AND itemsuffix1='paramater' ORDER BY id ASC" );
		query.exec();
		QString strData;
		while (query.next()){
			strData	=	query.value(0).toString();			
			QStringList strname, strvalue;
			ROPLOW::patchconfigstring(strData, strname, strvalue);
			for (unsigned int x=0;	x<strname.size(); ++x)
			{
				if (strname.at(x)	==	"offlinepath")
				{
					itemshareData.offlinepath	=	strvalue.at(x);

				} 
				if (strname.at(x)	==	"readsamepicture")
				{
					itemshareData.breadsamepicture	=	strvalue.at(x) == "true" ? true:false;
				}
			}
		}

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
	itemshareData.itemparameterLock.unlock();
	return 0;
}
int HisFX3CCMTest::saveofflineflag(bool bChecked)
{
	itemshareData.itemparameterLock.lockForRead();


	itemshareData.flagLock.lockForRead();
	if(!itemshareData.bdatabasevalid){
		itemshareData.flagLock.unlock();
		itemshareData.itemparameterLock.unlock();
		itemshareData.itemparameterLock.lockForWrite();

		itemshareData.itemparameterLock.unlock();
		return HisCCMError_opConflic;
	}
	itemshareData.flagLock.unlock();

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	itemshareData.itemparameterLock.unlock();
	itemshareData.itemparameterLock.lockForWrite();
	{
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return HisCCMError_Database;
		}

		QStringList strname, strvalue;
		QString itemsuffix2, key;
		QSqlQuery query(customdb);

		query.prepare("DELETE FROM " % itemshareData.currentTableName %  " WHERE id=:id AND classfy=:classfy AND item=:item AND itemsuffix1=:itemsuffix1");
		query.bindValue(":id",101);
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "offline");
		query.bindValue(":itemsuffix1", "offlineflag");
		query.exec();

		//(lsc:false)(wb:false)
		strname.clear(); strvalue.clear();
		strname.append("offlineflag");
		strvalue.append(bChecked? "true":"false");
		ROPLOW::jointconfigstring(key, strname, strvalue);

		query.prepare("INSERT INTO " % itemshareData.currentTableName %"(id,classfy,item,itemsuffix1,itemsuffix2,key,value,reserve) VALUES(:id,:classfy,:item,:itemsuffix1,:itemsuffix2,:key,:value,:reserve)");
		query.bindValue(":id", 101);
		query.bindValue(":classfy", "algorithm");
		query.bindValue(":item", "offline");
		query.bindValue(":itemsuffix1", "offlineflag");
		query.bindValue(":itemsuffix2", "");
		query.bindValue(":key", key);
		query.bindValue(":value", "");
		query.bindValue(":reserve", "");
		query.exec();

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
	itemshareData.itemparameterLock.unlock();
	return 0;
}
int HisFX3CCMTest::getofflineflag()
{
	itemshareData.itemparameterLock.lockForRead();

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	itemshareData.itemparameterLock.unlock();
	itemshareData.itemparameterLock.lockForWrite();

	for(int w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return HisCCMError_Database;
			break;
		}

		QSqlQuery query(customdb);
		query.prepare("SELECT key FROM " % itemshareData.currentTableName % " WHERE classfy='algorithm' AND item='offline' AND itemsuffix1='offlineflag' ORDER BY id ASC" );
		query.exec();
		QString strData;
		while (query.next()){
			strData	=	query.value(0).toString();			

			QStringList strname, strvalue;
			ROPLOW::patchconfigstring(strData, strname, strvalue);

			for (unsigned int x=0;	x<strname.size(); ++x)
			{

				if (strname.at(x)	==	"offlineflag")
				{
					threadshareData.bOfflineMode	=	strvalue.at(x) == "true" ? true:false;
					//emit information(strvalue.at(x));
				}
			}
		}

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
	itemshareData.itemparameterLock.unlock();
	return 0;
}
int HisFX3CCMTest::gettcpipparamater()
{
	itemshareData.itemparameterLock.lockForRead();

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);

	itemshareData.itemparameterLock.unlock();
	itemshareData.itemparameterLock.lockForWrite();

	for(int w=0;	w<1;	++w){
		QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
		customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
		if (!customdb.open()){
			return HisCCMError_Database;
			break;
		}

		QSqlQuery query(customdb);
		query.prepare("SELECT key,value FROM " % itemshareData.currentTableName % " WHERE classfy='algorithm' AND item='tcp' AND itemsuffix1='total' ORDER BY id ASC" );
		query.exec();
		QString strData;
		while (query.next()){
			strData	=	query.value(0).toString();
			QStringList strname, strvalue;
			ROPLOW::patchconfigstring(strData, strname, strvalue);
			for (unsigned int x=0;	x<strname.size(); ++x)
			{
				if (strname.at(x)	==	"ip")
				{
					itemshareData.tcpip_ip	=	strvalue.at(x);
				} 
				if (strname.at(x)	==	"port")
				{
					itemshareData.tcpip_port	=	strvalue.at(x).toShort();
				}
			}
		}

		customdb.close();
	}

	QSqlDatabase::removeDatabase("querycustom");
	itemshareData.itemparameterLock.unlock();
	return 0;
}

void HisFX3CCMTest::showBindWid(QString strNumber){
	wids->setSerialNumber(strNumber);
	wids->exec();
}
void HisFX3CCMTest::updateSN(QString strNumber,QString strPro){
	global_ioc_x=0;
	if(!m_sock){
		if(jsl_bindSerialNumber::init(m_sock,"192.168.10.15",8000)){
			global_ioc_x=-1;
			QMessageBox::warning(this,"Error",QString::fromLocal8Bit("错误：连接MES服务器失败!"));
			m_sock=NULL;
			return ;
		}
	}

	QString str;
	if(strPro.lastIndexOf("focus")<0){
		str=QString("{\
					\"JsonData\": [\
					{\
					\"LineCode\": \"line1\",\
					\"WorkStationCode\": \"sta1\",\
					\"ProcessCode\": \"%1\",\
					\"Id\": \"%2\"\
					}\
					],\
					\"OrgId\": 33,\
					\"ActionName\": \"xiaozhi.Action.MES.External.AddProcess\",\
					\"ActionAssembly\": \"xiaozhi.Action.MES\"\
					}").arg(strPro).arg(strNumber);
		
	}else{
		str=QString("{\
					\"JsonData\": [\
					{\
					\"LineCode\": \"line1\",\
					\"WorkStationCode\": \"sta1\",\
					\"ProcessCode\": \"focus\",\
					\"MODocNO\": \"MO111\",\
					\"SN\": \"%1\",\
					\"Id\": \"%2\"\
					}\
					],\
					\"OrgId\": 33,\
					\"ActionName\": \"xiaozhi.Action.MES.External.AddSNRd\",\
					\"ActionAssembly\": \"xiaozhi.Action.MES\"\
					}").arg(global_strSN).arg(strNumber);
	}
	

	char recvBuf[8912] = { 0 };
	jsl_bindSerialNumber::commit(m_sock,str.toLatin1().data(),recvBuf);

	str=QString::fromUtf8(recvBuf);
	if(str.lastIndexOf("success")<0){
		if(!global_ioc_x)global_ioc_x=3;
	}else{
		if(!global_ioc_x)global_ioc_x=1;
	}

	global_ioc_x=1;
}
