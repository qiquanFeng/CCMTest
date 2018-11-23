#ifndef QHCHOOSEGRABBERTYPE_H
#define QHCHOOSEGRABBERTYPE_H

#include <QDialog>
#include "ui_QHChooseGrabberType.h"
#include "inc/HisGlobalDefine.h"

class QHChooseGrabberType : public QDialog
{
	Q_OBJECT

public:
	QHChooseGrabberType(QWidget *parent = 0);
	~QHChooseGrabberType();

	_HisFX3_Platform_Type platformType;

private:
	Ui::QHChooseGrabberType ui;

private slots:
	void slotOK();
	void slotCancel();
};

#endif // QHCHOOSEGRABBERTYPE_H
