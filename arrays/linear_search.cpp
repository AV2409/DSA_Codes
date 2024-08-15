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

bool found(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(key==arr[i]) return 1;
    }
    return 0;
}

int main()
{
    cout << endl;
    
    int key;
    cin>>key;
    int arr[7]={23,45,33,-4,6,-99,56};
    

    printarr(arr, 7);
    cout << endl;
    int x=found(arr,7,key);
    if(x){
        cout<<"Element Found";
    }
    else{
        cout<<"not found";
    }
}