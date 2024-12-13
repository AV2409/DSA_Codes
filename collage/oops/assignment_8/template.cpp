#include <bits/stdc++.h>
using namespace std;

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    int a = 50;
    int b = 20;
    cout << "Maximum of " << a << " and " << b << " is " << myMax(a, b) << endl;

    double c = 12.5;
    double d = 23.7;
    cout << "Maximum of " << c << " and " << d << " is " << myMax(c, d) << endl;

    char e = 'A';
    char f = 'Z';
    cout << "Maximum of " << e << " and " << f << " is " << myMax(e, f) << endl;

    return 0;
}