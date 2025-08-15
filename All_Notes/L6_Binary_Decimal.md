# Binary and Decimal Number Systems

## 1. Number System Basics

### What are Number Systems?
Number systems are mathematical notations for representing numbers using a consistent set of digits and rules.

### Base (Radix)
- **Decimal**: Base 10 (uses digits 0-9)
- **Binary**: Base 2 (uses digits 0-1)

## 2. Decimal Number System (Base 10)

### Characteristics
- Uses 10 digits: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
- Each position represents a power of 10
- Most commonly used system by humans

### Place Value System
```
Position:  4   3   2   1   0
Power:    10⁴ 10³ 10² 10¹ 10⁰
Value:   10000 1000 100  10   1
```

### Examples
```
Number: 1234
= 1×10³ + 2×10² + 3×10¹ + 4×10⁰
= 1×1000 + 2×100 + 3×10 + 4×1
= 1000 + 200 + 30 + 4
= 1234

Number: 567
= 5×10² + 6×10¹ + 7×10⁰
= 5×100 + 6×10 + 7×1
= 500 + 60 + 7
= 567
```

## 3. Binary Number System (Base 2)

### Characteristics
- Uses only 2 digits: 0 and 1
- Each position represents a power of 2
- Used by computers and digital systems

### Place Value System
```
Position:  7   6   5   4   3   2   1   0
Power:    2⁷  2⁶  2⁵  2⁴  2³  2²  2¹  2⁰
Value:   128  64  32  16   8   4   2   1
```

### Examples
```
Binary: 1101
= 1×2³ + 1×2² + 0×2¹ + 1×2⁰
= 1×8 + 1×4 + 0×2 + 1×1
= 8 + 4 + 0 + 1
= 13 (decimal)

Binary: 10110
= 1×2⁴ + 0×2³ + 1×2² + 1×2¹ + 0×2⁰
= 1×16 + 0×8 + 1×4 + 1×2 + 0×1
= 16 + 0 + 4 + 2 + 0
= 22 (decimal)
```

## 4. Binary to Decimal Conversion

### Method 1: Positional Value
Multiply each binary digit by its corresponding power of 2 and sum them.

```cpp
// Example: Convert 1011 to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    
    // Process from right to left
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// 1011₂ = 1×2³ + 0×2² + 1×2¹ + 1×2⁰ = 8+0+2+1 = 11₁₀
```

### Method 2: Doubling Method
```cpp
int binaryToDecimal(string binary) {
    int decimal = 0;
    
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

// Example: 1011
// Step 1: 0*2 + 1 = 1
// Step 2: 1*2 + 0 = 2  
// Step 3: 2*2 + 1 = 5
// Step 4: 5*2 + 1 = 11
```

### Examples with Step-by-Step
```
Example 1: 1010₂ to decimal
= 1×2³ + 0×2² + 1×2¹ + 0×2⁰
= 8 + 0 + 2 + 0
= 10₁₀

Example 2: 11111₂ to decimal  
= 1×2⁴ + 1×2³ + 1×2² + 1×2¹ + 1×2⁰
= 16 + 8 + 4 + 2 + 1
= 31₁₀

Example 3: 100101₂ to decimal
= 1×2⁵ + 0×2⁴ + 0×2³ + 1×2² + 0×2¹ + 1×2⁰
= 32 + 0 + 0 + 4 + 0 + 1
= 37₁₀
```

## 5. Decimal to Binary Conversion

### Method 1: Division by 2
Keep dividing by 2 and collect remainders from bottom to top.

```cpp
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    
    string binary = "";
    while (decimal > 0) {
        binary = (char)('0' + decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}
```

### Step-by-Step Examples
```
Example 1: Convert 13₁₀ to binary
13 ÷ 2 = 6  remainder 1
6  ÷ 2 = 3  remainder 0  
3  ÷ 2 = 1  remainder 1
1  ÷ 2 = 0  remainder 1

Reading remainders from bottom to top: 1101₂

Example 2: Convert 25₁₀ to binary
25 ÷ 2 = 12  remainder 1
12 ÷ 2 = 6   remainder 0
6  ÷ 2 = 3   remainder 0
3  ÷ 2 = 1   remainder 1
1  ÷ 2 = 0   remainder 1

Reading remainders from bottom to top: 11001₂
```

### Method 2: Subtraction Method
Find the largest power of 2 ≤ number, subtract it, repeat.

```
Example: Convert 45₁₀ to binary
Powers of 2: 32, 16, 8, 4, 2, 1

45 - 32 = 13  (use 2⁵) → bit 5 = 1
13 - 8  = 5   (use 2³) → bit 3 = 1  
5  - 4  = 1   (use 2²) → bit 2 = 1
1  - 1  = 0   (use 2⁰) → bit 0 = 1

Binary positions: 1 0 1 1 0 1 = 101101₂
```

## 6. Complete Conversion Table

| Decimal | Binary | Explanation |
|---------|--------|-------------|
| 0       | 0      | Zero |
| 1       | 1      | 2⁰ |
| 2       | 10     | 2¹ |
| 3       | 11     | 2¹ + 2⁰ |
| 4       | 100    | 2² |
| 5       | 101    | 2² + 2⁰ |
| 6       | 110    | 2² + 2¹ |
| 7       | 111    | 2² + 2¹ + 2⁰ |
| 8       | 1000   | 2³ |
| 9       | 1001   | 2³ + 2⁰ |
| 10      | 1010   | 2³ + 2¹ |
| 15      | 1111   | 2³ + 2² + 2¹ + 2⁰ |
| 16      | 10000  | 2⁴ |

## 7. Programming Implementation

### Complete Binary-Decimal Converter
```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class NumberConverter {
public:
    // Binary to Decimal conversion
    static int binaryToDecimal(string binary) {
        int decimal = 0;
        int power = 0;
        
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += pow(2, power);
            } else if (binary[i] != '0') {
                cout << "Invalid binary digit!" << endl;
                return -1;
            }
            power++;
        }
        return decimal;
    }
    
    // Decimal to Binary conversion
    static string decimalToBinary(int decimal) {
        if (decimal == 0) return "0";
        if (decimal < 0) return "Invalid input";
        
        string binary = "";
        while (decimal > 0) {
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;
            decimal /= 2;
        }
        return binary;
    }
    
    // Alternative: Using bitwise operations
    static string decimalToBinaryBitwise(int decimal) {
        if (decimal == 0) return "0";
        
        string binary = "";
        while (decimal > 0) {
            binary = ((decimal & 1) ? "1" : "0") + binary;
            decimal >>= 1;  // Right shift by 1
        }
        return binary;
    }
};

// Usage example
int main() {
    // Binary to Decimal examples
    cout << "Binary to Decimal:" << endl;
    cout << "1101₂ = " << NumberConverter::binaryToDecimal("1101") << "₁₀" << endl;
    cout << "10110₂ = " << NumberConverter::binaryToDecimal("10110") << "₁₀" << endl;
    
    // Decimal to Binary examples  
    cout << "\nDecimal to Binary:" << endl;
    cout << "13₁₀ = " << NumberConverter::decimalToBinary(13) << "₂" << endl;
    cout << "22₁₀ = " << NumberConverter::decimalToBinary(22) << "₂" << endl;
    
    return 0;
}
```

## 8. Real-World Applications

### Computer Memory
```cpp
// 8-bit byte can represent 0-255 in decimal
// Each bit position has a value:
// [128][64][32][16][8][4][2][1]

// Example: Representing 170 in 8-bit binary
int value = 170;
// 170 = 128 + 32 + 8 + 2
// Binary: 10101010

cout << "Value 170 in binary: ";
for (int i = 7; i >= 0; i--) {
    cout << ((value >> i) & 1);
}
cout << endl;  // Output: 10101010
```

### Color Representation (RGB)
```cpp
// RGB color: Each component (Red, Green, Blue) is 8-bit (0-255)
// Example: RGB(255, 128, 64)

int red = 255;    // 11111111₂
int green = 128;  // 10000000₂  
int blue = 64;    // 01000000₂

// Combined 24-bit color value
int color = (red << 16) | (green << 8) | blue;
cout << "RGB(255,128,64) = " << color << " decimal" << endl;
```

### File Permissions (Unix/Linux)
```cpp
// File permissions in octal are based on binary
// rwx rwx rwx (owner, group, others)
// r=4, w=2, x=1

// Example: 755 permissions
// Owner: 7 = 4+2+1 = rwx = 111₂
// Group: 5 = 4+0+1 = r-x = 101₂  
// Others: 5 = 4+0+1 = r-x = 101₂
```

## 9. Practice Problems

### Exercise 1: Convert these binary numbers to decimal
```
1. 1001₂ = ?
2. 11010₂ = ?
3. 101101₂ = ?
4. 1111111₂ = ?

Answers:
1. 9₁₀
2. 26₁₀  
3. 45₁₀
4. 127₁₀
```

### Exercise 2: Convert these decimal numbers to binary
```
1. 17₁₀ = ?
2. 33₁₀ = ?
3. 63₁₀ = ?
4. 100₁₀ = ?

Answers:
1. 10001₂
2. 100001₂
3. 111111₂
4. 1100100₂
```

### Exercise 3: Programming Challenge
```cpp
// Write a function to validate if a string is a valid binary number
bool isValidBinary(string str) {
    for (char c : str) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return !str.empty();
}

// Write a function to add two binary numbers (as strings)
string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    
    return result;
}
```

## 10. Quick Reference

### Powers of 2 (First 16)
```
2⁰  = 1      2⁸  = 256
2¹  = 2      2⁹  = 512  
2²  = 4      2¹⁰ = 1024 (1K)
2³  = 8      2¹¹ = 2048
2⁴  = 16     2¹² = 4096
2⁵  = 32     2¹³ = 8192
2⁶  = 64     2¹⁴ = 16384
2⁷  = 128    2¹⁵ = 32768
```

### Common Binary Patterns
```
1 bit:  0-1       (0-1 decimal)
2 bits: 00-11     (0-3 decimal)  
3 bits: 000-111   (0-7 decimal)
4 bits: 0000-1111 (0-15 decimal)
8 bits: 00000000-11111111 (0-255 decimal)
```

## Memory Tips
- **Binary uses only 0 and 1**
- **Each position is a power of 2**
- **Rightmost bit is 2⁰ = 1**
- **To convert binary to decimal: sum powers of 2**
- **To convert decimal to binary: divide by 2, collect remainders**
- **1 byte = 8 bits = 256 possible values (0-255)**