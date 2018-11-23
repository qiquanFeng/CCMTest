#include "globaldefine.h"

// typedef enum{
// 	OTP_SELECT_PAGE0=0,
// 	OTP_SELECT_PAGE1,
// }OTP_PAGE;
typedef enum{
	otp_page0=0,
	otp_page1,
}otp_page;
typedef enum{
	otp_close=0,
	otp_open,
}otp_state;


//主DLG 直接调用此函数
void GC5005_gcore_identify_otp();

//void GC5005_MIPI_enable_OTP(otp_state state);

//void GC5005_MIPI_select_page_OTP(otp_page otp_select_page);
void GC5005_select_page_otp(otp_page otp_select_page);//GC5005_select_page_otp

void gc5005_gcore_update_dd();
//USHORT GC5005_MIPI_read_OTP(USHORT addr);

//void GC5005_MIPI_Write_SRAM_DD(void);
void GC5005_gcore_read_otp_info();
//void GC5005_MIPI_OTP(void);

//void write_cmos_sensor(USHORT reg,USHORT SSvalue);