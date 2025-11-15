#include <iostream>
using namespace std;

template <typename T>
class Task3{
	T *array;
	int size;
	public:
	Task3(int newsize);//+
	~Task3();//+
	void printArray(){
		for(int i = 0; i<size; i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
	//+
	T average();//+
	T amax();
};

template <typename T>
Task3<T>::Task3(int newsize){
	array = new T[size=newsize];
	for(int i = 0; i<size; i++)
		cin>>array[i];
}

template<typename T>
Task3<T>::~Task3(){
	delete [] array;
}

template<typename T>
T Task3<T>::average(){
	T temp = 0;
	for(int i=0; i<size; i++){
		temp += array[i];
	}
	return temp/size;
}

template<typename T>
T Task3<T>::amax(){
	T temp;
	for(int i = 1; i < size; i++){
		if(array[i] > array[i-1]){
			temp = array[i];
		}
	}
	return temp;
}
int main(){
	cout << "Введіть розмір масиву цідих чисел: ";
	int size1;
	cin >> size1;
	
	cout << "Введіть " << size1 << " цілих чисел: ";
	Task3<int> intArray(size1);
	
	cout << "Масив: ";
	intArray.printArray();
	cout << "Середнє значення: " << intArray.average() << endl;
	cout << "Максимальний елемент: " << intArray.amax() << endl;
	
	cout << "Введіть розмір масиву дійсних чисел: ";
	int size2;
	cin >> size2;
	
	cout << "Введіть " << size2 << " дійсних чисел: ";
	Task3<double> doubleArray(size2);
	
	cout << "Масив: ";
	doubleArray.printArray();
	cout << "Середнє значення: " << doubleArray.average() << endl;
	cout << "Максимальний елемент: " << doubleArray.amax() << endl;
	
	return 0;
}
