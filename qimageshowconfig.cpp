#include "qimageshowconfig.h"

qimageshowconfig::qimageshowconfig(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.savepushButton, SIGNAL(released()), this, SLOT(saveglobalParameter()));
	
	ui.aspectRatiocomboBox->setCurrentIndex(hisglobalparameter.ucAspectRatio);
	ui.scaleModecomboBox->setCurrentIndex(hisglobalparameter.ucScaleMode);
	ui.sodokuModecomboBox->setCurrentIndex(hisglobalparameter.ucSodokuMode);
	ui.crosscheckBox->setChecked(hisglobalparameter.bPaintCross);
	ui.squarecheckBox->setChecked(hisglobalparameter.bPaintSquare);
	ui.squareratioxspinBox->setValue(hisglobalparameter.iSquaresizex);
	ui.squareratioyspinBox->setValue(hisglobalparameter.iSquaresizey);
}

qimageshowconfig::~qimageshowconfig()
{

}

void qimageshowconfig::saveglobalParameter()
{
	//(aspectratio:0)(scalemode:0)(sodokumode:0)(cross:0)
	hisglobalparameter.ucAspectRatio		=	ui.aspectRatiocomboBox->currentIndex();
	hisglobalparameter.ucScaleMode		=	ui.scaleModecomboBox->currentIndex();
	hisglobalparameter.ucSodokuMode	=	ui.sodokuModecomboBox->currentIndex();
	hisglobalparameter.bPaintCross		=	ui.crosscheckBox->isChecked();
	hisglobalparameter.bPaintSquare		=	ui.squarecheckBox->isChecked();
	hisglobalparameter.iSquaresizex		=	ui.squareratioxspinBox->value();
	hisglobalparameter.iSquaresizey		=	ui.squareratioyspinBox->value();
	QString itemsuffix2;
	QStringList strname, strvalue;
	strname.append("aspectratio");
	strvalue.append(QString::number(hisglobalparameter.ucAspectRatio));
	strname.append("scalemode");
	strvalue.append(QString::number(hisglobalparameter.ucScaleMode));
	strname.append("sodokumode");
	strvalue.append(QString::number(hisglobalparameter.ucSodokuMode));
	strname.append("cross");
	strvalue.append((hisglobalparameter.bPaintCross)?("1"):("0"));
	strname.append("square");
	strvalue.append((hisglobalparameter.bPaintSquare)?("1"):("0"));
	strname.append("squresizex");
	strvalue.append(QString::number(hisglobalparameter.iSquaresizex));
	strname.append("squresizey");
	strvalue.append(QString::number(hisglobalparameter.iSquaresizey));
	ROPLOW::jointconfigstring(itemsuffix2, strname, strvalue);

	QMutexLocker locker(&hisglobalparameter.mutexDatabase);
	bool bDB;
	{
		QSqlDatabase stSqlDB;
		bDB	=	HISDBTEMPLATE::addDB(stSqlDB);
		if(bDB){
			HISDBTEMPLATE::deleteItem(stSqlDB, "global", _HISINLINEDB_FLAG_classfy|_HISINLINEDB_FLAG_item|_HISINLINEDB_FLAG_itemsuffix1, "global", "imageshow", "config");
			HISDBTEMPLATE::insertItem(stSqlDB, "global", 0, "global", "imageshow", "config", itemsuffix2);
			stSqlDB.close();
		}
	}
	if(bDB)
	{
		HISDBTEMPLATE::removeDB();
	}
}

