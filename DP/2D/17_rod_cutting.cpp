#include <bits/stdc++.h>
using namespace std;

int f_rec(int i, int length, vector<int> &price)
{
    if (length == 0)
    {
        return 0;
    }
    if (i == 0)
    {
        if (length > 0)
        {
            return price[0] + f_rec(i, length - 1, price);
        }
    }

    int np = f_rec(i - 1, length, price);
    int p = -1e9;
    if (length >= (i + 1))
    {
        p = price[i] + f_rec(i, length - i - 1, price);
    }
    return max(p, np);
}

int f(int i, int length, vector<int> &price, vector<vector<int>> &dp)
{
    if (length == 0)
    {
        return dp[i][0] = 0;
    }
    if (i == 0)
    {
        if (length > 0)
        {
            return dp[i][length] = price[0] * length;
        }
    }
    if (dp[i][length] != -1)
    {
        return dp[i][length];
    }
    int np = f(i - 1, length, price, dp);
    int p = -1e9;
    if (length >= (i + 1))
    {
        p = price[i] + f(i, length - i - 1, price, dp);
    }
    return dp[i][length] = max(p, np);
}

int cutRod(vector<int> &price)
{
    int length = price.size();
    // return f_rec(length - 1, length, price);

    vector<vector<int>> dp(length + 1, vector<int>(length + 1, -1));
    return f(length - 1, length, price, dp);

    // for(int i=0;i<=length;i++){
    //     for()
    // }
}

int cutRod_tab(vector<int> &price)
{
    int length = price.size();

    vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if (i == 1)
            {
                dp[i][j] = price[0] * j;
            }
            else
            {
                int np = dp[i - 1][j];
                int p = -1e9;
                if (j >= i)
                {
                    p = price[i - 1] + dp[i][j - i];
                }
                dp[i][j] = max(p, np);
            }
        }
    }
    return dp[length][length];
}

int main()
{

    return 0;
}