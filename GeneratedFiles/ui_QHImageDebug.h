/********************************************************************************
** Form generated from reading UI file 'QHImageDebug.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHIMAGEDEBUG_H
#define UI_QHIMAGEDEBUG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHImageDebug
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *dvpPhaseShiftcomboBox;
    QPushButton *phaseShiftpushButton;
    QLabel *fpgaDecodeInfolabel;
    QLabel *infolabel;

    void setupUi(QDockWidget *QHImageDebug)
    {
        if (QHImageDebug->objectName().isEmpty())
            QHImageDebug->setObjectName(QString::fromUtf8("QHImageDebug"));
        QHImageDebug->resize(406, 259);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHImageDebug->setFont(font);
        QHImageDebug->setFloating(true);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dvpPhaseShiftcomboBox = new QComboBox(widget);
        dvpPhaseShiftcomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("0")
         << QString::fromUtf8("90")
         << QString::fromUtf8("180")
         << QString::fromUtf8("270")
        );
        dvpPhaseShiftcomboBox->setObjectName(QString::fromUtf8("dvpPhaseShiftcomboBox"));

        horizontalLayout->addWidget(dvpPhaseShiftcomboBox);

        phaseShiftpushButton = new QPushButton(widget);
        phaseShiftpushButton->setObjectName(QString::fromUtf8("phaseShiftpushButton"));

        horizontalLayout->addWidget(phaseShiftpushButton);


        verticalLayout->addLayout(horizontalLayout);

        fpgaDecodeInfolabel = new QLabel(widget);
        fpgaDecodeInfolabel->setObjectName(QString::fromUtf8("fpgaDecodeInfolabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fpgaDecodeInfolabel->sizePolicy().hasHeightForWidth());
        fpgaDecodeInfolabel->setSizePolicy(sizePolicy);
        fpgaDecodeInfolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(fpgaDecodeInfolabel);

        infolabel = new QLabel(widget);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infolabel->sizePolicy().hasHeightForWidth());
        infolabel->setSizePolicy(sizePolicy1);
        infolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(infolabel);

        QHImageDebug->setWidget(widget);

        retranslateUi(QHImageDebug);

        QMetaObject::connectSlotsByName(QHImageDebug);
    } // setupUi

    void retranslateUi(QDockWidget *QHImageDebug)
    {
        QHImageDebug->setWindowTitle(QApplication::translate("QHImageDebug", "QHImageDebug", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QHImageDebug", "DVP PCLK Phase Shift(Dec):", 0, QApplication::UnicodeUTF8));
        phaseShiftpushButton->setText(QApplication::translate("QHImageDebug", "Set", 0, QApplication::UnicodeUTF8));
        fpgaDecodeInfolabel->setText(QString());
        infolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHImageDebug: public Ui_QHImageDebug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHIMAGEDEBUG_H
