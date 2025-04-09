# C++ Abstract Classes

## 🧩 What is an Abstract Class?

An **abstract class** in C++ is a class that **cannot be instantiated** on its own. It's meant to be **inherited** by other classes that **implement** its abstract (pure virtual) functions.

✅ It **must have at least one pure virtual function**:

```cpp
virtual void show() = 0; // Pure virtual function
```

## 🧠 Why and When to Use Abstract Classes

### 🎯 **Why:**
* To define a **common interface** for all derived classes.
* To **enforce implementation** of certain functions in child classes.
* To achieve **runtime polymorphism**.

### 🕒 **When:**
* When you want to **provide a blueprint** for derived classes.
* When some methods should have **different implementations** in each derived class.
* When you're following **Interface Segregation** or **Design by Contract** principles.

## 🛠️ Example in C++

```cpp
#include<iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function (Abstract)
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    // Shape s; ❌ Error: Cannot create object of abstract class
    
    Circle c;
    c.draw(); // ✅ Output: Drawing a Circle
    
    return 0;
}
```

## ❓ Can Abstract Classes Have Constructors?

✅ **YES**, abstract classes **can have constructors**!

Even though you can't create an object of an abstract class directly, the constructor:
* Gets called **when a derived class object is created**
* Helps in **initializing common data members**

### 🔍 Example:

```cpp
class Base {
public:
    Base() {
        cout << "Base class constructor\n";
    }
    virtual void show() = 0; // Abstract
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor\n";
    }
    void show() override {
        cout << "Derived show()\n";
    }
};

int main() {
    Derived d;
    d.show();
    return 0;
}
```

**🟢 Output:**
```
Base class constructor
Derived class constructor
Derived show()
```

✔️ See? The abstract class constructor **runs first**, then the derived class.

## ✅ Summary

| Feature | Abstract Class |
|---------|---------------|
| Can it be instantiated? | ❌ No |
| Contains pure virtual fn? | ✅ Yes (at least one) |
| Purpose | Define interface / enforce implementation |
| Constructors allowed? | ✅ Yes, runs when derived class is created |
