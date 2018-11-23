
//#include "DTCCM_SDK\dtccm.h" 
#include "WTypes.h"
#include "windows.h"
#include <string>
#include "GC5005_OTP_DD.h"


/***********************OTP**************************/
#define GC5005_MIPI_USE_OTP

#ifdef GC5005_MIPI_USE_OTP
//////////////////////////////////////////////////////////////////////////
#define kal_uint16 USHORT
#define kal_uint8 USHORT
#define kal_bool bool
#define mdelay Sleep
 //#elif defined(IMAGE_H_MIRROR) 
#define DD_PARAM_QTY 			200
#define WINDOW_WIDTH  			0x0a30 //2608 max effective pixels
#define WINDOW_HEIGHT 			0x07a0 //1952
#define RG_TYPICAL    			0x0090
#define BG_TYPICAL				0x0095
#define INFO_ROM_START			0x01
#define INFO_WIDTH       		0x07
#define WB_ROM_START            0x0f
#define WB_WIDTH         		0x02
#define GOLDEN_ROM_START        0x14
#define GOLDEN_WIDTH         	0x02
/*
typedef enum{
	otp_page0=0,
	otp_page1,
}otp_page;

typedef enum{
	otp_close=0,
	otp_open,
}otp_state;*/

//static kal_uint16 x_sram[DD_MAX_SIZE];
//static kal_uint16 y_sram[DD_MAX_SIZE];
//static kal_uint8 dd_type_sram[DD_MAX_SIZE];


static struct GC5005_otp{
	kal_uint16 module_id;
	kal_uint16 lens_id;
	kal_uint16 vcm_id;
	kal_uint16 vcm_driver_id;
	kal_uint16 year;
	kal_uint16 month;
	kal_uint16 day;
	kal_uint16 rg_gain;
	kal_uint16 bg_gain;
	kal_uint16 wb_flag;
	kal_uint16 golden_flag;	
	kal_uint16 dd_param_x[DD_PARAM_QTY];
	kal_uint16 dd_param_y[DD_PARAM_QTY];
	kal_uint16 dd_param_type[DD_PARAM_QTY];
	kal_uint16 dd_cnt;
	kal_uint16 dd_flag;
	kal_uint16 golden_rg;
	kal_uint16 golden_bg;	
	//kal_uint16 gc_flag;		
	//kal_uint16 Vald1;
	//kal_uint16 Val21;
	//kal_uint16 Val29;		
}gc5005_otp_info;

void write_cmos_sensor(USHORT reg,USHORT SSvalue)

{
	WriteHisFX3IICC1(0x6E,reg,SSvalue,0x0808,false);
}

USHORT read_cmos_sensor(USHORT reg)
{  
	unsigned __int64 svalue=0;
	int iRet=ReadHisFX3IICC1(0x6E,reg,&svalue,0x0808);
	return svalue;

}

void GC5005_gcore_enable_otp(otp_state state)
{
	kal_uint8 otp_clk,otp_en;
	otp_clk = read_cmos_sensor(0xfa);
	otp_en= read_cmos_sensor(0xd4);	
	if(state)	
	{ 
		otp_clk = otp_clk | 0x10;
		otp_en = otp_en | 0x80;
		mdelay(5);
		write_cmos_sensor(0xfa,otp_clk);	// 0xfa[6]:OTP_CLK_en
		write_cmos_sensor(0xd4,otp_en);	// 0xd4[7]:OTP_en	

		//LOG_INF("GC5005_OTP: Enable OTP!\n");		
	}
	else			
	{
		otp_en = otp_en & 0x7f;
		otp_clk = otp_clk & 0xef;
		mdelay(5);
		write_cmos_sensor(0xd4,otp_en);
		write_cmos_sensor(0xfa,otp_clk);

		//LOG_INF("GC5005_OTP: Disable OTP!\n");
	}
}

void GC5005_select_page_otp(otp_page otp_select_page)//otp_page otp_select_page
{
	kal_uint8 page;

	write_cmos_sensor(0xfe,0x00);
	page = read_cmos_sensor(0xd4);

	switch(otp_select_page)
	{
	case otp_page0:
		page = page & 0xfb;
		break;
	case otp_page1:
		page = page | 0x04;
		break;
	default:
		break;
	}
	mdelay(5);
	write_cmos_sensor(0xd4,page);	
}

kal_uint8 GC5005_read_otp(kal_uint8 addr)
{
	kal_uint8 value;

	write_cmos_sensor(0xfe,0x00);
	write_cmos_sensor(0xd5,addr);
	write_cmos_sensor(0xf3,0x20);
	value = read_cmos_sensor(0xd7);

	return value;
}
void GC5005_gcore_read_otp_info()
{  
  	/////////////////////////////////////////////////////////////////////
    //写入数据到TXT
	//FILE*fp=NULL;//需要注意
	//fp=fopen("C:\\my.txt","a+");
	//if(NULL==fp) 
	//	return -1;//要返回错误代码
	//while(fscanf(fp,"%c",&c)!=EOF) printf("%c",c); //从文本中读入并在控制台打印出来
	  //fwrite()
  ////////////////////////////////////////////////////////////////////////
	kal_uint8 flag0,flag1,flag_golden;
	kal_uint8 index,i,j,cnt=0;
	kal_uint8 info_start_add,wb_start_add,golden_start_add;
	kal_uint8 total_number0=0,total_number1=0,total_number=0; 
	kal_uint8 check_dd_flag,type;
	kal_uint8 dd0=0,dd1=0,dd2=0;
	kal_uint16 x,y;
	kal_uint8 dd_rom_start,offset;
	//struct gc5005_otp gc5005_otp_info={0x00};

	/*TODO*/
	GC5005_select_page_otp(otp_page0);
	flag0 =GC5005_read_otp(0x00);
	total_number0 = GC5005_read_otp(0x01) + GC5005_read_otp(0x02);
//	LOG_INF("GC5005_OTP : flag0 = 0x%x , total_number0 = %d\n",flag0,total_number0);

	//fprintf_s(fp,"flag0=%d,total_number=%d\n",flag0,total_number0);
	//str.Format("%d",total_number0);
	//fwrite(str,strlen(str),1,fp);

	GC5005_select_page_otp(otp_page1);
	total_number1 = GC5005_read_otp(0x28) + GC5005_read_otp(0x29);
	//fprintf_s(fp,"total_number1=%d\n",total_number1);

//	LOG_INF("GC5005_OTP : total_number1 = %d\n",total_number1);
	/*
	//For GC
	gc5005_otp_info.gc_flag = (flag0>>2)&0x03;
	LOG_INF("GC5005_OTP : gc5005_otp_info.gc_flag = 0x%x \n",gc5005_otp_info.gc_flag);

	if(gc5005_otp_info.gc_flag==0x01) 
	{
	gc5005_otp_info.Vald1=0xb0;
	gc5005_otp_info.Val21=0x08;
	gc5005_otp_info.Val29=0x14;
	}
	else
	{
	gc5005_otp_info.Vald1=0xa0;
	gc5005_otp_info.Val21=0x0a;
	gc5005_otp_info.Val29=0x22;
	}
	*/
	//DD
	switch(flag0&0x03)
	{
	case 0x00:
	//	LOG_INF("GC5005_OTP_DD is Empty !!\n");
		gc5005_otp_info.dd_flag = 0x00;
		break;
	case 0x01:	
	//	LOG_INF("GC5005_OTP_DD is Valid!!\n");

		total_number = (total_number1>=total_number0) ? total_number1 : total_number0;			   
		//fprintf_s(fp,"total=%d\n",total_number);
	//	LOG_INF("GC5005_OTP_DD total_number=%d!!\n",total_number);

		for(i=0; i<total_number; i++)
		{
			if(i<31)
			{	
				GC5005_select_page_otp(otp_page0);
				dd_rom_start=0x03;
				offset = 0;
			}
			else
			{
				GC5005_select_page_otp(otp_page1);			
				dd_rom_start=0x2a;
				offset = 124;//31*4
			}	

			check_dd_flag = GC5005_read_otp(dd_rom_start + 4*i -offset + 3);

			if(check_dd_flag&0x10)
			{//Read OTP
				type = check_dd_flag&0x0f;

				dd0 = GC5005_read_otp(dd_rom_start + 4*i -offset);
				dd1 = GC5005_read_otp(dd_rom_start + 4*i -offset + 1); 	
				dd2 = GC5005_read_otp(dd_rom_start + 4*i -offset + 2);
				x = ((dd1&0x0f)<<8) + dd0;
				y = (dd2<<4) + ((dd1&0xf0)>>4);
			//	LOG_INF("GC5005_OTP_DD : type = %d , x = %d , y = %d \n",type,x,y);
			//	LOG_INF("GC5005_OTP_DD : dd0 = %d , dd1 = %d , dd2 = %d \n",dd0,dd1,dd2);

				//fprintf_s(fp,"type=%d,x=%d,y=%d\n",type,x,y);
				//fprintf_s(fp,"dd0=%d,dd1=%d,dd2=%d\n",dd0,dd1,dd2);

				

				if(type == 3)
				{
					for(j=0; j<4; j++)
					{
						gc5005_otp_info.dd_param_x[cnt] = x;
						gc5005_otp_info.dd_param_y[cnt] = y + j;
						gc5005_otp_info.dd_param_type[cnt++] = 2;
					}
				}
				/*
				else if(type == 2)
				{
				y = ((y-1)/4)*4+1;
				for(j=0; j<4; j++)
				{
				gc5005_otp_info.dd_param_x[cnt] = x;
				gc5005_otp_info.dd_param_y[cnt] = y + j;
				gc5005_otp_info.dd_param_type[cnt++] = 2;
				}
				}
				*/				
				else
				{
					gc5005_otp_info.dd_param_x[cnt] = x;
					gc5005_otp_info.dd_param_y[cnt] = y;
					gc5005_otp_info.dd_param_type[cnt++] = type;
				}
			}
			else
			{
			//	LOG_INF("GC5005_OTP_DD:check_id[%d] = %x,checkid error!!\n",i,check_dd_flag);
			}
		}
		gc5005_otp_info.dd_cnt = cnt;
		gc5005_otp_info.dd_flag = 0x01;
		break;
	case 0x02:
	case 0x03:	
	//	LOG_INF("GC5005_OTP_DD is Invalid !!\n");
		gc5005_otp_info.dd_flag = 0x02;
		break;
	default :
		break;
	}

	GC5005_select_page_otp(otp_page1);
	flag1 =GC5005_read_otp(0x00);
	flag_golden = GC5005_read_otp(0x14);
	//LOG_INF("GC5005_OTP : flag1 = 0x%x , flag_golden = 0x%x\n",flag1,flag_golden);
	//fprintf_s(fp,"flag1=%d,flag_golden=0x%x,dd2=0x%x\n",flag1,flag_golden);

	//INFO&WB
	for(index=0;index<2;index++)
	{
		switch((flag1>>(4 + 2 * index))&0x03)
		{
		case 0x00:
		//	LOG_INF("gc5005_otp_info group%d is Empty !!\n", index + 1);
			break;
		case 0x01:
			info_start_add = INFO_ROM_START + index * INFO_WIDTH;
			gc5005_otp_info.module_id = GC5005_read_otp(info_start_add);
			gc5005_otp_info.lens_id = GC5005_read_otp(info_start_add + 1); 
			gc5005_otp_info.vcm_driver_id = GC5005_read_otp(info_start_add + 2);
			gc5005_otp_info.vcm_id = GC5005_read_otp(info_start_add + 3);
			gc5005_otp_info.year = GC5005_read_otp(info_start_add + 4);
			gc5005_otp_info.month = GC5005_read_otp(info_start_add + 5);
			gc5005_otp_info.day = GC5005_read_otp(info_start_add + 6);
			break;
		case 0x02:
		case 0x03:	
		//	LOG_INF("GC50gc5005_otp_info05_OTP_INFO group%d is Invalid !!\n", index + 1);
			break;
		default :
			break;
		}

		switch((flag1>>(2 * index))&0x03)
		{
		case 0x00:
		//	LOG_INF("GC5005_OTP_WB group%d is Empty !!\n", index + 1);
		gc5005_otp_info.wb_flag = 0x00;
			break;
		case 0x01:
		//	LOG_INF("GC5005_OTP_WB group%d is Valid !!\n", index + 1);						
			wb_start_add = WB_ROM_START + index * WB_WIDTH;
			gc5005_otp_info.rg_gain = GC5005_read_otp(wb_start_add);
			gc5005_otp_info.bg_gain = GC5005_read_otp(wb_start_add + 1); 
			gc5005_otp_info.wb_flag = 0x01;
			break;
		case 0x02:
		case 0x03:	
		//	LOG_INF("GC5005_OTP_WB group%d is Invalid !!\n", index + 1);			
			gc5005_otp_info.wb_flag =0x02;
			break;
		default :
			break;
		}

		switch((flag_golden>>(2 * index))&0x03)
		{
		case 0x00:
			//LOG_INF("GC5005_OTP_GOLDEN group%d is Empty !!\n", index + 1);
			gc5005_otp_info.golden_flag = 0x00;					
			break;
		case 0x01:
			//LOG_INF("GC5005_OTP_GOLDEN group%d is Valid !!\n", index + 1);						
			golden_start_add = GOLDEN_ROM_START + index * GOLDEN_WIDTH;
			gc5005_otp_info.golden_rg= GC5005_read_otp(golden_start_add);
			gc5005_otp_info.golden_bg = GC5005_read_otp(golden_start_add + 1); 
			gc5005_otp_info.golden_flag = 0x01;						
			break;
		case 0x02:
		case 0x03:	
			//LOG_INF("GC5005_OTP_GOLDEN group%d is Invalid !!\n", index + 1);	
			gc5005_otp_info.golden_flag = 0x02;			
			break;
		default :
			break;
		}		
	}
	//fclose(fp);
	//fp=NULL;//需要指向空，否则会指向原打开文件地址  
}


 void gc5005_gcore_update_dd()
{
	//FILE*fp=NULL;//需要注意
	//fp=fopen("C:\\test.txt","a+");

	kal_uint16 i=0,j=0,n=0,m=0,s=0,e=0;
	kal_uint16 temp_x=0,temp_y=0;
	kal_uint8 temp_type=0;
	kal_uint8 temp_val0,temp_val1,temp_val2;
	/*TODO*/

	if(0x01 ==gc5005_otp_info.dd_flag)
	{
		// #elif defined(IMAGE_H_MIRROR) 
#if defined(IMAGE_NORMAL_MIRROR)
		for(i=0; i<gc5005_otp_info.dd_cnt; i++)
		{
			if(gc5005_otp_info.dd_param_type[i]==0)
			{	gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i] + 1;	}
			else if(gc5005_otp_info.dd_param_type[i]==1)
			{	gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i] - 1;	}
			else
			{	gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i];	}
		}
#elif defined(IMAGE_H_MIRROR)
		//do nothing
#elif defined(IMAGE_V_MIRROR)
		for(i=0; i<gc5005_otp_info.dd_cnt; i++)
		{
			if(gc5005_otp_info.dd_param_type[i]==0)
			{	
				gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i]+1;
				gc5005_otp_info.dd_param_y[i]= WINDOW_HEIGHT - gc5005_otp_info.dd_param_y[i]+1;
			}
			else if(gc5005_otp_info.dd_param_type[i]==1)
			{
				gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i]-1;
				gc5005_otp_info.dd_param_y[i]= WINDOW_HEIGHT - gc5005_otp_info.dd_param_y[i]+1;
			}
			else
			{
				gc5005_otp_info.dd_param_x[i]= WINDOW_WIDTH - gc5005_otp_info.dd_param_x[i] ;
				gc5005_otp_info.dd_param_y[i]= WINDOW_HEIGHT - gc5005_otp_info.dd_param_y[i] + 1;
			}
		}
#elif defined(IMAGE_HV_MIRROR)
		for(i=0; i<gc5005_otp_info.dd_cnt; i++)
		{	gc5005_otp_info.dd_param_y[i]= WINDOW_HEIGHT - gc5005_otp_info.dd_param_y[i] + 1;	}
#endif

		//y
		for(i=0 ; i< gc5005_otp_info.dd_cnt-1; i++) 
		{
			for(j = i+1; j < gc5005_otp_info.dd_cnt; j++) 
			{  
				if(gc5005_otp_info.dd_param_y[i] > gc5005_otp_info.dd_param_y[j])  
				{  
					temp_x = gc5005_otp_info.dd_param_x[i] ; gc5005_otp_info.dd_param_x[i] = gc5005_otp_info.dd_param_x[j] ;  gc5005_otp_info.dd_param_x[j] = temp_x;
					temp_y = gc5005_otp_info.dd_param_y[i] ; gc5005_otp_info.dd_param_y[i] = gc5005_otp_info.dd_param_y[j] ;  gc5005_otp_info.dd_param_y[j] = temp_y;
					temp_type = gc5005_otp_info.dd_param_type[i] ; gc5005_otp_info.dd_param_type[i] = gc5005_otp_info.dd_param_type[j]; gc5005_otp_info.dd_param_type[j]= temp_type;
				} 
			}

		}

		//x
		for(i=0; i<gc5005_otp_info.dd_cnt; i++)
		{
			if(gc5005_otp_info.dd_param_y[i]==gc5005_otp_info.dd_param_y[i+1])
			{
				s=i++;
				while((gc5005_otp_info.dd_param_y[s] == gc5005_otp_info.dd_param_y[i+1])&&(i<gc5005_otp_info.dd_cnt-1))
					i++;
				e=i;

				for(n=s; n<e; n++)
				{
					for(m=n+1; m<e+1; m++)
					{
						if(gc5005_otp_info.dd_param_x[n] > gc5005_otp_info.dd_param_x[m])
						{
							temp_x = gc5005_otp_info.dd_param_x[n] ; gc5005_otp_info.dd_param_x[n] = gc5005_otp_info.dd_param_x[m] ;  gc5005_otp_info.dd_param_x[m] = temp_x;
							temp_y = gc5005_otp_info.dd_param_y[n] ; gc5005_otp_info.dd_param_y[n] = gc5005_otp_info.dd_param_y[m] ;  gc5005_otp_info.dd_param_y[m] = temp_y;
							temp_type = gc5005_otp_info.dd_param_type[n] ; gc5005_otp_info.dd_param_type[n] = gc5005_otp_info.dd_param_type[m]; gc5005_otp_info.dd_param_type[m]= temp_type;
						}
					}
				}

			}

		}


		//write SRAM
		write_cmos_sensor(0xfe,0x01);
		write_cmos_sensor(0xbe,0x00);
		write_cmos_sensor(0xa9,0x01);

		for(i=0; i<gc5005_otp_info.dd_cnt; i++)
		{
			temp_val0 = gc5005_otp_info.dd_param_x[i]& 0x00ff;
			temp_val1 = ((gc5005_otp_info.dd_param_y[i]<<4)& 0x00f0) + ((gc5005_otp_info.dd_param_x[i]>>8)&0X000f);
			temp_val2 = (gc5005_otp_info.dd_param_y[i]>>4) & 0xff;
			write_cmos_sensor(0xaa,i);
			write_cmos_sensor(0xac,temp_val0);
			write_cmos_sensor(0xac,temp_val1);
			write_cmos_sensor(0xac,temp_val2);
			write_cmos_sensor(0xac,gc5005_otp_info.dd_param_type[i]);
			//LOG_INF("GC5005_OTP_GC val0 = 0x%x , val1 = 0x%x , val2 = 0x%x \n",temp_val0,temp_val1,temp_val2);
			//LOG_INF("GC5005_OTP_GC x = %d , y = %d \n",((temp_val1&0x0f)<<8) + temp_val0,(temp_val2<<4) + ((temp_val1&0xf0)>>4));
			std::string str;

			//fprintf_s(fp,"GC5005_OTP_GC val0 = 0x%x , val1 = 0x%x , val2 = 0x%x \n",temp_val0,temp_val1,temp_val2);
			//fprintf_s(fp,"GC5005_OTP_GC val0 = 0x%x , val1 = 0x%x , val2 = 0x%x \n",temp_val0,temp_val1,temp_val2);
		}

		write_cmos_sensor(0xbe,0x01);
		write_cmos_sensor(0xfe,0x00);
	}

	//fclose(fp);
	//fp=NULL;//需要指向空，否则会指向原打开文件地址  
//////////////////////////////////////////////////////////////////////////
	

}
void GC5005_gcore_identify_otp()
{
	write_cmos_sensor(0xfe, 0x00); //reset related
	write_cmos_sensor(0xfe, 0x00); 
	write_cmos_sensor(0xfe, 0x00); //modify 1117
	write_cmos_sensor(0xf7, 0x01); 
	write_cmos_sensor(0xf8, 0x11); //PLL mode2
	write_cmos_sensor(0xf9, 0xaa);
	write_cmos_sensor(0xfa, 0x84); 
	write_cmos_sensor(0xfc, 0x8E); 

	GC5005_gcore_enable_otp(otp_open);
	GC5005_gcore_read_otp_info();
	gc5005_gcore_update_dd();
	GC5005_gcore_enable_otp(otp_close);
}


#endif
/***********************OTP*************************/

