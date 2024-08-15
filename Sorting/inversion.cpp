#include <bits/stdc++.h>
using namespace std;

int inver(vector<int> &arr, int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    vector<int> v;
    int inversions=0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }

        else
        {
            v.push_back(arr[j]);
            j++;
            inversions+=(mid-i+1);
        }
    }

    while (i <= mid)
    {
        v.push_back(arr[i]);
        i++;
    }

     while (j <= end)
    {
        v.push_back(arr[j]);
        j++;
    }


    for(i=st;i<=end;i++){
        arr[i]=v[i-st];
    }

    return inversions;

    
}

int merge_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return 0;


    int mid = start + (end - start) / 2;
    int x=0;

    x+= merge_sort(arr, start, mid);
    x+= merge_sort(arr, mid + 1, end);

    

    
    x+=inver(arr, start, mid, end);

    return x;
}

int main()
{
    vector<int> arr={1,5,4,3,2};

    
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x=merge_sort(arr, 0, 5-1);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<endl<<x<<endl;
}