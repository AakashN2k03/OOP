# Static Variables in C++ OOP

## Overview
This README provides a comprehensive guide to understanding static variables in C++ Object-Oriented Programming (OOP). Static variables retain their values between function calls and have special behavior in terms of lifetime and scope.

## Contents
1. [Definition](#definition)
2. [Static Variables Inside Functions](#static-variables-inside-functions)
3. [Static Variables Inside Classes](#static-variables-inside-classes)
4. [Key Points](#key-points)
5. [Initialization Rules](#initialization-rules)
6. [Constant vs Non-Constant Static Variables](#constant-vs-non-constant-static-variables)
7. [Advantages](#advantages)
8. [Const vs Constexpr](#const-vs-constexpr)

## Definition
A static variable in C++ is a variable that:
- Retains its value between function calls
- Is initialized only once 
- Exists for the entire lifetime of the program
- Can be shared across all instances of a class (when declared inside a class)
- Can be declared inside functions or classes

## Static Variables Inside Functions
When declared inside a function, a static variable:
- Retains its value between function calls
- Is local to the function in scope
- Is initialized only once

```cpp
#include <iostream>
using namespace std;

void countCalls() {
    static int count = 0;  // Static variable
    count++;
    cout << "Function called " << count << " times." << endl;
}

int main() {
    countCalls(); // Function called 1 time
    countCalls(); // Function called 2 times
    countCalls(); // Function called 3 times
    return 0;
}
```

## Static Variables Inside Classes
When declared inside a class, a static variable:
- Is shared among all instances of the class
- Is not tied to any particular object
- Must be defined outside the class (with some exceptions)

```cpp
#include <iostream>
using namespace std;

class Counter {
public:
    static int count;  // Static member variable declaration
    Counter() { count++; }
    
    static void displayCount() {
        cout << "Count: " << count << endl;
    }
};

int Counter::count = 0; // Definition of the static member variable

int main() {
    Counter c1, c2, c3;
    Counter::displayCount();  // Access static function using class name
    return 0;
}
```

## Key Points
1. **Lifetime**: Static variables exist for the entire runtime of the program
2. **Memory Allocation**: Stored in a fixed location (data segment) rather than the stack
3. **Initialization**: Initialized only once
4. **Scope**: Limited to the function/class but value is preserved
5. **Access**: Class static members can be accessed using the class name

## Initialization Rules
### Inside Class Definitions
For C++98 and earlier:
- Non-constant static variables must be defined outside the class
- Only static const integral types can be initialized inside the class

For C++11 and later:
- Non-constant static variables still must be defined outside the class
- static const and static constexpr can be initialized inside the class

```cpp
class Example {
public:
    static int value;                   // Declaration only
    static const int CONSTANT = 100;    // Inline initialization allowed for const
    static constexpr double PI = 3.14;  // Inline initialization allowed for constexpr
};

// Required for non-constant static variables
int Example::value = 0;
```

## Constant vs Non-Constant Static Variables

### Constant Integral Static Variables
- Are declared with `const` or `constexpr`
- Value cannot change after initialization
- Can be initialized inside the class definition
- Used for fixed values like constants or enum values

### Non-Constant Static Variables
- Value can change during execution
- Must be defined outside the class
- Used when the value needs to be modified (e.g., counters)

## Advantages
1. **Preserved State**: Maintains state between calls or instances
2. **Shared Data**: Allows data sharing between all instances of a class
3. **Efficiency**: Improves memory usage (only one copy exists)

## Const vs Constexpr
### const
- Value cannot be changed after initialization
- Can be set at runtime
- Used for values that should remain the same but don't need to be known at compile-time

### constexpr
- Must be known at compile-time
- Strictly evaluated during compilation
- Used for constants that must be evaluated at compile-time (for optimization or templates)
