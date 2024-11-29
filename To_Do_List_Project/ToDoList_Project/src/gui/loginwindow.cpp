#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui_Login) {
    ui->setupUi(this);

    // 初始化登录按钮状态
    updateLoginButtonState();

    // 信号槽连接
    connect(ui->CloseButton, &QPushButton::clicked, this, &LoginWindow::onCloseButtonClicked);
    connect(ui->UsrNameEdit, &QLineEdit::textChanged, this, &LoginWindow::onUsrNameEdited);
    connect(ui->PassWordEdit, &QLineEdit::textChanged, this, &LoginWindow::updateLoginButtonState);
    connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &LoginWindow::updateLoginButtonState);
    connect(ui->LoginInButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    // 鼠标悬停效果
    ui->CloseButton->installEventFilter(this);
    ui->LoginInButton->installEventFilter(this);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::onCloseButtonClicked() {
    close(); // 直接关闭窗口
}

void LoginWindow::onUsrNameEdited(const QString &text) {
    // 更新头像或显示默认头像
    if (!text.isEmpty()) {
        ui->ProFileLabel->setText("Avatar for " + text); // 模拟加载用户头像
    } else {
        ui->ProFileLabel->setText("Default Avatar");
    }
}

void LoginWindow::onLoginButtonClicked() {
    QString username = ui->UsrNameEdit->text().trimmed();
    QString password = ui->PassWordEdit->text().trimmed();

    // 检查输入是否为空
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Username and password cannot be empty.");
        return;
    }

    // 文件路径
    QString userFilePath = QCoreApplication::applicationDirPath() + "/../resource/users.txt";

    // 如果勾选了注册选项
    if (ui->checkBox->isChecked()) {
        QFile file(userFilePath);

        // 打开文件以追加写入方式
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open user data file.");
            return;
        }

        QTextStream in(&file);
        bool userExists = false;

        // 检查用户名是否已存在
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty()) continue;

            QStringList credentials = line.split(":");
            if (credentials.size() == 2 && credentials[0] == username) {
                userExists = true;
                break;
            }
        }

        if (userExists) {
            QMessageBox::warning(this, "Registration Error", "Username already exists.");
        } else {
            // 将新用户写入文件
            QTextStream out(&file);
            out << username << ":" << password << "\n";
            QMessageBox::information(this, "Registration", "Registration successful!");
        }
        file.close();
    } else {
        // 登录验证逻辑
        QFile file(userFilePath);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open user data file.");
            return;
        }

        QTextStream in(&file);
        bool isValidUser = false;

        // 验证用户名和密码
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty()) continue;

            QStringList credentials = line.split(":");
            if (credentials.size() == 2 && credentials[0] == username && credentials[1] == password) {
                isValidUser = true;
                break;
            }
        }
        file.close();

        if (isValidUser) {
            QMessageBox::information(this, "Login", "Login successful!");
            emit loginSuccessfulWithUsername(username);  // 发射带用户名的信号
        } else {
            QMessageBox::warning(this, "Login Error", "Invalid username or password.");
        }
    }
}

void LoginWindow::updateLoginButtonState() {
    // 根据输入和复选框状态更新登录按钮
    bool canLogin = !ui->UsrNameEdit->text().isEmpty() &&
                    !ui->PassWordEdit->text().isEmpty() ;
    ui->LoginInButton->setEnabled(canLogin);

    // 设置登录按钮的样式
    QString color = canLogin ? "blue" : "gray";
    ui->LoginInButton->setStyleSheet("background-color: " + color + ";");
}

bool LoginWindow::eventFilter(QObject *watched, QEvent *event) {
    // 处理鼠标悬停事件
    if (watched == ui->CloseButton) {
        if (event->type() == QEvent::Enter) {
            ui->CloseButton->setStyleSheet("background-color: red;");
        } else if (event->type() == QEvent::Leave) {
            ui->CloseButton->setStyleSheet(""); // 恢复默认样式
        }
    }

    if (watched == ui->LoginInButton) {
        if (event->type() == QEvent::Enter) {
            if (ui->LoginInButton->isEnabled()) {
                ui->LoginInButton->setStyleSheet("background-color: lightblue;");
            }
        } else if (event->type() == QEvent::Leave) {
            updateLoginButtonState(); // 恢复登录按钮状态
        }
    }

    return QWidget::eventFilter(watched, event); // 默认处理其他事件
}

void initializeUserFile() {
    QString userFilePath = QCoreApplication::applicationDirPath() + "/../resource/users.txt";

    // 如果文件已存在，不执行初始化
    if (QFile::exists(userFilePath)) return;

    // 确保目录存在
    QDir dir("resource");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    // 创建文件并写入默认用户
    QFile file(userFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "user:pass\n"; // 默认用户
        file.close();
    }
}
