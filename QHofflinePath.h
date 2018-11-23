#ifndef QHOFFLINEPATH_H
#define QHOFFLINEPATH_H

#include <QDialog>
#include "ui_QHofflinePath.h"

class QHofflinePath : public QDialog
{
	Q_OBJECT

public:
	QHofflinePath(QWidget *parent,QString tablename,QString& filename2,bool bReadsamepicture);
	~QHofflinePath();
	QString strTableName;
	QString Qfilename;
	bool bReadsamepicture;
private:
	Ui::QHofflinePath ui;
public slots:
		void slotSave();
		void slotOpenpath();
private:
	void paraToUI();
};

#endif // QHOFFLINEPATH_H
