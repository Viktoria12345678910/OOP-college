#ifndef MYSQL_DB_MANAGER_H
#define MYSQL_DB_MANAGER_H

#include "dbmanager.h"

/* Директиви імен таблиці, полів таблиці і бази даних */
#define DATABASE_HOST_NAME  "127.0.0.1"
#define DATABASE_PORT       3306
#define DATABASE_NAME       "db_manager_example"
#define DATABASE_USER_NAME  "root"
#define DATABASE_PASSWORD   ""

#define TABLE_STUDENTS                   "student"
#define TABLE_STUDENTS_ID                "id"
#define TABLE_STUDENTS_FIRST_NAME        "firstName"
#define TABLE_STUDENTS_LAST_NAME         "lastName"
#define TABLE_STUDENTS_PATERNAL_NAME     "paternalName"
#define TABLE_STUDENTS_DATE              "date"
#define TABLE_STUDENTS_ADDRESS           "addres"
#define TABLE_STUDENTS_PHONE_NUMBER      "phoneNumber"
#define TABLE_STUDENTS_FACULTY           "faculty"
#define TABLE_STUDENTS_YEAR              "year"
#define TABLE_STUDENTS_GROUP             "group"

class MySqlDBManager : public DBManager {

public:
    // Метод для отримання екземпляру даного класу (патерн Singleton)
    static MySqlDBManager* getInstance();

    // Метод для підключення до бази даних
    void connectToDataBase() override;

    // Метод для отримання обробника (хендлера) підключення до БД
    QSqlDatabase& getDB() override;

    // Метод для вставки записів у таблицю
    bool inserIntoTable(const Student& student) override;

    // Метод для отримання повідомлення по id
    Student findStudentById(int id) override;

    ~MySqlDBManager();

private:
    // Обробник підключення до БД, через який буде виконуватись робота із БД
    QSqlDatabase db;

    static MySqlDBManager* instance;

    // Приватний конструктор
    MySqlDBManager();

    // Внутрішні методи для роботи з базою даних
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};

#endif // MYSQL_DB_MANAGER_H
