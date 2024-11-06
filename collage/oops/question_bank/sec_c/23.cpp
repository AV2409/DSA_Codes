#include <bits/stdc++.h>
using namespace std;

class TIME
{
    int hour;
    int min;
    int sec;

public:
    TIME()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    TIME(TIME &d1)
    {
        this->hour = d1.hour;
        this->min = d1.min;
        this->sec = d1.sec;
    }

    void set()
    {
        int h, m, s;
        cin >> h >> m >> s;
        hour = h;
        min = m;
        sec = s;
    }
    void display()
    {
        cout << this->hour << "-" << this->min << "-" << this->sec;
    }

    TIME diff(TIME t)
    {
        TIME temp;
        long int t1 = (this->hour * 60 * 60) + (this->min * 60) + (this->sec);
        long int t2 = (t.hour * 60 * 60) + (t.min * 60) + (t.sec);
        long int diff;
        if (t1 > t2)
        {
            diff = t1 - t2;
        }
        else
        {
            diff = t2 - t1;
        }

        temp.hour = diff / 3600;
        temp.min = (diff - temp.hour * 60 * 60) / 60;
        temp.sec = diff % 60;
        return temp;
    }
};

int main()
{
    TIME t1;
    TIME t2;

    t1.set();
    t2.set();
    TIME t3 = t1.diff(t2);
    t3.display();
    return 0;
}