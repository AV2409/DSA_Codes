#include <bits/stdc++.h>
using namespace std;

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    vector<int> arr = {2, 3, 7, 8, 10};
    int target = 10;
    cout << perfectSum(arr, target);

    return 0;
}
