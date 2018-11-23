#ifndef JSL_LOGINDIALOG_H
#define JSL_LOGINDIALOG_H

#include <QDialog>
#include "ui_jsl_logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QMessageBox>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class jsl_loginDialog : public QDialog
{
	Q_OBJECT

public:
	jsl_loginDialog(QWidget *parent = 0);
	~jsl_loginDialog();

	QLabel *m_plabLogin;
	QLineEdit *m_plineLogin;
	QPushButton *m_pbutSubmit;
	QPushButton *m_pbutQuit;

	QHBoxLayout *m_pHLayout;
	QString m_strLotSN;
	_inline void SetLotSN(QString str){
		m_strLotSN=str;
	}
	_inline QString GetLotSN(){
		return m_strLotSN;
	}
	
private:
	Ui::jsl_loginDialog ui;
	
signals:
	void sig_reLotSN();
	
public slots:
	void slot_onSubmit();
	void slot_onQuit();
};

#endif // JSL_LOGINDIALOG_H
