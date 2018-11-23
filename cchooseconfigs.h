#ifndef CCHOOSECONFIGS_H
#define CCHOOSECONFIGS_H

#include <QDialog>
#include <QVector>
#include "ui_cchooseconfigs.h"

class cchooseconfigs : public QDialog
{
	Q_OBJECT

public:
	cchooseconfigs(QWidget *parent, QString currenselect);
	~cchooseconfigs();

signals:

private slots:
	void okbuttonclick();
	void slotCancel();
	void allSelected( bool checked);
	void sonySelected( bool checked);
	void sansungSelected( bool checked);
	void ovSelected( bool checked);
	void hynixSelected( bool checked);
	void otherSelected( bool checked);
	void textSelected( const QString &);

public:
	Ui::cchooseconfigs ui;

	QStringList strAllConfigList;
	QStringList strKeyOV;
	QStringList strKeySony;
	QStringList strKeySamsung;
	QStringList strKeyHynix;
	QString strCurrenSelect;
};

#endif // CCHOOSECONFIGS_H
