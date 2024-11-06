#include <bits/stdc++.h>
using namespace std;
class GrossItem
{
private:
    int item_number;
    int price;
    int qty;
    int total;

    void input_number()
    {
        int x;
        bool flag = 1;
        while (flag)
        {
            cout << "\nenter the number: ";
            cin >> x;
            if (x >= 1000 && x <= 9999)
            {
                item_number = x;
                flag = 0;
                break;
            }
        }
    }

    void input_price()
    {
        int x;
        bool flag = 1;
        while (flag)
        {
            cout << "\nenter the price: ";
            cin >> x;
            if (x > 0)
            {
                price = x;
                flag = 0;
                break;
            }
        }
    }

    void input_qty()
    {
        int x;
        bool flag = 1;
        while (flag)
        {
            cout << "\nenter the qty: ";
            cin >> x;
            if (x > 0)
            {
                qty = x;
                flag = 0;
                break;
            }
        }
    }

    void calculate()
    {
        total = price * qty;
    }

public:
    void data_entry()
    {
        input_number();
        cout << endl;
        input_price();
        cout << endl;
        input_qty();
        cout << endl;
        calculate();
    }

    void display()
    {
        cout << "\nnumber: " << item_number;
        cout << "\nprice: " << price;
        cout << "\nqty: " << qty;
        cout << "\ntotal: " << total;
    }
};
int main()
{
    GrossItem g[10];
    for (int i = 0; i < 10; i++)
    {
        g[i].data_entry();
    }

    for (int i = 0; i < 10; i++)
    {
        g[i].display();
    }
    return 0;
}