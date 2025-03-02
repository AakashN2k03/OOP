# C++ Classes and Objects

This repository contains fundamental concepts and examples of object-oriented programming in C++, focusing on classes, objects, data members, and member functions.

## Table of Contents
- [1. Classes in C++](#1-classes-in-c)
- [2. Objects in C++](#2-objects-in-c)
- [3. Data Members in C++](#3-data-members-in-c)
- [4. Member Functions in C++](#4-member-functions-in-c)
  - [Inside Class Definition](#inside-class-definition)
  - [Outside Class Definition](#outside-class-definition)

## 1. Classes in C++

### Definition:
A **class** is a user-defined data type that serves as a blueprint for creating objects. It defines the structure (data members) and behavior (member functions) of objects.

### Key Points about Classes:
✅ A class is a collection of variables (data members) and functions (member functions).
✅ It provides **encapsulation**, meaning data and functions are combined into a single unit.
✅ Memory for a class is allocated only when an **object** is created.
✅ It is defined using the `class` keyword.

### Syntax of a Class:
```cpp
class ClassName {
    // Access specifiers (public, private, protected)
    // Data Members (variables)
    // Member Functions (methods)
};
```

## 2. Objects in C++

### Definition:
An **object** is an instance of a class. It represents a real-world entity and has its own copy of the class's data members and member functions.

### Key Points about Objects:
✅ An object is created from a class using the class name.
✅ Multiple objects of the same class can be created.
✅ Objects are stored in memory separately.

### Syntax to Create an Object:
```cpp
ClassName objectName; // Declaration
```

### Example:
```cpp
Car myCar; // 'myCar' is an object of class 'Car'
```

## 3. Data Members in C++

### Definition:
**Data members** are variables declared inside a class that store data related to the objects.

### Key Points about Data Members:
✅ They represent the attributes or properties of an object.
✅ They can be of any data type (`int`, `float`, `string`, etc.).
✅ They can be **private, public, or protected** based on access specifiers.
✅ Memory for data members is allocated separately for each object.

### Example of Data Members:
```cpp
class Car {
public:
    string make;  // Data member
    string model; // Data member
    int year;     // Data member
};
```

## 4. Member Functions in C++

### Definition:
**Member functions** are functions defined inside a class that operate on the data members of that class. They define the behavior of objects.

### Types of Member Functions:
1. **Inside Class Definition:** Functions are defined inside the class itself.
2. **Outside Class Definition:** Functions are declared inside the class but defined outside.

### Key Points about Member Functions:
✅ They define how objects interact and modify data members.
✅ They can be **public, private, or protected**.
✅ Can have return types and parameters like regular functions.
✅ Can access and modify data members.

### Inside Class Definition
✅ The member function is defined **directly inside the class**.
✅ It is automatically treated as **inline** unless explicitly declared otherwise.

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string make;
    string model;
    int year;
    
    // Member function defined inside the class
    void displayInfo() {
        cout << "Car Make: " << make << endl;
        cout << "Car Model: " << model << endl;
        cout << "Car Year: " << year << endl;
    }
};

int main() {
    Car car1;
    car1.make = "Tesla";
    car1.model = "Model X";
    car1.year = 2023;
    
    car1.displayInfo(); // Calling the function
    
    return 0;
}
```

### Outside Class Definition
✅ The member function is **declared inside the class** but **defined outside**.
✅ We use the **scope resolution operator (**`::`**) to define the function outside the class.

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string make;
    string model;
    int year;
    
    // Function declaration inside class
    void displayInfo();
};

// Function definition outside the class using scope resolution (::)
void Car::displayInfo() {
    cout << "Car Make: " << make << endl;
    cout << "Car Model: " << model << endl;
    cout << "Car Year: " << year << endl;
}

int main() {
    Car car1;
    car1.make = "Ford";
    car1.model = "Mustang";
    car1.year = 2022;
    
    car1.displayInfo(); // Calling the function
    
    return 0;
}
```

## License
This project is licensed under the MIT License - see the LICENSE file for details.
