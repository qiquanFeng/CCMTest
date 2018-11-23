#ifndef QHTEXTINFOPANEL_H
#define QHTEXTINFOPANEL_H

#include <QDockWidget>
#include "ui_QHTextInfoPanel.h"
#include <QFile>
#include <QString>

class QHTextInfoPanel : public QDockWidget
{
	Q_OBJECT

public:
	QHTextInfoPanel(QWidget *parent, bool bChannel1, bool* bSaveTextInfo2Local2);
	~QHTextInfoPanel();
	Ui::QHTextInfoPanel ui;
	const bool bBoxChannel1;
	bool* bSaveTextInfo2Local;

private:
	

public slots:
	void saveinformation();
	void clearinformation();
	void ShowInformation(QString info); 
	void info_customMenuRequested(QPoint pos);

};

#endif // QHTEXTINFOPANEL_H
