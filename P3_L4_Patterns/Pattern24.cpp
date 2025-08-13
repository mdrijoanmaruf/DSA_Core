#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - 1 - i; j++){
            cout << "  ";
        }

        for(int j = 0; j < i + 1; j++){
            cout << i + 1 << " "; 
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
//       1 
//     2 2
//   3 3 3
// 4 4 4 4