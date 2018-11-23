#ifndef QHINFOPANEL_H
#define QHINFOPANEL_H

#include <QDockWidget>
#include "ui_QHInfoPanel.h"
#include "globaldefine.h"
#include "qoplow.h"
#include "qwt_plot_curve.h"
#include <QImage>
#include <QPixmap>

class QHBarChart;

class QHInfoPanel : public QDockWidget
{
	Q_OBJECT

public:
	QHInfoPanel(QWidget *parent = 0);
	~QHInfoPanel();
	Ui::QHInfoPanel ui;
	_globalParameter* hisglobalparameter;
	void drawBarChartSlef(QVector<_HBarChart_SelfItem>& vecItem, double dflYMin, double dflYMax);
	void drawCurve(QVector<_HQwtCurve_Item>& vecPoint, QVector<QColor>& vecLineColor, QVector<QString>& vecLegend, \
		double dflYMin=0.0, double dflYMax=0.0, double dflXMin=0.0, double dflXMax=0.0,bool bXAuto=true, unsigned int uiType = 0); //0-点 1-折线 2-平滑曲线


public slots:

// 	void slotDrawBarChart(QVector<_HBarChart_Item> vecItem, double dflYMin=0.0, double dflYMax=0.0, bool bYAuto=true);

// 	void slotDrawBarChartSelf(QVector<_HBarChart_SelfItem> vecItem, double dflYMin=0.0, double dflYMax=0.0);
	 
	void rightTabIndexChange(int index) { ROPLOW::saveGlobalConfigItem("ui", "right tab index", QString::number(index), 9); }
// 	void slotdockLocationChanged(Qt::DockWidgetArea area)
// 	{
// 		if(area == Qt::TopDockWidgetArea || area == Qt::BottomDockWidgetArea)
// 			ui.basicinfotabWidget->setTabPosition(QTabWidget::West);
// 		else
// 			ui.basicinfotabWidget->setTabPosition(QTabWidget::North);
// 	}

private:

	int getglobalParameter();
// 	void initBarqwtPlot();
	void initCurveqwtPlot();
	void drawBarChartSlefVertical(QPixmap& pixImage, QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax);
	void drawBarChartSlefVerticaCanvasl(QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax);
	void drawBarChartSlefHorizontalCanvasl(QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax);
	void drawBarChartSlefHorizontal(QPixmap& pixImage, QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax);

	unsigned char ucTableIndex;
// 	QHBarChart* d_barChartItem;
	QImage redSample;
	QImage greenSample;
	QImage yellowSample;
	QImage blueSample;
	QImage cyanSample; 
	QImage purpleSample;
	QPixmap pixCanvas;
	QRect canvasRect;
	double dflRulerMin;
	double dflRulerMax;
	QStringList strLabelX; 
	int iGroupCount;
	int iItemCount;
};

#endif // QHINFOPANEL_H
