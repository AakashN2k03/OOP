# Getters and Setters in Object-Oriented Programming

## 📌 Introduction
Getters and Setters are special methods used to **access** and **modify** the private data of an object in object-oriented programming (OOP). They enforce controlled access to internal data, ensuring **data integrity**, **access control**, and **flexibility**.

---

## 📚 What are Getters and Setters?

### 1. **Getters**
A **Getter** method allows you to **retrieve** or **access** the value of a private data member from outside the class. It usually returns the value of a private variable.

### 2. **Setters**
A **Setter** method allows you to **modify** or **update** the value of a private data member from outside the class. It typically accepts a parameter to set the value of a private variable.

---

## ✅ Why Use Getters and Setters?

1. **Data Integrity**
   - Validate or manipulate the data before it is set or retrieved.
   - Ensure that only **valid** data is stored, preventing invalid states.

2. **Access Control**
   - Restrict **direct** access to private data.
   - Control **how** and **when** data is accessed or updated.

3. **Flexibility**
   - Modify internal implementation (e.g., add validation or logging) **without changing** the public interface.

---

## 📊 Advantages of Using Getters and Setters

| Feature         | Benefit                                 |
|-----------------|----------------------------------------|
| **Encapsulation** | Controls access to internal object state |
| **Validation**   | Ensures only valid data is accepted      |
| **Flexibility**  | Internal changes do not affect external code |

---

## 🧾 Example: Implementing Getters and Setters

### Example: Temperature Control System (C++)
```cpp
#include<iostream>
using namespace std;

class TemperatureSensor {
private:
    int temperature;  // Private data member

public:
    // Setter with validation
    void setTemperature(int temp) {
        if (temp >= 0 && temp <= 50) {
            temperature = temp;
        } else {
            cout << "❌ Invalid Temperature!" << endl;
        }
    }

    // Getter to access temperature
    int getTemperature() {
        return temperature;
    }
};

int main() {
    TemperatureSensor sensor;

    sensor.setTemperature(25);  // Valid temperature
    cout << "Current Temperature: " << sensor.getTemperature() << "°C" << endl;

    sensor.setTemperature(100); // Invalid temperature
    cout << "Current Temperature: " << sensor.getTemperature() << "°C" << endl;

    return 0;
}
```

---

## 🔍 Key Takeaways

- **Getters**: Retrieve the value of private variables.
- **Setters**: Modify the value of private variables.
- Ensures **data integrity**, **access control**, and **flexibility**.

