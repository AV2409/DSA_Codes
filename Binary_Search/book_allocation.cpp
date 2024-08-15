#include <bits/stdc++.h>
using namespace std;

bool ispossible(int arr[], int size, int m, int mid)
{
    int sumpages = 0, students = 1;
    for (int i = 0; i < size; i++)
    {
        if (sumpages + arr[i] <= mid)
        {
            sumpages = sumpages + arr[i];
        }

        else
        {
            students++;
            if (students > m || arr[i] > mid)
            {
                return false;
            }

            sumpages = arr[i];
        }
    }
    return true;
}

int main()
{
    int arr[4] = {10, 20, 30, 40};

    int sum = 0, m = 2, n = 4, ans = -1;
    sum = accumulate(arr, arr + 4, sum);

    int s = 0;
    int e = sum;
    int mid = s + (e - s) / 2;

    while (s < e)
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

    cout << ans;
}