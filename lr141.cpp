#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("myfile.txt");
    
    if (!outFile) {
        cout << "Помилка відкриття файлу!" << endl;
        return -1;
    }
    string fullName, birthDate, school;
    int age;
    string phone;
    
    cout << "Введіть повне ім'я(прізвище, ім'я, по-батькові: ";
    getline(cin, fullName);
    
    cout << "Введіть вік: ";
    cin >> age;
    cin.ignore();
    cout << "Введіть номер телефону: ";
    getline(cin, phone);
  
    cout << "Введіть дату народження (ДД.МM.РРРР): ";
    getline(cin, birthDate);
    
    cout << "Введіть місце навчання: ";
    getline(cin, school);
    outFile << fullName << endl;
    outFile << age << endl;
    outFile << phone << endl;
    outFile << birthDate << endl;
    outFile << school << endl;
    
    outFile.close();
    cout << "Дані успішно записано!" << endl;
    
    return 0;
}

