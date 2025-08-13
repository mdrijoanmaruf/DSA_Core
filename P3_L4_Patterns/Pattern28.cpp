#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << j + 1  << " ";
        }

        for(int j = 0; j < i; j++){
            cout << "* ";
            cout << "* ";
        }

        for(int j = 0; j < n - i ; j++){ 
            cout << n - j - i << " ";
        }

        cout << endl;
    }
    return 0;
}

// Input : 9
// 1 2 3 4 5 6 7 8 9 9 8 7 6 5 4 3 2 1 
// 1 2 3 4 5 6 7 8 * * 8 7 6 5 4 3 2 1
// 1 2 3 4 5 6 7 * * * * 7 6 5 4 3 2 1
// 1 2 3 4 5 6 * * * * * * 6 5 4 3 2 1
// 1 2 3 4 5 * * * * * * * * 5 4 3 2 1
// 1 2 3 4 * * * * * * * * * * 4 3 2 1
// 1 2 3 * * * * * * * * * * * * 3 2 1
// 1 2 * * * * * * * * * * * * * * 2 1 
// 1 * * * * * * * * * * * * * * * * 1