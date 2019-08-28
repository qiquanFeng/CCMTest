//
#ifndef VERSIONSWITCH_H
#define VERSIONSWITCH_H

#include "inc/HisGlobalDefine.h"
#include "inc/HisFX3Platform.h"
#define USE_EQUIPMENT_GB_AFBURN //AFC
//#define USE_EQUIPMENT_AFM_JSL_V2 //自动调焦V2
//#define USE_EQUIPMENT_GB_PDAF //2017/12/27
//#define USE_EQUIPMENT_AFM_JSL_V1 //自动调焦
//#define USE_AFC_Fitting
//#define	USE_EQUIPMENT_JSL_FUNCTION_V1
#define  USE_MANUAL_LENS_BIN // A B规格
//#define	USE_EQUIPMENT_JSL_RRT_V1
//#define USE_AFC_Fitting

#define HisPlatform_BatchI2C



//#define EXELOG_USE_SUNNEX
#ifdef USE_EQUIPMENT_GB_PDAF
#define PDAF_LICENSE_ONLY_AUTHORIZE
#endif

#endif

