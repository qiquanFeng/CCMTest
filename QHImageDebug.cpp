#include "QHImageDebug.h"

QHImageDebug::QHImageDebug(QWidget *parent, bool bChannel1)
	: QDockWidget(parent), bBoxChannel1(bChannel1)
{
	ui.setupUi(this);

	connect(ui.phaseShiftpushButton, SIGNAL(released()), this, SLOT(slotDVPPhaseShift()));

	getDecodeInfoTimer.setSingleShot(false);
	getDecodeInfoTimer.setInterval(100);
	getDecodeInfoTimer.start();
	connect(&getDecodeInfoTimer, SIGNAL(timeout()), this, SLOT(slotGetFPGADecodeInfo()));
}

QHImageDebug::~QHImageDebug()
{

}

void QHImageDebug::slotDVPPhaseShift()
{
	int iresult = classPlatform.HisFX3DVPPCLKPhaseShift(ui.dvpPhaseShiftcomboBox->currentIndex());
	if(iresult){
		ui.infolabel->setText(tr("Set Fail"));
	}
	else{
		ui.infolabel->setText(tr("Set Success"));
	}
}

void QHImageDebug::slotGetFPGADecodeInfo()
{
	std::string strinfo;
	if(bBoxChannel1)
		classPlatform.getFPGADecodeInfo(strinfo);
	else
		classPlatform.getFPGADecodeInfo_S2(strinfo);

	if(classPlatform.getCurrentPlatformType() == _HisFX3_Platform_Type_R3X && bBoxChannel1)
	{
		unsigned int version;
		classPlatform.HisFX3GetHardwareVersion(&version);
		if((version & 0xFFFF) >= 1509){
			double t = 0.0;
			if (classPlatform.GetTemperature(&t) == 0){
				char text[64];
				sprintf(text, "\nFPGA Temperature: %f", t);
				strinfo += text;
			}
		}
	}

	ui.fpgaDecodeInfolabel->setText(QString::fromStdString(strinfo));
}
