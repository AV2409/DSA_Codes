#include <bits/stdc++.h>
using namespace std;

int f_rec(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }

    int u = f_rec(m - 1, n);
    int r = f_rec(m, n - 1);
    return u + r;
}

int f(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
    {
        return dp[m][n] = 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int u = f(m - 1, n, dp);
    int r = f(m, n - 1, dp);
    return dp[m][n] = u + r;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

int uniquePaths_tab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int x1 = dp[i - 1][j];
            int x2 = dp[i][j - 1];
            dp[i][j] = x1 + x2;
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    cout << uniquePaths_tab(3, 7);

    return 0;
}