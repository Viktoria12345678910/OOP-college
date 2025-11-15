#include <iostream>
using namespace std;
class Integer{
	int value;
	public:
		Integer();
		Integer(int value);
		void print() const;
		void init();
		Integer operator+(Integer&);
		Integer operator-(Integer&);
		Integer operator*(Integer&);
		Integer operator/(Integer&);
};
	Integer::Integer(){
		value = 0;
	}

	Integer::Integer(int value){
		this->value = value;
	}

	void  Integer::print() const{
		cout << value <<endl;
	}

	void Integer::init(){
		value = 0;
	}
	Integer Integer::operator+(  Integer& b)  {
		return Integer(value+b.value);
	}
	Integer Integer::operator-(  Integer &b)  {
		return Integer(value-b.value);
	}
	Integer Integer::operator*(  Integer &b)  {
		return Integer(value*b.value);
	}
	Integer Integer::operator/(  Integer &b)  {
		return Integer(value/b.value);
	}
int main(){
	Integer objA(10);
	Integer objB(1); 
	Integer objC;
	objC = objA + objB;
	objC.print();
	objC = objA - objB;
	objC.print();
	objC = objA * objB;
	objC.print();
	objC = objA / objB;
	objC.print();

}
//Done