/*======================================================================
    Copyright (c) 2018 Samsung Electronics Co., Ltd.
    All Rights Reserved.
    Confidential and Proprietary - Samsung Electronics Co., Ltd.
=======================================================================*/
#pragma once

#ifdef __cplusplus
extern "C"{
#endif

#ifndef _PDAF_LIB_ITF_H_
#define _PDAF_LIB_ITF_H_

#define WINDOW_NO 64
#define RAWS_NUM 2
#define BANDS_NUM 2

#define VRF_SUCCESS 0
#define VER_MIS_ERR 1
#define DEFOCUS_ERR 2

#define DEFOCUS_ERR_TH 30

/*defocus confidence*/
#define PDAF_LIB_E_OK                 (0)
#define PDAF_LIB_E_NG                 (-1)

typedef struct
{
    int                 RoiSx [WINDOW_NO];
    int                 RoiSy [WINDOW_NO];
    int                 RoiEx [WINDOW_NO];
    int                 RoiEy [WINDOW_NO];
} sPdafRoi_t;

typedef struct {
	int Defocus[RAWS_NUM][BANDS_NUM][WINDOW_NO];
	int lensPosition[RAWS_NUM];
	int ReturnCode;
}VrfOutput;

__declspec(dllexport) int pdaf_verify_main(char* raw_name, int raw_idx, int lens_position);
__declspec(dllexport) void print_error_code(int returnCode, int raw_idx);
void lsi_decide_vrf_result(VrfOutput* output);
void lsi_print_vrf_data(char* output_path, VrfOutput* output);

#endif  //_PDAF_LIB_ITF_H_

#ifdef __cplusplus
}
#endif