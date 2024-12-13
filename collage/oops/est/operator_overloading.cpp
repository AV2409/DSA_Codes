#include <bits/stdc++.h>
using namespace std;
//+

// for concatination
// strcpy(str,x1);
// strcat(str," ");
// strcat(str,x2);
class Complex
{
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    void show()
    {
        cout << real << " + " << img << "i" << endl;
    }

    // Complex operator+(Complex c)
    // {
    //     Complex temp;
    //     temp.real = this->real + c.real;
    //     temp.img = this->img + c.img;
    //     return temp;
    // }

    friend Complex operator+(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

// unary operator ++ and -- (prefix and postfix)
class demo
{
    int i;

public:
    demo(int x = 0)
    {
        i = x;
    }

    void show()
    {
        cout << i << endl;
    }

    void operator++()
    {
        ++i;
    }

    void operator++(int)
    {
        i++;
    }

    friend void operator--(demo &d);
    friend void operator--(demo &d, int);
    // demo operator++(int)
    // {
    //     demo temp;
    //     temp.i = i--;
    //     return temp;
    // }
};
void operator--(demo &d)
{
    --d.i;
}
void operator--(demo &d, int)
{
    d.i--;
}

// d2=d1+2--> member and friend both
// d2=2+d1--> friend only
class demo1
{
    int i;

public:
    demo1(int x = 0)
    {
        i = x;
    }

    void show()
    {
        cout << i << endl;
    }

    demo1 operator+(int x)
    {
        demo1 temp;
        temp.i = i + x;
        return temp;
    }
    //= d1=d2  d1 calling object,d2 argument
    void operator=(demo1 dd)
    {
        i = dd.i;
    }

    friend demo1 operator+(int x, demo1 d);
};

demo1 operator+(int x, demo1 d)
{
    demo1 temp;
    temp.i = x + d.i;
    return temp;
}

int main()
{
    Complex c1(10, 5);
    Complex c2(2, 7);
    Complex c3 = c1 + c2;
    c3.show();

    demo d1;
    d1.show();
    ++d1;
    d1.show();
    d1++;
    d1.show();
    --d1;
    d1.show();
    d1--;
    d1.show();
    // demo d1;
    // d1.show();
    // demo d2 = d1++;
    // d1.show();
    // d2.show();

    demo1 dd1(5), dd2, dd3;
    dd1.show();
    dd2 = dd1 + 2;
    dd2.show(); // 7
    dd3 = 7 + dd1;
    dd3.show(); // 12

    demo1 dd4;
    dd4 = dd3;
    dd4.show(); // 12

    return 0;
}