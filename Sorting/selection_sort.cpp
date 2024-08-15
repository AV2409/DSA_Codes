#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minindex] > arr[j])
                minindex = j;
        }

        swap(arr[minindex], arr[i]);
    }
}

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

void selection_sort_rec(int *arr, int n)
{
    if(n==0||n==1) return;
    int min_index=0;
    for(int i=0;i<n;i++){
        if(arr[min_index]>arr[i]) min_index=i;
    }

    swap(arr[0],arr[min_index]);

    selection_sort_rec(arr+1,--n);
}

int main()
{
    int arr[5] = {1, 5, 4, 3, 2};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    selection_sort_rec(arr, 5);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    
}