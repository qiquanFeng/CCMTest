#ifndef QHTEXTITEMEDIT_H
#define QHTEXTITEMEDIT_H

#include <QDialog>
#include "ui_QHTextItemEdit.h"
//#include "qoplow.h"
class QHTextItemEdit : public QDialog
{
	Q_OBJECT

public:
	QHTextItemEdit(QWidget *parent = 0,QString Qstr	="",QString Qinfo="", bool bChannel1 = true);//测试项信息，测试项
	~QHTextItemEdit();

	QString strNewAddInfo;
	
signals:
	
private:
	Ui::QHTextItemEdit ui;
	const bool bBoxChannel1;
	QString Qstrinfo;
	QString Qstritem;
	int iIndex;
	int Qstring2ui(QString qStr);
	void patchconfigstring(QString strsrc, QStringList& strname, QStringList& strvalue);
	void jointconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue);

public slots:
	void paramaterok();
	void BrowseResgiterFile();
	void clickCancel() { this->done(QDialog::Rejected);  }
};

#endif // QHTEXTITEMEDIT_H
