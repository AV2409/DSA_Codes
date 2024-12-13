#include <bits/stdc++.h>
using namespace std;

class base
{
public:
    base()
    {
        cout << "Base class constructor called" << endl;
    }

    virtual ~base()
    {
        cout << "Base class destructor called" << endl;
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "Derived class constructor called" << endl;
    }

    ~derived()
    {
        cout << "Derived class destructor called" << endl;
    }
};

int main()
{
    base *ptr = new derived();

    delete ptr; // This will call the destructor of base class

    // Output when no virtual destructor is used
    // Base class constructor called
    //  Derived class constructor called
    //  Base class destructor called

    // Output when virtual destructor is used
    // Base class constructor called
    // Derived class constructor called
    // Derived class destructor called
    // Base class destructor called
    return 0;
}