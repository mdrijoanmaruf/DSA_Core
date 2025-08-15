#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int x = 121;
    int result = 0;
    int l = to_string(abs(x)).length() - 1;

    while (x != 0)
    {
        int digit = x % 10;
        result = result + digit * (int)(pow(10, l) + 0.5);
        cout << result << endl;
        x /= 10;
        l--;
    }
    cout << result << endl;

    return 0;
}