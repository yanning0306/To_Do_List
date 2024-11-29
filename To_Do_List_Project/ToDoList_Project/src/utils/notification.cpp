#include "notification.h"
#include <QMessageBox>

Notification::Notification(const QString &message) : message(message) {}

QString Notification::getMessage() const {
    return message;
}

void Notification::showNotification() const {
    QMessageBox::information(nullptr, "Notification", message);
}
