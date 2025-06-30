#include <bits/stdc++.h>
using namespace std;

string findLCS(string &s1, string &s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    string lcsStr = "";

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcsStr = s1[i - 1] + lcsStr;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "LCS Length: " << dp[m][n] << endl;
    return lcsStr;
}

int main()
{
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    string lcsStr = findLCS(s1, s2);
    cout << "LCS String: " << lcsStr << endl;
    return 0;
}
