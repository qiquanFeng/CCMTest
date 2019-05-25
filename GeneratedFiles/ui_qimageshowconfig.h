/********************************************************************************
** Form generated from reading UI file 'qimageshowconfig.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIMAGESHOWCONFIG_H
#define UI_QIMAGESHOWCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_qimageshowconfig
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *aspectRatiocomboBox;
    QComboBox *scaleModecomboBox;
    QComboBox *sodokuModecomboBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *squarecheckBox;
    QLabel *label_4;
    QSpinBox *squareratioxspinBox;
    QLabel *label_5;
    QSpinBox *squareratioyspinBox;
    QCheckBox *crosscheckBox;
    QPushButton *savepushButton;

    void setupUi(QDialog *qimageshowconfig)
    {
        if (qimageshowconfig->objectName().isEmpty())
            qimageshowconfig->setObjectName(QString::fromUtf8("qimageshowconfig"));
        qimageshowconfig->resize(413, 158);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        qimageshowconfig->setFont(font);
        qimageshowconfig->setWindowTitle(QString::fromUtf8("qimageshowconfig"));
        horizontalLayout_3 = new QHBoxLayout(qimageshowconfig);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(qimageshowconfig);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label = new QLabel(qimageshowconfig);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(qimageshowconfig);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        aspectRatiocomboBox = new QComboBox(qimageshowconfig);
        aspectRatiocomboBox->setObjectName(QString::fromUtf8("aspectRatiocomboBox"));

        verticalLayout_2->addWidget(aspectRatiocomboBox);

        scaleModecomboBox = new QComboBox(qimageshowconfig);
        scaleModecomboBox->setObjectName(QString::fromUtf8("scaleModecomboBox"));

        verticalLayout_2->addWidget(scaleModecomboBox);

        sodokuModecomboBox = new QComboBox(qimageshowconfig);
        sodokuModecomboBox->setObjectName(QString::fromUtf8("sodokuModecomboBox"));

        verticalLayout_2->addWidget(sodokuModecomboBox);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        squarecheckBox = new QCheckBox(qimageshowconfig);
        squarecheckBox->setObjectName(QString::fromUtf8("squarecheckBox"));

        horizontalLayout_2->addWidget(squarecheckBox);

        label_4 = new QLabel(qimageshowconfig);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        squareratioxspinBox = new QSpinBox(qimageshowconfig);
        squareratioxspinBox->setObjectName(QString::fromUtf8("squareratioxspinBox"));
        squareratioxspinBox->setMinimum(100);
        squareratioxspinBox->setMaximum(99999);

        horizontalLayout_2->addWidget(squareratioxspinBox);

        label_5 = new QLabel(qimageshowconfig);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        squareratioyspinBox = new QSpinBox(qimageshowconfig);
        squareratioyspinBox->setObjectName(QString::fromUtf8("squareratioyspinBox"));
        squareratioyspinBox->setMinimum(100);
        squareratioyspinBox->setMaximum(99999);

        horizontalLayout_2->addWidget(squareratioyspinBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        crosscheckBox = new QCheckBox(qimageshowconfig);
        crosscheckBox->setObjectName(QString::fromUtf8("crosscheckBox"));

        verticalLayout_3->addWidget(crosscheckBox);


        horizontalLayout_3->addLayout(verticalLayout_3);

        savepushButton = new QPushButton(qimageshowconfig);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(savepushButton->sizePolicy().hasHeightForWidth());
        savepushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(savepushButton);


        retranslateUi(qimageshowconfig);

        sodokuModecomboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(qimageshowconfig);
    } // setupUi

    void retranslateUi(QDialog *qimageshowconfig)
    {
        label_3->setText(QApplication::translate("qimageshowconfig", "Aspect Ratio:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("qimageshowconfig", "Scale Mode:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("qimageshowconfig", "Sodoku Navigation Key:", 0, QApplication::UnicodeUTF8));
        aspectRatiocomboBox->clear();
        aspectRatiocomboBox->insertItems(0, QStringList()
         << QApplication::translate("qimageshowconfig", "Ignore Aspect Ratio", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Keep Aspect Ratio", 0, QApplication::UnicodeUTF8)
        );
        scaleModecomboBox->clear();
        scaleModecomboBox->insertItems(0, QStringList()
         << QApplication::translate("qimageshowconfig", "Near", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Bilinear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Area", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Bicubic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Lanczos", 0, QApplication::UnicodeUTF8)
        );
        sodokuModecomboBox->clear();
        sodokuModecomboBox->insertItems(0, QStringList()
         << QApplication::translate("qimageshowconfig", "Num1~9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("qimageshowconfig", "Arrow Key", 0, QApplication::UnicodeUTF8)
        );
        squarecheckBox->setText(QApplication::translate("qimageshowconfig", "Square", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("qimageshowconfig", "Width", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("qimageshowconfig", "Height", 0, QApplication::UnicodeUTF8));
        crosscheckBox->setText(QApplication::translate("qimageshowconfig", "Cross", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("qimageshowconfig", "SAVE", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(qimageshowconfig);
    } // retranslateUi

};

namespace Ui {
    class qimageshowconfig: public Ui_qimageshowconfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIMAGESHOWCONFIG_H
