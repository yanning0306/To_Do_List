#ifndef USER_H
#define USER_H

#include <QString>
#include <QJsonObject>
#include "taskmanager.h"

// User 类，表示一个用户及其相关数据
class User {
public:
    // 构造函数
    User(const QString &username = "");

    // 加载用户数据，如果文件不存在则初始化新的用户数据
    bool loadOrCreateUserData();

    // 保存用户数据
    void saveUserData();

    // 获取用户名
    QString getUserName() const { return userName; }

    // 设置用户名
    void setUserName(const QString &username);

    // 获取用户密码
    QString getPassword() const { return password; }

    // 设置用户密码
    void setPassword(const QString &pass) { password = pass; }

    // 获取头像路径
    QString getProfilePath() const { return profilePath; }

    // 设置头像路径
    void setProfilePath(const QString &path) { profilePath = path; }

    // 获取主题图片路径
    QString getThemePicture() const { return themePicture; }

    // 设置主题图片路径
    void setThemePicture(const QString &path) { themePicture = path; }

    // 获取用户的任务管理器
    TaskManager* getTaskManager() { return &taskManager; }

    void parseTasks(const QJsonObject &taskObj);
    void saveTasks(QJsonObject &taskObj);

private:
    QString userName;        // 用户名
    QString password;        // 密码
    QString profilePath;     // 头像路径
    QString themePicture;    // 主题图片路径
    TaskManager taskManager; // 任务管理器，用于管理该用户的任务

    // 获取用户数据文件路径
    QString getUserFilePath() const;
};

#endif // USER_H
