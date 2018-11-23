#pragma once
#ifndef MOTION_API
#define MOTION_API _declspec(dllimport)
#endif

#define SUCCESS             0
#define OPEN_DEVICE_FAIL   -1   //���˶����ƿ�ʧ��
#define OPEN_AXIS_FAIL     -2   //����ʧ��
#define ADD_GROUP_FAIL     -3   //Ⱥ��ʧ��


//************************************************************************
//�������� init
//�������ܣ� ���˶����ƿ�����ȡ��������Ⱥ��
//������   ��
//����ֵ��0 �ɹ� ��0 ʧ��   
//***********************************************************************
MOTION_API int init(void);    //��ʼ��

//************************************************************************
//�������� MoveFocusingRing
//�������ܣ� ת����������������
//������   1  RelAngle     --- ת���Ƕ�  ��˳ʱ��  ����ʱ��
//		   2  height	   --- �����߶�  ���½�  ������
//����ֵ��TRUE �ɹ�   FALSE ʧ��
//***********************************************************************
MOTION_API BOOL MoveFocusingRing(double RelAngle, double height);    

//************************************************************************
//�������� MoveZAxis
//�������ܣ� ����Z������
//������   1   ReaPos   --- �����߶�  ���½�  ������
//����ֵ��TRUE �ɹ�   FALSE ʧ��
MOTION_API BOOL MoveZAxis(double RelPos);    //�����߶�  ��λmm  ���½�  ������

//************************************************************************
//�������� isFocusingRingMove
//�������ܣ� ��ȡ�������Ƿ��˶���
//������  1  sts 	--- �˶�״̬    TRUE�˶���   FALSEֹͣ
//����ֵ��TRUE �ɹ�   FALSE ʧ��
MOTION_API BOOL isFocusingRingMove(BOOL &sts);

//************************************************************************
//�������� isZAxisMove
//�������ܣ� ��ȡ������Z���Ƿ��˶���
//������  1  sts 	--- �˶�״̬    TRUE�˶���   FALSEֹͣ
//����ֵ��TRUE �ɹ�   FALSE ʧ��
MOTION_API BOOL isZAxisMove(BOOL &sts);