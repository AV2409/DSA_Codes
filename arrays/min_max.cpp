#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int get_max(int arr[], int size)
{
    int i, max;
    max = arr[0];
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int get_min(int arr[], int size)
{
    int i, min;
    min = arr[0];
    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int get_sum(int arr[],int size){
    int i;
    int sum=0;
    for(i=0;i<size;i++){
        sum=sum+arr[i];
    }

    return sum;
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

    cout<<endl<<"Max Value="<<get_max(arr,n);
    cout<<endl<<"min Value="<<get_min(arr,n);
    cout<<endl<<"Sum="<<get_sum(arr,n);
    
}