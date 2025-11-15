#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
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
