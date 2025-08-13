#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << "  ";
        }

        for(int j = 0; j < n - i; j++){
            cout << i + j + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
// 1 2 3 4 
//   2 3 4
//     3 4
//       4