#include "task.h"

// 构造函数
Task::Task(int id, const QString &title, const QDate &deadline, int priority, const QString &tag, const QString &notes)
    : id(id), title(title), deadline(deadline), priority(priority), tag(tag), notes(notes) {}

Task::Task(const Task& other)
    : id(other.id),
    title(other.title),
    deadline(other.deadline),
    priority(other.priority),
    tag(other.tag),
    notes(other.notes),
    done(other.done) {}

Task& Task::operator=(const Task& other) {
    if (this != &other) { // 防止自赋值
        id = other.id;
        title = other.title;
        deadline = other.deadline;
        priority = other.priority;
        tag = other.tag;
        notes = other.notes;
        done = other.done;
    }
    return *this;
}

// Getters
int Task::getId() const {
    return id;
}

QString Task::getTitle() const {
    return title;
}

QDate Task::getDeadline() const {
    return deadline;
}

int Task::getPriority() const {
    return priority;
}

QString Task::getTag() const {
    return tag;
}

QString Task::getNotes() const {
    return notes;
}

// Setters
void Task::setTitle(const QString &title) {
    this->title = title;
}

void Task::setDeadline(const QDate &deadline) {
    this->deadline = deadline;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setTag(const QString &tag) {
    this->tag = tag;
}

void Task::setNotes(const QString &notes) {
    this->notes = notes;
}

void Task::markAsDone(){
    this->done=true;
}

void Task::setID(size_t id){
    this->id=id;
}

// 检查任务是否逾期
bool Task::isOverdue() const {
    return QDate::currentDate() > deadline;
}

bool Task::isValid() const {
    return (!isOverdue()) && (this->done==false);
}

// JSON 读取，恢复任务数据
void Task::read(const QJsonObject &json) {
    if (json.contains("id") && json["id"].isDouble())
        id = json["id"].toInt();

    if (json.contains("title") && json["title"].isString())
        title = json["title"].toString();

    if (json.contains("deadline") && json["deadline"].isString())
        deadline = QDate::fromString(json["deadline"].toString(), Qt::ISODate);

    if (json.contains("priority") && json["priority"].isDouble())
        priority = json["priority"].toInt();

    if (json.contains("tag") && json["tag"].isString())
        tag = json["tag"].toString();

    if (json.contains("notes") && json["notes"].isString())
        notes = json["notes"].toString();
    if(json.contains("done") && json["done"].isBool())
        done = json["done"].toBool();
}

// JSON 写入，保存任务数据
void Task::write(QJsonObject &json) const {
    json["id"] = id;
    json["title"] = title;
    json["deadline"] = deadline.toString(Qt::ISODate);
    json["priority"] = priority;
    json["tag"] = tag;
    json["notes"] = notes;
    json["done"] = done;
}
