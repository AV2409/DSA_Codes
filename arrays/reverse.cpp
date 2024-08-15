#include <iostream>
using namespace std;

void swap1(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void printarr(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void reverse_arr(int arr[], int size)
{
    int i;
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // swap1(&arr[start], &arr[end]);
        swap(arr[start], arr[end]);

        // int temp;
        // temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        start++;
        end--;
    }
    // printarr(arr,size);
}

int main()
{
    cout << "Enter the size";
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printarr(arr, n);
    reverse_arr(arr, n);

    printarr(arr, n);
}