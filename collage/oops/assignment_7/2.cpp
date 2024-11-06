#include <bits/stdc++.h>
using namespace std;
class Distance
{
    int x;
    int y;

public:
    Distance(int a = 0, int b = 0) : x(a), y(b) {}

    Distance operator+(Distance &c)
    {
        Distance temp;
        temp.x = x + c.x;
        temp.y = y + c.y;
        return temp;
    }

    void display()
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    Distance c1(3, 4);
    Distance c2(5, 6);

    Distance c3 = c1 + c2;

    c3.display();

    return 0;
}