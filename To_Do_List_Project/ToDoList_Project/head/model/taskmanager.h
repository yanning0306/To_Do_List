#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "task.h"
#include <vector>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>

// TaskManager 类，负责管理任务
class TaskManager {
public:
    // 构造函数
    TaskManager();

    // 添加任务
    void addTask(const Task &task);

    // 删除任务
    bool removeTask(int taskId);

    // 查找任务
    Task* findTask(int taskId);

    // 获取所有任务
    std::vector<Task> getAllTasks() const;

    //获取任务数量
    size_t getTasksCnt() const;

    // 获取逾期任务
    std::vector<Task> getOverdueTasks() const;

    // 根据优先级排序
    std::vector<Task> getTasksSortedByPriority() const;

    // 根据截止日期排序
    std::vector<Task> getTasksSortedByDeadline() const;

    //按照两者排序
    std::vector<Task> getTasksSorted() const;

    //在内部排序
    void setTasksSorted();

    // 读取任务数据（用于备份恢复）
    void read(const QJsonObject &json);

    // 保存任务数据（用于备份）
    void write(QJsonObject &json) const;

private:
    std::vector<Task> tasks; // 存储任务的容器
};

#endif // TASKMANAGER_H
