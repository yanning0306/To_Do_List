#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>

class Notification {
public:
    Notification(const QString &message);

    // 获取通知消息
    QString getMessage() const;

    // 显示通知
    void showNotification() const;

private:
    QString message;
};

#endif // NOTIFICATION_H
