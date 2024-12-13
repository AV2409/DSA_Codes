#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor" << endl;
    }
    void display()
    {
        cout << "NON-VIRTUAL DISPLAY" << endl;
    }

    void display(int x)
    {
        cout << "Display int" << endl;
    }

    void display(int x, float y)
    {
        cout << "Display int, Float" << endl;
    }

    void display(float x, int y)
    {
        cout << "Display float,int" << endl;
    }

    virtual void show()
    {
        cout << "Base Show" << endl;
    }

    virtual void pure() = 0;

    virtual ~Base()
    {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived Constructor" << endl;
    }

    void show()
    {
        cout << "Derived Show" << endl;
    }

    void display()
    {
        cout << "Derived Display" << endl;
    }

    void print()
    {
        cout << "Derived Print" << endl;
    }

    void pure()
    {
        cout << "Pure Virtual Function" << endl;
    }
    ~Derived()
    {
        cout << "Derived Destructor" << endl;
    }
};

int main()
{
    // Base b;
    // b.display();
    // b.display(10);
    // b.display(10, 20.5);
    // b.display(20.5, 10);

    // Derived d;
    // d.show();
    // d.Base::show();

    // Base *ptr1 = new Base();
    // Derived *ptr2 = new Derived();
    // ptr1->show();
    // ptr2->show();
    // delete ptr1;
    // delete ptr2;
    // Derived *ptr2=new Base();//Error

    Base *ptr1 = new Derived();
    // Base *ptr1;
    // Derived obj;
    // ptr1 = &obj;
    ptr1->show();
    ptr1->display(); // display is not virtual
    ptr1->pure();
    delete ptr1; // if no virtual destructor-->only base class destructor will be called

    // ptr1->print()//error

    return 0;
}