#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;
    return 0;
}