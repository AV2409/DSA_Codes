#include <bits/stdc++.h>
using namespace std;

class Test
{
    int x;
    int y;

public:
    Test(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    void display()
    {
        cout << this->x << endl;
        cout << this->y << endl;
    }

    friend void operator-(Test &t);
};

void operator-(Test &t)
{
    t.x = -t.x;
    t.y = -t.y;
}

int main()
{
    Test t1(10, 20);
    t1.display();
    cout << endl;
    -t1;
    t1.display();
    return 0;
}