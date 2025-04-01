# Constructor and Destructor in Inheritance

When a class is inherited in C++, the behavior of constructors and destructors follows a specific hierarchy.

## Constructor Behavior
### 1. Base Class Constructor is Called First
- When an object of the derived class is created, the base class constructor is executed first, followed by the derived class constructor.
- This ensures that base class members are properly initialized before the derived class extends functionality.

### 2. Order of Execution in Multi-Level Inheritance
- In multi-level inheritance (A → B → C), constructors are called in the order **Base → Intermediate → Derived**.

### 3. Parameterized Constructors
- If the base class has a parameterized constructor, the derived class constructor must explicitly call it using an **initializer list**.

## Destructor Behavior
### 1. Derived Class Destructor is Called First
- When an object goes out of scope, destructors are called in **reverse order**: first the derived class destructor, then the base class destructor.
- This ensures that derived class-specific resources are freed before base class members are deallocated.

## Example
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj; // Object creation
    return 0;    // Object destruction
}
```

## Output
```
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

## Explanation
1. The base class constructor is called first (`Base Constructor`).
2. Then the derived class constructor is executed (`Derived Constructor`).
3. Upon destruction, the derived class destructor runs first (`Derived Destructor`).
4. Finally, the base class destructor is called (`Base Destructor`).

