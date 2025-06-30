#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, vector<int> &height)
{
    if (i == 0)
        return 0;

    int s1 = f_rec(i - 1, height) + abs(height[i] - height[i - 1]);
    int s2 = 1e9;
    if (i > 1)
    {
        s2 = f_rec(i - 2, height) + abs(height[i] - height[i - 2]);
    }

    return min(s1, s2);
}

int f_mem(int i, vector<int> &height, vector<int> &dp)
{
    if (i == 0)
        return dp[i] = 0;

    if (dp[i] != -1)
        return dp[i];

    int s1 = f_mem(i - 1, height, dp) + abs(height[i] - height[i - 1]);
    int s2 = 1e9;
    if (i > 1)
    {
        s2 = f_mem(i - 2, height, dp) + abs(height[i] - height[i - 2]);
    }

    return dp[i] = min(s1, s2);
}

int minCost1(vector<int> &height)
{
    // recursive
    // return f_rec(3, height);

    // Memo
    int n = height.size();
    vector<int> dp(n, -1);
    return f_mem(n - 1, height, dp);
}

// tabulation
int minCost(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int s1 = dp[i - 1] + abs(height[i] - height[i - 1]);
        int s2 = 1e9;
        if (i > 1)
        {
            s2 = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(s1, s2);
    }
    return dp[n - 1];

    // this is also correct
    //  int n = height.size();
    //  vector<int> dp(n);
    //  dp[0] = 0;
    //  dp[1] = abs(height[1] - height[0]);
    //  for (int i = 2; i < n; i++)
    //  {
    //      int s1 = dp[i - 1] + abs(height[i] - height[i - 1]);
    //      int s2 = dp[i - 2] + abs(height[i] - height[i - 2]);
    //      dp[i] = min(s1, s2);
    //  }
    //  return dp[n - 1];
}

int main()
{
    vector<int> h = {20, 30, 40, 20};
    cout << minCost(h);

    return 0;
}