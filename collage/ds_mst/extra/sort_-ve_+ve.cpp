#include <bits/stdc++.h>
using namespace std;

void separate(int arr[], int n)
{
    int n_index;
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        while (arr[i] < 0 && i < j)
        {
            i++;
        }

        while (arr[j] > 0 && i < j)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    separate(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}