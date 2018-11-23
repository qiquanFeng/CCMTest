#ifndef QHBLEMISHHC_H
#define QHBLEMISHHC_H

#include <QDockWidget>
#include "ui_QHBlemishHC.h"
#include "globaldefine.h"
#include <QMouseEvent>

class QHBlemishHC : public QDockWidget
{
	Q_OBJECT

public:
	QHBlemishHC(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC);
	~QHBlemishHC();
	QString strTableName;
	 
	int iWidth;
	int iHeight;
	_HisFX3_BaylorMode ucDataFormat;
	unsigned char* pucShow;

	void ShowInformation(QString info);
	void getConfig(QString strTable);
	int whitepanel_BlemishHC(bool bDebug);

protected:
	void mousePressEvent ( QMouseEvent * event );
	void mouseReleaseEvent ( QMouseEvent * event );
	void mouseMoveEvent ( QMouseEvent * event );
	void keyPressEvent ( QKeyEvent * event );

public slots:
		void slotSave();
		void slotGetImage();
		void slotNormalTest();
		void slotDebugTest();
		void slotLoopBlemish();

private:
	Ui::QHBlemishHC ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;

	std::vector<_HisCCMAlg_BlemishHC_Blemish> vecBlemish;

	float cflEdgeSide;
	float cflCornerZone;
	float cflMinArea;
	float cflMaxArea;
	double cdflTuning;
	_HisCCMAlg_BlemishHC_Spec stSpec[12];
	unsigned int uiSelectIndex;
	bool bDrawValid;
	QReadWriteLock drawLock;
	float flStartX;
	float flStartY;
	float flEndX; 
	float flEndY;
	bool bPress;

	void paraFromUI();
	void drawImage();
	void drawSelectROI(float flNowX, float flNowY);
};

#endif // QHBLEMISHHC_H
