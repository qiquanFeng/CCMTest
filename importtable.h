#ifndef IMPORTTABLE_H
#define IMPORTTABLE_H

#include <QDialog>
#include "ui_importtable.h"

class importtable : public QDialog
{
	Q_OBJECT

public:
	importtable(QWidget *parent = 0);
	~importtable();

signals:
	void execimport(QString strPath, QString strTableName, QString strRename);

private slots:
	void findfile();
	void refeshtablelist();
	void import();
	void tableSelectedChanged(const QString & text);

private:
	Ui::importtable ui;
};

#endif // IMPORTTABLE_H
