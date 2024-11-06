#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            cnt++;
            if (arr[j] > arr[j + 1])
            {
                flag = false;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (flag)
        {
            break;
        }
    }
    cout << endl
         << "Number of iterations: " << cnt << endl;
}

void selection_sort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    cout << endl
         << "iterations: " << count << endl;
}

void insertion_sort(int arr[], int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {

        int temp = arr[i]; // Store the element to be inserted
        int j = i;

        // Shift elements that are greater than temp to the right
        while (j > 0 && arr[j - 1] > temp)
        {
            count++;
            arr[j] = arr[j - 1];
            j--;
        }

        // Place temp at its correct position
        arr[j] = temp;
    }

    cout << endl
         << "itr: " << count << endl;
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[10] = {1, 3, 5, 2, 7, 9, 4, 8, 6, 0};
    // int arr[5] = {1, 2, 3, 4, 5};
    int arr2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arr3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printarr(arr1, 10);
    insertion_sort(arr1, 10);
    printarr(arr1, 10);

    printarr(arr2, 10);
    insertion_sort(arr2, 10);
    printarr(arr2, 10);

    printarr(arr3, 10);
    insertion_sort(arr3, 10);
    printarr(arr3, 10);
    return 0;
}