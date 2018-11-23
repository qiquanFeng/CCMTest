#pragma once
#ifndef MOTION_API
#define MOTION_API _declspec(dllimport)
#endif

#define SUCCESS             0
#define OPEN_DEVICE_FAIL   -1   //打开运动控制卡失败
#define OPEN_AXIS_FAIL     -2   //打开轴失败
#define ADD_GROUP_FAIL     -3   //群组失败


//************************************************************************
//函数名： init
//函数功能： 打开运动控制卡并获取轴句柄进行群组
//参数：   无
//返回值：0 成功 非0 失败   
//***********************************************************************
MOTION_API int init(void);    //初始化

//************************************************************************
//函数名： MoveFocusingRing
//函数功能： 转动调焦环（联动）
//参数：   1  RelAngle     --- 转动角度  正顺时针  负逆时针
//		   2  height	   --- 升降高度  正下降  负上升
//返回值：TRUE 成功   FALSE 失败
//***********************************************************************
MOTION_API BOOL MoveFocusingRing(double RelAngle, double height);    

//************************************************************************
//函数名： MoveZAxis
//函数功能： 调焦Z轴升降
//参数：   1   ReaPos   --- 升降高度  正下降  负上升
//返回值：TRUE 成功   FALSE 失败
MOTION_API BOOL MoveZAxis(double RelPos);    //升降高度  单位mm  正下降  负上升

//************************************************************************
//函数名： isFocusingRingMove
//函数功能： 获取调焦环是否运动中
//参数：  1  sts 	--- 运动状态    TRUE运动中   FALSE停止
//返回值：TRUE 成功   FALSE 失败
MOTION_API BOOL isFocusingRingMove(BOOL &sts);

//************************************************************************
//函数名： isZAxisMove
//函数功能： 获取调焦环Z轴是否运动中
//参数：  1  sts 	--- 运动状态    TRUE运动中   FALSE停止
//返回值：TRUE 成功   FALSE 失败
MOTION_API BOOL isZAxisMove(BOOL &sts);