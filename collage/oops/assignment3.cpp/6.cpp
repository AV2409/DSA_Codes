#include <bits/stdc++.h>
using namespace std;

class demo
{
private:
    int a;

public:
    demo(int a)
    {
        this->a = a;
    }

    void display()
    {
        cout << this->a;
    }

    inline int cube()
    {
        return a * a * a;
    }
};

int main()
{
    demo d1(5);
    d1.display();

    cout << endl
         << d1.cube();
    return 0;
}