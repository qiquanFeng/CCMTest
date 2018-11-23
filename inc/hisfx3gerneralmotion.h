#ifndef HISFX3GERNERALMOTION_H
#define HISFX3GERNERALMOTION_H

#include <QtCore/qglobal.h>
#include <QString>

#ifdef HISFX3GERNERALMOTION_LIB
# define HISFX3GERNERALMOTION_EXPORT Q_DECL_EXPORT
#else
# define HISFX3GERNERALMOTION_EXPORT Q_DECL_IMPORT
#endif

enum _QHMOTIONCARDTYPE
{
	_QHMOTIONCARDTYPE_START									=	0x0,
	_QHMOTIONCARDTYPE_LEISAI_DMC3000				=	0x1,
	_QHMOTIONCARDTYPE_LEISAI_IO0640					=	0x2,
	_QHMOTIONCARDTYPE_END										=	0x3
};

class HISFX3GERNERALMOTION_EXPORT QHGerneralMotor
{
public:
	QHGerneralMotor();
	~QHGerneralMotor();
	QString GetLastError();
	int SetWorkDirectory(QString strDir);
	int OpenDevice(_QHMOTIONCARDTYPE card=_QHMOTIONCARDTYPE_START);
	int CloseDevice();
	bool IsDevOpened();
	int IOWriteOutBit(unsigned int uiCardNum, unsigned int uiPort, unsigned int uiBitNum, unsigned int uiValue);
	int IOReadOutBit(unsigned int uiCardNum, unsigned int uiPort, unsigned int uiBitNum, unsigned int* uiValue);
	int IOReadInBit(unsigned int uiCardNum, unsigned int uiPort, unsigned int uiBitNum, unsigned int* uiValue);
	int SetMoveCurve(unsigned int CardNo,unsigned int axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec);
	int MoveRelative(unsigned int CardNo,unsigned int axis, double Dist, bool bCheckStop);
	int MoveAbs(unsigned int CardNo,unsigned int axis, double Dist, bool bCheckStop);
	int CheckAxisStoped(unsigned int CardNo,unsigned int axis, unsigned int uiTimeOut = 60000);
	int SetPlusMode(unsigned int CardNo,unsigned int axis,unsigned int outmode);
	int DownloadConfigFile(unsigned int CardNo, QString strFilePath);

private:
	QString strError;
	QString strWorkDir;
	bool bIsOpened;
	_QHMOTIONCARDTYPE	cardType;
};

#endif // HISFX3GERNERALMOTION_H
