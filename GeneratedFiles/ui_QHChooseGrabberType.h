/********************************************************************************
** Form generated from reading UI file 'QHChooseGrabberType.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHCHOOSEGRABBERTYPE_H
#define UI_QHCHOOSEGRABBERTYPE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHChooseGrabberType
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *typecomboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *okpushButton;
    QPushButton *cancelpushButton;

    void setupUi(QDialog *QHChooseGrabberType)
    {
        if (QHChooseGrabberType->objectName().isEmpty())
            QHChooseGrabberType->setObjectName(QString::fromUtf8("QHChooseGrabberType"));
        QHChooseGrabberType->resize(330, 154);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        QHChooseGrabberType->setFont(font);
        verticalLayout = new QVBoxLayout(QHChooseGrabberType);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(QHChooseGrabberType);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        typecomboBox = new QComboBox(QHChooseGrabberType);
        typecomboBox->insertItems(0, QStringList()
         << QString::fromUtf8("R2R3")
         << QString::fromUtf8("R3X")
         << QString::fromUtf8("R5")
         << QString::fromUtf8("R5X")
         << QString::fromUtf8("R6(C-PHY)")
        );
        typecomboBox->setObjectName(QString::fromUtf8("typecomboBox"));

        horizontalLayout_2->addWidget(typecomboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okpushButton = new QPushButton(QHChooseGrabberType);
        okpushButton->setObjectName(QString::fromUtf8("okpushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okpushButton->sizePolicy().hasHeightForWidth());
        okpushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(okpushButton);

        cancelpushButton = new QPushButton(QHChooseGrabberType);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        sizePolicy.setHeightForWidth(cancelpushButton->sizePolicy().hasHeightForWidth());
        cancelpushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cancelpushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QHChooseGrabberType);

        QMetaObject::connectSlotsByName(QHChooseGrabberType);
    } // setupUi

    void retranslateUi(QDialog *QHChooseGrabberType)
    {
        QHChooseGrabberType->setWindowTitle(QApplication::translate("QHChooseGrabberType", "Choose Grabber Type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QHChooseGrabberType", "Choose Grabber Type:", 0, QApplication::UnicodeUTF8));
        okpushButton->setText(QApplication::translate("QHChooseGrabberType", "OK", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("QHChooseGrabberType", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHChooseGrabberType: public Ui_QHChooseGrabberType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHCHOOSEGRABBERTYPE_H
