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
    rectangle(int l, int b)
    {
        this->l = l;
        this->b = b;
    }
    
    rectangle(int a)
    {
        this->l = a;
        this->b = a;
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
    rectangle r1;
    rectangle r2(3,5);
    rectangle r3(6);
    
    r1.area();
    r2.area();
    r3.area();
    

    return 0;
}