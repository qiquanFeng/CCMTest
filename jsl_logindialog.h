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
#include "socket_jsl.h"
#include <QMessageBox>

class jsl_loginDialog : public QDialog
{
	Q_OBJECT

public:
	jsl_loginDialog(QWidget *parent = 0);
	~jsl_loginDialog();

	QLabel *m_plabLogin;
	QLabel *m_plabSta;
	QLabel *m_plabJob;
	QLabel *m_plabLine;
	QLineEdit *m_pleLot;
	QLineEdit *m_pleSta;
	QLineEdit *m_pleJob;
	QLineEdit *m_pleLine;

	QPushButton *m_pbutCommit;
	QPushButton *m_pbutQuit;

	QVBoxLayout *m_pvLayout;
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
	void slot_onCommit();
	void slot_onQuit();

	__inline void slot_changePos1(){
		m_pleSta->setFocus();
	};
	__inline void slot_changePos2(){
		m_pleJob->setFocus();
	};
	__inline void slot_changePos3(){
		m_pleLine->setFocus();
	};

};

class jsl_bindSerialNumber : public QDialog
{
	Q_OBJECT

public:
	jsl_bindSerialNumber(int nType=0,QWidget *parent = 0);
	~jsl_bindSerialNumber();

	int m_nType;
	SOCKET m_sock;
	QLineEdit *ledit;
	void setSerialNumber(QString);
	QString strSN;

	static char ucStrSN[1024];

signals:
	void information(QString info);

protected:
	void closeEvent(QCloseEvent *evt);

	public slots:
		void slotReturn();
};

#endif // JSL_LOGINDIALOG_H
