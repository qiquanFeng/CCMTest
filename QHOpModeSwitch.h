#ifndef QHOPMODESWITCH_H
#define QHOPMODESWITCH_H

#include "ui_QHOpModeSwitch.h"
#include "globaldefine.h"
#include "qoplow.h"

class QHOpModeSwitch : public QDialog
{
	Q_OBJECT

public:
	QHOpModeSwitch(QWidget *parent = 0);
	~QHOpModeSwitch();

public slots:
	void clickOK();
	void clickCancel();
	void OperatorModeChange(int Index);

private:
	void saveManualModeAConfig();
	void saveManualModeBConfig();
	void saveSlaveModeConfig();

public:
	Ui::QHOpModeSwitch ui;
};

#endif // QHOPMODESWITCH_H
