/********************************************************************************
** Form generated from reading UI file 'savedebuginfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDEBUGINFO_H
#define UI_SAVEDEBUGINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_savedebuginfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLineEdit *filedir;
    QPushButton *dirButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QDialog *savedebuginfo)
    {
        if (savedebuginfo->objectName().isEmpty())
            savedebuginfo->setObjectName(QString::fromUtf8("savedebuginfo"));
        savedebuginfo->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(savedebuginfo);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(savedebuginfo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);
        name->setContextMenuPolicy(Qt::NoContextMenu);
        name->setFrameShape(QFrame::StyledPanel);
        name->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(name);

        filedir = new QLineEdit(groupBox);
        filedir->setObjectName(QString::fromUtf8("filedir"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(10);
        filedir->setFont(font1);
        filedir->setReadOnly(true);

        horizontalLayout->addWidget(filedir);

        dirButton = new QPushButton(groupBox);
        dirButton->setObjectName(QString::fromUtf8("dirButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        dirButton->setFont(font2);

        horizontalLayout->addWidget(dirButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        saveButton = new QPushButton(groupBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(130, 0));
        saveButton->setFont(font);

        horizontalLayout_4->addWidget(saveButton);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(130, 0));
        cancelButton->setFont(font);

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

#ifndef QT_NO_SHORTCUT
        name->setBuddy(dirButton);
#endif // QT_NO_SHORTCUT

        retranslateUi(savedebuginfo);

        QMetaObject::connectSlotsByName(savedebuginfo);
    } // setupUi

    void retranslateUi(QDialog *savedebuginfo)
    {
        savedebuginfo->setWindowTitle(QApplication::translate("savedebuginfo", "savedebuginfo", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        name->setText(QApplication::translate("savedebuginfo", "Save Dir:", 0, QApplication::UnicodeUTF8));
        dirButton->setText(QApplication::translate("savedebuginfo", "Browse...", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("savedebuginfo", "SAVE", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("savedebuginfo", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class savedebuginfo: public Ui_savedebuginfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDEBUGINFO_H
