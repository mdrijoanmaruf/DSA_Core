#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int first = 0;
    int second = 1;
    int next;
    cout << first << endl;
    cout << second << endl;

    for (int i = 0; i < n; i++)
    {
        next = first + second;
        cout << next << endl;

        first = second;
        second = next;
    }
    
    return 0;
}