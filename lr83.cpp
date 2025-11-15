#include <iostream>
#include <vector>
#include "lr2.h"
using namespace std;
int main(){
	vector<Toy> vectorOfClassToy;
	Toy Toy1;    
    	char name1[] = "alexander hamilton"; 
    	Toy1.setOwnerName(name1);
    	Toy1.setOld(3);
    	vectorOfClassToy.push_back(Toy1);

    	char name2[] = "eliza schyler";
    	Toy Toy2(name2, 5); 
    	vectorOfClassToy.push_back(Toy2);
	cout<<"<<By index>>";
	for(int i = 0; i < vectorOfClassToy.size(); i++){
		cout<<vectorOfClassToy[i];
	}
	cout<<"<<By iterator>>";
	for(auto i: vectorOfClassToy){
		cout<<i;
	}

}
//Done
