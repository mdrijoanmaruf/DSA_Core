#include <iostream>
using namespace std;

int main() {
    int a = 4; // 1 0 0
    int b = 6; // 1 1 0

    cout << "a & b : " << (a&b) << endl;
    cout << "a | b : " << (a|b) << endl;
    cout << "~a    : " << ~(a) << endl;
    cout << "a ^ b : " << (a^b) << endl;
    return 0;
}