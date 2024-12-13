#include <bits/stdc++.h>
using namespace std;

class rectangle
{
private:
    int l;
    int b;

public:
    rectangle(int l = 6, int b =9 )
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
    ~rectangle()
    {
        cout << "bye" << " ";
    }
};

int main()
{

    rectangle r[3] = {rectangle(), rectangle(1, 1), rectangle(5)};

    for (int i = 0; i < 3; i++)
    {
        r[i].area();
    }
    cout << endl;

    return 0;
}