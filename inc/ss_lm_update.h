
#ifndef _SS_LM_UPDATE_H
#define _SS_LM_UPDATE_H

#include "ss_define.h"

#ifdef __cplusplus
extern "C"{
#endif
/*!
*   @brief  ��D2C����������
*   @param[in]  d2c_pkg     d2c�ļ�����
*   @param[out] error_msg   ������Ϣ����ʹ����Ҫ����slm_free�ͷ�
*   @return �ɹ�����SS_OK��ʧ�ܷ��ش�����
*   @remarks:   error_msg���������ݣ�JSON����
*   @code
*   [
*   {"pkg_order":1, "pkg_desc":"package decription.", "status": 0},
*   {"pkg_order":2, "pkg_desc":"package decription.", "status": 0}
*   ]
*   @endcode
*   @see    slm_update 
*/
SS_UINT32 SSAPI slm_update(char* d2c_pkg, char** error_msg);

/*!
*   @brief  ��D2C����������
*   @param[in]  lock_sn     ����
*   @param[in]  d2c_pkg     d2c�ļ�����
*   @param[out] error_msg   ������Ϣ����ʹ����Ҫ����slm_free�ͷ�
*   @return �ɹ�����SS_OK��ʧ�ܷ��ش�����
*   @remarks:   error_msg���������ݣ�JSON����
*   @code
*   [
*   {"pkg_order":1, "pkg_desc":"package decription.", "status": 0},
*   {"pkg_order":2, "pkg_desc":"package decription.", "status": 0}
*   ]
*   @endcode
*   @see    slm_update slm_update_short_code
*/
SS_UINT32 SSAPI slm_update_ex(SS_BYTE* lock_sn, char* d2c_pkg, char** error_msg);

/*!
*   @brief  ��������
*   @param[in]  short_code  �����ַ���
*   @param[in]  short_code_len ���볤��
*   @param[in]  lock_sn     ����
*   @param[in]  developer_id    ������ID
*   @return �ɹ�����SS_OK��ʧ�ܷ�����Ӧ������
*/
SS_UINT32 SSAPI slm_update_short_code(
    SS_BYTE*    short_code,
    SS_UINT32   short_code_len,
    SS_BYTE*    lock_sn,
    SS_BYTE*    developer_id
    );

/*!
*	@param[in]	d2c_stream	d2c������
*	@param[out]	d2c_buffer  ���հ������Ļ�����
*	@param[in]	max_buf_len d2c_buffer�Ĵ�С
*	@param[out]	out_buf_len ��ȡ�İ������Ĵ�С
*	@return		�ɹ�����SS_OK��ʧ�ܷ�����Ӧ�Ĵ�����
*	@remark d2c_buffer JSONʾ��
*   @code
*   {"serial": "0102030405060708", "pkg":
*       [{"pkg_order": 1, "pkg_desc":"add_pkg"},
*       {"pkg_order":2, "pkg_desc": "delete_pkg"}]
*   }
*   @endcode
*/
SS_UINT32 SSAPI package_parse( const char* d2c_stream, char* d2c_buffer, int max_buf_len, int* out_buf_len);

#ifdef __cplusplus
}
#endif


#endif