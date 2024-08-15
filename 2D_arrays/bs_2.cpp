#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int target)
{
    int st = 0;
    int end = n - 1;
    int mid = st + (end - st) / 2;
    while (st <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
            end = mid - 1;

        else
            st = mid + 1;
        mid = st + (end - st) / 2;
    }
    return -1;
}

int main()
{

    int n, m, target;
    cin >> m >> n >> target;

    int arr[n][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // bruteforce
    /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
        int s = 0;
        int e = n - 1;
        int found=-1;
        int i;
        for (i = 0; i < n; i++)
        {
            if (target >= arr[i][s] && target <= arr[i][e])
            {
                found=binary_search(arr[i], n, target);
            }
            if(found!=-1) break;

        }

        cout<<i<<","<<found;
    */
    int i = 0;
    int j = n - 1; // cols-1
    bool found = false;
    while (i < m && j >= 0)
    {
        if (arr[i][j] == target)
        {
            found = true;
            break;
        }

        else if (arr[i][j] < target)
            i++;

        else
            j--;
    }
    if(found) cout<<endl<<"present";
    else cout<<endl<<"not present";

    return 0;
}