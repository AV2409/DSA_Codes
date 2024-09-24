#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (arr[i] == arr[j])
                count++;
        }
        if (count == 1)
            ans++;
    }
    cout << ans;

    return 0;
}