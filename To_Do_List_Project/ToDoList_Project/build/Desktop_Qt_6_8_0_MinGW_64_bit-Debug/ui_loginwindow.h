/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseButton;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *PassWordEdit;
    QLineEdit *UsrNameEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LoginInButton;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLabel *ProFileLabel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1400, 900);
        Form->setMinimumSize(QSize(1400, 900));
        Form->setMaximumSize(QSize(1400, 900));
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CloseButton = new QPushButton(Form);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(CloseButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 11, 2, 1, 1);

        PassWordEdit = new QLineEdit(Form);
        PassWordEdit->setObjectName("PassWordEdit");
        PassWordEdit->setMinimumSize(QSize(0, 50));
        PassWordEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(PassWordEdit, 4, 1, 4, 3);

        UsrNameEdit = new QLineEdit(Form);
        UsrNameEdit->setObjectName("UsrNameEdit");
        UsrNameEdit->setMinimumSize(QSize(0, 50));
        UsrNameEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(UsrNameEdit, 2, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        LoginInButton = new QPushButton(Form);
        LoginInButton->setObjectName("LoginInButton");
        LoginInButton->setMinimumSize(QSize(0, 60));
        LoginInButton->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(LoginInButton, 12, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        checkBox = new QCheckBox(Form);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 10, 1, 1, 3);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 8, 2, 1, 1);

        ProFileLabel = new QLabel(Form);
        ProFileLabel->setObjectName("ProFileLabel");
        ProFileLabel->setMinimumSize(QSize(200, 200));
        ProFileLabel->setMaximumSize(QSize(200, 200));

        gridLayout->addWidget(ProFileLabel, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        CloseButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        LoginInButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("Form", "new user", nullptr));
        ProFileLabel->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
