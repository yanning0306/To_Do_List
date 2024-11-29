#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>
#include <QJsonObject>

// Task 类，表示一个任务的基本信息，包括备注
class Task {
public:
    // 构造函数
    Task(int id, const QString &title, const QDate &deadline, int priority = 0, const QString &tag = "", const QString &notes = "");
    Task(){
        id=rand()%65536;
        title="";
        deadline=QDate::currentDate();
        priority=0;
        tag="";
        notes="";
        done=false;
    }
    Task(const Task& other);                    // 拷贝构造函数
    Task& operator=(const Task& other);         // 拷贝赋值运算符
    // 访问器 (Getters)
    int getId() const;
    QString getTitle() const;
    QDate getDeadline() const;
    int getPriority() const;
    QString getTag() const;
    QString getNotes() const;

    // 修改器 (Setters)
    void setTitle(const QString &title);
    void setDeadline(const QDate &deadline);
    void setPriority(int priority);
    void setTag(const QString &tag);
    void setNotes(const QString &notes);
    void markAsDone();
    void setID(size_t id);

    // 检查任务是否逾期
    bool isOverdue() const;
    bool isValid() const;

    // JSON 序列化，支持备份和恢复
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    int id;                 // 任务 ID
    QString title;          // 任务标题
    QDate deadline;         // 截止日期
    int priority;           // 优先级（0 表示最低）
    QString tag;            // 标签
    QString notes;          // 备注
    bool done;              // 已完成
};

#endif // TASK_H
