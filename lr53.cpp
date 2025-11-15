#include <iostream>
#include <cstring>
using namespace std;
#define n 5
//базовий клас
    class Toy {
        char *ownerName; // власник
        int old; // для якого віку іграшка
    public:
        Toy();
        Toy(char * ownerName, int old);
        Toy(const Toy& );
        void setOwnerName(char * ownerName);
        char * getOwnerName();
        void setOld(int old);
        int getOld();
        virtual void print() const;
        virtual void input();
        ~Toy();
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
// EducationToy
    class EducationToy:public Toy {
        string subject; 
        int complexityLevel;
    public:
        EducationToy(); //+
        EducationToy(string subject, int complexityLevel); //+
        EducationToy(const EducationToy &toy);//+
        void input();//+
        void print() const;//+
        void setSubject(string subject);//+
        void setComplexityLevel(int complexityLevel);//+
        string getSubject();//+
        int getComplexityLevel();//+
        ~EducationToy();
        
    };
    
    EducationToy::EducationToy(){
        subject = "";
        complexityLevel = 0;
        cout << "Object created";
    }

    EducationToy::EducationToy(string subject, int complexityLevel){
        this->subject = subject;
        this->complexityLevel = complexityLevel;
    }

    EducationToy::EducationToy(const EducationToy &toy){
        this->subject = toy.subject;    
        this->complexityLevel = toy.complexityLevel;                     
    }

    void EducationToy::input(){
        Toy::input();
        cout<<"please enter subject ";
        cin.ignore();
        getline(cin, subject);
        cout<<"please enter complexity level ";
        cin >> complexityLevel;
    }

    void EducationToy::print() const{
        Toy::print();
        cout << "this toy is for " << subject << endl;
        cout << "It has complexity level of " << complexityLevel << endl;
    }

    void EducationToy::setSubject(string subject){
        this->subject = subject;
    }

    void EducationToy::setComplexityLevel(int complexityLevel){
        this->complexityLevel = complexityLevel;
    }

    int EducationToy::getComplexityLevel(){
        return complexityLevel;
    }

    string EducationToy::getSubject(){
        return subject;
    }

    EducationToy::~EducationToy(){
        cout << "Object destroyed";
    }
//BoardGameToy
    class BoardGameToy:public Toy {
        int numberOfPlayers; 
        string rules;
    public:
        BoardGameToy();
        BoardGameToy(int numberOfPlayers, string rules);
        BoardGameToy(const BoardGameToy&);
        void input();
        void print() const;
        void setNumberOfPlayers(int numberOfPlayers);
        void setRules(string rules);
        int getNumberOfPlayers();
        string getRules();
        ~BoardGameToy();
        
    };


    BoardGameToy::BoardGameToy(){
        rules = " ";
        numberOfPlayers = 0;
        cout << "Object created";
    }

    BoardGameToy::BoardGameToy(int numberOfPlayers, string rules){
        this->rules = rules;
        this->numberOfPlayers = numberOfPlayers;
    }

    BoardGameToy::BoardGameToy(const BoardGameToy &toy){
        this->rules = toy.rules;    
        this->numberOfPlayers = toy.numberOfPlayers;                     
    }

    void BoardGameToy::input(){
        Toy::input();
        cout<<"please enter rules ";
        cin.ignore();
        getline(cin, rules, '\n');
        cout<<"please enter number of players ";
        cin >> numberOfPlayers;
    }

    void BoardGameToy::print() const{
        Toy::print();
        cout << "this game is for " << numberOfPlayers << " people"<<endl;
        cout << "rules: " << rules << endl;
    }

    void BoardGameToy::setRules(string rules){
        this->rules = rules;
    }

    void BoardGameToy::setNumberOfPlayers(int numberOfPlayers){
        this->numberOfPlayers = numberOfPlayers;
    }

    int BoardGameToy::getNumberOfPlayers(){
        return numberOfPlayers;
    }

    string BoardGameToy::getRules(){
        return rules;
    }

    BoardGameToy::~BoardGameToy(){
        cout << "Object destroyed";
    }

//main
    int main()
    {
        //ввід
        Toy *toys[n];
        for (int i = 0; i < n; ++i)
        {
            int choice;
            Toy* pointerToToy;
            cout<<"Press 1 for EducationToy and 2 for BoardGameToy ";
            cin>>choice;
            //вибрати аудіо чи паперова книига      
            switch(choice){
                case 1:
                    {
                        EducationToy* pointerToEducationToy = new EducationToy();
                        pointerToEducationToy->input();
                        pointerToToy = pointerToEducationToy;
                        break;
                    }
                case 2:
                    {
                        BoardGameToy* pointerToBoardGameToy = new BoardGameToy();
                        pointerToBoardGameToy->input();
                        pointerToToy = pointerToBoardGameToy;
                        break;
                    }
                default:
                    {
                        cout << "Invalid choice. Creating EducationToy by default.\n";
                        pointerToToy = new EducationToy();
                        pointerToToy->input();
                        break;
                    }
            }


            toys[i] = pointerToToy;
        }
    //вивід 
        for (int i = 0; i < n; ++i)
        {
            toys[i]->print();
        }

        

        //звільнення динамічної пам'яті
        for (int i = 0; i < n; ++i)
        {
            delete toys[i];
        }
        return 0;
    }

//done