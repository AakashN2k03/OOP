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

## 📚 NOTE
- Abstraction is more about hiding complexity and showing only what's necessary to the outside world.
- Abstraction is implemented through encapsulation.



