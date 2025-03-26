# Data Abstraction in C++

## 📌 What is Data Abstraction?

**Definition:**
Data abstraction means hiding complex implementation details and showing only the necessary information to the user.

**Real-life Example:**
Imagine a car—you can drive it by using the steering wheel and pedals without knowing how the engine works internally.

**In C++:**
You use **classes** and **access specifiers** (`private`, `public`, `protected`) to hide implementation details and expose essential methods.

---

## 🧑‍💻 Example 1: Bank Account Simulation

```cpp
#include<iostream>
using namespace std;

// Encapsulation (class wraps data and methods)
class BankAccount {
private:
    // Data Hiding (cannot directly access these variables)
    string accountNumber;
    double balance;

public:
    // Constructor (initialize account)
    BankAccount(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Data Abstraction (simplified interface for the user)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }

    void displayBalance() {
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    BankAccount myAccount("12345", 1000);

    myAccount.deposit(500);  // Valid access (via public method)
    myAccount.displayBalance();

    // myAccount.balance = 5000; // ❌ ERROR: balance is private (Data Hiding)

    return 0;
}
```

---

## 🔍 Key Differences Between Data Hiding and Data Abstraction

| Feature             | Data Hiding                      | Data Abstraction                  |
|---------------------|----------------------------------|-----------------------------------|
| **Focus**           | Hiding how data is stored/modified. | Hiding how a function works internally. |
| **What is Hidden?** | Data members (variables in a class). | Implementation details (method logic). |
| **Access Control**  | Uses `private` and `protected` keywords. | Uses `public` methods to expose necessary features. |
| **Purpose**         | To protect sensitive data.         | To simplify user interaction with complex systems. |
| **User Interaction**| Users cannot access private data directly. | Users see only the method interface, not the logic. |
| **Example**         | Hiding the balance variable in a bank account. | Exposing the `deposit()` method while hiding logic. |

**Summary:** Data Hiding is about **security**, while Data Abstraction is about **simplicity**.

---

## 🦸‍♂️ Example 2: Omnitrix Transformation (Ben 10)

```cpp
#include<iostream>
using namespace std;

class Omnitrix {
private:
    // Data Hiding: Ben's secret alien forms
    string alienForm;

public:
    // Constructor to initialize Omnitrix
    Omnitrix() {
        alienForm = "Human";  // Default form
    }

    // Data Abstraction: Ben can only transform through this method
    void transform(string alien) {
        if (alien == "Heatblast" || alien == "XLR8" || alien == "Four Arms") {
            alienForm = alien;
            cout << "🔄 Ben transforms into: " << alienForm << "!" << endl;
        } else {
            cout << "❌ Unknown Alien Form!" << endl;
        }
    }

    // Display current form (Abstraction)
    void showCurrentForm() {
        cout << "🟢 Current Form: " << alienForm << endl;
    }
};

int main() {
    Omnitrix ben10;  // Ben's Omnitrix

    // ❌ Data Hiding: Cannot access 'alienForm' directly
    // cout << ben10.alienForm; // ERROR!

    // ✅ Data Abstraction: Using methods to interact
    ben10.showCurrentForm();   // Shows default form
    ben10.transform("Heatblast");  // Transforms into Heatblast
    ben10.showCurrentForm();   // Display new form

    ben10.transform("Ghostfreak"); // Invalid transformation

    return 0;
}
```

---

## 📚 Conclusion

- **Data Abstraction** hides the **implementation** but exposes essential **functionality**.
- **Data Hiding** protects **sensitive data** by restricting direct access.
- **Data Encapsulation** the **wrapping up of data and information in a single unit**.
In Object Oriented Programming, encapsulation is defined as binding together the data member and the member functions which comprises  **Data Abstraction** and **Data Hiding**



