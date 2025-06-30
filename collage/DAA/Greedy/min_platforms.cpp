#include <bits/stdc++.h>
using namespace std;

int MinPlatform(vector<int> arr, vector<int> dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat = 1, maxPlatforms = 1, i = 1, j = 0, n = arr.size();

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, plat);
    }
    return maxPlatforms;
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum platforms required: " << MinPlatform(arr, dep) << endl;
    return 0;
}
