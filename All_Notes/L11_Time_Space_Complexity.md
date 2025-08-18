# Time and Space Complexity

## 1. What is Complexity Analysis?

### Definition
Complexity analysis is a method to analyze the efficiency of algorithms by measuring:
- **Time Complexity**: How execution time grows with input size
- **Space Complexity**: How memory usage grows with input size

### Why is it Important?
- Compare different algorithms
- Predict performance for large inputs
- Optimize code for better efficiency
- Make informed decisions about algorithm choice

## 2. Three Types of Complexity

### 2.1 Best Case Complexity (Ω - Omega)
The **minimum** time/space an algorithm takes for any input of size n.

```cpp
// Example: Linear Search - Best Case
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Found at first position
        }
    }
    return -1;
}

// Best Case: Target is at index 0
// Time Complexity: Ω(1) - Constant time
```

### 2.2 Average Case Complexity (Θ - Theta)
The **expected** time/space an algorithm takes for typical inputs.

```cpp
// Example: Linear Search - Average Case
// Target could be anywhere in the array
// On average, we check n/2 elements
// Time Complexity: Θ(n) - Linear time
```

### 2.3 Worst Case Complexity (O - Big O)
The **maximum** time/space an algorithm takes for any input of size n.

```cpp
// Example: Linear Search - Worst Case
// Target is at the last position or not present
// We check all n elements
// Time Complexity: O(n) - Linear time
```

## 3. Big O Notation

### Definition
Big O notation describes the **worst-case** performance of an algorithm as the input size approaches infinity.

### Mathematical Definition
f(n) = O(g(n)) if there exist positive constants c and n₀ such that:
```
f(n) ≤ c × g(n) for all n ≥ n₀
```

### Key Properties
- **Upper Bound**: Describes the maximum growth rate
- **Asymptotic**: Focuses on behavior as n approaches infinity
- **Worst Case**: Considers the least favorable scenario
- **Ignores Constants**: O(2n) = O(n), O(n + 100) = O(n)

### Rules for Big O
```cpp
// 1. Drop constants
O(2n) = O(n)
O(n/2) = O(n)

// 2. Drop lower-order terms
O(n² + n) = O(n²)
O(n³ + n² + n + 1) = O(n³)

// 3. Different inputs use different variables
// Two separate arrays of size m and n
O(m + n) ≠ O(n)
```

## 4. Complexity Order (From Best to Worst)

### Common Time Complexities (Ranked)

| Big O | Name | Description | Example |
|-------|------|-------------|---------|
| O(1) | Constant | Same time regardless of input size | Array access |
| O(log n) | Logarithmic | Time grows logarithmically | Binary search |
| O(n) | Linear | Time grows linearly | Linear search |
| O(n log n) | Linearithmic | Efficient sorting algorithms | Merge sort |
| O(n²) | Quadratic | Nested loops over input | Bubble sort |
| O(n³) | Cubic | Three nested loops | Matrix multiplication |
| O(2ⁿ) | Exponential | Very slow for large inputs | Recursive fibonacci |
| O(n!) | Factorial | Extremely slow | Traveling salesman |

### Visual Growth Comparison
```
For n = 1000:
O(1)      = 1 operation
O(log n)  = ~10 operations
O(n)      = 1,000 operations
O(n log n)= ~10,000 operations
O(n²)     = 1,000,000 operations
O(2ⁿ)     = 2^1000 operations (practically impossible!)
```

## 5. Basic Algorithm Examples

### 5.1 Constant Time - O(1)

#### Array Access
```cpp
int getFirstElement(int arr[]) {
    return arr[0];  // Always takes same time
}
// Time: O(1), Space: O(1)
```

#### Variable Assignment
```cpp
void swapTwoNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// Time: O(1), Space: O(1)
```

### 5.2 Linear Time - O(n)

#### Reverse Array
```cpp
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);  // O(1) operation
        start++;
        end--;
    }
}
// Time: O(n) - we visit each element once
// Space: O(1) - only using few variables
```

#### Linear Search
```cpp
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {        // O(n) loop
        if (arr[i] == target) {          // O(1) comparison
            return i;
        }
    }
    return -1;
}
// Best Case: O(1) - found at first position
// Average Case: O(n) - found at middle
// Worst Case: O(n) - found at last or not found
// Space: O(1)
```

#### Sum of Array
```cpp
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {        // O(n) loop
        sum += arr[i];                   // O(1) operation
    }
    return sum;
}
// Time: O(n), Space: O(1)
```

### 5.3 Logarithmic Time - O(log n)

#### Binary Search (Sorted Array)
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {              // O(log n) iterations
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;              // Eliminate left half
        } else {
            right = mid - 1;             // Eliminate right half
        }
    }
    return -1;
}
// Time: O(log n) - we halve the search space each time
// Space: O(1)
```

### 5.4 Quadratic Time - O(n²)

#### Bubble Sort
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // O(n) outer loop
        for (int j = 0; j < n - i - 1; j++) {   // O(n) inner loop
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);       // O(1) operation
            }
        }
    }
}
// Time: O(n²) - nested loops
// Space: O(1)
```

#### Find All Pairs
```cpp
void printAllPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {               // O(n) outer loop
        for (int j = 0; j < n; j++) {           // O(n) inner loop
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
    }
}
// Time: O(n²), Space: O(1)
```

### 5.5 Prime Number Check - O(√n)

#### Optimized Prime Check
```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {      // O(√n) loop
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
// Time: O(√n) - we only check up to square root
// Space: O(1)
```

#### Naive Prime Check
```cpp
bool isPrimeNaive(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i < n; i++) {              // O(n) loop
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// Time: O(n), Space: O(1)
```

### 5.6 Exponential Time - O(2ⁿ)

#### Recursive Fibonacci (Inefficient)
```cpp
int fibonacci(int n) {
    if (n <= 1) {
        return n;                              // Base case
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Two recursive calls
}
// Time: O(2^n) - each call makes 2 more calls
// Space: O(n) - recursion depth
```

#### Fibonacci Optimized (Dynamic Programming)
```cpp
int fibonacciDP(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
// Time: O(n), Space: O(1)
```

## 6. Space Complexity Analysis

### 6.1 Constant Space - O(1)
```cpp
void printSum(int a, int b) {
    int sum = a + b;        // Fixed amount of variables
    cout << sum << endl;
}
// Space: O(1) - no matter the input values
```

### 6.2 Linear Space - O(n)
```cpp
int* createArray(int n) {
    int* arr = new int[n];  // Space grows with input size
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}
// Space: O(n) - array size depends on n
```

### 6.3 Recursive Space - O(n)
```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;           // Base case
    }
    return n * factorial(n - 1); // Recursive call
}
// Space: O(n) - n function calls on call stack
```

## 7. Analyzing Complex Algorithms

### 7.1 Multiple Loops (Sequential)
```cpp
void sequentialLoops(int arr[], int n) {
    // First loop
    for (int i = 0; i < n; i++) {       // O(n)
        cout << arr[i] << " ";
    }
    
    // Second loop
    for (int i = 0; i < n; i++) {       // O(n)
        arr[i] *= 2;
    }
}
// Total Time: O(n) + O(n) = O(n)
```

### 7.2 Nested Loops
```cpp
void nestedLoops(int arr[], int n) {
    for (int i = 0; i < n; i++) {           // O(n)
        for (int j = 0; j < n; j++) {       // O(n)
            cout << arr[i] + arr[j] << " "; // O(1)
        }
    }
}
// Total Time: O(n) × O(n) = O(n²)
```

### 7.3 Loop with Logarithmic Steps
```cpp
void logarithmicLoop(int n) {
    for (int i = 1; i < n; i *= 2) {       // i: 1, 2, 4, 8, 16...
        cout << i << " ";                   // O(1) operation
    }
}
// Time: O(log n) - loop runs log₂(n) times
```

### 7.4 Matrix Operations
```cpp
void matrixMultiplication(int A[][100], int B[][100], int C[][100], int n) {
    for (int i = 0; i < n; i++) {           // O(n)
        for (int j = 0; j < n; j++) {       // O(n)
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {   // O(n)
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
// Time: O(n³) - three nested loops
// Space: O(1) - no extra space (assuming matrices are given)
```

## 8. Best Practices for Analysis

### 8.1 Step-by-Step Analysis
```cpp
void exampleFunction(int arr[], int n) {
    int max = arr[0];                    // O(1) - constant time
    
    for (int i = 1; i < n; i++) {        // O(n) - linear loop
        if (arr[i] > max) {              // O(1) - constant comparison
            max = arr[i];                // O(1) - constant assignment
        }
    }
    
    for (int i = 0; i < n; i++) {        // O(n) - another linear loop
        cout << arr[i] << " ";           // O(1) - constant operation
    }
}

// Analysis:
// Line 2: O(1)
// Lines 4-8: O(n) × O(1) = O(n)
// Lines 10-12: O(n) × O(1) = O(n)
// Total: O(1) + O(n) + O(n) = O(n)
```

### 8.2 Common Mistakes to Avoid
```cpp
// MISTAKE 1: Confusing best/average/worst case
// Linear search is O(1) best case, but we use O(n) for analysis

// MISTAKE 2: Not considering all operations
void inefficientFunction(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Don't forget this is still O(n²) even if body is simple
            }
        }
    }
}

// MISTAKE 3: Ignoring space complexity
int* createLargeArray(int n) {
    return new int[n * n];  // This is O(n²) space, not O(1)!
}
```

## 9. Optimization Techniques

### 9.1 Early Exit Optimization
```cpp
// Unoptimized
bool hasTarget(int arr[], int n, int target) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = true;
        }
    }
    return found;
}

// Optimized with early exit
bool hasTargetOptimized(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return true;  // Early exit
        }
    }
    return false;
}
// Best case changes from O(n) to O(1)
```

### 9.2 Avoiding Redundant Calculations
```cpp
// Unoptimized
void inefficientLoop(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sqrt(n); j++) {  // sqrt(n) calculated n times!
            // some operation
        }
    }
}

// Optimized
void efficientLoop(int arr[], int n) {
    int sqrtN = sqrt(n);  // Calculate once
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sqrtN; j++) {
            // same operation
        }
    }
}
```

## 10. Summary Table

### Time Complexity Summary
| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |

### Decision Guidelines
```
Choose O(1) when: Direct access needed (hash tables, arrays)
Choose O(log n) when: Data is sorted (binary search, heaps)
Choose O(n) when: Must examine each element once
Choose O(n log n) when: Efficient sorting needed
Avoid O(n²) when: n is large (> 10,000)
Avoid O(2ⁿ) when: n > 20
```

## Memory Tips
- **O(1)**: Constant - Same time regardless of input
- **O(log n)**: Logarithmic - Halving problem size each step
- **O(n)**: Linear - One pass through data
- **O(n²)**: Quadratic - Nested loops over same data
- **Big O**: Worst-case upper bound
- **Drop constants and lower terms in Big O**
- **Different inputs use different variables**
- **Space complexity counts extra memory used**