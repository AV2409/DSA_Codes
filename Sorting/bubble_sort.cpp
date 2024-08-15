#include <iostream>
using namespace std;

// void bubble_sort(int arr[], int n)
// {

//     for (int i = 0; i < n - 1; i++)
//     {
//         bool swapped = false;

//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }

//         if (swapped == false)
//             break;
//     }
// }

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped=false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped=true;
            }
        }
        if (swapped==false) break;
    }
}

void bubble_sort_rec(int arr[], int n)
{
    if(n==1) return;


    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);

    }
    bubble_sort_rec(arr,--n);
}

int main()
{
    int arr[5] = {1, 5, 4, 3, 2};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    bubble_sort_rec(arr, 5);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}