#ifndef LEISAIMOTION_H
#define LEISAIMOTION_H

#include <QObject>

class leisaiMotion : public QObject
{
	Q_OBJECT

public:
	//填写调焦机台,对应的图像角落
	leisaiMotion(char* configPath,int ang1,int ang2,int ang3,int ang4,int card=0);
	~leisaiMotion();

	int m_arrAng[4];
	bool m_bBoardStatus;

	int angleMove(int card,int angle,int pos,int speed=50000,bool bAck=false);
	/***
	axis  0:y 1:x 2:z 3:cx 4:cy
	moveMode 0 相对移动， 1 绝对移动
	***/
	int axis_Move(int card,int axis,int pos,int moveMode=0,int speed=50000,bool bAck=false);

	bool statusCheck(int axis,int card=0);
	bool setSpeed(int axis,int card=0,int speed=50000);
	bool initial(char* configPath,int card=0);

};

#endif // LEISAIMOTION_H
