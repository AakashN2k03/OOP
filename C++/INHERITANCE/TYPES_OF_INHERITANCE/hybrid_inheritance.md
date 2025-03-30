# Hybrid Inheritance in C++

## Introduction
Hybrid inheritance is a combination of multiple types of inheritance, usually combining hierarchical and multiple inheritance. It is used when a class needs to inherit properties from multiple base classes, forming a complex inheritance structure.

## Hybrid Inheritance Diagram
```
        Base Class A
           |
  -----------------
  |               |
Class B         Class C
  |               |
  -------| |-------
        Class D
```

## Features of Hybrid Inheritance
- It combines multiple types of inheritance, such as multiple, hierarchical, and single inheritance.
- Provides greater flexibility in class relationships.
- Helps in reusing features from multiple base classes.
- May require the use of virtual inheritance to avoid ambiguity.

## Benefits of Hybrid Inheritance
- **Code Reusability:** Allows sharing of common functionalities across multiple derived classes.
- **Extensibility:** Enhances the ability to create new classes with minimal code duplication.
- **Efficient Data Organization:** Helps structure code effectively when dealing with complex relationships.
- **Encapsulation:** Maintains a clear hierarchy by allowing a derived class to inherit from multiple classes logically.

## Code Example
```cpp
#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void displayA() {
        cout << "Class A method" << endl;
    }
};

// Derived class B
class B : public A {
public:
    void displayB() {
        cout << "Class B method" << endl;
    }
};

// Derived class C
class C : public A {
public:
    void displayC() {
        cout << "Class C method" << endl;
    }
};

// Derived class D inheriting from both B and C
class D : public B, public C {
public:
    void displayD() {
        cout << "Class D method" << endl;
    }
};

int main() {
    D obj;
    obj.displayB();
    obj.displayC();
    obj.displayD();
    
    return 0;
}
```
## Output
```
Class B method
Class C method
Class D method
```

## Conclusion
Hybrid inheritance in C++ allows multiple types of inheritance to be combined, enabling more flexible and reusable code structures. However, it should be used cautiously to avoid ambiguity, especially when dealing with multiple inheritance.

