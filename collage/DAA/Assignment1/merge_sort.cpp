#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    int arr1[end - st + 1];
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            arr1[k++] = arr[i++];
        }

        else
        {
            arr1[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        arr1[k++] = arr[i++];
    }

    while (j <= end)
    {
        arr1[k++] = arr[j++];
    }

    for (i = st; i <= end; i++)
    {
        arr[i] = arr1[i - st];
    }
}
void merge_sort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = (st + end) / 2;
        merge_sort(arr, st, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
