#include <iostream>
using namespace std;

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pivot(int arr[], int size)
{

    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }

        else if (arr[mid] < arr[e])
        {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }

    return mid;
}

int main()
{

    int arr1[10] = {15, 21, 33, 35, 43,2, 5, 7, 9, 12};
    int arr2[9] = {33, 35,2, 5, 7, 9, 12, 15, 21};

    printarr(arr1, 10);
    printarr(arr2, 9);

    int a1, a2;
    a1 = pivot(arr1, 10);
    a2 = pivot(arr2, 9);

    cout << "the index= " << a1 << endl;
    cout << "the index= " << a2 << endl;

    
    return 0;
}