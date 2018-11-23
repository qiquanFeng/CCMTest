#ifndef _PDAFCALIBRATIONTOOLS_REV_H_
#define _PDAFCALIBRATIONTOOLS_REV_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "HisGlobalDefine.h"

#define SS3M2 0
#define SONYIMX258 1
#define SONYIMX258_BinningPDVer 2
#define OVT13853 3

#define OTPFORMAT1D 0
#define OTPFORMAT2D 1
#define OTPFORMATUnited_1D 2
#define OTPFORMATUnited_2D 3

#define GAINMAP1DFORMAT 1
#define GAINMAP2DFORMAT 2

#define MAXLENGTH 256
#define MINIMUM_LUT_LENGTH 10
#define GRIDPIXELS 256  // 512
#define MAXWIDTH 32  // =8K/256
#define MAXHEIGHT 32

#define MAXLENGTH2D MAXWIDTH*MAXHEIGHT
#define LEFTPDAFPIXEL 1
#define RIGHTPDAFPIXEL 2

typedef struct PDAFPatternParam
{
	int x_step;
	int y_step;
	int GlobalShift_x;
	int GlobalShift_y;
	int ImageBits;
	int BlackLevel;
	int SensorGain;
	int DSRatio;
	bool PDAFonG;
	char PDAFPatternFilename[1024];
}PDAFPattern;

typedef struct GainMap1DDataStructtag
{
	int VersionNum;
	unsigned short DSRatio;
	unsigned short ActualLength;
	unsigned short DSLength;
	unsigned short Left_GainMap[MAXLENGTH];
	unsigned short Right_GainMap[MAXLENGTH]; 
}GainMap1DDataStruct;

typedef struct GainMap2DDataStructtag
{
	int VersionNum;
	unsigned short OffsetX;
	unsigned short OffsetY;
	unsigned short RatioX;
	unsigned short RatioY;
	unsigned short MapWidth;
	unsigned short MapHeight;
	unsigned short Left_GainMap[MAXLENGTH2D];
	unsigned short Right_GainMap[MAXLENGTH2D]; 
}GainMap2DDataStruct;

typedef struct GainMapStructtag
{
	void *GainMapData;
	int Flag_1D_2D;
}GainMapStruct;


typedef struct CalibrationKOutputputParamsStructtag
{
	bool MultipleRegions;
	int PDConversionCoef[9];
	float FirstImage_PDShiftValue[9]; 
	float SecondImage_PDShiftValue[9]; 
	int FirstImage_CLValue[9]; 
	int SecondImage_CLValue[9]; 
}CalibrationKOutputParams;

typedef struct GainMapVerifyStructtag
{
	uint16_t MinPixelAvg;
	uint16_t MaxPixelAvg;
	uint16_t MinPDAvg;
	uint16_t MaxPDAvg;
	uint16_t MinGain;
	uint16_t MaxGain;
	uint16_t MaxPixelThresh;
	uint16_t GainDiff;
}GainMapVerifyStruct;

typedef struct VerificationStructtag
{
	float Verification_Lens_Position;
	int PD_ConversionCoeff;
	float Distance50cmTrueFocusPosition;
	float ToleranceError;
}VerificationInputParams;

typedef struct VerificationOutputtag
{
	float EstimationDAC;
	float Err;
	float PDShiftValue;
	int ConfidenceValue;
}VerificationOutputParams;

//Qualcomm PDAF L4 Version
#define GAIN_MAP_MAX_SZ 256
#define DCC_MAP_MAX_SZ 144
#define MAX_PD_PIXELS_PER_BLOCK 128

#define GAIN_MAP_HEIGHT 13
#define GAIN_MAP_WIDTH 17
#define GAIN_MAP_Q_FMT 8

#define DCC_MAP_HEIGHT 6
#define DCC_MAP_WIDTH 8
#define DCC_MAP_Q_FMT 4

#define DCC_FIR {-1, -4, -6, -4, 0, 4, 6, 4, 1}
#define DCC_FIR_SZ 9

#define DCC_STACK_SZ 10
#define DCC_SEARCH_RANGE 48
#define DCC_FIT_EXCLUSION 1
#define DCC_MIN_PD_RANGE 1
#define DCC_MAP_OVERLAP 0.5

#define DPD_PIXEL_UNIT 2
#define DPD_MIN_SENSOR_GAIN 1.9
#define DPD_MAX_SENSOR_GAIN 3.1

#define LINECHART 0
#define DIAMONDCHART 1

#define NORMALIZE 0
#define WEIGHTED 1

#define DCC_LINEARITY_LEVEL_THRESHOLD 0.1
//////////////////////////////////////////////

//////////////////////////////////////////////
// DCC VALIDATION TOLERANCE 
#define DCC_VAL_TOL_SPARSE \
{ 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, \
	0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, \
	0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, \
	0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, \
	0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, \
	0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20, 0.20 }

#define DCC_VAL_TOL_2BY1 \
{ 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, \
	0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, \
	0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, \
	0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, \
	0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, \
	0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.15 }

#define DCC_VAL_TOL_DPD \
{	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, \
	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, \
	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, \
	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, \
	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, \
	0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10 }
//////////////////////////////////////////////

typedef struct _dll_config_t {
	int8_t cal_version;
	int8_t chart_type;
	int8_t verify_type;
	int8_t gain_map_height;
	int8_t gain_map_width;
	int8_t gain_map_q_fmt;
	int8_t dcc_map_height;
	int8_t dcc_map_width;
	int8_t dcc_map_q_fmt;
	float dcc_fir[31];
	int8_t dcc_fir_sz;
	int8_t dcc_stack_sz;
	int8_t dcc_search_range;
	int8_t dcc_fit_exclusion;
	int8_t dcc_min_pd_range;
	float  dcc_map_overlap;
	float  dcc_tolerance_table[48];
	float  dcc_linearity_level_theshold;
	int8_t dpd_pixel_unit;
	float  dpd_min_sensor_gain;
	float  dpd_max_sensor_gain;
} dll_config_t;


typedef enum _cfa_pattern_t {
	UNSPECIFIED=0,
	RGGB,
	BGGR,
	GRBG,
	GBRG
} cfa_t; 

typedef struct _sensor_config_t
{
	cfa_t    cfa;
	uint16_t image_width;
	uint16_t image_height;
	uint16_t black_lvl;
	uint16_t bit_depth;
	uint16_t pd_block_width;
	uint16_t pd_block_height;
	uint16_t pd_block_start_x;
	uint16_t pd_block_start_y;
	uint16_t pd_block_n_pd_pairs;
	uint16_t pd_block_l_x[MAX_PD_PIXELS_PER_BLOCK];
	uint16_t pd_block_l_y[MAX_PD_PIXELS_PER_BLOCK];
	uint16_t pd_block_r_x[MAX_PD_PIXELS_PER_BLOCK];
	uint16_t pd_block_r_y[MAX_PD_PIXELS_PER_BLOCK];
	uint16_t fv_measure_channel; //1:left-top, 2:right-top, 3:left_bottom, 4:right_bottom
} sensor_config_t;


typedef struct _gainmap_limits_t
{
	uint16_t gain_max_limit;
	uint16_t pd_min_limit;
	uint16_t pd_max_limit;
} gainmap_limits_t;

typedef struct _gainmap_t
{
	int8_t cal_version;
	uint16_t width;
	uint16_t height;
	uint16_t gm_l[GAIN_MAP_MAX_SZ];
	uint16_t gm_r[GAIN_MAP_MAX_SZ];
} gainmap_t;

typedef struct _dccmap_t
{
	int8_t cal_version;
	uint16_t q_format;
	uint16_t width;
	uint16_t height;
	int16_t dm[DCC_MAP_MAX_SZ];
} dccmap_t;

typedef struct _pdmap_t
{
	uint16_t width;
	uint16_t height;
	float pd[DCC_MAP_MAX_SZ];
} pdmap_t;


#define CAL_VERSION 4

typedef struct _pdaf_cal_v4_t 
{
	uint16_t cal_version;
	uint16_t gm_width;     // 17
	uint16_t gm_height;    // 13
	uint16_t gm_l[221];    // 13x17
	uint16_t gm_r[221];    // 13x17
	uint16_t dm_q_format;  
	uint16_t dm_width;     // 8
	uint16_t dm_height;    // 6
	uint16_t dm[48];       // 6x8
	uint8_t  checksum; 
} pdaf_cal_v4_t;

typedef pdaf_cal_v4_t pdaf_cal_t;

// end pdaf l4 version defination

struct _HisQualcommPDAFBurn_Config{
	unsigned char ucEESlave;
	unsigned char ucSensorSlave;
	bool bDebug;

	unsigned char ucTpye; //1: step1 2: step2 0xFF: All Data
	std::string strGainMapDataStruct;
	GainMap2DDataStruct GainMapData2D;
	GainMap1DDataStruct GainMapData1D;
	CalibrationKOutputParams CalibrationKOutputValues[4];
	_gainmap_t  GainMapDataLVer;
	_dccmap_t    DccMapDatalVer;

	unsigned int uiMachineID;
	unsigned int uiHardwareVersion;
	unsigned short usGainMapSize;
	_haob64 Reserve1;
	_haob64 Reserve2;
	_haob64 Reserve3;
	_haob64 Reserve4;
	_HisFX3Platform_FactoryCode uiOEMFactory;
	std::string strproject;
	std::string strsensor;
	std::string strDriverIC;
	std::string strFunctionChoose;
	std::string strSerialNumber;
	std::vector<_HisCCMOTP_ConfigPair> vectorPair;

	_HisQualcommPDAFBurn_Config()
	{
		uiMachineID	=	uiHardwareVersion	=	0;
		strGainMapDataStruct="2D";
		Reserve1.u64value =Reserve2.u64value =Reserve3.u64value= Reserve4.u64value =0;
	}
};




#endif

