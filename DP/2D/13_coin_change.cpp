#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, vector<int> &coins, int amount)
{
    if (i == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        return 1e9;
    }

    int np = f_rec(i - 1, coins, amount);
    int p = 1e9;
    if (coins[i] <= amount)
    {
        p = 1 + f_rec(i, coins, amount - coins[i]);
    }

    return min(p, np);
}

int f(int i, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (amount % coins[0] == 0)
        {
            return dp[i][amount] = amount / coins[0];
        }
        return dp[i][amount] = 1e9;
    }

    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }
    int np = f(i - 1, coins, amount, dp);
    int p = 1e9;
    if (coins[i] <= amount)
    {
        p = 1 + f(i, coins, amount - coins[i], dp);
    }

    return dp[i][amount] = min(p, np);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    f(n - 1, coins, amount, dp);
    if (dp[n - 1][amount] == 1e9)
    {
        return -1;
    }
    return dp[n - 1][amount];
}

int coinChange_tab(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int np = dp[i - 1][j];
            int p = 1e9;
            if (coins[i - 1] <= j)
            {
                p = 1 + dp[i][j - coins[i - 1]];
            }
            dp[i][j] = min(p, np);
        }
    }

    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //     {
    //         if (j == 1e9)
    //             cout << "i" << "\t";
    //         else
    //             cout << j << "\t";
    //     }
    //     cout << endl;
    // }

    if (dp[n][amount] == 1e9)
    {
        return -1;
    }
    return dp[n][amount];
}

// no dummy
int coinChange_tab2(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int np = dp[i - 1][j];
            int p = 1e9;
            if (coins[i] <= j)
            {
                p = 1 + dp[i][j - coins[i]];
            }
            dp[i][j] = min(p, np);
        }
    }
    if (dp[n - 1][amount] == 1e9)
    {
        return -1;
    }
    return dp[n - 1][amount];
}

int main()
{
    vector<int> a = {2};
    int t = 3;
    cout << coinChange_tab(a, t);

    return 0;
}