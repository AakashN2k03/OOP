# Python Data Members (A to Z Explanation)

## Overview
In Python, **data members** refer to the variables **defined inside a class**. These variables **store data** and can be accessed by methods in the class.

## Types of Data Members in Python
There are three types of data members:
1. **Instance Variables** (Object-Specific)
2. **Class Variables** (Shared Across All Objects)
3. **Local Variables** (Method-Specific)

## 1. Instance Variables (Object-Specific Data Members)
* **Defined inside** `__init__()` using `self`
* **Each object gets its own copy** of instance variables
* **Values are unique to each object**

### Example
```python
class Person:
    def __init__(self, name, age):
        self.name = name  # Instance variable
        self.age = age    # Instance variable

p1 = Person("Aakash", 22)
p2 = Person("Rahul", 25)

print(p1.name, p1.age)  # Output: Aakash 22
print(p2.name, p2.age)  # Output: Rahul 25
```
🔹 `name` and `age` are instance variables and are **different for each object** (`p1` and `p2`).

## 2. Class Variables (Shared Data Members)
* **Defined inside the class but outside** `__init__()`
* **Shared by all objects** (Only one copy exists)
* **Can be accessed using** `ClassName.variable` or `self.variable`

### Example
```python
class Employee:
    company = "Google"  # Class variable (shared)
    
    def __init__(self, name, salary):
        self.name = name      # Instance variable
        self.salary = salary  # Instance variable

e1 = Employee("Alice", 50000)
e2 = Employee("Bob", 60000)

print(e1.company)  # Output: Google
print(e2.company)  # Output: Google

# Modify class variable
Employee.company = "Microsoft"
print(e1.company)  # Output: Microsoft
print(e2.company)  # Output: Microsoft
```
🔹 **Changing** `Employee.company` updates it for all objects, because class variables are shared.

## 3. Local Variables (Method-Specific Data Members)
* **Declared inside a method**
* **Scope is limited to the method only**
* **Not stored in the object**

### Example
```python
class Example:
    def show(self):
        x = 10  # Local variable
        print("Local variable:", x)

obj = Example()
obj.show()  # Output: Local variable: 10
# print(obj.x)  # Error! Local variables are not part of the object
```
🔹 `x` is a local variable and cannot be accessed outside the `show()` method.

## Difference Between Instance, Class, and Local Variables

| Feature | Instance Variable (`self.var`) | Class Variable (`ClassName.var`) | Local Variable (Inside Method) |
|---------|-------------------------------|----------------------------------|-------------------------------|
| **Scope** | Object-specific | Shared across all objects | Inside method only |
| **Storage** | Stored in object (`self`) | Stored in class memory | Not stored in object |
| **Modification** | Changes affect only that object | Changes affect all objects | Only available in method |
| **Access** | `self.variable` | `ClassName.variable` or `self.variable` | Directly inside method |

## Memory Management

### Does a Class Take Memory in Python?
A **class itself does take some memory**, but not in the same way as objects. When a class is **defined**, Python stores its **attributes, methods, and metadata** in memory. However, **no instance variables are stored** at this point because no object exists yet.

👉 **A class gets memory allocated when it is defined, but this memory is only for class-level attributes, methods, and metadata.**
👉 **An object gets its own separate memory only when it is created.**


### Does a class take memory by default?

# Class Memory:
Yes, when you define a class, Python allocates memory for:
Class-level attributes (like class_variable)
Methods (like method())
Metadata (class-level information)
This memory is allocated once when the class is defined and is shared across all objects of that class.

# Object Memory:
No, the class doesn't allocate memory for instance variables until an object is created.
Object-level memory (instance variables like self.variable) is only allocated when an object is created.

# Example
```python
class ClassName:
    # Class attributes (Stored in Class Memory)
    class_variable = "I am a class variable"
    
    # Constructor (called when an object is created)
    def __init__(self, instance_variable):
        self.instance_variable = instance_variable  # Stored in Object Memory
        
    # Method (stored in class memory)
    def show(self):
        print("Class variable:", ClassName.class_variable)
        print("Instance variable:", self.instance_variable)

# Creating Objects
obj1 = ClassName("Object 1 Variable")
obj2 = ClassName("Object 2 Variable")
```

