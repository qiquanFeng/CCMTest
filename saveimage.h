#ifndef SAVEIMAGE_H
#define SAVEIMAGE_H

#include <QDialog>
#include "ui_saveimage.h"
#include "globaldefine.h"

class saveimage : public QDialog
{
	Q_OBJECT

public:
	saveimage(QWidget *parent = 0, QString strdir = "");
	~saveimage();

signals:
	void execsave(QString strdir, QString strname, unsigned char ucimageformat, unsigned char ucimagesrc);

private slots:
	void radiochange(bool bckecked);
	void finddir(bool bchecked);
	void savebutton(bool bchecked);
// 	void cancelbutton(bool bchecked);

private:
	Ui::saveimage ui;
};

#endif // SAVEIMAGE_H
