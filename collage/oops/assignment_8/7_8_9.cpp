#include <bits/stdc++.h>
using namespace std;

template <class T>
class Test1
{
    T i;

public:
    Test1(T x = 0)
    {
        i = x;
    }

    void display()
    {
        cout << "Value of i is: " << i << endl;
    }

    // T divideBy2()
    // {
    //     return i / 2;
    // }

    T divideBy2();
};

template <class T>
T Test1<T>::divideBy2()
{
    return i / 2;
}
template <class T, int n>
class demo
{
    T i;
    int size = n;

public:
    demo(T x = 0)
    {
        i = x;
    }

    void show()
    {
        cout << "Value of i is: " << i << endl;
        cout << "Size is: " << size << endl;
    }
};
int main()
{
    Test1<int> t1(10);
    Test1<double> t2(5);

    t1.display();
    t2.display();

    cout << t1.divideBy2() << endl;
    cout << t2.divideBy2() << endl;

    cout << endl;

    demo<double, 7> d1(67.88);
    demo<char, 7> d2('c');
    demo<int, 7> d3(110);

    d1.show();
    d2.show();
    d3.show();
    return 0;
}