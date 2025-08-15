#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}

void nCr(int n , int r){
    if (r > n || r < 0 || n < 0) {
        cout << "Invalid input: n must be >= r and both must be non-negative" << endl;
        return;
    }
    cout << n << "C" << r << " value : " << factorial(n)/(factorial(r)*factorial(n-r)) << endl;
}

int main() {
    nCr(5, 2);   // Valid: 5C2 = 10
    nCr(10, 3);  // Valid: 10C3 = 120
    nCr(10, 20); // Invalid: will show error message
    return 0;
}