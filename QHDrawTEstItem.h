#ifndef QHDRAWTESTITEM_H
#define QHDRAWTESTITEM_H

#include <QDockWidget>
#include "ui_QHDrawTEstItem.h"

#include <windows.h>
#include <QtGui/QMainWindow>
#include "QMutex.h"
#include "QReadWriteLock.h"
#include "QEvent.h"
#include "QThread.h"
#include "Windows.h"
#include "QImage.h"
#include "QPainter.h"
#include "QTimer.h"
#include <QFileDialog>
#include <malloc.h>
#include <Dbt.h>
#include <vector>
#include "math.h"
#include "globaldefine.h"
#include <QFile>
#include <Iphlpapi.h>
#include <QTime>
#include <QElapsedTimer>
#include <QDesktopWidget>
#include <QTextStream>
#include <QInputDialog>
#include <QLibrary>
#include <QSettings>
#include "qoplow.h"
class QHDrawTEstItem : public QDockWidget
{
	Q_OBJECT

public:
	QHDrawTEstItem(_global_itemexec& itemshareData2,bool bShow =false,QWidget *parent = 0);
	~QHDrawTEstItem();
	_global_itemexec& itemshareData;

private:
	Ui::QHDrawTEstItem ui;

public slots:
	void drawitem();
	void slotTotalTestTime(unsigned int uiTime);
};

#endif // QHDRAWTESTITEM_H
