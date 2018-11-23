// BlackBeardDll.h
// BlackBeardDll Dll

#pragma once

#ifdef BLACKBEARDDLL_EXPORTS
#define BLACKBEARDDLL_API __declspec(dllexport) 
#else
#define BLACKBEARDDLL_API __declspec(dllimport) 
#endif

extern "C" {

	BLACKBEARDDLL_API float RGBImgMTF(unsigned char *rgbimg_src, int img_width, int img_height,
									  int XPOS, int YPOS, int length);

}