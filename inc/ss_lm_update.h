
#ifndef _SS_LM_UPDATE_H
#define _SS_LM_UPDATE_H

#include "ss_define.h"

#ifdef __cplusplus
extern "C"{
#endif
/*!
*   @brief  将D2C包进行升级
*   @param[in]  d2c_pkg     d2c文件数据
*   @param[out] error_msg   错误信息，不使用需要调用slm_free释放
*   @return 成功返回SS_OK，失败返回错误码
*   @remarks:   error_msg的数据内容（JSON）：
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
*   @brief  将D2C包进行升级
*   @param[in]  lock_sn     锁号
*   @param[in]  d2c_pkg     d2c文件数据
*   @param[out] error_msg   错误信息，不使用需要调用slm_free释放
*   @return 成功返回SS_OK，失败返回错误码
*   @remarks:   error_msg的数据内容（JSON）：
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
*   @brief  升级短码
*   @param[in]  short_code  短码字符串
*   @param[in]  short_code_len 短码长度
*   @param[in]  lock_sn     锁号
*   @param[in]  developer_id    开发商ID
*   @return 成功返回SS_OK，失败返回相应错误码
*/
SS_UINT32 SSAPI slm_update_short_code(
    SS_BYTE*    short_code,
    SS_UINT32   short_code_len,
    SS_BYTE*    lock_sn,
    SS_BYTE*    developer_id
    );

/*!
*	@param[in]	d2c_stream	d2c数据流
*	@param[out]	d2c_buffer  接收包描述的缓冲流
*	@param[in]	max_buf_len d2c_buffer的大小
*	@param[out]	out_buf_len 获取的包描述的大小
*	@return		成功返回SS_OK，失败返回相应的错误码
*	@remark d2c_buffer JSON示例
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