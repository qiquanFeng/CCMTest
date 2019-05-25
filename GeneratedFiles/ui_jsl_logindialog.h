/********************************************************************************
** Form generated from reading UI file 'jsl_logindialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSL_LOGINDIALOG_H
#define UI_JSL_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_jsl_loginDialog
{
public:

    void setupUi(QDialog *jsl_loginDialog)
    {
        if (jsl_loginDialog->objectName().isEmpty())
            jsl_loginDialog->setObjectName(QString::fromUtf8("jsl_loginDialog"));
        jsl_loginDialog->resize(400, 300);

        retranslateUi(jsl_loginDialog);

        QMetaObject::connectSlotsByName(jsl_loginDialog);
    } // setupUi

    void retranslateUi(QDialog *jsl_loginDialog)
    {
        jsl_loginDialog->setWindowTitle(QApplication::translate("jsl_loginDialog", "jsl_loginDialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class jsl_loginDialog: public Ui_jsl_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSL_LOGINDIALOG_H
