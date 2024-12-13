#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

double division(double x, double y)
{
    if (y == 0)
    {
        throw runtime_error("division by 0");
    }
    return x / y;
}

int main()
{
    double n, d, res;

    cout << "\nEnter n: ";
    cin >> n;
    cout << "\nEnter d: ";
    cin >> d;

    try
    {
        res = division(n, d);
        cout << "\nResult: " << res;
    }

    catch (const runtime_error &e)
    {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}