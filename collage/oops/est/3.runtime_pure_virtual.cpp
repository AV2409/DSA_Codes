#include <bits/stdc++.h>
using namespace std;

class base
{
public:
    virtual void show() = 0;
};

class derived : public base
{
public:
    void show()
    {
        cout << "Derived class" << endl;
    }

    void display()
    {
        cout << "derived display";
    }
};

int main()
{
    base *ptr;
    // base obj1;//not possible
    derived obj2;
    ptr = &obj2;
    ptr->show();
    // ptr->display();//cannot be accessed by base pointer
    return 0;
}