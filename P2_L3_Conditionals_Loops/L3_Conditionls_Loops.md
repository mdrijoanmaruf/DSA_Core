# C++ Conditionals and Loops

## 1. Conditional Statements

### if Statement
Basic conditional execution
```cpp
int age = 18;
if (age >= 18) {
    cout << "You are an adult" << endl;
}

// Single line (no braces needed)
if (age >= 18)
    cout << "Adult" << endl;
```

### if-else Statement
Two-way branching
```cpp
int score = 85;
if (score >= 60) {
    cout << "Pass" << endl;
} else {
    cout << "Fail" << endl;
}
```

### if-else if-else Ladder
Multiple conditions
```cpp
int marks = 88;
if (marks >= 90) {
    cout << "Grade A+" << endl;
} else if (marks >= 80) {
    cout << "Grade A" << endl;
} else if (marks >= 70) {
    cout << "Grade B" << endl;
} else if (marks >= 60) {
    cout << "Grade C" << endl;
} else {
    cout << "Grade F" << endl;
}
```

### Nested if Statements
if inside another if
```cpp
int age = 25;
bool hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        cout << "Can drive" << endl;
    } else {
        cout << "Get a license first" << endl;
    }
} else {
    cout << "Too young to drive" << endl;
}
```

### switch Statement
Multi-way branching based on exact values
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
        cout << "Below Average" << endl;
        break;
    case 'F':
        cout << "Failed" << endl;
        break;
    default:
        cout << "Invalid grade" << endl;
        break;
}
```

### switch with Fall-through
```cpp
int day = 3;
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Weekday" << endl;
        break;
    case 6:
    case 7:
        cout << "Weekend" << endl;
        break;
    default:
        cout << "Invalid day" << endl;
}
```

### Ternary Operator (Conditional Operator)
Short form of if-else
```cpp
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max = 20

string result = (score >= 60) ? "Pass" : "Fail";

// Nested ternary
string grade = (marks >= 80) ? "A" : (marks >= 60) ? "B" : "C";
```

## 2. Loops

### for Loop
Known number of iterations
```cpp
// Basic for loop
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
// Output: 1 2 3 4 5

// Counting backwards
for (int i = 10; i >= 1; i--) {
    cout << i << " ";
}
// Output: 10 9 8 7 6 5 4 3 2 1

// Step by 2
for (int i = 0; i <= 10; i += 2) {
    cout << i << " ";
}
// Output: 0 2 4 6 8 10
```

### for Loop Variations
```cpp
// Multiple variables
for (int i = 0, j = 10; i < j; i++, j--) {
    cout << i << " " << j << endl;
}

// Infinite loop
for (;;) {
    // code here
    break; // exit condition
}

// Empty body
for (int i = 0; i < 5; cout << i++ << " ");
```

### Range-based for Loop (C++11)
Iterate through containers
```cpp
int arr[] = {1, 2, 3, 4, 5};
for (int element : arr) {
    cout << element << " ";
}

string text = "Hello";
for (char ch : text) {
    cout << ch << " ";
}

vector<int> numbers = {10, 20, 30};
for (int num : numbers) {
    cout << num << " ";
}

// Modify elements (use reference)
int values[] = {1, 2, 3, 4, 5};
for (int& val : values) {
    val *= 2;  // doubles each element
}
```

### while Loop
Condition checked before execution
```cpp
int count = 1;
while (count <= 5) {
    cout << count << " ";
    count++;
}
// Output: 1 2 3 4 5

// Input validation
int num;
cout << "Enter positive number: ";
cin >> num;
while (num <= 0) {
    cout << "Invalid! Enter positive number: ";
    cin >> num;
}
```

### do-while Loop
Condition checked after execution (executes at least once)
```cpp
int choice;
do {
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Addition selected" << endl;
            break;
        case 2:
            cout << "Subtraction selected" << endl;
            break;
        case 3:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
} while (choice != 3);
```

### Nested Loops
Loop inside another loop
```cpp
// Multiplication table
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cout << i << " x " << j << " = " << i*j << endl;
    }
    cout << endl;
}

// Pattern printing
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
// Output:
// *
// * *
// * * *
// * * * *
// * * * * *
```

## 3. Loop Control Statements

### break Statement
Exit from loop immediately
```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;  // exits when i = 5
    }
    cout << i << " ";
}
// Output: 1 2 3 4

// In nested loops - breaks inner loop only
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        if (j == 2) break;
        cout << i << j << " ";
    }
}
// Output: 11 21 31
```

### continue Statement
Skip current iteration, go to next
```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;  // skips when i = 3
    }
    cout << i << " ";
}
// Output: 1 2 4 5

// Skip even numbers
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue;
    cout << i << " ";
}
// Output: 1 3 5 7 9
```

### goto Statement (Not recommended)
Jump to labeled statement
```cpp
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
        if (i == 3 && j == 3) {
            goto end;  // jumps out of both loops
        }
        cout << i << j << " ";
    }
}
end:
cout << "End reached" << endl;
```

## 4. Practical Examples

### Find Prime Numbers
```cpp
int num = 17;
bool isPrime = true;

if (num <= 1) {
    isPrime = false;
} else {
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
}

if (isPrime) {
    cout << num << " is prime" << endl;
} else {
    cout << num << " is not prime" << endl;
}
```

### Factorial Calculation
```cpp
int n = 5;
long long factorial = 1;

for (int i = 1; i <= n; i++) {
    factorial *= i;
}
cout << "Factorial of " << n << " = " << factorial << endl;
// Output: Factorial of 5 = 120
```

### Fibonacci Series
```cpp
int n = 10;
int a = 0, b = 1, next;

cout << "Fibonacci Series: ";
cout << a << " " << b << " ";

for (int i = 2; i < n; i++) {
    next = a + b;
    cout << next << " ";
    a = b;
    b = next;
}
// Output: Fibonacci Series: 0 1 1 2 3 5 8 13 21 34
```

### Number Guessing Game
```cpp
int secret = 42;
int guess;
int attempts = 0;

do {
    cout << "Guess the number (1-100): ";
    cin >> guess;
    attempts++;
    
    if (guess > secret) {
        cout << "Too high!" << endl;
    } else if (guess < secret) {
        cout << "Too low!" << endl;
    } else {
        cout << "Correct! You got it in " << attempts << " attempts!" << endl;
    }
} while (guess != secret);
```

## 5. Best Practices

### Loop Optimization
```cpp
// Avoid recalculating in loop condition
vector<int> vec = {1, 2, 3, 4, 5};
int size = vec.size();  // Calculate once
for (int i = 0; i < size; i++) {
    cout << vec[i] << " ";
}

// Use pre-increment for efficiency
for (int i = 0; i < 10; ++i) {  // prefer ++i over i++
    cout << i << " ";
}
```

### Choosing the Right Loop
- **for**: When you know the number of iterations
- **while**: When condition is checked before execution
- **do-while**: When you need at least one execution
- **range-based for**: When iterating through containers

### Common Pitfalls
```cpp
// Infinite loop - missing increment
int i = 0;
while (i < 5) {
    cout << i << " ";
    // i++; // forgot to increment!
}

// Off-by-one errors
for (int i = 1; i <= 10; i++) {  // 1 to 10 (10 iterations)
for (int i = 0; i < 10; i++) {   // 0 to 9 (10 iterations)
for (int i = 0; i <= 10; i++) {  // 0 to 10 (11 iterations)
```

## Memory Tips
- Use `break` to exit loops early
- Use `continue` to skip current iteration
- Prefer range-based for loops for containers
- Initialize loop variables properly
- Be careful with floating-point loop conditions
- Use meaningful variable names for readability