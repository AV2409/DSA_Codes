#include <bits/stdc++.h>
using namespace std;

class A
{
    int a;

protected:
    int a1;

public:
    A()
    {
        a = 10;
    }
    void display()
    {
        cout << a << endl;
    }
    ~A()
    {
        a = 10;
    }
};

class B : public A
{
    int b;

public:
    B()
    {
        b = 5;
    }
    void print()
    {
        cout << b << endl;
    }
    ~B()
    {
        b = 5;
    }
};

class C : public A, public B
{
    int c;

public:
    C()
    {
        c = 55;
    }
    void print_c()
    {
        cout << c << endl;
    }
};

class D : public A
{
    int d;

public:
    D()
    {
        d = 555;
    }
    void print_d()
    {
        cout << d << endl;
    }
};

class E : public B
{
    int e;

public:
    E()
    {
        e = 444;
    }
    void print_e()
    {
        cout << e << endl;
    }
};

class F : public B,public D
{
    int f;

public:
    F()
    {
        f = 3333;
    }
    void print_f()
    {
        cout << f << endl;
    }
};

int main()
{
    // // Single inheritance
    // B ch;
    // ch.display();
    // ch.print();

    // // Multiple inheritance

    // C cc;
    // cc.display();
    // cc.print();
    // cc.print_c();

    // //heirarichal
    // D dd;
    // dd.display();
    // dd.print_d();

    // //mulatilevel

    // E ee;
    // ee.display();
    // ee.print();
    // ee.print_e();

    //multiple
    
    F ff;
    
    ff.B::display();
    ff.D::display();
    ff.print();
    ff.print_d();
    ff.print_f();
    return 0;
}