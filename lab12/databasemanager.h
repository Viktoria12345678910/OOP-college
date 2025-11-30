#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
private:
    static DatabaseManager* instance;
    QSqlDatabase database;


    DatabaseManager();


    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

public:
    static DatabaseManager* getInstance();
    bool openDatabase();
    void closeDatabase();
    QSqlDatabase getDatabase();
    bool initializeDatabase();

    ~DatabaseManager();
};

#endif // DATABASEMANAGER_H
