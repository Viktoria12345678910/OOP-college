#include "sqlitedbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QDebug>

SqliteDBManager* SqliteDBManager::instance = nullptr;
SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

SqliteDBManager* SqliteDBManager::getInstance()
{
    if (instance == nullptr){
        instance = new SqliteDBManager();
    }
    return instance;
}

void SqliteDBManager::connectToDataBase() {
    if(QFile(DATABASE_FILE_NAME).exists()) {
        this->openDataBase();
    }
    else{
        this->restoreDataBase();
    }
    this->createTable();
}

QSqlDatabase& SqliteDBManager::getDB() {
    return db;
}

bool SqliteDBManager::restoreDataBase() {
    if(this->openDataBase()) {
        if(!this->createTable()){
            return false;
        }
        else{
            return true;
        }

    }else{
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

bool SqliteDBManager::openDataBase() {
    if (db.open()){
        return true;
    } else
        return false;
}

void SqliteDBManager::closeDataBase() {
    db.close();
}

bool SqliteDBManager::createTable() {
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXIST " TABLE_STUDENTS "("
                   TABLE_STUDENTS_ID                "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_FIRSTNAME         "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_LASTNAME          "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_PATERNALNAME      "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_DATE              "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_ADDRES            "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_PHONENUMBER       "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_FACULTY           "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_YEAR              "VARCHAR(225)   NOT NULL"
                   TABLE_STUDENTS_GROUP             "VARCHAR(225)   NOT NULL"
                   ")"
    )){
       qDebug() << "DataBase:error of create "<<TABLE_STUDENTS;
       qDebug() << query.lastError().text();
       qDebug() << query.lastQuery();
       return false;
    } else
        return true;
}

bool SqliteDBManager::insertIntoTable(const Student& student){
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE_STUDENTS " (" TABLE_STUDENTS_ID ", "
                  TABLE_STUDENTS_FIRSTNAME ", "
                  TABLE_STUDENTS_LASTNAME ", "
                  TABLE_STUDENTS_PATERNALNAME ", "
                  TABLE_STUDENTS_DATE ", "
                  TABLE_STUDENTS_ADDRES ", "
                  TABLE_STUDENTS_PHONENUMBER ", "
                  TABLE_STUDENTS_FACULTY ", "
                  TABLE_STUDENTS_YEAR ", "
                  TABLE_STUDENTS_GROUP " ) "
                  "VALUES (:Id, :FirstName, :LastName, :PaternalName, :Date, :Addres, :PhoneNumber, :Faculty, :Year, :Group )");
    query.bindValue(":Id", student.getId());
    query.bindValue(":FirstName", student.getFirstName());
    query.bindValue(":LastName", student.getLastName());
    query.bindValue(":Date", student.getDate());
    query.bindValue(":Addres", student.getAddres());
    query.bindValue(":PhoneNumber", student.getPhoneNumber());
    query.bindValue(":Faculty", student.getFaculty());
    query.bindValue(":Year", student.getYear());
    query.bindValue(":Group", student.getGroup());

    if(!query.exec()){
        qDebug() << "error insert into "<< TABLE_STUDENTS;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        return false;
    } else{
        db.commit();
        return true;
    }
}

