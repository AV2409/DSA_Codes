#include <iostream>
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

void swap_alternates(int arr[],int size){
    for(int i=0;i<size-1;i+=2){
    swap(arr[i],arr[i+1]);
}
}
int main()
{
    
    int arr[8]={23,45,33,-4,6,-99,56,88};
    int arr1[7]={23,45,33,-4,6,-99,56};
    

    printarr(arr, 8);
    cout << endl;
    swap_alternates(arr,8);
    printarr(arr,8);
cout << endl;
cout << endl;
    printarr(arr1, 7);
    cout << endl;
    swap_alternates(arr1,7);
    printarr(arr1,7);
}