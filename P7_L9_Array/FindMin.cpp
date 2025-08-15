#include <iostream>
using namespace std;

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {23, 45, 12, 67, 34, 9, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum value in array: " << findMin(arr, size) << endl;
    return 0;
}