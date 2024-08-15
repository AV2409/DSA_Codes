#include <iostream>
using namespace std;

int linearSearch(int arr[], int st, int size, int key)
{

    if (size == 0)
    {
        return -1;
    }

    if (arr[0] == key)
    {
        return st;
    }

    // st = st + 1;
    // size = size - 1;

    else
    {
        return linearSearch(arr + 1, ++st, --size, key);
    }

    return -1;
}

int main()
{
    int arr[6] = {1, 3, 15, 2, 34, 0};
    cout << linearSearch(arr, 0, 6, 0) << endl;
    cout << linearSearch(arr, 0, 6, 34) << endl;
    cout << linearSearch(arr, 0, 6, 2) << endl;
    cout << linearSearch(arr, 0, 6, 15) << endl;
    cout << linearSearch(arr, 0, 6, 3) << endl;
    cout << linearSearch(arr, 0, 6, 1) << endl;
    cout << linearSearch(arr, 0, 6, 20) << endl;
}