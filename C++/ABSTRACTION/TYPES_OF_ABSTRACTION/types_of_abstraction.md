# C++ Abstraction in Object-Oriented Programming

## Types of Abstraction

There are two major types of abstraction in C++ OOP:

| Type | Description |
|------|-------------|
| Data Abstraction | Hides the internal data and shows only essential attributes. |
| Control Abstraction | Hides the internal logic (control flow) and shows only what function does. |

## 1. Data Abstraction

### What it is:
Hiding the internal data (variables) of a class from outside access. Only allowing access through public methods.

### Achieved Using:
- Classes
- Access Specifiers: `private`, `public`
- Getters and Setters

### Example:

```cpp
class Car {
private:
    int speed; // ❌ can't access directly from outside
public:
    void setSpeed(int s) { speed = s; }
    int getSpeed() { return speed; }
};

int main() {
    Car c;
    c.setSpeed(80); // ✅ setting data through method
    cout << c.getSpeed() << endl; // ✅ getting data through method
}
```

### Summary:
We hid the variable `speed`. Gave access only via `setSpeed()` and `getSpeed()` → this is data abstraction.

## 2. Control Abstraction

### What it is:
Hiding how a method or function works internally. You only see what it does, not how.

### Achieved Using:
- Functions
- Abstract classes / Interfaces
- Polymorphism

### Example:

```cpp
int multiply(int a, int b) {
    return a * b; // You don't care how multiplication works here.
}

int main() {
    cout << multiply(3, 5); // Just use it!
}
```

### Summary:
You use `multiply(3, 5)` but don't need to know the internals.

## When to Use

* **Use Data Abstraction** when you want to **protect internal data** from direct access.
* **Use Control Abstraction** when you want to **simplify function usage** or **hide complex logic** behind interfaces or utility functions.
