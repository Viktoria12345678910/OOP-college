#ifndef MYSQLDBMANAGER_H
#define MYSQLDBMANAGER_H

#include "dbmanager.h"

#define DATABASE_HOST_NAME  "127.0.0.1"
#define DATABASE_PORT       3306
#define DATABASE_NAME       "baydetska_viktoria"
#define DATABASE_USER_NAME  "root"
#define DATABASE_PASSWORD   ""

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
class MySqlDBManager: public DBManager
{
    QSqlDatabase db;

    static MySqlDBManager* instance;
    MySqlDBManager();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
public:
    static MySqlDBManager* getInstance();
    void connectToDataBase() override;
    QSqlDatabase& getDB() override;
    bool insertIntoTable(const Student& student) override;
    ~MySqlDBManager();
};

#endif // MYSQLDBMANAGER_H
