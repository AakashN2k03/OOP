# Base Class in C++
A **Base Class** is a class whose properties (data members) and behaviors (methods) can be inherited by other classes. It acts as a **parent class**.

## 🔹 Syntax of Base Class
```cpp
class Base {
    // Data Members (Variables)
    // Member Functions (Methods)
};
```

---

## ✅ Derived Class in C++
A **Derived Class** is a class that inherits from a base class. It gains access to the properties and methods of the base class (depending on the access specifier).

## 🔹 Syntax of Derived Class
```cpp
class Derived : public Base {
    // Additional Members (if any)
};
```

---

## 🧑‍💻 Example: Base Class and Derived Class
```cpp
#include <iostream>
using namespace std;

// Base Class (Parent Class)
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Derived Class (Child Class)
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main() {
    Dog d;
    d.eat();  // Accessing Base Class method
    d.bark(); // Accessing Derived Class method
    return 0;
}
```

## ✅ Output:
```
Animal is eating
Dog is barking
```

