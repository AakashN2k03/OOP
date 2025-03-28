// ENCAPSULATION

#include <iostream>
using namespace std;

class mobile {
private:  // Explicitly declaring private access (data hiding)
    string name; 
    int model;
    float price;

public:
    // Constructor with initializer list
    mobile(string mobile_name, int model_no, float cost) 
        : name(mobile_name), model(model_no), price(cost) {}

    // Data abstraction through this method
    void get_mobile() {
        cout << "MOBILE: " << name << endl;
        cout << "MODEL NO: " << model << endl;
        cout << "PRICE: " << price << endl;
    }
};

int main() {
    mobile m1("OnePlus", 11, 425000.00);
    m1.get_mobile();

    return 0;
}
