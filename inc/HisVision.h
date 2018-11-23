// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HISVISION_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HISVISION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifndef HISVISION_H
#define HISVISION_H

#include <vector>
#include "HisGlobalDefine.h"

using namespace std;
#ifdef HISVISION_EXPORTS
#define HISVISION_API __declspec(dllexport)
#else
#define HISVISION_API __declspec(dllimport)
#endif


enum _HisCamera_ConfigType{
	_HisCamera_ConfigType_AOI						=	0x1,    //staoi
	_HisCamera_ConfigType_EsposureTime		=	0x2,    //Pylon: ui64data[0] us  IC:dfldata[0]
	_HisCamera_ConfigType_GrabTimeOut		=	0x3,     //uidata[0] ms
	_HisCamera_ConfigType_MaxBuffers			=	0x4,    //ui8data[0]
	_HisCamera_ConfigType_PixelFormat			=	0x5,     //uidata[0]  _HisVision_Frame_Format
	_HisCamera_ConfigType_Gain						=	0x6     //dfldata[0]
};

struct _HisCamera_Config{
	_HisCamera_ConfigType uitype;
	union HISCAMPRADATA{
		RECT staoi;
		unsigned int uidata[4];
		int idata[4];
		unsigned __int64 ui64data[2];
		__int64 i64data[2];
		unsigned __int16 ui16data[8];
		__int16 i16data[8];
		unsigned __int8 ui8data[16];
		__int8 i8data[16];
		char strchar[16];
		wchar_t wstrchar[8];
		float fldata[4];
		double dfldata[2];
	}stvalue;

	_HisCamera_Config()
	{
		uitype	=	_HisCamera_ConfigType_EsposureTime;
		stvalue.ui64data[0]	=	stvalue.ui64data[1]	=	0;
	}
};

enum _HisCamera_Library{
	_HisCamera_Library_Pylon			=	0x0,
	_HisCamera_Library_Directshow	=	0x1,
	_HisCamera_Library_Opencv		=	0x2,
	_HisCamera_Library_IC					=	0x3,
	_HisCamera_Library_None			=	0xff
};
 
enum _HisCamera_Link_Protocal{
	_HisCamera_Link_GigE				=	0x0,
	_HisCamera_Link_CameraLink	=	0x1,
	_HisCamera_Link_UVC20			=	0x2,
	_HisCamera_Link_None				=	0xff
};

enum _HisCamera_Descripte_Type{
	_HisCamera_Descripte_IP4		=	0x0,
	_HisCamera_Descripte_IP6		=	0x1,
	_HisCamera_Descripte_ID			=	0x2,
	_HisCamera_Descripte_None	=	0xff
};

struct _HisCamera_Camera_Descripte{
	_HisCamera_Descripte_Type uctype;
	union HISCAMDESTYPE{
		char strFreidlyName[72];
		char strIPAddr[72];
		unsigned int uiID[18];
	}stvalue;
};

// This class is exported from the HisVision.dll
class HISVISION_API CHisCamera {
public:
	CHisCamera();
	~CHisCamera(void);

	void setCameraLibrary(_HisCamera_Library cameraLib, _HisCamera_Link_Protocal linktype);

	int HisCamEnumDevice(vector<_HisCamera_Camera_Descripte>& vecCamera);
	int HisCamOpen(_HisCamera_Camera_Descripte& stCamera);
	int HisCamClose();
	bool HisCameraIsOpen();
	int HisCamGrabIncoming(_HisCamera_Frame_Descripte& stFrameGrab);
	int HisSetConfig(_HisCamera_Config& stconfig);
	int HisGetConfig(_HisCamera_Config& stconfig);

private:
	int basler_gige_Open(_HisCamera_Camera_Descripte& stCamera);
	int ic_gige_Open(_HisCamera_Camera_Descripte& stCamera);
	int basler_gige_Close();
	int ic_gige_Close();
	bool basler_gige_IsOpen();
	bool ic_gige_IsOpen();
	int ic_gige_GrabIncoming(_HisCamera_Frame_Descripte& stFrameGrab);
	int basler_gige_GrabIncoming(_HisCamera_Frame_Descripte& stFrameGrab);
	int basler_gige_SetValue(_HisCamera_Config& stconfig);
	int ic_gige_SetValue(_HisCamera_Config& stconfig);
	int basler_gige_GetValue(_HisCamera_Config& stconfig);
	int ic_gige_GetValue(_HisCamera_Config& stconfig);

	int switchBaslerErrorCode();

private:
	void* pstdevice;
	unsigned char* pucVisionBuffer;
	_HisCamera_Library				libraryCamera;
	_HisCamera_Link_Protocal	linkProtocol;
	unsigned int uiFrameTimeOut;
	bool bfirst;
};

#endif
