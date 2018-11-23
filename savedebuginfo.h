#ifndef SAVEDEBUGINFO_H
#define SAVEDEBUGINFO_H

#include <QDialog>
#include "ui_savedebuginfo.h"
#include "QMessageBox.h"
class savedebuginfo : public QDialog
{
	Q_OBJECT

public:
	savedebuginfo(QWidget *parent = 0);
	~savedebuginfo();
	QString qPath;
private:
	Ui::savedebuginfo ui;
private slots:
	void finddir(bool bchecked);
	void savebutton(bool bchecked);
};

#endif // SAVEDEBUGINFO_H
