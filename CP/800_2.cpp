#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int x, int mid)
{
    vector<int> stops;
    stops.push_back(0);
    for (int i = 0; i < n; i++)
    {
        stops.push_back(arr[i]);
    }

    stops.push_back(x);

    for (int i = 1; i < stops.size(); i++)
    {
        if ((stops[i] - stops[i - 1]) > mid)
        {
            return 0;
        }
    }
    if (mid < 2 * (x - arr[n - 1]))
    {
        return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        int x;
        cin >> n >> x;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        int st = 1;
        int end = 2 * x;

        int mid = (st + end) / 2;
        int ans = x;
        while (st <= end)
        {
            if (isPossible(arr, n, x, mid))
            {
                ans = mid;
                end = mid - 1;
            }

            else
            {
                st = mid + 1;
            }
            mid = (st + end) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int minTankCapacity(int arr[], int n, int x)
// {
//     vector<int> stops;

//     // Forward journey: 0 → a1 → ... → an → x
//     stops.push_back(0);
//     for (int i = 0; i < n; i++)
//         stops.push_back(arr[i]);
//     stops.push_back(x);

//     int maxGap = 0;
//     for (int i = 1; i < stops.size(); i++)
//     {
//         maxGap = max(maxGap, stops[i] - stops[i - 1]);
//     }
//     maxGap = max(maxGap, (2 * (x - arr[n - 1])));
//     return maxGap;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, x;
//         cin >> n >> x;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//             cin >> arr[i];

//         cout << minTankCapacity(arr, n, x);
//     }
//     return 0;
// }
