#include <iostream>
using namespace std;


void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int peak_index(int arr[],int size){

    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }

        else if(arr[mid]>arr[mid+1]){
            e=mid;
        }

        
        mid=s+(e-s)/2;
    }

    return mid;

}

int main(){

    int arr1[10]={2,5,7,9,12,15,13,11,3,0};
    int arr2[9]={2,5,7,9,8,7,7,4,4};
    int arr3[5]={15,13,11,3,0};

    printarr(arr1,10);
    printarr(arr2,9);

    int a1,a2,a3;
    a1=peak_index(arr1,10);
    a2=peak_index(arr2,9);
    a3=peak_index(arr3,5);

    cout<<"the index= "<<a1<<endl;
    cout<<"the index= "<<a2<<endl;
    cout<<"the index= "<<a3<<endl;
    return 0;
}