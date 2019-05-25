/********************************************************************************
** Form generated from reading UI file 'QHDrawTEstItem.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHDRAWTESTITEM_H
#define UI_QHDRAWTESTITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHDrawTEstItem
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *itemlabel;

    void setupUi(QDockWidget *QHDrawTEstItem)
    {
        if (QHDrawTEstItem->objectName().isEmpty())
            QHDrawTEstItem->setObjectName(QString::fromUtf8("QHDrawTEstItem"));
        QHDrawTEstItem->resize(116, 424);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHDrawTEstItem->setFont(font);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        itemlabel = new QLabel(widget);
        itemlabel->setObjectName(QString::fromUtf8("itemlabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(itemlabel->sizePolicy().hasHeightForWidth());
        itemlabel->setSizePolicy(sizePolicy);
        itemlabel->setMinimumSize(QSize(100, 400));
        itemlabel->setFont(font);
        itemlabel->setScaledContents(true);

        gridLayout->addWidget(itemlabel, 0, 0, 1, 1);

        QHDrawTEstItem->setWidget(widget);

        retranslateUi(QHDrawTEstItem);

        QMetaObject::connectSlotsByName(QHDrawTEstItem);
    } // setupUi

    void retranslateUi(QDockWidget *QHDrawTEstItem)
    {
        QHDrawTEstItem->setWindowTitle(QApplication::translate("QHDrawTEstItem", "Test Item Panel", 0, QApplication::UnicodeUTF8));
        itemlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHDrawTEstItem: public Ui_QHDrawTEstItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHDRAWTESTITEM_H
