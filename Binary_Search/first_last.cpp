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

int first_occurance(int arr[], int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    int ans=-1;
    
    while(start<=end){

        if(key==arr[mid]) {
            ans=mid;
            end=mid-1;

        }

        else if(key>arr[mid]) start=mid+1;

        else if(key<arr[mid]) end=mid-1;

        mid=start + (end-start)/2;

    }
    return ans;
}

int last_occurence(int arr[],int size,int key,int first){
    int start=first;
    int end=size-1;
    int mid=start + (end-start)/2;
    int ans=start;

    while(start<=end){
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }

        else if(key>arr[mid]){
            start=mid+1;
        }

        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=start + (end-start)/2;
    }
    return ans;
}

int main()
{
    
    int arr[9]={1,2,3,7,7,7,7,9,11};
    

    printarr(arr, 9);
    cout << endl;
    int first=first_occurance(arr,9,7);
    int last=last_occurence(arr,9,7,first);
    cout<<first<<" "<<last;

    cout<<endl;
    cout<<"Total= "<< last-first+1;
    
}