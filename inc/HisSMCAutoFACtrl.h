// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HISSMCAUTOFACTRL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HISSMCAUTOFACTRL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifndef HISSMCAUTOFACTRL_H
#define HISSMCAUTOFACTRL_H

#ifdef HISSMCAUTOFACTRL_EXPORTS
#define HISSMCAUTOFACTRL_API __declspec(dllexport)
#else
#define HISSMCAUTOFACTRL_API __declspec(dllimport)
#endif

#define _HisMotion_Axis_Main		0x1	//Y
#define _HisMotion_Axis_Next		0x0    //X
#define _HisMotion_Axis_Z			0x2
#define _HisMotion_Axis_U			0x3
#define _HisMotion_Axis_ZU			0x10

#define _HisMotion_SMC6480_Unit_Main			0.001  // mm / plus
#define _HisMotion_SMC6480_Unit_Next			0.0002  // mm / plus
#define _HisMotion_SMC6480_Unit_Z			0.0001  // mm / plus
#define _HisMotion_SMC6480_Unit_U			0.036  // deg / plus
#define _HisMotion_SMC6480_Unit_ZU			27.777777777777777777777777777778 // plus /deg  10000/360

#define _HisMotion_SMC6480_CW			-1.0
#define _HisMotion_SMC6480_CCW			1.0
#define _HisMotion_Zup_LaserDown

#define _BigVision_SMC6480_Unit_X2			0.01  // mm / plus
#define _BigVision_SMC6480_Unit_X1			0.01  // mm / plus
#define _BigVision_SMC6480_Unit_U		0.06768
#define _BigVision_Axis_X1		0x0
#define _BigVision_Axis_X2		0x1
#define _BigVision_Axis_U			0x2

enum _HisMotion_Position{
	HisMotionPosition_Zero				=	0x00,
	HisMotionPosition_Camera			=	0x01,
	HisMotionPosition_FA				=	0x02,
	HisMotionPosition_WhitePanel		=	0x03,
	HisMotionPosition_Laser				=	0x04,
	HisMotionPosition_LaserP1			=	0x05,
	HisMotionPosition_LaserP2			=	0x06,
	HisMotionPosition_LaserP3			=	0x07,
	HisMotionPosition_LaserP4			=	0x08,
	HisMotionPosition_Dispenser			=	0x09,
	HisMotionPosition_FApre750			=	0x10,
	HisMotionPosition_FApre500			=	0x10
};

// This class is exported from the HisSMCAutoFACtrl.dll
class HISSMCAUTOFACTRL_API CHisSMCAutoFACtrl {
public:
	CHisSMCAutoFACtrl(void);
	~CHisSMCAutoFACtrl(void);

	int connect();
	int bv_connect();
	int disconnect();
	bool isconnected();

	//************************************
	// Method:    tohome(X,Y,Z,U回零校正)
	// FullName:  CHisSMCAutoFACtrl::tohome
	// Access:    public 
	// Returns:   int
	// Qualifier:
	//************************************
	int tohome(bool bmain=true, bool bnext=true, bool bz=true, bool bu=true);
	int axismoveabs(unsigned char ucaxis, int ivalue, bool bcheck = true);
	int axismoverelative(unsigned char ucaxis, int ivalue, bool bcheck= true);
	int axisgetabs(unsigned char ucaxis, int& ivalue);
	void setTimeOut(unsigned int uitimeout);

// 	int toabspos(unsigned short usposition, int ioffsetY=0, int ioffsetX=0, int ioffsetZ=0, double dflringangle=0.0, double dfllaser=0.0);

	int setmodulecenter(int idirectmain, int idirectnext, int immpixelMain, int immpixelNext, double dflangle);
	int getVisionOffset(int& imainabsoffset1, int& inextabsoffset1);

	int rotateAngle(double dflrotateangle, bool bBack = true);
	int getlaservalue(double& dflvalue);

	int switcherrorcode(int ierrorcode);
	int setHisMotionAPP(wchar_t* pstrAPP);
	int getSMCDefSet(char* pstrkey, char* pstrvalue);
	int getHisMotionSetInt(wchar_t* pstrkey, int& ivalue);
	int getHisMotionSetDouble(wchar_t* pstrkey, double& dflvalue);
	int setHisMotionSet(wchar_t* pstrkey, wchar_t* pstrvalue);
	int getHisMotionSetStr(wchar_t* pstrkey, char* pstrValue);

	int checkaxisstop(bool bnext, bool bmain, bool bz, bool bu);

	bool singalStartActived();
	bool singalResetActived();
	bool singalCCMActived();
	bool singalPressureActived();
	bool singalEMGActived();
	bool greenSignalOut(bool bOn);
	bool redSignalOut(bool bOn);

	bool resetsignalout(bool bEnable);

	void clearHomeCount();
	int toposZero(int ioffsetNext=0, int ioffsetZ=0);
	int toposZero_home(int ioffsetNext=0, int ioffsetZ=0);
	int toposCamera(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int toposBicode(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int toposBicodeabs(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int toposBicode_After(int ioffsetZ);
	int toposLaser_Pre(int ioffsetMain, int ioffsetNext);
	int toposLaser_Prealfa(int ioffsetMain, int ioffsetNext);
	int toposLaser(int ioffsetMain, int ioffsetNext, int ioffsetCameraZ);
	int toposLaseralfa(int ioffsetMain, int ioffsetNext, double dflringangle, bool brate);
	int toposFA_Pre(int ioffsetMain, int ioffsetNext, int iCameraoffsetMain, int iCameraoffsetNext, double dflringangle, bool brate);

	int bv_rotateAnlge(double dflAngle);

	int toposFAback(int ioffsetMain);
	int toposFA(int ioffsetMain, int ioffsetNext, int ioffsetZ, int iCameraoffsetMain, int iCameraoffsetNext, int iCameraoffsetZ, double dflringangle, double dfllaser, double dflStressHeight);
	int toposWhite(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int toposWhiteDirect(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int setLocalSpeed(unsigned char ucaxis, double dflCoef);
	int toposStressLaser();
	int toposStressFA();
	int toposLaser_back(int ioffsetMain, int ioffsetNext, int ioffsetZ);
	int toposPlasticineFA_Vision(int iFAoffsetZ, int iCameraoffsetZ, double dfllaser, double dflStressHeight, double dflLensLaser);
	int toposPlasticineLaser(int iCameraoffsetZ);
	int toposDispenser(int ioffsetZ);
	int toposDispenser_Pre(int ioffsetMain, int ioffsetNext, int iCameraoffsetMain, int iCameraoffsetNext);
	bool isPositveU();
	bool isStation1();
	void setHardwareInfo(	double dfllenspitch2, double dfllensIncludedAngle2, double dflringIncludedAngle2);

public:
	int camera_absmain;
	int camera_absnext;
	int camera_absz;
	int camera_abszmax;

	int laser_absmain;
	int laser_absnext;

	int white_absmain;
	int white_absnext;
	int white_absz;

	int stress_lasermain;
	int stress_lasernext;

	int stress_fa_main;
	int stress_fa_next;

	int plasticine_vision_main;
	int plasticine_vision_next;

	int plasticine_laser_main;
	int plasticine_laser_next;

	int plasticine_fa_main;
	int plasticine_fa_next;

	double plasticine_machine_main;
	double plasticine_machine_next;

	double dflinitangle_u;
	bool bstation1;

	double dfllenspitch;;
	double dfllensIncludedAngle;
	double dflringIncludedAngle;

	char strSMCIPV4[20];
	char strVisionIPV4[20];
	unsigned char ucposition;
private:
	void* smchandle;
	int imainabsoffset;
	int inextabsoffset;
	wchar_t strHisAPP[20];
	unsigned int uiHomeCountMain;
	unsigned int uiHomeCountNext;
	unsigned int uiHomeCountZ;
	unsigned int uiHomeCountU;
	unsigned int uiMoveTimeOut;

	int iabsPlusMain;
	int iabsPlusNext;
	int iabsPlusZ;
	int iabsPlusU;

	unsigned char status_main; //0：正 1：负
	unsigned char status_next;
	unsigned char status_z;
	unsigned char status_u;

	int imackup_main;
	int imackup_next;
	int imackup_z;
	int imackup_u;

	unsigned int uiInitSpeedNext;
	unsigned int uiInitSpeedMain;
	unsigned int uiInitSpeedZ;
	unsigned int uiInitSpeedU;
	double dflInitSpeedZU;

	unsigned int uiNowSpeedNext;
	unsigned int uiNowSpeedMain;
	unsigned int uiNowSpeedZ;
	unsigned int uiNowSpeedU;
	double dflNowSpeedZU;
	double dflUnitU;

	//unsigned char ucposition;
};

#endif