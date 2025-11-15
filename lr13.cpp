#include <iostream>
#include <iomanip>
using namespace std;

class Time{
	int hours;
	int minutes;
	int seconds;
	public:
		void initZero(); 
		void initTime(int h, int m, int s); 
		void display() const; 
		Time addTime(const Time& other) const; 
};

void Time::initZero(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}


void Time::initTime(int h, int m, int s){
	hours = h;
	minutes = m;
	seconds = s;
}


void Time::display() const{
	cout << setfill('0') << setw(2) << hours << ":"
	     << setfill('0') << setw(2) << minutes << ":"
	     << setfill('0') << setw(2) << seconds;
}


Time Time::addTime(const Time& other) const{
	Time result; 
	
	int ho = hours + other.hours;
	int min = minutes + other.minutes;
	int sec = seconds + other.seconds;
	
	
	if(sec >= 60){
		min += sec/60;
		sec %= 60;
	}
	
	
	if(min >= 60){
		ho += min/60;
		min %= 60;
	}
	
	
	result.initTime(ho, min, sec); 
	return result;
}

int main(){
	int h1, h2, m1, m2, s1, s2;
	
	
	Time time1;
	Time time2;
	Time result;
	
	cout << "Введіть перший час:" << endl;
	cout << "Години: ";
	cin >> h1;
	cout << "Хвилини: ";
	cin >> m1;
	cout << "Секунди: ";
	cin >> s1;
	
	cout << "\nВведіть другий час:" << endl;
	cout << "Години: ";
	cin >> h2;
	cout << "Хвилини: ";
	cin >> m2;
	cout << "Секунди: ";
	cin >> s2;
	

	time1.initTime(h1, m1, s1);
	time2.initTime(h2, m2, s2);
	

	result = time1.addTime(time2);
	
	cout << "\nРезультати:" << endl;
	cout << "Перший час: ";
	time1.display();
	cout << endl;
	
	cout << "Другий час: ";
	time2.display();
	cout << endl;
	
	cout << "Сума часів: ";
	result.display();
	cout << endl;
	
	return 0;
}