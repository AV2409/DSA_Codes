#include <bits/stdc++.h>
using namespace std;
class employee
{
    const int id;

public:
    static int count;
    employee(int n) : id(n)
    {
        count++;
    }

    friend void display(employee e);
};

void display(employee e)
{
    cout << "\nid: " << e.id << "  count: " << employee::count;
}

int employee::count = 0;
int main()
{
    cout << employee::count;
    employee e1(101);
    display(e1);

    employee e2(102);
    display(e2);

    employee e3(103);
    display(e3);

    return 0;
}