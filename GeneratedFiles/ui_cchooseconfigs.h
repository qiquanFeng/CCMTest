/********************************************************************************
** Form generated from reading UI file 'cchooseconfigs.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCHOOSECONFIGS_H
#define UI_CCHOOSECONFIGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cchooseconfigs
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *allradioButton;
    QRadioButton *ovradioButton;
    QRadioButton *sonyradioButton;
    QRadioButton *sansungradioButton;
    QRadioButton *hynixradioButton;
    QRadioButton *otherradioButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *selectlineEdit;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QDialog *cchooseconfigs)
    {
        if (cchooseconfigs->objectName().isEmpty())
            cchooseconfigs->setObjectName(QString::fromUtf8("cchooseconfigs"));
        cchooseconfigs->setWindowModality(Qt::NonModal);
        cchooseconfigs->resize(523, 219);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(false);
        font.setWeight(50);
        cchooseconfigs->setFont(font);
        verticalLayout = new QVBoxLayout(cchooseconfigs);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(cchooseconfigs);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        allradioButton = new QRadioButton(groupBox);
        allradioButton->setObjectName(QString::fromUtf8("allradioButton"));
        allradioButton->setChecked(true);

        horizontalLayout_2->addWidget(allradioButton);

        ovradioButton = new QRadioButton(groupBox);
        ovradioButton->setObjectName(QString::fromUtf8("ovradioButton"));

        horizontalLayout_2->addWidget(ovradioButton);

        sonyradioButton = new QRadioButton(groupBox);
        sonyradioButton->setObjectName(QString::fromUtf8("sonyradioButton"));

        horizontalLayout_2->addWidget(sonyradioButton);

        sansungradioButton = new QRadioButton(groupBox);
        sansungradioButton->setObjectName(QString::fromUtf8("sansungradioButton"));

        horizontalLayout_2->addWidget(sansungradioButton);

        hynixradioButton = new QRadioButton(groupBox);
        hynixradioButton->setObjectName(QString::fromUtf8("hynixradioButton"));

        horizontalLayout_2->addWidget(hynixradioButton);

        otherradioButton = new QRadioButton(groupBox);
        otherradioButton->setObjectName(QString::fromUtf8("otherradioButton"));

        horizontalLayout_2->addWidget(otherradioButton);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        selectlineEdit = new QLineEdit(cchooseconfigs);
        selectlineEdit->setObjectName(QString::fromUtf8("selectlineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectlineEdit->sizePolicy().hasHeightForWidth());
        selectlineEdit->setSizePolicy(sizePolicy);
        selectlineEdit->setMaximumSize(QSize(80, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        selectlineEdit->setFont(font2);
        selectlineEdit->setInputMask(QString::fromUtf8(""));
        selectlineEdit->setText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(selectlineEdit);

        comboBox = new QComboBox(cchooseconfigs);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        comboBox->setFont(font3);
        comboBox->setEditable(false);

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(cchooseconfigs);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);
        okButton->setMinimumSize(QSize(150, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft PhagsPa"));
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        okButton->setFont(font4);

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(cchooseconfigs);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setMinimumSize(QSize(170, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft PhagsPa"));
        font5.setPointSize(26);
        font5.setBold(true);
        font5.setWeight(75);
        cancelButton->setFont(font5);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(cchooseconfigs);

        QMetaObject::connectSlotsByName(cchooseconfigs);
    } // setupUi

    void retranslateUi(QDialog *cchooseconfigs)
    {
        cchooseconfigs->setWindowTitle(QApplication::translate("cchooseconfigs", "Choose Config", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        allradioButton->setText(QApplication::translate("cchooseconfigs", "ALL", 0, QApplication::UnicodeUTF8));
        ovradioButton->setText(QApplication::translate("cchooseconfigs", "OV", 0, QApplication::UnicodeUTF8));
        sonyradioButton->setText(QApplication::translate("cchooseconfigs", "SONY", 0, QApplication::UnicodeUTF8));
        sansungradioButton->setText(QApplication::translate("cchooseconfigs", "SAMSUNG", 0, QApplication::UnicodeUTF8));
        hynixradioButton->setText(QApplication::translate("cchooseconfigs", "HYNIX", 0, QApplication::UnicodeUTF8));
        otherradioButton->setText(QApplication::translate("cchooseconfigs", "OTHER", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("cchooseconfigs", "SAVE", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("cchooseconfigs", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cchooseconfigs: public Ui_cchooseconfigs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCHOOSECONFIGS_H
