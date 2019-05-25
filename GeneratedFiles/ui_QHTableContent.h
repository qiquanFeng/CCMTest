/********************************************************************************
** Form generated from reading UI file 'QHTableContent.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHTABLECONTENT_H
#define UI_QHTABLECONTENT_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QHTableContent
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *customtableView;
    QVBoxLayout *verticalLayout;
    QComboBox *customcomboBox;
    QSpacerItem *verticalSpacer;
    QPushButton *customsavepushButton;
    QPushButton *customfreshpushButton;
    QLabel *statuslabel;

    void setupUi(QDialog *QHTableContent)
    {
        if (QHTableContent->objectName().isEmpty())
            QHTableContent->setObjectName(QString::fromUtf8("QHTableContent"));
        QHTableContent->resize(712, 567);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QHTableContent->setFont(font);
        QHTableContent->setContextMenuPolicy(Qt::CustomContextMenu);
        verticalLayout_2 = new QVBoxLayout(QHTableContent);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        customtableView = new QTableView(QHTableContent);
        customtableView->setObjectName(QString::fromUtf8("customtableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customtableView->sizePolicy().hasHeightForWidth());
        customtableView->setSizePolicy(sizePolicy);
        customtableView->setMinimumSize(QSize(463, 340));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        customtableView->setFont(font1);
        customtableView->setContextMenuPolicy(Qt::CustomContextMenu);
        customtableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
        customtableView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        customtableView->setWordWrap(false);
        customtableView->setCornerButtonEnabled(false);

        horizontalLayout->addWidget(customtableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        customcomboBox = new QComboBox(QHTableContent);
        customcomboBox->setObjectName(QString::fromUtf8("customcomboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customcomboBox->sizePolicy().hasHeightForWidth());
        customcomboBox->setSizePolicy(sizePolicy1);
        customcomboBox->setMinimumSize(QSize(130, 0));
        customcomboBox->setMaximumSize(QSize(230, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        customcomboBox->setFont(font2);

        verticalLayout->addWidget(customcomboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        customsavepushButton = new QPushButton(QHTableContent);
        customsavepushButton->setObjectName(QString::fromUtf8("customsavepushButton"));
        sizePolicy1.setHeightForWidth(customsavepushButton->sizePolicy().hasHeightForWidth());
        customsavepushButton->setSizePolicy(sizePolicy1);
        customsavepushButton->setMinimumSize(QSize(130, 41));
        customsavepushButton->setMaximumSize(QSize(230, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        customsavepushButton->setFont(font3);
        customsavepushButton->setContextMenuPolicy(Qt::NoContextMenu);
        customsavepushButton->setDefault(true);

        verticalLayout->addWidget(customsavepushButton);

        customfreshpushButton = new QPushButton(QHTableContent);
        customfreshpushButton->setObjectName(QString::fromUtf8("customfreshpushButton"));
        sizePolicy1.setHeightForWidth(customfreshpushButton->sizePolicy().hasHeightForWidth());
        customfreshpushButton->setSizePolicy(sizePolicy1);
        customfreshpushButton->setMinimumSize(QSize(130, 41));
        customfreshpushButton->setMaximumSize(QSize(230, 41));
        customfreshpushButton->setFont(font3);
        customfreshpushButton->setContextMenuPolicy(Qt::NoContextMenu);
        customfreshpushButton->setDefault(true);

        verticalLayout->addWidget(customfreshpushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        statuslabel = new QLabel(QHTableContent);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        QFont font4;
        font4.setPointSize(12);
        statuslabel->setFont(font4);
        statuslabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(statuslabel);


        retranslateUi(QHTableContent);

        QMetaObject::connectSlotsByName(QHTableContent);
    } // setupUi

    void retranslateUi(QDialog *QHTableContent)
    {
        QHTableContent->setWindowTitle(QApplication::translate("QHTableContent", "QHTableContent", 0, QApplication::UnicodeUTF8));
        customsavepushButton->setText(QApplication::translate("QHTableContent", "Save", 0, QApplication::UnicodeUTF8));
        customfreshpushButton->setText(QApplication::translate("QHTableContent", "Cancel", 0, QApplication::UnicodeUTF8));
        statuslabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QHTableContent: public Ui_QHTableContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHTABLECONTENT_H
