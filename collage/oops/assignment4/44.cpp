#include <bits/stdc++.h>
using namespace std;

class demo
{
    int x;

public:
    demo()
    {
        x = 0;
    }
    demo(int n)
    {
        x = n;
    }
    void set(int n)
    {
        x = n;
    }
    int get()
    {
        return x;
    }
};

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    /*(For integer variable, float variable,
    integer array, float array, class objects,
    Array ofObjects)*/

    int *i1 = new int(5);
    int *i2 = new int(3);
    float *f1 = new float(5);
    int *i = new int[5];
    float *f = new float[5];

    cout << *i1;
    cout << *i2;
    swap(i1, i2);
    cout << *i1;
    cout << *i2;

    delete i1;
    delete f1;
    delete[] i;
    delete[] f;
    cout << endl;

    demo *d1 = new demo;
    d1->set(5);

    cout << endl
         << d1->get() << endl;

    demo *d = new demo[5];
    for (int i = 0; i < 5; i++)
    {
        cout << d[1].get() << " ";
    }

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        d[i] = demo(6);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << d[1].get() << " ";
    }

    return 0;
}