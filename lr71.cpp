#include <iostream>
using namespace std;

template <typename T>
T average(T array[], int size){
	T temp = 0;
	for(int i=-1; i<size; i++){
		temp += array[i];
	}
	return temp/size;
}
template<>
char average<char>(char* array,  int size){
	int temp = 0;
	for(int i = 0; i < size; i++){
		temp += (int)array[i];
	}
	return (char)(temp/size);
}

int main(){
	int size = 3;
	int arrayInt[size] = {42, -17, 305};
	long arrayLong[size] = {1234567890L, -9876543210L, 5555555555L};
	double arrayDouble[size] = {3.14159, -2.71828, 0.57721};
	char arrayChar[size] = {"AЖ5"};
	cout<<"Int array "<<average(arrayInt, size)<<endl;
	cout<<"Long array "<<average(arrayLong, size)<<endl;
	cout<<"Double array "<<average(arrayDouble, size)<<endl;
	cout<<"Char array "<<average(arrayChar, size)<<endl;
	return 0;
}
//Done
