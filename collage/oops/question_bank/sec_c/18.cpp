#include <bits/stdc++.h>
using namespace std;
class Example
{
    static int x;

public:
    static void display()
    {
        cout << endl
             << x;
    }
};

int Example::x = 1;
int main()
{
    Example e1, e2;
    e1.display();
    e2.display();

    return 0;
}