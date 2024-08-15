#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // transpose
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        while (j < n)
        {
            swap(arr[i][j], arr[j][i]);
            j++;
        }
    }

    // reverse rows

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int k = n - 1;
        while (j < k)
        {
            swap(arr[i][j], arr[i][k]);
            j++;
            k--;
        }
    }

    return 0;
}