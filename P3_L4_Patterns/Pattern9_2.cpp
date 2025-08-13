#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n ; i++){
        // int c = i + 1;
        for(int j = 0; j < i+1; j++){
            cout << i + j + 1 << " ";
            // c++;
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
// 1 
// 2 3
// 3 4 5
// 4 5 6 7