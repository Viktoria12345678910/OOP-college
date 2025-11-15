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
	title = "";
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
	void inputData();
	void outputData() const;  // const у оголошенні
};

Sales::Sales(){
	for(int i = 0; i < months; i++){
		SoldInAMonth[i] = 0.0;
	}
}

void Sales::inputData(){
	cout << "Enter sales info"<<endl;
	for (int i = 0; i < months; ++i)
	{
		cout << "Enter sales for month "<<i+1<<": ";
		cin >> SoldInAMonth[i];
	}
}

void Sales::outputData() const{  // const у реалізації
	cout << "Printing sales info"<<endl;
	for (int i = 0; i < months; ++i)
	{
		cout << "Sales for month "<<i+1<<": "<<SoldInAMonth[i]<<endl;
	}
}

//Похідний класс публікації і продажів
class Book: public Publication, public Sales {
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
	Sales::inputData();
	cout<<"please enter number of pages in the book: ";
	cin >> pageCount;
}

void Book::OutputData() const{
	Publication::OutputData();
	Sales::outputData();
	cout<<"there are "<<pageCount<<" pages in the book"<<endl;
}

//Похідний класс - ВИДАЛЕНО подвійне наслідування Sales
class Type: public Book{  // Тільки Book, Sales вже є в Book
	float duration;
public:
	Type();
	void InputData();
	void OutputData() const;
};

Type::Type(){
	duration = 0.0;
}

void Type::InputData(){
	cout<<"AUDIOBOOK"<<endl;
	Book::InputData();  // Book вже викликає Sales::inputData()
	cout<<"please enter duration of audiobook (minutes): ";
	cin >> duration;
}

void Type::OutputData() const{
	Book::OutputData();  // Book вже викликає Sales::outputData()
	cout<<"audio is "<<duration<<" minutes long"<<endl;
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