# Python Method Types: Instance, Class, and Static Methods

This guide explains the three types of methods in Python classes with examples and use cases.

## Table of Contents
- [Overview](#overview)
- [Instance Methods](#instance-methods)
- [Class Methods](#class-methods) 
- [Static Methods](#static-methods)
- [Comparison Table](#comparison-table) 
- [When to Use Each Method Type](#when-to-use-each-method-type)
- [Real-Life Examples](#real-life-examples)
- [Common Questions](#common-questions)

## Overview

In Python, methods inside a class are categorized into three types:
1. **Instance Methods** – Work with instance variables (specific to an object)
2. **Class Methods** – Work with class variables (shared across all objects)
3. **Static Methods** – Independent of instance and class variables

## Instance Methods

Instance methods work with instance variables that are specific to an object. The first parameter must be `self`, which represents the instance of the class.

### Example:

```python
class Person:
    def __init__(self, name, age):
        # Constructor with instance variables
        self.name = name
        self.age = age
        
    def introduce(self):
        # Instance method
        print(f"Hello, my name is {self.name} and I am {self.age} years old.")

# Creating an object
person1 = Person("Aakash", 22)

# Calling the instance method
person1.introduce()
```

### Explanation:
1. `__init__` initializes the object with `name` and `age` (instance variables)
2. `introduce()` is an **instance method** because it uses `self` to access `self.name` and `self.age`
3. We create an object `person1` and call `introduce()`, which prints the message

## Class Methods

Class methods work with class variables that are shared among all objects. They are defined using the `@classmethod` decorator, and the first parameter must be `cls`, which represents the class itself.

### Example:

```python
class School:
    school_name = "VEC"  # Class variable
    
    @classmethod
    def change_school_name(cls, new_name):
        cls.school_name = new_name  # Modifies the class variable

# Calling the class method
School.change_school_name("New VEC")

# Printing the updated class variable
print(School.school_name)  # Output: New VEC
```

### Explanation:
1. `school_name` is a **class variable** (shared by all instances)
2. `change_school_name(cls, new_name)` is a **class method** that modifies `school_name`
3. We call `School.change_school_name("New VEC")`, which changes the class variable for all instances

## Static Methods

Static methods do not depend on instance or class variables. They are defined using the `@staticmethod` decorator and don't require a `self` or `cls` parameter.

### Example:

```python
class MathOperations:
    @staticmethod
    def add(x, y):
        return x + y  # Independent of class/instance variables

# Calling the static method
result = MathOperations.add(5, 10)
print(result)  # Output: 15
```

### Explanation:
1. `add(x, y)` is a **static method** because it does not use `self` or `cls`
2. It works like a normal function inside a class
3. We call it directly using `MathOperations.add(5, 10)`, and it returns `15`

## Comparison Table

| Method Type | Uses `self`? | Uses `cls`? | Works With | Decorator |
|-------------|-------------|------------|-----------|-----------|
| **Instance Method** | ✅ Yes | ❌ No | Instance Variables | None |
| **Class Method** | ❌ No | ✅ Yes | Class Variables | `@classmethod` |
| **Static Method** | ❌ No | ❌ No | Neither (Acts like a normal function) | `@staticmethod` |

## When to Use Each Method Type

| Method Type | When to Use It? |
|-------------|-----------------|
| **Instance Method** | When working with instance-specific data (e.g., user profile, bank account balance) |
| **Class Method** | When modifying or accessing class-level data that is shared among all instances (e.g., changing school name, tracking the number of students) |
| **Static Method** | When performing operations that don't need access to instance or class variables (e.g., utility functions like calculations) |

## Real-Life Examples

### 1. Instance Method Example: Bank Account
Each account has a unique balance, so an instance method is required.

```python
class BankAccount:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance  # Instance variable
        
    def deposit(self, amount):
        self.balance += amount
        print(f"{self.name}, your new balance is: {self.balance}")

# Creating accounts
account1 = BankAccount("Aakash", 1000)

# Depositing money (instance method)
account1.deposit(500)  # Output: Aakash, your new balance is: 1500
```

**Why Use an Instance Method?**
* Each user has a separate bank balance
* `self.balance` stores data **unique** to each object

### 2. Class Method Example: Changing Company Policy
A company has a **universal** leave policy for all employees.

```python
class Employee:
    leave_days = 20  # Class variable (same for all employees)
    
    @classmethod
    def update_leave_days(cls, new_days):
        cls.leave_days = new_days  # Modifies the class variable

# Changing leave policy for all employees
Employee.update_leave_days(25)

# Printing updated leave days
print(Employee.leave_days)  # Output: 25
```

**Why Use a Class Method?**
* `leave_days` is **shared** across all employees
* Updating once applies to everyone

### 3. Static Method Example: Utility Function
A math operation does not depend on any instance/class variable.

```python
class Calculator:
    @staticmethod
    def multiply(x, y):
        return x * y  # Independent of class/instance variables

# Using static method
result = Calculator.multiply(5, 4)
print(result)  # Output: 20
```

**Why Use a Static Method?**
* The function is **independent** of object state
* Works like a normal function inside the class

## Common Questions

### Can We Access Instance Variables in a Class Method?

No, **class methods cannot directly access instance variables** (`self.name`, `self.balance`) because they work at the **class level**.

**Example Showing This Limitation:**

```python
class Example:
    def __init__(self, name):
        self.name = name  # Instance variable
        
    @classmethod
    def show_name(cls):
        print(cls.name)  # ❌ This will cause an error!

obj = Example("Aakash")
obj.show_name()
```

❌ **Error:**
`AttributeError: type object 'Example' has no attribute 'name'`

**Solution: Passing Instance to Class Method**

If you want to **access instance variables inside a class method**, pass an instance (`self`) manually:

```python
class Example:
    def __init__(self, name):
        self.name = name  # Instance variable
        
    @classmethod
    def show_name(cls, instance):
        print(instance.name)  # Now it works!

# Creating object
obj = Example("Aakash")

# Calling class method with instance
Example.show_name(obj)  # Output: Aakash
```

### Is `instance` a Keyword?

No, `instance` is **not** a keyword in Python. It is just a **parameter name** that we use in functions. You can name it anything you want.

### Can We Access Static Methods Using Class or Instance Methods?

Yes, **static methods can be accessed using both class methods and instance methods**.

**Accessing Static Method Using a Class Method:**

```python
class Example:
    @staticmethod
    def static_method():
        return "Hello from static method"
        
    @classmethod
    def call_static(cls):
        return cls.static_method()  # Calling static method

# Calling class method, which calls static method
print(Example.call_static())  # Output: Hello from static method
```

**Accessing Static Method Using an Instance Method:**

```python
class Example:
    @staticmethod
    def static_method():
        return "Hello from static method"
        
    def call_static(self):
        return self.static_method()  # Calling static method

# Creating object
obj = Example()

# Calling instance method, which calls static method
print(obj.call_static())  # Output: Hello from static method
```

### What Are Methods by Default in Classes?

By default, **all methods in a Python class are**:
1. **Instance Methods** (if not decorated with `@staticmethod` or `@classmethod`)
2. They require `self` as the first parameter

## Memory
#### NOTE: All these methods are loaded only once at memory because these are class level definition


