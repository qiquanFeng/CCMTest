#include "QHFontSetting.h"

extern _globalParameter hisglobalparameter;

QHFontSetting::QHFontSetting(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.savepushButton, SIGNAL(released()), this, SLOT(save()));
	ui.fiMTFSizespinBox->setValue(hisglobalparameter.stForivate.ucImageMTFFontSize);
	ui.fiMTFBoldcheckBox->setChecked(hisglobalparameter.stForivate.bImageMTFFontBold);
	ui.fiSFRSizespinBox->setValue(hisglobalparameter.stForivate.ucImageSFRFontSize);
	ui.fiSFRBoldcheckBox->setChecked(hisglobalparameter.stForivate.bImageSFRFontBold);
	ui.fiTVLineSizespinBox->setValue(hisglobalparameter.stForivate.ucImageTVLineFontSize);
	ui.fiTVLineBoldcheckBox->setChecked(hisglobalparameter.stForivate.bImageTVLineFontBold);
	ui.fiOtherSizespinBox->setValue(hisglobalparameter.stForivate.ucImageOtherFontSize);
	ui.fiOtherBoldcheckBox->setChecked(hisglobalparameter.stForivate.bImageOtherFontBold);
}

QHFontSetting::~QHFontSetting()
{

}

void QHFontSetting::save()
{
	hisglobalparameter.stForivate.ucImageMTFFontSize		=	ui.fiMTFSizespinBox->value();
	hisglobalparameter.stForivate.bImageMTFFontBold			=	ui.fiMTFBoldcheckBox->isChecked();
	hisglobalparameter.stForivate.ucImageSFRFontSize		=	ui.fiSFRSizespinBox->value();
	hisglobalparameter.stForivate.bImageSFRFontBold			=	ui.fiSFRBoldcheckBox->isChecked();
	hisglobalparameter.stForivate.ucImageTVLineFontSize	=	ui.fiTVLineSizespinBox->value();
	hisglobalparameter.stForivate.bImageTVLineFontBold		=	ui.fiTVLineBoldcheckBox->isChecked();
	hisglobalparameter.stForivate.ucImageOtherFontSize		=	ui.fiOtherSizespinBox->value();
	hisglobalparameter.stForivate.bImageOtherFontBold		=	ui.fiOtherBoldcheckBox->isChecked();

	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			//(mtfsize:0)(mtfbold:1)(sfrsize:0)(sfrbold:1)
			//(tvlinesize:0)(tvlinebold:1)(othersize:0)(otherbold:1)
			HISDBTEMPLATE::deleteItem(stSqlDB, "fontonimage", _HISINLINEDB_FLAG_classfy);
			QString item,itemsuffix1;
			QStringList strname, strvalue;
			strname.append("mtfsize");		strvalue.append(ui.fiMTFSizespinBox->cleanText());
			strname.append("mtfbold");		strvalue.append((ui.fiMTFBoldcheckBox->isChecked())?("1"):("0"));
			strname.append("sfrsize");		strvalue.append(ui.fiSFRSizespinBox->cleanText());
			strname.append("sfrbold");		strvalue.append((ui.fiSFRBoldcheckBox->isChecked())?("1"):("0"));
			ROPLOW::jointconfigstring(item, strname, strvalue);

			strname.clear();	strvalue.clear();
			strname.append("tvlinesize");		strvalue.append(ui.fiTVLineSizespinBox->cleanText());
			strname.append("tvlinebold");		strvalue.append((ui.fiTVLineBoldcheckBox->isChecked())?("1"):("0"));
			strname.append("othersize");		strvalue.append(ui.fiOtherSizespinBox->cleanText());
			strname.append("otherbold");		strvalue.append((ui.fiOtherBoldcheckBox->isChecked())?("1"):("0"));
			ROPLOW::jointconfigstring(itemsuffix1, strname, strvalue);
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 0, "fontonimage", item,itemsuffix1);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}

	this->done(QDialog::Accepted);
}

