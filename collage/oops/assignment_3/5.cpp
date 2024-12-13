#include <bits/stdc++.h>
using namespace std;

class rectangle
{
private:
    int l;
    int b;

public:
    rectangle()
    {
        this->l = 0;
        this->b = 0;
    }
    void set_data(int l, int b)
    {
        this->l = l;
        this->b = b;
    }

    void display()
    {
        cout << this->l << " " << this->b;
    }

    void area()
    {
        cout << endl
             << (this->l) * (this->b);
    }
};

int main()
{
    int n;
    cin >> n;
    rectangle r[n];
    for (int i = 0; i < n; i++)
    {
        int l, b;
        cin >> l >> b;
        r[i].set_data(l, b);
    }
    for (int i = 0; i < n; i++)
    {
        r[i].area();
    }

    return 0;
}