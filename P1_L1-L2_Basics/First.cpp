#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;

    int a = 10;
    int size = sizeof(a);
    cout << size << endl;

    int b = 'b';
    cout << b << endl;

    int x = 2;
    int y = 3;

    bool z = (x < y);
    cout << z << endl;

    return 0;
}