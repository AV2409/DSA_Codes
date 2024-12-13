#include <bits/stdc++.h>
using namespace std;

template <typename T>
void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

template <typename T>
void print(T arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {1, 2, 9, 5, 5, 6};
    int n = 6;
    bubbleSort(arr, n);
    print(arr, n);

    char arr1[6] = {'a', 'c', 'g', 't', 'y', 'b'};
    bubbleSort(arr1, n);
    print(arr1, n);

    return 0;
}