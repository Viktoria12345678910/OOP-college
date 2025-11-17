#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H
#include <QSqlDatabase>
#include "dbmanager.h"


#define DATABASE_HOST_NAME              "BaydetskaViktoria"
#define DATABASE_FILE_NAME                   "Students.sqlite"

#define TABLE_STUDENTS                  "students"
#define TABLE_STUDENTS_ID               "id"
#define TABLE_STUDENTS_FIRSTNAME        "firstName"
#define TABLE_STUDENTS_LASTNAME         "lastName"
#define TABLE_STUDENTS_PATERNALNAME     "paternalName"
#define TABLE_STUDENTS_DATE             "date"
#define TABLE_STUDENTS_ADDRES           "addres"
#define TABLE_STUDENTS_PHONENUMBER      "phoneNumber"
#define TABLE_STUDENTS_FACULTY          "faculty"
#define TABLE_STUDENTS_YEAR             "year"
#define TABLE_STUDENTS_GROUP            "group"

class SqliteDBManager : public DBManager
{
    QSqlDatabase db;
    static SqliteDBManager* instance;
    SqliteDBManager();

    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
public:
    static SqliteDBManager* getInstance();
    void connectToDataBase() override;
    QSqlDatabase& getDB() override;
    bool insertIntoTable(const Student &student) override;
};

#endif // SQLITEDBMANAGER_H
