#include <bits/stdc++.h>
using namespace std;

int f_rec(int m, int n, vector<vector<int>> &obstacleGrid)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (obstacleGrid[m][n] == 1)
    {
        return 0;
    }

    int u = f_rec(m - 1, n, obstacleGrid);
    int r = f_rec(m, n - 1, obstacleGrid);
    return u + r;
}

int f(int m, int n, vector<vector<int>> &obstacleGrid,
      vector<vector<int>> &dp)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (obstacleGrid[m][n] == 1)
    {
        return dp[m][n] = 0;
    }
    if (m == 0 && n == 0)
    {
        return dp[m][n] = 1;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int u = f(m - 1, n, obstacleGrid, dp);
    int r = f(m, n - 1, obstacleGrid, dp);
    return dp[m][n] = u + r;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, obstacleGrid, dp);
}

int uniquePathsWithObstacles_tab(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int x1 = 0;
                int x2 = 0;
                if (i > 0)
                {
                    x1 = dp[i - 1][j];
                }
                if (j > 0)
                {
                    x2 = dp[i][j - 1];
                }
                dp[i][j] = x1 + x2;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};

    cout << uniquePathsWithObstacles_tab(obstacleGrid);

    return 0;
}