#include <bits/stdc++.h>
using namespace std;
class Order
{
    int table_number;
    int patrons;
    string server;
    static int min_price;

public:
    void setData(int num, int pat, string ser)
    {
        this->table_number = num;
        this->patrons = pat;
        this->server = ser;
    }

    void display()
    {
        cout << "\nTable Number: " << table_number;
        cout << "\nPatrons: " << patrons;
        cout << "\nserver: " << server;
        cout << "\nmin_price: " << min_price * patrons;
    }
    static int get_minPrice()
    {
        return min_price;
    }
};

int Order::min_price = 475;
int main()
{

    cout << Order::get_minPrice() << endl;

    Order o1;
    int n, x;
    string y;

    cin >> n >> x >> y;
    o1.setData(n, x, y);
    cout << endl;
    o1.display();
    return 0;
}