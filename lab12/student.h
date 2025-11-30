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
            Student(QString id, QString firstName, QString lastName, QString paternalName, QString date, QString addres, QString phoneNumber, QString year, QString group, QString faculty);
            QString toString();
    };


#endif // STUDENT_H
