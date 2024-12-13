#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
void show(T1 a, T2 b)
{
    cout << "different: ";
    cout << a << " " << b << endl;
}

template <typename T>
void show(T a, T b)
{
    cout << "same: ";
    cout << a << " " << b << endl;
}

int main()
{
    show(100, "hello hello");
    show('k', 1500);
    show(1.23, 2987);

    show(2, 1);
    return 0;
}