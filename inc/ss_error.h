/*! 
*  @file ss_error.h
*  @brief     SS��������������,32λ,����ͳһ�������ʽ�����һ�ֽ���ģ���ʶ��
*  @details   ����SS��LM��H5��IPC��NetAgent��SSprotect�ȴ���ֵ��������ߵ�һ�ֽ��Ǵ���ģ���ʶ��������ģ���Զ���
*  history:   0.01 created by chenxd ��RT LMһ��
*  
*             0.02 ��ֲ��SS��Ŀ,֧��doxygen
*             
*  @author    Chen Xiaodong <chenxd@sense.com.cn>
*  @author    zhaock <zhaock@sense.com.cn>
*  @version   1.0
*  @date      2013-2015
*  @pre       ��ǰ�������д���ֵ
*  @copyright Bussiness License,��ҵ��Ȩ.
*/
#ifndef __SS_ERROR_H__
#define __SS_ERROR_H__


//============================================================
//                  ģ���
//============================================================

#define MODE_H5_RUNTIME             0x01    //  H5 API�������
#define MODE_IPC                    0x02    //  IPC ģ�����
#define MODE_SS                     0x05    //  SS ģ��
#define MODE_NETAGENT               0x11    //  NetAgentģ��
#define MODE_SSPROTECT              0x12    //  SSPROTECT ģ�����
#define MODE_LM_API                 0x13    //  LM ģ��(runtime, develop, control)
#define MODE_LM_FIRM                0x22    //  LM �̼�ģ��
#define MODE_LM_SES                 0x23    //  LM SES�����
#define MODE_LM_SERVICE             0x24    //  LM SERVICEģ��
#define MODE_LIC_TRANS              0x28    //  ���ת��ģ��
#define MODE_AUTH_SERVER            0x29    //  Auth Serverģ��
#define MODE_CLOUD                  0x30    //  ����ģ��

//============================================================
//              һ�������
//============================================================

#define SS_OK                                       0x00000000  //  �ɹ�
#define SS_ERROR                                    0x00000001  //  ����ԭ��δ֪ */ // TODO(zhaock) : Ӧ��ȥ
#define SS_ERROR_INVALID_PARAM                      0x00000002  //  ���Ϸ��Ĳ���
#define SS_ERROR_MEMORY_FAIELD                      0x00000003  //  �ڴ����
#define SS_ERROR_INSUFFICIENT_BUFFER                0x00000004  //  ��������С����
#define SS_ERROR_NOT_FOUND                          0x00000005  //  û�ҵ�Ŀ��
#define SS_ERROR_EXISTED                            0x00000006  //  Ŀ���Ѵ���
#define SS_ERROR_DATA_BROKEN                        0x00000007  //  ������
#define SS_ERROR_INVALID_HANDLE                     0x00000008  //  ��Ч�ľ��
#define SS_ERROR_TIMEOUT                            0x00000009  //  ������ʱ
#define SS_ERROR_TARGET_NOT_IN_USE                  0x0000000A  //  Ŀ��δ��ʹ��״̬����Ŀ��ģ��δ�������ѹر�
#define SS_ERROR_DATA_CONFLICT                      0X0000000B  //  �����ݵ�����ͬʱ����
#define SS_ERROR_INVALID_TYPE                       0x0000000C  //  ��Ч����
#define SS_ERROR_INVALID_LENGTH                     0x0000000D  //  ��Ч����
#define SS_ERROR_USER_MOD_CRASH                     0x0000000E  //  �û�ģ���ͻ
#define SS_ERROR_SERVER_IS_LOCAL                    0x0000000F  //  ���ҵ�SS�Ǳ���
#define SS_ERROR_UNSUPPORT                          0x00000010  //  ��֧�ֵĲ���
#define SS_ERROR_PORT_IN_USE                        0x00000011  //  �˿�ռ��
#define SS_ERROR_NO_KEY                             0x00000013  //  û����Կ
#define SS_ERROR_SERVICE_TYPE_NOT_SUPPORT           0x00000014  //  �������Ͳ�֧�ֲ���
#define SS_ERROR_MULTICAST_ADDR_IN_USE              0x00000015  //  �ಥ��ַռ��
#define SS_ERROR_MULTICAST_PORT_IN_USE              0x00000016  //  �ಥ�˿�ռ��
#define SS_ERROR_MOD_FAIL_LIBSTRING                 0x00000020  //  libstring����
#define SS_ERROR_NET_ERROR                          0x00000040  //  �������
#define SS_ERROR_IPC_ERROR                          0x00000041  //  IPC ����
#define SS_ERROR_INVALID_SESSION                    0x00000042  //  �ỰʧЧ

//============================================================
//              SS ģ�� (0x05)
//============================================================

#define SS_ERROR_MOD_INIT_FAIL                      0x05000000  //  ģ���ʼ��ʧ��
#define SS_ERROR_BOUND_EXCEEDED                     0x05000001  //  ����Խ��
#define SS_ERROR_REACH_LIMIT                        0x05000002  //  �ﵽ��Ϊ����
#define SS_ERROR_IGNORE                             0x05000003  //  ��������
#define SS_ERROR_SERVER_NOT_FOUND                   0x05000004  //  �Ҳ���������
#define SS_ERROR_NO_LOCK                            0x05000005  //  �Ҳ�����
#define SS_ERROR_SLM_HANDLE_IS_FULL                 0x05000006  //  LM ����Ѵﵽ����
#define SS_ERROR_REG_NOT_FOUND                      0x05000007  //  ע�����δ�ҵ�
#define SS_ERROR_REG_ACCESS_DENIED                  0x05000008  //  ע����޷���Ȩ��
#define SS_ERROR_REG_INVALID_VALUE                  0x05000009  //  ע�����Чֵ
#define SS_ERROR_FORMAT_NOT_SUPPORTED               0x0500000A  //  ��֧�ֵĸ�ʽ
#define SS_ERROR_CONFIG_FILE_NOT_FOUND              0x0500000B  //  δ�ҵ������ļ�
#define SS_ERROR_CONFIG_PARSE_ERROR                 0x0500000C  //  �����ļ���������
#define SS_ERROR_SYSTEM_ERROR                       0x0500000D  //  ϵͳ����ʧ��
#define SS_ERROR_CREATE_THREAD_ERROR                0x0500000E  //  �����߳�ʧ��
#define SS_ERROR_SSRP_DATA_BROKEN                   0x0500000F  //  SS��Ϣ������
#define SS_ERROR_SSRP_WRONG_VERSION                 0x05000010  //  SS��Ϣ�汾��֧��
#define SS_ERROR_SSRP_INVALID_TYPE                  0x05000012  //  SS��Ϣ�������Ͳ�֧��
#define SS_ERROR_WHITELISTED                        0x05000013  //  ����������
#define SS_ERROR_BLACKLISTED                        0x05000014  //  ����������
#define SS_ERROR_FILE_ACCESS_DENIED                 0x05000015  //  �޷������ļ�
#define SS_ERROR_DEVICE_NOT_FOUND                   0x05000016  //  û�з����豸
#define SS_ERROR_DEVICE_FAIL_TO_OPEN                0x05000017  //  ���豸ʧ��
#define SS_ERROR_MSG_BAD_PACKAGE                    0x05000018  //  SS��Ϣ������
#define SS_ERROR_MSG_INVALID_TYPE                   0x05000019  //  SS��Ϣ��������Ч
#define SS_ERROR_SERVICE_INSTALL_ERROR              0x0500001A  //  ����װ����
#define SS_ERROR_SERVICE_UNINSTALL_ERROR            0x0500001B  //  ����ж�ش���
#define SS_ERROR_SERVICE_START_ERROR                0x0500001C  //  ������������
#define SS_ERROR_SERVICE_STOP_ERROR                 0x0500001D  //  ����ֹͣ����
#define SS_ERROR_SERVICE_QUERY_ERROR                0x0500001E  //  �����ѯ����
#define SS_ERROR_LOCK_NOT_FOUND                     0x0500001F  //  ��û���ҵ�
#define SS_ERROR_NO_SESSION_KEY_ERROR               0x05000020  //  û�лỰ��Կ
#define SS_ERROR_ENCRYPT_ERROR                      0x05000021  //  ���ܴ���
#define SS_ERROR_DECRYPT_ERROR                      0x05000022  //  ���ܴ���
#define SS_ERROR_DEVELOPER_NOT_FOUND                0x05000023  //  δ�ҵ�������
#define SS_ERROR_NET_PORT_BIND_ERROR                0X05000030  //  �˿ڱ�ռ��
#define SS_ERROR_BROADCAST_INIT_ERROR               0X05000031  //  �㲥ģ���ʼ������
#define SS_ERROR_BROADCAST_JOB_ERROR                0X05000030  //  �㲥ģ�����ʧ��
#define SS_ERROR_TASK_PENDING                       0x05000041  //  ��������ִ��
#define SS_ERROR_TASK_FAIL                          0x05000042  //  ����ִ��ʧ��
#define SS_ERROR_TASK_CANCELLING                    0x05000043  //  ��������ȡ��
#define SS_ERROR_TASK_CANCELLED                     0x05000044  //  ������ȡ��
#define SS_ERROR_CLOUD_AUTH                         0x05000045  //  ��֤����ʧ��

//============================================================
//          LM ģ��(0x20): (runtime, control, develop)
//============================================================

#define SS_ERROR_D2C_NO_PACKAGE                     0x13000000  //  D2C������ǩ������
#define SS_ERROR_DEVELOPER_CERT_ALREADY_EXIST       0x13000001  //  ������֤���Ѵ���
#define SS_ERROR_PARSE_CERT                         0x13000003  //  ����֤�����
#define SS_ERROR_D2C_PACKAGE_TOO_LARGE              0x13000004  //  D2C������
#define SS_ERROR_RESPONSE                           0x13000005  //  �����������Ӧ
#define SS_ERROR_SEND_LM_REMOTE_REQUEST             0x13000006  //  ����LMԶ������ʧ��
#define SS_ERROR_RUNTIME_NOT_INITIALIZE             0x13000007  //  δ����Runtime��ʼ������
#define SS_ERROR_BAD_CONNECT                        0x13000008  //  ��ȡ����ʧ��
#define SS_ERROR_RUNTIME_VERSION                    0x13000009  //  �汾��ƥ��
#define SS_ERROR_LIC_NOT_FOUND                      0x13000020  //  ���δ�ҵ�
#define SS_ERROR_AUTH_ACCEPT_FAILED                 0x13000021  //  ��֤����
#define SS_ERROR_AUTH_HANDLE_FAILED                 0x13000022  //  ��֤ʧ��
#define SS_ERROR_DECODE_BUFFER                      0x13000023  //  ���ܴ���
#define SS_ERROR_USER_DATA_TOO_SMALL                0x13000024  //  �û�������̫С
#define SS_ERROR_INVALID_LM_REQUEST                 0x13000025  //  ��Ч��LM����
#define SS_ERROR_INVALID_SHORTCODE                  0x13000026  //  ��Ч�Ķ���
#define SS_ERROR_INVALID_D2C_PACKAGE                0x13000027  //  �����D2C������
#define SS_ERROR_CLOUD_RESPONSE                     0x13000028  //  �������ص����ݴ���
#define SS_ERROR_USER_DATA_TOO_LARGE                0x13000029  //  ��д�����ݹ���
#define SS_ERROR_INVALID_MEMORY_ID                  0x1300002A  //  ��Ч���ڴ�ID
#define SS_ERROR_INVALID_MEMORY_OFFSET              0x1300002B  //  ��Ч���ڴ�ƫ��
#define SS_ERROR_INVALID_CLOUD_SERVER               0x1300002C  //  ��Ч������������
#define SS_ERROR_UNCALIBRATED_TIMESTAMP             0x1300002D  //  ʱ���δУ׼
#define SS_ERROR_GENERATE_GUID                      0x1300002F  //  ����GUID����
#define SS_ERROR_NO_LOGGED_USER                     0x13000030  //  û�е�¼���û�
#define SS_ERROR_USER_AUTH_SERVER_NOT_RUNNING       0x13000031  //  �û���֤����δ����
#define SS_ERROR_UNSUPPORTED_SNIPPET_CODE           0x13000033  //  ��֧�ֵĴ���Ƭ
#define SS_ERROR_INVALID_SNIPPET_CODE               0x13000034  //  ��Ч�Ĵ���
#define SS_ERROR_EXECUTE_SNIPPET_CODE               0x13000035  //  ִ����Ƭ����ʧ��
#define SS_ERROR_SNIPPET_EXECUTE_LOGIN              0x13000036  //  ��Ƭִ�е�¼ʧ��
#define SS_ERROR_LICENSE_MODULE_NOT_EXISTS          0x13000037  //  ���ģ�鲻����
#define SS_ERROR_DEVELOPER_PASSWORD                 0x13000038  //  ����Ŀ���������
#define SS_ERROR_CALLBACK_VERSION                   0x13000039  //  ����ĳ�ʼ���ص��汾��
#define SS_ERROR_INFO_RELOGIN                       0x1300003A  //  �û������µ�¼

//============================================================
//              IPC ģ�� (0x02)
//============================================================

#define SS_ERROR_BAD_ADDR                           0x02000000  //  ����ĵ�ַ
#define SS_ERROR_BAD_NAME                           0x02000001  //  ���������
#define SS_ERROR_IPC_FAILED                         0x02000002  //  IPC �շ�����
#define SS_ERROR_IPC_CONNECT_FAILED                 0x02000003  //  ����ʧ��
#define SS_ERROR_IPC_AUTH_INITIALIZE                0x02000004  //  Authʧ��
#define SS_ERROR_IPC_QUERY_STATE                    0x02000005  //  ��ѯSS״̬ʧ��
#define SS_ERROR_SERVICE_NOT_RUNNING                0x02000006  //  SSδ����
#define SS_ERROR_IPC_DISCONNECT_FAILED              0x02000007  //  �Ͽ�����ʧ��
#define SS_ERROR_IPC_BUILD_SESSION_KEY              0x02000008  //  �Ự��ԿЭ��ʧ��
#define SS_ERROR_REQUEST_OUTPUT_BUFFER_TOO_LARGE    0x02000009  //  �������󻺳�������
#define SS_ERROR_IPC_AUTH_ENCODE                    0x0200000A  //  Auth encode����
#define SS_ERROR_IPC_AUTH_DECODE                    0x0200000B  //  Auth decode����

//============================================================
//              Net Agent ģ�� (0x11)
//============================================================




//============================================================
//              ��ȫģ�� (0x12)
//============================================================

#define SS_ERROR_INIT_ANTIDEBUG                     0x12000005
#define SS_ERROR_DEBUG_FOUNDED                      0x12000006



//============================================================
//              LM Service (0x24)
//============================================================

#define ERROR_LM_SVC_UNINTIALIZED                   0x24000001  //  δ��ʼ�� service�еı���
#define ERROR_LM_SVC_INITIALIZING                   0x24000002  //  ���ڳ�ʼ��service��
#define ERROR_LM_SVC_INVALID_SESSION_INFO_SIZE      0x24000003  //  ����session ��С����ȷ
#define ERROR_LM_SVC_KEEP_ALIVE_FAILED              0x24000004  //  δ֪��keep alive ����ʧ��ԭ�� 
#define ERROR_LM_SVC_LICENSE_NOT_FOUND              0x24000005  //  ������û���ҵ���Ӧ���
#define ERROR_LM_SVC_SESSION_ALREADY_LOGOUT         0x24000006  //  session�Ѿ��˳� 
#define ERROR_LM_SVC_SESSION_ID_NOT_FOUND           0x24000007  //  �����ڸ�session id
#define ERROR_LM_SVC_DEBUGGED                       0x24000008  //  ���ֱ�����
#define ERROR_LM_SVC_INVALID_DESCRIPTION            0x24000009  //  ��Ч�����������Ϣ
#define ERROR_LM_SVC_HANDLE_NOT_FOUND               0x2400000A  //  �Ҳ���ָ�����
#define ERROR_LM_SVC_CACHE_OVERFLOW                 0x2400000B  //  cache ��������
#define ERROR_LM_SVC_SESSION_OVERFLOW               0x2400000C  //  session ��������
#define ERROR_LM_SVC_INVALID_SESSION                0x2400000D  //  ��Ч��session
#define ERROR_LM_SVC_SESSION_ALREADY_DELETED        0x2400000E  //  session �Ѿ���ɾ��
#define ERROR_LM_SVC_LICENCE_EXPIRED                0x2400000F  //  ����Ѿ�����
#define ERROR_LM_SVC_SESSION_TIME_OUT               0x24000010  //  session��ʱ
#define ERROR_LM_SVC_NOT_ENOUGH_BUFF                0x24000011  //  ��������С����
#define ERROR_LM_SVC_DESC_NOT_FOUND                 0x24000012  //  û�ҵ����豸����
#define ERROR_LM_INVALID_PARAMETER                  0x24000013  //  LM service��������
#define ERROR_LM_INVALID_LOCK_TYPE                  0x24000014  //	�����Ͳ�֧��
#define ERROR_LM_REMOTE_LOGIN_DENIED                0x24000015  //  ��ɲ�����Զ�̵�¼
#define ERROR_LM_SVC_SESSION_INVALID_AUTHCODE       0x24000016  //  session��֤ʧ��
#define ERROR_LM_SVC_ACCOUNT_NOT_BOUND              0x24000017  //  �˻�δ��


//============================================================
//              LM Native (0x21)
//============================================================

#define SS_ERROR_UNSUPPORTED_ALGORITHM              0x21000000  //  ��֧�ֵ��㷨����
#define SS_ERROR_INVAILD_HLC_HANDLE                 0x21000001  //  ��Ч��HLC���
#define SS_ERROR_HLC_CHECK                          0x21000002  //  HLC���ʧ��
#define SS_ERROR_LM_CHECK_READ                      0x21000003  //  ����־λ���ʧ��
#define SS_ERROR_LM_CHECK_LICENSE                   0x21000004  //  ������������ID��ƥ��
#define SS_ERROR_LM_CHECKSUM                        0x21000005  //  ���������У��ʧ��
#define SS_ERROR_HLC_BUFFER_LEN                     0x21000006  //  HLC���ݼ��ܴ������Ļ�����
#define SS_ERROR_L2CWF_LEN                          0x21000007  //  ��Ч�ļ��ܳ���
#define SS_ERROR_INVAILD_MAX_ENCRYPT_LENGTH         0x21000008  //  ��Ч�ļ��ܳ���
#define SS_ERROR_INVAILD_ENUM_CRYPT_TYPE            0x21000009  //  ��֧�ֵļ�������
#define SS_ERROR_NATIVE_INSUFFICIENT_BUFFER         0x2100000A  //  ����������
#define SS_ERROR_NATIVE_LIST_FILE_FAILED            0x2100000B  //  ö�������ļ�����
#define SS_ERROR_INVALID_C2H_REQUEST                0x2100000C  //  ��Ч��������Ӳ��������

//============================================================
//              LM Firmware (0x22)
//============================================================

#define SS_ERROR_FIRM_INVALID_FILE_NAME             0x22000001  // �ļ�������Ч                                        
#define SS_ERROR_FIRM_CHECK_BUFF_FAILED             0x22000002  // ����У��ʧ��
#define SS_ERROR_FIRM_INVALID_BUFF_LEN              0x22000003  // �������ݳ��ȴ���
#define SS_ERROR_FIRM_INVALID_PARAM                 0x22000004  // ��������
#define SS_ERROR_FIRM_INVALID_SESSION_INFO          0x22000005  // session ��Ϣ����
#define SS_ERROR_FIRM_INVALID_FILE_SIZE             0x22000006  // �����ļ����ȳ���
#define SS_ERROR_FIRM_WRITE_FILE_FAILED             0x22000007  // д���ļ����ݳ���
#define SS_ERROR_FIRM_INVALID_LICENCE_HEADER        0x22000008  // �����Ϣͷ������
#define SS_ERROR_FIRM_INVALID_LICENCE_SIZE          0x22000009  // �����Ϣ���ݴ���  
#define SS_ERROR_FIRM_INVALID_LICENCE_INDEX         0x2200000A  // ����֧�����������                                     
#define SS_ERROR_FIRM_LIC_NOT_FOUND                 0x2200000B  // û���ҵ���Ӧ�����
#define SS_ERROR_FIRM_MEM_STATUS_INVALID            0x2200000C  // �ڴ�״̬����δ��ʼ��
#define SS_ERROR_FIRM_INVALID_LIC_ID                0x2200000D  // �����õ���ɺ�
#define SS_ERROR_FIRM_LICENCE_ALL_DISABLED          0x2200000E  // ������ɱ�����
#define SS_ERROR_FIRM_CUR_LICENCE_DISABLED          0x2200000F  // ��ǰ��ɱ�����
#define SS_ERROR_FIRM_LICENCE_INVALID               0x22000010  // ��ǰ��ɲ�����
#define SS_ERROR_FIRM_LIC_STILL_UNAVALIABLE         0x22000011  // ����в�����
#define SS_ERROR_FIRM_LIC_TERMINATED                0x22000012  // ����Ѿ�����
#define SS_ERROR_FIRM_LIC_RUNTIME_TIME_OUT          0x22000013  // ����ʱ���þ�
#define SS_ERROR_FIRM_LIC_COUNTER_IS_ZERO           0x22000014  // �����þ�
#define SS_ERROR_FIRM_LIC_MAX_CONNECTION            0x22000015  // �Ѵﵽ��󲢷���Ȩ
#define SS_ERROR_FIRM_INVALID_LOGIN_COUNTER         0x22000016  // ����ȷ�ĵ�¼����
#define SS_ERROR_FIRM_REACHED_MAX_SESSION           0x22000017  // �����Ѿ��������Ự����
#define SS_ERROR_FIRM_INVALID_TIME_INFO             0x22000018  // ͨѶʱ����Ϣ����
#define SS_ERROR_FIRM_SESSION_SIZE_DISMATCH         0x22000019  // session ��Ϣ��С��ƥ��
#define SS_ERROR_FIRM_NOT_ENOUGH_SHAREMEMORY        0x2200001A  // û���㹻�Ĺ����ڴ�
#define SS_ERROR_FIRM_INVALID_OPCODE                0x2200001B  // �����õĲ�����
#define SS_ERROR_FIRM_INVALID_DATA_LEN              0x2200001C  // ����������ļ�����    
#define SS_ERROR_FIRM_DATA_FILE_NOT_FOUND           0x2200001E  // �Ҳ�����Ӧ����������ļ�
#define SS_ERROR_FIRM_INVALID_PKG_TYPE              0x2200001F  // Զ�����������ʹ���
#define SS_ERROR_FIRM_INVALID_TIME_STAMP            0x22000020  // ʱ��������Զ��������
#define SS_ERROR_FIRM_INVALID_UPD_LIC_ID            0x22000021  // �����Զ������������
#define SS_ERROR_FIRM_LIC_ALREADY_EXIST             0x22000022  // ��ӵ�����Ѿ�����
#define SS_ERROR_FIRM_LICENCE_SIZE_LIMITTED         0x22000023  // �����������
#define SS_ERROR_FIRM_INVALID_DATA_FILE_OFFSET      0x22000024  // ��Ч����������ļ�ƫ��
#define SS_ERROR_FIRM_ZERO_INDEX_LIC_DESTROY        0x22000025  // ��������
#define SS_ERROR_FIRM_LIC_ALREADY_DISABLED          0x22000026  // ���ԭ�Ѿ�����ֹ
#define SS_ERROR_FIRM_INVALID_UPD_OPCODE            0x22000027  // ��Ч��Զ������������
#define SS_ERROR_FIRM_LIC_ALREADY_ENABLED           0x22000028  // ���ԭ�Ѿ���Ч
#define SS_ERROR_FIRM_INVALID_PKG_SIZE              0x22000029  // Զ�����������Ȳ���ȷ
#define SS_ERROR_FIRM_LIC_COUNT_RETURN              0x2200002A  // �����˴������ɼ���
#define SS_ERROR_FIRM_INVALID_OPERATION             0x2200002B  // ִ���˲���ȷ�Ĳ���
#define SS_ERROR_FIRM_SESSION_ALREADY_LOGOUT        0x2200002C  // session�Ѿ��˳���¼
#define SS_ERROR_FIRM_EXCHANGE_KEY_TIMEOUT          0x2200002D  // ������Կ��ʱ
#define SS_ERROR_FIRM_INVALID_EXCHANGE_KEY_MAGIC    0x2200002E  // ����Ľ�����Կħ��
#define SS_ERROR_FIRM_INVALID_AUTH_CODE             0x2200002F  // ��֤���ݴ���
#define SS_ERROR_FIRM_CONVERT_INDEX_TO_FILE         0x22000030  // ת��lic��ŵ��ļ�����ʧ��
#define SS_ERROR_FIRM_INVALID_USER_DATA_TYPE        0x22000031  // �û��Զ����ֶ����ʹ���
#define SS_ERROR_FIRM_INVALID_DATA_FILE_SIZE        0x22000032  // �û��Զ����������
#define SS_ERROR_FIRM_INVALID_CCRNT_OPR_TYPE        0x22000033  // ����Ĳ���������������
#define SS_ERROR_FIRM_ALL_LIC_TERMINATED            0x22000034  // �������ʱ�䵽�ڲ�����
#define SS_ERROR_FIRM_INVALID_CCRNT_VALUE           0x22000035  // ����Ĳ�������
#define SS_ERROR_FIRM_INVALID_UPD_FILE              0x22000036  // �����õ�ɾ����ʷ��¼�ļ�
#define SS_ERROR_FIRM_UPD_RECORD_FULL               0x22000037  // ���¼�¼�ﵽ���ֵ
#define SS_ERROR_FIRM_UPDATE_FAILED                 0x22000038  // Զ������ʧ��
#define SS_ERROR_FIRM_LICENSE_BEING_WRITTING        0x22000039  // ��������ڱ�д��
#define SS_ERROR_FIRM_INVALID_PKG_FIELD_TYPE        0x2200003A  // �����������ʹ���
#define SS_ERROR_FIRM_LOAT_FSM_SALT                 0x2200003B  // ������ֵ�ļ�����
#define SS_ERROR_FIRM_DATA_LENGTH_ALIGNMENT         0x2200003C  // �ӽ������ݳ��Ȳ�����
#define SS_ERROR_FIRM_DATA_CRYPTION                 0x2200003D  // �ӽ������ݴ���
#define SS_ERROR_FIRM_SHORTCODE_UPDATE_NOT_SUPPORTED    0x2200003E  // ��֧�ֶ�������
#define SS_ERROR_FIRM_INVALID_SHORTCODE             0x2200003F  // �����õĶ���
#define SS_ERROR_FIRM_LIC_USR_DATA_NOT_EXIST        0x22000040  // �û��Զ������ݲ�����
#define SS_ERROR_FIRM_RCD_FILE_NOT_INITIALIZED      0x22000041  // ɾ����¼�ļ�δ��ʼ��
#define SS_ERROR_FIRM_AUTH_FILE_NOT_FOUND           0x22000042  // ��֤�ļ��Ҳ���
#define SS_ERROR_FIRM_SESSION_OVERFLOW              0x22000043  // session�Ự��������ڲ����Ʋ���ʱ���³�����������
#define SS_ERROR_FIRM_TIME_OVERFLOW                 0x22000044  // ʱ����Ϣ�����������������pcʱ�䱻�����޸�����
#define SS_ERROR_FIRM_REACH_FILE_LIS_END            0x22000045  // ö�ٵ������һ���ļ�
#define SS_ERROR_FIRM_ANTI_MECHANISM_ACTIVED        0x22000046  // �ͷ�������������lm
#define SS_ERROR_FIRM_NO_BLOCK                      0x22000047  // ��ȡblock����
#define SS_ERROR_FIRM_NOT_ENDED                     0x22000048  // ����δ�������   (���������)
#define SS_ERROR_FIRM_LIC_ALREADY_ACTIVE            0x22000049  // ����Ѿ�����
#define SS_ERROR_FIRM_FILE_NOT_FOUND                0x22000050  // �Ҳ����ļ�
#define SS_ERROR_FIRM_UNKNOW_USER_DATA_TYPE         0x22000051  // δ֪���û���������
#define SS_ERROR_FIRM_INVALID_TF_CODE               0x22000052  // �����ת�Ʋ�����
#define SS_ERROR_FIRM_UNMATCH_GUID                  0x22000053  // ��ƥ���GUID 
#define SS_ERROR_FIRM_UNABLE_TRANSFER               0x22000054  // ��ɲ��ɽ���ת��
#define SS_ERROR_FIRM_INVALID_TRANSCODE             0x22000055  // ����ʶ��������
#define SS_ERROR_FIRM_ACCOUNT_NAME_NOT_FOUND        0x22000056  // �û���δ�ҵ�
#define SS_ERROR_FIRM_ACCOUNT_ID_NOT_FOUND          0x22000057  // �˻�idδ�ҵ�
#define SS_ERROR_FIRM_INVALID_XKEY_STEP             0x22000058  // �������Կ��������
#define SS_ERROR_FIRM_INVLAID_DEVELOPER_ID          0x22000059  // ��Ч�Ŀ�����ID
#define SS_ERROR_FIRM_CA_TYPE                       0x2200005A  // CA���ʹ���
#define SS_ERROR_FIRM_LIC_TRANSFER_FAILURE          0x2200005B  // ���ת��ʧ��
#define SS_ERROR_FIRM_TF_PACKAGE_VERSION            0x2200005C  // ת�ư��汾�Ŵ���
#define SS_ERROR_FIRM_BEYOND_PKG_ITEM_SIZE          0x2200005D  // �����������������
#define SS_ERROR_FIRM_UNBOUND_ACCOUNT_INFO          0x2200005E  // �˻�δ��

//============================================================
//              MODE LIC TRANS ģ��()0x28
//============================================================
#define SS_ERROR_LIC_TRANS_NO_SN_DESC               0x28000001  // δ�ҵ���������Ϣ
#define SS_ERROR_LIC_TRANS_INVALID_DATA             0x28000002  // ���ݸ�ʽ����

//============================================================
//              AUTH SERVER ģ�� (0x29)
//============================================================

#define SS_ERROR_AUTH_SERVER_INVALID_TOKEN          0x29000001  //��Ч��token
#define SS_ERROR_AUTH_SERVER_REFRESH_TOKEN          0x29000002  //ˢ��tokenʧ��
#define SS_ERROR_AUTH_SERVER_LOGIN_CANCELED         0x29000003  //�û�ȡ����½
#define SS_ERROR_AUTH_SERVER_GET_ALL_USER_INFO_FAIL 0x29000004  //��ȡ�����û���Ϣʧ��

//============================================================
//              Cloud ģ�� (0x30)
//============================================================

#define SS_CLOUD_OK                                 0x30000000  //  �ɹ�
#define SS_ERROR_CLOUD_INVALID_PARAMETER            0x30000001  //  ��������
#define SS_ERROR_CLOUD_QUERY_UESR_INFO              0x30000002  //  ��ѯ�û���Ϣʧ��
#define SS_ERROR_CLOUD_INVALID_LICENSE_SESSION      0x30000003  //  ���δ��¼���ѳ�ʱ
#define SS_ERROR_CLOUD_DATA_EXPIRED                 0x30000004  //  �����ѹ���
#define SS_ERROR_CLOUD_VERIFY_TIMESTAMP_SIGNATURE   0x30000005  //  ʱ���ǩ����֤ʧ��
#define SS_ERROR_CLOUD_AUTH_FAILED                  0x30000006  //  �˵�����֤ʧ��
#define SS_ERROR_CLOUD_NOT_BOUND                    0x30000007  //  �㷨�����ڻ�δ��
#define SS_ERROR_CLOUD_EXECUTE_FAILED               0x30000008  //  �㷨ִ��ʧ��
#define SS_ERROR_CLOUD_INVALID_TOKEN                0x30000010  //  ���Ϸ���token
#define SS_ERROR_CLOUD_LICENSE_ALREADY_LOGIN        0x30000011  //  ����ѵ�½
#define SS_ERROR_CLOUD_LICENSE_EXPIRED              0x30000012  //  ����ѵ���
#define SS_ERROR_CLOUD_SESSION_KICKED               0x30000013  //  ����ѱ��������Ե�¼
#define SS_ERROR_CLOUD_INVALID_SESSSION             0x30001002  //  ��Ч��session
#define SS_ERROR_CLOUD_SESSION_TIMEOUT              0x30001004  //  �Ự��ʱ
#define SS_ERROR_CLOUD_PARSE_PARAM                  0x30001007  //  ������������
#define SS_ERROR_CLOUD_LICENSE_LOGIN_SUCCESS        0x31001000  //  ��ɵ�¼�ɹ�
#define SS_ERROR_CLOUD_LICENSE_NOT_EXISTS           0x31001001  //  ��ɲ�����
#define SS_ERROR_CLOUD_LICENSE_NOT_ACTIVE           0x31001002  //  ���δ����
#define SS_ERROR_CLOUD_LICENSE_EXPIRED2             0x31001003  //  ����ѹ���
#define SS_ERROR_CLOUD_LICENSE_COUNTER_IS_ZERO      0x31001004  //  �����ʹ�ô���
#define SS_ERROR_CLOUD_LICENSE_RUNTIME_TIME_OUT     0x31001005  //  �����ʹ��ʱ��
#define SS_ERROR_CLOUD_LICENSE_MAX_CONNECTION       0x31001006  //  ��ɲ���������
#define SS_ERROR_CLOUD_LICENSE_LOCKED               0x31001007  //  ��ɱ�����
#define SS_ERROR_CLOUD_LICENSE_DATA_NOT_EXISTS      0x31001008  //  ������ݲ�����
#define SS_ERROR_CLOUD_LICENSE_STILL_UNAVAILABLE    0x31001010  //  ���δ����ʼʹ��ʱ��
#define SS_ERROR_CLOUD_ZERO_LICENSE_NOT_EXISTS      0x31001011  //  0����ɲ�����
#define SS_ERROR_CLOUD_VERIFY_LICENSE               0x31001012  //  �����֤ʧ��
#define SS_ERROR_CLOUD_EXECUTE_FILE_NOT_EXISTS      0x31002000  //  �㷨������
#define SS_ERROR_CLOUD_LICENSE_NOT_BOUND            0x31003001  //  �㷨δ��

// ��
#define MAKE_ERROR(mode, errcode)           (((mode) << 24) | (errcode))
#define MAKE_COMMON_ERROR(mode, errcode)    (((mode) << 24) | (errcode))
#define MAKE_H5_RUNTIME(errorcode)          (((errorcode)==H5_ERROR_SUCCESS) ? 0 : (MAKE_COMMON_ERROR(MODE_H5_RUNTIME,(errorcode))))
#define MAKE_NETAGENT(errorcode)            MAKE_COMMON_ERROR(MODE_NETAGENT,(errorcode))
#define MAKE_SSPROTECT(errorcode)           MAKE_COMMON_ERROR(MODE_NETAGENT,(errorcode))
#define MAKE_LM_FIRM_ERROR(errorcode)       MAKE_COMMON_ERROR(MODE_LM_FIRM,(errorcode))
#define MAKE_LM_SES_ERROR(errorcode)        MAKE_COMMON_ERROR(MODE_LM_SES,(errorcode))
#define GET_ERROR_MODULE(errorcode)          ((errorcode) >> 24)


#endif //__SS_ERROR_H__
