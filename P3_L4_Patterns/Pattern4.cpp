#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << n - j << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 6
// 6 5 4 3 2 1 
// 6 5 4 3 2 1 
// 6 5 4 3 2 1 
// 6 5 4 3 2 1 
// 6 5 4 3 2 1 
// 6 5 4 3 2 1 