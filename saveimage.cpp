#include "saveimage.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QDateTime>

saveimage::saveimage(QWidget *parent, QString strdir)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.filedir->setText(strdir);
	ui.originalradio->setChecked(true);
	ui.lableradio->setChecked(false);
	ui.appradio->setChecked(false);
	ui.comboBox->clear();
	ui.comboBox->addItem(tr("save 8 bits raw"));
	ui.comboBox->addItem(tr("save 10 bits raw"));
	ui.comboBox->addItem(tr("save 12 bits raw"));
	ui.comboBox->addItem(tr("save bmp"));
	ui.comboBox->addItem(tr("save jpeg"));
	ui.comboBox->addItem(tr("save png"));
	ui.comboBox->setCurrentIndex(0);

	ui.filename->setText((QDateTime::currentDateTime()).toString("yyyy-MM-dd hh.mm.ss"));
	connect(ui.appradio, SIGNAL(clicked(bool)),	this,	SLOT(radiochange(bool)));
	connect(ui.lableradio, SIGNAL(clicked(bool)),	this,	SLOT(radiochange(bool)));
	connect(ui.originalradio, SIGNAL(clicked(bool)),	this,	SLOT(radiochange(bool)));
	connect(ui.dirButton,	SIGNAL(clicked(bool)), this, SLOT(finddir(bool)));
	connect(ui.saveButton,	SIGNAL(clicked(bool)), this, SLOT(savebutton(bool)));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));
}

saveimage::~saveimage()
{

}

void saveimage::radiochange(bool bckecked)
{
	int icount	=	ui.comboBox->count();
	int iindex	=	ui.comboBox->currentIndex();
	if(ui.originalradio->isChecked()){
		if(icount == 3){
			ui.comboBox->clear();
			ui.comboBox->addItem(tr("save 8 bits raw"));
			ui.comboBox->addItem(tr("save 10 bits raw"));
			ui.comboBox->addItem(tr("save 12 bits raw"));
			ui.comboBox->addItem(tr("save bmp"));
			ui.comboBox->addItem(tr("save jpeg"));
			ui.comboBox->addItem(tr("save png"));
			ui.comboBox->setCurrentIndex(iindex+2);
		}
	}
	else{
		if(icount == 5){
			ui.comboBox->clear();
			ui.comboBox->addItem(tr("save bmp"));
			ui.comboBox->addItem(tr("save jpeg"));
			ui.comboBox->addItem(tr("save png"));
			iindex	-=		2;
			iindex	=	(iindex < 0)?(0):(iindex);
			ui.comboBox->setCurrentIndex(iindex);
		}
	}
}

void saveimage::finddir(bool bchecked)
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),ui.filedir->text(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if(!dir.isEmpty())
		ui.filedir->setText(dir);
}

void saveimage::savebutton(bool bchecked)
{
	if(!((ui.filedir->text()).isEmpty()) && !((ui.filedir->text()).isEmpty())){
		unsigned char ucsrc;
		if(ui.lableradio->isChecked())
			ucsrc	=	_His_CCM_SaveImage_Src_ImageArea;
		else if(ui.appradio->isChecked())
			ucsrc	=	_His_CCM_SaveImage_Src_AppArea;
		else if(ui.desktopradio->isChecked())
			ucsrc	=	_His_CCM_SaveImage_Src_ScreenArea;
		else
			ucsrc	=	_His_CCM_SaveImage_Src_ImageBuffer;
		int iindex;
		int icount	=	ui.comboBox->count();
		if(icount == 3){
			switch (ui.comboBox->currentIndex()){
			case 0:
				iindex	=	_His_CCM_SaveImage_Type_BMP;
				break;
			case 1:
				iindex	=	_His_CCM_SaveImage_Type_JPEG;
				break;
			case 2:
			default:
				iindex	=	_His_CCM_SaveImage_Type_PNG;
				break;
			}
		}
		else{
			switch (ui.comboBox->currentIndex()){
			case 0:
				iindex	=	_His_CCM_SaveImage_Type_Raw8;
				break;
			case 1:
				iindex	=	_His_CCM_SaveImage_Type_Raw10;
				break;
			case 2:
				iindex	=	_His_CCM_SaveImage_Type_Raw12;
				break;
			case 3:
				iindex	=	_His_CCM_SaveImage_Type_BMP;
				break;
			case 4:
				iindex	=	_His_CCM_SaveImage_Type_JPEG;
				break;
			case 5:
			default:
				iindex	=	_His_CCM_SaveImage_Type_PNG;
				break;
			}
		}

		emit execsave(ui.filedir->text(), ui.filename->text(), iindex, ucsrc);
	}
	this->deleteLater();
}
