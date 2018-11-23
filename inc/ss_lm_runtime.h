/** 
*   @file ss_lm_runtime.h
*   @brief      Core header for LicenseManagent 、许可管理用的导入所有头文件.
*   @details   许可API用户运行时接口头文件.license runtime api head files
*   
*   history:
*   
*   对于针对Java和Dotnet的DLL封装函数 可以跟静态库不一样，比如 Handle  slm_login(licenseid_json), 可以直接返回登录句柄。
*   slm_keep_alive 是登录后必须要调用，让SS知道APP应用还还活着，没有死机活着被调试。
*   
*   @author    Chen Xiaodong <chenxd@sense.com.cn>
*   @version   0.5
*   @date      2013-2015
*   @bug       参考BUG列表  
*   @pre       开发商证书(深思签发，用来跟SS做认证)、Vdata(APP的信息，用开发商签名)、ECC公钥(端到端认证与加密)需要埋在lib
*   @copyright Bussiness License,商业授权.
*   @bug 
*
*/
#ifndef __SS_LM_RUMTIME_H__
#define __SS_LM_RUMTIME_H__
#include "ss_define.h"
#include "ss_error.h"

#ifdef  _MSC_VER
#pragma comment(linker, "/defaultlib:ws2_32.lib")
#pragma comment(linker, "/defaultlib:iphlpapi.lib")
#pragma comment(linker, "/defaultlib:psapi.lib")
#pragma comment(lib, "rpcrt4.lib")
#endif

#if _MSC_VER >= 1900   // 1900是VS2015的版本号，解决静态库在VS2015下编译失败的问题
#pragma comment(linker, "/defaultlib:legacy_stdio_definitions.lib")
#endif  // MSC_VER

/** 获得锁信息类型枚举  */
typedef enum _INFO_TYPE {
    /**  锁信息  */
    LOCK_INFO = 1,
    /**  会话信息 */
    SESSION_INFO = 2,
    /**  许可信息 */
    LICENSE_INFO  = 3,
	/**  文件列表 */
	FILE_LIST  = 4,
    
} INFO_TYPE;

/** 许可储存区类型枚举  */ 
typedef enum _LIC_USER_DATA_TYPE {
    /** 只读区 */
    ROM = 0,     
    /** 读写区 */
    RAW = 1,
    /** 公开区 */
    PUB = 2,
} LIC_USER_DATA_TYPE;

/** SS 消息处理回掉函数（当前版本 SLM_CALLBACK_VERSION01 )*/
typedef SS_UINT32 (SSAPI *SS_CALL_BACK)(
    SS_UINT32   message,
    void*       wparam,
    void*       lparam
    );

/** 闪灯颜色：蓝色*/
#define LED_COLOR_BLUE      0
/** 闪灯颜色：红色*/
#define LED_COLOR_RED       1

/** 闪灯控制：关闭*/
#define LED_STATE_CLOSE     0
/** 闪灯控制：打开*/
#define LED_STATE_OPEN      1
/** 闪灯控制：闪烁*/
#define LED_STATE_SHRINK    2

/** 闪灯控制结构*/
typedef struct _ST_LED_CONTROL {
    /**  0表示蓝色LED，1表示红色LED  */
    SS_UINT32   index;
    /**  0代表关闭，1代表打开， 2代表闪烁 */
    SS_UINT32   state;
    /**  间隔（毫秒）*/
    SS_UINT32   interval;   
} ST_LED_CONTROL;

//============================================================
//              回调消息 message 类型
//============================================================
/** 消息类型：信息提示*/
#define SS_ANTI_INFORMATION			0x0101
/** 消息类型：警告*/
#define SS_ANTI_WARNING				0x0102
/** 消息类型：异常*/
#define SS_ANTI_EXCEPTION			0x0103
/** 消息类型：暂保留*/
#define SS_ANTI_IDLE				0x0104

/** 服务启动*/
#define SS_MSG_SERVICE_START        0x0200
/** 服务停止*/
#define SS_MSG_SERVICE_STOP         0x0201
/** 锁可用（插入锁或SS启动时锁已初始化完成）回调函数wparam 代表锁号*/
#define SS_MSG_LOCK_AVAILABLE       0x0202
/** 锁无效（锁已拔出）回调函数wparam 代表锁号*/
#define SS_MSG_LOCK_UNAVAILABLE     0x0203


//============================================================
//              回调消息 wparam 参数
//============================================================
/** 发现注入*/
#define SS_ANTI_PATCH_INJECT		0x0201
/** 模块检测失败*/
#define SS_ANTI_MODULE_INVALID		0x0202
/** 发现被调试器附加*/
#define SS_ANTI_ATTACH_FOUND		0x0203
/** 无效的线程*/
#define SS_ANTI_THREAD_INVALID		0x0204
/** 线程检测失败*/
#define SS_ANTI_THREAD_ERROR		0x0205
/** CRC检验失败*/
#define SS_ANTI_CRC_ERROR			0x0206
/** 发现调试器*/
#define SS_ANTI_DEBUGGER_FOUND		0x0207

/** 时钟校准随机数种子长度*/
#define SLM_FIXTIME_RAND_LENGTH     8

/** SS_CALL_BACK的版本 （支持开发商API密码的版本）*/
#define SLM_CALLBACK_VERSION02      0x02

/** 内存托管最大字节*/
#define  SLM_MEM_MAX_SIZE           2048

/** 代码执行，最大输入缓冲区大小（字节）*/
#define SLM_MAX_INPUT_SIZE          1758
/** 代码执行，最大输出缓冲区大小（字节）*/
#define SLM_MAX_OUTPUT_SIZE         1758

/** 加解密最大缓冲区大小（字节）*/
#define SLM_MAX_USER_CRYPT_SIZE     1520

/** 用户数据区最大长度（字节）*/
#define SLM_MAX_USER_DATA_SIZE      2048

/** 用户数据区写入最大长度（字节）*/
#define SLM_MAX_WRITE_SIZE          1904

/** 请求签名的数据前缀*/
#define SLM_VERIFY_DEVICE_PREFIX    "SENSELOCK"

/** 请求签名的数据大小，见slm_sign_by_device*/
#define SLM_VERIFY_DATA_SIZE        41

/** 锁号的长度*/
#define SLM_LOCK_SN_LENGTH          16

/** 开发商ID长度*/
#define SLM_DEVELOPER_ID_SIZE       8

/** 服务器名称最大长度*/
#define SLM_MAX_SERVER_NAME         32

/** 云锁用户token最大长度*/
#define SLM_MAX_ACCESS_TOKEN_LENGTH 64

/** 云锁服务器地址最大长度*/
#define SLM_MAX_CLOUD_SERVER_LENGTH 100

/** 碎片代码种子长度*/
#define SLM_SNIPPET_SEED_LENGTH     32

/** 开发商密码长度*/
#define SLM_DEV_PASSWORD_LENGTH     16

/** 最大用户GUID长度 */
#define SLM_CLOUD_MAX_USER_GUID_SIZE 	        128	

/** 文件类型：数据文件*/
#define SLM_FILE_TYPE_BINARY                    0
/** 文件类型：可执行文件文件*/
#define SLM_FILE_TYPE_EXECUTIVE                 1
/** 文件类型：密钥文件*/
#define SLM_FILE_TYPE_KEY                       2

/** 可读*/
#define SLM_FILE_PRIVILEGE_FLAG_READ            0x01
/** 可写*/
#define SLM_FILE_PRIVILEGE_FLAG_WRITE           0x02
/** （密钥文件）可使用*/
#define SLM_FILE_PRIVILEGE_FLAG_USE             0x04
/** 可远程升级*/
#define SLM_FILE_PRIVILEGE_FLAG_UPDATE          0x08

/** 可读*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_READ      0x10
/** 可写*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_WRITE     0x20
/** （密钥文件）可使用*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_USE       0x40
/** 可远程升级*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_UPDATE    0x80


/** 内存句柄不需要客户维护内存，SS替开发商维护内存，返回一个内存id，范围在0-N之间*/
typedef unsigned int SLM_HANDLE_INDEX; 

/** 自动登录模式*/
#define SLM_LOGIN_MODE_AUTO             0x0000
/** 指定登录本地USE锁*/
#define SLM_LOGIN_MODE_LOCAL            0x0001
/** 指定登录远程USE锁 */
#define SLM_LOGIN_MODE_REMOTE           0x0002
/** 指定登录云锁 */
#define SLM_LOGIN_MODE_CLOUD            0x0004

/** 查找所有的锁，如果发现多个重名许可则不登录，提供选择，否则找到符合条件的锁直接登录*/
#define SLM_LOGIN_FLAG_FIND_ALL         0x0001
/** 指定许可版本*/
#define SLM_LOGIN_FLAG_VERSION          0x0004
/** 指定锁号（USB）*/
#define SLM_LOGIN_FLAG_LOCKSN           0x0008
/** 指定服务器*/
#define SLM_LOGIN_FLAG_SERVER           0x0010
/** 指定碎片代码*/
#define SLM_LOGIN_FLAG_SNIPPET          0x0020


/** 语言ID：简体中文*/
#define LANGUAGE_CHINESE_ASCII                  0x0001
/** 语言ID：英语*/
#define LANGUAGE_ENGLISH_ASCII                  0x0002
/** 语言ID：繁体中文*/
#define LANGUAGE_TRADITIONAL_CHINESE_ASCII      0x0003

/** 表示将收到SS的消息通知*/
#define SLM_INIT_FLAG_NOTIFY            0x01

/** API 初始化参数   */
typedef struct _ST_INIT_PARAM {
    /** 版本－用来兼容，当前使用 SLM_CALLBACK_VERSION02 */
    SS_UINT32       version;
    /** 如果需要接收SS通知，填 SLM_INIT_FLAG_NOTIFY */
    SS_UINT32       flag;
    /** 回调函数指针*/
    SS_CALL_BACK    pfn;
    /** 通信连接超时时间（毫秒），如果填0，则使用默认超时时间（7秒）*/
    SS_UINT32       timeout;
    /** API密码，可从开发者网站上获取*/
    SS_BYTE         password[SLM_DEV_PASSWORD_LENGTH];
} ST_INIT_PARAM;

/** 许可Login 结构*/
typedef struct _ST_LOGIN_PARAM{ 
    /** 结构体大小（必填）*/
    SS_UINT32       size;
    /** 要登录的许可ID*/
    SS_UINT32       license_id;
    /** 许可会话的超时时间（单位：秒）,填0则使用默认值：600秒   */
    SS_UINT32       timeout;
    /** 许可登录的模式：本地，远程，云（见LOGIN_MODE_XXX)，如果填0，则使用SLM_LOGIN_MODE_AUTO*/
    SS_UINT32       login_mode;
    /** 许可登录的标志：见SLM_LOGIN_FLAG_XXX */
    SS_UINT32       login_flag;
    /** 许可登录指定的锁唯一序列号（可选）*/
    SS_BYTE         sn[SLM_LOCK_SN_LENGTH];
    /** 网络锁服务器地址（可选），仅识别IP地址 */
    SS_CHAR         server[SLM_MAX_SERVER_NAME];
    /** 云锁用户token（可选）*/
    SS_CHAR         access_token[SLM_MAX_ACCESS_TOKEN_LENGTH];
    /** 云锁服务器地址（可选）*/
    SS_CHAR         cloud_server[SLM_MAX_CLOUD_SERVER_LENGTH];
    /** 碎片代码种子（可选），如果要支持碎片代码,login_flag需要指定为SLM_LOGIN_FLAG_SNIPPET*/
    SS_BYTE         snippet_seed[SLM_SNIPPET_SEED_LENGTH];
    /** 已登录用户的guid（可选） */
    SS_BYTE         user_guid[SLM_CLOUD_MAX_USER_GUID_SIZE];
} ST_LOGIN_PARAM;


/** 
*   @defgroup group1_lm_runtime  sense shield lm_runtime 深思许可用户运行时库
*   This is sense lm_runtime 深思许可用户运行时库 api声明
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*!
*   @brief      Runtime API初始化函数，调用所有Runtime API必须先调用此函数进行初始化
*   @param[in]  pst_init    初始化参数，见ST_INIT_PARAM结构声明
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see ST_INIT_PARAM
*/
SS_UINT32 SSAPI slm_init(IN ST_INIT_PARAM* pst_init);

/*!
*   @brief      查找许可信息(仅对硬件锁有效)
*   @param[in]  license_id      许可ID
*   @param[in]  format          参数格式，仅支持JSON
*   @param[out] license_desc    许可描述信息的指针，格式由format指定，不再使用时调用slm_free释放
*   @remark     如果成功，需要调用slm_free 释放license_desc
*/
SS_UINT32 SSAPI slm_find_license(
    IN  SS_UINT32           license_id,
    IN  INFO_FORMAT_TYPE    format,
    OUT char**              license_desc
    );


/*!
*   @brief      枚举已登录的用户token
*   @param[out] access_token 默认用户的token，不再使用时，需调用slm_free释放
*   @return     成功返回SS_OK，如果oauth后台进程未启动，则返回SS_ERROR_BAD_CONNECT
*   @remark     如果成功，需要调用slm_free 释放 access_token
*/
SS_UINT32 SSAPI slm_get_cloud_token(OUT SS_CHAR** access_token);

/*!
*   @brief 安全登录许可,用JSON传递参数,并且检查时间（是否到期或者是否早于开始时间）、次数、并发数是否归零，
*          如果有计数器，则永久性减少对应的计数器，对于网络锁则临时增加网络并发计数器。
*   @param[in]  license_param 登录许可描述参数串，可以用来描述licenseid，或者指定特性等。
*   @param[in]  param_format  许可描述字符串类型，支持JSON、STRUCT，建议使用STRUCT
*   @param[out] slm_handle    返回登录之后许可句柄index值,范围在0-256之间。
*   @param[out] auth          认证login函数返回是否正确，含有ECC签名和返回值加密，不使用可以填NULL。
*   @return     SS_UINT32错误码,非0代表失败
*   @remark
*   - slm_login函数详细说明：
*       -# 会自动查找跨锁查找许可句柄。
*       -# 在runtime库里面分配管理内存与进程线程信息。
*       -# 对与调用者需要定期监控会话进程，如果进程死锁或者崩溃，自己释放对应的内存和其它资源。
*       -# LM库属于客户定制自动编译，包含RSA 公钥、认证设备ID、开发商编号等一切认证手段。
*       -# LM后续操作必须都要login之后才能有权限操作 比如读写、加解密等操作。
*   - 功能参数说明：
*       - 采用结构体：
*       -# 参考 ST_LOGIN_PARAM 结构详细描述
*       - 采用JSON，每个JSON参数解释：
*       -# license_id 许可ID，为32位长整数，取值范围0-4294967295，必写参数
*       -# login_mode 许可登录模式，分为自动登录，本地锁登录，只登录远程锁模式，以及云锁模式.("auto", "local", "remote", "cloud")
*       -# sn 指定登录锁号 为16进制字符串（ 16字节锁号）。
*       -# access_token 如果登录云锁，则需要指定通过oauth认证的access token
*       -# time_out 指定登录会话超时 单位为秒。如果不填写，默认为600秒。
*       -# user_guid 登录用户的guid，最大长度为SLM_CLOUD_MAX_USER_GUID_SIZE，一般不填写
*   - 简单参数
*   @code
*       "{"license_id":0}"
*   @endcode
*   - 最复杂参数
*   @code
*       "{"license_id":4294967295,"time_out":86400}"
*   @endcode
*   @code
*   SS_UINT32 ret = SS_OK;
*   SLM_HANDLE_INDEX slm_handle = 0;
*
*   VMProtectBegin("app_slm_login")
*
*   ret = slm_login("{\"license_id\":12345678,\"login_mode\":\"auto\",\"time_out\":600}",JSON,&(slm_handle),NULL);
*
*   if (ret != SS_OK)
*   {
*       printf("license login failed\n");
*   }
*   else
*   {
*       printf("license login ok\n");
*   }
*
*   VMProtectEnd();
*   @endcode
*   @see slm_logout SS_UINT32 INFO_FORMAT_TYPE ST_LOGIN_TEMPLET
*/
SS_UINT32 SSAPI slm_login(
    IN  void*               license_param,
    IN  INFO_FORMAT_TYPE    param_format,
    OUT SLM_HANDLE_INDEX *  slm_handle,
    IN OUT void*            auth
    );

/*!
*   @brief     许可登出，并且释放许可句柄等资源
*   @param[in] slm_handle    许可句柄值
*   @return    SS_UINT32错误码
*   @see       slm_login
*/
SS_UINT32 SSAPI slm_logout(SLM_HANDLE_INDEX slm_handle);

/*!
*   @brief     保持登录会话心跳，避免变为“僵尸句柄”。
*              僵尸句柄：如果进程死循环或者崩溃，slm_handle不会自动被释放，造成slm_runtime库中内存和资源被
*   @param[in] slm_handle    许可句柄值
*   @return    SS_UINT32错误码
*   @see       slm_login
*/
SS_UINT32 SSAPI slm_keep_alive(SLM_HANDLE_INDEX slm_handle);

/*!
*   @brief      许可加密，相同的许可ID相同的开发商加密结果相同
*   @param[in]  slm_handle   许可句柄值
*   @param[in]  inbuffer     加密输入缓冲区,需要16字节对齐 
*   @param[out] outbuffer    加密输出缓冲区,需要16字节对齐 
*   @param[in]  len          加密缓冲区大小，为16字节的整数倍。
*   @return     SS_UINT32错误码
*   @see        slm_encrypt slm_decrypt slm_login
 */
SS_UINT32 SSAPI slm_encrypt(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            inbuffer,
    OUT SS_BYTE*            outbuffer,
    IN  SS_UINT32           len
    );

/*!
*   @brief      许可解密，相同的许可ID相同的开发商加密结果相同
*   @param[in]  slm_handle   许可句柄值
*   @param[in]  inbuffer     解密输入缓冲区,需要16字节对齐 
*   @param[out] outbuffer    解密输出缓冲区,需要16字节对齐 
*   @param[in]  len          加密缓冲区大小，为16字节的整数倍。
*   @return     SS_UINT32错误码
*   @see        slm_encrypt slm_login
 */
SS_UINT32 SSAPI slm_decrypt(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_BYTE*            inbuffer, 
    OUT SS_BYTE*            outbuffer, 
    IN  SS_UINT32           len
    );

/*!
*   @brief      获得许可的数据区大小
*   @param[in]  slm_handle 许可句柄值
*   @param[in]  type       数据区类型，类型定义见 LIC_USER_DATA_TYPE
*   @param[out] pmem_size  数据区大小（填地址）
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        LIC_USER_DATA_TYPE slm_user_data_getsize slm_user_data_read slm_user_data_write
 */
SS_UINT32 SSAPI slm_user_data_getsize(
    IN SLM_HANDLE_INDEX     slm_handle,
    IN LIC_USER_DATA_TYPE   type,
    OUT SS_UINT32*          pmem_size
    );

/*!
*   @brief      读许可数据，可以读取PUB、RAW和ROM
*   @param[in]  slm_handle   许可句柄值
*   @param[in]  type         内存类型，参考LIC_USER_DATA_TYPE
*   @param[out] readbuf      读取缓存区
*   @param[in]  offset       数据偏移
*   @param[in]  len          缓存区大小
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        LIC_USER_DATA_TYPE slm_user_data_getsize slm_user_data_read slm_user_data_write
 */
SS_UINT32 SSAPI slm_user_data_read(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  LIC_USER_DATA_TYPE  type,
    OUT SS_BYTE*            readbuf,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len
    );

/*!
*   @brief     写许可的读写数据区 ,数据区操作之前请先确认内存区的大小，可以使用slm_user_data_getsize获得
*   @param[in] slm_handle      许可句柄值
*   @param[in] writebuf        写缓存区
*   @param[in] offset          写偏移
*   @param[in] len             写长度（数据最大长度 = min(slm_user_data_getsize, SLM_MAX_WRITE_SIZE)
*   @return    成功返回SS_OK，失败返回相应的错误码
*   @see       LIC_USER_DATA_TYPE   slm_user_data_getsize slm_user_data_read slm_user_data_write
 */
SS_UINT32 SSAPI slm_user_data_write(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            writebuf,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len
    );

/*!
*   @brief      获得指定许可的公开区数据区大小，需要登录0号许可
*   @param[in]  slm_handle    0号许可句柄值
*   @param[in]  license_id    指定许可ID
*   @param[out] pmem_size     数据区大小（填地址）
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_user_data_read_pub 
*/
SS_UINT32 SSAPI slm_pub_data_getsize(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_UINT32           license_id,
    OUT SS_UINT32*          pmem_size
    );

/*!
*   @brief      读取许可公开区，需要登录0号许可
*   @param[in]  slm_handle   0号许可句柄值
*   @param[in]  license_id   指定许可ID
*   @param[out] readbuf      读取缓存区
*   @param[in]  offset       数据偏移
*   @param[in]  len          缓存区大小
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @remark     当用户不希望通过登录相应的许可，从而获取到公开区的时候，用户可用通过调用此接口进行获取，前提是需要登录0号许可
*              ，然后将0号许可句柄和要查询公开区的许可ID传入参数，获取该许可的公开区数据。
*   @see        slm_user_data_pub_getsize 
*/
SS_UINT32 SSAPI slm_pub_data_read(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_UINT32           license_id,
    OUT SS_BYTE*            readbuf,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len
    );

/*!
*   @brief 返回具体信息
*   ret = slm_get_info(hslm,ALL_INFO,JSON,result,sizeof(result),&retsize);
*   LOCK_INFO = 1 锁信息  
*   SESSION_INFO = 2 , 会话信息 UPDATE_INFO  升级信息
*   LOCK_INFO信息
*   会话信息
*   @param[in]  slm_handle  许可句柄值
*   @param[in]  type        信息类型 参考 INFO_TYPE,可以为锁信息，许可句柄信息，许可全部信息，升级请求信息等
*   @param[in]  format      信息格式，仅支持JSON
*   @param[out] result      返回结果，如果函数返回成功，需要调用slm_free释放
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @code
*   // JSON 参数说明：
*   - LICENSE_INFO（如果字段不存在，则表示没有该许可限制）
*   {
*     "rom_size" (云锁不支持）
*     "raw_size"（云锁不支持）
*     "pub_size"（云锁不支持）
*     
*     "type": "local"/"remote"/"cloud"
*     "sn":""
*     "developer_id":""
*     "license_id": number
*     "enable": bool
*     "start_time": number
*     "end_time": number
*     "first_use_time": number
*     "span_time": number
*     "counter": number
*     // 并发类型
*     "concurrent_type": "process" / "win_user_session"
*     //并发数
*     "concurrent": number
*     "version": number
*     "last_update_timestamp": number
*     "last_update_timesn": number
*     "lock_time": number
*   }

*   - SESSION_INFO
*   
*   {
*    "app_process_id": number,
*    "app_time_out": number,
*    "session_id":  （只支持云锁）
*    "bios": "BIOS information", （云锁不支持）
*    "cpuinfo": "CPU name", （云锁不支持）
*    "sn": ""(HEX16 String), （云锁不支持）
*    "mac":"00-00-00-00-00-00" （云锁不支持）
*   }
*    
*   - LOCK_INFO
*   {
*    "avaliable_space": number(Bytes),
*    "communication_protocol": number,
*    "lock_firmware_version": "0.0.0.0",
*    "lm_firmware_version": "1.1.1.1",
*    "h5_device_type": number,
*    "hardware_version": "2.2.2.2",
*    "manufacture_date": "2000-01-01 00:00:00",
*    "lock_sn": ""(HEX16 String),
*    "slave_addr": number,
*    "clock": number(UTC Time),
*    "user_info": ""(HEX16 String)(128字节)
*    "inner_info": ""(HEX16 String)(128字节）
*   }
*   
*   - FILE_LIST
*   
*
*   @endcode
*   @see INFO_TYPE INFO_FORMAT_TYPE SLM_HANDLE_INDEX slm_login
*/
SS_UINT32 SSAPI slm_get_info(
    IN  SLM_HANDLE_INDEX	slm_handle,
    IN  INFO_TYPE			type,
    IN  INFO_FORMAT_TYPE	format,
    OUT char**              result
    );

/*!
*   @brief      执行锁内算法，即静态代码执行
*   @param[in]  slm_handle  许可句柄值
*   @param[in]  exfname     锁内执行文件名
*   @param[in]  inbuf       输入缓冲区
*   @param[in]  insize      输入长度
*   @param[out] poutbuf     输出缓存区
*   @param[in]  outsize     输出缓存长度
*   @param[out] pretsize    实际返回缓存长度
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_login slm_execute_dynamic slm_snippet_execute
*/
SS_UINT32 SSAPI slm_execute_static(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  const char*         exfname,
    IN  SS_BYTE*            inbuf,
    IN  SS_UINT32           insize,
    OUT SS_BYTE*            poutbuf,
    IN  SS_UINT32           outsize,
    OUT SS_UINT32*          pretsize
    );

/*!
*   @brief      许可动态执行代码，由开发商API(d2c) gen_dynamic_code生成
*   @param[in]  slm_handle  许可句柄值，由slm_login得到
*   @param[in]  exf_buffer  动态exf算法缓冲区
*   @param[in]  exf_size    动态exf文件大小
*   @param[in]  inbuf       输入缓冲区
*   @param[in]  insize      输入长度
*   @param[out] poutbuf     输出缓存区
*   @param[in]  outsize     输出缓存长度
*   @param[out] pretsize    实际返回缓存长度
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_login slm_execute_static slm_snippet_execute
*/
SS_UINT32 SSAPI slm_execute_dynamic(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            exf_buffer,
    IN  SS_UINT32           exf_size,
    IN  SS_BYTE*            inbuf,
    IN  SS_UINT32           insize,
    OUT SS_BYTE*            poutbuf,
    IN  SS_UINT32           outsize,
    OUT SS_UINT32*          pretsize
    );

/*!
*   @brief      SS内存托管内存申请
*   @param[in]  slm_handle   许可句柄值
*   @param[in]  size         申请大小，最大 SLM_MEM_MAX_SIZE.
*   @param[out] mem_id       返回托管内存id
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_mem_free slm_mem_read slm_mem_write
*/
SS_UINT32 SSAPI slm_mem_alloc(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_UINT32           size, 
    OUT SS_UINT32*          mem_id
    );

/*!
*   @brief     释放托管内存
*   @param[in] slm_handle    许可句柄值
*   @param[in] mem_id        托管内存id
*   @return    成功返回SS_OK，失败返回相应的错误码
*   @see       slm_mem_alloc slm_mem_free slm_mem_read slm_mem_write
*/
SS_UINT32 SSAPI slm_mem_free(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_UINT32           mem_id
    );

/*!
*   @brief      SS内存托管读
*   @param[in]  slm_handle    许可句柄值
*   @param[in]  mem_id        托管内存id
*   @param[in]  offset        读取数据偏移
*   @param[in]  len           读取数据长度
*   @param[out] readbuff      缓存
*   @param[out] readlen       返回实际读的长度
*   @return    成功返回SS_OK，失败返回相应的错误码
*   @see slm_mem_alloc slm_mem_free slm_mem_write
*/
SS_UINT32 SSAPI slm_mem_read(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_UINT32           mem_id,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len,
    IN  SS_BYTE*            readbuff,
    OUT SS_UINT32*          readlen
    );

/*!
*   @brief      SS内存托管内存写入
*   @param[in]  slm_handle    许可句柄值
*   @param[in]  mem_id        托管内存id
*   @param[in]  offset        偏移
*   @param[in]  len           长度
*   @param[in]  writebuff     缓存
*   @param[out] numberofbyteswritten 返回实际写的长度
*   @return     成功返回SS_OK，失败则返回相应的错误码
*   @see slm_mem_alloc slm_mem_free slm_mem_read
*/
SS_UINT32 SSAPI slm_mem_write(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_UINT32           mem_id,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len,
    IN  SS_BYTE*            writebuff,
    OUT SS_UINT32*          numberofbyteswritten
    );

/*!
*   @brief      检测是否正在调试
*   @param[in]  auth     验证数据(保留参数，填NULL即可）
*   @return     SS_UINT32错误码, 返回SS_OK代表未调试
*/
SS_UINT32 SSAPI slm_is_debug(IN void *auth);

/*!
*   @brief      获取锁的设备证书
*   @param[in]  slm_handle  许可句柄
*   @param[out] device_cert 证备证书缓冲区
*   @param[in]  buff_size   缓冲区大小
*   @param[out] return_size 返回的设备证书大小
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_login
*/
SS_UINT32 SSAPI slm_get_device_cert(
    IN  SLM_HANDLE_INDEX    slm_handle,
    OUT SS_BYTE*            device_cert,
    IN  SS_UINT32           buff_size,
    OUT SS_UINT32*          return_size
    );

/*!
*   @brief      设备正版验证
*   @param[in]  slm_handle          许可句柄
*   @param[in]  verify_data         验证数据（必须以字符"SENSELOCK"(9字节)开头）
*   @param[in]  verify_data_size    验证数据大小，大小必须为 SLM_VERIFY_DATA_SIZE(41)个字节
*   @param[out] signature           返回的签名
*   @param[in]  signature_buf_size  缓冲区大小
*   @param[out] signature_size      签名结果大小
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @remarks
*   @see        slm_login
*/
SS_UINT32 SSAPI slm_sign_by_device(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            verify_data,
    IN  SS_UINT32           verify_data_size,
    OUT SS_BYTE*            signature,
    IN  SS_UINT32           signature_buf_size,
    OUT SS_UINT32*          signature_size
    );

/*!
*   @brief         获取时间修复数据，用于生成时钟校准请求
*   @param[in]     slm_handle  许可句柄
*   @param[out]    rand        随机数
*   @param[out]    lock_time   锁时间
*   @param[in,out] pc_time     PC时间，返回的PC时间（传入0则取当时时间）
*   @return        成功返回SS_OK，失败则返回相应错误码
*/
SS_UINT32 SSAPI slm_adjust_time_request(
    IN  SLM_HANDLE_INDEX    slm_handle,
    OUT SS_BYTE             rand[SLM_FIXTIME_RAND_LENGTH],
    OUT SS_UINT32*          lock_time,
    IN OUT SS_UINT32*       pc_time
    );

/*!
*   @brief      闪烁指示灯
*   @param[in]  slm_handle      许可句柄
*   @param[in]  led_ctrl        闪灯控制结构(ST_LED_CONTROL)
*   @return     成功返回SS_OK，失败返回相应的错误码
*   @see        slm_login
*/
SS_UINT32 SSAPI slm_led_control(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  ST_LED_CONTROL*     led_ctrl
    );

/*!
*   @brief      获得runtime库和SS的版本信息.
*   @param[out] api_version  API的版本（总是成功）
*   @param[out] ss_version   SS服务的版本
*   @return     成功返回SS_OK，失败则返回相应的错误码
*/
SS_UINT32 SSAPI slm_get_version(
    OUT SS_UINT32*      api_version, 
    OUT SS_UINT32*      ss_version
    );

/*!
*   @brief     释放API生成的缓冲区
*   @param[in] buffer API生成的缓冲区
*/
void SSAPI slm_free(
    IN void*        buffer
    );

/*!
*   @brief      将D2C包进行升级
*   @param[in]  d2c_pkg     d2c文件数据
*   @param[out] error_msg   错误信息，不使用需要调用slm_free释放
*   @return     成功返回SS_OK，失败返回错误码
*   @remarks:   error_msg的数据内容（JSON）：
*   @code
*   [
*   {"pkg_order":1, "pkg_desc":"package decription.", "status": 0},
*   {"pkg_order":2, "pkg_desc":"package decription.", "status": 0}
*   ]
*   @endcode
*/
SS_UINT32 SSAPI slm_update(
    IN  char*       d2c_pkg, 
    OUT char**      error_msg
    );

/*!
*   @brief      将D2C包进行升级，需指定加密锁唯一序列号
*   @param[in]  lock_sn     锁号（唯一序列号）
*   @param[in]  d2c_pkg     d2c文件数据
*   @param[out] error_msg   错误信息，不使用需要调用slm_free释放
*   @return     成功返回SS_OK，失败返回错误码
*   @remarks:   error_msg的数据内容（JSON）：
*   @code
*   [
*   {"pkg_order":1, "pkg_desc":"package decription.", "status": 0},
*   {"pkg_order":2, "pkg_desc":"package decription.", "status": 0}
*   ]
*   @endcode
*   @see    slm_update
*/
SS_UINT32 SSAPI slm_update_ex(
    IN SS_BYTE*     lock_sn, 
    IN char*        d2c_pkg, 
    OUT char**      error_msg
    );

/*!
*   @brief       枚举本地锁信息
*   @param[out]  device_info    锁信息，不再使用时，需调用slm_free释放
*   @return      成功返回SS_OK，失败返回相应错误码
*   @remark      若调用成功，需要调用slm_free 释放 device_info
*/
SS_UINT32 SSAPI slm_enum_device(
    OUT char**  device_info
    );

/*!
*   @brief     检查模块
*   @param[in] slm_handle     许可句柄
*   @param[in] module_id      模块ID，范围由（1 ~ 64）
*   @return    模块存在返回SS_OK，不存在返回SS_ERROR_LICENSE_MODULE_NOT_EXISTS, 否则返回其它错误码
*/
SS_UINT32 SSAPI slm_check_module(IN SLM_HANDLE_INDEX slm_handle, IN SS_UINT32 module_id);

/*!
*   @brief      碎片代码执行
*   @param[in]  slm_handle      许可句柄
*   @param[in]  snippet_code    碎片代码
*   @param[in]  code_size       碎片代码大小
*   @param[in]  input           输入数据
*   @param[in]  input_size      输入数据长度
*   @param[out] output          输出缓冲区
*   @param[in]  outbuf_size     输出缓冲区长度
*   @param[out] output_size     输出数据长度
*   @see        slm_login slm_execute_static slm_execute_dynamic
*/
SS_UINT32 SSAPI slm_snippet_execute(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            snippet_code,
    IN  SS_UINT32           code_size,
    IN  SS_BYTE*            input, 
    IN  SS_UINT32           input_size, 
    OUT SS_BYTE*            output, 
    IN  SS_UINT32           outbuf_size, 
    OUT SS_UINT32*          output_size
    );

/*!
*   @brief      获取API对应的开发商ID
*   @param[out] developer_id          输出开发商ID
*   @return     成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_get_developer_id(OUT SS_BYTE developer_id[SLM_DEVELOPER_ID_SIZE]);


/*!
*   @brief      通过错误码获得错误信息
*   @param[in]  error_code 错误码
*   @param[in]  language_id 要返回字符串的语言，见 LANGUAGE_CHINESE_ASCII,LANGUAGE_ENGLISH_ASCII,LANGUAGE_TRADITIONAL_CHINESE_ASCII
*   @return     成功返回错误码信息（不需要调用slm_free释放），失败返回空指针NULL 
*/
const SS_CHAR * SSAPI slm_error_format(
    IN SS_UINT32    error_code,
    IN SS_UINT32    language_id
    );

/*!
*   @brief  反初始化函数，与slm_init对应
*   @see    slm_init
*/
SS_UINT32 SSAPI slm_cleanup(void);

/**
*   @}
*/


#ifdef __cplusplus
};
#endif //__cplusplus


#endif // #ifndef __SS_LM_RUMTIME_H__

