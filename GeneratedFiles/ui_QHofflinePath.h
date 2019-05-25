/********************************************************************************
** Form generated from reading UI file 'QHofflinePath.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHOFFLINEPATH_H
#define UI_QHOFFLINEPATH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHofflinePath
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *offlinepathlineEdit;
    QPushButton *offlineopenpushButton;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *readsamepicturecheckBox;
    QPushButton *savepushButton;

    void setupUi(QDialog *QHofflinePath)
    {
        if (QHofflinePath->objectName().isEmpty())
            QHofflinePath->setObjectName(QString::fromUtf8("QHofflinePath"));
        QHofflinePath->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(QHofflinePath);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(QHofflinePath);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        offlinepathlineEdit = new QLineEdit(groupBox);
        offlinepathlineEdit->setObjectName(QString::fromUtf8("offlinepathlineEdit"));

        horizontalLayout->addWidget(offlinepathlineEdit);

        offlineopenpushButton = new QPushButton(groupBox);
        offlineopenpushButton->setObjectName(QString::fromUtf8("offlineopenpushButton"));

        horizontalLayout->addWidget(offlineopenpushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        readsamepicturecheckBox = new QCheckBox(groupBox);
        readsamepicturecheckBox->setObjectName(QString::fromUtf8("readsamepicturecheckBox"));

        horizontalLayout_3->addWidget(readsamepicturecheckBox);

        savepushButton = new QPushButton(groupBox);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));

        horizontalLayout_3->addWidget(savepushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(QHofflinePath);

        QMetaObject::connectSlotsByName(QHofflinePath);
    } // setupUi

    void retranslateUi(QDialog *QHofflinePath)
    {
        QHofflinePath->setWindowTitle(QApplication::translate("QHofflinePath", "QHofflinePath", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QHofflinePath", "Offline Setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QHofflinePath", "Path", 0, QApplication::UnicodeUTF8));
        offlineopenpushButton->setText(QApplication::translate("QHofflinePath", "OPEN", 0, QApplication::UnicodeUTF8));
        readsamepicturecheckBox->setText(QApplication::translate("QHofflinePath", "load same picture", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("QHofflinePath", "save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QHofflinePath: public Ui_QHofflinePath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHOFFLINEPATH_H
