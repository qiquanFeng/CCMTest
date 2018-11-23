#pragma once

#include "stdafx.h"

enum AF_R_STATUS_TYPE
{
	AF_R_RUN					= 0,
	AF_R_SUCCESS				= 1,
	AF_R_OVER_RANGE				= 2,
	AF_R_IIC_WRITE_ERROR,
	AF_R_FRAME_DELAY_ERROR,
	AF_R_LOG_FAIL_RAW_BUF,
	AF_R_LOG_FAIL_RAW_OPTION,
	AF_R_LOG_FAIL_ROI,
	AF_R_LOG_FAIL_PARAMETER,
	AF_R_LOG_FAIL_PEDESTAL,
    AF_R_LOG_FILE,
    AF_R_SYSTEM_IMG_FAIL,
    AF_R_FAIL
};

enum AF_R_CIS_ORDER_TYPE
{
	R_FIRST,
	GR_FIRST,
	GB_FIRST,
	B_FIRST
};

enum AF_R_ACT_MODEL_TYPE
{
	AK7371,
	AK7345,
    DW9807
};

enum AF_RUN_MODE
{
    AF_RUN_INFINITY,
    AF_RUN_MACRO
};

typedef struct __AF_R_info_type
{
	unsigned int 		i_Width;
	unsigned int 		i_Height;
	AF_R_CIS_ORDER_TYPE i_Order;
	unsigned int 		i_Pedestal;
	unsigned int 		Roi_SX;
	unsigned int 		Roi_SY;
	unsigned int 		Roi_EX;
	unsigned int 		Roi_EY;
	AF_R_ACT_MODEL_TYPE Act_Model;
}AF_R_info_type;

extern __declspec(dllexport) AF_R_STATUS_TYPE AutoFocus_R
(
	unsigned short *AF_Raw,
	AF_R_info_type AF_R_info,
	bool           (*AF_IIC_Write)(unsigned short Addr, unsigned short Data),
	bool           (*AF_IIC_Read)(unsigned short Addr, unsigned short *Data),
	int            *Lens_Pos,
    int            af_init_start_pos,                                          // Initial position of lens
    bool           init_device,                                                // true : Initialize mode, false : Normal mode
    int            af_mode                                                     // 0: infinity, 1: macro
);

// * In infinity mode - initial position can be 0 ~ 512
//   In Macro mode    - initial position can be 768 ~ 1023