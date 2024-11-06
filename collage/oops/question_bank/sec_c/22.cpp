#include <bits/stdc++.h>
using namespace std;

class DOB
{
    int year;
    int month;
    int day;

public:
    DOB()
    {
    }
    DOB(DOB &d1)
    {
        this->year = d1.year;
        this->month = d1.month;
        this->day = d1.day;
    }

    void set(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void display()
    {
        cout << this->year << "/" << this->month << "/" << this->day;
    }

    void compute_age()
    {
        int y = 2021 - this->year;
        int m = 7 - this->month;
        int d = 8 - this->day;

        if (m < 0 || (m == 0 && d < 0))
        {
            y--;
        }

        cout << y;
    }
};

int main()
{
    DOB d1;
    d1.set(2005, 7, 9);
    d1.compute_age();

    return 0;
}