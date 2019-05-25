/********************************************************************************
** Form generated from reading UI file 'importtable.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTTABLE_H
#define UI_IMPORTTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_importtable
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *databasePathlineEdit;
    QPushButton *pathpushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *refeshpushButton;
    QComboBox *tableListcomboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *tableRenamelineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *importpushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelpushButton;
    QLabel *infolabel;

    void setupUi(QDialog *importtable)
    {
        if (importtable->objectName().isEmpty())
            importtable->setObjectName(QString::fromUtf8("importtable"));
        importtable->resize(508, 224);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        importtable->setFont(font);
        verticalLayout = new QVBoxLayout(importtable);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(importtable);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        databasePathlineEdit = new QLineEdit(importtable);
        databasePathlineEdit->setObjectName(QString::fromUtf8("databasePathlineEdit"));
        databasePathlineEdit->setFont(font1);

        horizontalLayout->addWidget(databasePathlineEdit);

        pathpushButton = new QPushButton(importtable);
        pathpushButton->setObjectName(QString::fromUtf8("pathpushButton"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pathpushButton->setFont(font2);

        horizontalLayout->addWidget(pathpushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        refeshpushButton = new QPushButton(importtable);
        refeshpushButton->setObjectName(QString::fromUtf8("refeshpushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        refeshpushButton->setFont(font3);

        horizontalLayout_2->addWidget(refeshpushButton);

        tableListcomboBox = new QComboBox(importtable);
        tableListcomboBox->setObjectName(QString::fromUtf8("tableListcomboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableListcomboBox->sizePolicy().hasHeightForWidth());
        tableListcomboBox->setSizePolicy(sizePolicy);
        tableListcomboBox->setFont(font3);

        horizontalLayout_2->addWidget(tableListcomboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(importtable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        tableRenamelineEdit = new QLineEdit(importtable);
        tableRenamelineEdit->setObjectName(QString::fromUtf8("tableRenamelineEdit"));
        tableRenamelineEdit->setFont(font1);

        horizontalLayout_4->addWidget(tableRenamelineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        importpushButton = new QPushButton(importtable);
        importpushButton->setObjectName(QString::fromUtf8("importpushButton"));
        importpushButton->setMinimumSize(QSize(150, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        importpushButton->setFont(font4);

        horizontalLayout_3->addWidget(importpushButton);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cancelpushButton = new QPushButton(importtable);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        cancelpushButton->setMinimumSize(QSize(150, 0));
        cancelpushButton->setFont(font4);

        horizontalLayout_3->addWidget(cancelpushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        infolabel = new QLabel(importtable);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        infolabel->setFont(font3);
        infolabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(infolabel);


        retranslateUi(importtable);

        QMetaObject::connectSlotsByName(importtable);
    } // setupUi

    void retranslateUi(QDialog *importtable)
    {
        importtable->setWindowTitle(QApplication::translate("importtable", "importtable", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("importtable", "Select the database path:", 0, QApplication::UnicodeUTF8));
        pathpushButton->setText(QApplication::translate("importtable", "Browse...", 0, QApplication::UnicodeUTF8));
        refeshpushButton->setText(QApplication::translate("importtable", "Refresh the form list", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("importtable", "Rename\357\274\232", 0, QApplication::UnicodeUTF8));
        importpushButton->setText(QApplication::translate("importtable", "Import", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("importtable", "Cancel", 0, QApplication::UnicodeUTF8));
        infolabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class importtable: public Ui_importtable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTTABLE_H
