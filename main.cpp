#include "QHMainWindow.h"
#include <QtGui/QApplication>
#include <QTranslator>
#include "globaldefine.h"
#include "qdockwidget.h"


CHisFX3Platform classPlatform;
_globalParameter hisglobalparameter;
_threadshareData threadshareDataC1(true);
_global_itemexec itemshareDataC1;
HisFX3Log classGlobalLogC1;
CHisFX3CCMAlg classAlgorithm;
std::vector<std::wstring> vectorHisCCMOTPInfoWC1;

HisFX3Log classGlobalLogC2;
std::vector<std::wstring> vectorHisCCMOTPInfoWC2;
_threadshareData threadshareDataC2(false);
_global_itemexec itemshareDataC2;

QHGerneralMotor classMotion;

int global_ioc_x=0;
int global_ioc_y=0;
int global_unit_rg=0;
int global_unit_bg=0;
int global_unit_g=0;
int global_burn_group=0;
char global_strSN[1024]={0};
char global_strProcess[1024]={0};
char global_strLotNumber[1024]={0};
char global_strJobNumber[1024]={0};
char global_strStaNumber[1024]={0};
char global_strLineNumber[1024]={0};

_HisCCMAlg_AFC_MTF_DataItem_EX stItemData_EX;

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
leisaiMotion globalLeisaiMotion("./leisai.ini",3,1,2,4,0);
#endif

int __stdcall HisFX3PageWriteSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize, bool bCSLow, bool bLowFirst)
{
	return classPlatform.HisFX3PageWriteSPI(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall HisFX3PageReadSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize, bool bCSLow, bool bLowFirst)
{
	return classPlatform.HisFX3PageReadSPI(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall HisFX3WriteSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool bCSLow, bool bLowFirst)
{
	return classPlatform.HisFX3WriteSPI(ucSlave, uiReg, ui64Data, usType, bCSLow, bLowFirst);
}

int __stdcall HisFX3ReadSPIC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType, bool bCSLow, bool bLowFirst)
{
	return classPlatform.HisFX3ReadSPI(ucSlave, uiReg, pui64Data, usType, bCSLow, bLowFirst);
}

int __stdcall WriteHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool back)
{
	return classPlatform.HisFX3WriteIIC(ucSlave, uiReg, ui64Data, usType, back);
}

int __stdcall WriteHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool back)
{
	return classPlatform.HisFX3WriteIIC_S2(ucSlave, uiReg, ui64Data, usType, back);
}

int __stdcall ReadHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType)
{
	return classPlatform.HisFX3ReadI2C(ucSlave, uiReg, pui64Data, usType);
}

int __stdcall ReadHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType)
{
	return classPlatform.HisFX3ReadI2C_S2(ucSlave, uiReg, pui64Data, usType);
}

int __stdcall BatchWriteHisFX3IICNoLimitC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay)
{
	return classPlatform.HisFX3BatchWriteIICNoLimit(uiCount, pucSlave, puiReg, puiData, pusType, usDelay);
}

int __stdcall BatchWriteHisFX3IICNoLimitC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay)
{
	return classPlatform.HisFX3BatchWriteIICNoLimit_S2(uiCount, pucSlave, puiReg, puiData, pusType, usDelay);
}

int __stdcall BatchReadHisFX3IICNoLimitC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay)
{
	return classPlatform.HisFX3BatchReadIICNoLimit(uiCount, pucSlave, puiReg, puiData, pusType, usDelay);
}

int __stdcall BatchReadHisFX3IICNoLimitC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short* pusType, unsigned short usDelay)
{
	return classPlatform.HisFX3BatchReadIICNoLimit_S2(uiCount, pucSlave, puiReg, puiData, pusType, usDelay);
}

void __stdcall setBulkSize(long size)// 128~1024    * 1024
{
	return classPlatform.setBulkTransformSize(size);
}

int __stdcall BatchWriteHisFX3IICC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay)
{
#ifdef HisPlatform_BatchI2C
	unsigned short *usTypearray=new unsigned short [uiCount];
	for(int i=0;i<uiCount;i++)
	{
		usTypearray[i]=usType;
	}
	//memset(usTypearray,usType,sizeof(unsigned short)*uiCount);
	 int iresult=classPlatform.HisFX3BatchWriteIICNoLimit(uiCount, pucSlave, puiReg, puiData, usTypearray, usDelay);
	delete []usTypearray;
	return iresult;
#else
	return HisFX3Error_Other;
#endif
}

int __stdcall BatchReadHisFX3IICC1(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay)
{
#ifdef HisPlatform_BatchI2C
	unsigned short *usTypearray=new unsigned short [uiCount];
	//memset(usTypearray,usType,sizeof(unsigned short)*uiCount);
	for(int i=0;i<uiCount;i++)
	{
		usTypearray[i]=usType;
	}
	 int iresult=classPlatform.HisFX3BatchReadIICNoLimit(uiCount, pucSlave, puiReg, puiData, usTypearray, usDelay);
	delete []usTypearray;
	return iresult;
#else
	return HisFX3Error_Other;
#endif
}

int __stdcall BatchWriteHisFX3IICC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay)
{
#ifdef HisPlatform_BatchI2C
	unsigned short *usTypearray=new unsigned short [uiCount];
	//memset(usTypearray,usType,sizeof(unsigned short)*uiCount);
	for(int i=0;i<uiCount;i++)
	{
		usTypearray[i]=usType;
	}
	 int iresult=classPlatform.HisFX3BatchWriteIICNoLimit_S2(uiCount, pucSlave, puiReg, puiData, usTypearray, usDelay);
	delete []usTypearray;
	return iresult;
#else
	return HisFX3Error_Other;
#endif
}

int __stdcall BatchReadHisFX3IICC2(unsigned int uiCount, unsigned char* pucSlave, unsigned int* puiReg, unsigned int* puiData, unsigned short usType, unsigned short usDelay)
{
#ifdef HisPlatform_BatchI2C
	unsigned short *usTypearray=new unsigned short [uiCount];
	//memset(usTypearray,usType,sizeof(unsigned short)*uiCount);
	for(int i=0;i<uiCount;i++)
	{
		usTypearray[i]=usType;
	}
	 int iresult=classPlatform.HisFX3BatchReadIICNoLimit_S2(uiCount, pucSlave, puiReg, puiData, usTypearray, usDelay);
	delete []usTypearray;
	return iresult;
#else
	return HisFX3Error_Other;
#endif
}

int __stdcall PageWriteHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize)
{
	return classPlatform.HisFX3PageWriteIIC(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall PageWriteHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize)
{
	return classPlatform.HisFX3PageWriteIIC_S2(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall PageReadHisFX3IICC1(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize)
{
	return classPlatform.HisFX3PageReadIIC(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall PageReadHisFX3IICC2(unsigned char ucSlave, unsigned int uiReg, unsigned int uiRegSize, unsigned char* pucData, unsigned int uiDataSize)
{
	return classPlatform.HisFX3PageReadIIC_S2(ucSlave, uiReg, uiRegSize, pucData, uiDataSize);
}

int __stdcall SetHisFX3IICSpeedC1(unsigned short us1kMultiple)
{
	return classPlatform.HisFX3SetIICSpeed(us1kMultiple);
}

int __stdcall GetHisFX3IICSpeedC1(unsigned short* pus1kMultiple)
{
	return classPlatform.HisFX3GetIICSpeed(pus1kMultiple);
}

int __stdcall SetHisFX3IICSpeedC2(unsigned short us1kMultiple)
{
	return classPlatform.HisFX3SetIICSpeed_S2(us1kMultiple);
}

int __stdcall GetHisFX3IICSpeedC2(unsigned short* pus1kMultiple)
{
	return classPlatform.HisFX3GetIICSpeed_S2(pus1kMultiple);
}

int __stdcall SetHisFX3SPISpeedC1(unsigned short us1kMultiple)
{
	return classPlatform.HisFX3SetSPISpeed(us1kMultiple);
}

int __stdcall GetHisFX3SPISpeedC1(unsigned short* pus1kMultiple)
{
	return classPlatform.HisFX3GetSPISpeed(pus1kMultiple);
}

int __stdcall SetHisFX3VoltageC1(float flDOVDD, float flAVDD, float flDVDD, float flAF, float flVFuse, float flPOW, float flIODD, unsigned short usSwitch, float flMultiple)
{
	return classPlatform.HisFX3SetVolt(flDOVDD, flAVDD, flDVDD, flAF, flVFuse, flPOW, flIODD, usSwitch, flMultiple);
}

int __stdcall SetHisFX3VoltageC2(float flDOVDD, float flAVDD, float flDVDD, float flAF, float flVFuse, float flPOW, float flIODD, unsigned short usSwitch, float flMultiple)
{
	return classPlatform.HisFX3SetVolt_S2(flDOVDD, flAVDD, flDVDD, flAF, flVFuse, flPOW, flIODD, usSwitch, flMultiple);
}

int __stdcall GetHisFX3VoltageC1(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW, float* pflIODD)
{
	return classPlatform.HisFX3GetVolt(pflDOVDD, pflAVDD, pflDVDD, pflAF, pflVFuse, pflPOW, pflIODD);
}

int __stdcall GetHisFX3VoltageC2(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW, float* pflIODD)
{
	return classPlatform.HisFX3GetVolt_S2(pflDOVDD, pflAVDD, pflDVDD, pflAF, pflVFuse, pflPOW, pflIODD);
}

int __stdcall MeasureHisFX3VoltageC1(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW)
{
	return classPlatform.HIsFX3ReadVoltageValue(pflDOVDD, pflAVDD, pflDVDD, pflAF, pflVFuse, pflPOW);
}

int __stdcall MeasureHisFX3VoltageC2(float* pflDOVDD, float* pflAVDD, float* pflDVDD, float* pflAF, float* pflVFuse, float* pflPOW)
{
	return classPlatform.HIsFX3ReadVoltageValue_S2(pflDOVDD, pflAVDD, pflDVDD, pflAF, pflVFuse, pflPOW);
}

int __stdcall SetHisFX3VFuseVolt(float flVFUSE)
{
	return 0;
// 	return classPlatform.HisFX3SetVFuseVolt(ucVFUSE);
}

int __stdcall GetHisFX3VFuseVolt(float* pflVFUSE)
{
	return 0;
// 	return classPlatform.HisFX3GetVFuseVolt(pucVFUSE);
}

int __stdcall PullHisFX3PWNDC1(bool bPullHigh)
{
	return classPlatform.HisFX3PullPWND(bPullHigh);
}

int __stdcall PullHisFX3PWNDC2(bool bPullHigh)
{
	return classPlatform.HisFX3PullPWND_S2(bPullHigh);
}

int __stdcall PullHisFX3RESETC1(bool bPullHigh)
{
	return classPlatform.HisFX3PullReset(bPullHigh);
}

int __stdcall PullHisFX3RESETC2(bool bPullHigh)
{
	return classPlatform.HisFX3PullReset_S2(bPullHigh);
}

int __stdcall SetHisFX3MCLKC1(float flMCLK)
{
	return classPlatform.HisFX3SetMCLK(flMCLK);
}

int __stdcall SetHisFX3MCLKC2(float flMCLK)
{
	return classPlatform.HisFX3SetMCLK_S2(flMCLK);
}

int __stdcall GetHisFX3MCLKC1(float* pflMCLK)
{
	return classPlatform.HisFX3GetMCLK(pflMCLK);
}

int __stdcall GetHisFX3MCLKC2(float* pflMCLK)
{
	return classPlatform.HisFX3GetMCLK_S2(pflMCLK);
}

int __stdcall SetHisFX3LaneC1(unsigned char ucLane)
{
	return classPlatform.HisFX3SetMIPILane(ucLane);
}

int __stdcall SetHisFX3LaneC2(unsigned char ucLane)
{
	return classPlatform.HisFX3SetMIPILane_S2(ucLane);
}

int __stdcall GetHisFX3LaneC1(unsigned char* pucLane)
{
	return classPlatform.HisFX3GetMIPILane(pucLane);
}

int __stdcall GetHisFX3LaneC2(unsigned char* pucLane)
{
	return classPlatform.HisFX3GetMIPILane_S2(pucLane);
}

int __stdcall SetHisFX3DVPHSVSC1(bool bDVP_VS_ActiveHigh, bool bDVP_HS_ActiveHigh)
{
	return classPlatform.HisFX3SetDVPHSVS(bDVP_VS_ActiveHigh, bDVP_HS_ActiveHigh);
}

int __stdcall GetHisFX3DVPHSVSC1(bool* pbDVP_VS_ActiveHigh, bool* pbDVP_HS_ActiveHigh)
{
	return classPlatform.HisFX3GetDVPHSVS(pbDVP_VS_ActiveHigh, pbDVP_HS_ActiveHigh);
}

int __stdcall SetHisFX3GPIO(unsigned char ucGPIO0, unsigned char ucGPIO1, unsigned char ucGPIO2, unsigned char ucGPIO3, unsigned int uiFlag)
{
	return 0;
}

int __stdcall GetHisFX3GPIO(unsigned char* pucGPIO0, unsigned char* pucGPIO1, unsigned char* pucGPIO2, unsigned char* pucGPIO3, unsigned int uiFlag)
{
	return 0;
}

int __stdcall GetHisFX3SlaveResponseC1(unsigned char ucSlave)
{
	return classPlatform.HisFX3SlaveResponds(ucSlave);
}

int __stdcall GetHisFX3SlaveResponseC2(unsigned char ucSlave)
{
	return classPlatform.HisFX3SlaveResponds_S2(ucSlave);
}

bool __stdcall IsHisFX3DataStreamingC1(unsigned int uiTimeOut)
{
	return classPlatform.isDataStreaming(uiTimeOut);
}

bool __stdcall IsHisFX3DataStreamingC2(unsigned int uiTimeOut)
{
	return classPlatform.isDataStreaming_S2(uiTimeOut);
}

unsigned __int64 __stdcall getSensorFrameIndexC1()
{
	return classPlatform.getSensorFrameIndex();
}

unsigned __int64 __stdcall getSensorFrameIndexC2()
{
	return classPlatform.getSensorFrameIndex_S2();
}

QString __stdcall GetHisFX3ErrorInfo(int errorcode)
{
	switch (errorcode){
	case HisFX3Error_Construct:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：构造CHisFX3Platform类失败");
		break;
	case HisFX3Error_CloseUSB3:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：关闭3.0平台失败");
		break;
	case HisFX3Error_Timeout:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：操作超时");
		break;
	case HisFX3Error_Parameter:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：传入参数不符合要求");
		break;
	case HisFX3Error_IsNotOpen:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：3.0设备没有开启，请先开启设备");
		break;
	case HisCCMError_NotPreivew:
	case HisFX3Error_IsNotPreview:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：还没有开始图像预览输出");
		break;
	case HisFX3Error_MallocBuffer:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：申请内存空间失败");
		break;
	case HisFX3Error_USBDataOut:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：3.0数据传输错误，建议重启平台");
		break;
	case HisFX3Error_Hardware:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：3.0平台硬件可能有问题");
		break;
	case HisFX3Error_NotSuperSpeed:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：3.0平台不是超级速度，检查驱动或者连接线或者主板");
		break;
	case HisFX3Error_CreateThread:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：创建线程失败，检查windows系统资源或设定");
		break;
	case HisFX3Error_License:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：License错误");
		break;
	case HisFX3Error_NoRespond:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：设备IIC没有响应");
		break;
	case HisFX3Error_WirteIIC:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：写入IIC失败");
		break;
	case HisFX3Error_Check:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：校验失败");
		break;
	case HisFX3Error_AlgData:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：导入算法的数据不符合要求");
		break;
	case HisFX3Error_CreateEvent:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：创建事件失败");
		break;
	case HisCCMError_NoFrame:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：没有帧输出");
		break;
	case HisCCMError_Result:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：结果超出规格");
		break;
	case HisCCMError_Database:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：sqlite数据库连接");
		break;
	case HisCCMError_opConflic:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：操作存在冲突");
		break;
	case HisCCMError_luxtooLow:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：画面亮度过低");
		break;
	case HisCCMError_luxtooHigh:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：画面亮度过高");
		break;
	case HisCCMError_readIIC:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：读取I2C");
		break;
	case HisCCMError_OpenFile:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：打开文件失败");
		break;
	case HisCCMError_FileAttribute:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：获取文件属性失败，或者属性不匹配");
		break;
	case HisCCMError_ReadFile:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：读取文件失败");
		break;
	case HisCCMError_WriteFile:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：写入文件失败");
		break;
	case HisMotionError_SocketInit:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：初始化socket失败");
		break;
	case HisMotionError_GetHostName:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：取得主机描述名称失败");
		break;
	case HisMotionError_GetIPAddr:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：取得IP地址失败");
		break;
	case HisMotionError_Disconnect:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：没有打开链接");
		break;
	case HisMotionError_MoveFail:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：运动失败");
		break;
	case HisMotionError_Home:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：回零校正失败");
		break;
	case HisMotionError_Config:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：外配ini文档错误");
		break;
	case HisMotionError_NoHome:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：没有回零校正");
		break;
	case HisMotionError_InitAbsPos:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：初始绝对位置");
		break;
	case HisMotionError_Busy:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：正忙");
		break;
	case HisMotionError_TooManyConnect:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：链接过多");
		break;
	case HisMotionError_OS:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：嵌入式系统错误");
		break;
	case HisMotionError_Firmware:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Firmware错误");
		break;
	case HisMotionError_NotSupport:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：操作不支持");
		break;
	case HisMotionError_FileNameTooLong:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：文件名过长");
		break;
	case HisMotionError_Transmit:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：传输失败");
		break;
	case HisVisionError_OpenFile:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：打开文件");
		break;
	case HisVisionError_ReadFile:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：读取文件");
		break;
	case HisVisionError_ReadSize:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：读取文件大小错误");
		break;
	case HisVisionError_FileType:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：文件类型不正确");
		break;
	case HisVisionError_Center:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：中心位置不匹配");
		break;
	case HisVisionError_Match:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：模板不匹配");
		break;
	case HisVisionError_InputImage:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：输入模板不正确");
		break;
	case HisVisionError_InputColorImage:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：输入彩色模板不正确");
		break;
	case HisRs232Error_Open:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：打开Rs232失败");
		break;
	case HisRs232Error_BasicSteup:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232基础设置失败");
		break;
	case HisRs232Error_SetEvent:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232设置事件失败");
		break;
	case HisRs232Error_SetTimeOut:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232设置Timeout 失败");
		break;
	case HisRs232Error_WaitEvent:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232等待事件失败");
		break;
	case HisRs232Error_Read:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232读取失败");
		break;
	case HisRs232Error_SetHandShake:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232设置握手协议失败");
		break;
	case HisRs232Error_Write:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232写入失败");
		break;
	case HisRs232Error_DataMatch:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：Rs232数据不匹配");
		break;
	case HisMainFrameError_GetFrame:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：获取图像帧失败");
		break;
	case HisCCMError_LoadDLL:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：加载DLL 文件");
		break;
	case HisCCMError_LoadDLLFuc:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：加载DLL 函数");
		break;
	case HisCCMError_OtpFucExec:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：执行OTP库函数");
		break;
	case HisCCMError_QualcommPDAFStep1:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：高通PDAF校正STEP1");
		break;
	case HisCCMError_QualcommPDAFStep2:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：高通PDAF校正STEP2");
		break;
	case HisCCMError_QualcommPDAFStep2Verify:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：高通PDAF校正STEP2 K 验证");
		break;
	case HisFX3Error_Other:
	default:
		return QTextCodec::codecForName( "GBK")->toUnicode("错误：其他(0x") % QString::number(errorcode, 16) % ")";
		break;
	}
}

_globalFunctionPointer globalFunPointerC1(true);
_globalFunctionPointer globalFunPointerC2(false);

void __stdcall HisFX3LogPush_backC1(unsigned int uiIndex, const char* pstrKey, const char* pstrValue)
{
	if(pstrKey && pstrValue){
		uiIndex	=	classGlobalLogC1.getmaxtypeindex(uiIndex);
		_HisLog_Item stLogItem;
		stLogItem.itemtype		=	uiIndex +1;
		stLogItem.itemkey		=	QString::fromAscii(pstrKey);
		stLogItem.itemvalue	=	QString::fromAscii(pstrValue);
		classGlobalLogC1.push_back(stLogItem);
	}
}

void __stdcall HisFX3LogPush_backC2(unsigned int uiIndex, const char* pstrKey, const char* pstrValue)
{
	if(pstrKey && pstrValue){
		uiIndex	=	classGlobalLogC2.getmaxtypeindex(uiIndex);
		_HisLog_Item stLogItem;
		stLogItem.itemtype		=	uiIndex +1;
		stLogItem.itemkey		=	QString::fromAscii(pstrKey);
		stLogItem.itemvalue	=	QString::fromAscii(pstrValue);
		classGlobalLogC2.push_back(stLogItem);
	}
}

// sensor I2C callback
int OV4Cell_ReadReg_CallbackC1(void *handle, int id, int addr)
{
	unsigned long long ui64Data = 0;
	classPlatform.HisFX3ReadI2C(id, addr, &ui64Data, 0x1608);
	return ui64Data;
}

int __stdcall GetFreshframeC1(unsigned char* pucdata, unsigned int uibuffersize, unsigned char ucframetype, bool binit)
{
	return threadshareDataC1.GetFreshframe(pucdata, uibuffersize, ucframetype, binit);
}

int __stdcall GetFreshframeC2(unsigned char* pucdata, unsigned int uibuffersize, unsigned char ucframetype, bool binit)
{
	return threadshareDataC2.GetFreshframe(pucdata, uibuffersize, ucframetype, binit);
}

unsigned int GetLanugage()
{
	unsigned int ucLanguage = 0;
	for(int w=0;	w<1;	++w)
	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplate");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			break;

		QSqlQuery query(templatedb);
		query.prepare("SELECT value FROM global WHERE classfy='global' AND item='translate' AND key='language'");
		query.exec();

		while (query.next()){
			ucLanguage	=	query.value(0).toUInt();
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplate");
	return ucLanguage;
}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	QString strText;
	QStringList listKeyValue;
	for(int x = 0;	x< argc; ++x)
	{
		strText	=	QString::fromAscii(argv[x]);
		if(strText.contains("PlatformType"))
		{
			listKeyValue	=	strText.split(":");
			classPlatform.setCurrentPlatformType((_HisFX3_Platform_Type)listKeyValue.at(1).toUInt());
		}
		else if(strText.contains("CommuTimeOut"))
		{
			listKeyValue	=	strText.split(":");
			hisglobalparameter.stOperatorMode.u16SlaveMasterTimeout = listKeyValue.at(1).toUInt() & 0xFFFF;
		}
		else if(strText.contains("GrabberKey"))
		{
			listKeyValue	=	strText.split(":");
			strText	=	listKeyValue.at(1);
			listKeyValue	=	strText.split(".");
			hisglobalparameter.uiGrabberSerial[0] = listKeyValue.at(0).toUInt();
			hisglobalparameter.uiGrabberSerial[1] = listKeyValue.at(1).toUInt();
			hisglobalparameter.uiGrabberSerial[2] = listKeyValue.at(2).toUInt();
			hisglobalparameter.uiGrabberSerial[3] = listKeyValue.at(3).toUInt();
		}
		else if(strText.contains("GrabberIndex"))
		{
			listKeyValue	=	strText.split(":");
			hisglobalparameter.ucGrabberIndex = listKeyValue.at(1).toUInt() & 0xFF;
			hisglobalparameter.stOperatorMode.ucMode				= 2;
			hisglobalparameter.stOperatorMode.bSlaveFromArgv	=	true;
		}
	}

	QTranslator translator;
	if(GetLanugage() == 0){
		translator.load("hisfx3ccmtest_zh.qm");
		a.installTranslator(&translator);
	}

	qRegisterMetaType<_shoutCutDetail>("_shoutCutDetail");

	QDesktopWidget *d=QApplication::desktop();
	int width=d->width();//屏幕的宽度
	int height=d->height(); //屏幕的高度

	QHMainWindow w;
	//w.resize(width/2-15,height/2);
	//w.move(width/2+5,0);
	//w.move(0,0);
	w.show();
	

	return a.exec();
}

