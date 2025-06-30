#include <bits/stdc++.h>
using namespace std;
int f_rec(int i, vector<int> &arr)
{
    if (i == 0)
    {
        return arr[0];
    }
    int np = f_rec(i - 1, arr);
    int p = -1e9;
    if (i > 1)
    {
        p = arr[i] + f_rec(i - 2, arr);
    }
    return max(p, np);
}

int f(int i, vector<int> &arr, vector<int> &dp)
{
    if (i == 0)
    {
        return dp[i] = arr[0];
    }

    if (i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int np = f(i - 1, arr, dp);
    int p = arr[i] + f(i - 2, arr, dp);
    return dp[i] = max(p, np);
}

int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    // return f_rec(n - 1, arr);
    vector<int> dp(n, -1);
    return f(n - 1, arr, dp);
}

int findMaxSum1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1); // dp[i] represents max sum for first i elements
    dp[0] = 0;             // Base case: no elements
    dp[1] = arr[0];        // Base case: only first element

    for (int i = 2; i <= n; i++)
    {
        int np = dp[i - 1];             // Not pick current element
        int p = arr[i - 1] + dp[i - 2]; // Pick current element
        dp[i] = max(p, np);             // Store max in dp[i]
    }

    return dp[n]; // Final answer
}

int main()
{
    vector<int> arr = {11711, 11540, 1390, 24899};
    cout << findMaxSum1(arr);

    return 0;
}