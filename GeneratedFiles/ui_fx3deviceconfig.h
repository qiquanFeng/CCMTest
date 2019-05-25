/********************************************************************************
** Form generated from reading UI file 'fx3deviceconfig.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FX3DEVICECONFIG_H
#define UI_FX3DEVICECONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_fx3deviceconfig
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *platformChoosecomboBox;
    QPushButton *choosePlatformpushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *serialNumberlabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *connectgrabbersncomboBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *anyradioButton;
    QRadioButton *pos1radioButton;
    QRadioButton *pos2radioButton;
    QRadioButton *pos3radioButton;
    QRadioButton *pos4radioButton;
    QPushButton *savepushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *fpgaDelayspinBox;
    QLabel *label_3;
    QSpinBox *packetSizespinBox;
    QPushButton *setGrabberParameterpushButton;

    void setupUi(QDialog *fx3deviceconfig)
    {
        if (fx3deviceconfig->objectName().isEmpty())
            fx3deviceconfig->setObjectName(QString::fromUtf8("fx3deviceconfig"));
        fx3deviceconfig->resize(588, 381);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        fx3deviceconfig->setFont(font);
        verticalLayout_3 = new QVBoxLayout(fx3deviceconfig);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(fx3deviceconfig);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        platformChoosecomboBox = new QComboBox(groupBox_3);
        platformChoosecomboBox->addItem(QString());
        platformChoosecomboBox->addItem(QString::fromUtf8("UVC"));
        platformChoosecomboBox->addItem(QString::fromUtf8("RTSPM"));
        platformChoosecomboBox->addItem(QString::fromUtf8("HDMI"));
        platformChoosecomboBox->setObjectName(QString::fromUtf8("platformChoosecomboBox"));

        horizontalLayout_4->addWidget(platformChoosecomboBox);

        choosePlatformpushButton = new QPushButton(groupBox_3);
        choosePlatformpushButton->setObjectName(QString::fromUtf8("choosePlatformpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(choosePlatformpushButton->sizePolicy().hasHeightForWidth());
        choosePlatformpushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        choosePlatformpushButton->setFont(font1);

        horizontalLayout_4->addWidget(choosePlatformpushButton);


        verticalLayout_3->addWidget(groupBox_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(fx3deviceconfig);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        serialNumberlabel = new QLabel(fx3deviceconfig);
        serialNumberlabel->setObjectName(QString::fromUtf8("serialNumberlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serialNumberlabel->sizePolicy().hasHeightForWidth());
        serialNumberlabel->setSizePolicy(sizePolicy1);
        serialNumberlabel->setFrameShape(QFrame::StyledPanel);
        serialNumberlabel->setText(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(serialNumberlabel);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(fx3deviceconfig);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_2->addWidget(label_5);

        connectgrabbersncomboBox = new QComboBox(fx3deviceconfig);
        connectgrabbersncomboBox->setObjectName(QString::fromUtf8("connectgrabbersncomboBox"));

        horizontalLayout_2->addWidget(connectgrabbersncomboBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(fx3deviceconfig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font2;
        font2.setPointSize(13);
        groupBox->setFont(font2);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        anyradioButton = new QRadioButton(groupBox);
        anyradioButton->setObjectName(QString::fromUtf8("anyradioButton"));
        anyradioButton->setChecked(true);

        horizontalLayout->addWidget(anyradioButton);

        pos1radioButton = new QRadioButton(groupBox);
        pos1radioButton->setObjectName(QString::fromUtf8("pos1radioButton"));

        horizontalLayout->addWidget(pos1radioButton);

        pos2radioButton = new QRadioButton(groupBox);
        pos2radioButton->setObjectName(QString::fromUtf8("pos2radioButton"));

        horizontalLayout->addWidget(pos2radioButton);

        pos3radioButton = new QRadioButton(groupBox);
        pos3radioButton->setObjectName(QString::fromUtf8("pos3radioButton"));

        horizontalLayout->addWidget(pos3radioButton);

        pos4radioButton = new QRadioButton(groupBox);
        pos4radioButton->setObjectName(QString::fromUtf8("pos4radioButton"));

        horizontalLayout->addWidget(pos4radioButton);


        verticalLayout->addLayout(horizontalLayout);

        savepushButton = new QPushButton(groupBox);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
        sizePolicy.setHeightForWidth(savepushButton->sizePolicy().hasHeightForWidth());
        savepushButton->setSizePolicy(sizePolicy);
        savepushButton->setFont(font1);

        verticalLayout->addWidget(savepushButton);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(fx3deviceconfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        fpgaDelayspinBox = new QSpinBox(groupBox_2);
        fpgaDelayspinBox->setObjectName(QString::fromUtf8("fpgaDelayspinBox"));
        fpgaDelayspinBox->setMinimum(10);
        fpgaDelayspinBox->setMaximum(240);
        fpgaDelayspinBox->setValue(110);

        horizontalLayout_3->addWidget(fpgaDelayspinBox);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        packetSizespinBox = new QSpinBox(groupBox_2);
        packetSizespinBox->setObjectName(QString::fromUtf8("packetSizespinBox"));
        packetSizespinBox->setMinimum(4);
        packetSizespinBox->setMaximum(64);
        packetSizespinBox->setValue(16);

        horizontalLayout_3->addWidget(packetSizespinBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        setGrabberParameterpushButton = new QPushButton(groupBox_2);
        setGrabberParameterpushButton->setObjectName(QString::fromUtf8("setGrabberParameterpushButton"));
        sizePolicy.setHeightForWidth(setGrabberParameterpushButton->sizePolicy().hasHeightForWidth());
        setGrabberParameterpushButton->setSizePolicy(sizePolicy);
        setGrabberParameterpushButton->setFont(font1);

        verticalLayout_2->addWidget(setGrabberParameterpushButton);


        verticalLayout_3->addWidget(groupBox_2);


        retranslateUi(fx3deviceconfig);

        QMetaObject::connectSlotsByName(fx3deviceconfig);
    } // setupUi

    void retranslateUi(QDialog *fx3deviceconfig)
    {
        fx3deviceconfig->setWindowTitle(QApplication::translate("fx3deviceconfig", "fx3deviceconfig", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("fx3deviceconfig", "Choose Platform", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("fx3deviceconfig", "Platform:", 0, QApplication::UnicodeUTF8));
        platformChoosecomboBox->setItemText(0, QApplication::translate("fx3deviceconfig", "Grabber", 0, QApplication::UnicodeUTF8));

        choosePlatformpushButton->setText(QApplication::translate("fx3deviceconfig", "Set", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("fx3deviceconfig", "Grabber Serial Number:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("fx3deviceconfig", "Connect Grabber:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("fx3deviceconfig", "Choose Grabber to Open:", 0, QApplication::UnicodeUTF8));
        anyradioButton->setText(QApplication::translate("fx3deviceconfig", "ANY", 0, QApplication::UnicodeUTF8));
        pos1radioButton->setText(QApplication::translate("fx3deviceconfig", "Grabber 1", 0, QApplication::UnicodeUTF8));
        pos2radioButton->setText(QApplication::translate("fx3deviceconfig", "Grabber 2", 0, QApplication::UnicodeUTF8));
        pos3radioButton->setText(QApplication::translate("fx3deviceconfig", "Grabber 3", 0, QApplication::UnicodeUTF8));
        pos4radioButton->setText(QApplication::translate("fx3deviceconfig", "Grabber 4", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("fx3deviceconfig", "BIND", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("fx3deviceconfig", "Grabber Parameter Setting", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("fx3deviceconfig", "Upload Delay(clock):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("fx3deviceconfig", "Packet Size(64KB):", 0, QApplication::UnicodeUTF8));
        setGrabberParameterpushButton->setText(QApplication::translate("fx3deviceconfig", "Set", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fx3deviceconfig: public Ui_fx3deviceconfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FX3DEVICECONFIG_H
