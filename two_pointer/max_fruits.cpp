#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxFruits(vector<int> &arr)
{
    int n = arr.size();
    int maxlen = 0;
    int l = 0;
    int r = 0;
    map<int, int> mp;

    while (r < n)
    {
        mp[arr[r]]++;

        while (mp.size() > 2)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
                mp.erase(arr[l]);

            l++;
        }

        maxlen = max(maxlen, r - l + 1);

        r++;
    }

    return maxlen;
}
int main()
{
    vector<int> arr = {3, 1, 2, 2, 2,2};

    int ans = maxFruits(arr);

    cout << ans;
}