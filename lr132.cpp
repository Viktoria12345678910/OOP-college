#include <iostream>
#include <exception>
using namespace std;

const int LIMIT = 100; 

class out_of_bounds : public exception {
private:
    int index;
    int limit;

public:
    out_of_bounds(int idx, int lim) : index(idx), limit(lim) {}

    const char* what() const noexcept override {
        return "Помилка: індекс виходить за межі масиву!";
    }

    int getIndex() const { return index; }
    int getLimit() const { return limit; }
};

class safearay {
private:
    int arr[LIMIT];

public:
    int& operator [](int n) {
        if(n < 0 || n >= LIMIT) {
            throw out_of_bounds(n, LIMIT);
        }
        return arr[n];
    }
};
int main() {
    safearay sa1;

    try {
        for(int j = 0; j < LIMIT; j++)
            sa1[j] = j * 10;
        
        for(int j = 0; j < LIMIT; j++) {
            int temp = sa1[j];
            cout << "sa1[" << j << "] = " << temp << endl;
        }
        cout << "\nСпроба доступу до sa1[100]..." << endl;
        cout << sa1[100] << endl; 
    }
    catch(const out_of_bounds& e) {
        cout << "\n*** ПЕРЕХОПЛЕНО ВИНЯТОК ***" << endl;
        cout << e.what() << endl;
        cout << "Індекс: " << e.getIndex()
             << ", Допустимий діапазон: 0-" << (e.getLimit() - 1) << endl;
    }
	cout << "\nПрограма продовжує роботу після обробки винятку"<<endl;

	return 0;
}
