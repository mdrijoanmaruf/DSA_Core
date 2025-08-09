#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a : ";
    cin >> a ;
    if(a > 0){
        cout << a << " is Positive" << endl;
    } else if(a < 0){
        cout << a << " is Negative" << endl;
    } else {
        cout << a << " is Zero" << endl;
    }

    return 0;
    
    
    
}