#include <bits/stdc++.h>
using namespace std;
class DM;
class DB
{
    int feet;
    int inches;

public:
    DB(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    friend void addition(DB d1, DM d2);
};

class DM
{
    int meter;
    int centimeter;

public:
    DM(int m, int cm)
    {
        meter = m;
        centimeter = cm;
    }
    friend void addition(DB d1, DM d2);
};

void addition(DB d1, DM d2)
{
    cout << "\nEnter the unit in which you want the result";
    char ch;
    cin >> ch;
    if (ch == 'm')

    {
        float n1 = d1.feet * 12 + d1.inches;

        float n2 = d2.meter * 100 + d2.centimeter;

        float n3 = n1 * 2.54;

        float result = n3 + n2;

        cout << "meter=" << (int)result / 100 << "centimeter=" << (int)result % 100;
    }

    else
    {
        float n1 = d1.feet * 12 + d1.inches;

        float n2 = d2.meter * 100 + d2.centimeter;

        float n3 = n2 / 2.54;

        float result = n3 + n1;

        cout << "feet=" << (int)result / 12 << "inches=" << (int)result % 12;
    }
}

int main()
{
    DM m(5, 4);
    DB n(2, 3);

    addition(n, m);

    return 0;
}