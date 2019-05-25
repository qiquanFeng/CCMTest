/********************************************************************************
** Form generated from reading UI file 'qmanualtool.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMANUALTOOL_H
#define UI_QMANUALTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qmanualtool
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *exposureTimehorizontalSlider;
    QSpinBox *exposurespinBox;
    QPushButton *exposurepushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *motorhorizontalSlider;
    QSpinBox *motorspinBox;
    QPushButton *motorpushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *motorTestspinBox;
    QPushButton *motorTestButton;
    QPushButton *motorClearCount;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSlider *globalGainhorizontalSlider;
    QDoubleSpinBox *globalGaindoubleSpinBox;
    QPushButton *globalGainpushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *ColorcheckBox;
    QCheckBox *BrightnesscheckBox;
    QCheckBox *MtfcheckBox;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *BeginpushButton;
    QPushButton *StoppushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QSpinBox *LeftspinBox;
    QLabel *label_11;
    QSpinBox *RightspinBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QSpinBox *TopspinBox;
    QLabel *label_10;
    QSpinBox *BottomspinBox;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_8;
    QLabel *YLabelInfo;
    QLabel *B2GLabelInfo;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_6;
    QLabel *RLabelInfo;
    QLabel *R2GLabelInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_14;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_4;
    QLabel *GLabelInfo;
    QLabel *MTFLabelInfo;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLabel *BLabelInfo;
    QSpacerItem *verticalSpacer;
    QLabel *infolabel;

    void setupUi(QDockWidget *qmanualtool)
    {
        if (qmanualtool->objectName().isEmpty())
            qmanualtool->setObjectName(QString::fromUtf8("qmanualtool"));
        qmanualtool->resize(667, 413);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(9);
        qmanualtool->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        qmanualtool->setWindowIcon(icon);
        qmanualtool->setFloating(true);
        qmanualtool->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        qmanualtool->setWindowTitle(QString::fromUtf8("qmanualtool"));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        exposureTimehorizontalSlider = new QSlider(widget);
        exposureTimehorizontalSlider->setObjectName(QString::fromUtf8("exposureTimehorizontalSlider"));
        exposureTimehorizontalSlider->setOrientation(Qt::Horizontal);
        exposureTimehorizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(exposureTimehorizontalSlider);

        exposurespinBox = new QSpinBox(widget);
        exposurespinBox->setObjectName(QString::fromUtf8("exposurespinBox"));
        exposurespinBox->setMinimumSize(QSize(52, 0));
        exposurespinBox->setMaximumSize(QSize(52, 16777215));
        exposurespinBox->setMaximum(999999);

        horizontalLayout->addWidget(exposurespinBox);

        exposurepushButton = new QPushButton(widget);
        exposurepushButton->setObjectName(QString::fromUtf8("exposurepushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exposurepushButton->sizePolicy().hasHeightForWidth());
        exposurepushButton->setSizePolicy(sizePolicy1);
        exposurepushButton->setMinimumSize(QSize(40, 0));
        exposurepushButton->setMaximumSize(QSize(40, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        exposurepushButton->setFont(font2);

        horizontalLayout->addWidget(exposurepushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        motorhorizontalSlider = new QSlider(widget);
        motorhorizontalSlider->setObjectName(QString::fromUtf8("motorhorizontalSlider"));
        motorhorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(motorhorizontalSlider);

        motorspinBox = new QSpinBox(widget);
        motorspinBox->setObjectName(QString::fromUtf8("motorspinBox"));
        motorspinBox->setMinimumSize(QSize(52, 0));
        motorspinBox->setMaximumSize(QSize(52, 16777215));
        motorspinBox->setMinimum(-1024);
        motorspinBox->setMaximum(1024);

        horizontalLayout_2->addWidget(motorspinBox);

        motorpushButton = new QPushButton(widget);
        motorpushButton->setObjectName(QString::fromUtf8("motorpushButton"));
        sizePolicy1.setHeightForWidth(motorpushButton->sizePolicy().hasHeightForWidth());
        motorpushButton->setSizePolicy(sizePolicy1);
        motorpushButton->setMinimumSize(QSize(40, 0));
        motorpushButton->setMaximumSize(QSize(40, 16777215));
        motorpushButton->setFont(font2);

        horizontalLayout_2->addWidget(motorpushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        motorTestspinBox = new QSpinBox(widget);
        motorTestspinBox->setObjectName(QString::fromUtf8("motorTestspinBox"));
        motorTestspinBox->setMinimumSize(QSize(52, 0));
        motorTestspinBox->setMaximumSize(QSize(52, 16777215));
        motorTestspinBox->setMinimum(0);
        motorTestspinBox->setMaximum(10000000);

        horizontalLayout_3->addWidget(motorTestspinBox);

        motorTestButton = new QPushButton(widget);
        motorTestButton->setObjectName(QString::fromUtf8("motorTestButton"));
        sizePolicy1.setHeightForWidth(motorTestButton->sizePolicy().hasHeightForWidth());
        motorTestButton->setSizePolicy(sizePolicy1);
        motorTestButton->setMinimumSize(QSize(100, 0));
        motorTestButton->setMaximumSize(QSize(40, 16777215));
        motorTestButton->setFont(font2);

        horizontalLayout_3->addWidget(motorTestButton);

        motorClearCount = new QPushButton(widget);
        motorClearCount->setObjectName(QString::fromUtf8("motorClearCount"));
        sizePolicy1.setHeightForWidth(motorClearCount->sizePolicy().hasHeightForWidth());
        motorClearCount->setSizePolicy(sizePolicy1);
        motorClearCount->setMinimumSize(QSize(40, 0));
        motorClearCount->setMaximumSize(QSize(40, 16777215));
        motorClearCount->setFont(font2);

        horizontalLayout_3->addWidget(motorClearCount);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(90, 0));
        label_5->setMaximumSize(QSize(90, 16777215));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        globalGainhorizontalSlider = new QSlider(widget);
        globalGainhorizontalSlider->setObjectName(QString::fromUtf8("globalGainhorizontalSlider"));
        globalGainhorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(globalGainhorizontalSlider);

        globalGaindoubleSpinBox = new QDoubleSpinBox(widget);
        globalGaindoubleSpinBox->setObjectName(QString::fromUtf8("globalGaindoubleSpinBox"));

        horizontalLayout_4->addWidget(globalGaindoubleSpinBox);

        globalGainpushButton = new QPushButton(widget);
        globalGainpushButton->setObjectName(QString::fromUtf8("globalGainpushButton"));
        sizePolicy1.setHeightForWidth(globalGainpushButton->sizePolicy().hasHeightForWidth());
        globalGainpushButton->setSizePolicy(sizePolicy1);
        globalGainpushButton->setMinimumSize(QSize(40, 0));
        globalGainpushButton->setMaximumSize(QSize(40, 16777215));
        globalGainpushButton->setFont(font2);

        horizontalLayout_4->addWidget(globalGainpushButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ColorcheckBox = new QCheckBox(groupBox);
        ColorcheckBox->setObjectName(QString::fromUtf8("ColorcheckBox"));
        ColorcheckBox->setChecked(true);

        horizontalLayout_8->addWidget(ColorcheckBox);

        BrightnesscheckBox = new QCheckBox(groupBox);
        BrightnesscheckBox->setObjectName(QString::fromUtf8("BrightnesscheckBox"));
        BrightnesscheckBox->setChecked(true);

        horizontalLayout_8->addWidget(BrightnesscheckBox);

        MtfcheckBox = new QCheckBox(groupBox);
        MtfcheckBox->setObjectName(QString::fromUtf8("MtfcheckBox"));

        horizontalLayout_8->addWidget(MtfcheckBox);


        horizontalLayout_12->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        BeginpushButton = new QPushButton(groupBox);
        BeginpushButton->setObjectName(QString::fromUtf8("BeginpushButton"));

        horizontalLayout_11->addWidget(BeginpushButton);

        StoppushButton = new QPushButton(groupBox);
        StoppushButton->setObjectName(QString::fromUtf8("StoppushButton"));

        horizontalLayout_11->addWidget(StoppushButton);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_2->addLayout(horizontalLayout_12);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        LeftspinBox = new QSpinBox(groupBox_2);
        LeftspinBox->setObjectName(QString::fromUtf8("LeftspinBox"));
        LeftspinBox->setMaximum(5000);
        LeftspinBox->setValue(100);

        horizontalLayout_9->addWidget(LeftspinBox);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_9->addWidget(label_11);

        RightspinBox = new QSpinBox(groupBox_2);
        RightspinBox->setObjectName(QString::fromUtf8("RightspinBox"));
        RightspinBox->setMaximum(5000);
        RightspinBox->setValue(100);

        horizontalLayout_9->addWidget(RightspinBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        TopspinBox = new QSpinBox(groupBox_2);
        TopspinBox->setObjectName(QString::fromUtf8("TopspinBox"));
        TopspinBox->setMaximum(5000);
        TopspinBox->setValue(100);

        horizontalLayout_10->addWidget(TopspinBox);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        BottomspinBox = new QSpinBox(groupBox_2);
        BottomspinBox->setObjectName(QString::fromUtf8("BottomspinBox"));
        BottomspinBox->setMaximum(5000);
        BottomspinBox->setValue(100);

        horizontalLayout_10->addWidget(BottomspinBox);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font3;
        font3.setPointSize(12);
        groupBox_3->setFont(font3);
        horizontalLayout_14 = new QHBoxLayout(groupBox_3);
        horizontalLayout_14->setSpacing(3);
        horizontalLayout_14->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setText(QString::fromUtf8("Y:"));

        verticalLayout_9->addWidget(label_12);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setText(QString::fromUtf8("B/G:"));

        verticalLayout_9->addWidget(label_17);


        horizontalLayout_14->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        YLabelInfo = new QLabel(groupBox_3);
        YLabelInfo->setObjectName(QString::fromUtf8("YLabelInfo"));
        sizePolicy.setHeightForWidth(YLabelInfo->sizePolicy().hasHeightForWidth());
        YLabelInfo->setSizePolicy(sizePolicy);
        YLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_8->addWidget(YLabelInfo);

        B2GLabelInfo = new QLabel(groupBox_3);
        B2GLabelInfo->setObjectName(QString::fromUtf8("B2GLabelInfo"));
        sizePolicy.setHeightForWidth(B2GLabelInfo->sizePolicy().hasHeightForWidth());
        B2GLabelInfo->setSizePolicy(sizePolicy);
        B2GLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_8->addWidget(B2GLabelInfo);


        horizontalLayout_14->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setText(QString::fromUtf8("R:"));

        verticalLayout_7->addWidget(label_13);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setText(QString::fromUtf8("R/G:"));

        verticalLayout_7->addWidget(label_18);


        horizontalLayout_14->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        RLabelInfo = new QLabel(groupBox_3);
        RLabelInfo->setObjectName(QString::fromUtf8("RLabelInfo"));
        sizePolicy.setHeightForWidth(RLabelInfo->sizePolicy().hasHeightForWidth());
        RLabelInfo->setSizePolicy(sizePolicy);
        RLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_6->addWidget(RLabelInfo);

        R2GLabelInfo = new QLabel(groupBox_3);
        R2GLabelInfo->setObjectName(QString::fromUtf8("R2GLabelInfo"));
        sizePolicy.setHeightForWidth(R2GLabelInfo->sizePolicy().hasHeightForWidth());
        R2GLabelInfo->setSizePolicy(sizePolicy);
        R2GLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_6->addWidget(R2GLabelInfo);


        horizontalLayout_14->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setText(QString::fromUtf8("G:"));

        verticalLayout_5->addWidget(label_14);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setText(QString::fromUtf8("MTF:"));

        verticalLayout_5->addWidget(label_19);


        horizontalLayout_14->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        GLabelInfo = new QLabel(groupBox_3);
        GLabelInfo->setObjectName(QString::fromUtf8("GLabelInfo"));
        sizePolicy.setHeightForWidth(GLabelInfo->sizePolicy().hasHeightForWidth());
        GLabelInfo->setSizePolicy(sizePolicy);
        GLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_4->addWidget(GLabelInfo);

        MTFLabelInfo = new QLabel(groupBox_3);
        MTFLabelInfo->setObjectName(QString::fromUtf8("MTFLabelInfo"));
        sizePolicy.setHeightForWidth(MTFLabelInfo->sizePolicy().hasHeightForWidth());
        MTFLabelInfo->setSizePolicy(sizePolicy);
        MTFLabelInfo->setFrameShape(QFrame::StyledPanel);

        verticalLayout_4->addWidget(MTFLabelInfo);


        horizontalLayout_14->addLayout(verticalLayout_4);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setText(QString::fromUtf8("B:"));

        horizontalLayout_13->addWidget(label_15);

        BLabelInfo = new QLabel(groupBox_3);
        BLabelInfo->setObjectName(QString::fromUtf8("BLabelInfo"));
        sizePolicy.setHeightForWidth(BLabelInfo->sizePolicy().hasHeightForWidth());
        BLabelInfo->setSizePolicy(sizePolicy);
        BLabelInfo->setMinimumSize(QSize(80, 0));
        BLabelInfo->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_13->addWidget(BLabelInfo);


        verticalLayout_10->addLayout(horizontalLayout_13);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer);


        horizontalLayout_14->addLayout(verticalLayout_10);


        verticalLayout_2->addWidget(groupBox_3);


        verticalLayout_3->addWidget(groupBox);

        infolabel = new QLabel(widget);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        sizePolicy.setHeightForWidth(infolabel->sizePolicy().hasHeightForWidth());
        infolabel->setSizePolicy(sizePolicy);
        infolabel->setFont(font2);
        infolabel->setFrameShape(QFrame::StyledPanel);
        infolabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(infolabel);

        qmanualtool->setWidget(widget);

        retranslateUi(qmanualtool);

        QMetaObject::connectSlotsByName(qmanualtool);
    } // setupUi

    void retranslateUi(QDockWidget *qmanualtool)
    {
        label->setText(QApplication::translate("qmanualtool", "Exposure:", 0, QApplication::UnicodeUTF8));
        exposurepushButton->setText(QApplication::translate("qmanualtool", "Set", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("qmanualtool", "Motor:", 0, QApplication::UnicodeUTF8));
        motorpushButton->setText(QApplication::translate("qmanualtool", "Set", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("qmanualtool", "MotorTest:", 0, QApplication::UnicodeUTF8));
        motorTestButton->setText(QApplication::translate("qmanualtool", "Start", 0, QApplication::UnicodeUTF8));
        motorClearCount->setText(QApplication::translate("qmanualtool", "Clear", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("qmanualtool", "Global GAIN:", 0, QApplication::UnicodeUTF8));
        globalGainpushButton->setText(QApplication::translate("qmanualtool", "Set", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("qmanualtool", "Real-time Monitoring Paramater", 0, QApplication::UnicodeUTF8));
        ColorcheckBox->setText(QApplication::translate("qmanualtool", "Color", 0, QApplication::UnicodeUTF8));
        BrightnesscheckBox->setText(QApplication::translate("qmanualtool", "Brightness", 0, QApplication::UnicodeUTF8));
        MtfcheckBox->setText(QApplication::translate("qmanualtool", "MTF", 0, QApplication::UnicodeUTF8));
        BeginpushButton->setText(QApplication::translate("qmanualtool", "Begin", 0, QApplication::UnicodeUTF8));
        StoppushButton->setText(QApplication::translate("qmanualtool", "End", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("qmanualtool", "ROI Paramater", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("qmanualtool", "Left", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("qmanualtool", "Right", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("qmanualtool", "Top", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("qmanualtool", "Bottom", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("qmanualtool", "Result", 0, QApplication::UnicodeUTF8));
        YLabelInfo->setText(QString());
        B2GLabelInfo->setText(QString());
        RLabelInfo->setText(QString());
        R2GLabelInfo->setText(QString());
        GLabelInfo->setText(QString());
        MTFLabelInfo->setText(QString());
        BLabelInfo->setText(QString());
        infolabel->setText(QString());
        Q_UNUSED(qmanualtool);
    } // retranslateUi

};

namespace Ui {
    class qmanualtool: public Ui_qmanualtool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMANUALTOOL_H
