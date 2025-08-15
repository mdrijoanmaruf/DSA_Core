#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n == 2){
        return true;
    }
    for(int i = 2; i < n; i++){
        if(n%2 == 0){
            return false;
        }
    }
    return true;
}

void nthPrime (int n){
    for (int i = 1; i <= n; i++)
    {
        if(isPrime(i)){
            cout << i << " ";
        }
    }
    
}
int main() {
    int n;
    cin >> n;

    nthPrime(n);
    return 0;
}
