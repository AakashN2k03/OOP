# Access Specifiers in C++ Classes
 
In C++, **access specifiers** control the visibility and accessibility of class members (variables and functions). They are fundamental to implementing encapsulation, one of the core principles of object-oriented programming.

## Types of Access Specifiers

There are three types of access specifiers in C++:

1. **Public (`public`)**
   * Members declared `public` are accessible from anywhere in the program.
   * These can be accessed by objects of the class, derived classes, and any external code.

2. **Private (`private`)**
   * Members declared `private` can only be accessed within the same class.
   * They are not accessible from derived classes or external code.
   * This is the default access specifier if none is specified.

3. **Protected (`protected`)**
   * Members declared `protected` can be accessed within the same class and by derived classes (inheritance).
   * They are not accessible from external code.

## Example Code

```cpp
#include <iostream>
using namespace std;

class Example {
public:
    int publicVar;    // Accessible anywhere

private:
    int privateVar;   // Only accessible within this class

protected:
    int protectedVar; // Accessible within this class and derived classes

public:
    Example() {
        publicVar = 10;
        privateVar = 20;
        protectedVar = 30;
    }

    void display() {
        cout << "Public Variable: " << publicVar << endl;
        cout << "Private Variable: " << privateVar << endl;
        cout << "Protected Variable: " << protectedVar << endl;
    }
};

class Derived : public Example {
public:
    void show() {
        cout << "Accessing from Derived Class:" << endl;
        cout << "Public Variable: " << publicVar << endl;
        // cout << "Private Variable: " << privateVar << endl; // ❌ Not accessible
        cout << "Protected Variable: " << protectedVar << endl;
    }
};

int main() {
    Example obj;
    
    obj.publicVar = 100; // ✅ Accessible
    // obj.privateVar = 200; // ❌ Not Accessible
    // obj.protectedVar = 300; // ❌ Not Accessible
    
    obj.display();
    
    Derived d;
    d.show();
    
    return 0;
}
```

## Output

```
Public Variable: 100
Private Variable: 20
Protected Variable: 30
Accessing from Derived Class:
Public Variable: 100
Protected Variable: 30
```

## Key Takeaways

1. **Public Members:** Can be accessed anywhere.
2. **Private Members:** Can only be accessed inside the class (not even in derived classes).
3. **Protected Members:** Can be accessed inside the class and in derived classes.

## Access Specifiers in Inheritance

When a class is derived from another class, the access specifier used in the inheritance affects how the members from the base class are inherited:

```cpp
class Derived : public Base { /* ... */ };    // Public inheritance
class Derived : protected Base { /* ... */ }; // Protected inheritance
class Derived : private Base { /* ... */ };   // Private inheritance (default)
```

The inheritance mode affects how the access levels transfer:

| Base Class Member | Public Inheritance | Protected Inheritance | Private Inheritance |
|-------------------|--------------------|-----------------------|---------------------|
| Public            | Public             | Protected             | Private             |
| Protected         | Protected          | Protected             | Private             |
| Private           | Not Accessible     | Not Accessible        | Not Accessible      |

## Best Practices

1. **Encapsulation:** Make data members private and provide public getter/setter methods to access them.
2. **Interface Design:** Use public members to define the interface of your class.
3. **Implementation Details:** Keep implementation details private or protected.

## Why Use Access Specifiers?

- **Data Hiding:** Prevents accidental modification of data.
- **Controlled Access:** Allows controlled access to class members.
- **Abstraction:** Helps in focusing on what a class does rather than how it does it.
- **Maintainability:** Makes code more maintainable as internal changes don't affect external code.
