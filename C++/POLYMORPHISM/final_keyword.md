# C++ Final Keyword

## Overview
The `final` keyword was introduced in C++11 to prevent further overriding of virtual functions or inheriting from classes. It provides a way to control class design by explicitly marking methods or classes as terminal in their inheritance hierarchy.

## Use Cases

### 1. Prevent Overriding of Virtual Functions

You can use `final` after a virtual function declaration to prevent derived classes from overriding it.

#### Syntax:
```cpp
class Base {
public:
    virtual void show() final; // Cannot be overridden
};
```

#### Example:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() final {
        cout << "Base display" << endl;
    }
};

class Derived : public Base {
public:
    // ❌ Error: display() is marked final in base class
    // void display() {
    //     cout << "Derived display" << endl;
    // }
};

int main() {
    Base b;
    b.display();
    return 0;
}
```

**Result**: If you uncomment the `Derived::display()` method, the compiler will generate an error because the method has been marked as `final` in the base class.

### 2. Prevent Further Inheritance from Class

You can mark an entire class as `final` to prevent any other class from inheriting from it.

#### Syntax:
```cpp
class FinalClass final {
    // class body
};
```

#### Example:
```cpp
#include <iostream>
using namespace std;

class A final {
public:
    void greet() {
        cout << "Hello from A" << endl;
    }
};

// ❌ Error: Cannot inherit from 'A' because it's final
// class B : public A {};

int main() {
    A obj;
    obj.greet();
    return 0;
}
```

## Why Use final?

- To protect critical methods from being modified in derived classes
- To prevent inheritance for security, design, or performance reasons
- To signal to other developers that a method or class is not designed to be extended

## Summary

| Use | Syntax | Example | Effect |
|-----|--------|---------|--------|
| Prevent method override | `virtual void foo() final;` | `virtual void display() final` | Derived classes can't override the method |
| Prevent class inheritance | `class A final { ... };` | `class A final { ... }` | No class can inherit from the class |
