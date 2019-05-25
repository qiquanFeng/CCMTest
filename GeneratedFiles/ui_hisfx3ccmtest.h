/********************************************************************************
** Form generated from reading UI file 'hisfx3ccmtest.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISFX3CCMTEST_H
#define UI_HISFX3CCMTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QHImageFrame.h"

QT_BEGIN_NAMESPACE

class Ui_HisFX3CCMTestClass
{
public:
    QAction *configaction;
    QAction *operatorbasicinfoaction;
    QAction *enableconfigaction;
    QAction *disableconfigaction;
    QAction *csvManageaction;
    QAction *showLeftaction;
    QAction *showRightaction;
    QAction *showBottomInfoaction;
    QAction *showBottomLineaction;
    QAction *showItem2EndResultaction;
    QAction *showEndResult2Imageaction;
    QAction *enableDebugModeaction;
    QAction *enableOfflineaction;
    QAction *currentCalaction;
    QAction *OSCalibrationaction;
    QAction *simpleChineseaction;
    QAction *englishaction;
    QAction *actionCoordinate_Convertion;
    QAction *actionVersion;
    QAction *actionChoose_Grabber;
    QAction *actionUpdate_FPGA_FW;
    QAction *actionVoltage_Calibration;
    QAction *actionChange_Password;
    QAction *actionImage_Show;
    QAction *actionSave_Lock_UI;
    QAction *actionChoose_OperatorMode;
    QAction *actionManual_Mode_A;
    QAction *actionShow_Operation_Panel;
    QAction *actionShow_Info_Panel;
    QAction *actionPanel_moveable;
    QAction *actionShow_Text_Panel;
    QAction *actionReset_UI_Layout;
    QAction *actionBlemish_C_Tuning;
    QAction *actionShoactionShow_TestItem;
    QAction *actionShow_Statis_Panel;
    QAction *actionTCP_IPtransmission;
    QAction *actionImage;
    QAction *actionset_path;
    QAction *actionTest_Exposure_Delay;
    QAction *actionJsv_to_csv;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *fx3label;
    QLabel *slavelabel;
    QLabel *configlabel;
    QLabel *fpslabel;
    QLabel *COMlabel;
    QLabel *COM2label;
    QComboBox *imageshowPolicycomboBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHImageFrame *imageframe;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QMenu *menuConfig;
    QMenu *menu_OperatorMode;
    QMenu *menuUI;
    QMenu *menuDebug;

    void setupUi(QMainWindow *HisFX3CCMTestClass)
    {
        if (HisFX3CCMTestClass->objectName().isEmpty())
            HisFX3CCMTestClass->setObjectName(QString::fromUtf8("HisFX3CCMTestClass"));
        HisFX3CCMTestClass->resize(905, 716);
        HisFX3CCMTestClass->setMinimumSize(QSize(320, 240));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        HisFX3CCMTestClass->setFont(font);
        HisFX3CCMTestClass->setFocusPolicy(Qt::StrongFocus);
        HisFX3CCMTestClass->setContextMenuPolicy(Qt::NoContextMenu);
        HisFX3CCMTestClass->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        configaction = new QAction(HisFX3CCMTestClass);
        configaction->setObjectName(QString::fromUtf8("configaction"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        configaction->setFont(font1);
        operatorbasicinfoaction = new QAction(HisFX3CCMTestClass);
        operatorbasicinfoaction->setObjectName(QString::fromUtf8("operatorbasicinfoaction"));
        operatorbasicinfoaction->setFont(font);
        enableconfigaction = new QAction(HisFX3CCMTestClass);
        enableconfigaction->setObjectName(QString::fromUtf8("enableconfigaction"));
        enableconfigaction->setFont(font1);
        disableconfigaction = new QAction(HisFX3CCMTestClass);
        disableconfigaction->setObjectName(QString::fromUtf8("disableconfigaction"));
        disableconfigaction->setFont(font1);
        csvManageaction = new QAction(HisFX3CCMTestClass);
        csvManageaction->setObjectName(QString::fromUtf8("csvManageaction"));
        csvManageaction->setFont(font1);
        showLeftaction = new QAction(HisFX3CCMTestClass);
        showLeftaction->setObjectName(QString::fromUtf8("showLeftaction"));
        showLeftaction->setCheckable(true);
        showLeftaction->setChecked(true);
        showLeftaction->setFont(font1);
        showRightaction = new QAction(HisFX3CCMTestClass);
        showRightaction->setObjectName(QString::fromUtf8("showRightaction"));
        showRightaction->setCheckable(true);
        showRightaction->setChecked(true);
        showRightaction->setFont(font);
        showBottomInfoaction = new QAction(HisFX3CCMTestClass);
        showBottomInfoaction->setObjectName(QString::fromUtf8("showBottomInfoaction"));
        showBottomInfoaction->setCheckable(true);
        showBottomInfoaction->setChecked(true);
        showBottomInfoaction->setFont(font);
        showBottomLineaction = new QAction(HisFX3CCMTestClass);
        showBottomLineaction->setObjectName(QString::fromUtf8("showBottomLineaction"));
        showBottomLineaction->setCheckable(true);
        showBottomLineaction->setChecked(true);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        showBottomLineaction->setFont(font2);
        showItem2EndResultaction = new QAction(HisFX3CCMTestClass);
        showItem2EndResultaction->setObjectName(QString::fromUtf8("showItem2EndResultaction"));
        showItem2EndResultaction->setCheckable(true);
        showItem2EndResultaction->setChecked(true);
        showItem2EndResultaction->setFont(font1);
        showEndResult2Imageaction = new QAction(HisFX3CCMTestClass);
        showEndResult2Imageaction->setObjectName(QString::fromUtf8("showEndResult2Imageaction"));
        showEndResult2Imageaction->setCheckable(true);
        showEndResult2Imageaction->setChecked(true);
        showEndResult2Imageaction->setFont(font1);
        enableDebugModeaction = new QAction(HisFX3CCMTestClass);
        enableDebugModeaction->setObjectName(QString::fromUtf8("enableDebugModeaction"));
        enableDebugModeaction->setCheckable(true);
        enableDebugModeaction->setFont(font1);
        enableOfflineaction = new QAction(HisFX3CCMTestClass);
        enableOfflineaction->setObjectName(QString::fromUtf8("enableOfflineaction"));
        enableOfflineaction->setCheckable(true);
        enableOfflineaction->setFont(font1);
        currentCalaction = new QAction(HisFX3CCMTestClass);
        currentCalaction->setObjectName(QString::fromUtf8("currentCalaction"));
        currentCalaction->setFont(font1);
        OSCalibrationaction = new QAction(HisFX3CCMTestClass);
        OSCalibrationaction->setObjectName(QString::fromUtf8("OSCalibrationaction"));
        OSCalibrationaction->setFont(font1);
        simpleChineseaction = new QAction(HisFX3CCMTestClass);
        simpleChineseaction->setObjectName(QString::fromUtf8("simpleChineseaction"));
        simpleChineseaction->setCheckable(true);
        simpleChineseaction->setChecked(true);
        simpleChineseaction->setFont(font);
        englishaction = new QAction(HisFX3CCMTestClass);
        englishaction->setObjectName(QString::fromUtf8("englishaction"));
        englishaction->setCheckable(true);
        englishaction->setFont(font);
        actionCoordinate_Convertion = new QAction(HisFX3CCMTestClass);
        actionCoordinate_Convertion->setObjectName(QString::fromUtf8("actionCoordinate_Convertion"));
        actionCoordinate_Convertion->setFont(font1);
        actionVersion = new QAction(HisFX3CCMTestClass);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        actionVersion->setFont(font1);
        actionChoose_Grabber = new QAction(HisFX3CCMTestClass);
        actionChoose_Grabber->setObjectName(QString::fromUtf8("actionChoose_Grabber"));
        actionChoose_Grabber->setFont(font1);
        actionUpdate_FPGA_FW = new QAction(HisFX3CCMTestClass);
        actionUpdate_FPGA_FW->setObjectName(QString::fromUtf8("actionUpdate_FPGA_FW"));
        actionUpdate_FPGA_FW->setFont(font1);
        actionVoltage_Calibration = new QAction(HisFX3CCMTestClass);
        actionVoltage_Calibration->setObjectName(QString::fromUtf8("actionVoltage_Calibration"));
        actionVoltage_Calibration->setFont(font1);
        actionChange_Password = new QAction(HisFX3CCMTestClass);
        actionChange_Password->setObjectName(QString::fromUtf8("actionChange_Password"));
        actionChange_Password->setFont(font1);
        actionImage_Show = new QAction(HisFX3CCMTestClass);
        actionImage_Show->setObjectName(QString::fromUtf8("actionImage_Show"));
        actionImage_Show->setFont(font1);
        actionSave_Lock_UI = new QAction(HisFX3CCMTestClass);
        actionSave_Lock_UI->setObjectName(QString::fromUtf8("actionSave_Lock_UI"));
        actionSave_Lock_UI->setFont(font1);
        actionChoose_OperatorMode = new QAction(HisFX3CCMTestClass);
        actionChoose_OperatorMode->setObjectName(QString::fromUtf8("actionChoose_OperatorMode"));
        actionChoose_OperatorMode->setFont(font1);
        actionManual_Mode_A = new QAction(HisFX3CCMTestClass);
        actionManual_Mode_A->setObjectName(QString::fromUtf8("actionManual_Mode_A"));
        actionManual_Mode_A->setFont(font1);
        actionShow_Operation_Panel = new QAction(HisFX3CCMTestClass);
        actionShow_Operation_Panel->setObjectName(QString::fromUtf8("actionShow_Operation_Panel"));
        actionShow_Operation_Panel->setFont(font1);
        actionShow_Info_Panel = new QAction(HisFX3CCMTestClass);
        actionShow_Info_Panel->setObjectName(QString::fromUtf8("actionShow_Info_Panel"));
        actionShow_Info_Panel->setFont(font1);
        actionPanel_moveable = new QAction(HisFX3CCMTestClass);
        actionPanel_moveable->setObjectName(QString::fromUtf8("actionPanel_moveable"));
        actionPanel_moveable->setCheckable(true);
        actionPanel_moveable->setFont(font1);
        actionShow_Text_Panel = new QAction(HisFX3CCMTestClass);
        actionShow_Text_Panel->setObjectName(QString::fromUtf8("actionShow_Text_Panel"));
        actionShow_Text_Panel->setFont(font1);
        actionReset_UI_Layout = new QAction(HisFX3CCMTestClass);
        actionReset_UI_Layout->setObjectName(QString::fromUtf8("actionReset_UI_Layout"));
        actionReset_UI_Layout->setFont(font1);
        actionBlemish_C_Tuning = new QAction(HisFX3CCMTestClass);
        actionBlemish_C_Tuning->setObjectName(QString::fromUtf8("actionBlemish_C_Tuning"));
        actionBlemish_C_Tuning->setFont(font1);
        actionShoactionShow_TestItem = new QAction(HisFX3CCMTestClass);
        actionShoactionShow_TestItem->setObjectName(QString::fromUtf8("actionShoactionShow_TestItem"));
        actionShoactionShow_TestItem->setFont(font1);
        actionShow_Statis_Panel = new QAction(HisFX3CCMTestClass);
        actionShow_Statis_Panel->setObjectName(QString::fromUtf8("actionShow_Statis_Panel"));
        actionShow_Statis_Panel->setFont(font1);
        actionTCP_IPtransmission = new QAction(HisFX3CCMTestClass);
        actionTCP_IPtransmission->setObjectName(QString::fromUtf8("actionTCP_IPtransmission"));
        actionImage = new QAction(HisFX3CCMTestClass);
        actionImage->setObjectName(QString::fromUtf8("actionImage"));
        actionImage->setFont(font1);
        actionset_path = new QAction(HisFX3CCMTestClass);
        actionset_path->setObjectName(QString::fromUtf8("actionset_path"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        actionset_path->setFont(font3);
        actionTest_Exposure_Delay = new QAction(HisFX3CCMTestClass);
        actionTest_Exposure_Delay->setObjectName(QString::fromUtf8("actionTest_Exposure_Delay"));
        actionTest_Exposure_Delay->setFont(font1);
        actionJsv_to_csv = new QAction(HisFX3CCMTestClass);
        actionJsv_to_csv->setObjectName(QString::fromUtf8("actionJsv_to_csv"));
        centralWidget = new QWidget(HisFX3CCMTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fx3label = new QLabel(centralWidget);
        fx3label->setObjectName(QString::fromUtf8("fx3label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fx3label->sizePolicy().hasHeightForWidth());
        fx3label->setSizePolicy(sizePolicy);
        fx3label->setMinimumSize(QSize(25, 25));
        fx3label->setMaximumSize(QSize(25, 25));
        fx3label->setContextMenuPolicy(Qt::NoContextMenu);
        fx3label->setFrameShape(QFrame::StyledPanel);
        fx3label->setFrameShadow(QFrame::Sunken);
        fx3label->setText(QString::fromUtf8(""));
        fx3label->setScaledContents(true);
        fx3label->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(fx3label);

        slavelabel = new QLabel(centralWidget);
        slavelabel->setObjectName(QString::fromUtf8("slavelabel"));
        sizePolicy.setHeightForWidth(slavelabel->sizePolicy().hasHeightForWidth());
        slavelabel->setSizePolicy(sizePolicy);
        slavelabel->setMinimumSize(QSize(25, 25));
        slavelabel->setMaximumSize(QSize(25, 25));
        slavelabel->setContextMenuPolicy(Qt::NoContextMenu);
        slavelabel->setFrameShape(QFrame::StyledPanel);
        slavelabel->setFrameShadow(QFrame::Sunken);
        slavelabel->setText(QString::fromUtf8(""));
        slavelabel->setScaledContents(true);
        slavelabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(slavelabel);

        configlabel = new QLabel(centralWidget);
        configlabel->setObjectName(QString::fromUtf8("configlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(configlabel->sizePolicy().hasHeightForWidth());
        configlabel->setSizePolicy(sizePolicy1);
        configlabel->setMinimumSize(QSize(50, 25));
        configlabel->setMaximumSize(QSize(350, 25));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        configlabel->setFont(font4);
        configlabel->setContextMenuPolicy(Qt::NoContextMenu);
        configlabel->setFrameShape(QFrame::StyledPanel);
        configlabel->setFrameShadow(QFrame::Sunken);
        configlabel->setLineWidth(0);
        configlabel->setText(QString::fromUtf8(""));
        configlabel->setTextFormat(Qt::AutoText);
        configlabel->setScaledContents(true);
        configlabel->setWordWrap(false);
        configlabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(configlabel);

        fpslabel = new QLabel(centralWidget);
        fpslabel->setObjectName(QString::fromUtf8("fpslabel"));
        sizePolicy.setHeightForWidth(fpslabel->sizePolicy().hasHeightForWidth());
        fpslabel->setSizePolicy(sizePolicy);
        fpslabel->setMinimumSize(QSize(126, 25));
        fpslabel->setMaximumSize(QSize(126, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(9);
        fpslabel->setFont(font5);
        fpslabel->setContextMenuPolicy(Qt::NoContextMenu);
        fpslabel->setFrameShape(QFrame::StyledPanel);
        fpslabel->setFrameShadow(QFrame::Sunken);
        fpslabel->setText(QString::fromUtf8("fps:000.0/000.0/000.0"));
        fpslabel->setTextFormat(Qt::PlainText);
        fpslabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(fpslabel);

        COMlabel = new QLabel(centralWidget);
        COMlabel->setObjectName(QString::fromUtf8("COMlabel"));
        sizePolicy.setHeightForWidth(COMlabel->sizePolicy().hasHeightForWidth());
        COMlabel->setSizePolicy(sizePolicy);
        COMlabel->setMinimumSize(QSize(25, 25));
        COMlabel->setMaximumSize(QSize(25, 25));
        COMlabel->setContextMenuPolicy(Qt::NoContextMenu);
        COMlabel->setFrameShape(QFrame::StyledPanel);
        COMlabel->setFrameShadow(QFrame::Sunken);
        COMlabel->setText(QString::fromUtf8(""));
        COMlabel->setScaledContents(true);
        COMlabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(COMlabel);

        COM2label = new QLabel(centralWidget);
        COM2label->setObjectName(QString::fromUtf8("COM2label"));
        sizePolicy.setHeightForWidth(COM2label->sizePolicy().hasHeightForWidth());
        COM2label->setSizePolicy(sizePolicy);
        COM2label->setMinimumSize(QSize(25, 25));
        COM2label->setMaximumSize(QSize(25, 25));
        COM2label->setContextMenuPolicy(Qt::NoContextMenu);
        COM2label->setFrameShape(QFrame::StyledPanel);
        COM2label->setFrameShadow(QFrame::Sunken);
        COM2label->setText(QString::fromUtf8(""));
        COM2label->setScaledContents(true);
        COM2label->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(COM2label);

        imageshowPolicycomboBox = new QComboBox(centralWidget);
        imageshowPolicycomboBox->addItem(QString());
        imageshowPolicycomboBox->addItem(QString());
        imageshowPolicycomboBox->addItem(QString::fromUtf8("1.0X"));
        imageshowPolicycomboBox->addItem(QString::fromUtf8("2.0X"));
        imageshowPolicycomboBox->addItem(QString::fromUtf8("4.0X"));
        imageshowPolicycomboBox->setObjectName(QString::fromUtf8("imageshowPolicycomboBox"));
        QFont font6;
        font6.setPointSize(10);
        imageshowPolicycomboBox->setFont(font6);
        imageshowPolicycomboBox->setFocusPolicy(Qt::NoFocus);
        imageshowPolicycomboBox->setContextMenuPolicy(Qt::NoContextMenu);
        imageshowPolicycomboBox->setInsertPolicy(QComboBox::NoInsert);
        imageshowPolicycomboBox->setFrame(true);

        horizontalLayout->addWidget(imageshowPolicycomboBox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        imageframe = new QHImageFrame(centralWidget);
        imageframe->setObjectName(QString::fromUtf8("imageframe"));
        imageframe->setFrameShape(QFrame::StyledPanel);
        imageframe->setFrameShadow(QFrame::Plain);
        imageframe->setLineWidth(1);
        imageframe->setMidLineWidth(0);

        horizontalLayout_2->addWidget(imageframe);

        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalScrollBar->sizePolicy().hasHeightForWidth());
        verticalScrollBar->setSizePolicy(sizePolicy2);
        verticalScrollBar->setMinimumSize(QSize(0, 450));
        verticalScrollBar->setMaximumSize(QSize(16777215, 10000));
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalScrollBar);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        sizePolicy1.setHeightForWidth(horizontalScrollBar->sizePolicy().hasHeightForWidth());
        horizontalScrollBar->setSizePolicy(sizePolicy1);
        horizontalScrollBar->setMinimumSize(QSize(600, 0));
        horizontalScrollBar->setMaximumSize(QSize(10000, 16777215));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        HisFX3CCMTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HisFX3CCMTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 905, 28));
        menuBar->setFont(font1);
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QString::fromUtf8("menuConfig"));
        menu_OperatorMode = new QMenu(menuBar);
        menu_OperatorMode->setObjectName(QString::fromUtf8("menu_OperatorMode"));
        menuUI = new QMenu(menuBar);
        menuUI->setObjectName(QString::fromUtf8("menuUI"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        HisFX3CCMTestClass->setMenuBar(menuBar);

        menuBar->addAction(menuConfig->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menu_OperatorMode->menuAction());
        menuBar->addAction(menuUI->menuAction());
        menuConfig->addAction(configaction);
        menuConfig->addSeparator();
        menu_OperatorMode->addAction(actionManual_Mode_A);
        menuUI->addAction(actionShow_Operation_Panel);
        menuUI->addAction(actionShow_Info_Panel);
        menuUI->addAction(actionShow_Text_Panel);
        menuUI->addAction(actionShow_Statis_Panel);
        menuUI->addAction(actionShoactionShow_TestItem);
        menuDebug->addAction(actionImage);
        menuDebug->addSeparator();
        menuDebug->addAction(actionBlemish_C_Tuning);
        menuDebug->addSeparator();
        menuDebug->addAction(enableOfflineaction);
        menuDebug->addAction(actionset_path);
        menuDebug->addSeparator();

        retranslateUi(HisFX3CCMTestClass);

        QMetaObject::connectSlotsByName(HisFX3CCMTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *HisFX3CCMTestClass)
    {
        HisFX3CCMTestClass->setWindowTitle(QApplication::translate("HisFX3CCMTestClass", "HisFX3CCMTest", 0, QApplication::UnicodeUTF8));
        configaction->setText(QApplication::translate("HisFX3CCMTestClass", "Config", 0, QApplication::UnicodeUTF8));
        operatorbasicinfoaction->setText(QApplication::translate("HisFX3CCMTestClass", "Basic Info", 0, QApplication::UnicodeUTF8));
        enableconfigaction->setText(QApplication::translate("HisFX3CCMTestClass", "UnLock", 0, QApplication::UnicodeUTF8));
        disableconfigaction->setText(QApplication::translate("HisFX3CCMTestClass", "Lock", 0, QApplication::UnicodeUTF8));
        csvManageaction->setText(QApplication::translate("HisFX3CCMTestClass", "Config Manage", 0, QApplication::UnicodeUTF8));
        showLeftaction->setText(QApplication::translate("HisFX3CCMTestClass", "Show Left", 0, QApplication::UnicodeUTF8));
        showRightaction->setText(QApplication::translate("HisFX3CCMTestClass", "Show Right", 0, QApplication::UnicodeUTF8));
        showBottomInfoaction->setText(QApplication::translate("HisFX3CCMTestClass", "Show Bottom", 0, QApplication::UnicodeUTF8));
        showBottomLineaction->setText(QApplication::translate("HisFX3CCMTestClass", "\346\230\276\347\244\272\344\270\213\344\276\247-\350\260\203\350\257\225", 0, QApplication::UnicodeUTF8));
        showItem2EndResultaction->setText(QApplication::translate("HisFX3CCMTestClass", "Result On Right", 0, QApplication::UnicodeUTF8));
        showEndResult2Imageaction->setText(QApplication::translate("HisFX3CCMTestClass", "Result On Image", 0, QApplication::UnicodeUTF8));
        enableDebugModeaction->setText(QApplication::translate("HisFX3CCMTestClass", "Debug Mode ON", 0, QApplication::UnicodeUTF8));
        enableOfflineaction->setText(QApplication::translate("HisFX3CCMTestClass", "OFFLINE Mode ON", 0, QApplication::UnicodeUTF8));
        currentCalaction->setText(QApplication::translate("HisFX3CCMTestClass", "Current Self Calibration", 0, QApplication::UnicodeUTF8));
        OSCalibrationaction->setText(QApplication::translate("HisFX3CCMTestClass", "OS Self Calibration", 0, QApplication::UnicodeUTF8));
        simpleChineseaction->setText(QApplication::translate("HisFX3CCMTestClass", "simplified Chinese", 0, QApplication::UnicodeUTF8));
        englishaction->setText(QApplication::translate("HisFX3CCMTestClass", "English", 0, QApplication::UnicodeUTF8));
        actionCoordinate_Convertion->setText(QApplication::translate("HisFX3CCMTestClass", "Coordinate Convertion", 0, QApplication::UnicodeUTF8));
        actionVersion->setText(QApplication::translate("HisFX3CCMTestClass", "Version", 0, QApplication::UnicodeUTF8));
        actionChoose_Grabber->setText(QApplication::translate("HisFX3CCMTestClass", "Grabber Config", 0, QApplication::UnicodeUTF8));
        actionUpdate_FPGA_FW->setText(QApplication::translate("HisFX3CCMTestClass", "Update FPGA FW", 0, QApplication::UnicodeUTF8));
        actionVoltage_Calibration->setText(QApplication::translate("HisFX3CCMTestClass", "Voltage Calibration", 0, QApplication::UnicodeUTF8));
        actionChange_Password->setText(QApplication::translate("HisFX3CCMTestClass", "Change Password", 0, QApplication::UnicodeUTF8));
        actionImage_Show->setText(QApplication::translate("HisFX3CCMTestClass", "Image Show", 0, QApplication::UnicodeUTF8));
        actionSave_Lock_UI->setText(QApplication::translate("HisFX3CCMTestClass", "Save/Lock UI", 0, QApplication::UnicodeUTF8));
        actionChoose_OperatorMode->setText(QApplication::translate("HisFX3CCMTestClass", "Choose Operator Mode", 0, QApplication::UnicodeUTF8));
        actionManual_Mode_A->setText(QApplication::translate("HisFX3CCMTestClass", "Manual Mode-A Config", 0, QApplication::UnicodeUTF8));
        actionShow_Operation_Panel->setText(QApplication::translate("HisFX3CCMTestClass", "Show Operation Panel", 0, QApplication::UnicodeUTF8));
        actionShow_Info_Panel->setText(QApplication::translate("HisFX3CCMTestClass", "Show Graph Panel", 0, QApplication::UnicodeUTF8));
        actionPanel_moveable->setText(QApplication::translate("HisFX3CCMTestClass", "Panel Moveable", 0, QApplication::UnicodeUTF8));
        actionShow_Text_Panel->setText(QApplication::translate("HisFX3CCMTestClass", "Show Text Panel", 0, QApplication::UnicodeUTF8));
        actionReset_UI_Layout->setText(QApplication::translate("HisFX3CCMTestClass", "Reset UI Layout", 0, QApplication::UnicodeUTF8));
        actionBlemish_C_Tuning->setText(QApplication::translate("HisFX3CCMTestClass", "Blemish-C Tuning", 0, QApplication::UnicodeUTF8));
        actionShoactionShow_TestItem->setText(QApplication::translate("HisFX3CCMTestClass", "Show TestItem", 0, QApplication::UnicodeUTF8));
        actionShow_Statis_Panel->setText(QApplication::translate("HisFX3CCMTestClass", "Show Statis Panel", 0, QApplication::UnicodeUTF8));
        actionTCP_IPtransmission->setText(QApplication::translate("HisFX3CCMTestClass", "TCP/IP", 0, QApplication::UnicodeUTF8));
        actionImage->setText(QApplication::translate("HisFX3CCMTestClass", "Image", 0, QApplication::UnicodeUTF8));
        actionset_path->setText(QApplication::translate("HisFX3CCMTestClass", "SET PATH", 0, QApplication::UnicodeUTF8));
        actionTest_Exposure_Delay->setText(QApplication::translate("HisFX3CCMTestClass", "Test Exposure Delay", 0, QApplication::UnicodeUTF8));
        actionJsv_to_csv->setText(QApplication::translate("HisFX3CCMTestClass", "jsv to csv", 0, QApplication::UnicodeUTF8));
        imageshowPolicycomboBox->setItemText(0, QApplication::translate("HisFX3CCMTestClass", "Fit Size", 0, QApplication::UnicodeUTF8));
        imageshowPolicycomboBox->setItemText(1, QApplication::translate("HisFX3CCMTestClass", "Sodoku", 0, QApplication::UnicodeUTF8));

        menuConfig->setTitle(QApplication::translate("HisFX3CCMTestClass", "Config", 0, QApplication::UnicodeUTF8));
        menu_OperatorMode->setTitle(QApplication::translate("HisFX3CCMTestClass", "Operator Mode", 0, QApplication::UnicodeUTF8));
        menuUI->setTitle(QApplication::translate("HisFX3CCMTestClass", "UI", 0, QApplication::UnicodeUTF8));
        menuDebug->setTitle(QApplication::translate("HisFX3CCMTestClass", "Debug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HisFX3CCMTestClass: public Ui_HisFX3CCMTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISFX3CCMTEST_H
