// similar to knapsack and coin change 2 logic

#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, int w, vector<int> &val, vector<int> &wt)
{
    if (w == 0)
    {
        return 0;
    }
    if (i == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }

    int np = f_rec(i - 1, w, val, wt);
    int p = 0;
    if (wt[i] <= w)
        p = val[i] + f_rec(i, w - wt[i], val, wt);

    return max(np, p);
}

int f(int i, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (w == 0)
    {
        return dp[i][w] = 0;
    }
    if (i == 0)
    {
        if (wt[0] <= w)
            return dp[i][w] = val[0] + f(0, w - wt[0], val, wt, dp);
        return dp[i][w] = 0;
    }

    if (dp[i][w] != -1)
        return dp[i][w];

    int np = f(i - 1, w, val, wt, dp);
    int p = 0;
    if (wt[i] <= w)
        p = val[i] + f(i, w - wt[i], val, wt, dp);

    return dp[i][w] = max(np, p);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // return f_rec(val.size() - 1, W, val, wt);
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return f(n - 1, capacity, val, wt, dp);
}

int knapSack_tab(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int np = dp[i - 1][j];
            int p = 0;
            if (wt[i - 1] <= j)
                p = val[i - 1] + dp[i][j - wt[i - 1]];

            dp[i][j] = max(np, p);
        }
    }
    return dp[n][capacity];
}

int main()
{

    return 0;
}