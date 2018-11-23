#include "QHTextItemEdit.h"
#include <QString>
#include <QStringBuilder>
#include <QFileDialog>
#include  <QMessageBox>
#include <QDateTime>
//#include "globaldefine.h"

QHTextItemEdit::QHTextItemEdit(QWidget *parent,QString Qstr	,QString Qinfo, bool bChannel1)
	: QDialog(parent), bBoxChannel1(bChannel1)
{
	Qstrinfo	=	Qinfo;
	Qstritem	=	Qstr;
	ui.setupUi(this);

	if(bBoxChannel1)
	{
		ui.exposurespecdatabasespinBox->setMinimum(1);
		ui.exposurespecdatabasespinBox->setMaximum(20);
	}
	else
	{
		ui.exposurespecdatabasespinBox->setMinimum(21);
		ui.exposurespecdatabasespinBox->setMaximum(40);
	}

// 	QRegExp regx("[a-zA-Z0-9]+$");
// 	QValidator *validator = new QRegExpValidator(regx, ui.paramaterlineEdit );
// 	ui.paramaterlineEdit->setValidator( validator );

	QStringList strname, strvalue;
	iIndex	=	Qstring2ui(Qstr);
	ui.stackedWidget->setCurrentIndex(iIndex);
	patchconfigstring(Qinfo, strname, strvalue);

	for(int x=0;	x<strname.size();	++x)
	{
		if(strname.at(x) == "tactics")	
		{
			if (strvalue.at(x).toInt()	==	255)
			{
				ui.TacticscomboBox->setCurrentIndex(5);
			}
			else
				ui.TacticscomboBox->setCurrentIndex(strvalue.at(x).toInt());
		}
		else if(strname[x] == "notsavelog")						ui.saveTextLogcheckBox->setChecked(strvalue[x] == "false");
		else if(strname[x] == "notshowtotalresult")			ui.showResultcheckBox->setChecked(strvalue[x] == "false");
		else if(strname[x] == "testtype")							ui.debugItemTypecomboBox->setCurrentIndex(strvalue[x].toUInt());
		else if(strname.at(x) == "info")
		{
			ui.messageBoxcomboBox->setCurrentIndex(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "serialport")	
		{
			ui.serialportspinBox->setValue(strvalue.at(x).toInt());

		}
		else if(strname.at(x) == "ebaud")	
		{
			ui.ebaudcomboBox->setCurrentIndex(strvalue.at(x).toInt());
			//switch (strvalue.at(x).toInt())
			//{
			//case 2400:
			//	iIndexebaud=0;
			//	break;
			//case 4800:
			//	iIndexebaud=1;
			//	break;
			//case 9600:
			//	iIndexebaud=2;
			//	break;
			//case 14400:
			//	iIndexebaud=3;
			//	break;
			//case 19200:
			//	iIndexebaud=4;
			//	break;
			//case 38400:
			//	iIndexebaud=5;
			//	break;
			//case 56000:
			//	iIndexebaud=6;
			//	break;
			//case 57600:
			//	iIndexebaud=7;
			//	break;
			//case 115200:
			//	iIndexebaud=8;
			//	break;
			//case 128000:
			//	iIndexebaud=0;
			//	break;
			//case 256000:
			//	iIndexebaud=9;
			//	break;
			//default:
			//	iIndexebaud=0;
			//	break;
			//}
		}
		else if(strname.at(x) == "epar")	
		{
			ui.eparcomboBox->setCurrentIndex(strvalue.at(x).toInt());
			/*if (strvalue.at(x)=="EParOdd")
			{
				ui.eparcomboBox->setCurrentIndex(0);	
			} 
			else if(strvalue.at(x)=="EParEven")
			{
				ui.eparcomboBox->setCurrentIndex(1);	
			}
			else if (strvalue.at(x)	==	"EParNone")
			{
				ui.eparcomboBox->setCurrentIndex(2);	
			}*/
			
		}
		else if(strname.at(x) == "estop")	
		{
			ui.estopcomboBox->setCurrentIndex(strvalue.at(x).toInt());	
			/*if (strvalue.at(x)=="EStop1")
			{
				ui.estopcomboBox->setCurrentIndex(0);	
			} 
			else if(strvalue.at(x)=="EStop1.5")
			{
				ui.estopcomboBox->setCurrentIndex(1);	
			}
			else if (strvalue.at(x)	==	"EStop2")
			{
				ui.estopcomboBox->setCurrentIndex(2);	
			}*/

		}
		else if(strname.at(x) == "strinfo")
		{
			ui.paramaterlineEdit->setText(strvalue.at(x));
		}
		else if (strname.at(x) == "roi")
		{
			if (Qstritem	==	"brightnessitem")
			{
				QStringList listROI	=	strvalue.at(x).split(",");
				if (listROI.size()	==4)
				{
					ui.lightleftspinBox->setValue(listROI.at(0).toInt())	;
					ui.lighttopspinBox->setValue(listROI.at(1).toInt());
					ui.lightrightspinBox->setValue(listROI.at(2).toInt());
					ui.lightbottomspinBox->setValue(listROI.at(3).toInt());
				}

			}
			else if (Qstritem	==	"checkcoloritem")
			{
				QStringList listROI	=	strvalue.at(x).split(",");
				if (listROI.size()	==4)
				{
					ui.whitebalanceleftspinBox->setValue(listROI.at(0).toInt());
					ui.whitebalancetopspinBox->setValue(listROI.at(1).toInt());
					ui.whitebalancerightspinBox->setValue(listROI.at(2).toInt());
					ui.whitebalancebottomspinBox->setValue(listROI.at(3).toInt());
				}

			}
			else if (Qstritem	==	"autoexposureitem")
			{
				QStringList listROI	=	strvalue.at(x).split(",");
				if (listROI.size()	==4)
				{
					ui.exposureleftspinBox->setValue(listROI.at(0).toInt());
					ui.exposuretopspinBox->setValue(listROI.at(1).toInt());
					ui.exposurerightspinBox->setValue(listROI.at(2).toInt());
					ui.exposurebottomspinBox->setValue(listROI.at(3).toInt());
				}

			}
			else if(Qstritem	==	"autorawcapture")
			{
				QStringList listROI	=	strvalue.at(x).split(",");
				if (listROI.size()	==2)
				{
                    ui.autocaptureROIWspinBox->setValue(listROI.at(0).toInt());
					ui.autocaptureROIHspinBox->setValue(listROI.at(1).toInt());
				}				
			}		
		}
		else if (strname.at(x) == "spec")
		{
			if (Qstritem	==	"brightnessitem")
			{
				QStringList listSPEC	=	strvalue.at(x).split(",");
				if (listSPEC.size()	==2)
				{
					ui.specminspinBox->setValue(listSPEC.at(0).toInt())	;
					ui.specmaxspinBox->setValue(listSPEC.at(1).toInt());

				}
			}
			else if (Qstritem	==	"autoexposureitem")
			{
				QStringList listSPEC	=	strvalue.at(x).split(",");
				if (listSPEC.size()	==2)
				{
					ui.exposurespecminspinBox->setValue(listSPEC.at(0).toInt())	;
					ui.exposurespecmaxspinBox->setValue(listSPEC.at(1).toInt());

				}
			}
			else if (Qstritem	==	"awblscgoldenselection")
			{
				QStringList listSPEC	=	strvalue.at(x).split(",");
				if (listSPEC.size()	==2)
				{
					ui.GspecminspinBox->setValue(listSPEC.at(0).toInt())	;
					ui.GspecmaxspinBox->setValue(listSPEC.at(1).toInt());

				}
			}
			
		}
		else if (strname.at(x) == "r/gr")
		{
			QStringList listSPEC	=	strvalue.at(x).split(",");
			if (listSPEC.size()	==2)
			{
				ui.whitebalancermindoubleSpinBox->setValue(listSPEC.at(0).toDouble());
				ui.whitebalancermaxdoubleSpinBox->setValue(listSPEC.at(1).toDouble());

			}
		}
		else if (strname.at(x) == "b/gr")
		{
			QStringList listSPEC	=	strvalue.at(x).split(",");
			if (listSPEC.size()	==2)
			{
				ui.whitebalancebmindoubleSpinBox->setValue(listSPEC.at(0).toDouble());
				ui.whitebalancebmaxdoubleSpinBox->setValue(listSPEC.at(1).toDouble());

			}
		}
		else if (strname.at(x) == "sleep")
		{
			if (Qstritem	==	"saveimageitem")
				ui.saveImageSleepspinBox->setValue(strvalue.at(x).toUShort());
			else
				ui.exposurespecsleepspinBox->setValue(strvalue.at(x).toInt());

		}
		else if (strname.at(x) == "database")
		{
			ui.exposurespecdatabasespinBox->setValue(strvalue.at(x).toInt());

		}
		else if (strname.at(x) == "savefail")
		{
			ui.saveFailcheckBox->setChecked(strvalue.at(x) == "true");

		}
		else if (strname.at(x) == "channel_gr")
		{
			if (strvalue.at(x)=="true")
			{
				ui.exposurespecgrchannelcheckBox->setChecked(true);
			} 
			else
			{
				ui.exposurespecgrchannelcheckBox->setChecked(false);
			}
		}
		else if (strname.at(x) == "white")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.exposurespecwhitecheckBox->setChecked(true);
			}
			else
			{
				ui.exposurespecwhitecheckBox->setChecked(false);
			}		
		}
		else if (strname.at(x) == "value")
		{
			if (Qstritem	==	"setmotoritem")
			{
				ui.motorspinBox->setValue(strvalue.at(x).toInt());
			}
			else if (Qstritem	==	"setexposureitem")
			{
				ui.exposuretimespinBox->setValue(strvalue.at(x).toInt());
			}
			else if (Qstritem	==	"setgainitem")
			{
				ui.gaindoubleSpinBox->setValue(strvalue.at(x).toDouble());
			}
			if (Qstritem	==	"sleepitem")
			{
				ui.sleepspinBox->setValue(strvalue.at(x).toInt());
			}
		}
		else if (strname.at(x) == "otp")
		{
			if (strvalue.at(x)	=="no")
			{
				ui.otpcomboBox->setCurrentIndex(3);
			}
			else if(strvalue.at(x)	=="far")
			{
				ui.otpcomboBox->setCurrentIndex(0);
			}
			else if (strvalue.at(x)	=="middle")
			{
				ui.otpcomboBox->setCurrentIndex(1);
			}
			else if (strvalue.at(x)	=="near")
			{
				ui.otpcomboBox->setCurrentIndex(2);
			}
			
		}
		else if (strname.at(x) == "group")
		{
			ui.groupspinBox->setValue(strvalue.at(x).toInt());
		}
		else if (strname.at(x) == "replace")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.lscreplacecheckBox->setChecked(true);
			}
			else
			{
				ui.lscreplacecheckBox->setChecked(false);
			}
		}
		else if (strname.at(x) == "type")
		{
			ui.lsctypespinBox->setValue(strvalue.at(x).toInt());
		}
		else if (strname.at(x) == "shading")
		{
			ui.lscshadingspinBox->setValue(strvalue.at(x).toInt());
		}
		else if (strname.at(x) == "source")
		{
			if (strvalue.at(x)	=="sensor")
			{
				ui.sourcecomboBox->setCurrentIndex(0);
			} 
			else if (strvalue.at(x)	=="display")
			{
				ui.sourcecomboBox->setCurrentIndex(1);
			}
			else if (strvalue.at(x)	=="program")
			{
				ui.sourcecomboBox->setCurrentIndex(2);
			}
			else if (strvalue.at(x)	=="desktop")
			{
				ui.sourcecomboBox->setCurrentIndex(3);
			}

		}
		else if (strname.at(x) == "format")
		{
			if (strvalue.at(x)	=="raw8")
			{
				ui.formatcomboBox->setCurrentIndex(0);
			}
			else if (strvalue.at(x)	=="raw10")
				ui.formatcomboBox->setCurrentIndex(1);
			else if (strvalue.at(x)	=="png")
			{
				ui.formatcomboBox->setCurrentIndex(2);
			}
			else if (strvalue.at(x)	=="jpeg")
			{
				ui.formatcomboBox->setCurrentIndex(3);
			}
			else if (strvalue.at(x)	=="bmp")
			{
				ui.formatcomboBox->setCurrentIndex(4);
			}

		}
		else if (strname.at(x) == "original")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.originalcheckBox->setChecked(true);
			}
			else
			{
				ui.originalcheckBox->setChecked(false);
			}
		}
		else if (strname.at(x) == "io")
		{
			ui.iospinBox->setValue(strvalue.at(x).toInt());
		}
		else if (strname.at(x) == "out")
		{
			ui.outcomboBox->setCurrentIndex(strvalue.at(x).toInt());
		}
		else if (strname.at(x) == "sleepitem")
		{
			ui.sleepspinBox->setValue(strvalue.at(x).toInt());

		}
		else if(strname.at(x) == "FileName")
		{
			ui.setingpathtextEdit->setText(strvalue.at(x));
			
		}
		else if(strname.at(x) == "Savelog")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.bcalculateRGrGbBcheckBox->setChecked(true);
			}
			else
			{
				ui.bcalculateRGrGbBcheckBox->setChecked(false);
			}
		}
		/*else if(strname.at(x) == "RAWCaptureCount")
		{
			ui.RegisterItemCountlabel->setText(strvalue.at(x));
		}*/
		else if (strname.at(x) == "CaptureRawDelay")
		{
			ui.rawcapturedelaytimespinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "dualcmcenterdistance")
		{
			ui.dualcmcenterdisdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "squarehorizontaldistance")
		{
			ui.squareHdisdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "squareverticaldistance")
		{
			ui.squareVdisdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "dualcmtesdistance")
		{
			ui.testdisdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "maincameracolorsensor")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.maincmcolorcheckBox->setChecked(true);
			}
			else
			{
				ui.maincmcolorcheckBox->setChecked(false);
			}
		}
		else if(strname.at(x) == "dualcameracoaxialityitemspecx")
		{
			ui.specxdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "dualcameracoaxialityitemspecy")
		{
			ui.specydoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "dualcameracoaxialityitemspecpixelx")
		{
			ui.specxpixelspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "dualcameracoaxialityitemspecpixely")
		{
			ui.specypixelspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "subcameracolorsensor")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.subcmcolorcheckBox->setChecked(true);
			}
			else
			{
				ui.subcmcolorcheckBox->setChecked(false);
			}
		}
		else if(strname.at(x) == "dualcameracoaxialitytiltitemspecx")
		{
			ui.tiltspecxdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "dualcameracoaxialitytiltitemspecy")
		{
			ui.tiltspecydoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "FishEyejungeitemspec")
		{
			ui.FishEyespecdoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "modulecount")
		{
			ui.modulecountspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "blacklevel")
		{
			ui.blacklevelspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "awbroidivisor")
		{
			ui.roidivisorspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "imagecenter")
		{
			if (strvalue.at(x)	=="true")
			{
				ui.autoexposureimagecentercheckBox->setChecked(true);
			}
			else
			{
				ui.autoexposureimagecentercheckBox->setChecked(false);
			}
		}
		else if(strname.at(x) == "centerroiratio")
		{
			ui.autoexposurecenterroiratiodoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "tcpcmdid")
		{
			ui.tcpcmdidspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "tcpddata")
		{
			ui.tcpddatadoubleSpinBox->setValue(strvalue.at(x).toDouble());
		}
		else if(strname.at(x) == "tcpresult")
		{
			ui.tcpresultspinBox->setValue(strvalue.at(x).toInt());
		}
		else if(strname.at(x) == "tcptimeout")
		{
			ui.tcptimeoutspinBox->setValue(strvalue.at(x).toInt());
		}
	}

	if(Qstritem	==	"playaudioitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "source")		ui.audioPlaySourcecomboBox->setCurrentIndex(strvalue.at(x).toInt());
			else if(strname.at(x) == "time")			ui.audioPlayTimespinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "samplerate")			ui.audioPlaySampleRatedoubleSpinBox->setValue(strvalue.at(x).toFloat());
		}
	}
	else if(Qstritem	==	"imageprocessitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "blemishenhance")	{
				unsigned char ucData	=	strvalue.at(x).toUInt() & 0xFF;
				ui.dspBlemishEnhanceSetcheckBox->setChecked(ucData & 0x80);
				ui.dspBlemishEnhanceONcheckBox->setChecked(ucData & 0x40);
			}
			else if(strname.at(x) == "awb")	{
				unsigned char ucData	=	strvalue.at(x).toUInt() & 0xFF;
				ui.dspAWBSetcheckBox->setChecked(ucData & 0x80);
				ui.dspAWBONcheckBox->setChecked(ucData & 0x40);
				ui.dspAWBMethodcomboBox->setCurrentIndex(ucData & 0x3F);
			}
			else if(strname.at(x) == "awbrate")		{
				unsigned char ucData	=	strvalue.at(x).toUInt() & 0xFF;
				ui.dspAWBRefreshRatespinBox->setValue(ucData & 0x7F);
				ui.dspAWBSensorGaincheckBox->setChecked(ucData & 0x80);
			}
			else if(strname.at(x) == "gainr")			ui.dspAWBGainRdoubleSpinBox->setValue(strvalue.at(x).toFloat());
			else if(strname.at(x) == "gainb")			ui.dspAWBGainBdoubleSpinBox->setValue(strvalue.at(x).toFloat());
			else if(strname.at(x) == "lsc")	{
				unsigned char ucData	=	strvalue.at(x).toUInt() & 0xFF;
				ui.dspLSCSetcheckBox->setChecked(ucData & 0x80);
				ui.dspLSCONcheckBox->setChecked(ucData & 0x40);
				ui.dspLSCMethodcomboBox->setCurrentIndex(ucData & 0x3F);
			}
			else if(strname.at(x) == "blacklevel")	ui.dspBlackLevelspinBox->setValue(strvalue.at(x).toUInt() & 0xFF);
			else if(strname.at(x) == "mirror")	{
				unsigned char ucData	=	strvalue.at(x).toUInt() & 0xFF;
				ui.dspMirrorSetcheckBox->setChecked(ucData & 0x80);
				ui.dspMirrorONcheckBox->setChecked(ucData & 0x40);
				ui.dspFlipONcheckBox->setChecked(ucData & 0x20);
			}
		}
	}
	else if(Qstritem	==	"iobitoutitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "card")				ui.ioOutCardIndexspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "port")		ui.ioOutPortIndexspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "bit")			ui.ioOutBitIndexspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "out")			ui.ioOutHighcheckBox->setChecked(strvalue.at(x).toUInt());
		}
	}
	else if(Qstritem	==	"camdoracalibrationitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "left")								ui.cdrCalROILeftspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "top")						ui.cdrCalROITopspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "right")					ui.cdrCalROIRightspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "bottom")				ui.cdrCalROIBottomspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "minarea")			ui.cdrCalMinAreaspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "left2")					ui.cdrCalROILeft2spinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "top2")					ui.cdrCalROITop2spinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "right2")					ui.cdrCalROIRight2spinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "bottom2")			ui.cdrCalROIBottom2spinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "ysmax")				ui.cdrCalMaxYShiftspinBox->setValue(strvalue.at(x).toUInt());
		}
	}
	else if(Qstritem	==	"motormoveitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "card")				ui.motorCardIndexspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "axis")		ui.motorAxisIndexspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "dis")			ui.motorDistancedoubleSpinBox->setValue(strvalue.at(x).toDouble());
			else if(strname.at(x) == "abs")		ui.motorAbsMovecheckBox->setChecked(strvalue.at(x).toUInt());
		}
	}
	else if(Qstritem	==	"chartalignlitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "charttype")				ui.charalignChartcomboBox->setCurrentIndex(strvalue.at(x).toUInt());
			else if(strname.at(x) == "angle")				ui.charalignAnglespinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "times")				ui.charalignTimesspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "markmin")		ui.charalignMarkMinspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "markmax")		ui.charalignMarkMaxspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "diff")					ui.charalignPosDiffspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "spec")				ui.charalignSpectspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "fov")					ui.charalignFOVdoubleSpinBox->setValue(strvalue.at(x).toFloat());
			else if(strname.at(x) == "scalex")			ui.charalignScaleXdoubleSpinBox->setValue(strvalue.at(x).toFloat());
			else if(strname.at(x) == "scaley")			ui.charalignScaleYdoubleSpinBox->setValue(strvalue.at(x).toFloat());
			else if(strname.at(x) == "sleep")				ui.charalignSleepspinBox->setValue(strvalue.at(x).toUInt());
		}
	}
	else if(Qstritem	==	"autofocusitem")
	{
		for(int x=0;	x<strname.size();	++x)
		{
			if(strname.at(x) == "alg")							ui.afAlgcomboBox->setCurrentIndex(strvalue.at(x).toUInt());
			else if(strname.at(x) == "chart")				ui.afChartcomboBox->setCurrentIndex(strvalue.at(x).toUInt());
			else if(strname.at(x) == "timeout")			ui.afTimeOutspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "left")					ui.afLeftspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "top")					ui.afTopspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "right")				ui.afRightspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "bottom")			ui.afBottomspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "startpos")		ui.afMotorStartspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "pedestal")		ui.afPedestalspinBox->setValue(strvalue.at(x).toUInt());
			else if(strname.at(x) == "sleep")				ui.afSleepspinBox->setValue(strvalue.at(x).toUInt());
		}
	}

	if (Qstritem	==	"autorawcapture")
	{
        connect(ui.SelectfilepushButton, SIGNAL(released()), this, SLOT(BrowseResgiterFile()));
	}

	connect(ui.pushButtonOK, SIGNAL(released()), this, SLOT(paramaterok()));
	connect(ui.pushButtonCancel, SIGNAL(released()), this, SLOT(clickCancel()));

}

QHTextItemEdit::~QHTextItemEdit()
{

}

void QHTextItemEdit::paramaterok()
{
	//QString QSText	="";
	QString Qsitem	=Qstritem;
	QStringList	 strname, strvalue;
	strname.clear(); 
	strvalue.clear();
	if (Qsitem	==	"mtffc_nearitem" || Qsitem	=="mtffc_middleitem" || Qsitem	=="mtffc_infiniteitem" || Qsitem	=="sfrnearafcitem"|| Qsitem	=="sfrmiddleafcitem" || Qsitem	=="sfrfarafcitem" || Qsitem	=="lpnearafcitem" || Qsitem	=="lpmiddleafcitem" || Qsitem	=="lpfarafcitem")
	{
		strname.append("tactics");				
		if (ui.TacticscomboBox->currentIndex()	==5)
			strvalue.append(QString::number(255));
		else
			strvalue.append(QString::number(ui.TacticscomboBox->currentIndex()));
		jointconfigstring(Qstrinfo,strname,strvalue);
	} 
	else if (Qsitem	==	"brightnessitem")
	{
		QString	str	=	QString::number(ui.lightleftspinBox->value()) % "," % QString::number(ui.lighttopspinBox->value()) % "," % QString::number(ui.lightrightspinBox->value()) % "," % QString::number(ui.lightbottomspinBox->value());
		strname.append("roi");				
		strvalue.append(str);

		str	=	QString::number(ui.specminspinBox->value()) % "," % QString::number(ui.specmaxspinBox->value()) ;
		strname.append("spec");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);

	}
	else if (Qsitem	==	"checkcoloritem")
	{
		QString	str	=	QString::number(ui.whitebalanceleftspinBox->value()) % "," % QString::number(ui.whitebalancetopspinBox->value()) % "," % QString::number(ui.whitebalancerightspinBox->value()) % "," % QString::number(ui.whitebalancebottomspinBox->value());
		strname.append("roi");				
		strvalue.append(str);

		str	=	QString::number(ui.whitebalancermindoubleSpinBox->value()) % "," % QString::number(ui.whitebalancermaxdoubleSpinBox->value()) ;
		strname.append("r/gr");				
		strvalue.append(str);
		str	=	QString::number(ui.whitebalancebmindoubleSpinBox->value()) % "," % QString::number(ui.whitebalancebmaxdoubleSpinBox->value()) ;
		strname.append("b/gr");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem == "autorawcapture")
	{
		QString str	=ui.setingpathtextEdit->text();
		strname.append("FileName");				
		strvalue.append(str);

        str	=	QString::number(ui.autocaptureROIWspinBox->value()) % "," % QString::number(ui.autocaptureROIHspinBox->value());
		strname.append("roi");				
		strvalue.append(str);

		//str=ui.RegisterItemCountlabel->text();
		str.append("100");
		strname.append("RAWCaptureCount");				
		strvalue.append(str);

		str	=	QString::number(ui.rawcapturedelaytimespinBox->value());
		strname.append("CaptureRawDelay");				
		strvalue.append(str);

		strname.append("Savelog");	
		if (ui.bcalculateRGrGbBcheckBox->isChecked()==1){strvalue.append("true");}
		else {strvalue.append("false");}
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"autoexposureitem")
	{
		QString	str	=	QString::number(ui.exposureleftspinBox->value()) % "," % QString::number(ui.exposuretopspinBox->value()) % "," % QString::number(ui.exposurerightspinBox->value()) % "," % QString::number(ui.exposurebottomspinBox->value());
		strname.append("roi");				
		strvalue.append(str);

		str	=	QString::number(ui.exposurespecminspinBox->value()) % "," % QString::number(ui.exposurespecmaxspinBox->value()) ;
		strname.append("spec");				
		strvalue.append(str);

		str	=	QString::number(ui.exposurespecsleepspinBox->value());
		strname.append("sleep");				
		strvalue.append(str);

		str	=	QString::number(ui.exposurespecdatabasespinBox->value());
		strname.append("database");				
		strvalue.append(str);

		strname.append("imagecenter");		
		strvalue.append((ui.autoexposureimagecentercheckBox->isChecked())?("true"):("false"));

		strname.append("centerroiratio");				
		strvalue.append(QString::number(ui.autoexposurecenterroiratiodoubleSpinBox->value()));

		if (ui.exposurespecgrchannelcheckBox->isChecked()	==1)
		{
			strname.append("channel_gr");				
			strvalue.append("true");
		} 
		else
		{
			strname.append("channel_gr");				
			strvalue.append("false");
		}
		if (ui.exposurespecwhitecheckBox->isChecked()	==1)
		{
			strname.append("white");				
			strvalue.append("true");
		} 
		else
		{
			strname.append("white");				
			strvalue.append("false");
		}

		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"autofocusitem")
	{
		strname.append("alg");				strvalue.append(QString::number(ui.afAlgcomboBox->currentIndex()));
		strname.append("chart");			strvalue.append(QString::number(ui.afChartcomboBox->currentIndex()));
		strname.append("timeout");		strvalue.append(ui.afTimeOutspinBox->cleanText());
		strname.append("left");				strvalue.append(ui.afLeftspinBox->cleanText());
		strname.append("top");				strvalue.append(ui.afTopspinBox->cleanText());
		strname.append("right");				strvalue.append(ui.afRightspinBox->cleanText());
		strname.append("bottom");			strvalue.append(ui.afBottomspinBox->cleanText());
		strname.append("startpos");		strvalue.append(ui.afMotorStartspinBox->cleanText());
		strname.append("pedestal");		strvalue.append(ui.afPedestalspinBox->cleanText());
		strname.append("sleep");			strvalue.append(ui.afSleepspinBox->cleanText());
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"playaudioitem")
	{
		strname.append("source");			strvalue.append(QString::number(ui.audioPlaySourcecomboBox->currentIndex()));
		strname.append("time");				strvalue.append(ui.audioPlayTimespinBox->cleanText());
		strname.append("samplerate");				strvalue.append(ui.audioPlaySampleRatedoubleSpinBox->cleanText());
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"iobitoutitem")
	{
		strname.append("card");			strvalue.append(ui.ioOutCardIndexspinBox->cleanText());
		strname.append("port");			strvalue.append(ui.ioOutPortIndexspinBox->cleanText());
		strname.append("bit");			strvalue.append(ui.ioOutBitIndexspinBox->cleanText());
		strname.append("out");			strvalue.append(((ui.ioOutHighcheckBox->isChecked())?("1"):("0")));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"motormoveitem")
	{
		strname.append("card");			strvalue.append(ui.motorCardIndexspinBox->cleanText());
		strname.append("axis");			strvalue.append(ui.motorAxisIndexspinBox->cleanText());
		strname.append("dis");			strvalue.append(ui.motorDistancedoubleSpinBox->cleanText());
		strname.append("abs");			strvalue.append(((ui.motorAbsMovecheckBox->isChecked())?("1"):("0")));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"chartalignlitem")
	{
		strname.append("charttype");			strvalue.append(QString::number(ui.charalignChartcomboBox->currentIndex()));
		strname.append("angle");			strvalue.append(ui.charalignAnglespinBox->cleanText());
		strname.append("times");			strvalue.append(ui.charalignTimesspinBox->cleanText());
		strname.append("markmin");			strvalue.append(ui.charalignMarkMinspinBox->cleanText());
		strname.append("markmax");			strvalue.append(ui.charalignMarkMaxspinBox->cleanText());
		strname.append("diff");			strvalue.append(ui.charalignPosDiffspinBox->cleanText());
		strname.append("spec");			strvalue.append(ui.charalignSpectspinBox->cleanText());
		strname.append("fov");			strvalue.append(ui.charalignFOVdoubleSpinBox->cleanText());
		strname.append("scalex");		strvalue.append(ui.charalignScaleXdoubleSpinBox->cleanText());
		strname.append("scaley");		strvalue.append(ui.charalignScaleYdoubleSpinBox->cleanText());
		strname.append("sleep");		strvalue.append(ui.charalignSleepspinBox->cleanText());
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"imageprocessitem")
	{
		unsigned char ucBlemish = 0, ucLSC = 0, ucAWB = 0, ucMirror = 0;
		if(ui.dspBlemishEnhanceSetcheckBox->isChecked())	ucBlemish |= 0x80;
		if(ui.dspBlemishEnhanceONcheckBox->isChecked())	ucBlemish |= 0x40;

		if(ui.dspLSCSetcheckBox->isChecked())	ucLSC |= 0x80;
		if(ui.dspLSCONcheckBox->isChecked())	ucLSC |= 0x40;
		ucLSC	|=	ui.dspLSCMethodcomboBox->currentIndex();

		if(ui.dspAWBSetcheckBox->isChecked())	ucAWB |= 0x80;
		if(ui.dspAWBONcheckBox->isChecked())	ucAWB |= 0x40;
		ucAWB	|=	ui.dspAWBMethodcomboBox->currentIndex();

		if(ui.dspMirrorSetcheckBox->isChecked())	ucMirror |= 0x80;
		if(ui.dspMirrorONcheckBox->isChecked())	ucMirror |= 0x40;
		if(ui.dspFlipONcheckBox->isChecked())		ucMirror |= 0x20;

		unsigned char ucawbrate	=	ui.dspAWBRefreshRatespinBox->value();
		if(ui.dspAWBSensorGaincheckBox->isChecked()) ucawbrate |= 0x80;

		strname.append("blemishenhance");			strvalue.append(QString::number(ucBlemish));
		strname.append("lsc");								strvalue.append(QString::number(ucLSC));
		strname.append("awb");								strvalue.append(QString::number(ucAWB));
		strname.append("awbrate");						strvalue.append(QString::number(ucawbrate));
		strname.append("gainr");							strvalue.append(ui.dspAWBGainRdoubleSpinBox->cleanText());
		strname.append("gainb");							strvalue.append(ui.dspAWBGainBdoubleSpinBox->cleanText());
		strname.append("blacklevel");					strvalue.append(ui.dspBlackLevelspinBox->cleanText());
		strname.append("mirror");							strvalue.append(QString::number(ucMirror));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"setexposureitem")
	{
		QString	str	=	QString::number(ui.exposuretimespinBox->value());
		strname.append("value");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"setgainitem")
	{
		QString	str	=	QString::number(ui.gaindoubleSpinBox->value(),'f',3);
		strname.append("value");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"setmotoritem")
	{
		QString	str	=	QString::number(ui.motorspinBox->value());
		strname.append("value");				
		strvalue.append(str);
		if (ui.otpcomboBox->currentIndex()	==3)
		{
			strname.append("otp");				
			strvalue.append("no");
		} 
		else if (ui.otpcomboBox->currentIndex()	==0)
		{
			strname.append("otp");				
			strvalue.append("far");
		}
		else if (ui.otpcomboBox->currentIndex()	==1)
		{
			strname.append("otp");				
			strvalue.append("middle");
		}
		else if (ui.otpcomboBox->currentIndex()	==2)
		{
			strname.append("otp");				
			strvalue.append("near");
		}
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"setcustomiicitem")
	{
		QString	str	=	QString::number(ui.groupspinBox->value());
		strname.append("group");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"lsctemplateitem")
	{
		QString	str;
		if (ui.lscreplacecheckBox->isChecked())
		{
			strname.append("replace");				
			strvalue.append("true");
		} 
		else
		{
			strname.append("replace");				
			strvalue.append("false");
		}
		str	=	QString::number(ui.lsctypespinBox->value());
		strname.append("type");				
		strvalue.append(str);

		str	=	QString::number(ui.lscshadingspinBox->value()) ;
		strname.append("shading");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"saveimageitem")
	{
		QString	str	=	QString::number(ui.gaindoubleSpinBox->value(),'f',3);
		if (ui.sourcecomboBox->currentIndex()==0)
		{
			strname.append("source");				
			strvalue.append("sensor");
		} 
		else if(ui.sourcecomboBox->currentIndex()==1)
		{
			strname.append("source");				
			strvalue.append("display");
		}
		else if(ui.sourcecomboBox->currentIndex()==2)
		{
			strname.append("source");				
			strvalue.append("program");
		}
		else if (ui.sourcecomboBox->currentIndex()==3)
		{
			strname.append("source");				
			strvalue.append("desktop");
		}

		if (ui.formatcomboBox->currentIndex()==0)
		{
			strname.append("format");				
			strvalue.append("raw8");
		} 
		else if (ui.formatcomboBox->currentIndex()==1)
		{
			strname.append("format");				
			strvalue.append("raw10");
		} 
		else if(ui.formatcomboBox->currentIndex()==2)
		{
			strname.append("format");				
			strvalue.append("png");
		}
		else if(ui.formatcomboBox->currentIndex()==3)
		{
			strname.append("format");				
			strvalue.append("jpeg");
		}
		else if (ui.formatcomboBox->currentIndex()==4)
		{
			strname.append("format");				
			strvalue.append("bmp");
		}
		if (ui.originalcheckBox->isChecked())
		{
			strname.append("original");				
			strvalue.append("true");
		} 
		else 
		{
			strname.append("original");				
			strvalue.append("false");
		}

		strname.append("savefail");
		strvalue.append((ui.saveFailcheckBox->isChecked())?("true"):("false"));

		strname.append("sleep"); strvalue.append(ui.saveImageSleepspinBox->cleanText());
		jointconfigstring(Qstrinfo,strname,strvalue);

	}
	else if (Qsitem	==	"pdafgbmtkiocontrolitem")
	{
		QString	str	=	QString::number(ui.iospinBox->value());
		strname.append("io");				
		strvalue.append(str);
		str	=	QString::number(ui.outcomboBox->currentIndex());
		strname.append("out");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);	
	}
	else if (Qsitem	==	"sleepitem")
	{
		QString	str	=	QString::number(ui.sleepspinBox->value());
		strname.append("value");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"messageboxitem")
	{
		QString	str	=	QString::number(ui.messageBoxcomboBox->currentIndex());
		strname.append("info");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"serialportitem")
	{
		strname.append("serialport");				
		strvalue.append(ui.serialportspinBox->cleanText());
		strname.append("ebaud");
		strvalue.append(QString::number(ui.ebaudcomboBox->currentIndex()));
		strname.append("epar");
		strvalue.append(QString::number(ui.eparcomboBox->currentIndex()));
		strname.append("estop");
		strvalue.append(QString::number(ui.estopcomboBox->currentIndex()));
		strname.append("strinfo");				
		strvalue.append(ui.paramaterlineEdit->text());
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if (Qsitem	==	"camdoracalibrationitem")
	{
		strname.append("left");				strvalue.append(ui.cdrCalROILeftspinBox->cleanText());
		strname.append("top");				strvalue.append(ui.cdrCalROITopspinBox->cleanText());
		strname.append("right");				strvalue.append(ui.cdrCalROIRightspinBox->cleanText());
		strname.append("bottom");			strvalue.append(ui.cdrCalROIBottomspinBox->cleanText());
		strname.append("minarea");		strvalue.append(ui.cdrCalMinAreaspinBox->cleanText());
		strname.append("left2");				strvalue.append(ui.cdrCalROILeft2spinBox->cleanText());
		strname.append("top2");				strvalue.append(ui.cdrCalROITop2spinBox->cleanText());
		strname.append("right2");			strvalue.append(ui.cdrCalROIRight2spinBox->cleanText());
		strname.append("bottom2");		strvalue.append(ui.cdrCalROIBottom2spinBox->cleanText());
		strname.append("ysmax");			strvalue.append(ui.cdrCalMaxYShiftspinBox->cleanText());
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	=="dualcameracoaxialityitem")
	{
		QString str	=	QString::number(ui.dualcmcenterdisdoubleSpinBox->value(),'f',3);
		strname.append("dualcmcenterdistance");				
		strvalue.append(str);

		str	=	QString::number(ui.squareHdisdoubleSpinBox->value(),'f',3);
		strname.append("squarehorizontaldistance");				
		strvalue.append(str);

		str	=	QString::number(ui.squareVdisdoubleSpinBox->value(),'f',3);
		strname.append("squareverticaldistance");				
		strvalue.append(str);

		str	=	QString::number(ui.testdisdoubleSpinBox->value(),'f',3);
		strname.append("dualcmtesdistance");				
		strvalue.append(str);

		str	=	QString::number(ui.specxdoubleSpinBox->value(),'f',3);
		strname.append("dualcameracoaxialityitemspecx");				
		strvalue.append(str);

		str	=	QString::number(ui.specydoubleSpinBox->value(),'f',3);
		strname.append("dualcameracoaxialityitemspecy");				
		strvalue.append(str);

		str	=	QString::number(ui.specxpixelspinBox->value());
		strname.append("dualcameracoaxialityitemspecpixelx");				
		strvalue.append(str);

		str	=	QString::number(ui.specypixelspinBox->value());
		strname.append("dualcameracoaxialityitemspecpixely");				
		strvalue.append(str);



		strname.append("maincameracolorsensor");	
		if (ui.maincmcolorcheckBox->isChecked()==1){strvalue.append("true");}
		else {strvalue.append("false");}

		strname.append("subcameracolorsensor");	
		if (ui.subcmcolorcheckBox->isChecked()==1){strvalue.append("true");}
		else {strvalue.append("false");}
		jointconfigstring(Qstrinfo,strname,strvalue);
	}

	else if(Qsitem	=="dualcameracoaxialitytiltitem")
	{
		QString str	=	QString::number(ui.tiltspecxdoubleSpinBox->value(),'f',3);
		strname.append("dualcameracoaxialitytiltitemspecx");				
		strvalue.append(str);

		str	=	QString::number(ui.tiltspecydoubleSpinBox->value(),'f',3);
		strname.append("dualcameracoaxialitytiltitemspecy");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	=="FishEyejungeitem")
	{
		QString str	=	QString::number(ui.FishEyespecdoubleSpinBox->value(),'f',3);
		strname.append("FishEyejungeitemspec");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	==	"awblscgoldenselection")
	{
		QString str	=	QString::number(ui.modulecountspinBox->value());
		strname.append("modulecount");				
		strvalue.append(str);
		str	=	QString::number(ui.blacklevelspinBox->value());
		strname.append("blacklevel");				
		strvalue.append(str);
		str	=	QString::number(ui.roidivisorspinBox->value());
		strname.append("awbroidivisor");				
		strvalue.append(str);
		str	=	QString::number(ui.GspecminspinBox->value()) % "," % QString::number(ui.GspecmaxspinBox->value()) ;
		strname.append("spec");				
		strvalue.append(str);
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	==	"showresultitem")
	{
		strname.append("notsavelog");					strvalue.append(((ui.saveTextLogcheckBox->isChecked())?("false"):("true")));
		strname.append("notshowtotalresult");		strvalue.append(((ui.showResultcheckBox->isChecked())?("false"):("true")));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	==	"debugitem")
	{
		strname.append("testtype");					strvalue.append(QString::number(ui.debugItemTypecomboBox->currentIndex()));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}
	else if(Qsitem	==	"tcpsocketsimulateitem")
	{
		strname.append("tcpcmdid");					strvalue.append(QString::number(ui.tcpcmdidspinBox->value()));
		strname.append("tcpddata");					strvalue.append(QString::number(ui.tcpddatadoubleSpinBox->value()));
		strname.append("tcpresult");					strvalue.append(QString::number(ui.tcpresultspinBox->value()));
		strname.append("tcptimeout");					strvalue.append(QString::number(ui.tcptimeoutspinBox->value()));
		jointconfigstring(Qstrinfo,strname,strvalue);
	}

	strNewAddInfo	=	Qstrinfo;
	this->done(QDialog::Accepted);

}

int QHTextItemEdit::Qstring2ui(QString qStr)
{
	int iIndex	=0;
	if (qStr	==	"mtffc_nearitem" || qStr	=="mtffc_middleitem" || qStr	=="mtffc_infiniteitem" || qStr	=="sfrnearafcitem"|| qStr	=="sfrmiddleafcitem" || qStr	=="sfrfarafcitem" || qStr	=="lpnearafcitem" || qStr	=="lpmiddleafcitem" || qStr	=="lpfarafcitem")
	{
		iIndex	=0;
	} 
	else if (qStr	==	"brightnessitem")
	{
		iIndex	=1;
	}
	else if (qStr	==	"checkcoloritem")
	{
		iIndex	=2;
	}
	else if (qStr	==	"autoexposureitem")
	{
		iIndex	=3;
	}
	else if (qStr	==	"setexposureitem")
	{
		iIndex	=4;
	}
	else if (qStr	==	"setgainitem")
	{
		iIndex	=5;
	}
	else if (qStr	==	"setmotoritem")
	{
		iIndex	=6;
	}
	else if (qStr	==	"setcustomiicitem")
	{
		iIndex	=7;
	}
	else if (qStr	==	"lsctemplateitem")
	{
		iIndex=8;
	}
	else if (qStr	==	"saveimageitem")
	{
		iIndex	=9;
	}
	else if (qStr	==	"pdafgbmtkiocontrolitem")
	{
		iIndex	=10;
	}
	else if (qStr	==	"sleepitem")
	{
		iIndex	=11;
	}
	else if (qStr	==	"serialportitem")
	{
		iIndex	=12;
	}
	else if(qStr == "autorawcapture")
	{
		iIndex =13;
	}
	else if(qStr == "messageboxitem")
	{
		iIndex =14;
	}
		else if(qStr=="dualcameracoaxialityitem")
	{
		iIndex=15;
	}
	else if(qStr=="dualcameracoaxialitytiltitem")
	{
		iIndex=16;
	}
	else if(qStr=="FishEyejungeitem")
	{
		iIndex=17;
	}
	else if(qStr == "awblscgoldenselection")
	{
		iIndex =18;
	}
	else if(qStr == "showresultitem")								iIndex = 19;
	else if(qStr == "debugitem")										iIndex = 20;
	else if(qStr == "playaudioitem")									iIndex = 21;
	else if(qStr == "imageprocessitem")							iIndex = 22;
	else if(qStr == "iobitoutitem")										iIndex = 23;
	else if(qStr == "motormoveitem")								iIndex = 24;
	else if(qStr == "chartalignlitem")									iIndex = 25;
	else if(qStr == "autofocusitem")									iIndex = 26;
	else if(qStr == "tcpsocketsimulateitem")									iIndex = 27;
	else if(qStr == "camdoracalibrationitem")									iIndex = 30;
	return iIndex;
}

void QHTextItemEdit::patchconfigstring(QString strsrc, QStringList& strname, QStringList& strvalue)
{
	strname.clear();
	strvalue.clear();
// 	strsrc	=	strsrc.toLower();
	strsrc	=	strsrc.trimmed();
	strsrc	=	strsrc.remove(" ");
	if(strsrc.isEmpty() || !strsrc.contains("(") || !strsrc.contains(")") || !strsrc.contains(":"))
		return;
	QString strkey, strdata;
	int iindex	=	strsrc.indexOf(")");
	while(iindex > 0){
		strdata		=	strsrc.left(iindex);
		strsrc		=	strsrc.right(strsrc.size() -iindex -1);
		strdata		=	strdata.remove("(");
		if(strdata.count(":") == 1){
			iindex	=	strdata.indexOf(":");
			strkey	=	strdata.left(iindex);
			strdata	=	strdata.right(strdata.size() -iindex -1);
			if(!strkey.isEmpty() && !strdata.isEmpty()){
				strname.append(strkey);
				strvalue.append(strdata);
			}
		}
		iindex	=	strsrc.indexOf(")");
	}
}

void QHTextItemEdit::jointconfigstring(QString& strsrc, QStringList& strname, QStringList& strvalue)
{
	strsrc.clear();
	for(int x=0;	x<strname.size(); ++x){
		strsrc	=	strsrc % "(" % strname.at(x) % ":" % strvalue.at(x) % ")";
	}
}


void QHTextItemEdit::BrowseResgiterFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/Register", "Register (*.sset)");
	bool bIs	=	(fileName.size() < 5)?(false):(true);
	if(bIs){
		int iIndex	=	fileName.lastIndexOf("/");
		QString strNewFileName = fileName.right(fileName.size()-iIndex-1);
		ui.setingpathtextEdit->setText(strNewFileName);
	    QString strNewPath = QCoreApplication::applicationDirPath();
		strNewPath.append("/Register.sset");
		if(fileName.compare(strNewPath)!=0)
		{
			if(QFile::exists(strNewPath))
			{
		       QString StrOrgFile=strNewPath;
			   StrOrgFile.append("backup_"%(QDateTime::currentDateTime()).toString("yyyyMMdd_hhmmss")%".sset");
			   if(!QFile::copy(strNewPath, StrOrgFile))  
			   {  
				   QMessageBox::warning(this, "ERROR", "Rename file failed which exist in root dir");
			   }
			   else {if(!QFile::remove(strNewPath)) {QMessageBox::warning(this, "ERROR", "remove register.sset file failed");}}
			   
			}
			if(!QFile::copy(fileName, strNewPath))  
			{  
				QMessageBox::warning(this, "ERROR", "Copy File failed");
			}
		}




	}
}
