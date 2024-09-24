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

    friend int sum(A &aa, B &bb);
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

    friend int sum(A &aa, B &bb);
};

int sum(A &aa, B &bb)
{
    return aa.a + bb.b;
}

int main()
{
    int n;
    cin >> n;
    A a;
    B b;
    
    a.set_data(5);
    b.set_data(9);
    
    cout<<sum(a,b);

    return 0;
}