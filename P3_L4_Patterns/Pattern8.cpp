#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            sum++;
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
// 1 
// 2 3
// 4 5 6
// 7 8 9 10