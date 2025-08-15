# C++ Arrays - Complete Guide

## 1. What are Arrays?

### Definition
An array is a collection of elements of the same data type stored in contiguous memory locations. Each element can be accessed using an index.

### Key Characteristics
- **Homogeneous**: All elements must be of the same data type
- **Fixed Size**: Size is determined at compile time
- **Contiguous Memory**: Elements are stored in consecutive memory locations
- **Zero-based Indexing**: First element is at index 0

```cpp
// Array visualization
int arr[5] = {10, 20, 30, 40, 50};

Memory Layout:
Index:   0   1   2   3   4
Value:  10  20  30  40  50
Address: 100 104 108 112 116 (assuming 4 bytes per int)
```

## 2. Array Declaration and Initialization

### Basic Declaration
```cpp
// Syntax: dataType arrayName[size];
int numbers[5];           // Declares array of 5 integers
char letters[10];         // Declares array of 10 characters
double prices[100];       // Declares array of 100 doubles
float grades[30];         // Declares array of 30 floats
```

### Array Initialization

#### Method 1: During Declaration
```cpp
int numbers[5] = {1, 2, 3, 4, 5};
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
double temps[4] = {98.6, 99.1, 97.8, 100.2};
```

#### Method 2: Partial Initialization
```cpp
int arr[5] = {1, 2};  // Only first 2 elements initialized
// Result: {1, 2, 0, 0, 0} - remaining elements are 0
```

#### Method 3: Complete Initialization (Size Inference)
```cpp
int numbers[] = {1, 2, 3, 4, 5};  // Size automatically determined as 5
char name[] = {'J', 'o', 'h', 'n'};  // Size is 4
```

#### Method 4: Zero Initialization
```cpp
int zeros[5] = {0};      // All elements become 0
int allZeros[5] = {};    // All elements become 0 (C++11)
```

#### Method 5: String Initialization
```cpp
char str1[6] = "Hello";     // {'H','e','l','l','o','\0'}
char str2[] = "World";      // Size automatically 6 including '\0'
```

### After Declaration Initialization
```cpp
int arr[3];
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

## 3. Accessing Array Elements

### Using Index Notation
```cpp
int numbers[5] = {10, 20, 30, 40, 50};

// Reading elements
cout << numbers[0] << endl;  // Output: 10
cout << numbers[2] << endl;  // Output: 30
cout << numbers[4] << endl;  // Output: 50

// Modifying elements
numbers[1] = 25;  // Changes second element to 25
numbers[3] = 45;  // Changes fourth element to 45
```

### Array Traversal
```cpp
int arr[5] = {1, 2, 3, 4, 5};

// Method 1: Traditional for loop
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}

// Method 2: Range-based for loop (C++11)
for (int element : arr) {
    cout << element << " ";
}

// Method 3: Using sizeof to get size
int size = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
```

## 4. Array Operations

### Finding Array Size
```cpp
int arr[10] = {1, 2, 3, 4, 5};

// Method 1: Using sizeof (only works for static arrays)
int size = sizeof(arr) / sizeof(arr[0]);
cout << "Array size: " << size << endl;  // Output: 10

// Method 2: Manual tracking
const int ARRAY_SIZE = 10;
int arr2[ARRAY_SIZE];
```

### Finding Maximum Element
```cpp
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Usage
int numbers[5] = {23, 67, 34, 89, 12};
int maximum = findMax(numbers, 5);
cout << "Maximum: " << maximum << endl;  // Output: 89
```

### Finding Minimum Element
```cpp
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
```

### Sum of Array Elements
```cpp
int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Usage
int numbers[5] = {10, 20, 30, 40, 50};
int total = calculateSum(numbers, 5);
cout << "Sum: " << total << endl;  // Output: 150
```

### Average of Array Elements
```cpp
double calculateAverage(int arr[], int size) {
    int sum = calculateSum(arr, size);
    return (double)sum / size;
}

// Usage
double avg = calculateAverage(numbers, 5);
cout << "Average: " << avg << endl;  // Output: 30
```

## 5. Searching in Arrays

### Linear Search
```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Usage
int numbers[6] = {64, 34, 25, 12, 22, 11};
int index = linearSearch(numbers, 6, 25);
if (index != -1) {
    cout << "Element found at index: " << index << endl;
} else {
    cout << "Element not found" << endl;
}
```

### Binary Search (For Sorted Arrays)
```cpp
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}

// Usage (array must be sorted)
int sortedArr[6] = {11, 12, 22, 25, 34, 64};
int index = binarySearch(sortedArr, 6, 25);
```

## 6. Sorting Arrays

### Bubble Sort
```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Usage
int numbers[5] = {64, 34, 25, 12, 22};
bubbleSort(numbers, 5);
// Result: {12, 22, 25, 34, 64}
```

### Selection Sort
```cpp
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in remaining array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap minimum element with first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
```

### Insertion Sort
```cpp
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
```

## 7. Arrays and Functions

### Passing Arrays to Functions
```cpp
// Arrays are passed by reference (pointer to first element)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Alternative syntax (equivalent)
void printArray2(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Modifying array elements in function
void doubleElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Original array is modified
    }
}
```

### Returning Arrays from Functions
```cpp
// Cannot return array directly, use pointers or dynamic allocation
int* createArray(int size) {
    int* arr = new int[size];  // Dynamic allocation
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

// Better approach: pass array as parameter
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}
```

## 8. Multi-dimensional Arrays

### 2D Arrays Declaration
```cpp
// Syntax: dataType arrayName[rows][columns];
int matrix[3][4];        // 3 rows, 4 columns
int table[2][3];         // 2 rows, 3 columns
```

### 2D Array Initialization
```cpp
// Method 1: Row-wise initialization
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Method 2: Linear initialization
int matrix2[2][3] = {1, 2, 3, 4, 5, 6};
// Result:
// Row 0: {1, 2, 3}
// Row 1: {4, 5, 6}

// Method 3: Partial initialization
int matrix3[2][3] = {{1, 2}, {4}};
// Result:
// Row 0: {1, 2, 0}
// Row 1: {4, 0, 0}
```

### Accessing 2D Array Elements
```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Reading elements
cout << matrix[0][0] << endl;  // Output: 1
cout << matrix[1][2] << endl;  // Output: 6
cout << matrix[2][1] << endl;  // Output: 8

// Modifying elements
matrix[0][1] = 10;  // Changes element at row 0, column 1
```

### 2D Array Traversal
```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Nested loops for traversal
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}

// Range-based for loop (C++11)
for (auto& row : matrix) {
    for (auto& element : row) {
        cout << element << " ";
    }
    cout << endl;
}
```

### 3D Arrays
```cpp
// Declaration
int cube[2][3][4];  // 2 layers, 3 rows, 4 columns per layer

// Initialization
int cube2[2][2][2] = {
    {
        {1, 2},
        {3, 4}
    },
    {
        {5, 6},
        {7, 8}
    }
};

// Accessing elements
cout << cube2[1][0][1] << endl;  // Output: 6
```

## 9. Character Arrays (C-Strings)

### Declaration and Initialization
```cpp
// Method 1: Character by character
char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// Method 2: String literal
char greeting[] = "Hello";  // Automatically adds '\0'

// Method 3: Fixed size with string
char message[20] = "Welcome";  // Remaining spaces filled with '\0'
```

### String Operations
```cpp
#include <cstring>  // Required for string functions

char str1[20] = "Hello";
char str2[20] = "World";
char result[40];

// String length
int len = strlen(str1);  // Returns 5

// String copy
strcpy(result, str1);    // result = "Hello"

// String concatenation
strcat(result, " ");     // result = "Hello "
strcat(result, str2);    // result = "Hello World"

// String comparison
int cmp = strcmp(str1, str2);  // Returns negative, 0, or positive
```

### Input/Output with Character Arrays
```cpp
char name[50];

// Input (stops at whitespace)
cout << "Enter your name: ";
cin >> name;

// Input (reads entire line including spaces)
cout << "Enter full name: ";
cin.getline(name, 50);

// Output
cout << "Hello, " << name << endl;
```

## 10. Common Array Problems and Solutions

### Reverse an Array
```cpp
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

// Usage
int numbers[5] = {1, 2, 3, 4, 5};
reverseArray(numbers, 5);
// Result: {5, 4, 3, 2, 1}
```

### Find Duplicate Elements
```cpp
void findDuplicates(int arr[], int size) {
    cout << "Duplicate elements: ";
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;  // Found duplicate, move to next element
            }
        }
    }
    cout << endl;
}
```

### Remove Duplicates (In-place)
```cpp
int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;
    
    int uniqueIndex = 0;
    
    for (int i = 1; i < size; i++) {
        bool isDuplicate = false;
        
        // Check if current element is duplicate
        for (int j = 0; j <= uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        
        // If not duplicate, add to unique section
        if (!isDuplicate) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    
    return uniqueIndex + 1;  // Return new size
}
```

### Rotate Array
```cpp
void rotateLeft(int arr[], int size, int positions) {
    positions = positions % size;  // Handle positions > size
    
    // Store first 'positions' elements
    int temp[positions];
    for (int i = 0; i < positions; i++) {
        temp[i] = arr[i];
    }
    
    // Shift remaining elements left
    for (int i = 0; i < size - positions; i++) {
        arr[i] = arr[i + positions];
    }
    
    // Place stored elements at the end
    for (int i = 0; i < positions; i++) {
        arr[size - positions + i] = temp[i];
    }
}

void rotateRight(int arr[], int size, int positions) {
    positions = positions % size;
    
    // Store last 'positions' elements
    int temp[positions];
    for (int i = 0; i < positions; i++) {
        temp[i] = arr[size - positions + i];
    }
    
    // Shift remaining elements right
    for (int i = size - 1; i >= positions; i--) {
        arr[i] = arr[i - positions];
    }
    
    // Place stored elements at the beginning
    for (int i = 0; i < positions; i++) {
        arr[i] = temp[i];
    }
}
```

### Merge Two Sorted Arrays
```cpp
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge elements in sorted order
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    // Copy remaining elements from arr1
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    // Copy remaining elements from arr2
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}
```

## 11. Dynamic Arrays (Introduction)

### Problems with Static Arrays
- Fixed size at compile time
- Cannot change size during runtime
- Memory allocated on stack (limited)

### Dynamic Arrays using Pointers
```cpp
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    // Allocate memory dynamically
    int* arr = new int[size];
    
    // Input elements
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
    
    // Display elements
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Free allocated memory
    delete[] arr;
    
    return 0;
}
```

## 12. Array Limitations and Best Practices

### Limitations
- **Fixed Size**: Cannot change size after declaration
- **No Bounds Checking**: Accessing out-of-bounds elements causes undefined behavior
- **Memory Management**: Manual memory management for dynamic arrays
- **Limited Functionality**: No built-in methods like size(), push_back(), etc.

### Best Practices
```cpp
// 1. Always initialize arrays
int arr[5] = {0};  // Initialize all to 0

// 2. Use constants for array sizes
const int MAX_SIZE = 100;
int numbers[MAX_SIZE];

// 3. Validate array bounds
bool isValidIndex(int index, int size) {
    return (index >= 0 && index < size);
}

// 4. Use meaningful variable names
int studentGrades[30];  // Better than arr[30]

// 5. Pass size as parameter to functions
void processArray(int arr[], int size) {
    // Use size parameter, don't assume
}

// 6. Consider using std::vector for dynamic needs
#include <vector>
vector<int> dynamicArray;  // Can grow/shrink as needed
```

### Common Mistakes to Avoid
```cpp
// 1. Array out of bounds
int arr[5];
arr[5] = 10;  // ERROR: Index 5 is out of bounds (valid: 0-4)

// 2. Forgetting null terminator in strings
char str[6] = {'H', 'e', 'l', 'l', 'o'};  // Missing '\0'

// 3. Using array name as lvalue
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
arr2 = arr1;  // ERROR: Cannot assign arrays directly

// 4. Memory leaks with dynamic arrays
int* arr = new int[100];
// ... use array ...
// delete[] arr;  // Don't forget to free memory!
```

## 13. Complete Example Program

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class ArrayOperations {
private:
    static const int MAX_SIZE = 100;
    
public:
    // Display array
    static void displayArray(int arr[], int size) {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Input array elements
    static void inputArray(int arr[], int& size) {
        cout << "Enter array size: ";
        cin >> size;
        
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    
    // Find statistics
    static void findStatistics(int arr[], int size) {
        int sum = 0, max = arr[0], min = arr[0];
        
        for (int i = 0; i < size; i++) {
            sum += arr[i];
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }
        
        cout << "Sum: " << sum << endl;
        cout << "Average: " << (double)sum / size << endl;
        cout << "Maximum: " << max << endl;
        cout << "Minimum: " << min << endl;
    }
    
    // Search element
    static void searchElement(int arr[], int size) {
        int target;
        cout << "Enter element to search: ";
        cin >> target;
        
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found" << endl;
    }
};

int main() {
    int arr[100];
    int size;
    int choice;
    
    do {
        cout << "\n=== Array Operations Menu ===" << endl;
        cout << "1. Input Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Find Statistics" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                ArrayOperations::inputArray(arr, size);
                break;
            case 2:
                ArrayOperations::displayArray(arr, size);
                break;
            case 3:
                ArrayOperations::findStatistics(arr, size);
                break;
            case 4:
                ArrayOperations::searchElement(arr, size);
                break;
            case 5:
                cout << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    
    return 0;
}
```

## Memory Tips
- **Array indexing starts from 0**
- **Array size is fixed at compile time**
- **Arrays are passed by reference to functions**
- **Use sizeof(arr)/sizeof(arr[0]) to find size of static arrays**
- **Always check bounds to avoid segmentation faults**
- **String arrays need null terminator '\0'**
- **2D arrays: array[row][column]**
- **Initialize arrays to avoid garbage values**