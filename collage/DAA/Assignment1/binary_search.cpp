#include <iostream>
using namespace std;

bool binary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return false;
}

int main()
{
    int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;
    if (binary_search(arr, 10, key))
    {
        cout << "Element is present in array";
    }
    else
    {
        cout << "Element is not present in array";
    }

    return 0;
}
