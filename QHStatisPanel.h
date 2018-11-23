#ifndef QHSTATISPANEL_H
#define QHSTATISPANEL_H

#include <QDockWidget>
#include "ui_QHStatisPanel.h"
#include "globaldefine.h"
#include "qoplow.h"

class QHStatisPanel : public QDockWidget
{
	Q_OBJECT

public:
	QHStatisPanel(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC,_global_itemexec& itemshareData);
	~QHStatisPanel();
	void switchTactisticsShow(unsigned char ucType);
	void clearTactisticsData(unsigned char ucType);

public slots:
	void drawStatisticsImage();
	void showNowTactisticsData() { switchTactisticsShow(1); }
	void showHistoryTactisticsData() { switchTactisticsShow(0); }
	void clearNowTactisticsData() { clearTactisticsData(0); }
	void clearHistoryTactisticsData() { clearTactisticsData(1); }
	void clearALLTactisticsData() { clearTactisticsData(2); }
	void enableTactistics();
	void disableTactistics();
	void tactistics_customMenuRequested(QPoint pos);

public:
	Ui::QHStatisPanel ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;

};

#endif // QHSTATISPANEL_H
