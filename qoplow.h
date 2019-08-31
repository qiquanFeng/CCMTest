#ifndef HISQOPLOW_H
#define HISQOPLOW_H

#include "globaldefine.h"



#define maxv4(a,b,c,d)	max(max(a,b), max(c,d))
#define minv4(a,b,c,d)	min(min(a,b), min(c,d))
#define __rangescale(a,b,c)  min(c, max(a,b))

// class qoplow
// {
// public:
// 	qoplow(void);
// 	~qoplow(void);
// };

enum _ROLONGO_ENCRYPT_TYPE
{
	_ROLONGO_ENCRYPT_TYPE_BOX		=	0x0,
	_ROLONGO_ENCRYPT_TYPE_UVC		=	0x1,
	_ROLONGO_ENCRYPT_TYPE_GIGE		=	0x2,
	_ROLONGO_ENCRYPT_TYPE_RTSP	=	0x3,
	_ROLONGO_ENCRYPT_TYPE_EXE		=	0x4,
	_ROLONGO_ENCRYPT_TYPE_HDMI		=	0x5,
	_ROLONGO_ENCRYPT_TYPE_NONE	=	0xFF
};

enum _ROLONGO_CLIENT
{
	_ROLONGO_CLIENT_ALL									=	0x0,
	_ROLONGO_CLIENT_SUNNYOPTICAL				=	0x1,
	_ROLONGO_CLIENT_SUNNYINSTRUMENT		=	0x2,
	_ROLONGO_CLIENT_YUANDA							=	0x3,
	_ROLONGO_CLIENT_AONI									=	0x4,
	_ROLONGO_CLIENT_SUNNEX							=	0x5,
	_ROLONGO_CLIENT_SUNRISE							=	0x6,
	_ROLONGO_CLIENT_XUANYANG						=	0x7,
	_ROLONGO_CLIENT_OFEI									=	0x8,
	_ROLONGO_CLIENT_LECTRON							=	0x9,
	_ROLONGO_CLIENT_JUNGE								=	0xA,
	_ROLONGO_CLIENT_JSL									=	0xB,
	_ROLONGO_CLIENT_AZWARE							=	0xC,
	_ROLONGO_CLIENT_PRIMAX								=	0xD,
	_ROLONGO_CLIENT_GUANGBAO						=	0xE,
	_ROLONGO_CLIENT_TRUELY								=	0xF,
	_ROLONGO_CLIENT_BOLIXIN								=	0x10,
	_ROLONGO_CLIENT_QTECH								=	0x11
};



typedef struct BayerColorDouble{
	double R;
	double Gr;
	double Gb;
	double B;
}sBayerColorDouble;	
 
namespace ROPLOW
{
	void GetMeanFrom10BitBayer(unsigned short *pRaw,int width,int height,int l,int t,int w,int h,sBayerColorDouble *mean,_HisFX3_BaylorMode ucDataFormat);
	int ReadRawBuffer(const wchar_t* pwstrPath, unsigned char* pucData, unsigned int uiDesSize);
	int saveRaw8(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData);
	int saveRaw10(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData);
	int saveRaw12(QString strdir, QString strname, unsigned int uiFormat, unsigned int uiWidth, unsigned int uiHeight, void* pvData);
	float getSFRValueofFreq(double* pdflSFRValue, int iSFRCurveLen, unsigned char ucFreq);
	void DawSFRFACABar(int iGroupCount, QImage& imageBackgound, bool b2Freq, float* pflF1Value, float* pflF2Value, float* pflF1Spec, \
		float* pflF2Spec, float flWeight, float flMaxWeight, bool bTotalResult);
	void BaylorXForamt2Baloy8(_HisFX3_BaylorMode& before, _HisFX3_BaylorMode& after);
	void FastResize2(unsigned char* pucBefore, unsigned char* pucAfter, unsigned int uiWidth, unsigned int uiHeight);
	void AFALpItemDataInitial(std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItemData, std::vector<_HisCCMAlg_LPItem_Info>& vectorItemInfo, double& dflAbsAngle);
	void AFAItemDataAdd(std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItemData, RECT& stROI, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex);

	void AFCLpItemDataInitial(std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItemData, std::vector<_HisCCMAlg_LPItem_Info>& vectorItemInfo, int& iMotor);
	void AFCItemDataAdd(std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItemData, RECT& stROI,  RECT& stValueLine,  \
		RECT& stMaxLine,  RECT& stMinLine, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex);
	void AFCItemDataAdd(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, RECT& stROI,  RECT& stValueLine,  \
		RECT& stMaxLine,  RECT& stMinLine, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex);
	void LpMFAItemDataAdd(_HisCCMAlg_AFC_LP_DataItem& stItemData, RECT& stROI, double& dflValue, unsigned int uiFOVIndex, unsigned int uiROIIndex);

	void AFCSFRHAItemDataInitial(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorItemData, _SFRAFCCAParameter* pstParameter, int& iMotor);
	void MFASFRHAItemDataInitial(_HisCCMAlg_AFC_SFRHA_DataItem& stItemData, _SFRFACAParameter* pstParameter);
	void AFCMTFItemDataInitial(std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorItemData, _mtfAFCParameter* pstParameter, int& iMotor);
	void AFCMTFItemDataInitial_G(std::vector<_HisCCMAlg_AFC_MTF_DataItem_EX>& vectorItemData, _mtfAFCParameter* pstParameter, int& iMotor);
	void MFAMTFItemDataInitial(_HisCCMAlg_AFC_MTF_DataItem& stItemData, _mtffaParameter* pstParameter);
	void MFAMTFItemDataInitial_Ex(_HisCCMAlg_AFC_MTF_DataItem_EX& stItemData, _mtffaParameter* pstParameter);

	void showImageLable(QString strPath, int iWidth, int iHeight, unsigned int uiDataFormat);

	void savebin(QString strDir, QString strFileName, unsigned char* pucData, unsigned int uiLength, unsigned int uiOffset, bool bAddTime);

	unsigned int getAFACameraNextExposureTime(unsigned int uiNowEt, QString& strPath, unsigned char* pucBuffer, int iCenterX, int iCenterY);
	int BlackStripesDetected(unsigned char *pucRGB24,unsigned int iScanBoxSize,int Width, int Height,RECT &sBlock);
	int QualcommAWBLSCCaculation(unsigned char *pRaw, unsigned int uiBayerFormat,int iWidth, int iHeight, int iBlackLevel,CalibrationDataStruct &stCalData,ImageBlcokData &stBlockData);
	void bylorraw8average(unsigned __int8* pui8raw8, int iwidth, int iheight, unsigned int uidataformat, RECT strange, double& dflR, double& dflB, double& dflGr, double& dflGb);
	void savequalcomAWBLSCData(QString strserialnumber,CalibrationDataStruct stCalData,ImageBlcokData stBlockData, QString strPath);
	void savequalcomAWBLSCprocessData(QString strserialnumber,CalibrationprocessDataStruct stCalData,QString strPath);
	int ParseINIFile(QString strDir,wchar_t *KeyName, unsigned int *RegAddr, unsigned int *RegData, int &i2CCnt);
	void saveCDAFVerifyCure(int iVerifyStep,int *iDAC,float *fmtf50, float *fmtf50smooth,QString& strPath,QString sSerialnumber);
	__inline void hex2QString(QString& strtext, unsigned int uiHex, unsigned int uiType, bool bHeader = true)
	{
		strtext = QString::number(uiHex, 16);
		int iLen = 2;
		if(uiType == 0x16) iLen = 4;
		else if(uiType == 0x32) iLen = 8;
		while(strtext.size() < iLen) strtext.prepend("0");
		if(bHeader) strtext.prepend("0x");
	}

	__inline QString rect2qstring(RECT& stROI)
	{
		return "(" % QString::number(stROI.left) % "," % QString::number(stROI.top) % ")(" % QString::number(stROI.right) % "," % QString::number(stROI.bottom) % ")";
	}

	__inline QString getBlockName(RECT& stBlock, int iWidth, int iHeight)
	{
		int ibx	=	((stBlock.left + stBlock.right) >>1);
		int iby	=	((stBlock.top + stBlock.bottom) >>1);
		int icx	=	(iWidth >>1), icy = (iHeight >>1);
		if(abs(ibx-icx) > abs(iby-icy)){
			if(ibx < icx){ //left 0.08748866352592400522201866943496
				if(abs(iby-icy) < (icx - ibx) *0.087488f)
					return "L";
				else{
					return (iby > icy)?("LB"):("LT");
				}
			}
			else{
				if(abs(iby-icy) < (ibx - icx) *0.087488)
					return "R";
				else{
					return (iby > icy)?("RB"):("RT");
				}
			}
		}
		else{
			if(iby < icy){ //top
				if(abs(ibx-icx) < (icy - iby) *0.087488)
					return "T";
				else{
					return (ibx > icx)?("RT"):("LT");
				}
			}
			else{
				if(abs(ibx-icx) < (iby - icy) *0.087488)
					return "B";
				else{
					return (ibx > icx)?("RB"):("LB");
				}
			}
		}

		return "";
	}

	__inline void expand2minrect(RECT& stROI, unsigned int& iImgWidth, unsigned int& iImgHeight, int iROIWidth, int iROIHeight)
	{
		if(stROI.right < stROI.left + iROIWidth){
			int iCenterX	=	((stROI.right + stROI.left) >>1); 
			stROI.left		=	iCenterX - (iROIWidth >>1);
			stROI.right	=	stROI.left + iROIWidth;
			stROI.left		=	max(0, stROI.left);
			stROI.right	=	min(stROI.right, iImgWidth);
		}

		if(stROI.bottom < stROI.top + iROIHeight){
			int iCenterY		=	((stROI.top + stROI.bottom) >>1); 
			stROI.top			=	iCenterY - (iROIHeight >>1);
			stROI.bottom	=	stROI.top + iROIHeight;
			stROI.top			=	max(0, stROI.top);
			stROI.bottom	=	min(stROI.bottom, iImgHeight);
		}
	}

	__inline bool isEqual(const QByteArray& bins1,const QByteArray& bins2)
	{
		if(bins1.size() != bins2.size()) return false;
		for(unsigned int x=0;	x<bins1.size(); ++x){
			if(bins1[x] != bins2[x]) return false;
		}
		return true;
	}

	__inline QByteArray AFAALLTacticsBasicSerialize(_HisAutoFA_BASIC_STACTICS& stTacticsBasic2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		stream << stTacticsBasic2.bConfigValid  <<stTacticsBasic2.uclensleafs <<stTacticsBasic2.ucclaw << \
			stTacticsBasic2.dfllensIncludedAngle << stTacticsBasic2.dflringIncludedAngle << stTacticsBasic2.dfllenspitch <<stTacticsBasic2.ucTactics << \
			stTacticsBasic2.ucDirection << stTacticsBasic2.ucChartType << stTacticsBasic2.ucValueChoose << stTacticsBasic2.ucValueTypeChoose << \
			stTacticsBasic2.bDataBase << stTacticsBasic2.bUseMark << stTacticsBasic2.bUseLaser << stTacticsBasic2.bVision << \
			stTacticsBasic2.flOK2Percent <<stTacticsBasic2.flDBAngleOffset <<stTacticsBasic2.fltoBestAngOffset <<stTacticsBasic2.bUpCheckEveryStep << \
			stTacticsBasic2.flEveryUpDis <<stTacticsBasic2.ussteplimit <<stTacticsBasic2.usoperatedelay <<stTacticsBasic2.flConstMaxAngleCW << \
			stTacticsBasic2.flConstMaxAngleCCW <<stTacticsBasic2.flConstLaserMin <<stTacticsBasic2.flConstLaserMax <<stTacticsBasic2.flConstMarkDisMin << \
			stTacticsBasic2.flConstMarkDisMax <<stTacticsBasic2.flConstPeakDefValue <<stTacticsBasic2.flConstPeakDefFall <<stTacticsBasic2.uc1stCWMode << \
			stTacticsBasic2.fl1stCWAngle <<stTacticsBasic2.fl1stCWLaser <<stTacticsBasic2.bUpCheck << \
			stTacticsBasic2.flUpValueDiff <<stTacticsBasic2.uiUnderSpinAngle << stTacticsBasic2.flUnderSpinDValueMin <<stTacticsBasic2.flUnderSpinDValueMax << \
			stTacticsBasic2.ucLastRetryTime <<stTacticsBasic2.flLastRetryAngle <<stTacticsBasic2.ucVNodeNum <<stTacticsBasic2.ucSFRAMarkBlockCount << \
			stTacticsBasic2.flMTFBMarkRangeX << stTacticsBasic2.flMTFBMarkRangeY << stTacticsBasic2.flMTFBMarkRangeYMax << stTacticsBasic2.bXYReversal;
		for(unsigned int x=0;	x<9;	++x){
			stream <<stTacticsBasic2.flVNode[x] <<stTacticsBasic2.flVAngle[x];
		}
		return byteArray;
	}

	__inline void AFAALLTacticsBasicDeserialize(const QByteArray& byteArray, _HisAutoFA_BASIC_STACTICS& stTacticsBasic2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		stream >> stTacticsBasic2.bConfigValid  >>stTacticsBasic2.uclensleafs >>stTacticsBasic2.ucclaw >> \
			stTacticsBasic2.dfllensIncludedAngle >> stTacticsBasic2.dflringIncludedAngle >> stTacticsBasic2.dfllenspitch >>stTacticsBasic2.ucTactics >> \
			stTacticsBasic2.ucDirection >> stTacticsBasic2.ucChartType >> stTacticsBasic2.ucValueChoose >> stTacticsBasic2.ucValueTypeChoose >> \
			stTacticsBasic2.bDataBase >> stTacticsBasic2.bUseMark >> stTacticsBasic2.bUseLaser >> stTacticsBasic2.bVision >> \
			stTacticsBasic2.flOK2Percent >>stTacticsBasic2.flDBAngleOffset >>stTacticsBasic2.fltoBestAngOffset >>stTacticsBasic2.bUpCheckEveryStep >> \
			stTacticsBasic2.flEveryUpDis >>stTacticsBasic2.ussteplimit >>stTacticsBasic2.usoperatedelay >>stTacticsBasic2.flConstMaxAngleCW >> \
			stTacticsBasic2.flConstMaxAngleCCW >>stTacticsBasic2.flConstLaserMin >>stTacticsBasic2.flConstLaserMax >>stTacticsBasic2.flConstMarkDisMin >> \
			stTacticsBasic2.flConstMarkDisMax >>stTacticsBasic2.flConstPeakDefValue >>stTacticsBasic2.flConstPeakDefFall >>stTacticsBasic2.uc1stCWMode >> \
			stTacticsBasic2.fl1stCWAngle >>stTacticsBasic2.fl1stCWLaser >>stTacticsBasic2.bUpCheck >> \
			stTacticsBasic2.flUpValueDiff >>stTacticsBasic2.uiUnderSpinAngle >> stTacticsBasic2.flUnderSpinDValueMin >>stTacticsBasic2.flUnderSpinDValueMax >> \
			stTacticsBasic2.ucLastRetryTime >>stTacticsBasic2.flLastRetryAngle >>stTacticsBasic2.ucVNodeNum >>stTacticsBasic2.ucSFRAMarkBlockCount >> \
			stTacticsBasic2.flMTFBMarkRangeX >> stTacticsBasic2.flMTFBMarkRangeY >>stTacticsBasic2.flMTFBMarkRangeYMax >> stTacticsBasic2.bXYReversal;
		for(unsigned int x=0;	x<9;	++x){
			stream >>stTacticsBasic2.flVNode[x] >>stTacticsBasic2.flVAngle[x];
		}
	}

	__inline QByteArray TacticsBasicSerialize(_HisCCMAlg_AFC_Tactics_Basic& stTacticsBasic2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		stream << stTacticsBasic2.bDataBase  <<stTacticsBasic2.bLinearBack <<stTacticsBasic2.usMaxSteps << \
			stTacticsBasic2.usStepDelay << stTacticsBasic2.ucChartType << stTacticsBasic2.ucTactics <<stTacticsBasic2.ucValueChoose << \
			stTacticsBasic2.ucValueTypeChoose << stTacticsBasic2.sMotorStart << stTacticsBasic2.sMotorEnd << stTacticsBasic2.ucBigStep << \
			stTacticsBasic2.ucMiddleStep << stTacticsBasic2.ucSmallStep << stTacticsBasic2.flCurveFalloffDef << stTacticsBasic2.flCurveValidDef << \
			stTacticsBasic2.flStraightDevMax;
		return byteArray;
	}

	__inline void TacticsBasicDeserialize(const QByteArray& byteArray, _HisCCMAlg_AFC_Tactics_Basic& stTacticsBasic2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		stream >> stTacticsBasic2.bDataBase  >>stTacticsBasic2.bLinearBack >>stTacticsBasic2.usMaxSteps >> \
			stTacticsBasic2.usStepDelay >> stTacticsBasic2.ucChartType >> stTacticsBasic2.ucTactics >>stTacticsBasic2.ucValueChoose >> \
			stTacticsBasic2.ucValueTypeChoose >> stTacticsBasic2.sMotorStart >> stTacticsBasic2.sMotorEnd >> stTacticsBasic2.ucBigStep >> \
			stTacticsBasic2.ucMiddleStep >> stTacticsBasic2.ucSmallStep >> stTacticsBasic2.flCurveFalloffDef >> stTacticsBasic2.flCurveValidDef >> \
			stTacticsBasic2.flStraightDevMax;
	}

	__inline QByteArray LpHABasicSerialize(_HisCCMAlg_LPBasic_Info& stLpBasic2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		stream << stLpBasic2.flWHRatio  <<stLpBasic2.usFOVDisDev <<stLpBasic2.usConstLPWMin <<stLpBasic2.usConstLPWMax << \
			stLpBasic2.usConstLPHMin <<stLpBasic2.usConstLPHMax<<stLpBasic2.usConstMarkPMin <<stLpBasic2.usConstMarkPMax << \
			stLpBasic2.dflConstMarkFMin <<stLpBasic2.dflConstMarkFMax <<stLpBasic2.dflConstMarkAngle << \
			stLpBasic2.usConstExpandW <<stLpBasic2.usConstExpandH;
		return byteArray;
	}

	__inline void LpHABasicDeserialize(const QByteArray& byteArray, _HisCCMAlg_LPBasic_Info& stLpBasic2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		stream >> stLpBasic2.flWHRatio  >>stLpBasic2.usFOVDisDev >>stLpBasic2.usConstLPWMin >>stLpBasic2.usConstLPWMax >> \
			stLpBasic2.usConstLPHMin >>stLpBasic2.usConstLPHMax>>stLpBasic2.usConstMarkPMin >>stLpBasic2.usConstMarkPMax >> \
			stLpBasic2.dflConstMarkFMin >>stLpBasic2.dflConstMarkFMax >>stLpBasic2.dflConstMarkAngle >> \
			stLpBasic2.usConstExpandW >>stLpBasic2.usConstExpandH;
	}

	__inline QByteArray LpHAItemSerialize(std::vector<_HisCCMAlg_LPItem_Info>& vectorLpItem2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorLpItem2.size(); ++x){
			stream <<vectorLpItem2.at(x).bBlock4   <<vectorLpItem2.at(x).ucConstLPNum <<vectorLpItem2.at(x).ucConstThresholdB8 <<vectorLpItem2.at(x).flFOV << \
				vectorLpItem2.at(x).flAngle   <<vectorLpItem2.at(x).flWeight   <<vectorLpItem2.at(x).flSpecHor   << \
				vectorLpItem2.at(x).flSpecVec   <<vectorLpItem2.at(x).flSpecUniform   <<vectorLpItem2.at(x).flValueOffset   << \
				vectorLpItem2.at(x).usLPMax   <<vectorLpItem2.at(x).usLPMin;
		}

		return byteArray;
	}

	__inline void LpHAItemDeserialize(const QByteArray& byteArray, std::vector<_HisCCMAlg_LPItem_Info>& vectorLpItem2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorLpItem2.size(); ++x){
			stream >>vectorLpItem2.at(x).bBlock4   >>vectorLpItem2.at(x).ucConstLPNum >>vectorLpItem2.at(x).ucConstThresholdB8 >>vectorLpItem2.at(x).flFOV >> \
				vectorLpItem2.at(x).flAngle   >>vectorLpItem2.at(x).flWeight   >>vectorLpItem2.at(x).flSpecHor   >> \
				vectorLpItem2.at(x).flSpecVec   >>vectorLpItem2.at(x).flSpecUniform   >>vectorLpItem2.at(x).flValueOffset   >> \
				vectorLpItem2.at(x).usLPMax   >>vectorLpItem2.at(x).usLPMin;
		}
	}

	__inline QByteArray SFRHABasicSerialize(_HisCCMAlg_SFRPlusHABasic_Info& stSFRBasic2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		stream << stSFRBasic2.b2ndFreq  <<stSFRBasic2.uc1stFreq <<stSFRBasic2.uc2ndFreq <<stSFRBasic2.ucAlg << \
			stSFRBasic2.ucMethod <<stSFRBasic2.ucChannel<<stSFRBasic2.ucMinCantrast <<stSFRBasic2.usFOVOffset <<stSFRBasic2.iROIWidth <<stSFRBasic2.iROIHeght <<stSFRBasic2.flCenterWeight << \
			stSFRBasic2.flCenterMTF50SpecH <<stSFRBasic2.flCenterMTF50SpecV <<stSFRBasic2.flCenter1stFreqSpecH << \
			stSFRBasic2.flCenter1stFreqSpecV <<stSFRBasic2.flCenter2ndFreqSpecH <<stSFRBasic2.flCenter2ndFreqSpecV << \
			stSFRBasic2.usMarkSideMin <<stSFRBasic2.usMarkSideMax;
		return byteArray;
	}

	__inline void SFRHABasicDeserialize(const QByteArray& byteArray, _HisCCMAlg_SFRPlusHABasic_Info& stSFRBasic2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		stream >> stSFRBasic2.b2ndFreq  >>stSFRBasic2.uc1stFreq >>stSFRBasic2.uc2ndFreq >>stSFRBasic2.ucAlg >> \
			stSFRBasic2.ucMethod >>stSFRBasic2.ucChannel >>stSFRBasic2.ucMinCantrast >> stSFRBasic2.usFOVOffset>> stSFRBasic2.iROIWidth >>stSFRBasic2.iROIHeght >>stSFRBasic2.flCenterWeight >> \
			stSFRBasic2.flCenterMTF50SpecH >>stSFRBasic2.flCenterMTF50SpecV >>stSFRBasic2.flCenter1stFreqSpecH >> \
			stSFRBasic2.flCenter1stFreqSpecV >>stSFRBasic2.flCenter2ndFreqSpecH >>stSFRBasic2.flCenter2ndFreqSpecV >> \
			stSFRBasic2.usMarkSideMin >>stSFRBasic2.usMarkSideMax;
	}

	__inline QByteArray SFRHAItemSerialize(std::vector<_HisCCMAlg_SFRPlusHAItem_Info>& vectorSFRItem2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorSFRItem2.size(); ++x){
			stream <<vectorSFRItem2.at(x).ucBlockCount <<vectorSFRItem2.at(x).flFOV   <<vectorSFRItem2.at(x).flAngle <<vectorSFRItem2.at(x).flWeight <<vectorSFRItem2.at(x).flMTF50SpecH << \
				vectorSFRItem2.at(x).flMTF50SpecV   <<vectorSFRItem2.at(x).fl1stFreqSpecH   <<vectorSFRItem2.at(x).fl1stFreqSpecV   << \
				vectorSFRItem2.at(x).fl2ndFreqSpecH   <<vectorSFRItem2.at(x).fl2ndFreqSpecV   <<vectorSFRItem2.at(x).flMTF50SpecUnifH   << \
				vectorSFRItem2.at(x).flMTF50SpecUnifV   <<vectorSFRItem2.at(x).fl1stFreqSpecUnifH   <<vectorSFRItem2.at(x).fl1stFreqSpecUnifV   << \
				vectorSFRItem2.at(x).fl2ndFreqSpecUnifH   <<vectorSFRItem2.at(x).fl2ndFreqSpecUnifV;
		}

		return byteArray;
	}

	__inline void SFRHAItemDeserialize(const QByteArray& byteArray, std::vector<_HisCCMAlg_SFRPlusHAItem_Info>& vectorSFRItem2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorSFRItem2.size(); ++x){
			stream >>vectorSFRItem2.at(x).ucBlockCount >>vectorSFRItem2.at(x).flFOV   >>vectorSFRItem2.at(x).flAngle >>vectorSFRItem2.at(x).flWeight >>vectorSFRItem2.at(x).flMTF50SpecH >> \
				vectorSFRItem2.at(x).flMTF50SpecV   >>vectorSFRItem2.at(x).fl1stFreqSpecH   >>vectorSFRItem2.at(x).fl1stFreqSpecV   >> \
				vectorSFRItem2.at(x).fl2ndFreqSpecH   >>vectorSFRItem2.at(x).fl2ndFreqSpecV   >>vectorSFRItem2.at(x).flMTF50SpecUnifH   >> \
				vectorSFRItem2.at(x).flMTF50SpecUnifV   >>vectorSFRItem2.at(x).fl1stFreqSpecUnifH   >>vectorSFRItem2.at(x).fl1stFreqSpecUnifV   >> \
				vectorSFRItem2.at(x).fl2ndFreqSpecUnifH   >>vectorSFRItem2.at(x).fl2ndFreqSpecUnifV;
		}
	}

	__inline QByteArray MTFBasicSerialize(_HisCCMAlg_MTFBasic_Info& stMTFBasic2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		stream << stMTFBasic2.algswitch  <<stMTFBasic2.iblockwith <<stMTFBasic2.iblockheight <<stMTFBasic2.flcenterweight << \
			stMTFBasic2.flcenterspec;
		return byteArray;
	}

	__inline void MTFBasicDeserialize(const QByteArray& byteArray, _HisCCMAlg_MTFBasic_Info& stMTFBasic2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		stream >> stMTFBasic2.algswitch  >>stMTFBasic2.iblockwith >>stMTFBasic2.iblockheight >>stMTFBasic2.flcenterweight >> \
			stMTFBasic2.flcenterspec;
	}

	__inline QByteArray MTFItemSerialize(std::vector<_HisCCMAlg_MTFItem_Info>& vectorMTFItem2)
	{
		QByteArray byteArray;
		QDataStream stream(&byteArray, QIODevice::WriteOnly);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorMTFItem2.size(); ++x){
			stream <<vectorMTFItem2.at(x).ucBlockCount   <<vectorMTFItem2.at(x).flFOV <<vectorMTFItem2.at(x).flAngle <<vectorMTFItem2.at(x).flWeight << \
				vectorMTFItem2.at(x).flSpec   <<vectorMTFItem2.at(x).flSpecUniform;
		}

		return byteArray;
	}

	__inline void MTFItemDeserialize(const QByteArray& byteArray, std::vector<_HisCCMAlg_MTFItem_Info>& vectorMTFItem2)
	{
		QDataStream stream(byteArray);
		stream.setVersion(QDataStream::Qt_4_8);

		for(unsigned int x=0;	x<vectorMTFItem2.size(); ++x){
			stream >>vectorMTFItem2.at(x).ucBlockCount   >>vectorMTFItem2.at(x).flFOV >>vectorMTFItem2.at(x).flAngle >>vectorMTFItem2.at(x).flWeight >> \
				vectorMTFItem2.at(x).flSpec   >>vectorMTFItem2.at(x).flSpecUniform;
		}
	}

	__inline void extractrgb24(unsigned char* pucRGB24, unsigned char* pucR, unsigned char* pucG, unsigned char* pucB, int iWidth, int iHeight)
	{
		unsigned int uiPixel	=	iWidth *iHeight;
		for(unsigned int x=0;	x<uiPixel;	++x){
			*pucR	=	*pucRGB24;
			++pucR;
			++pucRGB24;
			*pucG	=	*pucRGB24;
			++pucG;
			++pucRGB24;
			*pucB	=	*pucRGB24;
			++pucB;
			++pucRGB24;
		}
	}

	__inline void GetPartImageFromRGB24(unsigned char* pucRGB24, int iWidth, int iHeight, unsigned char ucChannel, RECT& stBlock, float* pflY)
	{
		unsigned int uiWidthbyte	=	(iWidth <<1) +iWidth;
		if(ucChannel == _HisCCMAlg_ImageBuffer_Channel_Y){
			if(stBlock.right - stBlock.left < stBlock.bottom - stBlock.top){
				unsigned char* pucLine	=	pucRGB24 + (stBlock.top *uiWidthbyte + (stBlock.left <<1) +stBlock.left);
				unsigned char* pucData;
				for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
					pucData	=	pucLine;
					for(LONG x=stBlock.left;	x<stBlock.right;	++x){
						*pflY	=	(float)(*pucData) *0.299f + (float)(*(pucData+1)) *0.587f + (float)(*(pucData+2)) *0.114f;
						++pflY;
						pucData	+=	3;
					}
					pucLine	+=	uiWidthbyte;
				}
			}
			else{
				unsigned char* pucLine	=	pucRGB24 + ((stBlock.bottom-1) *uiWidthbyte + (stBlock.left <<1) +stBlock.left);
				unsigned char* pucData;
				for(LONG x=stBlock.left;	x<stBlock.right;	++x){
					pucData	=	pucLine;
					for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
						*pflY	=	(float)(*pucData) *0.299f + (float)(*(pucData+1)) *0.587f + (float)(*(pucData+2)) *0.114f;
						++pflY;
						pucData	-=	uiWidthbyte;
					}
					pucLine	+=	3;
				}
			}
		}
		else{
			if(stBlock.right - stBlock.left < stBlock.bottom - stBlock.top){
				unsigned char* pucLine	=	pucRGB24 + (stBlock.top *uiWidthbyte + (stBlock.left <<1) +stBlock.left);
				if(ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gr)	pucLine	+=	1;
				else if(ucChannel == _HisCCMAlg_ImageBuffer_Channel_B)	pucLine	+=	2;
				unsigned char* pucData;
				for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
					pucData	=	pucLine;
					for(LONG x=stBlock.left;	x<stBlock.right;	++x){
						*pflY	=	(float)(*pucData);
						++pflY;
						pucData	+=	3;
					}
					pucLine	+=	uiWidthbyte;
				}
			}
			else{
				unsigned char* pucLine	=	pucRGB24 + ((stBlock.bottom-1) *uiWidthbyte + (stBlock.left <<1) +stBlock.left);
				if(ucChannel == _HisCCMAlg_ImageBuffer_Channel_Gr)	pucLine	+=	1;
				else if(ucChannel == _HisCCMAlg_ImageBuffer_Channel_B)	pucLine	+=	2;
				unsigned char* pucData;
				for(LONG x=stBlock.left;	x<stBlock.right;	++x){
					pucData	=	pucLine;
					for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
						*pflY	=	(float)(*pucData);
						++pflY;
						pucData	-=	uiWidthbyte;
					}
					pucLine	+=	3;
				}
			}
		}
	}

	__inline void GetPartYFromY(unsigned char* pucSrcY, int iWidth, int iHeight, RECT& stBlock, float* pflY)
	{
		if(stBlock.right - stBlock.left < stBlock.bottom - stBlock.top){
			unsigned char* pucLine	=	pucSrcY + (stBlock.top *iWidth + stBlock.left);
			unsigned char* pucData;
			for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
				pucData	=	pucLine;
				for(LONG x=stBlock.left;	x<stBlock.right;	++x){
					*pflY	=	(float)(*pucData);
					++pflY;
					++pucData;
				}
				pucLine	+=	iWidth;
			}
		}
		else{
			unsigned char* pucLine	=	pucSrcY + ((stBlock.bottom - 1) *iWidth + stBlock.left);
			unsigned char* pucData;
			for(LONG x=stBlock.left;	x<stBlock.right;	++x){
				pucData	=	pucLine;
				for(LONG y=stBlock.top;	y<stBlock.bottom;	++y){
					*pflY	=	(float)(*pucData);
					++pflY;
					pucData	-=	iWidth;
				}
				++pucLine;
			}
		}
	}

	__inline void patchconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue)
	{
		//(belmish:on)(color:on)(snr:on)
		strname.clear();
		strvalue.clear();
// 		strsrc	=	strsrc.toLower();
		strsrc	=	strsrc.trimmed();
		strsrc	=	strsrc.remove(" ");
		if(strsrc.isEmpty() || !strsrc.contains("(") || !strsrc.contains(")") || !strsrc.contains(":"))	return;
		QString strkey, strdata;
		int iindex	=	strsrc.indexOf(")");
		while(iindex > 0){
			strdata		=	strsrc.left(iindex);
			strsrc		=	strsrc.right(strsrc.size() -iindex -1);
			strdata		=	strdata.remove("(");
			if(strdata.count(":") >= 1){
				iindex	=	strdata.indexOf(":");
				strkey	=	strdata.left(iindex);
				strdata	=	strdata.right(strdata.size() -iindex -1);
				if(!strkey.isEmpty() && !strdata.isEmpty()){
					strname.append(strkey);
					strvalue.append(strdata);
				}
			}
			iindex	=	strsrc.indexOf(")");
		}
	}

	__inline void jointconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue)
	{
		strsrc.clear();
		for(int x=0;	x<strname.size(); ++x){
			strsrc	=	strsrc % "(" % strname.at(x) % ":" % strvalue.at(x) % ")";
		}
	}

	__inline void removeDrawItem(std::vector<_itemDraw>& itemdrawList)
	{
		if(itemdrawList.empty()) return;
		std::vector<_itemDraw>::iterator theiterator;
		for(int iIndex = (int)(itemdrawList.size()-1); iIndex >= 0; --iIndex){
			theiterator	=	itemdrawList.begin() + iIndex;
			if(!(theiterator->usitem & _HisCCMDraw_NotRemove_Mask))	itemdrawList.erase(theiterator);
		}
	}

	__inline void removeDrawItem(std::vector<_itemDraw>& itemdrawList, unsigned short usItem)
	{
		if(itemdrawList.empty()) return;
		std::vector<_itemDraw>::iterator theiterator;
		for(int iIndex = (int)(itemdrawList.size()-1); iIndex >= 0; --iIndex){
			theiterator	=	itemdrawList.begin() + iIndex;
			if(!(theiterator->usitem & _HisCCMDraw_NotRemove_Mask) && ((theiterator->usitem & _HisCCMDraw_TestRemove_Mask) == usItem))	
				itemdrawList.erase(theiterator);
		}
	}

	__inline LONG GetRectCenterX(RECT* pstSrc)
	{
		return ((pstSrc->left + pstSrc->right) >>1);
	}

	__inline LONG GetRectCenterY(RECT* pstSrc)
	{
		return ((pstSrc->top + pstSrc->bottom) >>1);
	}

	__inline LONG GetRectWidth(RECT* pstSrc)
	{
		return (pstSrc->right - pstSrc->left);
	}

	__inline LONG GetRectHeight(RECT* pstSrc)
	{
		return (pstSrc->bottom - pstSrc->top);
	}

	__inline void AddDrawEllipse(int icx, int icy, int iwidth, int iheight, double dflFOV, int iScale, std::vector<_itemDraw>& itemdrawList)
	{
		int iRadio	=	static_cast<int>(sqrt((double)(iwidth*iwidth + iheight*iheight)) *0.5 *dflFOV);
		int iIndex	=	(int)itemdrawList.size();
		itemdrawList.resize(iIndex + 1);
		itemdrawList.at(iIndex).stcolor	=	QColor::fromRgb(0, 0, 0);
		itemdrawList.at(iIndex).uctype	=	HisDrawType_Ellipse;
		if(iScale == 1){
			itemdrawList.at(iIndex).strinfo.stblock.left			=	icx - iRadio;
			itemdrawList.at(iIndex).strinfo.stblock.right		=	icx + iRadio;
			itemdrawList.at(iIndex).strinfo.stblock.top			=	icy - iRadio;
			itemdrawList.at(iIndex).strinfo.stblock.bottom	=	icy + iRadio;
		}
		else{
			itemdrawList.at(iIndex).strinfo.stblock.left			=	(icx - iRadio) *iScale;
			itemdrawList.at(iIndex).strinfo.stblock.right		=	(icx + iRadio) *iScale;
			itemdrawList.at(iIndex).strinfo.stblock.top			=	(icy - iRadio) *iScale;
			itemdrawList.at(iIndex).strinfo.stblock.bottom	=	(icy + iRadio) *iScale;
		}
	}

	__inline void AddDrawMark(std::vector<RECT>& vectorMark, int iScale, std::vector<_itemDraw>& itemdrawList)
	{
		if(vectorMark.size() < 1) return;
		unsigned int uiMarkSize	=	(unsigned int)vectorMark.size();
		unsigned int iIndex			=	(unsigned int)itemdrawList.size();
		itemdrawList.resize(iIndex + uiMarkSize);

		if(iScale == 1){
			for(unsigned int x=0;	x<uiMarkSize;	++x){
				itemdrawList.at(iIndex+x).stcolor	=	QColor::fromRgb(0, 0, 0);
				itemdrawList.at(iIndex+x).uctype	=	HisDrawType_Block;
				itemdrawList.at(iIndex+x).strinfo.stblock	=	vectorMark.at(x);
			}
		}
		else{
			for(unsigned int x=0;	x<uiMarkSize;	++x){
				itemdrawList.at(iIndex+x).stcolor	=	QColor::fromRgb(0, 0, 0);
				itemdrawList.at(iIndex+x).uctype	=	HisDrawType_Block;
				itemdrawList.at(iIndex+x).strinfo.stblock.left	=	vectorMark.at(x).left *iScale;
				itemdrawList.at(iIndex+x).strinfo.stblock.right	=	vectorMark.at(x).right *iScale;
				itemdrawList.at(iIndex+x).strinfo.stblock.top	=	vectorMark.at(x).top *iScale;
				itemdrawList.at(iIndex+x).strinfo.stblock.bottom	=	vectorMark.at(x).bottom *iScale;
			}
		}
	}

	__inline void AddDrawMark2(std::vector<RECT>& vectorMark, std::vector<_itemDraw>& itemdrawList)
	{
		if(vectorMark.size() < 1) return;
		unsigned int uiMarkSize	=	(unsigned int)vectorMark.size();
		unsigned int iIndex			=	(unsigned int)itemdrawList.size();
		itemdrawList.resize(iIndex + uiMarkSize);

		for(unsigned int x=0;	x<uiMarkSize;	++x){
			itemdrawList.at(iIndex+x).stcolor	=	QColor::fromRgb(255, 255, 255);
			itemdrawList.at(iIndex+x).uctype	=	HisDrawType_Line;
			itemdrawList.at(iIndex+x).strinfo.stblock	=	vectorMark.at(x);
		}
	}

	__inline void AddDrawMark3(float& flMTFPt1X, float& flMTFPt1Y, float& flMTFPt2X, float& flMTFPt2Y, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int iIndex			=	itemdrawList.size();
		itemdrawList.resize(iIndex + 4);

		const float cflLine	=	50.0f;
		itemdrawList.at(iIndex).stcolor							=	QColor::fromRgb(0, 255, 0);
		itemdrawList.at(iIndex).uctype							=	HisDrawType_Line;
		itemdrawList.at(iIndex).strinfo.stblock.left			=	flMTFPt1X - cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.right		=	flMTFPt1X + cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.top			=	flMTFPt1Y;
		itemdrawList.at(iIndex).strinfo.stblock.bottom	=	flMTFPt1Y;
		++iIndex;

		itemdrawList.at(iIndex).stcolor							=	QColor::fromRgb(0, 255, 0);
		itemdrawList.at(iIndex).uctype							=	HisDrawType_Line;
		itemdrawList.at(iIndex).strinfo.stblock.left			=	flMTFPt1X;
		itemdrawList.at(iIndex).strinfo.stblock.right		=	flMTFPt1X;
		itemdrawList.at(iIndex).strinfo.stblock.top			=	flMTFPt1Y - cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.bottom	=	flMTFPt1Y + cflLine;
		++iIndex;

		itemdrawList.at(iIndex).stcolor							=	QColor::fromRgb(0, 255, 0);
		itemdrawList.at(iIndex).uctype							=	HisDrawType_Line;
		itemdrawList.at(iIndex).strinfo.stblock.left			=	flMTFPt2X - cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.right		=	flMTFPt2X + cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.top			=	flMTFPt2Y;
		itemdrawList.at(iIndex).strinfo.stblock.bottom	=	flMTFPt2Y;
		++iIndex;

		itemdrawList.at(iIndex).stcolor							=	QColor::fromRgb(0, 255, 0);
		itemdrawList.at(iIndex).uctype							=	HisDrawType_Line;
		itemdrawList.at(iIndex).strinfo.stblock.left			=	flMTFPt2X;
		itemdrawList.at(iIndex).strinfo.stblock.right		=	flMTFPt2X;
		itemdrawList.at(iIndex).strinfo.stblock.top			=	flMTFPt2Y - cflLine;
		itemdrawList.at(iIndex).strinfo.stblock.bottom	=	flMTFPt2Y + cflLine;
	}

	__inline void AddDrawMark4(RECT& stMTKMark1, RECT& stMTKMark2, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int iIndex			=	itemdrawList.size();
		itemdrawList.resize(iIndex + 2);
		itemdrawList.at(iIndex).stcolor				=	QColor::fromRgb(0, 0, 0);
		itemdrawList.at(iIndex).uctype				=	HisDrawType_Block;
		itemdrawList.at(iIndex).strinfo.stblock	=	stMTKMark1;
		++iIndex;

		itemdrawList.at(iIndex).stcolor				=	QColor::fromRgb(0, 0, 0);
		itemdrawList.at(iIndex).uctype				=	HisDrawType_Block;
		itemdrawList.at(iIndex).strinfo.stblock	=	stMTKMark2;
	}

	__inline void AddDrawFOV4(std::vector<_HisCCMAlg_RECT_FOV4>& vectorRectFov4, int iScale, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int uiIndex	=	itemdrawList.size();
		itemdrawList.resize(uiIndex + vectorRectFov4.size() *4);
		if(iScale == 1){
			for(unsigned int x=0;	x<vectorRectFov4.size(); ++x){
				for(unsigned int i=0;	i<4;	++i){
					itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0,0);
					itemdrawList.at(uiIndex).uctype	=	HisDrawType_Block;
					itemdrawList.at(uiIndex).strinfo.stblock	=	vectorRectFov4.at(x).stBlocks[i];
					++uiIndex;
				}
			}
		}
		else{
			for(unsigned int x=0;	x<vectorRectFov4.size(); ++x){
				for(unsigned int i=0;	i<4;	++i){
					itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0,0);
					itemdrawList.at(uiIndex).uctype	=	HisDrawType_Block;
					itemdrawList.at(uiIndex).strinfo.stblock.left	=	vectorRectFov4.at(x).stBlocks[i].left *iScale;
					itemdrawList.at(uiIndex).strinfo.stblock.right	=	vectorRectFov4.at(x).stBlocks[i].right *iScale;
					itemdrawList.at(uiIndex).strinfo.stblock.top	=	vectorRectFov4.at(x).stBlocks[i].top *iScale;
					itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	vectorRectFov4.at(x).stBlocks[i].bottom *iScale;
					++uiIndex;
				}
			}
		}
	}

	__inline void AddDrawFOV4(_HisCCMAlg_RECT_FOV4& stRectFov4, int iScale, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int uiIndex	=	itemdrawList.size();
		itemdrawList.resize(uiIndex +4);
		if(iScale == 1){
			for(unsigned int i=0;	i<4;	++i){
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0,0);
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Block;
				itemdrawList.at(uiIndex).strinfo.stblock	=	stRectFov4.stBlocks[i];
				++uiIndex;
			}
		}
		else{
			for(unsigned int i=0;	i<4;	++i){
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0,0);
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Block;
				itemdrawList.at(uiIndex).strinfo.stblock.left	=	stRectFov4.stBlocks[i].left *iScale;
				itemdrawList.at(uiIndex).strinfo.stblock.right	=	stRectFov4.stBlocks[i].right *iScale;
				itemdrawList.at(uiIndex).strinfo.stblock.top	=	stRectFov4.stBlocks[i].top *iScale;
				itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	stRectFov4.stBlocks[i].bottom *iScale;
				++uiIndex;
			}
		}
	}

	__inline void AddDrawLP(RECT& stRect, RECT& stLVal, RECT&stLMax, RECT& stLMin, int iImgW, int iImgH, float flSpec, float flValue, int iScale, std::vector<_itemDraw>& itemdrawList, const float cflGradeAPercent)
	{
		if(iScale != 1){
			iImgW	*=		iScale;
			iImgH	*=		iScale;
			stRect.left		*=		iScale;
			stRect.right		*=		iScale;
			stRect.top		*=		iScale;
			stRect.bottom	*=		iScale;
			stLVal.left		*=		iScale;
			stLVal.right		*=		iScale;
			stLVal.top		*=		iScale;
			stLVal.bottom	*=		iScale;
			stLMin.left		*=		iScale;
			stLMin.right		*=		iScale;
			stLMin.top		*=		iScale;
			stLMin.bottom	*=		iScale;
			stLMax.left		*=		iScale;
			stLMax.right		*=		iScale;
			stLMax.top		*=		iScale;
			stLMax.bottom	*=		iScale;
		}

		QColor stColor	=	QColor::fromRgb(255, 0, 0);
		if(flValue >= flSpec *cflGradeAPercent) stColor	=	QColor::fromRgb(0, 255, 0);
		else if(flValue >= flSpec) stColor	=	QColor::fromRgb(255, 255, 0);
		unsigned int  uiIndex	=	itemdrawList.size();
		
		if(flValue > 0.1f){
			itemdrawList.resize(uiIndex +3);
			itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
			itemdrawList.at(uiIndex).stcolor	=	stColor;
			itemdrawList.at(uiIndex).strinfo.stblock	=	stLVal;
			++uiIndex;
		}
		else{
			itemdrawList.resize(uiIndex +2);
		}

// 		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
// 		itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0, 0);
// 		itemdrawList.at(uiIndex).strinfo.stblock	=	stLMin;
// 		++uiIndex;
// 		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
// 		itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0, 0);
// 		itemdrawList.at(uiIndex).strinfo.stblock	=	stLMax;
// 		++uiIndex;
// 		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Block;
// 		itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(0, 0, 0);
// 		itemdrawList.at(uiIndex).strinfo.stblock	=	stRect;
// 		++uiIndex;

		bool bInner	=	false;
		LONG lCenterX	=	((stRect.left + stRect.right) >>1), lCenterY	=	((stRect.top + stRect.bottom) >>1);
		if(abs(lCenterX - (iImgW >>1)) < iImgW /3 && abs(lCenterY - (iImgH >>1)) < iImgH /3)
			bInner	=	true;
		bool bInnerH	=	false;
		if(abs(lCenterY - (iImgH >>1)) < iImgH /2)
			bInnerH	=	true;

		if(GetRectWidth(&stRect) > GetRectHeight(&stRect)){ //水平
			const int ciBlockH	=	20 *iImgH /1200;
			if((!bInner && GetRectCenterY(&stRect) < (iImgH >>1)) || (bInner && GetRectCenterX(&stRect) > (iImgW >>1))){ //上
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(255, 255, 0);
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left;
				itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom + ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "SPEC:%d", (int)(flSpec));
				++uiIndex;
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	stColor;
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left;
				itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom + ciBlockH + ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "LP:%d", (int)(flValue));
				++uiIndex;
			}
			else{
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(255, 255, 0);
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left;
				itemdrawList.at(uiIndex).idata[1]	=	stRect.top - ciBlockH - ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "SPEC:%d", (int)(flSpec));
				++uiIndex;
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	stColor;
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left;
				itemdrawList.at(uiIndex).idata[1]	=	stRect.top - ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "LP:%d", (int)(flValue));
				++uiIndex;
			}
		}
		else{ //垂直
			const int ciBlockH	=	20 *iImgH /1200;
			if((!bInner && GetRectCenterX(&stRect) > (iImgW >>1)) || (bInner && GetRectCenterY(&stRect) > (iImgH >>1))){ //左
				const unsigned int ciBlockW	=	120 *iImgW /1600;
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(255, 255, 0);
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left - ciBlockW;
				if(GetRectCenterY(&stRect) < (iImgH >>1))
					itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom - ciBlockH;
				else
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top;
				if(bInnerH)
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + GetRectHeight(&stRect) /2;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "SPEC:%d", (int)(flSpec));
				++uiIndex;
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	stColor;
				itemdrawList.at(uiIndex).idata[0]	=	stRect.left - ciBlockW;
				if(GetRectCenterY(&stRect) < (iImgH >>1))
					itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom - ciBlockH + ciBlockH;
				else
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + ciBlockH;
				if(bInnerH)
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + GetRectHeight(&stRect) /2 + ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "LP:%d", (int)(flValue));
				++uiIndex;
			}
			else{// 右
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	QColor::fromRgb(255, 255, 0);
				itemdrawList.at(uiIndex).idata[0]	=	stRect.right;
				if(GetRectCenterY(&stRect) < (iImgH >>1))
					itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom - ciBlockH;
				else
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top;
				if(bInnerH)
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + GetRectHeight(&stRect) /2;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "SPEC:%d", (int)(flSpec));
				++uiIndex;
				itemdrawList.at(uiIndex).uctype	=	HisDrawType_Text;
				itemdrawList.at(uiIndex).stcolor	=	stColor;
				itemdrawList.at(uiIndex).idata[0]	=	stRect.right;
				if(GetRectCenterY(&stRect) < (iImgH >>1))
					itemdrawList.at(uiIndex).idata[1]	=	stRect.bottom - ciBlockH + ciBlockH;
				else
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + ciBlockH;
				if(bInnerH)
					itemdrawList.at(uiIndex).idata[1]	=	stRect.top + GetRectHeight(&stRect) /2 + ciBlockH;
				sprintf(itemdrawList.at(uiIndex).strinfo.strtext, "LP:%d", (int)(flValue));
				++uiIndex;
			}
		}
	}

	__inline void AddDesiredFOV4Cross(double dflPixelDis, double dflAngle, int iCenterX, int iCenterY, std::vector<_itemDraw>& itemdrawList)
	{
		double dfldx, dfldy, dflX1, dflX2, dflX3, dflX4, dflY1, dflY2, dflY3, dflY4;
		if(dflAngle < 3.0){
			dflX1	=	iCenterX - dflPixelDis;
			dflY1	=	iCenterY;
			dflX2	=	iCenterX + dflPixelDis;
			dflY2	=	iCenterY;
			dflX3	=	iCenterX;
			dflY3	=	iCenterY - dflPixelDis;
			dflX4	=	iCenterX;
			dflY4	=	iCenterY + dflPixelDis;
		}
		else{
			dflAngle	=	dflAngle *3.1415926 /180.0;
			dfldx		=	dflPixelDis *cos(dflAngle);
			dfldy		= dflPixelDis *sin(dflAngle);
			dflX1	= iCenterX - dfldx;
			dflY1	= iCenterY - dfldy;
			dflX2	= iCenterX + dfldx;
			dflY2	= iCenterY - dfldy;
			dflX3	= iCenterX - dfldx;
			dflY3	= iCenterY + dfldy;
			dflX4	= iCenterX + dfldx;
			dflY4	= iCenterY + dfldy;
		}

		const double cdflLength	=	30.0;
		unsigned int uiIndex	=	itemdrawList.size();
		itemdrawList.resize(uiIndex + 8);
		const QColor stColor	=	QColor::fromRgb(0, 0, 0);

		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.left		=	dflX1 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.right	=	dflX1 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.top = itemdrawList.at(uiIndex).strinfo.stblock.bottom = dflY1;
		++uiIndex;
		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.top		=	dflY1 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	dflY1 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.left = itemdrawList.at(uiIndex).strinfo.stblock.right = dflX1;
		++uiIndex;

		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.left		=	dflX2 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.right	=	dflX2 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.top = itemdrawList.at(uiIndex).strinfo.stblock.bottom = dflY2;
		++uiIndex;
		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.top		=	dflY2 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	dflY2 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.left = itemdrawList.at(uiIndex).strinfo.stblock.right = dflX2;
		++uiIndex;

		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.left		=	dflX3 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.right	=	dflX3 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.top = itemdrawList.at(uiIndex).strinfo.stblock.bottom = dflY3;
		++uiIndex;
		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.top		=	dflY3 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	dflY3 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.left = itemdrawList.at(uiIndex).strinfo.stblock.right = dflX3;
		++uiIndex;

		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.left		=	dflX4 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.right	=	dflX4 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.top = itemdrawList.at(uiIndex).strinfo.stblock.bottom = dflY4;
		++uiIndex;
		itemdrawList.at(uiIndex).uctype	=	HisDrawType_Line;
		itemdrawList.at(uiIndex).stcolor	=	stColor;
		itemdrawList.at(uiIndex).strinfo.stblock.top		=	dflY4 - cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.bottom	=	dflY4 + cdflLength;
		itemdrawList.at(uiIndex).strinfo.stblock.left = itemdrawList.at(uiIndex).strinfo.stblock.right = dflX4;
		++uiIndex;
	}

	__inline double CalculateAnglePerMarkPixel(std::vector<_HisCCMAlg_AFA_LP_DataItem>& vectorItemData)
	{
		if(vectorItemData.size() < 2) return -1.0;
		unsigned int uiCount = 0;
		double dflSum		=	0.0;
		for(std::vector<_HisCCMAlg_AFA_LP_DataItem>::iterator theiterator = vectorItemData.begin()+1; theiterator != vectorItemData.end(); theiterator++){
			if(theiterator->uiMarkDistance != 0 && (theiterator-1)->uiMarkDistance != 0 && theiterator->uiMarkDistance != (theiterator-1)->uiMarkDistance){
				dflSum	=	dflSum + abs(theiterator->dflAbsAngle - (theiterator-1)->dflAbsAngle) / ((theiterator->uiMarkDistance>(theiterator-1)->uiMarkDistance)?(theiterator->uiMarkDistance-(theiterator-1)->uiMarkDistance):((theiterator-1)->uiMarkDistance-theiterator->uiMarkDistance));
				++uiCount;
			}
		}
		return (uiCount)?(dflSum /uiCount):(-1.0);
	}

	__inline int AFCLpHAFromDB(unsigned char uctype, _lpAFCParameter* pstPara, _HisCCMAlg_AFC_LP_DB* pDB, bool bChannel1)
	{
		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		pDB->initial();
		pDB->pstTacticsBasic	=	new _HisCCMAlg_AFC_Tactics_Basic;
		pDB->pstLpBasic		=	new _HisCCMAlg_LPBasic_Info;
		if(!(pDB->pstLpBasic && pDB->pstTacticsBasic)){
			pDB->initial();
			return HisFX3Error_MallocBuffer;
		}

		*(pDB->pstTacticsBasic)	=	pstPara->stTacticsBasic;
		*(pDB->pstLpBasic)			=	pstPara->stLpBasic;
		pDB->vectorLpItemInfo.assign(pstPara->vectorLpItem.begin(), pstPara->vectorLpItem.end());

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT bins1,bins2,bins3,bins1byte,bins2byte,bins3byte,ints1,ints2,ints3 FROM tablemanage WHERE tablename='" % strTableName % "'");
			query.exec();

			QByteArray bins1,bins2,bins3;
			unsigned int bins1byte=0,bins2byte=0,bins3byte=0, ints1=0, ints2 = 0, ints3 = 0;
			while (query.next()){
				bins1 = query.value(0).toByteArray();
				bins2 = query.value(1).toByteArray();
				bins3 = query.value(2).toByteArray();
				bins1byte	=	query.value(3).toUInt();
				bins2byte	=	query.value(4).toUInt();
				bins3byte	=	query.value(5).toUInt();
				ints1			=	query.value(6).toUInt();
				ints2			=	query.value(7).toUInt();
				ints3			=	query.value(8).toUInt();
			}

			QByteArray Sbins1	=	TacticsBasicSerialize(*pDB->pstTacticsBasic);
			QByteArray Sbins2	=	LpHABasicSerialize(*pDB->pstLpBasic);
			QByteArray Sbins3	=	LpHAItemSerialize(pDB->vectorLpItemInfo);
			unsigned int Sbins1byte	=	Sbins1.size();
			unsigned int Sbins2byte	=	Sbins2.size();
			unsigned int Sbins3byte	=	Sbins3.size();
			unsigned int Sints1			=	pDB->vectorLpItemInfo.size();
			unsigned int Sints2			=	30; //TV Line Chart-A
			unsigned int Sints3			=	(bChannel1)?(1):(2);

			bool bupdate = false;
			if(Sbins1byte != bins1byte || Sbins2byte != bins2byte || Sbins3byte != bins3byte || Sints1 != ints1 || Sints2 != ints2 || Sints3 != ints3)
				bupdate	=	true;
			if(!bupdate){
				if(!isEqual(bins1, Sbins1)) bupdate = true;
				if(!isEqual(bins2, Sbins2)) bupdate = true;
				if(!isEqual(bins3, Sbins3)) bupdate = true;
			}

			if(bupdate){
				query.prepare("UPDATE tablemanage SET bins1=:bins1,bins2=:bins2,bins3=:bins3,bins1byte=:bins1byte,bins2byte=:bins2byte,bins3byte=:bins3byte,ints1=:ints1,ints2=:ints2,ints3=:ints3 WHERE tablename='" % strTableName % "'");
				query.bindValue(":bins1", Sbins1);
				query.bindValue(":bins2", Sbins2);
				query.bindValue(":bins3", Sbins3);
				query.bindValue(":bins1byte", Sbins1byte);
				query.bindValue(":bins2byte", Sbins2byte);
				query.bindValue(":bins3byte", Sbins3byte);
				query.bindValue(":ints1", Sints1);
				query.bindValue(":ints2", Sints2);
				query.bindValue(":ints3", Sints3);
				query.exec();

				query.prepare("DELETE FROM " % strTableName);
				query.exec();
			}
			else{
				query.prepare("SELECT id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend FROM " % strTableName %  "  ORDER BY id ASC" );
				query.exec();
				unsigned int uiDataSize	=	pstPara->vectorLpItem.size() *4;

				_HisCCMAlg_AFC_LP_DB_Item stNewItem;
				stNewItem.vecValueStart.resize(uiDataSize);
				stNewItem.vecValueEnd.resize(uiDataSize);
				stNewItem.ucStatus	=	0;
				QByteArray valuestart, valueend;

				while (query.next()){
					stNewItem.ui64ID				=	query.value(0).toULongLong();
					stNewItem.sMotorStart		=	query.value(1).toInt();
					stNewItem.flMarkDisStart	=	query.value(2).toFloat();
					stNewItem.sMotorEnd			=	query.value(5).toInt();
					stNewItem.flMarkDisEnd		=	query.value(6).toFloat();
					valuestart								=	query.value(4).toByteArray();
					valueend								=	query.value(8).toByteArray();

					QDataStream streamstart(valuestart);
					streamstart.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamstart >> stNewItem.vecValueStart.at(x);
					}

					QDataStream streamend(valueend);
					streamend.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamend >> stNewItem.vecValueEnd.at(x);
					}

					pDB->ui64IDMax	=	max(pDB->ui64IDMax, stNewItem.ui64ID);
					pDB->vectorItem.push_back(stNewItem);
				}
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			pDB->initial();
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int AFCLpHAToDB(unsigned char uctype, _lpAFCParameter* pstPara, _HisCCMAlg_AFC_LP_DB* pDB, \
		std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorDataItem, unsigned int uiIndex, bool bChannel1)
	{
		if(uiIndex == 0) return 0;
		if(vectorDataItem.at(uiIndex).ucStatus == 0x0) return 0;

		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		_HisCCMAlg_AFC_LP_DB_Item stNewItem;
		stNewItem.flMarkDisStart	=	vectorDataItem.at(0).dflMarkDistance;
		stNewItem.sMotorStart		=	vectorDataItem.at(0).sMotorStep;
		stNewItem.ui64ID				=	pDB->ui64IDMax +1;
		stNewItem.flMarkDisEnd		=	vectorDataItem.at(uiIndex).dflMarkDistance;
		stNewItem.sMotorEnd			=	vectorDataItem.at(uiIndex).sMotorStep;

		stNewItem.vecValueStart.resize(vectorDataItem.at(0).vectorFOV.size() *4);
		stNewItem.vecValueEnd.resize(vectorDataItem.at(0).vectorFOV.size() *4);

		unsigned int uitempi	=	0;
		for(unsigned int y=0;	y<pstPara->vectorLpItem.size(); ++y){
			for(unsigned int x=0;	x<4;	++x){
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).stLpValue[x].flValue;
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).stLpValue[x].flValue;
				++uitempi;
			}
		}

		++(pDB->ui64IDMax);

		bool bReplace = false;
		unsigned int uiReplaceID	=	0;
		if(vectorDataItem.size() >= pDB->usConstMaxItem){
			unsigned __int64 uiMinID	=	0xFFFFFFFFFFFFFFFF;
			for(unsigned int x=0;	x<pDB->vectorItem.size(); ++x){
				if(pDB->vectorItem.at(x).ui64ID < uiMinID){
					uiMinID	=	pDB->vectorItem.at(x).ui64ID;
					uiReplaceID	=	x;
				}
			}

			bReplace = true;
			pDB->vectorItem.erase(pDB->vectorItem.begin() + uiReplaceID);		
		}

		pDB->vectorItem.push_back(stNewItem);

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);

			if(bReplace){
				query.prepare("DELETE FROM " % strTableName %  " WHERE id=:id");
				query.bindValue(":id", uiReplaceID);
				query.exec();
			}

			QByteArray valuestart, valueend;

			QDataStream streamstart(&valuestart, QIODevice::WriteOnly);
			streamstart.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueStart.size(); ++x){
				streamstart << stNewItem.vecValueStart.at(x);
			}

			QDataStream streamend(&valueend, QIODevice::WriteOnly);
			streamend.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueEnd.size(); ++x){
				streamend << stNewItem.vecValueEnd.at(x);
			}

			query.prepare("INSERT INTO " % strTableName %  "(id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend) VALUES(:id,:motorstart,:disstart,:reserves1,:valuestart,:motorend,:disend,:reservee1,:valueend)");		
			query.bindValue(":id", stNewItem.ui64ID);
			query.bindValue(":motorstart", stNewItem.sMotorStart);
			query.bindValue(":disstart", stNewItem.flMarkDisStart);
			query.bindValue(":reserves1", 0.0);
			query.bindValue(":valuestart", valuestart);
			query.bindValue(":motorend", stNewItem.sMotorEnd);
			query.bindValue(":disend", stNewItem.flMarkDisEnd);
			query.bindValue(":reservee1", 0.0);
			query.bindValue(":valueend", valueend);
			query.exec();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline void saveLpHAAFCCurve2File(std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorItemData, \
		_lpAFCParameter* pstParameter, QString& strPath)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);

		QTextStream out(&classFile);
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).sMotorStep) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).flWeightValue) << ",";
		}
		out << "\n";

		for(unsigned int w=0;	w<pstParameter->vectorLpItem.size(); ++w){
			for(unsigned int y=0; y<4;	++y){
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stLpValue[y].flValue) << ",";
				}
				out << "\n";
			}
		}
		
		classFile.close();
	}

	__inline void logitem_pushback(_HisLog_Item& logitem, QString& strKey, QVariant& strValue, HisFX3Log& classLog)
	{
		logitem.itemkey		=	strKey;
		logitem.itemvalue	=	strValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);
	}

	__inline void saveRJAFALPLog(_HisCCMAlg_AFA_LP_DataItem& stItemData, HisFX3Log& classLog)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_RJAFA_LP1);
		logitem.itemkey		=	"fa_lp_result";
		logitem.itemvalue	=	(stItemData.ucStatus == 0x1)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"marks_distance";
		logitem.itemvalue	=	stItemData.uiMarkDistance;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		QString strText;
		for(std::vector<_HisCCMAlg_AFA_LP_DataItem_FOV>::iterator theiterator = stItemData.vectorFOV.begin(); theiterator != stItemData.vectorFOV.end(); theiterator++){
			strText	=	QString::number(theiterator->flFOV, 'f', 2);
			logitem.itemkey		=	strText % "_data1";
			logitem.itemvalue	=	theiterator->stLpValue[0].flValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
			logitem.itemkey		=	strText % "_data2";
			logitem.itemvalue	=	theiterator->stLpValue[1].flValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
			logitem.itemkey		=	strText % "_data3";
			logitem.itemvalue	=	theiterator->stLpValue[2].flValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
			logitem.itemkey		=	strText % "_data4";
			logitem.itemvalue	=	theiterator->stLpValue[3].flValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
			logitem.itemkey		=	strText % "_uniforma";
			logitem.itemvalue	=	theiterator->flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void saveShadingHALog(_HisAlg_Shading_HA_Data& stData, HisFX3Log& classLog)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SHADING);
		logitem.itemkey		=	"shading_result";
		logitem.itemvalue	=	(stData.bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadingha_LT";
		logitem.itemvalue	=	stData.flLT;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadingha_RT";
		logitem.itemvalue	=	stData.flRT;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadingha_LB";
		logitem.itemvalue	=	stData.flLB;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadingha_RB";
		logitem.itemvalue	=	stData.flRB;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadingha_Dev";
		logitem.itemvalue	=	stData.flDev;
		classLog.push_back(logitem);
		++(logitem.itemtype);
	}

	__inline void addDrawShadingHA(_HisAlg_Shading_HA_Config& stConfig, _HisAlg_Shading_HA_Data& stData, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int iIndex			=	(unsigned int)itemdrawList.size();
		itemdrawList.resize(iIndex + 9);
		float flData;
		for(unsigned int x=0;	x<4;	++x){
			switch (x){
			case 0:	flData	=	stData.flLT;	break;
			case 1:	flData	=	stData.flRT;	break;
			case 2:	flData	=	stData.flLB;	break;
			default:		flData	=	stData.flRB;	break;
			}

			QColor stColor = (flData > stConfig.flShadingSpecMax || flData < stConfig.flShadingSpecMin)?(QColor::fromRgb(255,0,0)):(QColor::fromRgb(0,255,0));
			itemdrawList.at(iIndex).usitem	=	whitepanelitem_shading;
			itemdrawList.at(iIndex).stcolor	=	QColor::fromRgb(0,0,0);
			itemdrawList.at(iIndex).uctype	=	HisDrawType_Block;
			itemdrawList.at(iIndex).strinfo.stblock	=	stData.stROI[x];
			++iIndex;
			itemdrawList.at(iIndex).usitem	=	whitepanelitem_shading;
			itemdrawList.at(iIndex).stcolor	=	stColor;
			itemdrawList.at(iIndex).uctype	=	HisDrawType_Text;
			itemdrawList.at(iIndex).idata[0]	=	stData.stROI[x].left;
			itemdrawList.at(iIndex).idata[1]	=	stData.stROI[x].top;
			sprintf(itemdrawList.at(iIndex).strinfo.strtext, "%.2f", flData);
			switch (x){
			case 0: itemdrawList.at(iIndex).idata[0]	=	stData.stROI[x].left; itemdrawList.at(iIndex).idata[1]	=	stData.stROI[x].bottom; break;
			case 1: itemdrawList.at(iIndex).idata[0]	=	stData.stROI[x].left-50; itemdrawList.at(iIndex).idata[1]	=	stData.stROI[x].bottom; break;
			case 2: itemdrawList.at(iIndex).idata[0]	=	stData.stROI[x].left; itemdrawList.at(iIndex).idata[1]	=	stData.stROI[x].top; break;
			default: itemdrawList.at(iIndex).idata[0]	=	stData.stROI[x].left-50; itemdrawList.at(iIndex).idata[1]	=	stData.stROI[x].top; break;
			}
			++iIndex;
		}
		itemdrawList.at(iIndex).usitem	=	whitepanelitem_shading;
		itemdrawList.at(iIndex).stcolor	=	QColor::fromRgb(0,0,0);
		itemdrawList.at(iIndex).uctype	=	HisDrawType_Block;
		itemdrawList.at(iIndex).strinfo.stblock	=	stData.stROI[4];
		++iIndex;
	}

	__inline void addDrawShadingHB(_HisAlg_Shading_HB_Config& stConfig, _HisAlg_Shading_HB_Data& stData, std::vector<_itemDraw>& itemdrawList)
	{
		unsigned int iIndex			=	itemdrawList.size();
		itemdrawList.resize(iIndex + 49);
		for(unsigned int x=0;	x<49;	++x){
			itemdrawList.at(iIndex).usitem	=	whitepanelitem_shading;
			itemdrawList.at(iIndex).stcolor	=	QColor::fromRgb(0,0,0);
			itemdrawList.at(iIndex).uctype	=	HisDrawType_Block;
			itemdrawList.at(iIndex).strinfo.stblock	=	stData.stROI[x];
			++iIndex;
		}
	}

	__inline void saveShadingHBLog(_HisAlg_Shading_HB_Data& stData, _HisAlg_Shading_HB_Data& stDataOffset, \
		float flOffsetYY, float flOffsetRG, float flOffsetBG, float flOffsetPP, HisFX3Log& classLog)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SHADING);
		logitem.itemkey		=	"shading_result";
		logitem.itemvalue	=	(stDataOffset.bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_LT";
		logitem.itemvalue	=	stData.Y_0;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_RT";
		logitem.itemvalue	=	stData.Y_6;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_LB";
		logitem.itemvalue	=	stData.Y_42;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_RB";
		logitem.itemvalue	=	stData.Y_48;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_YY_Original";
		logitem.itemvalue	=	stData.Y;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_YY_Offset";
		logitem.itemvalue	=	flOffsetYY;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_YY_Final";
		logitem.itemvalue	=	stDataOffset.Y;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_RG_Original";
		logitem.itemvalue	=	stData.RG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_RG_Offset";
		logitem.itemvalue	=	flOffsetRG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_RG_Final";
		logitem.itemvalue	=	stDataOffset.RG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_BG_Original";
		logitem.itemvalue	=	stData.BG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_BG_Offset";
		logitem.itemvalue	=	flOffsetBG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_BG_Final";
		logitem.itemvalue	=	stDataOffset.BG;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_PP_Original";
		logitem.itemvalue	=	stData.PP;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_PP_Offset";
		logitem.itemvalue	=	flOffsetPP;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"shadinghb_PP_Final";
		logitem.itemvalue	=	stDataOffset.PP;
		classLog.push_back(logitem);
		++(logitem.itemtype);
	}

	__inline void  saveVignettingHALog(_HisAlg_Vignetting_HA_Data& stData, HisFX3Log& classLog)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_VIGNETTING);
		logitem.itemkey		=	"vignetting_result";
		logitem.itemvalue	=	(stData.bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_LT_R2";
		logitem.itemvalue	=	stData.flLTR2;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_LT_R3";
		logitem.itemvalue	=	stData.flLTR3;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_RT_R2";
		logitem.itemvalue	=	stData.flRTR2;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_RT_R3";
		logitem.itemvalue	=	stData.flRTR3;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_LB_R2";
		logitem.itemvalue	=	stData.flLBR2;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_LB_R3";
		logitem.itemvalue	=	stData.flLBR3;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_RB_R2";
		logitem.itemvalue	=	stData.flRBR2;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(Y)_RB_R3";
		logitem.itemvalue	=	stData.flRBR3;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	"vignettingha(R)_LT_R2";
		logitem.itemvalue	=	stData.flLTR2_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_LT_R3";
		logitem.itemvalue	=	stData.flLTR3_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_RT_R2";
		logitem.itemvalue	=	stData.flRTR2_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_RT_R3";
		logitem.itemvalue	=	stData.flRTR3_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_LB_R2";
		logitem.itemvalue	=	stData.flLBR2_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_LB_R3";
		logitem.itemvalue	=	stData.flLBR3_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_RB_R2";
		logitem.itemvalue	=	stData.flRBR2_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(R)_RB_R3";
		logitem.itemvalue	=	stData.flRBR3_R;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	"vignettingha(G)_LT_R2";
		logitem.itemvalue	=	stData.flLTR2_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_LT_R3";
		logitem.itemvalue	=	stData.flLTR3_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_RT_R2";
		logitem.itemvalue	=	stData.flRTR2_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_RT_R3";
		logitem.itemvalue	=	stData.flRTR3_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_LB_R2";
		logitem.itemvalue	=	stData.flLBR2_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_LB_R3";
		logitem.itemvalue	=	stData.flLBR3_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_RB_R2";
		logitem.itemvalue	=	stData.flRBR2_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(G)_RB_R3";
		logitem.itemvalue	=	stData.flRBR3_G;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	"vignettingha(B)_LT_R2";
		logitem.itemvalue	=	stData.flLTR2_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_LT_R3";
		logitem.itemvalue	=	stData.flLTR3_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_RT_R2";
		logitem.itemvalue	=	stData.flRTR2_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_RT_R3";
		logitem.itemvalue	=	stData.flRTR3_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_LB_R2";
		logitem.itemvalue	=	stData.flLBR2_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_LB_R3";
		logitem.itemvalue	=	stData.flLBR3_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_RB_R2";
		logitem.itemvalue	=	stData.flRBR2_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
		logitem.itemkey		=	"vignettingha(B)_RB_R3";
		logitem.itemvalue	=	stData.flRBR3_B;
		classLog.push_back(logitem);
		++(logitem.itemtype);
	}

	__inline void saveLpAFCResult(unsigned int uiType, bool bResult, unsigned int uiIndex, std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorDataItem, \
		_lpAFCParameter* pstParameter, HisFX3Log& classLog, int iWdith, int iHeight)
	{
		if(vectorDataItem.empty()) return;
		_HisLog_Item logitem;
		QString strKey1;
		if(uiType == 1) {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_AFC_LP_MIDDLE);
			strKey1	=	"afc_lp_middle_";
		}
		else if(uiType == 2)	{
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_AFC_LP_FAR);
			strKey1	=	"afc_lp_far_";
		}
		else {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_AFC_LP_NEAR);
			strKey1	=	"afc_lp_near_";
		}

		std::vector<_HisCCMAlg_AFC_LP_DataItem>::iterator saveiterator = vectorDataItem.begin() + uiIndex;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		int iCenterX, iCenterY;
		for(unsigned int x=0;	x<saveiterator->vectorFOV.size();	++x){
			iCenterX	=	iCenterY = 0;
			for(unsigned int i=0;	i<4;	++i){
				iCenterX	+=	saveiterator->vectorFOV.at(x).stBlock[i].left;
				iCenterX	+=	saveiterator->vectorFOV.at(x).stBlock[i].right;
				iCenterY	+=	saveiterator->vectorFOV.at(x).stBlock[i].top;
				iCenterY	+=	saveiterator->vectorFOV.at(x).stBlock[i].bottom;
			}

			iCenterX	=	(iCenterX >>2);
			iCenterY	=	(iCenterY >>2);

			for(unsigned int i=0;	i<4;	++i){
				logitem.itemkey		=	strKey1 % "f" % QString::number(pstParameter->vectorLpItem.at(x).flFOV, 'f', 3) % "_" % getBlockName(saveiterator->vectorFOV.at(x).stBlock[i], iCenterX, iCenterY);
				logitem.itemvalue	=	saveiterator->vectorFOV.at(x).stLpValue[i].flValue;
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey	=	strKey1 % "f" % QString::number(pstParameter->vectorLpItem.at(x).flFOV, 'f', 3) % "_u";
			logitem.itemvalue	=	saveiterator->vectorFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}

		if(pstParameter->stTacticsBasic.ucTactics == _HisCCMAlg_Rolongo_AFC_Tactics_Linear){

		}
		else if(pstParameter->stTacticsBasic.ucTactics != _HisCCMAlg_Rolongo_AFC_Tactics_Single){
			logitem.itemkey		=	strKey1 % "motor_pos";
			logitem.itemvalue	=	saveiterator->sMotorStep;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void LpMFACaculateResult(_HisCCMAlg_AFC_LP_DataItem& stDataItem, const float cflGradeAPercent)
	{
		stDataItem.ucStatus			=	5;
		double dflTotalWeightValue = 0.0;
		double dflTempWeightValue;
		float flMax, flMin;

		unsigned char ucStatus;
		for(std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV>::iterator tempiterator = stDataItem.vectorFOV.begin(); tempiterator != stDataItem.vectorFOV.end(); tempiterator++){
			tempiterator->ucStatus	=	5;
			flMax	=	-99999.9f;  flMin = 99999.9f;
			dflTempWeightValue	=	0.0;
			for(unsigned int x=0;	x<4;	++x){
				if((tempiterator->stLpValue[x].ucOrientation == 0 && tempiterator->stLpValue[x].flValue <  tempiterator->flSpecHor) || \
					(tempiterator->stLpValue[x].ucOrientation == 1 && tempiterator->stLpValue[x].flValue <  tempiterator->flSpecVec)){
						ucStatus		=	0;
				}
				else if((tempiterator->stLpValue[x].ucOrientation == 0 && tempiterator->stLpValue[x].flValue <  tempiterator->flSpecHor *cflGradeAPercent) || \
					(tempiterator->stLpValue[x].ucOrientation == 1 && tempiterator->stLpValue[x].flValue <  tempiterator->flSpecVec *cflGradeAPercent)){
						ucStatus		=	4;
				}
				else ucStatus = 5;
				tempiterator->ucStatus	=	min(tempiterator->ucStatus, ucStatus);
				stDataItem.ucStatus		=	min(stDataItem.ucStatus, ucStatus);
				flMax	=	max(flMax, tempiterator->stLpValue[x].flValue);
				flMin		=	min(flMin, tempiterator->stLpValue[x].flValue);
				dflTempWeightValue	+=	tempiterator->stLpValue[x].flValue;
			}

			tempiterator->flUniformValue	=	flMax - flMin;
			if(tempiterator->flUniformValue > tempiterator->flSpecUniform){
				tempiterator->ucStatus	=	0;
				stDataItem.ucStatus		=	0;
			}

			dflTempWeightValue   *= 0.25;
			dflTempWeightValue	*=	tempiterator->flWeight;
			dflTotalWeightValue		+=	dflTempWeightValue;
		}

		stDataItem.flWeightValue	=	dflTotalWeightValue;
	}

	__inline void LpMFADrawBarChart(_HisCCMAlg_AFC_LP_DataItem& stData, _HisCCMAlg_AFC_LP_DataItem& stMax, bool bDrawMax, float flMaxValue, \
		QImage& imageBackgound, QImage& imageGreen, QImage& imageRed, QImage& imageBlue, QPainter& painer, QPen&	thePen, QFont& theFont)
	{
		const int ciTotalWidth				=	imageBackgound.width();
		const int ciInitBarWidth			=	imageGreen.width();
		const int ciIntiBarHeight			=	imageGreen.height();
		const int ciBackBottom			=	40;
		const int ciBackTop					=	40;
		const int ciTextRectHeight		=	20;
		int iBarWidth	=	ciTotalWidth / (stData.vectorFOV.size()*6 -1);
		iBarWidth		=	min(iBarWidth, ciInitBarWidth);
		int iBlockCount	=	(int)(stData.vectorFOV.size()*4);
		int iGroupCount	=	(int)stData.vectorFOV.size();

		//draw bar chart
		imageBackgound.fill(QColor::fromRgb(240, 240, 240));
		thePen.setColor(QColor::fromRgb(0,0,0));
		painer.setPen(thePen);

		theFont.setPixelSize(iBarWidth /2);
		theFont.setBold(false);
		painer.setFont(theFont);

		QRect rectImage, rectText;
		QImage* ptheImage;
		QString strText;
		QLine lineSpec;

		rectImage.setLeft(ciTotalWidth - (iBlockCount + iGroupCount +iGroupCount -1) *iBarWidth);
		rectImage.setTop(ciBackTop);
		rectImage.setBottom(imageBackgound.height() - ciBackBottom);
		rectImage.setRight(rectImage.left() + iBarWidth -1);

		rectText.setLeft(ciTotalWidth - (iBlockCount + iGroupCount +iGroupCount -1) *iBarWidth);
		rectText.setTop(ciBackTop);
		rectText.setWidth(iBarWidth);
		rectText.setHeight(ciTextRectHeight);

		int w;
		for(int y=0;	y<iGroupCount;	++y){
			for(int x=0;	x<4;	++x){
				if(bDrawMax){
// 					w	=	static_cast<int>((1.0f - *(pflmax+x)) *static_cast<float>(ciIntiBarHeight));
// 					rectImage.setTop(w + ciBackTop);
// 					painer.drawImage(rectImage,  imageBlue);
				}

				if(stData.vectorFOV.at(y).stLpValue[x].ucOrientation == 0)
					ptheImage	=	(stData.vectorFOV.at(y).stLpValue[x].flValue < stData.vectorFOV.at(y).flSpecHor)?(&imageRed):(&imageGreen);
				else
					ptheImage	=	(stData.vectorFOV.at(y).stLpValue[x].flValue < stData.vectorFOV.at(y).flSpecVec)?(&imageRed):(&imageGreen);
				w	=	static_cast<int>((flMaxValue - stData.vectorFOV.at(y).stLpValue[x].flValue) /flMaxValue *static_cast<float>(ciIntiBarHeight));
				rectImage.setTop(w + ciBackTop);

				painer.drawImage(rectImage,  *ptheImage);

				rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
				strText	=	QString::number(stData.vectorFOV.at(y).stLpValue[x].flValue, 'f', 0);

				painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

				if(stData.vectorFOV.at(y).stLpValue[x].ucOrientation == 0)
					w	=	static_cast<int>((flMaxValue - stData.vectorFOV.at(y).flSpecHor)/flMaxValue *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
				else
					w	=	static_cast<int>((flMaxValue - stData.vectorFOV.at(y).flSpecVec)/flMaxValue *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
				lineSpec.setLine(rectImage.left(), w, rectImage.right(), w);

				painer.drawLine(lineSpec);

				rectImage.moveLeft(rectImage.left() + iBarWidth);
			}

			if(bDrawMax){
// 				w	=	static_cast<int>((1.0f + min(min(*(pflmax), *(pflmax+1)), min(*(pflmax+2), *(pflmax+3))) - \
// 					max(max(*(pflmax), *(pflmax+1)), max(*(pflmax+2), *(pflmax+3)))) *static_cast<float>(ciIntiBarHeight));
// 				rectImage.setTop(w + ciBackTop);
// 				painer.drawImage(rectImage,  imageBlue);
			}

			ptheImage	=	(stData.vectorFOV.at(y).flUniformValue > stData.vectorFOV.at(y).flSpecUniform)?(&imageRed):(&imageGreen);
			w	=	static_cast<int>((flMaxValue - stData.vectorFOV.at(y).flUniformValue) /flMaxValue *static_cast<float>(ciIntiBarHeight));
			rectImage.setTop(w + ciBackTop);

			painer.drawImage(rectImage,  *ptheImage);

			rectText.moveTo(rectImage.left(), rectImage.top() - ciTextRectHeight);
			strText	=	QString::number(stData.vectorFOV.at(y).flUniformValue, 'f', 0);

			painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

			w	=	static_cast<int>((flMaxValue - stData.vectorFOV.at(y).flSpecUniform) /flMaxValue *static_cast<float>(ciIntiBarHeight));
// 			w	=	static_cast<int>(stData.vectorFOV.at(y).flSpecUniform /flMaxValue *static_cast<float>(ciIntiBarHeight)) + ciBackTop;
			lineSpec.setLine(rectImage.left(), w, rectImage.right(), w);
			painer.drawLine(lineSpec);

			rectImage.moveLeft(rectImage.left() + iBarWidth);
			rectImage.moveLeft(rectImage.left() + iBarWidth);
		}

		//draw spec text
/*
		rectText.setLeft(ciTotalWidth - (iBlockCount + iGroupCount +iGroupCount -1) *iBarWidth);
		rectText.setTop(imageBackgound.height() - ciBackBottom);
		rectText.setWidth(iBarWidth*5);
		rectText.setHeight(ciBackBottom);

		rectImage	=	rectText;
		rectImage.moveBottom(imageBackgound.height()-1);

		thePen.setColor(QColor::fromRgb(255,128, 0));
		painer.setPen(thePen);

		theFont.setPixelSize(iBarWidth *0.5);
		theFont.setBold(false);
		painer.setFont(theFont);

		for(int i=0;	i<iGroupCount;	++i){
			strText	=	QString::number(itemshareData.mtffaParameter->stcircleinfo.at(i).flspecvalue, 'f', 0) % \
				" | " %  QString::number(itemshareData.mtffaParameter->stcircleinfo.at(i).flspecunifom, 'f', 0);

			painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);

			rectText.moveLeft(rectText.left() + iBarWidth *6);
		}

		rectText.setWidth(iBarWidth);
		strText	=	QString::number(itemshareData.mtffaParameter->flcenterspecvalue, 'f', 2);
		painer.drawText(rectText, Qt::AlignHCenter|Qt::AlignVCenter|Qt::TextSingleLine|Qt::TextDontClip, strText);
*/

	}

	__inline void LpMFASaveLog(_HisCCMAlg_AFC_LP_DataItem& stData, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	_HISLOG_CLASSIFY_LPMFA;
		QString strKey1	=	"fa_lp_";
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(stData.ucStatus != 0)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype); 

		int iCenterX, iCenterY;
		for(unsigned int x=0;	x<stData.vectorFOV.size();	++x){
			iCenterX	=	iCenterY = 0;
			for(unsigned int i=0;	i<4;	++i){
				iCenterX	+=	stData.vectorFOV.at(x).stBlock[i].left;
				iCenterX	+=	stData.vectorFOV.at(x).stBlock[i].right;
				iCenterY	+=	stData.vectorFOV.at(x).stBlock[i].top;
				iCenterY	+=	stData.vectorFOV.at(x).stBlock[i].bottom;
			}

			iCenterX	=	(iCenterX >>2);
			iCenterY	=	(iCenterY >>2);

			for(unsigned int i=0;	i<4;	++i){
				logitem.itemkey	=	strKey1 % "f" % QString::number(stData.vectorFOV.at(x).flFOV, 'f', 3) % "_" % getBlockName(stData.vectorFOV.at(x).stBlock[i], iCenterX, iCenterY);
				logitem.itemvalue	=	stData.vectorFOV.at(x).stLpValue[i].flValue;
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey	=	strKey1 % "f" % QString::number(stData.vectorFOV.at(x).flFOV, 'f', 3) % "_u";
			logitem.itemvalue	=	stData.vectorFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void OSSaveLog(bool bPositiveRel, bool bNegtiveRel, bool bShortRel, bool bOhmRel, bool bOpenRel, _openshortParameter& stPara, HisFX3Log& classLog)
	{
		_HisLog_Item stLogItem;
		if(stPara.bTestPositive)
		{		
			stLogItem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_OPENGNDTEST);
			stLogItem.itemkey		=	"OS_Positive_Result";
			stLogItem.itemvalue	=	(bPositiveRel)?("OK"):("NG");
			classLog.push_back(stLogItem);

			for(unsigned int x=0;	x<stPara.vectorPositive.size(); ++x){
				if(stPara.vectorPositive.at(x).bTest) {
					++(stLogItem.itemtype);
					stLogItem.itemkey	=	((stPara.vectorPositive.at(x).bAGND)?("OS_Positive_"):("OS_Positive_")) % QString::fromAscii(stPara.vectorPositive.at(x).strName);
					stLogItem.itemvalue	=	stPara.vectorPositive.at(x).flVoltValue;
					classLog.push_back(stLogItem);
				}
			}
		}

		if(stPara.bTestNegtive)
		{
			stLogItem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_OPENDOVDDTEST);
			stLogItem.itemkey		=	"OS_Negtive_Result";
			stLogItem.itemvalue	=	(bNegtiveRel)?("OK"):("NG");
			classLog.push_back(stLogItem);

			for(unsigned int x=0;	x<stPara.vectorNegtive.size(); ++x){
				if(stPara.vectorNegtive.at(x).bTest) {
					++(stLogItem.itemtype);
					stLogItem.itemkey	=	"OS_Negtive_" % QString::fromAscii(stPara.vectorNegtive.at(x).strName);
					stLogItem.itemvalue	=	stPara.vectorNegtive.at(x).flVoltValue;
					classLog.push_back(stLogItem);
				}
			}
		}

		if(stPara.bTestShort)
		{
			stLogItem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SHORTTEST);
			stLogItem.itemkey		=	"OS_Short_Result";
			stLogItem.itemvalue	=	(bShortRel)?("OK"):("NG");
			classLog.push_back(stLogItem);
			QString strText;

			for(unsigned int x=0;	x<stPara.vectorShort.size(); ++x){
				if(stPara.vectorShort.at(x).bTest) {
					++(stLogItem.itemtype);
					stLogItem.itemkey	=	"OS_Short_" % QString::fromAscii(stPara.vectorShort.at(x).strName);
					strText	=	QString::number(stPara.vectorShort.at(x).flVoltValue);
					if(stPara.vectorShort.at(x).ucShortIndex)	strText = strText % "(" % QString::fromAscii(stPara.vectorShort.at(x).strShortName) % ")";
					stLogItem.itemvalue	=	strText;
					classLog.push_back(stLogItem);
				}
			}
		}

		if(stPara.bTestOhm)
		{
			stLogItem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_OHMTEST);
			stLogItem.itemkey		=	"OHM_Result";
			stLogItem.itemvalue	=	(bOhmRel)?("OK"):("NG");
			classLog.push_back(stLogItem);

			for(unsigned int x=0;	x<stPara.vectorOhm.size(); ++x){
				++(stLogItem.itemtype);
				stLogItem.itemkey		=	"Ohm_" % QString::fromAscii(stPara.vectorOhm.at(x).str1stName) % "-" % QString::fromAscii(stPara.vectorOhm.at(x).str2ndName);
				stLogItem.itemvalue	=	stPara.vectorOhm.at(x).flOhmValue;
				classLog.push_back(stLogItem);
			}
		}

		if(stPara.bTestOpen)
		{
			stLogItem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_OPENCIRCUITTEST);
			stLogItem.itemkey		=	"OS_Open_Result";
			stLogItem.itemvalue	=	(bOpenRel)?("OK"):("NG");
			classLog.push_back(stLogItem);
			QString strText;

			for(unsigned int x=0;	x<stPara.vectorOpen.size(); ++x)
			{
				if(stPara.vectorOpen.at(x).bTest) 
				{
					++(stLogItem.itemtype);
					stLogItem.itemkey	=	"OS_Open_" % QString::fromAscii(stPara.vectorOpen.at(x).strName);
					strText	=	QString::number(stPara.vectorOpen.at(x).flVoltValue);
					if(stPara.vectorOpen.at(x).ucOpenIndex)	strText = strText % "(" % QString::fromAscii(stPara.vectorOpen.at(x).strOpenName) % ")";
					stLogItem.itemvalue	=	strText;
					classLog.push_back(stLogItem);
				}
			}
		}
	}

	__inline int currentCal2DB(unsigned int* puiKey, _HisFX3_Current_Calibration* pstCal, unsigned int uiChannel = 1)
	{
		if(!HISDBROLONGO::isCustomCanOpen())
		{
			return HisCCMError_Database;
		}

		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		if(!HISDBROLONGO::isTableExist("currentoffset"))
		{
			HISDBROLONGO::createNewTable("[currentoffset]([md0] INTEGER,[md1] INTEGER,[md2] INTEGER, [md3] INTEGER, [iswork] INTEGER, [line] INTEGER, [volt] INTEGER, [offset] DOUBLE)");
		}

		bool bparsesuccess	=	true;

#define _currentCal2DB_SAVE2LOCALFILE

#ifdef _currentCal2DB_SAVE2LOCALFILE
		QString strFileName = "/hao_currentcalbration_C1.txt";
		if(uiChannel == 2) strFileName = "/hao_currentcalbration_C2.txt";
		QFile classFile(QDir::currentPath() % strFileName);
		classFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
	    QTextStream classStream(&classFile);
#endif

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			unsigned int uiWork	=	(uiChannel == 1)?(0x01):(0x01000001);
			unsigned int uiStanby	=	(uiChannel == 1)?(0x00):(0x01000000);

			QSqlQuery query(customdb);
			query.prepare("DELETE FROM currentoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3 AND iswork=:iswork");
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.bindValue(":iswork", uiWork);
			query.exec();

			query.prepare("DELETE FROM currentoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3 AND iswork=:iswork");
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.bindValue(":iswork", uiStanby);
			query.exec();

			customdb.transaction();

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "[work][AVDD]";
#endif

			//work  0-AVDD 1-DVDD 2-DOVDD 3-AF 4-OTP  5-POW
			//stanby  0-AVDD 1-DVDD 2-DOVDD 3-AF 4-POW
			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 0);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkAVDD[x]);
				query.exec();
#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkAVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[work][DVDD]";
#endif
			 
			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 1);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkDVDD[x]);
				query.exec();
#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkDVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[work][DOVDD]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 2);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkDOVDD[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkDOVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[work][AF]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 3);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkAF[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkAF[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[work][OTP]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 4);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkOTP[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkOTP[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[work][POW]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiWork);
				query.bindValue(":line", 5);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flWorkPOW[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flWorkPOW[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[stanby][AVDD]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiStanby);
				query.bindValue(":line", 0);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flStandbyAVDD[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flStandbyAVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[stanby][DVDD]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiStanby);
				query.bindValue(":line", 1);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flStandbyDVDD[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flStandbyDVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[stanby][DOVDD]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiStanby);
				query.bindValue(":line", 2);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flStandbyDOVDD[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flStandbyDOVDD[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[stanby][AF]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiStanby);
				query.bindValue(":line", 3);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flStandbyAF[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flStandbyAF[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n[stanby][POW]";
#endif

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO currentoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiStanby);
				query.bindValue(":line", 4);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flStandbyPOW[x]);
				query.exec();

#ifdef _currentCal2DB_SAVE2LOCALFILE
				classStream << pstCal->flStandbyPOW[x] << ",";
#endif
			}

#ifdef _currentCal2DB_SAVE2LOCALFILE
			classStream << "\n";
#endif

			customdb.commit();


			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int currentCalFromDB(unsigned int* puiKey, _HisFX3_Current_Calibration* pstCal, unsigned int uiChannel = 1)
	{
		bool bparsesuccess	=	true;
		unsigned int uiCount	=	0;

		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			//0-AVDD 1-DVDD 3-DOVDD 4-AF 5-OTP

			QSqlQuery query(customdb);
			query.prepare("SELECT iswork,line,volt,offset FROM currentoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3" );
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.exec();

			unsigned int iswork, line, volt;
			float offset;
			while (query.next())
			{
				iswork	=	query.value(0).toUInt();
				line		=	query.value(1).toUInt();
				volt		=	query.value(2).toUInt();
				offset	=	query.value(3).toDouble();

				if((uiChannel == 1) && (iswork & 0x01000000)) continue;
				else if((uiChannel != 1) && !(iswork & 0x01000000)) continue;

				iswork &=	0x00FFFFFF;

				if(iswork){
					switch (line){
					case 0:	pstCal->flWorkAVDD[volt]	=	offset;	break;
					case 1:	pstCal->flWorkDVDD[volt]	=	offset;	break;
					case 2:	pstCal->flWorkDOVDD[volt]	=	offset;	break;
					case 3:	pstCal->flWorkAF[volt]	=	offset;	break;
					case 4:	pstCal->flWorkOTP[volt]	=	offset;	break;
					case 5:
					default:		pstCal->flWorkPOW[volt]	=	offset;	break;
					}
				}
				else{
					switch (line){
					case 0:	pstCal->flStandbyAVDD[volt]	=	offset;	break;
					case 1:	pstCal->flStandbyDVDD[volt]	=	offset;	break;
					case 2:	pstCal->flStandbyDOVDD[volt]	=	offset;	break;
					case 3:	pstCal->flStandbyAF[volt]	=	offset;	break;
					case 4:
					default:		pstCal->flStandbyPOW[volt]	=	offset;	break;
					}
				}
				++uiCount;
			}


			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5) && \
			uiCount != _HisFX3V2_CURRENTCAL_COUNT *11)
			return HisFX3Error_Other;
		else if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R5X) && \
			uiCount != _HisFX3V2_CURRENTCAL_COUNT *11)
			return HisFX3Error_Other;
		else if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R3X) && \
			uiCount != _HisFX3V2_CURRENTCAL_COUNT *9)
			return HisFX3Error_Other;
		else if((classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R2R3) && \
			uiCount != _HisFX3V2_CURRENTCAL_COUNT *9)
			return HisFX3Error_Other;

		return 0;
	}

	__inline int voltageCal2DB(unsigned int* puiKey, _HisFX3_Voltage_Calibration* pstCal, unsigned int uiChannel = 1)
	{
		if(!HISDBROLONGO::isCustomCanOpen())
		{
			return HisCCMError_Database;
		}

		if(!HISDBROLONGO::isTableExist("voltageoffset"))
		{
			HISDBROLONGO::createNewTable("[voltageoffset]([md0] INTEGER,[md1] INTEGER,[md2] INTEGER, [md3] INTEGER, [iswork] INTEGER, [line] INTEGER, [volt] INTEGER, [offset] DOUBLE)");
		}

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QSqlQuery query(customdb);

#if (defined _HisFX3_Platform_MIPI_R4)
			query.prepare("DELETE FROM voltageoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3 AND iswork=:iswork");
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.bindValue(":iswork", uiChannel);
			query.exec();
#else
			query.prepare("DELETE FROM voltageoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3");
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.exec();
#endif

			customdb.transaction();

			//0-AVDD 1-DVDD 2-DOVDD 3-AF 4-OTP 5-POW
			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 0);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotAVDD[x]);
				query.exec();
			}

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 1);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotDVDD[x]);
				query.exec();
			}

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 2);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotDOVDD[x]);
				query.exec();
			}

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 3);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotAF[x]);
				query.exec();
			}

			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 4);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotOTP[x]);
				query.exec();
			}

#if (defined _HisFX3_Platform_MIPI_R4)
			for(unsigned int x=0;	x<_HisFX3V2_CURRENTCAL_COUNT;	++x){
				query.prepare("INSERT INTO voltageoffset(md0,md1,md2,md3,iswork,line,volt,offset) VALUES(:md0,:md1,:md2,:md3,:iswork,:line,:volt,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":iswork", uiChannel);
				query.bindValue(":line", 5);
				query.bindValue(":volt", x);
				query.bindValue(":offset", pstCal->flVlotPOW[x]);
				query.exec();
			}
#endif

			customdb.commit();
			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int voltageCalFromDB(unsigned int* puiKey, _HisFX3_Voltage_Calibration* pstCal, unsigned int uiChannel = 1)
	{
		if(!HISDBROLONGO::isCustomCanOpen())
		{
			return HisCCMError_Database;
		}

		if(!HISDBROLONGO::isTableExist("voltageoffset"))
		{
			return HisFX3Error_Other;
		}

		bool bparsesuccess	=	true;
		unsigned int uiCount	=	0;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			//0-AVDD 1-DVDD 2-DOVDD 3-AF 4-OTP 5-POW

			QSqlQuery query(customdb);

			query.prepare("SELECT iswork,line,volt,offset FROM voltageoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3" );
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.exec();

			unsigned int iswork, line, volt;
			float offset;
			while (query.next()){
				iswork	=	query.value(0).toUInt();
				line		=	query.value(1).toUInt();
				volt		=	query.value(2).toUInt();
				offset	=	query.value(3).toDouble();

				if(iswork == uiChannel){
					switch (line){
					case 0:	pstCal->flVlotAVDD[volt]	=	offset;	break;
					case 1:	pstCal->flVlotDVDD[volt]	=	offset;	break;
					case 2:	pstCal->flVlotDOVDD[volt]	=	offset;	break;
					case 3:	pstCal->flVlotAF[volt]	=	offset;	break;
					case 4:	pstCal->flVlotOTP[volt]	=	offset;	break;
					case 5:
					default:		pstCal->flVlotPOW[volt]	=	offset;	break;
					}
					++uiCount;
				}
				
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

#if (defined _HisFX3_Platform_MIPI_R4)
		if(uiCount != _HisFX3V2_CURRENTCAL_COUNT *6){
			return HisFX3Error_Other;
		}
#else
		if(uiCount != _HisFX3V2_CURRENTCAL_COUNT *5){
			return HisFX3Error_Other;
		}
#endif

		return 0;
	}

	__inline void SFRAMFACaculateResult(_HisCCMAlg_AFC_SFRHA_DataItem& stItemData, const float cflGradeAPercent, _SFRFACAParameter* pstParam)
	{

		stItemData.ucStatus			=	5;
		double dflCenterWeightValue = 0.0;
		float flMaxH, flMaxV, flMinH, flMinV;
		unsigned char ucStatus;

		if(stItemData.ucMethod == _His_SFR_Method_2Freq)
		{
			//center
			if(min(stItemData.stSFRCenterFreq1.flValueH_L, stItemData.stSFRCenterFreq1.flValueH_R) < stItemData.flCenter1stFreqSpecH || \
				min(stItemData.stSFRCenterFreq1.flValueV_B, stItemData.stSFRCenterFreq1.flValueV_T) < stItemData.flCenter1stFreqSpecV){
					ucStatus	=	0;
			}
			else if(min(stItemData.stSFRCenterFreq1.flValueH_L, stItemData.stSFRCenterFreq1.flValueH_R) < stItemData.flCenter1stFreqSpecH *cflGradeAPercent || \
				min(stItemData.stSFRCenterFreq1.flValueV_B, stItemData.stSFRCenterFreq1.flValueV_T) < stItemData.flCenter1stFreqSpecV *cflGradeAPercent){
					ucStatus	=	4;
			}
			else ucStatus	=	5;
			stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);

			if(stItemData.b2ndFreq){
				if(min(stItemData.stSFRCenterFreq2.flValueH_L, stItemData.stSFRCenterFreq2.flValueH_R) < stItemData.flCenter2ndFreqSpecH || \
					min(stItemData.stSFRCenterFreq2.flValueV_B, stItemData.stSFRCenterFreq2.flValueV_T) < stItemData.flCenter2ndFreqSpecV){
						ucStatus	=	0;
				}
				else if(min(stItemData.stSFRCenterFreq2.flValueH_L, stItemData.stSFRCenterFreq2.flValueH_R) < stItemData.flCenter2ndFreqSpecH *cflGradeAPercent || \
					min(stItemData.stSFRCenterFreq2.flValueV_B, stItemData.stSFRCenterFreq2.flValueV_T) < stItemData.flCenter2ndFreqSpecV *cflGradeAPercent){
						ucStatus	=	4;
				}
				else ucStatus = 5;
				stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);
			}

			dflCenterWeightValue	=	stItemData.stSFRCenterFreq1.flValueH_L + stItemData.stSFRCenterFreq1.flValueH_R;
			dflCenterWeightValue	*=	0.5;

			//fov
			for(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem_FOV>::iterator tempiterator = stItemData.vectorFOV.begin(); tempiterator != stItemData.vectorFOV.end(); tempiterator++)
			{
				tempiterator->ucStatus	=	0x1;
				flMaxH = flMaxV	=	-99999.9f;
				flMinH	=	flMinV	=	99999.9f;
				for(unsigned int y=0;	y<tempiterator->ucBlockCount;	++y){
					if(min(tempiterator->stSFRFreq1[y].flValueH_L, tempiterator->stSFRFreq1[y].flValueH_R) < tempiterator->fl1stFreqSpecH || \
						min(tempiterator->stSFRFreq1[y].flValueV_B, tempiterator->stSFRFreq1[y].flValueV_T) < tempiterator->fl1stFreqSpecV){
							tempiterator->ucStatus	=	0x0;
							ucStatus		=	0;
					}
					else if(min(tempiterator->stSFRFreq1[y].flValueH_L, tempiterator->stSFRFreq1[y].flValueH_R) < tempiterator->fl1stFreqSpecH *cflGradeAPercent || 
						min(tempiterator->stSFRFreq1[y].flValueV_B,tempiterator->stSFRFreq1[y].flValueV_T) < tempiterator->fl1stFreqSpecV *cflGradeAPercent){
							tempiterator->ucStatus	=	0x0;
							ucStatus		=	4;
					}
					else ucStatus	=	5;
					stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);
					if(tempiterator->stSFRFreq1[y].flValueH_R < 9000.0f){
						flMaxH	=	max(flMaxH, tempiterator->stSFRFreq1[y].flValueH_R);
						flMinH	=	min(flMinH, tempiterator->stSFRFreq1[y].flValueH_R);
					}
					if(tempiterator->stSFRFreq1[y].flValueH_L < 9000.0f){
						flMaxH	=	max(flMaxH, tempiterator->stSFRFreq1[y].flValueH_L);
						flMinH	=	min(flMinH, tempiterator->stSFRFreq1[y].flValueH_L);
					}
					if(tempiterator->stSFRFreq1[y].flValueV_T < 9000.0f){
						flMaxV	=	max(flMaxV, tempiterator->stSFRFreq1[y].flValueV_T);
						flMinV	=	min(flMinV, tempiterator->stSFRFreq1[y].flValueV_T);
					}
					if(tempiterator->stSFRFreq1[y].flValueV_B < 9000.0f){
						flMaxV	=	max(flMaxV, tempiterator->stSFRFreq1[y].flValueV_B);
						flMinV	=	min(flMinV, tempiterator->stSFRFreq1[y].flValueV_B);
					}
				}

				tempiterator->flFreq1UnifH	=	flMaxH - flMinH;
				tempiterator->flFreq1UnifV	=	flMaxV - flMinV;
				if(tempiterator->flFreq1UnifH > tempiterator->fl1stFreqSpecUnifH || tempiterator->flFreq1UnifV > tempiterator->fl1stFreqSpecUnifV){
					tempiterator->ucStatus	=	0x0;
					stItemData.ucStatus		=	0x0;
				}

				if(stItemData.b2ndFreq){
					flMaxH = flMaxV	=	-99999.9f;
					flMinH	=	flMinV	=	99999.9f;
					for(unsigned int y=0;	y<tempiterator->ucBlockCount;	++y){
						if(min(tempiterator->stSFRFreq2[y].flValueH_L, tempiterator->stSFRFreq2[y].flValueH_R) < tempiterator->fl2ndFreqSpecH || \
							min(tempiterator->stSFRFreq2[y].flValueV_B, tempiterator->stSFRFreq2[y].flValueV_T) < tempiterator->fl2ndFreqSpecV){
								tempiterator->ucStatus	=	0x0;
								ucStatus		=	0;
						}
						else if(min(tempiterator->stSFRFreq2[y].flValueH_L, tempiterator->stSFRFreq2[y].flValueH_R) < tempiterator->fl2ndFreqSpecH *cflGradeAPercent || \
							min(tempiterator->stSFRFreq2[y].flValueV_B, tempiterator->stSFRFreq2[y].flValueV_T) < tempiterator->fl2ndFreqSpecV *cflGradeAPercent){
								tempiterator->ucStatus	=	0x0;
								ucStatus		=	4;
						}
						else ucStatus = 5;
						stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);
						if(tempiterator->stSFRFreq2[y].flValueH_R < 9000.0f){
							flMaxH	=	max(flMaxH, tempiterator->stSFRFreq2[y].flValueH_R);
							flMinH	=	min(flMinH, tempiterator->stSFRFreq2[y].flValueH_R);
						}
						if(tempiterator->stSFRFreq2[y].flValueH_L < 9000.0f){
							flMaxH	=	max(flMaxH, tempiterator->stSFRFreq2[y].flValueH_L);
							flMinH	=	min(flMinH, tempiterator->stSFRFreq2[y].flValueH_L);
						}
						if(tempiterator->stSFRFreq2[y].flValueV_T < 9000.0f){
							flMaxV	=	max(flMaxV, tempiterator->stSFRFreq2[y].flValueV_T);
							flMinV	=	min(flMinV, tempiterator->stSFRFreq2[y].flValueV_T);
						}
						if(tempiterator->stSFRFreq2[y].flValueV_B < 9000.0f){
							flMaxV	=	max(flMaxV, tempiterator->stSFRFreq2[y].flValueV_B);
							flMinV	=	min(flMinV, tempiterator->stSFRFreq2[y].flValueV_B);
						}
					}

					tempiterator->flFreq2UnifH	=	flMaxH - flMinH;
					tempiterator->flFreq2UnifV	=	flMaxV - flMinV;
					if(tempiterator->flFreq2UnifH > tempiterator->fl2ndFreqSpecUnifH || tempiterator->flFreq2UnifV > tempiterator->fl2ndFreqSpecUnifV){
						tempiterator->ucStatus	=	0x0;
						stItemData.ucStatus		=	0x0;
					}
				}
			}

			stItemData.flWeightValue = dflCenterWeightValue;
		}
		else{ //MTF50
			//center
			if(min(stItemData.stSFRCenterMTF50.flValueH_L, stItemData.stSFRCenterMTF50.flValueH_R) < stItemData.flCenterMTF50SpecH || \
				min(stItemData.stSFRCenterMTF50.flValueV_B, stItemData.stSFRCenterMTF50.flValueV_T) < stItemData.flCenterMTF50SpecV){
					ucStatus	=	0;
			}
			else if(min(stItemData.stSFRCenterMTF50.flValueH_L, stItemData.stSFRCenterMTF50.flValueH_R) < stItemData.flCenterMTF50SpecH *cflGradeAPercent || \
				min(stItemData.stSFRCenterMTF50.flValueV_B, stItemData.stSFRCenterMTF50.flValueV_T) < stItemData.flCenterMTF50SpecV *cflGradeAPercent){
					ucStatus	=	4;
			}
			else ucStatus	=	5;
			stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);

			dflCenterWeightValue	=	stItemData.stSFRCenterMTF50.flValueH_L + stItemData.stSFRCenterMTF50.flValueH_R;
			dflCenterWeightValue	*=	0.5;

			//fov
			for(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem_FOV>::iterator tempiterator = stItemData.vectorFOV.begin(); tempiterator != stItemData.vectorFOV.end(); tempiterator++){
				tempiterator->ucStatus	=	0x1;
				flMaxH = flMaxV	=	-99999.9f;
				flMinH	=	flMinV	=	99999.9f;
				for(unsigned int y=0;	y<tempiterator->ucBlockCount;	++y){
					if(min(tempiterator->stSFRMTF50[y].flValueH_L, tempiterator->stSFRMTF50[y].flValueH_R) < tempiterator->flMTF50SpecH || \
						min(tempiterator->stSFRMTF50[y].flValueV_B, tempiterator->stSFRMTF50[y].flValueV_T) < tempiterator->flMTF50SpecV){
							tempiterator->ucStatus	=	0x0;
							ucStatus		=	0;
					}
					else if(min(tempiterator->stSFRMTF50[y].flValueH_L, tempiterator->stSFRMTF50[y].flValueH_R) < tempiterator->flMTF50SpecH *cflGradeAPercent || \
						min(tempiterator->stSFRMTF50[y].flValueV_B, tempiterator->stSFRMTF50[y].flValueV_T) < tempiterator->flMTF50SpecV *cflGradeAPercent){
							tempiterator->ucStatus	=	0x0;
							ucStatus		=	4;
					}
					else ucStatus = 5;
					stItemData.ucStatus	=	min(stItemData.ucStatus, ucStatus);
					if(tempiterator->stSFRMTF50[y].flValueH_R < 9000.0f){
						flMaxH	=	max(flMaxH, tempiterator->stSFRMTF50[y].flValueH_R);
						flMinH	=	min(flMinH, tempiterator->stSFRMTF50[y].flValueH_R);
					}
					if(tempiterator->stSFRMTF50[y].flValueH_L < 9000.0f){
						flMaxH	=	max(flMaxH, tempiterator->stSFRMTF50[y].flValueH_L);
						flMinH	=	min(flMinH, tempiterator->stSFRMTF50[y].flValueH_L);
					}
					if(tempiterator->stSFRMTF50[y].flValueV_T < 9000.0f){
						flMaxV	=	max(flMaxV, tempiterator->stSFRMTF50[y].flValueV_T);
						flMinV	=	min(flMinV, tempiterator->stSFRMTF50[y].flValueV_T);
					}
					if(tempiterator->stSFRMTF50[y].flValueV_B < 9000.0f){
						flMaxV	=	max(flMaxV, tempiterator->stSFRMTF50[y].flValueV_B);
						flMinV	=	min(flMinV, tempiterator->stSFRMTF50[y].flValueV_B);
					}
				}

				tempiterator->flMTF50UnifH	=	flMaxH - flMinH;
				tempiterator->flMTF50UnifV	=	flMaxV - flMinV;
				if(tempiterator->flMTF50UnifH > tempiterator->flMTF50SpecUnifH || tempiterator->flMTF50UnifV > tempiterator->flMTF50SpecUnifV){
					tempiterator->ucStatus	=	0x0;
					stItemData.ucStatus		=	0x0;
				}
			}

			stItemData.flWeightValue = dflCenterWeightValue;
		}

	}

	__inline void saveSHRHAMFAResult(_HisCCMAlg_AFC_SFRHA_DataItem& stItemData, _SFRFACAParameter* pstParameter, HisFX3Log& classLog, int iWidth ,int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "mfa_sfra_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_SFRFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(stItemData.ucStatus != 0)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq)
		{
			strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x)
			{
				strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_fov" % QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i)
				{
					if(stItemData.vectorFOV.at(x).stBlock[i].stLeft.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(x).stBlock[i].stRight.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stRight, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(x).stBlock[i].stTop.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stTop, iWidth, iHeight);
					else
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stBottom, iWidth, iHeight);

					if(stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueH_L < 9000.0f){
						logitem.itemkey		=	strKey3 % "_left";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueH_L;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueH_R < 9000.0f){
						logitem.itemkey		=	strKey3 % "_right";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueH_R;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueV_T < 9000.0f){
						logitem.itemkey		=	strKey3 % "_top";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueV_T;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueV_B < 9000.0f){
						logitem.itemkey		=	strKey3 % "_bottom";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq1[i].flValueV_B;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}
				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq){
				strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_";

				logitem.itemkey		=	strKey2 % "center_left";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueH_L;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_right";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueH_R;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_top";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueV_T;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_bottom";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueV_B;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x){
					strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_fov" % QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "_";

					for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
						if(stItemData.vectorFOV.at(x).stBlock[i].stLeft.bottom)
							strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight);
						else if(stItemData.vectorFOV.at(x).stBlock[i].stRight.bottom)
							strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stRight, iWidth, iHeight);
						else if(stItemData.vectorFOV.at(x).stBlock[i].stTop.bottom)
							strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stTop, iWidth, iHeight);
						else
							strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stBottom, iWidth, iHeight);

						if(stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueH_L < 9000.0f){
							logitem.itemkey		=	strKey3 % "_left";
							logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueH_L;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueH_R < 9000.0f){
							logitem.itemkey		=	strKey3 % "_right";
							logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueH_R;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueV_T < 9000.0f){
							logitem.itemkey		=	strKey3 % "_top";
							logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueV_T;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueV_B < 9000.0f){
							logitem.itemkey		=	strKey3 % "_bottom";
							logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRFreq2[i].flValueV_B;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

					}
				}
			}
		}
		else{
			strKey2		=	strKey1 % "mtf50_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x){
				strKey2		=	strKey1 % "mtf50_fov" % QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
					if(stItemData.vectorFOV.at(x).stBlock[i].stLeft.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(x).stBlock[i].stRight.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stRight, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(x).stBlock[i].stTop.bottom)
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stTop, iWidth, iHeight);
					else						
						strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i].stBottom, iWidth, iHeight);

					if(stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueH_L < 9000.0f){
						logitem.itemkey		=	strKey3 % "_left";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueH_L;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueH_R < 9000.0f){
						logitem.itemkey		=	strKey3 % "_right";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueH_R;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueV_T < 9000.0f){
						logitem.itemkey		=	strKey3 % "_top";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueV_T;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueV_B < 9000.0f){
						logitem.itemkey		=	strKey3 % "_bottom";
						logitem.itemvalue	=	stItemData.vectorFOV.at(x).stSFRMTF50[i].flValueV_B;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

				}
			}
		}
	}

	__inline float GetSFRFreqValue(double* pdflCurve, int iLength, int iFreq)
	{
		double dflIndex	=	(double)(iLength-1) /(double)(iFreq);
		int iLowIndex	=	(int)(dflIndex);
		return (float)(pdflCurve[iLowIndex] + (pdflCurve[iLowIndex+1] - pdflCurve[iLowIndex]) * (dflIndex-iLowIndex));
// 		return pdflCurve[iLength /iFreq];
	}

	__inline int AFCSFRHAFromDB(unsigned char uctype, _SFRAFCCAParameter* pstPara, _HisCCMAlg_AFC_SFRHA_DB* pDB, bool bChannel1)
	{
		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		pDB->initial();
		pDB->pstTacticsBasic	=	new _HisCCMAlg_AFC_Tactics_Basic;
		pDB->pstSFRBasic		=	new _HisCCMAlg_SFRPlusHABasic_Info;
		if(!(pDB->pstSFRBasic && pDB->pstTacticsBasic)){
			pDB->initial();
			return HisFX3Error_MallocBuffer;
		}

		*(pDB->pstTacticsBasic)	=	pstPara->stTacticsBasic;
		*(pDB->pstSFRBasic)		=	pstPara->stSFRBasic;
		pDB->vectorSFRItem.assign(pstPara->vectorSFRItem.begin(), pstPara->vectorSFRItem.end());

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT bins1,bins2,bins3,bins1byte,bins2byte,bins3byte,ints1,ints2,ints3 FROM tablemanage WHERE tablename='" % strTableName % "'");
			query.exec();

			QByteArray bins1,bins2,bins3;
			unsigned int bins1byte=0,bins2byte=0,bins3byte=0, ints1=0, ints2 = 0, ints3 = 0;
			while (query.next()){
				bins1 = query.value(0).toByteArray();
				bins2 = query.value(1).toByteArray();
				bins3 = query.value(2).toByteArray();
				bins1byte	=	query.value(3).toUInt();
				bins2byte	=	query.value(4).toUInt();
				bins3byte	=	query.value(5).toUInt();
				ints1			=	query.value(6).toUInt();
				ints2			=	query.value(7).toUInt();
				ints3			=	query.value(8).toUInt();
			}

			QByteArray Sbins1	=	TacticsBasicSerialize(*pDB->pstTacticsBasic);
			QByteArray Sbins2	=	SFRHABasicSerialize(*pDB->pstSFRBasic);
			QByteArray Sbins3	=	SFRHAItemSerialize(pDB->vectorSFRItem);
			unsigned int Sbins1byte	=	Sbins1.size();
			unsigned int Sbins2byte	=	Sbins2.size();
			unsigned int Sbins3byte	=	Sbins3.size();
			unsigned int Sints1			=	pDB->vectorSFRItem.size();
			unsigned int Sints2			=	20; //SFR Chart-A
			unsigned int Sints3			=	(bChannel1)?(1):(2);

			bool bupdate = false;
			if(Sbins1byte != bins1byte || Sbins2byte != bins2byte || Sbins3byte != bins3byte || Sints1 != ints1 || Sints2 != ints2 || Sints3 != ints3)
				bupdate	=	true;
			if(!bupdate){
				if(!isEqual(bins1, Sbins1)) bupdate = true;
				if(!isEqual(bins2, Sbins2)) bupdate = true;
				if(!isEqual(bins3, Sbins3)) bupdate = true;
			}

			if(bupdate){
				query.prepare("UPDATE tablemanage SET bins1=:bins1,bins2=:bins2,bins3=:bins3,bins1byte=:bins1byte,bins2byte=:bins2byte,bins3byte=:bins3byte,ints1=:ints1,ints2=:ints2,ints3=:ints3 WHERE tablename='" % strTableName % "'");
				query.bindValue(":bins1", Sbins1);
				query.bindValue(":bins2", Sbins2);
				query.bindValue(":bins3", Sbins3);
				query.bindValue(":bins1byte", Sbins1byte);
				query.bindValue(":bins2byte", Sbins2byte);
				query.bindValue(":bins3byte", Sbins3byte);
				query.bindValue(":ints1", Sints1);
				query.bindValue(":ints2", Sints2);
				query.bindValue(":ints3", Sints3);
				query.exec();
			
				query.prepare("DELETE FROM " % strTableName);
				query.exec();
			}
			else
			{
				query.prepare("SELECT id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend FROM " % strTableName %  "  ORDER BY id ASC" );
				query.exec();
				unsigned int uiDataSize	=	2;
				for(int x=0;	x<pstPara->vectorSFRItem.size(); ++x){
					uiDataSize = uiDataSize + (pstPara->vectorSFRItem.at(x).ucBlockCount <<1);
				}

				_HisCCMAlg_AFC_SFRHA_DB_Item stNewItem;
				stNewItem.vecValueStart.resize(uiDataSize);
				stNewItem.vecValueEnd.resize(uiDataSize);
				QByteArray valuestart, valueend;

				while (query.next())
				{
					stNewItem.ui64ID				=	query.value(0).toULongLong();
					stNewItem.sMotorStart		=	query.value(1).toInt();
					stNewItem.flMarkDisStart	=	query.value(2).toFloat();
					stNewItem.sMotorEnd			=	query.value(5).toInt();
					stNewItem.flMarkDisEnd		=	query.value(6).toFloat();
					valuestart								=	query.value(4).toByteArray();
					valueend								=	query.value(8).toByteArray();

					QDataStream streamstart(valuestart);
					streamstart.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamstart >> stNewItem.vecValueStart.at(x);
					}

					QDataStream streamend(valueend);
					streamend.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamend >> stNewItem.vecValueEnd.at(x);
					}

					pDB->ui64IDMax	=	max(pDB->ui64IDMax, stNewItem.ui64ID);
					pDB->vectorItem.push_back(stNewItem);
				}
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			pDB->initial();
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int AFCSFRHAToDB(unsigned char uctype, _SFRAFCCAParameter* pstPara, _HisCCMAlg_AFC_SFRHA_DB* pDB, \
		std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorDataItem, unsigned int uiIndex, bool bChannel1)
	{
		if(uiIndex == 0) return 0;
		if(vectorDataItem.at(uiIndex).ucStatus == 0x0) return 0;

		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		_HisCCMAlg_AFC_SFRHA_DB_Item stNewItem;
		stNewItem.flMarkDisStart	=	vectorDataItem.at(0).dflMarkDistance;
		stNewItem.sMotorStart		=	vectorDataItem.at(0).sMotorStep;
		stNewItem.ui64ID				=	pDB->ui64IDMax +1;
		stNewItem.flMarkDisEnd		=	vectorDataItem.at(uiIndex).dflMarkDistance;
		stNewItem.sMotorEnd			=	vectorDataItem.at(uiIndex).sMotorStep;

		unsigned int uiTotalBlock	=	1;
		for(unsigned int y=0;	y<pstPara->vectorSFRItem.size(); ++y)
			uiTotalBlock	+=	pstPara->vectorSFRItem.at(y).ucBlockCount;

		stNewItem.vecValueStart.resize((uiTotalBlock <<1));
		stNewItem.vecValueEnd.resize((uiTotalBlock <<1));

		unsigned int uitempi	=	0;
		if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
			stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).stSFRCenterFreq1.flValueH_L;
			stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterFreq1.flValueH_L;
			++uitempi;
			stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).stSFRCenterFreq1.flValueH_R;
			stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterFreq1.flValueH_R;
			++uitempi;

			for(unsigned int y=0;	y<pstPara->vectorSFRItem.size(); ++y){
				for(unsigned int x=0;	x<pstPara->vectorSFRItem.at(y).ucBlockCount;	++x){
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).stSFRFreq1[x].flValueH_L;
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).stSFRFreq1[x].flValueH_L;
					++uitempi;
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).stSFRFreq1[x].flValueH_R;
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).stSFRFreq1[x].flValueH_R;
					++uitempi;
				}
			}
		}
		else{
			stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).stSFRCenterMTF50.flValueH_L;
			stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterMTF50.flValueH_L;
			++uitempi;
			stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).stSFRCenterMTF50.flValueH_R;
			stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterMTF50.flValueH_R;
			++uitempi;

			for(unsigned int y=0;	y<pstPara->vectorSFRItem.size(); ++y){
				for(unsigned int x=0;	x<pstPara->vectorSFRItem.at(y).ucBlockCount;	++x){
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).stSFRMTF50[x].flValueH_L;
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).stSFRMTF50[x].flValueH_L;
					++uitempi;
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).stSFRMTF50[x].flValueH_R;
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).stSFRMTF50[x].flValueH_R;
					++uitempi;
				}
			}
		}

		++(pDB->ui64IDMax);

		bool bReplace = false;
		unsigned int uiReplaceID	=	0;
		if(vectorDataItem.size() >= pDB->usConstMaxItem){
			unsigned __int64 uiMinID	=	0xFFFFFFFFFFFFFFFF;
			for(unsigned int x=0;	x<pDB->vectorItem.size(); ++x){
				if(pDB->vectorItem.at(x).ui64ID < uiMinID){
					uiMinID	=	pDB->vectorItem.at(x).ui64ID;
					uiReplaceID	=	x;
				}
			}

			bReplace = true;
			pDB->vectorItem.erase(pDB->vectorItem.begin() + uiReplaceID);		
		}
		
		pDB->vectorItem.push_back(stNewItem);

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);

			if(bReplace){
				query.prepare("DELETE FROM " % strTableName %  " WHERE id=:id");
				query.bindValue(":id", uiReplaceID);
				query.exec();
			}

			QByteArray valuestart, valueend;

			QDataStream streamstart(&valuestart, QIODevice::WriteOnly);
			streamstart.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueStart.size(); ++x){
				streamstart << stNewItem.vecValueStart.at(x);
			}

			QDataStream streamend(&valueend, QIODevice::WriteOnly);
			streamend.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueEnd.size(); ++x){
				streamend << stNewItem.vecValueEnd.at(x);
			}

			query.prepare("INSERT INTO " % strTableName %  "(id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend) VALUES(:id,:motorstart,:disstart,:reserves1,:valuestart,:motorend,:disend,:reservee1,:valueend)");		
			query.bindValue(":id", stNewItem.ui64ID);
			query.bindValue(":motorstart", stNewItem.sMotorStart);
			query.bindValue(":disstart", stNewItem.flMarkDisStart);
			query.bindValue(":reserves1", 0.0);
			query.bindValue(":valuestart", valuestart);
			query.bindValue(":motorend", stNewItem.sMotorEnd);
			query.bindValue(":disend", stNewItem.flMarkDisEnd);
			query.bindValue(":reservee1", 0.0);
			query.bindValue(":valueend", valueend);
			query.exec();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}


	__inline void AddDrawSFRHA(_SFRBlackROI4& stROI, _HisCCMAlg_SFRPlusHA_Block_Result& stMTF50, \
		_HisCCMAlg_SFRPlusHA_Block_Result& stFreq1, _HisCCMAlg_SFRPlusHA_Block_Result& stFreq2,  \
		_SFRAFCCAParameter* pstPara, unsigned int uiFOVIndex, std::vector<_itemDraw>& itemdrawList)
	{
		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift		=	120;
		const int ciHeightShift	=	50;
		float flSpecH50, flSpecV50, flSpecH1, flSpecV1, flSpecH2, flSpecV2;
		if(uiFOVIndex == 0xFFFFFFFF){
			flSpecH50	=	pstPara->stSFRBasic.flCenterMTF50SpecH;
			flSpecV50	=	pstPara->stSFRBasic.flCenterMTF50SpecV;
			flSpecH1		=	pstPara->stSFRBasic.flCenter1stFreqSpecH;
			flSpecV1		=	pstPara->stSFRBasic.flCenter1stFreqSpecV;
			flSpecH2		=	pstPara->stSFRBasic.flCenter2ndFreqSpecH;
			flSpecV2		=	pstPara->stSFRBasic.flCenter2ndFreqSpecV;
		}
		else{
			flSpecH50	=	pstPara->vectorSFRItem.at(uiFOVIndex).flMTF50SpecH;
			flSpecV50	=	pstPara->vectorSFRItem.at(uiFOVIndex).flMTF50SpecV;
			flSpecH1		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl1stFreqSpecH;
			flSpecV1		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl1stFreqSpecV;
			flSpecH2		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl2ndFreqSpecH;
			flSpecV2		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl2ndFreqSpecV;
		}

		_itemDraw stItem;

		if(stROI.stLeft.bottom)
		{
			//left
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stLeft;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
				stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift;
				stItem.stcolor	=	(stFreq1.flValueH_L < flSpecH1)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueH_L);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
					stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift + ciHeightShift;
					stItem.stcolor	=	(stFreq2.flValueH_L < flSpecH2)?(stRed):(stGreen);
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueH_L);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
				stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift;
				stItem.stcolor	=	(stMTF50.flValueH_L < flSpecH50)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueH_L);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stRight.bottom)
		{
			//right
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stRight;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stRight.right;
				stItem.idata[1]	=	stROI.stRight.top + ciHeightShift;
				stItem.stcolor	=	(stFreq1.flValueH_R < flSpecH1)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueH_R);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stRight.right;
					stItem.idata[1]	=	stROI.stRight.top + ciHeightShift + ciHeightShift;
					stItem.stcolor	=	(stFreq2.flValueH_R < flSpecH2)?(stRed):(stGreen);
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueH_R);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stRight.right;
				stItem.idata[1]	=	stROI.stRight.top + ciHeightShift;
				stItem.stcolor	=	(stMTF50.flValueH_R < flSpecH50)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueH_R);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stTop.bottom)
		{
			//top
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stTop;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stTop.left;
				stItem.idata[1]	=	stROI.stTop.top -ciHeightShift;
				stItem.stcolor	=	(stFreq1.flValueV_T < flSpecV1)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueV_T);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stTop.left;
					stItem.idata[1]	=	stROI.stTop.top;
					stItem.stcolor	=	(stFreq2.flValueV_T < flSpecV2)?(stRed):(stGreen);
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueV_T);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stTop.left;
				stItem.idata[1]	=	stROI.stTop.top ;
				stItem.stcolor	=	(stMTF50.flValueV_T < flSpecV50)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueV_T);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stBottom.bottom)
		{
			//bottom
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stBottom;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stBottom.left;
				stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift;
				stItem.stcolor	=	(stFreq1.flValueV_B < flSpecV1)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueV_B);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stBottom.left;
					stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift + ciHeightShift;
					stItem.stcolor	=	(stFreq2.flValueV_B < flSpecV2)?(stRed):(stGreen);
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueV_B);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stBottom.left;
				stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift;
				stItem.stcolor	=	(stMTF50.flValueV_B < flSpecV50)?(stRed):(stGreen);
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueV_B);
				itemdrawList.push_back(stItem);
			}
		}
		
	}

	__inline void AddDrawSFRHAMFA(_SFRBlackROI4& stROI, _HisCCMAlg_SFRPlusHA_Block_Result& stMTF50, \
		_HisCCMAlg_SFRPlusHA_Block_Result& stFreq1, _HisCCMAlg_SFRPlusHA_Block_Result& stFreq2,  \
		_SFRFACAParameter* pstPara, unsigned int uiFOVIndex, std::vector<_itemDraw>& itemdrawList, const float cflGradeAPercent)
	{

		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift		=	120;
		const int ciHeightShift	=	50;
		float flSpecH50, flSpecV50, flSpecH1, flSpecV1, flSpecH2, flSpecV2;
		if(uiFOVIndex == 0xFFFFFFFF){
			flSpecH50	=	pstPara->stSFRBasic.flCenterMTF50SpecH;
			flSpecV50	=	pstPara->stSFRBasic.flCenterMTF50SpecV;
			flSpecH1		=	pstPara->stSFRBasic.flCenter1stFreqSpecH;
			flSpecV1		=	pstPara->stSFRBasic.flCenter1stFreqSpecV;
			flSpecH2		=	pstPara->stSFRBasic.flCenter2ndFreqSpecH;
			flSpecV2		=	pstPara->stSFRBasic.flCenter2ndFreqSpecV;
		}
		else{
			flSpecH50	=	pstPara->vectorSFRItem.at(uiFOVIndex).flMTF50SpecH;
			flSpecV50	=	pstPara->vectorSFRItem.at(uiFOVIndex).flMTF50SpecV;
			flSpecH1		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl1stFreqSpecH;
			flSpecV1		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl1stFreqSpecV;
			flSpecH2		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl2ndFreqSpecH;
			flSpecV2		=	pstPara->vectorSFRItem.at(uiFOVIndex).fl2ndFreqSpecV;
		}

		_itemDraw stItem;

		if(stROI.stLeft.bottom)
		{
			//left
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stLeft;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
				stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift;
				if(stFreq1.flValueH_L >= flSpecH1 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stFreq1.flValueH_L >= flSpecH1)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueH_L);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
					stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift + ciHeightShift;
					if(stFreq2.flValueH_L >= flSpecH2 *cflGradeAPercent)	stItem.stcolor = stGreen;
					else if(stFreq2.flValueH_L >= flSpecH2)	stItem.stcolor = stYellow;
					else stItem.stcolor = stRed;
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueH_L);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stLeft.left - ciLeftShift;
				stItem.idata[1]	=	stROI.stLeft.top + ciHeightShift;
				if(stMTF50.flValueH_L >= flSpecH50 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stMTF50.flValueH_L >= flSpecH50)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueH_L);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stRight.bottom)
		{
			//right
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stRight;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stRight.right;
				stItem.idata[1]	=	stROI.stRight.top + ciHeightShift;
				if(stFreq1.flValueH_R >= flSpecH1 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stFreq1.flValueH_R >= flSpecH1)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueH_R);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stRight.right;
					stItem.idata[1]	=	stROI.stRight.top + ciHeightShift + ciHeightShift;
					if(stFreq2.flValueH_R >= flSpecH2 *cflGradeAPercent)	stItem.stcolor = stGreen;
					else if(stFreq2.flValueH_R >= flSpecH2)	stItem.stcolor = stYellow;
					else stItem.stcolor = stRed;
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueH_R);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stRight.right;
				stItem.idata[1]	=	stROI.stRight.top + ciHeightShift;
				if(stMTF50.flValueH_R >= flSpecH50 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stMTF50.flValueH_R >= flSpecH50)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueH_R);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stTop.bottom)
		{
			//top
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stTop;
			stItem.stcolor	=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stTop.left;
				stItem.idata[1]	=	stROI.stTop.top -ciHeightShift;
				if(stFreq1.flValueV_T >= flSpecV1 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stFreq1.flValueV_T >= flSpecV1)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueV_T);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stTop.left;
					stItem.idata[1]	=	stROI.stTop.top;
					if(stFreq2.flValueV_T >= flSpecV2 *cflGradeAPercent)	stItem.stcolor = stGreen;
					else if(stFreq2.flValueV_T >= flSpecV2)	stItem.stcolor = stYellow;
					else stItem.stcolor = stRed;
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueV_T);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stTop.left;
				stItem.idata[1]	=	stROI.stTop.top ;
				if(stMTF50.flValueV_T >= flSpecV50 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stMTF50.flValueV_T >= flSpecV50)stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueV_T);
				itemdrawList.push_back(stItem);
			}
		}
		
		if(stROI.stBottom.bottom)
		{
			//bottom
			stItem.uctype	=	HisDrawType_Block;
			stItem.strinfo.stblock	=	stROI.stBottom;
			stItem.stcolor				=	stBlack;
			itemdrawList.push_back(stItem);

			if(pstPara->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stBottom.left;
				stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift;
				if(stFreq1.flValueV_B >= flSpecV1 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stFreq1.flValueV_B >= flSpecV1) 	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stFreq1.flValueV_B);
				itemdrawList.push_back(stItem);

				if(pstPara->stSFRBasic.b2ndFreq){
					stItem.uctype	=	HisDrawType_Text;
					stItem.idata[0]	=	stROI.stBottom.left;
					stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift + ciHeightShift;
					if(stFreq2.flValueV_B >= flSpecV2 *cflGradeAPercent)	stItem.stcolor = stGreen;
					else if(stFreq2.flValueV_B >= flSpecV2)	stItem.stcolor = stYellow;
					else stItem.stcolor = stRed;
					sprintf(stItem.strinfo.strtext, "%.3f", stFreq2.flValueV_B);
					itemdrawList.push_back(stItem);
				}
			}
			else{
				stItem.uctype	=	HisDrawType_Text;
				stItem.idata[0]	=	stROI.stBottom.left;
				stItem.idata[1]	=	stROI.stBottom.bottom + ciHeightShift;
				if(stMTF50.flValueV_B >= flSpecV50 *cflGradeAPercent)	stItem.stcolor = stGreen;
				else if(stMTF50.flValueV_B >= flSpecV50)	stItem.stcolor = stYellow;
				else stItem.stcolor = stRed;
				sprintf(stItem.strinfo.strtext, "%.3f", stMTF50.flValueV_B);
				itemdrawList.push_back(stItem);
			}
		}	

	}

	__inline int UpdateOtpBurnParameter(QString strTableName, QStringList& strname, QStringList& strvalue)
	{
		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT itemsuffix2,key,value,reserve FROM " % strTableName % " WHERE classfy='sensor' AND item='otpburn'");
			query.exec();

			QString itemtext[4];
			bool bExist = false;
			QStringList strN1, strV1;
			while (query.next()){
				bExist	=	true;
				for(unsigned int x=0;	x<4;	++x){
					itemtext[x]	=	query.value(x).toString();
					if(itemtext[x].size() > 1){
						patchconfigstring(itemtext[x], strN1, strV1);
						for(unsigned int i=0;	i<strN1.size();	++i){
							for(unsigned int w=0;	w<strname.size();	++w){
								if(strN1.at(i) == strname.at(w)){
									strV1.replace(i, strvalue.at(w));
								}
							}
						}

						jointconfigstring(itemtext[x], strN1, strV1);
					}				
				}
			}

			if(bExist){
				query.prepare("UPDATE " % strTableName % " SET itemsuffix2=:itemsuffix2,key=:key,value=:value,reserve=:reserve WHERE classfy='sensor' AND item='otpburn'");
				query.bindValue(":itemsuffix2", itemtext[0]);
				query.bindValue(":key", itemtext[1]);
				query.bindValue(":value", itemtext[2]);
				query.bindValue(":reserve", itemtext[3]);
				query.exec();
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querycustom");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline void saveSHRHAAFCResult(unsigned int uiType, bool bResult, unsigned int uiIndex, std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorDataItem, \
		_SFRAFCCAParameter* pstParameter, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		if(vectorDataItem.empty()) return;
		_HisLog_Item logitem;
		QString strKey1;
		if(uiType == 1) {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SFRFCMIDDLE);
			strKey1	=	"afc_sfra_middle_";
		}
		else if(uiType == 2)	{
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SFRFCFAR);
			strKey1	=	"afc_sfra_far_";
		}
		else {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_SFRFCNEAR);
			strKey1	=	"afc_sfra_near_";
		}

		std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>::iterator iteratorsave	=	vectorDataItem.begin() + uiIndex;

		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
			strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	iteratorsave->stSFRCenterFreq1.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	iteratorsave->stSFRCenterFreq1.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	iteratorsave->stSFRCenterFreq1.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	iteratorsave->stSFRCenterFreq1.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<iteratorsave->vectorFOV.size(); ++x){
				strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_fov" % QString::number(iteratorsave->vectorFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<iteratorsave->vectorFOV.at(x).ucBlockCount;	++i){
					if(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft, iWidth ,iHeight);
					else if(iteratorsave->vectorFOV.at(x).stBlock[i].stRight.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stRight, iWidth ,iHeight);
					else if(iteratorsave->vectorFOV.at(x).stBlock[i].stTop.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stTop, iWidth ,iHeight);
					else
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stBottom, iWidth ,iHeight);

					if(iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueH_L < 9000.0f){
						logitem.itemkey		=	strKey3 % "_left";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueH_L;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueH_R < 9000.0f){
						logitem.itemkey		=	strKey3 % "_right";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueH_R;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueV_T < 9000.0f){
						logitem.itemkey		=	strKey3 % "_top";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueV_T;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueV_B < 9000.0f){
						logitem.itemkey		=	strKey3 % "_bottom";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq1[i].flValueV_B;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq){
				strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_";

				logitem.itemkey		=	strKey2 % "center_left";
				logitem.itemvalue	=	iteratorsave->stSFRCenterFreq2.flValueH_L;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_right";
				logitem.itemvalue	=	iteratorsave->stSFRCenterFreq2.flValueH_R;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_top";
				logitem.itemvalue	=	iteratorsave->stSFRCenterFreq2.flValueV_T;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_bottom";
				logitem.itemvalue	=	iteratorsave->stSFRCenterFreq2.flValueV_B;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				for(unsigned int x=0;	x<iteratorsave->vectorFOV.size(); ++x){
					strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_fov" % QString::number(iteratorsave->vectorFOV.at(x).flFOV, 'f', 2) % "_";

					for(unsigned int i=0;	i<iteratorsave->vectorFOV.at(x).ucBlockCount;	++i){
						if(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft.bottom)
							strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft, iWidth ,iHeight);
						else if(iteratorsave->vectorFOV.at(x).stBlock[i].stRight.bottom)
							strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stRight, iWidth ,iHeight);
						else if(iteratorsave->vectorFOV.at(x).stBlock[i].stTop.bottom)
							strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stTop, iWidth ,iHeight);
						else
							strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stBottom, iWidth ,iHeight);

						if(iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueH_L < 9000.0f){
							logitem.itemkey		=	strKey3 % "_left";
							logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueH_L;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueH_R < 9000.0f){
							logitem.itemkey		=	strKey3 % "_right";
							logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueH_R;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueV_T < 9000.0f){
							logitem.itemkey		=	strKey3 % "_top";
							logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueV_T;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

						if(iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueV_B < 9000.0f){
							logitem.itemkey		=	strKey3 % "_bottom";
							logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRFreq2[i].flValueV_B;
							classLog.push_back(logitem);
							++(logitem.itemtype);
						}

					}
				}
			}
		}
		else{
			strKey2		=	strKey1 % "mtf50_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	iteratorsave->stSFRCenterMTF50.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	iteratorsave->stSFRCenterMTF50.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	iteratorsave->stSFRCenterMTF50.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	iteratorsave->stSFRCenterMTF50.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<iteratorsave->vectorFOV.size(); ++x){
				strKey2		=	strKey1 % "mtf50_fov" % QString::number(iteratorsave->vectorFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<iteratorsave->vectorFOV.at(x).ucBlockCount;	++i){
					if(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stLeft, iWidth ,iHeight);
					else if(iteratorsave->vectorFOV.at(x).stBlock[i].stRight.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stRight, iWidth ,iHeight);
					else if(iteratorsave->vectorFOV.at(x).stBlock[i].stTop.bottom)
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stTop, iWidth ,iHeight);
					else
						strKey3		=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i].stBottom, iWidth ,iHeight);

					if(iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueH_L < 9000.0f){
						logitem.itemkey		=	strKey3 % "_left";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueH_L;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueH_R < 9000.0f){
						logitem.itemkey		=	strKey3 % "_right";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueH_R;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueV_T < 9000.0f){
						logitem.itemkey		=	strKey3 % "_top";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueV_T;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

					if(iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueV_B < 9000.0f){
						logitem.itemkey		=	strKey3 % "_bottom";
						logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).stSFRMTF50[i].flValueV_B;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}

				}
			}
		}

		if(pstParameter->stTacticsBasic.ucTactics == _HisCCMAlg_Rolongo_AFC_Tactics_Linear){

		}
		else if(pstParameter->stTacticsBasic.ucTactics != _HisCCMAlg_Rolongo_AFC_Tactics_Single){
			logitem.itemkey		=	strKey1 % "motor_pos";
			logitem.itemvalue	=	iteratorsave->sMotorStep;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}

	}

	__inline void saveSFRHAAFCCurve2File(std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorItemData, \
		_SFRAFCCAParameter* pstParameter, QString& strPath)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);

		QTextStream out(&classFile);
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).sMotorStep) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).flWeightValue) << ",";
		}
		out << "\n";

		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueH_L) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueH_R) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueV_T) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueV_B) << ",";
			}
			out << "\n";

			for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w){
				for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y){
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq1[y].flValueH_L) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq1[y].flValueH_R) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq1[y].flValueV_T) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq1[y].flValueV_B) << ",";
					}
					out << "\n";
				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq){
				out << "\n";

				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueH_L) << ",";
				}
				out << "\n";

				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueH_R) << ",";
				}
				out << "\n";

				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueV_T) << ",";
				}
				out << "\n";

				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueV_B) << ",";
				}
				out << "\n";

				for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w){
					for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y){
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq2[y].flValueH_L) << ",";
						}
						out << "\n";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq2[y].flValueH_R) << ",";
						}
						out << "\n";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq2[y].flValueV_T) << ",";
						}
						out << "\n";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRFreq2[y].flValueV_B) << ",";
						}
						out << "\n";
					}
				}
			}
		}
		else{
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueH_L) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueH_R) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueV_T) << ",";
			}
			out << "\n";

			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueV_B) << ",";
			}
			out << "\n";

			for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w){
				for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y){
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRMTF50[y].flValueH_L) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRMTF50[y].flValueH_R) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRMTF50[y].flValueV_T) << ",";
					}
					out << "\n";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorFOV.at(w).stSFRMTF50[y].flValueV_B) << ",";
					}
					out << "\n";
				}
			}
		}

		classFile.close();
	}

	__inline int GetMTFCABlock(int iImgWidth, int iImgHeight, _HisCCMAlg_MTFBasic_Info& stMTFBasic, std::vector<_HisCCMAlg_MTFItem_Info>& vectorMTFItem, RECT** ppstBlock)
	{
		unsigned int uiTotalBlockCount	=	1;
		for(unsigned int x=0;	x<vectorMTFItem.size(); ++x){
			if(vectorMTFItem.at(x).ucBlockCount == 2) uiTotalBlockCount += 2;
			else uiTotalBlockCount	+=	4;
		}

		*ppstBlock	=	new RECT[uiTotalBlockCount];
		if(*ppstBlock == NULL)	return HisFX3Error_MallocBuffer;

		int iCenterX	=	(iImgWidth >>1), iCenterY	=	(iImgHeight >>1);
		int iHalfW	=	(stMTFBasic.iblockwith >>1), iHalfH = (stMTFBasic.iblockheight >>1);
		
		RECT* pstTemp		=	*ppstBlock;
		pstTemp->left			=	iCenterX - iHalfW;
		pstTemp->top			=	iCenterY - iHalfH;
		pstTemp++;

		double dflN1	=	sqrt(double(iCenterX*iCenterX + iCenterY*iCenterY));
		int iDistance, iX, iY;
		double dflAngleswitch	=	3.1415926535897932384626433832795 /180.0;

		for(unsigned int x=0;	x<vectorMTFItem.size(); ++x){
			iDistance	=	dflN1 *vectorMTFItem.at(x).flFOV + 0.5;
			if(vectorMTFItem.at(x).ucBlockCount == 2){
				iX	=	iDistance *cos(vectorMTFItem.at(x).flAngle *dflAngleswitch) +0.5;
				iY	=	iDistance *sin(vectorMTFItem.at(x).flAngle *dflAngleswitch) +0.5;
				pstTemp->left	=	iCenterX + iX -iHalfW;
				pstTemp->top	=	iCenterY -iY -iHalfH;
				pstTemp++;

				pstTemp->left	=	iCenterX -iX -iHalfW;
				pstTemp->top	=	iCenterY +iY -iHalfH;
				pstTemp++;
			}
			else{
				if(vectorMTFItem.at(x).flAngle < 3.0f || vectorMTFItem.at(x).flAngle > 87.0f){
					pstTemp->left	=	iCenterX - iDistance -iHalfW;
					pstTemp->top	=	iCenterY - iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX -iHalfW;
					pstTemp->top	=	iCenterY - iDistance -iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX +iDistance -iHalfW;
					pstTemp->top	=	iCenterY -iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX -iHalfW;
					pstTemp->top	=	iCenterY +iDistance -iHalfH;
					pstTemp++;
				}
				else{
					iX	=	iDistance *cos(vectorMTFItem.at(x).flAngle *dflAngleswitch) +0.5;
					iY	=	iDistance *sin(vectorMTFItem.at(x).flAngle *dflAngleswitch) +0.5;
					pstTemp->left	=	iCenterX - iX -iHalfW;
					pstTemp->top	=	iCenterY -iY -iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX +iX -iHalfW;
					pstTemp->top	=	iCenterY -iY -iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX +iX -iHalfW;
					pstTemp->top	=	iCenterY +iY -iHalfH;
					pstTemp++;

					pstTemp->left	=	iCenterX -iX -iHalfW;
					pstTemp->top	=	iCenterY +iY -iHalfH;
					pstTemp++;
				}
			}
		}

		pstTemp	=	*ppstBlock;
		for(unsigned int x=0;	x<uiTotalBlockCount;	++x){
			pstTemp->right		=	pstTemp->left + stMTFBasic.iblockwith;
			pstTemp->bottom	=	pstTemp->top	+stMTFBasic.iblockheight;
			if(pstTemp->left < 0 || pstTemp->top < 0 || pstTemp->right > iImgWidth || pstTemp->bottom > iImgHeight)
				return HisFX3Error_Parameter;
			pstTemp++;
		}

		return 0;
	}
	__inline void AddDrawFishEyetestitem(std::vector<double> dvect , int iImgWidth, int iImgHeight, std::vector<_itemDraw>& itemdrawList,double dspec,int icenterx,int icentery)
	{
		const int ciLeftShift					=	540;
		const int ciHeightShift				=	350;
		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Text;
		//center
		stDrawItem.idata[0]	=(iImgWidth>>1);
		stDrawItem.idata[1]	=(iImgHeight>>1) - 50;
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "C_x:%d,", icenterx);
		itemdrawList.push_back(stDrawItem);
		stDrawItem.idata[0]	=(iImgWidth>>1);
		stDrawItem.idata[1]	=(iImgHeight>>1);
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "C_y:%d,", icentery);
		itemdrawList.push_back(stDrawItem);
		// spec
		stDrawItem.idata[0]	=30;
		stDrawItem.idata[1]	=30;
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "spec:%.3f,", dspec);
		itemdrawList.push_back(stDrawItem);

		stDrawItem.idata[0]	=(iImgWidth) -130;
		stDrawItem.idata[1]	=30;
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "spec:%.3f,", dspec);
		itemdrawList.push_back(stDrawItem);

		stDrawItem.idata[0]	=(iImgWidth)-130;
		stDrawItem.idata[1]	=(iImgHeight)-130;
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "spec:%.3f,", dspec);
		itemdrawList.push_back(stDrawItem);

		stDrawItem.idata[0]	= 30;
		stDrawItem.idata[1]	=(iImgHeight) - 130;
		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
		sprintf_s(stDrawItem.strinfo.strtext, 16, "spec:%.3f,", dspec);
		itemdrawList.push_back(stDrawItem);
		if (dvect.size() !=4)
		{
			return;
		}
		//value
 		stDrawItem.idata[0]	=30;
 		stDrawItem.idata[1]	=30+50;
 		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
 		sprintf_s(stDrawItem.strinfo.strtext, 16, "value:%.3f,", dvect.at(0));
 		itemdrawList.push_back(stDrawItem);
 
 		stDrawItem.idata[0]	=(iImgWidth) -130;
 		stDrawItem.idata[1]	=30+50;
 		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
 		sprintf_s(stDrawItem.strinfo.strtext, 16, "value:%.3f,", dvect.at(1));
 		itemdrawList.push_back(stDrawItem);
 
 		stDrawItem.idata[0]	=(iImgWidth)-130;
 		stDrawItem.idata[1]	=(iImgHeight)-80;
 		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
 		sprintf_s(stDrawItem.strinfo.strtext, 16, "value:%.3f,", dvect.at(2));
 		itemdrawList.push_back(stDrawItem);
 
 		stDrawItem.idata[0]	= 30;
 		stDrawItem.idata[1]	=(iImgHeight) -80;
 		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
 		sprintf_s(stDrawItem.strinfo.strtext, 16, "value:%.3f,", dvect.at(3));
 		itemdrawList.push_back(stDrawItem);

	/*	if (abs(dAngleX) < abs(dspecx))
		{
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);	
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		}
		if (abs(dAngleY) < abs(dspecy))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		}*/


	}
	__inline void AddDrawcoaxialityitem(double dAngleX,double dAngleY ,double dAngleZ,int iHorizontalShiftX, int iVerticalShiftY, int iImgWidth, int iImgHeight, std::vector<_itemDraw>& itemdrawList,double dSpecx,double dSpecy,int iSpecH,int iSpecV)
	{

		const int ciLeftShift					=	540;
		const int ciHeightShift				=	350;
		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Text;

		stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
		if (abs(dSpecx) > abs(dAngleX))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		}
		if (abs(dSpecy) > abs(dAngleY))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		}

		if (abs(iSpecH) > abs(iHorizontalShiftX))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1)+ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_Shift:%d,", iHorizontalShiftX);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1)+ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_Shift:%d,", iHorizontalShiftX);
			itemdrawList.push_back(stDrawItem);
		}
		if (abs(iSpecV) > abs(iVerticalShiftY))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1) +ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1)+ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_Shift:%d,", iVerticalShiftY);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1) +ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1)+ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_Shift:%d,", iVerticalShiftY);
			itemdrawList.push_back(stDrawItem);
		}
	}
	__inline void AddDrawcoaxialitytiltitem(double dAngleX,double dAngleY , int iImgWidth, int iImgHeight, std::vector<_itemDraw>& itemdrawList,double dspecx,double dspecy)
	{
		const int ciLeftShift					=	540;
		const int ciHeightShift				=	350;
		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Text;
		if (abs(dAngleX) < abs(dspecx))
		{
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);	
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.idata[0]	=(iImgWidth>>1)-ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);	
			sprintf_s(stDrawItem.strinfo.strtext, 16, "X_R:%.3f,", dAngleX);
			itemdrawList.push_back(stDrawItem);
		}
		if (abs(dAngleY) < abs(dspecy))
		{
			stDrawItem.stcolor	=	QColor::fromRgb(0,255,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		} 
		else
		{
			stDrawItem.stcolor	=	QColor::fromRgb(255,0,0);
			stDrawItem.idata[0]	=(iImgWidth>>1)+ciLeftShift;
			stDrawItem.idata[1]	=(iImgHeight>>1) -ciHeightShift;
			sprintf_s(stDrawItem.strinfo.strtext, 16, "Y_R:%.3f,", dAngleY);
			itemdrawList.push_back(stDrawItem);
		}

	
	}
	__inline void AddDrawMTFHA(_HisCCMAlg_AFC_MTF_DataItem& stItemData, int iImgWdith, int iImgHeight, std::vector<_itemDraw>& itemdrawList, const float cflGradeAPercent)
	{

		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift					=	120;
		const int ciHeightShift				=	50;

		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Block;
		stDrawItem.strinfo.stblock	=	stItemData.stCenterBlock;
		stDrawItem.stcolor	=	stBlack;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>((stItemData.stCenterBlock.top + stItemData.stCenterBlock.bottom)/2);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.flCenterValue);
		if(stItemData.flCenterValue >= stItemData.flCenterSpec *cflGradeAPercent) stDrawItem.stcolor = stGreen;
		else if(stItemData.flCenterValue >= stItemData.flCenterSpec) stDrawItem.stcolor = stYellow;
		else stDrawItem.stcolor = stRed;
		itemdrawList.push_back(stDrawItem);

		int iCenterX = (iImgWdith >>1), iCenterY = (iImgHeight >>1);

		for(unsigned int y=0; y<stItemData.vectorFOV.size(); ++y){
			for(unsigned int x=0; x < stItemData.vectorFOV.at(y).ucBlockCount;	++x){
				stDrawItem.uctype	=	HisDrawType_Block;
				stDrawItem.strinfo.stblock	=	stItemData.vectorFOV.at(y).stBlock[x];
				stDrawItem.stcolor	=	stBlack;
				itemdrawList.push_back(stDrawItem);

				if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec *cflGradeAPercent) stDrawItem.stcolor = stGreen;
				else if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec) stDrawItem.stcolor = stYellow;
				else stDrawItem.stcolor = stRed;

				if(stDrawItem.strinfo.stblock.left > iCenterX){
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].top + stItemData.vectorFOV.at(y).stBlock[x].bottom)/2);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					itemdrawList.push_back(stDrawItem);
				}
				else{
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].right+stItemData.vectorFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].top + stItemData.vectorFOV.at(y).stBlock[x].bottom)/2);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					itemdrawList.push_back(stDrawItem);
				}
			}
		}

	}
//************* 2018/04/10 fengqiquan Add ******
	__inline void AddDrawMTFHE(_HisAutoFA_Rolongo_DataItem_EX& stItemData, int iImgWdith, int iImgHeight, std::vector<_itemDraw>& itemdrawList,_mtffaParameter& pstParam)
	{
		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift					=	120;
		const int ciHeightShift				=	50;

		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Block;
		stDrawItem.strinfo.stblock	=	stItemData.stMTFCenterBlock;
		stDrawItem.stcolor	=	stBlack;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stMTFCenterBlock.right+ stItemData.stMTFCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stMTFCenterBlock.top+(stItemData.stMTFCenterBlock.bottom-stItemData.stMTFCenterBlock.top)*0.33);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.flMTFCenterValue_H);
		if(stItemData.flMTFCenterValue_H<pstParam.stMTFBasic.flHcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stMTFCenterBlock.right+ stItemData.stMTFCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stMTFCenterBlock.top+(stItemData.stMTFCenterBlock.bottom-stItemData.stMTFCenterBlock.top)*0.66);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.flMTFCenterValue_V);
		if(stItemData.flMTFCenterValue_V<pstParam.stMTFBasic.flVcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stMTFCenterBlock.right+ stItemData.stMTFCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stMTFCenterBlock.bottom);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.flMTFCenterValue);
		if(stItemData.flMTFCenterValue<pstParam.stMTFBasic.flcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);


		int iCenterX = (iImgWdith >>1), iCenterY = (iImgHeight >>1);

		for(unsigned int y=0; y<stItemData.vectorMTFFOV.size(); ++y){
			for(unsigned int x=0; x < stItemData.vectorMTFFOV.at(y).ucBlockCount;	++x){
				stDrawItem.uctype	=	HisDrawType_Block;
				stDrawItem.strinfo.stblock	=	stItemData.vectorMTFFOV.at(y).stBlock[x];
				stDrawItem.stcolor	=	stBlack;
				itemdrawList.push_back(stDrawItem);

				if(stDrawItem.strinfo.stblock.left > iCenterX){
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].left + stItemData.vectorMTFFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].top+(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom-stItemData.vectorMTFFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorMTFFOV.at(y).flHValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].left + stItemData.vectorMTFFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].top+(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom-stItemData.vectorMTFFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorMTFFOV.at(y).flVValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].left + stItemData.vectorMTFFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorMTFFOV.at(y).flValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
				else{
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].right+stItemData.vectorMTFFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].top+(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom-stItemData.vectorMTFFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorMTFFOV.at(y).flHValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].right+stItemData.vectorMTFFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].top+(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom-stItemData.vectorMTFFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorMTFFOV.at(y).flVValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].left + stItemData.vectorMTFFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorMTFFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorMTFFOV.at(y).flValue[x]);
					if(stItemData.vectorMTFFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
			}
		}

	}
	__inline void AddDrawMTFHE(_HisCCMAlg_AFC_MTF_DataItem_EX& stItemData, int iImgWdith, int iImgHeight, std::vector<_itemDraw>& itemdrawList,_mtfAFCParameter& pstParam,const float cflGradeAPercent)
	{
		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift					=	120;
		const int ciHeightShift				=	50;

		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Block;
		stDrawItem.strinfo.stblock	=	stItemData.stCenterBlock;
		stDrawItem.stcolor	=	stBlack;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.top+(stItemData.stCenterBlock.bottom-stItemData.stCenterBlock.top)*0.33);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.flHCenterValue);
		if(stItemData.flHCenterValue<pstParam.stMTFBasic.flHcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.top+(stItemData.stCenterBlock.bottom-stItemData.stCenterBlock.top)*0.66);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.flVCenterValue);
		if(stItemData.flVCenterValue<pstParam.stMTFBasic.flVcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.bottom);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.flCenterValue);
		if(stItemData.flCenterValue<pstParam.stMTFBasic.flcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		int iCenterX = (iImgWdith >>1), iCenterY = (iImgHeight >>1);

		for(unsigned int y=0; y<stItemData.vectorFOV.size(); ++y){
			for(unsigned int x=0; x < stItemData.vectorFOV.at(y).ucBlockCount;	++x){
				stDrawItem.uctype	=	HisDrawType_Block;
				stDrawItem.strinfo.stblock	=	stItemData.vectorFOV.at(y).stBlock[x];
				stDrawItem.stcolor	=	stBlack;
				itemdrawList.push_back(stDrawItem);

				if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec *cflGradeAPercent) stDrawItem.stcolor = stGreen;
				else if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec) stDrawItem.stcolor = stYellow;
				else stDrawItem.stcolor = stRed;

				if(stDrawItem.strinfo.stblock.left > iCenterX){
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorFOV.at(y).flHValue[x]);
					if(stItemData.vectorFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorFOV.at(y).flVValue[x]);
					if(stItemData.vectorFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					if(stItemData.vectorFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
				else{
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].right+stItemData.vectorFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorFOV.at(y).flHValue[x]);
					if(stItemData.vectorFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].right+stItemData.vectorFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorFOV.at(y).flVValue[x]);
					if(stItemData.vectorFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					if(stItemData.vectorFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
			}
		}

	}
	__inline void AddDrawMTFHE(_HisCCMAlg_AFC_MTF_DataItem_EX& stItemData, int iImgWdith, int iImgHeight, std::vector<_itemDraw>& itemdrawList,_mtffaParameter& pstParam,const float cflGradeAPercent)
	{
		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);
		QColor stBlack		=	QColor::fromRgb(0,0,0);

		const int ciLeftShift					=	120;
		const int ciHeightShift				=	50;

		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Block;
		stDrawItem.strinfo.stblock	=	stItemData.stCenterBlock;
		stDrawItem.stcolor	=	stBlack;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.top+(stItemData.stCenterBlock.bottom-stItemData.stCenterBlock.top)*0.33);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.flHCenterValue);
		if(stItemData.flHCenterValue<pstParam.stMTFBasic.flHcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.top+(stItemData.stCenterBlock.bottom-stItemData.stCenterBlock.top)*0.66);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.flVCenterValue);
		if(stItemData.flVCenterValue<pstParam.stMTFBasic.flVcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stCenterBlock.right+ stItemData.stCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>(stItemData.stCenterBlock.bottom);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.flCenterValue);
		if(stItemData.flCenterValue<pstParam.stMTFBasic.flcenterspec) stDrawItem.stcolor = stRed;
		else stDrawItem.stcolor = stGreen;
		itemdrawList.push_back(stDrawItem);

		int iCenterX = (iImgWdith >>1), iCenterY = (iImgHeight >>1);

		for(unsigned int y=0; y<stItemData.vectorFOV.size(); ++y){
			for(unsigned int x=0; x < stItemData.vectorFOV.at(y).ucBlockCount;	++x){
				stDrawItem.uctype	=	HisDrawType_Block;
				stDrawItem.strinfo.stblock	=	stItemData.vectorFOV.at(y).stBlock[x];
				stDrawItem.stcolor	=	stBlack;
				itemdrawList.push_back(stDrawItem);

				if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec *cflGradeAPercent) stDrawItem.stcolor = stGreen;
				else if(stItemData.vectorFOV.at(y).flValue[x] >= stItemData.vectorFOV.at(y).flSpec) stDrawItem.stcolor = stYellow;
				else stDrawItem.stcolor = stRed;

				if(stDrawItem.strinfo.stblock.left > iCenterX){
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorFOV.at(y).flHValue[x]);
					if(stItemData.vectorFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorFOV.at(y).flVValue[x]);
					if(stItemData.vectorFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					if(stItemData.vectorFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
				else{
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].right+stItemData.vectorFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.33);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "H:%.3f", stItemData.vectorFOV.at(y).flHValue[x]);
					if(stItemData.vectorFOV.at(y).flHValue[x]<pstParam.vectorMTFItem.at(y).flHSpec) stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].right+stItemData.vectorFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].top+(stItemData.vectorFOV.at(y).stBlock[x].bottom-stItemData.vectorFOV.at(y).stBlock[x].top)*0.66);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "V:%.3f", stItemData.vectorFOV.at(y).flVValue[x]);
					if(stItemData.vectorFOV.at(y).flVValue[x]<pstParam.vectorMTFItem.at(y).flVSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);

					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorFOV.at(y).stBlock[x].left + stItemData.vectorFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>(stItemData.vectorFOV.at(y).stBlock[x].bottom);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "AVR:%.3f", stItemData.vectorFOV.at(y).flValue[x]);
					if(stItemData.vectorFOV.at(y).flValue[x]<pstParam.vectorMTFItem.at(y).flSpec) 
						stDrawItem.stcolor = stRed;
					else stDrawItem.stcolor = stGreen;
					itemdrawList.push_back(stDrawItem);
				}
			}
		}
		
	}
//**********************************************
	__inline void AddDrawMTFHA(_HisAutoFA_Rolongo_DataItem& stItemData, int iImgWdith, int iImgHeight, std::vector<_itemDraw>& itemdrawList)
	{
		QColor stGreen	=	QColor::fromRgb(0,255,0);
		QColor stRed		=	QColor::fromRgb(255,0,0);
		QColor stYellow		=	QColor::fromRgb(255,255,0);

		const int ciLeftShift		=	120;
		const int ciHeightShift	=	50;

		_itemDraw stDrawItem;
		stDrawItem.uctype	=	HisDrawType_Block;
		stDrawItem.strinfo.stblock	=	stItemData.stMTFCenterBlock;
		stDrawItem.stcolor	=	stYellow;
		itemdrawList.push_back(stDrawItem);

		stDrawItem.uctype	=	HisDrawType_Text;
		stDrawItem.idata[0]	=	static_cast<int>((stItemData.stMTFCenterBlock.right+stItemData.stMTFCenterBlock.left)/2);
		stDrawItem.idata[1]	=	static_cast<int>((stItemData.stMTFCenterBlock.top + stItemData.stMTFCenterBlock.bottom)/2);
		sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.flMTFCenterValue);
		stDrawItem.stcolor	=	(stItemData.flMTFCenterValue < stItemData.flMTFCenterSpec)?(stRed):(stGreen);
		itemdrawList.push_back(stDrawItem);

		int iCenterX = (iImgWdith >>1), iCenterY = (iImgHeight >>1);

		for(unsigned int y=0; y<stItemData.vectorMTFFOV.size(); ++y){
			for(unsigned int x=0; x < stItemData.vectorMTFFOV.at(y).ucBlockCount;	++x){
				stDrawItem.uctype	=	HisDrawType_Block;
				stDrawItem.strinfo.stblock	=	stItemData.vectorMTFFOV.at(y).stBlock[x];
				stDrawItem.stcolor	=	stYellow;
				itemdrawList.push_back(stDrawItem);

				if(stDrawItem.strinfo.stblock.left > iCenterX){
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].left + stItemData.vectorMTFFOV.at(y).stBlock[x].right)/2);
					stDrawItem.idata[1]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].top + stItemData.vectorMTFFOV.at(y).stBlock[x].bottom)/2);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.vectorMTFFOV.at(y).flValue[x]);
					stDrawItem.stcolor	=	(stItemData.vectorMTFFOV.at(y).flValue[x] < stItemData.vectorMTFFOV.at(y).flSpec)?(stRed):(stGreen);
					itemdrawList.push_back(stDrawItem);
				}
				else{
					stDrawItem.uctype	=	HisDrawType_Text;
					stDrawItem.idata[0]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].right+stItemData.vectorMTFFOV.at(y).stBlock[x].left)/2);
					stDrawItem.idata[1]	=	static_cast<int>((stItemData.vectorMTFFOV.at(y).stBlock[x].top + stItemData.vectorMTFFOV.at(y).stBlock[x].bottom)/2);
					sprintf_s(stDrawItem.strinfo.strtext, 16, "%.3f", stItemData.vectorMTFFOV.at(y).flValue[x]);
					stDrawItem.stcolor	=	(stItemData.vectorMTFFOV.at(y).flValue[x] < stItemData.vectorMTFFOV.at(y).flSpec)?(stRed):(stGreen);
					itemdrawList.push_back(stDrawItem);
				}
			}
		}
	}

	void saveMTFHAAFCCurve2File(std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorItemData, \
		_mtfAFCParameter* pstParameter, QString& strPath);

	__inline void saveMTFHAAFCResult(unsigned int uiType, bool bResult, unsigned int uiIndex, std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorDataItem, \
		_HisCCMAlg_AFC_Linear_Result& stLinearResult, _mtfAFCParameter* pstParameter, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		if(vectorDataItem.empty()) return;
		_HisLog_Item logitem;
		QString strKey1;
		if(uiType == 1) {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCMIDDLE);
			strKey1	=	"afc_mtf_middle_";
		}
		else if(uiType == 2)	{
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCFAR);
			strKey1	=	"afc_mtf_far_";
		}
		else {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCNEAR);
			strKey1	=	"afc_mtf_near_";
		}

		std::vector<_HisCCMAlg_AFC_MTF_DataItem>::iterator iteratorsave	=	vectorDataItem.begin() + uiIndex;

		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center";
		logitem.itemvalue	=	iteratorsave->flCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<iteratorsave->vectorFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(iteratorsave->vectorFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<iteratorsave->vectorFOV.at(x).ucBlockCount;	++i){
				strKey3	=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i], iWidth, iHeight);
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).flValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey		=	strKey2 % "U";
			logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}

		if(pstParameter->stTacticsBasic.ucTactics == _HisCCMAlg_Rolongo_AFC_Tactics_Linear){
			if(stLinearResult.bTestStartMotor){
				logitem.itemkey		=	strKey1 % "start_current";
				logitem.itemvalue	=	stLinearResult.iStartMotor;
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
		}
		else if(pstParameter->stTacticsBasic.ucTactics != _HisCCMAlg_Rolongo_AFC_Tactics_Single){
			logitem.itemkey		=	strKey1 % "motor_pos";
			logitem.itemvalue	=	iteratorsave->sMotorStep;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void saveMTFHAAFCResult_G(unsigned int uiType, bool bResult, unsigned int uiIndex, std::vector<_HisCCMAlg_AFC_MTF_DataItem_EX>& vectorDataItem, \
		_HisCCMAlg_AFC_Linear_Result& stLinearResult, _mtfAFCParameter* pstParameter, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		if(vectorDataItem.empty()) return;
		_HisLog_Item logitem;
		QString strKey1;
		if(uiType == 1) {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCMIDDLE);
			strKey1	=	"afc_mtf_middle_";
		}
		else if(uiType == 2)	{
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCFAR);
			strKey1	=	"afc_mtf_far_";
		}
		else {
			logitem.itemtype		=	classLog.getmaxtypeindex(_HISLOG_CLASSIFY_MTFFCNEAR);
			strKey1	=	"afc_mtf_near_";
		}

		std::vector<_HisCCMAlg_AFC_MTF_DataItem_EX>::iterator iteratorsave	=	vectorDataItem.begin() + uiIndex;

		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center_H";
		logitem.itemvalue	=	iteratorsave->flHCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	strKey2 % "center_V";
		logitem.itemvalue	=	iteratorsave->flVCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<iteratorsave->vectorFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(iteratorsave->vectorFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<iteratorsave->vectorFOV.at(x).ucBlockCount;	++i){
				strKey3	=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i], iWidth, iHeight)%"_H";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).flHValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);

				strKey3	=	strKey2 % getBlockName(iteratorsave->vectorFOV.at(x).stBlock[i], iWidth, iHeight)%"_V";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	iteratorsave->vectorFOV.at(x).flVValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
		}

		if(pstParameter->stTacticsBasic.ucTactics == _HisCCMAlg_Rolongo_AFC_Tactics_Linear){
			if(stLinearResult.bTestStartMotor){
				logitem.itemkey		=	strKey1 % "start_current";
				logitem.itemvalue	=	stLinearResult.iStartMotor;
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
		}
		else if(pstParameter->stTacticsBasic.ucTactics != _HisCCMAlg_Rolongo_AFC_Tactics_Single){
			logitem.itemkey		=	strKey1 % "motor_pos";
			logitem.itemvalue	=	iteratorsave->sMotorStep;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}


	__inline int AFCMTFHAFromDB(unsigned char uctype, _mtfAFCParameter* pstPara, _HisCCMAlg_AFC_MTF_DB* pDB, bool bChannel1)
	{
		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		pDB->initial();
		pDB->pstTacticsBasic	=	new _HisCCMAlg_AFC_Tactics_Basic;
		pDB->pstMTFBasic		=	new _HisCCMAlg_MTFBasic_Info;
		if(!(pDB->pstMTFBasic && pDB->pstTacticsBasic)){
			pDB->initial();
			return HisFX3Error_MallocBuffer;
		}

		*(pDB->pstTacticsBasic)	=	pstPara->stTacticsBasic;
		*(pDB->pstMTFBasic)		=	pstPara->stMTFBasic;
		pDB->vectorMTFItem.assign(pstPara->vectorMTFItem.begin(), pstPara->vectorMTFItem.end());

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT bins1,bins2,bins3,bins1byte,bins2byte,bins3byte,ints1,ints2,ints3 FROM tablemanage WHERE tablename='" % strTableName % "'");
			query.exec();

			QByteArray bins1,bins2,bins3;
			unsigned int bins1byte=0,bins2byte=0,bins3byte=0, ints1=0, ints2 = 0, ints3 = 0;
			while (query.next()){
				bins1 = query.value(0).toByteArray();
				bins2 = query.value(1).toByteArray();
				bins3 = query.value(2).toByteArray();
				bins1byte	=	query.value(3).toUInt();
				bins2byte	=	query.value(4).toUInt();
				bins3byte	=	query.value(5).toUInt();
				ints1			=	query.value(6).toUInt();
				ints2			=	query.value(7).toUInt();
				ints3			=	query.value(8).toUInt();
			}

			QByteArray Sbins1	=	TacticsBasicSerialize(*pDB->pstTacticsBasic);
			QByteArray Sbins2	=	MTFBasicSerialize(*pDB->pstMTFBasic);
			QByteArray Sbins3	=	MTFItemSerialize(pDB->vectorMTFItem);
			unsigned int Sbins1byte	=	Sbins1.size();
			unsigned int Sbins2byte	=	Sbins2.size();
			unsigned int Sbins3byte	=	Sbins3.size();
			unsigned int Sints1			=	pDB->vectorMTFItem.size();
			unsigned int Sints2			=	10; //MTF Chart-A
			unsigned int Sints3			=	(bChannel1)?(1):(2);

			bool bupdate = false;
			if(Sbins1byte != bins1byte || Sbins2byte != bins2byte || Sbins3byte != bins3byte || Sints1 != ints1 || Sints2 != ints2 || Sints3 != ints3)
				bupdate	=	true;
			if(!bupdate){
				if(!isEqual(bins1, Sbins1)) bupdate = true;
				if(!isEqual(bins2, Sbins2)) bupdate = true;
				if(!isEqual(bins3, Sbins3)) bupdate = true;
			}

			if(bupdate){
				query.prepare("UPDATE tablemanage SET bins1=:bins1,bins2=:bins2,bins3=:bins3,bins1byte=:bins1byte,bins2byte=:bins2byte,bins3byte=:bins3byte,ints1=:ints1,ints2=:ints2,ints3=:ints3 WHERE tablename='" % strTableName % "'");
				query.bindValue(":bins1", Sbins1);
				query.bindValue(":bins2", Sbins2);
				query.bindValue(":bins3", Sbins3);
				query.bindValue(":bins1byte", Sbins1byte);
				query.bindValue(":bins2byte", Sbins2byte);
				query.bindValue(":bins3byte", Sbins3byte);
				query.bindValue(":ints1", Sints1);
				query.bindValue(":ints2", Sints2);
				query.bindValue(":ints3", Sints3);
				query.exec();

				query.prepare("DELETE FROM " % strTableName);
				query.exec();
			}
			else{
				query.prepare("SELECT id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend FROM " % strTableName %  "  ORDER BY id ASC" );
				query.exec();
				unsigned int uiDataSize	=	1;
				for(unsigned int x=0;	x<pDB->vectorMTFItem.size(); ++x){
					if(pDB->vectorMTFItem.at(x).ucBlockCount == 2)		uiDataSize += 2;
					else uiDataSize	+=	4;
				}

				_HisCCMAlg_AFC_MTF_DB_Item stNewItem;
				stNewItem.vecValueStart.resize(uiDataSize);
				stNewItem.vecValueEnd.resize(uiDataSize);
				QByteArray valuestart, valueend;

				while (query.next()){
					stNewItem.ui64ID				=	query.value(0).toULongLong();
					stNewItem.sMotorStart		=	query.value(1).toInt();
					stNewItem.flMarkDisStart	=	query.value(2).toFloat();
					stNewItem.sMotorEnd			=	query.value(5).toInt();
					stNewItem.flMarkDisEnd		=	query.value(6).toFloat();
					valuestart								=	query.value(4).toByteArray();
					valueend								=	query.value(8).toByteArray();

					QDataStream streamstart(valuestart);
					streamstart.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamstart >> stNewItem.vecValueStart.at(x);
					}

					QDataStream streamend(valueend);
					streamend.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamend >> stNewItem.vecValueEnd.at(x);
					}

					pDB->ui64IDMax	=	max(pDB->ui64IDMax, stNewItem.ui64ID);
					pDB->vectorItem.push_back(stNewItem);
				}
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			pDB->initial();
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int AFCMTFToDB(unsigned char uctype, _mtfAFCParameter* pstPara, _HisCCMAlg_AFC_MTF_DB* pDB, \
		std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorDataItem, unsigned int uiIndex, bool bChannel1)
	{
		if(uiIndex == 0) return 0;
		if(vectorDataItem.at(uiIndex).ucStatus == 0x0) return 0;

		QMutexLocker locker(&hisglobalparameter.mutexDBUser);

		_HisCCMAlg_AFC_MTF_DB_Item stNewItem;
		stNewItem.flMarkDisStart	=	vectorDataItem.at(0).dflMarkDistance;
		stNewItem.sMotorStart		=	vectorDataItem.at(0).sMotorStep;
		stNewItem.ui64ID				=	pDB->ui64IDMax +1;
		stNewItem.flMarkDisEnd		=	vectorDataItem.at(uiIndex).dflMarkDistance;
		stNewItem.sMotorEnd			=	vectorDataItem.at(uiIndex).sMotorStep;

		unsigned int uiDataSize	=	1;
		for(unsigned int x=0;	x<pDB->vectorMTFItem.size(); ++x){
			if(pDB->vectorMTFItem.at(x).ucBlockCount == 2)		uiDataSize += 2;
			else uiDataSize	+=	4;
		}

		stNewItem.vecValueStart.resize(uiDataSize);
		stNewItem.vecValueEnd.resize(uiDataSize);

		unsigned int uitempi	=	0;
		stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).flCenterValue;
		stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).flCenterValue;
		++uitempi;

		for(unsigned int y=0;	y<pstPara->vectorMTFItem.size(); ++y){
			for(unsigned int x=0;	x<pstPara->vectorMTFItem.at(y).ucBlockCount;	++x){
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(0).vectorFOV.at(y).flValue[x];
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorFOV.at(y).flValue[x];
				++uitempi;
			}
		}

		++(pDB->ui64IDMax);

		bool bReplace = false;
		unsigned int uiReplaceID	=	0;
		if(vectorDataItem.size() >= pDB->usConstMaxItem){
			unsigned __int64 uiMinID	=	0xFFFFFFFFFFFFFFFF;
			for(unsigned int x=0;	x<pDB->vectorItem.size(); ++x){
				if(pDB->vectorItem.at(x).ui64ID < uiMinID){
					uiMinID	=	pDB->vectorItem.at(x).ui64ID;
					uiReplaceID	=	x;
				}
			}

			bReplace = true;
			pDB->vectorItem.erase(pDB->vectorItem.begin() + uiReplaceID);		
		}

		pDB->vectorItem.push_back(stNewItem);

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName;
			switch (uctype){
			case 1: strTableName = (bChannel1)?("afcmiddlealldbc1"):("afcmiddlealldbc2");  break;
			case 2: strTableName = (bChannel1)?("afcfaralldbc1"):("afcfaralldbc2");  break;
			default: strTableName = (bChannel1)?("afcnearalldbc1"):("afcnearalldbc2");  break;
			}

			QSqlQuery query(customdb);

			if(bReplace){
				query.prepare("DELETE FROM " % strTableName %  " WHERE id=:id");
				query.bindValue(":id", uiReplaceID);
				query.exec();
			}

			QByteArray valuestart, valueend;

			QDataStream streamstart(&valuestart, QIODevice::WriteOnly);
			streamstart.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueStart.size(); ++x){
				streamstart << stNewItem.vecValueStart.at(x);
			}

			QDataStream streamend(&valueend, QIODevice::WriteOnly);
			streamend.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueEnd.size(); ++x){
				streamend << stNewItem.vecValueEnd.at(x);
			}

			query.prepare("INSERT INTO " % strTableName %  "(id,motorstart,disstart,reserves1,valuestart,motorend,disend,reservee1,valueend) VALUES(:id,:motorstart,:disstart,:reserves1,:valuestart,:motorend,:disend,:reservee1,:valueend)");		
			query.bindValue(":id", stNewItem.ui64ID);
			query.bindValue(":motorstart", stNewItem.sMotorStart);
			query.bindValue(":disstart", stNewItem.flMarkDisStart);
			query.bindValue(":reserves1", 0.0);
			query.bindValue(":valuestart", valuestart);
			query.bindValue(":motorend", stNewItem.sMotorEnd);
			query.bindValue(":disend", stNewItem.flMarkDisEnd);
			query.bindValue(":reservee1", 0.0);
			query.bindValue(":valueend", valueend);
			query.exec();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline void MTFMFACaculateResult(_HisCCMAlg_AFC_MTF_DataItem& stItemData, const float cflGradeAPercent)
	{

		stItemData.ucStatus	=	0x1;
		if(stItemData.flCenterValue < stItemData.flCenterSpec)	stItemData.ucStatus = 0x0;
		stItemData.flWeightValue	=	stItemData.flCenterValue *stItemData.flCenterWeight;
		float flMax, flMin, flSum;
		for(unsigned int y=0;	y<stItemData.vectorFOV.size(); ++y){
			flMax	=	-99999.0f;	flMin = 99999.0f, flSum = 0.0f;
			for(unsigned int x=0;	x<stItemData.vectorFOV.at(y).ucBlockCount;	++x){
				if(stItemData.vectorFOV.at(y).flValue[x] < stItemData.vectorFOV.at(y).flSpec)
					stItemData.ucStatus	=	0x0;
				flMax	=	max(flMax, stItemData.vectorFOV.at(y).flValue[x]);
				flMin		=	min(flMin, stItemData.vectorFOV.at(y).flValue[x]);
				flSum	+=	stItemData.vectorFOV.at(y).flValue[x];
			}
			stItemData.vectorFOV.at(y).flUniformValue	=	flMax - flMin;
			if(stItemData.vectorFOV.at(y).flUniformValue > stItemData.vectorFOV.at(y).flSpecUniform)
				stItemData.ucStatus	=	0x0;
		}

		if(stItemData.ucStatus == 0x1){
			stItemData.ucStatus	=	5;
			if(stItemData.flCenterValue < stItemData.flCenterSpec *cflGradeAPercent)	stItemData.ucStatus = 4;
			for(unsigned int y=0;	y<stItemData.vectorFOV.size(); ++y){
				for(unsigned int x=0;	x<stItemData.vectorFOV.at(y).ucBlockCount;	++x){
					if(stItemData.vectorFOV.at(y).flValue[x] < stItemData.vectorFOV.at(y).flSpec *cflGradeAPercent)
						stItemData.ucStatus	=	4;
				}
			}
		}		

	}

	__inline void curveMTFAFCCurveDraw(QVector<_HQwtCurve_Item>& vecCurvePoint, QVector<QColor>& vecCurveLineColor, \
		QVector<QString>& vecCurveLegend, std::vector<_HisCCMAlg_AFC_MTF_DataItem>& vectorDataItem, int iWidth, int iHeight)
	{
		if(vectorDataItem.size() < 1) return;
		unsigned int uiLineCount = 2;
		for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size(); ++x)
			uiLineCount	+=	vectorDataItem.at(0).vectorFOV.at(x).ucBlockCount;
		vecCurveLineColor.resize(uiLineCount);
		vecCurveLegend.resize(uiLineCount);

		for(unsigned int x=0;	x<vecCurveLineColor.size(); ++x){
			switch (x){
			case 0: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 0); break;
			case 1: vecCurveLineColor[x] = QColor::fromRgb(255, 255, 0); break;
			case 2: vecCurveLineColor[x] = QColor::fromRgb(0, 0, 220); break;
			case 3: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 255); break;
			case 4: vecCurveLineColor[x] = QColor::fromRgb(230, 0, 230); break;
			case 5: vecCurveLineColor[x] = QColor::fromRgb(255, 0, 0); break;
			case 6: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 7: vecCurveLineColor[x] = QColor::fromRgb(169,169,169); break;
			case 8: vecCurveLineColor[x] = QColor::fromRgb(128,0,0); break;
			case 9: vecCurveLineColor[x] = QColor::fromRgb(165,42,42); break;
			case 10: vecCurveLineColor[x] = QColor::fromRgb(188,143,143); break;
			case 11: vecCurveLineColor[x] = QColor::fromRgb(255,69,0); break;
			case 12: vecCurveLineColor[x] = QColor::fromRgb(160,82,45); break;
			case 13: vecCurveLineColor[x] = QColor::fromRgb(192,14,235); break;
			case 14: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 15: vecCurveLineColor[x] = QColor::fromRgb(210,180,140); break;
			case 16: vecCurveLineColor[x] = QColor::fromRgb(189,183,107); break;
			case 17: vecCurveLineColor[x] = QColor::fromRgb(107,142,35); break;
			case 18: vecCurveLineColor[x] = QColor::fromRgb(173,255,47); break;
			case 19: vecCurveLineColor[x] = QColor::fromRgb(50,205,50); break;
			case 20: vecCurveLineColor[x] = QColor::fromRgb(60,179,113); break;
			case 21: vecCurveLineColor[x] = QColor::fromRgb(0,128,128); break;
			case 22: vecCurveLineColor[x] = QColor::fromRgb(70,130,180); break;
			case 23: vecCurveLineColor[x] = QColor::fromRgb(30,144,255); break;
			case 24: vecCurveLineColor[x] = QColor::fromRgb(0,0,139); break;
			case 25: vecCurveLineColor[x] = QColor::fromRgb(106,90,205); break;
			case 26: vecCurveLineColor[x] = QColor::fromRgb(138,43,226); break;
			case 27: vecCurveLineColor[x] = QColor::fromRgb(220,20,60); break;
			default: vecCurveLineColor[x] = QColor::fromRgb(255,105,180); break;
			}
		}

		unsigned int uiIndex	=	0;
		vecCurveLegend[uiIndex++]	=	"Weight";
		vecCurveLegend[uiIndex++]	=	"CT";
		for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size();	++x){
			for(unsigned int i=0;	i<vectorDataItem.at(0).vectorFOV.at(x).ucBlockCount; ++i){
				vecCurveLegend[uiIndex++]	=	QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i], iWidth, iHeight);
			}
		}

		vecCurvePoint.resize(vectorDataItem.size());
		for(unsigned int w=0;	w<vectorDataItem.size();	++w){
			vecCurvePoint[w].dflX	=	vectorDataItem.at(w).sMotorStep;
			vecCurvePoint[w].vecValue.resize(uiLineCount);
			uiIndex	=	0;
			vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).flWeightValue;
			vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).flCenterValue;		
			for(unsigned int x=0;	x<vectorDataItem.at(w).vectorFOV.size();	++x){
				for(unsigned int i=0;	i<vectorDataItem.at(w).vectorFOV.at(x).ucBlockCount; ++i){
					vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).vectorFOV.at(x).flValue[i];
				}
			}
		}
	}

	__inline void curveSFRAFCCurveDraw(QVector<_HQwtCurve_Item>& vecCurvePoint, QVector<QColor>& vecCurveLineColor, \
		QVector<QString>& vecCurveLegend, std::vector<_HisCCMAlg_AFC_SFRHA_DataItem>& vectorDataItem, _SFRAFCCAParameter* pstParameter, int iWidth, int iHeight)
	{
		if(vectorDataItem.size() < 1) return;
		unsigned int uiLineCount = 2;
		for(int x=0;	x<pstParameter->vectorSFRItem.size(); ++x)
		{
			uiLineCount	+= (pstParameter->vectorSFRItem.at(x).ucBlockCount <<1);
		}

		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq && pstParameter->stSFRBasic.b2ndFreq)
			uiLineCount	*=	2;
		uiLineCount	+=	1;
		vecCurveLineColor.resize(uiLineCount);
		vecCurveLegend.resize(uiLineCount);

		for(unsigned int x=0;	x<vecCurveLineColor.size(); ++x)
		{
			switch (x){
			case 0: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 0); break;
			case 1: vecCurveLineColor[x] = QColor::fromRgb(255, 255, 0); break;
			case 2: vecCurveLineColor[x] = QColor::fromRgb(0, 0, 220); break;
			case 3: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 255); break;
			case 4: vecCurveLineColor[x] = QColor::fromRgb(230, 0, 230); break;
			case 5: vecCurveLineColor[x] = QColor::fromRgb(255, 0, 0); break;
			case 6: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 7: vecCurveLineColor[x] = QColor::fromRgb(169,169,169); break;
			case 8: vecCurveLineColor[x] = QColor::fromRgb(128,0,0); break;
			case 9: vecCurveLineColor[x] = QColor::fromRgb(165,42,42); break;
			case 10: vecCurveLineColor[x] = QColor::fromRgb(188,143,143); break;
			case 11: vecCurveLineColor[x] = QColor::fromRgb(255,69,0); break;
			case 12: vecCurveLineColor[x] = QColor::fromRgb(160,82,45); break;
			case 13: vecCurveLineColor[x] = QColor::fromRgb(192,14,235); break;
			case 14: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 15: vecCurveLineColor[x] = QColor::fromRgb(210,180,140); break;
			case 16: vecCurveLineColor[x] = QColor::fromRgb(189,183,107); break;
			case 17: vecCurveLineColor[x] = QColor::fromRgb(107,142,35); break;
			case 18: vecCurveLineColor[x] = QColor::fromRgb(173,255,47); break;
			case 19: vecCurveLineColor[x] = QColor::fromRgb(50,205,50); break;
			case 20: vecCurveLineColor[x] = QColor::fromRgb(60,179,113); break;
			case 21: vecCurveLineColor[x] = QColor::fromRgb(0,128,128); break;
			case 22: vecCurveLineColor[x] = QColor::fromRgb(70,130,180); break;
			case 23: vecCurveLineColor[x] = QColor::fromRgb(30,144,255); break;
			case 24: vecCurveLineColor[x] = QColor::fromRgb(0,0,139); break;
			case 25: vecCurveLineColor[x] = QColor::fromRgb(106,90,205); break;
			case 26: vecCurveLineColor[x] = QColor::fromRgb(138,43,226); break;
			case 27: vecCurveLineColor[x] = QColor::fromRgb(220,20,60); break;
			default: vecCurveLineColor[x] = QColor::fromRgb(255,105,180); break;
			}
		}

		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq)
		{
			unsigned int uiIndex	=	0;
			vecCurveLegend[uiIndex++]	=	"Weight";
			vecCurveLegend[uiIndex++]	=	"F1_CT_H";
			vecCurveLegend[uiIndex++]	=	"F1_CT_V";
			for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size();	++x){
				for(unsigned int i=0;	i<4; ++i){
					vecCurveLegend[uiIndex++]	=	"F1_" % QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_H";
					vecCurveLegend[uiIndex++]	=	"F1_" % QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_V";
				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq){
				vecCurveLegend[uiIndex++]	=	"F2_CT_H";
				vecCurveLegend[uiIndex++]	=	"F2_CT_V";
				for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size();	++x){
					for(unsigned int i=0;	i<4; ++i){
						vecCurveLegend[uiIndex++]	=	"F2_" % QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_H";
						vecCurveLegend[uiIndex++]	=	"F2_" % QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_V";
					}
				}
			}

			vecCurvePoint.resize(vectorDataItem.size());
			for(unsigned int w=0;	w<vectorDataItem.size();	++w){
				vecCurvePoint[w].dflX	=	vectorDataItem.at(w).sMotorStep;
				vecCurvePoint[w].vecValue.resize(uiLineCount);
				uiIndex	=	0;
				vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).flWeightValue;
				vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterFreq1.flValueH_L, vectorDataItem.at(w).stSFRCenterFreq1.flValueH_R);
				vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterFreq1.flValueV_T, vectorDataItem.at(w).stSFRCenterFreq1.flValueV_B);
				for(unsigned int x=0;	x<vectorDataItem.at(w).vectorFOV.size();	++x){
					for(unsigned int i=0;	i<vectorDataItem.at(w).vectorFOV.at(x).ucBlockCount; ++i){
						vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq1[i].flValueH_L, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq1[i].flValueH_R);
						vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq1[i].flValueV_T, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq1[i].flValueV_B);
					}
				}

				if(pstParameter->stSFRBasic.b2ndFreq){
					vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterFreq2.flValueH_L, vectorDataItem.at(w).stSFRCenterFreq2.flValueH_R);
					vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterFreq2.flValueV_T, vectorDataItem.at(w).stSFRCenterFreq2.flValueV_B);
					for(unsigned int x=0;	x<vectorDataItem.at(w).vectorFOV.size();	++x){
						for(unsigned int i=0;	i<vectorDataItem.at(w).vectorFOV.at(x).ucBlockCount; ++i){
							vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq2[i].flValueH_L, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq2[i].flValueH_R);
							vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq2[i].flValueV_T, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRFreq2[i].flValueV_B);
						}
					}
				}
			}
		}
		else
		{
			unsigned int uiIndex	=	0;
			vecCurveLegend[uiIndex++]	=	"Weight";
			vecCurveLegend[uiIndex++]	=	"CT_H";
			vecCurveLegend[uiIndex++]	=	"CT_V";
			for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size();	++x){
				for(unsigned int i=0;	i<4; ++i){
					vecCurveLegend[uiIndex++]	=	QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_H";
					vecCurveLegend[uiIndex++]	=	QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 2) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i].stLeft, iWidth, iHeight) % "_V";
				}
			}

			vecCurvePoint.resize(vectorDataItem.size());
			for(unsigned int w=0;	w<vectorDataItem.size();	++w){
				vecCurvePoint[w].dflX	=	vectorDataItem.at(w).sMotorStep;
				vecCurvePoint[w].vecValue.resize(uiLineCount);
				uiIndex	=	0;
				vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).flWeightValue;
				vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterMTF50.flValueH_L, vectorDataItem.at(w).stSFRCenterMTF50.flValueH_R);
				vecCurvePoint[w].vecValue[uiIndex++]	=	min(vectorDataItem.at(w).stSFRCenterMTF50.flValueV_T, vectorDataItem.at(w).stSFRCenterMTF50.flValueV_B);
				for(unsigned int x=0;	x<vectorDataItem.at(w).vectorFOV.size();	++x){
					for(unsigned int i=0;	i<vectorDataItem.at(w).vectorFOV.at(x).ucBlockCount; ++i){
						vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRMTF50[i].flValueH_L, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRMTF50[i].flValueH_R);
						vecCurvePoint[w].vecValue[uiIndex++]	=min(vectorDataItem.at(w).vectorFOV.at(x).stSFRMTF50[i].flValueV_T, 	vectorDataItem.at(w).vectorFOV.at(x).stSFRMTF50[i].flValueV_B);
					}
				}
			}
		}
	}

	__inline int UpdateOtpBurnParameterForGolden(QString strTableName,QString strGolden_r,QString strGolden_g,QString strGolden_b) 
	{
		bool bparsesuccess	=	true;
		//��ȡ������config
		for(int  w=0;	w<1;	++w){ //�˴����������,��Ҫɾ��
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querycustom");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Custom");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT reserve FROM " % strTableName % " WHERE classfy='sensor' AND item='otpburn'");
			query.exec();

			QString itemtext[4];
			bool bExist = false;
			QStringList strN1, strV1;
			while (query.next())
			{
				bExist	=	true;
					itemtext[0]	=	query.value(0).toString();
					if(itemtext[0].size() > 1)
					{
						patchconfigstring(itemtext[0], strN1, strV1);
						for(unsigned int i=0;	i<strN1.size();	++i)
						{
							if(i ==0)
							{
								strV1.replace(i, strGolden_r);
							}
							if(i ==1)
							{
								strV1.replace(i, strGolden_g);
							}
							if(i ==2)
							{
								strV1.replace(i, strGolden_g);
							}
							if(i ==3)
							{
								strV1.replace(i, strGolden_b);
							}
						}

						jointconfigstring(itemtext[0], strN1, strV1);
					}				
				
			}
			if(bExist)
			{
				query.prepare("UPDATE " % strTableName % " SET reserve=:reserve WHERE classfy='sensor' AND item='otpburn'");
				query.bindValue(":reserve", itemtext[0]);
				query.exec();
			}
			customdb.close();
		}

		QSqlDatabase::removeDatabase("querycustom");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}


	__inline void curveLpAFCCurveDraw(QVector<_HQwtCurve_Item>& vecCurvePoint, QVector<QColor>& vecCurveLineColor, \
		QVector<QString>& vecCurveLegend, std::vector<_HisCCMAlg_AFC_LP_DataItem>& vectorDataItem, int iWidth, int iHeight)
	{
		if(vectorDataItem.size() < 1) return;
		unsigned int uiLineCount = vectorDataItem.at(0).vectorFOV.size() *4;
		uiLineCount	+=	1;
		vecCurveLineColor.resize(uiLineCount);
		vecCurveLegend.resize(uiLineCount);

		for(unsigned int x=0;	x<vecCurveLineColor.size(); ++x){
			switch (x){
			case 0: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 0); break;
			case 1: vecCurveLineColor[x] = QColor::fromRgb(255, 255, 0); break;
			case 2: vecCurveLineColor[x] = QColor::fromRgb(0, 0, 220); break;
			case 3: vecCurveLineColor[x] = QColor::fromRgb(0, 255, 255); break;
			case 4: vecCurveLineColor[x] = QColor::fromRgb(230, 0, 230); break;
			case 5: vecCurveLineColor[x] = QColor::fromRgb(255, 0, 0); break;
			case 6: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 7: vecCurveLineColor[x] = QColor::fromRgb(169,169,169); break;
			case 8: vecCurveLineColor[x] = QColor::fromRgb(128,0,0); break;
			case 9: vecCurveLineColor[x] = QColor::fromRgb(165,42,42); break;
			case 10: vecCurveLineColor[x] = QColor::fromRgb(188,143,143); break;
			case 11: vecCurveLineColor[x] = QColor::fromRgb(255,69,0); break;
			case 12: vecCurveLineColor[x] = QColor::fromRgb(160,82,45); break;
			case 13: vecCurveLineColor[x] = QColor::fromRgb(192,14,235); break;
			case 14: vecCurveLineColor[x] = QColor::fromRgb(255,140,0); break;
			case 15: vecCurveLineColor[x] = QColor::fromRgb(210,180,140); break;
			case 16: vecCurveLineColor[x] = QColor::fromRgb(189,183,107); break;
			case 17: vecCurveLineColor[x] = QColor::fromRgb(107,142,35); break;
			case 18: vecCurveLineColor[x] = QColor::fromRgb(173,255,47); break;
			case 19: vecCurveLineColor[x] = QColor::fromRgb(50,205,50); break;
			case 20: vecCurveLineColor[x] = QColor::fromRgb(60,179,113); break;
			case 21: vecCurveLineColor[x] = QColor::fromRgb(0,128,128); break;
			case 22: vecCurveLineColor[x] = QColor::fromRgb(70,130,180); break;
			case 23: vecCurveLineColor[x] = QColor::fromRgb(30,144,255); break;
			case 24: vecCurveLineColor[x] = QColor::fromRgb(0,0,139); break;
			case 25: vecCurveLineColor[x] = QColor::fromRgb(106,90,205); break;
			case 26: vecCurveLineColor[x] = QColor::fromRgb(138,43,226); break;
			case 27: vecCurveLineColor[x] = QColor::fromRgb(220,20,60); break;
			default: vecCurveLineColor[x] = QColor::fromRgb(255,105,180); break;
			}
		}

		unsigned int uiIndex	=	0;
		vecCurveLegend[uiIndex++]	=	"Weight";
		for(unsigned int x=0;	x<vectorDataItem.at(0).vectorFOV.size();	++x){
			for(unsigned int i=0;	i<4; ++i){
				vecCurveLegend[uiIndex++]	=	QString::number(vectorDataItem.at(0).vectorFOV.at(x).flFOV, 'f', 3) % "_" % getBlockName(vectorDataItem.at(0).vectorFOV.at(x).stBlock[i], iWidth, iHeight);
			}
		}

		vecCurvePoint.resize(vectorDataItem.size());
		for(unsigned int w=0;	w<vectorDataItem.size();	++w){
			vecCurvePoint[w].dflX	=	vectorDataItem.at(w).sMotorStep;
			vecCurvePoint[w].vecValue.resize(uiLineCount);
			uiIndex	=	0;
			vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).flWeightValue;	
			for(unsigned int x=0;	x<vectorDataItem.at(w).vectorFOV.size();	++x){
				for(unsigned int i=0;	i<4; ++i){
					vecCurvePoint[w].vecValue[uiIndex++]	=	vectorDataItem.at(w).vectorFOV.at(x).stLpValue[i].flValue;
				}
			}
		}
	}

	__inline void fillMTFFALensBarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisCCMAlg_AFC_MTF_DataItem& stItemData, _mtffaParameter* pstParameter, int iWidth, int iHeight)
	{
		unsigned int uiItemCount = 1;
		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x)
			uiItemCount	+=	stItemData.vectorFOV.at(x).ucBlockCount;
		vecBarChartItem.resize(uiItemCount);

		unsigned int uiGroupIndex	=	0;
		vecBarChartItem[0].flValue				=	stItemData.flCenterValue;
		vecBarChartItem[0].flDotLine			=	stItemData.flCenterSpec;
		vecBarChartItem[0].uiGroupIndex	=	uiGroupIndex++;
		vecBarChartItem[0].strTitle				=	"CT";
		if(stItemData.flCenterValue >= stItemData.flCenterSpec) vecBarChartItem[0].uiColorIndex	=	1;
		else if(stItemData.flCenterValue >= stItemData.flCenterGradeB) vecBarChartItem[0].uiColorIndex	=	2;
		else if(stItemData.ucGrade >3 && stItemData.flCenterValue >= stItemData.flCenterGradeC) vecBarChartItem[0].uiColorIndex	=	3;
		else if(stItemData.ucGrade >4 && stItemData.flCenterValue >= stItemData.flCenterGradeD) vecBarChartItem[0].uiColorIndex	=	4;
		else if(stItemData.ucGrade >5 && stItemData.flCenterValue >= stItemData.flCenterGradeE) vecBarChartItem[0].uiColorIndex	=	5;
		else vecBarChartItem[0].uiColorIndex	=	0;

		unsigned int uiIndex	=	1;
		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x)
		{
			for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(x).flSpec;
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(x).flValue[i];
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "\n" %  getBlockName(stItemData.vectorFOV.at(x).stBlock[i], iWidth, iHeight);
				if(vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flSpec) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else if(vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flGradeB) vecBarChartItem[uiIndex].uiColorIndex = 2;
				else if(stItemData.ucGrade >3 && vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flGradeC) vecBarChartItem[uiIndex].uiColorIndex = 3;
				else if(stItemData.ucGrade >4 && vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flGradeD) vecBarChartItem[uiIndex].uiColorIndex = 4;
				else if(stItemData.ucGrade >5 && vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flGradeE) vecBarChartItem[uiIndex].uiColorIndex = 5;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
			}		
			++uiGroupIndex;
		}
	}

	__inline void fillMTFFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisCCMAlg_AFC_MTF_DataItem& stItemData, int iWidth, int iHeight, const float cflGradeAPercent)
	{
		unsigned int uiItemCount = 1;
		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x)
			uiItemCount	+=	stItemData.vectorFOV.at(x).ucBlockCount;
		uiItemCount	+=	stItemData.vectorFOV.size();
		vecBarChartItem.resize(uiItemCount);

		unsigned int uiGroupIndex	=	0;
		vecBarChartItem[0].flValue				=	stItemData.flCenterValue;
		vecBarChartItem[0].flDotLine			=	stItemData.flCenterSpec;
		vecBarChartItem[0].uiGroupIndex	=	uiGroupIndex++;
		vecBarChartItem[0].strTitle				=	"CT";
		if(stItemData.flCenterValue >= stItemData.flCenterSpec * cflGradeAPercent) vecBarChartItem[0].uiColorIndex	=	1;
		else if(stItemData.flCenterValue >= stItemData.flCenterSpec) vecBarChartItem[0].uiColorIndex	=	2;
		else vecBarChartItem[0].uiColorIndex	=	0;

		unsigned int uiIndex	=	1;
		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x)
		{
			for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(x).flSpec;
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(x).flValue[i];
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "\n" %  getBlockName(stItemData.vectorFOV.at(x).stBlock[i], iWidth, iHeight);
				if(vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flSpec * cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else if(vecBarChartItem[uiIndex].flValue >= stItemData.vectorFOV.at(x).flSpec) vecBarChartItem[uiIndex].uiColorIndex = 2;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
			}
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(x).flSpecUniform;
			vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(x).flUniformValue;
			vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 2) % "\nU";
			if(vecBarChartItem[uiIndex].flValue <= stItemData.vectorFOV.at(x).flSpecUniform) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex = 0;
			++uiIndex;
			++uiGroupIndex;
		}
	}

	__inline void fillMTFAFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisAutoFA_Rolongo_DataItem& stItemData, int iWidth, int iHeight)
	{
		unsigned int uiItemCount = 2;
		for(unsigned int x=0;	x<stItemData.vectorMTFFOV.size(); ++x)
			uiItemCount	+=	stItemData.vectorMTFFOV.at(x).ucBlockCount;
		uiItemCount	+=	stItemData.vectorMTFFOV.size();
		vecBarChartItem.resize(uiItemCount);

		unsigned int uiGroupIndex	=	0;
		vecBarChartItem[0].flValue				=	stItemData.flMTFCenterValue;
		vecBarChartItem[0].flDotLine			=	stItemData.flMTFCenterSpec;
		vecBarChartItem[0].uiGroupIndex	=	uiGroupIndex;
		vecBarChartItem[0].strTitle				=	"CT";
		if(stItemData.flMTFCenterValue >= stItemData.flMTFCenterSpec) vecBarChartItem[0].uiColorIndex	=	1;
		else vecBarChartItem[0].uiColorIndex	=	0;

		vecBarChartItem[1].flValue				=	stItemData.flWeightValue;
		vecBarChartItem[1].flDotLine			=	0.0f;
		vecBarChartItem[1].uiGroupIndex	=	uiGroupIndex;
		vecBarChartItem[1].strTitle				=	"WT";
		if(stItemData.ucStatus > 0) vecBarChartItem[1].uiColorIndex	=	1;
		else vecBarChartItem[1].uiColorIndex	=	0;

		++uiGroupIndex;
		unsigned int uiIndex	=	2;
		for(unsigned int x=0;	x<stItemData.vectorMTFFOV.size(); ++x)
		{
			for(unsigned int i=0;	i<stItemData.vectorMTFFOV.at(x).ucBlockCount;	++i){
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorMTFFOV.at(x).flSpec;
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorMTFFOV.at(x).flValue[i];
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorMTFFOV.at(x).flFOV, 'f', 2) % "\n" %  getBlockName(stItemData.vectorMTFFOV.at(x).stBlock[i], iWidth, iHeight);
				if(vecBarChartItem[uiIndex].flValue >= stItemData.vectorMTFFOV.at(x).flSpec) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
			}
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorMTFFOV.at(x).flSpecUniform;
			vecBarChartItem[uiIndex].flValue			=	stItemData.vectorMTFFOV.at(x).flUniformValue;
			vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorMTFFOV.at(x).flFOV, 'f', 2) % "\nU";
			if(vecBarChartItem[uiIndex].flValue <= stItemData.vectorMTFFOV.at(x).flSpecUniform) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex = 0;
			++uiIndex;
			++uiGroupIndex;
		}
	}

	__inline void fillSFRFALensBarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisCCMAlg_AFC_SFRHA_DataItem& stItemData, _SFRFACAParameter* pstParam, int iWidth, int iHeight, const float cflGradeAPercent)
	{
		unsigned int uiItemCount = 2;	
		for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
		{
			uiItemCount	=	uiItemCount + (stItemData.vectorFOV.at(w).ucBlockCount <<1);
		}
		vecBarChartItem.resize(uiItemCount);
		
		QString strTitle;
		unsigned int uiGroupIndex	=	0, uiIndex	=	0;
		//CT-H
		vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueH_L, stItemData.stSFRCenterMTF50.flValueH_R);
		vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenterMTF50SpecH;
		vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
		vecBarChartItem[uiIndex].strTitle			=	"CT-H";
		if(vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50SpecH) vecBarChartItem[uiIndex].uiColorIndex	=	1;
		else if(vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeBH) vecBarChartItem[uiIndex].uiColorIndex	=	2;
		else if(pstParam->stSFRBasic.ucGradeCount >3 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeCH) vecBarChartItem[uiIndex].uiColorIndex	=	3;
		else if(pstParam->stSFRBasic.ucGradeCount >4 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeDH) vecBarChartItem[uiIndex].uiColorIndex	=	4;
		else if(pstParam->stSFRBasic.ucGradeCount >5 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeEH) vecBarChartItem[uiIndex].uiColorIndex	=	5;
		else vecBarChartItem[uiIndex].uiColorIndex	=	0;
		++uiIndex;
		//CT-V
		vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueV_T, stItemData.stSFRCenterMTF50.flValueV_B);
		vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenterMTF50SpecV;
		vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
		vecBarChartItem[uiIndex].strTitle			=	"CT-V";
		if(vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50SpecV) vecBarChartItem[uiIndex].uiColorIndex	=	1;
		else if(vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeBV) vecBarChartItem[uiIndex].uiColorIndex	=	2;
		else if(pstParam->stSFRBasic.ucGradeCount >3 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeCV) vecBarChartItem[uiIndex].uiColorIndex	=	3;
		else if(pstParam->stSFRBasic.ucGradeCount >4 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeDV) vecBarChartItem[uiIndex].uiColorIndex	=	4;
		else if(pstParam->stSFRBasic.ucGradeCount >5 && vecBarChartItem[uiIndex].flValue >= pstParam->stSFRBasic.flCenterMTF50GradeEV) vecBarChartItem[uiIndex].uiColorIndex	=	5;
		else vecBarChartItem[uiIndex].uiColorIndex	=	0;
		++uiIndex;
		++uiGroupIndex;

		for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
		{
			for(unsigned int x=0;	x<stItemData.vectorFOV.at(w).ucBlockCount;	++x)
			{
				if(stItemData.vectorFOV.at(w).stBlock[x].stLeft.bottom)
					strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
				else if(stItemData.vectorFOV.at(w).stBlock[x].stRight.bottom)
					strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
				else if(stItemData.vectorFOV.at(w).stBlock[x].stTop.bottom)
					strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
				else
					strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
				//H
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueH_L, stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueH_R);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;			
				vecBarChartItem[uiIndex].strTitle			=	strTitle% "-H";
				if(vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50SpecH) vecBarChartItem[uiIndex].uiColorIndex	=	1;
				else if(vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeBH) vecBarChartItem[uiIndex].uiColorIndex	=	2;
				else if(pstParam->stSFRBasic.ucGradeCount >3 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeCH) vecBarChartItem[uiIndex].uiColorIndex	=	3;
				else if(pstParam->stSFRBasic.ucGradeCount >4 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeDH) vecBarChartItem[uiIndex].uiColorIndex	=	4;
				else if(pstParam->stSFRBasic.ucGradeCount >5 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeEH) vecBarChartItem[uiIndex].uiColorIndex	=	5;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//V
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueV_T, stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueV_B);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";
				if(vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50SpecV) vecBarChartItem[uiIndex].uiColorIndex	=	1;
				else if(vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeBV) vecBarChartItem[uiIndex].uiColorIndex	=	2;
				else if(pstParam->stSFRBasic.ucGradeCount >3 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeCV) vecBarChartItem[uiIndex].uiColorIndex	=	3;
				else if(pstParam->stSFRBasic.ucGradeCount >4 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeDV) vecBarChartItem[uiIndex].uiColorIndex	=	4;
				else if(pstParam->stSFRBasic.ucGradeCount >5 && vecBarChartItem[uiIndex].flValue >= pstParam->vectorSFRItem.at(w).flMTF50GradeEV) vecBarChartItem[uiIndex].uiColorIndex	=	5;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
			}

			++uiGroupIndex;
		}
	}

	__inline void fillSFRFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisCCMAlg_AFC_SFRHA_DataItem& stItemData, _HisCCMAlg_SFRPlusHABasic_Info* pstBasic, int iWidth, int iHeight, const float cflGradeAPercent)
	{
		unsigned int uiItemCount = 2;	
		for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
		{
			uiItemCount	 =	uiItemCount +(stItemData.vectorFOV.at(w).ucBlockCount <<1)+2;
		}

		if(pstBasic->ucMethod == _His_SFR_Method_2Freq && pstBasic->b2ndFreq)
			uiItemCount	*=	2;
		vecBarChartItem.resize(uiItemCount);

		QString strTitle;
		unsigned int uiGroupIndex	=	0, uiIndex	=	0;
		if(pstBasic->ucMethod == _His_SFR_Method_2Freq)
		{
			//CT-H
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq1.flValueH_L, stItemData.stSFRCenterFreq1.flValueH_R);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenter1stFreqSpecH;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"F1\nCT-H";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			//CT-V
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq1.flValueV_T, stItemData.stSFRCenterFreq1.flValueV_B);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenter1stFreqSpecV;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"F1\nCT-V";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			++uiGroupIndex;
		
			for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
			{
				for(unsigned int x=0;	x<stItemData.vectorFOV.at(w).ucBlockCount;	++x)
				{
					if(stItemData.vectorFOV.at(w).stBlock[x].stLeft.bottom)
						strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(w).stBlock[x].stRight.bottom)
						strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(w).stBlock[x].stTop.bottom)
						strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
					else
						strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
					//H
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRFreq1[x].flValueH_L, stItemData.vectorFOV.at(w).stSFRFreq1[x].flValueH_R);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl1stFreqSpecH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-H";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRFreq1[x].flValueV_T, stItemData.vectorFOV.at(w).stSFRFreq1[x].flValueV_B);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl1stFreqSpecV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";;
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
				}

				//H
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flFreq1UnifH;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl1stFreqSpecUnifH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" %  "U-H";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//V
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flFreq1UnifV;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl1stFreqSpecUnifV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F1\n" % "U-V";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;
			}

			if(pstBasic->b2ndFreq){
				//CT-H
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq2.flValueH_L, stItemData.stSFRCenterFreq2.flValueH_R);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenter2ndFreqSpecH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	"F2\nCT-H";
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//CT-V
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq2.flValueV_T, stItemData.stSFRCenterFreq2.flValueV_B);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenter2ndFreqSpecV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	"F2\nCT-V";
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;

				for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
				{
					for(unsigned int x=0;	x<stItemData.vectorFOV.at(w).ucBlockCount;	++x)
					{
						if(stItemData.vectorFOV.at(w).stBlock[x].stLeft.bottom)
							strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
						else if(stItemData.vectorFOV.at(w).stBlock[x].stRight.bottom)
							strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
						else if(stItemData.vectorFOV.at(w).stBlock[x].stTop.bottom)
							strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
						else
							strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
						//H
						vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRFreq2[x].flValueH_L, stItemData.vectorFOV.at(w).stSFRFreq2[x].flValueH_R);
						vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl2ndFreqSpecH;
						vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
						vecBarChartItem[uiIndex].strTitle			=	strTitle % "-H";;
						if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
						else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
						else vecBarChartItem[uiIndex].uiColorIndex	=	0;
						++uiIndex;
						//V
						vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRFreq2[x].flValueV_T, stItemData.vectorFOV.at(w).stSFRFreq2[x].flValueV_B);
						vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl2ndFreqSpecV;
						vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
						vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";;
						if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
						else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
						else vecBarChartItem[uiIndex].uiColorIndex	=	0;
						++uiIndex;
					}

					//H
					vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flFreq2UnifH;
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl2ndFreqSpecUnifH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" %  "U-H";;
					if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flFreq2UnifV;
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).fl2ndFreqSpecUnifV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "F2\n" % "U-V";;
					if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					++uiGroupIndex;
				}
			}
		}
		else //MTF50
		{
			//CT-H
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueH_L, stItemData.stSFRCenterMTF50.flValueH_R);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenterMTF50SpecH;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"CT-H";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			//CT-V
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueV_T, stItemData.stSFRCenterMTF50.flValueV_B);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flCenterMTF50SpecV;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"CT-V";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			++uiGroupIndex;

			for(unsigned int w=0;	w<stItemData.vectorFOV.size();	++w)
			{
				for(unsigned int x=0;	x<stItemData.vectorFOV.at(w).ucBlockCount;	++x)
				{
					if(stItemData.vectorFOV.at(w).stBlock[x].stLeft.bottom)
						strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(w).stBlock[x].stRight.bottom)
						strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
					else if(stItemData.vectorFOV.at(w).stBlock[x].stTop.bottom)
						strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
					else
						strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
					//H
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueH_L, stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueH_R);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;			
					vecBarChartItem[uiIndex].strTitle			=	strTitle% "-H";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueV_T, stItemData.vectorFOV.at(w).stSFRMTF50[x].flValueV_B);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
				}

				//H
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flMTF50UnifH;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecUnifH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" %  "U-H";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//V
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flMTF50UnifV;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flMTF50SpecUnifV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % "U-V";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;
			}
		}
	}

	__inline void fillSFRAFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisAutoFA_Rolongo_DataItem& stItemData, _HisCCMAlg_SFRPlusHABasic_Info* pstBasic, int iWidth, int iHeight)
	{
		unsigned int uiItemCount = 2;	
		for(unsigned int w=0;	w<stItemData.vectorSFRFOV.size();	++w)
			uiItemCount	=	uiItemCount + (stItemData.vectorSFRFOV.at(w).ucBlockCount <<1) +2;
		if(pstBasic->ucMethod == _His_SFR_Method_2Freq && pstBasic->b2ndFreq)
			uiItemCount	*=	2;
		uiItemCount += 1;
		vecBarChartItem.resize(uiItemCount);

		QString strTitle;
		unsigned int uiGroupIndex	=	0, uiIndex	=	0;
		if(pstBasic->ucMethod == _His_SFR_Method_2Freq)
		{
			//CT-H
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq1.flValueH_L, stItemData.stSFRCenterFreq1.flValueH_R);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenter1stFreqSpecH;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"F1\nCT-H";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			//CT-V
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq1.flValueV_T, stItemData.stSFRCenterFreq1.flValueV_B);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenter1stFreqSpecV;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"F1\nCT-V";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;

			//WT
			vecBarChartItem[uiIndex].flValue			=	stItemData.flWeightValue;
			vecBarChartItem[uiIndex].flDotLine		=	0.0;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"F1\nWT";
			if(stItemData.ucStatus > 0) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			++uiGroupIndex;

			for(unsigned int w=0;	w<stItemData.vectorSFRFOV.size();	++w)
			{
				for(unsigned int x=0;	x<stItemData.vectorSFRFOV.at(w).ucBlockCount;	++x)
				{
					if(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft.bottom)
						strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
					else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight.bottom)
						strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
					else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop.bottom)
						strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
					else
						strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
					//H
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRFreq1[x].flValueH_L, stItemData.vectorSFRFOV.at(w).stSFRFreq1[x].flValueH_R);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl1stFreqSpecH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-H";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRFreq1[x].flValueV_T, stItemData.vectorSFRFOV.at(w).stSFRFreq1[x].flValueV_B);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl1stFreqSpecV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";;
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
				}

				//H
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flFreq1UnifH;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl1stFreqSpecUnifH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" %  "U-H";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//V
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flFreq1UnifV;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl1stFreqSpecUnifV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F1\n" % "U-V";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;
			}

			if(pstBasic->b2ndFreq)
			{
				//CT-H
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq2.flValueH_L, stItemData.stSFRCenterFreq2.flValueH_R);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenter2ndFreqSpecH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	"F2\nCT-H";
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//CT-V
				vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterFreq2.flValueV_T, stItemData.stSFRCenterFreq2.flValueV_B);
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenter2ndFreqSpecV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	"F2\nCT-V";
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;

				for(unsigned int w=0;	w<stItemData.vectorSFRFOV.size();	++w)
				{
					for(unsigned int x=0;	x<stItemData.vectorSFRFOV.at(w).ucBlockCount;	++x)
					{
						if(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft.bottom)
							strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
						else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight.bottom)
							strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
						else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop.bottom)
							strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
						else
							strTitle	=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
						//H
						vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRFreq2[x].flValueH_L, stItemData.vectorSFRFOV.at(w).stSFRFreq2[x].flValueH_R);
						vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl2ndFreqSpecH;
						vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
						vecBarChartItem[uiIndex].strTitle			=	strTitle % "-H";;
						if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
						else vecBarChartItem[uiIndex].uiColorIndex	=	0;
						++uiIndex;
						//V
						vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRFreq2[x].flValueV_T, stItemData.vectorSFRFOV.at(w).stSFRFreq2[x].flValueV_B);
						vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl2ndFreqSpecV;
						vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
						vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";;
						if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
						else vecBarChartItem[uiIndex].uiColorIndex	=	0;
						++uiIndex;
					}

					//H
					vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flFreq2UnifH;
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl2ndFreqSpecUnifH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" %  "U-H";;
					if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flFreq2UnifV;
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).fl2ndFreqSpecUnifV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "F2\n" % "U-V";;
					if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					++uiGroupIndex;
				}
			}
		}
		else //MTF50
		{
			//CT-H
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueH_L, stItemData.stSFRCenterMTF50.flValueH_R);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenterMTF50SpecH;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"CT-H";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			//CT-V
			vecBarChartItem[uiIndex].flValue			=	min(stItemData.stSFRCenterMTF50.flValueV_T, stItemData.stSFRCenterMTF50.flValueV_B);
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.flSFRCenterMTF50SpecV;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"CT-V";
			if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;

			//WT
			vecBarChartItem[uiIndex].flValue			=	stItemData.flWeightValue;
			vecBarChartItem[uiIndex].flDotLine		=	0.0f;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle			=	"WT";
			if(stItemData.ucStatus > 0) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex	=	0;
			++uiIndex;
			++uiGroupIndex;

			for(unsigned int w=0;	w<stItemData.vectorSFRFOV.size();	++w)
			{
				for(unsigned int x=0;	x<stItemData.vectorSFRFOV.at(w).ucBlockCount;	++x)
				{
					if(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft.bottom)
						strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stLeft, iWidth, iHeight);
					else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight.bottom)
						strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stRight, iWidth, iHeight);
					else if(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop.bottom)
						strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stTop, iWidth, iHeight);
					else
						strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorSFRFOV.at(w).stBlock[x].stBottom, iWidth, iHeight);
					//H
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRMTF50[x].flValueH_L, stItemData.vectorSFRFOV.at(w).stSFRMTF50[x].flValueH_R);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).flMTF50SpecH;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;			
					vecBarChartItem[uiIndex].strTitle			=	strTitle% "-H";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
					//V
					vecBarChartItem[uiIndex].flValue			=	min(stItemData.vectorSFRFOV.at(w).stSFRMTF50[x].flValueV_T, stItemData.vectorSFRFOV.at(w).stSFRMTF50[x].flValueV_B);
					vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).flMTF50SpecV;
					vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
					vecBarChartItem[uiIndex].strTitle			=	strTitle % "-V";
					if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
					else vecBarChartItem[uiIndex].uiColorIndex	=	0;
					++uiIndex;
				}

				//H
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flMTF50UnifH;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).flMTF50SpecUnifH;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" %  "U-H";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				//V
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorSFRFOV.at(w).flMTF50UnifV;
				vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorSFRFOV.at(w).flMTF50SpecUnifV;
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle			=	QString::number(stItemData.vectorSFRFOV.at(w).flFOV, 'f', 2) % "\n" % "U-V";;
				if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex	=	0;
				++uiIndex;
				++uiGroupIndex;
			}
		}
	}



	__inline void fillLpFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisCCMAlg_AFC_LP_DataItem& stItemData, int iWidth, int iHeight, const float cflGradeAPercent)
	{
		unsigned int uiItemCount = stItemData.vectorFOV.size() *5;
		vecBarChartItem.resize(uiItemCount);

		unsigned int uiGroupIndex = 0, uiIndex = 0;
		int iCenterX, iCenterY;
		for(unsigned int w=0;	w<stItemData.vectorFOV.size(); ++w)
		{
			iCenterX	=	iCenterY = 0;
			for(unsigned int x=0;	x<4;	++x){
				iCenterX	+=	stItemData.vectorFOV.at(w).stBlock[x].left;
				iCenterX	+=	stItemData.vectorFOV.at(w).stBlock[x].right;
				iCenterY	+=	stItemData.vectorFOV.at(w).stBlock[x].top;
				iCenterY	+=	stItemData.vectorFOV.at(w).stBlock[x].bottom;
			}

			iCenterX	=	(iCenterX >>2);
			iCenterY	=	(iCenterY >>2);

			for(unsigned int x=0;	x<4;	++x){
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).stLpValue[x].flValue;
				vecBarChartItem[uiIndex].flDotLine		=	(stItemData.vectorFOV.at(w).stLpValue[x].ucOrientation == 0)?(stItemData.vectorFOV.at(w).flSpecHor):(stItemData.vectorFOV.at(w).flSpecVec);
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorFOV.at(w).stBlock[x], iCenterX, iCenterY);
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine *cflGradeAPercent) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 2;
				else vecBarChartItem[uiIndex].uiColorIndex = 0;
				++uiIndex;
			}

			vecBarChartItem[uiIndex].flValue			=	stItemData.vectorFOV.at(w).flUniformValue;
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorFOV.at(w).flSpecUniform;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle	=	QString::number(stItemData.vectorFOV.at(w).flFOV, 'f', 2) % "\nU";
			if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex = 0;
			++uiIndex;
			++uiGroupIndex;
		}
	}

	__inline void fillLpAFABarChartDrawInfo(QVector<_HBarChart_SelfItem>& vecBarChartItem, _HisAutoFA_Rolongo_DataItem& stItemData, int iWidth, int iHeight)
	{
		unsigned int uiItemCount = stItemData.vectorLPFOV.size() *5;
		vecBarChartItem.resize(uiItemCount);

		unsigned int uiGroupIndex = 0, uiIndex = 0;
		vecBarChartItem[uiIndex].flValue			=	stItemData.flWeightValue;
		vecBarChartItem[uiIndex].flDotLine		=	0.0f;
		vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
		vecBarChartItem[uiIndex].strTitle	=	"WT";
		if(stItemData.ucStatus > 0) vecBarChartItem[uiIndex].uiColorIndex = 1;
		else vecBarChartItem[uiIndex].uiColorIndex = 0;
		++uiIndex;
		++uiGroupIndex;

		int iCenterX, iCenterY;
		for(unsigned int w=0;	w<stItemData.vectorLPFOV.size(); ++w)
		{
			iCenterX	=	iCenterY = 0;
			for(unsigned int x=0;	x<4;	++x){
				iCenterX	+=	stItemData.vectorLPFOV.at(w).stBlock[x].left;
				iCenterX	+=	stItemData.vectorLPFOV.at(w).stBlock[x].right;
				iCenterY	+=	stItemData.vectorLPFOV.at(w).stBlock[x].top;
				iCenterY	+=	stItemData.vectorLPFOV.at(w).stBlock[x].bottom;
			}

			iCenterX	=	(iCenterX >>2);
			iCenterY	=	(iCenterY >>2);

			for(unsigned int x=0;	x<4;	++x){
				vecBarChartItem[uiIndex].flValue			=	stItemData.vectorLPFOV.at(w).stLpValue[x].flValue;
				vecBarChartItem[uiIndex].flDotLine		=	(stItemData.vectorLPFOV.at(w).stLpValue[x].ucOrientation == 0)?(stItemData.vectorLPFOV.at(w).flSpecHor):(stItemData.vectorLPFOV.at(w).flSpecVec);
				vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
				vecBarChartItem[uiIndex].strTitle	=	QString::number(stItemData.vectorLPFOV.at(w).flFOV, 'f', 2) % "\n" % getBlockName(stItemData.vectorLPFOV.at(w).stBlock[x], iCenterX, iCenterY);
				if(vecBarChartItem[uiIndex].flValue >= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
				else vecBarChartItem[uiIndex].uiColorIndex = 0;
				++uiIndex;
			}

			vecBarChartItem[uiIndex].flValue			=	stItemData.vectorLPFOV.at(w).flUniformValue;
			vecBarChartItem[uiIndex].flDotLine		=	stItemData.vectorLPFOV.at(w).flSpecUniform;
			vecBarChartItem[uiIndex].uiGroupIndex	=	uiGroupIndex;
			vecBarChartItem[uiIndex].strTitle	=	QString::number(stItemData.vectorLPFOV.at(w).flFOV, 'f', 2) % "\nU";
			if(vecBarChartItem[uiIndex].flValue <= vecBarChartItem[uiIndex].flDotLine) vecBarChartItem[uiIndex].uiColorIndex = 1;
			else vecBarChartItem[uiIndex].uiColorIndex = 0;
			++uiIndex;
			++uiGroupIndex;
		}
	}

	__inline void saveMTFHAMFAResult(bool bResult, _HisCCMAlg_AFC_MTF_DataItem& stItemData, _mtffaParameter* pstParameter, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "fa_mtf_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_MTFFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center";
		logitem.itemvalue	=	stItemData.flCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
				strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i], iWidth, iHeight);

				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorFOV.at(x).flValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey		=	strKey2 % "Tilt";
			logitem.itemvalue	=	stItemData.vectorFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void saveMTFHAMFAResult_G(bool bResult, _HisCCMAlg_AFC_MTF_DataItem_EX& stItemData, _mtffaParameter* pstParameter, HisFX3Log& classLog, int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "fa_mtf_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_MTFFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center_H";
		logitem.itemvalue	=	stItemData.flHCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	strKey2 % "center_V";
		logitem.itemvalue	=	stItemData.flVCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<stItemData.vectorFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(stItemData.vectorFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<stItemData.vectorFOV.at(x).ucBlockCount;	++i){
				strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i], iWidth, iHeight)% "_H";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorFOV.at(x).flHValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);

				strKey3		=	strKey2 % getBlockName(stItemData.vectorFOV.at(x).stBlock[i], iWidth, iHeight)% "_V";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorFOV.at(x).flVValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
		}
	}

	__inline int GetLinearResult(_HisCCMAlg_AFC_Linear_Result& stLinearConfig)
	{
		stLinearConfig.bResult = true;
		std::vector<_HisCCMAlg_AFC_Linear_Item> vectorCopy;
		std::vector<_HisCCMAlg_AFC_Linear_Item>::iterator theiteraoter;
		vectorCopy.reserve(stLinearConfig.vectorItemData.size());

		if(stLinearConfig.bTestStartMotor){
			for(theiteraoter = stLinearConfig.vectorItemData.begin(); theiteraoter != stLinearConfig.vectorItemData.end(); theiteraoter++){
				if(theiteraoter->ucFlag == 0x0) vectorCopy.push_back(*theiteraoter);
			}

			for(theiteraoter = vectorCopy.begin() + 1; theiteraoter != vectorCopy.end(); theiteraoter++){
				if(fabsf(theiteraoter->flValue - vectorCopy.begin()->flValue) >= stLinearConfig.flStartMotorDevDef){
					stLinearConfig.iStartMotor	=	(theiteraoter-1)->iMotor;
					break;
				}
			}

			if(stLinearConfig.iStartMotor == 0x00FFFFFF || stLinearConfig.iStartMotor < stLinearConfig.iStartMotorMin || stLinearConfig.iStartMotor > stLinearConfig.iStartMotorMax)
				stLinearConfig.bResult	=	false;
		}

		return 0;
	}

	__inline void AFARolongoItemDataInitial(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, _HisAutoFA_BASIC_STACTICS* afaBasicStacticsParameter, \
		_mtffaParameter* mtffaParameter, _SFRFACAParameter* sfrfacaParameter, _lpMFAParameter* lpmfaParameter, double& dflAbsAngle, \
	 unsigned char uclensleafs, double dflLenPitch, unsigned char ucDirect, unsigned char ucType, _AutoFA_YIOUV1_EQUI_VALUE* pstEqupInfo)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		std::vector<_HisAutoFA_Rolongo_DataItem>::iterator theiterator = vectorItemData.begin() + uiIndex;

		theiterator->ucStatus				=	0x0;
		theiterator->dflMarkDistance	=	0.0;
		theiterator->ucGrade				=	0;
		theiterator->ucType					=	0;
		theiterator->flWeightValue		=	0.0f;
		theiterator->dflAbsAngle			=	dflAbsAngle;
		theiterator->ucDirect				=	ucDirect;
		theiterator->ucType					=	ucType;

		if(pstEqupInfo == NULL){
			theiterator->dflRadius			=	0.0;
			theiterator->dflLesnAngle	=	0.0;
			theiterator->dflLaser			=	0.0;
		}
		else
		{
			theiterator->dflRadius				=	pstEqupInfo->dflLensRadius;
			theiterator->dflLesnAngle		=	pstEqupInfo->dflLensAngle + dflAbsAngle;
			theiterator->dflLaser				=	pstEqupInfo->dflLaserValue - dflAbsAngle *dflLenPitch /360.0;

			double dfldata	=	360.0 / static_cast<double>(uclensleafs);
			int ivalue	=	(int)(theiterator->dflLesnAngle) / 360;
			theiterator->dflLesnAngle -= (360 *ivalue);
			if(theiterator->dflLesnAngle > 180.0)
			{
				theiterator->dflLesnAngle = theiterator->dflLesnAngle - dfldata;
				if(theiterator->dflLesnAngle > 180.0)	theiterator->dflLesnAngle = theiterator->dflLesnAngle - dfldata;
			}
			else if(theiterator->dflLesnAngle < 0.0)
			{
				theiterator->dflLesnAngle	=	theiterator->dflLesnAngle + dfldata;
				if(theiterator->dflLesnAngle < 0.0)	theiterator->dflLesnAngle = theiterator->dflLesnAngle + dfldata;
			}
		}

		if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
			afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B)
		{
			theiterator->flMTFCenterValue		=	0.0f;
			theiterator->flMTFCenterWeight		=	mtffaParameter->stMTFBasic.flcenterweight;
			theiterator->flMTFCenterSpec		=	mtffaParameter->stMTFBasic.flcenterspec;
			memset(&(theiterator->stMTFCenterBlock), 0, sizeof(RECT));

			unsigned int uiFOVSize	=	(unsigned int)mtffaParameter->vectorMTFItem.size();
			theiterator->vectorMTFFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorMTFFOV.at(x).ucStatus	=	0x0;
				theiterator->vectorMTFFOV.at(x).ucBlockCount		=	mtffaParameter->vectorMTFItem.at(x).ucBlockCount;
				theiterator->vectorMTFFOV.at(x).flFOV			=	mtffaParameter->vectorMTFItem.at(x).flFOV;
				theiterator->vectorMTFFOV.at(x).flAngle		=	mtffaParameter->vectorMTFItem.at(x).flAngle;
				theiterator->vectorMTFFOV.at(x).flWeight		=	mtffaParameter->vectorMTFItem.at(x).flWeight;
				theiterator->vectorMTFFOV.at(x).flSpec		=	mtffaParameter->vectorMTFItem.at(x).flSpec;
				theiterator->vectorMTFFOV.at(x).flSpecUniform		=	mtffaParameter->vectorMTFItem.at(x).flSpecUniform;

				theiterator->vectorMTFFOV.at(x).flUniformValue	=	0.0f;
				memset(theiterator->vectorMTFFOV.at(x).flValue, 0, sizeof(float) *4);
				memset(theiterator->vectorMTFFOV.at(x).stBlock, 0, sizeof(RECT) *4);
			}
		}
		else if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A)
		{
			theiterator->flSFRCenterWeight		=	sfrfacaParameter->stSFRBasic.flCenterWeight;
			theiterator->bSFR2ndFreq				=	sfrfacaParameter->stSFRBasic.b2ndFreq;
			theiterator->ucSFRMethod				=	sfrfacaParameter->stSFRBasic.ucMethod;
			theiterator->flSFRCenterMTF50SpecH				=	sfrfacaParameter->stSFRBasic.flCenterMTF50SpecH;
			theiterator->flSFRCenterMTF50SpecV				=	sfrfacaParameter->stSFRBasic.flCenterMTF50SpecV;
			theiterator->flSFRCenter1stFreqSpecH			=	sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecH;
			theiterator->flSFRCenter1stFreqSpecV				=	sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecV;
			theiterator->flSFRCenter2ndFreqSpecH			=	sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecH;
			theiterator->flSFRCenter2ndFreqSpecV			=	sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecV;

			memset(&(theiterator->stSFRCenterMTF50), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterFreq1), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterFreq2), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterBlock), 0, sizeof(_SFRBlackROI4));

			unsigned int uiFOVSize	=	sfrfacaParameter->vectorSFRItem.size();
			theiterator->vectorSFRFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorSFRFOV.at(x).ucStatus	=	0x0;
				theiterator->vectorSFRFOV.at(x).flMTF50UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flMTF50UnifV	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq1UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq1UnifV	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq2UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq2UnifV	=	0.0f;

				theiterator->vectorSFRFOV.at(x).flFOV		=	sfrfacaParameter->vectorSFRItem.at(x).flFOV;
				theiterator->vectorSFRFOV.at(x).ucBlockCount		=	sfrfacaParameter->vectorSFRItem.at(x).ucBlockCount;
				theiterator->vectorSFRFOV.at(x).flAngle		=	sfrfacaParameter->vectorSFRItem.at(x).flAngle;
				theiterator->vectorSFRFOV.at(x).flWeight		=	sfrfacaParameter->vectorSFRItem.at(x).flWeight;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecH		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecH;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecV		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecV;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecH		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecH;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecV		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecV;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecH		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecH;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecV		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecV;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecUnifH;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecUnifV;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifH;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifV;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifH;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifV;
				memset(theiterator->vectorSFRFOV.at(x).stSFRMTF50, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stSFRFreq1, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stSFRFreq2, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stBlock, 0, sizeof(_SFRBlackROI4) *4);
			}
		}
		else{
			unsigned int uiFOVSize	=	lpmfaParameter->vectorLpItem.size();
			theiterator->vectorLPFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorLPFOV.at(x).flFOV		=	lpmfaParameter->vectorLpItem.at(x).flFOV;
				theiterator->vectorLPFOV.at(x).flAngle	=	lpmfaParameter->vectorLpItem.at(x).flAngle;
				theiterator->vectorLPFOV.at(x).flSpecHor	=	lpmfaParameter->vectorLpItem.at(x).flSpecHor;
				theiterator->vectorLPFOV.at(x).flSpecVec	=	lpmfaParameter->vectorLpItem.at(x).flSpecVec;
				theiterator->vectorLPFOV.at(x).flSpecUniform	=	lpmfaParameter->vectorLpItem.at(x).flSpecUniform;
				theiterator->vectorLPFOV.at(x).flWeight		=	lpmfaParameter->vectorLpItem.at(x).flWeight;
				theiterator->vectorLPFOV.at(x).ucStatus	=	0x0;
				memset(theiterator->vectorLPFOV.at(x).stLpValue, 0, sizeof(_HisCCMAlg_Resolution) *4);
				memset(theiterator->vectorLPFOV.at(x).stValueLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stMinLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stMaxLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stBlock, 0, sizeof(RECT) *4);
			}
		}
	}

	__inline void AFARolongoItemDataInitial_Ex(std::vector<_HisAutoFA_Rolongo_DataItem_EX>& vectorItemData, _HisAutoFA_BASIC_STACTICS* afaBasicStacticsParameter, \
		_mtffaParameter* mtffaParameter, _SFRFACAParameter* sfrfacaParameter, _lpMFAParameter* lpmfaParameter, double& dflAbsAngle, \
		unsigned char uclensleafs, double dflLenPitch, unsigned char ucDirect, unsigned char ucType, _AutoFA_YIOUV1_EQUI_VALUE* pstEqupInfo)
	{
		unsigned int uiIndex	=	vectorItemData.size();
		vectorItemData.resize(uiIndex + 1);
		std::vector<_HisAutoFA_Rolongo_DataItem_EX>::iterator theiterator = vectorItemData.begin() + uiIndex;

		theiterator->ucStatus				=	0x0;
		theiterator->dflMarkDistance	=	0.0;
		theiterator->ucGrade				=	0;
		theiterator->ucType					=	0;
		theiterator->flWeightValue		=	0.0f;
		theiterator->dflAbsAngle			=	dflAbsAngle;
		theiterator->ucDirect				=	ucDirect;
		theiterator->ucType					=	ucType;

		if(pstEqupInfo == NULL){
			theiterator->dflRadius			=	0.0;
			theiterator->dflLesnAngle	=	0.0;
			theiterator->dflLaser			=	0.0;
		}
		else
		{
			theiterator->dflRadius				=	pstEqupInfo->dflLensRadius;
			theiterator->dflLesnAngle		=	pstEqupInfo->dflLensAngle + dflAbsAngle;
			theiterator->dflLaser				=	pstEqupInfo->dflLaserValue - dflAbsAngle *dflLenPitch /360.0;

			double dfldata	=	360.0 / static_cast<double>(uclensleafs);
			int ivalue	=	(int)(theiterator->dflLesnAngle) / 360;
			theiterator->dflLesnAngle -= (360 *ivalue);
			if(theiterator->dflLesnAngle > 180.0)
			{
				theiterator->dflLesnAngle = theiterator->dflLesnAngle - dfldata;
				if(theiterator->dflLesnAngle > 180.0)	theiterator->dflLesnAngle = theiterator->dflLesnAngle - dfldata;
			}
			else if(theiterator->dflLesnAngle < 0.0)
			{
				theiterator->dflLesnAngle	=	theiterator->dflLesnAngle + dfldata;
				if(theiterator->dflLesnAngle < 0.0)	theiterator->dflLesnAngle = theiterator->dflLesnAngle + dfldata;
			}
		}

		if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
			afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B)
		{
			theiterator->flMTFCenterValue		=	0.0f;
			theiterator->flMTFCenterWeight		=	mtffaParameter->stMTFBasic.flcenterweight;
			theiterator->flMTFCenterSpec		=	mtffaParameter->stMTFBasic.flcenterspec;
			memset(&(theiterator->stMTFCenterBlock), 0, sizeof(RECT));

			unsigned int uiFOVSize	=	(unsigned int)mtffaParameter->vectorMTFItem.size();
			theiterator->vectorMTFFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorMTFFOV.at(x).ucStatus	=	0x0;
				theiterator->vectorMTFFOV.at(x).ucBlockCount		=	mtffaParameter->vectorMTFItem.at(x).ucBlockCount;
				theiterator->vectorMTFFOV.at(x).flFOV			=	mtffaParameter->vectorMTFItem.at(x).flFOV;
				theiterator->vectorMTFFOV.at(x).flAngle		=	mtffaParameter->vectorMTFItem.at(x).flAngle;
				theiterator->vectorMTFFOV.at(x).flWeight		=	mtffaParameter->vectorMTFItem.at(x).flWeight;
				theiterator->vectorMTFFOV.at(x).flSpec		=	mtffaParameter->vectorMTFItem.at(x).flSpec;
				theiterator->vectorMTFFOV.at(x).flSpecUniform		=	mtffaParameter->vectorMTFItem.at(x).flSpecUniform;

				theiterator->vectorMTFFOV.at(x).flUniformValue	=	0.0f;
				memset(theiterator->vectorMTFFOV.at(x).flValue, 0, sizeof(float) *4);
				memset(theiterator->vectorMTFFOV.at(x).stBlock, 0, sizeof(RECT) *4);
			}
		}
		else if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A)
		{
			theiterator->flSFRCenterWeight		=	sfrfacaParameter->stSFRBasic.flCenterWeight;
			theiterator->bSFR2ndFreq				=	sfrfacaParameter->stSFRBasic.b2ndFreq;
			theiterator->ucSFRMethod				=	sfrfacaParameter->stSFRBasic.ucMethod;
			theiterator->flSFRCenterMTF50SpecH				=	sfrfacaParameter->stSFRBasic.flCenterMTF50SpecH;
			theiterator->flSFRCenterMTF50SpecV				=	sfrfacaParameter->stSFRBasic.flCenterMTF50SpecV;
			theiterator->flSFRCenter1stFreqSpecH			=	sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecH;
			theiterator->flSFRCenter1stFreqSpecV				=	sfrfacaParameter->stSFRBasic.flCenter1stFreqSpecV;
			theiterator->flSFRCenter2ndFreqSpecH			=	sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecH;
			theiterator->flSFRCenter2ndFreqSpecV			=	sfrfacaParameter->stSFRBasic.flCenter2ndFreqSpecV;

			memset(&(theiterator->stSFRCenterMTF50), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterFreq1), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterFreq2), 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result));
			memset(&(theiterator->stSFRCenterBlock), 0, sizeof(_SFRBlackROI4));

			unsigned int uiFOVSize	=	sfrfacaParameter->vectorSFRItem.size();
			theiterator->vectorSFRFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorSFRFOV.at(x).ucStatus	=	0x0;
				theiterator->vectorSFRFOV.at(x).flMTF50UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flMTF50UnifV	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq1UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq1UnifV	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq2UnifH	=	0.0f;
				theiterator->vectorSFRFOV.at(x).flFreq2UnifV	=	0.0f;

				theiterator->vectorSFRFOV.at(x).flFOV		=	sfrfacaParameter->vectorSFRItem.at(x).flFOV;
				theiterator->vectorSFRFOV.at(x).ucBlockCount		=	sfrfacaParameter->vectorSFRItem.at(x).ucBlockCount;
				theiterator->vectorSFRFOV.at(x).flAngle		=	sfrfacaParameter->vectorSFRItem.at(x).flAngle;
				theiterator->vectorSFRFOV.at(x).flWeight		=	sfrfacaParameter->vectorSFRItem.at(x).flWeight;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecH		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecH;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecV		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecV;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecH		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecH;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecV		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecV;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecH		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecH;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecV		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecV;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecUnifH;
				theiterator->vectorSFRFOV.at(x).flMTF50SpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).flMTF50SpecUnifV;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifH;
				theiterator->vectorSFRFOV.at(x).fl1stFreqSpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).fl1stFreqSpecUnifV;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecUnifH		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifH;
				theiterator->vectorSFRFOV.at(x).fl2ndFreqSpecUnifV		=	sfrfacaParameter->vectorSFRItem.at(x).fl2ndFreqSpecUnifV;
				memset(theiterator->vectorSFRFOV.at(x).stSFRMTF50, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stSFRFreq1, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stSFRFreq2, 0, sizeof(_HisCCMAlg_SFRPlusHA_Block_Result) *4);
				memset(theiterator->vectorSFRFOV.at(x).stBlock, 0, sizeof(_SFRBlackROI4) *4);
			}
		}
		else{
			unsigned int uiFOVSize	=	lpmfaParameter->vectorLpItem.size();
			theiterator->vectorLPFOV.resize(uiFOVSize);
			for(unsigned int x=0;	x<uiFOVSize;	++x){
				theiterator->vectorLPFOV.at(x).flFOV		=	lpmfaParameter->vectorLpItem.at(x).flFOV;
				theiterator->vectorLPFOV.at(x).flAngle	=	lpmfaParameter->vectorLpItem.at(x).flAngle;
				theiterator->vectorLPFOV.at(x).flSpecHor	=	lpmfaParameter->vectorLpItem.at(x).flSpecHor;
				theiterator->vectorLPFOV.at(x).flSpecVec	=	lpmfaParameter->vectorLpItem.at(x).flSpecVec;
				theiterator->vectorLPFOV.at(x).flSpecUniform	=	lpmfaParameter->vectorLpItem.at(x).flSpecUniform;
				theiterator->vectorLPFOV.at(x).flWeight		=	lpmfaParameter->vectorLpItem.at(x).flWeight;
				theiterator->vectorLPFOV.at(x).ucStatus	=	0x0;
				memset(theiterator->vectorLPFOV.at(x).stLpValue, 0, sizeof(_HisCCMAlg_Resolution) *4);
				memset(theiterator->vectorLPFOV.at(x).stValueLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stMinLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stMaxLine, 0, sizeof(RECT) *4);
				memset(theiterator->vectorLPFOV.at(x).stBlock, 0, sizeof(RECT) *4);
			}
		}
	}

	__inline int AFARolongoFromDB(_mtffaParameter* mtffaParameter, _SFRFACAParameter* sfrfacaParameter, \
		_lpMFAParameter* lpmfaParameter, _HisAutoFA_BASIC_STACTICS* afaBasicStacticsParameter, _HisAutoFA_Rolongo_DB* pDB)
	{
		pDB->initial();
		pDB->pstTacticsBasic	=	new _HisAutoFA_BASIC_STACTICS;
		if(pDB->pstTacticsBasic == NULL){
			pDB->initial();
			return HisFX3Error_MallocBuffer;
		}

		*(pDB->pstTacticsBasic)	=	*afaBasicStacticsParameter;
		if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
			afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B){
			pDB->pstMTFBasic	=	new _HisCCMAlg_MTFBasic_Info;
			if(pDB->pstMTFBasic == NULL){
				pDB->initial();
				return HisFX3Error_MallocBuffer;
			}

			*(pDB->pstMTFBasic)	=	mtffaParameter->stMTFBasic;
			pDB->vectorMTFItem.assign(mtffaParameter->vectorMTFItem.begin(), mtffaParameter->vectorMTFItem.end());
		}
		else if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A){
			pDB->pstSFRBasic	=	new _HisCCMAlg_SFRPlusHABasic_Info;
			if(pDB->pstSFRBasic == NULL){
				pDB->initial();
				return HisFX3Error_MallocBuffer;
			}

			*(pDB->pstSFRBasic)	=	sfrfacaParameter->stSFRBasic;
			pDB->vectorSFRItem.assign(sfrfacaParameter->vectorSFRItem.begin(), sfrfacaParameter->vectorSFRItem.end());
		}
		else{
			pDB->pstLpBasic		=	new _HisCCMAlg_LPBasic_Info;
			if(pDB->pstLpBasic == NULL){
				pDB->initial();
				return HisFX3Error_MallocBuffer;
			}

			*(pDB->pstLpBasic)			=	lpmfaParameter->stLpBasic;
			pDB->vectorLpItemInfo.assign(lpmfaParameter->vectorLpItem.begin(), lpmfaParameter->vectorLpItem.end());
		}

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName = "autofadb";

			QSqlQuery query(customdb);
			query.prepare("SELECT bins1,bins2,bins3,bins1byte,bins2byte,bins3byte,ints1,ints2 FROM tablemanage WHERE tablename='" % strTableName % "'");
			query.exec();

			QByteArray bins1,bins2,bins3;
			unsigned int bins1byte=0,bins2byte=0,bins3byte=0, ints1=0, ints2 = 0;
			while (query.next()){
				bins1 = query.value(0).toByteArray();
				bins2 = query.value(1).toByteArray();
				bins3 = query.value(2).toByteArray();
				bins1byte	=	query.value(3).toUInt();
				bins2byte	=	query.value(4).toUInt();
				bins3byte	=	query.value(5).toUInt();
				ints1			=	query.value(6).toUInt();
				ints2			=	query.value(7).toUInt();
			}

			QByteArray Sbins1	=	AFAALLTacticsBasicSerialize(*pDB->pstTacticsBasic);
			QByteArray Sbins2, Sbins3;
			unsigned int Sints1;
			if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
				afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B){
				Sbins2	=	MTFBasicSerialize(*pDB->pstMTFBasic);
				Sbins3	=	MTFItemSerialize(pDB->vectorMTFItem);
				Sints1			=	pDB->vectorMTFItem.size();
			}
			else if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A){
				Sbins2	=	SFRHABasicSerialize(*pDB->pstSFRBasic);
				Sbins3	=	SFRHAItemSerialize(pDB->vectorSFRItem);
				Sints1			=	pDB->vectorSFRItem.size();
			}
			else{
				Sbins2	=	LpHABasicSerialize(*pDB->pstLpBasic);
				Sbins3	=	LpHAItemSerialize(pDB->vectorLpItemInfo);
				Sints1			=	pDB->vectorLpItemInfo.size();
			}

			unsigned int Sbins1byte	=	Sbins1.size();
			unsigned int Sbins2byte	=	Sbins2.size();
			unsigned int Sbins3byte	=	Sbins3.size();

			bool bupdate = false;
			if(Sbins1byte != bins1byte || Sbins2byte != bins2byte || Sbins3byte != bins3byte || Sints1 != ints1)
				bupdate	=	true;
			if(!bupdate){
				if(!isEqual(bins1, Sbins1)) bupdate = true;
				if(!isEqual(bins2, Sbins2)) bupdate = true;
				if(!isEqual(bins3, Sbins3)) bupdate = true;
			}

			if(bupdate){
				query.prepare("UPDATE tablemanage SET bins1=:bins1,bins2=:bins2,bins3=:bins3,bins1byte=:bins1byte,bins2byte=:bins2byte,bins3byte=:bins3byte,ints1=:ints1 WHERE tablename='" % strTableName % "'");
				query.bindValue(":bins1", Sbins1);
				query.bindValue(":bins2", Sbins2);
				query.bindValue(":bins3", Sbins3);
				query.bindValue(":bins1byte", Sbins1byte);
				query.bindValue(":bins2byte", Sbins2byte);
				query.bindValue(":bins3byte", Sbins3byte);
				query.bindValue(":ints1", Sints1);
				query.exec();

				query.prepare("DELETE FROM " % strTableName);
				query.exec();
			}
			else{
				query.prepare("SELECT id,markdisstart,laser,radius,visionangle,valuestart,rotate,markdisend,angleperpixle,valueend FROM " % strTableName %  "  ORDER BY id ASC" );
				query.exec();
				unsigned int uiDataSize;
				if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
					afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B){
					uiDataSize	=	1;
					for(unsigned int x=0;	x<pDB->vectorMTFItem.size(); ++x){
						if(pDB->vectorMTFItem.at(x).ucBlockCount == 2)		uiDataSize += 2;
						else uiDataSize	+=	4;
					}
				}
				else if(afaBasicStacticsParameter->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A){
					uiDataSize	=	2;
					for(int x=0; x< pDB->vectorSFRItem.size(); ++x){
						uiDataSize	+=	(pDB->vectorSFRItem.at(x).ucBlockCount <<1);
					}
				}
				else uiDataSize	=	pDB->vectorLpItemInfo.size() *4;

				_HisAutoFA_Rolongo_DB_Item stNewItem;
				stNewItem.vecValueStart.resize(uiDataSize);
				stNewItem.vecValueEnd.resize(uiDataSize);
				stNewItem.ucStatus	=	0;
				QByteArray valuestart, valueend;

				while (query.next()){
					stNewItem.ui64ID				=	query.value(0).toULongLong();
					stNewItem.flMarkDisStart		=	query.value(1).toFloat();
					stNewItem.flLaser		=	query.value(2).toFloat();
					stNewItem.flLensRadius		=	query.value(3).toFloat();
					stNewItem.flLensAngle		=	query.value(4).toFloat();
					valuestart								=	query.value(5).toByteArray();
					stNewItem.flRotateAngle		=	query.value(6).toFloat();
					stNewItem.flMarkDisEnd		=	query.value(7).toFloat();
					stNewItem.flAnglePerPixel		=	query.value(8).toFloat();
					valueend								=	query.value(9).toByteArray();

					QDataStream streamstart(valuestart);
					streamstart.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamstart >> stNewItem.vecValueStart.at(x);
					}

					QDataStream streamend(valueend);
					streamend.setVersion(QDataStream::Qt_4_8);
					for(unsigned int x=0;	x<uiDataSize;++x){
						streamend >> stNewItem.vecValueEnd.at(x);
					}

					pDB->ui64IDMax	=	max(pDB->ui64IDMax, stNewItem.ui64ID);
					pDB->vectorDataItem.push_back(stNewItem);
				}
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			pDB->initial();
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline void saveMTFHAAFACurve2File(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, \
		_mtffaParameter* pstParameter, QString& strPath,QString strSerialNumber,int iWidth, int iHeight)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

		QString strTime=QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
		QTextStream out(&classFile);
		out<<"SN,time,Angle,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x)
		{
			out << QString::number(vectorItemData.at(x).dflAbsAngle) << ",";
		}
		out << "\n";

		out <<strSerialNumber%","%strTime%",MarkDistance,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).dflMarkDistance) << ",";
		}
		out << "\n";

		out <<strSerialNumber%","%strTime%",Weight,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).flWeightValue) << ",";
		}
		out << "\n";

		out <<strSerialNumber%","%strTime%",Center,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out <<QString::number(vectorItemData.at(x).flMTFCenterValue) << ",";
		}
		out << "\n";

		for(unsigned int w=0;	w<pstParameter->vectorMTFItem.size(); ++w)
		{
			QString strKey2		=	"mtf_fov" % QString::number(pstParameter->vectorMTFItem.at(w).flFOV, 'f', 3) % "_";
			for(unsigned int y=0; y<pstParameter->vectorMTFItem.at(w).ucBlockCount;	++y)
			{
				QString strKey3	=	strKey2 % getBlockName(vectorItemData.at(0).vectorMTFFOV.at(w).stBlock[y], iWidth, iHeight);
				out <<strSerialNumber%","%strTime%","%strKey3%",";
				for(unsigned int x=0;	x<vectorItemData.size(); ++x)
				{
					out <<QString::number(vectorItemData.at(x).vectorMTFFOV.at(w).flValue[y]) << ",";
				}
				out << "\n";
			}
		}		

		classFile.close();
	}

	__inline void saveSFRHAAFACurve2File(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, \
		_SFRFACAParameter* pstParameter, QString& strPath,QString strSerialNumber,int iWidth, int iHeight)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

		QString strTime=QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");

		QTextStream out(&classFile);

		out<<"SN,time,Angle,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).dflAbsAngle) << ",";
		}
		out << "\n";

		out <<strSerialNumber%","%strTime%",MarkDistance,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).dflMarkDistance) << ",";
		}
		out << "\n";

		out <<strSerialNumber%","%strTime%",Weight,";
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).flWeightValue) << ",";
		}
		out << "\n";

		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq)
		{
			out <<strSerialNumber%","%strTime%",Center_Left_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x)
			{
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueH_L) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Rright_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x)
			{
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueH_R) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Top_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x)
			{
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueV_T) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Bottom_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterFreq1.flValueV_B) << ",";
			}
			out << "\n";

		
			for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w)
			{				
				QString strKey2		=	"sfr_freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_fov" % QString::number(vectorItemData.at(0).vectorSFRFOV.at(w).flFOV, 'f', 2) % "_";
				for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y)
				{
					QString strKey3 = strKey2 % getBlockName(vectorItemData.at(0).vectorSFRFOV.at(w).stBlock[y].stLeft, iWidth, iHeight) % "_";
                    out <<strSerialNumber%","%strTime%","%strKey3%"Left,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x)
					{
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq1[y].flValueH_L) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Right,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq1[y].flValueH_R) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Top,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq1[y].flValueV_T) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Bottom,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq1[y].flValueV_B) << ",";
					}
					out << "\n";
				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq)
			{
				out << "\n";

				out <<strSerialNumber%","%strTime%",Center_L_Freq2,";
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueH_L) << ",";
				}
				out << "\n";

				out <<strSerialNumber%","%strTime%",Center_R_Freq2,";
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueH_R) << ",";
				}
				out << "\n";

				out <<strSerialNumber%","%strTime%",Center_T_Freq2,";
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueV_T) << ",";
				}
				out << "\n";

				out <<strSerialNumber%","%strTime%",Center_B_Freq2,";
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).stSFRCenterFreq2.flValueV_B) << ",";
				}
				out << "\n";

				for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w)
				{
					QString strKey2		=	"sfr_freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_fov" % QString::number(vectorItemData.at(0).vectorSFRFOV.at(w).flFOV, 'f', 2) % "_";
					for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y)
					{
						QString strKey3 = strKey2 % getBlockName(vectorItemData.at(0).vectorSFRFOV.at(w).stBlock[y].stLeft, iWidth, iHeight) % "_";
						out <<strSerialNumber%","%strTime%","%strKey3%"Left,";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq2[y].flValueH_L) << ",";
						}
						out << "\n";

						out <<strSerialNumber%","%strTime%","%strKey3%"Right,";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x)
						{
							out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq2[y].flValueH_R) << ",";
						}
						out << "\n";

						out <<strSerialNumber%","%strTime%","%strKey3%"Top,";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq2[y].flValueV_T) << ",";
						}
						out << "\n";

						out <<strSerialNumber%","%strTime%","%strKey3%"Bottom,";
						for(unsigned int x=0;	x<vectorItemData.size(); ++x){
							out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRFreq2[y].flValueV_B) << ",";
						}
						out << "\n";
					}
				}
			}
		}
		else
		{
			out <<strSerialNumber%","%strTime%",Center_Left_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x)
			{
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueH_L) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Rright_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueH_R) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Top_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueV_T) << ",";
			}
			out << "\n";

			out <<strSerialNumber%","%strTime%",Center_Bottom_Freq1,";
			for(unsigned int x=0;	x<vectorItemData.size(); ++x){
				out <<QString::number(vectorItemData.at(x).stSFRCenterMTF50.flValueV_B) << ",";
			}
			out << "\n";

			for(unsigned int w=0;	w<pstParameter->vectorSFRItem.size(); ++w)
			{
				QString strKey2		=	"sfr_freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_fov" % QString::number(vectorItemData.at(0).vectorSFRFOV.at(w).flFOV, 'f', 2) % "_";
				for(unsigned int y=0; y<pstParameter->vectorSFRItem.at(w).ucBlockCount;	++y)
				{
					QString strKey3 = strKey2 % getBlockName(vectorItemData.at(0).vectorSFRFOV.at(w).stBlock[y].stLeft, iWidth, iHeight) % "_";
					out <<strSerialNumber%","%strTime%","%strKey3%"Left,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRMTF50[y].flValueH_L) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Right,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRMTF50[y].flValueH_R) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Top,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRMTF50[y].flValueV_T) << ",";
					}
					out << "\n";
					out <<strSerialNumber%","%strTime%","%strKey3%"Bottm,";
					for(unsigned int x=0;	x<vectorItemData.size(); ++x){
						out <<QString::number(vectorItemData.at(x).vectorSFRFOV.at(w).stSFRMTF50[y].flValueV_B) << ",";
					}
					out << "\n";
				}
			}
		}

		classFile.close();
	}

	__inline void saveLpHAAFACurve2File(std::vector<_HisAutoFA_Rolongo_DataItem>& vectorItemData, \
		_lpMFAParameter* pstParameter, QString& strPath)
	{
		QFile classFile(strPath);
		classFile.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);

		QTextStream out(&classFile);
		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).dflAbsAngle) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).dflMarkDistance) << ",";
		}
		out << "\n";

		for(unsigned int x=0;	x<vectorItemData.size(); ++x){
			out << QString::number(vectorItemData.at(x).flWeightValue) << ",";
		}
		out << "\n";

		for(unsigned int w=0;	w<pstParameter->vectorLpItem.size(); ++w){
			for(unsigned int y=0; y<4;	++y){
				for(unsigned int x=0;	x<vectorItemData.size(); ++x){
					out <<QString::number(vectorItemData.at(x).vectorLPFOV.at(w).stLpValue[y].flValue) << ",";
				}
				out << "\n";
			}
		}

		classFile.close();
	}

	__inline void saveMTFHAAFAResult(_HisAutoFA_Rolongo_DataItem& stItemData, bool bResult, _mtffaParameter* pstParameter, \
		HisFX3Log& classLog, int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "fa_mtf_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_MTFFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center";
		logitem.itemvalue	=	stItemData.flMTFCenterValue;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<stItemData.vectorMTFFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(stItemData.vectorMTFFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<stItemData.vectorMTFFOV.at(x).ucBlockCount;	++i){
				strKey3	=	strKey2 % getBlockName(stItemData.vectorMTFFOV.at(x).stBlock[i], iWidth, iHeight);

				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorMTFFOV.at(x).flValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey		=	strKey2 % "Tilt";
			logitem.itemvalue	=	stItemData.vectorMTFFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void saveMTFHAAFAResult_G(_HisAutoFA_Rolongo_DataItem_EX& stItemData, bool bResult, _mtffaParameter* pstParameter, \
		HisFX3Log& classLog, int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "fa_mtf_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_MTFFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		strKey2		=	strKey1;

		logitem.itemkey		=	strKey2 % "center_H";
		logitem.itemvalue	=	stItemData.flMTFCenterValue_H;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		logitem.itemkey		=	strKey2 % "center_V";
		logitem.itemvalue	=	stItemData.flMTFCenterValue_V;
		classLog.push_back(logitem);
		++(logitem.itemtype);

		for(unsigned int x=0;	x<stItemData.vectorMTFFOV.size(); ++x){
			strKey2		=	strKey1 % "fov" % QString::number(stItemData.vectorMTFFOV.at(x).flFOV, 'f', 3) % "_";
			for(unsigned int i=0;	i<stItemData.vectorMTFFOV.at(x).ucBlockCount;	++i){
				strKey3	=	strKey2 % getBlockName(stItemData.vectorMTFFOV.at(x).stBlock[i], iWidth, iHeight)%"_H";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorMTFFOV.at(x).flHValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);

				strKey3	=	strKey2 % getBlockName(stItemData.vectorMTFFOV.at(x).stBlock[i], iWidth, iHeight)%"_V";
				logitem.itemkey		=	strKey3;
				logitem.itemvalue	=	stItemData.vectorMTFFOV.at(x).flVValue[i];
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey		=	strKey2 % "Tilt";
			logitem.itemvalue	=	stItemData.vectorMTFFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline void saveSHRHAAFAResult(_HisAutoFA_Rolongo_DataItem& stItemData, bool bResult, _SFRFACAParameter* pstParameter, \
		HisFX3Log& classLog, int iWdith, int iHeight)
	{
		_HisLog_Item logitem;
		QString strKey1 = "fa_sfra_";

		logitem.itemtype		=	_HISLOG_CLASSIFY_SFRFA;
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		QString strKey2, strKey3;
		if(pstParameter->stSFRBasic.ucMethod == _His_SFR_Method_2Freq){
			strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	stItemData.stSFRCenterFreq1.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<stItemData.vectorSFRFOV.size(); ++x)
			{
				strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc1stFreq) % "_fov" % QString::number(stItemData.vectorSFRFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<stItemData.vectorSFRFOV.at(x).ucBlockCount;	++i){
					strKey3 = strKey2 % getBlockName(stItemData.vectorSFRFOV.at(x).stBlock[i].stLeft, iWdith, iHeight) % "_";

					logitem.itemkey		=	strKey3 % "left";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq1[i].flValueH_L;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "right";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq1[i].flValueH_R;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "top";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq1[i].flValueV_T;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "bottom";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq1[i].flValueV_B;
					classLog.push_back(logitem);
					++(logitem.itemtype);
				}
			}

			if(pstParameter->stSFRBasic.b2ndFreq){
				strKey2 =	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_";

				logitem.itemkey		=	strKey2 % "center_left";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueH_L;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_right";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueH_R;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_top";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueV_T;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				logitem.itemkey		=	strKey2 % "center_bottom";
				logitem.itemvalue	=	stItemData.stSFRCenterFreq2.flValueV_B;
				classLog.push_back(logitem);
				++(logitem.itemtype);

				for(unsigned int x=0;	x<stItemData.vectorSFRFOV.size(); ++x)
				{
					strKey2		=	strKey1 % "freq" % QString::number(pstParameter->stSFRBasic.uc2ndFreq) % "_fov" % QString::number(stItemData.vectorSFRFOV.at(x).flFOV, 'f', 2) % "_";

					for(unsigned int i=0;	i<stItemData.vectorSFRFOV.at(x).ucBlockCount;	++i){
						strKey3 = strKey2 % getBlockName(stItemData.vectorSFRFOV.at(x).stBlock[i].stLeft, iWdith, iHeight) % "_";

						logitem.itemkey		=	strKey3 % "left";
						logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq2[i].flValueH_L;
						classLog.push_back(logitem);
						++(logitem.itemtype);

						logitem.itemkey		=	strKey3 % "right";
						logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq2[i].flValueH_R;
						classLog.push_back(logitem);
						++(logitem.itemtype);

						logitem.itemkey		=	strKey3 % "top";
						logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq2[i].flValueV_T;
						classLog.push_back(logitem);
						++(logitem.itemtype);

						logitem.itemkey		=	strKey3 % "bottom";
						logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRFreq2[i].flValueV_B;
						classLog.push_back(logitem);
						++(logitem.itemtype);
					}
				}
			}
		}
		else{
			strKey2		=	strKey1 % "mtf50_";

			logitem.itemkey		=	strKey2 % "center_left";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueH_L;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_right";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueH_R;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_top";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueV_T;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			logitem.itemkey		=	strKey2 % "center_bottom";
			logitem.itemvalue	=	stItemData.stSFRCenterMTF50.flValueV_B;
			classLog.push_back(logitem);
			++(logitem.itemtype);

			for(unsigned int x=0;	x<stItemData.vectorSFRFOV.size(); ++x)
			{
				strKey2		=	strKey1 % "mtf50_fov" % QString::number(stItemData.vectorSFRFOV.at(x).flFOV, 'f', 2) % "_";

				for(unsigned int i=0;	i<stItemData.vectorSFRFOV.at(x).ucBlockCount;	++i){
					strKey3 = strKey2 % getBlockName(stItemData.vectorSFRFOV.at(x).stBlock[i].stLeft, iWdith, iHeight) % "_";

					logitem.itemkey		=	strKey3 % "left";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRMTF50[i].flValueH_L;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "right";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRMTF50[i].flValueH_R;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "top";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRMTF50[i].flValueV_T;
					classLog.push_back(logitem);
					++(logitem.itemtype);

					logitem.itemkey		=	strKey3 % "bottom";
					logitem.itemvalue	=	stItemData.vectorSFRFOV.at(x).stSFRMTF50[i].flValueV_B;
					classLog.push_back(logitem);
					++(logitem.itemtype);
				}
			}
		}
	}

	__inline void saveLpHAAFAResult(_HisAutoFA_Rolongo_DataItem& stItemData, bool bResult, _lpMFAParameter* pstParameter, \
		HisFX3Log& classLog ,int iWidth, int iHeight)
	{
		_HisLog_Item logitem;
		logitem.itemtype		=	_HISLOG_CLASSIFY_LPMFA;
		QString strKey1	=	"fa_lp_";
		logitem.itemkey		=	strKey1 % "result";
		logitem.itemvalue	=	(bResult)?("OK"):("NG");
		classLog.push_back(logitem);
		++(logitem.itemtype);

		int iCenterX, iCenterY;
		for(unsigned int x=0;	x<stItemData.vectorLPFOV.size();	++x){
			iCenterX	=	iCenterY = 0;
			for(unsigned int i=0;	i<4;	++i){
				iCenterX	+=	stItemData.vectorLPFOV.at(x).stBlock[i].left;
				iCenterX	+=	stItemData.vectorLPFOV.at(x).stBlock[i].right;
				iCenterY	+=	stItemData.vectorLPFOV.at(x).stBlock[i].top;
				iCenterY	+=	stItemData.vectorLPFOV.at(x).stBlock[i].bottom;
			}

			iCenterX	=	(iCenterX >>2);
			iCenterY	=	(iCenterY >>2);

			for(unsigned int i=0;	i<4;	++i){
				logitem.itemkey	=	strKey1 % "f" % QString::number(pstParameter->vectorLpItem.at(x).flFOV, 'f', 3) % "_" % getBlockName(stItemData.vectorLPFOV.at(x).stBlock[i], iCenterX, iCenterY);
				logitem.itemvalue	=	stItemData.vectorLPFOV.at(x).stLpValue[i].flValue;
				classLog.push_back(logitem);
				++(logitem.itemtype);
			}
			logitem.itemkey	=	strKey1 % "f" % QString::number(pstParameter->vectorLpItem.at(x).flFOV, 'f', 3) % "_u";
			logitem.itemvalue	=	stItemData.vectorLPFOV.at(x).flUniformValue;
			classLog.push_back(logitem);
			++(logitem.itemtype);
		}
	}

	__inline int AFADataToDB(bool bMark, _HisAutoFA_Rolongo_DB* pDB, std::vector<_HisAutoFA_Rolongo_DataItem>& vectorDataItem, unsigned int uiIndex)
	{
		if(uiIndex == 0) return 0;
		if(vectorDataItem.at(uiIndex).ucStatus == 0x0) return 0;

		unsigned int uiStartIndex	=	0;
		if(bMark){
			uiStartIndex	=	0xFFFFFFFF;
			for(unsigned int x=0;	x<uiIndex;	++x){
				if(vectorDataItem.at(x).dflMarkDistance > 0.1 && abs(vectorDataItem.at(x).dflMarkDistance - vectorDataItem.at(uiIndex).dflMarkDistance) > 1.0){
					uiStartIndex	=	x;
					break;
				}
			}
			if(uiStartIndex == 0xFFFFFFFF) return 0;
		}

		_HisAutoFA_Rolongo_DB_Item stNewItem;
		stNewItem.flMarkDisStart	=	vectorDataItem.at(uiStartIndex).dflMarkDistance;
		stNewItem.flLaser				=	vectorDataItem.at(uiStartIndex).dflLaser;
		stNewItem.flLensRadius		=	vectorDataItem.at(uiStartIndex).dflRadius;
		stNewItem.flLensAngle		=	vectorDataItem.at(uiStartIndex).dflLesnAngle;
		stNewItem.flRotateAngle		=	vectorDataItem.at(uiIndex).dflAbsAngle - vectorDataItem.at(uiStartIndex).dflAbsAngle;
		stNewItem.flMarkDisEnd		=	vectorDataItem.at(uiIndex).dflMarkDistance;
		if(bMark && abs(stNewItem.flMarkDisEnd - stNewItem.flMarkDisStart) > 0.5f) stNewItem.flAnglePerPixel	=	 abs(stNewItem.flRotateAngle /(stNewItem.flMarkDisEnd - stNewItem.flMarkDisStart));
		stNewItem.ui64ID				=	pDB->ui64IDMax +1;

		if(pDB->pstTacticsBasic->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_A || \
			pDB->pstTacticsBasic->ucChartType == _HisCCMAlg_Rolongo_Chart_MTF_B){
			unsigned int uiDataSize	=	1;
			for(unsigned int x=0;	x<pDB->vectorMTFItem.size(); ++x){
				if(pDB->vectorMTFItem.at(x).ucBlockCount == 2)		uiDataSize += 2;
				else uiDataSize	+=	4;
			}

			stNewItem.vecValueStart.resize(uiDataSize);
			stNewItem.vecValueEnd.resize(uiDataSize);

			unsigned int uitempi	=	0;
			stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).flMTFCenterValue;
			stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).flMTFCenterValue;
			++uitempi;

			for(unsigned int y=0;	y<pDB->vectorMTFItem.size(); ++y){
				for(unsigned int x=0;	x<pDB->vectorMTFItem.at(y).ucBlockCount;	++x){
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorMTFFOV.at(y).flValue[x];
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorMTFFOV.at(y).flValue[x];
					++uitempi;
				}
			}
		}
		else if(pDB->pstTacticsBasic->ucChartType == _HisCCMAlg_Rolongo_Chart_SFR_A){
			unsigned int uiDataSize	=	2;
			for(int x=0;	x<pDB->vectorSFRItem.size(); ++x)
				uiDataSize += (pDB->vectorSFRItem.at(x).ucBlockCount <<1);
			stNewItem.vecValueStart.resize(uiDataSize);
			stNewItem.vecValueEnd.resize(uiDataSize);

			unsigned int uitempi	=	0;
			if(pDB->pstSFRBasic->b2ndFreq == _His_SFR_Method_2Freq)
			{
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).stSFRCenterFreq1.flValueH_L;
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterFreq1.flValueH_L;
				++uitempi;
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).stSFRCenterFreq1.flValueH_R;
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterFreq1.flValueH_R;
				++uitempi;

				for(unsigned int y=0;	y<pDB->vectorSFRItem.size(); ++y)
				{
					for(unsigned int x=0;	x<pDB->vectorSFRItem.at(y).ucBlockCount;	++x){
						stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorSFRFOV.at(y).stSFRFreq1[x].flValueH_L;
						stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorSFRFOV.at(y).stSFRFreq1[x].flValueH_L;
						++uitempi;
						stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorSFRFOV.at(y).stSFRFreq1[x].flValueH_R;
						stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorSFRFOV.at(y).stSFRFreq1[x].flValueH_R;
						++uitempi;
					}
				}
			}
			else{
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).stSFRCenterMTF50.flValueH_L;
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterMTF50.flValueH_L;
				++uitempi;
				stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).stSFRCenterMTF50.flValueH_R;
				stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).stSFRCenterMTF50.flValueH_R;
				++uitempi;

				for(unsigned int y=0;	y<pDB->vectorSFRItem.size(); ++y)
				{
					for(unsigned int x=0;	x<pDB->vectorSFRItem.at(y).ucBlockCount;	++x){
						stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorSFRFOV.at(y).stSFRMTF50[x].flValueH_L;
						stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorSFRFOV.at(y).stSFRMTF50[x].flValueH_L;
						++uitempi;
						stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorSFRFOV.at(y).stSFRMTF50[x].flValueH_R;
						stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorSFRFOV.at(y).stSFRMTF50[x].flValueH_R;
						++uitempi;
					}
				}
			}
		}
		else //lp
		{
			stNewItem.vecValueStart.resize(pDB->vectorLpItemInfo.size() *4);
			stNewItem.vecValueEnd.resize(pDB->vectorLpItemInfo.size() *4);

			unsigned int uitempi	=	0;
			for(unsigned int y=0;	y<pDB->vectorLpItemInfo.size(); ++y){
				for(unsigned int x=0;	x<4;	++x){
					stNewItem.vecValueStart.at(uitempi)	=	vectorDataItem.at(uiStartIndex).vectorLPFOV.at(y).stLpValue[x].flValue;
					stNewItem.vecValueEnd.at(uitempi)	=	vectorDataItem.at(uiIndex).vectorLPFOV.at(y).stLpValue[x].flValue;
					++uitempi;
				}
			}
		}


		++(pDB->ui64IDMax);

		bool bReplace = false;
		unsigned int uiReplaceID	=	0;
		if(vectorDataItem.size() >= pDB->usConstMaxItem){
			unsigned __int64 uiMinID	=	0xFFFFFFFFFFFFFFFF;
			for(unsigned int x=0;	x<pDB->vectorDataItem.size(); ++x){
				if(pDB->vectorDataItem.at(x).ui64ID < uiMinID){
					uiMinID	=	pDB->vectorDataItem.at(x).ui64ID;
					uiReplaceID	=	x;
				}
			}

			bReplace = true;
			pDB->vectorDataItem.erase(pDB->vectorDataItem.begin() + uiReplaceID);		
		}

		pDB->vectorDataItem.push_back(stNewItem);

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "querydata");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Data");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strTableName = "autofadb";

			QSqlQuery query(customdb);

			if(bReplace){
				query.prepare("DELETE FROM " % strTableName %  " WHERE id=:id");
				query.bindValue(":id", uiReplaceID);
				query.exec();
			}

			QByteArray valuestart, valueend;

			QDataStream streamstart(&valuestart, QIODevice::WriteOnly);
			streamstart.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueStart.size(); ++x){
				streamstart << stNewItem.vecValueStart.at(x);
			}

			QDataStream streamend(&valueend, QIODevice::WriteOnly);
			streamend.setVersion(QDataStream::Qt_4_8);
			for(unsigned int x=0;	x<stNewItem.vecValueEnd.size(); ++x){
				streamend << stNewItem.vecValueEnd.at(x);
			}

			query.prepare("INSERT INTO " % strTableName %  "(id,markdisstart,laser,radius,visionangle,valuestart,rotate,markdisend,angleperpixle,valueend,reserve1,reserve2,reserve3,reserve4,reserve5) VALUES(:id,:markdisstart,:laser,:radius,:visionangle,:valuestart,:rotate,:markdisend,:angleperpixle,:valueend,:reserve1,:reserve2,:reserve3,:reserve4,:reserve5)");		
			query.bindValue(":id", stNewItem.ui64ID);
			query.bindValue(":markdisstart", stNewItem.flMarkDisStart);
			query.bindValue(":laser", stNewItem.flLaser);
			query.bindValue(":radius", stNewItem.flLensRadius);
			query.bindValue(":visionangle", stNewItem.flLensAngle);
			query.bindValue(":valuestart", valuestart);
			query.bindValue(":rotate", stNewItem.flRotateAngle);
			query.bindValue(":markdisend", stNewItem.flMarkDisEnd);
			query.bindValue(":angleperpixle", stNewItem.flAnglePerPixel);
			query.bindValue(":valueend", valueend);
			query.bindValue(":reserve1", 0.0);
			query.bindValue(":reserve2", 0.0);
			query.bindValue(":reserve3", 0.0);
			query.bindValue(":reserve4", 0.0);
			query.bindValue(":reserve5", 0.0);
			query.exec();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("querydata");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline void GetStatisticsFromDB(_HisFX3Global_TestStatistics& stStatisticsHistory, bool bChannel1)
	{
		QMutexLocker locker(&hisglobalparameter.mutexDatabase);

		for(int w=0;	w<1;	++w)
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
			if (!templatedb.open())
				break;

			QSqlQuery query(templatedb);
			query.prepare("SELECT version,count,data FROM statistics WHERE name=:name" );
			query.bindValue(":name", (bChannel1)?("ccmstatisticsc1"):("ccmstatisticsc2"));
			query.exec();

			bool bExist = false;
			unsigned char ucVersion, ucCount;
			QByteArray byteData;
			while (query.next()){
				bExist = true;
				ucVersion	=	query.value(0).toUInt();
				ucCount		=	query.value(1).toUInt();
				byteData		= query.value(2).toByteArray();
			}

			if(bExist && ucVersion==stStatisticsHistory.ucVersion && ucCount==stStatisticsHistory.ucItemCount){
				QDataStream stream(byteData);
				stream.setVersion(QDataStream::Qt_4_8);
				stream >>stStatisticsHistory.uiALL >>stStatisticsHistory.uiPASS >>stStatisticsHistory.uiFA >>stStatisticsHistory.uiAFCNear >> \
					stStatisticsHistory.uiAFCMiddle >> stStatisticsHistory.uiAFCFar >> stStatisticsHistory.uiOS >> stStatisticsHistory.uiWorkCurrent >> \
					stStatisticsHistory.uiStandbyCurrent >> stStatisticsHistory.uiPreview >> stStatisticsHistory.uiBlemish >> stStatisticsHistory.uiDefectPixel >> \
					stStatisticsHistory.uiOC >> stStatisticsHistory.uiShading >> stStatisticsHistory.uiVignetting >> stStatisticsHistory.uiColor >> \
					stStatisticsHistory.uiLine >> stStatisticsHistory.uiLightPixel >> stStatisticsHistory.uiOTPBurn >> stStatisticsHistory.uiOTPBurnCheck >> \
					stStatisticsHistory.uiAFBurn >> stStatisticsHistory.uiAFBurnCheck >> stStatisticsHistory.uiPDAFBurn >> stStatisticsHistory.uiPDAFBurnCheck >> \
					stStatisticsHistory.uiOther;
			}

			templatedb.close();
		}

		QSqlDatabase::removeDatabase("querytemplate");
	}

	__inline void SetStatisticsToDB(_HisFX3Global_TestStatistics& stStatisticsHistory, bool bChannel1)
	{
		QMutexLocker locker(&hisglobalparameter.mutexDatabase);

		for(int w=0;	w<1;	++w)
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
			if (!templatedb.open())
				break;

			QByteArray byteArray;
			QDataStream stream(&byteArray, QIODevice::WriteOnly);
			stream.setVersion(QDataStream::Qt_4_8);
			stream <<stStatisticsHistory.uiALL <<stStatisticsHistory.uiPASS <<stStatisticsHistory.uiFA <<stStatisticsHistory.uiAFCNear << \
				stStatisticsHistory.uiAFCMiddle << stStatisticsHistory.uiAFCFar << stStatisticsHistory.uiOS << stStatisticsHistory.uiWorkCurrent << \
				stStatisticsHistory.uiStandbyCurrent << stStatisticsHistory.uiPreview << stStatisticsHistory.uiBlemish << stStatisticsHistory.uiDefectPixel << \
				stStatisticsHistory.uiOC << stStatisticsHistory.uiShading << stStatisticsHistory.uiVignetting << stStatisticsHistory.uiColor << \
				stStatisticsHistory.uiLine << stStatisticsHistory.uiLightPixel << stStatisticsHistory.uiOTPBurn << stStatisticsHistory.uiOTPBurnCheck << \
				stStatisticsHistory.uiAFBurn << stStatisticsHistory.uiAFBurnCheck << stStatisticsHistory.uiPDAFBurn << stStatisticsHistory.uiPDAFBurnCheck << \
				stStatisticsHistory.uiOther;

			QSqlQuery query(templatedb);
			query.prepare("UPDATE statistics SET version=:version,count=:count,data=:data WHERE name=:name");
			query.bindValue(":name", (bChannel1)?("ccmstatisticsc1"):("ccmstatisticsc2"));
			query.bindValue(":version", stStatisticsHistory.ucVersion);
			query.bindValue(":count", stStatisticsHistory.ucItemCount);
			query.bindValue(":data", byteArray);
			query.exec();

			templatedb.close();
		}

		QSqlDatabase::removeDatabase("querytemplate");
	}

	__inline void drawStatisticsItem(QPainter& painer, QPen&thePen, QRect& stNameRect, QRect& stNumRect, int& iItemHeight, QColor& colorText, QColor& colotNum, QString strText, QString strNum)
	{
		thePen.setColor(colorText);
		painer.setPen(thePen);
		painer.drawText(stNameRect, Qt::AlignJustify | Qt::AlignVCenter |Qt::TextSingleLine, strText);
		thePen.setColor(colotNum);
		painer.setPen(thePen);
		painer.drawText(stNumRect, Qt::AlignJustify | Qt::AlignVCenter |Qt::TextSingleLine, strNum);
		stNameRect.moveTop(stNameRect.top() + iItemHeight);
		stNumRect.moveTop(stNumRect.top() + iItemHeight);
	}

	__inline double AFAtoBestOffset(double& dflDesAbs, double& dflNowAbs, float& flOffset)
	{
		if(dflDesAbs == dflNowAbs || fabsf(flOffset) < 0.05f) return dflDesAbs;
		if(dflDesAbs < dflNowAbs) //CW
			return dflDesAbs - flOffset;
		return dflDesAbs +flOffset;
	}

	__inline bool scaleImageShowBlock(RECT& stSrc, RECT& stDes, LONG& lshowW, LONG& lshowH, RECT& stCutROI, int& iOffsetLeft, int& iOffsetTop)
	{
		if(stSrc.left < stCutROI.left || stSrc.right > stCutROI.right || stSrc.top < stCutROI.top || stSrc.bottom > stCutROI.bottom) return false;
		stDes.left				= (stSrc.left - stCutROI.left) *(lshowW - (iOffsetLeft <<1)) /(stCutROI.right - stCutROI.left) +iOffsetLeft;
		stDes.top				= (stSrc.top - stCutROI.top) *(lshowH - (iOffsetTop <<1)) /(stCutROI.bottom - stCutROI.top) + iOffsetTop;
		stDes.right			= (stSrc.right	- stCutROI.left) *(lshowW - (iOffsetLeft <<1)) /(stCutROI.right - stCutROI.left) + iOffsetLeft;
		stDes.bottom		= (stSrc.bottom - stCutROI.top) *(lshowH - (iOffsetTop <<1)) /(stCutROI.bottom - stCutROI.top) + iOffsetTop;
		return true;
	}

	__inline bool scaleImageShowBlock(int& iLeft, int& iTop, RECT& stDes, LONG& lshowW, LONG& lshowH, RECT& stCutROI, int& iOffsetLeft, int& iOffsetTop)
	{
		if(iLeft < stCutROI.left || iTop < stCutROI.top) return false;
		stDes.left		= (iLeft - stCutROI.left) *(lshowW - (iOffsetLeft <<1)) /(stCutROI.right - stCutROI.left) + iOffsetLeft;
		stDes.top		= (iTop - stCutROI.top) *(lshowH - (iOffsetTop <<1)) /(stCutROI.bottom - stCutROI.top) + iOffsetTop;
		return true;
	}

	__inline void saveGlobalConfigItem(QString strItem, QString strKey, QString strValue, unsigned int uiID)
	{
		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
			if (templatedb.open()){
				QSqlQuery query(templatedb);
				query.prepare("DELETE FROM global WHERE classfy=:classfy AND item=:item AND key=:key");
				query.bindValue(":classfy", "global");
				query.bindValue(":item", strItem);
				query.bindValue(":key", strKey);
				query.exec();

				query.prepare("INSERT INTO global(id,classfy,item,key,value) VALUES(:id, :classfy, :item, :key, :value)");
				query.bindValue(":id", uiID);
				query.bindValue(":classfy", "global");
				query.bindValue(":item", strItem);
				query.bindValue(":key", strKey);
				query.bindValue(":value", strValue);
				query.exec();

				templatedb.close();
			}
		}

		QSqlDatabase::removeDatabase("querytemplate");
	}

	__inline bool checkSenseShieldEnabled(unsigned int uiLincenseID, unsigned char ucClient, unsigned char ucProduct)
	{
		ST_INIT_PARAM init_param = { 0 }; // 初始化参数
		ST_LOGIN_PARAM login_param = { 0 }; // 许可登录参数
		SLM_HANDLE_INDEX slm_handle = { 0 }; // 许可句柄
		SS_UINT32 rom_size = 0;
		//ST_INIT_PARAM init_param ;
		int iDllflag	=0;
		SS_BYTE psd[16] = { 0x87, 0xB7, 0x17, 0xF4, 0x6B, 0x08, 0x8D, 0xC0, 0x6B, 0x35, 0xCF, 0xD9, 0xCD, 0x77, 0x83, 0x74 }; //公司专有调用API密码，需写死
		init_param.flag = 0; // 不接收回调消息
		init_param.pfn = NULL; // 不接收回调消息时，回调函数可填NULL
		init_param.timeout = 0; // 通信超时时间（针对⽹络锁及云锁环境不好时可能会超
		init_param.version = SLM_CALLBACK_VERSION02; // 版本号（固定传SLM_CALLBACK_VERSION01）
		memcpy(init_param.password, psd, sizeof(psd));

		// Runtime 初始化
		SS_UINT32 status = slm_init(&init_param);
		if (status != SS_OK)
		{
			return false;
		}

		login_param.size = sizeof(ST_LOGIN_PARAM); // 传结构体⼤⼩
		login_param.login_mode = SLM_LOGIN_MODE_LOCAL; // 登录本地锁
		login_param.license_id = uiLincenseID; // 登录的许可ID
		login_param.timeout	  =	1000;

#define _CODE_checkSenseShieldEnabled_Exit(a) { slm_logout(slm_handle); /*slm_cleanup();*/ return a; }

		//许可登录
		status = slm_login(&login_param, STRUCT, &slm_handle, NULL) ;
		if (status != SS_OK)
		{
			return false;
		}

		status = slm_keep_alive(slm_handle); 
		if (status != SS_OK)
		{
			_CODE_checkSenseShieldEnabled_Exit(false)
		}

		char* lic_desc	=NULL;

		//查找许可文件
		status = slm_find_license(uiLincenseID, JSON, &lic_desc);
		if (status != SS_OK)
		{
			slm_free(lic_desc);
			_CODE_checkSenseShieldEnabled_Exit(false)
		}

		//0800000000000061 公司编号，判断是否是我们发出的license
		if(!strstr(lic_desc,"0800000000000061"))
		{
			slm_free(lic_desc);
			_CODE_checkSenseShieldEnabled_Exit(false)
		}

		slm_free(lic_desc);

		//读取加密狗读写区写入内容长度
		status = slm_user_data_getsize(slm_handle, ROM, &rom_size);
		if (status != SS_OK)
		{
			_CODE_checkSenseShieldEnabled_Exit(false)
		}

		// 		unsigned char ucClientNow = 0xFF, ucProductNow = 0xFF;
		bool bClient = (ucClient == _ROLONGO_CLIENT_ALL)?(true):(false);
		bool bProduct	=	(ucProduct == _ROLONGO_ENCRYPT_TYPE_NONE)?(true):(false);

		if (rom_size && (!bClient || !bProduct))
		{
			//读取加密狗读写区内容
			char readbuffer[1024];
			status = slm_user_data_read(slm_handle,ROM,(SS_BYTE*)readbuffer,0, min(1023, rom_size));
			if (status != SS_OK)
			{
				_CODE_checkSenseShieldEnabled_Exit(false)
			}

			readbuffer[rom_size] = '\0';
			QString strReadBuffer = QString::fromAscii(readbuffer);
			QStringList listName, listValue;

			patchconfigstring(strReadBuffer, listName, listValue);
			for(int x=0;	x<listName.size(); ++x)
			{
				if(!bProduct && (listName[x] == "product")){
					unsigned char ucCusData	=	listValue[x].toUInt() & 0xFF;
					if(ucCusData == ucProduct) bProduct = true;
				}
				else if(!bClient && (listName[x] == "client")){
					unsigned char ucCusData	=	listValue[x].toUInt() & 0xFF;
					if(ucCusData == ucClient) bClient = true;
				}
			}

		}

		//std::string str	=	lic_desc;
		// 许可登出
		status = slm_logout(slm_handle);
		if (status != SS_OK)
		{
			return false;
		}

		return (bClient && bProduct);
	}

	__inline bool focus2DB(QString sn,int iresult){
		QSqlDatabase templatedb= QSqlDatabase::addDatabase("QSQLITE", "JSL_OtpCount");
		templatedb.setDatabaseName(QDir::currentPath() % "/JSL_OtpCount");
		if (!templatedb.open())
			return false;

		QSqlQuery query(templatedb);
		query.prepare("select chipid from focus where chipid=:sn" );
		query.bindValue(":sn",sn);
		query.exec();

		if(query.next()){
			query.prepare("update focus set date=:date,time=:time,class=:result where chipid=:sn");
			query.bindValue(":sn",sn);
			query.bindValue(":date",QDate::currentDate());
			query.bindValue(":time",QTime::currentTime());
			query.bindValue(":result",iresult);
			query.exec();
		}else{
			query.prepare("insert into focus values(:sn,:date,:result,:time)");
			query.bindValue(":sn",sn);
			query.bindValue(":date",QDate::currentDate());
			query.bindValue(":time",QTime::currentTime());
			query.bindValue(":result",iresult);
			query.exec();
		}

		return true;
	}

	__inline bool getFocusDataFromDB(QDate date,QStringList &listOK,QStringList &listNG){
		QStringList list;
		QSqlDatabase templatedb= QSqlDatabase::addDatabase("QSQLITE", "JSL_OtpCount");
		templatedb.setDatabaseName(QDir::currentPath() % "/JSL_OtpCount");
		templatedb.open();
		QSqlQuery query(templatedb);

		for (int i=0;i<24;i++)
		{
			query.prepare("select count(chipid) as cou from focus where date=:date and time>=:timebegin and time<=:timeend and class=0");
			QString strbegin,strend;
			strbegin=QString("%1:00:00").arg(i);
			strend=QString("%1:59:59").arg(i);
			query.bindValue(":date",date);
			query.bindValue(":timebegin",strbegin);
			query.bindValue(":timeend",strend);
			query.exec();

			if(query.next()){
				listOK.push_back(query.value(0).toString());
			}else{
				listOK.push_back("0");
			}

			query.prepare("select count(chipid) as cou from focus where date=:date and time>=:timebegin and time<=:timeend and class!=0");
			strbegin=QString("%1:00:00").arg(i);
			strend=QString("%1:59:59").arg(i);
			query.bindValue(":date",date);
			query.bindValue(":timebegin",strbegin);
			query.bindValue(":timeend",strend);
			query.exec();

			if(query.next()){
				listNG.push_back(query.value(0).toString());
			}else{
				listNG.push_back("0");
			}
		}
		
		templatedb.close();
		templatedb.removeDatabase("JSL_OtpCount");
		return true;
	};

	__inline bool getFocusDataFromDB(QDate date,QString timeBegin,QString timeEnd,QList<int> &listKey,QList<int> &listVal){
		QStringList list;
		QSqlDatabase templatedb= QSqlDatabase::addDatabase("QSQLITE", "JSL_OtpCount");
		templatedb.setDatabaseName(QDir::currentPath() % "/JSL_OtpCount");
		templatedb.open();
		QSqlQuery query(templatedb);

		query.prepare("select class,count(class) as cou from focus where date=:date and time>=:timebegin and time<=:timeend group by class");
		query.bindValue(":date",date);
		query.bindValue(":timebegin",timeBegin);
		query.bindValue(":timeend",timeEnd);
		query.exec();

		while(query.next()){
			listKey.push_back(query.value(0).toInt());
			listVal.push_back(query.value(1).toInt());
		}

		templatedb.close();
		templatedb.removeDatabase("JSL_OtpCount");
		return true;
	};

}

namespace HISPLATFORMOS
{
	__inline void fillCalibrationItemR5(_HisFX3R2_OSCal_Item* stCal, unsigned int& uiItemCount)
	{
		QStringList strList;

		//MIPI C1
		QString strMIPIDGND	=	"IO_IN0;IO_OUT0;IO_OUT1;SDA;SCL;RST;PWDN;MCLK;LAN3-P;LAN3-N;LAN2-P;LAN2-N;LAN1-P;LAN1-N;LAN0-P;LAN0-N;MCP;MCN;OTP;AVDD;DOVDD;DVDD;AF-VCC;5V;POW;AGND";
		QString strMIPIAGND	=	"IO_IN0;IO_OUT0;IO_OUT1;SDA;SCL;RST;PWDN;MCLK;LAN3-P;LAN3-N;LAN2-P;LAN2-N;LAN1-P;LAN1-N;LAN0-P;LAN0-N;MCP;MCN;OTP;AVDD;DOVDD;DVDD;AF-VCC;5V;POW;DGND";
		QString strMIPIDOVDD	=	"IO_IN0;IO_OUT0;IO_OUT1;SDA;SCL;RST;PWDN;MCLK;LAN3-P;LAN3-N;LAN2-P;LAN2-N;LAN1-P;LAN1-N;LAN0-P;LAN0-N;MCP;MCN";

		QString strDVPDGND = "IO_IN0;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;D10;D11;D12;D13;D14;D15;PCLK;HSYNC;VSYNC;IO_OUT1;MCLK;PWDN;RST;SCL;SDA;AVDD;DOVDD;DVDD;AF-VCC;AGND";
		QString strDVPAGND = "IO_IN0;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;D10;D11;D12;D13;D14;D15;PCLK;HSYNC;VSYNC;IO_OUT1;MCLK;PWDN;RST;SCL;SDA;AVDD;DOVDD;DVDD;AF-VCC;DGND";
		QString strDVPDOVDD	=	"IO_IN0;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;D10;D11;D12;D13;D14;D15;PCLK;HSYNC;VSYNC;IO_OUT1;MCLK;PWDN;RST;SCL;SDA";


		//MIPI C1
		strList	=	strMIPIDGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIAGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "AGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIDOVDD.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DOVDD");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//MIPI C2
		strList	=	strMIPIDGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIAGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "AGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIDOVDD.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DOVDD");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//DVP
		strList	=	strDVPDGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPAGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "AGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPDOVDD.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DOVDD");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//MIPI C1
		QString strOHM	=	"IO_OUT0;IO_OUT1;RST;PWDN;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_IN0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_IN0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT1;RST;PWDN;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_OUT0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_OUT0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT0;RST;PWDN;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_OUT1");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_OUT1");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT0;IO_OUT1;PWDN;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "RST");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "RST");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT0;IO_OUT1;RST;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "PWDN");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	2;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "PWDN");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//DVP
		strOHM	=	"IO_OUT1;PWDN;RST;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_IN0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;PWDN;RST;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO_OUT1");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT1;RST;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "PWDN");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strOHM	=	"IO_IN0;IO_OUT1;PWDN;AGND;DGND";
		strList	=	strOHM.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "RST");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}
	}

	__inline void fillCalibrationItemR3(_HisFX3R2_OSCal_Item* stCal, unsigned int& uiItemCount)
	{
		QStringList strList;

		QString strMIPIDGND	=	"AVDD;DVDD;DOVDD;AF-VCC;VPP;5V;RST;PWDN;MCLK;SDA;SCL;MCP0;MCN0;LAN0-P;LAN0-N;LAN1-P;LAN1-N;LAN2-P;LAN2-N;LAN3-P;LAN3-N;IO2;IO3;IO4;AGND";
		QString strMIPIAGND	=	"AVDD;DVDD;DOVDD;AF-VCC;VPP;5V;RST;PWDN;MCLK;SDA;SCL;MCP0;MCN0;LAN0-P;LAN0-N;LAN1-P;LAN1-N;LAN2-P;LAN2-N;LAN3-P;LAN3-N;IO2;IO3;IO4;DGND";
		QString strMIPIDOVDD	=	"RST;PWDN;MCLK;SDA;SCL;MCP0;MCN0;LAN0-P;LAN0-N;LAN1-P;LAN1-N;LAN2-P;LAN2-N;LAN3-P;LAN3-N;IO2;IO3;IO4";

		QString strDVPDGND = "AVDD;DVDD;DOVDD;AF-VCC;HSYNC;VSYNC;RST;PWDN;MCLK;SDA;SCL;PCLK;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;IO0;IO1;AGND";
		QString strDVPAGND = "AVDD;DVDD;DOVDD;AF-VCC;HSYNC;VSYNC;RST;PWDN;MCLK;SDA;SCL;PCLK;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;IO0;IO1;DGND";
		QString strDVPDOVDD	=	"HSYNC;VSYNC;RST;PWDN;MCLK;SDA;SCL;PCLK;D0;D1;D2;D3;D4;D5;D6;D7;D8;D9;IO0;IO1";

		//MIPI C1
		strList	=	strMIPIDGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIAGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "AGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIDOVDD.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DOVDD");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//DVP
		strList	=	strDVPDGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPAGND.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "AGND");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPDOVDD.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "DOVDD");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		QString strMIPIIO2 = "RST;PWDN;IO3;IO4;DGND;AGND";
		QString strMIPIIO3 = "RST;PWDN;IO2;IO4;DGND;AGND";
		QString strMIPIIO4	= "RST;PWDN;IO2;IO3;DGND;AGND";
		QString strMIPIRST	 = "PWDN;IO2;IO3;IO4;DGND;AGND";
		QString strMIPIPWDN = "RST;IO2;IO3;IO4;DGND;AGND";

		QString strDVPIO0 = "RST;PWDN;IO1;DGND;AGND";
		QString strDVPIO1 = "RST;PWDN;IO0;DGND;AGND";
		QString strDVPRST	 = "PWDN;IO0;IO1;DGND;AGND";
		QString strDVPPWDN = "RST;IO0;IO1;DGND;AGND";

		strList	=	strMIPIIO2.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO2");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIIO3.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO3");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIIO4.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO4");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIRST.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "RST");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strMIPIPWDN.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	0;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "PWDN");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		//DVP
		strList	=	strDVPIO0.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO0");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPIO1.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "IO1");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPRST.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "RST");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

		strList	=	strDVPPWDN.split(";");
		for(unsigned int x=0;	x<strList.size();	++x){
			stCal[uiItemCount].ucSwitch	=	1;
			sprintf_s(stCal[uiItemCount].str1stName, 8, "PWDN");
			sprintf_s(stCal[uiItemCount].str2ndName, 8, "%s", strList.at(x).toAscii().data());
			++uiItemCount;
		}

	}

	__inline int OSCal2DB(unsigned int* puiKey, _HisFX3R2_OSCal_Item* pstCal, unsigned int uiItemCount)
	{
		if(!HISDBROLONGO::isCustomCanOpen())
		{
			return HisCCMError_Database;
		}

		if(!HISDBROLONGO::isTableExist("osoffset"))
		{
			HISDBROLONGO::createNewTable("[osoffset]([md0] INTEGER, [md1] INTEGER, [md2] INTEGER, [md3] INTEGER, [isdvp] INTEGER, [name1st] TEXT, [name2nd] TEXT, [offset] DOUBLE)");
		}

		bool bparsesuccess	=	true;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QString strData, strdata2;
			QStringList strname, strvalue;
			QSqlQuery query(customdb);

			query.prepare("DELETE FROM osoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3");
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.exec();

			customdb.transaction();

			for(unsigned int x=0;	x<uiItemCount;	++x){
				query.prepare("INSERT INTO osoffset(md0,md1,md2,md3,isdvp,name1st,name2nd,offset) VALUES(:md0,:md1,:md2,:md3,:isdvp,:name1st,:name2nd,:offset)");
				query.bindValue(":md0", puiKey[0]);
				query.bindValue(":md1", puiKey[1]);
				query.bindValue(":md2", puiKey[2]);
				query.bindValue(":md3", puiKey[3]);
				query.bindValue(":isdvp", pstCal[x].ucSwitch);
				query.bindValue(":name1st", QString::fromAscii(pstCal[x].str1stName));
				query.bindValue(":name2nd", QString::fromAscii(pstCal[x].str2ndName));
				query.bindValue(":offset", pstCal[x].flOffset);
				query.exec();
			}

			customdb.commit();

			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		return 0;
	}

	__inline int OSCalFromDB(unsigned int* puiKey, _HisFX3R2_OSCal_Item* pstCal, unsigned int* puiItemCount, QMutex& mutexDatabase)
	{
		QMutexLocker locker(&mutexDatabase);

		if(!HISDBROLONGO::isCustomCanOpen())
		{
			return HisCCMError_Database;
		}

		if(!HISDBROLONGO::isTableExist("osoffset"))
		{
			return HisFX3Error_Other;
		}

		bool bparsesuccess	=	true;
		*puiItemCount	=	0;

		//读取，解析config
		for(int  w=0;	w<1;	++w){ //此处是有意义的,不要删除
			QSqlDatabase customdb = QSqlDatabase::addDatabase("QSQLITE", "queryrolongo");
			customdb.setDatabaseName(QDir::currentPath() % "/HisFX3Rolongo");
			if (!customdb.open()){
				bparsesuccess	=	false;
				break;
			}

			QSqlQuery query(customdb);
			query.prepare("SELECT isdvp,name1st,name2nd,offset FROM osoffset WHERE md0=:md0 AND md1=:md1 AND md2=:md2 AND md3=:md3" );
			query.bindValue(":md0", puiKey[0]);
			query.bindValue(":md1", puiKey[1]);
			query.bindValue(":md2", puiKey[2]);
			query.bindValue(":md3", puiKey[3]);
			query.exec();

			unsigned int isdvp;
			float offset;
			QString name1st, name2nd;
			while (query.next()){
				isdvp			=	query.value(0).toUInt();
				name1st		=	query.value(1).toString();
				name2nd		=	query.value(2).toString();
				offset			=	query.value(3).toDouble();
				pstCal[*puiItemCount].ucSwitch	=	isdvp;
				pstCal[*puiItemCount].flOffset		=	offset;
				sprintf_s(pstCal[*puiItemCount].str1stName, 8, "%s", name1st.toAscii().data());
				sprintf_s(pstCal[*puiItemCount].str2ndName, 8, "%s", name2nd.toAscii().data());
				++(*puiItemCount);
			}

			customdb.close();
		}

		QSqlDatabase::removeDatabase("queryrolongo");

		if(!bparsesuccess){
			return HisCCMError_Database;
		}

		if(*puiItemCount == 0)
		{
			return HisFX3Error_OSNotCalibration;
		}

		return 0;
	}
}

namespace HISGLOBALUI
{


	__inline bool isUnlocked()
	{
		if(!hisglobalparameter.bconfiglock) return true;
		bool bok;
		QString strText	=	QInputDialog::getText(0, QObject::tr("Please enter the password"), QObject::tr("Password:"), QLineEdit::PasswordEchoOnEdit, QString(), &bok, Qt::Dialog);
		strText	=	strText.trimmed();
		if(bok)
		{
			if(hisglobalparameter.strPassword.isEmpty() || (hisglobalparameter.strPassword == strText)){
				hisglobalparameter.bconfiglock	=	false;
				return true;
			}
		}

		QMessageBox::critical(0, QObject::tr("Error"), QObject::tr("Please Unlock First."));
		return false;
	}

	__inline QString protocal2String(unsigned int uiProtocal)
	{
		QString strProtocal;
		switch (uiProtocal)
		{
		case _HisFX3_MIPILane_Stream_DVP:	strProtocal	=	"DVP";		break;
		case _HisFX3_MIPILane_Stream_Lane1_FPGA:	strProtocal	=	"MIPI 1Lane-FPGA";		break;
		case _HisFX3_MIPILane_Stream_Lane2_FPGA:	strProtocal	=	"MIPI 2Lane-FPGA";		break;
		case _HisFX3_MIPILane_Stream_Lane3_FPGA:	strProtocal	=	"MIPI 3Lane-FPGA";		break;
		case _HisFX3_MIPILane_Stream_Lane4_FPGA:	strProtocal	=	"MIPI 4Lane-FPGA";		break;
		case _HisFX3_MIPILane_Stream_Lane8_FPGA:	strProtocal	=	"MIPI 8Lane-FPGA";		break;
		case _HisFX3_MIPILane_Stream_Lane1_ST:	strProtocal	=	"MIPI 1Lane-ST";		break;
		case _HisFX3_MIPILane_Stream_Lane2_ST:	strProtocal	=	"MIPI 2Lane-ST";		break;
		case _HisFX3_MIPILane_Stream_SubLVDS_SONY:	strProtocal	=	"LVDS SONY";		break;
		case _HisFX3_MIPILane_Stream_SubLVDS_CMOSIS:	strProtocal	=	"LVDS CMOSIS";		break;
		case _HisFX3_MIPILane_Stream_HiSPI_Packetized_SP:	strProtocal	=	"HiSPI Packetized-SP";		break;
		case _HisFX3_MIPILane_Stream_HiSPI_Streaming_SP:	strProtocal	=	"HiSPI Streaming-SP";		break;
		case _HisFX3_MIPILane_Stream_HiSPI_Streaming_S:	strProtocal	=	"HiSPI Streaming-S";		break;
		case _HisFX3_MIPILane_Stream_HiSPI_ActiveStart_SP8:	strProtocal	=	"HiSPI ActiveStart-SP8";		break;
		case _HisFX3_MIPILane_Stream_Analog_Interleave:	strProtocal	=	"BT565-Interleave";		break;
		case _HisFX3_MIPILane_Stream_Analog_Progressive:	strProtocal	=	"BT565-Progressive";		break;
		case _HisFX3_MIPILane_Stream_BT1120M1_Interleave:	strProtocal	=	"BT1120M1-Interleave";		break;
		case _HisFX3_MIPILane_Stream_BT1120M1_Progressive:	strProtocal	=	"BT1120M1-Progressive";		break;
		case _HisFX3_MIPILane_Stream_BT1120M2_Interleave:	strProtocal	=	"BT1120M2-Interleave";		break;
		case _HisFX3_MIPILane_Stream_BT1120M2_Progressive:	strProtocal	=	"BT1120M2-Progressive";		break;
		case _HisFX3_MIPILane_Stream_DVP_HDMI:	strProtocal	=	"HDMI";		break;
		case _HisFX3_MIPILane_Stream_UVC:	strProtocal	=	"UVC";		break;
		case _HisFX3_MIPILane_Stream_HDMI:	strProtocal	=	"HDMI";		break;
		case _HisFX3_MIPILane_Stream_RTSP:	strProtocal	=	"RTSP";		break;
		case _HisFX3_MIPILane_Stream_Jigboard:	strProtocal	=	"Jigboard";		break;
		default:		break;
		}
		return strProtocal;
	}

	__inline unsigned int protocal2UInt(QString strProtocal)
	{
		unsigned int uiProtocal = _HisFX3_MIPILane_Stream_Lane2_FPGA;
		if(strProtocal == "DVP")	uiProtocal	=	_HisFX3_MIPILane_Stream_DVP;
		else if(strProtocal == "MIPI 1Lane-FPGA")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane1_FPGA;
		else if(strProtocal == "MIPI 2Lane-FPGA")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane2_FPGA;
		else if(strProtocal == "MIPI 3Lane-FPGA")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane3_FPGA;
		else if(strProtocal == "MIPI 4Lane-FPGA")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane4_FPGA;
		else if(strProtocal == "MIPI 8Lane-FPGA")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane8_FPGA;
		else if(strProtocal == "MIPI 1Lane-ST")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane1_ST;
		else if(strProtocal == "MIPI 2Lane-ST")	uiProtocal	=	_HisFX3_MIPILane_Stream_Lane2_ST;
		else if(strProtocal == "LVDS SONY")	uiProtocal	=	_HisFX3_MIPILane_Stream_SubLVDS_SONY;
		else if(strProtocal == "LVDS CMOSIS")	uiProtocal	=	_HisFX3_MIPILane_Stream_SubLVDS_CMOSIS;
		else if(strProtocal == "HiSPI Packetized-SP")	uiProtocal	=	_HisFX3_MIPILane_Stream_HiSPI_Packetized_SP;
		else if(strProtocal == "HiSPI Streaming-SP")	uiProtocal	=	_HisFX3_MIPILane_Stream_HiSPI_Streaming_SP;
		else if(strProtocal == "HiSPI Streaming-S")	uiProtocal	=	_HisFX3_MIPILane_Stream_HiSPI_Streaming_S;
		else if(strProtocal == "HiSPI ActiveStart-SP8")	uiProtocal	=	_HisFX3_MIPILane_Stream_HiSPI_ActiveStart_SP8;
		else if(strProtocal == "BT565-Interleave")	uiProtocal	=	_HisFX3_MIPILane_Stream_Analog_Interleave;
		else if(strProtocal == "BT565-Progressive")	uiProtocal	=	_HisFX3_MIPILane_Stream_Analog_Progressive;
		else if(strProtocal == "BT1120M1-Interleave")	uiProtocal	=	_HisFX3_MIPILane_Stream_BT1120M1_Interleave;
		else if(strProtocal == "BT1120M1-Progressive")	uiProtocal	=	_HisFX3_MIPILane_Stream_BT1120M1_Progressive;
		else if(strProtocal == "BT1120M2-Interleave")	uiProtocal	=	_HisFX3_MIPILane_Stream_BT1120M2_Interleave;
		else if(strProtocal == "BT1120M2-Progressive")	uiProtocal	=	_HisFX3_MIPILane_Stream_BT1120M2_Progressive;
		else if(strProtocal == "HDMI")	uiProtocal	=	_HisFX3_MIPILane_Stream_DVP_HDMI;
		else if(strProtocal == "UVC")	uiProtocal	=	_HisFX3_MIPILane_Stream_UVC;
		else if(strProtocal == "HDMI")	uiProtocal	=	_HisFX3_MIPILane_Stream_HDMI;
		else if(strProtocal == "RTSP")	uiProtocal	=	_HisFX3_MIPILane_Stream_RTSP;
		else if(strProtocal == "Jigboard")	uiProtocal	=	_HisFX3_MIPILane_Stream_Jigboard;
		return uiProtocal;
	}

	__inline QString dataformat2String(unsigned int uiDataFormat)
	{
		QString strFormat;
		switch (uiDataFormat)
		{
		case HisBaylor8_BGGR:	strFormat = "baylor8_bggr";	break;
		case HisBaylor8_RGGB:	strFormat = "baylor8_rggb";	break;
		case HisBaylor8_GRBG:	strFormat = "baylor8_grbg";	break;
		case HisBaylor8_GBRG:	strFormat = "baylor8_gbrg";	break;
		case HisBaylor8_MONO:	strFormat = "baylor8_mono";	break;
		case HisBaylor10_BGGR:	strFormat = "baylor10_bggr";	break;
		case HisBaylor10_RGGB:	strFormat = "baylor10_rggb";	break;
		case HisBaylor10_GRBG:	strFormat = "baylor10_grbg";	break;
		case HisBaylor10_GBRG:	strFormat = "baylor10_gbrg";	break;
		case HisBaylor10_MONO:	strFormat = "baylor10_mono";	break;
		case HisBaylor12_BGGR:	strFormat = "baylor12_bggr";	break;
		case HisBaylor12_RGGB:	strFormat = "baylor12_rggb";	break;
		case HisBaylor12_GRBG:	strFormat = "baylor12_grbg";	break;
		case HisBaylor12_GBRG:	strFormat = "baylor12_gbrg";	break;
		case HisBaylor12_MONO:	strFormat = "baylor12_mono";	break;
		case HisYUV8_422_YUYV:	strFormat = "yuyv422_8bit";	break;
		case HisYUV8_422_UYVY:	strFormat = "uyvy422_8bit";	break;
		case HisYUV8_422_YVYU:	strFormat = "yvyu422_8bit";	break;
		case HisYUV8_422_VYUY:	strFormat = "vyuy422_8bit";	break;
		case HisRGB_RGB24:	strFormat = "rgb24";	break;
		default: break;
		}
		return strFormat;
	}

	__inline _HisFX3_BaylorMode dataformat2UInt(QString strFormat)
	{ 
		_HisFX3_BaylorMode uiDataFormat	=	HisBaylor8_BGGR;
		if(strFormat == "baylor8_bggr")	uiDataFormat	=	HisBaylor8_BGGR;
		else if(strFormat == "baylor8_rggb")	uiDataFormat	=	HisBaylor8_RGGB;
		else if(strFormat == "baylor8_grbg")	uiDataFormat	=	HisBaylor8_GRBG;
		else if(strFormat == "baylor8_gbrg")	uiDataFormat	=	HisBaylor8_GBRG;
		else if(strFormat == "baylor8_mono")	uiDataFormat	=	HisBaylor8_MONO;
		else if(strFormat == "baylor10_bggr")	uiDataFormat	=	HisBaylor10_BGGR;
		else if(strFormat == "baylor10_rggb")	uiDataFormat	=	HisBaylor10_RGGB;
		else if(strFormat == "baylor10_grbg")	uiDataFormat	=	HisBaylor10_GRBG;
		else if(strFormat == "baylor10_gbrg")	uiDataFormat	=	HisBaylor10_GBRG;
		else if(strFormat == "baylor10_mono")	uiDataFormat	=	HisBaylor10_MONO;
		else if(strFormat == "baylor12_bggr")	uiDataFormat	=	HisBaylor12_BGGR;
		else if(strFormat == "baylor12_rggb")	uiDataFormat	=	HisBaylor12_RGGB;
		else if(strFormat == "baylor12_grbg")	uiDataFormat	=	HisBaylor12_GRBG;
		else if(strFormat == "baylor12_gbrg")	uiDataFormat	=	HisBaylor12_GBRG;
		else if(strFormat == "baylor12_mono")	uiDataFormat	=	HisBaylor12_MONO;
		else if(strFormat == "yuyv422_8bit")	uiDataFormat	=	HisYUV8_422_YUYV;
		else if(strFormat == "uyvy422_8bit")	uiDataFormat	=	HisYUV8_422_UYVY;
		else if(strFormat == "yvyu422_8bit")	uiDataFormat	=	HisYUV8_422_YVYU;
		else if(strFormat == "vyuy422_8bit")	uiDataFormat	=	HisYUV8_422_VYUY;
		else if(strFormat == "rgb24")	uiDataFormat	=	HisRGB_RGB24;
		return uiDataFormat;
	}

	__inline QString poweron2String(unsigned int uiData)
	{
		QString strPowerOn = "OV";
		switch (uiData)
		{
		case _HisFX3_ImageSenor_Factory_OTHER: strPowerOn	=	"OTHERS";	break;
		case _HisFX3_ImageSenor_Factory_CUSTOM: strPowerOn	=	"CUSTOM";	break;
		case _HisFX3_ImageSenor_Factory_SUPERPIX: strPowerOn	=	"SUPERPIX";	break;
		case _HisFX3_ImageSenor_Factory_GCOREINC: strPowerOn	=	"GCOREINC";	break;
		case _HisFX3_ImageSenor_Factory_TOSHIBA: strPowerOn	=	"TOSHIBA";	break;
		case _HisFX3_ImageSenor_Factory_ST: strPowerOn	=	"ST";	break;
		case _HisFX3_ImageSenor_Factory_APTINA: strPowerOn	=	"APTINA";	break;
		case _HisFX3_ImageSenor_Factory_HYNIX: strPowerOn	=	"HYNIX";	break;
		case _HisFX3_ImageSenor_Factory_SANSUNG: strPowerOn	=	"SANSUNG";	break;
		case _HisFX3_ImageSenor_Factory_DONGBU: strPowerOn	=	"DONGBU";	break;
		case _HisFX3_ImageSenor_Factory_SONY: strPowerOn	=	"SONY";	break;
		case _HisFX3_ImageSenor_Factory_OV: strPowerOn	=	"OV";	break;
		default:	break;
		}
		return strPowerOn;
	}

	__inline _HisFX3_ImageSenor_Factory poweron2UInt(QString strData)
	{
		_HisFX3_ImageSenor_Factory uiPowerOn	=	_HisFX3_ImageSenor_Factory_OV;
		if(strData	==	"OTHERS")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_OTHER;
		else if(strData	==	"CUSTOM")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_CUSTOM;
		else if(strData	==	"SUPERPIX")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_SUPERPIX;
		else if(strData	==	"GCOREINC")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_GCOREINC;
		else if(strData	==	"TOSHIBA")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_TOSHIBA;
		else if(strData	==	"ST")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_ST;
		else if(strData	==	"APTINA")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_APTINA;
		else if(strData	==	"HYNIX")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_HYNIX;
		else if(strData	==	"SANSUNG")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_SANSUNG;
		else if(strData	==	"DONGBU")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_DONGBU;
		else if(strData	==	"SONY")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_SONY;
		else if(strData	==	"OV")	uiPowerOn	=	_HisFX3_ImageSenor_Factory_OV;
		return uiPowerOn;
	} 

}

namespace HISMANUALMODE
{
	__inline bool isModuleHotPlugIn()
	{
		_HisFX3OS_OHM_Item stItem;
		sprintf(stItem.str1stName, "DGND");
		memcpy(stItem.str2ndName, hisglobalparameter.stOperatorMode.strPlug2ndName, 8);
		int iresult =  classPlatform.HisFX3OSOhmTest(hisglobalparameter.stOperatorMode.ucPlugInterface, stItem, 0.0f, 1);
		if(iresult) { return false;}

		if(stItem.flOhmValue > hisglobalparameter.stOperatorMode.flPlugMax || stItem.flOhmValue < hisglobalparameter.stOperatorMode.flPlugMin)
			return false;

		return true;
	}
	 
	__inline bool isManualModeBStreaming(_threadshareData& threadshareData, unsigned long long& ui64FrameIndex, int iImageTimeOut)
	{
		QElapsedTimer classTime;
		classTime.start();
		bool bresult = false;
		unsigned long long ui64Now;
		while(classTime.elapsed() < iImageTimeOut)
		{
			ui64Now	=	threadshareData.GetHisRawFrameIndex();
			if(ui64Now > ui64FrameIndex){
				ui64FrameIndex	=	ui64Now;
				bresult = true;
				break;
			}
			Sleep(10);
		}
		return bresult;
	}
}

namespace HISPARAMETER
{
}

namespace HISCCMSHORTCUT
{

	__inline QStringList getListALLItemKey()
	{
		QStringList listKey;
		listKey.push_back("HisFX3CCMTest");
#ifdef _HisFX3_Platform_Jigboard
		listKey.push_back("_HisFX3_Platform_Jigboard");
#endif

#ifdef USE_EQUIPMENT_GB_AFBURN
		listKey.push_back("HisGerneralMotion");
		listKey.push_back("USE_EQUIPMENT_GB_AFBURN");
#endif

#ifdef USE_EQUIPMENT_GB_PDAF
		listKey.push_back("HisGerneralMotion");
		listKey.push_back("USE_EQUIPMENT_GB_PDAF");
#endif

#ifdef USE_EQUIPMENT_AFM_JSL_V1
		listKey.push_back("USE_EQUIPMENT_AFM_JSL_V1");
#endif

#ifdef USE_EQUIPMENT_JSL_FUNCTION_V1
		listKey.push_back("USE_EQUIPMENT_JSL_FUNCTION_V1");	
#endif

#ifdef USE_EQUIPMENT_JSL_RRT_V1
		listKey.push_back("HisGerneralMotion");
		listKey.push_back("USE_EQUIPMENT_JSL_RRT_V1");
#endif

		return listKey;
	}

	__inline int getCCMShortcutItem(QMutex& mutexDatabase, QString currentTableName, QShortcutList& listShortcutItem, bool bChannel = true)
	{
		listShortcutItem.clear();
		if(currentTableName.isEmpty()) return HisFX3Error_Parameter;

		QMutexLocker locker(&mutexDatabase);
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBCUSTOM::addDB(stSqlDB);
			if(bDB){
				QSqlQuery query(stSqlDB);
				if(bChannel)
					query.prepare("SELECT item FROM " % currentTableName % " WHERE classfy='shortcut' OR classfy='shortcut1'" );
				else
					query.prepare("SELECT item FROM " % currentTableName % " WHERE classfy='shortcut' OR classfy='shortcut2'" );
				query.exec();
				unsigned int uiCount	=	0;
				while (query.next()){
					++uiCount;
				}

				listShortcutItem.reserve(uiCount);
				if(bChannel)
					query.prepare("SELECT classfy,item,itemsuffix1,itemsuffix2,key,value,reserve FROM " % currentTableName % " WHERE classfy='shortcut'  OR classfy='shortcut1'" );
				else
					query.prepare("SELECT classfy,item,itemsuffix1,itemsuffix2,key,value,reserve FROM " % currentTableName % " WHERE classfy='shortcut'  OR classfy='shortcut2'" );
				query.exec();

				_shoutCutDetail stShortCutItem;
// 				QStringList listKey = getListALLItemKey();
				QList<_TestItem_Basic_Info> itemList;
// 				globalgetListWantedTestItem(itemList, listKey);
				globalgetListAllTestItem(itemList);

				qDebug() << "getCCMShortcutItem" << currentTableName;

				QString strData, strData2;
				while (query.next())
				{
					strData	=	query.value(0).toString().trimmed();
					stShortCutItem.bDualCamera	=	(strData == "shortcut")?(false):(true);

					strData	=	query.value(2).toString().trimmed();
					if(strData.size()	==	1)	stShortCutItem.shortcutKey	=	(strData.at(0)).toAscii();
					else	continue;

					if(stShortCutItem.shortcutKey != '=' && (stShortCutItem.shortcutKey < 'a' || stShortCutItem.shortcutKey > 'z') && (stShortCutItem.shortcutKey < '0' || stShortCutItem.shortcutKey > '9')) continue;

					strData	=	query.value(3).toString().trimmed();
					if(strData	==	"first_click")	stShortCutItem.ucClickTime	=	1;
					else if(strData	==	"second_click")	stShortCutItem.ucClickTime	=	2;
					else	continue;

					strData	=	query.value(4).toString().trimmed();
					if(strData.size()	>=	1)	stShortCutItem.ucItemIndex	=	strData.toUInt();
					else	continue;

					strData	=	query.value(5).toString().trimmed();	
					int iIndex2	=	strData.indexOf("(");
					if(iIndex2 < 0){
						stShortCutItem.strAddInfo.clear();
					}
					else{
						stShortCutItem.strAddInfo	=	strData.right(strData.size() - iIndex2);
						strData	=	strData.left(iIndex2);
					}

					stShortCutItem.usItem	=	HISGLOBALSHORTCUT::getIdFromSaveName(itemList, strData);
					if(!stShortCutItem.usItem) continue;

					strData	=	query.value(6).toString().trimmed();
					stShortCutItem.ucloopTime	=	1;
					stShortCutItem.usItemfail		=	0;
					if(strData.size() > 0){
						int iindex	=	strData.indexOf("(");
						if(iindex > 0){
							strData2	=	strData.left(iindex);
							stShortCutItem.ucloopTime = strData2.toUInt() & 0xFF;
							stShortCutItem.ucloopTime = max(1, stShortCutItem.ucloopTime);
							stShortCutItem.ucloopTime = min(50, stShortCutItem.ucloopTime);
						}
						else if(iindex < 0){
							stShortCutItem.ucloopTime = strData.toUInt() & 0xFF;
							stShortCutItem.ucloopTime = max(1, stShortCutItem.ucloopTime);
							stShortCutItem.ucloopTime = min(50, stShortCutItem.ucloopTime);
						}
						if(iindex >= 0){
							strData	=	strData.right(strData.size() -iindex -1);
							strData	=	strData.remove("false:");
							strData	=	strData.remove(")");
							stShortCutItem.usItemfail	=	HISGLOBALSHORTCUT::getIdFromSaveName(itemList, strData);
						}
					}

					listShortcutItem.push_back(stShortCutItem);
				}

				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBCUSTOM::removeDB();
		}

		return 0;
	}

	__inline bool getShortcutSync()
	{
		bool bSync = false;
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				QSqlQuery query(stSqlDB);
				query.prepare("SELECT value FROM global WHERE classfy='shortcut' AND key='sync'" );
				query.exec();
				
				while (query.next()){
					bSync	=	query.value(0).toUInt();
				}

				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}

		return bSync;
	}

	__inline void saveShortcutSync(bool bSync)
	{
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_key, "shortcut", QVariant(), QVariant(), QVariant(), "sync");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 0, "shortcut", QVariant(), QVariant(), QVariant(), "sync", ((bSync)?("1"):("0")));
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}

		return;
	}

	__inline int setShortcutSync(QShortcutList& listShortcutItem)
	{
		if(listShortcutItem.size() < 1) return 0;
		bool bSync = getShortcutSync();
		for(int x=0;	x<listShortcutItem.size();	++x){
			listShortcutItem[x].bSync	=	bSync;
		}
		return 0;
	}

	__inline int getNextTestItem(char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex, const bool bDualCamera, const bool bBoxChannel1)
	{
		int iIndex	=	-1, iMin = 0x00FFFFFF;
		QShortcutList& listItemthe = (bBoxChannel1)?(itemshareDataC1.shortcutgather):(itemshareDataC2.shortcutgather);
		for(int x=0;	x<listItemthe.size();	++x)
		{
			if((listItemthe[x].ucItemIndex >= ucItemIndex) && (listItemthe[x].shortcutKey == shortcutKey) && (listItemthe[x].ucClickTime == ucClickTime) && (listItemthe[x].bDualCamera == bDualCamera)){
				if(listItemthe[x].ucItemIndex < iMin) { iMin = listItemthe[x].ucItemIndex; iIndex = x; }
			}
		}
		if((iIndex < 0) || !bDualCamera || !listItemthe[iIndex].bSync) return iIndex;
		unsigned char w = listItemthe[iIndex].ucItemIndex;
		QReadWriteLock& locker = (bBoxChannel1)?(itemshareDataC2.itemstatusLock):(itemshareDataC1.itemstatusLock);
		QShortcutList& listItemother = (bBoxChannel1)?(itemshareDataC2.shortcutgather):(itemshareDataC1.shortcutgather);
		QElapsedTimer classTime;
		classTime.start();
		iMin	=	0;
		while(classTime.elapsed() < 120000)
		{
			bool bIs	=	true;
			locker.lockForRead();
			for(int x=0;	x<listItemother.size();	++x)
			{
				if((listItemother[x].ucItemIndex < w) && (listItemother[x].shortcutKey == shortcutKey) && (listItemother[x].ucClickTime == ucClickTime) && (listItemother[x].bDualCamera == bDualCamera)){
					if(!(listItemother[x].status & _shoutCutDetail_Status_Tested)) { bIs = false; break; }
				}
			}
			locker.unlock();
			if(bIs) {iMin = 1; break;}
			Sleep(20);
		}

		return (iMin)?(iIndex):(-1);
	}

	__inline int getNextTestItemFail(QShortcutList& listItem, char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex, unsigned short usItem, bool bDualCamera)
	{
		int iIndex	=	-1;
		for(int x=0;	x<listItem.size();	++x)
		{
			if((listItem[x].ucItemIndex > ucItemIndex) && (listItem[x].shortcutKey == shortcutKey) && (listItem[x].usItem == usItem) && (listItem[x].ucClickTime == ucClickTime) && (listItem[x].bDualCamera == bDualCamera)){
				iIndex	=	listItem[x].ucItemIndex;
				break;
			}
		}
		if(iIndex >= 0)
		{
			for(int x=0;	x<listItem.size();	++x)
			{
				if((listItem[x].ucItemIndex > ucItemIndex) && (listItem[x].ucItemIndex < iIndex) && (listItem[x].shortcutKey == shortcutKey) && (listItem[x].ucClickTime == ucClickTime) && (listItem[x].bDualCamera == bDualCamera)){
					listItem[x].status |= _shoutCutDetail_Status_Tested;
				}
			}
		}
		else
		{
			for(int x=0;	x<listItem.size();	++x)
			{
				if((listItem[x].ucItemIndex > ucItemIndex) && (listItem[x].shortcutKey == shortcutKey) && (listItem[x].ucClickTime == ucClickTime) && (listItem[x].bDualCamera == bDualCamera)){
					listItem[x].status |= _shoutCutDetail_Status_Tested;
				}
			}
		}
		return iIndex;
	}

	__inline int getNextTestItemOneChannel(QShortcutList& listItem, char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex)
	{
		int iIndex	=	-1;
		for(int x=0;	x<listItem.size();	++x)
		{
			if(listItem[x].ucItemIndex == ucItemIndex && listItem[x].shortcutKey == shortcutKey && listItem[x].ucClickTime == ucClickTime && !listItem[x].bDualCamera){
				iIndex	=	x;
				break;
			}
		}
		return iIndex;
	}

	__inline int getNextTestItemTwoChannel(QShortcutList& listItem, char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex)
	{
		int iIndex	=	-1;
		for(int x=0;	x<listItem.size();	++x)
		{
			if(listItem[x].ucItemIndex == ucItemIndex && listItem[x].shortcutKey == shortcutKey && listItem[x].ucClickTime == ucClickTime && listItem[x].bDualCamera){
				iIndex	=	x;
				break;
			}
		}
		return iIndex;
	}

	__inline int getNextTestItemOneChannelFail(QShortcutList& listItem, char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex, unsigned short usItem)
	{
		int iIndex	=	-1;
		for(int x=0;	x<listItem.size();	++x)
		{
			if(listItem[x].ucItemIndex > ucItemIndex && listItem[x].shortcutKey == shortcutKey && listItem[x].usItem == usItem && listItem[x].ucClickTime == ucClickTime && !listItem[x].bDualCamera){
				iIndex	=	listItem[x].ucItemIndex;
				break;
			}
		}
		return iIndex;
	}

	__inline int getNextTestItemTwoChannelFail(QShortcutList& listItemC1, QShortcutList& listItemC2, char shortcutKey, unsigned char ucClickTime, unsigned char ucItemIndex, unsigned short usItem)
	{
		int iIndex	=	-1;
		for(int x=0;	x<listItemC1.size();	++x)
		{
			if(listItemC1[x].ucItemIndex > ucItemIndex && listItemC1[x].shortcutKey == shortcutKey && listItemC1[x].usItem == usItem && listItemC1[x].ucClickTime == ucClickTime && listItemC1[x].bDualCamera){
				iIndex	=	listItemC1[x].ucItemIndex;
				break;
			}
		}
		for(int x=0;	x<listItemC2.size() && iIndex < 0;	++x)
		{
			if(listItemC2[x].ucItemIndex > ucItemIndex && listItemC2[x].shortcutKey == shortcutKey && listItemC2[x].usItem == usItem && listItemC2[x].ucClickTime == ucClickTime && listItemC2[x].bDualCamera){
				iIndex	=	listItemC2[x].ucItemIndex;
				break;
			}
		}
		return iIndex;
	}

	__inline bool isKeyValidOneChannel(char key, unsigned char uctimer, QShortcutList& itemList)
	{
		bool bIs	=	false;
		for(QList<_shoutCutDetail>::iterator theiteraor = itemList.begin(); theiteraor	!= itemList.end(); 	theiteraor++)
		{
			if(theiteraor->shortcutKey == key && theiteraor->ucClickTime == uctimer && !theiteraor->bDualCamera){
				bIs	=	true;
				break;
			}
		}
		return bIs;
	}

	__inline bool isKeyValidTwoChannel(char key, unsigned char uctimer, QShortcutList& itemListC1, QShortcutList& itemListC2)
	{
		bool bIs	=	false;
		for(QList<_shoutCutDetail>::iterator theiteraor = itemListC1.begin(); theiteraor	!= itemListC1.end(); 	theiteraor++)
		{
			if(theiteraor->shortcutKey == key && theiteraor->ucClickTime == uctimer && theiteraor->bDualCamera){
				bIs	=	true;
				break;
			}
		}

		for(QList<_shoutCutDetail>::iterator theiteraor = itemListC2.begin(); theiteraor	!= itemListC2.end() && !bIs; 	theiteraor++)
		{
			if(theiteraor->shortcutKey == key && theiteraor->ucClickTime == uctimer && theiteraor->bDualCamera){
				bIs	=	true;
				break;
			}
		}
		return bIs;
	}

	__inline void eraseKeyItem(QShortcutList& itemList, char key)
	{
		bool bloop	=	true;
		while(bloop)
		{
			bloop	=	false;
			for(unsigned int x=0;	x<itemList.size();	++x)
			{
				if(itemList.at(x).shortcutKey == key){
					bloop	=	true;
					itemList.removeAt(x);
					break;
				}
			}
		}
	}

	__inline QString item2displaytext(unsigned int uiitem)
	{
		QList<_TestItem_Basic_Info> itemALL;
		globalgetListAllTestItem(itemALL);
		QString strText;
		for(QList<_TestItem_Basic_Info>::iterator theiterator = itemALL.begin(); theiterator != itemALL.end(); theiterator++)
		{
			if(uiitem	==	theiterator->uiID) {strText = theiterator->strDescripName; break; }
		}

		if(strText.isEmpty())
		{
			switch (uiitem)
			{
			case whitepanelitem_blemish:	return	QTextCodec::codecForName( "GBK")->toUnicode("脏污A");	break;
			case whitepanelitem_blemishb:	return	QTextCodec::codecForName( "GBK")->toUnicode("脏污B");	break;
			case whitepanelitem_color:	return	QTextCodec::codecForName( "GBK")->toUnicode("颜色");	break;
			case whitepanelitem_snr:	return	QTextCodec::codecForName( "GBK")->toUnicode("信噪比");	break;
			case whitepanelitem_oc:	return	QTextCodec::codecForName( "GBK")->toUnicode("光学中心");	break;
			case whitepanelitem_line:	return	QTextCodec::codecForName( "GBK")->toUnicode("线条");	break;
			case whitepanelitem_pixel:	return	QTextCodec::codecForName( "GBK")->toUnicode("坏点");	break;
			case whitepanelitem_shading:	return	QTextCodec::codecForName( "GBK")->toUnicode("SHADING");	break;
			case whitepanelitem_vignetting:	return	QTextCodec::codecForName( "GBK")->toUnicode("Vignetting");	break;
			}
		}
		return strText;
	}





}


#endif