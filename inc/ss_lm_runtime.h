/** 
*   @file ss_lm_runtime.h
*   @brief      Core header for LicenseManagent ����ɹ����õĵ�������ͷ�ļ�.
*   @details   ���API�û�����ʱ�ӿ�ͷ�ļ�.license runtime api head files
*   
*   history:
*   
*   �������Java��Dotnet��DLL��װ���� ���Ը���̬�ⲻһ�������� Handle  slm_login(licenseid_json), ����ֱ�ӷ��ص�¼�����
*   slm_keep_alive �ǵ�¼�����Ҫ���ã���SS֪��APPӦ�û������ţ�û���������ű����ԡ�
*   
*   @author    Chen Xiaodong <chenxd@sense.com.cn>
*   @version   0.5
*   @date      2013-2015
*   @bug       �ο�BUG�б�  
*   @pre       ������֤��(��˼ǩ����������SS����֤)��Vdata(APP����Ϣ���ÿ�����ǩ��)��ECC��Կ(�˵�����֤�����)��Ҫ����lib
*   @copyright Bussiness License,��ҵ��Ȩ.
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

#if _MSC_VER >= 1900   // 1900��VS2015�İ汾�ţ������̬����VS2015�±���ʧ�ܵ�����
#pragma comment(linker, "/defaultlib:legacy_stdio_definitions.lib")
#endif  // MSC_VER

/** �������Ϣ����ö��  */
typedef enum _INFO_TYPE {
    /**  ����Ϣ  */
    LOCK_INFO = 1,
    /**  �Ự��Ϣ */
    SESSION_INFO = 2,
    /**  �����Ϣ */
    LICENSE_INFO  = 3,
	/**  �ļ��б� */
	FILE_LIST  = 4,
    
} INFO_TYPE;

/** ��ɴ���������ö��  */ 
typedef enum _LIC_USER_DATA_TYPE {
    /** ֻ���� */
    ROM = 0,     
    /** ��д�� */
    RAW = 1,
    /** ������ */
    PUB = 2,
} LIC_USER_DATA_TYPE;

/** SS ��Ϣ����ص���������ǰ�汾 SLM_CALLBACK_VERSION01 )*/
typedef SS_UINT32 (SSAPI *SS_CALL_BACK)(
    SS_UINT32   message,
    void*       wparam,
    void*       lparam
    );

/** ������ɫ����ɫ*/
#define LED_COLOR_BLUE      0
/** ������ɫ����ɫ*/
#define LED_COLOR_RED       1

/** ���ƿ��ƣ��ر�*/
#define LED_STATE_CLOSE     0
/** ���ƿ��ƣ���*/
#define LED_STATE_OPEN      1
/** ���ƿ��ƣ���˸*/
#define LED_STATE_SHRINK    2

/** ���ƿ��ƽṹ*/
typedef struct _ST_LED_CONTROL {
    /**  0��ʾ��ɫLED��1��ʾ��ɫLED  */
    SS_UINT32   index;
    /**  0����رգ�1����򿪣� 2������˸ */
    SS_UINT32   state;
    /**  ��������룩*/
    SS_UINT32   interval;   
} ST_LED_CONTROL;

//============================================================
//              �ص���Ϣ message ����
//============================================================
/** ��Ϣ���ͣ���Ϣ��ʾ*/
#define SS_ANTI_INFORMATION			0x0101
/** ��Ϣ���ͣ�����*/
#define SS_ANTI_WARNING				0x0102
/** ��Ϣ���ͣ��쳣*/
#define SS_ANTI_EXCEPTION			0x0103
/** ��Ϣ���ͣ��ݱ���*/
#define SS_ANTI_IDLE				0x0104

/** ��������*/
#define SS_MSG_SERVICE_START        0x0200
/** ����ֹͣ*/
#define SS_MSG_SERVICE_STOP         0x0201
/** �����ã���������SS����ʱ���ѳ�ʼ����ɣ��ص�����wparam ��������*/
#define SS_MSG_LOCK_AVAILABLE       0x0202
/** ����Ч�����Ѱγ����ص�����wparam ��������*/
#define SS_MSG_LOCK_UNAVAILABLE     0x0203


//============================================================
//              �ص���Ϣ wparam ����
//============================================================
/** ����ע��*/
#define SS_ANTI_PATCH_INJECT		0x0201
/** ģ����ʧ��*/
#define SS_ANTI_MODULE_INVALID		0x0202
/** ���ֱ�����������*/
#define SS_ANTI_ATTACH_FOUND		0x0203
/** ��Ч���߳�*/
#define SS_ANTI_THREAD_INVALID		0x0204
/** �̼߳��ʧ��*/
#define SS_ANTI_THREAD_ERROR		0x0205
/** CRC����ʧ��*/
#define SS_ANTI_CRC_ERROR			0x0206
/** ���ֵ�����*/
#define SS_ANTI_DEBUGGER_FOUND		0x0207

/** ʱ��У׼��������ӳ���*/
#define SLM_FIXTIME_RAND_LENGTH     8

/** SS_CALL_BACK�İ汾 ��֧�ֿ�����API����İ汾��*/
#define SLM_CALLBACK_VERSION02      0x02

/** �ڴ��й�����ֽ�*/
#define  SLM_MEM_MAX_SIZE           2048

/** ����ִ�У�������뻺������С���ֽڣ�*/
#define SLM_MAX_INPUT_SIZE          1758
/** ����ִ�У���������������С���ֽڣ�*/
#define SLM_MAX_OUTPUT_SIZE         1758

/** �ӽ�����󻺳�����С���ֽڣ�*/
#define SLM_MAX_USER_CRYPT_SIZE     1520

/** �û���������󳤶ȣ��ֽڣ�*/
#define SLM_MAX_USER_DATA_SIZE      2048

/** �û�������д����󳤶ȣ��ֽڣ�*/
#define SLM_MAX_WRITE_SIZE          1904

/** ����ǩ��������ǰ׺*/
#define SLM_VERIFY_DEVICE_PREFIX    "SENSELOCK"

/** ����ǩ�������ݴ�С����slm_sign_by_device*/
#define SLM_VERIFY_DATA_SIZE        41

/** ���ŵĳ���*/
#define SLM_LOCK_SN_LENGTH          16

/** ������ID����*/
#define SLM_DEVELOPER_ID_SIZE       8

/** ������������󳤶�*/
#define SLM_MAX_SERVER_NAME         32

/** �����û�token��󳤶�*/
#define SLM_MAX_ACCESS_TOKEN_LENGTH 64

/** ������������ַ��󳤶�*/
#define SLM_MAX_CLOUD_SERVER_LENGTH 100

/** ��Ƭ�������ӳ���*/
#define SLM_SNIPPET_SEED_LENGTH     32

/** ���������볤��*/
#define SLM_DEV_PASSWORD_LENGTH     16

/** ����û�GUID���� */
#define SLM_CLOUD_MAX_USER_GUID_SIZE 	        128	

/** �ļ����ͣ������ļ�*/
#define SLM_FILE_TYPE_BINARY                    0
/** �ļ����ͣ���ִ���ļ��ļ�*/
#define SLM_FILE_TYPE_EXECUTIVE                 1
/** �ļ����ͣ���Կ�ļ�*/
#define SLM_FILE_TYPE_KEY                       2

/** �ɶ�*/
#define SLM_FILE_PRIVILEGE_FLAG_READ            0x01
/** ��д*/
#define SLM_FILE_PRIVILEGE_FLAG_WRITE           0x02
/** ����Կ�ļ�����ʹ��*/
#define SLM_FILE_PRIVILEGE_FLAG_USE             0x04
/** ��Զ������*/
#define SLM_FILE_PRIVILEGE_FLAG_UPDATE          0x08

/** �ɶ�*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_READ      0x10
/** ��д*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_WRITE     0x20
/** ����Կ�ļ�����ʹ��*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_USE       0x40
/** ��Զ������*/
#define SLM_FILE_PRIVILEGE_FLAG_ENTRY_UPDATE    0x80


/** �ڴ�������Ҫ�ͻ�ά���ڴ棬SS�濪����ά���ڴ棬����һ���ڴ�id����Χ��0-N֮��*/
typedef unsigned int SLM_HANDLE_INDEX; 

/** �Զ���¼ģʽ*/
#define SLM_LOGIN_MODE_AUTO             0x0000
/** ָ����¼����USE��*/
#define SLM_LOGIN_MODE_LOCAL            0x0001
/** ָ����¼Զ��USE�� */
#define SLM_LOGIN_MODE_REMOTE           0x0002
/** ָ����¼���� */
#define SLM_LOGIN_MODE_CLOUD            0x0004

/** �������е�����������ֶ����������򲻵�¼���ṩѡ�񣬷����ҵ�������������ֱ�ӵ�¼*/
#define SLM_LOGIN_FLAG_FIND_ALL         0x0001
/** ָ����ɰ汾*/
#define SLM_LOGIN_FLAG_VERSION          0x0004
/** ָ�����ţ�USB��*/
#define SLM_LOGIN_FLAG_LOCKSN           0x0008
/** ָ��������*/
#define SLM_LOGIN_FLAG_SERVER           0x0010
/** ָ����Ƭ����*/
#define SLM_LOGIN_FLAG_SNIPPET          0x0020


/** ����ID����������*/
#define LANGUAGE_CHINESE_ASCII                  0x0001
/** ����ID��Ӣ��*/
#define LANGUAGE_ENGLISH_ASCII                  0x0002
/** ����ID����������*/
#define LANGUAGE_TRADITIONAL_CHINESE_ASCII      0x0003

/** ��ʾ���յ�SS����Ϣ֪ͨ*/
#define SLM_INIT_FLAG_NOTIFY            0x01

/** API ��ʼ������   */
typedef struct _ST_INIT_PARAM {
    /** �汾���������ݣ���ǰʹ�� SLM_CALLBACK_VERSION02 */
    SS_UINT32       version;
    /** �����Ҫ����SS֪ͨ���� SLM_INIT_FLAG_NOTIFY */
    SS_UINT32       flag;
    /** �ص�����ָ��*/
    SS_CALL_BACK    pfn;
    /** ͨ�����ӳ�ʱʱ�䣨���룩�������0����ʹ��Ĭ�ϳ�ʱʱ�䣨7�룩*/
    SS_UINT32       timeout;
    /** API���룬�ɴӿ�������վ�ϻ�ȡ*/
    SS_BYTE         password[SLM_DEV_PASSWORD_LENGTH];
} ST_INIT_PARAM;

/** ���Login �ṹ*/
typedef struct _ST_LOGIN_PARAM{ 
    /** �ṹ���С�����*/
    SS_UINT32       size;
    /** Ҫ��¼�����ID*/
    SS_UINT32       license_id;
    /** ��ɻỰ�ĳ�ʱʱ�䣨��λ���룩,��0��ʹ��Ĭ��ֵ��600��   */
    SS_UINT32       timeout;
    /** ��ɵ�¼��ģʽ�����أ�Զ�̣��ƣ���LOGIN_MODE_XXX)�������0����ʹ��SLM_LOGIN_MODE_AUTO*/
    SS_UINT32       login_mode;
    /** ��ɵ�¼�ı�־����SLM_LOGIN_FLAG_XXX */
    SS_UINT32       login_flag;
    /** ��ɵ�¼ָ������Ψһ���кţ���ѡ��*/
    SS_BYTE         sn[SLM_LOCK_SN_LENGTH];
    /** ��������������ַ����ѡ������ʶ��IP��ַ */
    SS_CHAR         server[SLM_MAX_SERVER_NAME];
    /** �����û�token����ѡ��*/
    SS_CHAR         access_token[SLM_MAX_ACCESS_TOKEN_LENGTH];
    /** ������������ַ����ѡ��*/
    SS_CHAR         cloud_server[SLM_MAX_CLOUD_SERVER_LENGTH];
    /** ��Ƭ�������ӣ���ѡ�������Ҫ֧����Ƭ����,login_flag��Ҫָ��ΪSLM_LOGIN_FLAG_SNIPPET*/
    SS_BYTE         snippet_seed[SLM_SNIPPET_SEED_LENGTH];
    /** �ѵ�¼�û���guid����ѡ�� */
    SS_BYTE         user_guid[SLM_CLOUD_MAX_USER_GUID_SIZE];
} ST_LOGIN_PARAM;


/** 
*   @defgroup group1_lm_runtime  sense shield lm_runtime ��˼����û�����ʱ��
*   This is sense lm_runtime ��˼����û�����ʱ�� api����
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*!
*   @brief      Runtime API��ʼ����������������Runtime API�����ȵ��ô˺������г�ʼ��
*   @param[in]  pst_init    ��ʼ����������ST_INIT_PARAM�ṹ����
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see ST_INIT_PARAM
*/
SS_UINT32 SSAPI slm_init(IN ST_INIT_PARAM* pst_init);

/*!
*   @brief      ���������Ϣ(����Ӳ������Ч)
*   @param[in]  license_id      ���ID
*   @param[in]  format          ������ʽ����֧��JSON
*   @param[out] license_desc    ���������Ϣ��ָ�룬��ʽ��formatָ��������ʹ��ʱ����slm_free�ͷ�
*   @remark     ����ɹ�����Ҫ����slm_free �ͷ�license_desc
*/
SS_UINT32 SSAPI slm_find_license(
    IN  SS_UINT32           license_id,
    IN  INFO_FORMAT_TYPE    format,
    OUT char**              license_desc
    );


/*!
*   @brief      ö���ѵ�¼���û�token
*   @param[out] access_token Ĭ���û���token������ʹ��ʱ�������slm_free�ͷ�
*   @return     �ɹ�����SS_OK�����oauth��̨����δ�������򷵻�SS_ERROR_BAD_CONNECT
*   @remark     ����ɹ�����Ҫ����slm_free �ͷ� access_token
*/
SS_UINT32 SSAPI slm_get_cloud_token(OUT SS_CHAR** access_token);

/*!
*   @brief ��ȫ��¼���,��JSON���ݲ���,���Ҽ��ʱ�䣨�Ƿ��ڻ����Ƿ����ڿ�ʼʱ�䣩���������������Ƿ���㣬
*          ����м��������������Լ��ٶ�Ӧ�ļ���������������������ʱ�������粢����������
*   @param[in]  license_param ��¼���������������������������licenseid������ָ�����Եȡ�
*   @param[in]  param_format  ��������ַ������ͣ�֧��JSON��STRUCT������ʹ��STRUCT
*   @param[out] slm_handle    ���ص�¼֮����ɾ��indexֵ,��Χ��0-256֮�䡣
*   @param[out] auth          ��֤login���������Ƿ���ȷ������ECCǩ���ͷ���ֵ���ܣ���ʹ�ÿ�����NULL��
*   @return     SS_UINT32������,��0����ʧ��
*   @remark
*   - slm_login������ϸ˵����
*       -# ���Զ����ҿ���������ɾ����
*       -# ��runtime�������������ڴ�������߳���Ϣ��
*       -# �����������Ҫ���ڼ�ػỰ���̣���������������߱������Լ��ͷŶ�Ӧ���ڴ��������Դ��
*       -# LM�����ڿͻ������Զ����룬����RSA ��Կ����֤�豸ID�������̱�ŵ�һ����֤�ֶΡ�
*       -# LM�����������붼Ҫlogin֮�������Ȩ�޲��� �����д���ӽ��ܵȲ�����
*   - ���ܲ���˵����
*       - ���ýṹ�壺
*       -# �ο� ST_LOGIN_PARAM �ṹ��ϸ����
*       - ����JSON��ÿ��JSON�������ͣ�
*       -# license_id ���ID��Ϊ32λ��������ȡֵ��Χ0-4294967295����д����
*       -# login_mode ��ɵ�¼ģʽ����Ϊ�Զ���¼����������¼��ֻ��¼Զ����ģʽ���Լ�����ģʽ.("auto", "local", "remote", "cloud")
*       -# sn ָ����¼���� Ϊ16�����ַ����� 16�ֽ����ţ���
*       -# access_token �����¼����������Ҫָ��ͨ��oauth��֤��access token
*       -# time_out ָ����¼�Ự��ʱ ��λΪ�롣�������д��Ĭ��Ϊ600�롣
*       -# user_guid ��¼�û���guid����󳤶�ΪSLM_CLOUD_MAX_USER_GUID_SIZE��һ�㲻��д
*   - �򵥲���
*   @code
*       "{"license_id":0}"
*   @endcode
*   - ��Ӳ���
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
*   @brief     ��ɵǳ��������ͷ���ɾ������Դ
*   @param[in] slm_handle    ��ɾ��ֵ
*   @return    SS_UINT32������
*   @see       slm_login
*/
SS_UINT32 SSAPI slm_logout(SLM_HANDLE_INDEX slm_handle);

/*!
*   @brief     ���ֵ�¼�Ự�����������Ϊ����ʬ�������
*              ��ʬ��������������ѭ�����߱�����slm_handle�����Զ����ͷţ����slm_runtime�����ڴ����Դ��
*   @param[in] slm_handle    ��ɾ��ֵ
*   @return    SS_UINT32������
*   @see       slm_login
*/
SS_UINT32 SSAPI slm_keep_alive(SLM_HANDLE_INDEX slm_handle);

/*!
*   @brief      ��ɼ��ܣ���ͬ�����ID��ͬ�Ŀ����̼��ܽ����ͬ
*   @param[in]  slm_handle   ��ɾ��ֵ
*   @param[in]  inbuffer     �������뻺����,��Ҫ16�ֽڶ��� 
*   @param[out] outbuffer    �������������,��Ҫ16�ֽڶ��� 
*   @param[in]  len          ���ܻ�������С��Ϊ16�ֽڵ���������
*   @return     SS_UINT32������
*   @see        slm_encrypt slm_decrypt slm_login
 */
SS_UINT32 SSAPI slm_encrypt(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            inbuffer,
    OUT SS_BYTE*            outbuffer,
    IN  SS_UINT32           len
    );

/*!
*   @brief      ��ɽ��ܣ���ͬ�����ID��ͬ�Ŀ����̼��ܽ����ͬ
*   @param[in]  slm_handle   ��ɾ��ֵ
*   @param[in]  inbuffer     �������뻺����,��Ҫ16�ֽڶ��� 
*   @param[out] outbuffer    �������������,��Ҫ16�ֽڶ��� 
*   @param[in]  len          ���ܻ�������С��Ϊ16�ֽڵ���������
*   @return     SS_UINT32������
*   @see        slm_encrypt slm_login
 */
SS_UINT32 SSAPI slm_decrypt(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_BYTE*            inbuffer, 
    OUT SS_BYTE*            outbuffer, 
    IN  SS_UINT32           len
    );

/*!
*   @brief      �����ɵ���������С
*   @param[in]  slm_handle ��ɾ��ֵ
*   @param[in]  type       ���������ͣ����Ͷ���� LIC_USER_DATA_TYPE
*   @param[out] pmem_size  ��������С�����ַ��
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see        LIC_USER_DATA_TYPE slm_user_data_getsize slm_user_data_read slm_user_data_write
 */
SS_UINT32 SSAPI slm_user_data_getsize(
    IN SLM_HANDLE_INDEX     slm_handle,
    IN LIC_USER_DATA_TYPE   type,
    OUT SS_UINT32*          pmem_size
    );

/*!
*   @brief      ��������ݣ����Զ�ȡPUB��RAW��ROM
*   @param[in]  slm_handle   ��ɾ��ֵ
*   @param[in]  type         �ڴ����ͣ��ο�LIC_USER_DATA_TYPE
*   @param[out] readbuf      ��ȡ������
*   @param[in]  offset       ����ƫ��
*   @param[in]  len          ��������С
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
*   @brief     д��ɵĶ�д������ ,����������֮ǰ����ȷ���ڴ����Ĵ�С������ʹ��slm_user_data_getsize���
*   @param[in] slm_handle      ��ɾ��ֵ
*   @param[in] writebuf        д������
*   @param[in] offset          дƫ��
*   @param[in] len             д���ȣ�������󳤶� = min(slm_user_data_getsize, SLM_MAX_WRITE_SIZE)
*   @return    �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see       LIC_USER_DATA_TYPE   slm_user_data_getsize slm_user_data_read slm_user_data_write
 */
SS_UINT32 SSAPI slm_user_data_write(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_BYTE*            writebuf,
    IN  SS_UINT32           offset,
    IN  SS_UINT32           len
    );

/*!
*   @brief      ���ָ����ɵĹ�������������С����Ҫ��¼0�����
*   @param[in]  slm_handle    0����ɾ��ֵ
*   @param[in]  license_id    ָ�����ID
*   @param[out] pmem_size     ��������С�����ַ��
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see        slm_user_data_read_pub 
*/
SS_UINT32 SSAPI slm_pub_data_getsize(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  SS_UINT32           license_id,
    OUT SS_UINT32*          pmem_size
    );

/*!
*   @brief      ��ȡ��ɹ���������Ҫ��¼0�����
*   @param[in]  slm_handle   0����ɾ��ֵ
*   @param[in]  license_id   ָ�����ID
*   @param[out] readbuf      ��ȡ������
*   @param[in]  offset       ����ƫ��
*   @param[in]  len          ��������С
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @remark     ���û���ϣ��ͨ����¼��Ӧ����ɣ��Ӷ���ȡ����������ʱ���û�����ͨ�����ô˽ӿڽ��л�ȡ��ǰ������Ҫ��¼0�����
*              ��Ȼ��0����ɾ����Ҫ��ѯ�����������ID�����������ȡ����ɵĹ��������ݡ�
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
*   @brief ���ؾ�����Ϣ
*   ret = slm_get_info(hslm,ALL_INFO,JSON,result,sizeof(result),&retsize);
*   LOCK_INFO = 1 ����Ϣ  
*   SESSION_INFO = 2 , �Ự��Ϣ UPDATE_INFO  ������Ϣ
*   LOCK_INFO��Ϣ
*   �Ự��Ϣ
*   @param[in]  slm_handle  ��ɾ��ֵ
*   @param[in]  type        ��Ϣ���� �ο� INFO_TYPE,����Ϊ����Ϣ����ɾ����Ϣ�����ȫ����Ϣ������������Ϣ��
*   @param[in]  format      ��Ϣ��ʽ����֧��JSON
*   @param[out] result      ���ؽ��������������سɹ�����Ҫ����slm_free�ͷ�
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @code
*   // JSON ����˵����
*   - LICENSE_INFO������ֶβ����ڣ����ʾû�и�������ƣ�
*   {
*     "rom_size" (������֧�֣�
*     "raw_size"��������֧�֣�
*     "pub_size"��������֧�֣�
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
*     // ��������
*     "concurrent_type": "process" / "win_user_session"
*     //������
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
*    "session_id":  ��ֻ֧��������
*    "bios": "BIOS information", ��������֧�֣�
*    "cpuinfo": "CPU name", ��������֧�֣�
*    "sn": ""(HEX16 String), ��������֧�֣�
*    "mac":"00-00-00-00-00-00" ��������֧�֣�
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
*    "user_info": ""(HEX16 String)(128�ֽ�)
*    "inner_info": ""(HEX16 String)(128�ֽڣ�
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
*   @brief      ִ�������㷨������̬����ִ��
*   @param[in]  slm_handle  ��ɾ��ֵ
*   @param[in]  exfname     ����ִ���ļ���
*   @param[in]  inbuf       ���뻺����
*   @param[in]  insize      ���볤��
*   @param[out] poutbuf     ���������
*   @param[in]  outsize     ������泤��
*   @param[out] pretsize    ʵ�ʷ��ػ��泤��
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
*   @brief      ��ɶ�ִ̬�д��룬�ɿ�����API(d2c) gen_dynamic_code����
*   @param[in]  slm_handle  ��ɾ��ֵ����slm_login�õ�
*   @param[in]  exf_buffer  ��̬exf�㷨������
*   @param[in]  exf_size    ��̬exf�ļ���С
*   @param[in]  inbuf       ���뻺����
*   @param[in]  insize      ���볤��
*   @param[out] poutbuf     ���������
*   @param[in]  outsize     ������泤��
*   @param[out] pretsize    ʵ�ʷ��ػ��泤��
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
*   @brief      SS�ڴ��й��ڴ�����
*   @param[in]  slm_handle   ��ɾ��ֵ
*   @param[in]  size         �����С����� SLM_MEM_MAX_SIZE.
*   @param[out] mem_id       �����й��ڴ�id
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see        slm_mem_free slm_mem_read slm_mem_write
*/
SS_UINT32 SSAPI slm_mem_alloc(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_UINT32           size, 
    OUT SS_UINT32*          mem_id
    );

/*!
*   @brief     �ͷ��й��ڴ�
*   @param[in] slm_handle    ��ɾ��ֵ
*   @param[in] mem_id        �й��ڴ�id
*   @return    �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see       slm_mem_alloc slm_mem_free slm_mem_read slm_mem_write
*/
SS_UINT32 SSAPI slm_mem_free(
    IN  SLM_HANDLE_INDEX    slm_handle, 
    IN  SS_UINT32           mem_id
    );

/*!
*   @brief      SS�ڴ��йܶ�
*   @param[in]  slm_handle    ��ɾ��ֵ
*   @param[in]  mem_id        �й��ڴ�id
*   @param[in]  offset        ��ȡ����ƫ��
*   @param[in]  len           ��ȡ���ݳ���
*   @param[out] readbuff      ����
*   @param[out] readlen       ����ʵ�ʶ��ĳ���
*   @return    �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
*   @brief      SS�ڴ��й��ڴ�д��
*   @param[in]  slm_handle    ��ɾ��ֵ
*   @param[in]  mem_id        �й��ڴ�id
*   @param[in]  offset        ƫ��
*   @param[in]  len           ����
*   @param[in]  writebuff     ����
*   @param[out] numberofbyteswritten ����ʵ��д�ĳ���
*   @return     �ɹ�����SS_OK��ʧ���򷵻���Ӧ�Ĵ�����
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
*   @brief      ����Ƿ����ڵ���
*   @param[in]  auth     ��֤����(������������NULL���ɣ�
*   @return     SS_UINT32������, ����SS_OK����δ����
*/
SS_UINT32 SSAPI slm_is_debug(IN void *auth);

/*!
*   @brief      ��ȡ�����豸֤��
*   @param[in]  slm_handle  ��ɾ��
*   @param[out] device_cert ֤��֤�黺����
*   @param[in]  buff_size   ��������С
*   @param[out] return_size ���ص��豸֤���С
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see        slm_login
*/
SS_UINT32 SSAPI slm_get_device_cert(
    IN  SLM_HANDLE_INDEX    slm_handle,
    OUT SS_BYTE*            device_cert,
    IN  SS_UINT32           buff_size,
    OUT SS_UINT32*          return_size
    );

/*!
*   @brief      �豸������֤
*   @param[in]  slm_handle          ��ɾ��
*   @param[in]  verify_data         ��֤���ݣ��������ַ�"SENSELOCK"(9�ֽ�)��ͷ��
*   @param[in]  verify_data_size    ��֤���ݴ�С����С����Ϊ SLM_VERIFY_DATA_SIZE(41)���ֽ�
*   @param[out] signature           ���ص�ǩ��
*   @param[in]  signature_buf_size  ��������С
*   @param[out] signature_size      ǩ�������С
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
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
*   @brief         ��ȡʱ���޸����ݣ���������ʱ��У׼����
*   @param[in]     slm_handle  ��ɾ��
*   @param[out]    rand        �����
*   @param[out]    lock_time   ��ʱ��
*   @param[in,out] pc_time     PCʱ�䣬���ص�PCʱ�䣨����0��ȡ��ʱʱ�䣩
*   @return        �ɹ�����SS_OK��ʧ���򷵻���Ӧ������
*/
SS_UINT32 SSAPI slm_adjust_time_request(
    IN  SLM_HANDLE_INDEX    slm_handle,
    OUT SS_BYTE             rand[SLM_FIXTIME_RAND_LENGTH],
    OUT SS_UINT32*          lock_time,
    IN OUT SS_UINT32*       pc_time
    );

/*!
*   @brief      ��˸ָʾ��
*   @param[in]  slm_handle      ��ɾ��
*   @param[in]  led_ctrl        ���ƿ��ƽṹ(ST_LED_CONTROL)
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*   @see        slm_login
*/
SS_UINT32 SSAPI slm_led_control(
    IN  SLM_HANDLE_INDEX    slm_handle,
    IN  ST_LED_CONTROL*     led_ctrl
    );

/*!
*   @brief      ���runtime���SS�İ汾��Ϣ.
*   @param[out] api_version  API�İ汾�����ǳɹ���
*   @param[out] ss_version   SS����İ汾
*   @return     �ɹ�����SS_OK��ʧ���򷵻���Ӧ�Ĵ�����
*/
SS_UINT32 SSAPI slm_get_version(
    OUT SS_UINT32*      api_version, 
    OUT SS_UINT32*      ss_version
    );

/*!
*   @brief     �ͷ�API���ɵĻ�����
*   @param[in] buffer API���ɵĻ�����
*/
void SSAPI slm_free(
    IN void*        buffer
    );

/*!
*   @brief      ��D2C����������
*   @param[in]  d2c_pkg     d2c�ļ�����
*   @param[out] error_msg   ������Ϣ����ʹ����Ҫ����slm_free�ͷ�
*   @return     �ɹ�����SS_OK��ʧ�ܷ��ش�����
*   @remarks:   error_msg���������ݣ�JSON����
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
*   @brief      ��D2C��������������ָ��������Ψһ���к�
*   @param[in]  lock_sn     ���ţ�Ψһ���кţ�
*   @param[in]  d2c_pkg     d2c�ļ�����
*   @param[out] error_msg   ������Ϣ����ʹ����Ҫ����slm_free�ͷ�
*   @return     �ɹ�����SS_OK��ʧ�ܷ��ش�����
*   @remarks:   error_msg���������ݣ�JSON����
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
*   @brief       ö�ٱ�������Ϣ
*   @param[out]  device_info    ����Ϣ������ʹ��ʱ�������slm_free�ͷ�
*   @return      �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*   @remark      �����óɹ�����Ҫ����slm_free �ͷ� device_info
*/
SS_UINT32 SSAPI slm_enum_device(
    OUT char**  device_info
    );

/*!
*   @brief     ���ģ��
*   @param[in] slm_handle     ��ɾ��
*   @param[in] module_id      ģ��ID����Χ�ɣ�1 ~ 64��
*   @return    ģ����ڷ���SS_OK�������ڷ���SS_ERROR_LICENSE_MODULE_NOT_EXISTS, ���򷵻�����������
*/
SS_UINT32 SSAPI slm_check_module(IN SLM_HANDLE_INDEX slm_handle, IN SS_UINT32 module_id);

/*!
*   @brief      ��Ƭ����ִ��
*   @param[in]  slm_handle      ��ɾ��
*   @param[in]  snippet_code    ��Ƭ����
*   @param[in]  code_size       ��Ƭ�����С
*   @param[in]  input           ��������
*   @param[in]  input_size      �������ݳ���
*   @param[out] output          ���������
*   @param[in]  outbuf_size     �������������
*   @param[out] output_size     ������ݳ���
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
*   @brief      ��ȡAPI��Ӧ�Ŀ�����ID
*   @param[out] developer_id          ���������ID
*   @return     �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_get_developer_id(OUT SS_BYTE developer_id[SLM_DEVELOPER_ID_SIZE]);


/*!
*   @brief      ͨ���������ô�����Ϣ
*   @param[in]  error_code ������
*   @param[in]  language_id Ҫ�����ַ��������ԣ��� LANGUAGE_CHINESE_ASCII,LANGUAGE_ENGLISH_ASCII,LANGUAGE_TRADITIONAL_CHINESE_ASCII
*   @return     �ɹ����ش�������Ϣ������Ҫ����slm_free�ͷţ���ʧ�ܷ��ؿ�ָ��NULL 
*/
const SS_CHAR * SSAPI slm_error_format(
    IN SS_UINT32    error_code,
    IN SS_UINT32    language_id
    );

/*!
*   @brief  ����ʼ����������slm_init��Ӧ
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

