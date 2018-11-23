#include "QHButtonExec.h"

QHButtonExec::QHButtonExec(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);
	connect(ui.seriallineEdit,  SIGNAL(returnPressed()), this, SLOT(handleEnter()));
}

QHButtonExec::~QHButtonExec()
{

}

void QHButtonExec::handleEnter()
{
	ui.seriallineEdit->selectAll();
}

void QHButtonExec::resizeEvent (QResizeEvent * event)
{
	ui.resultlabel->setMaximumHeight(ui.resultlabel->width() *10 /13);
	ui.resultlabel->setMinimumHeight(ui.resultlabel->width() /2);
	QDockWidget::resizeEvent(event);
}

