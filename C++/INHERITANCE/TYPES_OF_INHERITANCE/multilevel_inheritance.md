# C++ Multilevel Inheritance Example

## What is Multilevel Inheritance?
**Multilevel Inheritance** is a type of inheritance where a class derives from another derived class, forming a chain of inheritance. This allows properties and behaviors to be passed through multiple levels.

### Benefits of Multilevel Inheritance:
- Promotes code hierarchy
- Encourages modular and scalable design
- Allows incremental additions to inherited functionality

### Diagram Representation:
```
      BaseClass
         |
         ↓
     DerivedClass1
         |
         ↓
     DerivedClass2
```

## Code Example
### Multilevel Inheritance Example
```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Intermediate Derived class
class Mammal : public Animal {
public:
    void breathe() {
        cout << "Mammal is breathing" << endl;
    }
};

// Further Derived class
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat(); // Inherited from Animal
    myDog.breathe(); // Inherited from Mammal
    myDog.bark(); // Defined in Dog
    return 0;
}
```

## Expected Output
```
Animal is eating
Mammal is breathing
Dog is barking
```
