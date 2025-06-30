// same as 7

#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, vector<int> &arr, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return arr[i] == sum;
    }

    // pick and not pick
    int np = f_rec(i - 1, arr, sum);
    int p = 0;
    if (arr[i] <= sum)
        p = f_rec(i - 1, arr, sum - arr[i]);
    return p + np;
}

int f(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return dp[i][sum] = 2;
        if (sum == 0 || arr[0] == sum)
            return dp[i][sum] = 1;
        return dp[i][sum] = 0;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    // pick and not pick
    int np = f(i - 1, arr, sum, dp);
    int p = 0;
    if (arr[i] <= sum)
        p = f(i - 1, arr, sum - arr[i], dp);
    return dp[i][sum] = (p + np);
}

int perfectSum(vector<int> &arr, int target)
{
    // return f_rec(arr.size() - 1, arr, target);
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, arr, target, dp);
}

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

        for (int j = 0; j <= 6; j++)
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

int main()
{
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    cout << perfectSum(arr, target);

    return 0;
}