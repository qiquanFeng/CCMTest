#ifndef CONFIGSETTING_H
#define CONFIGSETTING_H

#include <QDockWidget>
#include "ui_configsetting.h"
#include "globaldefine.h"
#include "qoplow.h"
#include "QSqlTableModel.h"
#include "QSqlError.h"
#include "QMenu.h"
#include "QTextCodec.h"
#include "QSqlQuery.h"
#include "QSqlRecord.h"
#include "QVariant.h"
#include "QHTextItemEdit.h"
#include <qtextcursor.h >
#include <QTextBlock> 
#include "itemprocess.h"

class configsetting : public QDockWidget
{
	Q_OBJECT

public:
	configsetting(QWidget *parent, bool bChannel1, _threadshareData& threadshareDataC, _global_itemexec& itemshareDataC, itemprocess* classItemProcess2);
	~configsetting();

	void previewData2UI();
	int savePreviewData();
	 
	void ccmData2UI();
	int saveCCMData();

	void whitepanel2UI();
	int saveWhitePanel();

	void blackpanel2UI();
	int saveBlackPanel();

	int saveOtpBurnData();

	void afBurn2UI();
	int saveAfBurnData();

	void pdafBurn2UI();
	int savePDAFBurnData();
	  
	void logData2UI();
	int saveLogData();

	void customIIC2UI();
	int saveCustomIICData(unsigned int uiGroup);

	void workCurrent2UI();
	int saveWorkCurrentData();

	void standbyCurrent2UI();
	int saveStandbyCurrentData();
	 
	void openshort2UI();
	int saveOpenShortData();
	 
	void afcMTFBasic2UI(unsigned char uctype);
	int saveAFCMTFBasicData(unsigned char uctype);

	void afcMTFTactics2UI(unsigned char uctype);
	int saveAFCMTFTacticsData(unsigned char uctype);

	void afcSFRABasic2UI(unsigned char uctype);
	int saveAFCSFRABasicData(unsigned char uctype);

	void afcSFRATactics2UI(unsigned char uctype);
	int saveAFCSFRATacticsData(unsigned char uctype);

	void afcLpBasic2UI(unsigned char uctype);
	int saveAFCLpBasicData(unsigned char uctype);

	void afcLpATactics2UI(unsigned char uctype);
	int saveAFCLpATacticsData(unsigned char uctype);

	void autoFA2UI();
	int saveAutoFAData();

	void ducalcameraBurn2UI();
	int saveducalcameraBurnData();

	void lightSourceCheck2UI();
	int saveLightSourceCheckExec();
	 
signals:

  
private slots:
	void DPCRULE2UI();
	void otpBurn2UI();
	void savepreviewinfo();
	void slotospSelectall(int state);
	void slotospnotSelectall(int state);
	void slotospallchange(int index);
	void slotosnSelectall(int state);
	void slotosnnotSelectall(int state);
	void slotoscSelectall(int state);
	void slotoscnotSelectall(int state);
	void slotortSelectall(int state);
	void slotortnotSelectall(int state);
	void slotoocSelectall(int state);
	void slotoocnotSelectall(int state);

	void savewhitepanelinfo();

	void dovddWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_dovdd->setEnabled(bchecked);}
	void dvddWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_dvdd->setEnabled(bchecked);}
	void avddWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_avdd->setEnabled(bchecked);}
	void afWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_af->setEnabled(bchecked);}
	void vfuseWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_vfuse->setEnabled(bchecked);}
	void powWorkCurrentOnOffchecked(bool bchecked) {ui.groupBox_workcurrent_pow->setEnabled(bchecked);}

	void dovddStandbyCurrentOnOffchecked(bool bchecked) {ui.groupBox_standbycurrent_dovdd->setEnabled(bchecked);}
	void dvddStandbyCurrentOnOffchecked(bool bchecked) {ui.groupBox_standbycurrent_dvdd->setEnabled(bchecked);}
	void avddStandbyCurrentOnOffchecked(bool bchecked) {ui.groupBox_standbycurrent_avdd->setEnabled(bchecked);}
	void afStandbyCurrentOnOffchecked(bool bchecked) {ui.groupBox_standbycurrent_af->setEnabled(bchecked);}
	void powStandbyCurrentOnOffchecked(bool bchecked) {ui.groupBox_standbycurrent_pow->setEnabled(bchecked);}

	void saveCurrent();
	void saveOpenShort();
	void changeOSTableName(const QString & text);
	void slotqualcommPDAFVersionChange(const QString &strVersion);
	void slotqualcommPDAFsensortypeChange(const QString &strtype);
	void slotPDAFplatformChange(int index);
	
	void slotOSNegtiveDOVDDAllChange(int index)
	{
		for(unsigned int x=0;	x<ui.osNegtivetableWidget->rowCount();	++x)
		{
			QComboBox* pstNegtive		=	(QComboBox*)ui.osNegtivetableWidget->cellWidget(x, 1);
			pstNegtive->setCurrentIndex(index);
		}
	}

	void saveAFCMTFNearTactics()
	{
		int iresult = saveAFCMTFTacticsData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFTactics2UI(0);
	}

	void saveAFCMTFMiddleTactics()
	{
		int iresult = saveAFCMTFTacticsData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFTactics2UI(1);
	}

	void saveAFCMTFFarTactics()
	{
		int iresult = saveAFCMTFTacticsData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFTactics2UI(2);
	}

	void saveAFCMTFNearBasic()
	{
		int iresult = saveAFCMTFBasicData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFBasic2UI(0);
	}

	void saveAFCMTFMiddleBasic()
	{
		int iresult = saveAFCMTFBasicData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFBasic2UI(1);
	}

	void saveAFCMTFFarBasic()
	{
		int iresult = saveAFCMTFBasicData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFBasic2UI(2);
	}

	void saveMFAMTFBasic() 
	{
		int iresult = saveAFCMTFBasicData(3);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcMTFBasic2UI(3);
	}

	void saveAFCSFRANearBasic()
	{
		int iresult = saveAFCSFRABasicData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRABasic2UI(0);
	}

	void saveAFCSFRAMiddleBasic()
	{
		int iresult = saveAFCSFRABasicData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRABasic2UI(1);
	}

	void saveAFCSFRAFarBasic()
	{
		int iresult = saveAFCSFRABasicData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRABasic2UI(2);
	}

	void saveMFASFRABasic()
	{
		int iresult = saveAFCSFRABasicData(3);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRABasic2UI(3);
	}

	void saveAFCSFRANearTactics()
	{
		int iresult = saveAFCSFRATacticsData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRATactics2UI(0);
	}

	void saveAFCSFRAMiddleTactics()
	{
		int iresult = saveAFCSFRATacticsData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRATactics2UI(1);
	}

	void saveAFCSFRAFarTactics()
	{
		int iresult = saveAFCSFRATacticsData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		else ui.statuslabel->setText(tr("Save Parameter Success"));
		afcSFRATactics2UI(2);
	}

	void slotCommProtocalChange(const QString & text)
	{
		bool bSPI	=	(text == "SPI");
		ui.spiCSLow_checkBox->setVisible(bSPI);
		ui.spiLittleEndian_checkBox->setVisible(bSPI);	
	}

	void slotDataProtocalChange(const QString & text)
	{
		unsigned int uiProtocal	=	 HISGLOBALUI::protocal2UInt(text);
		bool bLVDS = (uiProtocal >= _HisFX3_MIPILane_Stream_SubLVDS_SONY && uiProtocal <= _HisFX3_MIPILane_Stream_SubLVDS_END);
		bool bDVP	=	(uiProtocal == _HisFX3_MIPILane_Stream_DVP || uiProtocal == _HisFX3_MIPILane_Stream_Analog_Interleave || \
			uiProtocal == _HisFX3_MIPILane_Stream_Analog_Progressive || uiProtocal == _HisFX3_MIPILane_Stream_DVP_HDMI);
		bDVP = bDVP || (uiProtocal >= _HisFX3_MIPILane_Stream_BT1120M1_Interleave && uiProtocal <= _HisFX3_MIPILane_Stream_BT1120M2_Progressive);
		bool bHiSPI	=	(uiProtocal >= _HisFX3_MIPILane_Stream_HiSPI_Packetized_SP && uiProtocal <= _HisFX3_MIPILane_Stream_HiSPI_END);
		 
		ui.dvpStartgroupBox->setVisible(bDVP);

		ui.laneNumberlabel->setVisible(bLVDS || bHiSPI);
		ui.laneNumberspinBox->setVisible(bLVDS || bHiSPI);

		ui.lvdsStartgroupBox->setVisible(bLVDS);
		ui.lvdsAligngroupBox->setVisible(bLVDS);
	}

	void clearDB_FC();
	void clearDB_AE();

	void getdefaultotpBurn();
	void saveotpBurn();
	void saveLightSourceCheck();
	void saveDPCLoadRule();

	void saveAFBurn();
	void saveSaveLog();
	void saveBlackField();
	void saveMTKPDAFBurn();
	void saveducalcameraBurn();
	void slotOSPositiveOnOff(bool bChecked) { ui.OStabWidget->setTabEnabled(0, bChecked); }
	void slotOSNegtiveOnOff(bool bChecked) { ui.OStabWidget->setTabEnabled(1, bChecked); }
	void slotOSShortTestOnOff(bool bChecked) { ui.OStabWidget->setTabEnabled(2, bChecked); }
	void slotOSOpenTestOnOff(bool bChecked) { ui.OStabWidget->setTabEnabled(4, bChecked); }
	void slotOSResistanceOnOff(bool bChecked) { ui.OStabWidget->setTabEnabled(3, bChecked); }

	void saveAFCLpNearBasic()
	{
		int iresult = saveAFCLpBasicData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpBasic2UI(0);
	}

	void saveAFCLpMiddleBasic()
	{
		int iresult = saveAFCLpBasicData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpBasic2UI(1);
	}

	void saveAFCLpFarBasic()
	{
		int iresult = saveAFCLpBasicData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpBasic2UI(2);
	}

	void saveLpMFA()
	{
		int iresult = saveAFCLpBasicData(3);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpBasic2UI(3);
	}

	void saveAFCLpNearTactics()
	{
		int iresult = saveAFCLpATacticsData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpATactics2UI(0);
	}

	void saveAFCLpMiddleTactics()
	{
		int iresult = saveAFCLpATacticsData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpATactics2UI(1);
	}

	void saveAFCLpFarTactics()
	{
		int iresult = saveAFCLpATacticsData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Parameter Fail"));
		afcLpATactics2UI(2);
	}
		
	void RelaceSlave();
	void BlemishAlgSwitch(int index) {ui.blemishstackedWidget->setCurrentIndex(index);}
	void DefectPixelAlgSwitch(int index) {ui.defectpixelstackedWidget->setCurrentIndex(index);}
	void ShadingAlgSwitch(int index) {ui.shadingstackedWidget->setCurrentIndex(index);}
	void WPColorAlgSwitch(int index) {ui.colorstackedWidget->setCurrentIndex(index);}
	void OCAlgSwitch(int index) {ui.opticalcenterstackedWidget->setCurrentIndex(index);}
	void CHIPIDSwitch(const QString & strItem);
	void saveAutoFA();

	void BlackLightPixelAlgSwitch(int index) {ui.blackFieldstackedWidget->setCurrentIndex(index);}
	void LightSourceCheckSwitch(int index) {ui.lightSourceCheckstackedWidget->setCurrentIndex(index);}

	void slotAFAMarkOnoff(int state)
	{
		if(state == Qt::Unchecked){
			ui.afaMarkgroupBox->setVisible(false);
		}
		else{
			ui.afaMarkgroupBox->setVisible(true);

		}
	}

	void slotAFAChartChange(const QString & text)
	{
		if(text == "SFR-A"){
			ui.afaMarkgroupBox->setVisible(true);
			ui.afaSFRABlockMarklabel->setVisible(true);
			ui.afaSFRABlockMarkspinBox->setVisible(true);
			ui.afaMTFMarkRangeXlabel->setVisible(false);
			ui.afaMTFMarkRangeXdoubleSpinBox->setVisible(false);
			ui.afaXYReversalcheckBox->setVisible(false);
			ui.afaMTFMarkRangeYlabel->setVisible(false);
			ui.afaMTFMarkRangeYdoubleSpinBox->setVisible(false);
			ui.afaMTFMarkRangeXlabel_2->setVisible(false);
			ui.afaMTFMarkRangeYMaxdoubleSpinBox->setVisible(false);
		}
		else if(text == "MTF-B"){
			ui.afaMarkgroupBox->setVisible(true);
			ui.afaSFRABlockMarklabel->setVisible(false);
			ui.afaSFRABlockMarkspinBox->setVisible(false);
			ui.afaMTFMarkRangeXlabel->setVisible(true);
			ui.afaMTFMarkRangeXdoubleSpinBox->setVisible(true);
			ui.afaXYReversalcheckBox->setVisible(true);
			ui.afaMTFMarkRangeYlabel->setVisible(true);
			ui.afaMTFMarkRangeYdoubleSpinBox->setVisible(true);
			ui.afaMTFMarkRangeXlabel_2->setVisible(true);
			ui.afaMTFMarkRangeYMaxdoubleSpinBox->setVisible(true);
		}
		else if(text == "TV Line-A"){
			ui.afaMarkgroupBox->setVisible(true);
			ui.afaSFRABlockMarklabel->setVisible(false);
			ui.afaSFRABlockMarkspinBox->setVisible(false);
			ui.afaMTFMarkRangeXlabel->setVisible(false);
			ui.afaMTFMarkRangeXdoubleSpinBox->setVisible(false);
			ui.afaXYReversalcheckBox->setVisible(false);
			ui.afaMTFMarkRangeYlabel->setVisible(false);
			ui.afaMTFMarkRangeYdoubleSpinBox->setVisible(false);
			ui.afaMTFMarkRangeXlabel_2->setVisible(false);
			ui.afaMTFMarkRangeYMaxdoubleSpinBox->setVisible(false);
		}
		else{
			ui.afaMarkgroupBox->setVisible(false);
		}
	}

	void changeAFCNearSFRABasicMethod(int index)
	{
		if(index == _His_SFR_Method_2Freq)
		{		
			ui.afcsfraNBtableWidget->showColumn(8);
			ui.afcsfraNBtableWidget->showColumn(9);
			ui.afcsfraNBtableWidget->showColumn(10);
			ui.afcsfraNBtableWidget->showColumn(11);
			ui.afcsfraNBtableWidget->showColumn(12);
			ui.afcsfraNBtableWidget->showColumn(13);		
			ui.afcsfraNBtableWidget->hideColumn(5);
			ui.afcsfraNBtableWidget->hideColumn(6);
			ui.afcsfraNBtableWidget->hideColumn(7);

			ui.afcsfraNBMTF50groupBox->setVisible(false);
			ui.afcsfraNBF2SpecgroupBox->setVisible(true);
			ui.afcsfraNBF2groupBox->setVisible(true);

			if(ui.afcsfraNBUseF2checkBox->isChecked())
				AFCNearSFRABasicFreq2Checked(Qt::Checked);
			else
				AFCNearSFRABasicFreq2Checked(Qt::Unchecked);
		}
		else
		{			
			ui.afcsfraNBtableWidget->hideColumn(8);
			ui.afcsfraNBtableWidget->hideColumn(9);
			ui.afcsfraNBtableWidget->hideColumn(10);
			ui.afcsfraNBtableWidget->hideColumn(11);
			ui.afcsfraNBtableWidget->hideColumn(12);
			ui.afcsfraNBtableWidget->hideColumn(13);			
			ui.afcsfraNBtableWidget->showColumn(5);
			ui.afcsfraNBtableWidget->showColumn(6);
			ui.afcsfraNBtableWidget->showColumn(7);

			ui.afcsfraNBMTF50groupBox->setVisible(true);
			ui.afcsfraNBF2SpecgroupBox->setVisible(false);
			ui.afcsfraNBF2groupBox->setVisible(false);
		}
	}

	void AFCNearSFRABasicFreq2Checked(int state)
	{
		bool bChecked = (state == Qt::Checked);
		ui.afcsfraNBF2label->setVisible(bChecked);
		ui.afcsfraNBF2SpinBox->setVisible(bChecked);
		ui.afcsfraNBF2CenterHlabel->setVisible(bChecked);
		ui.afcsfraNBCenterF2HdoubleSpinBox->setVisible(bChecked);
		ui.afcsfraNBF2CenterVlabel->setVisible(bChecked);
		ui.afcsfraNBCenterF2VdoubleSpinBox->setVisible(bChecked);

		if(bChecked && ui.afcsfraNBMethodcomboBox->currentIndex() == _His_SFR_Method_2Freq){
			ui.afcsfraNBtableWidget->showColumn(11);
			ui.afcsfraNBtableWidget->showColumn(12);
			ui.afcsfraNBtableWidget->showColumn(13);
		}
		else{
			ui.afcsfraNBtableWidget->hideColumn(11);
			ui.afcsfraNBtableWidget->hideColumn(12);
			ui.afcsfraNBtableWidget->hideColumn(13);
		}
	}

	void changeAFCMiddleSFRABasicMethod(int index)
	{
		if(index == _His_SFR_Method_2Freq){		
			ui.afcsfraMBtableWidget->showColumn(8);
			ui.afcsfraMBtableWidget->showColumn(9);
			ui.afcsfraMBtableWidget->showColumn(10);
			ui.afcsfraMBtableWidget->showColumn(11);
			ui.afcsfraMBtableWidget->showColumn(12);
			ui.afcsfraMBtableWidget->showColumn(13);
			ui.afcsfraMBtableWidget->hideColumn(5);
			ui.afcsfraMBtableWidget->hideColumn(6);
			ui.afcsfraMBtableWidget->hideColumn(7);

			ui.afcsfraMBMTF50groupBox->setVisible(false);
			ui.afcsfraMBF2SpecgroupBox->setVisible(true);
			ui.afcsfraMBF2groupBox->setVisible(true);

			if(ui.afcsfraMBUseF2checkBox->isChecked())
				AFCMiddleSFRABasicFreq2Checked(Qt::Checked);
			else
				AFCMiddleSFRABasicFreq2Checked(Qt::Unchecked);
		}
		else{		
			ui.afcsfraMBtableWidget->hideColumn(8);
			ui.afcsfraMBtableWidget->hideColumn(9);
			ui.afcsfraMBtableWidget->hideColumn(10);
			ui.afcsfraMBtableWidget->hideColumn(11);
			ui.afcsfraMBtableWidget->hideColumn(12);
			ui.afcsfraMBtableWidget->hideColumn(13);
			ui.afcsfraMBtableWidget->showColumn(5);
			ui.afcsfraMBtableWidget->showColumn(6);
			ui.afcsfraMBtableWidget->showColumn(7);

			ui.afcsfraMBMTF50groupBox->setVisible(true);
			ui.afcsfraMBF2SpecgroupBox->setVisible(false);
			ui.afcsfraMBF2groupBox->setVisible(false);
		}
	}

	void AFCMiddleSFRABasicFreq2Checked(int state)
	{
		bool bChecked = (state == Qt::Checked);
		ui.afcsfraMBF2label->setVisible(bChecked);
		ui.afcsfraMBF2SpinBox->setVisible(bChecked);
		ui.afcsfraMBF2CenterHlabel->setVisible(bChecked);
		ui.afcsfraMBCenterF2HdoubleSpinBox->setVisible(bChecked);
		ui.afcsfraMBF2CenterVlabel->setVisible(bChecked);
		ui.afcsfraMBCenterF2VdoubleSpinBox->setVisible(bChecked);

		if(bChecked && ui.afcsfraMBMethodcomboBox->currentIndex() == _His_SFR_Method_2Freq){
			ui.afcsfraMBtableWidget->showColumn(11);
			ui.afcsfraMBtableWidget->showColumn(12);
			ui.afcsfraMBtableWidget->showColumn(13);
		}
		else{
			ui.afcsfraMBtableWidget->hideColumn(11);
			ui.afcsfraMBtableWidget->hideColumn(12);
			ui.afcsfraMBtableWidget->hideColumn(13);
		}
	}

	void changeAFCFarSFRABasicMethod(int index)
	{
		if(index == _His_SFR_Method_2Freq){			
			ui.afcsfraFBtableWidget->showColumn(8);
			ui.afcsfraFBtableWidget->showColumn(9);
			ui.afcsfraFBtableWidget->showColumn(10);
			ui.afcsfraFBtableWidget->showColumn(11);
			ui.afcsfraFBtableWidget->showColumn(12);
			ui.afcsfraFBtableWidget->showColumn(13);
			ui.afcsfraFBtableWidget->hideColumn(5);
			ui.afcsfraFBtableWidget->hideColumn(6);
			ui.afcsfraFBtableWidget->hideColumn(7);

			ui.afcsfraFBMTF50groupBox->setVisible(false);
			ui.afcsfraFBF2SpecgroupBox->setVisible(true);
			ui.afcsfraFBF2groupBox->setVisible(true);

			if(ui.afcsfraFBUseF2checkBox->isChecked())
				AFCFarSFRABasicFreq2Checked(Qt::Checked);
			else
				AFCFarSFRABasicFreq2Checked(Qt::Unchecked);
		}
		else{		
			ui.afcsfraFBtableWidget->hideColumn(8);
			ui.afcsfraFBtableWidget->hideColumn(9);
			ui.afcsfraFBtableWidget->hideColumn(10);
			ui.afcsfraFBtableWidget->hideColumn(11);
			ui.afcsfraFBtableWidget->hideColumn(12);
			ui.afcsfraFBtableWidget->hideColumn(13);
			ui.afcsfraFBtableWidget->showColumn(5);
			ui.afcsfraFBtableWidget->showColumn(6);
			ui.afcsfraFBtableWidget->showColumn(7);

			ui.afcsfraFBMTF50groupBox->setVisible(true);
			ui.afcsfraFBF2SpecgroupBox->setVisible(false);
			ui.afcsfraFBF2groupBox->setVisible(false);
		}
	}

	void AFCFarSFRABasicFreq2Checked(int state)
	{
		bool bChecked = (state == Qt::Checked);
		ui.afcsfraFBF2label->setVisible(bChecked);
		ui.afcsfraFBF2SpinBox->setVisible(bChecked);
		ui.afcsfraFBF2CenterHlabel->setVisible(bChecked);
		ui.afcsfraFBCenterF2HdoubleSpinBox->setVisible(bChecked);
		ui.afcsfraFBF2CenterVlabel->setVisible(bChecked);
		ui.afcsfraFBCenterF2VdoubleSpinBox->setVisible(bChecked);

		if(bChecked && ui.afcsfraFBMethodcomboBox->currentIndex() == _His_SFR_Method_2Freq){
			ui.afcsfraFBtableWidget->showColumn(11);
			ui.afcsfraFBtableWidget->showColumn(12);
			ui.afcsfraFBtableWidget->showColumn(13);
		}
		else{
			ui.afcsfraFBtableWidget->hideColumn(11);
			ui.afcsfraFBtableWidget->hideColumn(12);
			ui.afcsfraFBtableWidget->hideColumn(13);
		}
	}

	void changeMFASFRABasicMethod(int index)
	{
#if (defined USE_MANUAL_LENS_BIN)
		if(index == _His_SFR_Method_2Freq){			
			ui.mfasfratableWidget->showColumn(8);
			ui.mfasfratableWidget->showColumn(9);
			ui.mfasfratableWidget->showColumn(10);
			ui.mfasfratableWidget->showColumn(11);
			ui.mfasfratableWidget->showColumn(12);
			ui.mfasfratableWidget->showColumn(13);
			ui.mfasfratableWidget->hideColumn(5);
			ui.mfasfratableWidget->hideColumn(6);
			ui.mfasfratableWidget->hideColumn(7);

			ui.mfasfraMTF50groupBox->setVisible(false);
			ui.mfasfraF2SpecgroupBox->setVisible(true);
			ui.mfasfraF2groupBox->setVisible(true);

			if(ui.mfasfraUseF2checkBox->isChecked())
				MFASFRABasicFreq2Checked(Qt::Checked);
			else
				MFASFRABasicFreq2Checked(Qt::Unchecked);
		}
		else{			
			ui.mfasfratableWidget->hideColumn(8);
			ui.mfasfratableWidget->hideColumn(9);
			ui.mfasfratableWidget->hideColumn(10);
			ui.mfasfratableWidget->hideColumn(11);
			ui.mfasfratableWidget->hideColumn(12);
			ui.mfasfratableWidget->hideColumn(13);
			ui.mfasfratableWidget->showColumn(5);
			ui.mfasfratableWidget->showColumn(6);
			ui.mfasfratableWidget->showColumn(7);

			ui.mfasfraMTF50groupBox->setVisible(true);
			ui.mfasfraF2SpecgroupBox->setVisible(false);
			ui.mfasfraF2groupBox->setVisible(false);
		}
#endif
	}

	void MFASFRABasicFreq2Checked(int state)
	{
		bool bChecked = (state == Qt::Checked);
		ui.mfasfraF2label->setVisible(bChecked);
		ui.mfasfraF2SpinBox->setVisible(bChecked);
		ui.mfasfraF2CenterHlabel->setVisible(bChecked);
		ui.mfasfraCenterF2HdoubleSpinBox->setVisible(bChecked);
		ui.mfasfraF2CenterVlabel->setVisible(bChecked);
		ui.mfasfraCenterF2VdoubleSpinBox->setVisible(bChecked);

		if(bChecked && ui.mfasfraMethodcomboBox->currentIndex() == _His_SFR_Method_2Freq){
			ui.mfasfratableWidget->showColumn(11);
			ui.mfasfratableWidget->showColumn(12);
			ui.mfasfratableWidget->showColumn(13);
		}
		else{
			ui.mfasfratableWidget->hideColumn(11);
			ui.mfasfratableWidget->hideColumn(12);
			ui.mfasfratableWidget->hideColumn(13);
		}
	}

	void saveALLCustomIIC()
	{
		int iresult = saveCustomIICData(0);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Group 1 Parameter Fail"));
		iresult = saveCustomIICData(1);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Group 2 Parameter Fail"));
		iresult = saveCustomIICData(2);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Group 3 Parameter Fail"));
		iresult = saveCustomIICData(3);
		if(iresult)	QMessageBox::critical(this, tr("ERROR"), tr("Save Group 4 Parameter Fail"));
		customIIC2UI();
	}

	void changeMTKPDAFVersion(const QString &text)
	{

#if (defined _WIN64) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP64D";
#elif (defined _WIN64) && !(defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP64";
#elif (defined _WIN32) && (defined _DEBUG)
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP32D";
#else
	QString strLibPath	=	QDir::currentPath() % "/HisCCMOTP32";
#endif

	RolongoOTPAPIVersion getRolongoOTPAPIVersion = (RolongoOTPAPIVersion)(QLibrary::resolve(strLibPath, "getRolongoOTPAPIVersion"));
	RolongogetMTKPDAFList getMTKPDAFList = (RolongogetMTKPDAFList)(QLibrary::resolve(strLibPath, "getMTKPDAFList"));

	if(!(getRolongoOTPAPIVersion && getMTKPDAFList)){
		ui.statuslabel->setText(tr("Resolve HisCCMOTP DLL Function Fail"));
		return;
	}

		QStringList strList;
		std::vector<std::string> strList2;
 		getMTKPDAFList(strList2);

		QStringList strTextList = text.split(".");
		unsigned short usVer3	=	strTextList.at(0).toUShort();
		if(usVer3 == 2){
			for(int x=0;	x<strList2.size();	++x){
				if(strList2.at(x).find("PDAF_MTKV2_") != std::string::npos)
					strList.append(strList2.at(x).c_str());
			}
			strList.sort();
			ui.mtkpdafBurnGetFunListcomboBox->clear();
			ui.mtkpdafBurnGetFunListcomboBox->addItems(strList);
		}
		else if(usVer3 == 3){
			for(int x=0;	x<strList2.size();	++x){
				if(strList2.at(x).find("PDAF_MTKV3_") != std::string::npos)
					strList.append(strList2.at(x).c_str());
			}
			strList.sort();
			ui.mtkpdafBurnGetFunListcomboBox->clear();
			ui.mtkpdafBurnGetFunListcomboBox->addItems(strList);
		}
		else{
			for(int x=0;	x<strList2.size();	++x){
				if(strList2.at(x).find("PDAF_MTK_") != std::string::npos)
					strList.append(strList2.at(x).c_str());
			}
			strList.sort();
			ui.mtkpdafBurnGetFunListcomboBox->clear();
			ui.mtkpdafBurnGetFunListcomboBox->addItems(strList);
		}
	}

	void slotMTFFABinGradeChanged(const QString & text)
	{
#if (defined USE_MANUAL_LENS_BIN)
		if(text ==	"3"){
			ui.mfamtfaFBCenterSpecDlabel->setVisible(false);
			ui.mfamtfaFBCenterSpecDdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBCenterSpecClabel->setVisible(false);
			ui.mfamtfaFBCenterSpecCdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBCenterSpecElabel->setVisible(false);
			ui.mfamtfaFBCenterSpecEdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBtableWidget->hideColumn(8);
			ui.mfamtfaFBtableWidget->hideColumn(9);
			ui.mfamtfaFBtableWidget->hideColumn(10);
		}
		else if(text ==	"4"){
			ui.mfamtfaFBCenterSpecDlabel->setVisible(false);
			ui.mfamtfaFBCenterSpecDdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBCenterSpecClabel->setVisible(true);
			ui.mfamtfaFBCenterSpecCdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBCenterSpecElabel->setVisible(false);
			ui.mfamtfaFBCenterSpecEdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBtableWidget->showColumn(8);
			ui.mfamtfaFBtableWidget->hideColumn(9);
			ui.mfamtfaFBtableWidget->hideColumn(10);
		}
		else if(text == "5"){
			ui.mfamtfaFBCenterSpecDlabel->setVisible(true);
			ui.mfamtfaFBCenterSpecDdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBCenterSpecClabel->setVisible(true);
			ui.mfamtfaFBCenterSpecCdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBCenterSpecElabel->setVisible(false);
			ui.mfamtfaFBCenterSpecEdoubleSpinBox->setVisible(false);
			ui.mfamtfaFBtableWidget->showColumn(8);
			ui.mfamtfaFBtableWidget->showColumn(9);
			ui.mfamtfaFBtableWidget->hideColumn(10);
		}
		else if(text == "6"){
			ui.mfamtfaFBCenterSpecDlabel->setVisible(true);
			ui.mfamtfaFBCenterSpecDdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBCenterSpecClabel->setVisible(true);
			ui.mfamtfaFBCenterSpecCdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBCenterSpecElabel->setVisible(true);
			ui.mfamtfaFBCenterSpecEdoubleSpinBox->setVisible(true);
			ui.mfamtfaFBtableWidget->showColumn(8);
			ui.mfamtfaFBtableWidget->showColumn(9);
			ui.mfamtfaFBtableWidget->showColumn(10);
		}
#endif
	}

	void slotSFRFABinGradeChanged(const QString & text)
	{
#if (defined USE_MANUAL_LENS_BIN)
		if(text ==	"3"){
			ui.mfasfraCenterMTF50GCHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GCHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GCVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GCVdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GDHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GDHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GDVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GDVdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GEHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GEVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEVdoubleSpinBox->setVisible(false);
			ui.mfasfratableWidget->hideColumn(15);
			ui.mfasfratableWidget->hideColumn(16);
			ui.mfasfratableWidget->hideColumn(17);
			ui.mfasfratableWidget->hideColumn(18);
			ui.mfasfratableWidget->hideColumn(19);
			ui.mfasfratableWidget->hideColumn(20);
		}
		else if(text ==	"4"){
			ui.mfasfraCenterMTF50GCHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GCVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCVdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GDHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GDHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GDVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GDVdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GEHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GEVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEVdoubleSpinBox->setVisible(false);
			ui.mfasfratableWidget->showColumn(15);
			ui.mfasfratableWidget->showColumn(16);
			ui.mfasfratableWidget->hideColumn(17);
			ui.mfasfratableWidget->hideColumn(18);
			ui.mfasfratableWidget->hideColumn(19);
			ui.mfasfratableWidget->hideColumn(20);
		}
		else if(text == "5"){
			ui.mfasfraCenterMTF50GCHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GCVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCVdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GDHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GDHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GDVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GDVdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GEHlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEHdoubleSpinBox->setVisible(false);
			ui.mfasfraCenterMTF50GEVlabel->setVisible(false);
			ui.mfasfraCenterMTF50GEVdoubleSpinBox->setVisible(false);
			ui.mfasfratableWidget->showColumn(15);
			ui.mfasfratableWidget->showColumn(16);
			ui.mfasfratableWidget->showColumn(17);
			ui.mfasfratableWidget->showColumn(18);
			ui.mfasfratableWidget->hideColumn(19);
			ui.mfasfratableWidget->hideColumn(20);
		}
		else if(text == "6"){
			ui.mfasfraCenterMTF50GCHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GCVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GCVdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GDHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GDHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GDVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GDVdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GEHlabel->setVisible(true);
			ui.mfasfraCenterMTF50GEHdoubleSpinBox->setVisible(true);
			ui.mfasfraCenterMTF50GEVlabel->setVisible(true);
			ui.mfasfraCenterMTF50GEVdoubleSpinBox->setVisible(true);
			ui.mfasfratableWidget->showColumn(15);
			ui.mfasfratableWidget->showColumn(16);
			ui.mfasfratableWidget->showColumn(17);
			ui.mfasfratableWidget->showColumn(18);
			ui.mfasfratableWidget->showColumn(19);
			ui.mfasfratableWidget->showColumn(20);
		}
#endif
	}

	void removeOSPin(std::vector<std::string>& vecOSPin, QString strName)
	{
		QString strText;
		bool bLoop	=	true;
		while(bLoop)
		{
			bLoop	=	false;
			for(std::vector<std::string>::iterator theitertor = vecOSPin.begin(); theitertor != vecOSPin.end(); theitertor++)
			{
				strText	=	QString::fromStdString(*theitertor);
				if(strText.contains(strName)){
					bLoop	=	true;
					vecOSPin.erase(theitertor);
					break;
				}
			}
		}
	}

	QStringList osPinList2QStringList(std::vector<std::string>& vecOSPin)
	{
		QStringList listName;
		for(std::vector<std::string>::iterator theitertor = vecOSPin.begin(); theitertor != vecOSPin.end(); theitertor++)
		{
			listName.push_back(QString::fromStdString(*theitertor));
		}
		return listName;
	}

 	void textSelected();
	void nextSelected();

private:
	Ui::configsetting ui;
	const bool bBoxChannel1;
	_threadshareData& threadshareData;
	_global_itemexec& itemshareData;
	itemprocess* classItemProcess;

	std::vector<int> selectresult;
	int inextflag;
	QString selectstr;
	unsigned int uiHardwareVersion;
	QVector<QCheckBox*> vectorListosp;
	QVector<QComboBox*> vectorListcmbosp;
	QVector<QCheckBox*> vectorListosn;
	QVector<QCheckBox*> vectorListosc;
	QVector<QCheckBox*> vectorListort;
	QVector<QCheckBox*> vectorListooc;
	void  setCursorPos(int row,int col);
	void createMTFAFCTable(QTableWidget* pstTable);

	void createSFRAAFCTable(QTableWidget* pstTable);
	void createlpAFCTable(QTableWidget* pstTable);

	void createAutoFANodeTable();

	void createOpenShortTable();

	void freshDB_AE();
	void freshDB_FC();

	void SetCHIPIDComoBox();

	int saveCurrentIndex();
	void getCurrentIndex();
};

#endif // CONFIGSETTING_H
