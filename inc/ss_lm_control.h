/** 
*   @file	  ss_lm_control.h
*   @brief     Core header for ��ɱ�����SS��������鿴�Ƚӿ�
*   @details   ö������SS���豸��������
*   @author    Chen Xiaodong <chenxd@sense.com.cn>
*   @author    xiaodong Chen <chenxdclear@gmail.com>
*   @version   0.4
*   @bug       �ο�BUG�б�
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

#if _MSC_VER >= 1900   // 1900��VS2015�İ汾�ţ������̬����VS2015�±���ʧ�ܵ�����
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
    SS_UINT32   index;      //  0��ʾ��ɫLED��1��ʾ��ɫLED
    SS_UINT32   state;      //  0����رգ�1����򿪣� 2������˸
    SS_UINT32   interval;   //  ��������룩
} ST_LOCK_LED_CONTROL;

/** 
*@defgroup group3_lm_control_API  sense shield lm_control_api ��˼����ӿ�
*This is sense lm_control API ��˼����ӿ�API������������ʾ��ǰ�����
*@{
*/
#ifdef __cplusplus
extern "C" {
#endif


//	@breif ȡ���豸������������������������������ 
// @param[in] ss_client IPC��� (slm_client_open) 
//	@param[in] format_type ������ʽ��Ŀǰֻ֧��JSON) 
// @param[out] out_buf �õ����豸������ 
// @param[in] max_buf_len ���������� 
// @param[out] buf_len �õ���out_buf�ĳ��� 
// @retval �ɹ��򷵻�SS_OK��ʧ�ܷ��ش����� 
//����JSONʾ����
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
*   @brief ��ȡ����SS����
*   @param[in] ss_client ipc/client���
*   @param[in] format_type format_type����
*   @param[out] out_buf ���ؽ��
*   @remarks    ����JSONʾ����
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
*   @return ������
*/
SS_UINT32 SSAPI slm_get_all_server(
    IN  void*               ipc,
    IN  INFO_FORMAT_TYPE    format_type,
    OUT char**              out_buf
    );

/*!
*   @brief ��ȡ�����豸����
*   @param[in]  ipc     IPC���
*   @param[in]  format_type  ������ʽ
*   @param[out] desc    �豸����
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_get_all_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );

/*!
*   @brief ��ȡ��������
*   @param[in]  ipc         IPC���
*   @param[in]  cloud_url   ������������ַ����ѡ��
*   @param[in]  access_token    �û�token
*   @param[out] description ������Ϣ(JSON���飬����ѡ�����е�һ��������ɲ�ѯ��
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_get_cloud_description(
    IN  void*               ipc,
    IN  const SS_CHAR*      cloud_url,
    IN  const SS_CHAR*      access_token,
    OUT SS_CHAR**           descriptions
    );

/*!
*   @brief ��ȡ�����豸����
*   @param[in]  ipc     IPC���
*   @param[in]  format_type  ������ʽ
*   @param[out] desc    �豸����
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_get_local_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );


/*!
*   @brief ��ȡ�����豸����
*   @param[in]  ipc     IPC���
*   @param[in]  format_type  ������ʽ
*   @param[out] desc    �豸����
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_get_remote_description(
    IN  void*       ipc,
    IN  INFO_FORMAT_TYPE format_type,
    OUT char**      desc
    );


/*!
*   @brief  ��ȡָ���豸�����µ��������ID
*   @param[in]  ipc     IPC���
*   @param[in]  type    �������ͣ�JSON)
*   @param[in]  param   �豸����
*   @param[out] result  ���ID
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @remarks    ���ص�JSON���ʾ��
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
*   @brief ��ȡָ�����Ϳ������µ���ɼ�Ҫ��Ϣ
*   @param[in] ipc ipc���
*   @param[in] type �����ͷ������ͣ���ֻ֧��JSON��
*   @param[in] param �������
*   @param[out] result �����Ϣ
*   @return SS_UINT32������
*   @remarks
*   ���ز������ܣ�
*   @code
*   [{"license_id": 1405608497, "enable" : true / false, "start_time" : 1405608497,
*       "end_time" : 1405608497, "first_use_time" : 1405608497, "span_time" : 23234234, 
*       "counter" : 25, "concurrent" : 123, 
*       "concurrent_type" : "win_user_session"��Windows�û��Ự�� / "process"�����̣�, // ChenXD
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
*   @brief ��ȡ��������С
*   @param[in] ipc          IPC���
*   @param[in] license_id   ���ID
*   @param[in] desc         �豸����
*   @param[out] len         ���ع������Ĵ�С
*   @return �ɹ�����SS_OK�����򷵻���Ӧ�Ĵ�����
*   @see slm_read_pub_data
*/
SS_UINT32 SSAPI slm_get_pub_size(
    IN  void*           ipc,
    IN  SS_UINT32       license_id,
    IN  const char*     desc,
    OUT SS_UINT32*      len
    );

/*!
*   @brief ��ȡ�û���������
*   @param[in] ipc          IPC���
*   @param[in] license_id   ���ID
*   @param[in] desc         �豸����
*   @param[out] readbuf     ��ȡ�Ļ�����
*   @param[in] offset       ��ȡ��ƫ��
*   @param[in] len          ��ȡ�ĳ���
*/
SS_UINT32 SSAPI slm_read_pub_data(
    IN  void*           ipc,
    IN  SS_UINT32       license_id,
    IN  const char*     desc,       //  �豸����
    OUT SS_BYTE*        readbuf,
    IN  SS_UINT32       offset,
    IN  SS_UINT32       len
    );

/*!
*   @brief ��������ϸ��Ϣ
*   @param[in] ipc ipc���
*   @param[in] type type
*   @param[in]  license_id  ���ID
*   @param[in] desc �豸��������slm_get_all_server�õ�
*   @param[out] result �������ݵ�ָ�룬��Ҫ����slm_free�ͷ�
*   @return SS_UINT32������ 
*   @remark ����ͬ slm_read_brief_license_context
*/
SS_UINT32 SSAPI slm_read_license_context(
    IN  void *       ipc,
    IN  INFO_FORMAT_TYPE type,
    IN  SS_UINT32    license_id,
    IN  const char * desc,
    OUT char**      result
    );

/*!
*   @brief  ��ȡ��������ĳ���������µ�����session��Ϣ
*   @param[in]  ipc     IPC���
*   @param[in]  type    ��������
*   @param[in]  desc    �豸������
*   @param[out] result  ��ȡ����Ļ�����
*   @return ����ɹ�������SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @remarks
*   - ����JSONʾ����
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
*   @brief  �߳�ָ������ɻỰ
*   @param[in]  ipc     ���������Ӿ��������slm_client_open��
*   @param[in]  desc    �豸��������slm_get_all_server�õ�
*   @param[in]  session_id Ҫ�߳���session ID
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see    slm_client_open slm_get_all_server
*/
SS_UINT32 SSAPI slm_kick_session(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_UINT32   session_id
    );

/*!
*   @brief  ������ʷ��¼
*   @param[in]  ipc     ���������Ӿ��������slm_client_open��
*   @param[in]  desc    �豸����������slm_get_all_server�õ�
*/
SS_UINT32 SSAPI slm_clear_history(
    IN  void*       ipc,
    IN  const char* desc
    );


/*!
*   @brief ����豸��Ϣ
*   @param[in] ipc ipc���
*   @param[in] desc  �豸����
*   @param[in] result �������ݵ�ָ�룬��Ҫ����slm_free�ͷ�
*   @return SS_UINT32������ 
*   @remarks
*   - JSON �ֶ�˵����
*       -# "clock"�����֣�������ʱ�䣨UTC��
*       -# "available_space"(���֣������ÿ���
*       -# "communication_protocol": ͨѸЭ��
*       -# "firmware_version":�̼��汾
*       -# "manufacture_date":��������
*       -# "slave_addr": ���ߵ�ַ
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
*   @brief ��������ļ���Ϣ
*   @param[in] ipc ipc���
*   @param[in] desc  �豸����
*   @param[in] result �������ݵ�ָ�룬��Ҫ����slm_free�ͷ�
*   @return SS_UINT32������ 
*   @remarks
*   - JSON �ֶ�˵����
*       -# "validate"�����֣�����־��Щ����Ч�����������ļ�������ʹ��
*       -# "type"(���֣����ļ����ͣ������޸�
*       -# "privilege"�����֣�: �ļ�����Ȩ��
*       -# "size"�����֣�:�ļ���С
*       -# "time"�����֣�:�ļ��޸�ʱ��
*       -# "name"���ַ�����: �ļ���  ��ǰ�ļ����Ƴ���16�ֽ�
*/
SS_UINT32  SSAPI slm_get_filelist_info(
	IN  void*            ipc,
	IN  const char*      desc,
	OUT char**           result
	);


/*!
*   @brief  ��ȡ�����豸֤��
*   @param[in]  ipc         ipc���
*   @param[in]  desc        �豸��������slm_get_all_server�õ�
*   @param[out] device_cert ֤��֤�黺����
*   @param[in]  buff_size   ��������С
*   @param[out] return_size ���ص��豸֤���С
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @remarks    �ú�����δʵ��
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
*   @brief  ��ȡ�ѵ�¼��ɵ��豸֤��
*   @param[in]  ipc                 ipc���
*   @param[in]  desc                �豸��������slm_get_all_server�õ�
*   @param[in]  verify_data         ��֤����
*   @param[in]  verify_data_size    ��֤���ݴ�С
*   @param[out] signature           ���ص�ǩ��
*   @param[in]  signature_buf_size  ��������С
*   @param[out] signature_size      ǩ�������С
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @remarks    �ú�����δʵ��
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
*   @brief �ͻ��˴�SS IPC���
*   @param[out] ipc ����ipc���
*   @return SS_UINT32������ 
*/
SS_UINT32 SSAPI slm_client_open(OUT void** ipc);

/*!
*   @brief �رտͻ���IPC���
*   @param[in] ipc ����ipc���
*   @return SS_UINT32������ 
*/
SS_UINT32 SSAPI slm_client_close(IN void* ipc);

/*!
*   @brief �ͷ�API���ɵĻ�����
*   @param[in] buffer API���ɵĻ�����
*/
void SSAPI slm_free(
    IN  void*   buffer
    );

#define SS_SERVICE_TYPE_LOCAL       0   //  ����ģ��
#define SS_SERVICE_TYPE_CLIENT      1   //  �ͻ���
#define SS_SERVICE_TYPE_SERVER      2   //  �����
#define SS_SERVICE_TYPE_CS          3   //  ���ǿͻ������Ƿ����


/*!
*   @brief ��ȡ��������
*   @param [out] service_type ��������
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI ss_get_service_type(SS_UINT32* service_type);


/*!
*   @brief ��ȡ��������
*   @param [in] service_type ��������
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI ss_set_service_type(SS_UINT32 service_type);

/*!
*   @brief �󶨻�������
*   @param[in]  ipc                 ipc���
*   @param[in]  desc                �豸��������slm_get_all_server�õ�
*   @param[in]  bind                �Ƿ��ǰ󶨣�TRUE�����ΪFALSE��
*   @param[out] result              ����String������ΪHEX String��
*/
SS_UINT32 SSAPI slm_ctrl_bind_or_unbind(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_BOOL     bind,
    OUT SS_CHAR**   result
    );

/*!
*   @brief ת��������󣨴�������ת�ƣ�
*   @param[in]  ipc                 ipc���
*   @param[in]  desc                �豸��������slm_get_all_server�õ�
*   @param[in]  license_id          Ҫת�Ƶ����ID
*   @param[in]  guid                GUID�ַ�������"8B633770-0BB5-4764-BEEE-6CAB69F2E040"��
*   @param[out] result              ����String������ΪHEX String��
*/
SS_UINT32 SSAPI slm_ctrl_transfer_license(
    IN  void*       ipc,
    IN  const char* desc,
    IN  SS_UINT32   license_id,
    IN  const SS_CHAR*  guid,
    OUT SS_CHAR**   result
    );

/*!
*   @brief ����USB��������
*   @param[in]  ipc                 ipc���
*   @param[in]  desc                �豸��������slm_get_all_server�õ�
*   @param[in]  pkg                 ����������������
*   @param[in]  pkg_size            ���ݴ�С
*   @param[out] result              ����String������ΪHEX String��
*/
SS_UINT32 SSAPI slm_ctrl_cloud_to_dongle(
    IN  void*       ipc,
    IN  const char* desc,
    IN  const void* pkg,
    IN  SS_UINT32   pkg_size,
    OUT SS_CHAR**   result
    );

/*!
*   @brief ����USB��������
*   @param[in]  ipc                 ipc���
*   @param[in]  desc                �豸��������slm_get_all_server�õ�
*   @param[in]  datain              �������ݣ�������Э��Ĳ����й�
*   @param[in]  datain_len          datain�ĳ���
*   @param[out] result              ����String������ΪHEX String��
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
*   @brief �洢֤��
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
*   @brief ��ȡ�˻���Ϣ
*   @param[in]  ipc     IPC���
*   @param[in]  desc    �豸����
*   @param[out] account_info �˻���Ϣ��JSON��
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
*   @brief ˢ����ɻ���
*   @param[in]  ipc     IPC���
*   @param[in]  desc    �豸����
*/
SS_UINT32 SSAPI slm_ctrl_refresh_license(
    IN  void*               ipc,
    IN  const char*         desc
    );

/*!
*   @brief ö���ѵ�¼���û�token
*   @param[out] access_token Ĭ���û���token
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
