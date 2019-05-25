#ifdef CVIMAGETOOL_EXPORTS
#define CVIMAGETOOL_API __declspec(dllexport)
#else
#define CVIMAGETOOL_API __declspec(dllimport)
#endif







struct _ShadingImageInfo{
	void *pImage;
	unsigned int uiWidth;
	unsigned int uiHeight;
	unsigned int uiFirstPixel;// 0:R 1:GR 2:GB 3:B
	unsigned int uiBlackLeve;
	unsigned int uiImageType;// 0:Raw10 1:Raw8 2:BMP(DIB)

	unsigned int uiCShadingMode;// 0: 5  1: 9
	unsigned int uiYShadingMode;// 0: 5  1: 9
	bool bDrawMode;//0:false 1:true 
	double dCShadingROI_HRatio;
	double dCShadingROI_WRatio;
	double dYShadingROI_HRatio;
	double dYShadingROI_WRatio;
	double dAWBROI_HRatio;
	double dAWBROI_WRatio;
	

	_ShadingImageInfo() {
		pImage = NULL;
		uiWidth = 0;
		uiHeight = 0;
		uiFirstPixel = 0;
		uiBlackLeve = 0;
		uiImageType = 0;

		uiCShadingMode = 0;
		uiYShadingMode = 0;
		bDrawMode = 0;
		dCShadingROI_HRatio = 0.2f;
		dCShadingROI_WRatio = 0.2f;
		dYShadingROI_HRatio = 0.2f;
		dYShadingROI_WRatio = 0.2f;
		dAWBROI_HRatio = 0.2f;
		dAWBROI_WRatio = 0.2f;
	};

}SHADINGIMAGEINFO;

struct _OutAWBInfo{
	double dChannelR;
	double dChannelGR;
	double dChannelGB;
	double dChannelB;
	_OutAWBInfo() {
		dChannelR = 0.0f;
		dChannelGR = 0.0f;
		dChannelGB = 0.0f;
		dChannelB = 0.0f;
	}
}OUTAWBINFO;


struct _OutShadingInfo {
	double dShadingCenter;
	/*double dShadingLT;
	double dShadingRT;
	double dShadingLB;
	double dShadingRB;
	double dShadingT;
	double dShadingL;
	double dShadingR;
	double dShadingB;*/ 
	double dShadingLT;
	double dShadingT;
	double dShadingRT;
	double dShadingL;
	double dShadingR;
	double dShadingLB;
	double dShadingB;
	double dShadingRB;
	
	_OutShadingInfo() {
		dShadingCenter = 0.0f;
		dShadingLT = 0.0f;
		dShadingRT = 0.0f;
		dShadingLB = 0.0f;
		dShadingRB = 0.0f;
		dShadingT = 0.0f;
		dShadingL = 0.0f;
		dShadingR = 0.0f;
		dShadingB = 0.0f;
	}

}OUTSHADINGINFO;

struct _OutInfo {
	_OutAWBInfo AWBInfo;
	_OutShadingInfo RShadingInfo;
	_OutShadingInfo BShadingInfo;
	_OutShadingInfo YShadingInfo;
	unsigned char* outImageBGRA;
	unsigned long ulLen;
	_OutInfo() {
		unsigned char* outImageBGRA = NULL;
		unsigned long ulLen = 0;
	}
}SHADINGOUTINFO;

//CVIMAGETOOL_API int fnShading(_ShadingImageInfo& imageInfo,_OutInfo& outInfo);
typedef int (*fnShadingE)(_ShadingImageInfo& imageInfo,_OutInfo& outInfo);
typedef int (*fnShadingF)(IN unsigned char* pImageBuff,IN int imgWidth, IN int imgHeight,IN int imgDepth,IN int roiNumberW,IN int roiNumberH,OUT double *pValue,OUT long *len);
typedef int (*fnMTF_Q)(_ShadingImageInfo& imageInfo, RECT rect, float& fMtfH,float& fMtfV,BOOL bSTOU);



