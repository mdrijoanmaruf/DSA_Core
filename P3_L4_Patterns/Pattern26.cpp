#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 1;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - 1 - i; j++){
            cout << "  ";
        }

        for(int j = 0; j < i + 1; j++){
            cout << count++ << " "; 
        }
        cout << endl;
    }
    return 0;
}

// Input : 3
//     1 
//   2 3
// 4 5 6