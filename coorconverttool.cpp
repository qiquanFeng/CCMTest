#include "coorconverttool.h"
#include "globaldefine.h"

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

coorconverttool::coorconverttool(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);

	connect(ui.fovpushButton, SIGNAL(released()), this, SLOT(Coor2FOV()));
	connect(ui.dispushButton, SIGNAL(released()), this, SLOT(CalculateDistance()));
	connect(ui.RGB2LabpushButton, SIGNAL(released()), this, SLOT(slotRGB2Lab()));
}

coorconverttool::~coorconverttool()
{

}

void coorconverttool::setImageSize(unsigned int uiWidth, unsigned int uiHeight)
{
	ui.fovImageWidthspinBox->setValue(max(2, uiWidth));
	ui.fovImageHeightspinBox->setValue(max(2, uiHeight));
}

void coorconverttool::Coor2FOV()
{
	double dflWidth	=	ui.fovImageWidthspinBox->value();
	double dflHeight	=	ui.fovImageHeightspinBox->value();
	double dflX			=	ui.fovXspinBox->value();
	double dflY			=	ui.fovYspinBox->value();

	dflWidth	*=	0.5;
	dflHeight	*=	0.5;

	double dflN1	=	sqrt(dflWidth*dflWidth + dflHeight *dflHeight);
	double dflDis	=	sqrt((dflWidth-dflX)*(dflWidth-dflX) + (dflHeight-dflY)*(dflHeight-dflY));
	double dflFOV	=	dflDis / dflN1;
	double dflAngle = atan(abs(dflHeight-dflY) /abs(dflWidth-dflX)) *180.0 /3.1415926535897932384626433832795;

	ui.fovlineEdit->setText(QString::number(dflFOV, 'f', 3));
	ui.fovAnglelineEdit->setText(QString::number(dflAngle, 'f', 3));
}

void coorconverttool::CalculateDistance()
{
	double dflX1			=	ui.disX1spinBox->value();
	double dflY1			=	ui.disY1spinBox->value();
	double dflX2			=	ui.disX2spinBox->value();
	double dflY2			=	ui.disY2spinBox->value();

	double dflDis	=	sqrt((dflX1-dflX2)*(dflX1-dflX2) + (dflY1-dflY2)*(dflY1-dflY2));
	ui.dislineEdit->setText(QString::number(dflDis, 'f', 3));
}

void coorconverttool::slotRGB2Lab()
{
	unsigned char rgb24Buffer[3];
	rgb24Buffer[0]	=	ui.rgb2lab_RGB_RspinBox->value();
	rgb24Buffer[1]	=	ui.rgb2lab_RGB_GspinBox->value();
	rgb24Buffer[2]	=	ui.rgb2lab_RGB_BspinBox->value();

	float L, A, B, RB, RG, BG, Y;
	CRolongoImageTestAlg classTest;
	RECT stROI;
	stROI.left	=stROI.top	=0;
	stROI.right	=stROI.bottom	=1;
	DWORD dwstart = GetTickCount();
	classTest.GetROILab(rgb24Buffer, 1,1, stROI, &L, &A, &B, &RB, &RG, &BG, &Y);
	qDebug() << "time:" << GetTickCount() - dwstart;
	qDebug() << "GetROILab" <<L<< A<< B<< RB<< RG<< BG<< Y;
	ui.rgb2lab_Lab_LdoubleSpinBox->setValue(L);
	ui.rgb2lab_Lab_adoubleSpinBox->setValue(A);
	ui.rgb2lab_Lab_bdoubleSpinBox->setValue(B);
}
