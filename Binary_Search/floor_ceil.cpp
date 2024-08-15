#include <iostream>
using namespace std;

int floor(int arr[],int n,int x)
{

    int s = 0;
    int e = n - 1;
    
    int mid = s + (e - s) / 2;
    int ans=-1;

    if(arr[0]>x) return -1;
    while (s <= e)
    {
        if (arr[mid]==x)
        {
            return mid;

        }

        else if (arr[mid]<x)
        {
            ans=mid;
            s=mid+1;
        }

        else if (arr[mid] > x)
        {
            e = mid - 1;
        }

        

        mid = s + (e - s) / 2;
    }

    return ans;
}

int ceil(int arr[],int n,int x)
{

    int s = 0;
    int e = n - 1;
    
    int mid = s + (e - s) / 2;
    int ans=-1;

    if(arr[n-1]<x) return -1;
    while (s <= e)
    {
        if (arr[mid]==x)
        {
            return mid;

        }

        else if (arr[mid]<x)
        {
            
            s=mid+1;
        }

        else if (arr[mid] > x)
        {
            ans=mid;
            e = mid - 1;
        }

        

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int arr[7] = {1,2,8,10,11,12,19};

    
    
    cout<<floor(arr,7,10)<<" "<<ceil(arr,7,10);


}