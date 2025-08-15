#include <iostream>
using namespace std;
int countBit(int x){
        int count = 0;

        while(x != 0){
            if( x & 1){
                count++;
                x = x >> 1;
            }
            else {
                x = x >> 1;
            }
        
        }
        return count;
    }
int main() {
    cout << countBit(7) << endl;
    return 0;
}