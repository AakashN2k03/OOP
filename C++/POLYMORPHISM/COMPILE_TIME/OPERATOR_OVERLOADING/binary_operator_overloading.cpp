// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class complex{
    private:
    int real;
    int img;
    
    public:
    complex(int r=0,int i=0)
    {
        real=r;
        img=i;
    }
    
    complex operator+(const complex& obj)
    {
        complex result;
        result.real=real+obj.real;
        result.img=img+obj.img;
        return result;
    }
    void display()
    {
      cout << real << " + " << img << "i" << endl;
    }
    
};

int main() {
     complex c1(4,1);
     complex c2(5,42);
     complex c3;
     c3=c1+c2;
     c3.display();
     

    return 0;
}
