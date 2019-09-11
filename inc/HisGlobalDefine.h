//
#ifndef HISGLOBALDEFINE_H
#define HISGLOBALDEFINE_H


#include <string>
#include <vector>
#include <windows.h>

#pragma warning(disable:4251)

#define _HisBuffer_Aligned					16
#define _HisCacheLine_Aligned		64

#define HisReleaseMalloc(x)  {if(x!=NULL) {_aligned_free(x); x = NULL;}}
#define HisReleaseNewB(x)  {if(x!=NULL) {delete[] x; x = NULL;}}
#define HisReleaseNewO(x)  {if(x!=NULL) {delete x; x = NULL;}}
#define HisCloseHandle(x)  {if(x!=NULL) {CloseHandle(x); x = NULL;}}
#define HisAlignedMalloc(x) _aligned_malloc(x, _HisCacheLine_Aligned)



#if 1/**********  新SDK用 *****************/
#define _RMAX_BOXS 8
#define _RMAX_CHANNEL 8
#define _RMAX_STREAM_ROI_NUMS 17

#define _HisFX3V2_CURRENTCAL_COUNT	36
#define _HisFX3_OS_PinName_MaxByte	12

enum _HisFX3_Platform_Type
{
	_HisFX3_Platform_Type_UnKnowed		=	0x0,
	_HisFX3_Platform_Type_R2R3					=	0x2, /*! 此版SDK不支持*/
	_HisFX3_Platform_Type_R5						=	0x4, /*! 此版SDK暂不支持*/
	_HisFX3_Platform_Type_R3X					=	0x5,
	_HisFX3_Platform_Type_UVC					=	0x6, /*! 标准协议UVC 模组*/
	_HisFX3_Platform_Type_RTSPM				=	0x7, /*! RTSP网络相机*/
	_HisFX3_Platform_Type_R5X					=	0x8,
	_HisFX3_Platform_Type_HDMI					=	0x9,  /*! HDMI PCIE卡*/
	_HisFX3_Platform_Type_R6						=	0xA,  /*! C-PHY双摄 */
	_HisFX3_Platform_Type_R6_Sunny			 = 0xF,  /*! C-PHY双摄 Sunny版本*/
	_HisFX3_Platform_Type_R10_Sunny			= 0xB,		/*! 万兆*/
	_HisFX3_Platform_Type_R8						= 0xC,		/*! 万兆 */
	_HisFX3_Platform_Type_R2C					= 0xD,
	_HisFX3_Platform_Type_R5_Sunny			= 0xE,	/*! DPHY双摄 Sunny版本*/
	_HisFX3_Platform_Type_R11					= 0x10, /*! 2CPHY/2DPHY + 2DPHY光纤*/
	_HisFX3_Platform_Type_R12					= 0x11, /*! 1CPHY/1DPHY 光纤*/
	_HisFX3_Platform_Type_R15					= 0x12 /*! 4C4D		光纤x2*/
};

enum _HisFX3_CommunicationProtocal{
	_HisFX3_CommProtocal_I2C		=	0x0,
	_HisFX3_CommProtocal_SPI		=	0x1
};

enum UVC_CAPTURE_PROPETIES
{
	CAPTURE_BRIGHTNESS,
	CAPTURE_CONTRAST,
	CAPTURE_HUE,
	CAPTURE_SATURATION,
	CAPTURE_SHARPNESS,
	CAPTURE_GAMMA,
	CAPTURE_COLORENABLE,
	CAPTURE_WHITEBALANCE,
	CAPTURE_BACKLIGHTCOMPENSATION,
	CAPTURE_GAIN,
	CAPTURE_PAN,
	CAPTURE_TILT,
	CAPTURE_ROLL,
	CAPTURE_ZOOM,
	CAPTURE_EXPOSURE,
	CAPTURE_IRIS,
	CAPTURE_FOCUS,
	CAPTURE_PROP_MAX
};

enum _HisFX3_ImageSenor_Factory{
	_HisFX3_ImageSenor_Factory_OV					=	0x00,
	_HisFX3_ImageSenor_Factory_SONY				=	0x10,
	_HisFX3_ImageSenor_Factory_SANSUNG		=	0x20,
	_HisFX3_ImageSenor_Factory_HYNIX			=	0x30,
	_HisFX3_ImageSenor_Factory_APTINA			=	0x40,
	_HisFX3_ImageSenor_Factory_ST					=	0x50,
	_HisFX3_ImageSenor_Factory_TOSHIBA		=	0x60,
	_HisFX3_ImageSenor_Factory_GCOREINC		=	0x70,
	_HisFX3_ImageSenor_Factory_SUPERPIX		=	0x80,
	_HisFX3_ImageSenor_Factory_DONGBU			=	0x90,
	_HisFX3_ImageSenor_Factory_CUSTOM			=	0xFE,
	_HisFX3_ImageSenor_Factory_OTHER			=	0xFF
};

enum _HisFX3_ImageSenor_DataType{
	_HisFX3_ImageSenor_DataType_RAW_U8			=	0x00,
	_HisFX3_ImageSenor_DataType_RAW_U10			=	0x01,
	_HisFX3_ImageSenor_DataType_RAW_U12			=	0x02,
	_HisFX3_ImageSenor_DataType_LYUV420_U8	=	0x03,
	_HisFX3_ImageSenor_DataType_YUV420_U8		=	0x04,
	_HisFX3_ImageSenor_DataType_YUV420_U10	=	0x05,
	_HisFX3_ImageSenor_DataType_YUV422_U8		=	0x06,
	_HisFX3_ImageSenor_DataType_YUV422_U10	=	0x07,
	_HisFX3_ImageSenor_DataType_OTHER				=	0xFF
};

/*! 接口及协议*/
enum _HisFX3_MIPILane_Stream
{
	_HisFX3_MIPILane_Stream_DVP									=	0x0,
	_HisFX3_MIPILane_Stream_Lane1_FPGA					=	0x1,
	_HisFX3_MIPILane_Stream_Lane2_FPGA					=	0x2,
	_HisFX3_MIPILane_Stream_Lane3_FPGA					=	0x3,
	_HisFX3_MIPILane_Stream_Lane4_FPGA					=	0x4,
	_HisFX3_MIPILane_Stream_Lane8_FPGA					=	0x8,
	_HisFX3_MIPILane_Stream_Lane1_ST							=	0x5,
	_HisFX3_MIPILane_Stream_Lane2_ST							=	0x6,
	_HisFX3_MIPILane_Stream_DPHY									= 0x0F,
	_HisFX3_MIPILane_Stream_SubLVDS_SONY				=	0x10,
	_HisFX3_MIPILane_Stream_SubLVDS_CMOSIS			=	0x11,
	_HisFX3_MIPILane_Stream_SubLVDS_END				=	0x1F,
	_HisFX3_MIPILane_Stream_Analog_Interleave				=	0x20,
	_HisFX3_MIPILane_Stream_Analog_Progressive			=	0x21,
	_HisFX3_MIPILane_Stream_SPI_BT656_Lane1			=	0x22, //BT656
	_HisFX3_MIPILane_Stream_SPI_BT656_Lane2			=	0x23,
	_HisFX3_MIPILane_Stream_SPI_BT656_Lane4			=	0x24,
	_HisFX3_MIPILane_Stream_BT1120M1_Interleave		=	0x26, //mode 1
	_HisFX3_MIPILane_Stream_BT1120M1_Progressive	=	0x27,
	_HisFX3_MIPILane_Stream_BT1120M2_Interleave		=	0x28, //mode2
	_HisFX3_MIPILane_Stream_BT1120M2_Progressive	=	0x2A,
	_HisFX3_MIPILane_Stream_SPI_MTK_Lane1				=	0x2B, //MTK
	_HisFX3_MIPILane_Stream_SPI_MTK_Lane2				=	0x2C,
	_HisFX3_MIPILane_Stream_SPI_MTK_Lane4				=	0x2D,
	_HisFX3_MIPILane_Stream_DVP_HDMI						=	0xFF,
	_HisFX3_MIPILane_Stream_UVC									=	0x30,
	_HisFX3_MIPILane_Stream_HDMI									=	0x31,
	_HisFX3_MIPILane_Stream_RTSP								=	0x34,
	_HisFX3_MIPILane_Stream_Jigboard							=	0x40,
	_HisFX3_MIPILane_Stream_HiSPI_Packetized_SP		=	0x50,
	_HisFX3_MIPILane_Stream_HiSPI_Streaming_SP		=	0x51,
	_HisFX3_MIPILane_Stream_HiSPI_Streaming_S			=	0x52,
	_HisFX3_MIPILane_Stream_HiSPI_ActiveStart_SP8	=	0x53,
	_HisFX3_MIPILane_Stream_HiSPI_END						= 0x5F,
	_HisFX3_MIPILane_Stream_CPHY								=	0x60
	
};

enum _HisFX3_Deinterlace_Method{
	_HisFX3_Deinterlace_Overlap	=	0x0
};

enum _HisFX3_BaylorMode{
	HisBaylor8_BGGR				=	0x01,
	HisBaylor8_RGGB				=	0x02,
	HisBaylor8_GRBG				=	0x03, 
	HisBaylor8_GBRG				=	0x04,
	HisBaylor8_MONO				=	0x07,
	HisBaylor10_BGGR			=	0x11,
	HisBaylor10_RGGB			=	0x12,
	HisBaylor10_GRBG			=	0x13, 
	HisBaylor10_GBRG			=	0x14,
	HisBaylor10_MONO			=	0x17,
	HisBaylor12_BGGR			=	0x41,
	HisBaylor12_RGGB			=	0x42,
	HisBaylor12_GRBG			=	0x43, 
	HisBaylor12_GBRG			=	0x44,
	HisBaylor12_MONO			=	0x47,
	HisBaylor14_BGGR			=	0x51,
	HisBaylor14_RGGB			=	0x52,
	HisBaylor14_GRBG			=	0x53, 
	HisBaylor14_GBRG			=	0x54,
	HisBaylor14_MONO			=	0x57,
	HisBaylor_Compact			 = 0x80000000, /*! 数据排列变成高位在前，低位合并为1个Byte */
	HisYUV8_422_YUYV			=	0x21, //YUYV
	HisYUV8_422_UYVY			=	0x22,
	HisYUV8_422_YVYU			=	0x23,
	HisYUV8_422_VYUY			=	0x24,
	HisYUV8_422P					=	0x25,
	HisYUV8_420P					=	0x26,
	HisRGB_RGB24					=	0x30,
	HisRGB_BGR24					= 0x31,
	HisGray_Y8							= 0x61,
	HisRGB_Bilinear					=0x10000000, /*! 双线性差值算法，和HisRGB_RGB24, HisRGB_BGR24一起使用，eg: HisRGB_RGB24 | HisRGB_Bilinear*/
	HisOutputAddInfo				=0x20000000
};

enum _HisFX3_Platform_VoltFlag{
	_HisFX3_Platform_VlotOn_AVDD = 0x0001,
	_HisFX3_Platform_VlotOn_DVDD = 0x0002,
	_HisFX3_Platform_VlotOn_DOVDD = 0x0004,
	_HisFX3_Platform_VlotOn_AF = 0x0008,
	_HisFX3_Platform_VlotOn_OTP = 0x0010,
	_HisFX3_Platform_VlotOn_POW = 0x0020,
	_HisFX3_Platform_VlotOn_IODD = 0x0040,
	_HisFX3_Platform_VlotOn_V5 = 0x0080,
	_HisFX3_Platform_VlotOn_V12					= 0x0100
};

typedef struct _RRect
{
	int    left; /*！包含此坐标*/
	int    top; /*! 包含此坐标*/
	int    right;  /*！不包含此坐标*/
	int    bottom; /*！不包含此坐标*/

	_RRect() { left = top = right = bottom = 0; }
	_RRect(int left2, int top2, int right2, int bottom2)
	{
		this->left = left2;
		this->top = top2;
		this->right = right2;
		this->bottom = bottom2;
	}

	_RRect(const _RRect& src)
	{
		this->left = src.left;
		this->top = src.top;
		this->right = src.right;
		this->bottom = src.bottom;
	}

	_RRect& operator = (const _RRect& src)
	{
		this->left = src.left;
		this->top = src.top;
		this->right = src.right;
		this->bottom = src.bottom;
		return *this;
	}

	bool IsEqual(const _RRect& d)
	{
		return (this->left == d.left) && (this->right == d.right) && (this->top == d.top) && (this->bottom == d.bottom);
	}
} RRect, *PRRect;
 
typedef struct _HisFX3_PreviewStruct
{
	unsigned int ver; /*! 结构体版本号， 固定值， 不要修改*/
	unsigned int uiVoltSetFlag; /*!< 设置要操作的电压，eg. 只操作AVDD和DVDD:  _HisFX3_Platform_VlotOn_AVDD |  _HisFX3_Platform_VlotOn_DVDD； 全操作：0xFFFFFFFF*/
	float volt_DOVDD; /*!< 设置DOVDD电压，0.0~3.5范围可调, 实际所设电压 =  volt_DOVDD */
	float volt_DVDD; /*!< 设置DVDD电压，0.0~3.5范围可调, 实际所设电压 =  volt_DVDD */
	float volt_AVDD; /*!< 设置AVDD电压，0.0~3.5范围可调, 实际所设电压 =  volt_AVDD */
	float volt_AF; /*!< 设置AF电压，0.0~3.5范围可调, 实际所设电压 =  volt_AF */
	float volt_OTP; /*!< 设置DOVDD电压，0.0~10.0范围可调, 实际所设电压 =  volt_VFuse */
	float volt_POW; /*!< 设置POW电压，0.0~3.5范围可调, 实际所设电压 =  volt_POW */
	float volt_IODD; /*!< 设置IODD电压【板卡内部IO电平】【R5】，0.0~3.5范围可调, 实际所设电压 =  volt_IODD */
	float maxVoltDiff;  /*!< 每路电压设置后回读电压值，差异过大则断电返回错误； 单位：V； (maxVoltDiff < 10)时生效 */
	float volt_5V; /*!< 设置5V电压开关，0：不输出  1：输出 其他：不操作  */
	float volt_12V; /*!< 设置12V电压开关，0：不输出  1：输出  其他：不操作  */
	bool bIsSetRST; /*!< 是否设置bReset_ActiveLow */
	bool bReset_ActiveLow; /*!< true: 低电平有效，出图时拉高；   false: 高电平有效，出图时拉低 */
	bool bIsSetPWDN; /*!< 是否设置bPWND_ActiveLow */
	bool bPWND_ActiveLow; /*!< true: 低电平有效，出图时拉高；   false: 高电平有效，出图时拉低 */
	bool bIsSetMCLK; /*!< 是否设置MCLK*/
	double mclk; /*!< 设置mclk。 0~136MHz范围可调*/
	unsigned char onlyRightFrame; /*!< 是否只输出正确帧	b0: 设置FPGA;  b1: 设置上位机; */
	unsigned char ddr; /*!< 是否开启DDR缓存功能   0：关闭；1：开启；2：:不设置 */
	/*! 设置点亮时的上电时序
	 \sa _HisFX3_ImageSenor_Factory
	*/
	_HisFX3_ImageSenor_Factory sensorFactory;
	/*! 
	当工装类型 == _HisFX3_Platform_Type_RTSPM时， 表示URL；
	当sensorFactory == _HisFX3_ImageSenor_Factory_CUSTOM时， 由用户自定义上电时序；
	*/
	char powerUpSequence[256]; 
	/*! 设置板卡上传的数据格式
	\sa _HisFX3_BaylorMode
	*/
	_HisFX3_BaylorMode dataFormat;
	unsigned int iWidth; /*!< 设置一帧的图像宽，单位：像素 */
	unsigned int iHeight; /*!< 设置一帧的图像高，单位：像素 */
	unsigned int uiDummyLeft; /*!< 设置图像左边的Dummy Line */
	unsigned int uiDummyRight; /*!< 设置图像右边的Dummy Line */
	unsigned int uiDummyTop; /*!< 设置图像上边的Dummy Line */
	unsigned int uiDummyBottom; /*!< 设置图像下边的Dummy Line */
	int addInfoBytes; /*! 图像数据附加信息大小， 单位: Byte；正数表示在帧头位置， 负数表示在帧尾位置*/
	RRect streamROI[_RMAX_STREAM_ROI_NUMS]; /*! 分块上传数据流，区块坐标设置*/
	unsigned int streamROINums; /*! 分块上传数据流，块数量，范围：[0,_RMAX_STREAM_ROI_NUMS]；0表示不分块*/
	/*! 设置Sensor数据接口
	\sa _HisFX3_MIPILane_Stream
	*/
	_HisFX3_MIPILane_Stream port;
	unsigned char ucLaneNum; /*!< 设置C-PHY, D-PHY, LVDS 数据Lane数 */


	unsigned char ucCommProtocal; /*!< 设置命令通讯协议。  0:IIC； 1:SPI */
	bool bCheckDeviceAck; /*!< true:IIC通信时侦测是否有ACK回馈； false: 不侦测 */
	bool bSPICSLow; /*!< 设置读写SPI时，CS电平(R5有效)。 true:CS电平为低； false: CS电平为高 */
	bool bSPILittleEndian; /*!< 设置读写SPI时，低位在前还是高位在前(R5有效)。 true:低位在前； false: 高位在前 */
	bool bSPIClkHigh; /*! 设置SPI时钟  true: CLK默认是在高电平；false: CLK默认是在低电平；需要R2C >= 3506 */
	unsigned int usI2CSpeed;  /*!< 设置IIC通信速率，1KHz~1MHz范围可调 */
	unsigned short usI2CIntervalTime; /*!< 设置下发IIC命令的间隔时间，单位：us */
	unsigned int usI2CCount; /*!< 设置IIC或者SPI的命令条数 */
	unsigned char* pucSlave; /*!< 指向设备地址数组指针 */
	unsigned int* puiReg; /*!< 指向寄存器地址数组指针 */
	unsigned int* puiData; /*!< 指向数据数组指针 */
	unsigned short* pusType; /*!< 指向命令类型数组指针，包括0x0816, 0x0808,0x1608,0x1616,0x1632 */

	unsigned int timeout; /*!< 等待图像数据的时间(单位:ms), 0为不等待*/
	bool virtualChannel; /*!< 设置是否开启虚拟通道解码 。 true:开启虚拟通道解码； false: 不开启虚拟通道 */
	unsigned int virtualSize; /*!< 虚拟通道的数据量， 单位：Byte*/

	//D-PHY
	unsigned char ucSignalMode; /*!< 设置DPHY信号模式 0: Power Down 1: SLVS 2:D-PHY */
	bool outputXVSXHS_DPHY; /*!< 设置解码D-PHY时是否输出XS, VS信号(从机模式) */
	unsigned int XHS_DPHY; /*!< 设置解码D-PHY的HS同步信号 */
	unsigned int XVS_DPHY; /*!< 设置解码D-PHY的VS同步信号 */

	//DVP
	bool bDVP_VS_ActiveHigh; /*!< DVP VS 同步信号设置。   true: 高电平有效；   false: 低电平有效 */
	bool bDVP_HS_ActiveHigh; /*!< DVP HS 同步信号设置。   true: 高电平有效；   false: 低电平有效 */
	unsigned char ucDVP_LineFormat; /*!< DVP数据线设置  0：采9:2   1: 采7:0   2：采15:0   3：采9:0  4：采11:0   5：采13:0 */
	int DVP_PhaseShift; /*!<设置并口采集同步信号相移  0:不相移;  1: 90度;  2: 180度;  3: 270度; */

	//LVDS
	bool bOutputXSVS; /*!< 设置解码LVDS时是否输出XS, VS信号 */
	unsigned int LVDS_XHS; /*!< 设置解码LVDS的HS同步信号 */
	unsigned int LVDS_XVS; /*!< 设置解码LVDS的VS同步信号 */
	unsigned int LVDSAlign; /*!< 设置解码LVDS的对齐方式 */

	char strSensorName[64]; /*!< 设置Sensor名称，比如：imx234,imx081, */

	//CPHY
	unsigned int cphyMode; /*!< 0x0: SENSOR输出参考时钟; 0x1:SENSOR不输出参考时钟(9线模式) */
	double cphyRate;  /*!< CPHY速率， 在cphyMode==0x1时设置；单位：Gbps；支持范围：(0.1~1.6)(1.96~2.5) */
	
	unsigned int cphy2ndI2CCount;  /*!< 设置第2批次下发给SENSOR的寄存器数量 */
	unsigned char* cphy2ndSlave; /*!< 指向设备地址数组指针 */
	unsigned int* cphy2ndReg; /*!< 指向寄存器地址数组指针 */
	unsigned int* cphy2ndData; /*!< 指向数据数组指针 */
	unsigned short* cphy2ndType; /*!< 指向命令类型数组指针，包括0x0816, 0x0808,0x1608,0x1616,0x1632 */
	
	unsigned int cphySigI2CCount; /*!< 配置CPHY信号加强寄存器的数量*/
	unsigned char* cphySigSlave; /*!< 指向设备地址数组指针 */
	unsigned int* cphySigReg; /*!< 指向寄存器地址数组指针 */
	unsigned int* cphySigData; /*!< 指向数据数组指针 */
	unsigned short* cphySigType; /*!< 指向命令类型数组指针，包括0x0816, 0x0808,0x1608,0x1616,0x1632 */

	_HisFX3_PreviewStruct()
	{
		ver = 1;
		onlyRightFrame = 0x03;
		streamROINums =addInfoBytes =virtualSize =LVDSAlign = timeout = DVP_PhaseShift = ucDVP_LineFormat = iWidth = iHeight =0;
		bSPILittleEndian =bDVP_VS_ActiveHigh = virtualChannel = false;
		bSPIClkHigh =bSPICSLow =bDVP_HS_ActiveHigh = bIsSetMCLK = bIsSetPWDN = bIsSetRST = bCheckDeviceAck = true;
		bReset_ActiveLow = bPWND_ActiveLow = false;
		ddr	=ucSignalMode = 2;
		sensorFactory = _HisFX3_ImageSenor_Factory_OV;
		dataFormat = HisBaylor10_BGGR;
		ucCommProtocal = _HisFX3_CommProtocal_I2C;
		uiVoltSetFlag = 0xFFFFFFFF;
		mclk =volt_DOVDD = volt_DVDD = volt_AVDD = volt_AF = volt_OTP = volt_POW = volt_IODD = 0.0f;
		maxVoltDiff = 1000.0f;
		cphyRate = -1.0;
		volt_5V = volt_12V = -1.0f;
		outputXVSXHS_DPHY	=bOutputXSVS = false;
		XHS_DPHY = LVDS_XHS = 1152;
		XVS_DPHY = LVDS_XVS = 3125;
		cphyMode =uiDummyLeft = uiDummyRight = uiDummyTop = uiDummyBottom = 0;
		usI2CSpeed = 400;
		usI2CIntervalTime = 200;
		port = _HisFX3_MIPILane_Stream_DPHY;
		ucLaneNum = 4;
		cphySigI2CCount =usI2CCount = cphy2ndI2CCount = 0;
		cphySigSlave =pucSlave = cphy2ndSlave = 0;
		cphySigReg	=puiReg = cphy2ndReg = 0;
		cphySigData	=puiData = cphy2ndData = 0;
		cphySigType	=pusType = cphy2ndType = 0;
		powerUpSequence[0] = strSensorName[0] = '\0';
	}

	~_HisFX3_PreviewStruct()
	{
		if (pucSlave) { delete[] pucSlave; pucSlave = 0; }
		if (puiReg) { delete[] puiReg; puiReg = 0; }
		if (puiData) { delete[] puiData; puiData = 0; }
		if (pusType) { delete[] pusType; pusType = 0; }

		if (cphy2ndSlave) { delete[] cphy2ndSlave; cphy2ndSlave = 0; }
		if (cphy2ndReg) { delete[] cphy2ndReg; cphy2ndReg = 0; }
		if (cphy2ndData) { delete[] cphy2ndData; cphy2ndData = 0; }
		if (cphy2ndType) { delete[] cphy2ndType; cphy2ndType = 0; }

		if (cphySigSlave) { delete[] cphySigSlave; cphySigSlave = 0; }
		if (cphySigReg) { delete[] cphySigReg; cphySigReg = 0; }
		if (cphySigData) { delete[] cphySigData; cphySigData = 0; }
		if (cphySigType) { delete[] cphySigType; cphySigType = 0; }
	}

	_HisFX3_PreviewStruct& operator = (const _HisFX3_PreviewStruct& src)
	{
		if (this == &src) return *this;

		if (this->pucSlave) { delete[] this->pucSlave; this->pucSlave = 0; }
		if (this->puiReg) { delete[] this->puiReg; this->puiReg = 0; }
		if (this->puiData) { delete[] this->puiData; this->puiData = 0; }
		if (this->pusType) { delete[] this->pusType; this->pusType = 0; }

		if (this->cphy2ndSlave) { delete[] this->cphy2ndSlave; this->cphy2ndSlave = 0; }
		if (this->cphy2ndReg) { delete[] this->cphy2ndReg; this->cphy2ndReg = 0; }
		if (this->cphy2ndData) { delete[] this->cphy2ndData; this->cphy2ndData = 0; }
		if (this->cphy2ndType) { delete[] this->cphy2ndType; this->cphy2ndType = 0; }

		if (this->cphySigSlave) { delete[] this->cphySigSlave; this->cphySigSlave = 0; }
		if (this->cphySigReg) { delete[] this->cphySigReg; this->cphySigReg = 0; }
		if (this->cphySigData) { delete[] this->cphySigData; this->cphySigData = 0; }
		if (this->cphySigType) { delete[] this->cphySigType; this->cphySigType = 0; }

		
		this->ver = src.ver;
		this->uiVoltSetFlag = src.uiVoltSetFlag;
		this->volt_DOVDD = src.volt_DOVDD;
		this->volt_DVDD = src.volt_DVDD;
		this->volt_AVDD = src.volt_AVDD;
		this->volt_AF = src.volt_AF;
		this->volt_OTP = src.volt_OTP;
		this->volt_POW = src.volt_POW;
		this->volt_IODD = src.volt_IODD;
		this->maxVoltDiff = src.maxVoltDiff;
		this->volt_5V = src.volt_5V;
		this->volt_12V = src.volt_12V;
		this->bIsSetRST = src.bIsSetRST;
		this->bReset_ActiveLow = src.bReset_ActiveLow;
		this->bIsSetPWDN = src.bIsSetPWDN;
		this->bPWND_ActiveLow = src.bPWND_ActiveLow;
		this->bIsSetMCLK = src.bIsSetMCLK;
		this->mclk = src.mclk;
		this->onlyRightFrame = src.onlyRightFrame;
		this->ddr = src.ddr;
		this->sensorFactory = src.sensorFactory;
		memcpy(this->powerUpSequence, src.powerUpSequence, 256 *sizeof(char));
		this->dataFormat = src.dataFormat;
		this->iWidth = src.iWidth;
		this->iHeight = src.iHeight;
		this->uiDummyLeft = src.uiDummyLeft;
		this->uiDummyRight = src.uiDummyRight;
		this->uiDummyTop = src.uiDummyTop;
		this->uiDummyBottom = src.uiDummyBottom;
		this->addInfoBytes = src.addInfoBytes;
		this->streamROINums = src.streamROINums;
		memcpy(this->streamROI, src.streamROI, _RMAX_STREAM_ROI_NUMS * sizeof(_RRect));
		this->port = src.port;
		this->ucLaneNum = src.ucLaneNum;
		this->ucCommProtocal = src.ucCommProtocal;
		this->bCheckDeviceAck = src.bCheckDeviceAck;
		this->bSPICSLow = src.bSPICSLow;
		this->bSPILittleEndian = src.bSPILittleEndian;
		this->bSPIClkHigh = src.bSPIClkHigh;
		this->usI2CSpeed = src.usI2CSpeed;
		this->usI2CIntervalTime = src.usI2CIntervalTime;
		this->usI2CCount = src.usI2CCount;
		this->timeout = src.timeout;
		this->virtualChannel = src.virtualChannel;
		this->virtualSize = src.virtualSize;
		this->ucSignalMode = src.ucSignalMode;
		this->bDVP_VS_ActiveHigh = src.bDVP_VS_ActiveHigh;
		this->bDVP_HS_ActiveHigh = src.bDVP_HS_ActiveHigh;
		this->ucDVP_LineFormat = src.ucDVP_LineFormat;
		this->DVP_PhaseShift = src.DVP_PhaseShift;
		this->bOutputXSVS = src.bOutputXSVS;
		this->LVDS_XHS = src.LVDS_XHS;
		this->LVDS_XVS = src.LVDS_XVS;
		this->LVDSAlign = src.LVDSAlign;
		this->outputXVSXHS_DPHY = src.outputXVSXHS_DPHY;
		this->XHS_DPHY = src.XHS_DPHY;
		this->XVS_DPHY = src.XVS_DPHY;
		memcpy(this->strSensorName, src.strSensorName, 64 *sizeof(char));
		this->cphyMode = src.cphyMode;
		this->cphyRate = src.cphyRate;
		this->cphy2ndI2CCount = src.cphy2ndI2CCount;
		this->cphySigI2CCount = src.cphySigI2CCount;

		if (src.usI2CCount && src.pucSlave && src.puiReg && src.puiData && src.pusType)
		{
			this->pucSlave = new unsigned char[src.usI2CCount];
			memcpy(this->pucSlave, src.pucSlave, src.usI2CCount * sizeof(unsigned char));
			this->puiReg = new unsigned int[src.usI2CCount];
			memcpy(this->puiReg, src.puiReg, src.usI2CCount * sizeof(unsigned int));
			this->puiData = new unsigned int[src.usI2CCount];
			memcpy(this->puiData, src.puiData, src.usI2CCount * sizeof(unsigned int));
			this->pusType = new unsigned short[src.usI2CCount];
			memcpy(this->pusType, src.pusType, src.usI2CCount * sizeof(unsigned short));
		}

		if (src.cphy2ndI2CCount && src.cphy2ndSlave && src.cphy2ndReg && src.cphy2ndData && src.cphy2ndType)
		{
			this->cphy2ndSlave = new unsigned char[src.cphy2ndI2CCount];
			memcpy(this->cphy2ndSlave, src.cphy2ndSlave, src.cphy2ndI2CCount * sizeof(unsigned char));
			this->cphy2ndReg = new unsigned int[src.cphy2ndI2CCount];
			memcpy(this->cphy2ndReg, src.cphy2ndReg, src.cphy2ndI2CCount * sizeof(unsigned int));
			this->cphy2ndData = new unsigned int[src.cphy2ndI2CCount];
			memcpy(this->cphy2ndData, src.cphy2ndData, src.cphy2ndI2CCount * sizeof(unsigned int));
			this->cphy2ndType = new unsigned short[src.cphy2ndI2CCount];
			memcpy(this->cphy2ndType, src.cphy2ndType, src.cphy2ndI2CCount * sizeof(unsigned short));
		}

		if (src.cphySigI2CCount && src.cphySigSlave && src.cphySigReg && src.cphySigData && src.cphySigType)
		{
			this->cphySigSlave = new unsigned char[src.cphySigI2CCount];
			memcpy(this->cphySigSlave, src.cphySigSlave, src.cphySigI2CCount * sizeof(unsigned char));
			this->cphySigReg = new unsigned int[src.cphySigI2CCount];
			memcpy(this->cphySigReg, src.cphySigReg, src.cphySigI2CCount * sizeof(unsigned int));
			this->cphySigData = new unsigned int[src.cphySigI2CCount];
			memcpy(this->cphySigData, src.cphySigData, src.cphySigI2CCount * sizeof(unsigned int));
			this->cphySigType = new unsigned short[src.cphySigI2CCount];
			memcpy(this->cphySigType, src.cphySigType, src.cphySigI2CCount * sizeof(unsigned short));
		}

		return *this;
	}
}HisFX3_PreviewStruct;

struct _HisFX3_Current_Calibration
{
	float flWorkAVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flWorkDVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flWorkDOVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flWorkAF[_HisFX3V2_CURRENTCAL_COUNT];
	float flWorkOTP[100];
	float flWorkPOW[_HisFX3V2_CURRENTCAL_COUNT];
	float flStandbyAVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flStandbyDVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flStandbyDOVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flStandbyAF[_HisFX3V2_CURRENTCAL_COUNT];
	float flStandbyPOW[_HisFX3V2_CURRENTCAL_COUNT];

	_HisFX3_Current_Calibration()
	{
		memset(flWorkAVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flWorkDVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flWorkDOVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flWorkAF, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flWorkOTP, 0, sizeof(float) *100);
		memset(flStandbyAVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flStandbyDVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flStandbyDOVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flStandbyAF, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flWorkPOW, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flStandbyPOW, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
	}
};

struct _HisFX3_Voltage_Calibration
{
	float flVlotAVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flVlotDVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flVlotDOVDD[_HisFX3V2_CURRENTCAL_COUNT];
	float flVlotAF[_HisFX3V2_CURRENTCAL_COUNT];
	float flVlotOTP[_HisFX3V2_CURRENTCAL_COUNT];
	float flVlotPOW[_HisFX3V2_CURRENTCAL_COUNT];

	_HisFX3_Voltage_Calibration()
	{
		memset(flVlotAVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flVlotDVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flVlotDOVDD, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flVlotAF, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flVlotOTP, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
		memset(flVlotPOW, 0, sizeof(float) *_HisFX3V2_CURRENTCAL_COUNT);
	}
};

struct _HisFX3R2_OSCal_Item
{
	unsigned char ucSwitch;
	char str1stName[_HisFX3_OS_PinName_MaxByte];
	char str2ndName[_HisFX3_OS_PinName_MaxByte];
	float flOffset;

	_HisFX3R2_OSCal_Item()
	{
		ucSwitch	=	0; //0-MIPI  1-DVP 2- MIPI C2
		str1stName[0]		=	'\0';
		str2ndName[0]	=	'\0';
		flOffset		=	0.0f;
	}
};


enum _HisFX3_Current_Switch{
	_HisFX3_Current_DVDD		=	0x0,
	_HisFX3_Current_DOVDD		=	0x1,
	_HisFX3_Current_AVDD		=	0x2,
	_HisFX3_Current_AF				=	0x3
};

enum _HisFX3_OS_PIN_INDEX{
	_HisFX3_OS_PIN_VPPS		=	0x0,
	_HisFX3_OS_PIN_AVDDS		=	0x1,
	_HisFX3_OS_PIN_DOVDDS	=	0x2,
	_HisFX3_OS_PIN_DVDDS		=	0x3,
	_HisFX3_OS_PIN_AFS			=	0x4,
	_HisFX3_OS_PIN_SGND		=	0x5,
	_HisFX3_OS_PIN_MCLK1		=	0x6,
	_HisFX3_OS_PIN_MCLK2		=	0x7,
	_HisFX3_OS_PIN_RST			=	0x8,
	_HisFX3_OS_PIN_PWDN		=	0x9,
	_HisFX3_OS_PIN_SCL			=	0xa,
	_HisFX3_OS_PIN_SDA			=	0xb
};

struct _HisFX3OS_Positive_Item
{
	/*! PIN脚名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strName[_HisFX3_OS_PinName_MaxByte];
	/*! GND脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strGNDName[_HisFX3_OS_PinName_MaxByte];	
	float flSpecMin; /*!< 可设可不设， 库内部没有用到 */
	float flSpecMax; /*!< 可设可不设， 库内部没有用到 */
	float flVoltValue; /*!< 测试完成之后，此PIN脚的电压值会存入flVoltValue，单位：mV*/
	bool bTest; /*!< true：测试		false：不测试 */
	int cam; /*! -1:默认 其他：模组编号*/
	int port; /*! -1: 默认  0：DPHY  1:CPHY  2:DVP 3:LVDS*/
	unsigned int reserve; /*! 保留*/

	_HisFX3OS_Positive_Item()
	{
		flVoltValue	=	0.0f;
		strName[0]	= strGNDName[0] = '\0';
		port = cam = -1;
		reserve = 0;
		bTest = true;
	}

	_HisFX3OS_Positive_Item& operator = (const _HisFX3OS_Positive_Item& src)
	{
		memcpy(this->strName, src.strName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		memcpy(this->strGNDName, src.strGNDName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		this->flSpecMin = src.flSpecMin;
		this->flSpecMax = src.flSpecMax;
		this->flVoltValue = src.flVoltValue;
		this->bTest = src.bTest;
		this->cam = src.cam;
		this->port = src.port;
		this->reserve = src.reserve;
		return *this;
	}
};

struct _HisFX3OS_Negtive_Item
{
	/*! PIN脚名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strName[_HisFX3_OS_PinName_MaxByte];
	/*! DOVDD脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strDOVDDName[_HisFX3_OS_PinName_MaxByte];
	float flSpecMin; /*!< 可设可不设， 库内部没有用到 */
	float flSpecMax;  /*!< 可设可不设， 库内部没有用到 */
	float flVoltValue; /*!< 测试完成之后，此PIN脚的电压值会存入flVoltValue，单位：mV*/
	bool bTest; /*!< true：测试		false：不测试 */
	int cam; /*! -1:默认 其他：模组编号*/
	int port; /*! -1: 默认  0：DPHY  1:CPHY  2:DVP 3:LVDS*/
	unsigned int reserve; /*! 保留*/

	_HisFX3OS_Negtive_Item()
	{
		flVoltValue	=	0.0f;
		strName[0]		= strDOVDDName[0] = '\0';
		port = cam = -1;
		reserve = 0;
		bTest = true;
	}

	_HisFX3OS_Negtive_Item& operator = (const _HisFX3OS_Negtive_Item& src)
	{
		memcpy(this->strName, src.strName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		memcpy(this->strDOVDDName, src.strDOVDDName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		this->flSpecMin = src.flSpecMin;
		this->flSpecMax = src.flSpecMax;
		this->flVoltValue = src.flVoltValue;
		this->bTest = src.bTest;
		this->cam = src.cam;
		this->port = src.port;
		this->reserve = src.reserve;
		return *this;
	}
};

struct _HisFX3OS_Short_Item
{
	/*! PIN脚名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strName[_HisFX3_OS_PinName_MaxByte];
	/*! 当shortIndex != 0时，可以查看strShortName得到与此PIN脚短路的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strShortName[_HisFX3_OS_PinName_MaxByte];
	float flShortSpec; /*!< 小于flShortSpec，则为短路， 单位：mV */
	float flVoltValue; /*!< 测试完成之后，此PIN脚的电压值会存入flVoltValue，单位：mV*/
	unsigned int shortIndex; /*!< ucShortIndex != 0, 就表示此PIN脚有短路  */
	bool bTest; /*!< true：测试		false：不测试 */
	int cam; /*! -1:默认 其他：模组编号(如果|0x8000 为单摄模式, 否则为双摄模式)*/
	int port; /*! -1: 默认  0：DPHY  1:CPHY  2:DVP 3:LVDS*/
	unsigned int reserve; /*! 保留*/

	_HisFX3OS_Short_Item()
	{
		shortIndex =	0;
		flVoltValue	=	0.0f;
		strName[0]	= strShortName[0] =  '\0';
		port = cam = -1;
		reserve = 0;
		bTest = true;
	}

	_HisFX3OS_Short_Item& operator = (const _HisFX3OS_Short_Item& src)
	{
		memcpy(this->strName, src.strName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		memcpy(this->strShortName, src.strShortName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		this->flShortSpec = src.flShortSpec;
		this->flVoltValue = src.flVoltValue;
		this->shortIndex = src.shortIndex;
		this->bTest = src.bTest;
		this->cam = src.cam;
		this->port = src.port;
		this->reserve = src.reserve;
		return *this;
	}
};

struct _HisFX3OS_Open_Item
{
	/*! PIN脚名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char strName[_HisFX3_OS_PinName_MaxByte];
	/*! 当openIndex != 0时，可以查看strOpenName得到与此PIN脚开路的PIN脚名称
	\sa _HisFX3OS_Positive_Item
	*/
	char strOpenName[_HisFX3_OS_PinName_MaxByte];
	float flOpenSpec; /*!> 大于flOpenSpec，则为开路， 单位：mV */
	float flVoltValue; /*!< 测试完成之后，此PIN脚的电压值会存入flVoltValue，单位：mV*/
	unsigned int openIndex; /*!< ucOpenIndex != 0, 就表示此PIN脚开路  */
	bool bTest; /*!< true：测试		false：不测试 */
	int cam; /*! -1:默认 其他：模组编号*/
	int port; /*! -1: 默认  0：DPHY  1:CPHY  2:DVP 3:LVDS*/
	unsigned int reserve; /*! 保留*/

	_HisFX3OS_Open_Item()
	{
		openIndex =	0;
		flVoltValue	=	0.0f;
		strName[0]	= strOpenName[0] = '\0';
		port = cam = -1;
		reserve = 0;
		bTest = true;
	}

	_HisFX3OS_Open_Item& operator = (const _HisFX3OS_Open_Item& src)
	{
		memcpy(this->strName, src.strName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		memcpy(this->strOpenName, src.strOpenName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		this->flOpenSpec = src.flOpenSpec;
		this->flVoltValue = src.flVoltValue;
		this->openIndex = src.openIndex;
		this->bTest = src.bTest;
		this->cam = src.cam;
		this->port = src.port;
		this->reserve = src.reserve;
		return *this;
	}
};

struct _HisFX3OS_OHM_Item
{
	/*! PIN脚1 名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char str1stName[_HisFX3_OS_PinName_MaxByte];
	/*! PIN脚2 名称, 可以调用HisFX3GetOSPinNameList查看所有的PIN脚名称
	\sa HisFX3GetOSPinNameList
	*/
	char str2ndName[_HisFX3_OS_PinName_MaxByte];
	float flOhmValue; /*!< 测试完成之后，此PIN脚的阻值会存入flOhmValue，单位：欧姆*/
	float flSpecMin; /*!< 可设可不设， 库内部没有用到 */
	float flSpecMax; /*!< 可设可不设， 库内部没有用到 */
	int cam; /*! -1:默认 其他：模组编号*/
	int port; /*! -1: 默认  0：DPHY  1:CPHY  2:DVP 3:LVDS*/
	unsigned int reserve; /*! 保留*/

	_HisFX3OS_OHM_Item()
	{
		str1stName[0] = str2ndName[0] = '\0';
		port = cam = -1;
		reserve = 0;
	}

	_HisFX3OS_OHM_Item& operator = (const _HisFX3OS_OHM_Item& src)
	{
		memcpy(this->str1stName, src.str1stName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		memcpy(this->str2ndName, src.str2ndName, _HisFX3_OS_PinName_MaxByte * sizeof(char));
		this->flOhmValue = src.flOhmValue;
		this->flSpecMin = src.flSpecMin;
		this->flSpecMax = src.flSpecMax;
		this->cam = src.cam;
		this->port = src.port;
		this->reserve = src.reserve;
		return *this;
	}
};

enum _HisFX3Platform_ErrorCode{
	HisFX3Error_Construct			=	0x0100,	/*!< 类构造失败*/
	HisFX3Error_CloseUSB3		=	0x0200,	/*!< 关闭usb3.0失败 */
	HisFX3Error_Timeout				=	0x0300,	/*!< 操作超时 */
	HisFX3Error_Parameter			=	0x0400,	/*!< 参数错误 */
	HisFX3Error_IsNotOpen			=	0x0500,	/*!< 设备还未打开*/
	HisFX3Error_IsNotPreview		=	0x0600,	/*!< 还未出图*/
	HisFX3Error_MallocBuffer		=	0x0700,	/*!< 申请内存失败 */
	HisFX3Error_USBDataOut		=	0x0800,	/*!< 下发数据失败 */
	HisFX3Error_Hardware			=	0x0900,	/*!< 其他硬件错误 */
	HisFX3Error_Other					=	0x0A00,	/*!< 其他错误*/
	HisFX3Error_NotSuperSpeed	=	0x0B00,	/*!< 不是超速模式*/
	HisFX3Error_CreateThread	=	0x0C00,		/*!< 创建线程失败 */
	HisFX3Error_License				=	0x0D00,		/*!< license 错误 */
	HisFX3Error_NoRespond		=	0x0E00,		/*!< IIC没响应*/
	HisFX3Error_WirteIIC				=	0x0F00,	/*!< 写IIC失败*/
	HisFX3Error_Check				=	0x1000	,	/*!< 校验码出错 */
	HisFX3Error_AlgData				=	0x1100,				//导入算法的数据部符合要求
	HisFX3Error_CreateEvent		=	0x1200,	/*!< 创建事件失败*/
	HisFX3Error_MemNotEnough	=	0x1300,	/*!< 内存空间不满足要求*/
	HisFX3Error_FuntionNotSupport	=	0x1400,	/*!< 此函数不支持*/
	HisFX3Error_ShortTestAbort	=	0x1500,	/*!< OS短路测试异常*/
	HisFX3Error_NegOpenTestAbort	=	0x1600,	/*!< OS负向测试异常*/
	HisFX3Error_PosOpenTestAbort	=	0x1700, /*!< OS正向测试异常*/
	HisFX3Error_ImgBufConvert			=	0x1800,	/*!< 图像格式转换错误*/
	HisFX3Error_NoHardware				=	0x1900,	/*!< 没有硬件*/
	HisFX3Error_Connect					=	0x1A00,
	HisFX3Error_CameraON					=	0x1B00,
	HisFX3Error_GrabFrame					=	0x1C00,	/*!< 抓帧失败*/
	HisFX3Error_OSAbort						=	0x1D00,	/*!< OS测试异常*/
	HisFX3Error_VersionNotMatch		=	0x1E00,	/*!< 版本不匹配*/
	HisFX3Error_UpdateHW					=	0x1F00,	/*!< 升级固件失败*/
	HisFX3Error_NoGrabber					=	0x2000,	/*!< 没有找到工装*/
	HisFX3Error_GrabberClosing			=	0x2100,  //grabber is closing
	HisFX3Error_StreamInReset			=	0x2200,  //stream in error, and reseting
	HisFX3Error_StreamExit				=	0x2300	,	//stream thread exit timeout
	HisFX3Error_AVDDVDiffBig			=	0x2400,	/*! AVDD设置的电压和测量的电压过大 */
	HisFX3Error_DVDDVDiffBig = 0x2401,	/*! DVDD设置的电压和测量的电压过大 */
	HisFX3Error_DOVDDVDiffBig = 0x2402,	/*! DOVDD设置的电压和测量的电压过大 */
	HisFX3Error_IODDVDiffBig = 0x2403,	/*! IODD设置的电压和测量的电压过大 */
	HisFX3Error_AFVDiffBig = 0x2404,	/*! AF设置的电压和测量的电压过大 */
	HisFX3Error_POWVDiffBig = 0x2405,	/*! POW设置的电压和测量的电压过大 */
	HisFX3Error_OTPVDiffBig = 0x2406,	/*! OTP设置的电压和测量的电压过大 */
	HisFX3Error_Preivewing					=	0x2500,		/*!< 出图中*/
	HisFX3Error_OSNotCalibration							=	0x2600, /*!< OS还没有校准*/

	HisFX3Error_VoltageNotCalibration					=	0x2700, /*!< 电压还未校准*/
	HisFX3Error_CurrentNotCalibration			=	0x2800, /*!< 电流还未校准*/
	HisFX3Error_IsNotStart								 =	 0x2900,
	HisFX3Error_OSPinName = 0x2A00,
	HisFX3Error_CPUNotMeet	=	0x2A01,
	HisFX3Error_InvalidLineSize	=	0x2A2,
	HisFX3Error_InvalidImageSize	=	0x2A03,
	HisFX3Error_OutofMemrory	=	0x2A04,
	HisFX3Error_InvalidFormat	=	0x2A05,
	HisFX3Error_OpenDev = 0x2A06, /*!< 打开工装失败*/
	HisFX3Error_NoImageData = 0x2A07, /*!< 没有图像数据*/
	HisFX3Error_OpenFile = 0x2A08, /*!< 打开文件失败*/
	HisFX3Error_OSNotSupported = 0x2A09, /*!< OS功能不支持*/
	HisFX3Error_USBDataIn = 0x2A0A, 	/*!< 上传数据失败 */
	HisFX3Error_LoadDLL = 0x2A0B, /*! 动态加载DLL文件失败*/
	HisFX3Error_LoadAPI = 0x2A0C, /*! 动态加载DLL 中的API失败*/
	HisFX3Error_CRC = 0x2A0D,  /*! 校验码错误*/
	HisFX3Error_AF = 0x2A0E, /*! 对焦失败*/
	HisFX3Error_FlashMemNotEnough	=	0x2A0F, /*! Flash空间不足*/
	HisFX3Error_PtIsNULL	=	0x2A10,  /*! 指针为NULL*/
	HisFX3Error_WaitEventAbort	=	0x2A11,  /*! 等待事件异常退出*/
	HisFX3Error_DecodeWidthHeight = 0x2A12,  /*! 图像宽高解码不匹配*/
	HisFX3Error_UpFrame = 0x2A13, 	/*! 上传错误帧*/
	HisFX3Error_DecodeDataFormat = 0x2A14,  /*! 解码数据格式不正确*/
	HisFX3Error_DecodeLaneNum = 0x2A15, 	/*! 解码LANE数不正确*/
	HisFX3Error_MeasureCPHYRate = 0x2A16, /*! 检测CPHY速率失败*/
	HisFX3Error_OperateRegister = 0x2A17, /*! 操作注册表失败*/
	HisFX3Error_AdapterCPUBand = 0x2A18, /*! 网卡CPU绑定错误*/
	HisFX3Error_ProcessCPUBand = 0x2A19, /*! 进程绑定CPU失败*/
	HisCCMError_NotPreivew		=	0x100100,
	HisCCMError_NoFrame			=	0x100200,
	HisCCMError_Result				=	0x100300,
	HisCCMError_Database			=	0x100400,
	HisCCMError_opConflic			=	0x100500,
	HisCCMError_saveImage		=	0x100600,
	HisCCMError_luxtooLow		=	0x100700,
	HisCCMError_luxtooHigh		=	0x100800,
	HisCCMError_readIIC				=	0x100900,
	HisCCMError_OpenFile			=	0x100A00,	//打开文件失败
	HisCCMError_FileAttribute		=	0x100B00,	//获取文件属性失败，或者属性不匹配
	HisCCMError_ReadFile			=	0x100C00,	//读取文件数据失败
	HisCCMError_WriteFile			=	0x100D00,
	HisCCMError_NoOTP				=	0x100E00,
	HisCCMError_OTPCheckSum	=	0x100F00,
	HisCCMError_LoadDLL				=	0x101000,
	HisCCMError_LoadDLLFuc		=	0x102000,
	HisCCMError_OtpFucExec		=	0x103000,
	HisCCMError_FilePath		=	0x104000,
	HisCCMError_CreateProcess	=	0x105000,
	HisCCMError_NoValidOTP		=	0x106000,
	HisCCMError_OtpWrite		=	0x107000,
	HisCCMError_NoOTPSpace		=	0x108000,
	HisCCMError_CreateFile		=	0x108100,
	HisCCMError_ImageQuality	=	0x108200,
	HisCCMError_NoRightPos		=	0x108300,
	HisCCMError_CPUNotMeet		=	0x108400,
	HisCCMError_InvalidLineSize		=	0x108500,
	HisCCMError_InvalidWidthSize		=	0x108600,
	HisCCMError_InvalidHeightSize		=	0x108700,
	HisCCMError_InvalidImageSize		=	0x108800,
	HisCCMError_OutofMemrory				=	0x108900,
	HisCCMError_InvalidFormat				=	0x108A00,
	HisCCMError_ExtractFOV					=	0x108B00,
	HisCCMError_UnderSpin						=	0x108C00,
	HisCCMError_UpCheck							=	0x108D00,
	HisCCMError_NotSupportx86				=	0x108E00,
	HisCCMError_NotSupportx64				=	0x108F00,
	HisCCMError_NoFocusStep					=	0x109000,
	HisCCMError_AF									=	0x109100,
	HisCCMError_FileFormat					=	0x109200,
	HisCCMError_String2Hex					=	0x109300,
	HisCCMError_String2Data					=	0x109400,
	HisCCMError_QualcommPDAFStep1			=	0x109500,
	HisCCMError_QualcommPDAFStep2			=	0x109600,  //qualcomm pdaf step2 fail
	HisCCMError_QualcommPDAFStep2Verify			=	0x109700,  //qualcomm pdaf step2 fail
	HisCCMError_MARK								=	0x109800, 
	HisCCMError_SONYPDAF_SPC  =0x109900,
	HisCCMError_SONYPDAF_DCC  =0x109A00,
	HisCCMError_SONYPDAF_DCC_COEF  =0x109B00,
	HisCCMError_SONYPDAF_DCC_VERIFY  =0x109C00,
	HisCCMError_PDAF_VERIFY  =0x109D00,
	HisCCMEMG_Return                              =0x109E00,
	HisCCMError_TiltRotation                  =0x109F00,
	HisCCMError_CoaxilityTest                  =0x10A000,
	HisCCMError_OpticalCenterTest       =0x10B000,
	HisCCMError_BlemishTest       =0x10c000,
	HisCCMError_DefectPixelTest       =0x10d000,
	HisCCMError_HotPixelTest       =0x10e000,
	HisCCMError_OpenshortTest       =0x10f000,

	HisMotionError_SocketInit				=	0x10100,	//初始化socket失败
	HisMotionError_GetHostName		=	0x10200, //取得主机描述名称失败
	HisMotionError_GetIPAddr				=	0x10300, //取得IP地址失败
	HisMotionError_Disconnect			=	0x10400,	//没有打开链接
	HisMotionError_MoveFail				=	0x10500,  //运动失败
	HisMotionError_Home						=	0x10600,  //回零校正失败
	HisMotionError_Config					=	0x10700,	//外配ini文档错误
	HisMotionError_NoHome				=	0x10800, //还没有回零校正
	HisMotionError_InitAbsPos				=	0x10900, //绝对坐标初始化失败或者还未初始化
	HisMotionError_Busy						=	0x10a00, //正忙
	HisMotionError_TooManyConnect	=	0x10b00, //找到太多设备
	HisMotionError_OS							=	0x10c00, //下位机控制软件错误
	HisMotionError_Firmware				=	0x10d00, //下位机分位错误
	HisMotionError_NotSupport			=	0x10e00, //功能不支持
	HisMotionError_FileNameTooLong=	0x10f00,
	HisMotionError_Transmit					=	0x11000,
	HisMotionError_ExpandMoveLimit		=	0x11100,
	HisMotionError_ProtectionLimit			=	0x11200,
	HisMotionError_NotFoundDev					=	0x11300, //没有找到设备
	HisMotionError_FoundTooManyDev			=	0x11400, //找到太多设备
	HisMotionError_LibFucExec						=	0x11500, //运动控制库函数返回错误
	HisMotionError_SoftLimit						=	0x11600,  //超过运动行程
	HisMotionError_PositiveEL						=	0x11700, //正向限位
	HisMotionError_NegtiveEL						=	0x11800,   //负向限位
	HisMotionError_INIONoResponse			=	0x11900,	//输入IO没响应

	HisVisionError_OpenFile					=	0x20100,
	HisVisionError_ReadFile					=	0x20200,
	HisVisionError_ReadSize					=	0x20300,
	HisVisionError_FileType					=	0x20400,
	HisVisionError_Center					=	0x20500,
	HisVisionError_Match					=	0x20600,
	HisVisionError_InputImage				=	0x20700,
	HisVisionError_InputColorImage			=	0x20800,
	HisVisionError_Radius						=	0x20900,
	HisVisionError_Binary							=	0x20A00,
	HisVisionError_ContourNumber			=	0x20B00,
	HisVisionError_PetalNumber				=	0x20C00,
	HisVisionError_CreateFile				=	0x20D00,
	HisVisionError_WriteFile				=	0x20E00,
	HisVisionError_GrabVisionFrame				=	0x20F00,

	HisRs232Error_Open					=	0x30100,
	HisRs232Error_BasicSteup			=	0x30200,
	HisRs232Error_SetEvent			=	0x30300,
	HisRs232Error_SetTimeOut			=	0x30400,
	HisRs232Error_WaitEvent			=	0x30500,
	HisRs232Error_Read					=	0x30600,
	HisRs232Error_SetHandShake	=	0x30700,
	HisRs232Error_Write					=	0x30800,
	HisRs232Error_DataMatch			=	0x30900,
	HisRs232Error_NotOpen			=	0x30A00,

	HisTcpIpError_Listen							=	0x40100,
	HisTcpIpError_IsNotListen					=	0x40200,
	HisTcpIpError_SocketWriteError		=	0x40300,
	HisTcpIpError_WriteLengthError		=	0x40400,
	HisTcpIpError_WriteError					=	0x40500,
	HisTcpIpError_NoSocket						=	0x40600,
	HisTcpIpError_Connect						=	0x40700,
	HisTcpIpError_IsNotConnect				=	0x40800,
	HisTcpIpError_Busy =0x40801,
	HisTcpIpError_ReceiveOverTime =0x40802,
	HisTcpIpError_dualcameracoaxialitytest	=	0x40803
};

enum _HisFX3_YUVCVTRGB_FLAG{
	_HisFX3_YUVCVTRGB_BT601				=	0x1,
	_HisFX3_YUVCVTRGB_BT709				=	0x2
};

struct _HisFX3_AF_Block
{
	int left; /*! 单位：像素*/
	int top; /*! 单位：像素*/
	int right; /*! 单位：像素*/
	int bottom; /*! 单位：像素*/
	int weight; /*! 对焦曲线权重, 0~100*/

	_HisFX3_AF_Block() {}
	_HisFX3_AF_Block(_HisFX3_AF_Block& src)
	{
		this->left = src.left;
		this->top = src.top;
		this->right = src.right;
		this->bottom = src.bottom;
		this->weight = src.weight;
	}

	_HisFX3_AF_Block& operator = (const _HisFX3_AF_Block& src)
	{
		this->left = src.left;
		this->top = src.top;
		this->right = src.right;
		this->bottom = src.bottom;
		this->weight = src.weight;
		return *this;
	}
};

struct _HisFX3_VCMDriver_Cfg
{
	char type[32]; /*! 马达型号, 内置9714a,gt9762s,9718s*/
	unsigned char slave; /*! 设备地址*/

	unsigned char iicCount; /*! IIC数量*/
	unsigned char iicInterval; /*! IIC间隔时间, 单位：ms*/
	unsigned char regBytes; /*! 寄存器位长度，单位：Byte*/
	unsigned char dataBytes; /*! 数据位长度， 单位:Byte*/
	unsigned char regRightShift[2];
	unsigned char regLeftShift[2];
	unsigned short regAnd[2];
	unsigned short regOr[2];
	unsigned char dataRightShift[2];
	unsigned char dataLeftShift[2];
	unsigned short dataAnd[2];
	unsigned short dataOr[2];

	_HisFX3_VCMDriver_Cfg()
	{
		type[0] = '\0';
		iicCount = 0;
		iicInterval = 0;
	}
};

struct _HisFX3_FPGAAF_Cfg
{
	const unsigned int ver; /*! 结构体版本号， 内部使用，无需修改*/
	bool doCurveFit; /*! 是否要做曲线拟合*/
	unsigned char afAlg; /*!对焦算法*/
	unsigned char mtfAlg; /*! 解析力算法*/
	unsigned char waitMotorStableMethod; /*! 等待马达稳定的延时方法，0:等待固定的帧数  1:等待固定的时间*/
	unsigned char frames[2]; /*! 等待马达稳定的帧数；数组0：大步近延帧；数组1：:小步进延帧*/
	unsigned short waitms[2]; /*! 等待马达稳定的时间， 单位:ms；数组0：大步近延时；数组1：:小步进延时*/
	unsigned int timeout; /*! 对焦过程timeout时间， 单位:ms*/
	unsigned short steptimeout; /*! 单独等待正确帧的timeout时间，单位:ms*/
	unsigned char blockCount; /*! 算解析力ROI个数，范围(1: 9)*/
	_HisFX3_AF_Block roi[9];
	_HisFX3_VCMDriver_Cfg motor;
	unsigned int bigStep; /*! 马达对焦策略大步步数*/
	unsigned int smallStep; /*! 马达对焦策略小步步数*/
	double bsChangeMTF; /*! 马达大小步数切换的解析力阀值*/
	int motorStart; /*! 马达对焦的范围起始位置*/
	int motorEnd; /*! 马达对焦的范围结束位置*/
	double peakValidMTF; /*! PEAK点的最小MTF值*/
	double curveDropMTF; /*! 判断曲线下降的MTF落差值*/
	int luxDiffMin;	/*! 亮度差值范围最小值*/
	int luxDiffMax;	/*! 亮度差值范围最大值*/
	double pixelNumsMin; /*! 最低有效像素比例*/

	_HisFX3_FPGAAF_Cfg()
		: ver(1), doCurveFit(false)
	{
		blockCount =afAlg = mtfAlg =0;
		waitMotorStableMethod = 1;
		frames[0] = frames[1] = 2;
		waitms[0] = waitms[1] = 100;
		timeout = 10000;
		steptimeout = 500;
		bigStep = 20; smallStep = 5;
		motorStart = 0; motorEnd = 1023;
		luxDiffMin = 6; luxDiffMax = 200;
		pixelNumsMin = 0.0001;
	}
};

struct _HisFX3_AF_Curve
{
	int motorDec; /*! 马达值*/
	double mtf; /*! MTF值*/

	_HisFX3_AF_Curve() {}
	_HisFX3_AF_Curve(const _HisFX3_AF_Curve& src)
	{
		this->motorDec = src.motorDec;
		this->mtf = src.mtf;
	}

	_HisFX3_AF_Curve& operator = (const _HisFX3_AF_Curve& src)
	{
		this->motorDec = src.motorDec;
		this->mtf = src.mtf;
		return *this;
	}
};

struct _HisFX3_FPGAAF_Rel
{
	int peakMotor; /*! PEAK点的马达值*/
	double peakMTF; /*! PEAK点的MTF值*/
	_HisFX3_AF_Curve curve[4096];
	unsigned int curvePtCount; /*! 曲线的点数*/
};
#endif/**********  新SDK用 *****************/


class QHisFX3MallocAlignedManage
{
public:
	QHisFX3MallocAlignedManage(void* pvBuf2)
	{
		pvBuf	=	pvBuf2;
	}

	~QHisFX3MallocAlignedManage()
	{
		HisReleaseMalloc(pvBuf)
	}

	void Release()
	{
		HisReleaseMalloc(pvBuf)
	}

private:
	void* pvBuf;
};

template <class T> class QHisFX3NewObjectManage
{
public: 	
	QHisFX3NewObjectManage(T* aVar)
	{
		mVar = aVar;
	}

	~QHisFX3NewObjectManage()
	{
		if(mVar != 0){
			delete mVar;
			mVar = 0;
		}
	}

	void Release()
	{
		if(mVar != 0){
			delete mVar;
			mVar = 0;
		}
	}

private:
	T *mVar;
};

template <class T> class QHisFX3NewBufManage
{
public: 	
	QHisFX3NewBufManage(T * aVar)
	{
		mVar = aVar;
	}

	~QHisFX3NewBufManage()
	{
		if(mVar != 0){
			delete[] mVar;
			mVar = 0;
		}
	}

	void Release()
	{
		if(mVar != 0){
			delete[] mVar;
			mVar = 0;
		}
	}

private:
	T *mVar;
};


#define RJ_AFAM_CCW_INDEX		1.0
#define RJ_AFAM_CW_INDEX		-1.0

#define _HisAlg_SWITCH_A				0
#define _HisAlg_SWITCH_B				1
#define _HisAlg_SWITCH_C				2
#define _HisAlg_SWITCH_D				3
#define _HisAlg_SWITCH_E				4
#define _HisAlg_SWITCH_F				5
#define _HisAlg_SWITCH_G				6
#define _HisAlg_SWITCH_H				7

#define _HisCCMDraw_NotRemove_Mask	0x8000
#define _HisCCMDraw_TestRemove_Mask	0x7fff

#define _HisAlg_InvalidValueDefine_Double_0				0.0
#define _HisAlg_InvalidValueDefine_Double_999999	999999.0


enum _HisCoaxiality_ErrorCode{
	HisCoaxiality_Errorparamater			=	0x01,	//输入参数错误
	HisCoaxiality_ErrorRgbFalg				=	0x02, //彩色图像参数错误
	HisCoaxiality_ErrorRectNumber			=	0x03, //提取正方形个数错误
	HisCoaxiality_ErrorCircleNumber			=	0x04,	//提取圆形个数错误
	HisCoaxiality_ErrorCrossNumber			=	0x05,  //提取十字架个数错误
	HisCoaxiality_ErrorRectSuperposition	=	0x06,  //正方形提取位置重合
	HisCoaxiality_ErrorChartExcursion		=	0x07,  //chart放歪了
	HisCoaxiality_ErrorLuminancethreshold	=	0x08,  //亮度阈值错误
	HisCoaxiality_ErrorRESULT				=	0x09  //结果不符合规格
};
enum _HisFX3_FrameType{
	_FrameType_Raw							=	0x01, //RAW8
	_FrameType_RGB24						=	0x02,
	_FrameType_Raw10						=	0x04, //RAW10
	_FrameType_Raw12						=	0x08, //RAW12
	_FrameType_ALL_ADD_ORIGINAL	=	0x80
};


enum _HisFX3_BufferFormat{
	_HisFX3_BufferFormat_RAW8			= 0x00,
	_HisFX3_BufferFormat_RAW10		= 0x01,
	_HisFX3_BufferFormat_YUV422U8	=	0x02,
	_HisFX3_BufferFormat_RGB24		=	0x03,
	_HisFX3_BufferFormat_BayloyGr	=	0x04,
	_HisFX3_BufferFormat_BaylorGb	=	0x05,
	_HisFX3_BufferFormat_BaylorR	=	0x06,
	_HisFX3_BufferFormat_BaylorB	=	0x07,
	_HisFX3_BufferFormat_Y				=	0x08,
	_HisFX3_BufferFormat_G				=	0x09
};

enum _HisAlg_LineType{
	_HisAlg_LineType_Horizontal		=	0x00,
	_HisAlg_LineType_Vertical			=	0x01
};


enum _HisCCM_AlgID_Enum{
	_HisCCM_AlgID_MTF_hao_a			=	0x00000001,	//自带MTF算法
	_HisCCM_AlgID_MTF_standard		=	0x00000002	,	//标准MTF算法
	_HisCCM_AlgID_MTF_hao_b			=	0x00000003	,	//自带MTF算法
	_HisCCM_AlgID_MTF_hao_c			=	0x00000004	,	//自带MTF算法
	_HisCCM_AlgID_SFR_hao_a			=	0x00000011
};


enum _HisFX3Platform_FactoryCode{
};

enum _HisFX3Platform_APPCode{
	 _HisFX3Platform_APP_None					=	0x0,
	 _HisFX3Platform_APP_Manual				=	0x1,
	 _HisFX3Platform_APP_YIOU_AFA_G1	=	0x2,
	 _HisFX3Platform_APP_YIOU_AFC_G1	=	0x3,
	 _HisFX3Platform_APP_JIGBOARD			=	0x4,
	 _HisFX3Platform_APP_ALL						=	0xFF
};

enum _HisFX3Platform_AuthCode{
};

enum _HisMainFrame_ErrorCode{
	HisMainFrameError_GetFrame		=	0x40100
};

enum _HisCamera_ErrorCode{
	HisCameraError_Open						=	0x40100,
	HisCameraError_Close					=	0x40200,
	HisCameraError_IsNotOpen			=	0x40300,
	HisCameraError_SetConfig			=	0x40400,
	HisCameraError_GetConfig			=	0x40500
};

enum _HisSaveLog_ErrorCode{
	_HisSaveLogError_NoKey				=	0x50100,
	_HisSaveLogError_SNMatch			=	0x50200
};

enum _HISLOG_CLASSIFY{
	_HISLOG_CLASSIFY_SN									=	0,
	_HISLOG_CLASSIFY_DATE								=	1,
	_HISLOG_CLASSIFY_TIME								=	2,
	_HISLOG_CLASSIFY_DATETIME						=	3,
	_HISLOG_CLASSIFY_TOTALRESULT				=	4,
	_HISLOG_CLASSIFY_JOBNUMBER					=	5,
	_HISLOG_CLASSIFY_PRODUCTLINE				=	6,
	_HISLOG_CLASSIFY_EQUIPNUMBER				=	7,
	_HISLOG_CLASSIFY_PRODUCBATCH			=	8,
	_HISLOG_CLASSIFY_MACADDRESS				=	9,
	_HISLOG_CLASSIFY_MTFFA							=	100,
	_HISLOG_CLASSIFY_SFRFA							=	200,
	_HISLOG_CLASSIFY_MTFFCNEAR					=	300,
	_HISLOG_CLASSIFY_MTFFCMIDDLE				=	400,
	_HISLOG_CLASSIFY_MTFFCFAR					=	500,
	_HISLOG_CLASSIFY_SFRFCNEAR					=	600,
	_HISLOG_CLASSIFY_SFRFCMIDDLE				=	700,
	_HISLOG_CLASSIFY_SFRFCFAR					=	800,
	_HISLOG_CLASSIFY_WHITEPANEL				=	900,
	_HISLOG_CLASSIFY_AE									=	1000,
	_HISLOG_CLASSIFY_BRIGHTNESS				=	1100,
	_HISLOG_CLASSIFY_WORKCURRENT			=	1200,
	_HISLOG_CLASSIFY_STANDBYCURRENT		=	1300,
	_HISLOG_CLASSIFY_OTPBURN						=	1400,
	_HISLOG_CLASSIFY_OTPCHECK					=	1500,
	_HISLOG_CLASSIFY_AFBURN							=	1600,
	_HISLOG_CLASSIFY_AFBURNCHECK			=	1700,
	_HISLOG_CLASSIFY_BLACKFIELD					=	1800,
	_HISLOG_CLASSIFY_RJAFA_LP1					=	1900,
	_HISLOG_CLASSIFY_AFC_LP_NEAR				=	2000,
	_HISLOG_CLASSIFY_AFC_LP_MIDDLE			=	2100,
	_HISLOG_CLASSIFY_AFC_LP_FAR					=	2200,
	_HISLOG_CLASSIFY_LPMFA							=	2300,
	_HISLOG_CLASSIFY_PDAFBURN						=	2400,
	_HISLOG_CLASSIFY_PDAFBURNCHECK			=	2500,
	_HISLOG_CLASSIFY_OPENGNDTEST				=	2600,
	_HISLOG_CLASSIFY_OPENDOVDDTEST			=	2700,
	_HISLOG_CLASSIFY_SHORTTEST					=	2800,
	_HISLOG_CLASSIFY_OPENCIRCUITTEST		=	2900,
	_HISLOG_CLASSIFY_OHMTEST						=	3000,
	_HISLOG_CLASSIFY_MICTEST						=	3100,
	_HISLOG_CLASSIFY_LEDTEST						=	3200,
	_HISLOG_CLASSIFY_FWBURN						=	3300,
	_HISLOG_CLASSIFY_BLEMISH						=	3400,
	_HISLOG_CLASSIFY_DEFECTPIXEL				=	3500,
	_HISLOG_CLASSIFY_OC									=	3600,
	_HISLOG_CLASSIFY_DEFECTLINE					=	3700,
	_HISLOG_CLASSIFY_WHITECOLOR				=	3800,
	_HISLOG_CLASSIFY_SHADING						=	3900,
	_HISLOG_CLASSIFY_VIGNETTING					=	4000,
	_HISLOG_CLASSIFY_RRTMacro						=	4100,
	_HISLOG_CLASSIFY_RRTFar							=	4200,
	_HISLOG_CLASSIFY_AFMacro							=	4300,
	_HISLOG_CLASSIFY_AFMiddle							=	4400,
	_HISLOG_CLASSIFY_AFFar								=	4500,
	_HISLOG_CLASSIFY_LSCHECK						=	4600,
	_HISLOG_CLASSIFY_CDRDCALIBRATION		=	4700
};

enum _HisCCMAlg_ImageBuffer_BitDepth{
	_HisCCMAlg_ImageBuffer_BitDepth_U8	=	0x1,
	_HisCCMAlg_ImageBuffer_BitDepth_U16	=	0x2,
	_HisCCMAlg_ImageBuffer_BitDepth_U32	=	0x4,
	_HisCCMAlg_ImageBuffer_BitDepth_I16	=	0x8,
	_HisCCMAlg_ImageBuffer_BitDepth_I32	=	0x10,
	_HisCCMAlg_ImageBuffer_BitDepth_F32	=	0x20,
	_HisCCMAlg_ImageBuffer_BitDepth_F64	=	0x40
};

enum _HisCCMAlg_ImageBuffer_Type{
	_HisCCMAlg_ImageBuffer_Type_BGGR8			=	0x1,
	_HisCCMAlg_ImageBuffer_Type_RGGB8			=	0x2,
	_HisCCMAlg_ImageBuffer_Type_GRBG8			=	0x3,
	_HisCCMAlg_ImageBuffer_Type_GBRG8			=	0x4,
	_HisCCMAlg_ImageBuffer_Type_BGGR10		=	0x11,
	_HisCCMAlg_ImageBuffer_Type_RGGB10		=	0x12,
	_HisCCMAlg_ImageBuffer_Type_GRBG10		=	0x13,
	_HisCCMAlg_ImageBuffer_Type_GBRG10		=	0x14,
	_HisCCMAlg_ImageBuffer_Type_YUV422_U8	=	0x21,
	_HisCCMAlg_ImageBuffer_Type_RGB24			=	0x31,
	_HisCCMAlg_ImageBuffer_Type_Y_U8			= 0x41,
	_HisCCMAlg_ImageBuffer_Type_Y_U16			= 0x42,
	_HisCCMAlg_ImageBuffer_Type_Y_F32			= 0x43
};

enum _HisCCMAlg_ImageBuffer_Channel{
	_HisCCMAlg_ImageBuffer_Channel_Y			=	0x0,
	_HisCCMAlg_ImageBuffer_Channel_Gr			=	0x1, 
	_HisCCMAlg_ImageBuffer_Channel_Gb			=	0x2,
	_HisCCMAlg_ImageBuffer_Channel_R			=	0x3,
	_HisCCMAlg_ImageBuffer_Channel_B			=	0x4,
	_HisCCMAlg_ImageBuffer_Channel_U			=	0x5,
	_HisCCMAlg_ImageBuffer_Channel_V			=	0x6
};

enum _HisCCMAlg_Rolongo_Chart{
	_HisCCMAlg_Rolongo_Chart_MTF_A			=	0x10,
	_HisCCMAlg_Rolongo_Chart_MTF_B			=	0x11,
	_HisCCMAlg_Rolongo_Chart_SFR_A			=	0x20,
	_HisCCMAlg_Rolongo_Chart_LP_A				=	0x30
};

enum _HisCCMAlg_Rolongo_AFA_Tactics{
	_HisCCMAlg_Rolongo_AFA_Tactics_CCW_PASS		=	0x00,
	_HisCCMAlg_Rolongo_AFA_Tactics_CCW_BEST		=	0x01
};

enum _HisCCM_EnvironmentType{
	_EnvironmentType_Mtf						=	0x01, 
	_EnvironmentType_Sfr						=	0x02,
	_EnvironmentType_Tvline						=	0x03,
	_EnvironmentType_WhitePanel					=	0x04,
	_EnvironmentType_Blackboard					=	0x05,
	_EnvironmentType_Error						=	0X06

};

enum _His_CCM_SaveImage_Src{
	_His_CCM_SaveImage_Src_ImageBuffer	=	0,
	_His_CCM_SaveImage_Src_ImageArea	=	1,
	_His_CCM_SaveImage_Src_AppArea		=	2,
	_His_CCM_SaveImage_Src_ScreenArea	=	3
};

enum _His_CCM_SaveImage_Type{
	_His_CCM_SaveImage_Type_Raw8			=	0,
	_His_CCM_SaveImage_Type_Raw10		=	1,
	_His_CCM_SaveImage_Type_BMP			=	2,
	_His_CCM_SaveImage_Type_JPEG			=	3,
	_His_CCM_SaveImage_Type_PNG			=	4,
	_His_CCM_SaveImage_Type_Raw12		=	5
};

enum _HisVision_Frame_Format{
	_HisVision_Frame_Format_Mono8		=	0,
	_HisVision_Frame_Format_Mono10	=	1,
	_HisVision_Frame_Format_Mono12	=	2,
	_HisVision_Frame_Format_RGB888	=	3
};

struct _HisCamera_Frame_Descripte{
	unsigned __int8 *pucbuffer;	
	int iiwidthpixel;
	int iheightpixel;
	int iwidthbyte;
	_HisVision_Frame_Format ucformat; //picture format
};

union _haob32{
	float flvalue;
	__int32 i32value;
	unsigned __int32 u32value;
	unsigned __int16 u16value[2];
	__int16 i16value[2];
	unsigned char u8value[4];
	char i8value[4];
};

union _haob64{
	double dflvalue;
	unsigned __int64 u64value;
	__int64 i64value;
	float flvalue[2];
	__int32 ivalue[2];
	unsigned __int32 uivalue[2];
	unsigned __int16 u16value[4];
	__int16 i16value[4];
	unsigned char u8value[8];
	char i8value[8];
};

struct _HisCCMAlg_RECT_FOV2{
	RECT stBlocks[2];
};

struct _HisCCMAlg_RECT_FOV4{
	RECT stBlocks[4];
	_HisCCMAlg_RECT_FOV4()
	{
		memset(stBlocks, 0, sizeof(RECT) *4);
	}
};

struct _HisCCMAlg_RECT_FOV8{
	RECT stBlocks[8];
};

struct _HisCCMAlg_Resolution{
	float flValue;
	unsigned char ucOrientation; //0-水平 1-垂直 
};

struct _HisCCMAlg_LPBasic_Info{
	float flWHRatio; //线对宽高比
	float flGradeMultiple;
	unsigned short usFOVDisDev;  //寻找线对时的误差
	unsigned short usConstLPWMin; //线对长边最少PIXEL数量
	unsigned short usConstLPWMax; //线对长边最多PIXEL数量
	unsigned short usConstLPHMin; //线对短边最少PIXEL数量
	unsigned short usConstLPHMax; //线对短边最多PIXEL数量
	unsigned short usConstMarkPMin; //黑块MARK点边长最少PIXEL数量
	unsigned short usConstMarkPMax; //黑块MARK点边长最多PIXEL数量
	double dflConstMarkFMin;	//黑块MARK点FOV最小值
	double dflConstMarkFMax;	//黑块MARK点FOV最大值
	double dflConstMarkAngle; //黑块MARK点角度
	unsigned short usConstExpandW; //在原有的基础上长边扩展多少像素, 单边
	unsigned short usConstExpandH; //在原有的基础上短边扩展多少像素, 单边
	unsigned char ucFrames;
	_HisCCMAlg_LPBasic_Info()
	{
		flWHRatio					=	4.0f;
		usFOVDisDev				=	100;
		usConstLPWMin			=	100;
		usConstLPWMax			=	300;
		usConstLPHMin			=	10;
		usConstLPHMax			=	60;
		usConstMarkPMin		=	40;
		usConstMarkPMax		=	90;
		dflConstMarkFMin	=	0.4;
		dflConstMarkFMax	=	0.9;
		dflConstMarkAngle	=	45.0;
		usConstExpandW		=	0;
		usConstExpandH		=	3;
		flGradeMultiple				=	1.2f;
		ucFrames					=	1;
	}
};

struct _HisCCMAlg_LPItem_Info{
	bool bBlock4;
	unsigned char ucConstLPNum; //CHART上的线对数-6
	unsigned char ucConstThresholdB8; //8bit 位深阀值
	float flFOV; 
	float flAngle;
	float flWeight;  //权重比
	float flSpecHor; //水平规格
	float flSpecVec; //垂直规格
	float flSpecUniform;
	float flValueOffset;
	unsigned short usLPMax;
	unsigned short usLPMin;
	float flSpecHor_GradeB; //水平规格
	float flSpecVec_GradeB; //垂直规格
	float flSpecUniform_GradeB;
	float flSpecHor_GradeC; //水平规格
	float flSpecVec_GradeC; //垂直规格
	float flSpecUniform_GradeC;
	float flSpecHor_GradeD; //水平规格
	float flSpecVec_GradeD; //垂直规格
	float flSpecUniform_GradeD;
	float flSpecHor_GradeE; //水平规格
	float flSpecVec_GradeE; //垂直规格
	float flSpecUniform_GradeE;
	_HisCCMAlg_LPItem_Info()
	{
		bBlock4		=	true;
		ucConstLPNum			=	6;
		ucConstThresholdB8	=	20;
		flFOV			=	0.7f;
		flAngle		=	0.0f;
		flWeight	=	0.1f;
		flSpecHor	=	700.0f;
		flSpecVec	=	700.0f;
		usLPMin		=	400;
		usLPMax		=	1100;
		flSpecUniform	=	1000.0f;
		flValueOffset	=	0.0f;
		flSpecHor_GradeB=flSpecHor_GradeC=flSpecHor_GradeD=flSpecHor_GradeE=700.0f;
		flSpecVec_GradeB=flSpecVec_GradeC=flSpecVec_GradeD=flSpecVec_GradeE=700.0f;
		flSpecUniform_GradeB=flSpecUniform_GradeC=flSpecUniform_GradeD=flSpecUniform_GradeE=1000.0f;
	}
};

struct _HisCCMAlg_AFA_LP_DataItem_FOV{
	unsigned char ucStatus;
	_HisCCMAlg_Resolution stLpValue[4];
	float flUniformValue;
	float flSpecHor; //第一优先级
	float flSpecVec;
	float flSpecUniform;
	float flWeight;
	float flFOV;
	float flAngle;
	
	_HisCCMAlg_AFA_LP_DataItem_FOV()
	{
		ucStatus	=	0x0; //0x0-FAIL 0x1-PASS
		memset(stLpValue, 0, sizeof(_HisCCMAlg_Resolution)*4);
		flWeight	=	0.1f;
		flSpecHor	=	0.2f;
		flSpecVec	=	0.2f;
		flSpecUniform	=	0.1f;
		flFOV	=	0.3f;
		flAngle	=	0.0f;
	}
};

struct _HisCCMAlg_AFA_LP_DataItem{
	unsigned char ucStatus;
	float flWeightValue;
	unsigned int uiMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflAbsAngle;
	std::vector<_HisCCMAlg_AFA_LP_DataItem_FOV> vectorFOV;
	_HisCCMAlg_AFA_LP_DataItem()
	{
		ucStatus			=	0x0; //0x0-FAIL 0x1-PASS
		flWeightValue	=	0.0f;
		dflAbsAngle		=	0.0;
		uiMarkDistance	=	0;
	}
};

//正角度--CCW  负角度--CW

struct _HisCCMAlg_AFA_Tactics_Basic{
	bool bRTacticsForMark;
	bool bDataBase; //是否使用数据库调焦策略
	unsigned short usMaxSteps;
	unsigned short usStepDelay;
	unsigned char ucChartType; //_HisCCMAlg_Rolongo_Chart
	unsigned char ucTactics; //_HisCCMAlg_Rolongo_AFA_Tactics
	unsigned char ucValueChoose; //0-最大值 1-最小值 2-平均值 3-中值
	unsigned char ucValueTypeChoose; //0-中心 1-权重 2-加uniform权重
	unsigned short usConstMarkTarget; //清晰时MARK点距离
	unsigned short usConstMarkOffset; //(usConstMarkTarget-usConstMarkOffset, usConstMarkTarget+usConstMarkOffset)范围内不使用MARK点策略
	double dflConstAnglePerMarkPixel;
	float flConstMaxAngleCCW; //最大反旋角度
	float flConstMaxAngleCW; //最大正旋角度
	float flConstMaxMarkDis; //最大MARK点距离
	float flConstMinMarkDis; //最小MARK点距离
	unsigned char cucMaxVNodeNum;
	unsigned char ucVNodeNum;
	float flVNode[9];
	float flVAngle[9];
	bool bUpCheck; //是否调焦环抬起做CHECK
	float flUpDistace;
	float flUpValueDiff;
	bool bUnderSpin;
	float flUnderSpinAngle;
	float flUnderSpinDValueMin;
	float flUnderSpinDValueMax;
	float fl1stCWAngle;
	int iUpReadValue; //>0 调焦环脱离模组再计算解析力
	
	_HisCCMAlg_AFA_Tactics_Basic()
	{
		bDataBase	=	false;
		bRTacticsForMark	=	false;
		ucValueChoose	=	0;
		ucValueTypeChoose	=	0;
		ucVNodeNum		=	4;
		cucMaxVNodeNum		=	9;
		usMaxSteps	=	10;
		usStepDelay	=	500;
		ucChartType	=	_HisCCMAlg_Rolongo_Chart_LP_A;
		ucTactics		=	_HisCCMAlg_Rolongo_AFA_Tactics_CCW_PASS;
		memset(flVNode, 0, sizeof(float) *9);
		memset(flVAngle, 0, sizeof(float) *9);
		usConstMarkTarget	=	200;
		usConstMarkOffset	=	50;
		dflConstAnglePerMarkPixel	=	0.1;
		bUpCheck	=	true;
		flUpDistace	=	1.0f;
		flUpValueDiff	=	0.05f;
		flConstMaxAngleCCW	=	360.0f;
		flConstMaxAngleCW		=	360.0f;
		bUnderSpin	=	false;
		flUnderSpinAngle	=	30.0;
		flUnderSpinDValueMin	=	0.1f;
		flUnderSpinDValueMax	=	0.7f;
		fl1stCWAngle	=	80.0f;
		iUpReadValue	=	0;
		flConstMaxMarkDis	=	-1.0f;
		flConstMinMarkDis	=	-1.0f;
	}
};

struct _HisCCMAlg_AFA_Tractics_CCW_PASS{	
	float flLastAngleOffset;
	_HisCCMAlg_AFA_Tractics_CCW_PASS()
	{	
		flLastAngleOffset	=	0.0f;
	}
};

struct _HisCCMAlg_AFA_Tractics_CCW_BEST{
	float flMinPeakDef;
	float flMinCurveDownDef;
	float flLastAngleOffset;
	_HisCCMAlg_AFA_Tractics_CCW_BEST()
	{
		flMinPeakDef			=	600.0f;
		flMinCurveDownDef	=	200.0f;
		flLastAngleOffset	=	0.0f;
	}
};

enum _HisCCMAlg_Rolongo_AFC_Tactics{
	_HisCCMAlg_Rolongo_AFC_Tactics_PASS				=	0x00,
	_HisCCMAlg_Rolongo_AFC_Tactics_PEAK				=	0x01,
	_HisCCMAlg_Rolongo_AFC_Tactics_Linear			=	0x02,
	_HisCCMAlg_Rolongo_AFC_Tactics_Single			=	0x03,
	_HisCCMAlg_Rolongo_AFC_Tactics_Inflexion		=	0x04,
	_HisCCMAlg_Rolongo_AFC_Tactics_Fitting			=	0x05
};

struct _HisCCMAlg_AFC_Tactics_Basic{
	bool bDataBase;
	bool bLinearBack;
	bool bTestStartMotor;
	unsigned short usMaxSteps;
	unsigned short usStepDelay;
	unsigned char ucChartType; //_HisCCMAlg_Rolongo_Chart
	unsigned char ucTactics; //_HisCCMAlg_Rolongo_AFC_Tactics
	unsigned char ucValueChoose; //0-最大值 1-最小值 2-平均值 3-中值
	unsigned char ucValueTypeChoose; //0-中心 1-权重 2-加uniform权重
	short sMotorStart;
	short sMotorEnd;
	short sMotorSpecMin;
	short sMotorSpecMax;
	unsigned char ucBigStep;
	unsigned char ucMiddleStep;
	unsigned char ucSmallStep;
	float flCurveFalloffDef;
	float flCurveValidDef;
	float flStraightDevMax;
	float flStartMotorDevDef;
	short sStartMotorMin;
	short sStartMotorMax;
	bool bMark;
	bool bXYReversal;
	float flMTFBMarkRangeX;
	float flMTFBMarkRangeY;
	float flMTFBMarkRangeYMax;
	float flMTFBMarkTargetDis;
	bool bCurveFitting;
	
	_HisCCMAlg_AFC_Tactics_Basic()
	{
		bCurveFitting =bTestStartMotor = bLinearBack	=	false;
		bDataBase		=	true;
		usMaxSteps	=	1;
		usStepDelay	=	500;
		ucChartType	=	_HisCCMAlg_Rolongo_Chart_MTF_A;
		ucTactics		=	_HisCCMAlg_Rolongo_AFC_Tactics_Single;
		ucValueChoose	=	3;
		ucValueTypeChoose	=	0;
		sStartMotorMin = sMotorSpecMin =  sMotorStart	=	0;
		sMotorSpecMax = sMotorSpecMax = sMotorEnd		=	1023;
		ucBigStep		=	20;
		ucMiddleStep	=	10;
		ucSmallStep		=	5;
		flCurveFalloffDef	=	300.0f;
		flCurveValidDef		=	600.0f;
		flStraightDevMax	=	0.1f;
		flStartMotorDevDef	=	0.05f;
		bMark=false;
		bXYReversal=false;
		flMTFBMarkRangeX	=	0.3f;
		flMTFBMarkRangeY	=	0.25f;
		flMTFBMarkRangeYMax	=	0.7f;
	}
};

struct _HisCCMAlg_AFC_LP_DataItem_FOV{
	unsigned char ucStatus;
	_HisCCMAlg_Resolution stLpValue[4];
	RECT stValueLine[4];
	RECT stMaxLine[4];
	RECT stMinLine[4];
	RECT stBlock[4];
	float flUniformValue;
	float flSpecHor; //第一优先级
	float flSpecVec;
	float flSpecUniform;
	float flWeight;
	float flFOV;
	float flAngle;

	float flSpecHor_GradeB; //水平规格
	float flSpecVec_GradeB; //垂直规格
	float flSpecUniform_GradeB;
	float flSpecHor_GradeC; //水平规格
	float flSpecVec_GradeC; //垂直规格
	float flSpecUniform_GradeC;
	float flSpecHor_GradeD; //水平规格
	float flSpecVec_GradeD; //垂直规格
	float flSpecUniform_GradeD;
	float flSpecHor_GradeE; //水平规格
	float flSpecVec_GradeE; //垂直规格
	float flSpecUniform_GradeE;
	
	_HisCCMAlg_AFC_LP_DataItem_FOV()
	{
		ucStatus	=	0x0; //0x0-FAIL 0x1-PASS
		memset(stLpValue, 0, sizeof(_HisCCMAlg_Resolution)*4);
		memset(stValueLine, 0, sizeof(RECT) *4);
		memset(stMinLine, 0, sizeof(RECT) *4);
		memset(stMaxLine, 0, sizeof(RECT) *4);
		memset(stBlock, 0, sizeof(RECT) *4);
		flWeight	=	0.1f;
		flSpecHor	=	0.2f;
		flSpecVec	=	0.2f;
		flSpecUniform	=	0.1f;
		flFOV	=	0.3f;
		flAngle	=	0.0f;

		flSpecHor_GradeB=flSpecHor_GradeC=flSpecHor_GradeD=flSpecHor_GradeE=700.0f;
		flSpecVec_GradeB=flSpecVec_GradeC=flSpecVec_GradeD=flSpecVec_GradeE=700.0f;
		flSpecUniform_GradeB=flSpecUniform_GradeC=flSpecUniform_GradeD=flSpecUniform_GradeE=1000.0f;
	}
};

struct _HisCCMAlg_AFC_LP_DataItem{
	unsigned char ucStatus; 
	unsigned char ucFlag; //_HisCCMAlg_Rolongo_AFC_Tactics_Linear 0-上升 1-下降
												//_HisCCMAlg_Rolongo_AFC_Tactics_PEAK  1-PEAk点
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflAbsAngle;
	short sMotorStep;
	std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV> vectorFOV;
		
	_HisCCMAlg_AFC_LP_DataItem()
	{
		ucFlag			=	0;
		ucStatus			=	0x0; //0x0-FAIL 0x1-PASS
		flWeightValue	=	0.0f;
		sMotorStep		=	0;
		dflMarkDistance	=	0.0;
		dflAbsAngle	=	0.0;
	}
};

struct _HisCCMAlg_AFC_LP_DB_Item{
	unsigned char ucStatus; //0-not use 1-used
	unsigned __int64 ui64ID;
	short sMotorStart;
	float flMarkDisStart;
	short sMotorEnd;
	float flMarkDisEnd;
	std::vector<float> vecValueStart;
	std::vector<float> vecValueEnd;
	
	_HisCCMAlg_AFC_LP_DB_Item()
	{
		ucStatus		=	0;
		ui64ID			=	0;
		sMotorStart	=	0;
		flMarkDisStart	=	0.0f;
		sMotorEnd	=	0;
		flMarkDisEnd	=	0.0f;
	}
};

struct _HisCCMAlg_AFC_Linear_Item{
	unsigned char ucFlag; //0-上升 1-下降
	int iMotor;
	float flValue;
};

struct _HisCCMAlg_AFC_Linear_Result{
	bool bLinearBack;
	bool bTestStartMotor;
	float flStartMotorDevDef;
	int iStartMotorMin;
	int iStartMotorMax;
	
	bool bResult;
	int iStartMotor;
	
	std::vector<_HisCCMAlg_AFC_Linear_Item> vectorItemData;
	_HisCCMAlg_AFC_Linear_Result()
	{
		bLinearBack = bTestStartMotor = bResult	=	false;
		iStartMotor	=	0x00FFFFFF;
	}
};

struct _HisCCMAlg_AFC_LP_DB{
	unsigned short usConstMaxItem;
	unsigned __int64 ui64IDMax;
	_HisCCMAlg_AFC_Tactics_Basic* pstTacticsBasic;
	_HisCCMAlg_LPBasic_Info* pstLpBasic;
	std::vector<_HisCCMAlg_LPItem_Info> vectorLpItemInfo;
	std::vector<_HisCCMAlg_AFC_LP_DB_Item> vectorItem;
		
	void initial()
	{
		ui64IDMax				=	0;
		usConstMaxItem	=	4000;
		if(pstTacticsBasic != NULL) {delete pstTacticsBasic; pstTacticsBasic = NULL;}
		if(pstLpBasic != NULL) {delete pstLpBasic; pstLpBasic = NULL;}
		vectorLpItemInfo.clear();
		vectorItem.clear();
	}
		
	_HisCCMAlg_AFC_LP_DB()
	{
		pstTacticsBasic	=	NULL;
		pstLpBasic			=	NULL;
		initial();
	}
	
	~_HisCCMAlg_AFC_LP_DB()
	{
		initial();
	}
};

struct _HisCCMAlg_ImageBuffer{
	void* pvImgBuf;
	int iImgWidth;
	int iImgHeight;
	_HisCCMAlg_ImageBuffer_Type enumFormat;
	_HisCCMAlg_ImageBuffer_Channel enumChannel; 
	
	_HisCCMAlg_ImageBuffer()
	{
		pvImgBuf		=	NULL;
		iImgWidth		=	0;
		iImgHeight	=	0;
		enumFormat	=	_HisCCMAlg_ImageBuffer_Type_RGB24;
		enumChannel	=	_HisCCMAlg_ImageBuffer_Channel_Y;
	}
};

struct _HisAlg_Shading_HA_Config{
	float flRatioW; //ROI长比例
	float flRatioH; //ROI宽比例
	_HisCCMAlg_ImageBuffer_Channel imgChannel; //用于计算的通道
	float flShadingSpecMin; //暗角最小值
	float flShadingSpecMax; //暗角最大值
	float flShadingSpecDev; //暗角之间的差异
	_HisAlg_Shading_HA_Config()
	{
		flRatioW		=	0.2f;
		flRatioH		=	0.2f;
		imgChannel	=	_HisCCMAlg_ImageBuffer_Channel_Gr;
		flShadingSpecMin	=	50.0f;
		flShadingSpecMax	=	90.0f;
		flShadingSpecDev	=	5.0f;
	}
};

struct _HisAlg_Shading_HA_Data{
	bool bResult;
	float flLT;
	float flRT;
	float flLB;
	float flRB;
	float flDev;
	RECT stROI[5]; //LT, RT, LB, RB, Center
	_HisAlg_Shading_HA_Data()
	{
		bResult	=	false;
		flLT		=	0.0f;
		flRT		=	0.0f;
		flLB		=	0.0f;
		flRB		=	0.0f;
		flDev		=	0.0f;
		memset(stROI, 0, sizeof(RECT) *5);
	}
};

struct _HisAlg_Shading_HB_Config{
	float flSpecRGMin;
	float flSpecRGMax;
	float flSpecBGMin;
	float flSpecBGMax;
	float flSpecPPMin;
	float flSpecPPMax;
	float flShadingSpecMin; //暗角最小值
	float flShadingSpecMax; //暗角最大值
	float flShadingSpecDev; //暗角之间的差异
	float flRGOffset;
	float flBGOffset;
	float flPPOffset;
	float flYYOffset;
	_HisAlg_Shading_HB_Config()
	{
		flShadingSpecMin	=	50.0f;
		flShadingSpecMax	=	90.0f;
		flShadingSpecDev	=	5.0f;
		flSpecRGMin				=	-1.0f;
		flSpecRGMax				=	5.0f;
		flSpecBGMin				=	-1.0f;
		flSpecBGMax				=	5.0f;
		flSpecPPMin				=	-1.0f;
		flSpecPPMax				=	5.0f;
		flRGOffset = flBGOffset = flPPOffset = flYYOffset = 0.0f;
	}
};

struct _HisAlg_Shading_HB_Data{
	bool bResult;
	float Y;
	float RG;
	float BG;
	float PP;
	float Y_0;
	float Y_6;
	float Y_42;
	float Y_48;
	float flSaturationR;
	float flSaturationG;
	float flSaturationB;
	RECT stROI[49];
	_HisAlg_Shading_HB_Data()
	{
		bResult	=	false;
		Y =RG	=BG	=PP	=Y_0 =Y_6 =Y_42 =Y_48 =flSaturationR =flSaturationG =flSaturationB= 	0.0f;
		memset(stROI, 0, sizeof(RECT)*49);
	}
};

struct _HisAlg_Vignetting_HA_Config{
	unsigned int uiROIW; //第一层ROI宽(pixel)
	unsigned int uiROIH; //第一层ROI高(pixel)
	_HisCCMAlg_ImageBuffer_Channel imgChannel; //用于计算的通道
	float flSpecR2Min; //R1 / R2最小值
	float flSpecR2Max; //R1 / R2最大值
	float flSpecR3Min; //R1 / R3最小值
	float flSpecR3Max; //R1 / R3最大值
	_HisAlg_Vignetting_HA_Config()
	{
		uiROIW =uiROIH	=	32;
		imgChannel	=	_HisCCMAlg_ImageBuffer_Channel_Y;
		flSpecR2Min =flSpecR3Min	=	0.9f;
		flSpecR2Max =flSpecR3Max	=	1.1f;
	}
};

struct _HisAlg_Vignetting_HA_Data{
	bool bResult;
	float flLTR2; //LT R1 /R2数据
	float flLTR3;
	float flRTR2;
	float flRTR3;
	float flLBR2;
	float flLBR3;
	float flRBR2;
	float flRBR3;
	float flLTR2_R; //R-LT R1 /R2数据
	float flLTR3_R;
	float flRTR2_R;
	float flRTR3_R;
	float flLBR2_R;
	float flLBR3_R;
	float flRBR2_R;
	float flRBR3_R;
	float flLTR2_G; //G-LT R1 /R2数据
	float flLTR3_G;
	float flRTR2_G;
	float flRTR3_G;
	float flLBR2_G;
	float flLBR3_G;
	float flRBR2_G;
	float flRBR3_G;
	float flLTR2_B; //B-LT R1 /R2数据
	float flLTR3_B;
	float flRTR2_B;
	float flRTR3_B;
	float flLBR2_B;
	float flLBR3_B;
	float flRBR2_B;
	float flRBR3_B;
	_HisAlg_Vignetting_HA_Data()
	{
		bResult	=	false;
		flLTR2 =flLTR3 =flRTR2 =flRTR3 =flLBR2 =flLBR3 =flRBR2 =flRBR3 =	0.0f;
		flLTR2_R =flLTR3_R =flRTR2_R =flRTR3_R =flLBR2_R =flLBR3_R =flRBR2_R =flRBR3_R	=	0.0f;
		flLTR2_G =flLTR3_G =flRTR2_G =flRTR3_G =flLBR2_G =flLBR3_G =flRBR2_G =flRBR3_G	=	0.0f;
		flLTR2_B =flLTR3_B =flRTR2_B =flRTR3_B =flLBR2_B =flLBR3_B =flRBR2_B =flRBR3_B	=	0.0f;
	}
};

struct _SFRBlackROI4{
	RECT stLeft;
	RECT stRight;
	RECT stTop;
	RECT stBottom;
	float flAngle;
};

enum _His_SFR_Method{
	_His_SFR_Method_MTF50		=	0,
	_His_SFR_Method_2Freq		=	1
};

struct _HisCCMAlg_SFRPlusHABasic_Info{
	bool b2ndFreq; //ucMethod == _His_SFR_Method_2Freq 使用2个分频
	bool bOnlyInner;
	unsigned char ucGradeCount;
	unsigned char uc1stFreq; //第一频率
	unsigned char uc2ndFreq;	//第二频率
	unsigned char ucAlg;	//算法A
	unsigned char ucMethod;	//_His_SFR_Method
	unsigned char ucChannel;
	unsigned char ucMinCantrast;
	unsigned short usFOVOffset;
	unsigned short usMarkSideMin;
	unsigned short usMarkSideMax;
	int iROIWidth;
	int iROIHeght;
	float flCenterWeight;
	float flCenterMTF50SpecH;
	float flCenterMTF50SpecV;
	float flCenterMTF50GradeBH;
	float flCenterMTF50GradeBV;
	float flCenterMTF50GradeCH;
	float flCenterMTF50GradeCV;
	float flCenterMTF50GradeDH;
	float flCenterMTF50GradeDV;
	float flCenterMTF50GradeEH;
	float flCenterMTF50GradeEV;
	float flCenter1stFreqSpecH;
	float flCenter1stFreqSpecV;
	float flCenter2ndFreqSpecH;
	float flCenter2ndFreqSpecV;
	float flGradeMultiple;
	_HisCCMAlg_SFRPlusHABasic_Info()
	{
		bOnlyInner			=	false;
		b2ndFreq				=	false;
		ucChannel				=	_HisCCMAlg_ImageBuffer_Channel_Y;
		uc1stFreq				=	4;
		uc2ndFreq				=	8;
		ucMinCantrast		=	10;
		iROIWidth				=	32;
		iROIHeght				=	64;
		flCenterWeight	=	1.0f;
		usFOVOffset			=	100;
		flCenterMTF50SpecH =flCenterMTF50SpecV =flCenter1stFreqSpecH =flCenter1stFreqSpecV =flCenter2ndFreqSpecH =flCenter2ndFreqSpecV =0.5f;
		usMarkSideMin		=	60;
		usMarkSideMax		=	200;
		flGradeMultiple			=	1.2f;
		ucGradeCount			=	3;
	}
};

struct _HisCCMAlg_SFRPlusHAItem_Info{
	unsigned char ucBlockCount;
	float flFOV;
	float flAngle;
	float flWeight;
	float flMTF50SpecH;
	float flMTF50SpecV;
	float flMTF50GradeBH;
	float flMTF50GradeBV;
	float flMTF50GradeCH;
	float flMTF50GradeCV;
	float flMTF50GradeDH;
	float flMTF50GradeDV;
	float flMTF50GradeEH;
	float flMTF50GradeEV;
	float fl1stFreqSpecH;
	float fl1stFreqSpecV;
	float fl2ndFreqSpecH;
	float fl2ndFreqSpecV;
	float flMTF50SpecUnifH;
	float flMTF50SpecUnifV;
	float fl1stFreqSpecUnifH;
	float fl1stFreqSpecUnifV;
	float fl2ndFreqSpecUnifH;
	float fl2ndFreqSpecUnifV;
	_HisCCMAlg_SFRPlusHAItem_Info()
	{
		ucBlockCount				=	4;
		flFOV								=	0.7f;
		flAngle							=	45.0f;
		flWeight						=	0.0f;
		flMTF50SpecH =flMTF50SpecV =fl1stFreqSpecH =fl1stFreqSpecV =fl2ndFreqSpecH =fl2ndFreqSpecV =0.5f;
		flMTF50SpecUnifH =flMTF50SpecUnifV =fl1stFreqSpecUnifH =fl1stFreqSpecUnifV= fl2ndFreqSpecUnifH =fl2ndFreqSpecUnifV =0.1f;
	}
};

struct _HisCCMAlg_SFRPlusHA_Block_Result{
	float flValueH_L;
	float flValueH_R;
	float flValueV_T;
	float flValueV_B;
	_HisCCMAlg_SFRPlusHA_Block_Result()
	{
		flValueH_L = flValueH_R = flValueV_T = flValueV_B = 0.0f;
	}
};

struct _HisCCMAlg_AFC_SFRHA_DataItem_FOV{
	unsigned char ucStatus;
	unsigned char ucBlockCount;
	float flFOV;
	float flAngle;
	float flWeight;
	float flMTF50SpecH;
	float flMTF50SpecV;
	float fl1stFreqSpecH;
	float fl1stFreqSpecV;
	float fl2ndFreqSpecH;
	float fl2ndFreqSpecV;
	float flMTF50SpecUnifH;
	float flMTF50SpecUnifV;
	float fl1stFreqSpecUnifH;
	float fl1stFreqSpecUnifV;
	float fl2ndFreqSpecUnifH;
	float fl2ndFreqSpecUnifV;

	_SFRBlackROI4 stBlock[4];
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRMTF50[4]; //顺时针
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRFreq1[4]; //顺时针
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRFreq2[4]; //顺时针
	float flMTF50UnifH;
	float flMTF50UnifV;
	float flFreq1UnifH;
	float flFreq1UnifV;
	float flFreq2UnifH;
	float flFreq2UnifV;

	_HisCCMAlg_AFC_SFRHA_DataItem_FOV()
	{
		ucBlockCount	=	4;
		ucStatus	=	0x0; //0x0-FAIL 0x1-PASS
		flMTF50UnifH =flMTF50UnifV =0.0f;
	}
};

struct _HisCCMAlg_AFC_SFRHA_DataItem{
	bool b2ndFreq; //ucMethod == _His_SFR_Method_2Freq 使用2个分频
	unsigned char ucMethod;	//_His_SFR_Method
	unsigned char ucStatus; 
	unsigned char ucFlag; //_HisCCMAlg_Rolongo_AFC_Tactics_Linear 0-上升 1-下降
												//_HisCCMAlg_Rolongo_AFC_Tactics_PEAK  1-PEAk点
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflAbsAngle;
	short sMotorStep;

	float flCenterWeight;
	float flCenterMTF50SpecH;
	float flCenterMTF50SpecV;
	float flCenter1stFreqSpecH;
	float flCenter1stFreqSpecV;
	float flCenter2ndFreqSpecH;
	float flCenter2ndFreqSpecV;
	
	_SFRBlackROI4 stCenterBlock;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterMTF50;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq1;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq2;
	
	std::vector<_HisCCMAlg_AFC_SFRHA_DataItem_FOV> vectorFOV;
		
	_HisCCMAlg_AFC_SFRHA_DataItem()
	{
		ucFlag					=	0;
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		flWeightValue		=	0.0f;
		sMotorStep			=	0;
		dflMarkDistance	=	0.0;
		dflAbsAngle	=	0.0;
	}
};

struct _HisCCMAlg_AFC_SFRHA_DB_Item{
	unsigned char ucStatus; //0-not use 1-used
	unsigned __int64 ui64ID;
	short sMotorStart;
	float flMarkDisStart;
	short sMotorEnd;
	float flMarkDisEnd;
	std::vector<float> vecValueStart;
	std::vector<float> vecValueEnd;
	
	_HisCCMAlg_AFC_SFRHA_DB_Item()
	{
		ucStatus		=	0;
		ui64ID			=	0;
		sMotorStart	=	0;
		flMarkDisStart	=	0.0f;
		sMotorEnd	=	0;
		flMarkDisEnd	=	0.0f;
	}
};

struct _HisCCMAlg_AFC_SFRHA_DB{
	unsigned short usConstMaxItem;
	unsigned __int64 ui64IDMax;
	_HisCCMAlg_AFC_Tactics_Basic* pstTacticsBasic;
	_HisCCMAlg_SFRPlusHABasic_Info* pstSFRBasic;
	std::vector<_HisCCMAlg_SFRPlusHAItem_Info> vectorSFRItem;
	std::vector<_HisCCMAlg_AFC_SFRHA_DB_Item> vectorItem;
		
	void initial()
	{
		ui64IDMax				=	0;
		usConstMaxItem	=	4000;
		if(pstTacticsBasic != NULL) {delete pstTacticsBasic; pstTacticsBasic = NULL;}
		if(pstSFRBasic != NULL) {delete pstSFRBasic; pstSFRBasic = NULL;}
		vectorSFRItem.clear();
		vectorItem.clear();
	}
	
	_HisCCMAlg_AFC_SFRHA_DB()
	{
		pstTacticsBasic	=	NULL;
		pstSFRBasic			=	NULL;
		initial();
	}
	
	~_HisCCMAlg_AFC_SFRHA_DB()
	{
		initial();
	}
};

struct _HisCCMAlg_MTFBasic_Info{
	bool bAutoSeartchROI;
	unsigned int algswitch;
	int iblockwith;
	int iblockheight;
	float flcenterweight;
	float flcenterspec;
	float flGradeMultiple;
	unsigned char ucGrade;
	float flCenterGradeD;
	float flCenterGradeC;
	float flCenterGradeB;
	float flCenterGradeE;

	float flHcenterspec;
	float flVcenterspec;

	_HisCCMAlg_MTFBasic_Info()
	{
		bAutoSeartchROI = false;
		iblockwith	=	iblockheight	=	200;
		flcenterweight		=	1.0f;
		flCenterGradeE =flCenterGradeB =flCenterGradeC =flCenterGradeD =flcenterspec = 0.5f;
		algswitch	=	_HisCCM_AlgID_MTF_hao_a;
		ucGrade		=	6;
		flGradeMultiple	=	1.2f;
	}
};


struct _HisCCMAlg_MTFBasic_Info_EX{
	bool bAutoSeartchROI;
	unsigned int algswitch;
	int iblockwith;
	int iblockheight;
	float flcenterweight;
	float flcenterspec;
	float flGradeMultiple;
	unsigned char ucGrade;
	float flCenterGradeD;
	float flCenterGradeC;
	float flCenterGradeB;
	float flCenterGradeE;

	float flHcenterspec;
	float flVcenterspec;
	
	_HisCCMAlg_MTFBasic_Info_EX()
	{
		bAutoSeartchROI = false;
		iblockwith	=	iblockheight	=	200;
		flcenterweight		=	1.0f;
		flCenterGradeE =flCenterGradeB =flCenterGradeC =flCenterGradeD =flcenterspec = 0.5f;
		algswitch	=	_HisCCM_AlgID_MTF_hao_a;
		ucGrade		=	6;
		flGradeMultiple	=	1.2f;
	}
};

struct _HisCCMAlg_MTFItem_Info{
	unsigned char ucBlockCount;
	float flFOV; 
	float flAngle;
	float flWeight;  //权重比
	float flSpec;
	float flSpecUniform;
	float flGradeD;
	float flGradeC;
	float flGradeB;
	float flGradeE;

	float flHSpec;//*********** 2018.04.11 fengqiquan Add *************
	float flVSpec;//*********** 2018.04.11 fengqiquan Add *************
	
	_HisCCMAlg_MTFItem_Info()
	{
		ucBlockCount	=	4;
		flFOV					=	0.7f;
		flAngle				=	45.0f;
		flGradeD =flGradeC =flGradeB =flGradeE =flSpec =	0.5f;
		flSpecUniform	=	0.5f;
	}
};

struct _HisCCMAlg_AFC_MTF_DB_Item{
	unsigned char ucStatus; //0-not use 1-used
	unsigned __int64 ui64ID;
	short sMotorStart;
	float flMarkDisStart;
	short sMotorEnd;
	float flMarkDisEnd;
	std::vector<float> vecValueStart;
	std::vector<float> vecValueEnd;
	
	_HisCCMAlg_AFC_MTF_DB_Item()
	{
		ucStatus		=	0;
		ui64ID			=	0;
		sMotorStart			=	sMotorEnd			=	0;
		flMarkDisStart	=	flMarkDisEnd	=	0.0f;
	}
};

struct _HisCCMAlg_AFC_MTF_DB{
	unsigned short usConstMaxItem;
	unsigned __int64 ui64IDMax;
	_HisCCMAlg_AFC_Tactics_Basic* pstTacticsBasic;
	_HisCCMAlg_MTFBasic_Info* pstMTFBasic;
	std::vector<_HisCCMAlg_MTFItem_Info> vectorMTFItem;
	std::vector<_HisCCMAlg_AFC_MTF_DB_Item> vectorItem;
		
	void initial()
	{
		ui64IDMax				=	0;
		usConstMaxItem	=	4000;
		if(pstTacticsBasic != NULL) {delete pstTacticsBasic; pstTacticsBasic = NULL;}
		if(pstMTFBasic != NULL) {delete pstMTFBasic; pstMTFBasic = NULL;}
		vectorMTFItem.clear();
		vectorItem.clear();
	}
	
	_HisCCMAlg_AFC_MTF_DB()
	{
		pstTacticsBasic	=	NULL;
		pstMTFBasic			=	NULL;
		initial();
	}
	
	~_HisCCMAlg_AFC_MTF_DB()
	{
		initial();
	}
};

struct _HisCCMAlg_AFC_MTF_DataItem_FOV{
	unsigned char ucStatus;
	unsigned char ucBlockCount;
	float flFOV;
	float flAngle;
	float flWeight;
	float flSpec;
	float flSpecUniform;
	float flUniformValue;
	float flGradeD;
	float flGradeC;
	float flGradeB;
	float flGradeE;
	float flValue[4];
	RECT stBlock[4];

	_HisCCMAlg_AFC_MTF_DataItem_FOV()
	{
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		ucBlockCount		=	4;
		flUniformValue	=	0.0f;
	}
};

/*
struct _HisCCMAlg_AFC_MTF_DataItem_FOV{
	unsigned char ucStatus;
	unsigned char ucBlockCount;
	float flFOV;
	float flAngle;
	float flWeight;
	float flSpec;
	float flSpecUniform;
	float flUniformValue;
	float flGradeD;
	float flGradeC;
	float flGradeB;
	float flGradeE;
	float flValue[4];
	//float flHValue[4];   // MTF Horizontal Value
	//float flVValue[4];	 // MTF Vertical Value
	RECT stBlock[4];

	_HisCCMAlg_AFC_MTF_DataItem_FOV()
	{
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		ucBlockCount		=	4;
		flUniformValue	=	0.0f;
	}
};
*/
struct _HisCCMAlg_AFC_MTF_DataItem{
	unsigned char ucStatus; 
	unsigned char ucFlag; //_HisCCMAlg_Rolongo_AFC_Tactics_Linear 0-上升 1-下降
												//_HisCCMAlg_Rolongo_AFC_Tactics_PEAK  1-PEAk点
	unsigned char ucGrade;
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflAbsAngle;
	short sMotorStep;
	float flCenterWeight;
	float flCenterSpec;
	float flCenterGradeD;
	float flCenterGradeC;
	float flCenterGradeB;
	float flCenterGradeE;
	float flCenterValue;
	RECT stCenterBlock;
	std::vector<_HisCCMAlg_AFC_MTF_DataItem_FOV> vectorFOV;
		
	_HisCCMAlg_AFC_MTF_DataItem()
	{
		ucFlag					=	0;
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		flWeightValue		=	0.0f;
		sMotorStep			=	0;
		dflMarkDistance	=	0.0;
		dflAbsAngle	=	0.0;
	}
};

//********************* 2018/04/11 fengqiquan ***********************
struct _HisCCMAlg_AFC_MTF_DataItem_FOV_EX{
	unsigned char ucStatus;
	unsigned char ucBlockCount;
	float flFOV;
	float flAngle;
	float flWeight;
	float flSpec;
	float flSpecUniform;
	float flUniformValue;
	float flGradeD;
	float flGradeC;
	float flGradeB;
	float flGradeE;
	float flValue[4];
	RECT stBlock[4];
	float flHValue[4];   // MTF Horizontal Value
	float flVValue[4];	 // MTF Vertical Value

	_HisCCMAlg_AFC_MTF_DataItem_FOV_EX()
	{
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		ucBlockCount		=	4;
		flUniformValue	=	0.0f;
	}
};

struct _HisCCMAlg_AFC_MTF_DataItem_EX{
	unsigned char ucStatus; 
	unsigned char ucFlag; //_HisCCMAlg_Rolongo_AFC_Tactics_Linear 0-上升 1-下降
	//_HisCCMAlg_Rolongo_AFC_Tactics_PEAK  1-PEAk点
	unsigned char ucGrade;
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflAbsAngle;
	short sMotorStep;
	float flCenterWeight;
	float flCenterSpec;
	float flCenterGradeD;
	float flCenterGradeC;
	float flCenterGradeB;
	float flCenterGradeE;
	float flCenterValue;
	RECT stCenterBlock;
	std::vector<_HisCCMAlg_AFC_MTF_DataItem_FOV_EX> vectorFOV;
	float flHCenterValue;
	float flVCenterValue;

	_HisCCMAlg_AFC_MTF_DataItem_EX()
	{
		ucFlag					=	0;
		ucStatus				=	0x0; //0x0-FAIL 0x1-PASS
		flWeightValue		=	0.0f;
		sMotorStep			=	0;
		dflMarkDistance	=	0.0;
		dflAbsAngle	=	0.0;
	}
};

//*******************************************************************

struct _HisAutoFA_Rolongo_DataItem{
	unsigned char ucStatus;  //0x0-FAIL 0x1-PASS 0x2-OK2 0xFF-undefined
	unsigned char ucDirect; //0x0-CCW 0x1-CW 0x2-DB 0xFF-第一点
	unsigned char ucGrade;
	unsigned char ucType; //b7:1 通过精确定位  b6:1 通过模糊定位  b5:1 已反向 
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflRadius;
	double dflLesnAngle;
	double dflLaser;
	double dflAbsAngle;
	
	float flMTFCenterWeight;
	float flMTFCenterSpec;
	float flMTFCenterValue;
	RECT stMTFCenterBlock;
	
	bool bSFR2ndFreq; //ucMethod == _His_SFR_Method_2Freq 使用2个分频
	unsigned char ucSFRMethod;	//_His_SFR_Method
	float flSFRCenterWeight;
	float flSFRCenterMTF50SpecH;
	float flSFRCenterMTF50SpecV;
	float flSFRCenter1stFreqSpecH;
	float flSFRCenter1stFreqSpecV;
	float flSFRCenter2ndFreqSpecH;
	float flSFRCenter2ndFreqSpecV;
	_SFRBlackROI4 stSFRCenterBlock;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterMTF50;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq1;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq2;
	
	std::vector<_HisCCMAlg_AFC_MTF_DataItem_FOV> vectorMTFFOV;
	std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV> vectorLPFOV;
	std::vector<_HisCCMAlg_AFC_SFRHA_DataItem_FOV> vectorSFRFOV;
};

struct _HisAutoFA_Rolongo_DataItem_EX{
	unsigned char ucStatus;  //0x0-FAIL 0x1-PASS 0x2-OK2 0xFF-undefined
	unsigned char ucDirect; //0x0-CCW 0x1-CW 0x2-DB 0xFF-第一点
	unsigned char ucGrade;
	unsigned char ucType; //b7:1 通过精确定位  b6:1 通过模糊定位  b5:1 已反向 
	float flWeightValue;
	double dflMarkDistance; //MARK点之间的对角线距离 0--MARK点未找到
	double dflRadius;
	double dflLesnAngle;
	double dflLaser;
	double dflAbsAngle;

	float flMTFCenterWeight;
	float flMTFCenterSpec;
	float flMTFCenterSpec_H;
	float flMTFCenterSpec_V;
	float flMTFCenterValue;
	float flMTFCenterValue_H;
	float flMTFCenterValue_V;
	RECT stMTFCenterBlock;

	bool bSFR2ndFreq; //ucMethod == _His_SFR_Method_2Freq 使用2个分频
	unsigned char ucSFRMethod;	//_His_SFR_Method
	float flSFRCenterWeight;
	float flSFRCenterMTF50SpecH;
	float flSFRCenterMTF50SpecV;
	float flSFRCenter1stFreqSpecH;
	float flSFRCenter1stFreqSpecV;
	float flSFRCenter2ndFreqSpecH;
	float flSFRCenter2ndFreqSpecV;
	_SFRBlackROI4 stSFRCenterBlock;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterMTF50;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq1;
	_HisCCMAlg_SFRPlusHA_Block_Result stSFRCenterFreq2;

	std::vector<_HisCCMAlg_AFC_MTF_DataItem_FOV_EX> vectorMTFFOV;
	std::vector<_HisCCMAlg_AFC_LP_DataItem_FOV> vectorLPFOV;
	std::vector<_HisCCMAlg_AFC_SFRHA_DataItem_FOV> vectorSFRFOV;
};


struct _HisAutoFA_BASIC_STACTICS{ //CW：负数 CCW：正数
	bool bConfigValid;
	unsigned char uclensleafs; //lens花瓣个数
	unsigned char ucclaw;	 //调焦环爪子个数
	double dfllensIncludedAngle;	//lens夹角
	double dflringIncludedAngle; //调焦环夹角
	double dfllenspitch; //mm / circle
	
	unsigned char ucTactics; //0-最优点  1-PASS退出
	unsigned char ucDirection; //0-反旋调焦 1-从当前位置调焦
	unsigned char ucChartType;
	unsigned char ucValueChoose; //0-最大值 1-最小值 2-平均值 3-中值
	unsigned char ucValueTypeChoose; //0-中心 1-权重 2-加uniform权重
	unsigned char ucSFRAMarkBlockCount;
	bool bDataBase;
	bool bUseMark;
	bool bUseLaser;
	bool bVision;
	float flOK2Percent;
	float flDBAngleOffset;
	float fltoBestAngOffset; //回到最优点时OFFSET角度
	bool bXYReversal;
	float flMTFBMarkRangeX;
	float flMTFBMarkRangeY;
	float flMTFBMarkRangeYMax;
	
	bool bUpCheckEveryStep;
	float flEveryUpDis;
	
	unsigned short ussteplimit; //max focus adjust steps
	unsigned short usoperatedelay; //image delay after every lens adjust
	float flConstMaxAngleCW;
	float flConstMaxAngleCCW;
	float flConstLaserMin;
	float flConstLaserMax;
	float flConstMarkDisMin;
	float flConstMarkDisMax;
	float flConstPeakDefValue;
	float flConstPeakDefFall;
	
	unsigned char uc1stCWMode; //0-不下旋 1-固定下旋 2-LASER下旋
	float fl1stCWAngle;
	float fl1stCWLaser;
	
	bool bUpCheck; //是否调焦环抬起做CHECK
	float flUpValueDiff;
	unsigned int uiUnderSpinAngle;
	float flUnderSpinDValueMin;
	float flUnderSpinDValueMax;
	
	unsigned char ucLastRetryTime;
	float flLastRetryAngle;
	
	unsigned char cucMaxVNodeNum;
	unsigned char ucVNodeNum;
	float flVNode[9];
	float flVAngle[9];

#ifdef USE_AFC_Fitting
	double dflMarkMinArea;
	double dflMarkMaxArea;
	double dflMarkMinLength;
	double dflMarkMaxLength;
	double dflMarkTargetDistance;
	double dflMarkStepDistance;
#endif

	_HisAutoFA_BASIC_STACTICS()
	{
		bXYReversal	=	false;
		ucSFRAMarkBlockCount	=	0;
		bConfigValid	=	false;
		uclensleafs	=	ucclaw	=	3;
		dfllensIncludedAngle	=	60;
		dflringIncludedAngle	=	45;
		dflringIncludedAngle	=	0.25;
		cucMaxVNodeNum	=	9;
		flOK2Percent	=	1.2f;
		flMTFBMarkRangeX	=	0.3f;
		flMTFBMarkRangeY	=	0.25f;
		flMTFBMarkRangeYMax	=	0.7f;
		flUpValueDiff	=	0.05f;
		
		memset(flVNode, 0, sizeof(float) *9);
		memset(flVAngle, 0, sizeof(float) *9);

#ifdef USE_AFC_Fitting
		dflMarkMinArea = 10000;
		dflMarkMaxArea = 35000;
		dflMarkMinLength=800;
		dflMarkMaxLength=1200;
		dflMarkTargetDistance=1060.0f;
		dflMarkStepDistance=0.33f;
#endif

	}
};

struct _HisAutoFA_Rolongo_DB_Item{
	unsigned char ucStatus; //0-not use 1-used
	unsigned __int64 ui64ID;
	float flMarkDisStart;
	float flMarkDisEnd;
	float flLaser;
	float flLensRadius;
	float flLensAngle;
	float flRotateAngle;
	float flAnglePerPixel;
	std::vector<float> vecValueStart;
	std::vector<float> vecValueEnd;
		
	_HisAutoFA_Rolongo_DB_Item()
	{
		ucStatus		=	0;
		ui64ID			=	0;
		flLaser = flMarkDisEnd = flMarkDisStart	=	0.0f;
		flLensRadius =flLensAngle =flRotateAngle =flAnglePerPixel =0.0f;
	}
};

struct _HisAutoFA_Rolongo_DB{
	unsigned short usConstMaxItem;
	unsigned __int64 ui64IDMax;
	_HisAutoFA_BASIC_STACTICS* pstTacticsBasic;
	_HisCCMAlg_SFRPlusHABasic_Info* pstSFRBasic;
	std::vector<_HisCCMAlg_SFRPlusHAItem_Info> vectorSFRItem;
	_HisCCMAlg_LPBasic_Info* pstLpBasic;
	std::vector<_HisCCMAlg_LPItem_Info> vectorLpItemInfo;
	_HisCCMAlg_MTFBasic_Info* pstMTFBasic;
	std::vector<_HisCCMAlg_MTFItem_Info> vectorMTFItem;
	std::vector<_HisAutoFA_Rolongo_DB_Item> vectorDataItem;
		
	void initial()
	{
		ui64IDMax				=	0;
		usConstMaxItem	=	8000;
		if(pstTacticsBasic != NULL) {delete pstTacticsBasic; pstTacticsBasic = NULL;}
		if(pstSFRBasic != NULL) {delete pstSFRBasic; pstSFRBasic = NULL;}
		if(pstLpBasic != NULL) {delete pstLpBasic; pstLpBasic = NULL;}
		if(pstMTFBasic != NULL) {delete pstMTFBasic; pstMTFBasic = NULL;}
		vectorDataItem.clear();
		vectorSFRItem.clear();
		vectorLpItemInfo.clear();
		vectorMTFItem.clear();
	}
	
	_HisAutoFA_Rolongo_DB()
	{
		pstTacticsBasic = NULL;
		pstSFRBasic			=	NULL;
		pstLpBasic			=	NULL;
		pstMTFBasic			=	NULL;
		initial();
	}
	
	~_HisAutoFA_Rolongo_DB()
	{
		initial();
	}
};

struct _AutoFA_YIOUV1_EQUI_VALUE{
	double dflLaserValue;
	double dflLensRadius;
	double dflLensAngle;
	
	void clear()
	{
		dflLensRadius	=	_HisAlg_InvalidValueDefine_Double_0;
		dflLaserValue	=	_HisAlg_InvalidValueDefine_Double_999999;
		dflLensAngle	=	_HisAlg_InvalidValueDefine_Double_999999;
	}
	
	_AutoFA_YIOUV1_EQUI_VALUE()
	{
		clear();
	}
};

struct _AutoFA_YIOUV1_EQUI_CONFIG{
	bool bConfigValid;
	//total
	//(speedmain:1.0)(speednext:1.0)(speedz:1.0)(speedu:1.0)(speedzu:1.0)
	double dflSpeedMain;
	double dflSpeedNext;
	double dflSpeedZ;
	double dflSpeedU;
	double dflSpeedZU;
	double dflbigstep;
	double dflsmallstep;
	//camera
	//(offsetnext:0)(offsetmain:0)(offsetz:0)
	//(mmpixelmain:100)(mmpixelnext:100)(idealmain:480)(idealnext:480)
	//(exposure:50000)(match:90)(angleadd:0.0)
	int iCameraOffsetMain;
	int iCameraOffsetNext;
	int iCameraOffsetZ;
	int immpixelMain;
	int immpixelNext;
	int idealCenterMain;
	int idealCenterNext;
	int iThresoldOffset;
	float flAngleBias;
	double dflExposureOffset;
	unsigned int uiexposureTime; //曝光时间
	unsigned char ucmatchThreasold; //匹配阀值
	double dflVisionAngleAdd;

	//laser
	//(offsetmain:0)(offsetnext:0)(offsetz:0)
	//(avergmin:30.0)(avergmax:50.0)
	int iLaserOffsetMain;
	int iLaserOffsetNext;
	double dfldistancemin;	//mm
	double dfldistancemax;
	unsigned short usLaserDelay;

	//fa
	//(offsetmain:0)(offsetnext:0)(offsetz:0)
	//(initangle:0.0)(stressheight:40.0)
	int iFocusOffsetMain;
	int iFocusOffsetNext;
	int iFocusOffsetZ;
	double dflRingInitAngle;	//调焦环预旋角度
	double dflStressHeight;	//压力传感器高度

	//ohter
	//(whiteoffsetmain:0)(whiteoffsetnext:0)(whiteoffsetz:0)
	//(bicodeoffsetmain:0)(bicodeoffsetnext:0)(bicodeoffsetz:0)
	//(blackoffsetmain:0)(blackoffsetnext:0)(nearfcoffsetmain:0)(nearfcoffsetnext:0)
	int iWhitePanelOffsetMain;
	int iWhitePanelOffsetNext;
	int iWhitePanelOffsetZ;
	int iBicodeOffsetMain;
	int iBicodeOffsetNext;
	int iBicodeOffsetZ;
	int iBlackPanelOffsetMain;
	int iBlackPanelOffsetNext;
	int iNearFCOffsetMain;
	int iNearFCOffsetNext;

	_AutoFA_YIOUV1_EQUI_CONFIG()
	{
		dflExposureOffset	=	0.15;
		flAngleBias	=	3.0f;
		iThresoldOffset	=	0;
		bConfigValid = false;
		dflSpeedMain =dflSpeedNext =dflSpeedZ =dflSpeedU =dflSpeedZU =1.0;
		iBlackPanelOffsetMain=iBlackPanelOffsetNext =iNearFCOffsetMain = iNearFCOffsetNext =0;
		uiexposureTime	=	2000;
		dflbigstep		=	1.0;
		dflsmallstep	=	0.1;
		usLaserDelay	=	500;
	}
};

struct _AutoLensTest_EQUI_CONFIG{

     double		dTrayStartX[6]; // A B C D E F
	 double		dTrayStartY[6]; // A B  C D E F
	 double		dTestPostionX;
	 double		dTestpostionY;
	 double    dTestPostionSuck2x;
	 double    dTestPostionSuck2y;
	 double    dStandbyPostionx;
	 double    dStandbyPostiony;
	 double     dZdefaultPos;
	 double		dStartSpeed[3];
	 double		dMaxSpeed[3];
	 double		dStopSpeed[3];
	 double		dSpeedUpTime[3];
	 double		dSpeedCutTime[3];
	 double		dSRangeTime[3];
	 int				TraySize_X;
	 int				TraySize_Y;
	 double		dLensGapX;
	 double		dLensGapY;
	 double		dMoveRelativeSmallStep;
	 double		dMoveRelativeBigStep;
	 double     dSuckMouthXGap;
	 int        iRelayDelayTime;
	 int        iSuckMouthDelayTime;
	 int        iSuckBlowDelayTime;
	 bool    bUsingRelay;
	 double dPCBthickness;
	 double dDisZBasetoLens;
};
struct _HisAlg_Block_TypeA{
	int iX;
	int iY;
	int iWidth;
	int iHeight;
};

typedef void (__stdcall *hardwaresetcommprotocal)(unsigned char);
typedef int (__stdcall *hardwarelvdsspipagewrite)(unsigned char, unsigned int, unsigned int, unsigned char*, unsigned int);

typedef int (__stdcall *hardwarereadiic)(unsigned char, unsigned int, unsigned __int64*, unsigned short);
typedef int (__stdcall *hardwarewriteiic)(unsigned char, unsigned int, unsigned __int64, unsigned short, bool);

typedef int (__stdcall *hardwarebatchreadiic)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short, unsigned short);
typedef int (__stdcall *hardwarebatchwriteiic)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short, unsigned short);

typedef int (__stdcall *hardwarebatchreadiic_v2)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short*, unsigned short);
typedef int (__stdcall *hardwarebatchwriteiic_v2)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short*, unsigned short);

typedef int (__stdcall *hardwarebatchreadiicnolimit)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short*, unsigned short);
typedef int (__stdcall *hardwarebatchwriteiicnolimit)(unsigned int, unsigned char*, unsigned int*, unsigned int*, unsigned short*, unsigned short);

typedef int (__stdcall *hardwarepagewriteiic)(unsigned char, unsigned int, unsigned int, unsigned char*, unsigned int);
typedef int (__stdcall *hardwarepagereadiic)(unsigned char, unsigned int, unsigned int, unsigned char*, unsigned int);

typedef int (__stdcall *hardwarepagewritespi)(unsigned char, unsigned int, unsigned int, unsigned char*, unsigned int, bool, bool);
typedef int (__stdcall *hardwarepagereadspi)(unsigned char, unsigned int, unsigned int, unsigned char*, unsigned int, bool, bool);

typedef int (__stdcall *hardwarereadspi)(unsigned char ucSlave, unsigned int uiReg, unsigned __int64* pui64Data, unsigned short usType, bool bCSLow, bool bLowFirst);
typedef int (__stdcall *hardwarewritespi)(unsigned char ucSlave, unsigned int uiReg, unsigned __int64 ui64Data, unsigned short usType, bool bCSLow, bool bLowFirst);

typedef int (__stdcall *hardwaresetiicspeed)(unsigned short);
typedef int (__stdcall *hardwaregetiicspeed)(unsigned short*);

typedef int (__stdcall *hardwaresetspispeed)(unsigned short);
typedef int (__stdcall *hardwaregetspispeed)(unsigned short*);

typedef int (__stdcall *hardwaresetvolt)(float, float, float, float,float, float, float, unsigned short, float);
typedef int (__stdcall *hardwaregetvolt)(float*, float*, float*, float*, float*, float*, float*);

typedef int (__stdcall *hardwaresetvfuse)(float);
typedef int (__stdcall *hardwaregetvfuse)(float*);

typedef int (__stdcall *hardwaregetframe)(unsigned char*, unsigned int, unsigned char, bool);

typedef int (__stdcall *hardwarepullreset)(bool);
typedef int (__stdcall *hardwarepullpwnd)(bool);

typedef int (__stdcall *hardwaresetmclk)(float);
typedef int (__stdcall *hardwaregetmclk)(float*);

typedef int (__stdcall *hardwaresetlane)(unsigned char);
typedef int (__stdcall *hardwaregetlane)(unsigned char*);

typedef int (__stdcall *hardwaresetdvphsvs)(bool bDVP_VS_ActiveHigh, bool bDVP_HS_ActiveHigh);
typedef int (__stdcall *hardwaregetdvphsvs)(bool* pbDVP_VS_ActiveHigh, bool* pbDVP_HS_ActiveHigh);

typedef int (__stdcall *hardwaresetgpio)(unsigned char, unsigned char, unsigned char, unsigned char, unsigned int);
typedef int (__stdcall *hardwaregetgpio)(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int);

typedef int (__stdcall *hardwaregetslaveresponse)(unsigned char);

typedef bool (__stdcall *softwaregetpreviewflag)();

typedef void (__stdcall *hisfx3logpush_back)(unsigned int, const char*, const char*);

//add By feng 2019-07-15
typedef void (__stdcall *setbulktransformsize)(long bufSize);

//Add By Peng 2017-03-28
typedef int (__stdcall *hardwareGCCheckImageDead)(IN unsigned char *pucdata,IN unsigned int uibuffersize,IN int nTestMode,IN int nImageWidth,IN int nImageHeight,IN int nxOffset,IN int nyOffset,OUT int *nClusterNo,OUT int &iDeadPixelCount,OUT int *DeadX,OUT int *DeadY)  ;




struct _HisCCMOTP_ConfigPair{
	std::string strkey;
	std::string strvalue;
};

struct _HisCCMOTP_Config{
	unsigned char ucEESlave;
	unsigned char ucSlave;
	unsigned int uiBlockSize;
	int iwidth;
	int iheight;
	bool bDebug;
	bool bburn;
	bool bOnlyBurnOnce;
	bool bBlockResult;
	bool bOnlyCheckBurnData;
	bool bBurnOpticalCenter;
	int iOpitcalcenterX;
	int iOpitcalcenterY;
	_HisFX3Platform_FactoryCode uiOEMFactory;
	unsigned int* puiIndex;
	unsigned int uiFrameSleep;
	unsigned int uiDataFormat;
	unsigned int uiMID;
	unsigned int uiLENSID;
	unsigned int uiVCMID;
	unsigned int uiDRIVERICID;
	float flRangeRatio;
	unsigned int uiLuxMin;
	unsigned int uiLuxMax;
	float flLuxResult;
	unsigned int uiDark;
	float flLSC_LuxShadingMin;
	float flLSC_LuxShadingMax;
	float flLSC_LuxShadingUniform;
	float flLSC_LuxShadingResult_GrLT;
	float flLSC_LuxShadingResult_GrRT;
	float flLSC_LuxShadingResult_GrLB;
	float flLSC_LuxShadingResult_GrRB;
	float flLSC_LuxShadingUniformResult_Gr;
	float flLSC_LuxSymmMax;
	float flLSC_LuxSymmMaxResult_Gr;
	float flLSC_LuxSymmMaxResult_Gb;
	float flLSC_LuxSymmMaxResult_R;
	float flLSC_LuxSymmMaxResult_B;
	float flLSC_CenterR2GrMin;
	float flLSC_CenterR2GrMax;
	float flLSC_CenterR2GrResult;
	float flLSC_CenterB2GrMin;
	float flLSC_CenterB2GrMax;
	float flLSC_CenterB2GrResult;
	float flLSC_CenterGb2GrResult;
	float flLSC_WB2CenterMax_R2Gr;
	float flLSC_WB2CenterMax_B2Gr;
	float flLSC_WB2CenterMaxResult_R2Gr;
	float flLSC_WB2CenterMaxResult_B2Gr;
#if 1
	float flWB_CenterChannelR;
	float flWB_CenterChannelGr;
	float flWB_CenterChannelGb;
	float flWB_CenterChannelB;
	float flWB_CenterR2G;
	float flWB_CenterB2G;
	float flWB_CenterGb2Gr;

	float flWB_CenterChannelR_3000K;
	float flWB_CenterChannelGr_3000K;
	float flWB_CenterChannelGb_3000K;
	float flWB_CenterChannelB_3000K;
	float flWB_CenterR2G_3000K;
	float flWB_CenterB2G_3000K;
	float flWB_CenterGb2Gr_3000K;

	float flCLSC_R2G_LT;
	float flCLSC_R2G_RT;
	float flCLSC_R2G_LB;
	float flCLSC_R2G_RB;

	float flCLSC_B2G_LT;
	float flCLSC_B2G_RT;
	float flCLSC_B2G_LB;
	float flCLSC_B2G_RB;

	float flYLSC_LT;
	float flYLSC_RT;
	float flYLSC_LB;
	float flYLSC_RB;
	float flYLSC_Diff;
#endif

	float flR2Gr[121];
	float flB2Gr[121];
	float flGr[121];
	double dflLightCoeB;
	double dflLightCoeR;
	unsigned int uiMachineID;
	unsigned int uiHardwareVersion;
	_haob64 Reserve1; 
	_haob64 Reserve2;
	_haob64 Reserve3;
	_haob64 Reserve4;
	void* pvReserve[6];
	std::string strproject;
	std::string strsensor;
	std::string strSerialNumber;
	std::string strFunctionChoose;
	std::vector<_HisCCMOTP_ConfigPair> vectorPair;
		
	_HisCCMOTP_Config()
	{
		bOnlyCheckBurnData	=	false;
		bBurnOpticalCenter=false;
		iOpitcalcenterX=0;
		iOpitcalcenterY=0;
		flLSC_LuxShadingResult_GrLT	=	-100.0f;
		flLSC_LuxShadingResult_GrRT	=	-100.0f;
		flLSC_LuxShadingResult_GrLB	=	-100.0f;
		flLSC_LuxShadingResult_GrRB	=	-100.0f;
		flLuxResult	=	-100.0f;
		flLSC_LuxShadingUniformResult_Gr	=	-100.0f;
		flLSC_LuxSymmMaxResult_Gr	=	-100.0f;
		flLSC_LuxSymmMaxResult_Gb	=	-100.0f;
		flLSC_LuxSymmMaxResult_R	=	-100.0f;
		flLSC_LuxSymmMaxResult_B	=	-100.0f;
		flLSC_CenterR2GrResult	=	-100.0f;
		flLSC_CenterGb2GrResult	=	-100.0f;
		flLSC_CenterB2GrResult	=	-100.0f;
		flLSC_WB2CenterMaxResult_R2Gr	=	-100.0f;
		flLSC_WB2CenterMaxResult_B2Gr	=	-100.0f;
		uiMachineID	=	uiHardwareVersion	=	0;
		Reserve1.u64value =Reserve2.u64value =Reserve3.u64value= Reserve4.u64value =0;
		memset(pvReserve, 0, sizeof(void*) *6);

#if 1
		flWB_CenterChannelR=0.0f;
		flWB_CenterChannelGr=0.0f;
		flWB_CenterChannelGb=0.0f;
		flWB_CenterChannelB=0.0f;
		flWB_CenterR2G=0.0f;
		flWB_CenterB2G=0.0f;
		flWB_CenterGb2Gr=0.0f;

		flCLSC_R2G_LT=0.0f;
		flCLSC_R2G_RT=0.0f;
		flCLSC_R2G_LB=0.0f;
		flCLSC_R2G_RB=0.0f;

		flCLSC_B2G_LT=0.0f;
		flCLSC_B2G_RT=0.0f;
		flCLSC_B2G_LB=0.0f;
		flCLSC_B2G_RB=0.0f;

		flYLSC_LT=0.0f;
		flYLSC_RT=0.0f;
		flYLSC_LB=0.0f;
		flYLSC_RB=0.0f;
		flYLSC_Diff=0.0f;
#endif
	}
};

struct _HisCCMAFBurn_Config{
	unsigned char ucEESlave;
	unsigned char ucSlave;
	bool bNear;
	bool bMiddle;
	bool bInfinite;
	bool bDebug;
	bool bOnlyBurnOnce;
	int iNearMotor;
	int iMiddleMotor;
	int iInfinitMotor;
	int iwidth;
	int iheight;
	unsigned int uiFrameSleep;
	unsigned int uiDataFormat;
	unsigned int uiMachineID;
	unsigned int uiHardwareVersion;
	_haob64 Reserve1; //ivalue[0]:start current   ivalue[1]:end current
	_haob64 Reserve2;
	_haob64 Reserve3;
	_haob64 Reserve4;
	void* pvReserve[6];
	_HisFX3Platform_FactoryCode uiOEMFactory;
	std::string strproject;
	std::string strsensor;
	std::string strDriverIC;
	std::string strFunctionChoose;
	std::string strSerialNumber;
	std::vector<_HisCCMOTP_ConfigPair> vectorPair;
		
	_HisCCMAFBurn_Config()
	{
		uiMachineID	=	uiHardwareVersion	=	0;
		Reserve1.u64value =Reserve2.u64value =Reserve3.u64value= Reserve4.u64value =0;
		memset(pvReserve, 0, sizeof(void*) *6);
	}
};

struct _HisCCMMTKPDAFBurn_Config{
	unsigned char ucEESlave;
	unsigned char ucSensorSlave;
	bool bDebug;
	bool bSONYIMX258Cal;
	bool bWBVerify;
	unsigned char ucTpye; //1: step1 2: step2 3: step3
	unsigned int uiDataSize;
	unsigned char ucData[2048];
	unsigned int uiStep1Size;
	unsigned int uiStep2Size;
	unsigned int uiStep3Size;
	unsigned int uiMachineID;
	unsigned int uiHardwareVersion;
	_haob64 Reserve1; //version:  u16value[3].u16value[2].u16value[1].u16value[0]
	_haob64 Reserve2;
	_haob64 Reserve3;
	_haob64 Reserve4;
	void* pvReserve[6];
	_HisFX3Platform_FactoryCode uiOEMFactory;
	std::string strproject;
	std::string strsensor;
	std::string strDriverIC;
	std::string strFunctionChoose;
	std::string strSerialNumber;
	std::vector<_HisCCMOTP_ConfigPair> vectorPair;
		
	_HisCCMMTKPDAFBurn_Config()
	{
		bWBVerify =bSONYIMX258Cal	=	false;
		uiStep1Size	=	0;
		uiStep2Size	=	0;
		uiStep3Size	=	0;
		uiMachineID	=	uiHardwareVersion	=	0;
		Reserve1.u64value =Reserve2.u64value =Reserve3.u64value= Reserve4.u64value =0;
		memset(pvReserve, 0, sizeof(void*) *6);
	}
};

struct _HisCCMSONYPDAFBurn_Config{
	unsigned char ucEESlave;
	unsigned char ucSensorSlave;
	bool bDebug;
	unsigned char ucTpye; //1: SPC 2: DCC 
	unsigned int uiSPCSize;
	unsigned int uiDCCSize;
	unsigned short uSPC[512];
	unsigned short uDCC[512];
	_haob64 Reserve1; 
	_haob64 Reserve2;
	_haob64 Reserve3;
	_haob64 Reserve4;
	void* pvReserve[6];
	std::string strproject;
	std::string strsensor;
	std::string strDriverIC;
	std::string strFunctionChoose;
	std::string strSerialNumber;
	std::vector<_HisCCMOTP_ConfigPair> vectorPair;

	_HisCCMSONYPDAFBurn_Config()
	{
		Reserve1.u64value =Reserve2.u64value =Reserve3.u64value= Reserve4.u64value =0;
		memset(pvReserve, 0, sizeof(void*) *6);
	}
};

struct _HisCCMDualCameraBurn_Config
{
	int iwidth;
	int iheight;
	unsigned int uiDataFormat;
	unsigned char ucSlave;
	unsigned char ucEESlave;
	unsigned char ucSensorSlave;
	std::string strproject;
	std::string strsensor;
    std::string strSerialNumber;
	std::string strFunctionChoose;
	bool bDebug;
	bool bBurn;

	unsigned int uiTiltX;  //cvRolongoTiltFunction  
	unsigned int uiTilty;  //cvRolongoTiltFunction  
	unsigned int uiRotation;  //cvRolongoTiltFunction  
	double dAlignment_X;  //cvRolongoCoaxialityCailibrationbySquare 
	double dAlignment_Y;  //cvRolongoCoaxialityCailibrationbySquare 
	double dAlignment_Z;  //cvRolongoCoaxialityCailibrationbySquare 

	unsigned int StartAddr;
	unsigned char CheckSumType; //0: sum%256 1: sum%255

	_HisCCMDualCameraBurn_Config()
	{
		bBurn = false;
		uiTiltX=uiTilty=uiRotation=0;
		dAlignment_X=dAlignment_Y=dAlignment_Z=0.0f;
		CheckSumType =StartAddr = 0x0;
	}
};

struct _HisXWAESyncBurn_Config
{
	int iwidth;
	int iheight;
	unsigned int uiDataFormat;
	unsigned char ucSlave;
	unsigned char ucEESlave;
	std::string strproject;
	std::string strsensor;
	std::string strSerialNumber;
	std::string strFunctionChoose;
	bool bDebug;
	bool bBurn;

	unsigned int MainGain;
	unsigned int MainLineCount;
	unsigned int AuxGain;
	unsigned int AuxLineCount;
	unsigned int LumaRatio;

	unsigned int StartAddr;
	unsigned char CheckSumType; //0: sum%256 1: sum%255

	_HisXWAESyncBurn_Config()
	{
		MainGain = MainLineCount = AuxGain = AuxLineCount = LumaRatio = StartAddr =0;
		CheckSumType = 0;
	}
};

struct _SFRBlackItem{
	POINT stCenter;
	POINT stLeft;
	POINT stRight;
	POINT stTop;
	POINT stBottom;
	float flAngle;
};

struct _HisPlatformAudio_Buffer
{
	int samplerate;
	int channels;
	int sampleSize;
	unsigned char* pucBuf;
	unsigned int uiBufSize;
	unsigned int uiPrivateMollacSize;

	_HisPlatformAudio_Buffer(void)
	{
		pucBuf = 0;
		uiPrivateMollacSize	=uiBufSize	=	0;
	}

	~_HisPlatformAudio_Buffer(void)
	{
		HisReleaseMalloc(pucBuf);
		uiPrivateMollacSize	=uiBufSize	=	0;
	}

	void clear(void)
	{
		HisReleaseMalloc(pucBuf);
		uiPrivateMollacSize	=uiBufSize	=	0;
	}

	void h_malloc(unsigned int uiSize)
	{
		if(uiSize > uiPrivateMollacSize)
		{
			HisReleaseMalloc(pucBuf);
			pucBuf		= (unsigned char*)HisAlignedMalloc(uiSize);
			uiPrivateMollacSize	=	uiSize;
		}
		uiBufSize	=	uiSize;
	}
};

#endif
