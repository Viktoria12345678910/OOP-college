#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> alphabet = {"а", "б", "в", "г", "ґ", "д", "е", "є", "ж", "з", 
                               "и", "і", "ї", "й", "к", "л", "м", "н", "о", "п", 
                               "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", 
                               "ь", "ю", "я"};
    
    vector<string> vowels = {"а", "е", "є", "и", "і", "ї", "о", "у", "ю", "я"};
    
    for (const string& s : alphabet) {
        cout << s;
    }
    cout<<endl;
    cout<<"пропущені голосні: "<<endl;
    for (int i = 0; i < alphabet.size(); i++) {
        for (int j = 0; j < vowels.size(); j++) {
            if (alphabet[i] == vowels[j]) {
                alphabet[i] = " ";
                break;
            }
        }
    }
    
    for (const string& s : alphabet) {
        cout << s;
    }
    cout << endl;
    
    return 0;
}
