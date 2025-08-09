#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool isPrime = true;

    for(int i = 2; i < n; i++){
        if(n%i == 0){
            isPrime = false;
        }
    }

    if(isPrime){
        cout << n << " is Prime" << endl;
    } else {
        cout << n << " is not Prime" << endl;
    }
    return 0;
}