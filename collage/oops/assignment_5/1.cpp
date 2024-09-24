#include <bits/stdc++.h>
using namespace std;

class parent
{
    int a;

public:
    parent()
    {
        a = 10;
        cout << "parent constructor" << endl;
    }
    void display()
    {
        cout << a << endl;
    }
    ~parent()
    {
        cout << "parent destructor" << endl;
    }
};

class child : public parent
{
    int b;

public:
    child()
    {
        b = 5;
        cout << "child constructor" << endl;
    }
    void print()
    {
        cout << b << endl;
    }
    ~child()
    {
        cout << "child destructorr" << endl;
    }
};

int main()
{
    child ch;
    ch.display();
    ch.print();

    return 0;
}