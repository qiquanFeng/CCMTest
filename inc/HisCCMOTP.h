// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HISCCMOTP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HISCCMOTP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HISCCMOTP_EXPORTS
#define HISCCMOTP_API extern "C" __declspec(dllexport)
#else
#define HISCCMOTP_API extern "C" __declspec(dllimport)
#endif

#ifndef HISCCMOTP_H
#define HISCCMOTP_H

#define HISCCMOTP_QUALCOMM_PDAF_API

#include "inc/PDAFCalibrationTools_Rev.h"
#include "inc/HisGlobalDefine.h"
#include <string>
#include <vector>

HISCCMOTP_API void __cdecl getOTPList(std::vector<std::string>& listOTP);
HISCCMOTP_API int __cdecl writeotp(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMOTP_Config* pstconfig = 0, hardwarereadiic funreadiic = 0, hardwarewriteiic funwriteiic = 0, hardwaresetiicspeed funiicspeed = 0, \
	hardwaresetvolt funsetvolt = 0, hardwaregetvolt fungetvolt = 0, hardwaresetvfuse funsetvfuse = 0, hardwaregetvfuse fungetvfuse = 0, hardwaregetframe fungetframe = 0, \
	hardwarebatchwriteiic funbatchwriteiic = 0, hardwarebatchreadiic funbatchreadiic = 0, hardwaresetgpio funsetgpio = 0, hardwaregetgpio fungetgpio = 0, \
	hardwarepullreset funreset = 0, hardwarepullpwnd funpwnd = 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit = 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit = 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl checkotp(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMOTP_Config* pstconfig= 0, hardwarereadiic funreadiic = 0, hardwarewriteiic funwriteiic = 0, hardwaresetiicspeed funiicspeed = 0, \
	hardwaresetvolt funsetvolt = 0, hardwaregetvolt fungetvolt = 0, hardwaresetvfuse funsetvfuse = 0, hardwaregetvfuse fungetvfuse = 0, hardwaregetframe fungetframe = 0, \
	hardwarebatchwriteiic funbatchwriteiic = 0, hardwarebatchreadiic funbatchreadiic = 0, hardwaresetgpio funsetgpio = 0, hardwaregetgpio fungetgpio = 0, \
	hardwarepullreset funreset = 0, hardwarepullpwnd funpwnd = 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit = 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit = 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API int __cdecl getdefaultconfig(_HisCCMOTP_Config* pstconfig);

HISCCMOTP_API void __cdecl getAFList(std::vector<std::string>& listAF);
HISCCMOTP_API int __cdecl writeafmotor(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, \
	hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl checkafmotor(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, \
	hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API void __cdecl getApplyList(std::vector<std::string>& listApply);
HISCCMOTP_API int __cdecl applyOTPforPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMOTP_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API void __cdecl getMTKPDAFList(std::vector<std::string>& listPDAF);
HISCCMOTP_API int __cdecl writeMTKPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMMTKPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl checkMTKPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMMTKPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API void __cdecl getSONYPDAFList(std::vector<std::string>& listPDAF);
HISCCMOTP_API int __cdecl writeSONYPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMSONYPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl checkSONYPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMSONYPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API void __cdecl getQualcommPDAFList(std::vector<std::string>& listPDAF);
HISCCMOTP_API int __cdecl writeQualcommPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisQualcommPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back fuclogpushback= 0, hardwarepagewriteiic fucpagewriteiic= 0, hardwarepagereadiic fucpagereadiic= 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl checkQualcommPDAF(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisQualcommPDAFBurn_Config* pstconfig= 0, hardwarereadiic funreadiic= 0, hardwarewriteiic funwriteiic= 0, hardwaresetiicspeed funiicspeed= 0, \
	hardwaresetvolt funsetvolt= 0, hardwaregetvolt fungetvolt= 0, hardwaresetvfuse funsetvfuse= 0, hardwaregetvfuse fungetvfuse= 0, hardwaregetframe fungetframe= 0, \
	hardwarebatchwriteiic funbatchwriteiic= 0, hardwarebatchreadiic funbatchreadiic= 0, hardwaresetgpio funsetgpio= 0, hardwaregetgpio fungetgpio= 0, \
	hardwarepullreset funreset= 0, hardwarepullpwnd funpwnd= 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit= 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit= 0, \
	hisfx3logpush_back fuclogpushback= 0, hardwarepagewriteiic fucpagewriteiic= 0, hardwarepagereadiic fucpagereadiic= 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API void __cdecl getDualCameraBurnList(std::vector<std::string>& listOTP);
HISCCMOTP_API int __cdecl writedualcameratestdata(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMDualCameraBurn_Config* pstconfig = 0, hardwarereadiic funreadiic = 0, hardwarewriteiic funwriteiic = 0, hardwaresetiicspeed funiicspeed = 0, \
	hardwaresetvolt funsetvolt = 0, hardwaregetvolt fungetvolt = 0, hardwaresetvfuse funsetvfuse = 0, hardwaregetvfuse fungetvfuse = 0, hardwaregetframe fungetframe = 0, \
	hardwarebatchwriteiic funbatchwriteiic = 0, hardwarebatchreadiic funbatchreadiic = 0, hardwaresetgpio funsetgpio = 0, hardwaregetgpio fungetgpio = 0, \
	hardwarepullreset funreset = 0, hardwarepullpwnd funpwnd = 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit = 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit = 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);
HISCCMOTP_API int __cdecl cehckdualcameratestdata(std::vector<std::wstring>& vectorHisCCMOTPInfoW, _HisCCMDualCameraBurn_Config* pstconfig= 0, hardwarereadiic funreadiic = 0, hardwarewriteiic funwriteiic = 0, hardwaresetiicspeed funiicspeed = 0, \
	hardwaresetvolt funsetvolt = 0, hardwaregetvolt fungetvolt = 0, hardwaresetvfuse funsetvfuse = 0, hardwaregetvfuse fungetvfuse = 0, hardwaregetframe fungetframe = 0, \
	hardwarebatchwriteiic funbatchwriteiic = 0, hardwarebatchreadiic funbatchreadiic = 0, hardwaresetgpio funsetgpio = 0, hardwaregetgpio fungetgpio = 0, \
	hardwarepullreset funreset = 0, hardwarepullpwnd funpwnd = 0, hardwarebatchreadiicnolimit funbatchreadiicnolimit = 0, hardwarebatchwriteiicnolimit funbatchwriteiicnolimit = 0, \
	hisfx3logpush_back funlogpushback = 0, hardwarepagewriteiic fucpagewriteiic = 0, hardwarepagereadiic fucpagereadiic = 0, \
	hardwarepagewritespi funpagewritespi =0, hardwarepagereadspi funpagereadspi =0);

HISCCMOTP_API unsigned int __cdecl getRolongoOTPAPIVersion();

// HISCCMOTP_API void setFunctionPointer(hisfx3logpush_back inlogpushback, hardwarepagewriteiic inpagewriteiic, hardwarepagereadiic inpagereadiic);
//  
// HISCCMOTP_API void HisCCM_OTPDLL_SetExitFlag(bool bexit);

// #ifdef HISCCMOTP_EXPORTS
// __declspec(dllexport) std::vector<std::wstring> vectorHisCCMOTPInfoW;
// #else
// __declspec(dllimport) std::vector<std::wstring> vectorHisCCMOTPInfoW;
// #endif

// HISCCMOTP_API std::vector<std::wstring> vectorHisCCMOTPInfoW;

// This class is exported from the HisCCMOTP.dll
// class HISCCMOTP_API CHisCCMOTP {
// public:
// 	CHisCCMOTP(void);
// 	~CHisCCMOTP(void);
// 
// 	
// 
// private:
// 
// 	hisfx3logpush_back funlogpushback;
// 	hardwarepagewriteiic fucpagewriteiic;
// 	hardwarepagereadiic fucpagereadiic;
// };
  


#endif
