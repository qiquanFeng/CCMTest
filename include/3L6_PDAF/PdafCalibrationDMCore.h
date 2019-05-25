/*======================================================================
Copyright (c) 2018 Samsung Electronics Co., Ltd.
All Rights Reserved.
Confidential and Proprietary - Samsung Electronics Co., Ltd.
=======================================================================*/
#pragma once

#ifdef __cplusplus
extern "C"{
#endif

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int    uint32;
typedef short           sint16;
typedef long long int   sint64;

#define RAW_NUM 10

#define RAW_WIDTH 4160
#define RAW_HEIGHT 3120

#define AF_SIZE_WIDTH    260
#define AF_SIZE_HEIGHT    192

#define CAL_WIDTH 8
#define CAL_HEIGHT 8

#define GAINMAP_WIDTH   13
#define GAINMAP_HEIGHT   12
#define GAINMAP_UNIT_WIDTH   20
#define GAINMAP_UNIT_HEIGHT   16
#define GAIN_PROF_NUM 52

#define GAIN_PEDESTAL 64 // config->i_ob_value = 64 ¿Í Sync

// Cal. Return Code
#define CAL_SUCCESS 0
#define HIGH_CODE_ERR 1
#define LOW_CODE_ERR 2
#define SAT_ERR 3
#define DISP_OFFSET_ERR 4
#define DISP_LINEARITY_ERR 5
#define LENS_POS_ERR 6

// Threshold for Cal. Verification
#define DARK_AREA_TH 330
#define HIGH_CODE_TH 920
#define LOW_CODE_TH 380
#define SAT_CODE_TH 945
#define SAT_CNT_TH 5
#define DISP_LINEARITY_ERR_TH 2.0
#define LENS_POS_ERR_TH 3
#define DISP_OFFSET_ERR_TH \
{ 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6 \
, 0.6, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.6 \
, 0.6, 0.5, 0.3, 0.3, 0.3, 0.3, 0.5, 0.6 \
, 0.6, 0.5, 0.3, 0.3, 0.3, 0.3, 0.5, 0.6 \
, 0.6, 0.5, 0.3, 0.3, 0.3, 0.3, 0.5, 0.6 \
, 0.6, 0.5, 0.3, 0.3, 0.3, 0.3, 0.5, 0.6 \
, 0.6, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.6 \
, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6 }

typedef struct {
	int focusValue[RAW_NUM][CAL_HEIGHT*CAL_WIDTH];
	double disparity0[RAW_NUM][CAL_HEIGHT*CAL_WIDTH];
	double disparity1[RAW_NUM][CAL_HEIGHT*CAL_WIDTH];
	int lensPosition[RAW_NUM];
	uint16 cafInfocus[CAL_HEIGHT*CAL_WIDTH];
	double dccCoefA_BAND0[CAL_HEIGHT*CAL_WIDTH];
	double dccCoefB_BAND0[CAL_HEIGHT*CAL_WIDTH];
	double dccCoefA_BAND1[CAL_HEIGHT*CAL_WIDTH];
	double dccCoefB_BAND1[CAL_HEIGHT*CAL_WIDTH];
	uint16 GainL[GAINMAP_HEIGHT][GAINMAP_WIDTH];
	uint16 GainR[GAINMAP_HEIGHT][GAINMAP_WIDTH];
	uint16 GainL_Prof[GAIN_PROF_NUM];
	uint16 GainR_Prof[GAIN_PROF_NUM];
	uint16 GainL_Full[AF_SIZE_HEIGHT][AF_SIZE_WIDTH];
	uint16 GainR_Full[AF_SIZE_HEIGHT][AF_SIZE_WIDTH];
	int ReturnCode;
}CalOutput;

__declspec(dllexport) int pdaf_dm_cal_main(char* raw_name, int raw_idx, int lens_position);
__declspec(dllexport) void print_dm_error_code(int returnCode, int raw_idx);
void lsi_calculate_caf_infocus(CalOutput* output);
void lsi_calculate_dcc_coef(CalOutput* output);
void lsi_verify_lens_pos(CalOutput* output);
int lsi_get_max_position(CalOutput* output, int roi_num, int raw_num);
double lsi_quadric_interpolation_caf(CalOutput* output, int nMaxPos, int roiPos, int rawNum);
void lsi_print_cal_data(char* raw_name, CalOutput* output);
void lsi_make_cal_binary(char* raw_name, CalOutput* output);
void lsi_load_gm_data(char* data_path, CalOutput* output);

#ifdef __cplusplus
}
#endif


