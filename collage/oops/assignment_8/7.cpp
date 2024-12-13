#include <bits/stdc++.h>
using namespace std;

template <typename T>
class demo
{
private:
    T value;

public:
    demo(T val) : value(val) {}

    void divideBy2()
    {
        value /= 2;
    }

    void display() const
    {
        cout << "Current value: " << value << endl;
    }
};

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
