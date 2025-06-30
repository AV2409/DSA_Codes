#include <bits/stdc++.h>
using namespace std;

int perfectSum_tab(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int np = dp[i - 1][j];
            int p = 0;
            if (arr[i - 1] <= j)
            {
                p = dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j] = (np + p);
        }
    }
    return dp[n][target];
}

int countPartitions(vector<int> &arr, int d)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if ((sum - d) < 0 || (sum - d) % 2 != 0)
    {
        return 0;
    }

    int target = (sum - d) / 2;
    return perfectSum_tab(arr, target);
}

int main()
{
    vector<int> arr = {
        2,
        3,
        5,
        1,
        3,
        4,
        5,
        4,
        4,
        5,
        2,
        4,
        1,
        1,
    };
    int d = 48;
    cout << countPartitions(arr, d);

    return 0;
}