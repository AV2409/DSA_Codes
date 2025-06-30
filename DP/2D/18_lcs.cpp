#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, int j, string &s1, string &s2)
{
    // base case
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + f_rec(i - 1, j - 1, s1, s2);
    }
    else
    {
        return max(f_rec(i - 1, j, s1, s2), f_rec(i, j - 1, s1, s2));
    }
}

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + f_rec(i - 1, j - 1, s1, s2);
    }
    else
    {
        return dp[i][j] = max(f_rec(i - 1, j, s1, s2), f_rec(i, j - 1, s1, s2));
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    // return f_rec(m - 1, n - 1, text1, text2);
    vector<vector<int>> dp(m, vector<int>(n, -1));
    f(m - 1, n - 1, text1, text2, dp);
}

int longestCommonSubsequence_tab(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, string &ans)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (s1[i - 1] == s2[j - 1])
    {
        ans += s1[i - 1];
        return solve(i - 1, j - 1, s1, s2, dp, ans);
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
        return solve(i - 1, j, s1, s2, dp, ans);
    }
    else
    {
        return solve(i, j - 1, s1, s2, dp, ans);
    }
}

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans;
    solve(n, m, s1, s2, dp, ans);

    int e = ans.size() - 1;
    int s = 0;
    while (s < e)
    {
        swap(ans[s++], ans[e--]);
    }

    return ans;
}
int main()
{

    return 0;
}