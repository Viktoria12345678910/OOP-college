#ifndef STUDENT_H
#define STUDENT_H

#endif // STUDENT_H
#include <iostream>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

//student class
    class Student{
            QString id;
            QString firstName;
            QString lastName;
            QString paternalName;
            QString date;
            QString addres;
            QString phoneNumber;
            QString faculty;
            QString year;
            QString group;

        public:
            Student(); //+
            Student(QString id, QString firstName, QString lastName, QString paternalName, QString date, QString addres, QString phoneNumber, QString year, QString group, QString faculty);
            void setId(QString id);
            void setFirstName(QString firstName);
            void setLastName(QString lastName);
            void setPaternalName(QString paternalName);
            void setDate(QString date);
            void setPhoneNumber(QString phoneNumber);
            void setAddres(QString addres);
            void setFaculty(QString faculty);
            void setYear(QString year);
            void setGroup(QString group);
            QString toString();
    };

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
                QString faculty){
            this->id = id;
            this->firstName = firstName;
            this->lastName = lastName;
            this->paternalName = paternalName;
            this->date = date;
            this->addres = addres;
            this->phoneNumber = phoneNumber;
            this->year = year;
            this->group = group;
            this->faculty = faculty;
        }

            void Student::setId(QString id){
                this->id = id;
            }
            void Student::setFirstName(QString firstName){
                this->firstName = firstName;
            }
            void Student::setLastName(QString lastName){
                this->lastName = lastName;
            }
            void Student::setPaternalName(QString paternalName){
                this->paternalName = paternalName;
            }
            void Student::setDate(QString date){
                this->date = date;
            }
            void Student::setPhoneNumber(QString phoneNumber){
                this->phoneNumber = phoneNumber;
            }
            void Student::setAddres(QString addres){
                this->addres = addres;
            }
            void Student::setFaculty(QString faculty){
                this->faculty =faculty;
            }
            void Student::setYear(QString year){
                this->year = year;
            }
            void Student::setGroup(QString group){
                this->group = group;
            }

            QString Student::toString(){
                QString studentInfo = "Nothing is here";
                studentInfo =" first name: "+firstName+" last name: "+lastName+" Paternal name: "+paternalName+" date of birth: "+date+" phone number: "+phoneNumber+" home address:"+addres+" faculty: "+faculty+" on year "+year+" group "+group+"\n";
                return studentInfo;
            }
