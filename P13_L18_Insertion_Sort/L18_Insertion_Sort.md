# Insertion Sort - Quick Guide

## Definition
Insertion Sort builds the sorted array one element at a time by taking each element from the unsorted portion and inserting it into its correct position in the sorted portion.

## Algorithm
1. Start with second element (assume first is sorted)
2. Compare current element with elements in sorted portion
3. Shift larger elements to the right
4. Insert current element in correct position
5. Repeat until all elements are processed

## Basic Implementation
```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Current element to be inserted
        int j = i - 1;     // Index of last element in sorted portion
        
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert key at correct position
        arr[j + 1] = key;
    }
}
```

## Complexity

### Basic Insertion Sort
- **Time Complexity**: 
  - Best Case: O(n) - Already sorted array
  - Average Case: O(n²)
  - Worst Case: O(n²) - Reverse sorted array
- **Space Complexity**: O(1)

### General Properties
- **Stability**: Yes - maintains relative order of equal elements
- **In-place**: Yes - sorts within original array
- **Adaptive**: Yes - performs better on partially sorted arrays
- **Online**: Yes - can sort elements as they arrive
