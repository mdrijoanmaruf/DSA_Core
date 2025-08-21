#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;  // Pivot index
}

int main() {
    // Test Case 1
    vector<int> arr1 = {7, 9, 1, 2, 3};
    cout << "Pivot index: " << getPivot(arr1) << endl; // Expected: 2

    // Test Case 2
    vector<int> arr2 = {3, 4, 5, 1, 2};
    cout << "Pivot index: " << getPivot(arr2) << endl; // Expected: 3

    // Test Case 3
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Pivot index: " << getPivot(arr3) << endl; // Expected: 0 (already sorted, no rotation)

    // Test Case 4
    vector<int> arr4 = {5, 1, 2, 3, 4};
    cout << "Pivot index: " << getPivot(arr4) << endl; // Expected: 1

    return 0;
}
