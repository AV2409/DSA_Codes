#include <iostream>
using namespace std;

bool isSorted(int arr[], int st, int size)
{

    if(size==1) return true;
    if(arr[st]>arr[st+1]) return false;

    return isSorted(arr, ++st, --size);
}

int main()
{
    int arr[6] = {1, 3, 15, 2, 34, 0};
    int arr1[6] = {0, 1, 2, 3, 15, 34};
    cout << isSorted(arr, 0, 6) << endl;
    cout << isSorted(arr1, 0, 6) << endl;
}