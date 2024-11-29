#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include "task.h"

#include "ui_taskdialog.h"

class TaskDialog : public QDialog {
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();

    // 设置和获取任务
    void setTask(Task &task);
    Task getTask() const;

private slots:
    void onOkButtonClicked();
    void onCancelButtonClicked();
    void onMarkAsDoneButtonClicked();

signals:
    void editTaskSuccess();

private:
    Ui_TaskDialog *ui;
    Task currentTask; // 当前任务
};

#endif // TASKDIALOG_H
