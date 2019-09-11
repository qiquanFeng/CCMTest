#include "updatefirewaredialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStringBuilder>

updatefirewaredialog::updatefirewaredialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.browsepushButton, SIGNAL(released()), this, SLOT(chooseBinFile()));
	connect(ui.updatepushButton, SIGNAL(released()), this, SLOT(updateFW()));
	connect(ui.cancelpushButton, SIGNAL(released()), this, SLOT(cancelUpdate()));
}

updatefirewaredialog::~updatefirewaredialog()
{

}

void updatefirewaredialog::chooseBinFile()
{
	QString strBinPath = QFileDialog::getOpenFileName(this, tr("Choose Bin File"), "/home", "Bin (*.bin)");
	if(!strBinPath.isEmpty()) ui.binPathlineEdit->setText(strBinPath);
}

void updatefirewaredialog::updateFW()
{
	QString strBinPath	=	ui.binPathlineEdit->text();
	strBinPath.trimmed();
	if(strBinPath.isEmpty() || !strBinPath.contains(".bin") || !strBinPath.contains(":")){
		QMessageBox::critical(this, tr("Error"), tr("Please Choose the Right File First."));
		return;
	}

	wchar_t strPath[260];
	strBinPath.toWCharArray(strPath);
	strPath[strBinPath.size()]	=	L'\0';

	int iresult	=	classPlatform.HisFX3UpdateFPGA(strBinPath.toLatin1().data());
	if(iresult){
		QMessageBox::critical(this, tr("Error"), tr("update FPGA FW Fail. please check if the bin file is correct. \n Error Code: 0x") % QString::number(iresult, 16));
		return;
	}

	QMessageBox::information(this, tr("Update FPGA FW"), tr("Update FPGA FW Success.\n Please reboot the grabber."));

	emit deleteLater();
}

void updatefirewaredialog::cancelUpdate()
{
	emit deleteLater();
}