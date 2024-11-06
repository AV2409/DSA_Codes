#include <bits/stdc++.h>
using namespace std;
class date
{
private:
    int month;
    int day;
    int year;
    static char ch;

    void setMonth(int x)
    {
        if (x >= 12)
        {
            month = 12;
        }
        else
        {
            month = x;
        }
    }

    void setDay(int x)
    {
        if (x >= 31)
        {
            day = 31;
        }
        else
        {
            day = x;
        }
    }

    void setYear(int x)
    {
        year = x;
    }

public:
    void setDate(int x, int y, int z)
    {
        setDay(x);
        setMonth(y);
        setYear(z);
    }

    void showDate()
    {
        cout << endl
             << day << ch << month << ch << year;
    }
};

char date::ch = '/';

int main()
{
    date d[5];

    for (int i = 0; i < 5; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[i].setDate(x, y, z);
    }

    for (int i = 0; i < 5; i++)
    {
        d[i].showDate();
    }
    return 0;
}