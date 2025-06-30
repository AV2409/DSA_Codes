// similar to 10

#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int np = dp[i - 1][j];
            int p = 0;
            if (coins[i - 1] <= j)
            {
                p = dp[i][j - coins[i - 1]];
            }
            dp[i][j] = (np + p);
        }
    }
    return dp[n][amount];
}

int main()
{
    vector<int> c = {1, 2, 5};
    int a = 5;
    cout << change(a, c);

    return 0;
}