#include "leisaimotion.h"
#include "./LeisaiLib/LTDMC.h"
#include "inc/versionswitch.h"


leisaiMotion::leisaiMotion(char* configFilePath,int ang1,int ang2,int ang3,int ang4,int card)
{
	m_arrAng[0]=ang1;
	m_arrAng[1]=ang2;
	m_arrAng[2]=ang3;
	m_arrAng[3]=ang4;

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	m_bBoardStatus=initial(configFilePath,card);
#endif
}

leisaiMotion::~leisaiMotion()
{
#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	dmc_board_close();
#endif
}

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
int leisaiMotion::angleMove(int card,int angle,int pos,int speed,bool bAck){
	if(!m_bBoardStatus)
		return -1;

	setSpeed(3,card,speed);
	setSpeed(4,card,speed);

	switch(m_arrAng[angle-1]){
	case 1:
		dmc_pmove(card,3,pos,0);
		dmc_pmove(card,4,pos,0);
		break;
	case 2:
		dmc_pmove(card,3,pos,0);
		dmc_pmove(card,4,pos,0);
		break;
	case 3:
		dmc_pmove(card,3,pos,0);
		dmc_pmove(card,4,pos,0);
		break;
	case 4:
		dmc_pmove(card,3,pos,0);
		dmc_pmove(card,4,pos,0);
		break;
	}

	if(bAck){
		statusCheck(3,card);
		statusCheck(4,card);
	}

	return 0;
}
int leisaiMotion::axis_Move(int card,int axis,int pos,int speed,int moveMode/* =0 */,bool bAck){
	if(!m_bBoardStatus)
		return -1;
	setSpeed(axis,card,speed);
	dmc_pmove(card,axis,pos,moveMode);
	if(bAck){
		statusCheck(axis,card);
	}

	return 0;
}


bool leisaiMotion::statusCheck(int axis,int card /* =0 */){
	ushort usMoveStatus=0;
	while(!usMoveStatus){
		usMoveStatus=dmc_check_done(card,axis);
	}
	return true;
}
bool leisaiMotion::setSpeed(int axis,int card/* =0 */,int speed/* =50000 */){
	return dmc_set_profile(card,axis,0,speed,0.1,0.1,0);
}
bool leisaiMotion::initial(char* configPath,int card/* =0 */){
	short sStatus=dmc_board_init();
	sStatus=dmc_download_configfile(card,configPath);
	for (int i=0;i<8;i++)
	{
		sStatus=dmc_write_sevon_pin(card,i,0);
		setSpeed(i,card,50000);
	}

	return sStatus;
}

#endif
