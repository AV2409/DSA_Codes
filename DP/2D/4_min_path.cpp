#include <bits/stdc++.h>
using namespace std;

int f_rec(int m, int n, vector<vector<int>> &grid)
{
    if (m == 0 && n == 0)
    {
        return grid[0][0];
    }
    if (m < 0 || n < 0)
    {
        return 1e9;
    }

    int u = grid[m][n] + f_rec(m - 1, n, grid);
    int r = grid[m][n] + f_rec(m, n - 1, grid);
    return min(u, r);
}

int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
    {
        return dp[m][n] = grid[0][0];
    }
    if (m < 0 || n < 0)
    {
        return 1e9;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int u = grid[m][n] + f(m - 1, n, grid, dp);
    int r = grid[m][n] + f(m, n - 1, grid, dp);
    return dp[m][n] = min(u, r);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // return f_rec(m - 1, n - 1, grid);
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, grid, dp);
}

int minPathSum_tab(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x1 = 1e9;
            int x2 = 1e9;
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i > 0)
                x1 = grid[i][j] + dp[i - 1][j];
            if (j > 0)
                x2 = grid[i][j] + dp[i][j - 1];
            dp[i][j] = min(x1, x2);
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    cout << minPathSum_tab(grid);

    return 0;
}