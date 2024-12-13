#include <bits/stdc++.h>
using namespace std;

template <typename T>
class demo
{
public:
    T value;
    demo(T val) : value(val) {}

    void divideBy2();

    void display();
};
template <typename T>
void demo<T>::divideBy2()
{
    value /= 2;
}

template <typename T>
void demo<T>::display()
{
    cout << "Current value: " << value << endl;
}

int main()
{
    demo<int> o1(10);
    o1.display();
    o1.divideBy2();
    o1.display();

    demo<double> o2(5.5);
    o2.display();
    o2.divideBy2();
    o2.display();

    return 0;
}