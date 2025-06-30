#include <bits/stdc++.h>
using namespace std;

int findLIS(vector<int> &arr, int n, int i, int prev)
{
    if (i == n)
        return 0;

    int exclude = findLIS(arr, n, i + 1, prev);

    int include = 0;
    if (prev == -1 || arr[i] > arr[prev])
        include = 1 + findLIS(arr, n, i + 1, i);

    return max(include, exclude);
}

int findLIS_memo(vector<int> &arr, int n, int i, int prev, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 0;
    }

    if (i == n)
        return 0;

    int exclude = findLIS(arr, n, i + 1, prev);

    int include = 0;
    if (prev == -1 || arr[i] > arr[prev])
        include = 1 + findLIS(arr, n, i + 1, i);

    return max(include, exclude);
}

int main()
{
    vector<int> arr = {3, 10, 2, 1, 20};
    int n = arr.size();
    int count = findLIS(arr, n, 0, -1);
    cout << count;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return 0;
}