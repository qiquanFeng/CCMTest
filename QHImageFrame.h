#ifndef QHIMAGEFRAME_H
#define QHIMAGEFRAME_H

#include <QFrame>
#include <QList>
#include "globaldefine.h"

class QHImageFrame : public QFrame
{
	Q_OBJECT

public:
	QHImageFrame(QWidget *parent =0, Qt::WindowFlags f=0);
	~QHImageFrame();

	int getDrawType()
	{
		flagLock.lockForRead();
		int x = iDrawType;
		flagLock.unlock();
		return x;
	}

	void setDrawType(int iType)
	{
		flagLock.lockForWrite();
		iDrawType	=	iType;
		flagLock.unlock();
	}

protected:
	void paintEvent(QPaintEvent *event);

public slots:
	void DrawFrame(int itype);
	void slotDrawAnotherSingle(QImage image1, unsigned int uiTimeOut);

	void backToNormalMode()
	{
		setDrawType(-100);
		Sleep(20);
		HisReleaseNewO(imageSingle);
	}

public:
	_threadshareData* threadshareData;
	_global_itemexec* itemshareData;
	int iDrawType;
	std::vector<_itemDraw> itemdrawList;
	QReadWriteLock flagLock;
	QImage* imageSingle;
};

#endif // QHIMAGEFRAME_H
