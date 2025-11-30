#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"

Student::Student()
{
}

Student::Student(
        QString id,
        QString firstName,
        QString lastName,
        QString paternalName,
        QString date,
        QString addres,
        QString phoneNumber,
        QString year,
        QString group,
        QString faculty) :id(id), firstName(firstName), lastName(lastName), paternalName(paternalName), date(date), addres(addres), phoneNumber(phoneNumber), year(year),
group(group),
faculty(faculty){

}


QString Student::toString(){
    QString studentInfo = "Nothing is here";
    studentInfo ="First name: "+firstName+"\nLast name: "+lastName+"\nPaternal name: "+paternalName+"\nDate of birth: "+date+"\nPhone number: "+phoneNumber+"\nHome address:"+addres+"\nFaculty: "+faculty+" on year "+year+"\nGroup "+group+"\n";
    return studentInfo;
}
// Геттери
QString Student::getId() const { return id; }
QString Student::getFirstName() const { return firstName; }
QString Student::getLastName() const { return lastName; }
QString Student::getPaternalName() const { return paternalName; }
QString Student::getDate() const { return date; }
QString Student::getAddres() const { return addres; }
QString Student::getPhoneNumber() const { return phoneNumber; }
QString Student::getFaculty() const { return faculty; }
QString Student::getYear() const { return year; }
QString Student::getGroup() const { return group; }

// Сеттери
void Student::setId(const QString &id) { this->id = id; }
void Student::setFirstName(const QString &firstName) { this->firstName = firstName; }
void Student::setLastName(const QString &lastName) { this->lastName = lastName; }
void Student::setPaternalName(const QString &paternalName) { this->paternalName = paternalName; }
void Student::setDate(const QString &date) { this->date = date; }
void Student::setAddres(const QString &addres) { this->addres = addres; }
void Student::setPhoneNumber(const QString &phoneNumber) { this->phoneNumber = phoneNumber; }
void Student::setFaculty(const QString &faculty) { this->faculty = faculty; }
void Student::setYear(const QString &year) { this->year = year; }
void Student::setGroup(const QString &group) { this->group = group; }
