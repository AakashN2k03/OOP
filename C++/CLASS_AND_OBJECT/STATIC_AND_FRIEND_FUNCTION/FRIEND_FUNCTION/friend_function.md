# Friend Function in C++

## ✅ What is a Friend Function?
A **friend function** in C++:

- Can access **private** and **protected** members of a class.
- Is **not** a member of the class but is declared inside the class using the **`friend`** keyword.
- Is defined **outside** the class like a normal function.

---

## ✅ Simple Example:

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;
    int year;

public:
    Car(string n, int y) : name(n), year(y) {}

    // Declaration of friend function
    friend void displayCar(Car c);
};

// Definition of friend function (outside the class)
void displayCar(Car c) {
    cout << "Car Name: " << c.name << ", Year: " << c.year << endl;
}

int main() {
    Car c1("Audi", 2020);
    displayCar(c1); // Calling the friend function

    return 0;
}
```

### ✅ Output:
```
Car Name: Audi, Year: 2020
```

---

## ✅ How It Works:

1. **`friend` keyword** allows the `displayCar()` function to access **private members** (name, year) of the `Car` class.
2. The **friend function** is **declared** inside the class but **defined** outside.
3. **No scope resolution operator (`::`)** is needed for the friend function.

---

## ✅ Key Points:

- Friend functions **are not member functions** but can access **private** and **protected** members.
- They are **declared inside** the class using the **`friend`** keyword.
- They are **defined outside** the class like a normal function.

---

## ✅ Using Reference (`&`) in Friend Functions:

Using a reference (`&`) in a friend function parameter is **optional** but **recommended** for efficiency and modification purposes.

### ✅ When to Use Reference (`&`):

1. **Efficiency**: Avoids copying large objects.
2. **Modifying Objects**: Allows the friend function to modify the object.

### ✅ Example Without Reference (Pass by Value):

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;
    int year;

public:
    Car(string n, int y) : name(n), year(y) {}

    friend void displayCar(Car c); // Pass by value
};

void displayCar(Car c) {
    cout << "Car Name: " << c.name << ", Year: " << c.year << endl;
}

int main() {
    Car c1("Audi", 2020);
    displayCar(c1); // Copies the object

    return 0;
}
```

### ✅ Drawback:
This copies the entire object, which is **inefficient** if the object is **large**.

---

### ✅ Example With Reference (Pass by Reference):

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;
    int year;

public:
    Car(string n, int y) : name(n), year(y) {}

    friend void displayCar(const Car &c); // Pass by reference
};

// Using 'const' to prevent modification
void displayCar(const Car &c) {
    cout << "Car Name: " << c.name << ", Year: " << c.year << endl;
}

int main() {
    Car c1("Audi", 2020);
    displayCar(c1); // No copy, better performance

    return 0;
}
```

### ✅ Benefits:

1. **Faster**: Avoids object copying.
2. **Safer**: `const` ensures the object cannot be modified.

---

## ✅ When to Use Each Approach:

- **Pass by Value**: For **small** objects (e.g., integers, floats).
- **Pass by Reference**: For **large** objects (e.g., classes, vectors).
- **`const` Reference**: When you **don’t** want to modify the object.

---

## ✅ Modifying Objects Using Friend Functions:

If you don’t use `const`, the object can be **modified** inside the friend function.

### ✅ Example (Without `const` - Modifiable Reference):

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;
    int year;

public:
    Car(string n, int y) : name(n), year(y) {}

    // Friend function (modifiable reference)
    friend void updateCar(Car &c);
};

void updateCar(Car &c) {
    c.year = 2025; // Modifying the object
    cout << "Updated Year: " << c.year << endl;
}

int main() {
    Car c1("Audi", 2020);
    updateCar(c1); // Modifies original object
    return 0;
}
```

### ✅ Output:
```
Updated Year: 2025
```

---

## ✅ Using `const` for Read-only Access:

If you use `const`, the object becomes **read-only** and **cannot be modified**.

### ✅ Example (With `const` - Read-only Reference):

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;
    int year;

public:
    Car(string n, int y) : name(n), year(y) {}

    // Friend function (const reference)
    friend void displayCar(const Car &c);
};

void displayCar(const Car &c) {
    cout << "Car Year: " << c.year << endl;
}

int main() {
    Car c1("Audi", 2020);
    displayCar(c1); // Cannot modify the object
    return 0;
}
```

### ✅ Output:
```
Car Year: 2020
```

---

## ✅ Summary:

- Use **without `const`** if the friend function needs to **modify** the object.
- Use **with `const`** if the function should only **read** the object (safer and prevents accidental changes).
