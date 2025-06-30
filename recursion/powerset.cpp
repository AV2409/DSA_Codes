#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int> arr, int n)
{
    if (n == 0)
    {
        return;
    }
    // include
    cout << arr[n - 1];
    powerSet(arr, n - 1);

    // exclude
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    powerSet(arr, 4);

    return 0;
}