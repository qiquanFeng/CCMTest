/** 
*   @file	  ss_lm_control.h
*   @brief     Core header for 许可遍历、SS服务遍历查看等接口
*   @details   枚举所有SS上设备描述符号
*   @author    Chen Xiaodong <chenxd@sense.com.cn>
*   @author    xiaodong Chen <chenxdclear@gmail.com>
*   @version   0.4
*   @bug       参考BUG列表
*   @date      2014
*
*/
#ifndef _H_DEF_SLM_CONTROL_API_
#define _H_DEF_SLM_CONTROL_API_

#include "ss_define.h"

#ifdef  _MSC_VER
#pragma comment(linker, "/defaultlib:setupapi.lib")
#elif defined __WATCOMC__
#pragma library("\watcom\lib386\nt\setupapi.lib")
#endif

#if _MSC_VER >= 1900   // 1900是VS2015的版本号，解决静态库在VS2015下编译失败的问题
#pragma comment(linker, "/defaultlib:legacy_stdio_definitions.lib")
#endif  // MSC_VER

#ifndef __SS_LM_RUMTIME_H__
#define SLM_FIXTIME_RAND_LENGTH     8
#endif


#define SLM_CTRL_LED_COLOR_BLUE      0
#define SLM_CTRL_LED_COLOR_RED       1

#define SLM_CTRL_LED_STATE_CLOSE     0
#define SLM_CTRL_LED_STATE_OPEN      1
#define SLM_CTRL_LED_STATE_SHRINK    2

#define SLM_CTRL_MAX_CLOUD_SERVER_LENGTH    110
#define SLM_CTRL_MAX_ACCESS_TOKEN_LENGTH    63

typedef struct _ST_LOCK_LED_CONTROL {
    SS_UINT32   index;      //  0表示蓝色LED，1表示红色LED
    SS_UINT32   state;      //  0代表关闭，1代表打开， 2代表闪烁
    SS_UINT32   interval;   //  间隔（毫秒）
} ST_LOCK_LED_CONTROL;

/** 
*@defgroup group3_lm_control_API  sense shield lm_control_api 深思管理接口
*This is sense lm_control API 深思管理接口API声明，服务显示当前的许可
*@{
*/
#ifdef __cplusplus
extern "C" {
#endif


//	@breif 取获设备描述，包括本地锁，网络锁及云锁 
// @param[in] ss_client IPC句柄 (slm_client_open) 
//	@param[in] format_type 参数格式（目前只支持JSON) 
// @param[out] out_buf 得到的设备描述符 
// @param[in] max_buf_len 缓冲区长度 
// @param[out] buf_len 得到的out_buf的长度 
// @retval 成功则返回SS_OK，失败返回错误码 
//返回JSON示例：
//{
//  ["type":"local", "computer_name" : "ABC-PC", "lock":
//      {
//          ["sn":"2000000000000120",   
//              "developers" :
//              {
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//              }
//          ]
//          ["sn":2000000000000121", 
//              "developers": 
//              {
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//              }
//          ]
//      }
//  ]
//  ["type":"remote", "computer_name" : "XYZ-PC", "lock" :
//      {
//          ["sn":"2000000000000120", 
//              "developers": 
//              {
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//              }
//          }
//  ["type":"cloud", "computer_name": "cloud_server_name", "user_name":"chenxd@sense.com.cn", "lock":
//      {
//          ["sn":"0000000000000001",
//              "develpers":
//              {
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//                  ["developer_id":"0400000000000000", "developer_desc":{}],
//              }
//          } 
//}

/*!
*   @brief 获取所有SS服务
*   @param[in] ss_client ipc/client句柄
*   @param[in] format_type format_type类型
*   @param[out] out_buf 返回结果
*   @remarks    返回JSON示例：
*   @code
*   ["type":"local", "computer_name" : "ABC-PC", "lock": 
*       [
*          {"sn":"20000000000001202000000000000120",
*              "developers" :
*              {
*                  ["developer_id":"0400000000000000", "developer_desc":{}],
*                  ["developer_id":"0400000000000000", "developer_desc":{}],
*              }
*          }
*      ]
*   ]
*   ["type":"remote", "computer_name" : "XYZ-PC", "lock" :
*       [
*           ["sn":"20000000000001202000000000000120",
*               "developers":
*               {
*                   ["developer_id":"0400000000000000", "developer_desc":{}],
*                   ["developer_id":"0400000000000000", "developer_desc":{}],
*               }
*           ]
*       ]
*   ]
*   ["type":"cloud", "computer_name": "cloud_server_name", "user_name":"chenxd@sense.com.cn", "lock":
*      [
*          ["sn":"00000000000000012000000000000120",
*              "develpers":
*              {
*                  ["developer_id":"0400000000000000", "developer_desc":{}],
*                  ["developer_id":"0400000000000000", "developer_desc":{}],
*              }
*          ]
*       ]
*   ]
*   @endcode
*   @return 错误码
*/
SS_UINT32 SSAPI slm_get_all_server(
    IN  void*               ipc,
    IN  INFO_FORMAT_TYPE    format_type,
    OUT char**              out_buf
    );

/*!
*   @brief 获取所有设备描述
*   @param[in]  ipc     IPC句柄
*   @param[in]  format_type  参数格式
*   @param[out] desc    设备描述
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_get_all_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );

/*!
*   @brief 获取云锁描述
*   @param[in]  ipc         IPC句柄
*   @param[in]  cloud_url   云锁服务器地址（可选）
*   @param[in]  access_token    用户token
*   @param[out] description 描述信息(JSON数组，可以选择其中的一个进行许可查询）
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_get_cloud_description(
    IN  void*               ipc,
    IN  const SS_CHAR*      cloud_url,
    IN  const SS_CHAR*      access_token,
    OUT SS_CHAR**           descriptions
    );

/*!
*   @brief 获取本地设备数组
*   @param[in]  ipc     IPC句柄
*   @param[in]  format_type  参数格式
*   @param[out] desc    设备描述
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_get_local_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );


/*!
*   @brief 获取本地设备数组
*   @param[in]  ipc     IPC句柄
*   @param[in]  format_type  参数格式
*   @param[out] desc    设备描述
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_get_remote_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );


/*!
*   @brief  获取指定设备描述下的所有许可ID
*   @param[in]  ipc     IPC句柄
*   @param[in]  type    参数类型（JSON)
*   @param[in]  param   设备描述
*   @param[out] result  许可ID
*   @return 成功返回SS_OK，失败返回相应的错误码
*   @remarks    返回的JSON结果示例
*   @code
*   [1,2,3,4]
*   @endcode
*   @see    slm_client_open
*/
SS_UINT32 SSAPI slm_get_license_id(
    IN  void *              ipc,
    IN  INFO_FORMAT_TYPE    type,
    IN  const char*         param,
    OUT char**              result
    );

/*!
*   @brief 读取指定锁和开发商下的许可简要信息
*   @param[in] ipc ipc句柄
*   @param[in] type 参数和返回类型（暂只支持JSON）
*   @param[in] param 许可描述
*   @param[out] result 许可信息
*   @return SS_UINT32错误码
*   @remarks
*   返回参数介绍：
*   @code
*   [{"license_id": 1405608497, "enable" : true / false, "start_time" : 1405608497,
*       "end_time" : 1405608497, "first_use_time" : 1405608497, "span_time" : 23234234, 
*       "counter" : 25, "concurrent" : 123, 
*       "concurrent_type" : "win_user_session"（Windows用户会话） / "process"（进程）, // ChenXD
*       "version" : 342512, "last_update_timestamp": 42342525, "last_update_timesn":2342 ,
*       "lock_time" : 23542532
*   }]
*   @endcode
*   @see slm_client_open slm_get_server
*/
SS_UINT32  SSAPI slm_read_brief_license_context(
    IN  void *               ipc,
    IN  INFO_FORMAT_TYPE     type,
    IN  const char *         param,
    OUT char**               result
    );

/*!
*   @brief 读取公开区大小
*   @param[in] ipc          IPC句柄
*   @param[in] license_id   许可ID
*   @param[in] desc         设备描述
*   @param[out] len         返回公开区的大小
*   @return 成功返回SS_OK，否则返回相应的错误码
*   @see slm_read_pub_data
*/
SS_UINT32 SSAPI slm_get_pub_size(
    IN  void*           ipc,
    IN  SS_UINT32       license_id,
    IN  const char*     desc,
    OUT SS_UINT32*      len
    );

/*!
*   @brief 读取用户公开内容
*   @param[in] ipc          IPC句柄
*   @param[in] license_id   许可ID
*   @param[in] desc         设备描述
*   @param[out] readbuf     读取的缓冲区
*   @param[in] offset       读取的偏移
*   @param[in] len          读取的长度
*/
SS_UINT32 SSAPI slm_read_pub_data(
    IN  void*           ipc,
    IN  SS_UINT32       license_id,
    IN  const char*     desc,       //  设备描述
    OUT SS_BYTE*        readbuf,
    IN  SS_UINT32       offset,
    IN  SS_UINT32       len
    );

/*!
*   @brief 获得许可详细信息
*   @param[in] ipc ipc句柄
*   @param[in] type type
*   @param[in]  license_id  许可ID
*   @param[in] desc 设备描述，由slm_get_all_server得到
*   @param[out] result 接收数据的指针，需要调用slm_free释放
*   @return SS_UINT32错误码 
*   @remark 参数同 slm_read_brief_license_context
*/
SS_UINT32 SSAPI slm_read_license_context(
    IN  void *       ipc,
    IN  INFO_FORMAT_TYPE type,
    IN  SS_UINT32    license_id,
    IN  const char * desc,
    OUT char**      result
    );

/*!
*   @brief  获取单个锁的某个开发商下的所有session信息
*   @param[in]  ipc     IPC句柄
*   @param[in]  type    参数类型
*   @param[in]  desc    设备描述符
*   @param[out] result  获取结果的缓冲区
*   @return 如果成功，返回SS_OK，失败返回相应的错误码
*   @remarks
*   - 返回JSON示例：
*   @code
*   ["license_id": 1, "sessions": [
*       {"session_id": 1, "concurrent_type": "win_user_session", "curr_concurrent" : 5, "max_concurrent": 5000,
*           "process_name": "notepad.exe", "process_id": 5234, "win_session_id": 1, "computer_name": "ABC-PC"}
*   ["license_id": 2, "sessions": [
*       {"session_id": 2, "concurrent_type": "process", "curr_concurrent" : 5, "max_concurrent": 5000,
*           "process_name": "calc.exe", "process_id": 2346, "win_session_id": 1, "computer_name": "DEF-PC"}
*   @endcode
*   @see    slm_get_all_server
*/
SS_UINT32  SSAPI slm_read_session_context(
    IN  void*               ipc,
    IN  INFO_FORMAT_TYPE    type,
    IN  const char*         desc,
    OUT char**              result
    );

/*!
*   @brief  踢除指定的许可会话
*   @param[in]  ipc     与服务的连接句柄，可由slm_client_open打开
*   @param[in]  desc    设备描述，由slm_get_all_server得到
*   @param[in]  session_id 要踢除的session ID
*   @return 成功返回SS_OK，失败返回相应的错误码
*   @see    slm_client_open slm_get_all_server
*/
SS_UINT32 SSAPI slm_kick_session(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_UINT32   session_id
    );

/*!
*   @brief  清理历史记录
*   @param[in]  ipc     与服务的连接句柄，可由slm_client_open打开
*   @param[in]  desc    设备描述，可由slm_get_all_server得到
*/
SS_UINT32 SSAPI slm_clear_history(
    IN  void*       ipc,
    IN  const char* desc
    );


/*!
*   @brief 获得设备信息
*   @param[in] ipc ipc句柄
*   @param[in] desc  设备描述
*   @param[in] result 接收数据的指针，需要调用slm_free释放
*   @return SS_UINT32错误码 
*   @remarks
*   - JSON 字段说明：
*       -# "clock"（数字）：锁内时间（UTC）
*       -# "available_space"(数字）：可用空用
*       -# "communication_protocol": 通迅协议
*       -# "firmware_version":固件版本
*       -# "manufacture_date":生产日期
*       -# "slave_addr": 总线地址
*/
SS_UINT32  SSAPI slm_get_device_info(
    IN  void*           ipc,
    IN  const char*     desc,
    OUT char**          result
    );

SS_UINT32 SSAPI slm_ctrl_adjust_time_request(
    IN  void*               ipc,
    IN  const char*         desc,
    OUT SS_BYTE             rand[SLM_FIXTIME_RAND_LENGTH],
    OUT SS_UINT32*          lock_time,
    IN OUT SS_UINT32*       pc_time
    );
/*!
*   @brief 获得所内文件信息
*   @param[in] ipc ipc句柄
*   @param[in] desc  设备描述
*   @param[in] result 接收数据的指针，需要调用slm_free释放
*   @return SS_UINT32错误码 
*   @remarks
*   - JSON 字段说明：
*       -# "validate"（数字）：标志哪些域有效，仅在设置文件属性中使用
*       -# "type"(数字）：文件类型，不能修改
*       -# "privilege"（数字）: 文件访问权限
*       -# "size"（数字）:文件大小
*       -# "time"（数字）:文件修改时间
*       -# "name"（字符串）: 文件名  当前文件名称长度16字节
*/
SS_UINT32  SSAPI slm_get_filelist_info(
	IN  void*            ipc,
	IN  const char*      desc,
	OUT char**           result
	);


/*!
*   @brief  获取锁的设备证书
*   @param[in]  ipc         ipc句柄
*   @param[in]  desc        设备描述，由slm_get_all_server得到
*   @param[out] device_cert 证备证书缓冲区
*   @param[in]  buff_size   缓冲区大小
*   @param[out] return_size 返回的设备证书大小
*   @return 成功返回SS_OK，失败返回相应的错误码
*   @remarks    该函数暂未实现
*   @see    slm_login
*/
SS_UINT32 SSAPI slm_ctrl_get_device_cert(
    IN  void*               ipc,
    IN  const char*         desc,
    OUT SS_BYTE*            device_cert,
    IN  SS_UINT32           buff_size,
    OUT SS_UINT32*          return_size
    );

/*!
*   @brief  获取已登录许可的设备证书
*   @param[in]  ipc                 ipc句柄
*   @param[in]  desc                设备描述，由slm_get_all_server得到
*   @param[in]  verify_data         验证数据
*   @param[in]  verify_data_size    验证数据大小
*   @param[out] signature           返回的签名
*   @param[in]  signature_buf_size  缓冲区大小
*   @param[out] signature_size      签名结果大小
*   @return 成功返回SS_OK，失败返回相应的错误码
*   @remarks    该函数暂未实现
*   @see    slm_login
*/
SS_UINT32 SSAPI slm_ctrl_verify_device(
    IN  void*               ipc,
    IN  const char*         desc,
    IN  SS_BYTE*            verify_data,
    IN  SS_UINT32           verify_data_size,
    OUT SS_BYTE*            signature,
    IN  SS_UINT32           signature_buf_size,
    OUT SS_UINT32*          signature_size
    );

SS_UINT32 SSAPI slm_ctrl_led_control(
    IN  void*               ipc,
    IN  const char*         desc,
    IN  ST_LOCK_LED_CONTROL*     led_ctrl
    );

/*!
*   @brief 客户端打开SS IPC句柄
*   @param[out] ipc 返回ipc句柄
*   @return SS_UINT32错误码 
*/
SS_UINT32 SSAPI slm_client_open(OUT void** ipc);

/*!
*   @brief 关闭客户端IPC句柄
*   @param[in] ipc 输入ipc句柄
*   @return SS_UINT32错误码 
*/
SS_UINT32 SSAPI slm_client_close(IN void* ipc);

/*!
*   @brief 释放API生成的缓冲区
*   @param[in] buffer API生成的缓冲区
*/
void SSAPI slm_free(
    IN  void*   buffer
    );

#define SS_SERVICE_TYPE_LOCAL       0   //  本地模块
#define SS_SERVICE_TYPE_CLIENT      1   //  客户端
#define SS_SERVICE_TYPE_SERVER      2   //  服务端
#define SS_SERVICE_TYPE_CS          3   //  既是客户端又是服务端


/*!
*   @brief 获取服务类型
*   @param [out] service_type 服务类型
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI ss_get_service_type(SS_UINT32* service_type);


/*!
*   @brief 获取服务类型
*   @param [in] service_type 服务类型
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI ss_set_service_type(SS_UINT32 service_type);

/*!
*   @brief 绑定或解绑请求
*   @param[in]  ipc                 ipc句柄
*   @param[in]  desc                设备描述，由slm_get_all_server得到
*   @param[in]  bind                是否是绑定（TRUE，解绑为FALSE）
*   @param[out] result              返回String（内容为HEX String）
*/
SS_UINT32 SSAPI slm_ctrl_bind_or_unbind(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_BOOL     bind,
    OUT SS_CHAR**   result
    );

/*!
*   @brief 转移许可请求（从云向锁转移）
*   @param[in]  ipc                 ipc句柄
*   @param[in]  desc                设备描述，由slm_get_all_server得到
*   @param[in]  license_id          要转移的许可ID
*   @param[in]  guid                GUID字符串（如"8B633770-0BB5-4764-BEEE-6CAB69F2E040"）
*   @param[out] result              返回String（内容为HEX String）
*/
SS_UINT32 SSAPI slm_ctrl_transfer_license(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_UINT32   license_id,
    IN  const SS_CHAR*  guid,
    OUT SS_CHAR**   result
    );

/*!
*   @brief 云向USB锁的请求
*   @param[in]  ipc                 ipc句柄
*   @param[in]  desc                设备描述，由slm_get_all_server得到
*   @param[in]  pkg                 云向锁的数据内容
*   @param[in]  pkg_size            数据大小
*   @param[out] result              返回String（内容为HEX String）
*/
SS_UINT32 SSAPI slm_ctrl_cloud_to_dongle(
    IN  void*       ipc,
    IN  const char* desc,
    IN  const void* pkg,
    IN  SS_UINT32   pkg_size,
    OUT SS_CHAR**   result
    );

/*!
*   @brief 云向USB锁的请求
*   @param[in]  ipc                 ipc句柄
*   @param[in]  desc                设备描述，由slm_get_all_server得到
*   @param[in]  datain              数据内容，具体与协议的步骤有关
*   @param[in]  datain_len          datain的长度
*   @param[out] result              返回String（内容为HEX String）
*/
SS_UINT32 SSAPI slm_ctrl_exchange_key_cloud(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_BYTE*    datain,
    IN  SS_UINT32   datain_len,
    OUT SS_CHAR**   result
    );

typedef enum _ENUM_STORE_CERT_TYPE{
    ENUM_STORE_CERT_TYPE_CLOUD = 0,
    ENUM_STORE_CERT_TYPE_ACCOUNT = 1,
    ENUM_STORE_CERT_TYPE_DEVELOPER = 2,
    ENUM_STORE_CERT_TYPE_CLOUD_ENC = 3,
} ENUM_STORE_CERT_TYPE;

/*!
*   @brief 存储证书
*/
SS_UINT32 SSAPI slm_ctrl_store_cert(
    IN  void*               ipc,
    IN  const char*         desc,
    IN  ENUM_STORE_CERT_TYPE cert_type,
    IN  SS_BYTE*            sub_cert,
    IN  SS_UINT32           sub_cert_size,
    IN  SS_BYTE*            cert,
    IN  SS_UINT32           cert_size
    );

/*!
*   @brief 获取账户信息
*   @param[in]  ipc     IPC句柄
*   @param[in]  desc    设备描述
*   @param[out] account_info 账户信息（JSON）
*   @code
*   {"guid":"60B5FDC5-C3AE-4D82-BA4E-C1D9CF95E5E3", "account":["xxx@xxx.com", "13000000000"]
*   @endcode
*/
SS_UINT32 SSAPI slm_ctrl_get_account_info(
    IN  void*               ipc,
    IN  const char*         desc,
    OUT  SS_CHAR**           account_info
    );

/*!
*   @brief 刷新许可缓存
*   @param[in]  ipc     IPC句柄
*   @param[in]  desc    设备描述
*/
SS_UINT32 SSAPI slm_ctrl_refresh_license(
    IN  void*               ipc,
    IN  const char*         desc
    );

/*!
*   @brief 枚举已登录的用户token
*   @param[out] access_token 默认用户的token
*   @return 成功返回SS_OK，失败返回相应的错误码
*   @see slm_refresh_cloud_token
*/
SS_UINT32 SSAPI slm_ctrl_get_cloud_token(OUT SS_CHAR** access_token);

#ifdef __cplusplus
};
#endif //__cplusplus

/**
*   @}
*/



#endif //_H_DEF_SLM_CONTROL_API_
