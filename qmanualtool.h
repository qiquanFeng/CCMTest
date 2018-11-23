#ifndef QMANUALTOOL_H
#define QMANUALTOOL_H

#include <QDockWidget>
#include "ui_qmanualtool.h"
#include "globaldefine.h"
#include <QSqlDatabase>
#include <QThread>

class thread1:public QThread
{
	Q_OBJECT
public:
	thread1(QObject* parent=0);
	~thread1();

protected:
	virtual void run();

};

class qmanualtool : public QDockWidget
{
	Q_OBJECT
		 
public:
	qmanualtool(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC);
	~qmanualtool();

public:
	thread1 *motorThread;
	bool bCount;

	Ui::qmanualtool ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;

	QTimer luxTimer;
	QTimer motorTimer;
	QTimer globalGainTimer;

	bool bExposureFlag;
	bool bMotorFlag;
	bool bGlobalGainFlag;

	RolongogetSensorAPIVersion getSensorAPIVersion;
	RolongogetExposureTime getExposureTime;
	RolongosetExposureTime setExposureTime;
	RolongogetMotor getMotor;
	RolongosetMotor setMotor;
	RolongogetGlobalGain getGlobalGain;
	RolongosetGlobalGain setGlobalGain;

public slots:
	void MotorTest();
	void ClearMotorCount();

	void setExposreValue();
	void updateExposruetime();
	void startUpdateExposruetime();
	void stopUpdateExposruetime();

	void setMotorValue();
	void updateMotorPos();
	void startUpdateMotorPos();
	void stopUpdateMotorPos();

	void setGlobalGainValue();
	void updateGlobalGain();
	void startUpdateGlobalGain();
	void stopUpdateGlobalGain();

	 void startRealtime();
	 void StopRealtime();
	 void luxMonitorResult(float flY, float flR, float flG, float flB, float flR2G, float flB2G, float flMTF);

signals:
	 void startLuxMonitor(unsigned int uiLeft, unsigned int uiRight, unsigned int uiTop, unsigned int uiBottom, unsigned int uiTimer, unsigned int uiFlag);
	 void stopLuxMonitor();
};

#endif // QMANUALTOOL_H
