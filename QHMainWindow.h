#ifndef QHMAINWINDOW_H
#define QHMAINWINDOW_H

#include <QMainWindow>
#include "ui_QHMainWindow.h"
#include "hisfx3ccmtest.h"
#include "globaldefine.h"
#include "qconfigmanage.h"
#include "qimageshowconfig.h"
#include "QHShortcut.h"
#include "QHTableContent.h"
#include "QHChooseGrabberType.h"
#include <QDesktopServices>
#include <QUrl>
#include "QHRepeatedTest.h"
#include "QHFontSetting.h"
#include "jsl_logindialog.h"






class QHthreadShortcut : public QObject
{
	Q_OBJECT

public slots:
	void finish();
	void slotHotPlugInLoop();
	void slotExecKeyshortcut(char key, unsigned char uctimer);

signals:
	void finished(); 
	void signalNativeItemExecC1(const _shoutCutDetail& currentitem);
	void signalNativeItemExecC2(const _shoutCutDetail& currentitem);
	void signalExecKeyshortcutC1(char key, unsigned char uctimer);
	void signalExecKeyshortcutC2(char key, unsigned char uctimer);
};

class QHMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QHMainWindow(QWidget *parent = 0);
	~QHMainWindow();

	int getglobalParameter(bool& bShowChannel1, bool& bShowChannel2);
	void getOperateModeConfig();
	void restoreUI();
	void creatMenuAction();

protected:
	int  MessageEvent(int key);
	void keyPressEvent(QKeyEvent* event);
	void closeEvent(QCloseEvent *event);
	bool winEvent ( MSG * message, long * result );
	void mouseDoubleClickEvent(QMouseEvent * event);
	 
signals:
	void finish();
	void information(QString info);
	void signalExecKeyshortcutC1(char key, unsigned char uctimer);
	void signalExecKeyshortcutC2(char key, unsigned char uctimer);

public slots:
	void slotPanelMoveable(bool bChecked);
	void registerEvent();
	void openfx3slot();
	void closefx3slot();
	void closefx3slot2();
	void currentSelfCal();
	void voltageSelfCal();
	void OSSelfCal();
	void FX3DeviceConfig();
	void UpdateFPGAFW();
	void slotShortcutConfig();
	void slotVersionShow();
	void slotCompterCompatibilityTest();






	_inline void slotShowSOP()
	{
		QPixmap pixmap("./SOP/SOP.png", "PNG");
		if(pixmap.isNull()){
			QMessageBox::warning(this,QString::fromLocal8Bit("打开SOP图片错误!"),QString::fromLocal8Bit("打开SOP图片 ./SOP/SOP.png 失败"));
			return ;
		}

		QDialog *winSOP=new QDialog(this);
		QLabel *lab=new QLabel("test",winSOP);
		lab->setPixmap(pixmap);
		winSOP->setFixedSize(pixmap.size());

		//QPixmap pixmap1(":/Resources/testing.png", "PNG");
		//winSOP->setWindowFlags(Qt::FramelessWindowHint);//无边框   
		//winSOP->setAttribute(Qt::WA_TranslucentBackground);

		winSOP->setAttribute(Qt::WA_DeleteOnClose);
		winSOP->show();
		winSOP->raise();
		winSOP->activateWindow();
	}
	_inline void slotExit(){
		qApp->exit();
	}

#if (defined USE_EQUIPMENT_AFM_JSL_V2)
	_inline void slotShowIOControl(){
		jsl_controlpanel *control=new jsl_controlpanel((QDialog*)this);
		control->setAttribute(Qt::WA_DeleteOnClose);
		control->show();
		control->raise();
		control->activateWindow();
	}
#endif

	void slotExecHelpFile()
	{
		QDesktopServices::openUrl (QUrl::fromLocalFile (QDir::currentPath() % "/doc/" % QTextCodec::codecForName( "GBK")->toUnicode("RoLongo软件使用说明.chm")));
	}

	void slotShowChannel1(bool checked)
	{
		if(classPlatform.getCameraCountSupported() == 2)
		{
			windowc1.setVisible(checked);

			QMutexLocker locker(&hisglobalparameter.mutexDatabase);
			bool bDB;
			{
				QSqlDatabase stSqlDB;
				bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
				if(bDB){
					HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "ui", QVariant(), QVariant(), "show ccmtest channel 1");
					HISDBTEMPLATE::insertItem(stSqlDB, "global", 6, "global", "ui", QVariant(), QVariant(), "show ccmtest channel 1", (checked)?("true"):("false"));
					stSqlDB.close();
				}
			}
			if(bDB)
			{
				HISDBTEMPLATE::removeDB();
			}
		}
	}

	void slotShowChannel2(bool checked)
	{
		if(classPlatform.getCameraCountSupported() == 2)
		{
			windowc2.setVisible(checked);

			QMutexLocker locker(&hisglobalparameter.mutexDatabase);
			bool bDB;
			{
				QSqlDatabase stSqlDB;
				bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
				if(bDB){
					HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "ui", QVariant(), QVariant(), "show ccmtest channel 2");
					HISDBTEMPLATE::insertItem(stSqlDB, "global", 6, "global", "ui", QVariant(), QVariant(), "show ccmtest channel 2", (checked)?("true"):("false"));
					stSqlDB.close();
				}
			}
			if(bDB)
			{
				HISDBTEMPLATE::removeDB();
			}
		}
	}

	void DebugModeSwitch(bool bChecked)
	{
		hisglobalparameter.bDebugMode	=	bChecked;		
		QString strText = (bChecked)?(tr("Enter Debug Mode")):(tr("Quit Debug Mode"));
		QMessageBox::information(this, tr("INFO"), strText);	
	}

	void slotSaveTextInfoToLocal(bool bChecked)
	{
		if(!HISGLOBALUI::isUnlocked()) return;
		QMutexLocker locker(&hisglobalparameter.mutexDatabase);
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "debug", QVariant(), QVariant(), "savetextinfo2local");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 0, "global", "debug", QVariant(), QVariant(), "savetextinfo2local", QString::number((unsigned int)(bChecked)));
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}
		hisglobalparameter.bSaveTextInfo2Local	=	bChecked;	
		if(bChecked)
			emit information(tr("Save Text Info To Local File: ") % "ON");
		else
			emit information(tr("Save Text Info To Local File: ") % "OFF");
	}

	void DisableConfigSetting()
	{
		hisglobalparameter.bconfiglock	=	true;
		QMessageBox::information(this, tr("INFO"), tr("Operation has been locked"));
	}

	void changePassword()
	{
		if(!HISGLOBALUI::isUnlocked()) return;

		bool bok;
		QString strText	=	QInputDialog::getText(this, tr("Please enter new password"), tr("New Password:"), QLineEdit::Normal, QString(), &bok, Qt::Dialog);
		strText	=	strText.trimmed();
		if(!bok) return;

		QString strText2	=	QInputDialog::getText(this, tr("Please confirm new password"), tr("New Password:"), QLineEdit::Normal, QString(), &bok, Qt::Dialog);
		strText2	=	strText2.trimmed();
		if(!bok) return;

		if(strText != strText2)
		{
			QMessageBox::critical(this, tr("ERROR"), tr("The two passwords you typed do not match"));
			return;
		}

		QMutexLocker locker(&hisglobalparameter.mutexDatabase);
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "configsetting", QVariant(), QVariant(), "password");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 0, "global", "configsetting", QVariant(), QVariant(), "password", strText);
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}

		hisglobalparameter.strPassword	=	strText;

		QMessageBox::information(this, tr("INFO"), tr("Change password success"));

	}

	void ShowConfigManageDialog()
	{
		if(!HISGLOBALUI::isUnlocked()) return;

		if(threadshareDataC1.GetHisTestingflag() || threadshareDataC2.GetHisTestingflag()){
			QMessageBox::warning(this, tr("Warning"), tr("The Sensor preview is on, Please try later."));
			return;
		}

		if(threadshareDataC1.GetHisPreviewflag() || threadshareDataC2.GetHisPreviewflag()){
			QMessageBox::warning(this, tr("Warning"), tr("The test process is going, Please try later."));
			return;
		}

		qconfigmanage stDialog;
		stDialog.exec();
	}

	void slotConfigContentTable()
	{
		if(!hisglobalparameter.mutexDatabase.tryLock(50)){
			QMessageBox::warning(0, tr("ERROR"), tr("Database is being operated on other place, please try again later"));
			return;
		}

		QString strTable;
		if(!HISDBCUSTOM::isCustomCanOpen()) return;
		if(HISDBCUSTOM::isTableExist(itemshareDataC1.currentTableName)) strTable	=	itemshareDataC1.currentTableName;
		if(strTable.isEmpty() && HISDBCUSTOM::isTableExist(itemshareDataC2.currentTableName)) strTable	=	itemshareDataC2.currentTableName;

		QHTableContent classTable(this, strTable);
		classTable.exec();
		hisglobalparameter.mutexDatabase.unlock();
	}

	void slotChooseOpMode()
	{
		QHOpModeSwitch classOpModeSwitch(this);
		if(classOpModeSwitch.exec() > 0) {
			windowc1.opModeSwitch_UI(hisglobalparameter.stOperatorMode.ucMode);
			windowc2.opModeSwitch_UI(hisglobalparameter.stOperatorMode.ucMode);
		}		
	}

	void slotFontSetting()
	{
		QHFontSetting classFontSetting(this);
		classFontSetting.exec();
	}

	void showItem2EndResultRegion(bool bChecked)
	{
		hisglobalparameter.bShowItem2EndResult	=	bChecked;

		QMutexLocker locker(&hisglobalparameter.mutexDatabase);
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "ui", QVariant(), QVariant(), "show item to end result");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 6, "global", "ui", QVariant(), QVariant(), "show item to end result", (bChecked)?("true"):("false"));
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}
	}

	void showEndResult2ImageRegion(bool bChecked)
	{
		hisglobalparameter.bShowResult2Image	=	bChecked;

		QMutexLocker locker(&hisglobalparameter.mutexDatabase);
		bool bDB;
		{
			QSqlDatabase stSqlDB;
			bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
			if(bDB){
				HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_key, "global", "ui", QVariant(), QVariant(), "show result to image");
				HISDBTEMPLATE::insertItem(stSqlDB, "global", 7, "global", "ui", QVariant(), QVariant(), "show result to image", (bChecked)?("true"):("false"));
				stSqlDB.close();
			}
		}
		if(bDB)
		{
			HISDBTEMPLATE::removeDB();
		}
	}

	void slotSave_LockUI()
	{
		if(!HISGLOBALUI::isUnlocked()) return;

		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplateui");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
			if (!templatedb.open())
				return;

			QSqlQuery query(templatedb);
			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='QHMainWindow'" );
			query.exec();

			query.prepare("INSERT INTO ui(classfy,item,geometry,windowState) VALUES(:classfy,:item,:geometry,:windowState)");
			query.bindValue(":classfy", "restorestatus");
			query.bindValue(":item", "QHMainWindow");
			query.bindValue(":geometry", saveGeometry());
			query.bindValue(":windowState", saveState());
			query.exec();

			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC1'" );
			query.exec();

			query.prepare("INSERT INTO ui(classfy,item,geometry,windowState) VALUES(:classfy,:item,:geometry,:windowState)");
			query.bindValue(":classfy", "restorestatus");
			query.bindValue(":item", "HisFX3CCMTestC1");
			query.bindValue(":geometry", windowc1.saveGeometry());
			query.bindValue(":windowState", windowc1.saveState());
			query.exec();

			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC2'" );
			query.exec();

			query.prepare("INSERT INTO ui(classfy,item,geometry,windowState) VALUES(:classfy,:item,:geometry,:windowState)");
			query.bindValue(":classfy", "restorestatus");
			query.bindValue(":item", "HisFX3CCMTestC2");
			query.bindValue(":geometry", windowc2.saveGeometry());
			query.bindValue(":windowState", windowc2.saveState());
			query.exec();

			templatedb.close();
		}

		QSqlDatabase::removeDatabase("querytemplateui");

		slotPanelMoveable(false);
		ui.actionPanel_moveable->setChecked(false);
	}

	void slotResetUILayout()
	{
		if(!HISGLOBALUI::isUnlocked()) return;

		{
			QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplateui");
			templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
			if (!templatedb.open())
				return;

			QSqlQuery query(templatedb);
			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='hisfx3ccmtest'" );
			query.exec();
			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC1'" );
			query.exec();
			query.prepare("DELETE FROM ui WHERE classfy='restorestatus' AND item='HisFX3CCMTestC2'" );
			query.exec();
			

			templatedb.close();
		}

		QSqlDatabase::removeDatabase("querytemplateui");

		QMessageBox::information(this, tr("Information"), tr("Please restart the program to make it valid."));
	}


	void slotImageShowDialog()
	{
		qimageshowconfig* classimageshowconfig	=	new qimageshowconfig(this);
		classimageshowconfig->setAttribute(Qt::WA_DeleteOnClose);
		classimageshowconfig->show();
		classimageshowconfig->raise();
		classimageshowconfig->activateWindow();
	}

	void CoorConvertTool()
	{
		coorconverttool* classcoorconverttool	=	new coorconverttool();
		classcoorconverttool->setAttribute(Qt::WA_DeleteOnClose);
		classcoorconverttool->show();
		classcoorconverttool->raise();
		classcoorconverttool->activateWindow();

		windowc1.itemshareData.itemparameterLock.lockForRead();
		if(windowc1.itemshareData.previewParameter != NULL){
			classcoorconverttool->setImageSize(windowc1.itemshareData.previewParameter->iWidth, windowc1.itemshareData.previewParameter->iHeight);
		}
		windowc1.itemshareData.itemparameterLock.unlock();
	}

	void slotRepeatedTest()
	{
		QHRepeatedTest* classRepeatedTest	=	new QHRepeatedTest(this);
		connect(classRepeatedTest,  SIGNAL(signalExecKeyshortcutC1(char, unsigned char)), windowc1.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));
		connect(classRepeatedTest,  SIGNAL(signalExecKeyshortcutC2(char, unsigned char)), windowc2.itemprocessworker, SLOT(ExecKeyshortcut(char, unsigned char)));

		classRepeatedTest->setAttribute(Qt::WA_DeleteOnClose);
		classRepeatedTest->show();
		classRepeatedTest->raise();
		classRepeatedTest->activateWindow();
	}

	void chooseSimpleChinenes(bool bChecked)
	{
		ui.simpleChineseaction->setChecked(true);
		ui.englishaction->setChecked(false);	
		ROPLOW::saveGlobalConfigItem("translate", "language", "0", 8); 
		QMessageBox::information(this, tr("Language Switch"), tr("Please restart program to make it valid"));
	}

	void chooseEnglish(bool bChecked)
	{
		ui.simpleChineseaction->setChecked(false);
		ui.englishaction->setChecked(true);	
		ROPLOW::saveGlobalConfigItem("translate", "language", "1", 8); 
		QMessageBox::information(this, tr("Language Switch"), tr("Please restart program to make it valid"));
	}

	void slotCloseExe()
	{
		this->close();
	}

	void slotPDAF50cmFinish()
	{
		hisglobalparameter.flagLocker.lockForWrite();
		hisglobalparameter.bSlaveMotionFinish	=	true;
		hisglobalparameter.flagLocker.unlock();
	}

	void slotSlaveShortcutExe()
	{
		QList<_shoutCutDetailCopy> shortcutC1 = classTcpClient.shortcutC1;
		QList<_shoutCutDetailCopy> shortcutC2 = classTcpClient.shortcutC2;
		qDebug() << "slotSlaveShortcutExe";
		if(!itemshareDataC1.shortcutgather.size())
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);		
		}
		HISCCMSHORTCUT::eraseKeyItem(itemshareDataC1.shortcutgather, '#');

		_shoutCutDetail stItem;
		stItem.shortcutKey	=	'#';
		stItem.ucClickTime	=	1;
		for(QList<_shoutCutDetailCopy>::iterator theiterator = shortcutC1.begin(); theiterator != shortcutC1.end(); theiterator++)
		{
			stItem.bDualCamera	=	theiterator->bDualCamera;
			stItem.bMaster			=	theiterator->bMaster;
			stItem.bSync				=	theiterator->bSync;
			stItem.strAddInfo			=	theiterator->strAddInfo;
			stItem.ucItemIndex		=	theiterator->ucItemIndex;
			stItem.ucloopTime		=	theiterator->ucloopTime;
			stItem.usItem				=	theiterator->usItem;
			stItem.usItemfail			=	theiterator->usItemfail;
			itemshareDataC1.shortcutgather.push_back(stItem);
			qDebug() <<stItem.usItem << stItem.bDualCamera << stItem.ucItemIndex;
		}

		if(classPlatform.getCameraCountSupported() == 2)
		{
			if(!itemshareDataC2.shortcutgather.size())
			{
				HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC2.currentTableName, itemshareDataC2.shortcutgather, false);
				HISCCMSHORTCUT::setShortcutSync(itemshareDataC2.shortcutgather);
			}
			HISCCMSHORTCUT::eraseKeyItem(itemshareDataC2.shortcutgather, '#');

			stItem.shortcutKey	=	'#';
			stItem.ucClickTime	=	1;
			for(QList<_shoutCutDetailCopy>::iterator theiterator = shortcutC2.begin(); theiterator != shortcutC2.end(); theiterator++)
			{
				stItem.bDualCamera	=	theiterator->bDualCamera;
				stItem.bMaster			=	theiterator->bMaster;
				stItem.bSync				=	theiterator->bSync;
				stItem.strAddInfo			=	theiterator->strAddInfo;
				stItem.ucItemIndex		=	theiterator->ucItemIndex;
				stItem.ucloopTime		=	theiterator->ucloopTime;
				stItem.usItem				=	theiterator->usItem;
				stItem.usItemfail			=	theiterator->usItemfail;
				itemshareDataC2.shortcutgather.push_back(stItem);
			}

			if(itemshareDataC1.mutexItemExec.tryLock(30))
			{
				if(itemshareDataC2.mutexItemExec.tryLock(30)){
					itemshareDataC1.mutexItemExec.unlock();
					itemshareDataC2.mutexItemExec.unlock();
					emit signalExecKeyshortcutC1('#', 1);
					emit signalExecKeyshortcutC2('#', 1);
				}
				else{
					itemshareDataC1.mutexItemExec.unlock();
				}
			}
		}
		else
		{
			if(itemshareDataC1.mutexItemExec.tryLock(30)){
				itemshareDataC1.mutexItemExec.unlock();
				emit signalExecKeyshortcutC1('#', 1);		
			}
		}

	}

	void slotMasterExeFinish(unsigned short usItem, unsigned char ucItemIndex, quint8 u8Status)
	{
		qDebug() <<"slotMasterExeFinish" <<usItem << ucItemIndex << u8Status;
		threadshareDataC1.flaglock.lockForWrite();
		windowc1.itemprocessworker->bMasterItemExecFinish		=	true;
		windowc1.itemprocessworker->u8MasterItemExecStatus	=	u8Status;
		threadshareDataC1.flaglock.unlock();

		threadshareDataC2.flaglock.lockForWrite();
		windowc2.itemprocessworker->bMasterItemExecFinish		=	true;
		windowc2.itemprocessworker->u8MasterItemExecStatus	=	u8Status;
		threadshareDataC2.flaglock.unlock();
	}



public:
	Ui::QHMainWindow ui;
	HisFX3CCMTest windowc1;
	HisFX3CCMTest windowc2;
	bool b2ndClick[36];
	QHTcpIpClient classTcpClient;
	QMyTcpServer  m_MyTCPServer;
	QHthreadShortcut* shortcutworker;
	quint8 cu8TimeResolution;

	//****************** 2017/12/11 ADD ***********
	jsl_loginDialog loginDlg;

	HDEVNOTIFY hDeviceNote;
};

#endif // QHMAINWINDOW_H
