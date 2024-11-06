#include <bits/stdc++.h>
using namespace std;

class base
{
    int a;

public:
    base()
    {
        a = 0;
    }
    virtual void print() = 0;
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
    derived1 dd1;
    derived2 dd2;
    dd1.print();
    dd2.print();

    base *pb;
    pb = &dd1;
    pb->print();
    pb = &dd2;
    pb->print();

    return 0;
}