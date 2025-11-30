#ifndef STUDENT_H
#define STUDENT_H





#include <iostream>
#include <string>
// #include "mainwindow.h"
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
            QString getId() const;
            QString getFirstName() const;
            QString getLastName() const;
            QString getPaternalName() const;
            QString getDate() const;
            QString getAddres() const;
            QString getPhoneNumber() const;
            QString getFaculty() const;
            QString getYear() const;
            QString getGroup() const;

            // Сеттери
            void setId(const QString &id);
            void setFirstName(const QString &firstName);
            void setLastName(const QString &lastName);
            void setPaternalName(const QString &paternalName);
            void setDate(const QString &date);
            void setAddres(const QString &addres);
            void setPhoneNumber(const QString &phoneNumber);
            void setFaculty(const QString &faculty);
            void setYear(const QString &year);
            void setGroup(const QString &group);
            QString toString();
    };


#endif // STUDENT_H
