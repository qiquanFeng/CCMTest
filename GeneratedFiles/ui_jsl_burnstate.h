/********************************************************************************
** Form generated from reading UI file 'jsl_burnstate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSL_BURNSTATE_H
#define UI_JSL_BURNSTATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jsl_burnState
{
public:

    void setupUi(QWidget *jsl_burnState)
    {
        if (jsl_burnState->objectName().isEmpty())
            jsl_burnState->setObjectName(QString::fromUtf8("jsl_burnState"));
        jsl_burnState->resize(524, 331);

        retranslateUi(jsl_burnState);

        QMetaObject::connectSlotsByName(jsl_burnState);
    } // setupUi

    void retranslateUi(QWidget *jsl_burnState)
    {
        jsl_burnState->setWindowTitle(QApplication::translate("jsl_burnState", "jsl_burnState", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class jsl_burnState: public Ui_jsl_burnState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSL_BURNSTATE_H
