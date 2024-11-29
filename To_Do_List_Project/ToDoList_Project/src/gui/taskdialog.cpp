#include "ui_taskdialog.h"
#include "taskdialog.h"
#include <QMessageBox>

TaskDialog::TaskDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui_TaskDialog) {
    ui->setupUi(this);

    // 连接 OK 按钮点击信号
    connect(ui->okButton, &QPushButton::clicked, this, &TaskDialog::onOkButtonClicked);

    // 连接 Cancel 按钮点击信号
    connect(ui->cancelButton, &QPushButton::clicked, this, &TaskDialog::onCancelButtonClicked);

    // 连接 Mark As Done 按钮点击信号
    connect(ui->MarkAsDoneButton, &QPushButton::clicked, this, &TaskDialog::onMarkAsDoneButtonClicked);
    // 设置默认日期为今天
    ui->deadlineDateEdit->setDate(QDate::currentDate());
    // 设置优先级范围
    ui->prioritySpinBox->setRange(0, 10); // 假设优先级范围是 0 到 10
}

TaskDialog::~TaskDialog() {
    delete ui;
}

void TaskDialog::setTask( Task& task) {
    currentTask = task;

    // 更新界面中的字段
    ui->titleLineEdit->setText(task.getTitle());
    ui->deadlineDateEdit->setDate(task.getDeadline());
    ui->prioritySpinBox->setValue(task.getPriority());
    ui->tagLineEdit->setText(task.getTag());
    ui->notesTextEdit->setPlainText(task.getNotes());
}

Task TaskDialog::getTask() const {
    return currentTask;
}

void TaskDialog::onMarkAsDoneButtonClicked(){
    currentTask.markAsDone();
}

void TaskDialog::onOkButtonClicked() {
    // 获取用户输入的值
    QString title = ui->titleLineEdit->text();
    QDate deadline = ui->deadlineDateEdit->date();
    int priority = ui->prioritySpinBox->value();
    QString tag = ui->tagLineEdit->text();
    QString notes = ui->notesTextEdit->toPlainText();

    // 校验标题是否为空
    if (title.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "The task title cannot be empty.");
        return;
    }

    // 更新当前任务信息
    currentTask.setTitle(title);
    currentTask.setDeadline(deadline);
    currentTask.setPriority(priority);
    currentTask.setTag(tag);
    currentTask.setNotes(notes);

    accept(); // 关闭对话框并返回 QDialog::Accepted
}

void TaskDialog::onCancelButtonClicked() {
    reject(); // 关闭对话框并返回 QDialog::Rejected
}
