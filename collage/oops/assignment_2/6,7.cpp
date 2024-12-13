#include <bits/stdc++.h>
using namespace std;

class demo
{
public:
    static int i;
    void display();
    static void print()
    {
        cout << i << endl;
    }
};
int x = 100;
int demo::i = 1;
void demo::display()
{
    cout << i;
}

namespace A
{
    int y = 0;
    void show()
    {
        cout << "A";
    }

}
namespace B
{
    int y = 5;
    void show()
    {
        cout << "B";
    }

}
using namespace B;
int main()
{
    int x = 50;
    cout << x << endl;
    cout << ::x << endl;
    demo::print();
    // std::cout << demo::i << endl;

    cout << A::y << endl;
    cout << B::y << endl;
    show();
    cout << endl
         << y << endl;

    A::show();
    cout << endl;
    B::show();

    return 0;
}