// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� RJAUTOFOCUSMC_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// RJAUTOFOCUSMC_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

#ifndef HISRJAUTOFOCUSMC_H
#define HISRJAUTOFOCUSMC_H

#ifdef RJAUTOFOCUSMC_EXPORTS
#define RJAUTOFOCUSMC_API __declspec(dllexport)
#else
#define RJAUTOFOCUSMC_API __declspec(dllimport)
#endif

#include "inc/HisGlobalDefine.h"

#define RJ_AFAM_ZAXIS_PLUSPer1mm	80

// �����Ǵ� RJAutoFocusMC.dll ������
// class RJAUTOFOCUSMC_API CRJAutoFocusMC {
// public:
// 	CRJAutoFocusMC(void);
// 	// TODO: �ڴ�������ķ�����
// };

extern RJAUTOFOCUSMC_API int nRJAutoFocusMC;

RJAUTOFOCUSMC_API int _His_P8102_Init(void);
RJAUTOFOCUSMC_API bool _His_P8102_IsConnect(void);
RJAUTOFOCUSMC_API void _His_P8102_Close(void);
RJAUTOFOCUSMC_API int _His_P8102_Home(void);
RJAUTOFOCUSMC_API int _His_P8102_Move_A(__int32 iPlus);
RJAUTOFOCUSMC_API wchar_t* _His_P8102_GetLastError();
RJAUTOFOCUSMC_API int _His_P8102_Move_R(__int32 iPlus);
RJAUTOFOCUSMC_API int _His_P8102_Rotate(double dflAngle, double dflSpeedRatio = 1.0); //CCW-��  CW-��
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