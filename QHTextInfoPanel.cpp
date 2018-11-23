#include "QHTextInfoPanel.h"
#include <QListWidgetItem>
#include <QDir>
#include <QTextCodec>
#include <QTextStream>
#include <QTime>
#include <QStringBuilder>
#include <QMenu>
#include <windows.h>
#include "savedebuginfo.h"
#include "globaldefine.h"

QHTextInfoPanel::QHTextInfoPanel(QWidget *parent, bool bChannel1, bool* bSaveTextInfo2Local2)
	: QDockWidget(parent), bBoxChannel1(bChannel1), bSaveTextInfo2Local(bSaveTextInfo2Local2)
{
	ui.setupUi(this);

	connect(ui.listinfowidge, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(info_customMenuRequested(QPoint)));

}

QHTextInfoPanel::~QHTextInfoPanel()
{
	if(*bSaveTextInfo2Local)
	{
		QDateTime classDataTime = QDateTime::currentDateTime();
		QString strFileName = "Text Info" % classDataTime.toString("[yyyy.MM.dd]");
		if(classDataTime.time().hour() <= 12) strFileName.append("[00]");
		else strFileName.append("[12]");
		QDir classDir;
		classDir.mkpath(QDir::currentPath() % "/savelog");
		if(bBoxChannel1)
			strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C1].txt";
		else
			strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C2].txt";
		QFile classLocalFile(strFileName);
		if(classLocalFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			QString strText;
			unsigned int uiItemCount = ui.listinfowidge->count();
			for(unsigned int x=0;	x<uiItemCount;	++x)
			{
				QListWidgetItem *stItem = ui.listinfowidge->item(x);
				strText	=	stItem->text() % "\n";
				classLocalFile.write(strText.toUtf8());
			}
			classLocalFile.close();
		}
	}
}

void QHTextInfoPanel::info_customMenuRequested(QPoint pos)
{
	QMenu menu(this);

	QAction* saveAct	=	new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&保存"), this);
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveinformation()));
	menu.addAction(saveAct);

	QAction* clearAct	=	new QAction(QTextCodec::codecForName( "GBK")->toUnicode("&清除"), this);
	connect(clearAct, SIGNAL(triggered()), this, SLOT(clearinformation()));
	menu.addAction(clearAct);

	menu.exec(QCursor::pos());
}

void QHTextInfoPanel::saveinformation()
{
	savedebuginfo* debuginfo	=	new savedebuginfo();
	if(debuginfo->exec() == QDialog::Accepted)
	{

	}
	QString strPath	=	debuginfo->qPath ;

	//QString strPath	=	QDir::currentPath() % "/debuglog.txt"; 
	QFile classFile(strPath);
	if(!classFile.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)){
		ShowInformation(QTextCodec::codecForName( "GBK")->toUnicode("打开txt文件失败"));
		return;
	}

	classFile.seek(0);

	unsigned int uiCount	=	ui.listinfowidge->count();
	if(!uiCount){
		classFile.close();
		return;
	}

	QTextStream fileout(&classFile);

	QListWidgetItem* pitem;
	for(unsigned int x=0;	x<uiCount;	++x){
		pitem	=	ui.listinfowidge->item(x);
		fileout << pitem->text() << "\r\n";
	}

	classFile.close();
	ShowInformation(QTextCodec::codecForName( "GBK")->toUnicode("信息保存完成"));
}

void QHTextInfoPanel::clearinformation()
{
	if(*bSaveTextInfo2Local)
	{
		QDateTime classDataTime = QDateTime::currentDateTime();
		QString strFileName = "Text Info" % classDataTime.toString("[yyyy.MM.dd]");
		if(classDataTime.time().hour() <= 12) strFileName.append("[00]");
		else strFileName.append("[12]");
		QDir classDir;
		classDir.mkpath(QDir::currentPath() % "/savelog");
		if(bBoxChannel1)
			strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C1].txt";
		else
			strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C2].txt";
		QFile classLocalFile(strFileName);
		if(classLocalFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			QString strText;
			unsigned int uiItemCount = ui.listinfowidge->count();
			for(unsigned int x=0;	x<uiItemCount;	++x)
			{
				QListWidgetItem *stItem = ui.listinfowidge->item(x);
				strText	=	stItem->text() % "\n";
				classLocalFile.write(strText.toUtf8());
			}
			classLocalFile.close();
		}
	}

	ui.listinfowidge->clear();
}

void QHTextInfoPanel::ShowInformation(QString info)
{
/*
	QListWidgetItem* plistitem	=	new QListWidgetItem(info.prepend((QTime::currentTime()).toString("hh:mm:ss.zzz   ")), ui.listinfowidge);
	if(ui.listinfowidge->count() > 1000){
		plistitem		=	ui.listinfowidge->takeItem(0);
		delete plistitem;
		plistitem	=	0;
	}
*/
	QDateTime classDataTime = QDateTime::currentDateTime();
	info.prepend(classDataTime.toString("HH:mm:ss.zzz   "));

	ui.listinfowidge->addItem(info);
	if(ui.listinfowidge->count() > 500)
	{
		if(*bSaveTextInfo2Local)
		{
			QString strFileName = "Text Info" % classDataTime.toString("[yyyy.MM.dd]");
			if(classDataTime.time().hour() <= 12) strFileName.append("[00]");
			else strFileName.append("[12]");
			QDir classDir;
			classDir.mkpath(QDir::currentPath() % "/savelog");
			if(bBoxChannel1)
				strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C1].txt";
			else
				strFileName	=	QDir::currentPath() % "/savelog/" % strFileName % "[C2].txt";
			QFile classLocalFile(strFileName);
			if(classLocalFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
			{
				QString strText;
				for(unsigned int x=0;	x<100;	++x)
				{
					QListWidgetItem *stItem = ui.listinfowidge->takeItem(x);
					strText	=	stItem->text() % "\n";
					classLocalFile.write(strText.toUtf8());
					delete stItem;
				}
				classLocalFile.close();
			}
		}
		else
		{
			for(unsigned int x=0;	x<100;	++x)
			{
				delete ui.listinfowidge->takeItem(x);
			}
		}
	}


	ui.listinfowidge->scrollToBottom();
}