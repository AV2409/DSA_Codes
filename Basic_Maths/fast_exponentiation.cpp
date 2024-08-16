#include <bits/stdc++.h>
using namespace std;

int pow(int n, int power)
{
    int ans = 1;
    // if (power == 0)
    //     return 1;
    // if (power == 1)
    //     return n;

    // if (power & 1 == 1)
    //     ans = n * pow(n, (power / 2)) * pow(n, (power / 2));

    // else
    //     ans = pow(n, (power / 2)) * pow(n, (power / 2));

    // return ans;
    while (power > 0)
    {
        if (power & 1 == 1)
        {
            ans = ans * n;
        }

        power = power / 2;
        n=  n * n;
    }
    return ans;
}

int main()
{
    int n, power;
    cin >> n >> power;

    cout << pow(n, power);

    return 0;
}