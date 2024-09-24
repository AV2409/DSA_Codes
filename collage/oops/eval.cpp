#include <bits/stdc++.h>
using namespace std;

class demo
{

    int a;
    int b;

public:
    static int counter;
    demo(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
        counter++;
    }
    void set_value(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    void display()
    {
        cout << "counter: " << counter << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

    static void update()
    {
        counter++;
    }

    static void display_counter()
    {
        cout << "counter: " << counter << endl;
    }

    demo make_double(demo temp)
    {
        temp.a = this->a * 2;
        temp.b = this->b * 2;
        return temp;
    }
};

class Test
{
    const int i;
    int x;

public:
    Test(int x) : i(x) {} // initialized using constructor

    void show() { cout << "i=" << i << endl; }

    void func() const
    {
        // x = 0; // [Error] can’t modify object variable
    }
};

// void fun() const{}//const function should be a member function
//[Error] non-member function 'void fun()' cannot have cv-qualifier

class Test1
{
public:
    int i;
    Test1() : i(0) {}
    void setValue(int a) { i = a; }
};

class A
{
    int i;

public:
    A()
    {
        i = 5;
    }
    friend class B;
};
class B
{
public:
    void show(A a)
    {
        cout << "i=" << a.i << endl;
    }
};

int demo::counter = 0;

int main()
{
    // static functions
    demo::display_counter();
    demo::update();
    demo::display_counter();

    // static variable

    demo::counter = 0;
    cout << demo::counter << endl;
    demo d1;
    d1.display();
    demo d2(5, 6);
    cout << demo::counter << endl;
    d2.display();
    d2.update();
    d2.display_counter();

    d2 = d2.make_double(d2);
    d2.display();

    // const variable
    const int i = 10;
    const int j = i + 10; // works fine

    // i++;                  // this leads to Compile time error

    cout << i << " " << j << endl;

    // const class member
    Test t(190);
    t.show();

    const Test1 t1; // calls default constructor
                    // t1.i = 5; // [Error]
    // t1.setValue(5); // [Error]
    A a;
    B b;
    b.show(a);
    return 0;
}