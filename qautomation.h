#ifndef HISQAUTOMATION_H
#define HISQAUTOMATION_H


#include "globaldefine.h"

namespace RAUTOMATION{
	__inline int AutoFARingRotate(double dflAngle, bool bMakeUp, void* calssControl) //CW：负数 CCW：正数
	{

#if (defined USE_EQUIPMENT_AFM_JSL_V1)
		return _His_P8102_Rotate(dflAngle);

#endif
		return 0;
	}

	__inline int AutoFAAxisZMoveR(double dflDistance, void* calssControl) //正：靠近调焦环  负：远离调焦环
	{ 

#if (defined USE_EQUIPMENT_AFM_JSL_V1)
		return _His_P8102_Move_R(dflDistance *RJ_AFAM_ZAXIS_PLUSPer1mm);

#endif

		return 0;
	}

	

}

#endif