#include "User.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QDir>

constexpr auto USER_FILE_EXTENSION = ".json"; // 定义文件后缀

User::User(const QString &username)
    : userName(username){
    // 使用 QCoreApplication::applicationDirPath() 获取应用程序的路径，并根据该路径设置资源文件路径
    QString appDirPath = QCoreApplication::applicationDirPath();
    profilePath = appDirPath + "/../resource/profile/default_profile.png";  // 假设资源文件在应用目录的上一级
    themePicture = appDirPath + "/../resource/theme/default_theme.png";
}

void User::setUserName(const QString &username) {
    userName = username;
    // 动态更新存储路径
    profilePath = getUserFilePath();
}

QString User::getUserFilePath() const {
    // 构造用户文件路径：<程序路径>/../resource/users/<用户名>.json
    QString userDir = QCoreApplication::applicationDirPath() + "/../resource/users/";
    return userDir + userName + USER_FILE_EXTENSION;
}

bool User::loadOrCreateUserData() {
    QString filePath = getUserFilePath();
    QFile file(filePath);

    // 如果文件不存在，则初始化新的用户数据
    if (!file.exists()) {
        saveUserData();
        return true;
    }

    // 加载用户数据
    if (!file.open(QIODevice::ReadOnly)) return false;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) return false;

    QJsonObject rootObj = doc.object();
    password = rootObj["password"].toString();     // 加载密码
    profilePath = rootObj["profilePath"].toString();
    themePicture = rootObj["themePicture"].toString();

    QJsonObject taskObj = rootObj["tasks"].toObject(); // 读取任务对象
    parseTasks(taskObj);

    return true;
}

void User::saveUserData() {
    QString filePath = getUserFilePath();
    QFile file(filePath);

    // 确保用户目录存在
    QDir dir(QFileInfo(filePath).absolutePath());
    if (!dir.exists() && !dir.mkpath(".")) {
        qWarning() << "Failed to create user directory for saving:" << dir.path();
        return;
    }

    // 打开文件（不存在则创建，存在则清空内容）
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "Failed to open user file for writing:" << filePath;
        return;
    }

    // 构造 JSON 对象并写入文件
    QJsonObject rootObj;
    rootObj["password"] = password;  // 保存密码
    rootObj["profilePath"] = profilePath;
    rootObj["themePicture"] = themePicture;

    QJsonObject taskObj;
    saveTasks(taskObj);  // 保存任务数据
    rootObj["tasks"] = taskObj;

    QJsonDocument doc(rootObj);
    file.write(doc.toJson());
    qDebug() << "User data saved successfully to:" << filePath;
}


void User::parseTasks(const QJsonObject &taskObj) {
    taskManager.read(taskObj); // 传递 QJsonObject 进行解析
}

void User::saveTasks(QJsonObject &taskObj) {
    taskManager.write(taskObj); // 传递 QJsonObject 来保存任务
}
