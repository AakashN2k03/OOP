# 📘 Data Hiding in Object-Oriented Programming

## 📊 1. What is Data Hiding?
Data hiding is an object-oriented programming (OOP) concept where sensitive data within a class is hidden from the outside world. It prevents direct access and ensures data security through private and protected access modifiers.

---

## ✅ 2. Why is Data Hiding Important?
- **Security**: Prevents unauthorized access to critical data.
- **Control**: Allows controlled access using getters and setters.
- **Flexibility**: Internal implementation can change without affecting external code.
- **Data Integrity**: Reduces the risk of accidental modification.

---

## 📚 3. Core Principles of Data Hiding
- **Private and Protected Members**: Keep class attributes hidden using private or protected access specifiers.
- **Controlled Access**: Use getter and setter functions to manage read/write operations.
- **Encapsulation**: Combine data and methods in a class while hiding the implementation details.

---

## 📖 4. Access Modifiers and Data Hiding

| Access Modifier | Accessible Within Class | Accessible in Derived Class | Accessible Outside Class |
|-----------------|-------------------------|-----------------------------|--------------------------|
| **private**     | ✅ Yes                  | ❌ No                        | ❌ No                   |
| **protected**   | ✅ Yes                  | ✅ Yes                       | ❌ No                   |
| **public**      | ✅ Yes                  | ✅ Yes                       | ✅ Yes                  |

---

## 🔎 5. Example: Basic Data Hiding in C++

```cpp
#include <iostream>
using namespace std;

class Car {
private:
    string name;  // Hidden data (private member)
    int year;     // Hidden data (private member)

public:
    // Setter function to update private members
    void setData(string carName, int carYear) {
        name = carName;
        year = carYear;
    }

    // Getter function to access private members
    void display() {
        cout << "Car Name: " << name << ", Year: " << year << endl;
    }
};

int main() {
    Car c1;
    c1.setData("Tesla", 2023);  // Set private members using setter
    c1.display();               // Access private members using getter

    // ❌ Error: Cannot access private members directly
    // cout << c1.name;

    return 0;
}
```

### ✅ Output:
```
Car Name: Tesla, Year: 2023
```

---

## 🔗 6. Relationship between Data Hiding and Data Encapsulation

- **Data Encapsulation**: The broader concept that bundles data (variables) and methods (functions) into a single unit (a class).
- **Data Hiding**: A feature within encapsulation that restricts direct access to the internal data using access modifiers (private, protected).

### 🧐 Analogy:
- **Data Encapsulation**: Hiding the implementation and exposing only what is necessary.
- **Data Hiding**: Specifically protecting the data by controlling how it’s accessed.

### Example:

```cpp
class Car {
private:
    int speed;  // Data Hiding (private member)

public:
    // Data Encapsulation (method controlling access)
    void setSpeed(int s) { speed = s; }  
    int getSpeed() { return speed; }     
};
```

---

## 📝 In Simple Terms:
- **Data Hiding**: How we protect data.
- **Data Encapsulation**: How we organize data and methods.

➡️ Without data encapsulation, there is no data hiding—but data encapsulation can exist without hiding data (using public variables).

