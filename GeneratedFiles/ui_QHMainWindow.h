/********************************************************************************
** Form generated from reading UI file 'QHMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHMAINWINDOW_H
#define UI_QHMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHMainWindow
{
public:
    QAction *disableconfigaction;
    QAction *actionChange_Password;
    QAction *csvManageaction;
    QAction *actionChoose_OperatorMode;
    QAction *showItem2EndResultaction;
    QAction *showEndResult2Imageaction;
    QAction *actionImage_Show;
    QAction *actionSave_Lock_UI;
    QAction *actionPanel_moveable;
    QAction *actionReset_UI_Layout;
    QAction *enableDebugModeaction;
    QAction *actionCoordinate_Convertion;
    QAction *actionChoose_Grabber;
    QAction *actionUpdate_FPGA_FW;
    QAction *actionVoltage_Calibration;
    QAction *currentCalaction;
    QAction *OSCalibrationaction;
    QAction *simpleChineseaction;
    QAction *englishaction;
    QAction *actionVersion;
    QAction *actionShortcut;
    QAction *actionConfig_Content_Table;
    QAction *actionShow_Channel_1;
    QAction *actionShow_Channel_2;
    QAction *actionComputer_Compatibility_Test;
    QAction *actionHelp;
    QAction *actionRepeated_Test;
    QAction *actionSave_Text_Info_To_Local;
    QAction *actionFont;
    QAction *actionSOP;
    QAction *actionJsl_to_csv;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuAdministrator;
    QMenu *menuUI;
    QMenu *menuDEBUG;
    QMenu *menuTool;
    QMenu *menuGrabber;
    QMenu *menuLanguage;
    QMenu *menuAbort;
    QMenu *menuEquipment;

    void setupUi(QMainWindow *QHMainWindow)
    {
        if (QHMainWindow->objectName().isEmpty())
            QHMainWindow->setObjectName(QString::fromUtf8("QHMainWindow"));
        QHMainWindow->resize(642, 433);
        QHMainWindow->setMinimumSize(QSize(320, 240));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        QHMainWindow->setFont(font);
        QHMainWindow->setFocusPolicy(Qt::StrongFocus);
        QHMainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        disableconfigaction = new QAction(QHMainWindow);
        disableconfigaction->setObjectName(QString::fromUtf8("disableconfigaction"));
        actionChange_Password = new QAction(QHMainWindow);
        actionChange_Password->setObjectName(QString::fromUtf8("actionChange_Password"));
        csvManageaction = new QAction(QHMainWindow);
        csvManageaction->setObjectName(QString::fromUtf8("csvManageaction"));
        actionChoose_OperatorMode = new QAction(QHMainWindow);
        actionChoose_OperatorMode->setObjectName(QString::fromUtf8("actionChoose_OperatorMode"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        actionChoose_OperatorMode->setFont(font1);
        showItem2EndResultaction = new QAction(QHMainWindow);
        showItem2EndResultaction->setObjectName(QString::fromUtf8("showItem2EndResultaction"));
        showItem2EndResultaction->setCheckable(true);
        showItem2EndResultaction->setChecked(true);
        showItem2EndResultaction->setFont(font1);
        showEndResult2Imageaction = new QAction(QHMainWindow);
        showEndResult2Imageaction->setObjectName(QString::fromUtf8("showEndResult2Imageaction"));
        showEndResult2Imageaction->setCheckable(true);
        showEndResult2Imageaction->setChecked(true);
        showEndResult2Imageaction->setFont(font1);
        actionImage_Show = new QAction(QHMainWindow);
        actionImage_Show->setObjectName(QString::fromUtf8("actionImage_Show"));
        actionImage_Show->setFont(font1);
        actionSave_Lock_UI = new QAction(QHMainWindow);
        actionSave_Lock_UI->setObjectName(QString::fromUtf8("actionSave_Lock_UI"));
        actionSave_Lock_UI->setFont(font1);
        actionPanel_moveable = new QAction(QHMainWindow);
        actionPanel_moveable->setObjectName(QString::fromUtf8("actionPanel_moveable"));
        actionPanel_moveable->setCheckable(true);
        actionPanel_moveable->setFont(font1);
        actionReset_UI_Layout = new QAction(QHMainWindow);
        actionReset_UI_Layout->setObjectName(QString::fromUtf8("actionReset_UI_Layout"));
        actionReset_UI_Layout->setFont(font1);
        enableDebugModeaction = new QAction(QHMainWindow);
        enableDebugModeaction->setObjectName(QString::fromUtf8("enableDebugModeaction"));
        enableDebugModeaction->setCheckable(true);
        enableDebugModeaction->setFont(font1);
        actionCoordinate_Convertion = new QAction(QHMainWindow);
        actionCoordinate_Convertion->setObjectName(QString::fromUtf8("actionCoordinate_Convertion"));
        actionCoordinate_Convertion->setFont(font1);
        actionChoose_Grabber = new QAction(QHMainWindow);
        actionChoose_Grabber->setObjectName(QString::fromUtf8("actionChoose_Grabber"));
        actionChoose_Grabber->setFont(font1);
        actionUpdate_FPGA_FW = new QAction(QHMainWindow);
        actionUpdate_FPGA_FW->setObjectName(QString::fromUtf8("actionUpdate_FPGA_FW"));
        actionUpdate_FPGA_FW->setFont(font1);
        actionVoltage_Calibration = new QAction(QHMainWindow);
        actionVoltage_Calibration->setObjectName(QString::fromUtf8("actionVoltage_Calibration"));
        actionVoltage_Calibration->setFont(font1);
        currentCalaction = new QAction(QHMainWindow);
        currentCalaction->setObjectName(QString::fromUtf8("currentCalaction"));
        currentCalaction->setFont(font1);
        OSCalibrationaction = new QAction(QHMainWindow);
        OSCalibrationaction->setObjectName(QString::fromUtf8("OSCalibrationaction"));
        OSCalibrationaction->setFont(font1);
        simpleChineseaction = new QAction(QHMainWindow);
        simpleChineseaction->setObjectName(QString::fromUtf8("simpleChineseaction"));
        simpleChineseaction->setCheckable(true);
        simpleChineseaction->setChecked(true);
        simpleChineseaction->setFont(font1);
        englishaction = new QAction(QHMainWindow);
        englishaction->setObjectName(QString::fromUtf8("englishaction"));
        englishaction->setCheckable(true);
        englishaction->setFont(font1);
        actionVersion = new QAction(QHMainWindow);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        actionVersion->setFont(font1);
        actionShortcut = new QAction(QHMainWindow);
        actionShortcut->setObjectName(QString::fromUtf8("actionShortcut"));
        actionShortcut->setFont(font1);
        actionConfig_Content_Table = new QAction(QHMainWindow);
        actionConfig_Content_Table->setObjectName(QString::fromUtf8("actionConfig_Content_Table"));
        actionShow_Channel_1 = new QAction(QHMainWindow);
        actionShow_Channel_1->setObjectName(QString::fromUtf8("actionShow_Channel_1"));
        actionShow_Channel_1->setCheckable(true);
        actionShow_Channel_1->setChecked(true);
        actionShow_Channel_1->setFont(font1);
        actionShow_Channel_2 = new QAction(QHMainWindow);
        actionShow_Channel_2->setObjectName(QString::fromUtf8("actionShow_Channel_2"));
        actionShow_Channel_2->setCheckable(true);
        actionShow_Channel_2->setChecked(true);
        actionShow_Channel_2->setFont(font1);
        actionComputer_Compatibility_Test = new QAction(QHMainWindow);
        actionComputer_Compatibility_Test->setObjectName(QString::fromUtf8("actionComputer_Compatibility_Test"));
        actionComputer_Compatibility_Test->setFont(font1);
        actionHelp = new QAction(QHMainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionHelp->setFont(font1);
        actionRepeated_Test = new QAction(QHMainWindow);
        actionRepeated_Test->setObjectName(QString::fromUtf8("actionRepeated_Test"));
        actionSave_Text_Info_To_Local = new QAction(QHMainWindow);
        actionSave_Text_Info_To_Local->setObjectName(QString::fromUtf8("actionSave_Text_Info_To_Local"));
        actionSave_Text_Info_To_Local->setCheckable(true);
        actionSave_Text_Info_To_Local->setFont(font1);
        actionFont = new QAction(QHMainWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionFont->setFont(font1);
        actionSOP = new QAction(QHMainWindow);
        actionSOP->setObjectName(QString::fromUtf8("actionSOP"));
        actionJsl_to_csv = new QAction(QHMainWindow);
        actionJsl_to_csv->setObjectName(QString::fromUtf8("actionJsl_to_csv"));
        centralWidget = new QWidget(QHMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QHMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QHMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 642, 28));
        menuBar->setFont(font1);
        menuAdministrator = new QMenu(menuBar);
        menuAdministrator->setObjectName(QString::fromUtf8("menuAdministrator"));
        menuAdministrator->setFont(font1);
        menuUI = new QMenu(menuBar);
        menuUI->setObjectName(QString::fromUtf8("menuUI"));
        menuUI->setFont(font1);
        menuDEBUG = new QMenu(menuBar);
        menuDEBUG->setObjectName(QString::fromUtf8("menuDEBUG"));
        menuDEBUG->setFont(font1);
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        menuTool->setFont(font1);
        menuGrabber = new QMenu(menuBar);
        menuGrabber->setObjectName(QString::fromUtf8("menuGrabber"));
        menuGrabber->setFont(font1);
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuLanguage->setFont(font1);
        menuAbort = new QMenu(menuBar);
        menuAbort->setObjectName(QString::fromUtf8("menuAbort"));
        menuAbort->setFont(font1);
        menuEquipment = new QMenu(menuBar);
        menuEquipment->setObjectName(QString::fromUtf8("menuEquipment"));
        menuEquipment->setFont(font1);
        QHMainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuAdministrator->menuAction());
        menuBar->addAction(menuUI->menuAction());
        menuBar->addAction(menuDEBUG->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuGrabber->menuAction());
        menuBar->addAction(menuEquipment->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuBar->addAction(menuAbort->menuAction());
        menuAdministrator->addAction(csvManageaction);
        menuAdministrator->addAction(actionConfig_Content_Table);
        menuAdministrator->addSeparator();
        menuAdministrator->addAction(actionShortcut);
        menuAdministrator->addSeparator();
        menuAdministrator->addAction(actionChoose_OperatorMode);
        menuAdministrator->addSeparator();
        menuAdministrator->addAction(disableconfigaction);
        menuAdministrator->addAction(actionChange_Password);
        menuUI->addAction(showItem2EndResultaction);
        menuUI->addAction(showEndResult2Imageaction);
        menuUI->addSeparator();
        menuUI->addAction(actionImage_Show);
        menuUI->addSeparator();
        menuUI->addAction(actionSave_Lock_UI);
        menuUI->addAction(actionPanel_moveable);
        menuUI->addAction(actionReset_UI_Layout);
        menuUI->addSeparator();
        menuUI->addAction(actionShow_Channel_1);
        menuUI->addAction(actionShow_Channel_2);
        menuUI->addSeparator();
        menuUI->addAction(actionFont);
        menuDEBUG->addAction(enableDebugModeaction);
        menuDEBUG->addAction(actionSave_Text_Info_To_Local);
        menuTool->addAction(actionCoordinate_Convertion);
        menuTool->addAction(actionComputer_Compatibility_Test);
        menuTool->addAction(actionRepeated_Test);
        menuTool->addAction(actionJsl_to_csv);
        menuGrabber->addAction(actionChoose_Grabber);
        menuGrabber->addAction(actionUpdate_FPGA_FW);
        menuGrabber->addSeparator();
        menuGrabber->addAction(actionVoltage_Calibration);
        menuGrabber->addAction(currentCalaction);
        menuGrabber->addAction(OSCalibrationaction);
        menuLanguage->addAction(simpleChineseaction);
        menuLanguage->addAction(englishaction);
        menuAbort->addAction(actionVersion);
        menuAbort->addAction(actionHelp);
        menuAbort->addAction(actionSOP);

        retranslateUi(QHMainWindow);

        QMetaObject::connectSlotsByName(QHMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QHMainWindow)
    {
        QHMainWindow->setWindowTitle(QApplication::translate("QHMainWindow", "HisFX3CCMTest", 0, QApplication::UnicodeUTF8));
        disableconfigaction->setText(QApplication::translate("QHMainWindow", "Lock", 0, QApplication::UnicodeUTF8));
        actionChange_Password->setText(QApplication::translate("QHMainWindow", "Change Password", 0, QApplication::UnicodeUTF8));
        csvManageaction->setText(QApplication::translate("QHMainWindow", "Config Manage", 0, QApplication::UnicodeUTF8));
        actionChoose_OperatorMode->setText(QApplication::translate("QHMainWindow", "Choose Operator Mode", 0, QApplication::UnicodeUTF8));
        showItem2EndResultaction->setText(QApplication::translate("QHMainWindow", "Result On Right", 0, QApplication::UnicodeUTF8));
        showEndResult2Imageaction->setText(QApplication::translate("QHMainWindow", "Result On Image", 0, QApplication::UnicodeUTF8));
        actionImage_Show->setText(QApplication::translate("QHMainWindow", "Image Show", 0, QApplication::UnicodeUTF8));
        actionSave_Lock_UI->setText(QApplication::translate("QHMainWindow", "Save/Lock UI", 0, QApplication::UnicodeUTF8));
        actionPanel_moveable->setText(QApplication::translate("QHMainWindow", "Panel Moveable", 0, QApplication::UnicodeUTF8));
        actionReset_UI_Layout->setText(QApplication::translate("QHMainWindow", "Reset UI Layout", 0, QApplication::UnicodeUTF8));
        enableDebugModeaction->setText(QApplication::translate("QHMainWindow", "Debug Mode ON", 0, QApplication::UnicodeUTF8));
        actionCoordinate_Convertion->setText(QApplication::translate("QHMainWindow", "Coordinate Convertion", 0, QApplication::UnicodeUTF8));
        actionChoose_Grabber->setText(QApplication::translate("QHMainWindow", "Grabber Config", 0, QApplication::UnicodeUTF8));
        actionUpdate_FPGA_FW->setText(QApplication::translate("QHMainWindow", "Update FPGA FW", 0, QApplication::UnicodeUTF8));
        actionVoltage_Calibration->setText(QApplication::translate("QHMainWindow", "Voltage Calibration", 0, QApplication::UnicodeUTF8));
        currentCalaction->setText(QApplication::translate("QHMainWindow", "Current Self Calibration", 0, QApplication::UnicodeUTF8));
        OSCalibrationaction->setText(QApplication::translate("QHMainWindow", "OS Self Calibration", 0, QApplication::UnicodeUTF8));
        simpleChineseaction->setText(QApplication::translate("QHMainWindow", "simplified Chinese", 0, QApplication::UnicodeUTF8));
        englishaction->setText(QApplication::translate("QHMainWindow", "English", 0, QApplication::UnicodeUTF8));
        actionVersion->setText(QApplication::translate("QHMainWindow", "Version", 0, QApplication::UnicodeUTF8));
        actionShortcut->setText(QApplication::translate("QHMainWindow", "Shortcut", 0, QApplication::UnicodeUTF8));
        actionConfig_Content_Table->setText(QApplication::translate("QHMainWindow", "Config Content Table", 0, QApplication::UnicodeUTF8));
        actionShow_Channel_1->setText(QApplication::translate("QHMainWindow", "Show Channel 1", 0, QApplication::UnicodeUTF8));
        actionShow_Channel_2->setText(QApplication::translate("QHMainWindow", "Show Channel 2", 0, QApplication::UnicodeUTF8));
        actionComputer_Compatibility_Test->setText(QApplication::translate("QHMainWindow", "Computer Compatibility Test", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("QHMainWindow", "User Manual(CHM)", 0, QApplication::UnicodeUTF8));
        actionRepeated_Test->setText(QApplication::translate("QHMainWindow", "Repeated Test", 0, QApplication::UnicodeUTF8));
        actionSave_Text_Info_To_Local->setText(QApplication::translate("QHMainWindow", "Save Text Info To Local", 0, QApplication::UnicodeUTF8));
        actionFont->setText(QApplication::translate("QHMainWindow", "Font", 0, QApplication::UnicodeUTF8));
        actionSOP->setText(QApplication::translate("QHMainWindow", "\344\275\234\344\270\232\346\214\207\345\257\274\344\271\246(SOP)", 0, QApplication::UnicodeUTF8));
        actionJsl_to_csv->setText(QApplication::translate("QHMainWindow", "jsv to csv", 0, QApplication::UnicodeUTF8));
        menuAdministrator->setTitle(QApplication::translate("QHMainWindow", "Administrator", 0, QApplication::UnicodeUTF8));
        menuUI->setTitle(QApplication::translate("QHMainWindow", "UI", 0, QApplication::UnicodeUTF8));
        menuDEBUG->setTitle(QApplication::translate("QHMainWindow", "DEBUG", 0, QApplication::UnicodeUTF8));
        menuTool->setTitle(QApplication::translate("QHMainWindow", "Tool", 0, QApplication::UnicodeUTF8));
        menuGrabber->setTitle(QApplication::translate("QHMainWindow", "Grabber", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("QHMainWindow", "Language", 0, QApplication::UnicodeUTF8));
        menuAbort->setTitle(QApplication::translate("QHMainWindow", "Abort", 0, QApplication::UnicodeUTF8));
        menuEquipment->setTitle(QApplication::translate("QHMainWindow", "Equipment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHMainWindow: public Ui_QHMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHMAINWINDOW_H
