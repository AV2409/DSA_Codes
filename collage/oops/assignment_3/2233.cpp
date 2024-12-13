#include <bits/stdc++.h>
using namespace std;
class B;
class A
{
    int a;

public:
    A(int n = 0)
    {
        a = n;
    }

    int get()
    {
        return a;
    }

    friend void swap(A &num1, B &num2);
    friend void add(A &num1, B &num2);
};

class B
{
    int b;

public:
    B(int n = 0)
    {
        b = n;
    }

    int get()
    {
        return b;
    }

    inline int cube()
    {
        return b * b * b;
    }

    friend void swap(A &num1, B &num2);
    friend void add(A &num1, B &num2);
};

void swap(A &num1, B &num2)
{
    int temp = num1.a;
    num1.a = num2.b;
    num2.b = temp;
}

void add(A &num1, B &num2)
{
    cout << "\naddition: " << num1.a + num2.b;
}

int main()
{
    A x(7);
    B y(9);

    cout << "Before swapping: ";
    cout << endl
         << "a=" << x.get();
    cout << " " << "b=" << y.get();

    swap(x, y);
    cout << "\nAfter swapping: ";
    cout << endl
         << "a=" << x.get();
    cout << " " << "b=" << y.get();

    add(x, y);
    cout << "\ncube=" << y.cube();
    return 0;
}