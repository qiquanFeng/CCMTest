//
#pragma once

#include "inc/versionswitch.h"

#if (defined USE_EQUIPMENT_YIOU_FUNTION_V2)
#define VER_Major    4
#elif (defined USE_EQUIPMENT_GB_AFBURN)
#define VER_Major    5
#elif (defined USE_EQUIPMENT_KANGTAIDA_FUNTION)
#define VER_Major    6
#elif (defined USE_EQUIPMENT_YIOU_FUNTION_V3)
#define VER_Major    7
#elif (defined USE_EQUIPMENT_GB_PDAF)
#define VER_Major    8
#elif (defined USE_EQUIPMENT_AFM_JSL_V1)
#define VER_Major    9
#elif (defined USE_EQUIPMENT_YIOU_AFA_V1)
#define VER_Major    10
#elif (defined USE_EQUIPMENT_YIOU_AFABV_V1)
#define VER_Major    11
#elif (defined USE_EQUIPMENT_JSL_FUNCTION_V1)
#define VER_Major    12
#elif (defined USE_EQUIPMENT_SUNRISE_AFA_V1)
#define VER_Major    100
#elif (defined USE_EQUIPMENT_AZWARE_AFA_V1)
#define VER_Major    101
#elif (defined USE_EQUIPMENT_JSL_RRT_V1)
#define VER_Major    102
#else
#define VER_Major    1
#endif

#if (defined _HisFX3_Platform_Jigboard)
#define VER_Minor    30
#elif (defined _HisFX3_Platform_LVDS_R1)
#define VER_Minor    20
#elif (defined _HisFX3_Platform_ANALOG_R1)
#define VER_Minor    40
#elif (defined _HisFX3_Platform_MIPI_R2R3)
#define VER_Minor    10
#elif (defined _HisFX3_Platform_MIPI_R4)
#define VER_Minor    11
#elif (defined _HisFX3_Platform_UVC)
#define VER_Minor    50
#elif (defined _HisFX3_Platform_MIPI_R1)
#define VER_Minor    1
#else
#define VER_Minor    0
#endif

#define VER_Release    86 

#define VER_Build			11

#define VER_Version    MAKELONG(MAKEWORD(VER_Major, VER_Minor), VER_Release)

#define _Stringizing(v)    #v

#define _VerJoin(a, b, c, d)  _Stringizing(a.b.c.d)

#define STR_Version    TEXT(_VerJoin(VER_Major, VER_Minor, VER_Release, VER_Build))
