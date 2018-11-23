#ifndef QHIMAGEDEBUG_H
#define QHIMAGEDEBUG_H

#include <QDockWidget>
#include "ui_QHImageDebug.h"

#include "globaldefine.h"

class QHImageDebug : public QDockWidget
{
	Q_OBJECT

public:
	QHImageDebug(QWidget *parent = 0, bool bChannel1 = true);
	~QHImageDebug();

private:
	Ui::QHImageDebug ui;
	bool bBoxChannel1;
	QTimer	getDecodeInfoTimer;

public slots:
	void slotDVPPhaseShift();
	void slotGetFPGADecodeInfo();
};

#endif // QHIMAGEDEBUG_H
