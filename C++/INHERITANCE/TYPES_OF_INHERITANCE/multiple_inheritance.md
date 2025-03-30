# C++ Multiple Inheritance Example

## What is Multiple Inheritance?
**Multiple Inheritance** is a type of inheritance where a single derived class inherits from more than one base class. This allows the derived class to acquire the functionalities of multiple parent classes.

### Benefits and Features of Multiple Inheritance:
- Enables a class to combine features from multiple sources.
- Increases code reusability and modular design.
- Enhances flexibility in designing class relationships.
- Demonstrates how a single class can inherit from multiple base classes.
- Shows method inheritance from different parent classes.

### Diagram Representation:
```
  BaseClass1      BaseClass2
      |              |
      ---------------
            |
            ↓
      DerivedClass
```

## Code Example
### Multiple Inheritance Example
```cpp
#include <iostream>
using namespace std;

// Base class 1
class Engine {
public:
    void startEngine() {
        cout << "Engine started" << endl;
    }
};

// Base class 2
class Wheels {
public:
    void rotateWheels() {
        cout << "Wheels are rotating" << endl;
    }
};

// Derived class inheriting from both Engine and Wheels
class Car : public Engine, public Wheels {
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

int main() {
    Car myCar;
    myCar.startEngine(); // Inherited from Engine
    myCar.rotateWheels(); // Inherited from Wheels
    myCar.drive(); // Defined in Car
    return 0;
}
```

## Expected Output
```
Engine started
Wheels are rotating
Car is driving
```
