#include "QHChooseGrabberType.h"

QHChooseGrabberType::QHChooseGrabberType(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	platformType	=	_HisFX3_Platform_Type_UnKnowed;

	connect(ui.okpushButton, SIGNAL(released()), this, SLOT(slotOK()));
	connect(ui.cancelpushButton, SIGNAL(released()), this, SLOT(slotCancel()));
}

QHChooseGrabberType::~QHChooseGrabberType()
{

}

void QHChooseGrabberType::slotOK()
{
	if(ui.typecomboBox->currentText() == "R2R3") platformType	=	_HisFX3_Platform_Type_R2R3;
	else if(ui.typecomboBox->currentText() == "R5") platformType	=	_HisFX3_Platform_Type_R5;
	else if(ui.typecomboBox->currentText() == "R5X") platformType	=	_HisFX3_Platform_Type_R5X;
	else if(ui.typecomboBox->currentText() == "R3X") platformType	=	_HisFX3_Platform_Type_R3X;
	else if(ui.typecomboBox->currentText() == "R6(C-PHY)") platformType	=	_HisFX3_Platform_Type_R6;

	this->done(QDialog::Accepted);
}

void QHChooseGrabberType::slotCancel()
{
	this->done(QDialog::Rejected);
}
