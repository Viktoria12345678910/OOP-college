#ifndef STUDENT_H
#define STUDENT_H

#endif // STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//student class
    class Student{
            int id;
            string firstName;
            string lastName;
            string paternalName;
            int date;
            string addres;
            string phoneNumber;
            string faculty;
            int year;
            string group;

        public:
            Student(); //+
            Student(string firstName, string lastName, string paternalName, int age, string phoneNumber);
            void setFirstName(string firstName);
            void setLastName(string lastName);
            void setPaternalName(string paternalName);
            void setAge(int age);
            void setPhoneNumber(string phoneNumber);


            //визначення виводу
            friend ostream& operator<<(ostream&, Student& student){
                cout<<" Last Name: "<<student.lastName<<"\n First name: "<<student.firstName<<"\n Paternal name"<<student.paternalName<<"age: "<<student.age<<"phone number: "<<student.phoneNumber<<endl;
            return cout;
            };
    };

        Student::Student(){
            int temp;
            cout<<"Введіть прізвище: ";
            cin>>lastName;
            cout<<"Введіть ім'я: ";
            cin>>firstName;
            cout<<"Введіть побатькові: ";
            cin>>paternalName;
            cout<<"Введіть вік: ";
            cin>>age;
            cout<<"Введіть номер телефону: ";
            cin>>phoneNumber;

                    }

        Student::Student(string firstName, string lastName, string paternalName, int age, string phoneNumber){
            this->firstName = firstName;
            this->lastName = lastName;
            this->paternalName = paternalName;
            this->age = age;
            this->phoneNumber = phoneNumber;
        }

            void Student::setFirstName(string firstName){
                this->firstName = firstName;
            }
            void Student::setLastName(string lastName){
                this->lastName = lastName;
            }
            void Student::setPaternalName(string paternalName){
                this->paternalName = paternalName;
            }
            void Student::setAge(int age){
                this->age = age;
            }
            void Student::setPhoneNumber(string phoneNumber){
                this->phoneNumber;
            }
