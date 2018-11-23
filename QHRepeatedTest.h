#ifndef QHREPEATEDTEST_H
#define QHREPEATEDTEST_H

#include <QDockWidget>
#include "ui_QHRepeatedTest.h"
#include "globaldefine.h"

class QHRepeatedTest : public QDockWidget
{
	Q_OBJECT

public:
	QHRepeatedTest(QWidget *parent = 0);
	~QHRepeatedTest();

private:
	Ui::QHRepeatedTest ui;
	unsigned int uiTotalTestTimes;
	unsigned int uiTestCount;
	char key;
	bool bTest;
	QTimer	repeatTimer;

public slots:
	void slotTest();
	void slotStop();
	void slotLoopOne();

signals:
	void signalExecKeyshortcutC1(char key, unsigned char uctimer);
	void signalExecKeyshortcutC2(char key, unsigned char uctimer);
};

#endif // QHREPEATEDTEST_H
