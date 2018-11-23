#ifndef FX3DEVICECONFIG_H
#define FX3DEVICECONFIG_H

#include <QDialog>
#include "ui_fx3deviceconfig.h"
#include "globaldefine.h"

class fx3deviceconfig : public QDialog
{
	Q_OBJECT

public:
	fx3deviceconfig(QWidget *parent = 0);
	~fx3deviceconfig();

	void setConfig(bool bOpen1, unsigned int GrabberCount,unsigned char ucIndex1, unsigned int uiSerial1[4], unsigned int uiSerial2[40], QString strFreidlyName1);

private slots:
	void saveConfig();
	void slotSetGrabberParameter();
	void slotChoosePlatform();

private:
	Ui::fx3deviceconfig ui;
	bool bOpen;
	unsigned char ucIndex;
	unsigned int uiSerialChoose[4];
	unsigned int uiSerialNow[40];
	QString strFreidlyName;
};

#endif // FX3DEVICECONFIG_H
