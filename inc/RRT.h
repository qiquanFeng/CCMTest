typedef enum RRT_error_t
{
	RRT_SUCCESS							= 0,
	RRT_FAILURE							= -1,
	RRT_FAILURE_CHART_DETECTION			= -2,
	RRT_FAILURE_MONOCHROME_CONVERSION	= -3,
	RRT_FAILURE_DEMOSAICING				= -4,
	RRT_FAILURE_FILE_ALLOCATION			= -21,
	RRT_FAILURE_TEXT_EXPORT				= -22,
	RRT_FAILURE_IMAGE_EXPORT			= -23,
	RRT_MEMORY_ALLOCATION_FAILURE		= -5,
	RRT_TARGET_LOAD_FAILURE				= -19,
	RRT_MISMATCH_RAW_SIZE				= -6,
	RRT_INVALID_RAWFILE					= -7,
	RRT_INVALID_ARGUMENT_VALUE			= -8,
	RRT_INVALID_FEATURE					= -9,
	RRT_INVALID_CONFIG_FILE				= -10,
	RRT_INVALID_BIGMESH					= -11,
	RRT_INVALID_ERROR_CODE				= -12,
	RRT_INVALID_BAYER_METHOD			= -13,
	RRT_INVALID_OPERATION_MODE			= -14,
	RRT_INVALID_FEATURE_MODE			= -15,
	RRT_INVALID_LOG_TYPE				= -16,
	RRT_CHART_NOT_SUPPORTED				= -17, 
	RRT_INVALID_PARAMETER				= -18,
	RRT_FUNCTION_NOT_SUPPORTED			= -20,
} RRT_ERROR;

typedef struct
{
	unsigned int x;
	unsigned int y;
	double       pix_cntrst;
} ChartPixInfo;

typedef struct 
{
	ChartPixInfo lt;
	ChartPixInfo rt;
	ChartPixInfo lb;
	ChartPixInfo rb;
	ChartPixInfo center;
} RRT_Chart_Position;

typedef struct
{
	unsigned int  roiNo;
	unsigned int  fieldNo;     //0= center, 1= 0.3F, 2=0.5F, 3=0.7F, 4=0.9F 
	unsigned int  x;
	unsigned int  y;
	unsigned int  width;
	unsigned int  height;
	int           isPass;
	unsigned int  tvl;
	double        sfr;
} RRT_Result_info;

#define CHART_NO7_ROI_SIZE  52 
#define CHART_NO8_ROI_SIZE  50 
#define CHART_NO11_ROI_SIZE  32 
#define CHART_NO12_ROI_SIZE  24 
#define CHART_NO13_ROI_SIZE  24 
#define CHART_NO14_ROI_SIZE  32 
#define CHART_NO16_ROI_SIZE  32 
#define CHART_NO17_ROI_SIZE  24 
#define CHART_NO40_ROI_SIZE  16 
#define CHART_NO60_ROI_SIZE  20 

extern __declspec(dllexport) int RRT_Checkup_ChartAlign(RRT_Chart_Position *chart_mark);
extern __declspec(dllexport) int RRT_Checkup_ChartAlign(unsigned short *rawUnpacked, RRT_Chart_Position *chart_mark);
extern __declspec(dllexport) int RRT_Run(unsigned char *moduleID);
extern __declspec(dllexport) unsigned short * RRT_get_data_from_RAWfile(char *file_name);
extern __declspec(dllexport) void RRT_release_data(void *mem);
extern __declspec(dllexport) void RRT_list_directory(char *file_extension);

extern __declspec(dllexport) int RRT_Run_GchRAW_point1F(unsigned short *rawUnpacked, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_GchRAW_point1F(RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run(unsigned char *moduleID);
extern __declspec(dllexport) int RRT_Run_n_Get(unsigned char *moduleID, unsigned short *rawUnpacked, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_n_Get(unsigned char *moduleID, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_GchRAW(unsigned short *rawUnpacked, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_GchRAW_Target2nd(unsigned short *rawUnpacked, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_Target2nd(unsigned char *moduleID, unsigned short *rawUnpacked);
extern __declspec(dllexport) int RRT_Run_Target2nd(unsigned char *moduleID);
extern __declspec(dllexport) int RRT_Run_n_Get_Target2nd(unsigned char *moduleID, unsigned short *rawUnpacked, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Run_n_Get_Target2nd(unsigned char *moduleID, RRT_Result_info *out);
extern __declspec(dllexport) int RRT_Set_ConfigurationPath(char *path);
extern __declspec(dllexport) char * RRT_Get_ConfigurationPath(void);