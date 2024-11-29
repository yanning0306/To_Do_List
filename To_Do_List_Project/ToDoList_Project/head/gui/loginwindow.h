#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include "ui_loginwindow.h"

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui_Login *ui; // Ui_Login is generated from ui_loginwindow.h
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onCloseButtonClicked();
    void onUsrNameEdited(const QString &text); // When username is edited
    void onLoginButtonClicked();     // When Login button is clicked
    void updateLoginButtonState();   // Update LoginButton state based on input

signals:
    void loginSuccessful();  // Existing signal
    void loginSuccessfulWithUsername(const QString& username);  // New signal for passing username
};

void initializeUserFile();

#endif // LOGINWINDOW_H
