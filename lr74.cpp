#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
	T** array;
	int capacity;
	int top;
	public:
		Stack(int size = 10);
		~Stack();
		void push(const T& value);
		T pop();
		void print() const;
		int size() const;
		bool isEmpty() const;
		bool isFull() const;
};

template <typename T>
Stack<T>::Stack(int size): capacity(size), top(-1){
	array = new T*[capacity];
	for(int i = 0; i < capacity; i++){
		array[i] = nullptr;
	}
}

template <typename T>
Stack<T>::~Stack(){
	for(int i = 0; i <= top; i++){
		delete  array[i];
	}
	delete [] array;
}

template <typename T>
void Stack<T>::push(const T& value){
	if(isFull()){
		cout<<"Черга повна"<<endl;
		return;
	}
	top++;
	array[top] = new T(value);
}

template <typename T>
T Stack<T>::pop(){
	if(isEmpty()){
	cout<<"черга порожня"<<endl;
	return 0;
	}
	T value = *array[top];
	delete array[top];
	array[top] = nullptr;
	top--;
	return value;
}

template <typename T>
void Stack<T>::print() const{
	if(isEmpty()){
		cout<< "стек порожній"<<endl;
		return;
	}
	for(int i = top; i >=0; i--){
		cout<<" ["<<i<<"] "<< *array[i]<<endl;
	}
}

template <typename T>
int Stack<T>::size() const{
	return top + 1;
}

template <typename T>
bool Stack<T>::isEmpty() const{
	return top == -1;
}

template <typename T>
bool Stack<T>::isFull() const{
	return top == capacity - 1;
}

int main(){
	cout<<"Стек цілих чисел"<<endl;
	Stack<int> intStack(5);

	intStack.push(10);
	intStack.push(20);
	intStack.push(30);
	intStack.push(40);

	cout<<"кількість елементів"<<intStack.size();
	intStack.print();

	cout<<"вилучення елементів"<<endl;
	intStack.pop();
	intStack.pop();
	intStack.print();
	cout<<"кількість елементів"<<intStack.size();

	cout<<"Стек дійсних чисел чисел"<<endl;
	Stack<double> doubleStack(4);

	doubleStack.push(3.14);
	doubleStack.push(2.71);
	doubleStack.push(1.41);

	cout<<"кількість елементів"<<doubleStack.size();
	doubleStack.print();

	cout<<"вилучення елементів"<<endl;
	intStack.pop();
	intStack.pop();
	intStack.print();
	cout<<"кількість елементів"<<intStack.size();


	cout<<"Стек рядків"<<endl;
	Stack<string> stringStack(3);

	stringStack.push(string("Hello"));
	stringStack.push(string("World"));
	stringStack.push(string("!"));

	cout<<"кількість елементів"<<stringStack.size();
	stringStack.print();

	cout<<"вилучення елементів"<<endl;
	stringStack.pop();
	stringStack.pop();
	stringStack.print();
	cout<<"кількість елементів"<<stringStack.size();
	return 0;
}

