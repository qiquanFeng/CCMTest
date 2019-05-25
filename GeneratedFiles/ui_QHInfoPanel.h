/********************************************************************************
** Form generated from reading UI file 'QHInfoPanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHINFOPANEL_H
#define UI_QHINFOPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_QHInfoPanel
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QwtPlot *drawcurveqwtPlot;
    QLabel *drawinfolabel;

    void setupUi(QDockWidget *QHInfoPanel)
    {
        if (QHInfoPanel->objectName().isEmpty())
            QHInfoPanel->setObjectName(QString::fromUtf8("QHInfoPanel"));
        QHInfoPanel->resize(258, 465);
        QHInfoPanel->setMinimumSize(QSize(82, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        QHInfoPanel->setFont(font);
        QHInfoPanel->setFloating(false);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        drawcurveqwtPlot = new QwtPlot(widget);
        drawcurveqwtPlot->setObjectName(QString::fromUtf8("drawcurveqwtPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(drawcurveqwtPlot->sizePolicy().hasHeightForWidth());
        drawcurveqwtPlot->setSizePolicy(sizePolicy);
        drawcurveqwtPlot->setFrameShape(QFrame::NoFrame);
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        drawcurveqwtPlot->setCanvasBackground(brush);

        verticalLayout->addWidget(drawcurveqwtPlot);

        drawinfolabel = new QLabel(widget);
        drawinfolabel->setObjectName(QString::fromUtf8("drawinfolabel"));
        sizePolicy.setHeightForWidth(drawinfolabel->sizePolicy().hasHeightForWidth());
        drawinfolabel->setSizePolicy(sizePolicy);
        drawinfolabel->setMinimumSize(QSize(0, 0));
        drawinfolabel->setMaximumSize(QSize(10000, 10000));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        drawinfolabel->setFont(font1);
        drawinfolabel->setContextMenuPolicy(Qt::NoContextMenu);
        drawinfolabel->setFrameShape(QFrame::StyledPanel);
        drawinfolabel->setFrameShadow(QFrame::Sunken);
        drawinfolabel->setTextFormat(Qt::PlainText);
        drawinfolabel->setScaledContents(true);
        drawinfolabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(drawinfolabel);

        QHInfoPanel->setWidget(widget);

        retranslateUi(QHInfoPanel);

        QMetaObject::connectSlotsByName(QHInfoPanel);
    } // setupUi

    void retranslateUi(QDockWidget *QHInfoPanel)
    {
        QHInfoPanel->setWindowTitle(QApplication::translate("QHInfoPanel", "Graph Panel", 0, QApplication::UnicodeUTF8));
        drawinfolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHInfoPanel: public Ui_QHInfoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHINFOPANEL_H
