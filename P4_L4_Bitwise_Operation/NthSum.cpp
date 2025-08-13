#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += i + 1;
    }

    cout << "Sum : " << sum << endl;
    
    return 0;
}