# C++ Bitwise Operators

## Overview
Bitwise operators work on bits (0s and 1s) and perform bit-by-bit operations.

## 1. Bitwise AND (&)
Returns 1 only if both bits are 1, otherwise 0.

### Truth Table
```
A | B | A & B
0 | 0 |   0
0 | 1 |   0
1 | 0 |   0
1 | 1 |   1
```

### Examples
```cpp
int a = 5;    // 101 in binary
int b = 3;    // 011 in binary
int result = a & b;  // 001 = 1

cout << "5 & 3 = " << result << endl;  // Output: 1

// Step by step:
//   101 (5)
// & 011 (3)
// -------
//   001 (1)
```

### Practical Uses
```cpp
// Check if number is even or odd
int num = 15;
if (num & 1) {
    cout << "Odd" << endl;
} else {
    cout << "Even" << endl;
}

// Extract specific bits (masking)
int data = 0b11010110;
int mask = 0b00001111;  // Extract last 4 bits
int lastFourBits = data & mask;  // Result: 0110 = 6
```

## 2. Bitwise OR (|)
Returns 1 if at least one bit is 1, otherwise 0.

### Truth Table
```
A | B | A | B
0 | 0 |   0
0 | 1 |   1
1 | 0 |   1
1 | 1 |   1
```

### Examples
```cpp
int a = 5;    // 101 in binary
int b = 3;    // 011 in binary
int result = a | b;  // 111 = 7

cout << "5 | 3 = " << result << endl;  // Output: 7

// Step by step:
//   101 (5)
// | 011 (3)
// -------
//   111 (7)
```

### Practical Uses
```cpp
// Set specific bits
int flags = 0b00000000;
int readFlag = 0b00000001;
int writeFlag = 0b00000010;

flags = flags | readFlag;   // Set read permission
flags = flags | writeFlag;  // Set write permission
// flags = 0b00000011
```

## 3. Bitwise NOT (~)
Flips all bits: 0 becomes 1, 1 becomes 0.

### Examples
```cpp
int a = 5;        // 00000101 (8-bit representation)
int result = ~a;  // 11111010 = -6 (in two's complement)

cout << "~5 = " << result << endl;  // Output: -6

// For unsigned:
unsigned char b = 5;    // 00000101
unsigned char res = ~b; // 11111010 = 250
cout << "~5 (unsigned) = " << (int)res << endl;  // Output: 250
```

### Practical Uses
```cpp
// Clear specific bits
int data = 0b11111111;
int mask = 0b00001111;
int cleared = data & (~mask);  // Clear last 4 bits
// Result: 0b11110000
```

## 4. Bitwise XOR (^) - Exclusive OR
Returns 1 if bits are different, 0 if bits are same.

### Truth Table
```
A | B | A ^ B
0 | 0 |   0
0 | 1 |   1
1 | 0 |   1
1 | 1 |   0
```

### Examples
```cpp
int a = 5;    // 101 in binary
int b = 3;    // 011 in binary
int result = a ^ b;  // 110 = 6

cout << "5 ^ 3 = " << result << endl;  // Output: 6

// Step by step:
//   101 (5)
// ^ 011 (3)
// -------
//   110 (6)
```

### Practical Uses
```cpp
// Swap two numbers without temporary variable
int x = 10, y = 20;
cout << "Before: x=" << x << ", y=" << y << endl;

x = x ^ y;  // x = 10 ^ 20
y = x ^ y;  // y = (10 ^ 20) ^ 20 = 10
x = x ^ y;  // x = (10 ^ 20) ^ 10 = 20

cout << "After: x=" << x << ", y=" << y << endl;

// Toggle specific bits
int flags = 0b00001010;
int toggleMask = 0b00000101;
flags = flags ^ toggleMask;  // Result: 0b00001111
```

## 5. Left Shift (<<)
Shifts bits to the left, fills with 0s from right.

### Examples
```cpp
int a = 5;        // 101 in binary
int result = a << 1;  // 1010 = 10

cout << "5 << 1 = " << result << endl;  // Output: 10

int b = 3;        // 011 in binary
int result2 = b << 2;  // 1100 = 12

cout << "3 << 2 = " << result2 << endl;  // Output: 12
```

### Mathematical Relation
```cpp
// Left shift by n positions = multiply by 2^n
int num = 7;
cout << num << " << 1 = " << (num << 1) << " (7 * 2^1 = 14)" << endl;
cout << num << " << 2 = " << (num << 2) << " (7 * 2^2 = 28)" << endl;
cout << num << " << 3 = " << (num << 3) << " (7 * 2^3 = 56)" << endl;
```

### Practical Uses
```cpp
// Fast multiplication by powers of 2
int fastMultiply(int num, int power) {
    return num << power;
}

cout << "8 * 4 = " << fastMultiply(8, 2) << endl;  // 8 << 2 = 32
cout << "5 * 8 = " << fastMultiply(5, 3) << endl;  // 5 << 3 = 40
```

## 6. Right Shift (>>)
Shifts bits to the right, behavior depends on sign.

### Examples
```cpp
int a = 20;       // 10100 in binary
int result = a >> 1;  // 01010 = 10

cout << "20 >> 1 = " << result << endl;  // Output: 10

int b = 12;       // 1100 in binary
int result2 = b >> 2;  // 0011 = 3

cout << "12 >> 2 = " << result2 << endl;  // Output: 3
```

### Mathematical Relation
```cpp
// Right shift by n positions = divide by 2^n (for positive numbers)
int num = 64;
cout << num << " >> 1 = " << (num >> 1) << " (64 / 2^1 = 32)" << endl;
cout << num << " >> 2 = " << (num >> 2) << " (64 / 2^2 = 16)" << endl;
cout << num << " >> 3 = " << (num >> 3) << " (64 / 2^3 = 8)" << endl;
```

### Signed vs Unsigned Right Shift
```cpp
// Positive number
int positive = 8;     // 00001000
int result1 = positive >> 2;  // 00000010 = 2

// Negative number (sign extension)
int negative = -8;    // 11111000 (in two's complement)
int result2 = negative >> 2;  // 11111110 = -2

// Unsigned (logical shift)
unsigned int unsignedNum = 8;
unsigned int result3 = unsignedNum >> 2;  // Always fills with 0s
```

## 7. Compound Assignment Operators

### Examples
```cpp
int a = 12;  // 1100 in binary

a &= 10;     // a = a & 10, a = 8 (1000)
a |= 5;      // a = a | 5, a = 13 (1101)
a ^= 7;      // a = a ^ 7, a = 10 (1010)
a <<= 2;     // a = a << 2, a = 40 (101000)
a >>= 1;     // a = a >> 1, a = 20 (10100)
```

## 8. Advanced Applications

### Check if Power of 2
```cpp
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

cout << isPowerOfTwo(8) << endl;   // 1 (true)
cout << isPowerOfTwo(10) << endl;  // 0 (false)

// Explanation: Powers of 2 have only one bit set
// 8 = 1000, 8-1 = 0111, 1000 & 0111 = 0000
```

### Count Set Bits (1s)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);  // Remove rightmost set bit
    }
    return count;
}

cout << "Set bits in 15: " << countSetBits(15) << endl;  // 4
// 15 = 1111, has 4 set bits
```

### Find Missing Number
```cpp
// Array contains numbers 1 to n except one missing
int findMissing(vector<int>& arr, int n) {
    int xorAll = 0, xorArr = 0;
    
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }
    
    // XOR all array elements
    for (int num : arr) {
        xorArr ^= num;
    }
    
    return xorAll ^ xorArr;  // Missing number
}
```

### Set, Clear, Toggle Specific Bit
```cpp
class BitManipulation {
public:
    // Set bit at position pos (0-indexed from right)
    static int setBit(int num, int pos) {
        return num | (1 << pos);
    }
    
    // Clear bit at position pos
    static int clearBit(int num, int pos) {
        return num & (~(1 << pos));
    }
    
    // Toggle bit at position pos
    static int toggleBit(int num, int pos) {
        return num ^ (1 << pos);
    }
    
    // Check if bit at position pos is set
    static bool checkBit(int num, int pos) {
        return (num & (1 << pos)) != 0;
    }
};

// Usage
int num = 5;  // 101
cout << "Original: " << num << endl;
cout << "Set bit 1: " << BitManipulation::setBit(num, 1) << endl;     // 111 = 7
cout << "Clear bit 2: " << BitManipulation::clearBit(num, 2) << endl; // 001 = 1
cout << "Toggle bit 0: " << BitManipulation::toggleBit(num, 0) << endl; // 100 = 4
```

## 9. Performance Tips

### Fast Operations
```cpp
// Instead of: num * 8
int fastMult8 = num << 3;

// Instead of: num / 4
int fastDiv4 = num >> 2;

// Instead of: num % 8 (for positive numbers)
int fastMod8 = num & 7;

// Check if even: num % 2 == 0
bool isEven = (num & 1) == 0;
```

## Memory Tips
- **&**: AND - Both bits must be 1
- **|**: OR - At least one bit must be 1  
- **^**: XOR - Bits must be different
- **~**: NOT - Flips all bits
- **<<**: Left shift - Multiply by 2^n
- **>>**: Right shift - Divide by 2^n
- Use bitwise operations for flags and efficient calculations
- Remember: XOR with same number gives 0, XOR with 0 gives original number