#ifndef QHFONTSETTING_H
#define QHFONTSETTING_H

#include <QDialog>
#include "ui_QHFontSetting.h"
#include "globaldefine.h"
#include "qoplow.h"

class QHFontSetting : public QDialog
{
	Q_OBJECT

public:
	QHFontSetting(QWidget *parent = 0);
	~QHFontSetting();

public slots:
	void save();

private:
	Ui::QHFontSetting ui;
};

#endif // QHFONTSETTING_H
