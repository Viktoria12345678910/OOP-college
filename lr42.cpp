#include <iostream>
#include <string>
using namespace std;
#define months 3
//Базовий клас
class Publication{
	string title;
	float price;
public:
	Publication();
	void InputData();
	void OutputData() const;
	
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

//Базовий клас
class Sales{
float SoldInAMonth[months];
public:
	Sales();
	void InputData();
	void OutputData() const;
};

Sales::Sales(){
	for(int i = 0; i < months; i++){
		SoldInAMonth[i] = 0.0;
	}
}

void Sales::InputData(){
	cout << "Enter sales info"<<endl;
	for (int i = 0; i < months; ++i)
	{
		cout << "Enter sales for month "<<i<<endl;
		cin >> SoldInAMonth[i];
	}
}

void Sales::OutputData() const{
	cout << "Printing sales info"<<endl;
	for (int i = 0; i < months; ++i)
	{
		cout << "Sales for month "<<i<<endl;
		cout << SoldInAMonth[i];
	}
}


//Похідний класс публікації і продажів
class Book:public Publication, public Sales {
	int pageCount;
public:
	Book();
	void InputData();
	void OutputData() const;
	
};

Book::Book(){
	pageCount = 0;
}

void Book::InputData(){
	Publication::InputData();
	Sales::InputData();
	cout<<"please enter number of pages in the book ";
	cin >> pageCount;
}

void Book::OutputData() const{
	Publication::OutputData();
	Sales::OutputData();
	cout<<"there are "<<pageCount<<" pages in the book"<<endl;
}

//Похідний класс книжки
class Type:public Book{
	float duration;
public:
	Type();
	void InputData() ;
	void OutputData() const ;

	
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
	Sales::OutputData();
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