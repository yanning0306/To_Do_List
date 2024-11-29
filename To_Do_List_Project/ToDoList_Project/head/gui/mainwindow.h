#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QScrollArea>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include "taskdialog.h"  // 引入 TaskDialog 类
#include "user.h"        // 引入 User 类
#include "taskmanager.h" // 引入 TaskManager 类
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(User *user, QWidget *parent = nullptr);  // 需要传入 User 对象
    ~MainWindow();
    void setUser(User *user);

private slots:
    void onNewTaskButtonClicked();    // 新建任务按钮点击
    void onSettingButtonClicked();    // 设置按钮点击
    void onFilterButtonClicked();     // 筛选按钮点击
    void onTaskItemClicked(QListWidgetItem *item);  // 任务项点击
    void onExitButtonClicked();         //退出程序

signals:
    void exit();

private:
    Ui_MainWindow *ui;
    User *currentUser;  // 当前用户
    TaskManager *taskManager;  // 当前用户的任务管理器

    void updateDateTime();            // 更新日期和时间
    void updateTaskCnt();             // 更新任务数量
    void updateTaskList();            // 更新任务列表显示
};


#endif // MAINWINDOW_H
