#include <iostream>
using namespace std;

class Rectangle{
    private:
    int length;
    int breadth;
    
    public:
    
    Rectangle(int x,int y):length(x),breadth(y){}
    
    friend void area(Rectangle rec);
};
void area(Rectangle rec)
{
    cout<<"AREA OF THE RECTANGLE "<<rec.length * rec.breadth;
}

int main() {
Rectangle r(5,5);
area(r);

    return 0;
}
