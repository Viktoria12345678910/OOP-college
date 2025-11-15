#include <iostream>
#include "student.h"
using namespace std;

int main(){
    cout<<"=== Testing Student Class ==="<<endl;
    
    Student student1("Іван", "Петренко", "Михайлович", true);
    cout<<student1<<endl;
    
    cout<<"\n=== Testing Group Class ==="<<endl;
    
    Student student2("Марія", "Коваленко", "Петрівна", false);
    Student student3("Олег", "Сидоренко", "Васильович", true);
    
    Group group1("КН-121", 121, student2);
    cout<<group1<<endl;
    
    Group group2("ПЗ-22", 122, student3);
    
    cout<<"\n=== Testing Facultet Class ==="<<endl;
    
    Facultet facultet1("Факультет комп'ютерних наук", group1);
    cout<<facultet1<<endl;
    
    
    return 0;
}