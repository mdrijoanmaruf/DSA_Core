#include <iostream>
using namespace std;

int main() {
    int a , b;
    cout << "Enter a , b : ";
    cin >> a >> b;

    if(a > b){
        cout << a << " is bigger" << endl;
        cout << b << " is smaller" << endl;
    }else{
        cout << b <<" is bigger" << endl;
        cout << a <<" is smaller" << endl;
    } 
    return 0;
}