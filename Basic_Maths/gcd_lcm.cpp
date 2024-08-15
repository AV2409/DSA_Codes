#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
            a = a - b;

        if (b > a)
            b = b - a;
    }
    return a;
}

int lcm(int a, int b)
{
    int ans = (a * b) / gcd(a, b);
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << ans;

    cout << endl
         << lcm(a, b);

    return 0;
}