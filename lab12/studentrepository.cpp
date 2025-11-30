#include "studentrepository.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StudentRepository::StudentRepository()
{
}

bool StudentRepository::addStudent(const Student& student)
{
    QMessageBox::information(nullptr, "Debug 1", "Початок addStudent");

    QSqlQuery query;

    QMessageBox::information(nullptr, "Debug 2", "Query створено");

    query.prepare("INSERT INTO students (firstName, lastName, paternalName, date, "
                  "addres, phoneNumber, faculty, year, groupName) "
                  "VALUES (:FirstName, :LastName, :PaternalName, :Date, "
                  ":Addres, :PhoneNumber, :Faculty, :Year, :Group)");

    query.bindValue(":FirstName", student.getFirstName());
    query.bindValue(":LastName", student.getLastName());
    query.bindValue(":PaternalName", student.getPaternalName());
    query.bindValue(":Date", student.getDate());
    query.bindValue(":Addres", student.getAddres());
    query.bindValue(":PhoneNumber", student.getPhoneNumber());
    query.bindValue(":Faculty", student.getFaculty());
    query.bindValue(":Year", student.getYear());
    query.bindValue(":Group", student.getGroup());

    QMessageBox::information(nullptr, "Debug 4", "Перед exec");

    bool execResult = query.exec();

    QMessageBox::information(nullptr, "Debug 5",
            "Exec: " + QString(execResult ? "OK" : "FAIL") + "\n" +
            "Error: " + query.lastError().text());

        if (!execResult) {
            return false;
        }

        return true;
    // if (!query.exec()) {
        // qDebug() << "Помилка додавання студента:" << query.lastError().text();
        // return false;
        // QMessageBox::critical(nullptr, "SQL ERROR",
                    // "Error: " + query.lastError().text() + "\n\n" +
                    // "SQL: " );

    // }
    // QMessageBox::information(nullptr, "Success", "Rows affected: " + QString::number(query.numRowsAffected()));
    return true;
}

QList<Student> StudentRepository::getAllStudents()
{
    QList<Student> students;
    QSqlQuery query("SELECT * FROM students");

    while (query.next()) {
        Student student;
        student.setId(query.value("id").toString());
        student.setLastName(query.value("lastName").toString());
        student.setFirstName(query.value("firstName").toString());
        student.setPaternalName(query.value("paternalName").toString());
        student.setAddres(query.value("address").toString());
        student.setPhoneNumber(query.value("phoneNumber").toString());
        student.setDate(query.value("date").toString());
        student.setFaculty(query.value("faculty").toString());
        student.setYear(query.value("year").toString());
        student.setGroup(query.value("group").toString());
        students.append(student);
    }

    return students;
}

bool StudentRepository::deleteStudent(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM students WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Помилка видалення студента:" << query.lastError().text();
        return false;
    }
    return true;
}

bool StudentRepository::updateStudent(const Student& student)
{
    QSqlQuery query;
    query.prepare("UPDATE students SET id = :Id, firstName = :FirstName, lastName = :LastName, paternalName = :PaternalName, date = :Date"
                  "addres = :Addres, phoneNumber = :phoneNumber, faculty = :Faculty, year = :Year, \"group\" = :Group ");

    query.bindValue(":Id", student.getId());
    query.bindValue(":FirstName", student.getFirstName());
    query.bindValue(":LastName", student.getLastName());
    query.bindValue(":PaternalName", student.getPaternalName());
    query.bindValue(":Date", student.getDate());
    query.bindValue(":Addres", student.getAddres());
    query.bindValue(":PhoneNumber", student.getPhoneNumber());
    query.bindValue(":Faculty", student.getFaculty());
    query.bindValue(":Year", student.getYear());
    query.bindValue(":Group", student.getGroup());


    if (!query.exec()) {
        qDebug() << "Помилка оновлення пацієнта:" << query.lastError().text();
        return false;
    }
    return true;
}
