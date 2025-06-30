#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int np = dp[i - 1][j];
            int p = 0;
            if (arr[i - 1] <= j)
            {
                p = dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j] = (np || p);
        }
    }

    int mini = INT_MAX;

    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i])
        {
            mini = min(mini, abs(i - (sum - i)));
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 6, 11, 5};
    cout << minDifference(arr);

    return 0;
}