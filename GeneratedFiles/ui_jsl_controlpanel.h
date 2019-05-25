/********************************************************************************
** Form generated from reading UI file 'jsl_controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSL_CONTROLPANEL_H
#define UI_JSL_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jsl_controlpanel
{
public:

    void setupUi(QWidget *jsl_controlpanel)
    {
        if (jsl_controlpanel->objectName().isEmpty())
            jsl_controlpanel->setObjectName(QString::fromUtf8("jsl_controlpanel"));
        jsl_controlpanel->resize(555, 454);

        retranslateUi(jsl_controlpanel);

        QMetaObject::connectSlotsByName(jsl_controlpanel);
    } // setupUi

    void retranslateUi(QWidget *jsl_controlpanel)
    {
        jsl_controlpanel->setWindowTitle(QApplication::translate("jsl_controlpanel", "jsl_controlpanel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class jsl_controlpanel: public Ui_jsl_controlpanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSL_CONTROLPANEL_H
