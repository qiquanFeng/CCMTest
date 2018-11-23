#include "savedebuginfo.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QDateTime>
savedebuginfo::savedebuginfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.dirButton,	SIGNAL(clicked(bool)), this, SLOT(finddir(bool)));
	connect(ui.saveButton,	SIGNAL(clicked(bool)), this, SLOT(savebutton(bool)));
	connect(ui.cancelButton, SIGNAL(released()), this, SLOT(close()));
}

savedebuginfo::~savedebuginfo()
{

}
void savedebuginfo::finddir(bool bchecked)
{
	qPath	=	QFileDialog::getSaveFileName(this, tr("Open Directory"),"./home.txt"/*ui.filedir->text()*/);
	//qPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),ui.filedir->text(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if(!qPath.isEmpty())
		ui.filedir->setText(qPath);
	else
	{
		QMessageBox::warning(this, "ERROR", "File name is empty");
		return;
	}
}

void savedebuginfo::savebutton(bool bchecked)
{
	this->done(QDialog::Accepted);
}