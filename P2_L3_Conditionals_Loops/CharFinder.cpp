#include <iostream>
using namespace std;

int main() {
    char ch ;
    cout << "Enter a Char : ";
    cin >> ch;

    if(ch >= 'a' && ch <= 'z'){
        cout << ch << " is between 'a-z'" << endl;
    } else if(ch >= 'A' && ch <= 'Z'){
        cout << ch << " is between 'A-Z'" << endl;
    } else {
        cout << ch << " is between '0-9'" << endl;
    }
    return 0;
}