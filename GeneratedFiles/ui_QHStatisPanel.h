/********************************************************************************
** Form generated from reading UI file 'QHStatisPanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHSTATISPANEL_H
#define UI_QHSTATISPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHStatisPanel
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *statisticsinfolabel;

    void setupUi(QDockWidget *QHStatisPanel)
    {
        if (QHStatisPanel->objectName().isEmpty())
            QHStatisPanel->setObjectName(QString::fromUtf8("QHStatisPanel"));
        QHStatisPanel->resize(175, 376);
        QHStatisPanel->setMinimumSize(QSize(82, 82));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHStatisPanel->setFont(font);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        statisticsinfolabel = new QLabel(widget);
        statisticsinfolabel->setObjectName(QString::fromUtf8("statisticsinfolabel"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statisticsinfolabel->sizePolicy().hasHeightForWidth());
        statisticsinfolabel->setSizePolicy(sizePolicy);
        statisticsinfolabel->setMinimumSize(QSize(0, 0));
        statisticsinfolabel->setMaximumSize(QSize(10000, 20000));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        statisticsinfolabel->setFont(font1);
        statisticsinfolabel->setContextMenuPolicy(Qt::CustomContextMenu);
        statisticsinfolabel->setFrameShape(QFrame::StyledPanel);
        statisticsinfolabel->setFrameShadow(QFrame::Sunken);
        statisticsinfolabel->setTextFormat(Qt::PlainText);
        statisticsinfolabel->setScaledContents(true);
        statisticsinfolabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        statisticsinfolabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(statisticsinfolabel);

        QHStatisPanel->setWidget(widget);

        retranslateUi(QHStatisPanel);

        QMetaObject::connectSlotsByName(QHStatisPanel);
    } // setupUi

    void retranslateUi(QDockWidget *QHStatisPanel)
    {
        QHStatisPanel->setWindowTitle(QApplication::translate("QHStatisPanel", "Statis Panel", 0, QApplication::UnicodeUTF8));
        statisticsinfolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHStatisPanel: public Ui_QHStatisPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHSTATISPANEL_H
