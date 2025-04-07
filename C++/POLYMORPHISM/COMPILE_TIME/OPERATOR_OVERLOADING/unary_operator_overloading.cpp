#include <iostream>
using namespace std;

class increment {
private:
    int age;

public:
    // Default constructor
    increment() : age(0) {}

    // Parameterized constructor
    increment(int a) : age(a) {}

    // Overload prefix ++ operator
    void operator++() { //pre
        ++age;
    }
       void operator++(int) { //post
        ++age;
    }

    void display() {
        cout << "Age : " << age << endl;
    }
};

int main() {
    increment inc1;
    increment inc2(15);

    ++inc1;   // Prefix increment
    ++inc2;
    inc2++;

    inc1.display();  // Age : 1
    inc2.display();  // Age : 16

    return 0;
}

// The int in void operator++(int) is just a dummy parameter. It doesn't take any real value. It is only used to differentiate between:

// ++obj; → prefix

// obj++; → postfix

