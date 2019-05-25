/********************************************************************************
** Form generated from reading UI file 'qitemexetool.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QITEMEXETOOL_H
#define UI_QITEMEXETOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qitemexetool
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDockWidget *qitemexetool)
    {
        if (qitemexetool->objectName().isEmpty())
            qitemexetool->setObjectName(QString::fromUtf8("qitemexetool"));
        qitemexetool->resize(273, 608);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        qitemexetool->setFont(font);
        qitemexetool->setFloating(true);
        qitemexetool->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 236, 530));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        qitemexetool->setWidget(widget);

        retranslateUi(qitemexetool);

        QMetaObject::connectSlotsByName(qitemexetool);
    } // setupUi

    void retranslateUi(QDockWidget *qitemexetool)
    {
        qitemexetool->setWindowTitle(QApplication::translate("qitemexetool", "qitemexetool", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qitemexetool: public Ui_qitemexetool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QITEMEXETOOL_H
