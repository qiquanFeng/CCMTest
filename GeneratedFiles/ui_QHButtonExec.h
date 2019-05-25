/********************************************************************************
** Form generated from reading UI file 'QHButtonExec.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHBUTTONEXEC_H
#define UI_QHBUTTONEXEC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHButtonExec
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *seriallineEdit;
    QLabel *resultlabel;
    QPushButton *execpushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *focusAdjustpushButton;
    QPushButton *whitePanelpushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *farFCpushButton;
    QPushButton *nearFCpushButton;

    void setupUi(QDockWidget *QHButtonExec)
    {
        if (QHButtonExec->objectName().isEmpty())
            QHButtonExec->setObjectName(QString::fromUtf8("QHButtonExec"));
        QHButtonExec->resize(208, 319);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        QHButtonExec->setFont(font);
        QHButtonExec->setFloating(false);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        seriallineEdit = new QLineEdit(widget);
        seriallineEdit->setObjectName(QString::fromUtf8("seriallineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(seriallineEdit->sizePolicy().hasHeightForWidth());
        seriallineEdit->setSizePolicy(sizePolicy);
        seriallineEdit->setMinimumSize(QSize(40, 30));
        seriallineEdit->setMaximumSize(QSize(400, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        seriallineEdit->setFont(font1);
        seriallineEdit->setAcceptDrops(false);
        seriallineEdit->setFrame(true);

        verticalLayout->addWidget(seriallineEdit);

        resultlabel = new QLabel(widget);
        resultlabel->setObjectName(QString::fromUtf8("resultlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resultlabel->sizePolicy().hasHeightForWidth());
        resultlabel->setSizePolicy(sizePolicy1);
        resultlabel->setMinimumSize(QSize(40, 30));
        resultlabel->setMaximumSize(QSize(400, 300));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(10);
        resultlabel->setFont(font2);
        resultlabel->setContextMenuPolicy(Qt::NoContextMenu);
        resultlabel->setFrameShape(QFrame::StyledPanel);
        resultlabel->setFrameShadow(QFrame::Sunken);
        resultlabel->setTextFormat(Qt::PlainText);
        resultlabel->setScaledContents(true);
        resultlabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(resultlabel);

        execpushButton = new QPushButton(widget);
        execpushButton->setObjectName(QString::fromUtf8("execpushButton"));
        sizePolicy1.setHeightForWidth(execpushButton->sizePolicy().hasHeightForWidth());
        execpushButton->setSizePolicy(sizePolicy1);
        execpushButton->setMinimumSize(QSize(40, 30));
        execpushButton->setMaximumSize(QSize(400, 100));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font3.setPointSize(28);
        font3.setBold(true);
        font3.setWeight(75);
        execpushButton->setFont(font3);
        execpushButton->setContextMenuPolicy(Qt::NoContextMenu);
        execpushButton->setAutoDefault(false);
        execpushButton->setDefault(true);
        execpushButton->setFlat(false);

        verticalLayout->addWidget(execpushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        focusAdjustpushButton = new QPushButton(widget);
        focusAdjustpushButton->setObjectName(QString::fromUtf8("focusAdjustpushButton"));
        sizePolicy1.setHeightForWidth(focusAdjustpushButton->sizePolicy().hasHeightForWidth());
        focusAdjustpushButton->setSizePolicy(sizePolicy1);
        focusAdjustpushButton->setMaximumSize(QSize(16777215, 60));
        QFont font4;
        font4.setPointSize(11);
        focusAdjustpushButton->setFont(font4);

        horizontalLayout->addWidget(focusAdjustpushButton);

        whitePanelpushButton = new QPushButton(widget);
        whitePanelpushButton->setObjectName(QString::fromUtf8("whitePanelpushButton"));
        sizePolicy1.setHeightForWidth(whitePanelpushButton->sizePolicy().hasHeightForWidth());
        whitePanelpushButton->setSizePolicy(sizePolicy1);
        whitePanelpushButton->setMaximumSize(QSize(16777215, 60));
        whitePanelpushButton->setFont(font4);

        horizontalLayout->addWidget(whitePanelpushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        farFCpushButton = new QPushButton(widget);
        farFCpushButton->setObjectName(QString::fromUtf8("farFCpushButton"));
        sizePolicy1.setHeightForWidth(farFCpushButton->sizePolicy().hasHeightForWidth());
        farFCpushButton->setSizePolicy(sizePolicy1);
        farFCpushButton->setMaximumSize(QSize(16777215, 60));
        farFCpushButton->setFont(font4);

        horizontalLayout_2->addWidget(farFCpushButton);

        nearFCpushButton = new QPushButton(widget);
        nearFCpushButton->setObjectName(QString::fromUtf8("nearFCpushButton"));
        sizePolicy1.setHeightForWidth(nearFCpushButton->sizePolicy().hasHeightForWidth());
        nearFCpushButton->setSizePolicy(sizePolicy1);
        nearFCpushButton->setMaximumSize(QSize(16777215, 60));
        nearFCpushButton->setFont(font4);

        horizontalLayout_2->addWidget(nearFCpushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        QHButtonExec->setWidget(widget);

        retranslateUi(QHButtonExec);

        QMetaObject::connectSlotsByName(QHButtonExec);
    } // setupUi

    void retranslateUi(QDockWidget *QHButtonExec)
    {
        QHButtonExec->setWindowTitle(QApplication::translate("QHButtonExec", "Operation Panel", 0, QApplication::UnicodeUTF8));
        seriallineEdit->setText(QString());
        resultlabel->setText(QString());
        execpushButton->setText(QApplication::translate("QHButtonExec", "START", 0, QApplication::UnicodeUTF8));
        focusAdjustpushButton->setText(QApplication::translate("QHButtonExec", "FA", 0, QApplication::UnicodeUTF8));
        whitePanelpushButton->setText(QApplication::translate("QHButtonExec", "White Field", 0, QApplication::UnicodeUTF8));
        farFCpushButton->setText(QApplication::translate("QHButtonExec", "Far FC", 0, QApplication::UnicodeUTF8));
        nearFCpushButton->setText(QApplication::translate("QHButtonExec", "Near FC", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHButtonExec: public Ui_QHButtonExec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHBUTTONEXEC_H
