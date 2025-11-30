#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("test.db");
}

DatabaseManager* DatabaseManager::getInstance()
{
    if (instance == nullptr) {
        instance = new DatabaseManager();
    }
    return instance;
}

bool DatabaseManager::openDatabase()
{
    if (!database.open()) {
        qDebug() << "Помилка відкриття БД:" << database.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::closeDatabase()
{
    if (database.isOpen()) {
        database.close();
    }
}

QSqlDatabase DatabaseManager::getDatabase()
{
    return database;
}

bool DatabaseManager::initializeDatabase()
{
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS students");

    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "firstName TEXT NOT NULL, "
        "lastName TEXT NOT NULL, "
        "paternalName TEXT NOT NULL, "
        "date TEXT NOT NULL, "
        "addres TEXT NOT NULL, "
        "phoneNumber TEXT NOT NULL, "
        "faculty TEXT NOT NULL, "
        "year TEXT NOT NULL, "
        "groupName TEXT NOT NULL)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Помилка створення таблиці:" << query.lastError().text();
        return false;
    }
    return true;
}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}
