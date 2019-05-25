/********************************************************************************
** Form generated from reading UI file 'QHBlemishHC.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHBLEMISHHC_H
#define UI_QHBLEMISHHC_H

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
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHBlemishHC
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_2;
    QLabel *blemishhclabel;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *blemishhcGetImagepushButton;
    QPushButton *blemishhcNormalTestpushButton;
    QPushButton *blemishhcDebugpushButton;
    QPushButton *blemishhcLooppushButton;
    QListWidget *blemishhclistWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    QDoubleSpinBox *blemishhcAreaMindoubleSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *blemishhcAreaMaxdoubleSpinBox;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_4;
    QDoubleSpinBox *blemishhcEdgeZonedoubleSpinBox;
    QLabel *label_21;
    QDoubleSpinBox *blemishhcCornerZonedoubleSpinBox;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_5;
    QDoubleSpinBox *blemishhcTuningdoubleSpinBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QDoubleSpinBox *blemishhcZ1BdoubleSpinBox;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QDoubleSpinBox *blemishhcZ2BdoubleSpinBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QDoubleSpinBox *blemishhcZ3BdoubleSpinBox;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QDoubleSpinBox *blemishhcZ4BdoubleSpinBox;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QDoubleSpinBox *blemishhcZ5BdoubleSpinBox;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QDoubleSpinBox *blemishhcZ6BdoubleSpinBox;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QDoubleSpinBox *blemishhcZ7BdoubleSpinBox;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QDoubleSpinBox *blemishhcZ8BdoubleSpinBox;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QDoubleSpinBox *blemishhcZ9BdoubleSpinBox;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QDoubleSpinBox *blemishhcZ10BdoubleSpinBox;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_17;
    QDoubleSpinBox *blemishhcEdgeBdoubleSpinBox;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_19;
    QDoubleSpinBox *blemishhcCornerBdoubleSpinBox;
    QPushButton *blemishhcSavepushButton;

    void setupUi(QDockWidget *QHBlemishHC)
    {
        if (QHBlemishHC->objectName().isEmpty())
            QHBlemishHC->setObjectName(QString::fromUtf8("QHBlemishHC"));
        QHBlemishHC->resize(878, 674);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHBlemishHC->setFont(font);
        QHBlemishHC->setFloating(true);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_15 = new QHBoxLayout(widget);
        horizontalLayout_15->setSpacing(3);
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        blemishhclabel = new QLabel(widget);
        blemishhclabel->setObjectName(QString::fromUtf8("blemishhclabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(blemishhclabel->sizePolicy().hasHeightForWidth());
        blemishhclabel->setSizePolicy(sizePolicy);
        blemishhclabel->setMinimumSize(QSize(320, 240));
        blemishhclabel->setFrameShape(QFrame::StyledPanel);
        blemishhclabel->setText(QString::fromUtf8(""));
        blemishhclabel->setScaledContents(true);

        verticalLayout_2->addWidget(blemishhclabel);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        blemishhcGetImagepushButton = new QPushButton(widget);
        blemishhcGetImagepushButton->setObjectName(QString::fromUtf8("blemishhcGetImagepushButton"));
        blemishhcGetImagepushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_14->addWidget(blemishhcGetImagepushButton);

        blemishhcNormalTestpushButton = new QPushButton(widget);
        blemishhcNormalTestpushButton->setObjectName(QString::fromUtf8("blemishhcNormalTestpushButton"));
        blemishhcNormalTestpushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_14->addWidget(blemishhcNormalTestpushButton);

        blemishhcDebugpushButton = new QPushButton(widget);
        blemishhcDebugpushButton->setObjectName(QString::fromUtf8("blemishhcDebugpushButton"));
        blemishhcDebugpushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_14->addWidget(blemishhcDebugpushButton);

        blemishhcLooppushButton = new QPushButton(widget);
        blemishhcLooppushButton->setObjectName(QString::fromUtf8("blemishhcLooppushButton"));
        blemishhcLooppushButton->setFocusPolicy(Qt::NoFocus);
        blemishhcLooppushButton->setText(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/itemexe.png"), QSize(), QIcon::Normal, QIcon::Off);
        blemishhcLooppushButton->setIcon(icon);

        horizontalLayout_14->addWidget(blemishhcLooppushButton);


        verticalLayout_2->addLayout(horizontalLayout_14);

        blemishhclistWidget = new QListWidget(widget);
        blemishhclistWidget->setObjectName(QString::fromUtf8("blemishhclistWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(blemishhclistWidget->sizePolicy().hasHeightForWidth());
        blemishhclistWidget->setSizePolicy(sizePolicy1);
        blemishhclistWidget->setMaximumSize(QSize(16777215, 120));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        blemishhclistWidget->setFont(font1);

        verticalLayout_2->addWidget(blemishhclistWidget);


        horizontalLayout_15->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_12->addWidget(label_2);

        blemishhcAreaMindoubleSpinBox = new QDoubleSpinBox(groupBox);
        blemishhcAreaMindoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcAreaMindoubleSpinBox"));
        blemishhcAreaMindoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcAreaMindoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcAreaMindoubleSpinBox->setDecimals(6);
        blemishhcAreaMindoubleSpinBox->setMinimum(1e-06);
        blemishhcAreaMindoubleSpinBox->setMaximum(0.5);
        blemishhcAreaMindoubleSpinBox->setSingleStep(1e-06);
        blemishhcAreaMindoubleSpinBox->setValue(8e-05);

        horizontalLayout_12->addWidget(blemishhcAreaMindoubleSpinBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_12->addWidget(label_3);

        blemishhcAreaMaxdoubleSpinBox = new QDoubleSpinBox(groupBox);
        blemishhcAreaMaxdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcAreaMaxdoubleSpinBox"));
        blemishhcAreaMaxdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcAreaMaxdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcAreaMaxdoubleSpinBox->setDecimals(6);
        blemishhcAreaMaxdoubleSpinBox->setMinimum(1e-05);
        blemishhcAreaMaxdoubleSpinBox->setMaximum(0.5);
        blemishhcAreaMaxdoubleSpinBox->setSingleStep(1e-05);
        blemishhcAreaMaxdoubleSpinBox->setValue(0.125);

        horizontalLayout_12->addWidget(blemishhcAreaMaxdoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_13->addWidget(label_4);

        blemishhcEdgeZonedoubleSpinBox = new QDoubleSpinBox(groupBox);
        blemishhcEdgeZonedoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcEdgeZonedoubleSpinBox"));
        blemishhcEdgeZonedoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcEdgeZonedoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcEdgeZonedoubleSpinBox->setDecimals(6);
        blemishhcEdgeZonedoubleSpinBox->setMinimum(0);
        blemishhcEdgeZonedoubleSpinBox->setMaximum(0.3);
        blemishhcEdgeZonedoubleSpinBox->setSingleStep(1e-06);
        blemishhcEdgeZonedoubleSpinBox->setValue(0.08);

        horizontalLayout_13->addWidget(blemishhcEdgeZonedoubleSpinBox);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_13->addWidget(label_21);

        blemishhcCornerZonedoubleSpinBox = new QDoubleSpinBox(groupBox);
        blemishhcCornerZonedoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcCornerZonedoubleSpinBox"));
        blemishhcCornerZonedoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcCornerZonedoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcCornerZonedoubleSpinBox->setDecimals(6);
        blemishhcCornerZonedoubleSpinBox->setMinimum(0);
        blemishhcCornerZonedoubleSpinBox->setMaximum(0.3);
        blemishhcCornerZonedoubleSpinBox->setSingleStep(1e-06);
        blemishhcCornerZonedoubleSpinBox->setValue(0.08);

        horizontalLayout_13->addWidget(blemishhcCornerZonedoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_20->addWidget(label_5);

        blemishhcTuningdoubleSpinBox = new QDoubleSpinBox(groupBox);
        blemishhcTuningdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcTuningdoubleSpinBox"));
        blemishhcTuningdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcTuningdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcTuningdoubleSpinBox->setDecimals(1);
        blemishhcTuningdoubleSpinBox->setMinimum(-5);
        blemishhcTuningdoubleSpinBox->setMaximum(5);
        blemishhcTuningdoubleSpinBox->setSingleStep(1);
        blemishhcTuningdoubleSpinBox->setValue(2);

        horizontalLayout_20->addWidget(blemishhcTuningdoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_20);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 2, 0);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        blemishhcZ1BdoubleSpinBox = new QDoubleSpinBox(groupBox_2);
        blemishhcZ1BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ1BdoubleSpinBox"));
        blemishhcZ1BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ1BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ1BdoubleSpinBox->setDecimals(5);
        blemishhcZ1BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ1BdoubleSpinBox->setMaximum(10);
        blemishhcZ1BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ1BdoubleSpinBox->setValue(0.009);

        horizontalLayout->addWidget(blemishhcZ1BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 0, 2, 0);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        blemishhcZ2BdoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        blemishhcZ2BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ2BdoubleSpinBox"));
        blemishhcZ2BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ2BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ2BdoubleSpinBox->setDecimals(5);
        blemishhcZ2BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ2BdoubleSpinBox->setMaximum(10);
        blemishhcZ2BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ2BdoubleSpinBox->setValue(0.009);

        horizontalLayout_2->addWidget(blemishhcZ2BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 0, 2, 0);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        blemishhcZ3BdoubleSpinBox = new QDoubleSpinBox(groupBox_4);
        blemishhcZ3BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ3BdoubleSpinBox"));
        blemishhcZ3BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ3BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ3BdoubleSpinBox->setDecimals(5);
        blemishhcZ3BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ3BdoubleSpinBox->setMaximum(10);
        blemishhcZ3BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ3BdoubleSpinBox->setValue(0.009);

        horizontalLayout_3->addWidget(blemishhcZ3BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(1, 0, 1, 0);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        blemishhcZ4BdoubleSpinBox = new QDoubleSpinBox(groupBox_5);
        blemishhcZ4BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ4BdoubleSpinBox"));
        blemishhcZ4BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ4BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ4BdoubleSpinBox->setDecimals(5);
        blemishhcZ4BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ4BdoubleSpinBox->setMaximum(10);
        blemishhcZ4BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ4BdoubleSpinBox->setValue(0.009);

        horizontalLayout_4->addWidget(blemishhcZ4BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_6);
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);

        blemishhcZ5BdoubleSpinBox = new QDoubleSpinBox(groupBox_6);
        blemishhcZ5BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ5BdoubleSpinBox"));
        blemishhcZ5BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ5BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ5BdoubleSpinBox->setDecimals(5);
        blemishhcZ5BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ5BdoubleSpinBox->setMaximum(10);
        blemishhcZ5BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ5BdoubleSpinBox->setValue(0.009);

        horizontalLayout_5->addWidget(blemishhcZ5BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_7);
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(2, 0, 2, 0);
        label_12 = new QLabel(groupBox_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_6->addWidget(label_12);

        blemishhcZ6BdoubleSpinBox = new QDoubleSpinBox(groupBox_7);
        blemishhcZ6BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ6BdoubleSpinBox"));
        blemishhcZ6BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ6BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ6BdoubleSpinBox->setDecimals(5);
        blemishhcZ6BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ6BdoubleSpinBox->setMaximum(10);
        blemishhcZ6BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ6BdoubleSpinBox->setValue(0.009);

        horizontalLayout_6->addWidget(blemishhcZ6BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_8);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(2, 0, 2, 0);
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_7->addWidget(label_13);

        blemishhcZ7BdoubleSpinBox = new QDoubleSpinBox(groupBox_8);
        blemishhcZ7BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ7BdoubleSpinBox"));
        blemishhcZ7BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ7BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ7BdoubleSpinBox->setDecimals(5);
        blemishhcZ7BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ7BdoubleSpinBox->setMaximum(10);
        blemishhcZ7BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ7BdoubleSpinBox->setValue(0.009);

        horizontalLayout_7->addWidget(blemishhcZ7BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(groupBox);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_9);
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(2, 0, 2, 0);
        label_14 = new QLabel(groupBox_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_8->addWidget(label_14);

        blemishhcZ8BdoubleSpinBox = new QDoubleSpinBox(groupBox_9);
        blemishhcZ8BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ8BdoubleSpinBox"));
        blemishhcZ8BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ8BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ8BdoubleSpinBox->setDecimals(5);
        blemishhcZ8BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ8BdoubleSpinBox->setMaximum(10);
        blemishhcZ8BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ8BdoubleSpinBox->setValue(0.009);

        horizontalLayout_8->addWidget(blemishhcZ8BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(groupBox);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_10);
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(2, 0, 2, 0);
        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_9->addWidget(label_15);

        blemishhcZ9BdoubleSpinBox = new QDoubleSpinBox(groupBox_10);
        blemishhcZ9BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ9BdoubleSpinBox"));
        blemishhcZ9BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ9BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ9BdoubleSpinBox->setDecimals(5);
        blemishhcZ9BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ9BdoubleSpinBox->setMaximum(10);
        blemishhcZ9BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ9BdoubleSpinBox->setValue(0.009);

        horizontalLayout_9->addWidget(blemishhcZ9BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(groupBox);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_11);
        horizontalLayout_10->setSpacing(3);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(2, 0, 2, 0);
        label_16 = new QLabel(groupBox_11);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_10->addWidget(label_16);

        blemishhcZ10BdoubleSpinBox = new QDoubleSpinBox(groupBox_11);
        blemishhcZ10BdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcZ10BdoubleSpinBox"));
        blemishhcZ10BdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcZ10BdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcZ10BdoubleSpinBox->setDecimals(5);
        blemishhcZ10BdoubleSpinBox->setMinimum(0.001);
        blemishhcZ10BdoubleSpinBox->setMaximum(10);
        blemishhcZ10BdoubleSpinBox->setSingleStep(0.001);
        blemishhcZ10BdoubleSpinBox->setValue(0.009);

        horizontalLayout_10->addWidget(blemishhcZ10BdoubleSpinBox);


        verticalLayout->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(groupBox);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_12);
        horizontalLayout_11->setSpacing(3);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(2, 0, 2, 0);
        label_17 = new QLabel(groupBox_12);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_11->addWidget(label_17);

        blemishhcEdgeBdoubleSpinBox = new QDoubleSpinBox(groupBox_12);
        blemishhcEdgeBdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcEdgeBdoubleSpinBox"));
        blemishhcEdgeBdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcEdgeBdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcEdgeBdoubleSpinBox->setDecimals(5);
        blemishhcEdgeBdoubleSpinBox->setMinimum(0.001);
        blemishhcEdgeBdoubleSpinBox->setMaximum(10);
        blemishhcEdgeBdoubleSpinBox->setSingleStep(0.001);
        blemishhcEdgeBdoubleSpinBox->setValue(0.009);

        horizontalLayout_11->addWidget(blemishhcEdgeBdoubleSpinBox);


        verticalLayout->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(groupBox);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        horizontalLayout_18 = new QHBoxLayout(groupBox_13);
        horizontalLayout_18->setSpacing(3);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(2, 0, 2, 0);
        label_19 = new QLabel(groupBox_13);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_18->addWidget(label_19);

        blemishhcCornerBdoubleSpinBox = new QDoubleSpinBox(groupBox_13);
        blemishhcCornerBdoubleSpinBox->setObjectName(QString::fromUtf8("blemishhcCornerBdoubleSpinBox"));
        blemishhcCornerBdoubleSpinBox->setPrefix(QString::fromUtf8(""));
        blemishhcCornerBdoubleSpinBox->setSuffix(QString::fromUtf8(""));
        blemishhcCornerBdoubleSpinBox->setDecimals(5);
        blemishhcCornerBdoubleSpinBox->setMinimum(0.001);
        blemishhcCornerBdoubleSpinBox->setMaximum(10);
        blemishhcCornerBdoubleSpinBox->setSingleStep(0.001);
        blemishhcCornerBdoubleSpinBox->setValue(0.009);

        horizontalLayout_18->addWidget(blemishhcCornerBdoubleSpinBox);


        verticalLayout->addWidget(groupBox_13);

        blemishhcSavepushButton = new QPushButton(groupBox);
        blemishhcSavepushButton->setObjectName(QString::fromUtf8("blemishhcSavepushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(blemishhcSavepushButton->sizePolicy().hasHeightForWidth());
        blemishhcSavepushButton->setSizePolicy(sizePolicy2);
        blemishhcSavepushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(blemishhcSavepushButton);


        horizontalLayout_15->addWidget(groupBox);

        QHBlemishHC->setWidget(widget);

        retranslateUi(QHBlemishHC);

        QMetaObject::connectSlotsByName(QHBlemishHC);
    } // setupUi

    void retranslateUi(QDockWidget *QHBlemishHC)
    {
        QHBlemishHC->setWindowTitle(QApplication::translate("QHBlemishHC", "Blemish-C Tool", 0, QApplication::UnicodeUTF8));
        blemishhcGetImagepushButton->setText(QApplication::translate("QHBlemishHC", "Get Image", 0, QApplication::UnicodeUTF8));
        blemishhcNormalTestpushButton->setText(QApplication::translate("QHBlemishHC", "Normal Test", 0, QApplication::UnicodeUTF8));
        blemishhcDebugpushButton->setText(QApplication::translate("QHBlemishHC", "Debug", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QHBlemishHC", "Spec", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QHBlemishHC", "Blemish Area:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QHBlemishHC", "~", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QHBlemishHC", "Edge Zone:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("QHBlemishHC", "Corner Zone:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QHBlemishHC", "Tuning:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("QHBlemishHC", "Zone1(0-0.1FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("QHBlemishHC", "Zone2(0.1-0.2FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("QHBlemishHC", "Zone3(0.2-0.3FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("QHBlemishHC", "Zone4(0.3-0.4FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("QHBlemishHC", "Zone5(0.4-0.5FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("QHBlemishHC", "Zone6(0.5-0.6FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("QHBlemishHC", "Zone7(0.6-0.7FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("QHBlemishHC", "Zone8(0.7-0.8FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("QHBlemishHC", "Zone9(0.8-0.9FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("QHBlemishHC", "Zone10(0.9-1.0FOV) Spec", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("QHBlemishHC", "Zone Edge Spec", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("QHBlemishHC", "Zone Corner Spec", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("QHBlemishHC", "Brightness:", 0, QApplication::UnicodeUTF8));
        blemishhcSavepushButton->setText(QApplication::translate("QHBlemishHC", "SAVE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHBlemishHC: public Ui_QHBlemishHC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHBLEMISHHC_H
