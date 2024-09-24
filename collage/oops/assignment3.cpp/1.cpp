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
};

int main()
{
    demo d1(5);
    d1.display();

    demo *d2 = new demo(10);
    cout<<endl;
    d2->display();
    return 0;
}