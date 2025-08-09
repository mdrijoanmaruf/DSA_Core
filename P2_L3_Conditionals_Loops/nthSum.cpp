#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter n : ";
    cin >> n;

    int i = 0;
    int sum = 0;
    while (i <= n)
    {
        sum = sum + i;
        i++;
    } 
    cout << sum << endl;
    return 0;
}