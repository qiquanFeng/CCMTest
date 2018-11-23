#ifndef UPDATEFIREWAREDIALOG_H
#define UPDATEFIREWAREDIALOG_H

#include <QDialog>
#include "ui_updatefirewaredialog.h"
#include "globaldefine.h"

class updatefirewaredialog : public QDialog
{
	Q_OBJECT

public:
	updatefirewaredialog(QWidget *parent = 0);
	~updatefirewaredialog();

private:
	Ui::updatefirewaredialog ui;

private slots:
	void chooseBinFile();
	void updateFW();
	void cancelUpdate();

};

#endif // UPDATEFIREWAREDIALOG_H
