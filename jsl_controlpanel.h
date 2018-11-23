#ifndef JSL_CONTROLPANEL_H
#define JSL_CONTROLPANEL_H


#include <QWidget>
#include <QDialog>
#include "ui_jsl_controlpanel.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <qt_windows.h>

#include ".\\LeisaiLib\\LTDMC.h"
#include "globaldefine.h"

#if (defined USE_EQUIPMENT_AFM_JSL_V2)

class jsl_controlpanel : public QDialog
{
	Q_OBJECT

public:

	~jsl_controlpanel();
	jsl_controlpanel(QDialog *parent = 0);
	QLabel *labAxis1,*labAxis2,*labAxis3,*labAxis4,*labAxis5;
	QLabel *labAxis1_E,*labAxis2_E,*labAxis3_E,*labAxis4_E,*labAxis5_E;
	QLabel *labAxis1_L,*labAxis2_L,*labAxis3_L,*labAxis4_L,*labAxis5_L;
	QLabel *labAxis1_O, *labAxis2_O, *labAxis3_O, *labAxis4_O, *labAxis5_O;
	QLabel *LabAxis1_Pos,*LabAxis2_Pos,*LabAxis3_Pos,*LabAxis4_Pos,*LabAxis5_Pos;

	QTableWidget *tabIoStatus,*tabAxisStatus;
	QSpinBox *leAxis1,*leAxis2,*leAxis3,*leAxis4,*leAxis5;
	QPushButton *butAxis1Move,*butAxis2Move,*butAxis3Move,*butAxis4Move,*butAxis5Move,*butReset,*butInstall,*butFocus;
	QPushButton *butAxis1Org,*butAxis2Org,*butAxis3Org,*butAxis4Org,*butAxis5Org;
	QVBoxLayout *vLayout;

	int m_nTimerID;
	virtual void timerEvent(QTimerEvent *e);

	public slots:
		void slot_IOdoubleClick(int row, int column);
		void slot_Axis1_Move();
		void slot_Axis2_Move();
		void slot_Axis3_Move();
		void slot_Axis4_Move();
		void slot_Axis5_Move();

		void slot_Axis4_org();
		void slot_Axis5_org();

		void slot_Reset();
		void slot_Install();
		void slot_Focus();

private:
	Ui::jsl_controlpanel ui;
};

#endif

#endif // JSL_CONTROLPANEL_H
