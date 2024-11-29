#include <QApplication>
#include <QMessageBox>
#include "LoginWindow.h"
#include "MainWindow.h"
#include "User.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建登录窗口
    LoginWindow loginWindow;
    User user(""); // 初始化没有用户名的用户对象
    MainWindow mainwindow(&user);

    // 连接登录成功信号
    QObject::connect(&loginWindow, &LoginWindow::loginSuccessfulWithUsername, [&](const QString& username) {
        // 登录成功，关闭登录窗口
        loginWindow.close();

        // 创建用户对象
        user.setUserName(username);

        // 加载用户数据
        if (!user.loadOrCreateUserData()) {
            QMessageBox::critical(nullptr, "Error", "Failed to load or create user data.");
            return;
        }

        // 设置主窗口的用户数据
        mainwindow.setUser(&user);
        mainwindow.show();
    });

    // 连接退出信号
    QObject::connect(&mainwindow, &MainWindow::exit, [&]() {
        // 退出应用程序
        user.saveUserData();
        a.quit();
    });

    // 显示登录窗口
    loginWindow.show();

    // 运行应用
    return a.exec();
}
