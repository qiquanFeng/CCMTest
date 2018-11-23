#ifndef JSL_BURNSTATE_H
#define JSL_BURNSTATE_H

#include <QWidget>
#include <QFrame>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QTableWidget>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "qcustomplot.h"
#include "ui_jsl_burnstate.h"
#include "jsl_logindialog.h"
#include "qoplow.h"
#include <QList>


class jsl_burnState : public QDockWidget
{
	Q_OBJECT

public:
	jsl_burnState(int configtype,QWidget *parent = 0);
	~jsl_burnState();

	QWidget *widget;
	QVBoxLayout *vlayout;
	QHBoxLayout *hlayout;
	QLabel *label;
	QLabel *lab_Count;
	QPixmap *pix;

	QTableWidget *tab;
	QTableWidget *NgTab;
	QCustomPlot *plot;
	QWidget *wid;

protected:
	//virtual void mousePressEvent(QMouseEvent *);
	//virtual void mouseMoveEvent(QMouseEvent *);
	virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);
	virtual void enterEvent(QEvent *);
	virtual void leaveEvent(QEvent *);

	QPoint relativePos;
	QWidget *parentWid;

	jsl_loginDialog *loginDlg;
	QString GetLotSN();
	int GetLotNum();
private:
	Ui::jsl_burnState ui;

public slots:
	void slotBurnCount();
	void slot_UpdatePlot(int row,int col);
	void slot_ToPanel(QStringList,QStringList);
	void slot_test(QqrealList);
	void slot_ShowNgData(QTableWidgetItem *);
	void slot_ShowNgTableSelect();
	void slot_BurnDataExport();
};

#endif // JSL_BURNSTATE_H
