#include "sqlitedbmanager.h"
#include "mainwindow.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>

SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

// Метод для отримання екземпляру даного класу (патерн Singleton)
SqliteDBManager* SqliteDBManager::getInstance() {
    if (instance == nullptr) {
        instance = new SqliteDBManager();
    }
    return instance;
}

// Метод для підключення до бази даних
void SqliteDBManager::connectToDataBase() {
    /* Перед підключенням до бази даних виконуємо перевірку на її існування.
     * В залежності від результату виконуємо відкриття бази даних або її відновлення
     * */
    if (QFile(DATABASE_FILE_NAME).exists()) {
        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

// Метод для отримання обробника підключення до БД
QSqlDatabase& SqliteDBManager::getDB() {
    return db;
}

// Метод відновлення бази даних
bool SqliteDBManager::restoreDataBase() {
    if (this->openDataBase()) {
        if (!this->createTable()) {
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

// Метод для відкриття бази даних
bool SqliteDBManager::openDataBase() {
    /* База даних відкривається по вказаному шляху
     * та імені бази даних, якщо вона існує
     * */
    if (db.open()) {
        return true;
    } else
        return false;
}

// Метод закриття бази даних
void SqliteDBManager::closeDataBase() {
    db.close();
}

// Метод для створення таблиці в базі даних
bool SqliteDBManager::createTable() {
    /* В даному випадку використовується фурмування сирого SQL-запиту
     * з наступним його виконанням.
     * */
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS" TABLE_STUDENTS " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_STUDENTS_ID               " VARCHAR(50)     NOT NULL,"
                    TABLE_STUDENTS_FIRST_NAME       " VARCHAR(100)    NOT NULL,"
                    TABLE_STUDENTS_LAST_NAME        " VARCHAR(100)    NOT NULL,"
                    TABLE_STUDENTS_PATERNAL_NAME    " VARCHAR(100)    NOT NULL,"
                    TABLE_STUDENTS_DATE             " DATE            NOT NULL,"
                    TABLE_STUDENTS_ADDRESS          " VARCHAR(255)    NOT NULL,"
                    TABLE_STUDENTS_PHONE_NUMBER     " VARCHAR(20)     NOT NULL,"
                    TABLE_STUDENTS_FACULTY          " VARCHAR(100)    NOT NULL,"
                    TABLE_STUDENTS_YEAR             " VARCHAR(10)     NOT NULL,"
                    TABLE_STUDENTS_GROUP            " VARCHAR(50)     NOT NULL"
                    " )"
    )) {
        qDebug() << "DataBase: error of create " << TABLE_STUDENTS;

        // QMessageBox::information(this, "Успіх", error);
        return false;
    } else
        return true;
}

// Метод для вставки записів у таблицю messages
bool SqliteDBManager::inserIntoTable(const Student& student) {
    // SQL-запит формується із об'єкта класу Message
    QSqlQuery query;
    /*
     * Спочатку SQL-запит формується з ключами, які потім зв'язуються методом bindValue
     * для підставки даних із об'єкта класу Message
     * */
    query.prepare("INSERT INTO " TABLE_STUDENTS " ( "
                  TABLE_STUDENTS_ID ", "
                  TABLE_STUDENTS_FIRST_NAME ", "
                  TABLE_STUDENTS_LAST_NAME ", "
                  TABLE_STUDENTS_PATERNAL_NAME ", "
                  TABLE_STUDENTS_DATE ", "
                  TABLE_STUDENTS_ADDRESS ", "
                  TABLE_STUDENTS_PHONE_NUMBER ", "
                  TABLE_STUDENTS_FACULTY ", "
                  TABLE_STUDENTS_YEAR ", "
                  TABLE_STUDENTS_GROUP " ) "
                  "VALUES (?,?,?,?,?,?,?,?,?,?)");
// :FirstName, :LastName, :PaternalName, :Date, :Address, :PhoneNumber, :Faculty, :Year, :Group
    query.addBindValue(student.getId());
    query.addBindValue(student.getFirstName());
    query.addBindValue(student.getLastName());
    query.addBindValue(student.getPaternalName());
    query.addBindValue(student.getDate());
    query.addBindValue(student.getAddres());
    query.addBindValue(student.getPhoneNumber());
    query.addBindValue(student.getFaculty());
    query.addBindValue(student.getYear());
    query.addBindValue(student.getGroup());
    // Після чого виконується запит методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_STUDENTS;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();
        QString error = query.lastError().text();
        QMessageBox msgBox;
        msgBox.setText(error);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        // QMessageBox::information(this, error);
        return false;
    } else
        return true;
}

// Метод для отримання повідомлення по id
Student SqliteDBManager::findStudentById(int id) {
    QSqlQuery query(this->db);
    Student student;
    // Спочатку формується SQL-запит з ключем (заповнювачем) 'id', який потім замінюється значенням методом bindValue
    query.prepare("SELECT * FROM " TABLE_STUDENTS " WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        student.setId(query.value(TABLE_STUDENTS_ID).toString());
        student.setFirstName(query.value(TABLE_STUDENTS_FIRST_NAME).toString());
        student.setLastName(query.value(TABLE_STUDENTS_LAST_NAME).toString());
        student.setPaternalName(query.value(TABLE_STUDENTS_PATERNAL_NAME).toString());
        student.setDate(query.value(TABLE_STUDENTS_DATE).toString());
        student.setAddres(query.value(TABLE_STUDENTS_ADDRESS).toString());
        student.setPhoneNumber(query.value(TABLE_STUDENTS_PHONE_NUMBER).toString());
        student.setFaculty(query.value(TABLE_STUDENTS_FACULTY).toString());
        student.setYear(query.value(TABLE_STUDENTS_YEAR).toString());
        student.setGroup(query.value(TABLE_STUDENTS_GROUP).toString());
    }
    return student;
}
