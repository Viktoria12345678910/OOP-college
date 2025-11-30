#include "groupmanagerdialog.h"
#include "../database.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>

GroupManagerDialog::GroupManagerDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    refreshGroupList();
}

void GroupManagerDialog::setupUI()
{
    setWindowTitle("Управління групами");
    setMinimumSize(400, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    m_groupsList = new QListWidget();
    mainLayout->addWidget(m_groupsList);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    m_createButton = new QPushButton("Створити групу");
    connect(m_createButton, &QPushButton::clicked, this, &GroupManagerDialog::onCreateGroup);
    buttonLayout->addWidget(m_createButton);

    m_deleteButton = new QPushButton("Видалити групу");
    connect(m_deleteButton, &QPushButton::clicked, this, &GroupManagerDialog::onDeleteGroup);
    buttonLayout->addWidget(m_deleteButton);

    m_manageMembersButton = new QPushButton("Керувати учасниками");
    connect(m_manageMembersButton, &QPushButton::clicked, this, &GroupManagerDialog::onManageMembers);
    buttonLayout->addWidget(m_manageMembersButton);

    mainLayout->addLayout(buttonLayout);

    QPushButton *closeButton = new QPushButton("Закрити");
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(closeButton);
}

void GroupManagerDialog::onCreateGroup()
{
    bool ok;
    QString groupName = QInputDialog::getText(
        this, "Нова група", "Назва групи:", QLineEdit::Normal, "", &ok);

    if (ok && !groupName.isEmpty()) {
        int groupId = Database::instance().createGroup(groupName);
        if (groupId > 0) {
            QMessageBox::information(this, "Успіх", "Групу створено!");
            refreshGroupList();
        } else {
            QMessageBox::critical(this, "Помилка", "Не вдалось створити групу!");
        }
    }
}

void GroupManagerDialog::onDeleteGroup()
{
    QListWidgetItem *item = m_groupsList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Попередження", "Оберіть групу для видалення!");
        return;
    }

    int groupId = item->data(Qt::UserRole).toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Підтвердження", "Ви впевнені, що хочете видалити цю групу?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM groups WHERE group_id = ?");
        query.addBindValue(groupId);

        if (query.exec()) {
            QMessageBox::information(this, "Успіх", "Групу видалено!");
            refreshGroupList();
        } else {
            QMessageBox::critical(this, "Помилка", "Не вдалось видалити групу!");
        }
    }
}

void GroupManagerDialog::onManageMembers()
{
    QListWidgetItem *item = m_groupsList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Попередження", "Оберіть групу!");
        return;
    }

    // Тут можна додати діалог для управління учасниками групи
    QMessageBox::information(this, "Інформація",
                           "Функціонал управління учасниками буде реалізовано в майбутньому");
}

void GroupManagerDialog::refreshGroupList()
{
    m_groupsList->clear();

    QSqlQuery query("SELECT group_id, group_name FROM groups");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();

        QListWidgetItem *item = new QListWidgetItem(name);
        item->setData(Qt::UserRole, id);
        m_groupsList->addItem(item);
    }
}
