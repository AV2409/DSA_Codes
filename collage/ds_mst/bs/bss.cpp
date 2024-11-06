#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int binary_search_rec(int arr[], int s, int n, int key)
{
    int e = n - 1;
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return -1;
    }

    if (arr[mid] == key)
    {
        return mid;
    }

    else if (arr[mid] > key)
    {
        return binary_search_rec(arr, s, mid, key);
    }
    else
    {
        return binary_search_rec(arr, mid + 1, n, key);
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 12, 15, 19, 20};
    int n = 10;
    int key = 5;
    cout << "element present at: " << binary_search(arr, n, key);
    cout << "\nelement present at: " << binary_search_rec(arr, 0, n, key);

    return 0;
}