#include <iostream>
using namespace std;

int main() {
    int n;
    cin >>n;
    char ch = 'A';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch++ << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}

// Input : 4
// A 
// B C
// D E F
// G H I J