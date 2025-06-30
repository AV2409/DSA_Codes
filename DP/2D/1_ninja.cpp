#include <bits/stdc++.h>
using namespace std;

int f_rec(int d, int last, vector<vector<int>> &arr)
{
    // base case
    if (d == 0)
    {
        int maxi = -1e9;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[d][i]);
            }
        }
        return maxi;
    }

    int maxi = -1e9;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int x1 = arr[d][i] + f_rec(d - 1, i, arr);
            maxi = max(maxi, x1);
        }
    }
    return maxi;
}

int f(int d, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    // base case
    if (d == 0)
    {
        int maxi = -1e9;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[d][i]);
            }
        }
        return dp[d][last] = maxi;
    }

    if (dp[d][last] != -1)
    {
        return dp[d][last];
    }
    int maxi = -1e9;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int x1 = arr[d][i] + f(d - 1, i, arr, dp);
            maxi = max(maxi, x1);
        }
    }
    return dp[d][last] = maxi;
}

int maximumPoints(vector<vector<int>> &arr)
{
    // return f_rec(arr.size() - 1, 3, arr);
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, arr, dp);
}

int maximumPoints_tab(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    for (int d = 1; d < n; d++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = -1e9;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int x1 = arr[d][i] + dp[d - 1][i];
                    maxi = max(maxi, x1);
                }
            }
            dp[d][last] = maxi;
        }
    }
    return dp[n - 1][3];
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}};

    cout << maximumPoints_tab(arr);

    return 0;
}