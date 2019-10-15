//
#ifndef ITEMPROCESS_H
#define ITEMPROCESS_H

#include "qoplow.h"
#include <QScrollBar>
#include <QSqlError>
#include "QHImageFrame.h"
#include "inc//RolongoImageTestAlg.h"
#include <QList>
#include "./include/3L6_PDAF/PdafCalibrationGMCore.h"
#include "./include/3L6_PDAF/PdafCalibrationDMCore.h"
#include "./include/3L6_PDAF/PdafVerificationCore.h"
#pragma comment(lib,"./include/3L6_PDAF/PdafCalibrationGMDll.lib")
#pragma comment(lib,"./include/3L6_PDAF/PdafCalibrationDMDll.lib")
#pragma comment(lib,"./include/3L6_PDAF/PdafVerificationDll.lib")


struct _autoExposreData{
	bool bChannel_Gr;
	bool bAverage;
	unsigned char unIndex;
	unsigned int uimin;
	unsigned int uimax;
	unsigned __int32 uiidmin;
	unsigned __int32 uiidmax;
	RECT stroi;
	QString strTableName;
	__declspec(align(_HisCacheLine_Aligned)) unsigned __int32 uiid[_AE_DATA_MAX];
	unsigned int usdatacount;
	__declspec(align(_HisCacheLine_Aligned)) _autoexposureItem stAEData[_AE_DATA_MAX];

	_autoExposreData()
	{
		bChannel_Gr	=	true;
		bAverage			=	true;
		unIndex			=	1;
		uimin				=	150;
		uimax				=	160;
		uiidmin				=	0;
		uiidmax			=	0;
		usdatacount	=	0;
		memset(&stroi,	0,	sizeof(RECT));
		memset(uiid, 0, sizeof(unsigned __int32) *_AE_DATA_MAX);
		memset(stAEData, 0, sizeof(_autoexposureItem) *_AE_DATA_MAX);
	}
};

class HisFX3CCMTest;
class itemprocess : public QObject
{
	Q_OBJECT

public:
	itemprocess(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC, \
		QHImageFrame& imageframeC, QScrollBar& horizontalScrollBarC, QScrollBar& verticalScrollBarC, QLineEdit& serialNumberLineEditC,HisFX3CCMTest *parent=NULL);
	~itemprocess();

public slots:
	void ExecKeyshortcut(char key, unsigned char uctimer);
	void finish();
	void slotItemExec(quint8 u8Channel, quint16 usItem, QString strOtherInfo, quint64 u64ID, quint8 u8LoopTime);
		 
	void slotNativeItemExec(_shoutCutDetail& currentitem)
	{
		int iresult	=	operateItem(currentitem);
		threadshareData.setSlotItemExecStatus(false, iresult);
	}

signals:
		void finished();
		void enablebutton(bool benable);
		void updateresult();
		void startpreview();
		void showresult(int istatus);
		void signalshowitem2endresult(unsigned short usitem, unsigned char ucstatus, unsigned int ustime);
		void information(QString info);
		void plotpainter(unsigned int uiType);
		void drawTactistics();
		void getSNRBuffer();
		void enableinfotimer(unsigned int uiflag);
		void getuiinfo();
		void execsaveimage(QString strdir, QString strname, unsigned char ucimageformat, unsigned char ucimagesrc);
		void signaldrawframe(int itype);
		void signalwriteItemResult(quint64 u64ID, quint8 u8TestItemResult);
		void signalWritePDAF50cm(quint8 u8Channel);
		void signalopenoffline(bool bChecked);
		void signalopenofflineb(bool bChecked);
		void signalPlugInDetect();
		void signalDrawAnotherSingle(QImage image1, unsigned int uiTimeOut);
		void signalBackToNormalMode();
		void signalTotalTestTime(unsigned int uiTime);
		void signalMessageBox(int iInfo);
		void signalwriteItemResult(unsigned short usItem, quint8 u8Status, bool bChannel1);
		void signalwriteMasterItemExec(unsigned short usItem, unsigned char ucItemIndex, quint8 u8AddInfo,  bool bChannel1);
		void signalTCPMessageSend(QVariant dataVar);  //发送数据给客户端

		//*********** 2017/12/11
		void sigBurnCount();
		void sigCountToPanel(QStringList,QStringList);

		//************ 2019/03/30
public:
	signals:
		void sig_test(QqrealList);
		void sig_serialnumberbind(QString);//************ 2019/03/30
		void sig_messtatusupdate(QString,QString);//************ 2019/03/30

		 
public:
	//***************** 2018.04.16 ADD **************
	bool bAutoFocus;
	//*******************  2019/03/30************
	HisFX3CCMTest *widCCMTest;
	//***********************************************

	const bool bBoxChannel1;
	bool bMasterItemExecFinish;
	quint8 u8MasterItemExecStatus;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;
	QScrollBar& horizontalScrollBar;
	QScrollBar& verticalScrollBar;
	QLineEdit& serialNumberLineEdit;
	QHImageFrame& imageframe; 
	hardwaregetframe GetFreshframe;

	RolongosetExposureTime setExposureTime;
	RolongosetGlobalGain setGlobalGain;
	RolongosetMotor setMotor;
	RolongogetExposureTime getExposureTime;
	RolongomotorScaleto1023 motorScaleto1023;
	RolongomotorScalefrom1023 motorScalefrom1023;
	RolongogetSensorAPIVersion getSensorAPIVersion;

	CRolongoImageTestAlg classRolongoTest;
	HisFX3Log* classLog;
	int getccmhardwareParameter(bool bupdate=false, bool bcheck = true);


	int IOBitOut(unsigned int uiCardNum, unsigned int uiPort, unsigned int uiBitNum, unsigned int uiValue);
	int IOBitCheck(unsigned int uiCardNum, unsigned int uiPort, unsigned int uiBitNum, unsigned int uiValue);
	int MotorMove(unsigned int CardNo,unsigned int axis, double Dist, bool bAbs);
	int toPosWhitePanel();
	int toPosBlackPanel();
	int toPosNearFocus();
	int toPosFarFocus();
	int ChartAlign(unsigned char ucChartType, unsigned char ucAngle, unsigned char ucTimes, unsigned short usMarkMin, unsigned short usMarkMax, \
		unsigned short usPosDiff, unsigned short usTarget, float flFOV, float flScaleX, float flScaleY, unsigned short usFrameSleep);
	int RRTCheck(unsigned int uiChart);






	 
	int getGereralAFAParameter(bool bupdate=false, bool bcheck = true);
#if (defined USE_EQUIPMENT_AFM_JSL_V1) 
	void DrawAFAMTFBarChart(_HisAutoFA_Rolongo_DataItem& stItemData);
	void DrawAFASFRBarChart(_HisCCMAlg_SFRPlusHABasic_Info* pstBasic, _HisAutoFA_Rolongo_DataItem& stItemData);
	void DrawAFALpBarChart(_lpMFAParameter* pstParameter, _HisAutoFA_Rolongo_DataItem& stItemData);	
	int gereralAutoFA();
	_HisAutoFA_Rolongo_DB stAFARolongoDB;
#endif
#if (defined USE_EQUIPMENT_AFM_JSL_V2) 
	int mtfFocus();
#endif

#ifdef USE_EQUIPMENT_JSL_FUNCTION_V1
	int RsCommOut(unsigned char* pucComm, unsigned int uiCount, unsigned char ucCOMIndex = 1, bool bBack = false);
#endif
	 
	int getpreviewParameter(bool bupdate=false, bool bcheck = true);
	int getmtffaParameter(bool bupdate=false, bool bcheck = true);
	
	int startPreview();
	int stopPreview();
	int operateItem(_shoutCutDetail& currentitem);
	void updateItemstatus(_itemStatus& itemstatus);
	int GetTotalResult();
	int getBrightness(RECT stRange, int iMin, int iMax);
	int getColorRatio(RECT stRange, double dflR2GrMin, double dflR2GrMax, double dflB2GrMin, double dflB2GrMax);
	int setexposureTimeExe(unsigned int uiexposure);
	int setGain(float gain);
	int setMotorExe(int imotor, int iType);
	int getCustomIICGParameter(bool bupdate=false, unsigned int uiGroup=1, bool bcheck = true);
	int setCustomIICG(unsigned int uiGroup);
	void clearplotitem();

	int getBlemishParameter(bool bupdate=false, bool bcheck = true);
	int blemish();
	int blemishb();
	int getwhitePanelColorParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelColor();
	int getwhitePanelSNRParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelSNR();
	int getwhitePanelOCParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelOC();
	int getwhitePanelDefectLineParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelDefectLine();
	int getwhitePanelDefectPixelParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelDefectPixel();
	int getwhitePanelShadingParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelShading();
	int getwhitePanelVignettingParameter(bool bupdate=false, bool bcheck = true);
	int whitePanelVignetting();
	
	int getlpFAParameter(bool bupdate=false, bool bcheck = true);
	int lpFA();
	int getLpAFCParameter(unsigned char uctype = 0, bool bupdate = false, bool bcheck = true);
	int lpAFC(unsigned char uctype, int iNewStactics, int& iOldStatics); //0-近焦 1-中焦 2-远焦
	 
	int getSFRMFACAParameter(bool bupdate=false, bool bcheck = true);
	int sfrFACA();
	int getsfrAFCCAParameter(unsigned char uctype=0, bool bupdate=false, bool bcheck = true);
	int sfrAFCCA(unsigned char uctype, int iNewStactics, int& iOldStatics);
	void DrawSFRHAAFCPointCurve(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorDataItem, \
		_SFRAFCCAParameter* pstParameter, bool bCenter, bool bFOV);

	int getautoexposuredata(_autoExposreData *pstTheData);
	int updateautoexposuredata(_autoExposreData *pstTheData, _autoexposureItem* newdata);
	int autoExposure(RECT stroi,unsigned int uimin, unsigned int uimax, unsigned int uisleep, unsigned int uiindex, bool bG, bool bWhite,bool bCenterImage, float dCenterROIRatio);
	int autoFocus(unsigned int uiAlg, unsigned int uiChart, unsigned int uiTimeOut, unsigned int uiROILeft, unsigned int uiROITop, unsigned int uiROIRight, \
		unsigned int uiROIBottom, int iStartPos, unsigned int uiPedestal, unsigned int uiFrameSleep);
	int AutoRAWCaputre(char * FileName,unsigned int CaptureCount,unsigned int uisleep,unsigned int ROIW,unsigned int ROIH, bool bSavelog);
	int QualcommAWBLSCGoldenSelection(unsigned int uimodulecount, unsigned int uiblacklevel, unsigned int uiroidivisor, unsigned int GChannelMin, unsigned int GChannelMax);
	int mtfFA(unsigned int uiOpMode = 0); //0: Normal   1:Manual Mode B
	int getmtfAFCCAParameter(unsigned char uctype=0, bool bupdate=false, bool bcheck = true);
	int mtfAFCCA(unsigned char uctype, int iNewStactics, int& iOldStatics);
	void DrawMTFHAAFCPointCurve(std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorDataItem, \
		_mtfAFCParameter* pstParameter, bool bCenter, bool bFOV);

	int getblackfieldParameter(bool bupdate=false, bool bcheck = true);
	int blackfield();

	int getworkcurrentParameter(bool bupdate=false, bool bcheck = true);
	int testworkcurrent(); 
	int getstandbycurrentParameter(bool bupdate=false, bool bcheck = true);
	int teststandbycurrent();
	int getOSParameter(bool bupdate=false, bool bcheck = true);
	int openshortTest();
	int manualModeBLoop1();
	int playAudio(unsigned int cuiSource, unsigned int cuiPlayTime, float flSampleRateMultiple);
	int testMIC();
	int testLED();
	int fwBurn();

	int getotpburnParameter(bool bupdate=false, bool bcheck = true);
	int otpburn();
	int otpcheck();
	int ReadGolden();
	int getlsCheckParameter(bool bupdate=false, bool bcheck = true);
	int getlsSpecificationParameter(bool bupdate=false,bool bcheck=true);
	int LightSourceCheck();
	int LightSourceVerify();
	int LightSourceCal();
	int getLightSourceParam(QString &strMacAddr,QString &strChipID,double &dflCoefR,double &dflCoefB,QDateTime &time);
	int getGoldenChipID(IN QString strProjectModel,OUT QStringList &list);
	int getMacAddresses(std::string& macOUT);

	int getsavelogParameter(bool bupdate=false, bool bcheck = true);
	int getSerialNumber();
	int burnSerialNumber();

	int getafburnParameter(bool bupdate= false, bool bcheck = true);
	int afBurn(int farcode,int midcode,int nearcode);
	int afBurnCheck(); 

	int lschatemplate(bool breplace, unsigned char ucType, unsigned int uiShading);

	int saveimage(unsigned char ucimagesrc, unsigned char ucimageformat, bool bOriginal, bool bSaveFail, unsigned short usDelay);
	int serialport(QString QStrinfo, unsigned char ucEbaud,unsigned char ucEpar,unsigned char ucEstop,unsigned char ucCOMIndex = 0x1);
	int senttcpmessage(_QH_TcpIpCommu_Itemnew clientiteminfo);
	int FishEyeForjunge(double dspec);
	int dualcameracoaxialitytest(double dDualCameraCenterdistacne, double dSquare_HorizontalDistance, double dSquare_VerticalDistance,double dTestDistance,bool bMainCameraColorSensor, bool bSubCameraColorSensor,double dSpecx,double dSpecy,int iSpecH,int iSpecV);
	int dualcameracoaxialitytilttest(bool bMainCameraColorSensor, bool bSubCameraColorSensor,double dspecx,double dspecy);
#ifdef _HisFX3_Platform_Jigboard
	int Jig_StartPreview();
	int Jig_Change2Capture();
	int Jig_Change2Preview();
	int Jig_afBurn();
	int Jig_afBurnCheck(unsigned char ucType);
#endif

#ifdef USE_EQUIPMENT_GB_AFBURN
	int movetopos(unsigned char uctype, unsigned int uiIO, unsigned int uiOut);
#endif
	 
	int MTkErrorcodeConvert(int errorcode);
	int getpdafParameter(bool bupdate=false, bool bcheck = true);
	int PDAFCalibrationWhitePanel();
	int PDAFCalibrationSTEP2();
	int PDAFCalibration15CM();
	int PDAFCalibration50CM();
	int PDAFCalibration20CM();
	int PDAFBurnCheck();
	int PDAFautoExposure(RECT stroi,unsigned int uimin, unsigned int uimax, unsigned int uisleep, unsigned int uiindex);
	float PDAFGetWhiteGAver(unsigned char* pucBarlor, _HisFX3_BaylorMode enDataFormat, RECT stroi, int iWidth, int iHeight);
	int QualCommPDAFStep1();
	int QualCommPDAFStep2();
	int QualcommPDAFCheck();
	int QualCommPDAF_LVersion_GainCalibration();
	int QualCommPDAF_LVersion_DCCCalibration();
	int QualcommPDAF_VVersion_GetGainMAP();
	void  FindCurePeak(float *in,int Siz,float &MaxValue,int &MaxValueIndexe);
	void CureSmooth(float in[], float out[], int N);
	int MTKPDAFSTEP1_WhitePannel();
	int MTKPDAFSTEP2_20CM();
	int MTKPDAFCheck();
	int PDAFSTEP2Verify(int iPDAFDAC, int &iCDAFDAC,int  Width,int Height);
	int Display_GmCheckResult(int GainMapFlag);
	int print_return_code(int rc);
	int SONYIMX258PDAF_SPCCal();
	int  SONYPDAF_SPCCal();
	int SONYPDAF_DCCCal();
	void DCCVerify_PhaseDiffPixelCovert_IMX230(unsigned int *pSensorData,int PD_WindowIndex,  int PD_WindowMode, float &PDPixel);
	bool PhaseDifferenceCovert_IMX230(unsigned int *pSensorData,int *PD16_12, int *Coef16_12,int *PD8_6, int *Coef8_6,int PDWindowMode);
	void DCCVerify_PhaseDiffPixelCovert_IMX386(unsigned int *pSensorData,int PD_WindowIndex,  int PD_WindowMode, float &PDPixel);
	bool PhaseDifferenceCovert_IMX386(unsigned int *pSensorData,int *PD16_12, int *Coef16_12,int *PD8_6, int *Coef8_6,int PDWindowMode);
	void SavePDReadData(unsigned int iPDStartAddr,unsigned int *RegisterData, int *PDData_16_12,int *Coef_16_12,int *PDData_8_6, int *Coef_8_6, int iAFDAC,int PDMODE);
	int ApplySONYIMX258SPC();
	int SONYPDAFCheck(unsigned char CheckMode); // 1; SPC Check 2; DCC Check 3: Check SPC &DCC	

	int HISIPDAFSTEP1_WhitePannel();
	int HISIPDAFSTEP2_20CM();
	int HISIPDAFCheck();

#ifdef USE_EQUIPMENT_GB_PDAF
	int movetopos(unsigned char uctype);
#endif
	int getdualcameraParameter(bool bupdate=false, bool bcheck = true);
	int getDPCParameter(bool bupdate=false, bool bcheck = true);
	int CameraTiltRotationTestDataBurn();
	int CameraTiltRotationTestTestDataBurnCheck();
	int DualCameraCoaxilityTestDataBurn();
	int DualCameraCoaxilityTestDataBurnCheck();

	int Sensor_DPC_FunctionProcess();

	int CamdoraCaliration(int left1, int top1, int right1, int bottom1, int minArea1,int left2, int top2, int right2, int bottom2, int maxYShift);
	int Http2Camdora(int YShift);


	int rolongodebug(unsigned int uiTestType = 0);



	quint32 licenseCount;
	__int32 iNearPeakMotorDec;
	__int32 iMiddlePeakMotorDec;
	__int32 iFarPeakMotorDec;
	__int32 iMotorStartDec;
	_HisLog_Item stLogItem;
	_autoExposreData* pstAeData[45]; 
	_HisCCMAlg_AFC_LP_DB stAFCLpNearDB;
	_HisCCMAlg_AFC_LP_DB stAFCLpMiddleDB;
	_HisCCMAlg_AFC_LP_DB stAFCLpFarDB;

	_HisCCMAlg_AFC_SFRHA_DB stAFCSFRHANearDB;
	_HisCCMAlg_AFC_SFRHA_DB stAFCSFRHAMiddleDB;
	_HisCCMAlg_AFC_SFRHA_DB stAFCSFRHAFarDB;

	_HisCCMAlg_AFC_MTF_DB stAFCMTFNearDB;
	_HisCCMAlg_AFC_MTF_DB stAFCMTFMiddleDB;
	_HisCCMAlg_AFC_MTF_DB stAFCMTFFarDB;

    private:
		   void RAW10CovertDualPDLeftandRightImage(unsigned short *img,_HisFX3_BaylorMode cfa,unsigned int iWidth, unsigned int iHeight,unsigned short *img_l, unsigned short *img_r );


};

#endif

//