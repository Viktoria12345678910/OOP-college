#include <iostream>
#include <string>
using namespace std;
#define n 5
class Publication{
	string title;
	float price;
public:
	Publication();
	Publication* operator[](const int i){
		Publication* pointer;
		pointer = this;
		return pointer;
	}
	virtual void InputData();
	virtual void OutputData() const;
	virtual ~Publication(){
		cout << "object destroyed"<<endl;
	}
	
};
	Publication::Publication(){
		title = ' ';
		price = 0.0;
	}
	void Publication::InputData(){
		cout<<"BOOK"<<endl;
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

class AudioBook:public Publication{
	float duration;
public:
	AudioBook();
	void InputData() override;
	void OutputData() const override;

	
};
	AudioBook::AudioBook(){
		duration = 0.0;
	}

	void AudioBook::InputData() {
		cout<<"AUDIOBOOK"<<endl;
		Publication::InputData();
		cout<<"please enter duration of audiobook ";
		cin >> duration;

	}

	void AudioBook::OutputData() const{
		Publication::OutputData();
		cout<<"audio is "<<duration<<"minutes long"<<endl;
	}
int main()
{
	//ввід
	Publication *publications[n];
	for (int i = 0; i < n; ++i)
	{
		int choice;
		Publication publication;
		Publication* pointerToPublication;
		cout<<"Press 1 for book and 2 for audiobook ";
		cin>>choice;
		//вибрати аудіо чи паперова книига		
		switch(choice){
			case 1:
				{
					Book* pointerToBook = new Book();
					pointerToBook->InputData();
					pointerToPublication = pointerToBook;
					break;
				}
			case 2:
				{
					AudioBook* pointerToAudioBook = new AudioBook();
					pointerToAudioBook->InputData();
					pointerToPublication = pointerToAudioBook;
					break;
				}
		}


		publications[i] = pointerToPublication;
	}
//вивід ввід
	for (int i = 0; i < n; ++i)
	{
		publications[i]->OutputData();
	}
	//звільнення динамічної пам'яті
	for (int i = 0; i < n; ++i)
	{
		delete publications[i];
	}
	return 0;
}
