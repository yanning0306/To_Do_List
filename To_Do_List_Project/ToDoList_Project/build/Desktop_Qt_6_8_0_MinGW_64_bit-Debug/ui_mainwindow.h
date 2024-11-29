/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TimeLabel;
    QLabel *DateLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *FilteButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QPushButton *ExitButton;
    QLabel *taskCntLabel;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QListWidget *TaskList;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *NewTaskButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SettingButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1400, 900);
        Form->setMinimumSize(QSize(1400, 900));
        Form->setMaximumSize(QSize(1400, 900));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 190, 1180, 627));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        TimeLabel = new QLabel(widget);
        TimeLabel->setObjectName("TimeLabel");

        horizontalLayout_2->addWidget(TimeLabel);

        DateLabel = new QLabel(widget);
        DateLabel->setObjectName("DateLabel");

        horizontalLayout_2->addWidget(DateLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        FilteButton = new QPushButton(widget);
        FilteButton->setObjectName("FilteButton");

        horizontalLayout_2->addWidget(FilteButton);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 294, 109));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 9, 79, 16));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ExitButton = new QPushButton(widget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setMinimumSize(QSize(120, 50));
        ExitButton->setMaximumSize(QSize(120, 50));

        verticalLayout->addWidget(ExitButton);

        taskCntLabel = new QLabel(widget);
        taskCntLabel->setObjectName("taskCntLabel");

        verticalLayout->addWidget(taskCntLabel);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(454, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        TaskList = new QListWidget(widget);
        TaskList->setObjectName("TaskList");

        gridLayout_2->addWidget(TaskList, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(454, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NewTaskButton = new QPushButton(widget);
        NewTaskButton->setObjectName("NewTaskButton");
        NewTaskButton->setMinimumSize(QSize(100, 50));
        NewTaskButton->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(NewTaskButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        SettingButton = new QPushButton(widget);
        SettingButton->setObjectName("SettingButton");
        SettingButton->setMinimumSize(QSize(100, 50));
        SettingButton->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(SettingButton);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        TimeLabel->setText(QCoreApplication::translate("Form", "Time", nullptr));
        DateLabel->setText(QCoreApplication::translate("Form", "Date", nullptr));
        FilteButton->setText(QCoreApplication::translate("Form", "sift", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form", "tags", nullptr));
        ExitButton->setText(QCoreApplication::translate("Form", "Exit", nullptr));
        taskCntLabel->setText(QCoreApplication::translate("Form", "Completed Today", nullptr));
        NewTaskButton->setText(QCoreApplication::translate("Form", "NewTask", nullptr));
        SettingButton->setText(QCoreApplication::translate("Form", "Setting", nullptr));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
