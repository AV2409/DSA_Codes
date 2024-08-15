#include <iostream>
using namespace std;


void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binary_search(int arr[],int size,int key){

    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }

        else if(arr[mid]>key){
            e=mid-1;
        }

        else if(arr[mid]<key){
            s=mid+1;
        }

        mid=s+(e-s)/2;
    }

    return -1;

}

int main(){

    int arr1[10]={2,5,7,9,12,15,21,33,35,43};
    int arr2[9]={2,5,7,9,12,15,21,33,35};

    printarr(arr1,10);
    printarr(arr2,9);

    int a1,a2;
    a1=binary_search(arr1,10,15);
    a2=binary_search(arr2,9,35);

    cout<<"the index= "<<a1<<endl;
    cout<<"the index= "<<a2<<endl;
    return 0;
}