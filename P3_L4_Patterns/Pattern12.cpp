#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char ch = 'A';
        for(int j = 0; j < n ; j++){
            cout << ch++ << " ";
        }
        cout << endl;
    }
    return 0;
}

// Input : 4
// A B C D 
// A B C D
// A B C D
// A B C D