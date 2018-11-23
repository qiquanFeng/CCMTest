#ifndef COORCONVERTTOOL_H
#define COORCONVERTTOOL_H

#include <QDockWidget>
#include "ui_coorconverttool.h"

class coorconverttool : public QDockWidget
{
	Q_OBJECT

public:
	coorconverttool(QWidget *parent = 0);
	~coorconverttool();

	void setImageSize(unsigned int uiWidth, unsigned int uiHeight);

private slots:
	void Coor2FOV();
	void CalculateDistance();
	void slotRGB2Lab();

private:
	Ui::coorconverttool ui;
};

#endif // COORCONVERTTOOL_H
