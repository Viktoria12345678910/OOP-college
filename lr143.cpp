#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
private:
    string pib;
    int age;
    string phone;
    string birthDate;
    string university;
    
public:
  
    Person() {
        cout << "Введіть П.І.Б.: ";
        getline(cin, pib);
        
        cout << "Введіть вік: ";
        cin >> age;
        cin.ignore();
        
        cout << "Введіть номер телефону: ";
        getline(cin, phone);
        
        cout << "Введіть дату народження (ДД.ММ.РРРР): ";
        getline(cin, birthDate);
        
        cout << "Введіть місце навчання: ";
        getline(cin, university);
    }
   
    Person(bool empty) : age(0) {}
    
    friend ofstream& operator<<(ofstream& out, const Person& p) {
        out << p.pib << endl;
        out << p.age << endl;
        out << p.phone << endl;
        out << p.birthDate << endl;
        out << p.university << endl;
        return out;
    }
    
    friend ifstream& operator>>(ifstream& in, Person& p) {
        getline(in, p.pib);
        in >> p.age;
        in.ignore();
        getline(in, p.phone);
        getline(in, p.birthDate);
        getline(in, p.university);
        return in;
    }
 
    void display() const {
        cout << "П.І.Б.: " << pib << endl;
        cout << "Вік: " << age << endl;
        cout << "Номер телефону: " << phone << endl;
        cout << "Дата народження: " << birthDate << endl;
        cout << "Місце навчання: " << university << endl;
    }
};

// Завдання 4
void task4() {
    Person ME;
    
    ofstream outFile("person.txt");
    if (!outFile) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }
    
    outFile << ME;
    outFile.close();
    
    cout << "\nДані успішно записано у файл!" << endl;
}

// Завдання 5
void task5() {
    Person readPerson(true);
    
    ifstream inFile("person.txt");
    if (!inFile) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }
    
    inFile >> readPerson;
    inFile.close();
    
    cout << "\nДані зчитано з файлу:\n";
    readPerson.display();
}


int main() {
    cout << "=== Завдання 4: Запис об'єкта ===\n";
    task4();
    
    cout << "\n=== Завдання 5: Читання об'єкта ===\n";
    task5();
    
    return 0;
}

