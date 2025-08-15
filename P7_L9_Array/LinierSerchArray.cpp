#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {23, 45, 12, 67, 34, 9, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter value to search: ";
    cin >> target;
    int index = linearSearch(arr, size, target);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in array." << endl;
    }
    return 0;
}