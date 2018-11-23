#ifndef QIMAGESHOWCONFIG_H
#define QIMAGESHOWCONFIG_H

#include <QDialog>
#include "ui_qimageshowconfig.h"
#include "globaldefine.h"
#include "qoplow.h"


class qimageshowconfig : public QDialog
{
	Q_OBJECT

public:
	qimageshowconfig(QWidget *parent = 0);
	~qimageshowconfig();

private slots:
	void saveglobalParameter();

private:
	Ui::qimageshowconfig ui;
};

#endif // QIMAGESHOWCONFIG_H
