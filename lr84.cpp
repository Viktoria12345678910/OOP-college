#include <iostream>
#include<list>
#include "student2.h"
using namespace std;

int main(){
	list<Student> group;
	Student student1("Іван", "Петренко", "Михайлович", 17, "+380 67 123 45 67");
	group.push_back(student1);

	Student student2("Марія", "Коваленко", "Петрівна", 18, "+380 50 987 65 43");
	group.push_back(student2);

	Student student3("Олег", "Сидоренко", "Васильович", 19, "+380 93 456 78 90");
	group.push_back(student3);

	
	for(auto i: group){
		cout<<i;
	}

	cout<<"success";
	return 0;
}
