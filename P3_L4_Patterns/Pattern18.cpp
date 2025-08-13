#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + n - i - 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch++ << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}

// Input : 4
// D 
// C D
// B C D
// A B C D