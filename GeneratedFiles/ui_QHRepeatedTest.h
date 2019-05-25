/********************************************************************************
** Form generated from reading UI file 'QHRepeatedTest.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHREPEATEDTEST_H
#define UI_QHREPEATEDTEST_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHRepeatedTest
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *shortcutcomboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *timesspinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *testpushButton;
    QPushButton *stoppushButton;
    QLabel *infolabel;

    void setupUi(QDockWidget *QHRepeatedTest)
    {
        if (QHRepeatedTest->objectName().isEmpty())
            QHRepeatedTest->setObjectName(QString::fromUtf8("QHRepeatedTest"));
        QHRepeatedTest->resize(400, 211);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        QHRepeatedTest->setFont(font);
        QHRepeatedTest->setFloating(true);
        QHRepeatedTest->setAllowedAreas(Qt::NoDockWidgetArea);
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

        shortcutcomboBox = new QComboBox(widget);
        shortcutcomboBox->addItem(QString());
        shortcutcomboBox->addItem(QString::fromUtf8("0"));
        shortcutcomboBox->addItem(QString::fromUtf8("1"));
        shortcutcomboBox->addItem(QString::fromUtf8("2"));
        shortcutcomboBox->addItem(QString::fromUtf8("3"));
        shortcutcomboBox->addItem(QString::fromUtf8("4"));
        shortcutcomboBox->addItem(QString::fromUtf8("5"));
        shortcutcomboBox->addItem(QString::fromUtf8("6"));
        shortcutcomboBox->addItem(QString::fromUtf8("7"));
        shortcutcomboBox->addItem(QString::fromUtf8("8"));
        shortcutcomboBox->addItem(QString::fromUtf8("9"));
        shortcutcomboBox->addItem(QString::fromUtf8("A"));
        shortcutcomboBox->addItem(QString::fromUtf8("B"));
        shortcutcomboBox->addItem(QString::fromUtf8("C"));
        shortcutcomboBox->addItem(QString::fromUtf8("D"));
        shortcutcomboBox->addItem(QString::fromUtf8("E"));
        shortcutcomboBox->addItem(QString::fromUtf8("F"));
        shortcutcomboBox->addItem(QString::fromUtf8("G"));
        shortcutcomboBox->addItem(QString::fromUtf8("H"));
        shortcutcomboBox->addItem(QString::fromUtf8("I"));
        shortcutcomboBox->addItem(QString::fromUtf8("J"));
        shortcutcomboBox->addItem(QString::fromUtf8("K"));
        shortcutcomboBox->addItem(QString::fromUtf8("L"));
        shortcutcomboBox->addItem(QString::fromUtf8("M"));
        shortcutcomboBox->addItem(QString::fromUtf8("N"));
        shortcutcomboBox->addItem(QString::fromUtf8("O"));
        shortcutcomboBox->addItem(QString::fromUtf8("P"));
        shortcutcomboBox->addItem(QString::fromUtf8("Q"));
        shortcutcomboBox->addItem(QString::fromUtf8("R"));
        shortcutcomboBox->addItem(QString::fromUtf8("S"));
        shortcutcomboBox->addItem(QString::fromUtf8("T"));
        shortcutcomboBox->addItem(QString::fromUtf8("U"));
        shortcutcomboBox->addItem(QString::fromUtf8("V"));
        shortcutcomboBox->addItem(QString::fromUtf8("W"));
        shortcutcomboBox->addItem(QString::fromUtf8("X"));
        shortcutcomboBox->addItem(QString::fromUtf8("Y"));
        shortcutcomboBox->addItem(QString::fromUtf8("Z"));
        shortcutcomboBox->setObjectName(QString::fromUtf8("shortcutcomboBox"));

        horizontalLayout->addWidget(shortcutcomboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        timesspinBox = new QSpinBox(widget);
        timesspinBox->setObjectName(QString::fromUtf8("timesspinBox"));
        timesspinBox->setSuffix(QString::fromUtf8(""));
        timesspinBox->setPrefix(QString::fromUtf8(""));
        timesspinBox->setMinimum(1);
        timesspinBox->setMaximum(2147483647);
        timesspinBox->setValue(10000);

        horizontalLayout_2->addWidget(timesspinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        testpushButton = new QPushButton(widget);
        testpushButton->setObjectName(QString::fromUtf8("testpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(testpushButton->sizePolicy().hasHeightForWidth());
        testpushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(testpushButton);

        stoppushButton = new QPushButton(widget);
        stoppushButton->setObjectName(QString::fromUtf8("stoppushButton"));
        sizePolicy.setHeightForWidth(stoppushButton->sizePolicy().hasHeightForWidth());
        stoppushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(stoppushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        infolabel = new QLabel(widget);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infolabel->sizePolicy().hasHeightForWidth());
        infolabel->setSizePolicy(sizePolicy1);
        infolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(infolabel);

        QHRepeatedTest->setWidget(widget);

        retranslateUi(QHRepeatedTest);

        QMetaObject::connectSlotsByName(QHRepeatedTest);
    } // setupUi

    void retranslateUi(QDockWidget *QHRepeatedTest)
    {
        QHRepeatedTest->setWindowTitle(QApplication::translate("QHRepeatedTest", "Repeated Test", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QHRepeatedTest", "Shortcut:", 0, QApplication::UnicodeUTF8));
        shortcutcomboBox->setItemText(0, QApplication::translate("QHRepeatedTest", "Button", 0, QApplication::UnicodeUTF8));

        label_2->setText(QApplication::translate("QHRepeatedTest", "Repeated Times:", 0, QApplication::UnicodeUTF8));
        testpushButton->setText(QApplication::translate("QHRepeatedTest", "TEST", 0, QApplication::UnicodeUTF8));
        stoppushButton->setText(QApplication::translate("QHRepeatedTest", "STOP", 0, QApplication::UnicodeUTF8));
        infolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHRepeatedTest: public Ui_QHRepeatedTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHREPEATEDTEST_H
