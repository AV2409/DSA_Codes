#include <bits/stdc++.h>
using namespace std;

class Distance
{
    float feet;

public:
    Distance(float f = 0)
    {
        feet = f;
    }
    Distance operator+(Distance d)
    {
        Distance temp;
        temp.feet = this->feet + d.feet;
        return temp;
    }

    Distance operator-(Distance d)
    {
        Distance temp;
        temp.feet = this->feet - d.feet;
        return temp;
    }

    Distance operator*(Distance d)
    {
        Distance temp;
        temp.feet = this->feet * d.feet;
        return temp;
    }

    Distance operator/(Distance d)
    {
        Distance temp;
        temp.feet = this->feet / d.feet;
        return temp;
    }

    bool operator==(Distance d)
    {
        if (this->feet == d.feet)
        {
            return 1;
        }
        return 0;
    }

    bool operator>=(Distance d)
    {
        if (this->feet >= d.feet)
        {
            return 1;
        }
        return 0;
    }

    bool operator<=(Distance d)
    {
        if (this->feet <= d.feet)
        {
            return 1;
        }
        return 0;
    }

    bool operator&&(Distance d)
    {
        if (this->feet && d.feet)
        {
            return 1;
        }
        else
            return 0;
    }

    bool operator||(Distance d)
    {
        if (this->feet || d.feet)
        {
            return 1;
        }
        else
            return 0;
    }
    void show()
    {
        cout << this->feet << " feet" << endl;
    }
};

int main()
{
    Distance d1(10);
    Distance d2(5);
    Distance d3(10);
    Distance d5;

    Distance d4 = d1 + d2;
    d4.show();

    d4 = d1 - d2;
    d4.show();

    d4 = d1 * d2;
    d4.show();

    d4 = d1 / d2;
    d4.show();

    cout << "Equality: " << (d1 == d2) << endl;
    cout << "Equality: " << (d1 == d3) << endl;

    cout << "d1 >= d2: " << (d1 >= d2) << endl;
    cout << "d2 >= d3: " << (d2 >= d3) << endl;

    cout << "d1 <= d2: " << (d1 <= d2) << endl;
    cout << "d2 <= d3: " << (d2 <= d3) << endl;

    cout << "d1 && d5: " << (d1 && d5) << endl;
    cout << "d1 || d5: " << (d1 || d5) << endl;
    return 0;
}