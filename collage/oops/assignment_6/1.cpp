#include <bits/stdc++.h>
using namespace std;
class demo
{
public:
    void print()
    {
        cout << endl
             << "No arguments";
    }

    void print(int a)
    {
        cout << endl
             << "single int argument";
    }

    void print(double a)
    {
        cout << endl
             << "single double arguments";
    }

    void print(int a, int b)
    {
        cout << endl
             << "two arguments";
    }
};

class base
{
public:
    virtual void print()
    {
        cout << endl
             << "base";
    }
};

class derived1 : public base
{
public:
    void print()
    {
        cout << endl
             << "derived1";
    }
};

class derived2 : public base
{
public:
    void print()
    {
        cout << endl
             << "derived2";
    }
};

int main()
{
    demo d1;

    d1.print();
    d1.print(5);
    d1.print(5.5);
    d1.print(1, 2);

    base b1;
    derived1 dd1;
    derived2 dd2;
    b1.print();
    dd1.print();
    dd2.print();

    base *pb = &b1;

    pb->print();
    pb = &dd1;
    pb->print();
    pb = &dd2;
    pb->print();

    return 0;
}