#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                j--;
            }

            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }

            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {

            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void insertion_sort_rec(int arr[], int n)
{
    if (n == 1 || n == 0)
        return;

    insertion_sort_rec(arr, --n);
    int j = n - 1;
    while (j > 0)
    {
        if (arr[j] < arr[j - 1])
            swap(arr[j], arr[j - 1]);

        else
            break;

        j--;
    }
}

int main()
{
    int arr[5] = {1, 5, 4, 3, 2};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    insertion_sort_rec(arr, 5);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}