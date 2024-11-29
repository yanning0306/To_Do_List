QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Include path for header files in 'head' directory
INCLUDEPATH += $$PWD/head/gui
INCLUDEPATH += $$PWD/head/model
INCLUDEPATH += $$PWD/head/utils
# 源文件
SOURCES += \
    src/gui/loginwindow.cpp \
    src/main.cpp \
    src/gui/mainwindow.cpp \
    src/gui/taskdialog.cpp \
    src/model/task.cpp \
    src/model/taskmanager.cpp \
    src/model/user.cpp \
    src/utils/notification.cpp

# 头文件
HEADERS += \
    head/gui/loginwindow.h \
    head/gui/mainwindow.h \
    head/gui/taskdialog.h \
    head/model/task.h \
    head/model/taskmanager.h \
    head/model/user.h \
    head/utils/notification.h

# UI 文件
FORMS += \
    forms/loginwindow.ui \
    forms/taskdialog.ui \
    forms/mainwindow.ui

# 资源文件
RESOURCES += \
    #resources/icons/icons.qrc \
    #resources/styles/styles.qrc

# 默认部署路径
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
