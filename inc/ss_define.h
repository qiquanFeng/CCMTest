/*! 
*  @file ss_error.h
*  @brief     SS�������������ƶ��塣
*  
*/
#ifndef __SS_DEFINE_H__
#define __SS_DEFINE_H__

typedef unsigned long long  SS_UINT64;
typedef unsigned int    SS_UINT32;
typedef unsigned short  SS_UINT16;
typedef unsigned char   SS_UINT8;

typedef long long       SS_INT64;
typedef int             SS_INT32;
typedef short           SS_INT16;
typedef char            SS_INT8;

typedef unsigned char   SS_BYTE;
typedef char            SS_CHAR;
typedef int             SS_BOOL;


#ifndef         IN
#define         IN
#endif

#ifndef         OUT
#define         OUT
#endif

#ifndef SSAPI
  #if defined WIN32 || defined _WIN32 || defined _WIN64
    #define SSAPI __stdcall
  #else
    #define SSAPI
  #endif
#endif

/** ������ʽö��  */
typedef enum _INFO_FORMAT_TYPE {

    /** JSON��ʽ  */
    JSON = 2,
    /** �ṹ���ʽ  */
    STRUCT = 3,
    /**  �ַ���ģʽ,����Key=value  */
    STRING_KV = 4,
    /** ���ܶ����Ƹ�ʽ*/
    CIPHER = 5,
} INFO_FORMAT_TYPE;

#endif //__SS_DEFINE_H__
