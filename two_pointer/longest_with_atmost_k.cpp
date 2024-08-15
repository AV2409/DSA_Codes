#include <bits/stdc++.h>
using namespace std;

int maxLen(string s,int k)
{
    int n = s.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int, int> mp;

    while (r < n)
    {
        mp[s[r]]++;

        while (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);

            l++;
        }

        maxlen = max(maxlen, r - l + 1);

        r++;
    }

    return maxlen;
}
int main()
{
    // vector<int> arr};

    string s="abbbbbbc";

    int ans = maxLen(s,2);

    cout << ans;
}