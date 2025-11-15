#include <iostream>
#include <cstring>
using namespace std;

class Toy {
    char *ownerName; 
    int old; 
public:
    Toy();
    Toy(char * ownerName, int old);
    Toy(const Toy& );
    void setOwnerName(char * ownerName);
    char * getOwnerName();
    void setOld(int old);
    int getOld();
    void print() const;
    void input();
    ~Toy();
    friend istream& operator>>(istream&, Toy& toy){
        cout << "Enter name: ";
        cin >> toy.ownerName;
        cout << "Enter age: ";
        cin >> toy.old;
        return cin;
    };
    friend ostream& operator<<(ostream&, Toy& toy){
        cout <<"Owner name: "<<toy.ownerName<<" toy is for "<<toy.old<<" years old"<<endl;
        return cout;
    };
};

// Реалізація методів класу
    Toy::Toy(){
        old = 0;
        ownerName = new char[1];
        ownerName[0] = '\0';
        cout << "object created " << endl;
    }

    Toy::Toy(char * ownerName, int old){
        this->old = old;
        this->ownerName = new char[strlen(ownerName) + 1]; 
        strcpy(this->ownerName, ownerName);
        cout << "object created " << endl;
    }


    Toy::Toy(const Toy &toy){
        this->ownerName = new char[strlen(toy.ownerName) + 1];  
        strcpy(this->ownerName, toy.ownerName);  
        this->old = toy.old;                     
        cout << "object copied " << endl;
    }


    void Toy::setOwnerName(char * ownerName){
        delete[] this->ownerName;                           
        this->ownerName = new char[strlen(ownerName) + 1];  
        strcpy(this->ownerName, ownerName);                 
    }

    void Toy::setOld(int old){
        this->old = old;
    }

    void Toy::input(){
        char buffer[100];              
        cout << "Enter owner's name: ";
        cin.ignore();                  
        cin.getline(buffer, 100);      
        
        delete[] this->ownerName;                      
        this->ownerName = new char[strlen(buffer) + 1]; 
        strcpy(this->ownerName, buffer);               
        
        cout << "Enter age: ";
        cin >> this->old;         
    }

    char * Toy::getOwnerName(){
        return ownerName;
    }

    int Toy::getOld(){
        return old;
    }

    void Toy::print() const{   
        cout << "owner's name is " << ownerName << endl;
        cout << "toy is for " << old << "+ years old children " << endl;
    }

    Toy::~Toy(){
        delete[] ownerName;
        cout << "object destroyed" << endl;
    }

//main
 int main(){
    Toy objA;
    cin>>objA;
    cout<<objA;
    return 0;
 }
 //Done