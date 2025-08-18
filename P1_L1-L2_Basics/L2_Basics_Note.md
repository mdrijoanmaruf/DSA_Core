# C++ Quick Notes

## 1. Data Types and Variables

### Basic Data Types
- **int**: Integer numbers (4 bytes)
  ```cpp
  int age = 25;
  int temperature = -10;
  ```

- **float**: Single precision decimal (4 bytes)
  ```cpp
  float price = 99.99f;
  float pi = 3.14f;
  ```

- **double**: Double precision decimal (8 bytes)
  ```cpp
  double precise = 3.14159265359;
  double salary = 50000.75;
  ```

- **char**: Single character (1 byte)
  ```cpp
  char grade = 'A';
  char symbol = '$';
  ```

- **bool**: Boolean true/false (1 byte)
  ```cpp
  bool isActive = true;
  bool isComplete = false;
  ```

- **string**: Text (variable size)
  ```cpp
  string name = "Rijoan";
  string message = "Hello World!";
  ```

### Variable Declaration
```cpp
dataType variableName = value;
int count = 0;
const int MAX_SIZE = 100; // constant
```

## 2. How Data is Stored

### Memory Layout
- **Stack**: Local variables, function parameters
- **Heap**: Dynamic memory allocation
- **Data Segment**: Global/static variables
- **Code Segment**: Program instructions

### Byte Organization
```cpp
int num = 305419896;  // 4 bytes: 0x12345678
// Memory: [78][56][34][12] (little-endian)

char arr[4] = {'A', 'B', 'C', 'D'};
// Memory: [A][B][C][D]
```

## 3. Type Casting

### Implicit Casting (Automatic)
```cpp
int a = 10;
double b = a;    // int → double (safe)
float c = 3.14;
int d = c;       // float → int (data loss: d = 3)
```

### Explicit Casting
```cpp
// C-style casting
int x = (int)3.14;        // x = 3

// C++-style casting
double pi = 3.14159;
int whole = static_cast<int>(pi);  // whole = 3

// Other casting types
const_cast<int&>(constVar);        // Remove const
reinterpret_cast<int*>(&floatVar); // Raw memory reinterpret
```

## 4. How Negative Numbers are Stored

### Two's Complement System
- **Positive**: Normal binary representation
- **Negative**: Flip all bits + add 1

```cpp
// 8-bit example:
int8_t positive = 5;   // 00000101
int8_t negative = -5;  // 11111011

// Process for -5:
// Step 1: +5 = 00000101
// Step 2: Flip bits = 11111010
// Step 3: Add 1 = 11111011 = -5
```

### Range Examples
```cpp
// 8-bit signed: -128 to +127
// 16-bit signed: -32,768 to +32,767
// 32-bit signed: -2,147,483,648 to +2,147,483,647

signed char a = -128;    // Minimum value
unsigned char b = 255;   // Maximum for unsigned
```

## 5. Operators

### Arithmetic Operators
```cpp
int a = 10, b = 3;
int sum = a + b;      // Addition: 13
int diff = a - b;     // Subtraction: 7
int product = a * b;  // Multiplication: 30
int quotient = a / b; // Division: 3 (integer division)
int remainder = a % b; // Modulus: 1
```

### Assignment Operators
```cpp
int x = 5;
x += 3;  // x = x + 3 = 8
x -= 2;  // x = x - 2 = 6
x *= 4;  // x = x * 4 = 24
x /= 3;  // x = x / 3 = 8
x %= 3;  // x = x % 3 = 2
```

### Comparison Operators
```cpp
int a = 5, b = 10;
bool result;
result = (a == b);  // Equal: false
result = (a != b);  // Not equal: true
result = (a < b);   // Less than: true
result = (a > b);   // Greater than: false
result = (a <= b);  // Less or equal: true
result = (a >= b);  // Greater or equal: false
```

### Logical Operators
```cpp
bool p = true, q = false;
bool result;
result = p && q;  // AND: false
result = p || q;  // OR: true
result = !p;      // NOT: false
```

### Bitwise Operators
```cpp
int a = 5;  // 101 in binary
int b = 3;  // 011 in binary

int result;
result = a & b;   // AND: 001 = 1
result = a | b;   // OR: 111 = 7
result = a ^ b;   // XOR: 110 = 6
result = ~a;      // NOT: ...11111010 = -6
result = a << 1;  // Left shift: 1010 = 10
result = a >> 1;  // Right shift: 10 = 2
```

### Increment/Decrement
```cpp
int x = 5;
int pre = ++x;   // Pre-increment: x=6, pre=6
int post = x++;  // Post-increment: post=6, x=7

int y = 5;
int pre_dec = --y;   // Pre-decrement: y=4, pre_dec=4
int post_dec = y--;  // Post-decrement: post_dec=4, y=3
```

### Ternary Operator
```cpp
int a = 10, b = 20;
int max = (a > b) ? a : b;  // max = 20

string grade = (score >= 60) ? "Pass" : "Fail";
```

### Special Operators
```cpp
// sizeof operator
int size = sizeof(int);        // Returns 4 (bytes)
int arr[10];
int arrSize = sizeof(arr);     // Returns 40 (10 * 4 bytes)

// Address operator (&) and Pointer operator (*)
int num = 42;
int* ptr = &num;    // ptr stores address of num
int value = *ptr;   // value = 42 (dereference ptr)
```

## Memory Tips
- Always initialize variables before use
- Be careful with type casting to avoid data loss
- Use `const` for values that shouldn't change
- Understand operator precedence: `*` `/` before `+` `-`
- Use parentheses for clarity: `(a + b) * c`