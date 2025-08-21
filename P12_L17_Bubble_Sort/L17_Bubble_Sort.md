# Bubble Sort - Quick Guide

## Definition
Bubble Sort repeatedly compares adjacent elements and swaps them if they're in wrong order. Larger elements "bubble up" to the end of the array through multiple passes.

## Algorithm
1. Compare adjacent elements from start to end
2. Swap if left element > right element
3. After each pass, largest element reaches correct position
4. Repeat for n-1 passes until array is sorted

## Basic Implementation
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

## Optimized Implementation
```cpp
void optimizedBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Flag to detect if any swap occurred
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping occurred, array is already sorted
        if (!swapped) {
            break;
        }
    }
}
```

## Example
```
Array: [64, 34, 25, 12, 22]

Pass 1: Compare & swap adjacent elements
[64,34,25,12,22] → [34,64,25,12,22] → [34,25,64,12,22] → 
[34,25,12,64,22] → [34,25,12,22,64]
Result: [34, 25, 12, 22, 64] (64 in correct position)

Pass 2: Repeat for remaining elements
[34,25,12,22,64] → [25,34,12,22,64] → [25,12,34,22,64] → [25,12,22,34,64]
Result: [25, 12, 22, 34, 64] (34 in correct position)

Pass 3: Continue...
[25,12,22,34,64] → [12,25,22,34,64] → [12,22,25,34,64]
Result: [12, 22, 25, 34, 64] (25 in correct position)

Pass 4: Final pass
[12,22,25,34,64] → No swaps needed
Final: [12, 22, 25, 34, 64] ✓
```

## Complexity

### Basic Bubble Sort
- **Time Complexity**: 
  - Best Case: O(n²) - Even if already sorted
  - Average Case: O(n²)
  - Worst Case: O(n²)
- **Space Complexity**: O(1)

### Optimized Bubble Sort
- **Time Complexity**: 
  - Best Case: O(n) - Already sorted array
  - Average Case: O(n²)
  - Worst Case: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Yes - maintains relative order of equal elements
- **In-place**: Yes

## Optimization Techniques

### 1. Early Termination (Implemented above)
```cpp
// Stop if no swaps occur in a complete pass
if (!swapped) break;
```

### 2. Cocktail Shaker Sort (Bidirectional Bubble Sort)
```cpp
void cocktailShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0, end = n - 1;
    
    while (swapped) {
        swapped = false;
        
        // Forward pass (left to right)
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        end--;  // Last element is in correct position
        
        if (!swapped) break;
        
        swapped = false;
        
        // Backward pass (right to left)
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;  // First element is in correct position
    }
}
```

### 3. Recursive Bubble Sort
```cpp
void recursiveBubbleSort(int arr[], int n) {
    // Base case
    if (n == 1) return;
    
    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    // Largest element is now at correct position
    // Recursively sort remaining n-1 elements
    recursiveBubbleSort(arr, n - 1);
}
```

## Comparison with Selection Sort
| Feature | Bubble Sort | Selection Sort |
|---------|-------------|----------------|
| **Best Case** | O(n) optimized | O(n²) always |
| **Swaps** | O(n²) max | O(n) max |
| **Stability** | Yes | No |
| **Adaptive** | Yes (optimized) | No |
| **Implementation** | Slightly complex | Very simple |

## Key Points
- **Adaptive**: Optimized version performs better on partially sorted arrays
- **Stable**: Maintains relative order of equal elements
- **More swaps**: Generally performs more swaps than Selection Sort
- **Early termination**: Can detect when array becomes sorted
- **Cocktail Shaker**: Bidirectional version can be more efficient
- **Educational value**: Great for understanding basic sorting concepts
- **Practical use**: Rarely used for large datasets due to O(n²) complexity

## When to Use
- **Small datasets** (< 50 elements)
- **Nearly sorted arrays** (with optimization)
- **Educational purposes** - easy to understand and visualize
- **Stability required** - maintains order of equal elements
- **Memory constraints** - O(1) space complexity

## Memory Tips
- **Adjacent comparison** - always compares neighboring elements
- **Largest bubbles up** - heaviest element moves to end each pass
- **Optimization flag** - `swapped` variable for early termination
- **Stable algorithm** - equal elements maintain original order
- **Adaptive** - optimized version adapts to input order
- **n-1 passes maximum** - but can terminate early if sorted
