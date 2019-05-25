/********************************************************************************
** Form generated from reading UI file 'QHFontSetting.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHFONTSETTING_H
#define UI_QHFONTSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHFontSetting
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *fiMTFSizespinBox;
    QCheckBox *fiMTFBoldcheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *fiSFRSizespinBox;
    QCheckBox *fiSFRBoldcheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *fiTVLineSizespinBox;
    QCheckBox *fiTVLineBoldcheckBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *fiOtherSizespinBox;
    QCheckBox *fiOtherBoldcheckBox;
    QPushButton *savepushButton;

    void setupUi(QDialog *QHFontSetting)
    {
        if (QHFontSetting->objectName().isEmpty())
            QHFontSetting->setObjectName(QString::fromUtf8("QHFontSetting"));
        QHFontSetting->resize(296, 252);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        QHFontSetting->setFont(font);
        verticalLayout_2 = new QVBoxLayout(QHFontSetting);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(QHFontSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setText(QString::fromUtf8("MTF"));

        horizontalLayout->addWidget(label);

        fiMTFSizespinBox = new QSpinBox(groupBox);
        fiMTFSizespinBox->setObjectName(QString::fromUtf8("fiMTFSizespinBox"));
        fiMTFSizespinBox->setMinimum(7);
        fiMTFSizespinBox->setMaximum(35);
        fiMTFSizespinBox->setValue(12);

        horizontalLayout->addWidget(fiMTFSizespinBox);

        fiMTFBoldcheckBox = new QCheckBox(groupBox);
        fiMTFBoldcheckBox->setObjectName(QString::fromUtf8("fiMTFBoldcheckBox"));
        fiMTFBoldcheckBox->setChecked(true);

        horizontalLayout->addWidget(fiMTFBoldcheckBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setText(QString::fromUtf8("SFR"));

        horizontalLayout_2->addWidget(label_2);

        fiSFRSizespinBox = new QSpinBox(groupBox);
        fiSFRSizespinBox->setObjectName(QString::fromUtf8("fiSFRSizespinBox"));
        fiSFRSizespinBox->setMinimum(7);
        fiSFRSizespinBox->setMaximum(35);
        fiSFRSizespinBox->setValue(12);

        horizontalLayout_2->addWidget(fiSFRSizespinBox);

        fiSFRBoldcheckBox = new QCheckBox(groupBox);
        fiSFRBoldcheckBox->setObjectName(QString::fromUtf8("fiSFRBoldcheckBox"));
        fiSFRBoldcheckBox->setChecked(true);

        horizontalLayout_2->addWidget(fiSFRBoldcheckBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setText(QString::fromUtf8("TV Line"));

        horizontalLayout_3->addWidget(label_3);

        fiTVLineSizespinBox = new QSpinBox(groupBox);
        fiTVLineSizespinBox->setObjectName(QString::fromUtf8("fiTVLineSizespinBox"));
        fiTVLineSizespinBox->setMinimum(7);
        fiTVLineSizespinBox->setMaximum(35);
        fiTVLineSizespinBox->setValue(12);

        horizontalLayout_3->addWidget(fiTVLineSizespinBox);

        fiTVLineBoldcheckBox = new QCheckBox(groupBox);
        fiTVLineBoldcheckBox->setObjectName(QString::fromUtf8("fiTVLineBoldcheckBox"));
        fiTVLineBoldcheckBox->setChecked(true);

        horizontalLayout_3->addWidget(fiTVLineBoldcheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        fiOtherSizespinBox = new QSpinBox(groupBox);
        fiOtherSizespinBox->setObjectName(QString::fromUtf8("fiOtherSizespinBox"));
        fiOtherSizespinBox->setMinimum(7);
        fiOtherSizespinBox->setMaximum(35);
        fiOtherSizespinBox->setValue(9);

        horizontalLayout_4->addWidget(fiOtherSizespinBox);

        fiOtherBoldcheckBox = new QCheckBox(groupBox);
        fiOtherBoldcheckBox->setObjectName(QString::fromUtf8("fiOtherBoldcheckBox"));

        horizontalLayout_4->addWidget(fiOtherBoldcheckBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        savepushButton = new QPushButton(QHFontSetting);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(savepushButton->sizePolicy().hasHeightForWidth());
        savepushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        savepushButton->setFont(font1);

        verticalLayout_2->addWidget(savepushButton);


        retranslateUi(QHFontSetting);

        QMetaObject::connectSlotsByName(QHFontSetting);
    } // setupUi

    void retranslateUi(QDialog *QHFontSetting)
    {
        QHFontSetting->setWindowTitle(QApplication::translate("QHFontSetting", "Font Setting", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QHFontSetting", "Font On Image", 0, QApplication::UnicodeUTF8));
        fiMTFBoldcheckBox->setText(QApplication::translate("QHFontSetting", "Bold", 0, QApplication::UnicodeUTF8));
        fiSFRBoldcheckBox->setText(QApplication::translate("QHFontSetting", "Bold", 0, QApplication::UnicodeUTF8));
        fiTVLineBoldcheckBox->setText(QApplication::translate("QHFontSetting", "Bold", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QHFontSetting", "Other", 0, QApplication::UnicodeUTF8));
        fiOtherBoldcheckBox->setText(QApplication::translate("QHFontSetting", "Bold", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("QHFontSetting", "SAVE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHFontSetting: public Ui_QHFontSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHFONTSETTING_H
