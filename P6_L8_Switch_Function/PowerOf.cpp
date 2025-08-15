#include <iostream>
using namespace std;

int power(int a , int b){
    int ans = 1;
    for(int i = 1; i <= b; i++){
        ans *= a;
    }
    return ans;
}

int main() {
    cout << "Power of 2, 3 : " << power(2,3) << endl;
    cout << "Power of 2, 5 : " << power(2,5) << endl;
    cout << "Power of 2, 8 : " << power(2,8) << endl;
    
    return 0;
}