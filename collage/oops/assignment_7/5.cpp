#include <bits/stdc++.h>
using namespace std;
class Complex
{
    int real;
    int img;

public:
    Complex(int a = 0, int b = 0) : real(a), img(b) {}

    Complex operator+(Complex &c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    void display()
    {
        cout << real << " + " << img << "i" << endl;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1 + c2;

    c3.display();

    return 0;
}