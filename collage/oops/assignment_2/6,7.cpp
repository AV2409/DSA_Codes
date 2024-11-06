#include <bits/stdc++.h>
using namespace std;

class demo
{
public:
    static int i;
    void display();
};
int x = 100;
int demo::i = 1;
void demo::display()
{
    cout << i;
}

namespace A
{
    int x = 0;
    void show()
    {
        cout << "A";
    }

}
namespace B
{
    int x = 5;
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

    // std::cout << demo::i << endl;

    cout << A::x << endl;
    cout << B::x << endl;
    show();
    cout << endl
         << x << endl;

    A::show();
    cout << endl;
    B::show();

    return 0;
}