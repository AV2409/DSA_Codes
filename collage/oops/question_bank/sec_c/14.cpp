#include <bits/stdc++.h>
using namespace std;
class order
{
private:
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;

public:
    static float price;
    static int count;
    order()
    {
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;
    }
    void takeOrder()
    {
        count++;
        cout << "\nwant cream: type 1 else 0";
        cin >> flag1;
        cout << "\nwant milk: type 1 else 0";
        cin >> flag2;
        cout << "\nwant sugar: type 1 else 0";
        cin >> flag3;
        cout << "\nwant artificial: type 1 else 0";
        cin >> flag4;

        if (flag1 && flag2)
        {
            flag2 = 0;
        }

        if (flag3 && flag4)
        {
            flag4 = 0;
        }
    }

    void summary()
    {
        if (flag1)
        {
            cout << "\ncream ordered\t";
        }
        if (flag2)
        {
            cout << "milk ordered\t";
        }
        if (flag3)
        {
            cout << "sugar ordered\t";
        }
        if (flag4)
        {
            cout << "artificial sugar ordered\n";
        }
    }
};

float order::price = 1.25;
int order::count = 0;

int main()
{
    // order o1;
    // o1.takeOrder();
    // cout << endl;
    // o1.summary();
    int o_count = 0;
    order o[10];
    cout << order::count;
    bool flag = 1;
    while (flag && order::count < 10)
    {
        char ch;

        cout << "\n\nEnter n to stop or y";
        cin >> ch;
        if (ch == 'n')
        {
            flag = 0;
            break;
        }
        else
        {
            o[o_count++].takeOrder();
        }
    }

    for (int i = 0; i < order::count; i++)
    {
        o[i].summary();
        cout << endl;
    }
    cout << "\ntotal coffee=" << order::count;
    cout << endl
         << "total=" << order::price * order::count;
    return 0;
}