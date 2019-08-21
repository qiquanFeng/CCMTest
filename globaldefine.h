#ifndef INTELGLOBALDEFINE_H
#define INTELGLOBALDEFINE_H
#pragma once

#include <windows.h>
#include "math.h"
#include <QtCore/qglobal.h>
#include <QObject>
#include <QMutex>
#include <QReadWriteLock>
#include <QPixmap>
#include <QTcpSocket>
#include <QTcpServer>
#include <QElapsedTimer>
#include <QNetworkInterface>
#include <QCoreApplication>
#include  <QMessageBox>
#include <QSettings>
#include <QLibrary>
#include <QInputDialog>
#include <QDesktopWidget> 
#include <QTextStream>
#include <QElapsedTimer>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <malloc.h>
#include <Dbt.h>
#include <vector>
#include <QImage>
#include <QThread>
#include <QEvent>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QInputDialog>
#include <QCryptographicHash>
 
#include "inc/versionswitch.h"
#include "inc/HisGlobalDefine.h"
#include "inc/HisFX3CCMAlg.h"
#include "inc/HisFX3Platform.h"
#include "inc/RolongoImageTestAlg.h"
#include "itemGlobalHeader.h"
#include "../QHTcpIpCommu/qhtcpipcommu.h"
#include "Serial.h"
#include "inc/HisFX3Log.h"
#include "Qualcomm_LSCCalibrationDll.h"
#include "inc/OV4CellLib.h"
#include "inc/hisfx3gerneralmotion.h"
#include "pdh.h"
#include "json.h"
#include "ss_lm_runtime.h"
#include "io.h"

//************* 2018.05.23 ****************
#if (defined USE_EQUIPMENT_AFM_JSL_V2)
#include "./LeisaiLib/LTDMC.h"
#include "leisaiMotion.h"
#ifdef _WIN32
#pragma comment(lib,"./LeisaiLib/X86/LTDMC")
#else
#pragma comment(lib,"./LeisaiLib/X64/LTDMC")
#endif
#endif
//***************************************




#ifdef USE_EQUIPMENT_AFM_JSL_V1

#include "inc/RJAutoFocusMC.h"
#if (defined _WIN64) && (defined _DEBUG)
#pragma comment(lib, "lib/x64/Debug/HisRJAFMC64D.lib")
#elif (defined _WIN64)
#pragma comment(lib, "lib/x64/Release/HisRJAFMC64.lib")
#elif (defined _DEBUG)
#pragma comment(lib, "lib/x86/Debug/HisRJAFMC32D.lib")
#else
#pragma comment(lib, "lib/x86/Release/HisRJAFMC32.lib")
#endif

#endif


extern int global_unit_rg;
extern int global_unit_bg;
extern int global_unit_g;
extern int global_burn_group;
extern int global_ioc_x;
extern int global_ioc_y;
extern char global_strSN[1024];
extern _HisCCMAlg_AFC_MTF_DataItem_EX stItemData_EX;



#define _Thread_Wait_Times					100
#define _Firstframe_Timeout					2500
#define _Slider_Interval					100
#define _AE_MaxTimes						20
#define _FC_MaxTimes						20
#define _FC_DATA_MAX						50000
#define _AE_DATA_MAX						600
#define _FRAME_SLEEP_ADVANCE		50
#define _USB30FPGA_INIT_MAXTIME	50

#ifdef _HisFX3_Platform_Jigboard
#define _ThreadExit_TimeOut					8000
#else
#define _ThreadExit_TimeOut					3000
#endif

#define _CODE_CLEAR_PAINTREGION {threadshareData.pixmaplock.lockForWrite();threadshareData.frameimage.fill(QColor::fromRgb(240, 240, 240));threadshareData.pixmaplock.unlock();emit plotpainter();}
#define _CODE_CLEAR_IMAGEDRAW {itemshareData.drawLock.lockForWrite();itemshareData.itemdrawList.clear();itemshareData.drawLock.unlock();}
#define _CODE_EMIT_PAINTREGION(a)  {itemshareData.plotLock.lockForWrite();itemshareData.plotimage	=	a;itemshareData.plotLock.unlock();emit plotpainter();}
#define _CODE_WHITEPANEL_EXIT {HisReleaseMalloc(pucbalor);HisReleaseMalloc(pucrgb);HisReleaseMalloc(pucr);HisReleaseMalloc(pucb);HisReleaseMalloc(pucgr);HisReleaseMalloc(pucgb);HisReleaseMalloc(pucYUV422U8_Y);HisReleaseMalloc(pucrgb_g);HisReleaseMalloc(pucrgb_r);HisReleaseMalloc(pucrgb_b);itemshareData.itemparameterLock.unlock();}
#define _CODE_OPERATEITEM_UPDATEITEM {itemstatus.ucstatus=(iresult)?(_His_ItemStatus_NG):(_His_ItemStatus_PASS); itemstatus.ustime		=	testtimer.elapsed();	updateItemstatus(itemstatus);}
#define _CODE_OPERATEITEM_UPDATETESTING {itemstatus.ucstatus=_His_ItemStatus_Testing; itemstatus.ustime		=	0;	updateItemstatus(itemstatus);}
#define _CODE_RJAFA_LP_ASIGNDRAW {itemshareData.drawLock.lockForWrite();itemshareData.itemdrawList.assign(vectorDraw.begin(), vectorDraw.end());itemshareData.drawLock.unlock();}
#define _CODE_RJAFA_LP_EXIT1 {HisReleaseMalloc(pucBufY);HisReleaseMalloc(pucBufRaw);return iresult;}
#define _CODE_UPDATE_ITEMDATA1(a, b) { itemstatus.usitem	=	a; itemstatus.ucstatus = b; itemstatus.ustime	=	testtimer.restart(); updateItemstatus(itemstatus); }
#define _CODE_AFC_LP_EXIT1 {HisReleaseMalloc(pucBufY);HisReleaseMalloc(pucBufRaw);itemshareData.itemparameterLock.unlock(); return iresult;}
#define _CODE_LOG_PUSHBACK(a,b) { ++(stLogItem.itemtype); stLogItem.itemkey = a; stLogItem.itemvalue = b; classLog->push_back(stLogItem);}
#define _CODE_LOG_PUSHBACK_ALL(a,b,c) { stLogItem.itemtype=a; stLogItem.itemkey = b; stLogItem.itemvalue = c; classLog->push_back(stLogItem);}
#define _CODE_AFC_SFRHA_EXIT1 {HisReleaseMalloc(pucBufRaw);HisReleaseMalloc(pucBufY);HisReleaseMalloc(pflSFRBlock);HisReleaseMalloc(pdflsfrvalue);itemshareData.itemparameterLock.unlock(); return iresult;}
#define _CODE_AFC_MTF_EXIT1 {HisReleaseMalloc(pucBufRaw);/*HisReleaseMalloc(pucBufRaw10)*/;HisReleaseNewB(pstBlock); itemshareData.itemparameterLock.unlock(); return iresult;}
#define _CODE_AFA_ALL_EXIT1 {HisReleaseMalloc(pucBufRaw);/*HisReleaseMalloc(pucBufRaw10);*/HisReleaseMalloc(pucBufY);HisReleaseMalloc(pflSFRBlock);HisReleaseMalloc(pdflsfrvalue);HisReleaseNewB(pstBlock);itemshareData.itemparameterLock.unlock(); return iresult;}
#define _CODE_BLEMISH_HC_EXIT1(a) {HisReleaseMalloc(pucRGB24);HisReleaseMalloc(pucR);HisReleaseMalloc(pucG);HisReleaseMalloc(pucB); return a;}
 
#if (defined USE_EQUIPMENT_AFM_JSL_V2)
extern leisaiMotion globalLeisaiMotion;
#endif
extern CHisFX3CCMAlg classAlgorithm;
extern CHisFX3Platform classPlatform;
extern int OV4Cell_ReadReg_CallbackC1(void *handle, int id, int addr);

//OV 4Cell DLL
typedef int (*fun_ov4c_get_version)();
typedef int (*fun_ov4c_set_i2c_callback)(void* handle, int sensor_id, ov4c_i2c_callback i2c_callback);
typedef int (*fun_ov4c_init)(ROI_PARA *roi_para);
typedef int (*fun_ov4c_20880_transform_bayer_raw10)(unsigned short *raw_in, unsigned short *raw_out, ROI_PARA *roi_para);
typedef int (*fun_ov4c_20880_crosstalk_calibration_raw10)(unsigned short *raw, unsigned char *eeprom_buf, int &size, int blc, double &max_gain, double &min_gain, double criteria);
typedef int (*fun_ov4c_16885_transform_bayer_raw10)(unsigned short *raw_in, unsigned short *raw_out, ROI_PARA *roi_para);
typedef int (*fun_ov4c_16885_crosstalk_calibration_raw10)(unsigned short *raw, unsigned char *eeprom_buf, int &size, int blc, double &max_gain, double &min_gain, double criteria);
typedef void (*fun_ov4c_release)();

class QHReadWriteLockManage
{
public: 
	QHReadWriteLockManage(QReadWriteLock* pstLock2 = 0, bool bWrite = false)
	{
		pstLock	=	pstLock2;
		if(bWrite){
			if(pstLock) pstLock->lockForWrite();
		}
		else{
			if(pstLock) pstLock->lockForRead();
		}
	}

	~QHReadWriteLockManage()
	{
		if(pstLock) pstLock->unlock();
	}

	void unlock(void)
	{
		if(pstLock) { pstLock->unlock(); pstLock = 0; }
	}

	QReadWriteLock* pstLock;
};

class QHDefaultLogManage
{
public:
	QHDefaultLogManage(HisFX3Log* pstSave2, _HisLog_Item* pstItem2, QVariant defaultValue2)
	{
		pstSave		=	pstSave2;
		pstItem		=	pstItem2;
		defaultValue	=	defaultValue2;
		uiRef			=	1;
	}

	~QHDefaultLogManage()
	{
		if(uiRef){
			pstItem->itemvalue	=	defaultValue;
			pstSave->push_back(*pstItem);
		}
	}

	__inline void SubRef(void)
	{
		if(uiRef) --uiRef;
	}

	unsigned int uiRef;
	HisFX3Log* pstSave;
	_HisLog_Item* pstItem;
	QVariant defaultValue;
};

enum _His_Draw_Type{
	HisDrawType_Block		=	0x1,
	HisDrawType_Line			=	0x2,
	HisDrawType_Text			=	0x3,
	HisDrawType_Rectfill		=	0x4,
	HisDrawType_Dashline	=	0x5,
	HisDrawType_Ellipse		=	0x6
};
 
enum _His_ItemStatus_Enum{
	_His_ItemStatus_PASS			=	0x0,
	_His_ItemStatus_NG				=	0x1,
	_His_ItemStatus_Testing		=	0x2
};

enum _His_SerialNumber_Source{
	_His_SerialNumber_Text		=	0x0,
	_His_SerialNumber_OTP		=	0x1,
	_His_SerialNumber_Vision		=	0x2,
	_His_SerialNumber_Chip		=	0x3
};

enum _shoutCutDetail_Status
{
	_shoutCutDetail_Status_Tested				= 0x1, 
	_shoutCutDetail_Status_GoTest			= 0x2 
};
 
struct _shoutCutDetail 
{
	char shortcutKey;
	bool bDualCamera;
	bool bMaster;
	bool bSync;
	unsigned char ucClickTime;
	unsigned char ucItemIndex;
	unsigned char ucloopTime;
	unsigned short usItem;
	unsigned short usItemfail;
	QString strAddInfo;
	quint8 status; 

	_shoutCutDetail()
	{
		bSync	=	false;
		bMaster =bDualCamera	=	false;
		ucloopTime		=	1;
		usItemfail			=	0;
		status				=	0;
	}
};
typedef QList<_shoutCutDetail> QShortcutList;

struct _HBarChart_Item{
	QColor stColor;
	double dflValue;
	QString strTitle;
	_HBarChart_Item()
	{
		dflValue	=	0.0;
		stColor		=	QColor::fromRgb(0,0,0);
	}
};

struct _HBarChart_SelfItem{
	unsigned int uiColorIndex; //0-red 1:green 2:yellow 3:blue 4:cyan 5:purple
	unsigned int uiGroupIndex;
	float flValue;
	float flDotLine;
	QString strTitle;
};

struct _HQwtCurve_Item{
	double dflX;
	QVector<double> vecValue;
	_HQwtCurve_Item()
	{
		dflX	=	0.0;
	}
};

union _drawdescrip{
	RECT stblock;
	char strtext[16];
	int idata[4];
	unsigned int uidata[4];
};


//***************************  2018.04.20 Add **************************
enum NgClass{
	NG_FA=0x01,
	NG_AFCNear,
	NG_AFCMiddle,
	NG_AFCFar,
	NG_OS,
	NG_WorkCurrent,
	NG_StandbyCurrent,
	NG_Preview,
	NG_Blemish,
	NG_DefectPixel,
	NG_OC,
	NG_Shading,
	NG_Vignetting,
	NG_Color,
	NG_Line,
	NG_LightPixel,
	NG_OTPBurn,
	NG_OTPBurnCheck,
	NG_AFBurn,
	NG_AFBurnCheck,
	NG_PDAFBurn,
	NG_PDAFBurnCheck,
	NG_Other
};


//************************************************************************


struct _HisFX3Global_TestStatistics{
	bool bEnable;
	unsigned char ucVersion;
	unsigned char ucItemCount;
	 
	unsigned int uiALL;
	unsigned int uiPASS;
	unsigned int uiFA;
	unsigned int uiAFCNear;
	unsigned int uiAFCMiddle;
	unsigned int uiAFCFar;
	unsigned int uiOS;
	unsigned int uiWorkCurrent;
	unsigned int uiStandbyCurrent;
	unsigned int uiPreview;
	unsigned int uiBlemish;
	unsigned int uiDefectPixel;
	unsigned int uiOC;
	unsigned int uiShading;
	unsigned int uiVignetting;
	unsigned int uiColor;
	unsigned int uiLine;
	unsigned int uiLightPixel;
	unsigned int uiOTPBurn;
	unsigned int uiOTPBurnCheck;
	unsigned int uiAFBurn;
	unsigned int uiAFBurnCheck;
	unsigned int uiPDAFBurn;
	unsigned int uiPDAFBurnCheck;
	unsigned int uiOther;

	void clear()
	{
		uiALL	=uiPASS	=uiFA	=uiAFCNear	=uiAFCMiddle	=uiAFCFar	=uiOS	=uiWorkCurrent	=uiStandbyCurrent	=0;
		uiPreview	=uiBlemish	=uiDefectPixel	=uiOC	=uiShading	=uiVignetting	=uiColor	=uiLine	=uiLightPixel	=0;
		uiOTPBurn	=uiOTPBurnCheck	=uiAFBurn	=uiAFBurnCheck	=uiPDAFBurn	=uiPDAFBurnCheck	=uiOther	=0;
	}

	_HisFX3Global_TestStatistics()
	{
		bEnable			=	true;
		ucVersion		=	1;
		ucItemCount	=	25;
		clear();
	}
};

//设置不同的测试项，图像上字的字体和粗体
struct _CumtomForivate_Config
{
	unsigned char ucImageFontSize, ucImageMTFFontSize, ucImageSFRFontSize, ucImageTVLineFontSize, ucImageOtherFontSize;
	bool bImageFontBold, bImageMTFFontBold, bImageSFRFontBold, bImageTVLineFontBold, bImageOtherFontBold;
	_CumtomForivate_Config()
	{
		ucImageOtherFontSize	=ucImageFontSize	=	9;
		bImageOtherFontBold =bImageFontBold		=	false;
		ucImageMTFFontSize =ucImageSFRFontSize =ucImageTVLineFontSize =12;
		bImageMTFFontBold	=bImageSFRFontBold =bImageTVLineFontBold =true;
	}
};

struct _imageShowPolicy{
	unsigned char ucMode; //0-fit size 1:sodoku 2-1.0x 3-2.0x 4-4.0x
	unsigned char ucSodokuPos; //7,8,9
													//4,5,6
													//1,2,3
	_imageShowPolicy()
	{
		ucMode				= 0;
		ucSodokuPos		= 5;
	}
};

struct _OperatorModeConfig{
	unsigned char ucMode; //0-normal 1-manual A  2-slave  3-manual B 4 Server
	bool bSaveLog;
	bool bShowTotalResult;
	unsigned char ucChartType;
	quint32 u32IpV4;
	quint16 u16SocketPort;
	quint8 u8TcpIpType;
	bool bSlaveFromArgv; //是否从main函数的行参接受参数
	quint16 u16SlaveMasterTimeout;


	unsigned char ucChartType_B;
	unsigned char ucPlugInterface; //0-MIPI C1  1-DVP 2-LVDS 
	char strPlug2ndName[8];
	float flPlugMin;
	float flPlugMax;
	unsigned char ucPlugScene; //0-None 1-Auto 2-FA 3-White Field 4-Black Field

	_OperatorModeConfig()
	{
		ucMode			=	1;
		bSlaveFromArgv	=bSaveLog		=	bShowTotalResult	=false;
		ucChartType_B	=ucChartType	=	_HisCCMAlg_Rolongo_Chart_MTF_A;
		u32IpV4	=	0x7F000001;
		u16SocketPort = 41589;
		u8TcpIpType	=	0;
		u16SlaveMasterTimeout	=	120;

		ucPlugScene	=ucPlugInterface		=	0;
		flPlugMin	=	5.0f;
		flPlugMax	=	800.0f;
		sprintf(strPlug2ndName, "RST");
	}
};

struct _ManualModeAConfig{
	unsigned int uiExposureValue_FA;
	unsigned int uiExposureValue_NearFC;
	unsigned int uiExposureValue_FarFC;
	unsigned int uiExposureValue_WhiteField;
	unsigned short usDelay;
	bool bBlemishON;
	bool bOCON;
	bool bLineON;
	bool bDefectPixelON;
	bool bColorON;
	bool bShadingON;
	bool bVignetON;

	_ManualModeAConfig()
	{
		uiExposureValue_FA	=uiExposureValue_NearFC	=uiExposureValue_FarFC	=uiExposureValue_WhiteField	=0;
		usDelay	=500;
		bBlemishON	=	true;
		bOCON	=bLineON	=bDefectPixelON	=bColorON	=bShadingON	=bVignetON	=false;
	}
}; 

 
struct _globalParameter{
	bool brun;
	bool bfaing;
	QReadWriteLock flagLocker;
	QMutex mutexDatabase;
	QMutex mutexDBUser;
	QMutex mutexOperate;
	bool bconfiglock; //lock 
	QString	strPassword;
	_OperatorModeConfig stOperatorMode;
// 	quint8 u8ShortcutMode; //0:Channel 1	1: Channel 2	2:Dual Camera
	bool bSlaveMotionFinish;
	PDH_HQUERY cpuQuery;
	PDH_HCOUNTER cpuTotal;

	bool bDebugMode;
	bool bSaveTextInfo2Local;
	bool bShowItem2EndResult;
	bool bShowResult2Image;
	bool bPaintCross;
	bool bPaintSquare;
	int  iSquaresizex,iSquaresizey;
	unsigned char ucAspectRatio; //0-IgnoreAspectRatio 1- KeepAspectRatio, 2-KeepAspectRatioByExpanding
	unsigned char ucScaleMode; //0-fast 1-smooth
	unsigned char ucSodokuMode; //0-Num[1~9] 1:arrow key

	unsigned char ucStatisticsDrawType;
	unsigned char ucGrabberIndex;
	unsigned int uiGrabberSerial[4];
	QString strFreindlyName;
	unsigned char ucFPGAUploadDelay;
	unsigned char ucFX3PacketSize;
	unsigned char ucChoosePlatform; //0-工装  1-UVC 2-RTSP
	
	QString	maxAddress;	
	double mouse_ptx;
	double mouse_pty;
	_CumtomForivate_Config stForivate;

	bool Jig_bRefreshImage;

	_globalParameter()
	{
		cpuQuery	=	0;
		cpuTotal		=	0;
		bPaintCross =brun	=	bfaing		=	bPaintSquare	=false;
		iSquaresizex=	iSquaresizey	=	0;
		ucAspectRatio		= 0;
		ucScaleMode		= 0;
		ucSodokuMode	= 1;
		Jig_bRefreshImage	=	false;
		bSaveTextInfo2Local	=bDebugMode		=	false;
		bShowItem2EndResult	=	true;
		bShowResult2Image		=	true;
		ucStatisticsDrawType	=	0;
		mouse_ptx	=	mouse_pty	=	0.0;
		ucGrabberIndex	=	0;
		memset(uiGrabberSerial, 0, sizeof(unsigned int) *4);
		ucFPGAUploadDelay	=	110;
		ucFX3PacketSize		=	16;
		ucChoosePlatform		=	0;

#ifdef _DEBUG
		bconfiglock	=	false;
#else
		bconfiglock	=	true;
#endif
	}

	~_globalParameter()
	{
		if(cpuQuery)	
		{
			if(cpuTotal) PdhRemoveCounter(cpuTotal);
			PdhCloseQuery(cpuQuery);
		}
	}

	__inline bool getrunflag()
	{
		flagLocker.lockForRead();
		bool bFlag	=	brun;
		flagLocker.unlock();
		return bFlag;
	}

	__inline void setrunflag(bool bstatus)
	{
		flagLocker.lockForWrite();
		brun	=	bstatus;
		flagLocker.unlock();
	}

	__inline bool getfaflag()
	{
		flagLocker.lockForRead();
		bool bFlag	=	bfaing;
		flagLocker.unlock();
		return bFlag;
	}

	__inline void setfaflag(bool bstatus)
	{
		flagLocker.lockForWrite();
		bfaing	=	bstatus;
		flagLocker.unlock();
	}

	__inline int IsCPUOk(unsigned int uiMaxPercent = 85, unsigned int uiTimeOut = 5000)
	{
		PDH_STATUS status;
		if(cpuQuery == NULL)
		{
			status = PdhOpenQueryW(NULL, NULL, &cpuQuery);
			if (ERROR_SUCCESS != status)	{
				if(cpuQuery) {PdhCloseQuery(cpuQuery);  cpuQuery = 0; }
				return 0;
			}

			status = PdhAddCounterW(cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &cpuTotal);
			if (ERROR_SUCCESS != status)	{
				if(cpuTotal) { PdhRemoveCounter(cpuTotal); cpuTotal = 0; }
				if(cpuQuery) {PdhCloseQuery(cpuQuery);  cpuQuery = 0; }
				return 0;
			}

			status = PdhCollectQueryData(cpuQuery);
			if (ERROR_SUCCESS != status)	{
				if(cpuTotal) { PdhRemoveCounter(cpuTotal); cpuTotal = 0; }
				if(cpuQuery) {PdhCloseQuery(cpuQuery);  cpuQuery = 0; }
				return 0;
			}
			Sleep(100);
		}

		unsigned int uiCount = 0;
		QElapsedTimer classTime;
		classTime.start();
		char strText[32];
		do {
			status = PdhCollectQueryData(cpuQuery);
			if (ERROR_SUCCESS != status)	return 0;

			PDH_FMT_COUNTERVALUE counterVal;
			status = PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_NOCAP100 | PDH_FMT_LONG, NULL, &counterVal);
			if (ERROR_SUCCESS != status)	return 0;

			sprintf(strText, "Total CPU: %d", counterVal.longValue);
			OutputDebugStringA(strText);

			if(counterVal.longValue < 60) break;

			if(counterVal.longValue < uiMaxPercent) ++uiCount;
			else	uiCount	=	0;

			if(uiCount >= 2) break;
			Sleep(10);
		} while (classTime.elapsed() < uiTimeOut);	

		return 0;
	}
};

struct _itemStatus{
	char shortcutKey;
	unsigned char ucClickTime;
	unsigned char ucItemIndex;
	unsigned char ucstatus;
	unsigned short usitem;
	unsigned __int32 ustime;
	int iErrorCode;

	_itemStatus(){
		ucClickTime	=	0xFF;
		ucstatus			=	_His_ItemStatus_Testing;
		ustime				=	0xFFFFFFFF;
		ucItemIndex		=	0xFF;
		iErrorCode		=	0;
	}
};

struct _itemDraw{
	unsigned short usitem;
	unsigned char uctype;
	int idata[2];
	QColor stcolor;
	_drawdescrip strinfo;
};

struct _bigvisionV1Parameter{
	bool bConfigValid;
	float flSpeedX1;
	float flSpeedX2;
	float flSpeedU;
	float flFAAbsX1;
	float flFAAbsX2;
	_bigvisionV1Parameter()
	{
		flSpeedX1	=flSpeedX2	=flSpeedU	=1.0f;
		flFAAbsX1	=	flFAAbsX2	=	0.0f;
		bConfigValid	=	false;
	}
};

struct _mtffaParameter{
	_HisCCMAlg_MTFBasic_Info stMTFBasic;
	std::vector<_HisCCMAlg_MTFItem_Info> vectorMTFItem;
};
 
struct _mtfAFCParameter{
	_HisCCMAlg_AFC_Tactics_Basic stTacticsBasic;
	_HisCCMAlg_MTFBasic_Info stMTFBasic;
	std::vector<_HisCCMAlg_MTFItem_Info> vectorMTFItem;
};

struct _lpMFAParameter{
	_HisCCMAlg_LPBasic_Info stLpBasic;
	std::vector<_HisCCMAlg_LPItem_Info> vectorLpItem; 
};

struct _lpAFCParameter{
	_HisCCMAlg_AFC_Tactics_Basic stTacticsBasic;
	_HisCCMAlg_LPBasic_Info stLpBasic;
	std::vector<_HisCCMAlg_LPItem_Info> vectorLpItem; 
};

struct _SFRFACAParameter{
	_HisCCMAlg_SFRPlusHABasic_Info stSFRBasic;
	std::vector<_HisCCMAlg_SFRPlusHAItem_Info> vectorSFRItem;
};

struct _SFRAFCCAParameter{
	_HisCCMAlg_AFC_Tactics_Basic stTacticsBasic;
	_HisCCMAlg_SFRPlusHABasic_Info stSFRBasic;
	std::vector<_HisCCMAlg_SFRPlusHAItem_Info> vectorSFRItem;
};
 
struct _ccmHardware
{
	bool b4Cell;
	bool bCheckFrameRight;
	unsigned char ucEESlave;
	unsigned int uiSensorFactory;
	QString sensortype;
	QString motortype;
	QString lenstype;
	QString projectname;
	QString machinetype;
	double dwdr,dopd,dactual;
	_ccmHardware()
	{
		bCheckFrameRight	=	true;
		b4Cell					=	false;
		ucEESlave			=	0;
		dwdr	=	dopd	=	dactual	=0;
		uiSensorFactory	=	_HisFX3_ImageSenor_Factory_OV;
	}
};

struct _workcurrentParameter {
	bool btestAVDD;
	bool btestDOVDD;
	bool btestAF;
	bool btestDVDD;
	bool btestVFUSE;
	bool btestPOW;
	bool btestTotal;
	float flSpecDOVDDMin;
	float flSpecDOVDDMax;
	float flSpecDVDDMin;
	float flSpecDVDDMax;
	float flSpecAVDDMin;
	float flSpecAVDDMax;
	float flSpecAFMin;
	float flSpecAFMax;
	float flSpecVFUSEMin;
	float flSpecVFUSEMax;
	float flSpecPOWMin;
	float flSpecPOWMax;
	float flTotalMin;
	float flTotalMax;
	_workcurrentParameter()
	{
		btestPOW	=btestAVDD =btestDOVDD =btestAF =btestDVDD =btestVFUSE =false;
	}
};

struct _standbycurrentParameter {
	bool btestAVDD;
	bool btestDOVDD;
	bool btestAF;
	bool btestDVDD;
	bool btestPOW;
	bool btestTotal;
	bool bPWND;
	bool bReset;
	bool bMCLK;
	bool bDVDDDown;

	float flSpecDOVDDMin;
	float flSpecDOVDDMax;
	float flSpecDVDDMin;
	float flSpecDVDDMax;
	float flSpecAVDDMin;
	float flSpecAVDDMax;
	float flSpecAFMin;
	float flSpecAFMax;
	float flSpecPOWMin;
	float flSpecPOWMax;
	float flTotalMin;
	float flTotalMax;
	unsigned int uiDelay;
	_standbycurrentParameter()
	{
		btestPOW	=btestAVDD	=	btestDOVDD	=	btestAF	=	btestDVDD	=	btestTotal	=	false;
		uiDelay	=	5000;
	}
};

struct _openshortParameter{
	bool bTestPositive;
	bool bTestNegtive;
	bool bTestShort;
	bool bTestOpen;
	bool bTestOhm;
	unsigned char ucOSSwitch;
	unsigned short usPositiveDelay;
	unsigned short usNegtiveDelay;
	unsigned short usShortDelay;
	unsigned short usOpenDelay;
	unsigned short usOhmDelay;
	std::vector<_HisFX3OS_Positive_Item> vectorPositive;
	std::vector<_HisFX3OS_Negtive_Item> vectorNegtive;
	std::vector<_HisFX3OS_Short_Item> vectorShort;
	std::vector<_HisFX3OS_Open_Item> vectorOpen;
	std::vector<_HisFX3OS_OHM_Item> vectorOhm;
	 
	_openshortParameter()
	{
		bTestPositive = bTestNegtive = bTestShort = bTestOpen = bTestOhm = false;
		ucOSSwitch	=	0; //0-MIPI 1-DVP
		usShortDelay	= usNegtiveDelay =usPositiveDelay	= usOpenDelay =	12;
		usOhmDelay	=	30;
	}
};
 
struct _savelogParameter{
	unsigned char ucSerialNumberSource;
	QString strSerialNumberFormat;
	QString strCHIPIDIIC;
	QString strChipIDSensorType;

	_savelogParameter()
	{
		ucSerialNumberSource	=	_His_SerialNumber_Text;
	}
};

struct _HisAlg_Blemish_HA_Config
{
	float blemish_flrange; 
	float blemish_corner;
	int blemish_ihighpass;
	int blemish_ilowpass;
	int blemish_iamplitude;
	int blemish_idev;

	_HisAlg_Blemish_HA_Config()
	{

	}
};

struct _HisAlg_Blemish_HB_Config
{
	unsigned char frames;
	bool blemishhb_RemoveDefectPixel;
	float blemishhb_Zone1Range;
	unsigned int blemishhb_Zone3X;
	unsigned int blemishhb_Zone3Y;
	float blemishhb_Zone1Spec[15];
	float blemishhb_Zone2Spec[15];
	float blemishhb_Zone3Spec[15];

	_HisAlg_Blemish_HB_Config()
	{
		frames = 1;
	}
};

struct _HisAlg_Blemish_HC_Config
{
	unsigned char frames;
	float flAreaMin;
	float flAreaMax;
	float flEdgeZone;
	float flCornerZone;
	float flTuning;
	_HisCCMAlg_BlemishHC_Spec stSpec[12];

	_HisAlg_Blemish_HC_Config()
	{
		flAreaMin	=	0.00001f;
		flAreaMax	=	0.125f;
		flCornerZone =flEdgeZone	=	0.05f;
		flTuning		=	2.0f;
		frames = 1;
	}
};

struct _HisAlg_Blemish_HD_Config
{
	QString strRawInfo;
	QString strOptionBin;
	double dflMaxEdgeDiff;
	_HisAlg_Blemish_HD_Config()
	{
		dflMaxEdgeDiff = 0.0;
		strRawInfo		=	"RawInfo_G532F_M_0705.bin";
		strOptionBin	=	"RSBT_OPT.bin";
	}
}; 

struct _blemishParameter
{
	unsigned __int8 blemishAlg;
	_HisAlg_Blemish_HA_Config stBlemishHA;
	_HisAlg_Blemish_HB_Config stBlemishHB;
	_HisAlg_Blemish_HC_Config stBlemishHC;
	_HisAlg_Blemish_HD_Config stBlemishHD;

	_blemishParameter()
	{
		blemishAlg				=	_HisAlg_SWITCH_C;
	}
};

struct _HisAlg_WPOC_HA_Config
{
	float oc_flpixelratio;
	float oc_fldeviation;
	_HisAlg_WPOC_HA_Config()
	{

	}
};

struct _HisAlg_WPOC_HB_Config
{
	float oc_flpixelratio;
	float oc_fldeviation;
	_HisAlg_WPOC_HB_Config()
	{
		oc_flpixelratio = 0.5f;
		oc_fldeviation = 30.0f;
	}
};

struct _wpOCParameter
{
	unsigned __int8 opticalcenterAlg;
	_HisAlg_WPOC_HA_Config stAlgHA;
	_HisAlg_WPOC_HB_Config stAlgHB;
	_wpOCParameter()
	{
		opticalcenterAlg		=	_HisAlg_SWITCH_B;
	}
};
 
struct _HisAlg_Shading_HC_Config
{
	QString strRawInfo;
	QString strTuneGain;
	QString strLightSource;
	float flYMin, flYMax, flYOffset; //YDev
	float flRGMin, flRGMax, flRGOffset;
	float flBGMin, flBGMax, flBGOffset;
	float flPPMin, flPPMax, flPPOffset;
	float flCornerMin, flCornerMax, flCornerOffset; //YMin
	float flVignetMin, flVignetMax, flVignetOffset;
	_HisAlg_Shading_HC_Config()
	{
		strRawInfo		=	"RawInfo_G532F_M_0705.bin";
		strLightSource	=	"LightGainOneRLST_ZKSPA00.bin";
		strTuneGain		=	"tune_gain.bin";
		flYOffset =flRGOffset =flBGOffset =flPPOffset =flCornerOffset =flVignetOffset =0.0f;
	}
};

struct _HisAlg_Shading_HD_Config //Convert alg E\ F
{
	unsigned short usBlockW;
	unsigned short usBlockH;
	float flPP_YMin;
	float flPP_YMax;
	float flPP_RGMin;
	float flPP_RGMax;
	float flPP_BGMin;
	float flPP_BGMax;

	//************   fengqiquan 2018/01/16 Add ***********************
	float qs_fRoiSize;
	int qs_iBlackLevel;
	float qs_fYDiff;
	
	float qs_ShadingY1_min;
	float qs_ShadingY2_min;
	float qs_ShadingY3_min;
	float qs_ShadingY4_min;
	float qs_ShadingY6_min;
	float qs_ShadingY7_min;
	float qs_ShadingY8_min;
	float qs_ShadingY9_min;
	float qs_ShadingR1_min;
	float qs_ShadingR2_min;
	float qs_ShadingR3_min;
	float qs_ShadingR4_min;
	float qs_ShadingR6_min;
	float qs_ShadingR7_min;
	float qs_ShadingR8_min;
	float qs_ShadingR9_min;
	float qs_ShadingB1_min;
	float qs_ShadingB2_min;
	float qs_ShadingB3_min;
	float qs_ShadingB4_min;
	float qs_ShadingB6_min;
	float qs_ShadingB7_min;
	float qs_ShadingB8_min;
	float qs_ShadingB9_min;

	float qs_ShadingY1_max;
	float qs_ShadingY2_max;
	float qs_ShadingY3_max;
	float qs_ShadingY4_max;
	float qs_ShadingY6_max;
	float qs_ShadingY7_max;
	float qs_ShadingY8_max;
	float qs_ShadingY9_max;
	float qs_ShadingR1_max;
	float qs_ShadingR2_max;
	float qs_ShadingR3_max;
	float qs_ShadingR4_max;
	float qs_ShadingR6_max;
	float qs_ShadingR7_max;
	float qs_ShadingR8_max;
	float qs_ShadingR9_max;
	float qs_ShadingB1_max;
	float qs_ShadingB2_max;
	float qs_ShadingB3_max;
	float qs_ShadingB4_max;
	float qs_ShadingB6_max;
	float qs_ShadingB7_max;
	float qs_ShadingB8_max;
	float qs_ShadingB9_max;

	//************   fengqiquan 2019/01/26 Add ***********************
	int iROIWNumber_AlgF;
	int iROIHNumber_AlgF;
	float fMinMaxRatioSpec_AlgF;


	_HisAlg_Shading_HD_Config()
	{
		usBlockW	=	17;
		usBlockH		=	15;
		flPP_YMin	=flPP_RGMin		=flPP_BGMin	=0.3f;
		flPP_YMax	=	flPP_RGMax	=flPP_BGMax	=	0.6f;
	}
};

struct _wpShadingParameter
{
	unsigned __int8 shadingAlg;
	_HisAlg_Shading_HA_Config stShadingConfigHA;
	_HisAlg_Shading_HB_Config stShadingConfigHB;
	_HisAlg_Shading_HC_Config stShadingConfigHC;
	_HisAlg_Shading_HD_Config stShadingConfigHD;
	_HisAlg_Shading_HD_Config stShadingConfigHE;
	_HisAlg_Shading_HD_Config stShadingConfigHF;
	_wpShadingParameter()
	{
		shadingAlg				=	_HisAlg_SWITCH_A;
	}
}; 

struct _wpVignetingParameter
{
	unsigned __int8 vignettingAlg;
	_HisAlg_Vignetting_HA_Config stVignettingConfigHA;
	_wpVignetingParameter()
	{
		vignettingAlg			=	_HisAlg_SWITCH_A;
	}
};

struct _HisAlg_WPColor_HA_Config
{
	float color_flideala;	//中心区域理想a分量平均值(Lab空间)
	float color_flidealb; //中心区域理想b分量平均值(Lab空间)
	float color_flcenterrange; //中心区域比例
	int color_iwithblocks; //行分块
	float color_fluniform; //颜色均匀性规格
	float color_flaberration; //中心区域实际与理想偏差
	float color_flsym; //四周对称最大颜色差异
	float color_flfalloff;	//中心与四周最大颜色差异
	 
	_HisAlg_WPColor_HA_Config()
	{	
	}
};

struct _HisAlg_WPColor_HB_Config
{
	unsigned char ucGMin, ucGMax, ucROINumW, ucROINumH;
	float flCenterRatio, flRGMin, flRGMax, flBGMin, flBGMax, flCCRGMin, flCCRGMax, flCCBGMin, flCCBGMax;
	float flConerPP_RGMin, flConerPP_RGMax, flConerPP_BGMin, flConerPP_BGMax;
	float flAllPP_RGMin, flAllPP_RGMax, flAllPP_BGMin, flAllPP_BGMax;
	_HisAlg_WPColor_HB_Config()
	{
		ucGMin = 170;  ucGMax = 230; ucROINumW = 17; ucROINumH = 13;
		flCenterRatio = 0.1f; flRGMin = flBGMin = 0.6f; flRGMax = flBGMax = 0.7f;
		flCCRGMin = flCCBGMin = 0.9f; flCCRGMax = flCCBGMax = 1.1f;
		flConerPP_RGMin =flConerPP_BGMin = 0.8f; flConerPP_RGMax = flConerPP_BGMax = 0.9f;
		flAllPP_RGMin =flAllPP_BGMin = 0.8f; flAllPP_RGMax = flAllPP_BGMax = 0.9f;
	}
};

struct _wpColorParameter
{
	unsigned __int8 colorAlg;
	_HisAlg_WPColor_HA_Config stAlgHA;
	_HisAlg_WPColor_HB_Config stAlgHB;
	_wpColorParameter()
	{
		colorAlg					=	_HisAlg_SWITCH_B;
	}
};

struct _HisAlg_WPDefectPixel_HA_Config
{
	float defectpixel_fldefect;
	float defectpixel_flwound;
	float defectpixel_fldead;
	unsigned char defectpixel_ucdefectscore;
	unsigned char defectpixel_ucwoundscore;
	unsigned char defectpixel_ucdeadscore;
	int defectpixel_iclusterscore;
	int defectpixel_iwidthblocks;
	int defectpixel_ispecdefect;
	int defectpixel_ispecwound;
	int defectpixel_ispecdead; 
	int defectpixel_itotalscore;
	int defectpixel_ispeccluster;
	int defectpixel_iclustermaxscore;
	_HisAlg_WPDefectPixel_HA_Config()
	{

	}
};

struct _HisAlg_WPDefectPixel_HB_Config
{
	float flDefectMin;
	float flWoundMin;
	float flDeadMin;
	float flDefectMax;
	float flWoundMax;
	float flDeadMax;
	float defectpixelhb_flCenterRange;
	unsigned int defectpixelhb_uiBlockSize;
	bool defectpixelhb_bPerChannel; 
	unsigned int defectpixelhb_uiCenterDefectSingle;
	unsigned int defectpixelhb_uiCenterWoundSingle; 
	unsigned int defectpixelhb_uiCenterDeadSingle;
	unsigned int defectpixelhb_uiCenterDefectClusterMax;
	unsigned int defectpixelhb_uiCenterWoundClusterMax;
	unsigned int defectpixelhb_uiCenterDeadClusterMax;
	unsigned int defectpixelhb_uiEdgeDefectSingle;
	unsigned int defectpixelhb_uiEdgeWoundSingle;
	unsigned int defectpixelhb_uiEdgeDeadSingle;
	unsigned int defectpixelhb_uiEdgeDefectClusterMax;
	unsigned int defectpixelhb_uiEdgeWoundClusterMax;
	unsigned int defectpixelhb_uiEdgeDeadClusterMax;
	_HisAlg_WPDefectPixel_HB_Config()
	{
		flDefectMin	=	-0.3f; flDefectMax	=	0.3f;
		flWoundMin	=	-0.5f; flWoundMax	=	0.5f;
		flDeadMin	=	-0.7f; flDeadMax		=	0.7f;
	}
};

struct _wpDefectPixelParameter
{
	bool bSaveDefectPixelCalImage;
	unsigned __int8 defectpixelAlg;
	_HisAlg_WPDefectPixel_HA_Config stAlgHA;
	_HisAlg_WPDefectPixel_HB_Config stAlgHB;
	_wpDefectPixelParameter()
	{
		defectpixelAlg			=	_HisAlg_SWITCH_A;
		bSaveDefectPixelCalImage=false;
	}
};

struct _HisAlg_WPLine_HA_Config
{
	float line_flspec_r;
	float line_flspec_g;
	float line_flspec_b;
	_HisAlg_WPLine_HA_Config()
	{

	}
};

struct _wpDefectLineParameter
{
	unsigned __int8 defectlineAlg;
	_HisAlg_WPLine_HA_Config stAlgHA;
	_wpDefectLineParameter()
	{
		defectlineAlg			=	_HisAlg_SWITCH_A;
	}
};

struct _wpSNRParameter
{
	_wpSNRParameter()
	{

	}
};

struct _HisAlg_BPLightPixel_HA_Config
{
	unsigned __int8 ui8CenterRatio;
	unsigned __int8 ui8LightPixelDef;
	unsigned int uiClusterDef;
	unsigned int uiSpecCenterPixel;
	unsigned int uiSpecAroundPixel;
	unsigned int uiSpecCenterCluster;
	unsigned int uiSpecAroundCluster;
	unsigned int uiSpecMaxCluster;
	_HisAlg_BPLightPixel_HA_Config()
	{
		ui8CenterRatio	=	70;
		ui8LightPixelDef	=	10;
		uiClusterDef		=	2;
		uiSpecCenterPixel	=	1000;
		uiSpecAroundPixel	=	5000;
		uiSpecCenterCluster	=	2;
		uiSpecAroundCluster	=	3;
		uiSpecMaxCluster		=	4;
	}
};

struct _HisAlg_BPLightPixel_HB_Config
{
	unsigned char ucBlackLevel;
	float flRGMin;
	float flRGMax;
	float flBGMin;
	float flBGMax;
	float flPPMin;
	float flPPMax;
	_HisAlg_BPLightPixel_HB_Config()
	{
		ucBlackLevel	=	0;
		flRGMin	=	flBGMin	=	flPPMin	=	-100.0f;
		flRGMax	=	flBGMax	=	flPPMax	=	100.0f;
	}
};

struct _HisAlg_BPLightPixel_HC_Config
{
	unsigned char ucBlackLevel;
	float flThreshold;
	float flChannelMax;
	float flCellMax;
	_HisAlg_BPLightPixel_HC_Config()
	{
		ucBlackLevel	=	0;
		flThreshold		=   0;
		flChannelMax = 1;
		flCellMax =1;
	}
};


struct _blackfiledParameter 
{
	unsigned __int8 ui8BlackFiledAlg;
	_HisAlg_BPLightPixel_HA_Config stAlgA;
	_HisAlg_BPLightPixel_HB_Config stAlgB;
	_HisAlg_BPLightPixel_HC_Config stAlgC;
	_blackfiledParameter()
	{
		ui8BlackFiledAlg	=	_HisAlg_SWITCH_A;
	}
};

struct _HisAlg_LSCheck_HA_Config
{
	float flROIW;
	float flROIH;
	float flRGMin;
	float flRGMax;
	float flBGMin;
	float flBGMax;
	float flGMin;
	float flGMax;
	_HisAlg_LSCheck_HA_Config()
	{
		flROIW	=	flROIH = 0.2f;
		flGMin	=	180.0f; flGMax = 190.0f;
		flRGMin	= flBGMin		= 0.3f;
		flRGMax	=	flBGMax	=	0.6f;
	}
};

struct _HisAlg_LSCheck_HB_Config
{
	QString strRawInfo;
	float flRGMin;
	float flRGMax;
	float flBGMin;
	float flBGMax;
	float flPPMin;
	float flPPMax;
	_HisAlg_LSCheck_HB_Config()
	{
		flPPMin	=	flRGMin	= flBGMin		= 0.3f;
		flPPMax	=	flRGMax	=	flBGMax	=	0.6f;
		strRawInfo	=	"RawInfo_G532F_M_0705.bin";
	}
};

struct _lightsourcecheckParameter
{
	unsigned char ucAlg;
	_HisAlg_LSCheck_HA_Config stAlgA;
	_HisAlg_LSCheck_HB_Config stAlgB;
	_lightsourcecheckParameter()
	{
		ucAlg	=	_HisAlg_SWITCH_A;
	}
};

struct _otpburnParameter
{
	bool bburn;
	bool bOnlyCheckData;
	bool bBurnOpticalCenter;
	unsigned int uiIndex;
	double dflLightCoeB;
	double dflLightCoeR;
	unsigned int uiBlockSize;
	unsigned int uiFrameSleep;
	unsigned int uiMID;
	unsigned int uiLENSID;
	unsigned int uiVCMID;
	unsigned int uiDRIVERICID;
	float flRangeRatio;
	unsigned int uiLuxMin;
	unsigned int uiLuxMax;
	unsigned int uiDark;
	float flLSC_LuxShadingMin;
	float flLSC_LuxShadingMax;
	float flLSC_LuxShadingUniform;
	float flLSC_LuxSymmMax;
	float flLSC_CenterR2GrMin;
	float flLSC_CenterR2GrMax;
	float flLSC_CenterB2GrMin;
	float flLSC_CenterB2GrMax;
	float flLSC_WB2CenterMax_R2Gr;
	float flLSC_WB2CenterMax_B2Gr;
	int  iOCXDeviationMax;
	int  iOCYDeviationMax;
	QString pairConfig;
	QString strFunctionChoose;

	_otpburnParameter()
	{
		bOnlyCheckData	=	false;
		bburn					=	false;
		bBurnOpticalCenter=false;
	}
};


struct _afburnParameter{
	bool bNear;
	bool bMiddle; 
	bool bInfinite;
	int iNearMotorOffset;
	int iMiddleMotorOffset;
	int iFarMotorOffset;
	int iNearMotorMin;
	int iNearMotorMax;
	int iMiddleMotorMin;
	int iMiddleMotorMax;
	int iFarMotorMin;
	int iFarMotorMax;
	unsigned int uiFrameDelay;
	unsigned int uiMachineCode;
	QString strFunctionChoose;

	//******************* 20190817 **********************************
	bool bRecalCheck;
	int iRecalSpec;

	_afburnParameter()
	{
		bNear	=	bMiddle	=	bInfinite	=	false;
		uiFrameDelay		=	650;
		uiMachineCode	=	0x0;
		iNearMotorOffset	=	iMiddleMotorOffset	=	iFarMotorOffset	=	0;
		iNearMotorMin		=	iMiddleMotorMin		=	iFarMotorMin		=	0;
		iNearMotorMax	=	iMiddleMotorMax		=	iFarMotorMax		=	1023;
		bRecalCheck=false;
		iRecalSpec=50;
	}
};



struct _pdafParameter{
	bool bWhiteMove2NearFocus;
	bool bQualcommpdafverify;
	bool bQualcomm50CMexp;
	bool bPDAFVerifyMTFDropStop;
	bool bSONY258MTKCal;
	unsigned char ucPlatform; //0-MTK  1-Qualcomm 2 SONY
	QChar cVersion;
	unsigned short usVersion[4];
	unsigned short uiMotorSleep;
	unsigned short uiIO3Sleep;
	unsigned short uiIO4Sleep;
	unsigned short uiIO5Sleep;
	unsigned short uiIO6Sleep;
	unsigned short uiIO7Sleep;
	unsigned short uiIO8Sleep;
	unsigned short uiIO9Sleep;
	unsigned short usQualcommGainMapSize;
	unsigned short usQualcommkverifyoffest;
	unsigned short usVerifyDACShiftCount;
	unsigned short usDACMoveStep;
	unsigned short usCDAFmtfROIW;
	unsigned short usCDAFmtfROIH;
	unsigned short usAutoExpsoureROIW;
	unsigned short usAutoExposureROIH;
	unsigned short us50CMEVDelayTime;
	unsigned short usMTKV2Step1dataSize;
	unsigned short usMTKV2Step2dataSize;
	QString strQualcommChoose;
	QString strAFChoose;
	QString strPDAFChoose;
	QString strHISIPDAFChoose;
	QString strSONYPDAFChoose;
	std::string  strQualcommGainMapStruct;
	unsigned short usSonySPCTableSize;
	unsigned char ucSonyDCCWindow;  // 0 8*6   1: 16*12     2 flexible
	unsigned char  ucSonySensorMode; //0 imx230 1 imx298
	double  dDCCVerifySpec;
	bool bEnableMTKStep2Verify;
	 unsigned char ucpdafsensortype; //SPARSE sensor 0 / dual pd sensor 1
	 unsigned short usSensorBlackLevel;
	_pdafParameter()
	{
		uiMotorSleep =uiIO3Sleep	=	uiIO4Sleep	=	uiIO5Sleep	=uiIO6Sleep	=uiIO7Sleep	=uiIO8Sleep	=uiIO9Sleep	=1000;
		ucPlatform	=	0;
		usQualcommGainMapSize	=	221;
		bWhiteMove2NearFocus = true;
		bQualcomm50CMexp=true;
		bQualcommpdafverify=true;
		usVerifyDACShiftCount=20;
		usDACMoveStep=4;
		memset(usVersion, 0, sizeof(unsigned short) *4);
		cVersion	=	'J';
		ucpdafsensortype=99;
		usSensorBlackLevel=64;
	}
};

struct _dualCameraParameter{
	bool bburn;
	bool bOnlyCheckData;
	double dChart2lensDistance_Rotation; 
	double dFocusLength_Rotation;
	double dCycleDistanceHorizontal_Rotation;
	double dCycleDistanceVertical_Rotation;
	double dMaxTiltX;
	double dMaxTiltY;
	double dMaxRotation;
	double dMinTiltX;
	double dMinTiltY;
	double dMinRotation;
	double dCameraCenterXShift;
	double dCameraCenterYShift;
	QString strDualCameraBurnChoose;

	bool bCoaxialityburn;
	bool bCoaxialityOnlyCheckData;
	QString strDualCameraCoaxialityBurnChoose;
	double dDualCameraCenterDistance;
	double dSquare_HorizontalDistance;
	double dSquare_VerticalDistance;
	double dCoaxialityTestDistance;
	bool bMainCameraColorSensor;
	bool bSubCameraColorSensor;
	double dMaxAngleX;
	double dMaxAngleY;
	double dMaxAngleZ;
	int iMaxShiftX;
	int iMaxShiftY;

	_dualCameraParameter()
	{
		bburn=bOnlyCheckData=bCoaxialityburn=bCoaxialityOnlyCheckData=false;
		dChart2lensDistance_Rotation=500;
		dFocusLength_Rotation=dCycleDistanceHorizontal_Rotation=dCycleDistanceVertical_Rotation=0;
		dMaxAngleX=dMaxAngleY=dMaxAngleZ=0.0f;
		dMaxTiltX=dMaxTiltY=dMaxRotation=0.0f;
		dMinTiltX=dMinTiltY=dMinRotation=0.0f;
	}
};

struct _DPCParameter{
		QString strDPCRuleChoose;
	_DPCParameter()
	{
		strDPCRuleChoose.clear();
	}
};

struct _RJAutoFocusParameter{
	bool bMotionEnable;
	_HisCCMAlg_AFA_Tactics_Basic stTacticsBasic;
	_HisCCMAlg_AFA_Tractics_CCW_PASS stCCWPass;
	_HisCCMAlg_AFA_Tractics_CCW_BEST stCCWBest;
	_HisCCMAlg_LPBasic_Info stLpBasic;
	std::vector<_HisCCMAlg_LPItem_Info> vectorLpItem;

	_RJAutoFocusParameter()
	{
		bMotionEnable	=	true;
	}
};
 
struct _HisCCMCustomIICParatemer{
	unsigned short usCount;
	unsigned char* pucSlave;
	unsigned int* puiAddr;
	unsigned int* puiData;
	unsigned short* pusType;
	_HisCCMCustomIICParatemer()
	{
		usCount	=	0;
		pucSlave	=	NULL;
		puiAddr	=	NULL;
		puiData	=	NULL;
		pusType	=	NULL;
	}

	~_HisCCMCustomIICParatemer()
	{
		HisReleaseNewB(pucSlave);
		HisReleaseNewB(puiAddr);
		HisReleaseNewB(puiData);
		HisReleaseNewB(pusType);
		usCount	=	0;
	}
};
 
enum _plot_mtfbar_item_type{
	PlotMtfbarItemType_Space		=	0x2,
	PlotMtfbarItemType_Ng			=	0x1,
	PlotMtfbarItemType_Pass		=	0x0
};

struct _plot_mtfbar_item{
	float flvalue;
	float flspec;
	float flmax;
	unsigned char uctype;
	QColor rangecolor;
};

struct  _focuscheckCurvePlotItem{
	__int32 istep;
	bool bpass;
	float flweightvalue;
};

struct SONY_PDAF_PDInfo
{
	int Phase_diff_16_12[192];
	int  Coef_16_12[192];
	int Phase_diff_8_6[48];
	int  Coef_8_6[48];
};

struct SONY_PDAF_DCCRes
{
	unsigned short DCC_16_12[192];
	unsigned short DCC_8_6[48];
	int DACOut_16_12[192];
	int DACOut_8_6[48];
	float InfocusdPDPixel_16_12[192];
	float InfocusdPDPixel_8_6[48];
	int DCCVerifyRes16_12[192];
	int DCCVerifyRes8_6[48];
	int DACCenterOut_16_12;
	int DACCenterOut_8_6;
};

struct DCCVerify
{
	int PDWindowIndex_16_12[5];
	int PDWindowIndex_8_6[5];
	int DCCVerify_FlexibleWindow;
};
  
struct _global_itemexec{
	bool bOK2;
	bool bNG;
	QString currentTableName; 
	bool bdatabasevalid;
// 	bool bfunctionflag;
	int totalresult;
	char shortcutKey;
	unsigned char ucClickTime;
	unsigned char ucItemIndex;
	int iWheelPosition;
	 
	_ManualModeAConfig stManualModeA;
 	  
	QShortcutList shortcutgather;
	_HisFX3_PreviewStruct* previewParameter; 
	_mtffaParameter* mtffaParameter;
	_ccmHardware* ccmhardwareParameter;
	_blemishParameter* blemishParameter;
	_wpOCParameter* wpOCParameter;
	_wpShadingParameter* wpShadingParameter;
	_wpVignetingParameter* wpVignetingParameter;
	_wpColorParameter* wpColorParameter;
	_wpDefectPixelParameter* wpDefectPixelParameter;
	_wpDefectLineParameter* wpDefectLineParameter;
	_wpSNRParameter* wpSNRParameter;
	_mtfAFCParameter* mtfnearafcParameter;
	_mtfAFCParameter* mtfmiddleafcParameter;
	_mtfAFCParameter* mtffarafcParameter;
	_workcurrentParameter *workcurrentParameter;
	_standbycurrentParameter *standbycurrentParameter;
	_otpburnParameter* otpburnParameter;
	_lightsourcecheckParameter* lightsourcecheckParameter;
	_savelogParameter* savelogParameter;
	_afburnParameter* afburnParameter;
	_blackfiledParameter* blackfieldParameter;
	_pdafParameter* pdafParameter;
	_dualCameraParameter* dualCameraParameter;
	_DPCParameter  *dpcParameter;
	_SFRFACAParameter* sfrfacaParameter;
	_SFRAFCCAParameter* sfrnearafcParameter;
	_SFRAFCCAParameter* sfrmiddleafcParameter;
	_SFRAFCCAParameter* sfrfarafcParameter;
	_RJAutoFocusParameter* rjafmParameter;
	_lpAFCParameter* lpnearafcParameter;
	_lpAFCParameter* lpmiddleafcParameter;
	_lpAFCParameter* lpfarafcParameter;
	_lpMFAParameter* lpmfaParameter;
	_openshortParameter* openshortParameter;
	_HisAutoFA_BASIC_STACTICS* afaBasicStacticsParameter;
	_AutoFA_YIOUV1_EQUI_CONFIG* afaYIOUV1Parameter;
	_HisCCMCustomIICParatemer* customIICG1Parameter;
	_HisCCMCustomIICParatemer* customIICG2Parameter;
	_HisCCMCustomIICParatemer* customIICG3Parameter;
	_HisCCMCustomIICParatemer* customIICG4Parameter;
	_bigvisionV1Parameter* bigvisionv1Parameter;
	 
	QImage plotimage;

	QVector<_HBarChart_SelfItem> vecBarChartItem;
	double dflBarChartYMin;
	double dflBarChartYMax;

	QVector<_HQwtCurve_Item> vecCurvePoint;
	QVector<QColor> vecCurveLineColor;
	QVector<QString> vecCurveLegend;
	double dflCurveYMin;
	double dflCurveYMax;
	double dflCurveXMin;
	double dflCurveXMax;
	bool bCurveXScaleAuto;
	unsigned char ucCurveType;

	QReadWriteLock plotLock;
	QReadWriteLock flagLock;
	QReadWriteLock itemparameterLock;
	QReadWriteLock drawLock;
	QReadWriteLock itemstatusLock;
	QMutex mutexItemExec;

	QList<_itemStatus> itemstatusList;
	std::vector<_itemDraw> itemdrawList;
	quint16 tcpip_port;
	QString tcpip_ip;
	QString offlinepath;
	bool breadsamepicture;
	unsigned char ucOfflineloadimage;
	int iSocketReceiveTimeOut;
	void clear(void)
	{
		HisReleaseNewO(previewParameter);
		HisReleaseNewO(mtffaParameter);
		HisReleaseNewO(ccmhardwareParameter);
		HisReleaseNewO(blemishParameter);
		HisReleaseNewO(wpOCParameter);
		HisReleaseNewO(wpShadingParameter);
		HisReleaseNewO(wpVignetingParameter);
		HisReleaseNewO(wpColorParameter);
		HisReleaseNewO(wpDefectPixelParameter);
		HisReleaseNewO(wpDefectLineParameter);
		HisReleaseNewO(wpSNRParameter);
		HisReleaseNewO(mtfnearafcParameter);
		HisReleaseNewO(mtfmiddleafcParameter);
		HisReleaseNewO(mtffarafcParameter);
		HisReleaseNewO(workcurrentParameter);
		HisReleaseNewO(standbycurrentParameter);
		HisReleaseNewO(otpburnParameter);
		HisReleaseNewO(lightsourcecheckParameter);
		HisReleaseNewO(savelogParameter);
		HisReleaseNewO(afburnParameter);
		HisReleaseNewO(blackfieldParameter);
		HisReleaseNewO(pdafParameter);
		HisReleaseNewO(sfrfacaParameter);
		HisReleaseNewO(rjafmParameter);
		HisReleaseNewO(lpnearafcParameter);
		HisReleaseNewO(lpmiddleafcParameter);
		HisReleaseNewO(lpfarafcParameter);
		HisReleaseNewO(lpmfaParameter);
		HisReleaseNewO(openshortParameter);
		HisReleaseNewO(sfrnearafcParameter);
		HisReleaseNewO(sfrmiddleafcParameter);
		HisReleaseNewO(sfrfarafcParameter);
		HisReleaseNewO(afaBasicStacticsParameter);
		HisReleaseNewO(afaYIOUV1Parameter);
		HisReleaseNewO(customIICG1Parameter);
		HisReleaseNewO(customIICG2Parameter);
		HisReleaseNewO(customIICG3Parameter);
		HisReleaseNewO(customIICG4Parameter);
		HisReleaseNewO(bigvisionv1Parameter);
		HisReleaseNewO(dpcParameter);
		shortcutgather.clear();
	}

	_global_itemexec()
	{
		ucCurveType		=	0;
		bdatabasevalid	=	true;
		totalresult				=	_His_ItemStatus_Testing;
		iWheelPosition	=	0;
		itemdrawList.reserve(80);
		itemstatusList.reserve(20);

		previewParameter				=	NULL; 
		mtffaParameter					=	NULL;
		ccmhardwareParameter		=	NULL;
		blemishParameter				=	NULL;
		wpOCParameter					=	NULL;
		wpShadingParameter			=	NULL;
		wpVignetingParameter		=	NULL;
		wpColorParameter				=	NULL;
		wpDefectPixelParameter	=	NULL;
		wpDefectLineParameter		=	NULL;
		wpSNRParameter				=	NULL;
		workcurrentParameter		=	NULL;
		standbycurrentParameter	=	NULL;
		otpburnParameter				=	NULL;
		lightsourcecheckParameter=	NULL;
		savelogParameter				=	NULL;
		afburnParameter					=	NULL;
		blackfieldParameter			=	NULL;
		pdafParameter					=	NULL;
		sfrfacaParameter				=	NULL;
		rjafmParameter					=	NULL;
		lpnearafcParameter			=	NULL;
		lpmiddleafcParameter			=	NULL;
		lpfarafcParameter				=	NULL;
		lpmfaParameter					=	NULL;
		openshortParameter			=	NULL;
		afaBasicStacticsParameter			=	NULL;
		afaYIOUV1Parameter			=	NULL;
		mtfnearafcParameter	=	mtfmiddleafcParameter	=	mtffarafcParameter	=	NULL;
		sfrnearafcParameter = sfrmiddleafcParameter = sfrfarafcParameter = NULL;
		customIICG1Parameter =customIICG2Parameter = customIICG3Parameter =customIICG4Parameter =NULL;
		bigvisionv1Parameter		=	NULL;
		tcpip_port	=0;
		tcpip_ip	="";
		offlinepath	="";
		breadsamepicture	=	false;
		ucOfflineloadimage	=	0;
		iSocketReceiveTimeOut=1000;
	}

	~_global_itemexec()
	{
		clear();
	}

	__inline void setTotalResult(int iresult)
	{
		itemstatusLock.lockForWrite();
		totalresult	=	iresult;
		if(!iresult) itemstatusList.clear();
		itemstatusLock.unlock();
	}

	__inline int getTotalResult()
	{
		itemstatusLock.lockForRead();
		int iresult	=	totalresult;
		itemstatusLock.unlock();
		return iresult;
	}
	 
	__inline void clearDrawList()
	{
		drawLock.lockForWrite();
		itemdrawList.clear();
		drawLock.unlock();
	}

	__inline void shortcutInit(char shortcutKey, unsigned char ucClickTime, bool bDualCamera)
	{	
		itemstatusLock.lockForWrite();
		for (QList<_shoutCutDetail>::iterator theiterator = shortcutgather.begin(); theiterator != shortcutgather.end(); theiterator++)
		{
			if((theiterator->shortcutKey == shortcutKey) && (theiterator->ucClickTime == ucClickTime) && (theiterator->bDualCamera == bDualCamera))
			{
				theiterator->status	=	0;
			}
		}
		itemstatusLock.unlock();
	}
}; 

extern _global_itemexec itemshareDataC1;
extern _global_itemexec itemshareDataC2;

struct _threadshareData
{
	QReadWriteLock flaglock;
	bool bKeepLoop; //图像旗标
	bool bTesting;
	bool bBoxChannel1;
	QReadWriteLock raw2lock;
	QReadWriteLock rgb2lock;
	unsigned __int64 ui64IndexStamp;
	unsigned char* pucRaw1;
	unsigned char* pucRaw2;
	unsigned char* pucRawX;
	unsigned int uiRawBufByte;
	unsigned __int64 ui64Raw1Index;
	unsigned __int64 ui64Raw2Index; 

	unsigned char* pucRGB1;
	unsigned char* pucRGB2;
	unsigned __int64 ui64RGB2Index;

	bool bBlemishEnhaceShow;
	_imageShowPolicy stImageShowPolicy;
	QReadWriteLock pixmaplock; 
	unsigned char* pucDrawImageRGB24;
	int iDrawImageWidth;
	int iDrawImageHeight;
	RECT stDrawImageROI;
	int iDrawImageOffsetLeft;
	int iDrawImageOffsetTop;

	_HisFX3Global_TestStatistics stStatisticsHistory;
	_HisFX3Global_TestStatistics stStatisticsNow;

	bool bslotItemExecGoing;
	int isoltItemExecResult;
	  
	bool bIsexposure;
	float  flExposure;
	bool bSetGlobalGain;
	float flGlobalGainValue;

	unsigned char ucFormat;
	unsigned char ucInterpolation;
	unsigned char ucSlave;
	unsigned int uiWidth;
	unsigned int uiHeight;
	unsigned short usWaitPreviewDataTime;
	bool bLSC;
	bool bGrayImage;
	bool bOutputErrorFrame;
	wchar_t wstrLSCTemplatePath[260];

	//AWB
	bool bAWB;
	bool bUseSensorAWBGain;
	unsigned char ucAWB_Method;
	unsigned char ucAWB_RefreshRate;
	float flAWB_GainR;
	float flAWB_GainB;

	//Black Level
	unsigned char ucBlackLevel;

	//Mirror / Flip
	bool bMirrorON;
	bool bFlipON;

	QString strSerialNumber;

	unsigned char ucUPH10m[6];
	unsigned char ucUPH10mIndex;
	QElapsedTimer timerUPH;

	bool bSavingImage;
	bool brawrun;
	bool brgbrun;
	bool brenderrun;
	bool bOfflineMode;
	unsigned char ucOfflineloadimage;

	_threadshareData(bool bChannel1)
	{
		bBoxChannel1	=	bChannel1;
		ucBlackLevel	=ucInterpolation	=ucFormat			=	0;
		bGrayImage =bSavingImage =bOfflineMode =brawrun =brenderrun =brgbrun = false;
		ucOfflineloadimage	=0;
		isoltItemExecResult	=	0;
		usWaitPreviewDataTime	=	2500;
		bMirrorON =bFlipON =bAWB =bLSC =bBlemishEnhaceShow	=bTesting =bKeepLoop =bOutputErrorFrame	=	false;
		bIsexposure		=bSetGlobalGain =bslotItemExecGoing =	false;
		pucRawX =pucRaw1	=	pucRaw2	=	pucRGB1	=	pucRGB2	=	pucDrawImageRGB24 = 0;
		uiHeight	= uiWidth	= uiRawBufByte = iDrawImageHeight = iDrawImageWidth = 0;
		ui64IndexStamp =ui64Raw1Index=ui64Raw2Index	= ui64RGB2Index = 0;
		flGlobalGainValue = flAWB_GainR	=	flAWB_GainB	=	1.0f;
		bUseSensorAWBGain = false;

		memset(ucUPH10m, 0, sizeof(unsigned char) *6);
		ucUPH10mIndex	=	0;
		timerUPH.start();
	}

	~_threadshareData()
	{
		HisReleaseMalloc(pucRaw1);
		HisReleaseMalloc(pucRaw2);
		HisReleaseMalloc(pucRGB1);
		HisReleaseMalloc(pucRGB2);
		HisReleaseMalloc(pucDrawImageRGB24);
	}

	__inline void ClearDSPFlag(void)
	{
		flaglock.lockForWrite();
		bMirrorON = bFlipON =bAWB =bLSC =bBlemishEnhaceShow	=	false;
		flAWB_GainR	=	flAWB_GainB	=	1.0f;
		ucBlackLevel	=	0;
		flaglock.unlock();
	}

	__inline void SetBlemishEnhanceShowFlag(bool bOn)
	{
		flaglock.lockForWrite();
		bBlemishEnhaceShow	=	bOn;
		flaglock.unlock();
	}

	__inline bool GetBlemishEnhanceShowFlag(void)
	{
		flaglock.lockForRead();
		bool bIs	=	bBlemishEnhaceShow;
		flaglock.unlock();
		return bIs;
	}

	__inline void SetDSPLSCFlag(bool bOn)
	{
		flaglock.lockForWrite();
		bLSC		=	bOn;
		flaglock.unlock();
	}

	__inline bool GetDSPLSCFlag(void)
	{
		flaglock.lockForRead();
		bool bIs	=	bLSC;
		flaglock.unlock();
		return bIs;
	}

	__inline void SetDSPAWBFlag(bool bOn, unsigned char ucMethod, bool bUseSensorGain, unsigned char ucRefreshRate, float GainR, float GainB)
	{
		flaglock.lockForWrite();
		bAWB							=	bOn;
		bUseSensorAWBGain=	bUseSensorGain;
		ucAWB_Method			=	ucMethod;
		ucAWB_RefreshRate	=	ucRefreshRate;
		flAWB_GainR				=	GainR;
		flAWB_GainB				=	GainB;
		flaglock.unlock();
	}

	__inline bool GetDSPAWBFlag(void)
	{
		flaglock.lockForRead();
		bool bIs	=	bAWB;
		flaglock.unlock();
		return bIs;
	}

	__inline void SetDSPBlackLevel(unsigned char ucLevel)
	{
		flaglock.lockForWrite();
		ucBlackLevel	=	ucLevel;
		flaglock.unlock();
	}

	__inline unsigned char GetDSPBlackLevel(void)
	{
		flaglock.lockForRead();
		unsigned char ucLevel	=	ucBlackLevel;
		flaglock.unlock();
		return ucLevel;
	}

	__inline void SetDSPMirrorFlip(bool bMirror, bool bFlip)
	{
		flaglock.lockForWrite();
		bMirrorON	=	bMirror;
		bFlipON		=	bFlip;
		flaglock.unlock();
	}

	__inline void GetDSPMirrorFlip(bool& bMirror, bool& bFlip)
	{
		flaglock.lockForRead();
		bMirror		=	bMirrorON;
		bFlip			=	bFlipON;
		flaglock.unlock();
	}

	__inline void SetHisPreviewflag(bool bstatus)
	{
		flaglock.lockForWrite();
		bKeepLoop	=	bstatus;
		flaglock.unlock();
	}

	__inline bool GetHisPreviewflag()
	{
		flaglock.lockForRead();
		bool bIs	=	bKeepLoop;
		flaglock.unlock();
		return bIs;
	}

	__inline void SetHisTestingflag(bool bstatus)
	{
		flaglock.lockForWrite();
		bTesting	=	bstatus;
		flaglock.unlock();
	}

	__inline bool GetHisTestingflag()
	{
		flaglock.lockForRead();
		bool bIs	=	bTesting;
		flaglock.unlock();
		return bIs;
	}

	__inline unsigned __int64 GetHisRawFrameIndex()
	{
		flaglock.lockForRead();
		unsigned __int64 ui64The	=	ui64Raw1Index;
		flaglock.unlock();
		return ui64The;
	}

	__inline unsigned __int64 GetHisRGBFrameIndex()
	{
		flaglock.lockForRead();
		unsigned __int64 ui64The	=	ui64RGB2Index;
		flaglock.unlock();
		return ui64The;
	}

	__inline void setSlotItemExecStatus(bool bGoing, int iResult)
	{
		flaglock.lockForWrite();
		bslotItemExecGoing	=	bGoing;
		isoltItemExecResult	=	iResult;
		flaglock.unlock();
	}

	__inline bool getSlotItemExecStatus(int& iresult)
	{
		flaglock.lockForRead();
		bool bstatus	=	bslotItemExecGoing;
		iresult			=	isoltItemExecResult;
		flaglock.unlock();
		return bstatus;
	}

	__inline int  CopyRawXBuf(unsigned char** ppucBuf)
	{
		flaglock.lockForWrite();
		pucRawX	=	*ppucBuf;
		flaglock.unlock();

		QElapsedTimer classTime;
		classTime.start();
		while(classTime.elapsed() < 1000)
		{
			Sleep(5);
			flaglock.lockForRead();
			if(!pucRawX) {flaglock.unlock(); return 0; }
			flaglock.unlock();
		}

		flaglock.lockForWrite();
		pucRawX	=	0;
		flaglock.unlock();
		return HisFX3Error_GrabFrame;
	}

	__inline void RawX2RGB24(unsigned char* pucRawX, unsigned char* pucDRGB24, bool b4Cell2 = false, QString sensortype = QString())
	{
		switch (ucFormat)
		{
		case HisBaylor10_BGGR:
		case HisBaylor10_RGGB:
		case HisBaylor10_GRBG:
		case HisBaylor10_GBRG:
			{
				bool b4Cell = b4Cell2;
				if(b4Cell && sensortype.contains("ov20880", Qt::CaseInsensitive))
				{
#ifdef _WIN64
					b4Cell = false;
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
						OutputDebugStringA("OV 4Cell Library Version: ");
						OutputDebugStringA((QString::number(version)).toAscii().data());

						unsigned char ucSlave;
						if(bBoxChannel1)
							ucSlave	=	itemshareDataC1.previewParameter->ucSlave;
						else
							ucSlave	=	itemshareDataC2.previewParameter->ucSlave;
						// set sensor I2C callback
						int ret = ov4c_set_i2c_callback(0, ucSlave, (ov4c_i2c_callback)OV4Cell_ReadReg_CallbackC1);			
						if (ret != 0)
						{
							b4Cell = false;
							OutputDebugStringA("ov4c_set_i2c_callback return: ");
							OutputDebugStringA((QString::number(ret)).toAscii().data());
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
								OutputDebugStringA("ov4c_init return: ");
								OutputDebugStringA((QString::number(ret)).toAscii().data());
								// release library
								ov4c_release();
							}
							else
							{
								unsigned char* pucTempBaylor = (unsigned char*)HisAlignedMalloc(roi_para.w*roi_para.roi_x_num*roi_para.h*roi_para.roi_y_num *2);
								QHisFX3MallocAlignedManage classpucTempBaylor(pucTempBaylor);

								ret = ov4c_20880_transform_bayer_raw10((unsigned short*)pucRawX, (unsigned short*)pucTempBaylor, &roi_para);
								if(ret != 0)
								{
									b4Cell = false;
									OutputDebugStringA("ov4c_20880_transform_bayer_raw10 return: ");
									OutputDebugStringA((QString::number(ret)).toAscii().data());
									// release library
									ov4c_release();
								}
								else
								{
									classAlgorithm.HisCCMBarlor2RGB24(pucTempBaylor, pucDRGB24, uiWidth, uiHeight & 0xFFFFFFFE, ucFormat, ucInterpolation);
								}

								memcpy(pucDRGB24 + 5120 *3840 *3, pucDRGB24 + 5120 *3839 *3, 5120 *3);

								// release library
								ov4c_release();
							}
						}
					}
					else
					{
						b4Cell = false;
						OutputDebugStringA("Load OV20880 4cell conversion function fail");
					}
#endif
				}
				else
				{
					b4Cell	=	false;
				}

				if(!b4Cell)
				{
					classAlgorithm.HisCCMBarlor2RGB24(pucRawX, pucDRGB24, uiWidth, uiHeight, ucFormat, ucInterpolation);
				}			
			}
			break;
		case HisBaylor12_BGGR:
		case HisBaylor12_RGGB:
		case HisBaylor12_GRBG:
		case HisBaylor12_GBRG:
			classAlgorithm.HisCCMBarlor2RGB24(pucRawX, pucDRGB24, uiWidth, uiHeight, ucFormat, ucInterpolation);
			break;
		case HisBaylor10_MONO:
			{
				unsigned short* pusSrc = (unsigned short*)pucRawX;
				unsigned char* pucDes	=	pucDRGB24;
				unsigned int uiP	=	uiHeight *uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = ((*pusSrc >>2) & 0xFF);
					pucDes += 3;
					++pusSrc;
				}
			}
			break;
		case HisBaylor12_MONO:
			{
				unsigned short* pusSrc = (unsigned short*)pucRawX;
				unsigned char* pucDes	=	pucDRGB24;
				unsigned int uiP	=	uiHeight *uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = ((*pusSrc >>4) & 0xFF);
					pucDes += 3;
					++pusSrc;
				}
			}
			break;
		case HisYUV8_422_YUYV:
		case HisYUV8_422_UYVY:
		case HisYUV8_422_YVYU:
		case HisYUV8_422_VYUY:
			if(bGrayImage)
			{
				unsigned char* pucSrc	=	pucRawX, *pucDes = pucDRGB24;
				if((ucFormat == HisYUV8_422_UYVY) || (ucFormat == HisYUV8_422_VYUY)) ++pucSrc;
				unsigned int uiPixel = uiWidth *uiHeight;
				for(unsigned int x=0;	x<uiPixel; ++x)
				{
					*(pucDes+2) = *(pucDes+1) = *pucDes =*pucSrc;
					pucDes += 3;
					pucSrc+=2;
				}
			}
			else
			{			
				classAlgorithm.HisCCMYUV2RGB24(pucRawX, pucDRGB24, uiWidth, uiHeight, ucFormat/*, _HisFX3_YUVCVTRGB_BT709*/);
			}
			break;
		case HisRGB_RGB24:
			classAlgorithm.copyframebuffer(pucRawX, pucDRGB24, uiWidth *uiHeight *3);
			break;
		case HisBaylor8_MONO:
			{
				unsigned char* pucDes	=	pucDRGB24, *pucSrc = pucRawX;
				unsigned int uiP	=	uiHeight *uiWidth;
				for(unsigned int x=0;	x< uiP; ++x){
					*(pucDes+2) = *(pucDes+1) = *pucDes = *pucSrc++;
					pucDes += 3;
				}
			}
			break;
		case HisBaylor8_BGGR:
		case HisBaylor8_RGGB:
		case HisBaylor8_GRBG:
		case HisBaylor8_GBRG:
		default:
			classAlgorithm.HisCCMBarlor2RGB24(pucRawX, pucDRGB24, uiWidth, uiHeight, ucFormat, ucInterpolation);
			break;
		}
	}

	__inline int GetFreshframe(unsigned char* pucdata, unsigned int uibuffersize, unsigned char ucframetype, bool binit)
	{
		if(!pucdata || !uibuffersize)	return HisFX3Error_Parameter;
		if(binit)	ui64IndexStamp	=	0;
		unsigned __int64 ui64the	=	0;
		bool bIs			=	true;
		ucframetype	&=	0x7F;
		int iresult = 0;

		QElapsedTimer classTime;
		classTime.start();
		while(classTime.elapsed() < _Firstframe_Timeout)
		{
			if(!GetHisPreviewflag())	return HisCCMError_NotPreivew;
			ui64the		=	GetHisRawFrameIndex();
			if(ui64the > ui64IndexStamp) {	bIs	=	false; break; }
			Sleep(15);
		}

		if(bIs)	return HisCCMError_NoFrame;
		ui64IndexStamp	=	ui64the;

		if((ucFormat >= HisBaylor8_BGGR) && (ucFormat < HisBaylor8_BGGR + 15)) //raw8
		{
			switch (ucframetype)
			{
			case _FrameType_Raw:
				iresult = CopyRawXBuf(&pucdata);
				break;
			case _FrameType_Raw10:
				{
					unsigned char* pucRaw8 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight);
					if(!pucRaw8) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw8);
					classAlgorithm.raw8toraw10(pucRaw8, (unsigned short*)(pucdata), uiWidth, uiHeight);
					HisReleaseMalloc(pucRaw8);
				}
				break;
			case _FrameType_Raw12:
				{
					unsigned char* pucRaw8 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight);
					if(!pucRaw8) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw8);
					classAlgorithm.raw8toraw12(pucRaw8, (unsigned short*)(pucdata), uiWidth, uiHeight);
					HisReleaseMalloc(pucRaw8);
				}
				break;
			case _FrameType_RGB24:
				{
					unsigned char* pucRaw8 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight);
					if(!pucRaw8) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw8);
					if(bBoxChannel1){
						RawX2RGB24(pucRaw8, pucdata,  itemshareDataC1.ccmhardwareParameter->b4Cell, \
							itemshareDataC1.ccmhardwareParameter->sensortype);
					}
					else{
						RawX2RGB24(pucRaw8, pucdata,  itemshareDataC2.ccmhardwareParameter->b4Cell, \
							itemshareDataC2.ccmhardwareParameter->sensortype);
					}
					HisReleaseMalloc(pucRaw8);
				}
				break;
			default:
				return HisFX3Error_Parameter;
				break;
			}
		}
		else  if((ucFormat >= HisBaylor10_BGGR) && (ucFormat < HisBaylor10_BGGR + 15))  //raw10
		{
			switch (ucframetype)
			{
			case _FrameType_Raw:
				{
					unsigned char* pucRaw10 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight *2);
					if(!pucRaw10) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw10);
					classAlgorithm.raw10toraw8((unsigned short*)(pucRaw10), pucdata, uiWidth, uiHeight);
					HisReleaseMalloc(pucRaw10);
				}
				break;
			case _FrameType_Raw10:
				iresult = CopyRawXBuf(&pucdata);
				break;
			case _FrameType_Raw12:
				iresult = CopyRawXBuf(&pucdata);
				classAlgorithm.raw10toraw12((unsigned short*)(pucdata), (unsigned short*)(pucdata), uiWidth, uiHeight);
				break;
			case _FrameType_RGB24:
				{
					unsigned char* pucRaw10 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight *2);
					if(!pucRaw10) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw10);
					if(bBoxChannel1){
						RawX2RGB24(pucRaw10, pucdata,  itemshareDataC1.ccmhardwareParameter->b4Cell, \
							itemshareDataC1.ccmhardwareParameter->sensortype);
					}
					else{
						RawX2RGB24(pucRaw10, pucdata,  itemshareDataC2.ccmhardwareParameter->b4Cell, \
							itemshareDataC2.ccmhardwareParameter->sensortype);
					}
					HisReleaseMalloc(pucRaw10);
				}	
				break;
			default:
				return HisFX3Error_Parameter;
				break;
			}
		}
		else  if((ucFormat >= HisBaylor12_BGGR) && (ucFormat < HisBaylor12_BGGR + 15))  //raw12
		{
			switch (ucframetype){
			case _FrameType_Raw:
				{
					unsigned char* pucRaw12 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight *2);
					if(!pucRaw12) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw12);
					classAlgorithm.raw12toraw8((unsigned short*)(pucRaw12), pucdata, uiWidth, uiHeight);
					HisReleaseMalloc(pucRaw12);
				}
				break;
			case _FrameType_Raw12:
				iresult = CopyRawXBuf(&pucdata);
				break;
			case _FrameType_Raw10:
				iresult = CopyRawXBuf(&pucdata);
				classAlgorithm.raw12toraw10((unsigned short*)(pucdata), (unsigned short*)(pucdata), uiWidth, uiHeight);
				break;
			case _FrameType_RGB24:
				{
					unsigned char* pucRaw12 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight *2);
					if(!pucRaw12) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucRaw12);
					if(bBoxChannel1){
						RawX2RGB24(pucRaw12, pucdata,  itemshareDataC1.ccmhardwareParameter->b4Cell, \
							itemshareDataC1.ccmhardwareParameter->sensortype);
					}
					else{
						RawX2RGB24(pucRaw12, pucdata,  itemshareDataC2.ccmhardwareParameter->b4Cell, \
							itemshareDataC2.ccmhardwareParameter->sensortype);
					}
					HisReleaseMalloc(pucRaw12);
				}		
				break;
			default:
				return HisFX3Error_Parameter;
				break;
			}
		}
		else if((ucFormat >= HisYUV8_422_YUYV) && (ucFormat <= HisYUV8_422_VYUY))
		{
			switch (ucframetype)
			{
			case _FrameType_Raw:
				iresult = CopyRawXBuf(&pucdata);
				break;
			case _FrameType_RGB24:
				{
					unsigned char* pucYUV422 = (unsigned char*)HisAlignedMalloc(uiWidth *uiHeight *2);
					if(!pucYUV422) return HisFX3Error_MallocBuffer;
					iresult = CopyRawXBuf(&pucYUV422);
					if(bBoxChannel1){
						RawX2RGB24(pucYUV422, pucdata,  itemshareDataC1.ccmhardwareParameter->b4Cell, \
							itemshareDataC1.ccmhardwareParameter->sensortype);
					}
					else{
						RawX2RGB24(pucYUV422, pucdata,  itemshareDataC2.ccmhardwareParameter->b4Cell, \
							itemshareDataC2.ccmhardwareParameter->sensortype);
					}
					HisReleaseMalloc(pucYUV422);
				}	
				break;
			default:
				return HisFX3Error_Parameter;
				break;
			}
		}
		else if(ucFormat == HisRGB_RGB24)
		{
			switch (ucframetype)
			{
			case _FrameType_Raw:
			case _FrameType_RGB24:
				iresult = CopyRawXBuf(&pucdata);
				break;
			default:
				return HisFX3Error_Parameter;
				break;
			}
		}

		return iresult;
	}

};

extern _globalParameter hisglobalparameter;
extern _threadshareData threadshareDataC1;

extern HisFX3Log classGlobalLogC1;
extern std::vector<std::wstring> vectorHisCCMOTPInfoWC1;

extern HisFX3Log classGlobalLogC2;
extern std::vector<std::wstring> vectorHisCCMOTPInfoWC2;
extern _threadshareData threadshareDataC2;
extern QHGerneralMotor classMotion;

extern int __stdcall HisFX3PageWriteSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize, bool bCSLow, bool bLowFirst);
extern int __stdcall HisFX3PageReadSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize, bool bCSLow, bool bLowFirst);
extern int __stdcall HisFX3WriteSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool bCSLow, bool bLowFirst);
extern int __stdcall HisFX3ReadSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType, bool bCSLow, bool bLowFirst);
extern int __stdcall WriteHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool back);
extern int __stdcall WriteHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool back);
extern int __stdcall ReadHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType);
extern int __stdcall ReadHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType);
extern int __stdcall BatchWriteHisFX3IICNoLimitC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay);
extern int __stdcall BatchWriteHisFX3IICNoLimitC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay);
extern int __stdcall BatchReadHisFX3IICNoLimitC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay);
extern int __stdcall BatchReadHisFX3IICNoLimitC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay);
extern int __stdcall BatchWriteHisFX3IICC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay);
extern int __stdcall BatchReadHisFX3IICC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay);
extern int __stdcall BatchWriteHisFX3IICC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay);
extern int __stdcall BatchReadHisFX3IICC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay);
extern int __stdcall PageWriteHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize);
extern int __stdcall PageWriteHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize);
extern int __stdcall PageReadHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize);
extern int __stdcall PageReadHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize);
extern int __stdcall SetHisFX3IICSpeedC1(unsigned short us1kMultiple);
extern int __stdcall SetHisFX3IICSpeedC2(unsigned short us1kMultiple);
extern int __stdcall GetHisFX3IICSpeedC1(unsigned short* pus1kMultiple);
extern int __stdcall GetHisFX3IICSpeedC2(unsigned short* pus1kMultiple);
extern int __stdcall SetHisFX3SPISpeedC1(unsigned short us1kMultiple);
extern int __stdcall GetHisFX3SPISpeedC1(unsigned short* pus1kMultiple);
extern int __stdcall SetHisFX3VoltageC1(float flDOVDD, float flAVDD, float flDVDD, float flAF, float flVFuse, float flPOW, float flIODD, unsigned short usSwitch, float flMultiple);
extern int __stdcall SetHisFX3VoltageC2(float flDOVDD, float flAVDD, float flDVDD, float flAF, float flVFuse, float flPOW, float flIODD, unsigned short usSwitch, float flMultiple);
extern int __stdcall GetHisFX3VoltageC1(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW, float* pflIODD);
extern int __stdcall GetHisFX3VoltageC2(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW, float* pflIODD);
extern int __stdcall MeasureHisFX3VoltageC1(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW);
extern int __stdcall MeasureHisFX3VoltageC2(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW);
extern int __stdcall SetHisFX3VFuseVolt(float flVFUSE);
extern int __stdcall GetHisFX3VFuseVolt(float* pflVFUSE);
extern int __stdcall PullHisFX3PWNDC1(bool bPullHigh);
extern int __stdcall PullHisFX3PWNDC2(bool bPullHigh);
extern int __stdcall PullHisFX3RESETC1(bool bPullHigh);
extern int __stdcall PullHisFX3RESETC2(bool bPullHigh);
extern int __stdcall SetHisFX3MCLKC1(float flMCLK);
extern int __stdcall SetHisFX3MCLKC2(float flMCLK);
extern int __stdcall GetHisFX3MCLKC1(float* pflMCLK);
extern int __stdcall GetHisFX3MCLKC2(float* pflMCLK);
extern int __stdcall SetHisFX3LaneC1(unsigned char ucLane);
extern int __stdcall SetHisFX3LaneC2(unsigned char ucLane);
extern int __stdcall GetHisFX3LaneC1(unsigned char* pucLane);
extern int __stdcall GetHisFX3LaneC2(unsigned char* pucLane);
extern int __stdcall SetHisFX3DVPHSVSC1(bool bDVP_VS_ActiveHigh, bool bDVP_HS_ActiveHigh);
extern int __stdcall GetHisFX3DVPHSVSC1(bool* pbDVP_VS_ActiveHigh, bool* pbDVP_HS_ActiveHigh);
extern int __stdcall SetHisFX3GPIO(unsigned char ucGPIO0, unsigned char ucGPIO1, unsigned char ucGPIO2, unsigned char ucGPIO3, unsigned int uiFlag);
extern int __stdcall GetHisFX3GPIO(unsigned char* pucGPIO0, unsigned char* pucGPIO1, unsigned char* pucGPIO2, unsigned char* pucGPIO3, unsigned int uiFlag);
extern int __stdcall GetHisFX3SlaveResponseC1(unsigned char ucSlave);
extern int __stdcall GetHisFX3SlaveResponseC2(unsigned char ucSlave);
extern bool __stdcall IsHisFX3DataStreamingC1(unsigned int uiTimeOut);
extern bool __stdcall IsHisFX3DataStreamingC2(unsigned int uiTimeOut);
extern unsigned __int64 __stdcall getSensorFrameIndexC1();
extern unsigned __int64 __stdcall getSensorFrameIndexC2();
extern QString __stdcall GetHisFX3ErrorInfo(int errorcode);
extern void __stdcall HisFX3LogPush_backC1(unsigned int uiIndex, const char* pstrKey, const char* pstrValue);
extern void __stdcall HisFX3LogPush_backC2(unsigned int uiIndex, const char* pstrKey, const char* pstrValue);
extern int __stdcall GetFreshframeC1(unsigned char* pucdata, unsigned int uibuffersize, unsigned char ucframetype, bool binit);
extern int __stdcall GetFreshframeC2(unsigned char* pucdata, unsigned int uibuffersize, unsigned char ucframetype, bool binit);
extern void __stdcall setBulkSize(long size);

//add By feng 2019-07-15
typedef void (__stdcall *setbulktransformsize)(long bufSize);

typedef void (__cdecl *RolongogetAFList)(std::vector<std::string>& listAF);
typedef int (__cdecl *Rolongowriteafmotor)(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMAFBurn_Config* pstconfig, hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, \
	hardwaresetvolt funsetvolt, hardwaregetvolt fungetvolt, hardwaresetvfuse funsetvfuse, hardwaregetvfuse fungetvfuse, hardwaregetframe fungetframe, \
	hardwaresetgpio funsetgpio, hardwaregetgpio fungetgpio, hardwarepullreset funreset, hardwarepullpwnd funpwnd, \
	hardwarebatchreadiicnolimit funbatchreadiicnolimit, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit, \
	hisfx3logpush_back funlogpushback, hardwarepagewriteiic fucpagewriteiic, hardwarepagereadiic fucpagereadiic, \
	hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi,setbulktransformsize funsetbulk);
typedef int (__cdecl *Rolongocheckafmotor)(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMAFBurn_Config* pstconfig , hardwarereadiic funreadiic , hardwarewriteiic funwriteiic , hardwaresetiicspeed funiicspeed , \
	hardwaresetvolt funsetvolt , hardwaregetvolt fungetvolt , hardwaresetvfuse funsetvfuse , hardwaregetvfuse fungetvfuse , hardwaregetframe fungetframe , \
	hardwaresetgpio funsetgpio , hardwaregetgpio fungetgpio , hardwarepullreset funreset , hardwarepullpwnd funpwnd , \
	hardwarebatchreadiicnolimit funbatchreadiicnolimit , hardwarebatchwriteiicnolimit funbatchwriteiicnolimit , \
	hisfx3logpush_back funlogpushback  , hardwarepagewriteiic fucpagewriteiic  , hardwarepagereadiic fucpagereadiic, \
	hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi,setbulktransformsize funsetbulk);

//OTP DLL
typedef unsigned int (__cdecl *RolongoOTPAPIVersion)();
typedef void (__cdecl *RolongogetOTPList)(std::vector<std::string>& listOTP);
typedef int (__cdecl *Rolongogetdefaultconfig)(_HisCCMOTP_Config* pstconfig);
typedef void (__cdecl *RolongogetApplyList)(std::vector<std::string>& listApply);
typedef void (__cdecl *RolongogetMTKPDAFList)(std::vector<std::string>& listPDAF);
typedef void (__cdecl *RolongogetSONYPDAFList)(std::vector<std::string>& listPDAF);
typedef void (__cdecl *RolongogetQualcommPDAFList)(std::vector<std::string>& listPDAF);
typedef void (__cdecl *RolongogetDualCameraBurnList)(std::vector<std::string>& listOTP);
typedef void (__cdecl *RolongogetHISIPDAFList)(std::vector<std::string>& listPDAF);

//Sensor DLL
typedef int (__cdecl *RolongosetExposureTime)(char* pstrsensor, unsigned char ucslave, unsigned int uivalue, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetExposureTime)(char* pstrsensor, unsigned char ucslave, unsigned int& uivalue, unsigned int& uimin, unsigned int& uimax, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef int (__cdecl *RolongosetDigtalGain)(char* pstrsensor, unsigned char ucslave, float flGain, \
	hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetDigtalGain)(char* pstrsensor, unsigned char ucslave, float& flGain, \
	float& flMin, float& flMax, hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef int (__cdecl *RolongosetAnalogGain)(char* pstrsensor, unsigned char ucslave, float flGain, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetAnalogGain)(char* pstrsensor, unsigned char ucslave, float& flGain, float& flMin, float& flMax, \
	hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef void (__cdecl *RolongogetGlobalGainList)(std::vector<std::string>& vectorGlobalGain);
typedef int (__cdecl *RolongosetGlobalGain)(char* pstrsensor, unsigned char ucslave, float flGain, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetGlobalGain)(char* pstrsensor, unsigned char ucslave, float& flGain, float& flMin, float& flMax, \
	hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef void (__cdecl *RolongogetAWBGainList)(std::vector<std::string>& vectorAWBGain);
typedef int (__cdecl *RolongosetAWBGain)(char* pstrsensor, unsigned char ucslave, float flGainR, bool bSetR, float flGainB, bool bSetB, float flGainG, bool bSetG, \
	hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetAWBGain)(char* pstrsensor, unsigned char ucslave, float& flGainR, float& flGainB, float& flGainG, \
	float& flMin, float& flMax, hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef void (__cdecl *RolongogetMotorList)(std::vector<std::string>& vectorMotor);
typedef int (__cdecl *RolongosetMotor)(char* pstrsensor, unsigned char ucslave, char* pstrproject, int ivalue, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);
typedef int (__cdecl *RolongogetMotor)(char* pstrsensor, unsigned char ucslave, char* pstrproject, int& ivalue, int& imin, int& imax, hardwarereadiic funreadiic, \
	hardwarewriteiic funwriteiic,hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef int (__cdecl *RolongogetChipID)(char* pstrsensor, unsigned char ucslave, char* pstrproject, std::string& strChipID, \
	hardwarereadiic funreadiic, hardwarewriteiic funwriteiic, hardwaresetiicspeed funiicspeed, hardwarepullreset funreset, hardwarepullpwnd funpwdn, hardwarepagewriteiic funpagewriteiic, \
	hardwarepagereadiic funpagereadiic, hardwarepagewritespi funpagewritespi, hardwarepagereadspi funpagereadspi);

typedef void (__cdecl *RolongomotorScaleto1023)(std::string strDriverIC, int iBefore, int& uiNow);
typedef void (__cdecl *RolongomotorScalefrom1023)(std::string strDriverIC, int uiBefore, int& iNow);

typedef unsigned int (__cdecl *RolongogetSensorAPIVersion)();

typedef bool (__stdcall *hardwareisdatastreaming)(unsigned int uiLoop);
typedef unsigned __int64 (__stdcall *hardwaregetsensorframeindex)();
typedef int (__stdcall *hardwaremeasurevoltage)(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW);


struct _globalFunctionPointer
{
	hardwarewriteiic WriteHisFX3IIC;
	hardwarereadiic	ReadHisFX3IIC;
	hardwaresetiicspeed	SetHisFX3IICSpeed;
	hardwaregetiicspeed	GetHisFX3IICSpeed;
	hardwaresetspispeed	SetHisFX3SPISpeed;
	hardwaregetspispeed	GetHisFX3SPISpeed;
	hardwaregetframe	GetFreshframe;
	hardwaresetvolt	SetHisFX3Voltage;
	hardwaregetvolt	GetHisFX3Voltage;
	hardwarepullreset	PullHisFX3RESET;
	hardwarepullpwnd	PullHisFX3PWND;
	hardwaresetmclk	SetHisFX3MCLK;
	hardwaregetmclk	GetHisFX3MCLK;
	hardwaresetlane		SetHisFX3Lane;
	hardwaregetlane		GetHisFX3Lane;
	hardwaresetdvphsvs	SetHisFX3DVPHSVS;
	hardwaregetdvphsvs	GetHisFX3DVPHSVS;
	hardwaregetslaveresponse	GetHisFX3SlaveResponse;
	hardwarebatchwriteiicnolimit	BatchWriteHisFX3IICNoLimit;
	hardwarebatchreadiicnolimit	BatchReadHisFX3IICNoLimit;
	hardwarebatchwriteiic	  BatchWriteHisFX3IIC;
	hardwarebatchreadiic	   BatchReadHisFX3IIC;
	hardwarepagewritespi		HisFX3PageWriteSPI;
	hardwarepagereadspi		HisFX3PageReadSPI;
	hardwarewritespi		HisFX3WriteSPI;
	hardwarereadspi		HisFX3ReadSPI;
	hisfx3logpush_back HisFX3LogPush_back;
	hardwarepagewriteiic	PageWriteHisFX3IIC;
	hardwarepagereadiic	PageReadHisFX3IIC;
	hardwareisdatastreaming IsHisFX3DataStreaming;
	hardwaregetsensorframeindex getSensorFrameIndex;
	hardwaremeasurevoltage MeasureHisFX3Voltage;
	//**************** 20190707  *****************************
	setbulktransformsize setbulkSize;

	std::vector<std::wstring>* vectorHisCCMOTPInfoW;
	 
	_globalFunctionPointer(bool bChannel1 = true)
	{
		setbulkSize=setBulkSize;

		if(bChannel1)
		{
			vectorHisCCMOTPInfoW	=	&vectorHisCCMOTPInfoWC1;
			WriteHisFX3IIC			=	WriteHisFX3IICC1;
			ReadHisFX3IIC			=	ReadHisFX3IICC1;
			SetHisFX3IICSpeed	=	SetHisFX3IICSpeedC1;
			GetHisFX3IICSpeed	=	GetHisFX3IICSpeedC1;
			GetFreshframe			=	GetFreshframeC1;
			SetHisFX3Voltage		=	SetHisFX3VoltageC1;
			GetHisFX3Voltage		=	GetHisFX3VoltageC1;
			PullHisFX3RESET		=	PullHisFX3RESETC1;
			PullHisFX3PWND		=	PullHisFX3PWNDC1;
			SetHisFX3MCLK			=	SetHisFX3MCLKC1;
			GetHisFX3MCLK			=	GetHisFX3MCLKC1;
			SetHisFX3Lane			=	SetHisFX3LaneC1;
			GetHisFX3Lane			=	GetHisFX3LaneC1;
			GetHisFX3SlaveResponse	=	GetHisFX3SlaveResponseC1;
			BatchWriteHisFX3IICNoLimit	=	BatchWriteHisFX3IICNoLimitC1;
			BatchReadHisFX3IICNoLimit	=	BatchReadHisFX3IICNoLimitC1;
			BatchWriteHisFX3IIC= BatchWriteHisFX3IICC1;
			BatchReadHisFX3IIC=BatchReadHisFX3IICC1;
			HisFX3LogPush_back			=	HisFX3LogPush_backC1;
			PageWriteHisFX3IIC				=	PageWriteHisFX3IICC1;
			PageReadHisFX3IIC				=	PageReadHisFX3IICC1;
			IsHisFX3DataStreaming			=	IsHisFX3DataStreamingC1;
			getSensorFrameIndex			=	getSensorFrameIndexC1;
			MeasureHisFX3Voltage			=	MeasureHisFX3VoltageC1;
			
		}
		else
		{
			vectorHisCCMOTPInfoW	=	&vectorHisCCMOTPInfoWC2;
			WriteHisFX3IIC			=	WriteHisFX3IICC2;
			ReadHisFX3IIC			=	ReadHisFX3IICC2;
			SetHisFX3IICSpeed	=	SetHisFX3IICSpeedC2;
			GetHisFX3IICSpeed	=	GetHisFX3IICSpeedC2;
			GetFreshframe			=	GetFreshframeC2;
			SetHisFX3Voltage		=	SetHisFX3VoltageC2;
			GetHisFX3Voltage		=	GetHisFX3VoltageC2;
			PullHisFX3RESET		=	PullHisFX3RESETC2;
			PullHisFX3PWND		=	PullHisFX3PWNDC2;
			SetHisFX3MCLK			=	SetHisFX3MCLKC2;
			GetHisFX3MCLK			=	GetHisFX3MCLKC2;
			SetHisFX3Lane			=	SetHisFX3LaneC2;
			GetHisFX3Lane			=	GetHisFX3LaneC2;
			GetHisFX3SlaveResponse	=	GetHisFX3SlaveResponseC2;
			BatchWriteHisFX3IICNoLimit	=	BatchWriteHisFX3IICNoLimitC2;
			BatchReadHisFX3IICNoLimit	=	BatchReadHisFX3IICNoLimitC2;
			BatchWriteHisFX3IIC = BatchWriteHisFX3IICC2;
			BatchReadHisFX3IIC = BatchReadHisFX3IICC2;
			HisFX3LogPush_back			=	HisFX3LogPush_backC2;
			PageWriteHisFX3IIC				=	PageWriteHisFX3IICC2;
			PageReadHisFX3IIC				=	PageReadHisFX3IICC2;
			IsHisFX3DataStreaming			=	IsHisFX3DataStreamingC2;
			getSensorFrameIndex			=	getSensorFrameIndexC2;
			MeasureHisFX3Voltage			=	MeasureHisFX3VoltageC2;
		}

		SetHisFX3SPISpeed	=	SetHisFX3SPISpeedC1;
		GetHisFX3SPISpeed	=	GetHisFX3SPISpeedC1;
		SetHisFX3DVPHSVS	=	SetHisFX3DVPHSVSC1;
		GetHisFX3DVPHSVS	=	GetHisFX3DVPHSVSC1;
		HisFX3PageWriteSPI	=	HisFX3PageWriteSPIC1;
		HisFX3PageReadSPI	=	HisFX3PageReadSPIC1;
		HisFX3WriteSPI			=	HisFX3WriteSPIC1;
		HisFX3ReadSPI			=	HisFX3ReadSPIC1;
	}
};

extern _globalFunctionPointer globalFunPointerC1;
extern _globalFunctionPointer globalFunPointerC2;
 
#endif