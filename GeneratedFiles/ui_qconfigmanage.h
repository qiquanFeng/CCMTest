/********************************************************************************
** Form generated from reading UI file 'qconfigmanage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCONFIGMANAGE_H
#define UI_QCONFIGMANAGE_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qconfigmanage
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *selectALL_checkBox;
    QCheckBox *selectNone_checkBox;
    QLineEdit *serachlineEdit;
    QScrollArea *configList_scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *importDBradioButton;
    QRadioButton *importXMLradioButton;
    QRadioButton *importTxtradioButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *import_pushButton;
    QPushButton *export_pushButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *plainradioButton;
    QRadioButton *createAndCopyradioButton;
    QPushButton *new_pushButton;
    QPushButton *rename_pushButton;
    QPushButton *delete_pushButton;
    QLabel *info_label;

    void setupUi(QDialog *qconfigmanage)
    {
        if (qconfigmanage->objectName().isEmpty())
            qconfigmanage->setObjectName(QString::fromUtf8("qconfigmanage"));
        qconfigmanage->resize(656, 507);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        qconfigmanage->setFont(font);
        verticalLayout_5 = new QVBoxLayout(qconfigmanage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        selectALL_checkBox = new QCheckBox(qconfigmanage);
        selectALL_checkBox->setObjectName(QString::fromUtf8("selectALL_checkBox"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        selectALL_checkBox->setFont(font1);

        horizontalLayout_3->addWidget(selectALL_checkBox);

        selectNone_checkBox = new QCheckBox(qconfigmanage);
        selectNone_checkBox->setObjectName(QString::fromUtf8("selectNone_checkBox"));
        selectNone_checkBox->setFont(font1);

        horizontalLayout_3->addWidget(selectNone_checkBox);

        serachlineEdit = new QLineEdit(qconfigmanage);
        serachlineEdit->setObjectName(QString::fromUtf8("serachlineEdit"));
        serachlineEdit->setInputMask(QString::fromUtf8(""));
        serachlineEdit->setText(QString::fromUtf8(""));
        serachlineEdit->setMaxLength(100);
        serachlineEdit->setPlaceholderText(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(serachlineEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        configList_scrollArea = new QScrollArea(qconfigmanage);
        configList_scrollArea->setObjectName(QString::fromUtf8("configList_scrollArea"));
        configList_scrollArea->setFont(font1);
        configList_scrollArea->setWidgetResizable(true);
        configList_scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 251, 421));
        configList_scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(configList_scrollArea);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(qconfigmanage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        importDBradioButton = new QRadioButton(groupBox);
        importDBradioButton->setObjectName(QString::fromUtf8("importDBradioButton"));

        horizontalLayout->addWidget(importDBradioButton);

        importXMLradioButton = new QRadioButton(groupBox);
        importXMLradioButton->setObjectName(QString::fromUtf8("importXMLradioButton"));
        importXMLradioButton->setChecked(false);

        horizontalLayout->addWidget(importXMLradioButton);

        importTxtradioButton = new QRadioButton(groupBox);
        importTxtradioButton->setObjectName(QString::fromUtf8("importTxtradioButton"));
        importTxtradioButton->setChecked(true);

        horizontalLayout->addWidget(importTxtradioButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        import_pushButton = new QPushButton(groupBox);
        import_pushButton->setObjectName(QString::fromUtf8("import_pushButton"));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        import_pushButton->setFont(font2);

        horizontalLayout_2->addWidget(import_pushButton);

        export_pushButton = new QPushButton(groupBox);
        export_pushButton->setObjectName(QString::fromUtf8("export_pushButton"));
        export_pushButton->setFont(font2);

        horizontalLayout_2->addWidget(export_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(qconfigmanage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        plainradioButton = new QRadioButton(groupBox_2);
        plainradioButton->setObjectName(QString::fromUtf8("plainradioButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainradioButton->sizePolicy().hasHeightForWidth());
        plainradioButton->setSizePolicy(sizePolicy);
        plainradioButton->setMinimumSize(QSize(130, 0));
        plainradioButton->setMaximumSize(QSize(230, 16777215));
        plainradioButton->setMouseTracking(true);
        plainradioButton->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_2->addWidget(plainradioButton);

        createAndCopyradioButton = new QRadioButton(groupBox_2);
        createAndCopyradioButton->setObjectName(QString::fromUtf8("createAndCopyradioButton"));
        sizePolicy.setHeightForWidth(createAndCopyradioButton->sizePolicy().hasHeightForWidth());
        createAndCopyradioButton->setSizePolicy(sizePolicy);
        createAndCopyradioButton->setMinimumSize(QSize(130, 0));
        createAndCopyradioButton->setMaximumSize(QSize(230, 16777215));
        createAndCopyradioButton->setMouseTracking(true);
        createAndCopyradioButton->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_2->addWidget(createAndCopyradioButton);

        new_pushButton = new QPushButton(groupBox_2);
        new_pushButton->setObjectName(QString::fromUtf8("new_pushButton"));
        new_pushButton->setFont(font2);

        verticalLayout_2->addWidget(new_pushButton);


        verticalLayout_3->addWidget(groupBox_2);

        rename_pushButton = new QPushButton(qconfigmanage);
        rename_pushButton->setObjectName(QString::fromUtf8("rename_pushButton"));
        rename_pushButton->setFont(font2);

        verticalLayout_3->addWidget(rename_pushButton);

        delete_pushButton = new QPushButton(qconfigmanage);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setFont(font2);

        verticalLayout_3->addWidget(delete_pushButton);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);

        info_label = new QLabel(qconfigmanage);
        info_label->setObjectName(QString::fromUtf8("info_label"));
        sizePolicy.setHeightForWidth(info_label->sizePolicy().hasHeightForWidth());
        info_label->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        info_label->setFont(font3);
        info_label->setFrameShape(QFrame::StyledPanel);

        verticalLayout_5->addWidget(info_label);


        retranslateUi(qconfigmanage);

        QMetaObject::connectSlotsByName(qconfigmanage);
    } // setupUi

    void retranslateUi(QDialog *qconfigmanage)
    {
        qconfigmanage->setWindowTitle(QApplication::translate("qconfigmanage", "qconfigmanage", 0, QApplication::UnicodeUTF8));
        selectALL_checkBox->setText(QApplication::translate("qconfigmanage", "Select All", 0, QApplication::UnicodeUTF8));
        selectNone_checkBox->setText(QApplication::translate("qconfigmanage", "Don't Select ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("qconfigmanage", "Import/Export", 0, QApplication::UnicodeUTF8));
        importDBradioButton->setText(QApplication::translate("qconfigmanage", "Rolongo DB", 0, QApplication::UnicodeUTF8));
        importXMLradioButton->setText(QApplication::translate("qconfigmanage", "Rolongo XML", 0, QApplication::UnicodeUTF8));
        importTxtradioButton->setText(QApplication::translate("qconfigmanage", "Rolongo TXT", 0, QApplication::UnicodeUTF8));
        import_pushButton->setText(QApplication::translate("qconfigmanage", "Import", 0, QApplication::UnicodeUTF8));
        export_pushButton->setText(QApplication::translate("qconfigmanage", "Export", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("qconfigmanage", "Create New Form", 0, QApplication::UnicodeUTF8));
        plainradioButton->setText(QApplication::translate("qconfigmanage", "Blank Form", 0, QApplication::UnicodeUTF8));
        createAndCopyradioButton->setText(QApplication::translate("qconfigmanage", "Create And Copy", 0, QApplication::UnicodeUTF8));
        new_pushButton->setText(QApplication::translate("qconfigmanage", "Create", 0, QApplication::UnicodeUTF8));
        rename_pushButton->setText(QApplication::translate("qconfigmanage", "Rename", 0, QApplication::UnicodeUTF8));
        delete_pushButton->setText(QApplication::translate("qconfigmanage", "Delete", 0, QApplication::UnicodeUTF8));
        info_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class qconfigmanage: public Ui_qconfigmanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCONFIGMANAGE_H
