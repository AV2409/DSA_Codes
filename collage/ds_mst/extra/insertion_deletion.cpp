#include <bits/stdc++.h>
using namespace std;

void insert(int arr[], int &n, int ele, int indx)
{
    for (int i = n - 1; i >= indx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[indx] = ele;
    n++;
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteEle(int arr[], int &n, int indx)
{
    int i = indx;
    for (i; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i] = 0;
    n--;
}

int main()
{
    int arr[10] = {1, 3, 4, 5, 6};
    int n = 5;
    printarr(arr, n);

    insert(arr, n, 2, 1);
    insert(arr, n, 2, 0);
    insert(arr, n, 2, 7);

    insert(arr, n, 5, 7);

    insert(arr, n, 1, 7);

    printarr(arr, n);

    // deleteEle(arr, n, 2);

    printarr(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << "for" << arr[i] << ": ";
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[j] << "  Deleted" << "  ";
                deleteEle(arr, n, j);
            }
        }
        cout << endl;
    }

    cout << endl;
    printarr(arr, n);

    return 0;
}