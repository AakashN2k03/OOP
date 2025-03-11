# Python Classes and Objects

This README provides an overview of classes and objects in Python, fundamental concepts in object-oriented programming (OOP).

## Table of Contents
- [Classes in Python](#classes-in-python)
  - [Syntax of a Class](#syntax-of-a-class)
  - [Class Components](#class-components)
- [Objects in Python](#objects-in-python)
  - [Creating Objects](#creating-objects)
- [Best Practices](#best-practices)


## Classes in Python

A **class** is a blueprint or template for creating objects. It defines **properties (data members)** and **behaviors (member functions)** that objects of that class will have.

### Syntax of a Class

```python
class ClassName:
    # Class attributes (optional)
    class_variable = "I am a class variable"
    
    # Constructor (special method to initialize objects)
    def __init__(self, instance_variable):
        self.instance_variable = instance_variable  # Instance variable
        
    # Method (member function)
    def show(self):
        print("Class variable:", ClassName.class_variable)
        print("Instance variable:", self.instance_variable)
```

### Class Components

* `class ClassName:` → Defines a class.
* `__init__()` → Special method (constructor) to initialize an object.
* `self` → Represents the instance of the class.
* **Instance Variable** (`self.instance_variable`) → Specific to each object.
* **Class Variable** (`class_variable`) → Shared among all objects.

## Objects in Python

An **object** is an instance of a class. Each object has its own set of attributes and can call the methods defined in the class.

### Creating Objects

```python
# Creating an object of the class
obj = ClassName("I am an instance variable")

# Calling a method
obj.show()
```


## Best Practices

1. **Naming Conventions**:
   - Class names should use CamelCase
   - Method and variable names should use snake_case

2. **Documentation**:
   - Use docstrings to document classes and methods

3. **Encapsulation**:
   - Use single underscore prefix (`_variable`) for protected members
   - Use double underscore prefix (`__variable`) for private members

