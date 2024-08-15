#include <iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid)
{
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= mid)
        {
            time += arr[i];
        }

        else
        {
            painters++;

            if (painters > m || arr[i] > mid)
                return false;
            time = arr[i];
        }
    }
    return true;
}

int main()
{

    int k, n, m;
    cin >> k;
    for (int a = 0; a < k; a++)
    {
        cin >> n;
        cin >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int sum = 0, ans = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        // cout<<sum;
        int s = 0;
        int e = sum;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (ispossible(arr, n, m, mid))
            {
                ans = mid;
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }

        cout << ans << endl;
    }
}