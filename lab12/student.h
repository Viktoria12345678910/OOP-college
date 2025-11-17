#ifndef STUDENT_H
#define STUDENT_H





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
            Student();
            Student(QString id, QString firstName, QString lastName, QString paternalName, QString date, QString addres, QString phoneNumber, QString year, QString group, QString faculty);
            QString toString();
            QString getId() const;
            void setId(QString& id);
            QString getFirstName() const;
            void setFirstName();
            QString getLastName() const;
            void setLastName();
            QString getPaternalName() const;
            void setPaternalName();
            QString getDate() const;
            void setDate();
            QString getAddres() const;
            void setAddres();
            QString getPhoneNumber() const;
            void setPhoneNumber();
            QString getFaculty() const;
            void setFaculty();
            QString getYear() const;
            void setYear();
            QString getGroup() const;
            void setGroup();

    };


#endif // STUDENT_H
