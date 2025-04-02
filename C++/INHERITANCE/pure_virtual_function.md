Pure Virtual Functions or Abstract Functions

1. What is a Pure Virtual Function?

A pure virtual function is a function declared in a base class that must be overridden in derived classes. It has no function body in the base class and ensures that every derived class provides its own implementation. A class containing at least one pure virtual function is called an abstract class and cannot be instantiated.

Syntax:

class Base {
public:
    virtual void show() = 0;  // Pure virtual function
};

❌ No function body in the base class! ✅ Must be overridden in the derived class.



2. Why Use Pure Virtual Functions?

✅ To force derived classes to provide their own implementation. ✅ To create an abstract base class that cannot be instantiated. ✅ To enable runtime polymorphism.



3. Example of a Pure Virtual Function

#include <iostream>
using namespace std;

class Animal {  // Abstract base class
public:
    virtual void makeSound() = 0;  // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks!\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows!\n";
    }
};

int main() {
    // Animal a; ❌ ERROR! Cannot create an object of an abstract class
    Dog d;
    Cat c;

    d.makeSound();  // Calls Dog’s version
    c.makeSound();  // Calls Cat’s version

    return 0;
}

Output:

Dog barks!
Cat meows!

✅ makeSound() is implemented in each derived class. ✅ The base class Animal cannot be instantiated because it has a pure virtual function.



4. What Happens If a Derived Class Does Not Override the Pure Virtual Function?

If a derived class does not override the pure virtual function, it also becomes an abstract class and cannot be instantiated.

class Bird : public Animal { };  // Does not override makeSound()

❌ ERROR: Bird is still abstract because it did not override makeSound().



5. Can a Pure Virtual Function Have a Body?

Yes! A pure virtual function can have a body, but only in the base class. However, derived classes must still override it.

class Base {
public:
    virtual void show() = 0 {  // Pure virtual function with a body
        cout << "Base class show()\n";
    }
};

⚠️ Rarely used, but allowed! ✅ Derived classes must override the function but can call Base::show() if needed.



6. Key Features of Pure Virtual Functions

✅ Declared using = 0 in the base class. ✅ Forces derived classes to override it. ✅ Makes the base class abstract (cannot create objects of it). ✅ Used in polymorphism to ensure derived classes provide their own implementations.



7. Real-World Use Cases

GUI Systems – A Shape class with a pure virtual draw() method that must be implemented by Circle, Rectangle, etc.
Game Development – A Character class with a pure virtual attack() method for Warrior, Mage, etc.
Operating Systems – An OS class with a pure virtual boot() method for Windows, Linux, etc.



8. Difference Between Virtual and Pure Virtual Functions

Feature

Virtual Function

Pure Virtual Function

Definition

A function in the base class that can be overridden in the derived class but has a default implementation.

A function in the base class that must be overridden in the derived class and has no default implementation.

Implementation in Base Class

Can have a function body.

Cannot have a function body (unless optional).

Overriding in Derived Class

Optional (derived class may or may not override it).

Mandatory (derived class must override it).

Base Class Instantiation

The base class can be instantiated if all functions are defined.

The base class cannot be instantiated (it becomes an abstract class).

Use Case

When you want to allow derived classes to optionally override a function.

When you want to force derived classes to implement their own version of the function.


Syntax of an Abstract Function

class Base {
public:
    virtual void show() = 0;  // Abstract function (Pure Virtual Function)
};

🔹 The = 0 syntax means the function is pure virtual (abstract). 🔹 The base class becomes an abstract class, meaning it cannot be instantiated.



Conclusion

✔ Virtual Function → Can be overridden, but not mandatory. ✔ Pure Virtual Function (Abstract Function) → Must be overridden in derived classes. ✔ Abstract Class → A class that contains at least one pure virtual function and cannot be instantiated.

