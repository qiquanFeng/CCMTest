#pragma once
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#include "../include/rapidjson/rapidjson.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"

#ifdef SOCKET_JSL_EXPORTS
#define socket_jsl_api __declspec(dllexport)
#else
#define socket_jsl_api __declspec(dllimport)
#endif


//extern "C" socket_jsl_api int init(SOCKET &sock,char *pcIP, int nPort);
//extern "C" socket_jsl_api int commit(IN SOCKET &sock,IN char *pucSendBuff,OUT char *pucRecvBuff);
//extern "C" socket_jsl_api int clean(SOCKET* pSocket);