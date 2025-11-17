#include "mysqldbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QDebug>

MySqlDBManager* MySqlDBManager::instance = nullptr;

MySqlDBManager::MySqlDBManager()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(DATABASE_HOST_NAME);
    db.setPort(DATABASE_PORT);
    db.setDatabaseName(DATABASE_NAME);
    db.setUserName(DATABASE_USER_NAME);
    db.setPassword(DATABASE_PASSWORD);
}

MySqlDBManager* MySqlDBManager::getInstance() {
    if (instance == nullptr){
        instance = new MySqlDBManager();
    }
    return instance;
}

void MySqlDBManager::connectToDataBase() {
    if (db.isOpen()){
        return;
    }
    if(!db.open()){
        qDebug() << "Не вдалось відкрити базу даних";
    }
    this->createTable();
}

QSqlDatabase& MySqlDBManager::getDB() {
    return db;
}

void MySqlDBManager::closeDataBase(){
    if(db.isOpen()){
        db.close();
    }
}

bool MySqlDBManager::createTable() {
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

bool MySqlDBManager::insertIntoTable(const Student& student){
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
    } else
        return true;
}

MySqlDBManager::~MySqlDBManager() {
    this -> closeDataBase();
}
