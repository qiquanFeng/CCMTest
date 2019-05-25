/********************************************************************************
** Form generated from reading UI file 'updatefirewaredialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEFIREWAREDIALOG_H
#define UI_UPDATEFIREWAREDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_updatefirewaredialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *binPathlineEdit;
    QPushButton *browsepushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *updatepushButton;
    QPushButton *cancelpushButton;

    void setupUi(QDialog *updatefirewaredialog)
    {
        if (updatefirewaredialog->objectName().isEmpty())
            updatefirewaredialog->setObjectName(QString::fromUtf8("updatefirewaredialog"));
        updatefirewaredialog->resize(482, 141);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        updatefirewaredialog->setFont(font);
        updatefirewaredialog->setModal(false);
        verticalLayout = new QVBoxLayout(updatefirewaredialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(updatefirewaredialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        binPathlineEdit = new QLineEdit(updatefirewaredialog);
        binPathlineEdit->setObjectName(QString::fromUtf8("binPathlineEdit"));
        binPathlineEdit->setInputMask(QString::fromUtf8(""));

        horizontalLayout->addWidget(binPathlineEdit);

        browsepushButton = new QPushButton(updatefirewaredialog);
        browsepushButton->setObjectName(QString::fromUtf8("browsepushButton"));

        horizontalLayout->addWidget(browsepushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        updatepushButton = new QPushButton(updatefirewaredialog);
        updatepushButton->setObjectName(QString::fromUtf8("updatepushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(updatepushButton->sizePolicy().hasHeightForWidth());
        updatepushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        updatepushButton->setFont(font1);

        horizontalLayout_3->addWidget(updatepushButton);

        cancelpushButton = new QPushButton(updatefirewaredialog);
        cancelpushButton->setObjectName(QString::fromUtf8("cancelpushButton"));
        sizePolicy.setHeightForWidth(cancelpushButton->sizePolicy().hasHeightForWidth());
        cancelpushButton->setSizePolicy(sizePolicy);
        cancelpushButton->setFont(font1);

        horizontalLayout_3->addWidget(cancelpushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(updatefirewaredialog);

        QMetaObject::connectSlotsByName(updatefirewaredialog);
    } // setupUi

    void retranslateUi(QDialog *updatefirewaredialog)
    {
        updatefirewaredialog->setWindowTitle(QApplication::translate("updatefirewaredialog", "updatefirewaredialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("updatefirewaredialog", "Choose Bin:", 0, QApplication::UnicodeUTF8));
        browsepushButton->setText(QApplication::translate("updatefirewaredialog", "Browse", 0, QApplication::UnicodeUTF8));
        updatepushButton->setText(QApplication::translate("updatefirewaredialog", "UPDATE", 0, QApplication::UnicodeUTF8));
        cancelpushButton->setText(QApplication::translate("updatefirewaredialog", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class updatefirewaredialog: public Ui_updatefirewaredialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEFIREWAREDIALOG_H
