# Types of Constructors in C++

In C++, constructors are special member functions that are automatically called when an object of a class is created. They initialize the object's data members and allocate necessary resources. There are three main types of constructors in C++:

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor

## 1. Default Constructor

A **default constructor** is a constructor without parameters. It initializes object members with default values.

### Syntax:
```cpp
ClassName() {
    // Initialization code
}
```

### Example:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    int model;
    string brand;
    
    // Default Constructor
    Car() {
        model = 0;
        brand = "Unknown";
        cout << "Default Constructor Called!" << endl;
    }
    
    void display() {
        cout << "Model: " << model << ", Brand: " << brand << endl;
    }
};

int main() {
    Car car1; // Default constructor is called
    car1.display();
    return 0;
}
```

### Output:
```
Default Constructor Called!
Model: 0, Brand: Unknown
```

### Key Points:
* Automatically called when an object is created **without arguments**.
* Useful when you want to initialize data members with **default values**.
* If you don't define any constructor, C++ automatically provides a default constructor.

## 2. Parameterized Constructor

A **parameterized constructor** allows passing **arguments** to initialize an object with **custom values**.

### Syntax:
```cpp
ClassName(data_type parameter1, data_type parameter2) {
    // Initialization code
}
```

### Example:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    int model;
    string brand;
    
    // Parameterized Constructor
    Car(int m, string b) {
        model = m;
        brand = b;
        cout << "Parameterized Constructor Called!" << endl;
    }
    
    void display() {
        cout << "Model: " << model << ", Brand: " << brand << endl;
    }
};

int main() {
    Car car1(2022, "Tesla"); // Parameterized constructor is called
    car1.display();
    return 0;
}
```

### Output:
```
Parameterized Constructor Called!
Model: 2022, Brand: Tesla
```

### Key Points:
* Allows **initializing objects with specific values**.
* Provides flexibility by allowing **different initial values** for different objects.
* Can have multiple parameterized constructors with different parameter lists (constructor overloading).

## 3. Copy Constructor

A **copy constructor** is used to create a **new object by copying an existing object**.

### Syntax:
```cpp
ClassName(const ClassName &oldObject) {
    // Copy initialization code
}
```

### Example:
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    int model;
    string brand;
    
    // Parameterized Constructor
    Car(int m, string b) {
        model = m;
        brand = b;
        cout << "Parameterized Constructor Called!" << endl;
    }
    
    // Copy Constructor
    Car(const Car &c) {
        model = c.model;
        brand = c.brand;
        cout << "Copy Constructor Called!" << endl;
    }
    
    void display() {
        cout << "Model: " << model << ", Brand: " << brand << endl;
    }
};

int main() {
    Car car1(2023, "BMW"); // Calls parameterized constructor
    Car car2 = car1; // Calls copy constructor
    
    car1.display();
    car2.display();
    return 0;
}
```

### Output:
```
Parameterized Constructor Called!
Copy Constructor Called!
Model: 2023, Brand: BMW
Model: 2023, Brand: BMW
```

### Key Points:
* Used to **copy the values** of one object into another.
* By default, C++ provides a **built-in copy constructor** if you don't define one.
* Custom copy constructors are needed when working with **dynamic memory allocation** to prevent shallow copying.

## Summary of Constructor Types

| Constructor Type | Description |
|-----------------|-------------|
| **Default Constructor** | No parameters, initializes values to default. |
| **Parameterized Constructor** | Accepts arguments to initialize an object with specific values. |
| **Copy Constructor** | Creates a new object by copying an existing object. |

## Additional Types of Constructors

Apart from the three main types, C++ also supports:

### 4. Move Constructor (C++11 and later)
Used for efficiently transferring resources from temporary objects.

### 5. Delegating Constructor (C++11 and later)
Allows one constructor to call another constructor of the same class.

### 6. Converting Constructor
Implicitly converts one type to the class type unless declared with explicit keyword.
