/********************************************************************************
** Form generated from reading UI file 'taskdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QPushButton *okButton;
    QLineEdit *titleLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QDateTimeEdit *deadlineDateEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *prioritySpinBox;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *tagLineEdit;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QTextEdit *notesTextEdit;
    QPushButton *MarkAsDoneButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(696, 616);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelButton = new QPushButton(Form);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 10, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 1, 1, 1);

        okButton = new QPushButton(Form);
        okButton->setObjectName("okButton");

        gridLayout->addWidget(okButton, 13, 1, 1, 2);

        titleLineEdit = new QLineEdit(Form);
        titleLineEdit->setObjectName("titleLineEdit");

        gridLayout->addWidget(titleLineEdit, 2, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 10, 0, 1, 1);

        deadlineDateEdit = new QDateTimeEdit(Form);
        deadlineDateEdit->setObjectName("deadlineDateEdit");
        deadlineDateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 1)));

        gridLayout->addWidget(deadlineDateEdit, 4, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 13, 0, 1, 1);

        prioritySpinBox = new QSpinBox(Form);
        prioritySpinBox->setObjectName("prioritySpinBox");
        prioritySpinBox->setMinimum(1);
        prioritySpinBox->setMaximum(3);

        gridLayout->addWidget(prioritySpinBox, 6, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 3, 1, 1, 1);

        tagLineEdit = new QLineEdit(Form);
        tagLineEdit->setObjectName("tagLineEdit");

        gridLayout->addWidget(tagLineEdit, 8, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 11, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 13, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 12, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 9, 1, 1, 1);

        notesTextEdit = new QTextEdit(Form);
        notesTextEdit->setObjectName("notesTextEdit");

        gridLayout->addWidget(notesTextEdit, 10, 1, 1, 1);

        MarkAsDoneButton = new QPushButton(Form);
        MarkAsDoneButton->setObjectName("MarkAsDoneButton");

        gridLayout->addWidget(MarkAsDoneButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        cancelButton->setText(QCoreApplication::translate("Form", "Cancle", nullptr));
        okButton->setText(QCoreApplication::translate("Form", "OK", nullptr));
#if QT_CONFIG(accessibility)
        titleLineEdit->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        MarkAsDoneButton->setText(QCoreApplication::translate("Form", "Done", nullptr));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
