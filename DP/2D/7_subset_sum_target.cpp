#include <bits/stdc++.h>
using namespace std;

// bool f_rec(int i, vector<int> &arr, int sum)
// {
//     if (sum == 0)
//     {
//         return true;
//     }
//     if (i == 0)
//     {
//         return arr[i] == sum;
//     }

//     // pick and not pick
//     bool np = f_rec(i - 1, arr, sum);
//     bool p = false;
//     if (arr[i] <= sum)
//         p = f_rec(i - 1, arr, sum - arr[i]);
//     return np || p;
// }

bool f_rec(int i, vector<int> &arr, int sum)
{
    if (sum < 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (i == 0)
    {
        return arr[i] == sum;
    }

    // pick and not pick
    bool np = f_rec(i - 1, arr, sum);

    bool p = f_rec(i - 1, arr, sum - arr[i]);
    return p || np;
}

bool f(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    if (sum < 0)
    {
        return false;
    }

    if (sum == 0)
    {
        return dp[i][sum] = 1;
    }

    if (i == 0)
    {
        return dp[i][sum] = (arr[i] == sum);
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    // pick and not pick
    bool np = f(i - 1, arr, sum, dp);

    bool p = f(i - 1, arr, sum - arr[i], dp);
    return dp[i][sum] = (p || np);
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    // return f_rec(n - 1, arr, sum);

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return f(n - 1, arr, sum, dp);
}

bool isSubsetSum_tab2(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            int np = dp[i - 1][j];
            int p = 0;
            if (arr[i] <= j)
            {
                p = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (np || p);
        }
    }
    return dp[n - 1][sum];
}

// understandable
bool isSubsetSum_tab1(vector<int> &arr, int sum)
{
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
    return dp[n][sum];
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    cout << isSubsetSum_tab2(arr, 30);

    return 0;
}