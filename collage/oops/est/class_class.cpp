// 1. basic to class--> constructors
// 2. class to basics--> type casting
// 3. class to class--> constructor or type conversion
// polar-rectangular
#include <bits/stdc++.h>
using namespace std;
class rectangular
{
    float a;
    float b;

public:
    rectangular(float x = 0, float y = 0)
    {
        a = x;
        b = y;
    }

    void show()
    {
        cout << a << ", " << b << endl;
    }
};
class Polar
{
    float r;
    float angle;

public:
    Polar(float x = 0, float y = 0)
    {
        r = x;
        angle = y;
    }

    void show()
    {
        cout << r << ", " << angle << endl;
    }

    operator rectangular()
    {
        float x = r * cos(angle);
        float y = r * sin(angle);

        rectangular r1(x, y);
        return r1;
    }
};

class Line
{
    float l;

public:
    Line(float x = 0)
    {
        l = x;
    }

    void show()
    {
        cout << " length = " << l << endl;
    }
};

class Circle
{
    float r;

public:
    Circle(float x = 0)
    {
        r = x;
    }

    void show()
    {
        cout << " radius = " << r << endl;
    }

    operator Line()
    {
        float x = 2 * 3.14 * r;
        Line l1(x);
        return l1;
    }
};

int main()
{
    Polar p(23, 1.5);
    rectangular r;
    r = p;
    r.show();

    Circle c1(4);
    Line l1 = c1;
    l1.show();
    return 0;
}