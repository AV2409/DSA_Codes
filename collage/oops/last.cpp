#include <bits/stdc++.h>
using namespace std;
class demo
{
    int a;
    int b;

public:
    static void display()
    {
        cout << "this is first before inheritance\n";
    }

    ~demo()
    {
        cout << "bye\t";
    }
};

class B : public demo
{
public:
    static void display()
    {
        cout << "After overiding";
    }
};
int main()
{
    B::display();
    demo::display();

    B b;
    b.display();
    b.demo::display();

    return 0;
}