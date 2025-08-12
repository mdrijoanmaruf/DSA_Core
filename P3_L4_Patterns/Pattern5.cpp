#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            count = count + 1;
            cout << count << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 3
// 1 2 3 
// 4 5 6 
// 7 8 9