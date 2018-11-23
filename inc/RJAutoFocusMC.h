// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 RJAUTOFOCUSMC_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// RJAUTOFOCUSMC_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

#ifndef HISRJAUTOFOCUSMC_H
#define HISRJAUTOFOCUSMC_H

#ifdef RJAUTOFOCUSMC_EXPORTS
#define RJAUTOFOCUSMC_API __declspec(dllexport)
#else
#define RJAUTOFOCUSMC_API __declspec(dllimport)
#endif

#include "inc/HisGlobalDefine.h"

#define RJ_AFAM_ZAXIS_PLUSPer1mm	80

// 此类是从 RJAutoFocusMC.dll 导出的
// class RJAUTOFOCUSMC_API CRJAutoFocusMC {
// public:
// 	CRJAutoFocusMC(void);
// 	// TODO: 在此添加您的方法。
// };

extern RJAUTOFOCUSMC_API int nRJAutoFocusMC;

RJAUTOFOCUSMC_API int _His_P8102_Init(void);
RJAUTOFOCUSMC_API bool _His_P8102_IsConnect(void);
RJAUTOFOCUSMC_API void _His_P8102_Close(void);
RJAUTOFOCUSMC_API int _His_P8102_Home(void);
RJAUTOFOCUSMC_API int _His_P8102_Move_A(__int32 iPlus);
RJAUTOFOCUSMC_API wchar_t* _His_P8102_GetLastError();
RJAUTOFOCUSMC_API int _His_P8102_Move_R(__int32 iPlus);
RJAUTOFOCUSMC_API int _His_P8102_Rotate(double dflAngle, double dflSpeedRatio = 1.0); //CCW-正  CW-负
RJAUTOFOCUSMC_API int _His_P8102_ToAF();
RJAUTOFOCUSMC_API int _His_P8102_LCD_Red(bool bON);
RJAUTOFOCUSMC_API int _His_P8102_LCD_Green(bool bON);
RJAUTOFOCUSMC_API int _His_P8102_ToWhite();
RJAUTOFOCUSMC_API int _His_P8102_ToBlack();
RJAUTOFOCUSMC_API int _His_P8102_ToColor();
RJAUTOFOCUSMC_API int _His_P8102_ToOriginal();

RJAUTOFOCUSMC_API int _His_P8102_MoveLens(bool bON);
RJAUTOFOCUSMC_API int _His_P8102_MoveBlack(bool bON);
RJAUTOFOCUSMC_API int _His_P8102_MoveWhite(bool bON);
RJAUTOFOCUSMC_API int _His_P8102_MoveColor(bool bON);

#endif