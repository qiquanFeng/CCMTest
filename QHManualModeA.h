#ifndef QHMANUALMODEA_H
#define QHMANUALMODEA_H

#include <QDialog>
#include "ui_QHManualModeA.h"
#include "globaldefine.h"

class QHManualModeA : public QDialog
{
	Q_OBJECT

public:
	QHManualModeA(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC);
	~QHManualModeA();
	void saveManualModeAConfig();

public slots:
	void saveConfig();
	void setExposreValue();
	void updateExposruetime();
	void startUpdateExposruetime();
	void stopUpdateExposruetime();
	void slotSceneChanged(int iIndex);

public:
	Ui::QHManualModeA ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;

	QTimer luxTimer;
	bool bExposureFlag;

	RolongogetSensorAPIVersion getSensorAPIVersion;
	RolongogetExposureTime getExposureTime;
	RolongosetExposureTime setExposureTime;

};

#endif // QHMANUALMODEA_H
