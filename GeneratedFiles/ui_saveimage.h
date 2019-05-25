/********************************************************************************
** Form generated from reading UI file 'saveimage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEIMAGE_H
#define UI_SAVEIMAGE_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_saveimage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLineEdit *filedir;
    QPushButton *dirButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name_2;
    QLineEdit *filename;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *originalradio;
    QRadioButton *lableradio;
    QRadioButton *appradio;
    QRadioButton *desktopradio;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QDialog *saveimage)
    {
        if (saveimage->objectName().isEmpty())
            saveimage->setObjectName(QString::fromUtf8("saveimage"));
        saveimage->resize(506, 214);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setBold(true);
        font.setWeight(75);
        saveimage->setFont(font);
        verticalLayout = new QVBoxLayout(saveimage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name = new QLabel(saveimage);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        name->setFont(font1);
        name->setContextMenuPolicy(Qt::NoContextMenu);
        name->setFrameShape(QFrame::StyledPanel);
        name->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(name);

        filedir = new QLineEdit(saveimage);
        filedir->setObjectName(QString::fromUtf8("filedir"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(10);
        filedir->setFont(font2);
        filedir->setReadOnly(true);

        horizontalLayout->addWidget(filedir);

        dirButton = new QPushButton(saveimage);
        dirButton->setObjectName(QString::fromUtf8("dirButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        dirButton->setFont(font3);

        horizontalLayout->addWidget(dirButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        name_2 = new QLabel(saveimage);
        name_2->setObjectName(QString::fromUtf8("name_2"));
        name_2->setFont(font1);
        name_2->setContextMenuPolicy(Qt::NoContextMenu);
        name_2->setFrameShape(QFrame::StyledPanel);
        name_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(name_2);

        filename = new QLineEdit(saveimage);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setFont(font2);
        filename->setReadOnly(false);

        horizontalLayout_2->addWidget(filename);


        verticalLayout->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(saveimage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        comboBox->setFont(font4);

        verticalLayout->addWidget(comboBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        originalradio = new QRadioButton(saveimage);
        originalradio->setObjectName(QString::fromUtf8("originalradio"));
        originalradio->setFont(font3);

        horizontalLayout_3->addWidget(originalradio);

        lableradio = new QRadioButton(saveimage);
        lableradio->setObjectName(QString::fromUtf8("lableradio"));
        lableradio->setFont(font3);

        horizontalLayout_3->addWidget(lableradio);

        appradio = new QRadioButton(saveimage);
        appradio->setObjectName(QString::fromUtf8("appradio"));
        appradio->setFont(font3);

        horizontalLayout_3->addWidget(appradio);

        desktopradio = new QRadioButton(saveimage);
        desktopradio->setObjectName(QString::fromUtf8("desktopradio"));
        desktopradio->setFont(font3);

        horizontalLayout_3->addWidget(desktopradio);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        saveButton = new QPushButton(saveimage);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(130, 0));
        saveButton->setFont(font1);

        horizontalLayout_4->addWidget(saveButton);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancelButton = new QPushButton(saveimage);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(130, 0));
        cancelButton->setFont(font1);

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);

#ifndef QT_NO_SHORTCUT
        name->setBuddy(dirButton);
        name_2->setBuddy(filename);
#endif // QT_NO_SHORTCUT

        retranslateUi(saveimage);

        QMetaObject::connectSlotsByName(saveimage);
    } // setupUi

    void retranslateUi(QDialog *saveimage)
    {
        saveimage->setWindowTitle(QApplication::translate("saveimage", "saveimage", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("saveimage", "Save Dir:", 0, QApplication::UnicodeUTF8));
        dirButton->setText(QApplication::translate("saveimage", "Browse...", 0, QApplication::UnicodeUTF8));
        name_2->setText(QApplication::translate("saveimage", "Save Name:", 0, QApplication::UnicodeUTF8));
        originalradio->setText(QApplication::translate("saveimage", "Sensor Image", 0, QApplication::UnicodeUTF8));
        lableradio->setText(QApplication::translate("saveimage", "Image shot", 0, QApplication::UnicodeUTF8));
        appradio->setText(QApplication::translate("saveimage", "Program shot", 0, QApplication::UnicodeUTF8));
        desktopradio->setText(QApplication::translate("saveimage", "Screen shot", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("saveimage", "SAVE", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("saveimage", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class saveimage: public Ui_saveimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEIMAGE_H
