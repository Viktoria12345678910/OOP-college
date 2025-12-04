#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    ifstream inFile("myfile.txt");
    
    if (!inFile) {
        cout << "Помилка відкриття файлу!" << endl;
        return -1;
    }
    string fullName, phone, birthDate, school;
    int age;
    
    getline(inFile, fullName);
    inFile >> age;
    inFile.ignore(); 
    getline(inFile, phone);
    getline(inFile, birthDate);
    getline(inFile, school);
    
    inFile.close();
    
    cout << "Повне ім'я(прізвище, ім'я, по-батькові): " << fullName << endl;
    cout << "Вік: " << age << endl;
    cout << "Номер телефону: " << phone << endl;
    cout << "Дата народження: " << birthDate << endl;
    cout << "Місце навчання: " << school << endl;
    
    return 0;
}

