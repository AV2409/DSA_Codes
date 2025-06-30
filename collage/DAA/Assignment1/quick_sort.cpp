#include <iostream>
using namespace std;

int partition(int arr[], int st, int end)
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

    // left side <pivot & right side > pivot
    int i = st, j = end - 1;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quick_sort(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quick_sort(arr, start, p);
    quick_sort(arr, p + 1, end);
}

int main()
{
    int arr[5] = {4, 2, 6, 9, 2};
    int n = 5;
    quick_sort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
