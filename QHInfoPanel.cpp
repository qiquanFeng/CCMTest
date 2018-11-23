#include "QHInfoPanel.h"
#include <QMenu>
#include <QListWidgetItem>
#include <QTime>
#include "qwt_plot_canvas.h"
#include "qwt_plot_barchart.h"
#include "qwt_column_symbol.h"
#include "qwt_legend.h"
#include "qwt_scale_draw.h"
#include "qwt_symbol.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_layout.h"
#include "qwt_curve_fitter.h"

class QHBarChartScaleDraw: public QwtScaleDraw
{
public:
	QHBarChartScaleDraw( Qt::Orientation orientation, const QStringList &labels ):
	  d_labels( labels )
	  {
// 		  setTickLength( QwtScaleDiv::MinorTick, 0 );
// 		  setTickLength( QwtScaleDiv::MediumTick, 0 );
// 		  setTickLength( QwtScaleDiv::MajorTick, 2 );
// 
		  enableComponent( QwtScaleDraw::Backbone, false );
		  enableComponent( QwtScaleDraw::Ticks, false );

		  if ( orientation == Qt::Vertical )
		  {
			  setLabelRotation( -60.0 );
		  }
		  else
		  {
			  setLabelRotation( -20.0 );
// 			  setAlignment(QwtScaleDraw::RightScale);
		  }

		  setLabelAlignment( Qt::AlignLeft | Qt::AlignVCenter );
	  }

	  virtual QwtText label( double value ) const
	  {
		  QwtText lbl;

		  const int index = qRound( value );
		  if ( index >= 0 && index < d_labels.size() )
		  {
			  lbl = d_labels[ index ];
		  }

		  return lbl;
	  }

private:
	const QStringList d_labels;
};

class QHBarChart: public QwtPlotBarChart
{
public:
	QHBarChart():
	  QwtPlotBarChart(/* "Page Hits" */)
	  {
		  setLegendMode( QwtPlotBarChart::LegendBarTitles);
// 		  setLegendIconSize( QSize( 13, 13 ) );
		  setLayoutPolicy( AutoAdjustSamples );
		  setLayoutHint( 4.0 ); // minimum width for a single bar

		  setSpacing( 2 ); // spacing between bars
		  setMargin(2);
	  }

	  void addDistro( const QString &distro, const QColor &color )
	  {
		  d_colors += color;
		  d_distros += distro;
	  }

	  virtual QwtColumnSymbol *specialSymbol(
		  int index, const QPointF& ) const
	  {
		  // we want to have individual colors for each bar

		  QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
		  symbol->setLineWidth( 2 );
		  symbol->setFrameStyle( QwtColumnSymbol::Raised );

		  QColor c( Qt::white );
		  if ( index >= 0 && index < d_colors.size() )
			  c = d_colors[ index ];

		  symbol->setPalette( c );

		  return symbol;
	  }

/*
	  virtual QwtText barTitle( int sampleIndex ) const
	  {
		  QwtText title;
		  if ( sampleIndex >= 0 && sampleIndex < d_distros.size() )
			  title = d_distros[ sampleIndex ];

		  return title;
	  }
*/

	  void clear()
	  {
		  d_colors.clear();
		  d_distros.clear();
	  }

private:
	QList<QColor> d_colors;
	QList<QString> d_distros;
};

bool curvesortbyX(const _HQwtCurve_Item &s1, const _HQwtCurve_Item &s2)
{
	return s1.dflX < s2.dflX;
}

QHInfoPanel::QHInfoPanel(QWidget *parent)
	: QDockWidget(parent)
{
	ui.setupUi(this);

// 	connect(ui.basicinfotabWidget, SIGNAL(currentChanged(int)), this, SLOT(rightTabIndexChange(int)));
// 	connect(this, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(slotdockLocationChanged(Qt::DockWidgetArea)));

	ucTableIndex	=	1;
// 	getglobalParameter();
// 	ui.basicinfotabWidget->setCurrentIndex(ucTableIndex);

// 	initBarqwtPlot();
	initCurveqwtPlot();
// 	ui.drawinfoqwtPlot->setVisible(false);
	ui.drawcurveqwtPlot->setVisible(false);
}

QHInfoPanel::~QHInfoPanel()
{
// 	d_barChartItem->detach();
// 	HisReleaseNewO(d_barChartItem);

}


int QHInfoPanel::getglobalParameter()
{
	{
		QSqlDatabase templatedb = QSqlDatabase::addDatabase("QSQLITE", "querytemplateinfo");
		templatedb.setDatabaseName(QDir::currentPath() % "/HisFX3Template");
		if (!templatedb.open())
			return HisCCMError_Database;

		QSqlQuery query(templatedb);
		query.prepare("SELECT key, value FROM global WHERE item='ui' ORDER BY id ASC" );
		query.exec();
		while (query.next()){
			if(query.value(0).toString() == "right tab index")  ucTableIndex = query.value(1).toString().toUInt();
		}

		templatedb.close();
	}

	QSqlDatabase::removeDatabase("querytemplateinfo");

	return 0;
}

/*
void QHInfoPanel::initBarqwtPlot()
{
	ui.drawinfoqwtPlot->setAutoFillBackground( true );
	QwtPlotCanvas *canvas = new QwtPlotCanvas();
	canvas->setLineWidth( 1 );
	canvas->setFrameStyle(QFrame::Box | QFrame::Sunken);
//	canvas->setBorderRadius( 10 );

// 	QPalette canvasPalette( QColor( "Plum" ) );
// 	canvasPalette.setColor( QPalette::Foreground, QColor( "Indigo" ) );
// 	canvas->setPalette( canvasPalette );

	ui.drawinfoqwtPlot->setCanvas( canvas );
// 	ui.drawinfoqwtPlot->insertLegend( new QwtLegend() );
	d_barChartItem	=	new QHBarChart();
	d_barChartItem->setMargin(2);
	d_barChartItem->attach(ui.drawinfoqwtPlot);
}

void QHInfoPanel::slotDrawBarChart(QVector<_HBarChart_Item> vecItem, double dflYMin, double dflYMax, bool bYAuto)
{
	if(vecItem.size() < 1) return;

	ui.drawinfolabel->setVisible(false);
	ui.drawcurveqwtPlot->setVisible(false);
	ui.drawinfoqwtPlot->setVisible(true);
	const unsigned int cuiBarWidthMax	=	50;

	QStringList listLabel;
	d_barChartItem->clear();
	QVector< double > samples;
	
// 	d_barChartItem->setBaseline(dflYMin);
	if(ui.drawinfoqwtPlot->width() > ui.drawinfoqwtPlot->height()){
		for(int x = 0; x < vecItem.size(); ++x){
			d_barChartItem->addDistro(vecItem.at(x).strTitle, vecItem.at(x).stColor);
			samples	+=	vecItem.at(x).dflValue;
			listLabel	+=	vecItem.at(x).strTitle;
		}
		d_barChartItem->setSamples(samples);

		d_barChartItem->setOrientation( Qt::Vertical );
		unsigned int uiIndexCount	=	ui.drawinfoqwtPlot->width() /cuiBarWidthMax;
		uiIndexCount	=	max(uiIndexCount, vecItem.size()-1);
		ui.drawinfoqwtPlot->setAxisScale(QwtPlot::xBottom, 0, uiIndexCount, 1);
		if(!bYAuto)
			ui.drawinfoqwtPlot->setAxisScale(QwtPlot::yLeft, dflYMin, dflYMax);

		ui.drawinfoqwtPlot->setAxisMaxMinor(QwtPlot::xBottom, 3 );
		ui.drawinfoqwtPlot->setAxisScaleDraw(QwtPlot::xBottom, new QHBarChartScaleDraw( Qt::Vertical, listLabel) );

		QwtScaleDraw *scaleDraw = new QwtScaleDraw();
// 		scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 4 );
		ui.drawinfoqwtPlot->setAxisScaleDraw(QwtPlot::yLeft, scaleDraw );
	}
	else{
		for(int x = vecItem.size()-1; x >= 0; --x){
			d_barChartItem->addDistro(vecItem.at(x).strTitle, vecItem.at(x).stColor);
			samples	+=	vecItem.at(x).dflValue;
			listLabel	+=	vecItem.at(x).strTitle;
		}
		d_barChartItem->setSamples(samples);

		d_barChartItem->setOrientation( Qt::Horizontal );
// 		d_barChartItem->setXAxis(QwtPlot::xBottom);
		unsigned int uiIndexCount	=	ui.drawinfoqwtPlot->height() /cuiBarWidthMax;
		uiIndexCount	=	max(uiIndexCount, vecItem.size()-1);
		ui.drawinfoqwtPlot->setAxisScale(QwtPlot::yLeft, 0, uiIndexCount, 1);
		if(!bYAuto)
			ui.drawinfoqwtPlot->setAxisScale(QwtPlot::xBottom, dflYMin, dflYMax);

		ui.drawinfoqwtPlot->setAxisMaxMinor(QwtPlot::yLeft, 3 );
		ui.drawinfoqwtPlot->setAxisScaleDraw(QwtPlot::yLeft, new QHBarChartScaleDraw( Qt::Horizontal, listLabel) );

		QwtScaleDraw *scaleDraw = new QwtScaleDraw();
// 		scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 4 );
		ui.drawinfoqwtPlot->setAxisScaleDraw(QwtPlot::xBottom, scaleDraw );
	}

	ui.drawinfoqwtPlot->replot();
}
*/

void QHInfoPanel::initCurveqwtPlot()
{
	ui.drawcurveqwtPlot->setAutoFillBackground( true );
	ui.drawcurveqwtPlot->insertLegend( new QwtLegend() );
	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->attach(ui.drawcurveqwtPlot);
}

void QHInfoPanel::drawCurve(QVector<_HQwtCurve_Item>& vecPoint, QVector<QColor>& vecLineColor, \
	QVector<QString>& vecLegend, double dflYMin, double dflYMax, double dflXMin, double dflXMax,bool bXAuto, unsigned int uiType)
{
	if(vecLineColor.size() < 1) return;
	ui.drawinfolabel->setVisible(false);
// 	ui.drawinfoqwtPlot->setVisible(false);
	ui.drawcurveqwtPlot->setVisible(true);

	QwtPlotItemList curveList = ui.drawcurveqwtPlot->itemList(QwtPlotItem::Rtti_PlotCurve);

	if ( curveList.size() != vecLineColor.size() )
	{
		while ( curveList.size() > vecLineColor.size()){
			QwtPlotItem* curve = curveList.takeFirst();
			delete curve;
		}

		for ( int i = curveList.size(); i < vecLineColor.size(); i++ ){
			QwtPlotCurve *curve = new QwtPlotCurve();
			QwtSymbol::Style iStyle;
			switch (i){
			case 0: iStyle = QwtSymbol::Ellipse; break;
			case 1: iStyle = QwtSymbol::Rect; break;
			case 2: iStyle = QwtSymbol::Diamond; break;
			case 3: iStyle = QwtSymbol::Triangle; break;
			case 4: iStyle = QwtSymbol::Cross; break;
			case 5: iStyle = QwtSymbol::XCross; break;
			case 6: iStyle = QwtSymbol::Star1; break;
			case 7: iStyle = QwtSymbol::Star2; break;
			case 8: iStyle = QwtSymbol::HLine; break;
			case 9: iStyle = QwtSymbol::VLine; break;
			case 10: iStyle = QwtSymbol::DTriangle; break;
			case 11: iStyle = QwtSymbol::UTriangle; break;
			case 12: iStyle = QwtSymbol::LTriangle; break;
			case 13: iStyle = QwtSymbol::RTriangle; break;
			default: iStyle = QwtSymbol::Hexagon; break;
			}
			QwtSymbol *symbol = new QwtSymbol( iStyle, QBrush( Qt::yellow ), QPen( Qt::darkCyan, 2 ), QSize( 8, 8 ) );
			curve->setSymbol( symbol );
			curve->setCurveFitter(new QwtSplineCurveFitter());
			curve->attach( ui.drawcurveqwtPlot );
		}
	}

	qSort(vecPoint.begin(), vecPoint.end(), curvesortbyX);

	curveList = ui.drawcurveqwtPlot->itemList(QwtPlotItem::Rtti_PlotCurve);
	QVector< QPointF > 	vecSamples;
	vecSamples.resize(vecPoint.size());
	for ( int i = 0; i < curveList.count(); i++ )
	{
		QwtPlotCurve* curve = static_cast<QwtPlotCurve*>( curveList[i] );
		switch (uiType){
		case 0: curve->setStyle(QwtPlotCurve::Dots); break;
		case 1: curve->setStyle(QwtPlotCurve::Lines); curve->setCurveAttribute( QwtPlotCurve::Fitted, false); break;
		default: curve->setStyle(QwtPlotCurve::Lines); curve->setCurveAttribute( QwtPlotCurve::Fitted, true); break;
		}	
		QwtSymbol* cuurentSymbol	=	(QwtSymbol*)curve->symbol();
		cuurentSymbol->setColor(vecLineColor[i]);
		curve->setTitle(vecLegend[i]);
		curve->setPen(vecLineColor[i], 4);
		for(unsigned int x=0;	x<vecSamples.size();	++x){
			vecSamples[x].setX(vecPoint[x].dflX);
			vecSamples[x].setY(vecPoint[x].vecValue[i]);
		}

		curve->setSamples(vecSamples);
	}

	ui.drawcurveqwtPlot->setAxisScale(QwtPlot::yLeft, dflYMin, dflYMax);
	if(!bXAuto)
		ui.drawcurveqwtPlot->setAxisScale(QwtPlot::xBottom, dflXMin, dflXMax);

	if(ui.drawcurveqwtPlot->width() > ui.drawcurveqwtPlot->height()){
		if(ui.drawcurveqwtPlot->plotLayout()->legendPosition() != QwtPlot::RightLegend)
			ui.drawcurveqwtPlot->insertLegend( new QwtLegend(), QwtPlot::RightLegend);
	}
	else{
		if(ui.drawcurveqwtPlot->plotLayout()->legendPosition() != QwtPlot::TopLegend)
			ui.drawcurveqwtPlot->insertLegend( new QwtLegend(), QwtPlot::TopLegend);
	}

	ui.drawcurveqwtPlot->replot();
}

void QHInfoPanel::drawBarChartSlef(QVector<_HBarChart_SelfItem>& vecItem, double dflYMin, double dflYMax)
{
	if(vecItem.size() < 1 || dflYMin >= dflYMax) return;
	
// 	ui.drawinfoqwtPlot->setVisible(false);
	ui.drawcurveqwtPlot->setVisible(false);
	ui.drawinfolabel->setVisible(true);

	bool bVertical	=	(ui.drawinfolabel->width() > ui.drawinfolabel->height());
	if(bVertical)
		drawBarChartSlefVerticaCanvasl(vecItem, dflYMin, dflYMax);
	else
		drawBarChartSlefHorizontalCanvasl(vecItem, dflYMin, dflYMax);

	QPixmap pixImage = pixCanvas;
	if(bVertical)
		drawBarChartSlefVertical(pixImage, vecItem, dflYMin, dflYMax);
	else
		drawBarChartSlefHorizontal(pixImage, vecItem, dflYMin, dflYMax);

	
	ui.drawinfolabel->setPixmap(pixImage);
// 	pixImage.save("caintoe.png");
}

void QHInfoPanel::drawBarChartSlefVerticaCanvasl(QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax)
{
	QRect stCanvasRect;
	int iBarCount	=	vecItem.size();
	int iGoupe		=	0, iXTextCount = 0;
	QVector<_HBarChart_SelfItem>::iterator theiterator;
	QStringList listLabel;
	for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
		iGoupe	=	max(iGoupe, theiterator->uiGroupIndex);
		iXTextCount	=	max(iXTextCount, theiterator->strTitle.size());
		listLabel	+=	theiterator->strTitle;
	}
	++iGoupe;

	const int ciCanvasLineWidth	=	2, ciRulerLineWidth = 1, ciRulerLong = 8, ciRulerShort = 4, ciRulerMiddle = 6, ciRulerGap = 1;
	const int ciYTextGap = 2, ciXTextGap = 2, ciYTextFont = 9, ciXTextFont = 9;
	const int ciBarGap = 1, ciBarMargin = 2, ciGroupGap = 6, ciBarWidth = 40, ciBarHeight = 140;
	const int ciValueTextFont = 7, ciValueTextGap = 1;
	int iYTextCount	=	4;
	int iCanvasWidth	=	iYTextCount *ciYTextFont /2 + ciYTextGap *2 +ciRulerLong +ciRulerLineWidth +ciRulerGap +ciCanvasLineWidth*2 +ciBarMargin +max(iBarCount, 6) *(ciBarWidth+1) +max(0,iGoupe-1) *ciGroupGap;
	int iCanvasHeight	=	ciXTextFont *2 + ciXTextGap *2 +ciCanvasLineWidth *2 +ciBarHeight +ciValueTextFont + ciValueTextGap *2;
	stCanvasRect.setLeft(iYTextCount *ciYTextFont /2 + ciYTextGap *2 +ciRulerLong +ciRulerLineWidth +ciRulerGap +ciCanvasLineWidth);
	stCanvasRect.setWidth(ciBarMargin +max(iBarCount, 6) *(ciBarWidth+1) +max(0,iGoupe-1) *ciGroupGap-1);
	stCanvasRect.setTop(ciCanvasLineWidth);
	stCanvasRect.setHeight(ciBarHeight +ciValueTextFont + ciValueTextGap *2);

	bool bRepaint = false;
	if(pixCanvas.isNull() || pixCanvas.width() != iCanvasWidth || pixCanvas.height() != iCanvasHeight || stCanvasRect != canvasRect || \
		dflYMin != dflRulerMin || dflYMax != dflRulerMax || listLabel != strLabelX || iGroupCount != iGoupe || iItemCount != vecItem.size())
		bRepaint = true;

	if(!bRepaint) return;

	QPixmap pixCaintor(iCanvasWidth, iCanvasHeight);
	pixCaintor.fill(QColor::fromRgb(240,240,240));
	QPainter painter(&pixCaintor);
	QPen pen	=	painter.pen();
	pen.setStyle(Qt::SolidLine);
	QFont font	=	painter.font();
	font.setFamily("Arial");
	painter.setRenderHint(QPainter::TextAntialiasing, true);

	//border
	QRect stRect(stCanvasRect.left()-2, stCanvasRect.top()-2, stCanvasRect.width()+4, stCanvasRect.height() +4);
	pen.setColor(QColor::fromRgb(255, 255, 255));
	pen.setWidth(1);
	painter.setPen(pen);
	painter.drawRect(stRect);
	stRect.setRect(stCanvasRect.left()-1, stCanvasRect.top()-1, stCanvasRect.width()+2, stCanvasRect.height() +2);
	pen.setColor(QColor::fromRgb(160, 160, 160));
	painter.setPen(pen);
	painter.drawRect(stRect);

	//X label
	font.setPixelSize(ciXTextFont);
	painter.setFont(font);
	pen.setColor(QColor::fromRgb(0,0,0));
	painter.setPen(pen);
	stRect.setTop(stCanvasRect.bottom()+ciCanvasLineWidth +1);
	stRect.setBottom(iCanvasHeight - 1);
	stRect.setWidth(ciBarWidth+ciBarGap);
	stRect.setLeft(stCanvasRect.left() +ciBarMargin);

	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x) continue;
			painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  theiterator->strTitle);
			stRect.moveLeft(stRect.left() + ciBarWidth+ciBarGap);
		}
		stRect.moveLeft(stRect.left() + ciGroupGap -ciBarGap);
	}

	QLine stLine(stCanvasRect.left()-ciCanvasLineWidth-ciRulerGap-1, stCanvasRect.top()+ciValueTextFont + ciValueTextGap *2, stCanvasRect.left()-ciCanvasLineWidth-ciRulerGap-1, stCanvasRect.bottom());
	painter.drawLine(stLine);
	QLine stLine0(stCanvasRect.left()-ciCanvasLineWidth-ciRulerGap-ciRulerLineWidth-ciRulerLong, stCanvasRect.top()+ciValueTextFont + ciValueTextGap *2, stCanvasRect.left()-ciCanvasLineWidth-ciRulerGap-ciRulerLineWidth-1, stCanvasRect.top()+ciValueTextFont + ciValueTextGap *2);
	painter.drawLine(stLine0);
	QLine stLine4(stLine0.x1(), stCanvasRect.bottom(), stLine0.x2(), stCanvasRect.bottom());
	painter.drawLine(stLine4);
	QLine stLine2(stLine0.x1(), (stLine0.y1() + stLine4.y1()) /2, stLine0.x2(), (stLine0.y1() + stLine4.y1()) /2);
	painter.drawLine(stLine2);
	QLine stLine1(stLine0.x1(), (stLine0.y1() + stLine2.y1()) /2, stLine0.x2(), (stLine0.y1() + stLine2.y1()) /2);
	painter.drawLine(stLine1);
	QLine stLine3(stLine0.x1(), (stLine2.y1() + stLine4.y1()) /2, stLine0.x2(), (stLine2.y1() + stLine4.y1()) /2);
	painter.drawLine(stLine3);

	QStringList listValueLabel;
	if(dflYMax > 10.0){
		listValueLabel += QString::number(qRound(dflYMax), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMax *0.75 + dflYMin *0.25), 'f', 0);
		listValueLabel += QString::number(qRound((dflYMax + dflYMin) *0.5), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMax *0.25 + dflYMin *0.75), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMin), 'f', 0);
	}
	else{
		double dflBigStep = (dflYMax - dflYMin) /4.0;
		int iDec	=	(abs(dflBigStep *10.0 - qRound(dflBigStep*10.0)) > 0.1)?(2):(1);
		listValueLabel += QString::number(dflYMax, 'f', iDec);
		listValueLabel += QString::number(dflYMax *0.75 + dflYMin *0.25, 'f', iDec);
		listValueLabel += QString::number((dflYMax + dflYMin) *0.5, 'f', iDec);
		listValueLabel += QString::number(dflYMax *0.25 + dflYMin *0.75, 'f', iDec);
		listValueLabel += QString::number(dflYMin, 'f', iDec);
	}

	stRect.setRect(0, stLine0.y1()-ciYTextFont/2, stLine0.x1(), ciYTextFont);
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[0]);
	stRect.setRect(0, stLine1.y1()-ciYTextFont/2, stLine1.x1(), ciYTextFont);
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[1]);
	stRect.setRect(0, stLine2.y1()-ciYTextFont/2, stLine2.x1(), ciYTextFont);
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[2]);
	stRect.setRect(0, stLine3.y1()-ciYTextFont/2, stLine3.x1(), ciYTextFont);
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[3]);
	stRect.setRect(0, stLine4.y1()-ciYTextFont/2, stLine4.x1(), ciYTextFont);
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[4]);

	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine0.y1() *0.25 + stLine1.y2()*0.75, stLine0.x2(), stLine0.y1() *0.25 + stLine1.y2()*0.75);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerMiddle+1, stLine0.y1() *0.5 + stLine1.y2()*0.5, stLine0.x2(), stLine0.y1() *0.5 + stLine1.y2()*0.5);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine0.y1() *0.75 + stLine1.y2()*0.25, stLine0.x2(), stLine0.y1() *0.75 + stLine1.y2()*0.25);
	painter.drawLine(stLine);

	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine1.y1() *0.25 + stLine2.y2()*0.75, stLine0.x2(), stLine1.y1() *0.25 + stLine2.y2()*0.75);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerMiddle+1, stLine1.y1() *0.5 + stLine2.y2()*0.5, stLine0.x2(), stLine1.y1() *0.5 + stLine2.y2()*0.5);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine1.y1() *0.75 + stLine2.y2()*0.25, stLine0.x2(), stLine1.y1() *0.75 + stLine2.y2()*0.25);
	painter.drawLine(stLine);

	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine2.y1() *0.25 + stLine3.y2()*0.75, stLine0.x2(), stLine2.y1() *0.25 + stLine3.y2()*0.75);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerMiddle+1, stLine2.y1() *0.5 + stLine3.y2()*0.5, stLine0.x2(), stLine2.y1() *0.5 + stLine3.y2()*0.5);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine2.y1() *0.75 + stLine3.y2()*0.25, stLine0.x2(), stLine2.y1() *0.75 + stLine3.y2()*0.25);
	painter.drawLine(stLine);

	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine3.y1() *0.25 + stLine4.y2()*0.75, stLine0.x2(), stLine3.y1() *0.25 + stLine4.y2()*0.75);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerMiddle+1, stLine3.y1() *0.5 + stLine4.y2()*0.5, stLine0.x2(), stLine3.y1() *0.5 + stLine4.y2()*0.5);
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x2() -ciRulerShort+1, stLine3.y1() *0.75 + stLine4.y2()*0.25, stLine0.x2(), stLine3.y1() *0.75 + stLine4.y2()*0.25);
	painter.drawLine(stLine);

	pixCanvas	=	pixCaintor;
	canvasRect	=	stCanvasRect;
	dflRulerMin	=	dflYMin;
	dflRulerMax	=	dflYMax;
	strLabelX		=	listLabel;
	iGroupCount	=	iGoupe;
	iItemCount		=	vecItem.size();
}

void QHInfoPanel::drawBarChartSlefVertical(QPixmap& pixImage, QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax)
{
	const int ciBarGap = 1, ciBarMargin = 2, ciGroupGap = 6, ciBarWidth = 40, ciBarHeight = 140;
	const int ciValueTextFont = 7, ciValueTextGap = 1;

	int iGoupe		=	0;
	QVector<_HBarChart_SelfItem>::iterator theiterator;
	for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
		iGoupe	=	max(iGoupe, theiterator->uiGroupIndex);
		switch (theiterator->uiColorIndex){ //0-red 1:green 2:yellow 3:blue 4:cyan 5:purple
		case 0: if(redSample.isNull() || redSample.width() > redSample.height()) redSample.load(":/Resources/bar_red.png", "PNG"); break;
		case 1: if(greenSample.isNull() || greenSample.width() > greenSample.height()) greenSample.load(":/Resources/bar_green.png", "PNG"); break;
		case 2: if(yellowSample.isNull() || yellowSample.width() > yellowSample.height()) yellowSample.load(":/Resources/bar_yellow.PNG", "PNG"); break;
		case 3: if(blueSample.isNull() || blueSample.width() > blueSample.height()) blueSample.load(":/Resources/bar_blue.png", "PNG"); break;
		case 4: if(cyanSample.isNull() || cyanSample.width() > cyanSample.height()) cyanSample.load(":/Resources/bar_cyan.PNG", "PNG"); break;
		default: if(purpleSample.isNull() || purpleSample.width() > purpleSample.height()) purpleSample.load(":/Resources/bar_purple.PNG", "PNG"); break;
		}
	}
	++iGoupe;

	QPainter painter(&pixImage);
	QPen pen	=	painter.pen();
	pen.setWidth(2);
	pen.setColor(QColor::fromRgb(0,0,0));
	pen.setStyle(Qt::DotLine);
	painter.setPen(pen);
	QFont font	=	painter.font();
	font.setPixelSize(ciValueTextFont);
	font.setFamily("Arial");
	painter.setFont(font);
	QImage* pstBar;

	QRect stRect(canvasRect.left()+ciBarMargin, canvasRect.top(), ciBarWidth, canvasRect.bottom() - canvasRect.top());
	stRect.setBottom(canvasRect.bottom());
	QLine stLine;
	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x || theiterator->flValue > dflYMax || theiterator->flValue < dflYMin) continue;
			switch (theiterator->uiColorIndex){ //0-red 1:green 2:yellow 3:blue 4:cyan 5:purple
			case 0: pstBar = &redSample; break;
			case 1: pstBar = &greenSample; break;
			case 2: pstBar = &yellowSample; break;
			case 3: pstBar = &blueSample; break;
			case 4: pstBar = &cyanSample; break;
			default: pstBar = &purpleSample; break;
			}
			stRect.setTop(stRect.bottom() - qRound((theiterator->flValue-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5) +1);
			painter.drawImage(stRect, *pstBar);
			if(theiterator->flDotLine >dflYMin && theiterator->flDotLine < dflYMax){
				int itemp	=	stRect.bottom() - qRound((theiterator->flDotLine-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5) +1;
				stLine.setLine(stRect.left(), itemp, stRect.right(), itemp);
				painter.drawLine(stLine);
			}
			stRect.moveLeft(stRect.left() + ciBarWidth+ciBarGap);
		}
		stRect.moveLeft(stRect.left() + ciGroupGap-ciBarGap);
	}

	pen.setWidth(1);
	painter.setPen(pen);
	stRect.setRect(canvasRect.left()+ciBarMargin, canvasRect.top(), ciBarWidth, ciValueTextFont + ciValueTextGap *2);
	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x || theiterator->flValue > dflYMax || theiterator->flValue < dflYMin) continue;
			stRect.moveBottom(canvasRect.bottom() - qRound((theiterator->flValue-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5) +1);
			painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter, QString::number(theiterator->flValue, 'f', (theiterator->flValue > 1.0f)?(0):(3)));
			stRect.moveLeft(stRect.left() + ciBarWidth+ciBarGap);
		}
		stRect.moveLeft(stRect.left() + ciGroupGap-ciBarGap);
	}
}

void QHInfoPanel::drawBarChartSlefHorizontalCanvasl(QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax)
{
	QRect stCanvasRect;
	int iBarCount	=	vecItem.size();
	int iGoupe		=	0, iYTextCount = 0;
	QVector<_HBarChart_SelfItem>::iterator theiterator;
	QStringList listLabel;
	for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
		iGoupe	=	max(iGoupe, theiterator->uiGroupIndex);
		QStringList listTemp	=	theiterator->strTitle.split("\n");
		for(int x=0;	x<listTemp.size();	++x)
			iYTextCount	=	max(iYTextCount, listTemp.at(x).size());
		listLabel	+=	theiterator->strTitle;
	}
	++iGoupe;

	const int ciCanvasLineWidth	=	2, ciRulerLineWidth = 1, ciRulerLong = 8, ciRulerShort = 4, ciRulerMiddle = 6, ciRulerGap = 1;
	const int ciYTextGap = 2, ciXTextGap = 2, ciYTextFont = 9, ciXTextFont = 9;
	const int ciBarGap = 1, ciBarMargin = 2, ciGroupGap = 6, ciBarWidth = 40, ciBarHeight = 140;
	const int ciValueTextFont = 7, ciValueTextGap = 1, ciValueTextCount = 5;
	int iXTextCount	=	4;
	int iCanvasWidth		=	ciYTextGap*2 +iYTextCount*ciYTextFont/2 +ciCanvasLineWidth*2 +ciBarHeight +ciValueTextFont *ciValueTextCount /2 + ciValueTextGap *2;
	int iCanvasHeight	=	ciXTextFont + ciXTextGap*2 + ciRulerLong +ciRulerLineWidth + ciRulerGap + ciCanvasLineWidth*2 +ciBarMargin +max(iBarCount, 6) *(ciBarWidth+1) +max(0,iGoupe-1) *ciGroupGap;
	stCanvasRect.setLeft(ciYTextGap*2 +iYTextCount*ciYTextFont/2 +ciCanvasLineWidth);
	stCanvasRect.setWidth(ciBarHeight +ciValueTextFont *ciValueTextCount /2 + ciValueTextGap *2-1);
	stCanvasRect.setTop(ciXTextFont + ciXTextGap*2 + ciRulerLong +ciRulerLineWidth + ciRulerGap + ciCanvasLineWidth);
	stCanvasRect.setHeight(ciBarMargin +max(iBarCount, 6) *(ciBarWidth+1) +max(0,iGoupe-1) *ciGroupGap-1);

	bool bRepaint = false;
	if(pixCanvas.isNull() || pixCanvas.width() != iCanvasWidth || pixCanvas.height() != iCanvasHeight || stCanvasRect != canvasRect || \
		dflYMin != dflRulerMin || dflYMax != dflRulerMax || listLabel != strLabelX || iGroupCount != iGoupe || iItemCount != vecItem.size())
		bRepaint = true;

	if(!bRepaint) return;

	QPixmap pixCaintor(iCanvasWidth, iCanvasHeight);
	pixCaintor.fill(QColor::fromRgb(240,240,240));
	QPainter painter(&pixCaintor);
	QPen pen	=	painter.pen();
	pen.setStyle(Qt::SolidLine);
	QFont font	=	painter.font();
	font.setFamily("Arial");
	painter.setRenderHint(QPainter::TextAntialiasing, true);

	//border
	QRect stRect(stCanvasRect.left()-2, stCanvasRect.top()-2, stCanvasRect.width()+4, stCanvasRect.height() +4);
	pen.setColor(QColor::fromRgb(255, 255, 255));
	pen.setWidth(1);
	painter.setPen(pen);
	painter.drawRect(stRect);
	stRect.setRect(stCanvasRect.left()-1, stCanvasRect.top()-1, stCanvasRect.width()+2, stCanvasRect.height() +2);
	pen.setColor(QColor::fromRgb(160, 160, 160));
	painter.setPen(pen);
	painter.drawRect(stRect);

	//Y label
	font.setPixelSize(ciYTextFont);
	painter.setFont(font);
	pen.setColor(QColor::fromRgb(0,0,0));
	painter.setPen(pen);
	stRect.setLeft(0);
	stRect.setRight(stCanvasRect.left() - ciCanvasLineWidth);
	stRect.setTop(stCanvasRect.top());
	stRect.setHeight(ciBarWidth);

	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x) continue;
			painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  theiterator->strTitle);
			stRect.moveTop(stRect.top() + ciBarWidth+ciBarGap);
		}
		stRect.moveTop(stRect.top() + ciGroupGap -ciBarGap);
	}

	QLine stLine(stCanvasRect.left(), stCanvasRect.top() -ciCanvasLineWidth -ciRulerGap-1, stCanvasRect.left() +ciBarHeight-1, stCanvasRect.top() -ciCanvasLineWidth -ciRulerGap-1);
	painter.drawLine(stLine);
	QLine stLine0(stLine.x1(), stLine.y1(), stLine.x1(), stLine.y1()-ciRulerLong);
	painter.drawLine(stLine0);
	QLine stLine4(stLine.x2(), stLine.y1(), stLine.x2(), stLine.y1()-ciRulerLong);
	painter.drawLine(stLine4);
	QLine stLine2((stLine0.x1() + stLine4.x1()) /2, stLine0.y1(), (stLine0.x2() + stLine4.x2()) /2, stLine0.y2());
	painter.drawLine(stLine2);
	QLine stLine1((stLine0.x1() + stLine2.x1()) /2, stLine0.y1(), (stLine0.x2() + stLine2.x2()) /2, stLine0.y2());
	painter.drawLine(stLine1);
	QLine stLine3((stLine2.x1() + stLine4.x1()) /2, stLine0.y1(), (stLine2.x2() + stLine4.x2()) /2, stLine0.y2());
	painter.drawLine(stLine3);

	QStringList listValueLabel;
	if(dflYMax > 10.0){
		listValueLabel += QString::number(qRound(dflYMin), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMax *0.25 + dflYMin *0.75), 'f', 0);
		listValueLabel += QString::number(qRound((dflYMax + dflYMin) *0.5), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMax *0.75 + dflYMin *0.25), 'f', 0);
		listValueLabel += QString::number(qRound(dflYMax), 'f', 0);	
	}
	else{
		double dflBigStep = (dflYMax - dflYMin) /4.0;
		int iDec	=	(abs(dflBigStep *10.0 - qRound(dflBigStep*10.0)) > 0.1)?(2):(1);
		listValueLabel += QString::number(dflYMin, 'f', iDec);
		listValueLabel += QString::number(dflYMax *0.25 + dflYMin *0.75, 'f', iDec);
		listValueLabel += QString::number((dflYMax + dflYMin) *0.5, 'f', iDec);
		listValueLabel += QString::number(dflYMax *0.75 + dflYMin *0.25, 'f', iDec);
		listValueLabel += QString::number(dflYMax, 'f', iDec);		
	}

	stRect.setRect(stLine0.x1()-ciXTextFont *iXTextCount/4, 0, ciXTextFont *iXTextCount/2, stLine0.y2());
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[0]);
	stRect.setRect(stLine1.x1()-ciXTextFont *iXTextCount/4, 0, ciXTextFont *iXTextCount/2, stLine1.y2());
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[1]);
	stRect.setRect(stLine2.x1()-ciXTextFont *iXTextCount/4, 0, ciXTextFont *iXTextCount/2, stLine2.y2());
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[2]);
	stRect.setRect(stLine3.x1()-ciXTextFont *iXTextCount/4, 0, ciXTextFont *iXTextCount/2, stLine3.y2());
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[3]);
	stRect.setRect(stLine4.x1()-ciXTextFont *iXTextCount/4, 0, ciXTextFont *iXTextCount/2, stLine4.y2());
	painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter,  listValueLabel[4]);

	stLine.setLine(stLine0.x1() *0.25 + stLine1.x2()*0.75, stLine0.y1() -ciRulerShort, stLine0.x1() *0.25 + stLine1.x2()*0.75, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x1() *0.5 + stLine1.x2()*0.5, stLine0.y1() -ciRulerMiddle, stLine0.x1() *0.5 + stLine1.x2()*0.5, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine0.x1() *0.75 + stLine1.x2()*0.25, stLine0.y1() -ciRulerShort, stLine0.x1() *0.75 + stLine1.x2()*0.25, stLine0.y1());
	painter.drawLine(stLine);

	stLine.setLine(stLine1.x1() *0.25 + stLine2.x2()*0.75, stLine0.y1() -ciRulerShort, stLine1.x1() *0.25 + stLine2.x2()*0.75, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine1.x1() *0.5 + stLine2.x2()*0.5, stLine0.y1() -ciRulerMiddle, stLine1.x1() *0.5 + stLine2.x2()*0.5, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine1.x1() *0.75 + stLine2.x2()*0.25, stLine0.y1() -ciRulerShort, stLine1.x1() *0.75 + stLine2.x2()*0.25, stLine0.y1());
	painter.drawLine(stLine);

	stLine.setLine(stLine2.x1() *0.25 + stLine3.x2()*0.75, stLine0.y1() -ciRulerShort, stLine2.x1() *0.25 + stLine3.x2()*0.75, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine2.x1() *0.5 + stLine3.x2()*0.5, stLine0.y1() -ciRulerMiddle, stLine2.x1() *0.5 + stLine3.x2()*0.5, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine2.x1() *0.75 + stLine3.x2()*0.25, stLine0.y1() -ciRulerShort, stLine2.x1() *0.75 + stLine3.x2()*0.25, stLine0.y1());
	painter.drawLine(stLine);

	stLine.setLine(stLine3.x1() *0.25 + stLine4.x2()*0.75, stLine0.y1() -ciRulerShort, stLine3.x1() *0.25 + stLine4.x2()*0.75, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine3.x1() *0.5 + stLine4.x2()*0.5, stLine0.y1() -ciRulerMiddle, stLine3.x1() *0.5 + stLine4.x2()*0.5, stLine0.y1());
	painter.drawLine(stLine);
	stLine.setLine(stLine3.x1() *0.75 + stLine4.x2()*0.25, stLine0.y1() -ciRulerShort, stLine3.x1() *0.75 + stLine4.x2()*0.25, stLine0.y1());
	painter.drawLine(stLine);

	pixCanvas	=	pixCaintor;
	canvasRect	=	stCanvasRect;
	dflRulerMin	=	dflYMin;
	dflRulerMax	=	dflYMax;
	strLabelX		=	listLabel;
	iGroupCount	=	iGoupe;
	iItemCount		=	vecItem.size();
}

void QHInfoPanel::drawBarChartSlefHorizontal(QPixmap& pixImage, QVector<_HBarChart_SelfItem>& vecItem, double& dflYMin, double& dflYMax)
{
	const int ciBarGap = 1, ciBarMargin = 2, ciGroupGap = 6, ciBarWidth = 40, ciBarHeight = 140;
	const int ciValueTextFont = 7, ciValueTextGap = 1, ciValueTextCount = 5;

	int iGoupe		=	0;
	QVector<_HBarChart_SelfItem>::iterator theiterator;
	for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
		iGoupe	=	max(iGoupe, theiterator->uiGroupIndex);
		switch (theiterator->uiColorIndex){ //0-red 1:green 2:yellow 3:blue 4:cyan 5:purple
		case 0: if(redSample.isNull()) redSample.load(":/Resources/bar_red.png", "PNG");  
			if(redSample.height() >redSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				redSample	=	redSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		case 1: if(greenSample.isNull()) greenSample.load(":/Resources/bar_green.png", "PNG"); 
			if(greenSample.height() >greenSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				greenSample	=	greenSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		case 2: if(yellowSample.isNull()) yellowSample.load(":/Resources/bar_yellow.PNG", "PNG"); 
			if(yellowSample.height() >yellowSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				yellowSample	=	yellowSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		case 3: if(blueSample.isNull()) blueSample.load(":/Resources/bar_blue.png", "PNG"); 
			if(blueSample.height() >blueSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				blueSample	=	blueSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		case 4: if(cyanSample.isNull()) cyanSample.load(":/Resources/bar_cyan.PNG", "PNG"); 
			if(cyanSample.height() >cyanSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				cyanSample	=	cyanSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		default: if(purpleSample.isNull()) purpleSample.load(":/Resources/bar_purple.PNG", "PNG"); 
			if(purpleSample.height() >purpleSample.width()){
				QMatrix rotationMatrix(0, 1, -1, 0, 0, 0);
				purpleSample	=	purpleSample.transformed(rotationMatrix, Qt::FastTransformation);
			} 
			break;
		}
	}
	++iGoupe;

	QPainter painter(&pixImage);
	QPen pen	=	painter.pen();
	pen.setWidth(2);
	pen.setColor(QColor::fromRgb(0,0,0));
	pen.setStyle(Qt::DotLine);
	painter.setPen(pen);
	QFont font	=	painter.font();
	font.setPixelSize(ciValueTextFont);
	font.setFamily("Arial");
	painter.setFont(font);
	QImage* pstBar;

	QRect stRect(canvasRect.left(), canvasRect.top()+ciBarMargin, ciBarHeight, ciBarWidth);
	QLine stLine;
	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x || theiterator->flValue > dflYMax || theiterator->flValue < dflYMin) continue;
			switch (theiterator->uiColorIndex){ //0-red 1:green 2:yellow 3:blue 4:cyan 5:purple
			case 0: pstBar = &redSample; break;
			case 1: pstBar = &greenSample; break;
			case 2: pstBar = &yellowSample; break;
			case 3: pstBar = &blueSample; break;
			case 4: pstBar = &cyanSample; break;
			default: pstBar = &purpleSample; break;
			}
			stRect.setRight(stRect.left() + qRound((theiterator->flValue-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5) -1);
			painter.drawImage(stRect, *pstBar);
			if(theiterator->flDotLine >dflYMin && theiterator->flDotLine < dflYMax){
				int itemp	=	stRect.left() + qRound((theiterator->flDotLine-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5) -1;
				stLine.setLine(itemp, stRect.top(), itemp, stRect.bottom());
				painter.drawLine(stLine);
			}
			stRect.moveTop(stRect.top() + ciBarWidth+ciBarGap);
		}
		stRect.moveTop(stRect.top() + ciGroupGap-ciBarGap);
	}

	pen.setWidth(1);
	painter.setPen(pen);
	stRect.setRect(canvasRect.left(), canvasRect.top()+ciBarMargin, ciValueTextFont*ciValueTextCount/2 + ciValueTextGap *2, ciBarWidth);
	for(int x=0;	x<iGoupe;	++x){
		for(theiterator = vecItem.begin(); theiterator != vecItem.end(); theiterator++){
			if(theiterator->uiGroupIndex != x || theiterator->flValue > dflYMax || theiterator->flValue < dflYMin) continue;
			stRect.moveLeft(canvasRect.left() + qRound((theiterator->flValue-dflYMin) /(dflYMax-dflYMin) *ciBarHeight +0.5)  +1);
			painter.drawText(stRect, Qt::AlignHCenter | Qt::AlignVCenter, QString::number(theiterator->flValue, 'f', (theiterator->flValue > 1.0f)?(0):(3)));
			stRect.moveTop(stRect.top() + ciBarWidth+ciBarGap);
		}
		stRect.moveTop(stRect.top() + ciGroupGap-ciBarGap);
	}
}

