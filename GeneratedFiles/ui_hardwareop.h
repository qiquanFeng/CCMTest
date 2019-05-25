/********************************************************************************
** Form generated from reading UI file 'hardwareop.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARDWAREOP_H
#define UI_HARDWAREOP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hardwareop
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *avddVolt_checkBox;
    QCheckBox *dvddVolt_checkBox;
    QCheckBox *dovddVolt_checkBox;
    QCheckBox *ioddVolt_checkBox;
    QCheckBox *afVolt_checkBox;
    QCheckBox *vfuseVolt_checkBox;
    QCheckBox *powVolt_checkBox;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *avddVolt_doubleSpinBox;
    QDoubleSpinBox *dvddVolt_doubleSpinBox;
    QDoubleSpinBox *dovddVolt_doubleSpinBox;
    QDoubleSpinBox *ioddVolt_doubleSpinBox;
    QDoubleSpinBox *afVolt_doubleSpinBox;
    QDoubleSpinBox *vfuseVolt_doubleSpinBox;
    QDoubleSpinBox *powVolt_doubleSpinBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *vol5Vlabel;
    QComboBox *vol5VcomboBox;
    QHBoxLayout *horizontalLayout_18;
    QLabel *vol12Vlabel;
    QComboBox *vol12VcomboBox;
    QPushButton *vlotsetpushButton;
    QPushButton *voltreadpushButton;
    QPushButton *voltMeasurepushButton;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pwndhighpushButton;
    QPushButton *pwndlowpushButton;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *resethighpushButton;
    QPushButton *resetlowpushButton;
    QGroupBox *mclkgroupBox;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QDoubleSpinBox *mclk_doubleSpinBox;
    QComboBox *mipiLanecomboBox;
    QVBoxLayout *verticalLayout_11;
    QPushButton *setmclkpushButton;
    QPushButton *setLanepushButton;
    QVBoxLayout *verticalLayout_12;
    QPushButton *readmclkpushButton;
    QPushButton *readLanepushButton;
    QCheckBox *vsync_checkBox;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_17;
    QCheckBox *spiCSLowcheckBox;
    QCheckBox *spiLittleEndiancheckBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *communicatetypelabel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_7;
    QComboBox *communicatetypecomboBox;
    QSpinBox *i2cspeedspinBox;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *slavelineEdit;
    QPushButton *searchSlave_pushButton;
    QLineEdit *reglineEdit;
    QLineEdit *datalineEdit;
    QComboBox *i2ctypecomboBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *i2cwritepushButton;
    QPushButton *i2creadpushButton;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *GPIOOut0checkBox;
    QCheckBox *GPIOOut1checkBox;
    QCheckBox *GPIOOut2checkBox;
    QCheckBox *GPIOOut3checkBox;
    QHBoxLayout *horizontalLayout_26;
    QCheckBox *GPIOIn0checkBox;
    QCheckBox *GPIOIn1checkBox;
    QPushButton *getGPIO_pushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label;
    QComboBox *batchIICModecomboBox;
    QPushButton *batchFormatpushButton;
    QHBoxLayout *horizontalLayout_21;
    QLabel *communicatetypelabel_2;
    QComboBox *batchProtocalcomboBox;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_16;
    QSpinBox *batchSpeedspinBox;
    QLabel *label_17;
    QSpinBox *batchDelayspinBox;
    QHBoxLayout *horizontalLayout_23;
    QLabel *pageStartAddrlabel;
    QLineEdit *pageStartAddrlineEdit;
    QHBoxLayout *horizontalLayout_24;
    QLabel *pageSlavelabel;
    QLineEdit *batchSlavelineEdit;
    QLabel *pageSizelabel;
    QSpinBox *pageSizespinBox;
    QHBoxLayout *horizontalLayout_25;
    QLabel *batchEETypelabel;
    QComboBox *batchEETypecomboBox;
    QPushButton *batchTestpushButton;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *i2cbatchpushButton;
    QPushButton *i2cbatchRead_pushButton;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLineEdit *binSlavelineEdit;
    QLabel *label_14;
    QComboBox *binTypecomboBox;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *binRegStartlineEdit;
    QLabel *label_7;
    QSpinBox *binRegAddspinBox;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QSpinBox *binCountspinBox;
    QLabel *label_6;
    QSpinBox *binDelayspinBox;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *binOpenpushButton;
    QPushButton *binSavepushButton;
    QCheckBox *binSavecheckBox;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *binDataCreratepushButton;
    QPushButton *binData00epushButton;
    QPushButton *binDataFFpushButton;
    QPlainTextEdit *binplainTextEdit;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *binWritepushButton;
    QPushButton *binReadpushButton;
    QLabel *infolabel;

    void setupUi(QDockWidget *hardwareop)
    {
        if (hardwareop->objectName().isEmpty())
            hardwareop->setObjectName(QString::fromUtf8("hardwareop"));
        hardwareop->resize(333, 694);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hardwareop->sizePolicy().hasHeightForWidth());
        hardwareop->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        hardwareop->setFont(font);
        hardwareop->setFloating(true);
        hardwareop->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 0, 3, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_9 = new QVBoxLayout(tab);
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setFont(font1);
        horizontalLayout_19 = new QHBoxLayout(groupBox);
        horizontalLayout_19->setSpacing(2);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(1, 0, 1, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        avddVolt_checkBox = new QCheckBox(groupBox);
        avddVolt_checkBox->setObjectName(QString::fromUtf8("avddVolt_checkBox"));
        avddVolt_checkBox->setText(QString::fromUtf8("AVDD(0~3.5V)"));
        avddVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(avddVolt_checkBox);

        dvddVolt_checkBox = new QCheckBox(groupBox);
        dvddVolt_checkBox->setObjectName(QString::fromUtf8("dvddVolt_checkBox"));
        dvddVolt_checkBox->setText(QString::fromUtf8("DVDD(0~3.5V)"));
        dvddVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(dvddVolt_checkBox);

        dovddVolt_checkBox = new QCheckBox(groupBox);
        dovddVolt_checkBox->setObjectName(QString::fromUtf8("dovddVolt_checkBox"));
        dovddVolt_checkBox->setText(QString::fromUtf8("DOVDD(0~3.5V)"));
        dovddVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(dovddVolt_checkBox);

        ioddVolt_checkBox = new QCheckBox(groupBox);
        ioddVolt_checkBox->setObjectName(QString::fromUtf8("ioddVolt_checkBox"));
        ioddVolt_checkBox->setText(QString::fromUtf8("IODD(0~3.5V)"));
        ioddVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(ioddVolt_checkBox);

        afVolt_checkBox = new QCheckBox(groupBox);
        afVolt_checkBox->setObjectName(QString::fromUtf8("afVolt_checkBox"));
        afVolt_checkBox->setText(QString::fromUtf8("AF(0~3.5V)"));
        afVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(afVolt_checkBox);

        vfuseVolt_checkBox = new QCheckBox(groupBox);
        vfuseVolt_checkBox->setObjectName(QString::fromUtf8("vfuseVolt_checkBox"));
        vfuseVolt_checkBox->setText(QString::fromUtf8("OTP(0~10V)"));
        vfuseVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(vfuseVolt_checkBox);

        powVolt_checkBox = new QCheckBox(groupBox);
        powVolt_checkBox->setObjectName(QString::fromUtf8("powVolt_checkBox"));
        powVolt_checkBox->setText(QString::fromUtf8("POW(0~3.5V)"));
        powVolt_checkBox->setChecked(true);

        verticalLayout_3->addWidget(powVolt_checkBox);


        horizontalLayout_19->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        avddVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        avddVolt_doubleSpinBox->setObjectName(QString::fromUtf8("avddVolt_doubleSpinBox"));
        avddVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        avddVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        avddVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        avddVolt_doubleSpinBox->setDecimals(2);
        avddVolt_doubleSpinBox->setMaximum(3.5);
        avddVolt_doubleSpinBox->setSingleStep(0.1);
        avddVolt_doubleSpinBox->setValue(2.8);

        verticalLayout_2->addWidget(avddVolt_doubleSpinBox);

        dvddVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        dvddVolt_doubleSpinBox->setObjectName(QString::fromUtf8("dvddVolt_doubleSpinBox"));
        dvddVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        dvddVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        dvddVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        dvddVolt_doubleSpinBox->setDecimals(2);
        dvddVolt_doubleSpinBox->setMaximum(3.5);
        dvddVolt_doubleSpinBox->setSingleStep(0.1);
        dvddVolt_doubleSpinBox->setValue(1);

        verticalLayout_2->addWidget(dvddVolt_doubleSpinBox);

        dovddVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        dovddVolt_doubleSpinBox->setObjectName(QString::fromUtf8("dovddVolt_doubleSpinBox"));
        dovddVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        dovddVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        dovddVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        dovddVolt_doubleSpinBox->setDecimals(2);
        dovddVolt_doubleSpinBox->setMaximum(3.5);
        dovddVolt_doubleSpinBox->setSingleStep(0.1);
        dovddVolt_doubleSpinBox->setValue(1.8);

        verticalLayout_2->addWidget(dovddVolt_doubleSpinBox);

        ioddVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        ioddVolt_doubleSpinBox->setObjectName(QString::fromUtf8("ioddVolt_doubleSpinBox"));
        ioddVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        ioddVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        ioddVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        ioddVolt_doubleSpinBox->setDecimals(2);
        ioddVolt_doubleSpinBox->setMaximum(3.5);
        ioddVolt_doubleSpinBox->setSingleStep(0.1);
        ioddVolt_doubleSpinBox->setValue(0);

        verticalLayout_2->addWidget(ioddVolt_doubleSpinBox);

        afVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        afVolt_doubleSpinBox->setObjectName(QString::fromUtf8("afVolt_doubleSpinBox"));
        afVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        afVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        afVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        afVolt_doubleSpinBox->setDecimals(2);
        afVolt_doubleSpinBox->setMaximum(3.5);
        afVolt_doubleSpinBox->setSingleStep(0.1);
        afVolt_doubleSpinBox->setValue(2.8);

        verticalLayout_2->addWidget(afVolt_doubleSpinBox);

        vfuseVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        vfuseVolt_doubleSpinBox->setObjectName(QString::fromUtf8("vfuseVolt_doubleSpinBox"));
        vfuseVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        vfuseVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        vfuseVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        vfuseVolt_doubleSpinBox->setDecimals(2);
        vfuseVolt_doubleSpinBox->setMaximum(10);
        vfuseVolt_doubleSpinBox->setSingleStep(0.1);
        vfuseVolt_doubleSpinBox->setValue(0);

        verticalLayout_2->addWidget(vfuseVolt_doubleSpinBox);

        powVolt_doubleSpinBox = new QDoubleSpinBox(groupBox);
        powVolt_doubleSpinBox->setObjectName(QString::fromUtf8("powVolt_doubleSpinBox"));
        powVolt_doubleSpinBox->setAlignment(Qt::AlignCenter);
        powVolt_doubleSpinBox->setPrefix(QString::fromUtf8(""));
        powVolt_doubleSpinBox->setSuffix(QString::fromUtf8(""));
        powVolt_doubleSpinBox->setDecimals(2);
        powVolt_doubleSpinBox->setMaximum(3.5);
        powVolt_doubleSpinBox->setSingleStep(0.1);
        powVolt_doubleSpinBox->setValue(0);

        verticalLayout_2->addWidget(powVolt_doubleSpinBox);


        horizontalLayout_19->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vol5Vlabel = new QLabel(groupBox);
        vol5Vlabel->setObjectName(QString::fromUtf8("vol5Vlabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(vol5Vlabel->sizePolicy().hasHeightForWidth());
        vol5Vlabel->setSizePolicy(sizePolicy3);
        vol5Vlabel->setText(QString::fromUtf8("5V:"));

        horizontalLayout->addWidget(vol5Vlabel);

        vol5VcomboBox = new QComboBox(groupBox);
        vol5VcomboBox->addItem(QString::fromUtf8("OFF"));
        vol5VcomboBox->addItem(QString::fromUtf8("ON"));
        vol5VcomboBox->addItem(QString());
        vol5VcomboBox->setObjectName(QString::fromUtf8("vol5VcomboBox"));

        horizontalLayout->addWidget(vol5VcomboBox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        vol12Vlabel = new QLabel(groupBox);
        vol12Vlabel->setObjectName(QString::fromUtf8("vol12Vlabel"));
        sizePolicy3.setHeightForWidth(vol12Vlabel->sizePolicy().hasHeightForWidth());
        vol12Vlabel->setSizePolicy(sizePolicy3);
        vol12Vlabel->setText(QString::fromUtf8("12V:"));

        horizontalLayout_18->addWidget(vol12Vlabel);

        vol12VcomboBox = new QComboBox(groupBox);
        vol12VcomboBox->addItem(QString::fromUtf8("OFF"));
        vol12VcomboBox->addItem(QString::fromUtf8("ON"));
        vol12VcomboBox->addItem(QString());
        vol12VcomboBox->setObjectName(QString::fromUtf8("vol12VcomboBox"));

        horizontalLayout_18->addWidget(vol12VcomboBox);


        verticalLayout_4->addLayout(horizontalLayout_18);

        vlotsetpushButton = new QPushButton(groupBox);
        vlotsetpushButton->setObjectName(QString::fromUtf8("vlotsetpushButton"));
        sizePolicy2.setHeightForWidth(vlotsetpushButton->sizePolicy().hasHeightForWidth());
        vlotsetpushButton->setSizePolicy(sizePolicy2);
        vlotsetpushButton->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(15);
        vlotsetpushButton->setFont(font2);

        verticalLayout_4->addWidget(vlotsetpushButton);

        voltreadpushButton = new QPushButton(groupBox);
        voltreadpushButton->setObjectName(QString::fromUtf8("voltreadpushButton"));
        sizePolicy2.setHeightForWidth(voltreadpushButton->sizePolicy().hasHeightForWidth());
        voltreadpushButton->setSizePolicy(sizePolicy2);
        voltreadpushButton->setFont(font2);

        verticalLayout_4->addWidget(voltreadpushButton);

        voltMeasurepushButton = new QPushButton(groupBox);
        voltMeasurepushButton->setObjectName(QString::fromUtf8("voltMeasurepushButton"));
        sizePolicy2.setHeightForWidth(voltMeasurepushButton->sizePolicy().hasHeightForWidth());
        voltMeasurepushButton->setSizePolicy(sizePolicy2);
        voltMeasurepushButton->setFont(font2);

        verticalLayout_4->addWidget(voltMeasurepushButton);


        horizontalLayout_19->addLayout(verticalLayout_4);


        verticalLayout_9->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        groupBox_3->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, 0, 1, 0);
        pwndhighpushButton = new QPushButton(groupBox_3);
        pwndhighpushButton->setObjectName(QString::fromUtf8("pwndhighpushButton"));
        sizePolicy2.setHeightForWidth(pwndhighpushButton->sizePolicy().hasHeightForWidth());
        pwndhighpushButton->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font3.setPointSize(12);
        pwndhighpushButton->setFont(font3);

        horizontalLayout_7->addWidget(pwndhighpushButton);

        pwndlowpushButton = new QPushButton(groupBox_3);
        pwndlowpushButton->setObjectName(QString::fromUtf8("pwndlowpushButton"));
        sizePolicy2.setHeightForWidth(pwndlowpushButton->sizePolicy().hasHeightForWidth());
        pwndlowpushButton->setSizePolicy(sizePolicy2);
        pwndlowpushButton->setFont(font3);

        horizontalLayout_7->addWidget(pwndlowpushButton);


        horizontalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setFont(font1);
        horizontalLayout_8 = new QHBoxLayout(groupBox_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(1, 0, 1, 0);
        resethighpushButton = new QPushButton(groupBox_4);
        resethighpushButton->setObjectName(QString::fromUtf8("resethighpushButton"));
        sizePolicy2.setHeightForWidth(resethighpushButton->sizePolicy().hasHeightForWidth());
        resethighpushButton->setSizePolicy(sizePolicy2);
        resethighpushButton->setFont(font3);

        horizontalLayout_8->addWidget(resethighpushButton);

        resetlowpushButton = new QPushButton(groupBox_4);
        resetlowpushButton->setObjectName(QString::fromUtf8("resetlowpushButton"));
        sizePolicy2.setHeightForWidth(resetlowpushButton->sizePolicy().hasHeightForWidth());
        resetlowpushButton->setSizePolicy(sizePolicy2);
        resetlowpushButton->setFont(font3);

        horizontalLayout_8->addWidget(resetlowpushButton);


        horizontalLayout_2->addWidget(groupBox_4);


        verticalLayout_9->addLayout(horizontalLayout_2);

        mclkgroupBox = new QGroupBox(tab);
        mclkgroupBox->setObjectName(QString::fromUtf8("mclkgroupBox"));
        sizePolicy2.setHeightForWidth(mclkgroupBox->sizePolicy().hasHeightForWidth());
        mclkgroupBox->setSizePolicy(sizePolicy2);
        mclkgroupBox->setFont(font1);
        verticalLayout_13 = new QVBoxLayout(mclkgroupBox);
        verticalLayout_13->setSpacing(2);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(1, 0, 1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        mclk_doubleSpinBox = new QDoubleSpinBox(mclkgroupBox);
        mclk_doubleSpinBox->setObjectName(QString::fromUtf8("mclk_doubleSpinBox"));
        sizePolicy3.setHeightForWidth(mclk_doubleSpinBox->sizePolicy().hasHeightForWidth());
        mclk_doubleSpinBox->setSizePolicy(sizePolicy3);
        mclk_doubleSpinBox->setAlignment(Qt::AlignCenter);
        mclk_doubleSpinBox->setDecimals(3);
        mclk_doubleSpinBox->setMaximum(136);
        mclk_doubleSpinBox->setValue(24);

        verticalLayout_10->addWidget(mclk_doubleSpinBox);

        mipiLanecomboBox = new QComboBox(mclkgroupBox);
        mipiLanecomboBox->setObjectName(QString::fromUtf8("mipiLanecomboBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mipiLanecomboBox->sizePolicy().hasHeightForWidth());
        mipiLanecomboBox->setSizePolicy(sizePolicy4);
        mipiLanecomboBox->setMaximumSize(QSize(130, 16777215));

        verticalLayout_10->addWidget(mipiLanecomboBox);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        setmclkpushButton = new QPushButton(mclkgroupBox);
        setmclkpushButton->setObjectName(QString::fromUtf8("setmclkpushButton"));
        sizePolicy2.setHeightForWidth(setmclkpushButton->sizePolicy().hasHeightForWidth());
        setmclkpushButton->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        setmclkpushButton->setFont(font4);

        verticalLayout_11->addWidget(setmclkpushButton);

        setLanepushButton = new QPushButton(mclkgroupBox);
        setLanepushButton->setObjectName(QString::fromUtf8("setLanepushButton"));
        sizePolicy2.setHeightForWidth(setLanepushButton->sizePolicy().hasHeightForWidth());
        setLanepushButton->setSizePolicy(sizePolicy2);
        setLanepushButton->setFont(font4);

        verticalLayout_11->addWidget(setLanepushButton);


        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(2);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        readmclkpushButton = new QPushButton(mclkgroupBox);
        readmclkpushButton->setObjectName(QString::fromUtf8("readmclkpushButton"));
        sizePolicy2.setHeightForWidth(readmclkpushButton->sizePolicy().hasHeightForWidth());
        readmclkpushButton->setSizePolicy(sizePolicy2);
        readmclkpushButton->setFont(font4);

        verticalLayout_12->addWidget(readmclkpushButton);

        readLanepushButton = new QPushButton(mclkgroupBox);
        readLanepushButton->setObjectName(QString::fromUtf8("readLanepushButton"));
        sizePolicy2.setHeightForWidth(readLanepushButton->sizePolicy().hasHeightForWidth());
        readLanepushButton->setSizePolicy(sizePolicy2);
        readLanepushButton->setFont(font4);

        verticalLayout_12->addWidget(readLanepushButton);


        horizontalLayout_3->addLayout(verticalLayout_12);


        verticalLayout_13->addLayout(horizontalLayout_3);

        vsync_checkBox = new QCheckBox(mclkgroupBox);
        vsync_checkBox->setObjectName(QString::fromUtf8("vsync_checkBox"));

        verticalLayout_13->addWidget(vsync_checkBox);


        verticalLayout_9->addWidget(mclkgroupBox);

        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy2.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy2);
        groupBox_6->setFont(font1);
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(1, 0, 1, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        spiCSLowcheckBox = new QCheckBox(groupBox_6);
        spiCSLowcheckBox->setObjectName(QString::fromUtf8("spiCSLowcheckBox"));
        spiCSLowcheckBox->setChecked(true);

        horizontalLayout_17->addWidget(spiCSLowcheckBox);

        spiLittleEndiancheckBox = new QCheckBox(groupBox_6);
        spiLittleEndiancheckBox->setObjectName(QString::fromUtf8("spiLittleEndiancheckBox"));
        spiLittleEndiancheckBox->setChecked(true);

        horizontalLayout_17->addWidget(spiLittleEndiancheckBox);


        verticalLayout_8->addLayout(horizontalLayout_17);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        communicatetypelabel = new QLabel(groupBox_6);
        communicatetypelabel->setObjectName(QString::fromUtf8("communicatetypelabel"));
        sizePolicy2.setHeightForWidth(communicatetypelabel->sizePolicy().hasHeightForWidth());
        communicatetypelabel->setSizePolicy(sizePolicy2);
        communicatetypelabel->setMaximumSize(QSize(95, 16777215));
        communicatetypelabel->setFont(font4);

        verticalLayout_6->addWidget(communicatetypelabel);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMaximumSize(QSize(95, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font5.setPointSize(8);
        label_9->setFont(font5);

        verticalLayout_6->addWidget(label_9);

        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setMaximumSize(QSize(95, 16777215));
        label_10->setFont(font4);

        verticalLayout_6->addWidget(label_10);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMaximumSize(QSize(95, 16777215));
        label_11->setFont(font4);

        verticalLayout_6->addWidget(label_11);

        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMaximumSize(QSize(95, 16777215));
        label_12->setFont(font4);

        verticalLayout_6->addWidget(label_12);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMaximumSize(QSize(95, 16777215));
        label_13->setFont(font4);

        verticalLayout_6->addWidget(label_13);


        horizontalLayout_6->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        communicatetypecomboBox = new QComboBox(groupBox_6);
        communicatetypecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("I2C")
        );
        communicatetypecomboBox->setObjectName(QString::fromUtf8("communicatetypecomboBox"));
        sizePolicy2.setHeightForWidth(communicatetypecomboBox->sizePolicy().hasHeightForWidth());
        communicatetypecomboBox->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(communicatetypecomboBox);

        i2cspeedspinBox = new QSpinBox(groupBox_6);
        i2cspeedspinBox->setObjectName(QString::fromUtf8("i2cspeedspinBox"));
        i2cspeedspinBox->setMinimum(2);
        i2cspeedspinBox->setMaximum(1024);
        i2cspeedspinBox->setValue(400);

        verticalLayout_7->addWidget(i2cspeedspinBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        slavelineEdit = new QLineEdit(groupBox_6);
        slavelineEdit->setObjectName(QString::fromUtf8("slavelineEdit"));
        sizePolicy2.setHeightForWidth(slavelineEdit->sizePolicy().hasHeightForWidth());
        slavelineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(slavelineEdit);

        searchSlave_pushButton = new QPushButton(groupBox_6);
        searchSlave_pushButton->setObjectName(QString::fromUtf8("searchSlave_pushButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(searchSlave_pushButton->sizePolicy().hasHeightForWidth());
        searchSlave_pushButton->setSizePolicy(sizePolicy5);
        searchSlave_pushButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(searchSlave_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_4);

        reglineEdit = new QLineEdit(groupBox_6);
        reglineEdit->setObjectName(QString::fromUtf8("reglineEdit"));
        sizePolicy2.setHeightForWidth(reglineEdit->sizePolicy().hasHeightForWidth());
        reglineEdit->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(reglineEdit);

        datalineEdit = new QLineEdit(groupBox_6);
        datalineEdit->setObjectName(QString::fromUtf8("datalineEdit"));
        sizePolicy2.setHeightForWidth(datalineEdit->sizePolicy().hasHeightForWidth());
        datalineEdit->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(datalineEdit);

        i2ctypecomboBox = new QComboBox(groupBox_6);
        i2ctypecomboBox->setObjectName(QString::fromUtf8("i2ctypecomboBox"));
        sizePolicy2.setHeightForWidth(i2ctypecomboBox->sizePolicy().hasHeightForWidth());
        i2ctypecomboBox->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(i2ctypecomboBox);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        i2cwritepushButton = new QPushButton(groupBox_6);
        i2cwritepushButton->setObjectName(QString::fromUtf8("i2cwritepushButton"));
        sizePolicy2.setHeightForWidth(i2cwritepushButton->sizePolicy().hasHeightForWidth());
        i2cwritepushButton->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Microsoft PhagsPa"));
        font6.setPointSize(14);
        i2cwritepushButton->setFont(font6);

        horizontalLayout_5->addWidget(i2cwritepushButton);

        i2creadpushButton = new QPushButton(groupBox_6);
        i2creadpushButton->setObjectName(QString::fromUtf8("i2creadpushButton"));
        sizePolicy2.setHeightForWidth(i2creadpushButton->sizePolicy().hasHeightForWidth());
        i2creadpushButton->setSizePolicy(sizePolicy2);
        i2creadpushButton->setFont(font6);

        horizontalLayout_5->addWidget(i2creadpushButton);


        verticalLayout_8->addLayout(horizontalLayout_5);


        verticalLayout_9->addWidget(groupBox_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        GPIOOut0checkBox = new QCheckBox(tab);
        GPIOOut0checkBox->setObjectName(QString::fromUtf8("GPIOOut0checkBox"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font7.setPointSize(9);
        GPIOOut0checkBox->setFont(font7);
        GPIOOut0checkBox->setText(QString::fromUtf8("O0"));

        horizontalLayout_10->addWidget(GPIOOut0checkBox);

        GPIOOut1checkBox = new QCheckBox(tab);
        GPIOOut1checkBox->setObjectName(QString::fromUtf8("GPIOOut1checkBox"));
        GPIOOut1checkBox->setFont(font7);
        GPIOOut1checkBox->setText(QString::fromUtf8("O1"));

        horizontalLayout_10->addWidget(GPIOOut1checkBox);

        GPIOOut2checkBox = new QCheckBox(tab);
        GPIOOut2checkBox->setObjectName(QString::fromUtf8("GPIOOut2checkBox"));
        GPIOOut2checkBox->setFont(font7);
        GPIOOut2checkBox->setText(QString::fromUtf8("O2"));

        horizontalLayout_10->addWidget(GPIOOut2checkBox);

        GPIOOut3checkBox = new QCheckBox(tab);
        GPIOOut3checkBox->setObjectName(QString::fromUtf8("GPIOOut3checkBox"));
        GPIOOut3checkBox->setFont(font1);
        GPIOOut3checkBox->setText(QString::fromUtf8("O3"));

        horizontalLayout_10->addWidget(GPIOOut3checkBox);


        verticalLayout_9->addLayout(horizontalLayout_10);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        GPIOIn0checkBox = new QCheckBox(tab);
        GPIOIn0checkBox->setObjectName(QString::fromUtf8("GPIOIn0checkBox"));
        GPIOIn0checkBox->setEnabled(false);
        GPIOIn0checkBox->setFont(font7);
        GPIOIn0checkBox->setText(QString::fromUtf8("I0"));
        GPIOIn0checkBox->setCheckable(true);

        horizontalLayout_26->addWidget(GPIOIn0checkBox);

        GPIOIn1checkBox = new QCheckBox(tab);
        GPIOIn1checkBox->setObjectName(QString::fromUtf8("GPIOIn1checkBox"));
        GPIOIn1checkBox->setEnabled(false);
        GPIOIn1checkBox->setFont(font7);
        GPIOIn1checkBox->setText(QString::fromUtf8("I1"));
        GPIOIn1checkBox->setCheckable(true);

        horizontalLayout_26->addWidget(GPIOIn1checkBox);

        getGPIO_pushButton = new QPushButton(tab);
        getGPIO_pushButton->setObjectName(QString::fromUtf8("getGPIO_pushButton"));
        sizePolicy5.setHeightForWidth(getGPIO_pushButton->sizePolicy().hasHeightForWidth());
        getGPIO_pushButton->setSizePolicy(sizePolicy5);
        getGPIO_pushButton->setMaximumSize(QSize(40, 16777215));
        getGPIO_pushButton->setFont(font4);
        getGPIO_pushButton->setCheckable(false);
        getGPIO_pushButton->setAutoDefault(false);

        horizontalLayout_26->addWidget(getGPIO_pushButton);


        verticalLayout_9->addLayout(horizontalLayout_26);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_20->addWidget(label);

        batchIICModecomboBox = new QComboBox(tab_2);
        batchIICModecomboBox->setObjectName(QString::fromUtf8("batchIICModecomboBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(batchIICModecomboBox->sizePolicy().hasHeightForWidth());
        batchIICModecomboBox->setSizePolicy(sizePolicy6);

        horizontalLayout_20->addWidget(batchIICModecomboBox);

        batchFormatpushButton = new QPushButton(tab_2);
        batchFormatpushButton->setObjectName(QString::fromUtf8("batchFormatpushButton"));

        horizontalLayout_20->addWidget(batchFormatpushButton);


        verticalLayout_5->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        communicatetypelabel_2 = new QLabel(tab_2);
        communicatetypelabel_2->setObjectName(QString::fromUtf8("communicatetypelabel_2"));
        sizePolicy4.setHeightForWidth(communicatetypelabel_2->sizePolicy().hasHeightForWidth());
        communicatetypelabel_2->setSizePolicy(sizePolicy4);
        communicatetypelabel_2->setMaximumSize(QSize(95, 16777215));
        communicatetypelabel_2->setFont(font4);

        horizontalLayout_21->addWidget(communicatetypelabel_2);

        batchProtocalcomboBox = new QComboBox(tab_2);
        batchProtocalcomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("I2C")
         << QString::fromUtf8("SPI")
        );
        batchProtocalcomboBox->setObjectName(QString::fromUtf8("batchProtocalcomboBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(batchProtocalcomboBox->sizePolicy().hasHeightForWidth());
        batchProtocalcomboBox->setSizePolicy(sizePolicy7);

        horizontalLayout_21->addWidget(batchProtocalcomboBox);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setMaximumSize(QSize(95, 16777215));
        label_16->setFont(font5);

        horizontalLayout_22->addWidget(label_16);

        batchSpeedspinBox = new QSpinBox(tab_2);
        batchSpeedspinBox->setObjectName(QString::fromUtf8("batchSpeedspinBox"));
        batchSpeedspinBox->setMinimum(10);
        batchSpeedspinBox->setMaximum(2048);
        batchSpeedspinBox->setValue(400);

        horizontalLayout_22->addWidget(batchSpeedspinBox);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font8;
        font8.setPointSize(9);
        label_17->setFont(font8);

        horizontalLayout_22->addWidget(label_17);

        batchDelayspinBox = new QSpinBox(tab_2);
        batchDelayspinBox->setObjectName(QString::fromUtf8("batchDelayspinBox"));
        batchDelayspinBox->setMinimum(10);
        batchDelayspinBox->setMaximum(30000);
        batchDelayspinBox->setValue(3000);

        horizontalLayout_22->addWidget(batchDelayspinBox);


        verticalLayout_5->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        pageStartAddrlabel = new QLabel(tab_2);
        pageStartAddrlabel->setObjectName(QString::fromUtf8("pageStartAddrlabel"));
        pageStartAddrlabel->setFont(font8);

        horizontalLayout_23->addWidget(pageStartAddrlabel);

        pageStartAddrlineEdit = new QLineEdit(tab_2);
        pageStartAddrlineEdit->setObjectName(QString::fromUtf8("pageStartAddrlineEdit"));

        horizontalLayout_23->addWidget(pageStartAddrlineEdit);


        verticalLayout_5->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        pageSlavelabel = new QLabel(tab_2);
        pageSlavelabel->setObjectName(QString::fromUtf8("pageSlavelabel"));

        horizontalLayout_24->addWidget(pageSlavelabel);

        batchSlavelineEdit = new QLineEdit(tab_2);
        batchSlavelineEdit->setObjectName(QString::fromUtf8("batchSlavelineEdit"));
        batchSlavelineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_24->addWidget(batchSlavelineEdit);

        pageSizelabel = new QLabel(tab_2);
        pageSizelabel->setObjectName(QString::fromUtf8("pageSizelabel"));
        pageSizelabel->setFont(font8);

        horizontalLayout_24->addWidget(pageSizelabel);

        pageSizespinBox = new QSpinBox(tab_2);
        pageSizespinBox->setObjectName(QString::fromUtf8("pageSizespinBox"));
        pageSizespinBox->setMinimum(32);
        pageSizespinBox->setMaximum(512);
        pageSizespinBox->setValue(128);

        horizontalLayout_24->addWidget(pageSizespinBox);


        verticalLayout_5->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        batchEETypelabel = new QLabel(tab_2);
        batchEETypelabel->setObjectName(QString::fromUtf8("batchEETypelabel"));
        batchEETypelabel->setFont(font8);

        horizontalLayout_25->addWidget(batchEETypelabel);

        batchEETypecomboBox = new QComboBox(tab_2);
        batchEETypecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("DW9807")
        );
        batchEETypecomboBox->setObjectName(QString::fromUtf8("batchEETypecomboBox"));
        sizePolicy6.setHeightForWidth(batchEETypecomboBox->sizePolicy().hasHeightForWidth());
        batchEETypecomboBox->setSizePolicy(sizePolicy6);

        horizontalLayout_25->addWidget(batchEETypecomboBox);

        batchTestpushButton = new QPushButton(tab_2);
        batchTestpushButton->setObjectName(QString::fromUtf8("batchTestpushButton"));

        horizontalLayout_25->addWidget(batchTestpushButton);


        verticalLayout_5->addLayout(horizontalLayout_25);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        QFont font9;
        font9.setFamily(QString::fromUtf8("Arial"));
        font9.setPointSize(10);
        font9.setBold(false);
        font9.setWeight(50);
        plainTextEdit->setFont(font9);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        verticalLayout_5->addWidget(plainTextEdit);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        i2cbatchpushButton = new QPushButton(tab_2);
        i2cbatchpushButton->setObjectName(QString::fromUtf8("i2cbatchpushButton"));
        sizePolicy2.setHeightForWidth(i2cbatchpushButton->sizePolicy().hasHeightForWidth());
        i2cbatchpushButton->setSizePolicy(sizePolicy2);
        QFont font10;
        font10.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font10.setPointSize(14);
        i2cbatchpushButton->setFont(font10);

        horizontalLayout_9->addWidget(i2cbatchpushButton);

        i2cbatchRead_pushButton = new QPushButton(tab_2);
        i2cbatchRead_pushButton->setObjectName(QString::fromUtf8("i2cbatchRead_pushButton"));
        sizePolicy2.setHeightForWidth(i2cbatchRead_pushButton->sizePolicy().hasHeightForWidth());
        i2cbatchRead_pushButton->setSizePolicy(sizePolicy2);
        i2cbatchRead_pushButton->setFont(font10);

        horizontalLayout_9->addWidget(i2cbatchRead_pushButton);


        verticalLayout_5->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_14 = new QVBoxLayout(tab_3);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_11->addWidget(label_4);

        binSlavelineEdit = new QLineEdit(tab_3);
        binSlavelineEdit->setObjectName(QString::fromUtf8("binSlavelineEdit"));
        binSlavelineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_11->addWidget(binSlavelineEdit);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMaximumSize(QSize(76, 16777215));

        horizontalLayout_11->addWidget(label_14);

        binTypecomboBox = new QComboBox(tab_3);
        binTypecomboBox->setObjectName(QString::fromUtf8("binTypecomboBox"));
        sizePolicy2.setHeightForWidth(binTypecomboBox->sizePolicy().hasHeightForWidth());
        binTypecomboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(binTypecomboBox);


        verticalLayout_14->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font8);

        horizontalLayout_12->addWidget(label_8);

        binRegStartlineEdit = new QLineEdit(tab_3);
        binRegStartlineEdit->setObjectName(QString::fromUtf8("binRegStartlineEdit"));

        horizontalLayout_12->addWidget(binRegStartlineEdit);

        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_12->addWidget(label_7);

        binRegAddspinBox = new QSpinBox(tab_3);
        binRegAddspinBox->setObjectName(QString::fromUtf8("binRegAddspinBox"));
        binRegAddspinBox->setMinimum(1);
        binRegAddspinBox->setMaximum(4);
        binRegAddspinBox->setValue(1);

        horizontalLayout_12->addWidget(binRegAddspinBox);


        verticalLayout_14->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        binCountspinBox = new QSpinBox(tab_3);
        binCountspinBox->setObjectName(QString::fromUtf8("binCountspinBox"));
        binCountspinBox->setMinimum(0);
        binCountspinBox->setMaximum(10240);

        horizontalLayout_13->addWidget(binCountspinBox);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font8);

        horizontalLayout_13->addWidget(label_6);

        binDelayspinBox = new QSpinBox(tab_3);
        binDelayspinBox->setObjectName(QString::fromUtf8("binDelayspinBox"));
        binDelayspinBox->setMinimum(10);
        binDelayspinBox->setMaximum(30000);
        binDelayspinBox->setValue(3000);

        horizontalLayout_13->addWidget(binDelayspinBox);


        verticalLayout_14->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        binOpenpushButton = new QPushButton(tab_3);
        binOpenpushButton->setObjectName(QString::fromUtf8("binOpenpushButton"));
        QFont font11;
        font11.setPointSize(12);
        binOpenpushButton->setFont(font11);

        horizontalLayout_14->addWidget(binOpenpushButton);

        binSavepushButton = new QPushButton(tab_3);
        binSavepushButton->setObjectName(QString::fromUtf8("binSavepushButton"));
        binSavepushButton->setFont(font11);

        horizontalLayout_14->addWidget(binSavepushButton);

        binSavecheckBox = new QCheckBox(tab_3);
        binSavecheckBox->setObjectName(QString::fromUtf8("binSavecheckBox"));
        binSavecheckBox->setChecked(true);

        horizontalLayout_14->addWidget(binSavecheckBox);


        verticalLayout_14->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        binDataCreratepushButton = new QPushButton(tab_3);
        binDataCreratepushButton->setObjectName(QString::fromUtf8("binDataCreratepushButton"));
        binDataCreratepushButton->setFont(font8);

        horizontalLayout_16->addWidget(binDataCreratepushButton);

        binData00epushButton = new QPushButton(tab_3);
        binData00epushButton->setObjectName(QString::fromUtf8("binData00epushButton"));
        binData00epushButton->setFont(font8);

        horizontalLayout_16->addWidget(binData00epushButton);

        binDataFFpushButton = new QPushButton(tab_3);
        binDataFFpushButton->setObjectName(QString::fromUtf8("binDataFFpushButton"));
        binDataFFpushButton->setFont(font8);

        horizontalLayout_16->addWidget(binDataFFpushButton);


        verticalLayout_14->addLayout(horizontalLayout_16);

        binplainTextEdit = new QPlainTextEdit(tab_3);
        binplainTextEdit->setObjectName(QString::fromUtf8("binplainTextEdit"));
        sizePolicy1.setHeightForWidth(binplainTextEdit->sizePolicy().hasHeightForWidth());
        binplainTextEdit->setSizePolicy(sizePolicy1);
        binplainTextEdit->setFont(font9);
        binplainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        verticalLayout_14->addWidget(binplainTextEdit);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        binWritepushButton = new QPushButton(tab_3);
        binWritepushButton->setObjectName(QString::fromUtf8("binWritepushButton"));
        binWritepushButton->setFont(font11);

        horizontalLayout_15->addWidget(binWritepushButton);

        binReadpushButton = new QPushButton(tab_3);
        binReadpushButton->setObjectName(QString::fromUtf8("binReadpushButton"));
        binReadpushButton->setFont(font11);

        horizontalLayout_15->addWidget(binReadpushButton);


        verticalLayout_14->addLayout(horizontalLayout_15);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        infolabel = new QLabel(widget);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        sizePolicy2.setHeightForWidth(infolabel->sizePolicy().hasHeightForWidth());
        infolabel->setSizePolicy(sizePolicy2);
        infolabel->setFont(font);
        infolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(infolabel);

        hardwareop->setWidget(widget);
#ifndef QT_NO_SHORTCUT
        label_10->setBuddy(slavelineEdit);
        label_11->setBuddy(reglineEdit);
        label_12->setBuddy(datalineEdit);
        label_13->setBuddy(i2ctypecomboBox);
        label_14->setBuddy(i2ctypecomboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(hardwareop);

        tabWidget->setCurrentIndex(0);
        vol5VcomboBox->setCurrentIndex(2);
        vol12VcomboBox->setCurrentIndex(2);
        communicatetypecomboBox->setCurrentIndex(0);
        i2ctypecomboBox->setCurrentIndex(0);
        batchProtocalcomboBox->setCurrentIndex(0);
        binTypecomboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(hardwareop);
    } // setupUi

    void retranslateUi(QDockWidget *hardwareop)
    {
        hardwareop->setWindowTitle(QApplication::translate("hardwareop", "Hardware Operation Panel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("hardwareop", "Voltage", 0, QApplication::UnicodeUTF8));
        vol5VcomboBox->setItemText(2, QApplication::translate("hardwareop", "Not Set", 0, QApplication::UnicodeUTF8));

        vol12VcomboBox->setItemText(2, QApplication::translate("hardwareop", "Not Set", 0, QApplication::UnicodeUTF8));

        vlotsetpushButton->setText(QApplication::translate("hardwareop", "Set", 0, QApplication::UnicodeUTF8));
        voltreadpushButton->setText(QApplication::translate("hardwareop", "Get", 0, QApplication::UnicodeUTF8));
        voltMeasurepushButton->setText(QApplication::translate("hardwareop", "Measure", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("hardwareop", "PWND", 0, QApplication::UnicodeUTF8));
        pwndhighpushButton->setText(QApplication::translate("hardwareop", "High", 0, QApplication::UnicodeUTF8));
        pwndlowpushButton->setText(QApplication::translate("hardwareop", "Low", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("hardwareop", "RESET", 0, QApplication::UnicodeUTF8));
        resethighpushButton->setText(QApplication::translate("hardwareop", "High", 0, QApplication::UnicodeUTF8));
        resetlowpushButton->setText(QApplication::translate("hardwareop", "Low", 0, QApplication::UnicodeUTF8));
        mclkgroupBox->setTitle(QApplication::translate("hardwareop", "MCLK, Stream Protocal", 0, QApplication::UnicodeUTF8));
        setmclkpushButton->setText(QApplication::translate("hardwareop", "Set", 0, QApplication::UnicodeUTF8));
        setLanepushButton->setText(QApplication::translate("hardwareop", "Set", 0, QApplication::UnicodeUTF8));
        readmclkpushButton->setText(QApplication::translate("hardwareop", "Get", 0, QApplication::UnicodeUTF8));
        readLanepushButton->setText(QApplication::translate("hardwareop", "Get", 0, QApplication::UnicodeUTF8));
        vsync_checkBox->setText(QApplication::translate("hardwareop", "VSYNC Active High", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("hardwareop", "I2C,SPI", 0, QApplication::UnicodeUTF8));
        spiCSLowcheckBox->setText(QApplication::translate("hardwareop", "CS Low", 0, QApplication::UnicodeUTF8));
        spiLittleEndiancheckBox->setText(QApplication::translate("hardwareop", "Little Endian", 0, QApplication::UnicodeUTF8));
        communicatetypelabel->setText(QApplication::translate("hardwareop", "Protocal", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("hardwareop", "I2C Speed(KHz)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("hardwareop", "Slave(0x)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("hardwareop", "Reg(0x)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("hardwareop", "Data(0x)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("hardwareop", "I2C Type", 0, QApplication::UnicodeUTF8));
        slavelineEdit->setText(QApplication::translate("hardwareop", "6c", 0, QApplication::UnicodeUTF8));
        searchSlave_pushButton->setText(QApplication::translate("hardwareop", "...", 0, QApplication::UnicodeUTF8));
        reglineEdit->setText(QApplication::translate("hardwareop", "3501", 0, QApplication::UnicodeUTF8));
        datalineEdit->setText(QApplication::translate("hardwareop", "01", 0, QApplication::UnicodeUTF8));
        i2ctypecomboBox->clear();
        i2ctypecomboBox->insertItems(0, QStringList()
         << QApplication::translate("hardwareop", "0x0808", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0816", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1608", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1616", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1632", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1664", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0864", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0008", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0016", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0032", 0, QApplication::UnicodeUTF8)
        );
        i2cwritepushButton->setText(QApplication::translate("hardwareop", "Write", 0, QApplication::UnicodeUTF8));
        i2creadpushButton->setText(QApplication::translate("hardwareop", "Read", 0, QApplication::UnicodeUTF8));
        getGPIO_pushButton->setText(QApplication::translate("hardwareop", "Read", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("hardwareop", "Common", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("hardwareop", "Mode:", 0, QApplication::UnicodeUTF8));
        batchIICModecomboBox->clear();
        batchIICModecomboBox->insertItems(0, QStringList()
         << QApplication::translate("hardwareop", "Item By Item Write/Read", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "Batch Write/Read", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "Page Write/Read", 0, QApplication::UnicodeUTF8)
        );
        batchFormatpushButton->setText(QApplication::translate("hardwareop", "Format", 0, QApplication::UnicodeUTF8));
        communicatetypelabel_2->setText(QApplication::translate("hardwareop", "Protocal:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("hardwareop", "Speed(KHz)", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("hardwareop", "Delay(us):", 0, QApplication::UnicodeUTF8));
        pageStartAddrlabel->setText(QApplication::translate("hardwareop", "Page Start Addr(0x):", 0, QApplication::UnicodeUTF8));
        pageStartAddrlineEdit->setText(QApplication::translate("hardwareop", "0000", 0, QApplication::UnicodeUTF8));
        pageSlavelabel->setText(QApplication::translate("hardwareop", "Slave(0x):", 0, QApplication::UnicodeUTF8));
        batchSlavelineEdit->setText(QApplication::translate("hardwareop", "a0", 0, QApplication::UnicodeUTF8));
        pageSizelabel->setText(QApplication::translate("hardwareop", "Page Size:", 0, QApplication::UnicodeUTF8));
        batchEETypelabel->setText(QApplication::translate("hardwareop", "EE Type:", 0, QApplication::UnicodeUTF8));
        batchTestpushButton->setText(QApplication::translate("hardwareop", "Test", 0, QApplication::UnicodeUTF8));
        i2cbatchpushButton->setText(QApplication::translate("hardwareop", "Write", 0, QApplication::UnicodeUTF8));
        i2cbatchRead_pushButton->setText(QApplication::translate("hardwareop", "Read", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("hardwareop", "Batch I2C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("hardwareop", "Slave(0x):", 0, QApplication::UnicodeUTF8));
        binSlavelineEdit->setText(QApplication::translate("hardwareop", "a0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("hardwareop", "I2C Type:", 0, QApplication::UnicodeUTF8));
        binTypecomboBox->clear();
        binTypecomboBox->insertItems(0, QStringList()
         << QApplication::translate("hardwareop", "0x0808", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x0816", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1608", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1616", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hardwareop", "0x1632", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("hardwareop", "begin Addr(0x):", 0, QApplication::UnicodeUTF8));
        binRegStartlineEdit->setText(QApplication::translate("hardwareop", "0000", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("hardwareop", "Addr bits increment:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("hardwareop", "IIC Quantity:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("hardwareop", "Delay(us):", 0, QApplication::UnicodeUTF8));
        binOpenpushButton->setText(QApplication::translate("hardwareop", "Open BIN", 0, QApplication::UnicodeUTF8));
        binSavepushButton->setText(QApplication::translate("hardwareop", "Save BIN", 0, QApplication::UnicodeUTF8));
        binSavecheckBox->setText(QApplication::translate("hardwareop", "Clear && Save", 0, QApplication::UnicodeUTF8));
        binDataCreratepushButton->setText(QApplication::translate("hardwareop", "incremental data", 0, QApplication::UnicodeUTF8));
        binData00epushButton->setText(QApplication::translate("hardwareop", "generated 0x0", 0, QApplication::UnicodeUTF8));
        binDataFFpushButton->setText(QApplication::translate("hardwareop", "generated 0xFF", 0, QApplication::UnicodeUTF8));
        binWritepushButton->setText(QApplication::translate("hardwareop", "Write", 0, QApplication::UnicodeUTF8));
        binReadpushButton->setText(QApplication::translate("hardwareop", "Read", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("hardwareop", "Batch BIN", 0, QApplication::UnicodeUTF8));
        infolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hardwareop: public Ui_hardwareop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDWAREOP_H
