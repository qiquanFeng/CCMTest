/********************************************************************************
** Form generated from reading UI file 'QHTextInfoPanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHTEXTINFOPANEL_H
#define UI_QHTEXTINFOPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHTextInfoPanel
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listinfowidge;

    void setupUi(QDockWidget *QHTextInfoPanel)
    {
        if (QHTextInfoPanel->objectName().isEmpty())
            QHTextInfoPanel->setObjectName(QString::fromUtf8("QHTextInfoPanel"));
        QHTextInfoPanel->resize(217, 390);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        QHTextInfoPanel->setFont(font);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listinfowidge = new QListWidget(widget);
        listinfowidge->setObjectName(QString::fromUtf8("listinfowidge"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listinfowidge->sizePolicy().hasHeightForWidth());
        listinfowidge->setSizePolicy(sizePolicy);
        listinfowidge->setMinimumSize(QSize(100, 80));
        listinfowidge->setMaximumSize(QSize(10000, 10000));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        listinfowidge->setFont(font1);
        listinfowidge->setContextMenuPolicy(Qt::CustomContextMenu);
        listinfowidge->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listinfowidge->setSelectionMode(QAbstractItemView::ContiguousSelection);

        verticalLayout->addWidget(listinfowidge);

        QHTextInfoPanel->setWidget(widget);

        retranslateUi(QHTextInfoPanel);

        QMetaObject::connectSlotsByName(QHTextInfoPanel);
    } // setupUi

    void retranslateUi(QDockWidget *QHTextInfoPanel)
    {
        QHTextInfoPanel->setWindowTitle(QApplication::translate("QHTextInfoPanel", "Text Panel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHTextInfoPanel: public Ui_QHTextInfoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHTEXTINFOPANEL_H
