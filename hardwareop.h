#ifndef HARDWAREOP_H
#define HARDWAREOP_H

#include <QDockWidget>
#include "ui_hardwareop.h"
#include "globaldefine.h"
#include "qoplow.h"

class hardwareop : public QDockWidget
{
	Q_OBJECT

public:
	hardwareop(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, _globalFunctionPointer& globalFunPointerC);
	~hardwareop();

	void seti2cinfo(unsigned char ucslave, unsigned short ustype);

	void showinformation(QString strinfo);
	void batchwritei2c_NotHardware();
	void batchwritei2c_Hardware();
	void batchreadi2c_Hardware();
	void batchreadi2c_NotHardware();

	void analysisBinPainText(unsigned int* puiAddr, unsigned int* puiData, unsigned int& uiCount);
	void toBinPainText(unsigned int* puiAddr, unsigned int* puiData, unsigned int uiCount);


	void changeHexStrLength(QString& strHex, unsigned int uiLength){
		while(strHex.size() < uiLength)
			strHex.prepend("0");
	}

public:
	Ui::hardwareop ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	_globalFunctionPointer& globalFunPointer;
  
public slots:
	void freshVoltage();
	void setVoltage();
	void resethigh();
	void resetlow();
	void pwndhigh();
	void pwndlow();
	void freshmclk();
	void setmclk();
	void freshlane();
	void setlane();
	void readi2c();
	void writei2c();
	void batchwritei2c();
	void batchreadi2c();
	void changgpio0(int state);
	void changgpio1(int state);
	void changgpio2(int state);
	void changgpio3(int state);
	void readGPIOStatus();
	void searchSlave();
	void openBIN();
	void saveBIN();
	void writeBIN();
	void readBIN();
	void binDataCreate();
	void binDataCreate0();
	void binDataCreate0xFF();
	void slotBatchTest();
	void slotMeasureVolt();

	void changeMIPILaneCombo(int index)
	{
#ifdef _HisFX3_Platform_MIPI_V2
		ui.vsync_checkBox->setChecked(index == 0);
#endif
	}

	void slotChangeCommuProtocal(const QString & text)
	{
		bool bSPI	=	(text == "SPI");
		ui.spiCSLowcheckBox->setVisible(bSPI);
		ui.spiLittleEndiancheckBox->setVisible(bSPI);
	}

	void slotBatchIICModeChange(int index)
	{
		if(index == 2)
		{
			ui.pageStartAddrlabel->setVisible(true);
			ui.pageStartAddrlineEdit->setVisible(true);
			ui.pageSlavelabel->setVisible(true);
			ui.batchSlavelineEdit->setVisible(true);
			ui.pageSizelabel->setVisible(true);
			ui.pageSizespinBox->setVisible(true);
		}
		else
		{
			ui.pageStartAddrlabel->setVisible(false);
			ui.pageStartAddrlineEdit->setVisible(false);
			ui.pageSizelabel->setVisible(false);
			ui.pageSizespinBox->setVisible(false);

#ifndef _DEBUG
			ui.pageSlavelabel->setVisible(false);
			ui.batchSlavelineEdit->setVisible(false);
#endif
		}
	}

	void slotBatchFormat()
	{

	}

};

#endif // HARDWAREOP_H
