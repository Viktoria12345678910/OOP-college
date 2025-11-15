#include <iostream>
#include <string>
using namespace std;
class Publication{
	string title;
	float price;
public:
	Publication();
	void InputData();
	void OutputData() const;
	~Publication();
	
};
void Publication::InputData(){
	string title;
	float price;
	cout<<"please enter title of the book";
	cin >> title;
	this->title = title;
	cout<<"please enter price of the book";
	cin >> price;
	this->price = price;
}


void Publication::OutputData() const{
	cout<<"book title: "<<title<<endl<<"book price: "<<price<<endl;
}


class Book:public Publication {
	int pageCount;
public:
	Book();
	void InputData();
	void OutputData() const;
	~Book();
	
};

void Book::InputData(){
	int pageCount;
	Publication::InputData();
	cout<<"please enter number of pages in the book";
	cin >> pageCount;
	this->pageCount = pageCount;
}

void Book::OutputData() const{
	Publication::OutputData();
	cout<<"there are "<<pageCount<<"pages in the book"<<endl;
}

class Type{
	float duration;
public:
	Type();
	void InputData();
	void OutputData() const;
	~Type();
	
};

void Type::InputData() {
	float duration;
	Book::InputData();
	cout<<"please enter duration of audiobook";
	cin >> duration;
	this->duration = duration;
}

void Type::OutputData() const{
	Book::OutputData();
	cout<<"audio is "<<duration<<"minutes long"<<endl;
}

int main()
{
	Book book;
	Type audiobook;
	book.InputData();
	audiobook.InputData();
	book.OutputData();
	audiobook.OutputData();
	return 0;
}