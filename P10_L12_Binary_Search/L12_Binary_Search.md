# Binary Search - Quick Guide

## Time and Space Complexity
- **Time Complexity:** O(log n) (each step halves the search space)
- **Best Case:** O(1) (target is at the middle)
- **Worst/Average Case:** O(log n)
- **Space Complexity:**
    - Iterative: O(1) (uses a few variables)
    - Recursive: O(log n) (due to recursion stack)

## 1. What is Binary Search?

**Definition**: Efficient searching algorithm for **sorted arrays** that repeatedly divides search space in half.

**Key Requirement**: Array must be sorted!

## 2. Basic Algorithm

```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (arr[mid] == target) {
            return mid;  // Found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        }
        else {
            right = mid - 1; // Search left half
        }
    }
    
    return -1;  // Not found
}
```

## 3. How It Works

```
Array: [2, 5, 8, 12, 16, 23, 38, 45, 56]
Target: 23

Step 1: mid = 16, 23 > 16 → search right
Step 2: mid = 38, 23 < 38 → search left  
Step 3: mid = 23, 23 == 23 → Found!
```

## 4. Common Variants

### First Occurrence
```cpp
int findFirst(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Continue searching left
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### Last Occurrence
```cpp
int findLast(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;   // Continue searching right
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

## 5. Binary Search on Answer

### Square Root
```cpp
int sqrt(int n) {
    int left = 1, right = n, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (mid <= n / mid) {  // mid * mid <= n
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

## 6. Rotated Array Search

```cpp
int searchRotated(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        
        // Left half sorted
        if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half sorted
        else {
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

## 7. Important Tips

### Avoid Integer Overflow
```cpp
// Wrong: int mid = (left + right) / 2;
// Correct:
int mid = left + (right - left) / 2;
```

### Boundary Search Pattern
```cpp
// For finding boundaries, use:
while (left < right) {  // Not <=
    int mid = left + (right - left) / 2;
    if (condition) {
        right = mid;     // Not mid - 1
    } else {
        left = mid + 1;
    }
}
```

## 8. STL Functions

```cpp
#include <algorithm>
vector<int> arr = {1, 2, 3, 4, 5};

// Check if exists
bool found = binary_search(arr.begin(), arr.end(), 3);

// Find first occurrence
auto it = lower_bound(arr.begin(), arr.end(), 3);

// Find after last occurrence
auto it2 = upper_bound(arr.begin(), arr.end(), 3);
```

## 9. When to Use

**Use Binary Search when**:
- Array is sorted
- Need O(log n) performance
- Searching frequently

**Don't use when**:
- Array is unsorted
- Array is very small (< 100 elements)
- One-time search on unsorted data

## Memory Tips
- **Only works on SORTED arrays**
- **O(log n) = very fast for large data**
- **Each step eliminates half the elements**
- **Use `left + (right-left)/2` to avoid overflow**
- **Perfect for "guess and check" problems**