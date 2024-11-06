#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Overloaded static functions in Base class
    void display()
    {
        cout << "Base: display() with no arguments" << endl;
    }

    void display1(int x)
    {
        cout << "Base: display() with int argument: " << x << endl;
    }
};

// Derived class
class Derived : public Base
{
public:
    // Redefining display() in the derived class
    void display()
    {
        cout << "Derived: display() with no arguments" << endl;
    }
};

int main()
{
    Derived d;

    // Call the redefined function in Derived
    d.display(); // Calls Derived::display()

    // The following line will cause a compile-time error
    // because the int version of display() from Base is hidden
    // d.display(10); // Error: no matching function

    // To access the hidden Base class functions, we use the scope resolution operator
    // Base::display(10); // Calls Base::display(int)

    return 0;
}
