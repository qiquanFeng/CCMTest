/********************************************************************************
** Form generated from reading UI file 'coorconverttool.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORCONVERTTOOL_H
#define UI_COORCONVERTTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_coorconverttool
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *fovImageWidthspinBox;
    QSpinBox *fovImageHeightspinBox;
    QSpinBox *fovXspinBox;
    QSpinBox *fovYspinBox;
    QPushButton *fovpushButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *fovlineEdit;
    QLineEdit *fovAnglelineEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *disX1spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpinBox *disY1spinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QSpinBox *disX2spinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QSpinBox *disY2spinBox;
    QPushButton *dispushButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLineEdit *dislineEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QSpinBox *rgb2lab_RGB_RspinBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QSpinBox *rgb2lab_RGB_GspinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QSpinBox *rgb2lab_RGB_BspinBox;
    QPushButton *RGB2LabpushButton;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QDoubleSpinBox *rgb2lab_Lab_LdoubleSpinBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QDoubleSpinBox *rgb2lab_Lab_adoubleSpinBox;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_17;
    QDoubleSpinBox *rgb2lab_Lab_bdoubleSpinBox;

    void setupUi(QDockWidget *coorconverttool)
    {
        if (coorconverttool->objectName().isEmpty())
            coorconverttool->setObjectName(QString::fromUtf8("coorconverttool"));
        coorconverttool->resize(495, 472);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        coorconverttool->setFont(font);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_9 = new QVBoxLayout(widget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fovImageWidthspinBox = new QSpinBox(groupBox);
        fovImageWidthspinBox->setObjectName(QString::fromUtf8("fovImageWidthspinBox"));
        fovImageWidthspinBox->setMinimum(2);
        fovImageWidthspinBox->setMaximum(99999);
        fovImageWidthspinBox->setValue(3264);

        verticalLayout_2->addWidget(fovImageWidthspinBox);

        fovImageHeightspinBox = new QSpinBox(groupBox);
        fovImageHeightspinBox->setObjectName(QString::fromUtf8("fovImageHeightspinBox"));
        fovImageHeightspinBox->setMinimum(2);
        fovImageHeightspinBox->setMaximum(99999);
        fovImageHeightspinBox->setValue(2448);

        verticalLayout_2->addWidget(fovImageHeightspinBox);

        fovXspinBox = new QSpinBox(groupBox);
        fovXspinBox->setObjectName(QString::fromUtf8("fovXspinBox"));
        fovXspinBox->setMinimum(0);
        fovXspinBox->setMaximum(99999);
        fovXspinBox->setValue(0);

        verticalLayout_2->addWidget(fovXspinBox);

        fovYspinBox = new QSpinBox(groupBox);
        fovYspinBox->setObjectName(QString::fromUtf8("fovYspinBox"));
        fovYspinBox->setMinimum(0);
        fovYspinBox->setMaximum(99999);
        fovYspinBox->setValue(0);

        verticalLayout_2->addWidget(fovYspinBox);


        horizontalLayout->addLayout(verticalLayout_2);

        fovpushButton = new QPushButton(groupBox);
        fovpushButton->setObjectName(QString::fromUtf8("fovpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fovpushButton->sizePolicy().hasHeightForWidth());
        fovpushButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft PhagsPa"));
        fovpushButton->setFont(font2);

        horizontalLayout->addWidget(fovpushButton);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        fovlineEdit = new QLineEdit(groupBox);
        fovlineEdit->setObjectName(QString::fromUtf8("fovlineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fovlineEdit->sizePolicy().hasHeightForWidth());
        fovlineEdit->setSizePolicy(sizePolicy1);
        fovlineEdit->setMaximumSize(QSize(80, 16777215));

        verticalLayout_4->addWidget(fovlineEdit);

        fovAnglelineEdit = new QLineEdit(groupBox);
        fovAnglelineEdit->setObjectName(QString::fromUtf8("fovAnglelineEdit"));
        sizePolicy1.setHeightForWidth(fovAnglelineEdit->sizePolicy().hasHeightForWidth());
        fovAnglelineEdit->setSizePolicy(sizePolicy1);
        fovAnglelineEdit->setMaximumSize(QSize(80, 16777215));

        verticalLayout_4->addWidget(fovAnglelineEdit);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_9->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        disX1spinBox = new QSpinBox(groupBox_2);
        disX1spinBox->setObjectName(QString::fromUtf8("disX1spinBox"));
        disX1spinBox->setMinimum(0);
        disX1spinBox->setMaximum(99999);
        disX1spinBox->setValue(0);

        horizontalLayout_2->addWidget(disX1spinBox);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        disY1spinBox = new QSpinBox(groupBox_2);
        disY1spinBox->setObjectName(QString::fromUtf8("disY1spinBox"));
        disY1spinBox->setMinimum(0);
        disY1spinBox->setMaximum(99999);
        disY1spinBox->setValue(0);

        horizontalLayout_3->addWidget(disY1spinBox);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        disX2spinBox = new QSpinBox(groupBox_2);
        disX2spinBox->setObjectName(QString::fromUtf8("disX2spinBox"));
        disX2spinBox->setMinimum(0);
        disX2spinBox->setMaximum(99999);
        disX2spinBox->setValue(0);

        horizontalLayout_4->addWidget(disX2spinBox);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        disY2spinBox = new QSpinBox(groupBox_2);
        disY2spinBox->setObjectName(QString::fromUtf8("disY2spinBox"));
        disY2spinBox->setMinimum(0);
        disY2spinBox->setMaximum(99999);
        disY2spinBox->setValue(0);

        horizontalLayout_5->addWidget(disY2spinBox);


        verticalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_6);

        dispushButton = new QPushButton(groupBox_2);
        dispushButton->setObjectName(QString::fromUtf8("dispushButton"));
        sizePolicy.setHeightForWidth(dispushButton->sizePolicy().hasHeightForWidth());
        dispushButton->setSizePolicy(sizePolicy);
        dispushButton->setFont(font2);

        horizontalLayout_6->addWidget(dispushButton);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        verticalLayout_5->addWidget(label_11);

        dislineEdit = new QLineEdit(groupBox_2);
        dislineEdit->setObjectName(QString::fromUtf8("dislineEdit"));
        sizePolicy1.setHeightForWidth(dislineEdit->sizePolicy().hasHeightForWidth());
        dislineEdit->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(dislineEdit);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_9->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font3;
        font3.setPointSize(10);
        groupBox_3->setFont(font3);
        groupBox_3->setTitle(QString::fromUtf8("RGB ==> Lab"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_3);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMinimumSize(QSize(30, 0));
        label_12->setMaximumSize(QSize(30, 16777215));
        label_12->setText(QString::fromUtf8("R:"));

        horizontalLayout_7->addWidget(label_12);

        rgb2lab_RGB_RspinBox = new QSpinBox(groupBox_3);
        rgb2lab_RGB_RspinBox->setObjectName(QString::fromUtf8("rgb2lab_RGB_RspinBox"));
        rgb2lab_RGB_RspinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_RGB_RspinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_RGB_RspinBox->setMaximum(255);

        horizontalLayout_7->addWidget(rgb2lab_RGB_RspinBox);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMinimumSize(QSize(30, 0));
        label_13->setMaximumSize(QSize(30, 16777215));
        label_13->setText(QString::fromUtf8("G:"));

        horizontalLayout_8->addWidget(label_13);

        rgb2lab_RGB_GspinBox = new QSpinBox(groupBox_3);
        rgb2lab_RGB_GspinBox->setObjectName(QString::fromUtf8("rgb2lab_RGB_GspinBox"));
        rgb2lab_RGB_GspinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_RGB_GspinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_RGB_GspinBox->setMaximum(255);

        horizontalLayout_8->addWidget(rgb2lab_RGB_GspinBox);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMinimumSize(QSize(30, 0));
        label_14->setMaximumSize(QSize(30, 16777215));
        label_14->setText(QString::fromUtf8("B:"));

        horizontalLayout_9->addWidget(label_14);

        rgb2lab_RGB_BspinBox = new QSpinBox(groupBox_3);
        rgb2lab_RGB_BspinBox->setObjectName(QString::fromUtf8("rgb2lab_RGB_BspinBox"));
        rgb2lab_RGB_BspinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_RGB_BspinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_RGB_BspinBox->setMaximum(255);

        horizontalLayout_9->addWidget(rgb2lab_RGB_BspinBox);


        verticalLayout_7->addLayout(horizontalLayout_9);


        horizontalLayout_13->addLayout(verticalLayout_7);

        RGB2LabpushButton = new QPushButton(groupBox_3);
        RGB2LabpushButton->setObjectName(QString::fromUtf8("RGB2LabpushButton"));
        sizePolicy.setHeightForWidth(RGB2LabpushButton->sizePolicy().hasHeightForWidth());
        RGB2LabpushButton->setSizePolicy(sizePolicy);
        RGB2LabpushButton->setFont(font2);

        horizontalLayout_13->addWidget(RGB2LabpushButton);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setMinimumSize(QSize(30, 0));
        label_15->setMaximumSize(QSize(30, 16777215));
        label_15->setText(QString::fromUtf8("L:"));

        horizontalLayout_10->addWidget(label_15);

        rgb2lab_Lab_LdoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        rgb2lab_Lab_LdoubleSpinBox->setObjectName(QString::fromUtf8("rgb2lab_Lab_LdoubleSpinBox"));
        rgb2lab_Lab_LdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_Lab_LdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_Lab_LdoubleSpinBox->setDecimals(4);
        rgb2lab_Lab_LdoubleSpinBox->setMaximum(100);

        horizontalLayout_10->addWidget(rgb2lab_Lab_LdoubleSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setMinimumSize(QSize(30, 0));
        label_16->setMaximumSize(QSize(30, 16777215));
        label_16->setText(QString::fromUtf8("A:"));

        horizontalLayout_11->addWidget(label_16);

        rgb2lab_Lab_adoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        rgb2lab_Lab_adoubleSpinBox->setObjectName(QString::fromUtf8("rgb2lab_Lab_adoubleSpinBox"));
        rgb2lab_Lab_adoubleSpinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_Lab_adoubleSpinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_Lab_adoubleSpinBox->setDecimals(4);
        rgb2lab_Lab_adoubleSpinBox->setMinimum(-128);
        rgb2lab_Lab_adoubleSpinBox->setMaximum(127);

        horizontalLayout_11->addWidget(rgb2lab_Lab_adoubleSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);
        label_17->setMinimumSize(QSize(30, 0));
        label_17->setMaximumSize(QSize(30, 16777215));
        label_17->setText(QString::fromUtf8("B:"));

        horizontalLayout_12->addWidget(label_17);

        rgb2lab_Lab_bdoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        rgb2lab_Lab_bdoubleSpinBox->setObjectName(QString::fromUtf8("rgb2lab_Lab_bdoubleSpinBox"));
        rgb2lab_Lab_bdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        rgb2lab_Lab_bdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        rgb2lab_Lab_bdoubleSpinBox->setDecimals(4);
        rgb2lab_Lab_bdoubleSpinBox->setMinimum(-128);
        rgb2lab_Lab_bdoubleSpinBox->setMaximum(127);

        horizontalLayout_12->addWidget(rgb2lab_Lab_bdoubleSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout_8);


        verticalLayout_9->addWidget(groupBox_3);

        coorconverttool->setWidget(widget);

        retranslateUi(coorconverttool);

        QMetaObject::connectSlotsByName(coorconverttool);
    } // setupUi

    void retranslateUi(QDockWidget *coorconverttool)
    {
        coorconverttool->setWindowTitle(QApplication::translate("coorconverttool", "coorconverttool", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("coorconverttool", "Coordinate to FOV", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("coorconverttool", "Image Width:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("coorconverttool", "Image Height:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("coorconverttool", "X:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("coorconverttool", "Y:", 0, QApplication::UnicodeUTF8));
        fovpushButton->setText(QApplication::translate("coorconverttool", "Convert", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("coorconverttool", "FOV:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("coorconverttool", "Angle:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("coorconverttool", "Calculate Distance", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("coorconverttool", "X1:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("coorconverttool", "Y1:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("coorconverttool", "X2:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("coorconverttool", "Y2:", 0, QApplication::UnicodeUTF8));
        dispushButton->setText(QApplication::translate("coorconverttool", "Calculate", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("coorconverttool", "Distance(Pixel):", 0, QApplication::UnicodeUTF8));
        RGB2LabpushButton->setText(QApplication::translate("coorconverttool", "==>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class coorconverttool: public Ui_coorconverttool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORCONVERTTOOL_H
