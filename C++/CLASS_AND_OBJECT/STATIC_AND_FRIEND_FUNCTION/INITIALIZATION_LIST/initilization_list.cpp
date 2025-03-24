#include <iostream>
using namespace std;

class Car
{
    private:
    int year;
    string name;
    string model;
    
    public:
    // USE INITIALIZATION LIST ONLY ON CONSTRUCTOR

    Car(int x,string y,string z):year(x),name(y),model(z){}
   
    void display()
    {
        cout<<"My car => "<<name<<" "<<model<<" "<<year;
    }
};

int main() {
   Car c1(1998,"Audi","A2");
   c1.display();

    return 0;
}
