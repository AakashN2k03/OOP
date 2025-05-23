# C++ Single Inheritance Example

## What is Single Inheritance?
**Single Inheritance** is a type of inheritance in which a single derived class inherits from a single base class. This allows the derived class to use the properties and methods of the base class while also adding its own functionality. 

### Benefits and Features of Single Inheritance:
- Code Reusability
- Improves Maintainability
- Establishes a Hierarchical Relationship
- Shows method overriding.

### Diagram Representation:
```
      BaseClass
         |
         ↓
     DerivedClass1

```

## Code Example
```cpp
#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle is starting" << endl;
    }
};

// Derived class inheriting from Vehicle
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start(); // Inherited from Vehicle
    myCar.drive(); // Defined in Car
    return 0;
}
```

### NOTE: ## Public inheritance is usually the most common because it allows the derived class to be treated as an instance of the base class and makes sense for an "is-a" relationship (e.g., Car is-a Vehicle).

## Protected and private inheritance are used in special cases where you want to hide the base class's interface from outside code.
