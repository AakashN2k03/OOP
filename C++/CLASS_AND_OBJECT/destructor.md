# Destructors in C++

A **destructor** is a special member function of a class that is executed **automatically** when an object goes **out of scope** or is **deleted**. It is used to **release resources** like memory, file handles, or network connections.

## Key Points About Destructors

✅ It has the **same name as the class** but with a **tilde (~) prefix**.  
✅ It **does not take parameters** and **does not return a value**.  
✅ It is **automatically called** when the object is destroyed.  
✅ **Only one destructor per class** (Destructor Overloading is NOT possible).  
✅ **Used to free memory, close files, or release resources**.

## Example: Basic Destructor

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    Car() {
        cout << "Constructor called: Car object created." << endl;
    }
    
    ~Car() {
        cout << "Destructor called: Car object destroyed." << endl;
    }
};

int main() {
    Car c1; // Object created → Constructor runs
    return 0; // Object goes out of scope → Destructor runs
}
```

## Output

```
Constructor called: Car object created.
Destructor called: Car object destroyed.
```

✅ **Destructor is automatically called when the object `c1` goes out of scope.**

## When is a Destructor Called?

1. **When an object goes out of scope** (e.g., at the end of a function).
2. **When `delete` is used on a dynamically allocated object** (`delete obj;`).
3. **When a program exits** (for global/static objects).
