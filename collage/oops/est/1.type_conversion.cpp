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

    // can also be done by using =

    void operator=(int x)
    {
        hr = x / 60;
        min = x % 60;
    }
};

// celcius to fahrenheit
class temp
{
    float far;

public:
    temp()
    {
        far = 0;
    }

    temp(float x)
    {
        far = (1.8 * x) + 32;
    }

    void show()
    {
        cout << far << "F" << endl;
    }
};
int main()
{
    int duration = 365;
    Time t;
    t = duration;
    t.show();

    float t_c = 23;
    temp t1;
    t1 = t_c;
    t1.show();

    return 0;
}