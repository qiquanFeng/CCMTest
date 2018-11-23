#ifndef HISFX3CCMALG_H
#define HISFX3CCMALG_H

#include <string>
#include "HisGlobalDefine.h"

#ifdef HISFX3CCMALG_LIB
# define HISFX3CCMALG_EXPORT __declspec(dllexport)
#else
# define HISFX3CCMALG_EXPORT __declspec(dllimport)
#endif

#define _His_MAX_BLOCK_COUNT					25
#define _His_MAX_DATABASE_PROJECT		9

struct _HisAlg_DebugList{
	unsigned short ustype;
	double dflvalue;
};

struct _HisAlg_Debug{
	unsigned int uipt_x;
	unsigned int uipt_y;
	std::vector<_HisAlg_DebugList> stlist;
};

struct _HisAlg_Cluster{
	__int32 iscore;
	RECT stRange;
}; 

struct _autoexposureItem{
	unsigned __int32 uifirstet;
	float flfirstlux;
	unsigned __int32 uifinalet;
	float flfinallux;
};

__declspec(align(128)) struct _autoFAItem{
	unsigned __int32 uiid;
	unsigned __int32 usfirststep;
	double dflfirstdis;
	float flfirstvalue[_His_MAX_BLOCK_COUNT];
	// 	unsigned __int32 usfinalstep;
	double dflfinaldis;
	float flfinalvalue;
};

struct MotorVPair
{
	int motor;
	float value;
};

struct SingleAACurvePair
{
	double value;
	double d;
};

struct _autofamtfCurve{
	unsigned __int8 u8grage;
	unsigned __int8 u8valuepass;
	unsigned __int8 u8uniformpass;
	unsigned __int8 u8type; //0: normal 1: average 2: grade1 3: grade2 4: grade3
	unsigned __int8 u8loop;
	unsigned __int16 u16step;
	double dfldistance;
	float flweightvalue;
	float flvalue[_His_MAX_BLOCK_COUNT]; 
};

struct _HisAlg_SFRBlock{
	RECT stblock[4];
	float flsfrvalue[4];
	float flsfraverage;
};

struct _HisAlg_ChartSFR{
	unsigned char uclevel;
	std::vector<_HisAlg_SFRBlock> stsfrs;
};

struct _HisAlg_LSCHA_Template{
	unsigned char enBayerMode;
	int iWdith;
	int iHeight;
	wchar_t wstrPath[MAX_PATH];
	unsigned int* puiTemplate;
};

struct _HisAlg_BlemishHA_DebugInfo{
	float flvalue;
	RECT stroi;
};

struct _HisAlg_ColorHA_DebugItem{

};

struct _HisAlg_ColorHA_DebugInfo{

};

struct _HisAlg_DefectPixelHB_Cluster{
	unsigned char ucType;		//1:defect 2:wound 3:dead
	bool bCenter;
	unsigned int uiPixelCount;
	unsigned int uiClusterCount;
};


struct _HisAlg_AutoExposure_DataItem{
	unsigned int uiTime;
	float flValue;
};

enum _HisAlg_DebugType{
	HisAlg_WhitePanel_Blemish_Corner					=	0x0001,
	HisAlg_WhitePanel_Blemish_Amplitude			=	0x0002,
	HisAlg_WhitePanel_Blemish_Dev						=	0x0003,
	HisAlg_WhitePanel_Color_Uniform					=	0x0004
};

enum _HisFX3_WhitePanel_TestItem{
	_WhitePanel_Blemish			=	0x0001,		//污点测试
	_WhitePanel_Color					=	0x0002,		//色异测试
	_WhitePanel_SNR					=	0x0004,		//性噪比
	_WhitePanel_OpticalCenter	=	0x0008,		//光学中心
	_WhitePanel_DefectPixel		=	0x0010,		//坏点
	_WhitePanel_Line					=	0x0020			//线条
};

struct _WhitePanel_DefectLine_Result {
	_HisAlg_LineType	lineType;
	_HisFX3_BufferFormat bufferType;
	unsigned int uiLineIndex;
	float flPercent;
};

struct _HisCCMAlg_AFC_ALL_DataItem{
	unsigned char ucStatus;  //0x0-FAIL 0x1-PASS 0xFF-undefined
	unsigned char ucFlag; //_HisCCMAlg_Rolongo_AFC_Tactics_Linear 0-上升 1-下降
	//_HisCCMAlg_Rolongo_AFC_Tactics_PEAK  1-PEAk点
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	short sMotorStep;
};

struct _HisCCMAlg_AFA_ALL_DataItem{
	unsigned char ucStatus;  //0x0-FAIL 0x1-PASS 0x2-OK2 0xFF-undefined
	unsigned char ucDirect; //0x0-CW 0x1-CCW 0x10-Last Up Check1 0x11-Last Up Check2 0x13-UnderSpin 0x20-Last CCW Retry 0x30-Last CW Retry
	unsigned char ucGrade;
	unsigned char ucType; //0-普通计算 
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflRadius;
	double dflLesnAngle;
	double dflLaser;
	double dflAbsAngle;
};

struct _HisCCMAlg_BlemishHC_Spec{
	float flLux;

	_HisCCMAlg_BlemishHC_Spec()
	{
		flLux	=	0.005f;
	}
};

struct _HisCCMAlg_BlemishHC_Blemish{
	RECT stROI;
	float flLux;
	float flColor;
	unsigned int uiSpecIndex;
};

struct _HisCCMAlg_SFRBlock_ValueItem
{
	float mtf50;
	RECT roi; 
	bool bH; //true: 属于水平解析力， false:属于垂直解析力
};

struct _SingleAASFR_SFRPos
{
	double centerX[9];
	double centerY[9];
	RECT left[9];
	RECT right[9];
	RECT top[9];
	RECT bottom[9];

	_SingleAASFR_SFRPos& operator = (const _SingleAASFR_SFRPos& t)
	{
		memcpy(this->centerX, t.centerX, sizeof(double) *9);
		memcpy(this->centerY, t.centerY, sizeof(double) *9);
		memcpy(this->left, t.left, sizeof(RECT) *9);
		memcpy(this->right, t.right, sizeof(RECT) *9);
		memcpy(this->top, t.top, sizeof(RECT) *9);
		memcpy(this->bottom, t.bottom, sizeof(RECT) *9);
		return *this;
	}
};

// struct _SingleAASFR_MarkPos
// {
// 
// };

class HISFX3CCMALG_EXPORT CHisFX3CCMAlg
{
public:
	CHisFX3CCMAlg(void);
	~CHisFX3CCMAlg(void);

	const wchar_t* GetLastError(void);
	void ClearError(void);

	void averageraw8x2(unsigned char* pucSrcImg1, unsigned char* pucSrcImg2, unsigned char* pucDesImg, unsigned int uiWidth, unsigned int uiHeight);
	void recoverrawdata(unsigned __int8* pui8data, unsigned int uisize);
	void raw10toraw8(unsigned short* pusRaw10, unsigned char* pucRaw8, int iwidth, int iheight);
	void raw8toraw10( unsigned char* pucRaw8, unsigned short* pusRaw10, int iwidth, int iheight);
	void raw12toraw8(unsigned short* pusRaw12, unsigned char* pucRaw8, int iwidth, int iheight);
	void raw8toraw12( unsigned char* pucRaw8, unsigned short* pusRaw12, int iwidth, int iheight);
	void raw12toraw10(unsigned short* pusRaw12, unsigned short* pusRaw10, int iwidth, int iheight);
	void raw10toraw12(unsigned short* pusRaw10, unsigned short* pusRaw12, int iwidth, int iheight);
	int patchbaylor(void* pvbalor ,int iwidth, int iheight, void* pvb, void* pvr, void* pvgr, void* pvgb, unsigned char ucbalormode);
	void copyframebuffer(unsigned char* pucsrc, unsigned char* pucdes, unsigned int uisize);
	void extactYfromYUV422U8(unsigned char* pucYUV422U8, unsigned char* pucY, unsigned int uisize, _HisFX3_BaylorMode emdataFormat);
	int flip(unsigned char* pucBuffer, int iWidth, int iHeight,_HisFX3_BaylorMode ucDataFormat);
	int mirror(unsigned char* pucBuffer, int iWidth, int iHeight,_HisFX3_BaylorMode ucDataFormat);
	void rgb24tograybit8(unsigned char* pucRGB24, unsigned char* pucGray, int iWidth, int iHeight, RECT& stBlock);
	void subblacklevel(unsigned char* pucImage, short sLevel, unsigned int uiPixel, unsigned char ucDataFormat);

	double HisCCMWhitePartAverageU8(unsigned char* pucY, unsigned int uiWidth, unsigned int uiHeight);

	int HisCCMYUV2RGB24(unsigned char* pucYUV, unsigned char* pucRGB24, unsigned int uiWidth, unsigned int uiHeight, unsigned char ucFormat, unsigned int uiFlag=0x0);
	int HisCCMBarlor2RGB24(unsigned char* pucRaw, unsigned char* pucRGB24, int iWidth, int iHeight, unsigned char ucBaylor, unsigned char ucAlg = 0);
	int HisCCMBrightness(unsigned char *pucRGB24, int iwidth, int iheight, RECT stRange, float& flgrayValue, unsigned char ucbits=8);
	int HisCCMGetAWBGain(unsigned char* pucraw, int iwidth, int iheight, unsigned char ucbaylormode, float& flGainB, float& flGainR, unsigned char param=11);
	int HisCCMSetAWBGain(unsigned char* pucraw, int iwidth, int iheight, unsigned char ucbaylormode, float flGainB, float flGainR);

	int HisCCMDeinterlaceYUVBit8_Overlap(unsigned char* pucSrcImg, unsigned char* pucDesImg, unsigned int uiWidth, \
		unsigned int uiHeight,unsigned int uiDummyLeft=0, unsigned int uiDummyRight=0, unsigned int uiDummyTop=0,unsigned int uiDummyBottom=0);

	int HisCCMFrameOverlapb8_step1(unsigned char* pucsrc1, unsigned char* pucsrc2, unsigned short* pusdes, int ipixcount);
	int HisCCMFrameOverlapb8_step2(unsigned char* pucsrc1, unsigned short* pusdes, int ipixcount);
	int HisCCMFrameOverlapb8_step3(unsigned short* pussum, unsigned char* pucdes, int ipixcount, unsigned char ucdiv);

	int HisCCMMTF(unsigned char* pucRGB24, int iWidth, int iHeight, RECT stRange, unsigned int uiAlgorithm, float& flMTFValue, bool bGChannel=false);


	//************************************
	// Method:    HisCCMWhitePanel_PartI(测试白板下的污点和颜色异常)
	// FullName:  CHisFX3CCMAlg::HisCCMWhitePanel_PartI
	// Access:    public 
	// Returns:   int(0:成功；非0：失败)
	// Qualifier:
	// Parameter: unsigned char * pucrgb24
	// Parameter: int iwidth
	// Parameter: int iheight
	// Parameter: unsigned short usitem(_WhitePanel_Blemish | _WhitePanel_Color)
	// Parameter: std::vector<RECT> & stblemish(污点的位置)
	// Parameter: RECT & stcoloruniform(颜色异常的位置)
	// Parameter: float & centera(中心区域的A分量的均值)
	// Parameter: float & centerb(中心区域的B分量的均值)
	// Parameter: float & symmetrymax(四周对称位置的最大颜色差异 sqrt((a1-a2)*(a1-a2) + (b1-b2)*(b1-b2))
	// Parameter: float & falloffmax(中心区域与四周的最大颜色差异)
	// Parameter: _HisAlg_Debug & stdebug(返回调试数值，方便规格设定)
	// Parameter: float cflcut(污点参数，计算区域0.8-0.9)
	// Parameter: int ihighpass(污点参数，高通>9)
	// Parameter: int ilowpass(污点参数，低通：<30)
	// Parameter: int amplitude(污点spec，频谱振幅，依模组而定)
	// Parameter: int dev(污点spec，差异)
	// Parameter: float blemishconer(污点spec，现没用)
	// Parameter: float flcolorcenter(颜色参数：要计算的中心区域比例)
	// Parameter: int colorbw(颜色参数,要划分的区域 >16)
	// Parameter: float coloruniform(颜色spec)
	//************************************
	int HisCCMWhitePanel_PartIHA(unsigned char* pucrgb24, int iwidth, int iheight, unsigned short usitem, \
		std::vector<RECT>& stblemish, RECT& stcoloruniform, float& centera, float& centerb, float& symmetrymax, \
		float& falloffmax, _HisAlg_Debug& stdebug, float cflcut=0.9, int ihighpass=12, int ilowpass=24, int amplitude=70, int dev=43, \
		float blemishconer=0.1, float flcolorcenter=0.08, int colorbw=32, float coloruniform=2.8);

	//************************************
	// Method:    HisCCMWhitePanel_PartII(测试白板下的光心，线条异常)
	// FullName:  CHisFX3CCMAlg::HisCCMWhitePanel_PartII
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucr(baylor raw分拆出来的R分量)
	// Parameter: unsigned char * pucb
	// Parameter: unsigned char * pucg1
	// Parameter: unsigned char * pucg2
	// Parameter: unsigned short usitem(_WhitePanel_OpticalCenter | _WhitePanel_Line)
	// Parameter: int iwidth
	// Parameter: int iheight
	// Parameter: int & ioc_x
	// Parameter: int & ioc_y
	// Parameter: std::vector<float> & stmaxLine(返回线条测试的数值，结果如下：)
	//					  R  分量: 最大差异行位置，最大差异值,最大差异列位置，最大差异值
	//					  B  分量: 最大差异行位置，最大差异值,最大差异列位置，最大差异值
	//					  G1分量: 最大差异行位置，最大差异值,最大差异列位置，最大差异值
	//					  G2分量: 最大差异行位置，最大差异值,最大差异列位置，最大差异值
	// Parameter: float flocratio(测试光心的pixel比例，最好设置在(0.01, 0.1)的范围)
	//************************************
	int HisCCMWhitePanel_PartIIHA(unsigned char* pucr, unsigned char* pucb, unsigned char* pucg1, unsigned char* pucg2, \
		unsigned short usitem, int iwidth, int iheight, int& ioc_x, int& ioc_y, std::vector<float>& stmaxLine, float flocratio=	0.09);

	//************************************
	// Method:    HisCCMWhitePanel_PartIII(测试白场下的坏像素点，伤像素点和死像素点)
	// FullName:  CHisFX3CCMAlg::HisCCMWhitePanel_PartIII
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucr(baylor raw分拆出来的R分量, 在曝光时间x的条件下)
	// Parameter: unsigned char * pucb
	// Parameter: unsigned char * pucg1
	// Parameter: unsigned char * pucg2
	// Parameter: unsigned char * puchr(baylor raw分拆出来的R分量, 在曝光时间x/2的条件下)
	// Parameter: unsigned char * puchb
	// Parameter: unsigned char * puchg1
	// Parameter: unsigned char * puchg2
	// Parameter: int iwidth
	// Parameter: int iheight
	// Parameter: int & idefectpixel(坏点的总个数)
	// Parameter: int & iwoundpixel(伤点的总个数)
	// Parameter: int & ideadpixel(死点的总个数)
	// Parameter: int & itotalscore(不良像素点的总分数)
	// Parameter: std::vector<_HisAlg_Cluster> & stCluster(不良像素聚类的范围和总分数)
	// Parameter: float defect(坏点的规格 > 0.01)
	// Parameter: float wound(伤点的规格 >坏点)
	// Parameter: int clusterscore(聚类的规格 >1)
	// Parameter: int lineblock(图像分块: (100, 300))
	// Parameter: unsigned char defectscore(一个坏点的分数 >0)
	// Parameter: unsigned char woundscore(一个伤点的分数 >坏点)
	// Parameter: unsigned char deadscore(一个死点的分数 >伤点)
	//************************************
	int HisCCMWhitePanel_PartIIIHA(unsigned char *pucr, unsigned char *pucb, unsigned char* pucg1, unsigned char* pucg2, \
		int iwidth, int iheight, int& idefectpixel, int& iwoundpixel, int& ideadpixel, int& itotalscore, std::vector<_HisAlg_Cluster>& stCluster, \
		int& iclustercount, float defect=0.1, float wound=0.2, float dead=0.3, int clusterscore=50,int lineblock=180,unsigned char defectscore	=1,\
		unsigned char woundscore=2,unsigned char deadscore=3);
	int HisCCMWhitePanel_DefectPixelHB(unsigned char *pucr, unsigned char *pucb, unsigned char* pucgr, unsigned char* pucgb, \
		int iwidth, int iheight,float defect_min, float defect_max, float wound_min, float wound_max, float dead_min, float dead_max, float flCenterRange, unsigned int uiBlockSize, _HisFX3_BaylorMode enDataFormat, \
		bool bPerChannel, int& iCenterDefect, int& iCenterWound, int& iCenterDead, int& iEdgeDefect, int& iEdgeWound, int& iEdgeDead, \
		RECT& stMaxCluster, std::vector<_HisAlg_DefectPixelHB_Cluster>& vectorCluster, bool bDebug);

	int HisCCMWhitePanel_PartIIIIHA(std::vector<unsigned char*> vectBaylorR, std::vector<unsigned char*> vectBaylorB, \
		std::vector<unsigned char*> vectBaylorG1, std::vector<unsigned char*> vectBaylorG2, int iwidth, int iheight, \
		double& dflSNR_R, double& dflSNR_B, double& dflSNR_G);

	int HisCCMWhitePanel_BlemishHA(unsigned char* pucrgb24, int iwidth, int iheight, std::vector<RECT>& stblemish, \
		_HisAlg_Debug& stdebug, float cflcut, int ihighpass, int ilowpass, int amplitude, int dev, float blemishconer);
	int HisCCMWhitePanel_BlemishHB(unsigned char* pucY, int iwidth, int iheight, float flZone1Range, \
		unsigned int uiZone3SizeX, unsigned int uiZone3SizeY, float* pflZone1Spec, float* pflZone2Spec, float* pflZone3Spec, \
		std::vector<RECT>& stblemish, bool bFilter, bool bDebug, _HisAlg_BlemishHA_DebugInfo* pstZone1Debug, \
		_HisAlg_BlemishHA_DebugInfo* pstZone2Debug, _HisAlg_BlemishHA_DebugInfo* pstZone3Debug);
	int HisCCMWhitePanel_BlemishHC(unsigned char* pucImgR, unsigned char* pucImgG, unsigned char* pucImgB, int iwidth, int iheight, \
		_HisCCMAlg_BlemishHC_Spec* pstSpec, std::vector<_HisCCMAlg_BlemishHC_Blemish>& vecBlemish, const float cflEdgeSide=0.05f, const float cflCorner = 0.05f, const float cflMinArea=0.00006f, \
		const float cflMaxArea=0.125f, bool bDebug=false, const double cdflThresholdSub=2.0, const bool cbAWB=false, const bool cbOC=true);
	int contrastenhance(unsigned char* pucY, int iWidth, int iHeight);
	 
	int HisCCMWhitePanel_ColorHA(unsigned char* pucrgb24, int iwidth, int iheight, RECT& stcoloruniform, \
		float& centera, float& centerb, float& symmetrymax, float& falloffmax, _HisAlg_Debug& stdebug, \
		float flcolorcenter, int colorbw, float coloruniform);

	int HisCCMWhitePanel_DefectLineHA(unsigned char* pucr, unsigned char* pucb, unsigned char* pucgr, \
		unsigned char* pucgb, int iwidth, int iheight, std::vector<_WhitePanel_DefectLine_Result>& stmaxLine);

	int HisCCMWhitePanel_OCHA(unsigned char* pucgr, int iwidth, int iheight, int& ioc_x, int& ioc_y, float flocratio);
	int HisCCMWhitePanel_OCHB(unsigned char* bufY, int iwidth, int iheight, float sizeRatio, float& ocx, float& ocy);
	int HisCCMWhitePanel_ShadingHA(unsigned char* pucRGB24, unsigned int uiWidth, unsigned int uiHeight, _HisAlg_Shading_HA_Config& stConfig, _HisAlg_Shading_HA_Data& stData, bool bDebugMode=false);
	int HisCCMWhitePanel_ShadingHB(unsigned char* pucRGB24, unsigned int uiWidth, unsigned int uiHeight, _HisAlg_Shading_HB_Data& stData, bool bDebugMode=false);
	int HisCCMWhitePanel_VignettingHA(unsigned char* pucRGB24, unsigned int uiWidth, unsigned int uiHeight, _HisAlg_Vignetting_HA_Config& stConfig, _HisAlg_Vignetting_HA_Data& stData, bool bDebugMode=false);
	
	int HisCCMBlackFieldHA(unsigned char* pucRaw8, _HisFX3_BaylorMode ucDataFormat, int iWidth, \
		int iHeight, unsigned int uiClusterDefine, unsigned char ucLightDefine, unsigned int uiCenterDefine, unsigned int& uiCenterPixel, \
		unsigned int& uiAroudPixel, unsigned int& uiCenterCluster, unsigned int& uiAroudCluster, \
		unsigned int& uiMaxClusterScore, RECT& stMaxClusterRect);
	int HisCCMBlackFieldHB(unsigned char* pucRaw8, _HisFX3_BaylorMode ucDataFormat, int iWidth, \
		int iHeight, unsigned char ucScoreGrade1, unsigned char ucScoreGrade2, unsigned char ucScoreGrade3, \
		unsigned char ucWeightGrade1, unsigned char ucWeightGrade2, unsigned char ucWeightGrade3, \
		unsigned int uiClusterScore, unsigned int& uiPixelCount, unsigned int& uiScoreCount, unsigned int& uiClusterCount, \
		unsigned int& uiMaxClusterScore, RECT& stMaxClusterRect);

	//************************************
	// Method:    HisCCMSFROne 测试单个block的SFR值
	// FullName:  CHisFX3CCMAlg::HisCCMSFROne
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucrgb24(图像数据，数据格式为rgb24)
	// Parameter: int iwidth(图像宽)
	// Parameter: int iheight(图像高)
	// Parameter: RECT stblock(黑白斜边所在位置)
	// Parameter: unsigned char ucMinCantrast(黑白区域最小亮度差值)
	// Parameter: double * pdflsfrvalue(返回SFR曲线, 长度==((stblock.right-stblock.left) >>2)<<1 )
	// Parameter: int isftcurvelen(SFR曲线长度)
	// Parameter: float & flmtf50(返回MTF50值) 
	//************************************
	int HisCCMSFROne(float* pflY, int ibw, int ibh, unsigned char ucMinCantrast, double* pdflsfrvalue, int& isftcurvelen, float& flmtf50, float* MTF50P=0, float* MTF30=0, float* MTF30P=0);
	int decodeSFRChartTAHA(unsigned char* pucY, int iWidth, int iHeight, int iSideMin, int iSideMax, std::vector<_SFRBlackItem>& vecPos);
	int getSFRFOVPos(std::vector<_SFRBlackItem>& vecPos, int iWidth, int iHeight, float flFOV, float flAngle, int iROIW, int iROIH, \
		int iDisTolenrance, std::vector<_SFRBlackROI4>& vecFOVROI, unsigned int uiBlockCount = 4, unsigned char* pucDirect = NULL, bool bOnlyInner = false);
	int getSFRAMarkDistance(std::vector<_SFRBlackItem>& vecPos, int iWidth, int iHeight, int iDisTolenrance, int iIndex, \
		double& dflDistance, std::vector<RECT>& vectorMark);
	int getChartAlignMarkCenter(std::vector<_SFRBlackItem>& vecPos, int iWidth, int iHeight, float flFOV, \
		float flAngle, int iDisTolenrance, POINT& stP1, POINT& stP2, POINT& stP3, POINT& stP4, POINT& stCenter);

	int getSFRBlockValue(unsigned char* bufY, int width, int height, RECT stROI, int sfrW, int sfrH, _HisCCMAlg_SFRBlock_ValueItem* mtfValue);

	int HisCCMGetnextet(_autoexposureItem* paedata, unsigned int usdatacount, float flnowlux, unsigned int uinowet, \
		float flminlux, float flmaxlux, unsigned int uiminet, unsigned int uimaxet, unsigned int& uinextet, unsigned int uiindex=0);

	int HisCCMGetNextAutoFAStepHA(std::vector<_autofamtfCurve>& vectorcurve, _autofamtfCurve& stnextstep, \
		_autoFAItem* mtfdata, double dfldislimit, bool& bdirectup, float flpeakdef, float flpeakfall,\
		unsigned int udatacount, unsigned int ublockcount, double dfldismin, double dfldismax, double* pdflgrade, float* pflgradedef);

	int HisCCMImageMosaicDEX3(unsigned char* pucraw1, unsigned char* pucraw2, unsigned char* pucraw3, \
		unsigned char* pucdesraw, int iwidth, int iheight);

	int HisCCMLSCHA_ImportTemplate(void* pvRaw, int iWidth, int iHeight, \
		_HisFX3_BaylorMode enBayerMode, wchar_t* pwstrPath, bool bChannel1 = true);
	int HisCCMLSCHA_SaveTemplate(void* pvRaw1, void* pvRaw2, void* pvRaw3, void* pvRaw4, void* pvRaw5, \
		void* pvRaw6, void* pvRaw7, void* pvRaw8, int iWidth, int iHeight, _HisFX3_BaylorMode enBayerMode, double dflShading, \
		unsigned char ucType, wchar_t* pwstrPath);

	int HisCCMLinePairValueHA(_HisCCMAlg_ImageBuffer& imgBuffer, RECT stROI, unsigned int uiLineCount, unsigned int uiContrastThreshold, \
		int iminValue, int imaxValue, double dflAngle, double dflValueOffset, double& dflValue, RECT& m_rcMaxDetectedLpPos, RECT& m_rcMinLpPos, RECT& m_rcMaxLpPos);

	int HisCCMlinePairDetectHA(char* lpbuff,int width,int height,const unsigned int cuiLpWMin, const unsigned int cuiLpWMax, \
		const unsigned int cuiLpHMin, const unsigned int cuiLpHMax, const unsigned int cuiMarkMin, const unsigned int cuiMarkMax, const double cdflMarkFOVMin, \
		const double cdflMarkFOVMax, const double cdflMarkAngle, const int ciOffsetW, const int ciOffsetH, int& centerptx,int& centerpty, \
		double& dangle,double& ddistance,std::vector<RECT>& vectorBlock,std::vector<RECT>& vectorMark);
	int HisCCMExtractLPDetectHAFOV4(std::vector<RECT>& vectorBlock, int iImgWidth, int iImgHeight, int iCenterX, int iCenterY, double dflFOV, double dflAngle, double dflOffset, _HisCCMAlg_RECT_FOV4& stFOV4);
	int HisCCMExtractLPDetectHBFOV4(std::vector<RECT>& vectorBlock, int iImgWidth, int iImgHeight, int iCenterX, int iCenterY, double dflDistace, double dflAngle, double dflOffset, _HisCCMAlg_RECT_FOV4& stFOV4);

	int HisAFATactics_LP_CCW_PASS_HA(_HisCCMAlg_AFA_Tactics_Basic& stTBasic, _HisCCMAlg_AFA_Tractics_CCW_PASS& stTThe, \
		std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItem, double& dflAngle, double& dflAbsAngle);
	int HisAFATactics_LP_CCW_BEST_HA(_HisCCMAlg_AFA_Tactics_Basic& stTBasic, _HisCCMAlg_AFA_Tractics_CCW_BEST& stTThe, \
		std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItem, double& dflAngle, double& dflAbsAngle);

	int HisAFCTactics_LP_DB_HA(_HisCCMAlg_AFC_Tactics_Basic& stBasic, std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItem, _HisCCMAlg_AFC_LP_DB& stDB, int& iMotor);
	int HisAFCTactics_SFRHA_DB_HA(_HisCCMAlg_AFC_Tactics_Basic& stBasic, std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorItem, _HisCCMAlg_AFC_SFRHA_DB& stDB, int& iMotor);
	int HisAFCTactics_MTFHA_DB_HA(_HisCCMAlg_AFC_Tactics_Basic& stBasic, std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorItem, _HisCCMAlg_AFC_MTF_DB& stDB, int& iMotor);
	float AFPeakFitting(std::vector<MotorVPair>& pairs);
	void HisAFATactics_Rolongo_CaculateValue(_HisAutoFA_BASIC_STACTICS& stTBasic, std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItem);
	int HisAFATactics_Rolongo_GetPeakIndex(_HisAutoFA_BASIC_STACTICS& stBasic, std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItem);
	int HisAFATactics_ALL_CCW_DB_HA(_HisAutoFA_BASIC_STACTICS& stBasic, std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItem, _HisAutoFA_Rolongo_DB& stDB, double& dflAbsAngle, unsigned char& ucType, unsigned char& ucDirect);

	double SingleAAPeakFitting(std::vector<SingleAACurvePair>& pairs);

	void resizeImageFrame(unsigned char* pucSrcRGB24, int iSrcWidth, int iSrcHeight, unsigned char* pucDesRGB24, int iDesWidth, int iDesHeight, int iMethod, int& iOffsetLeft, int& iOffsetTop, unsigned int uiAspectRatio=0);
	void resizeImageFrameSodu(unsigned char* pucSrcRGB24, int iSrcWidth, int iSrcHeight, RECT stSrcROI, unsigned char* pucDesRGB24, int iDesWidth, int iDesHeight, int iMethod);

	int GetSingleAASFRPosInfo(unsigned char* rgb24, int width, int height, int fovCount, float* fov, float* fAngle, \
		int* sfrSearchROIW2, int* sfrSearchROIH2, int* ROIW, int* ROIH, _SingleAASFR_SFRPos* sfrPos);

	void test();

private:

	int HisCCMBrightness_b8(unsigned char *pucRGB24, int& iwidth, int& iheight, RECT& stRange, float& flgrayValue);

	int HisCCMLSCHA_SaveTemplate_Raw8(unsigned char* pucRaw1, unsigned char* pucRaw2, unsigned char* pucRaw3, \
		unsigned char* pucRaw4, unsigned char* pucRaw5, unsigned char* pucRaw6, unsigned char* pucRaw7, \
		unsigned char* pucRaw8, int iWidth, int iHeight, _HisFX3_BaylorMode enBayerMode, double dflShading, wchar_t* pwstrPath);
	int HisCCMLSCHA_SaveTemplate_Raw10(unsigned short* pusRaw1, unsigned short* pusRaw2, unsigned short* pusRaw3, \
		unsigned short* pusRaw4, unsigned short* pusRaw5, unsigned short* pusRaw6, unsigned short* pusRaw7, \
		unsigned short* pusRaw8, int iWidth, int iHeight, _HisFX3_BaylorMode enBayerMode, double dflShading, wchar_t* pwstrPath);
	int HisCCMLSCHA_ImportTemplate_Raw8(unsigned char* pucRaw, int iWidth, int iHeight, \
		_HisFX3_BaylorMode enBayerMode, wchar_t* pwstrPath, bool bChannel1);
	int HisCCMLSCHA_ImportTemplate_Raw10(unsigned short* pusRaw, int iWidth, int iHeight, \
		_HisFX3_BaylorMode enBayerMode, wchar_t* pwstrPath, bool bChannel1);

	int HisAFCTactics_ALL_NoDB_HA(_HisCCMAlg_AFC_Tactics_Basic& stBasic, std::vector<_HisCCMAlg_AFC_ALL_DataItem>& vectorItem, int& iMotor, float cflValueDev);
	

private:
	int isfrbin;
	double* pdflsfrwindow;
	double* pdflsfrdftcos;
	double* pdflsfrdftsin;
	void* classMiddle;
	_HisAlg_LSCHA_Template stLSCHATemplateC1;
	_HisAlg_LSCHA_Template stLSCHATemplateC2;
	std::wstring wstrLastError;

	bool bHisFX3PlatformConstruct;
};

#endif // HISFX3CCMALG_H
