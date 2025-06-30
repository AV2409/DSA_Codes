#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n)
    {
        return triangle[i][j];
    }
    if (i > n)
    {
        return 1e9;
    }

    int d = triangle[i][j] + f_rec(i + 1, j, triangle, n);
    int dg = triangle[i][j] + f_rec(i + 1, j + 1, triangle, n);

    return min(d, dg);
}
int f(int i, int j, vector<vector<int>> &triangle, int n,
      vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return dp[i][j] = triangle[i][j];
    }
    if (i > n - 1)
    {
        return 1e9;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int d = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int dg = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(d, dg);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    // return f_rec(0, 0, triangle, n - 1);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n, dp);
}

int minimumTotal_tab(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int x = triangle[n - 1].size();

    for (int i = 0; i < x; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int len = triangle[i].size();
        for (int j = 0; j < len; j++)
        {
            int d = triangle[i][j] + dp[i + 1][j];
            int dg = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    cout << minimumTotal_tab(triangle);

    return 0;
}