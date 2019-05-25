/********************************************************************************
** Form generated from reading UI file 'QHManualModeA.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHMANUALMODEA_H
#define UI_QHMANUALMODEA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHManualModeA
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QComboBox *scenecomboBox;
    QLabel *label_10;
    QSpinBox *delayspinBox;
    QPushButton *savepushButton;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *blemishcheckBox;
    QCheckBox *occheckBox;
    QCheckBox *defectPixelcheckBox;
    QCheckBox *colorcheckBox;
    QCheckBox *shadingcheckBox;
    QCheckBox *vignettingcheckBox;
    QCheckBox *linecheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QSlider *exposureTimehorizontalSlider;
    QSpinBox *exposurespinBox;
    QPushButton *exposurepushButton;
    QLabel *infolabel;

    void setupUi(QDialog *QHManualModeA)
    {
        if (QHManualModeA->objectName().isEmpty())
            QHManualModeA->setObjectName(QString::fromUtf8("QHManualModeA"));
        QHManualModeA->resize(640, 156);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHManualModeA->setFont(font);
        verticalLayout = new QVBoxLayout(QHManualModeA);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_14 = new QLabel(QHManualModeA);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_2->addWidget(label_14);

        scenecomboBox = new QComboBox(QHManualModeA);
        scenecomboBox->setObjectName(QString::fromUtf8("scenecomboBox"));

        horizontalLayout_2->addWidget(scenecomboBox);

        label_10 = new QLabel(QHManualModeA);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        delayspinBox = new QSpinBox(QHManualModeA);
        delayspinBox->setObjectName(QString::fromUtf8("delayspinBox"));
        delayspinBox->setMinimum(1);
        delayspinBox->setMaximum(65535);
        delayspinBox->setValue(500);

        horizontalLayout_2->addWidget(delayspinBox);


        horizontalLayout->addLayout(horizontalLayout_2);

        savepushButton = new QPushButton(QHManualModeA);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(savepushButton->sizePolicy().hasHeightForWidth());
        savepushButton->setSizePolicy(sizePolicy);
        savepushButton->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(18);
        savepushButton->setFont(font1);

        horizontalLayout->addWidget(savepushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        blemishcheckBox = new QCheckBox(QHManualModeA);
        blemishcheckBox->setObjectName(QString::fromUtf8("blemishcheckBox"));
        blemishcheckBox->setChecked(true);

        horizontalLayout_4->addWidget(blemishcheckBox);

        occheckBox = new QCheckBox(QHManualModeA);
        occheckBox->setObjectName(QString::fromUtf8("occheckBox"));

        horizontalLayout_4->addWidget(occheckBox);

        defectPixelcheckBox = new QCheckBox(QHManualModeA);
        defectPixelcheckBox->setObjectName(QString::fromUtf8("defectPixelcheckBox"));

        horizontalLayout_4->addWidget(defectPixelcheckBox);

        colorcheckBox = new QCheckBox(QHManualModeA);
        colorcheckBox->setObjectName(QString::fromUtf8("colorcheckBox"));

        horizontalLayout_4->addWidget(colorcheckBox);

        shadingcheckBox = new QCheckBox(QHManualModeA);
        shadingcheckBox->setObjectName(QString::fromUtf8("shadingcheckBox"));
        shadingcheckBox->setText(QString::fromUtf8("Shading"));

        horizontalLayout_4->addWidget(shadingcheckBox);

        vignettingcheckBox = new QCheckBox(QHManualModeA);
        vignettingcheckBox->setObjectName(QString::fromUtf8("vignettingcheckBox"));
        vignettingcheckBox->setText(QString::fromUtf8("Vignet"));

        horizontalLayout_4->addWidget(vignettingcheckBox);

        linecheckBox = new QCheckBox(QHManualModeA);
        linecheckBox->setObjectName(QString::fromUtf8("linecheckBox"));

        horizontalLayout_4->addWidget(linecheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_15 = new QLabel(QHManualModeA);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(70, 0));
        label_15->setMaximumSize(QSize(70, 16777215));
        label_15->setFont(font);

        horizontalLayout_3->addWidget(label_15);

        exposureTimehorizontalSlider = new QSlider(QHManualModeA);
        exposureTimehorizontalSlider->setObjectName(QString::fromUtf8("exposureTimehorizontalSlider"));
        exposureTimehorizontalSlider->setOrientation(Qt::Horizontal);
        exposureTimehorizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(exposureTimehorizontalSlider);

        exposurespinBox = new QSpinBox(QHManualModeA);
        exposurespinBox->setObjectName(QString::fromUtf8("exposurespinBox"));
        exposurespinBox->setMinimumSize(QSize(52, 0));
        exposurespinBox->setMaximumSize(QSize(52, 16777215));
        exposurespinBox->setMaximum(999999);

        horizontalLayout_3->addWidget(exposurespinBox);

        exposurepushButton = new QPushButton(QHManualModeA);
        exposurepushButton->setObjectName(QString::fromUtf8("exposurepushButton"));
        sizePolicy.setHeightForWidth(exposurepushButton->sizePolicy().hasHeightForWidth());
        exposurepushButton->setSizePolicy(sizePolicy);
        exposurepushButton->setMinimumSize(QSize(40, 0));
        exposurepushButton->setMaximumSize(QSize(40, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        exposurepushButton->setFont(font2);

        horizontalLayout_3->addWidget(exposurepushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        infolabel = new QLabel(QHManualModeA);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        infolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(infolabel);


        retranslateUi(QHManualModeA);

        QMetaObject::connectSlotsByName(QHManualModeA);
    } // setupUi

    void retranslateUi(QDialog *QHManualModeA)
    {
        QHManualModeA->setWindowTitle(QApplication::translate("QHManualModeA", "Manual Mode-A Config", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QHManualModeA", "Scene:", 0, QApplication::UnicodeUTF8));
        scenecomboBox->clear();
        scenecomboBox->insertItems(0, QStringList()
         << QApplication::translate("QHManualModeA", "FA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHManualModeA", "Near FC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHManualModeA", "Far FC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHManualModeA", "White Field", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("QHManualModeA", "Delay Time:", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("QHManualModeA", "SAVE", 0, QApplication::UnicodeUTF8));
        blemishcheckBox->setText(QApplication::translate("QHManualModeA", "Blemish", 0, QApplication::UnicodeUTF8));
        occheckBox->setText(QApplication::translate("QHManualModeA", "OC", 0, QApplication::UnicodeUTF8));
        defectPixelcheckBox->setText(QApplication::translate("QHManualModeA", "Defect Pixel", 0, QApplication::UnicodeUTF8));
        colorcheckBox->setText(QApplication::translate("QHManualModeA", "Color", 0, QApplication::UnicodeUTF8));
        linecheckBox->setText(QApplication::translate("QHManualModeA", "Line", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QHManualModeA", "Exposure:", 0, QApplication::UnicodeUTF8));
        exposurepushButton->setText(QApplication::translate("QHManualModeA", "Set", 0, QApplication::UnicodeUTF8));
        infolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHManualModeA: public Ui_QHManualModeA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHMANUALMODEA_H
