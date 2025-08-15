# C++ Switch Case and Functions

## 1. Switch Case Statement

### Basic Syntax
```cpp
switch (expression) {
    case constant1:
        // statements
        break;
    case constant2:
        // statements
        break;
    default:
        // default statements
        break;
}
```

### Simple Example
```cpp
int choice = 2;
switch (choice) {
    case 1:
        cout << "Option 1 selected" << endl;
        break;
    case 2:
        cout << "Option 2 selected" << endl;
        break;
    case 3:
        cout << "Option 3 selected" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
}
// Output: Option 2 selected
```

### Character Switch
```cpp
char grade = 'B';
switch (grade) {
    case 'A':
        cout << "Excellent!" << endl;
        break;
    case 'B':
        cout << "Good!" << endl;
        break;
    case 'C':
        cout << "Average" << endl;
        break;
    case 'D':
    case 'F':
        cout << "Need improvement" << endl;
        break;
    default:
        cout << "Invalid grade" << endl;
        break;
}
```

## 2. Switch Case Control Statements

### break Statement
Exits the switch block immediately after executing a case.

```cpp
int num = 2;
switch (num) {
    case 1:
        cout << "One" << endl;
        break;  // Exits switch
    case 2:
        cout << "Two" << endl;
        break;  // Exits switch
    case 3:
        cout << "Three" << endl;
        break;  // Exits switch
}
// Output: Two
```

### Without break (Fall-through)
```cpp
int num = 2;
switch (num) {
    case 1:
        cout << "One" << endl;
        // No break - continues to next case
    case 2:
        cout << "Two" << endl;
        // No break - continues to next case
    case 3:
        cout << "Three" << endl;
        break;
}
// Output: Two
//         Three
```

### continue Statement
Used inside loops within switch cases.

```cpp
for (int i = 1; i <= 5; i++) {
    switch (i) {
        case 2:
        case 4:
            continue;  // Skip current iteration
        default:
            cout << i << " ";
    }
}
// Output: 1 3 5
```

### exit() Function
Terminates the entire program immediately.

```cpp
#include <cstdlib>  // Required for exit()

int choice;
cout << "Enter choice (1-3): ";
cin >> choice;

switch (choice) {
    case 1:
        cout << "Processing..." << endl;
        break;
    case 2:
        cout << "Saving and exiting..." << endl;
        exit(0);  // Terminates program with status 0
    case 3:
        cout << "Cancelled" << endl;
        break;
    default:
        cout << "Invalid choice. Exiting..." << endl;
        exit(1);  // Terminates program with error status
}

cout << "This won't execute if exit() was called" << endl;
```

### Advanced Switch Examples
```cpp
// Calculator using switch
char op;
double num1, num2;

cout << "Enter operator (+, -, *, /): ";
cin >> op;
cout << "Enter two numbers: ";
cin >> num1 >> num2;

switch (op) {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 != 0) {
            cout << "Result: " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero!" << endl;
            exit(1);
        }
        break;
    default:
        cout << "Invalid operator!" << endl;
        break;
}
```

## 3. Functions

### Function Declaration and Definition
```cpp
// Function declaration (prototype)
int add(int a, int b);

// Function definition
int add(int a, int b) {
    return a + b;
}

// Function call
int result = add(5, 3);  // result = 8
```

### Function Components
```cpp
// Return type | Function name | Parameters
int            calculateSum    (int x, int y) {
    int sum = x + y;
    return sum;  // Return statement
}
```

### Types of Functions

#### 1. Functions with Return Value
```cpp
int multiply(int x, int y) {
    return x * y;
}

double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

bool isEven(int num) {
    return (num % 2 == 0);
}
```

#### 2. Void Functions (No Return Value)
```cpp
void printMessage() {
    cout << "Hello, World!" << endl;
}

void displayMenu() {
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Exit" << endl;
}

void greetUser(string name) {
    cout << "Welcome, " << name << "!" << endl;
}
```

#### 3. Functions with Default Parameters
```cpp
void greet(string name = "User", string greeting = "Hello") {
    cout << greeting << ", " << name << "!" << endl;
}

// Function calls
greet();                    // Hello, User!
greet("Alice");             // Hello, Alice!
greet("Bob", "Hi");         // Hi, Bob!
```

#### 4. Function Overloading
```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

// Usage
int result1 = add(5, 3);        // Calls int version
double result2 = add(5.5, 3.2); // Calls double version
int result3 = add(1, 2, 3);     // Calls three-parameter version
```

## 4. Function Call Stack

### How Function Calls Work
The call stack is a data structure that keeps track of function calls in a program.

```cpp
void functionC() {
    cout << "Inside function C" << endl;
    // Function C returns
}

void functionB() {
    cout << "Inside function B" << endl;
    functionC();  // Call function C
    cout << "Back in function B" << endl;
}

void functionA() {
    cout << "Inside function A" << endl;
    functionB();  // Call function B
    cout << "Back in function A" << endl;
}

int main() {
    cout << "Starting main" << endl;
    functionA();  // Call function A
    cout << "Back in main" << endl;
    return 0;
}
```

### Call Stack Visualization
```
Stack Growth:
1. main() pushed
2. functionA() pushed
3. functionB() pushed  
4. functionC() pushed

Stack Shrinking:
4. functionC() popped (returns)
3. functionB() popped (returns)
2. functionA() popped (returns)
1. main() popped (program ends)

Output:
Starting main
Inside function A
Inside function B
Inside function C
Back in function B
Back in function A
Back in main
```

### Stack Frame Contents
Each function call creates a stack frame containing:
- Local variables
- Parameters
- Return address
- Return value

```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Call: factorial(4)
// Stack frames:
// factorial(4) -> calls factorial(3)
// factorial(3) -> calls factorial(2)  
// factorial(2) -> calls factorial(1)
// factorial(1) -> returns 1
// factorial(2) -> returns 2*1 = 2
// factorial(3) -> returns 3*2 = 6
// factorial(4) -> returns 4*6 = 24
```

## 5. Pass by Value

### Concept
A copy of the actual parameter's value is passed to the function. Changes made to the parameter inside the function don't affect the original variable.

```cpp
void modifyValue(int x) {
    x = 100;  // Only modifies the copy
    cout << "Inside function: x = " << x << endl;
}

int main() {
    int num = 5;
    cout << "Before function call: num = " << num << endl;
    
    modifyValue(num);  // Pass by value
    
    cout << "After function call: num = " << num << endl;
    return 0;
}

// Output:
// Before function call: num = 5
// Inside function: x = 100
// After function call: num = 5  (unchanged)
```

### Array Pass by Value (Special Case)
```cpp
void modifyArray(int arr[], int size) {
    arr[0] = 999;  // This WILL modify the original array
    cout << "Inside function: arr[0] = " << arr[0] << endl;
}

int main() {
    int numbers[3] = {1, 2, 3};
    cout << "Before: numbers[0] = " << numbers[0] << endl;
    
    modifyArray(numbers, 3);  // Array name is a pointer
    
    cout << "After: numbers[0] = " << numbers[0] << endl;
    return 0;
}

// Output:
// Before: numbers[0] = 1
// Inside function: arr[0] = 999
// After: numbers[0] = 999  (changed!)
```

## 6. Pass by Reference

### Using Reference Parameters (&)
The function receives a reference (alias) to the original variable. Changes affect the original variable.

```cpp
void modifyByReference(int& x) {
    x = 100;  // Modifies the original variable
    cout << "Inside function: x = " << x << endl;
}

int main() {
    int num = 5;
    cout << "Before function call: num = " << num << endl;
    
    modifyByReference(num);  // Pass by reference
    
    cout << "After function call: num = " << num << endl;
    return 0;
}

// Output:
// Before function call: num = 5
// Inside function: x = 100
// After function call: num = 100  (changed!)
```

### Swap Function Example
```cpp
// Pass by value - DOESN'T work for swapping
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // Only swaps the copies
}

// Pass by reference - WORKS for swapping
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    // Swaps the original variables
}

int main() {
    int x = 10, y = 20;
    
    cout << "Original: x = " << x << ", y = " << y << endl;
    
    swapByValue(x, y);
    cout << "After swapByValue: x = " << x << ", y = " << y << endl;
    
    swapByReference(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;
    
    return 0;
}

// Output:
// Original: x = 10, y = 20
// After swapByValue: x = 10, y = 20      (unchanged)
// After swapByReference: x = 20, y = 10  (swapped)
```

### Pass by Pointer
Alternative way to modify original variables using pointers.

```cpp
void modifyByPointer(int* x) {
    *x = 100;  // Dereference pointer to modify original
    cout << "Inside function: *x = " << *x << endl;
}

void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num = 5;
    cout << "Before: num = " << num << endl;
    
    modifyByPointer(&num);  // Pass address of num
    
    cout << "After: num = " << num << endl;
    
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    
    swapByPointer(&x, &y);
    
    cout << "After swap: x = " << x << ", y = " << y << endl;
    
    return 0;
}
```

## 7. Practical Examples

### Complete Calculator with Functions
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

// Function declarations
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void getNumbers(double& num1, double& num2);

int main() {
    int choice;
    double num1, num2, result;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                getNumbers(num1, num2);
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
                
            case 2:
                getNumbers(num1, num2);
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
                
            case 3:
                getNumbers(num1, num2);
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
                
            case 4:
                getNumbers(num1, num2);
                result = divide(num1, num2);
                if (result != -1) {  // Check for division by zero
                    cout << "Result: " << result << endl;
                }
                break;
                
            case 5:
                cout << "Thank you for using the calculator!" << endl;
                exit(0);
                
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 5);
    
    return 0;
}

// Function definitions
void displayMenu() {
    cout << "=== CALCULATOR ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return -1;  // Error indicator
    }
    return a / b;
}

void getNumbers(double& num1, double& num2) {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}
```

### Factorial with Different Approaches
```cpp
// Iterative approach
int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive approach
int factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

// Pass by reference to avoid return
void factorialByReference(int n, int& result) {
    result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
}
```

## 8. Best Practices

### Function Design Principles
```cpp
// Good: Single responsibility
int calculateSquare(int num) {
    return num * num;
}

// Good: Descriptive names
bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Good: Input validation
double safeDivide(double dividend, double divisor) {
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return dividend / divisor;
}
```

### When to Use Each Passing Method
```cpp
// Pass by value: When you don't want to modify original
int getAbsolute(int num) {
    return (num < 0) ? -num : num;
}

// Pass by reference: When you want to modify original
void makePositive(int& num) {
    if (num < 0) num = -num;
}

// Pass by const reference: Large objects, no modification
void displayVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
}
```

## Memory Tips
- **Switch**: Must use constant expressions in cases
- **break**: Exits switch immediately
- **continue**: Used in loops within switch
- **exit()**: Terminates entire program
- **Pass by value**: Creates copy, original unchanged
- **Pass by reference (&)**: Direct access to original variable
- **Call stack**: LIFO (Last In, First Out) structure
- **Function overloading**: Same name, different parameters