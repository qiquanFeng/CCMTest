#ifndef JIGBOARDFUNCTION_H
#define JIGBOARDFUNCTION_H

#include "inc/HisFX3Platform.h"

struct _JIGSPRDVersionStruct{
	unsigned char ucCoreVersion;
	unsigned short usPixelNumber;//big endian
	unsigned char ucISP;
	unsigned char ucSensorMaker;
	unsigned char ucYear;
	unsigned char ucMonth;
	unsigned short usReleaseNumber;//big endian
	unsigned char ucMID;
	unsigned char ucModuleVersion;
};

void jigboard_FillVersionStruct(unsigned char* pucData, _JIGSPRDVersionStruct& stStruct)
{
	stStruct.ucCoreVersion	=	pucData[0];
	stStruct.usPixelNumber	=	pucData[1];
	stStruct.usPixelNumber	=	(stStruct.usPixelNumber <<8) | pucData[2];
	stStruct.ucISP	=	pucData[3];
	stStruct.ucSensorMaker	=	pucData[4];
	stStruct.ucYear	=	pucData[5];
	stStruct.ucMonth	=	pucData[6];
	stStruct.usReleaseNumber	=	pucData[7];
	stStruct.usReleaseNumber	=	(stStruct.usReleaseNumber <<8) | pucData[8];
	stStruct.ucMID	=	pucData[9];
	stStruct.ucModuleVersion	=	pucData[10];
}

bool jigboard_isSameVersionStruct(_JIGSPRDVersionStruct& stStruct1, _JIGSPRDVersionStruct& stStruct2)
{
	return ((stStruct1.ucCoreVersion == stStruct2.ucCoreVersion) && (stStruct1.usPixelNumber == stStruct2.usPixelNumber) && \
		(stStruct1.ucISP == stStruct2.ucISP) && (stStruct1.ucSensorMaker == stStruct2.ucSensorMaker) && \
		(stStruct1.ucYear == stStruct2.ucYear) && (stStruct1.ucMonth == stStruct2.ucMonth) && \
		(stStruct1.usReleaseNumber == stStruct2.usReleaseNumber) && (stStruct1.ucMID == stStruct2.ucMID) && \
		(stStruct1.ucModuleVersion == stStruct2.ucModuleVersion));
}

unsigned __int32 jigboard_get_crc32(unsigned __int32 crcint, unsigned char *bs, unsigned __int32 bssize)
{
	const unsigned __int32 crc32_table[] =
	{
		0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
		0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
		0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
		0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
		0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
		0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
		0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
		0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
		0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
		0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
		0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
		0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
		0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
		0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
		0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
		0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
		0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
		0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
		0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
		0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
		0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
		0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
		0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
		0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
		0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
		0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
		0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
		0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
		0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
		0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
		0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
		0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
		0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
		0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
		0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
		0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
		0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
		0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
		0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
		0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
		0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
		0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
		0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
	};

	unsigned __int32 crc = crcint ^ 0xffffffff;
	while(bssize--)
		crc=(crc >> 8) ^ crc32_table[(crc & 0xff) ^ *bs++];

	return crc ^ 0xffffffff;
}

int jigboard_GetAFFoucsPos(int& iPos, unsigned int uiType, CHisFX3Platform* pclassPlatform)
{
	iPos	=	0x00FFFFFF;
	//uiType =0--near  uiType=1-middle uiType=2--far
	wchar_t Jig_strIniPath[MAX_PATH]		=	L".\\RolongoJigboard.ini";
	wchar_t jig_strAppName[32];
	if(uiType == 1) swprintf(jig_strAppName, L"AF MIDDLE");
	else if(uiType == 2) swprintf(jig_strAppName, L"AF FAR");
	else swprintf(jig_strAppName, L"AF NEAR");
	unsigned int uiDelay	=	::GetPrivateProfileIntW(jig_strAppName, L"af_waittime", 3000, Jig_strIniPath);
	if (pclassPlatform->Jig_StartAf(pclassPlatform->Jig_m_uPhoneIndex) != TOtpResult::Success) return HisCCMError_AF;

	::Sleep(100);
	int iLoop	=	uiDelay /100;
	bool bAF	=	false;
	while(iLoop){
		--iLoop;
		TOtpResult::E eResult = pclassPlatform->Jig_GetAfState(pclassPlatform->Jig_m_uPhoneIndex);
		if(eResult == TOtpResult::Success){
			bAF	=	true;
			break;
		}
		::Sleep(100);
	}

	if(!bAF)	return HisFX3Error_Timeout;

	TOtpSetting stOtpSetting = {0};
	if (pclassPlatform->Jig_ReadSetting(pclassPlatform->Jig_m_uPhoneIndex, &stOtpSetting) != TOtpResult::Success)
		return HisCCMError_AF;

	iPos	=	stOtpSetting.uAfPosition;
	return 0;
}

int jigboard_AFBurn_Write_Rule1(int iNearPos, int iFarPos, CHisFX3Platform* pclassPlatform)
{
	TOtpBuffer m_stCalibrationOtpBuffer;
	memset(&m_stCalibrationOtpBuffer,	0,	sizeof(TOtpBuffer));

	 if (pclassPlatform->Jig_ReadCalibratedOtpPart(pclassPlatform->Jig_m_uPhoneIndex, 0, 8192, &m_stCalibrationOtpBuffer) != TOtpResult::Success){
		 pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		 return HisCCMError_readIIC;
	 }

	 if(m_stCalibrationOtpBuffer.uLength != 8192){
		 pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		  return HisCCMError_readIIC;
	 }

	 if(pclassPlatform->Jig_EraseEFlash(pclassPlatform->Jig_m_uPhoneIndex) != TOtpResult::Success){
		 pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		 return HisCCMError_OtpWrite;
	 }
	 ::Sleep(10);

	 pclassPlatform->Jig_SaveFile(L".\\Jig_BeforeWrite_Read.bin", &m_stCalibrationOtpBuffer);

	 unsigned char* pucData	=	(unsigned char*)(m_stCalibrationOtpBuffer.pData);
	 pucData[0x010c]	=	(iNearPos &0x00ff);
	 pucData[0x010d]	=	(iNearPos >>8);
	 pucData[0x010e]	=	0;
	 pucData[0x010f]	=	0;

	 pucData[0x0110]	=	(iFarPos &0x00ff);
	 pucData[0x0111]	=	(iFarPos >>8);
	 pucData[0x0112]	=	0;
	 pucData[0x0113]	=	0;

	 unsigned int uiOEMCheckGet	=	jigboard_get_crc32(0, pucData+0x0100, 0x015F-0x0100+1);
	 pucData[0x08FC]	=		uiOEMCheckGet & 0xFF;
	 pucData[0x08FD]	=		(uiOEMCheckGet >> 8) & 0xFF;
	 pucData[0x08FE]	=		(uiOEMCheckGet >> 16) & 0xFF;
	 pucData[0x08FF]	=		(uiOEMCheckGet >> 24) & 0xFF;


	 if (pclassPlatform->Jig_WriteCalibratedOtpPart(pclassPlatform->Jig_m_uPhoneIndex, 0, &m_stCalibrationOtpBuffer) != TOtpResult::Success){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		 return HisCCMError_OtpWrite;
	 }

	  pclassPlatform->Jig_SaveFile(L".\\Jig_Write.bin", &m_stCalibrationOtpBuffer);

	pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
	return 0;
}

int jigboard_AFBurn_Read_Rule1(int& iNearPos, int& iFarPos, CHisFX3Platform* pclassPlatform)
{
	TOtpBuffer m_stCalibrationOtpBuffer;
	memset(&m_stCalibrationOtpBuffer,	0,	sizeof(TOtpBuffer));

	if (pclassPlatform->Jig_ReadCalibratedOtpPart(pclassPlatform->Jig_m_uPhoneIndex, 0, 8192, &m_stCalibrationOtpBuffer) != TOtpResult::Success){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_readIIC;
	}

	if(m_stCalibrationOtpBuffer.uLength != 8192){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_readIIC;
	}

	pclassPlatform->Jig_SaveFile(L".\\Jig_Check_Read.bin", &m_stCalibrationOtpBuffer);
	unsigned char* pucData	=	(unsigned char*)(m_stCalibrationOtpBuffer.pData);

	iNearPos	=	pucData[0x010d];
	iNearPos	=	(iNearPos <<8);
	iNearPos	|=	pucData[0x010c];

	iFarPos	=	pucData[0x0111];
	iFarPos	=	(iFarPos <<8);
	iFarPos	|=	pucData[0x0110];

	pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
	return 0;
}

int jigboard_OTPCheck_Rule1(CHisFX3Platform* pclassPlatform)
{
	TOtpBuffer m_stCalibrationOtpBuffer;
	memset(&m_stCalibrationOtpBuffer,	0,	sizeof(TOtpBuffer));

	if (pclassPlatform->Jig_ReadCalibratedOtpPart(pclassPlatform->Jig_m_uPhoneIndex, 0, 8192, &m_stCalibrationOtpBuffer) != TOtpResult::Success){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_readIIC;
	}
	if(m_stCalibrationOtpBuffer.uLength != 8192){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_readIIC;
	}

	pclassPlatform->Jig_SaveFile(L".\\Jig_Check_Read.bin", &m_stCalibrationOtpBuffer);

	unsigned char* pucData	=	(unsigned char*)(m_stCalibrationOtpBuffer.pData);
	unsigned int uiHeaderCheckBurn	=	pucData[0x00FF];
	uiHeaderCheckBurn	=	(uiHeaderCheckBurn <<8) | pucData[0x00FE];
	uiHeaderCheckBurn	=	(uiHeaderCheckBurn <<8) | pucData[0x00FD];
	uiHeaderCheckBurn	=	(uiHeaderCheckBurn <<8) | pucData[0x00FC];
	unsigned int uiHeaderCheckGet	=	jigboard_get_crc32(0, pucData+0, 0x5F-0x00+1);

	unsigned int uiOEMCheckBurn	=	pucData[0x08FF];
	uiOEMCheckBurn	=	(uiOEMCheckBurn <<8) | pucData[0x08FE];
	uiOEMCheckBurn	=	(uiOEMCheckBurn <<8) | pucData[0x08FD];
	uiOEMCheckBurn	=	(uiOEMCheckBurn <<8) | pucData[0x08FC];
	unsigned int uiOEMCheckGet	=	jigboard_get_crc32(0, pucData+0x0100, 0x015F-0x0100+1);

	unsigned int uiAWBCheckBurn	=	pucData[0x09FF];
	uiAWBCheckBurn	=	(uiAWBCheckBurn <<8) | pucData[0x09FE];
	uiAWBCheckBurn	=	(uiAWBCheckBurn <<8) | pucData[0x09FD];
	uiAWBCheckBurn	=	(uiAWBCheckBurn <<8) | pucData[0x09FC];
	unsigned int uiAWBCheckGet	=	jigboard_get_crc32(0, pucData+0x0900, 0x091F-0x0900+1);

	unsigned int uiShadingCheckBurn	=	pucData[0x12FF];
	uiShadingCheckBurn	=	(uiShadingCheckBurn <<8) | pucData[0x12FE];
	uiShadingCheckBurn	=	(uiShadingCheckBurn <<8) | pucData[0x12FD];
	uiShadingCheckBurn	=	(uiShadingCheckBurn <<8) | pucData[0x12FC];
	unsigned int uiShadingCheckGet	=	jigboard_get_crc32(0, pucData+0x0A00, 0x12CF-0x0A00+1);

	if(uiOEMCheckBurn != uiOEMCheckGet || uiHeaderCheckBurn != uiHeaderCheckGet || uiAWBCheckBurn != uiAWBCheckGet || uiShadingCheckBurn != uiShadingCheckGet){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_OTPCheckSum;
	}

	_JIGSPRDVersionStruct stStandVersion, stHeaderVersion, stOEMVersion, stAWBVersion, stShadingVersion;
	stStandVersion.ucCoreVersion	=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Core_Version", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucISP					=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"ISP", 0, L".\\RolongoJigboard.ini");
	stStandVersion.usPixelNumber	=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Pixel_Number", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucSensorMaker					=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Sensor_Maker", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucYear	=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Year", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucMonth					=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Month", 0, L".\\RolongoJigboard.ini");
	stStandVersion.usReleaseNumber	=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Release_Number", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucMID					=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Manufacturer_ID", 0, L".\\RolongoJigboard.ini");
	stStandVersion.ucModuleVersion	=	::GetPrivateProfileIntW(L"SPRD OTP MANUFACTURER DATA", L"Module_Version", 0, L".\\RolongoJigboard.ini");

	jigboard_FillVersionStruct(pucData +0x0030, stHeaderVersion);
	jigboard_FillVersionStruct(pucData + 0x08E0, stOEMVersion);
	jigboard_FillVersionStruct(pucData + 0x09E0, stAWBVersion);
	jigboard_FillVersionStruct(pucData + 0x12E0, stShadingVersion);

	if(!jigboard_isSameVersionStruct(stStandVersion, stHeaderVersion)){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_OTPCheckSum;
	}

	if(!jigboard_isSameVersionStruct(stStandVersion, stOEMVersion)){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_OTPCheckSum;
	}

	if(!jigboard_isSameVersionStruct(stStandVersion, stAWBVersion)){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_OTPCheckSum;
	}

	if(!jigboard_isSameVersionStruct(stStandVersion, stShadingVersion)){
		pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
		return HisCCMError_OTPCheckSum;
	}

	pclassPlatform->Jig_FreeBuffer(&m_stCalibrationOtpBuffer);
	return 0;
}

#endif