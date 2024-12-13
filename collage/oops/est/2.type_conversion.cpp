// 1. basic to class--> constructors
// 2. class to basics--> type casting
// 3. class to class--> constructor or type conversion

#include <bits/stdc++.h>
using namespace std;

class Time
{
    int hr;
    int min;

public:
    Time(int x = 0)
    {
        hr = x / 60;
        min = x % 60;
    }

    void show()
    {
        cout << hr << " : " << min << endl;
    }

    operator int()
    {
        return hr * 60 + min;
    }
};

class dist
{
    float m;

public:
    dist(float x = 0)
    {
        m = x;
    }

    void show()
    {
        cout << m << "m" << endl;
    }

    operator float()
    {
        return m / 1000;
    }
};
int main()
{
    int duration = 365;
    Time t;
    t = duration;
    t.show();

    int dur = t;
    cout << dur << endl;

    dist d1(5670);
    d1.show();
    float km = d1;
    cout << km << endl;

    return 0;
}