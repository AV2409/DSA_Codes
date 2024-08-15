#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

// void rotate(int arr[],int size,int k){

//     int temp[size]={0};
//     int x=size-k;
//     int j=0;

//     for(int i=k+1;i<size;i++){
//         temp[j]=arr[i];
//         j++;
//     }

//     for(int i=0;i<=x;i++){
//         temp[j]=arr[i];

//         j++;
//     }

//     for(int i=0;i<size;i++){
//         arr[i]=temp[i];
//     }
    

// }

void rotate(vector<int>& nums, int k) {

    vector<int> temp;
    int x=nums.size()-k;
    int j=0;

    for(int i=k+1;i<nums.size();i++){
        temp.push_back(nums[i]);
        j++;
    }

    for(int i=0;i<x;i++){
        temp.push_back(nums[i]);

        j++;
    }

    nums=temp;
        
    }

int main(){

    vector<int> arr={1,2,3,4,5};

    // print(arr,5);

    print(arr);
    cout<<endl;
    rotate(arr,2);

    print(arr);


}