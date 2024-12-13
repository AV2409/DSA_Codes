#include <bits/stdc++.h>
using namespace std;

class base
{
public:
    virtual void show()
    {
        cout << "Base class" << endl;
    }
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
    base obj1;
    derived obj2;
    ptr = &obj1;
    ptr->show(); // Output: Base class
    ptr = &obj2;
    ptr->show(); // Output: Base class if no virtiual function is used
    // ptr->display();//cannot be accessed by base pointer
    return 0;
}