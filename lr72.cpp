#include <iostream>
using namespace std;

template <typename T> 
T amax(T *array, int size){
	T temp;
	for(int i = 1; i < size; i++){
		if(array[i] > array[i-1]){
			temp = array[i];
		}
	}
	return temp;
}

int main(){
	int size = 3;
	int arrayInt[size] = {42, -17, 305};
	long arrayLong[size] = {1234567890L, -9876543210L, 5555555555L};
	double arrayDouble[size] = {3.14159, -2.71828, 0.57721};
	cout<<"Int Array "<<amax(arrayInt, size)<<endl;
	cout<<"Long array "<<amax(arrayLong, size)<<endl;
	cout<<"Double array "<<amax(arrayDouble, size)<<endl;
	return 0;
}
//Done
