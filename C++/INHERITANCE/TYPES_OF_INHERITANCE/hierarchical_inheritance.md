# Hierarchical Inheritance in C++

## Introduction
Hierarchical inheritance is a type of inheritance in C++ where multiple derived classes inherit from a single base class. This allows different subclasses to share the common functionalities of the base class while having their own specific features.

## Hierarchical Inheritance Diagram
```
        Base Class
           |
  -----------------
  |               |
Derived1       Derived2
```

## Features of Hierarchical Inheritance
- Multiple derived classes inherit from a single base class.
- Each derived class can have additional functionalities apart from the inherited ones.
- Provides a structured way to reuse code and maintain consistency.
- Ensures that common attributes and methods are managed in a single base class.
- Reduces redundancy and improves code maintainability.

## Code Example


```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "The cat meows." << endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    cout << "Dog actions:" << endl;
    myDog.eat();
    myDog.bark();

    cout << "\nCat actions:" << endl;
    myCat.eat();
    myCat.meow();

    return 0;
}
```

## Output
```
Dog actions:
This animal eats food.
The dog barks.

Cat actions:
This animal eats food.
The cat meows.
```

