#include <bits/stdc++.h>
using namespace std;

class B;
class A
{
private:
    int a;

public:
    A()
    {
        this->a = 0;
    }
    void set_data(int a)
    {
        this->a = a;
    }

    void display()
    {
        cout << this->a;
    }

    friend void swap(A aa, B bb);
};

class B
{
private:
    int b;

public:
    B()
    {
        this->b = 0;
    }
    void set_data(int b)
    {
        this->b = b;
    }

    void display()
    {
        cout << this->b;
    }

    friend void swap(A aa, B bb);
};

void swap(A aa, B bb)
{
    int temp = aa.a;
    aa.a = bb.b;
    bb.b = temp;
}

int main()
{
    // int n;
    // cin >> n;
    A a;
    B b;

    a.set_data(5);
    b.set_data(9);

    cout << "Before swapping: ";
    cout << endl
         << "a=";
    a.display();
    cout << " " << "b=";
    b.display();

    swap(a, b);
    cout << "\nAfter swapping: ";
    cout << endl
         << "a=";
    a.display();
    cout << " " << "b=";
    b.display();

    return 0;
}