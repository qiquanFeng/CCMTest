#include "QHRepeatedTest.h"
#include "qoplow.h"

QHRepeatedTest::QHRepeatedTest(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);

	connect(ui.testpushButton, SIGNAL(released()), this, SLOT(slotTest()));
	connect(ui.stoppushButton, SIGNAL(released()), this, SLOT(slotStop()));

	bTest = false;

	repeatTimer.setSingleShot(false);
	repeatTimer.setInterval(300);
	if(repeatTimer.isActive())	repeatTimer.stop();
	connect(&repeatTimer, SIGNAL(timeout()), this, SLOT(slotLoopOne()));
}

QHRepeatedTest::~QHRepeatedTest()
{

}

void QHRepeatedTest::slotTest()
{
	if(bTest) return;

	bTest	=	true;
	uiTestCount	=	0;
	uiTotalTestTimes	=	ui.timesspinBox->value();
	if(ui.shortcutcomboBox->currentIndex() == 0) key = '=';
	else if(ui.shortcutcomboBox->currentIndex() >= 1 && ui.shortcutcomboBox->currentIndex() <= 10)
		key = '0' + (ui.shortcutcomboBox->currentIndex() - 1);
	else
		key = 'a' + (ui.shortcutcomboBox->currentIndex() - 11);

	if(classPlatform.getCameraCountSupported() == 2)
	{
		if(!itemshareDataC1.shortcutgather.size())
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
		}
		if(!itemshareDataC2.shortcutgather.size())
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC2.currentTableName, itemshareDataC2.shortcutgather, false);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC2.shortcutgather);
		}

		if(!HISCCMSHORTCUT::isKeyValidTwoChannel(key, 1, itemshareDataC1.shortcutgather, itemshareDataC2.shortcutgather))
		{
			return;
		}
	}
	else
	{
		if(!itemshareDataC1.shortcutgather.size())
		{
			HISCCMSHORTCUT::getCCMShortcutItem(hisglobalparameter.mutexDatabase, itemshareDataC1.currentTableName, itemshareDataC1.shortcutgather, true);
			HISCCMSHORTCUT::setShortcutSync(itemshareDataC1.shortcutgather);
		}

		if(!HISCCMSHORTCUT::isKeyValidOneChannel(key, 1, itemshareDataC1.shortcutgather))
		{
			return;
		}

	}

	ui.infolabel->setText(tr("Start Repeated Test Have."));

	repeatTimer.start();
}

void QHRepeatedTest::slotStop()
{
	bTest = false;
}

void QHRepeatedTest::slotLoopOne()
{
	if(bTest)
	{
		if(uiTestCount < uiTotalTestTimes)
		{
			if(itemshareDataC1.mutexItemExec.tryLock(30))
			{
				if(itemshareDataC2.mutexItemExec.tryLock(30))
				{
					itemshareDataC1.mutexItemExec.unlock();
					itemshareDataC2.mutexItemExec.unlock();

					++uiTestCount;
					emit signalExecKeyshortcutC1(key, 1);		
					emit signalExecKeyshortcutC2(key, 1);		
					ui.infolabel->setText(tr("Have Tested Times: ") % QString::number(uiTestCount));
				}
				else
				{
					itemshareDataC1.mutexItemExec.unlock();
				}
			}
		}
		else
		{
			bTest = false;
		}
	}

	if(!bTest)
	{
		repeatTimer.stop();
		ui.infolabel->setText(tr("Repeated Test Have Stopped."));
	}
}