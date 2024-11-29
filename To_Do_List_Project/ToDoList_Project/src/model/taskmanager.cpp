// TaskManager.cpp
#include "taskmanager.h"

TaskManager::TaskManager() {}

void TaskManager::addTask(const Task &task) {
    tasks.push_back(task);
}

bool TaskManager::removeTask(int taskId) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == taskId) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

Task* TaskManager::findTask(int taskId) {
    for (auto &task : tasks) {
        if (task.getId() == taskId) {
            return &task;
        }
    }
    return nullptr;
}

std::vector<Task> TaskManager::getAllTasks() const {
    return tasks;
}

size_t TaskManager::getTasksCnt() const {
    return tasks.size();
}

std::vector<Task> TaskManager::getOverdueTasks() const {
    std::vector<Task> overdueTasks;
    for (const auto &task : tasks) {
        if (task.isOverdue()) {
            overdueTasks.push_back(task);
        }
    }
    return overdueTasks;
}

std::vector<Task> TaskManager::getTasksSortedByPriority() const {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task &a, const Task &b) {
        return a.getPriority() > b.getPriority();
    });
    return sortedTasks;
}

std::vector<Task> TaskManager::getTasksSortedByDeadline() const {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task &a, const Task &b) {
        return a.getDeadline() < b.getDeadline();
    });
    return sortedTasks;
}

std::vector<Task> TaskManager::getTasksSorted() const {
    std::vector<Task> sortedTasks = tasks;

    // 按 deadline 先排序，deadline 相同时按 priority 排序
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        if (a.getDeadline() == b.getDeadline()) {
            return a.getPriority() > b.getPriority(); // 优先级大的排在前面
        }
        return a.getDeadline() < b.getDeadline(); // 截止日期早的排在前面
    });

    return sortedTasks;
}

void TaskManager::setTasksSorted() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if (a.getDeadline() == b.getDeadline()) {
            return a.getPriority() > b.getPriority(); // 优先级大的排在前面
        }
        return a.getDeadline() < b.getDeadline(); // 截止日期早的排在前面
    });
}


void TaskManager::read(const QJsonObject &json) {
    tasks.clear();
    QJsonArray taskArray = json["tasks"].toArray();
    for (const QJsonValue &value : taskArray) {
        QJsonObject taskObj = value.toObject();
        Task task;
        task.read(taskObj);
        tasks.push_back(task);
    }
}

void TaskManager::write(QJsonObject &json) const {
    QJsonArray taskArray;
    for (const Task &task : tasks) {
        if(task.isValid()){
            QJsonObject taskObj;
            task.write(taskObj);
            taskArray.append(taskObj);
        }
    }
    json["tasks"] = taskArray;
}
