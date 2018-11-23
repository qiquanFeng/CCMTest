#ifndef ROLONGOIMAGETESTALG_H
#define ROLONGOIMAGETESTALG_H

#include <windows.h>
#include<vector>
#include "HisGlobalDefine.h"

#ifdef ROLONGOIMAGETESTALG_LIB
#define ROLONGOIMAGETESTALG_EXPORT __declspec(dllexport)
#else
#define ROLONGOIMAGETESTALG_EXPORT __declspec(dllimport)
#endif

struct _sfrresult
{
	POINT ptH1;
	POINT ptH2;
	POINT ptV1;
	POINT ptV2;
	POINT ptC;
	_sfrresult()
	{
		ptH1.x	=	0;
		ptH1.y	=	0;
		ptH2.x	=	0;
		ptH2.y	=	0;
		ptV1.x	=	0;
		ptV1.y	=	0;
		ptV2.x	=	0;
		ptV2.y	=	0;
		ptC.x	=	0;
		ptC.y	=	0;

	}
};

struct __HisShadingHD_Result_Item
{
	RECT stROI;
	float flY;
	float flBG;
	float flRG;
};

struct _HisShadingHD_Result
{
	int iCenterX;
	int iCenterY;
	float flPP_Y;
	float flPP_RG;
	float flPP_BG;
	std::vector<__HisShadingHD_Result_Item> vecItem;
	_HisShadingHD_Result()
	{
		iCenterX	=	iCenterY	=0;
		flPP_Y = flPP_RG =flPP_BG = 0.0f;
	}
};

struct _HisWhiteColorHB_Result_item
{
	RECT roi;
	float r, g, b;
	float rg, bg;
	_HisWhiteColorHB_Result_item()
	{
		roi.left	=roi.right	=roi.top	=roi.bottom	=0;
		r	=g	=b	=rg	=bg	=0.0f;
	}
};

struct _HisWhiteColorHB_Result
{
	float PP_RG, PP_BG;
	_HisWhiteColorHB_Result_item center; 
	_HisWhiteColorHB_Result_item LT;
	_HisWhiteColorHB_Result_item RT;
	_HisWhiteColorHB_Result_item LB;
	_HisWhiteColorHB_Result_item RB;
	std::vector<_HisWhiteColorHB_Result_item> vecUnion;
	_HisWhiteColorHB_Result()
	{
		PP_RG	=	PP_BG	=	0.0f;
	}
};

class ROLONGOIMAGETESTALG_EXPORT CRolongoImageTestAlg
{
public:
	CRolongoImageTestAlg();
	~CRolongoImageTestAlg();

	int CRolongoBlockAutomaticSearching(RECT stRect,unsigned char* pucrgb,int iWidth, int iHeight,int iSize, RECT& RtRect,int iSizeExtend=20);
	int CRolongoBlockAutomaticSearchingV2(RECT stRect,unsigned char* pucrgb,int iWidth, int iHeight,int iSize, RECT& RtRect,int iSizeExtend=20);
	int MTFChartBMarkDistance(unsigned char* pucRGB24, int iWdith, int iHeight, double& dflDistance);
	int cvRolongoMTFChartMarkDetectV2(unsigned char* pucrgb,RECT stRect,int iWidth,int iHeight,POINT& pt1,POINT& pt2);
	int cvRolongoMTFChartMarkDetect(unsigned char* pucrgb, int iWidth,int iHeight, float flROIX, float flROIY_S, float flROIY_E, \
		float& flPt1X, float& flPt1Y, float& flPt2X, float& flPt2Y, RECT& stROI1, RECT& stROI2, bool bRevert= false);
	int RolongoTestenvironmentDetection(unsigned char* pucrgb,int iWidth,int iHeight, RECT stRect,int iResize,int& iEnvironmentflag,bool bChartflag =false);
	int cvRolongoSFRMarkdetect(unsigned char* pucrgb,RECT stRect,int iWidth,int iHeight,_sfrresult& sfrresultpar);
	int cvRolongoImageStitch(unsigned char* pucImage1Buff,unsigned char* pucImage2Buff,int iWidth,int iHeight,bool bDown,int iW_min,int iH_min,int& iMatchRows,int& iResultWidth,int& iResultHeight);
	int cvRolongoImageStitch_SIFT(unsigned char* pucImage1Buff,unsigned char* pucImage2Buff,int iWidth,int iHeight,bool bDown,bool bResize,double* dMatH,int& iMatchRows,int& iResultWidth,int& iResultHeight);
	int cvRolongoFindCollimatorArea(unsigned char* pucY, int iWidth, int iHeight, int iSideMin, int iSideMax, std::vector<_SFRBlackItem>& vecPos,bool bFindCenter);
	int cvRolongoRingdetect(unsigned char* pucgray,int iWidth,int iHeight,int iSlotnnumber,double& angle);
	int cvRolongoForjungeFishEye(unsigned char* pucrgb,int iwidth,int iheight,int& iCenterx,int& iCentery ,std::vector<double>& vpercent,int ithreshold	=100);
	//************************************
	// Method:    cvRolongoCoaxialityCailibrationbySquare 通过正方形校准双摄同轴度
	// FullName:  CRolongoCoaxialityCalibration::cvRolongoCoaxialityCailibrationbySquare
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucrgbmainbuff  主摄像头图像buff
	// Parameter: bool bIsrgbmain				主摄像头buff是否是彩色
	// Parameter: int iWidthmain				主摄像头buff宽
	// Parameter: int iHeightmain				主摄像头buff高
	// Parameter: unsigned char * pucrgbassistantbuff	副摄像头图像buff
	// Parameter: bool bIsrgnassis						副摄像头buff是否是彩色
	// Parameter: int iWidthassistance					副摄像头buff宽
	// Parameter: int iHeightassistance					副摄像头buff高
	// Parameter: double dChartsquaredistancex			chart水平方块距离单位mm
	// Parameter: double dChartsquaredistancey			chart竖直方块距离单位mm
	// Parameter: double dCamdistance					主摄像头副摄像头lens中心距离 单位mm
	// Parameter: double dDcam2chart					chart到摄像头距离 单位 mm
	//输出
	// Parameter: double & dAnglex						双摄水平旋转角度
	// Parameter: double & dAngley						双摄竖直旋转角度
	// Parameter: int & iPixeldiffx						双摄水平偏移像素点个数
	// Parameter: int & iPixeldiffy						双摄竖直偏移像素点个数
	//************************************
	int cvRolongoCoaxialityCailibrationbySquare(unsigned char* pucrgbmainbuff,bool bIsrgbmain, int iWidthmain, int iHeightmain,unsigned char* pucrgbassistantbuff,bool bIsrgnassis,int iWidthassistance,int iHeightassistance,double dChartsquaredistancex,double dChartsquaredistancey,double dCamdistance,double dDcam2chart,double&dAnglex,double& dAngley,double& dAnglez,int&iPixeldiffx,int& iPixeldiffy);
	//************************************
	// Method:    cvRolongoCoaxialityCailibrationbyCircle 通过中心的圆环校准双摄同轴度
	// FullName:  CRolongoCoaxialityCalibration::cvRolongoCoaxialityCailibrationbyCircle
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucrgbmainbuff	主摄像头图像buff
	// Parameter: bool bIsrgbmain					主摄像头是否彩色
	// Parameter: int iWidthmain					主摄像头buff宽
	// Parameter: int iHeightmain					主摄像头buff高
	// Parameter: unsigned char * pucrgbassistantbuff	副摄像头图像buff
	// Parameter: bool bIsrgnassis						副摄像头是否是彩色
	// Parameter: int iWidthassistance					副摄像头buff宽
	// Parameter: int iHeightassistance					副摄像头buff高
	//输出
	// Parameter: double & dAnglex						水平旋转角度
	// Parameter: double & dAngley						竖直旋转角度
	//************************************
	int cvRolongoCoaxialityCailibrationbyCircle(unsigned char* pucrgbmainbuff,bool bIsrgbmain, int iWidthmain, int iHeightmain,unsigned char* pucrgbassistantbuff,bool bIsrgnassis,int iWidthassistance,int iHeightassistance,double&dAnglex,double& dAngley);
	//************************************
	// Method:    cvRolongoCoaxialityCailibrationbyDistortion 通过畸变校准双摄同轴度
	// FullName:  CRolongoCoaxialityCalibration::cvRolongoCoaxialityCailibrationbyDistortion
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucrgbmainbuff		主摄像头图像buff
	// Parameter: bool bIsrgbmain						主摄像头是否彩色
	// Parameter: int iWidthmain						主摄像头buff宽
	// Parameter: int iHeightmain						主摄像头buff高
	// Parameter: unsigned char * pucrgbassistantbuff	副摄像头图像buff
	// Parameter: bool bIsrgnassis						副摄像头是否彩色
	// Parameter: int iWidthassistance					副摄像头buff宽
	// Parameter: int iHeightassistance					副摄像头buff高
	//输出
	// Parameter: double & dAnglex						输出水平方向旋转角度
	// Parameter: double & dAngley						输出竖直方向旋转角度
	//************************************
	int cvRolongoCoaxialityCailibrationbyDistortion(unsigned char* pucrgbmainbuff,bool bIsrgbmain, int iWidthmain, int iHeightmain,unsigned char* pucrgbassistantbuff,bool bIsrgnassis,int iWidthassistance,int iHeightassistance,double&dAnglex,double& dAngley);


	//************************************
	// Method:    cvRolongoCoaxialityCailibrationTiltbyCircle 通过圆形测试tilt算法
	// FullName:  CRolongoCoaxialityCalibration::cvRolongoCoaxialityCailibrationTiltbyCircle
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned char * pucrgbbuff 摄像头图像buff
	// Parameter: bool bIsrgb				buff是否是彩色
	// Parameter: int iWidth				buff宽	
	// Parameter: int iHeight				buff高	
	// Parameter: double & dAnglex			输出水平tilt角度
	// Parameter: double & dAngley			输出竖直tilt角度
	//************************************
	int cvRolongoCoaxialityCailibrationTiltbyCircle(unsigned char* pucrgbbuff,bool bIsrgb, int iWidth, int iHeight,double&dAnglex,double& dAngley);
		//************************************
		// Method:    cvRolongoCoaxialityCailibrationTiltbyDistortion 通过正方形畸变测试图像tilt
		// FullName:  CRolongoCoaxialityCalibration::cvRolongoCoaxialityCailibrationTiltbyDistortion
		// Access:    public 
		// Returns:   int
		// Qualifier:
		// Parameter: unsigned char * pucrgbbuff		摄像头图像buff
		// Parameter: bool bIsrgb						buff是否是彩色
		// Parameter: int iWidth						buff宽
		// Parameter: int iHeight						buff高
		// Parameter: double & dAnglex					输出水平tilt角度
		// Parameter: double & dAngley					输出竖直tilt角度
		//************************************
		int cvRolongoCoaxialityCailibrationTiltbyDistortion(unsigned char* pucrgbbuff,bool bIsrgb, int iWidth, int iHeight,double&dAnglex,double& dAngley);

		int licensesample();
		int cvRolongoFindImageCenter(unsigned char* pucrgb,RECT stRect,int iWidth,int iHeight,int& iCenterX,int&iCenterY);
		//************************************
		// Method:    cvRolongoHD6017Otpcenter				阈值光心算法函数
		// FullName:  CRolongoImageTestAlg::cvRolongoHD6017Otpcenter
		// Access:    public 
		// Returns:   int
		// Qualifier:
		// Parameter: unsigned char * pucrgb			输入白板rgb图像buff
		// Parameter: int iWidth						图像宽
		// Parameter: int iHeight						图像高
		// Parameter: float flocratio					像素比例（0.0001）
		// Parameter: int & iOcx						光心横坐标
		// Parameter: int & iOcy						光心纵坐标
		//************************************
		int cvRolongoHD6017Otpcenter( unsigned char* pucrgb,int iWidth,int iHeight,float flocratio,int& iOcx,int&iOcy );
		//************************************
		// Method:    cvRolongoTiltFunction
		// FullName:  CRolongoImageTestAlg::cvRolongoTiltFunction			6017otp chart tilt rotation算法函数
		// Access:    public 
		// Returns:   int
		// Qualifier:
		// Parameter: unsigned char * pucrgb				图像rgbbuff
		// Parameter: int iWidth							图像宽
		// Parameter: int iHeight							图像高
		// Parameter: double dDistancefromChart2Lens		chart到lens距离（mm）
		// Parameter: double dFocusLength					焦距（mm）
		// Parameter: double dChartparamaterDistancex		水平方向最左边的圆中心到最右边圆中心的距离（mm）
		// Parameter: double dChartparamaterDistancey		竖直方向最上边的圆中心到最下边圆中心的距离（mm）
		// Parameter: int & iTiltAnglex						输出水平方向tilt角度
		// Parameter: int & iTiltAngley						输出竖直方向tilt角度
		// Parameter: int & iRotationAngle					输出rotation角度
		// Parameter: int & iSiftx							中心平移x方向
		// Parameter: int & iSifty							中心平移y方向
		//************************************		
		int cvRolongoTiltFunction(unsigned char* pucrgb,int iWidth,int iHeight,double dDistancefromChart2Lens,double dFocusLength,double dChartparamaterDistancex,double dChartparamaterDistancey,int& iTiltAnglex,int& iTiltAngley,int& iRotationAngle,int& iSiftx,int& iSifty ,double dOffsetx,double dOffsety);
		int HisCCMMTF(unsigned char* pucRGB24, int iWidth, int iHeight, RECT stRange, unsigned int uiAlgorithm, float& flMTFValue, bool bGChannel=false);
		int HisCCMMTF(unsigned char* pucRGB24, int iWidth, int iHeight, RECT stRange, unsigned int uiAlgorithm, float& flMTFValueX,float& flMTFValueY,bool bGChannel =false);
		int ShadingHD(unsigned char* pucRGB24, int iWidth, int iHeight, int iROICountW, int iROICountH, _HisShadingHD_Result& stRel);
		int WhiteColorHB(unsigned char* pucRGB24, const int ciWidth, const int ciHeight, const float cflCenterRatio, const int ciROINumW, \
			const int ciROINumH, const int ciROISizeW, const int ciROISizeH, _HisWhiteColorHB_Result& stRel);
		int GetROILab(unsigned char* pucRGB24, int iWidth, int iHeight, RECT stROI, float* L=0, float* A=0, float* B=0, float* RB=0, float* RG=0, float* BG=0, float* Y=0);
		int DefectSFRObjectForHuaWei(unsigned char* bufY, int width, int height, RECT stROI, int iSideMin, int iSideMax, _SFRBlackItem *sfrPos, POINT* pt);
		int DefectSFRMacroObjectForHuaWei(unsigned char* bufY, int width, int height, RECT stROI, float radius, _SFRBlackItem *sfrPos);
		int CrossCoaxialityAlgHA(unsigned char* bufY, int width, int height, RECT stROI, int minAreaSize, float& cx, float& cy, float& rollAngle, float& crossX, float& crossY);
		//roiX， roiY：选取中心ROI大小，范围0~1.0
		//minArea: 圆最小面积，单位：像素
		//chartHeight：CHART到模组的高度，单位：mm
		//circleSize：圆的直径，单位：mm
		//rollAngle: 绕Z轴的旋转角度
		//angleX 正： chart顺时针旋转  负: chart逆时针旋转
		//angleY 正: chart向前转 负: chart向后转
		//提取出来的4个角点加一个中心，再加十字的4个点，所以至少要申明9个POINT的数组
		int SpotCoaxialityAlgHA(unsigned char* rgb24, int width, int height, float roiX, float roiY, int minArea, float chartHeight, float circleSize, \
			float& rollAngle, float& angleX, float& angleY, POINT* posPt, float& pixPermmW, float& pixPermmH);
		const char* GetLastError();
private:
	void* classMiddle;
	void* classHao;
	
};

// This class is exported from the HisVision.dll
class ROLONGOIMAGETESTALG_EXPORT CHisVision {
public:
	CHisVision(void);
	~CHisVision(void);
	int HisVisionAFCross(_HisCamera_Frame_Descripte& stFrameGrab,int* centerx,int* centery);
	int HisVisionAFLens(_HisCamera_Frame_Descripte& stFrameGrab,char* tmpSmallFileName,char* tmpMiddleFileName,char* tmpBigFileName,\
		int petalNum, double match,int* matchFlag,bool* centerFlag,int *centerx,int* centery,double* angle);
	int Cailibrating(_HisCamera_Frame_Descripte& FrameGrab,int WidthNum,int HeightNum,double CheckerBoardSize,double* PixelSize);
	int CailByCenter(_HisCamera_Frame_Descripte& FrameGrab,char* tmpSmallFileName,int* centerx,int * centery);
	int Plasticine(_HisCamera_Frame_Descripte& FrameGrab,int iPetelNum,double dAngleIn,int& iRadius,int& iptx,int& ipty,double&dangle);
	int HisVisionAFLensB8(_HisCamera_Frame_Descripte& stFrameGrab, char* tmpSmallFileName,char* tmpMiddleFileName,\
		char* tmpBigFileName, int petalNum, double match,double angleIn, int* centerx,int* centery,double* angle, int* piRadiusRel, int iThresholdOffset = 0, float cdflAngleSpec = 3.0f);
	int DataMatrixDecode(unsigned char* buff, int width, int height, unsigned char* Message, bool bMirror=true, bool bFlip=false);
	int DmtxbicodeDecode(unsigned char* buff,int width, int height,unsigned char* Message, bool bMirror = false, bool bFlip = false);

private:
	void* classHao;
};

#endif // ROLONGOIMAGETESTALG_H
