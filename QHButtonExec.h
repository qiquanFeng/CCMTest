#ifndef QHBUTTONEXEC_H
#define QHBUTTONEXEC_H

#include <QDockWidget>
#include "ui_QHButtonExec.h"

class QHButtonExec : public QDockWidget
{
	Q_OBJECT

public:
	QHButtonExec(QWidget *parent = 0);
	~QHButtonExec();

	Ui::QHButtonExec ui;

private slots:
	void handleEnter();

protected:
	void resizeEvent (QResizeEvent * event);
	
};

#endif // QHBUTTONEXEC_H
