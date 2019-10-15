//
#pragma once
#ifndef HISFX3CCMTEST_H
#define HISFX3CCMTEST_H

#define WINVER					0x0501
#define _WIN32_WINNT		0x0501
#define _WIN32_IE				0x0700
#define WIN32_LEAN_AND_MEAN  


#include <QtGui/QMainWindow>
#include "ui_hisfx3ccmtest.h"
#include "configsetting.h"
#include "globaldefine.h"
#include "saveimage.h"
#include <winsock2.h>
#include <Iphlpapi.h>
#include "cchooseconfigs.h"
#include "qmanualtool.h"
#include "coorconverttool.h"
#include "fx3deviceconfig.h"
#include "updatefirewaredialog.h"
#include "QHButtonExec.h"
#include "QHInfoPanel.h"
#include "QHOpModeSwitch.h"
#include "QHManualModeA.h"
#include "QHTextInfoPanel.h"
#include "QHStatisPanel.h"
#include "QHBlemishHC.h"
#include "QHDrawTEstItem.h"
#include "itemprocess.h"
#include <QToolBar>
#include "QHImageDebug.h"
#include <QMessageBox>
#include <QList>
#include <QPushButton>


#include "jsl_burnstate.h"
#include "jsl_controlpanel.h"
#include "WininetHttp.h"


class renderframe : public QObject
{
	Q_OBJECT

public:
	renderframe(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, QHImageFrame& imageframeC, \
		QScrollBar& horizontalScrollBarC, QScrollBar& verticalScrollBarC);

	public slots:
		void startpreview();
		void finish();

signals:
		void finished();
		void information(QString info);
		void drawframe(int itype);
		void updatefps(float fpsSensor, float fpsUpload, float fpsDisplay, unsigned int uiFlag);

public:
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	QHImageFrame& imageframe;
	QScrollBar& horizontalScrollBar;
	QScrollBar& verticalScrollBar;
};


class improveraw : public QObject
{
	Q_OBJECT

public:
	improveraw(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC);

public slots:
		void startpreview();
		void finish();

signals:
		void finished();
		void information(QString info);
		void updatefps(float fpsSensor, float fpsUpload, float fpsDisplay, unsigned int uiFlag);

private:
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;
};
 
class improvergb24 : public QObject
{
	Q_OBJECT
		 
public:
	improvergb24(bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC);

public slots:
	void startpreview();
	void finish();
	
signals:
		void finished();
		void information(QString info);

private:
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
};
 
class HisFX3CCMTest : public QMainWindow
{
	Q_OBJECT

public:
	HisFX3CCMTest(QWidget *parent, Qt::WFlags flags, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, \
		_globalFunctionPointer& globalFunPointerC,bool bLogin=false);
	~HisFX3CCMTest();
	void close();
	void restoreUI();

	jsl_burnState *burnState;
	QHButtonExec* classButtonExec;
	QHInfoPanel* classInfoPanel;
	QHStatisPanel* classStatisPanel;
	QHTextInfoPanel* classTextPanel;
	QHDrawTEstItem* classDrawTestItem;
	itemprocess* itemprocessworker;
	QDockWidget *wid;

	SOCKET m_sock;//20190401
protected:
	void mouseDoubleClickEvent(QMouseEvent * event);
	void resizeEvent (QResizeEvent * event);
	void wheelEvent ( QWheelEvent * event );
	void keyPressEvent(QKeyEvent* event);

signals:
	void keyshortcutPress(char key, unsigned char uctimer);
	void finish();
	void luxMonitorResult(float flY, float flR, float flG, float flB, float flR2G, float flB2G, float flMTF);
	void information(QString info);

public slots:
	void itemdebugslot(unsigned short usItem, QString strAddInfo);
	void drawproject();
	void testsignalslot(char, unsigned char);
	void ClickExecbutton();
	void slotImageDebug();
	

	void updateCOMstatus(bool bConnect)
	{
		if(bConnect){ QPixmap pixmap1(":/Resources/Green.png", "PNG"); ui.COMlabel->setPixmap(pixmap1); }
		else{ QPixmap pixmap1(":/Resources/Red.png", "PNG"); ui.COMlabel->setPixmap(pixmap1); }
	}

	void updateCOM2status(bool bConnect)
	{
		if(bConnect){ QPixmap pixmap1(":/Resources/Green.png", "PNG"); ui.COM2label->setPixmap(pixmap1); }
		else{ QPixmap pixmap1(":/Resources/Red.png", "PNG"); ui.COM2label->setPixmap(pixmap1); }
	}

	void slotMessageBox(int iInfo)
	{
		QString strText;
		switch (iInfo)
		{
		case 0:
		default: strText = tr("WAIT..."); break;
		}
		

		QMessageBox::information(this, tr("Info"), strText);
		threadshareData.flaglock.lockForWrite();
		threadshareData.bSavingImage = false;
		threadshareData.flaglock.unlock();
	}

private slots:
	void ShowConfigDialog();
	void EnableConfigMenu();
	void slotWheelVCMTimer();
	void enablebutton(bool benable);
	void showItemStatus2EndResult(unsigned short usitem, unsigned char ucstatus, unsigned int ustime);
	void showEndresult(int istatus);
	void painterplot(unsigned int uiType);
	
	void manulsaveImage();
	void EnableSaveImage();
	void execsaveimage(QString strdir, QString strname, unsigned char ucimageformat, unsigned char ucimagesrc);
	void chooseconfigs();
	void customMenuRequested(QPoint pos);
	void adddebugpoint();
	void removedebugpoint();
	void HardwareSetting();
	void slotBlemishTuningTool();
	void enableinfotimer(unsigned int uiflag);
	void loopshowinfo();
	void serialNumtextChanged(const QString & text);
	void ShowManualTool();
	void showItemExeTool();
	void offlineModeSwitch(bool bChecked);
	void slotoffline(bool bChecked);
	void slotofflineb(bool bChecked);
	void offlineSetPath();
	void TextInfoDoubleClicked(QListWidgetItem* item);
	void slotImageShowPolicyChange(int index);

	//void showLeftRegion(bool bChecked);
	void slotManualModeAConfig();
	void slotTcpConnect();
	
	void slotButtonFA()  { ManualMultiButtonExec(0); }
	void slotButtonWhiteField()  { ManualMultiButtonExec(1); }
	void slotButtonNearFC()  { ManualMultiButtonExec(2); }
	void slotButtonFarFC()  { ManualMultiButtonExec(3); }

	void slotTcpIpDisconnect()
	{
		drawTcpIpStatus(false);
	}

	void updatefps(float fpsSensor, float fpsUpload, float fpsDisplay, unsigned int uiFlag)
	{
		QString strText	 = ui.fpslabel->text();
		strText.remove("fps:");
		QStringList strList = strText.split("/");
		float flNowSensor	=	strList.at(0).toFloat();
		float flNowUpload	=	strList.at(1).toFloat();
		float flNowDisplay	=	strList.at(2).toFloat();
		if(uiFlag & 0xFF) { flNowSensor = fpsSensor; flNowUpload = fpsUpload; }
		if(uiFlag & 0xFF00) flNowDisplay = fpsDisplay;
		strText = "fps:" % QString::number(flNowSensor, 'f', 1) % " / " % QString::number(flNowUpload, 'f', 1) % " / " % QString::number(flNowDisplay, 'f', 1);
		ui.fpslabel->setText(strText);
	}

	void calculateLuxMonitor();
	void startLuxMonitor(unsigned int uiLeft, unsigned int uiRight, unsigned int uiTop, unsigned int uiBottom, unsigned int uiTimer, unsigned int uiFlag);
	void stopLuxMonitor() { if(luxmonitorTimer.isActive())	luxmonitorTimer.stop(); }

	void slotShowOperationPanel() {if(!HISGLOBALUI::isUnlocked()) return; if(classButtonExec->isHidden()) classButtonExec->show(); }
	void slotShowInfoPanel() {if(!HISGLOBALUI::isUnlocked()) return; if(classInfoPanel->isHidden()) classInfoPanel->show(); }
	void slotShowTextPanel() {if(!HISGLOBALUI::isUnlocked()) return;if(classTextPanel->isHidden())classTextPanel->show(); }
	void slotShowStatisPanel() {if(!HISGLOBALUI::isUnlocked()) return;if(classStatisPanel->isHidden())classStatisPanel->show(); }
	void slotTestItem(){if(!HISGLOBALUI::isUnlocked()) return;if(classDrawTestItem->isHidden())classDrawTestItem->show(); }
	void showBindWid(QString);
	void updateSN(QString,QString);
	
public:
	Ui::HisFX3CCMTestClass ui; 
	QToolBar *mainToolBar;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;

	bool b2ndClick;
	RECT	stRectRealTime;
	unsigned int uiRealTimeFlag;
	double mouse_ptx;
	double mouse_pty;
	unsigned int uiInfoflag;
	QAction *saveimageAction;
	QAction *chooseprojectAction;
	  
	QString	saveimageDir;
	QTimer	luxmonitorTimer;
	QTimer	wheelvcmTimer;

	jsl_bindSerialNumber *wids;

	double uidaat;
	int getglobalParameter();
	void createToolbar();
	void updateDevicestatus(bool bConnect);
	void updateItemstatus(_itemStatus& itemstatus);
	void getmacAddress();
	void ManualMultiButtonExec(unsigned int uiFlag);
	void getManualModeAConfig();

	void drawTcpIpStatus(bool bconnect)
	{
		QPixmap pixmap1;
		if(bconnect) pixmap1.load(":/Resources/Tcp-Green.png", "PNG");
		else pixmap1.load(":/Resources/Tcp-Red.png", "PNG");
		ui.slavelabel->setPixmap(pixmap1);
	}

	void opModeSwitch_UI(unsigned int uiMode)
	{
		if(uiMode == 0){ //normal mode
			classButtonExec->ui.execpushButton->setVisible(true);
			classButtonExec->ui.focusAdjustpushButton->setVisible(false);
			classButtonExec->ui.whitePanelpushButton->setVisible(false);
			classButtonExec->ui.farFCpushButton->setVisible(false);
			classButtonExec->ui.nearFCpushButton->setVisible(false);
			ui.slavelabel->setVisible(false);
		}
		else if(uiMode == 2){ //slave mode
			classButtonExec->ui.execpushButton->setVisible(true);
			classButtonExec->ui.focusAdjustpushButton->setVisible(false);
			classButtonExec->ui.whitePanelpushButton->setVisible(false);
			classButtonExec->ui.farFCpushButton->setVisible(false);
			classButtonExec->ui.nearFCpushButton->setVisible(false);
			ui.slavelabel->setVisible(true);
		}
		else if(uiMode == 1){ //manual mode A
			classButtonExec->ui.execpushButton->setVisible(false);
			classButtonExec->ui.focusAdjustpushButton->setVisible(true);
			classButtonExec->ui.whitePanelpushButton->setVisible(true);
			classButtonExec->ui.farFCpushButton->setVisible(true);
			classButtonExec->ui.nearFCpushButton->setVisible(true);
			ui.slavelabel->setVisible(false);
		}
		else if(uiMode == 3){ //manual mode B
			classButtonExec->ui.execpushButton->setVisible(false);
			classButtonExec->ui.focusAdjustpushButton->setVisible(false);
			classButtonExec->ui.whitePanelpushButton->setVisible(false);
			classButtonExec->ui.farFCpushButton->setVisible(false);
			classButtonExec->ui.nearFCpushButton->setVisible(false);
			ui.slavelabel->setVisible(false);
		}
	}

	int gettcpipparamater();
	int getofflineparamater();
	int saveofflineflag(bool bChecked);
	int getofflineflag();
	
};

#endif // HISFX3CCMTEST_H 
