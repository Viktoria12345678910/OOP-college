#include "student.h"

Student::Student(){
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

QString Student::getId() const{
    return id;
}
void Student::setId(QString& id){
    this->id = id;
}
QString Student::getFirstName() const{
    return firstName;
}
void Student::setFirstName(){
    this->firstName = firstName;
}
QString Student::getLastName() const{
    return lastName;
}
void Student::setLastName(){
    this->lastName = lastName;
}
QString Student::getPaternalName() const{
    return paternalName;
}
void Student::setPaternalName(){
    this->paternalName = paternalName;
}
QString Student::getDate() const{
    return date;
}
void Student::setDate(){
    this->date = date;
}
QString Student::getAddres() const{
    return addres;
}
void Student::setAddres(){
    this->addres = addres;
}
QString Student::getPhoneNumber() const{
    return phoneNumber;
}
void Student::setPhoneNumber(){
    this->phoneNumber = phoneNumber;
}
QString Student::getFaculty() const{
    return faculty;
}
void Student::setFaculty(){
    this->faculty = faculty;
}
QString Student::getYear() const{
    return year;
}
void Student::setYear(){
    this->year = year;
}
QString Student::getGroup() const{
    return group;
}
void Student::setGroup(){
    this->group = group;
}
