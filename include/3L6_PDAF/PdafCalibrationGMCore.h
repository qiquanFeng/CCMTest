/*======================================================================
Copyright (c) 2018 Samsung Electronics Co., Ltd.
All Rights Reserved.
Confidential and Proprietary - Samsung Electronics Co., Ltd.
=======================================================================*/
#pragma once

#ifdef __cplusplus
extern "C"{
#endif

typedef unsigned char uint8;
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

// Threshold for Cal. Verification
#define HIGH_CODE_TH 920
#define LOW_CODE_TH 380
#define SAT_CODE_TH 945
#define SAT_CNT_TH 5

	typedef struct {
		uint16 GainL[GAINMAP_HEIGHT][GAINMAP_WIDTH];
		uint16 GainR[GAINMAP_HEIGHT][GAINMAP_WIDTH];
		uint16 GainL_Prof[GAIN_PROF_NUM];
		uint16 GainR_Prof[GAIN_PROF_NUM];
		int ReturnCode;
	}GainMapOutput;

	__declspec(dllexport) int pdaf_gm_cal_main(char* raw_name, int raw_idx);
	__declspec(dllexport) void print_gm_error_code(int returnCode, int raw_idx);
	void lsi_make_gm_data(char* raw_name, GainMapOutput* output);

#ifdef __cplusplus
}
#endif


