#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int st, int mid, int end)
{
    int count = 0;
    int i = st;
    int j = mid + 1;
    int k = 0;
    int temp[end - st + 1];

    while (i <= mid && j <= end)
    {
        count++;
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int i = st; i <= end; i++)
    {
        arr[i] = temp[i - st];
    }
    cout << count << ", ";
}

void mergeSort(int arr[], int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int mid = (st + end) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

int partition(int arr[], int st, int end)
{
    // int pivot = arr[end];
    // int i = st - 1;
    // for (int j = st; j < end; j++)
    // {
    //     if (arr[j] <= pivot)
    //     {
    //         i++;
    //         swap(arr[i], arr[j]);
    //     }
    // }
    // swap(arr[i + 1], arr[end]);
    // return (i + 1);

    int pivot = arr[st];
    int cnt = 0;
    for (int i = st; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            cnt++;
        }
    }
    int pivotIndex = st + cnt;
    swap(arr[pivotIndex], arr[st]);
    int i = st;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int pivot = partition(arr, st, end);
    quickSort(arr, st, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {4, 2, 5, 1, 3};
    // print(arr, 5);
    // mergeSort(arr, 0, 5 - 1);
    // print(arr, 5);

    // print(arr, 5);
    // quickSort(arr, 0, 5 - 1);
    // print(arr, 5);

    int arr1[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(arr1, 13);
    mergeSort(arr1, 0, 12);
    cout << endl;
    print(arr1, 12);

    return 0;
}