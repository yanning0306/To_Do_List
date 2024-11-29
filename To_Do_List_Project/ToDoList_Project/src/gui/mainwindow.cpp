#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QMessageBox>
#include <QListWidgetItem>

MainWindow::MainWindow(User *user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui_MainWindow), currentUser(user)
{
    ui->setupUi(this);

    // 初始化 TaskManager
    taskManager = currentUser->getTaskManager();

    // 连接信号与槽
    connect(ui->NewTaskButton, &QPushButton::clicked, this, &MainWindow::onNewTaskButtonClicked);
    connect(ui->SettingButton, &QPushButton::clicked, this, &MainWindow::onSettingButtonClicked);
    connect(ui->FilteButton, &QPushButton::clicked, this, &MainWindow::onFilterButtonClicked);
    connect(ui->TaskList, &QListWidget::itemClicked, this, &MainWindow::onTaskItemClicked);
    connect(ui->ExitButton, &QPushButton::clicked, this, &MainWindow::onExitButtonClicked);

    // 初始化日期和时间显示
    // updateDateTime();
    // updateTaskCnt();
    // updateTaskList();  // 更新任务列表
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(User* user){
    currentUser = user;
    taskManager = currentUser->getTaskManager();
    updateDateTime();
    updateTaskCnt();
    updateTaskList();  // 更新任务列表
}

void MainWindow::onNewTaskButtonClicked()
{
    // 新建任务时弹出 TaskDialog
    TaskDialog *taskDialog = new TaskDialog(this);
    Task task;
    taskDialog->setTask(task);  // 传入一个空任务以便创建
    if (taskDialog->exec() == QDialog::Accepted) {
        Task newTask = taskDialog->getTask();  // 获取用户输入的新任务
        taskManager->addTask(newTask);  // 将新任务添加到任务管理器中
        updateTaskList();  // 更新任务列表
    }
    delete taskDialog;  // 确保关闭时删除 TaskDialog
}

void MainWindow::onSettingButtonClicked()
{
    // 点击设置按钮进入设置界面
    // 假设 SettingsDialog 是您的设置界面
    // SettingsDialog *settingsDialog = new SettingsDialog(this);
    // settingsDialog->exec();
}

void MainWindow::onFilterButtonClicked()
{
    // 点击筛选按钮后显示筛选项（假设您已经有了相关控件）
    ui->scrollArea->setVisible(!ui->scrollArea->isVisible());  // 显示或隐藏筛选项
}

void MainWindow::onTaskItemClicked(QListWidgetItem *item)
{
    // 点击任务项时弹出 TaskDialog 以编辑该任务
    Task task = item->data(Qt::UserRole).value<Task>();  // 获取与任务项关联的任务对象
    TaskDialog *taskDialog = new TaskDialog(this);
    taskDialog->setTask(task);  // 设置当前任务
    if (taskDialog->exec() == QDialog::Accepted) {
        task = taskDialog->getTask();  // 获取修改后的任务
        taskManager->removeTask(task.getId());  // 删除原任务
        taskManager->addTask(task);  // 添加更新后的任务
        updateTaskList();  // 更新任务列表
    }
    delete taskDialog;  // 确保关闭时删除 TaskDialog
}

void MainWindow::updateDateTime()
{
    // 更新日期和时间标签
    QDateTime current = QDateTime::currentDateTime();
    ui->DateLabel->setText(current.toString("yyyy-MM-dd"));
    ui->TimeLabel->setText(current.toString("HH:mm:ss"));
}

void MainWindow::updateTaskCnt()
{
    // 更新当天完成的任务数量标签
    // 获取任务列表中的已完成任务数量
    int taskCount = 0;  // 假设已完成任务会有一个标志
    for (const Task &task : taskManager->getAllTasks()) {
        if (task.isOverdue()) {  // 逾期任务算作完成任务
            taskCount++;
        }
    }
    ui->taskCntLabel->setText(QString("Tasks Completed Today: %1").arg(taskCount));
}

void MainWindow::updateTaskList()
{
    // 更新任务列表显示
    ui->TaskList->clear();  // 清空现有任务
    taskManager->setTasksSorted();
    for (const Task &task : taskManager->getAllTasks()) {
        QListWidgetItem *item = new QListWidgetItem(task.getTitle());
        item->setData(Qt::UserRole, QVariant::fromValue(task));  // 将任务与列表项关联
        ui->TaskList->addItem(item);
    }
}
void MainWindow::onExitButtonClicked()
{
    emit exit();
}
