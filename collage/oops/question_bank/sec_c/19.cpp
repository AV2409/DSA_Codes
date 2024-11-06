#include <bits/stdc++.h>
using namespace std;

class TC;
class TF
{
    float f;

public:
    TF(float n = 0)
    {
        f = n;
    }

    void setTemp()
    {
        float n;
        cin >> n;
        f = n;
    }
    friend TC addTemp(TF t1, TC t2);
};

class TC
{
    float c;

public:
    TC(float n = 0)
    {
        c = n;
    }

    void setTemp()
    {
        float n;
        cin >> n;
        c = n;
    }
    void display()
    {
        cout << "temp=" << c;
    }

    friend TC addTemp(TF t1, TC t2);
};

TC addTemp(TF t1, TC t2)
{
    TC temp;
    float f_to_c = (t1.f - 32) / 1.8;
    float c = t2.c;
    temp.c = f_to_c + c;
    return temp;
}

int main()
{
    TC t2;
    TF t1;

    t1.setTemp();
    t2.setTemp();
    TC res = addTemp(t1, t2);
    res.display();

    return 0;
}