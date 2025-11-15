#include <iostream>
#include <list>
#include <locale.h>
using namespace std;

int main(){
	setlocale(LC_CTYPE, "uk_UA.UTF-8");
	list<char> lastName;
	char ln[] = "Baydetska";
	for(char i: ln){
		lastName.push_back(i);
	}

	for(auto i: lastName){
		cout << i;
	}
	cout<<endl;

	lastName.sort();
	cout<<"List is being sorted!"<<endl;
	
	for(auto i: lastName){
		cout << i;
	}
	cout<<endl;

	return 0;
}
//Done
