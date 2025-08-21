# Selection Sort - Quick Guide

## Definition
Selection Sort finds the minimum element from the unsorted portion and swaps it with the first element of the unsorted portion. Repeats until entire array is sorted.

## Algorithm
1. Find minimum element in unsorted array
2. Swap it with first element of unsorted portion
3. Move boundary of sorted portion forward
4. Repeat until array is sorted

## Implementation
```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find minimum in remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap minimum with first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
```

## Example
```
Array: [64, 25, 12, 22, 11]

Pass 1: Find min(64,25,12,22,11) = 11 → [11, 25, 12, 22, 64]
Pass 2: Find min(25,12,22,64) = 12    → [11, 12, 25, 22, 64]
Pass 3: Find min(25,22,64) = 22       → [11, 12, 22, 25, 64]
Pass 4: Find min(25,64) = 25          → [11, 12, 22, 25, 64]

Result: [11, 12, 22, 25, 64] ✓
```

## Complexity
- **Time Complexity**: 
  - Best Case: O(n²)
  - Average Case: O(n²)
  - Worst Case: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Not stable
- **In-place**: Yes

## Key Points
- Always O(n²) regardless of input
- Makes minimum number of swaps (at most n-1)
- Good for small arrays or when swaps are expensive
- Simple to implement but inefficient for large data