/********************************************************************************
** Form generated from reading UI file 'QHOpModeSwitch.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHOPMODESWITCH_H
#define UI_QHOPMODESWITCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHOpModeSwitch
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *modecomboBox;
    QGroupBox *manualmodeAgroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *charttypeAlabel;
    QComboBox *chartTypecomboBox;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *saveLogcheckBox;
    QCheckBox *showTotalResultcheckBox;
    QGroupBox *manualmodeBgroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *charttypeBlabel;
    QComboBox *B_chartTypecomboBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Scenelabel;
    QComboBox *B_scenccomboBox;
    QGroupBox *HotPlugroupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *interfacelabel;
    QComboBox *B_PlugInterfacecomboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *PINlabel;
    QComboBox *B_Plug2ndNamecomboBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *rangelabel;
    QDoubleSpinBox *B_PlugMindoubleSpinBox;
    QLabel *wavelinelabel;
    QDoubleSpinBox *B_PlugMaxdoubleSpinBox;
    QGroupBox *ipsetgroupBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *localradioButton;
    QHBoxLayout *horizontalLayout;
    QRadioButton *ipV4radioButton;
    QLineEdit *ipv4lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *portspinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okpushButton;
    QPushButton *cancelpushButton;

    void setupUi(QDialog *QHOpModeSwitch)
    {
        if (QHOpModeSwitch->objectName().isEmpty())
            QHOpModeSwitch->setObjectName(QString::fromUtf8("QHOpModeSwitch"));
        QHOpModeSwitch->resize(336, 514);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHOpModeSwitch->setFont(font);
        verticalLayout_6 = new QVBoxLayout(QHOpModeSwitch);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(QHOpModeSwitch);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        modecomboBox = new QComboBox(QHOpModeSwitch);
        modecomboBox->setObjectName(QString::fromUtf8("modecomboBox"));

        horizontalLayout_6->addWidget(modecomboBox);


        verticalLayout_6->addLayout(horizontalLayout_6);

        manualmodeAgroupBox = new QGroupBox(QHOpModeSwitch);
        manualmodeAgroupBox->setObjectName(QString::fromUtf8("manualmodeAgroupBox"));
        verticalLayout = new QVBoxLayout(manualmodeAgroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        charttypeAlabel = new QLabel(manualmodeAgroupBox);
        charttypeAlabel->setObjectName(QString::fromUtf8("charttypeAlabel"));

        horizontalLayout_3->addWidget(charttypeAlabel);

        chartTypecomboBox = new QComboBox(manualmodeAgroupBox);
        chartTypecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("MTF")
         << QString::fromUtf8("SFR")
         << QString::fromUtf8("TV Line")
        );
        chartTypecomboBox->setObjectName(QString::fromUtf8("chartTypecomboBox"));

        horizontalLayout_3->addWidget(chartTypecomboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        saveLogcheckBox = new QCheckBox(manualmodeAgroupBox);
        saveLogcheckBox->setObjectName(QString::fromUtf8("saveLogcheckBox"));

        horizontalLayout_4->addWidget(saveLogcheckBox);

        showTotalResultcheckBox = new QCheckBox(manualmodeAgroupBox);
        showTotalResultcheckBox->setObjectName(QString::fromUtf8("showTotalResultcheckBox"));

        horizontalLayout_4->addWidget(showTotalResultcheckBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_6->addWidget(manualmodeAgroupBox);

        manualmodeBgroupBox = new QGroupBox(QHOpModeSwitch);
        manualmodeBgroupBox->setObjectName(QString::fromUtf8("manualmodeBgroupBox"));
        verticalLayout_5 = new QVBoxLayout(manualmodeBgroupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        charttypeBlabel = new QLabel(manualmodeBgroupBox);
        charttypeBlabel->setObjectName(QString::fromUtf8("charttypeBlabel"));

        horizontalLayout_7->addWidget(charttypeBlabel);

        B_chartTypecomboBox = new QComboBox(manualmodeBgroupBox);
        B_chartTypecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("MTF")
         << QString::fromUtf8("SFR")
         << QString::fromUtf8("TV Line")
        );
        B_chartTypecomboBox->setObjectName(QString::fromUtf8("B_chartTypecomboBox"));

        horizontalLayout_7->addWidget(B_chartTypecomboBox);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        Scenelabel = new QLabel(manualmodeBgroupBox);
        Scenelabel->setObjectName(QString::fromUtf8("Scenelabel"));

        horizontalLayout_11->addWidget(Scenelabel);

        B_scenccomboBox = new QComboBox(manualmodeBgroupBox);
        B_scenccomboBox->setObjectName(QString::fromUtf8("B_scenccomboBox"));

        horizontalLayout_11->addWidget(B_scenccomboBox);


        verticalLayout_5->addLayout(horizontalLayout_11);

        HotPlugroupBox = new QGroupBox(manualmodeBgroupBox);
        HotPlugroupBox->setObjectName(QString::fromUtf8("HotPlugroupBox"));
        verticalLayout_4 = new QVBoxLayout(HotPlugroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        interfacelabel = new QLabel(HotPlugroupBox);
        interfacelabel->setObjectName(QString::fromUtf8("interfacelabel"));

        horizontalLayout_8->addWidget(interfacelabel);

        B_PlugInterfacecomboBox = new QComboBox(HotPlugroupBox);
        B_PlugInterfacecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("MIPI")
         << QString::fromUtf8("DVP")
        );
        B_PlugInterfacecomboBox->setObjectName(QString::fromUtf8("B_PlugInterfacecomboBox"));

        horizontalLayout_8->addWidget(B_PlugInterfacecomboBox);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        PINlabel = new QLabel(HotPlugroupBox);
        PINlabel->setObjectName(QString::fromUtf8("PINlabel"));

        horizontalLayout_9->addWidget(PINlabel);

        B_Plug2ndNamecomboBox = new QComboBox(HotPlugroupBox);
        B_Plug2ndNamecomboBox->addItem(QString::fromUtf8("RST"));
        B_Plug2ndNamecomboBox->addItem(QString::fromUtf8("PWDN"));
        B_Plug2ndNamecomboBox->addItem(QString());
        B_Plug2ndNamecomboBox->addItem(QString());
        B_Plug2ndNamecomboBox->addItem(QString());
        B_Plug2ndNamecomboBox->setObjectName(QString::fromUtf8("B_Plug2ndNamecomboBox"));

        horizontalLayout_9->addWidget(B_Plug2ndNamecomboBox);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        rangelabel = new QLabel(HotPlugroupBox);
        rangelabel->setObjectName(QString::fromUtf8("rangelabel"));

        horizontalLayout_10->addWidget(rangelabel);

        B_PlugMindoubleSpinBox = new QDoubleSpinBox(HotPlugroupBox);
        B_PlugMindoubleSpinBox->setObjectName(QString::fromUtf8("B_PlugMindoubleSpinBox"));
        B_PlugMindoubleSpinBox->setPrefix(QString::fromUtf8(""));
        B_PlugMindoubleSpinBox->setSuffix(QString::fromUtf8(""));
        B_PlugMindoubleSpinBox->setDecimals(1);
        B_PlugMindoubleSpinBox->setMaximum(2000);
        B_PlugMindoubleSpinBox->setValue(5);

        horizontalLayout_10->addWidget(B_PlugMindoubleSpinBox);

        wavelinelabel = new QLabel(HotPlugroupBox);
        wavelinelabel->setObjectName(QString::fromUtf8("wavelinelabel"));
        wavelinelabel->setText(QString::fromUtf8("~"));

        horizontalLayout_10->addWidget(wavelinelabel);

        B_PlugMaxdoubleSpinBox = new QDoubleSpinBox(HotPlugroupBox);
        B_PlugMaxdoubleSpinBox->setObjectName(QString::fromUtf8("B_PlugMaxdoubleSpinBox"));
        B_PlugMaxdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        B_PlugMaxdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        B_PlugMaxdoubleSpinBox->setDecimals(1);
        B_PlugMaxdoubleSpinBox->setMaximum(2000);
        B_PlugMaxdoubleSpinBox->setValue(800);

        horizontalLayout_10->addWidget(B_PlugMaxdoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_5->addWidget(HotPlugroupBox);


        verticalLayout_6->addWidget(manualmodeBgroupBox);

        ipsetgroupBox = new QGroupBox(QHOpModeSwitch);
        ipsetgroupBox->setObjectName(QString::fromUtf8("ipsetgroupBox"));
        verticalLayout_3 = new QVBoxLayout(ipsetgroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 2, 2, 2);
        groupBox_3 = new QGroupBox(ipsetgroupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        localradioButton = new QRadioButton(groupBox_3);
        localradioButton->setObjectName(QString::fromUtf8("localradioButton"));
        localradioButton->setChecked(true);

        verticalLayout_2->addWidget(localradioButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ipV4radioButton = new QRadioButton(groupBox_3);
        ipV4radioButton->setObjectName(QString::fromUtf8("ipV4radioButton"));

        horizontalLayout->addWidget(ipV4radioButton);

        ipv4lineEdit = new QLineEdit(groupBox_3);
        ipv4lineEdit->setObjectName(QString::fromUtf8("ipv4lineEdit"));
        ipv4lineEdit->setInputMask(QString::fromUtf8("000.000.000.000; "));
        ipv4lineEdit->setText(QString::fromUtf8("127.0.0.1"));
        ipv4lineEdit->setAlignment(Qt::AlignCenter);
        ipv4lineEdit->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayout->addWidget(ipv4lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(ipsetgroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        portspinBox = new QSpinBox(ipsetgroupBox);
        portspinBox->setObjectName(QString::fromUtf8("portspinBox"));
        portspinBox->setSuffix(QString::fromUtf8(""));
        portspinBox->setPrefix(QString::fromUtf8(""));
        portspinBox->setMinimum(30000);
        portspinBox->setMaximum(65535);
        portspinBox->setValue(41589);

        horizontalLayout_5->addWidget(portspinBox);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_6->addWidget(ipsetgroupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        okpushButton = new QPushButton(QHOpModeSwitch);
        okpushButton->setObjectName(QString::fromUtf8("okpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okpushButton->sizePolicy().hasHeightForWidth());
        okpushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        okpushButton->setFont(font1);

        horizontalLayout_2->addWidget(okpushButton);

        cancelpushButton = new QPushButton(QHOpModeSwitch);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        sizePolicy.setHeightForWidth(cancelpushButton->sizePolicy().hasHeightForWidth());
        cancelpushButton->setSizePolicy(sizePolicy);
        cancelpushButton->setFont(font1);

        horizontalLayout_2->addWidget(cancelpushButton);


        verticalLayout_6->addLayout(horizontalLayout_2);


        retranslateUi(QHOpModeSwitch);

        B_scenccomboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QHOpModeSwitch);
    } // setupUi

    void retranslateUi(QDialog *QHOpModeSwitch)
    {
        QHOpModeSwitch->setWindowTitle(QApplication::translate("QHOpModeSwitch", "Choose Operator Mode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QHOpModeSwitch", "Operator Mode:", 0, QApplication::UnicodeUTF8));
        modecomboBox->clear();
        modecomboBox->insertItems(0, QStringList()
         << QApplication::translate("QHOpModeSwitch", "Normal Mode", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Manual Mode A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Slave Mode", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Manual Mode B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Master Mode", 0, QApplication::UnicodeUTF8)
        );
        manualmodeAgroupBox->setTitle(QApplication::translate("QHOpModeSwitch", "Manual Mode A", 0, QApplication::UnicodeUTF8));
        charttypeAlabel->setText(QApplication::translate("QHOpModeSwitch", "Chart Type:", 0, QApplication::UnicodeUTF8));
        saveLogcheckBox->setText(QApplication::translate("QHOpModeSwitch", "Save Log", 0, QApplication::UnicodeUTF8));
        showTotalResultcheckBox->setText(QApplication::translate("QHOpModeSwitch", "Show Total Result", 0, QApplication::UnicodeUTF8));
        manualmodeBgroupBox->setTitle(QApplication::translate("QHOpModeSwitch", "Manual Mode B", 0, QApplication::UnicodeUTF8));
        charttypeBlabel->setText(QApplication::translate("QHOpModeSwitch", "Chart Type:", 0, QApplication::UnicodeUTF8));
        Scenelabel->setText(QApplication::translate("QHOpModeSwitch", "Scene:", 0, QApplication::UnicodeUTF8));
        B_scenccomboBox->clear();
        B_scenccomboBox->insertItems(0, QStringList()
         << QApplication::translate("QHOpModeSwitch", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Auto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Focus Adjust", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "White Field", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QHOpModeSwitch", "Black Field", 0, QApplication::UnicodeUTF8)
        );
        HotPlugroupBox->setTitle(QApplication::translate("QHOpModeSwitch", "Hot Plug", 0, QApplication::UnicodeUTF8));
        interfacelabel->setText(QApplication::translate("QHOpModeSwitch", "Interface:", 0, QApplication::UnicodeUTF8));
        PINlabel->setText(QApplication::translate("QHOpModeSwitch", "PIN:", 0, QApplication::UnicodeUTF8));
        B_Plug2ndNamecomboBox->setItemText(2, QApplication::translate("QHOpModeSwitch", "MCLK", 0, QApplication::UnicodeUTF8));
        B_Plug2ndNamecomboBox->setItemText(3, QApplication::translate("QHOpModeSwitch", "SCL", 0, QApplication::UnicodeUTF8));
        B_Plug2ndNamecomboBox->setItemText(4, QApplication::translate("QHOpModeSwitch", "SDA", 0, QApplication::UnicodeUTF8));

        rangelabel->setText(QApplication::translate("QHOpModeSwitch", "Range:", 0, QApplication::UnicodeUTF8));
        ipsetgroupBox->setTitle(QApplication::translate("QHOpModeSwitch", "IP/PORT Configure", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        localradioButton->setText(QApplication::translate("QHOpModeSwitch", "Local", 0, QApplication::UnicodeUTF8));
        ipV4radioButton->setText(QApplication::translate("QHOpModeSwitch", "IP V4", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QHOpModeSwitch", "Socket Port:", 0, QApplication::UnicodeUTF8));
        okpushButton->setText(QApplication::translate("QHOpModeSwitch", "OK", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("QHOpModeSwitch", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHOpModeSwitch: public Ui_QHOpModeSwitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHOPMODESWITCH_H
