#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

class Kasa{
	int carCount;
	double money;
	public:
		Kasa(); // Constructor
		void payingCar();
		void noPayingCar();
		void display() const;
};

Kasa::Kasa(){ 
	carCount = 0;
	money = 0;
}

void Kasa::payingCar(){
	carCount++;
	money += 0.5;
}

void Kasa::noPayingCar(){
	carCount++;
}

void Kasa::display() const{
	cout << "Усього автомобілів проїхало: " << carCount << endl;
	cout << "Виручка: $" << money << endl;
}


char getch() {
	struct termios oldt, newt;
	char ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

int main(){
	Kasa kasa;
	
	cout << "Виберіть подію:" << endl;
	cout << "1. Водій проїхав й оплатив проїзд" << endl;
	cout << "2. Водій ухильнувся" << endl;
	cout << "3. Кінець дня, що там по касі?" << endl;
	cout << "ESC - Вихід з програми" << endl << endl;
	
	while(true){
		cout << "Натисніть клавішу: " << flush; // flush ensures immediate display
		char key = getch();
		cout << endl;
		
		if(key == 27){ // ESC key
			cout << "Вихід з програми..." << endl;
			kasa.display();
			break;
		}
		
		switch(key){
			case '1':
				kasa.payingCar();
				cout << "Водій оплатив проїзд" << endl << endl;
				break;
			case '2':
				kasa.noPayingCar();
				cout << "Водій ухильнувся від оплати" << endl << endl;
				break;
			case '3':
				cout << "Кінець дня:" << endl;
				kasa.display();
				return 0;
			default:
				cout << "Невірний вибір" << endl << endl;
		}
	}
	
	return 0;
}
