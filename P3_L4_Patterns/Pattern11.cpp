#include <iostream>
using namespace std;

int main() {
    int n;
    char c = 'A';
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            cout << c << " ";
        }
        c++;
        cout << endl;
    }
    return 0;
}

// Input : 4
// A A A A 
// B B B B 
// C C C C 
// D D D D 