#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {23, 45, 12, 67, 34, 9, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value in array: " << findMax(arr, size) << endl;
    return 0;
}