#include <iostream>
#include <string>
#include <vector>
using namespace std;

//student class
	class Student{
			string firstName;
			string lastName;
			string paternalName;
			bool scholarship;
		public:
			Student(); //+
			Student(string firstName, string lastName, string paternalName, bool scholarship);
			//визначення виводу
			friend ostream& operator<<(ostream&, Student& student){
	        	cout<<" Last Name: "<<student.lastName<<"\n First name: "<<student.firstName<<"\n Paternal name"<<student.paternalName<<endl;
	        	if (student.scholarship == true)
	        		cout<<"студент вчиться на бюджеті ";
	        	else
	        		cout<<"студент вчиться на контракті";
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
			cout<<"Чи навчається цей студент на бюджеті 0 - ні, 1 - так ";
			cin>>temp;

				switch(temp){
					case 1:
					{
						scholarship = true;
						break;
					}
					case 0:
					{
						scholarship = false;
						break;
					}
					default:
					{
						cout<<"неправильне значення. Автоматично призначається на платне";
						scholarship = false;
						break;
					}

				}
		}

		Student::Student(string firstName, string lastName, string paternalName, bool scholarship){
			this->firstName = firstName;
			this->lastName = lastName;
			this->paternalName = paternalName;
			this->scholarship = scholarship;
		}

//group class
	class Group{
			string groupName;
			int major;
			vector<Student> students;
		public:
			// конструктор за замовчуванням
			Group();
			//параметризований конструктор
			Group(string groupName, int major, Student& student);
			//деструктор
			~Group();
			//операція виводу в потік
			friend ostream& operator<<(ostream&, Group& group){
	        	cout<<"\n Groupe Name: "<<group.groupName<<"major: "<<group.major<<endl;
	        	for (auto i: group.students)
	        	{
	        		cout<<i;
	        	}
	        	return cout;
	    	}
	    };

	Group::Group(){
		int temp;
		cout<<"Введіть назву групи: ";
		cin>>groupName;
		cout<<"Введіть номер спеціальності: ";
		cin>> major;
		cout<<"Введіть скільки студентів в групі: ";
		cin>>temp;
		int i = 0;
		do {
			cout<<"Введіть студента ";
			Student student;
			students.push_back(student);
			++i;
		} while(i<temp);

	}

	Group::Group(string groupName, int major, Student& student){
		this->groupName = groupName;
		this->major = major;
		students.push_back(student);
	}

	Group::~Group(){
		cout<<"object destroyed";
	}

//facultet class
	class Facultet{
		string facultetName;
		vector<Group> groups;
		public:
			Facultet();
			Facultet(string facultetName,Group group);
			friend ostream& operator<<(ostream&, Facultet& facultet){
	        	cout<<"\n facultet Name: "<<facultet.facultetName<<endl;
	        	for (auto i: facultet.groups)
	        	{
	        		cout<<i;
	        	}
	        	return cout;
	    	}
	    	~Facultet();
	};

	Facultet::Facultet(){
		int temp;
		cout<<"Введіть назву факультету: ";
		cin>>facultetName;
		cout<<"Введіть скільки груп на факультеті в групі: ";
		cin>>temp;
		int i = 0;
		do {
			cout<<"Введіть групу";
			Group group;
			groups.push_back(group);
			++i;
		} while(i<temp);
	}


	Facultet::Facultet(string facultetName,Group group){
		this->facultetName = facultetName;
		groups.push_back(group);

	}

	Facultet::~Facultet(){
		cout<<"facultet destroyed";
	}

