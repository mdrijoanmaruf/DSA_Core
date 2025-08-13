#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch = 'A' + i + j;
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
// A B C D 
// B C D E
// C D E F
// D E F G