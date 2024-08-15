#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[st];
    int cnt = 0;

    // calculating the right place to pivot
    for (int i = st + 1; i < end; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    // placing at right posi
    int pivotIndex = st + cnt;
    swap(arr[st], arr[pivotIndex]);

    // left side <pvot & right side > pivot
    int i = st, j = end - 1;

    while (i < pivotIndex && j > pivotIndex)
    {

        // while (arr[i] > pivot && arr[j] < pivot)
        // {
        //     while (arr[i] <= pivot)
        //         i++;
        //     while (arr[j] > pivot)
        //         j--;

        //     if (i < pivotIndex && j > pivotIndex)
        //     {
        //         swap(arr[i], arr[j]);
        //         i++;
        //         j--;
        //     }
        // }
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        else if (arr[i] <= pivot)
        {
            i++;
        }

        else if (arr[j] > pivot)
        {
            j--;
        }
    }

    return pivotIndex;
}

void solve(vector<int> &arr, int start, int end)
{
    
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    solve(arr, start, p);
    solve(arr, p + 1, end);
}

int main()
{
    vector<int> arr = {4, 2, 5,1,3};
    //4 1 3 9 7

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    solve(arr, 0, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}