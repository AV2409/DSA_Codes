#include <bits/stdc++.h>
using namespace std;

class demo
{
private:
    int a;

public:
    demo()
    {
        a = 0;
    }
    demo(int a)
    {
        this->a = a;
    }

    void display()
    {
        cout << this->a;
    }

    demo update_by_value(demo d)
    {
        d.a++;
        return d;
    }
    demo update_by_refrence(demo &d)
    {
        d.a++;
        return d;
    }
};

int main()
{
    demo d1(5);
    d1.display();

    cout << endl
         << "pass by value: ";
         
    d1.update_by_value(d1);
    d1.display();
    d1.update_by_refrence(d1);
    cout<<endl<<"pass by refrence: ";
    d1.display();
    return 0;
}