#include <iostream>
using namespace std;

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int binary_search(int arr[],int key,int start,int end){
    // int ans=-1;
    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        
        else if(arr[mid]>key){
            end=mid-1;
        }

        else if(arr[mid]<key){
            start=mid+1;
        }

        mid=start+(end-start)/2;

    }

    return -1;
}


int pivot(int arr[], int size)
{

    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }

        else if (arr[mid] < arr[e])
        {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }

    return mid;
}

int main()
{

    int arr[10] = {15, 21, 33, 35, 43,2, 5, 7, 9, 12};
    int arr2[8] = {11, 3, 4, 5, 6, 7, 8,9};

    

    printarr(arr, 10);
    printarr(arr2, 8);

    int p1, p2;
    p1 = pivot(arr, 10);
    p2 = pivot(arr2, 8);

    cout << "the index= " << p1 << endl;
    cout << "the index= " << p2 << endl;
    
    int key=3;

    if(key>=arr2[0]&&key<=arr2[p1-1]){
        cout<<binary_search(arr2,key,0,p2-1);
    }

    else{
        cout<<binary_search(arr2,key,p2,7);
    }

    return 0;
}


// class Solution {

//     int pivot(vector<int>& arr)
// {

//     int s = 0;
//     int e = arr.size() - 1;
//     int mid = s + (e - s) / 2;

//     while (s < e)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             s = mid + 1;
//         }

//         else if (arr[mid] < arr[e])
//         {
//             e = mid;
//         }

//         mid = s + (e - s) / 2;
//     }

//     return mid;
// }

// int binary_search(vector<int>& arr,int key,int start,int end){
//     // int ans=-1;
//     int mid=start+(end-start)/2;

//     while(start<=end){
//         if(arr[mid]==key){
//             return mid;
//         }
        
//         else if(arr[mid]>key){
//             end=mid-1;
//         }

//         else if(arr[mid]<key){
//             start=mid+1;
//         }

//         mid=start+(end-start)/2;

//     }

//     return -1;
// }


// public:
//     int search(vector<int>& nums, int target) {

//         if(nums.size()==1&&nums[0]==target) return 0;
//         if(nums.size()==1&&nums[0]!=target) return -1;
//         int p1;
//     p1 = pivot(nums);

//     if(target>=nums[0]&&target<=nums[p1-1]){
//         return binary_search(nums,target,0,p1-1);
//     }

//     else{
//         return binary_search(nums,target,p1,nums.size()-1);
//     }
//     }
// };