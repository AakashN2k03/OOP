# Virtual Function in C++

A **virtual function** is a member function in a base class that you can override in a derived class. It enables **runtime polymorphism**, meaning that the function that gets called is determined at **runtime** based on the actual type of the object, not the type of the pointer or reference.

---
## Why Use Virtual Functions?
- ✅ To achieve **dynamic binding** (i.e., function calls resolved at runtime instead of compile time).
- ✅ To allow **function overriding** in derived classes.
- ✅ To enable **polymorphism**, so that the correct function executes based on the actual object type.

---
## Syntax of Virtual Function
To declare a virtual function, use the `virtual` keyword in the base class:

```cpp
class Base {
public:
    virtual void show() {  // Virtual function
        cout << "Base class show() method\n";
    }
};
```

---
## How Virtual Functions Work?
- If a **base class function** is declared as virtual, C++ uses **dynamic dispatch (late binding)** to determine which function to call at **runtime**.
- When a **base class pointer or reference** points to a derived class object, the **derived class function** is called instead of the base class function.

---
## Example of Virtual Function

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show() method\n";
    }
};

class Derived : public Base {
public:
    void show() override { // Overriding the virtual function
        cout << "Derived class show() method\n";
    }
};

int main() {
    Base* basePtr;  
    Derived obj;  
    basePtr = &obj; // Base class pointer points to derived class object

    basePtr->show(); // Calls Derived class show() method (runtime polymorphism)
    return 0;
}
```

### **Output**
```
Derived class show() method
```

### **Why does it print `Derived class show() method` instead of `Base class show() method`?**
Because `show()` is a **virtual function**, so even though `basePtr` is of type `Base*`, it calls the derived class implementation at **runtime**.

---
## Key Features of Virtual Functions
✅ Declared using **virtual** in the base class.
✅ Must be **overridden** in the derived class.
✅ Enables **runtime polymorphism** (calls derived class function using a base class pointer).
✅ Supports **dynamic dispatch** (late binding instead of early binding).

---
## Virtual Function Without Overriding
Even if a derived class does **not override** the virtual function, the base class version is still accessible.

```cpp
class Derived : public Base { };
```

Here, the **base class `show()`** will be called if `Derived` does not override it.

---
