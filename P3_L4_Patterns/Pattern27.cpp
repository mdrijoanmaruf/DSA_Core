#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < n - 1 - i; j++){
            cout << "  ";
        }

        for(int j = 0; j < i + 1 ; j++){
            cout << j + 1 << " ";
        }

        for(int j = 0; j < i; j++){
            cout << i  - j << " "; 
        }
        cout << endl;
    }
    return 0;
}

// Input : 9
//                 1 
//               1 2 1
//             1 2 3 2 1
//           1 2 3 4 3 2 1
//         1 2 3 4 5 4 3 2 1
//       1 2 3 4 5 6 5 4 3 2 1
//     1 2 3 4 5 6 7 6 5 4 3 2 1
//   1 2 3 4 5 6 7 8 7 6 5 4 3 2 1
// 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1