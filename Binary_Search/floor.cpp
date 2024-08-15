#include <iostream>
using namespace std;

int binary_search(int arr[],int n,int x)
{

    long long int s = 0;
    long long int e = n - 1;
    
    long long int mid = s + (e - s) / 2;
    int ans=-1;

    if(arr[0]>=x) return -1;
    while (s <= e)
    {
        if (arr[mid]==x)
        {
            return mid-1;

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


int main()
{
    int arr[7] = {1,2,8,10,11,12,19};
    cout<<binary_search(arr,7,5);
}