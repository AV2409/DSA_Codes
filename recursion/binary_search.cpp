#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int s, int e)
{
    int mid = s + (e - s) / 2;

    if(s>e) return -1;
    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
    {
        
        return binarySearch(arr, key, s, mid - 1);
    }

    if (arr[mid] < key)
    {
        return binarySearch(arr, key, mid+1, e);
    }

    return -1;

}

int main()
{
    int arr[7] = {1, 4, 6, 11, 12, 34, 56};
    cout << binarySearch(arr, 56, 0, 6)<<endl;
    cout << binarySearch(arr, 30, 0, 6);
}