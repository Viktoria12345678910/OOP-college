#include <iostream>
using namespace std;
class Integer{
	int value;
	public:
		void setInt(int value);
		int getInt();
		void init();
};
	void Integer::setInt(int value){
		this->value = value;
	}

	int  Integer::getInt(){
		return value;
	}

	void Integer::init(){
		value = 0;
	}
int main(){
	Integer x1;
	Integer x2;
	Integer y;
	int x, y1;
	cout << "enter x1 ";
	cin >> x;
	x1.setInt(x);
	cout << "enter x2 ";
	cin >> x;
	x2.setInt(x);
	y1 = x1.getInt() + x2. getInt();
	y.setInt(y1);
	cout << "x1 = "<<x1.getInt()<<endl;
	cout << "x2 = "<<x2.getInt()<<endl;
	cout << "y = "<<y.getInt()<<endl;
	return 0;

}
