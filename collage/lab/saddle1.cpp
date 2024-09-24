#include <bits/stdc++.h>
using namespace std;

int mini(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= min)
            min = arr[i];
    }
    return min;
}

int maxi(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
            max = arr[i];
    }
    return max;
}

int find(int arr[], int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < m; i++)
    {
        int min = mini(arr[i], n);
        // cout<<endl<<min<<" "<<find(arr[i],min,3);

        int index = find(arr[i], min, n);
        int ele = arr[i][index];
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (ele < arr[j][index])
                break;
        }
        if (j == m)
        {
            cout << endl
                 << ele;
            ans1++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int max = maxi(arr[i], n);
        // cout<<endl<<min<<" "<<find(arr[i],min,3);
        int index = find(arr[i], max, n);
        int ele = arr[i][index];
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (ele > arr[j][index])
                break;
        }
        if (j == m)
        {
            cout << endl
                 << ele;
            ans2++;
        }
    }

    cout << endl
         << ans1 << " " << ans2;
    return 0;
}