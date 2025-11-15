#include <iostream>
#include <string>
using namespace std;
class Publication{
	string title;
	float price;
public:
	Publication();
	virtual void InputData();
	virtual void OutputData() const;
	
};
Publication::Publication(){
	title = ' ';
	price = 0.0;
}
void Publication::InputData(){

	cout<<"please enter title of the book ";
	cin >> title;
	cout<<"please enter price of the book ";
	cin >> price;
}


void Publication::OutputData() const{
	cout<<"book title: "<<title<<endl<<"book price: "<<price<<endl;
}


class Book:public Publication {
	int pageCount;
public:
	Book();
	void InputData() override;
	void OutputData() const override;
	
};

Book::Book(){
	pageCount = 0;
}

void Book::InputData(){
	Publication::InputData();
	cout<<"please enter number of pages in the book ";
	cin >> pageCount;
}

void Book::OutputData() const{
	Publication::OutputData();
	cout<<"there are "<<pageCount<<" pages in the book"<<endl;
}

class Type:public Book{
	float duration;
public:
	Type();
	void InputData() override;
	void OutputData() const override;

	
};
Type::Type(){
	duration = 0.0;
}

void Type::InputData() {
	cout<<"AUDIOBOOK"<<endl;
	Book::InputData();
	cout<<"please enter duration of audiobook ";
	cin >> duration;

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