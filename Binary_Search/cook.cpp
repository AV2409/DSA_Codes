#include <bits/stdc++.h> 
using namespace std;

bool ispossible(vector<int> &arr, int m, int mid)
{
    int time = 0;
    int cook = 0; // start with the first cook
    int j = 1;    // start with the first dish for the current cook
    int n=arr.size();
    for (int i = 0; i < m; i++)
    {
        if (time + j * arr[cook] <= mid)
        {
            time += j * arr[cook];
            j++;
        }
        else
        {
            cook++;
            if (cook >= n || arr[cook] > mid)
                return false;
            time = arr[cook];
            j = 2; // reset j for the new cook
        }
    }

    return true;
}

int main()
{

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    int n = 4, m = 10, ans = -1;

    int s = 1;
    int e = 5 * (m * (m + 1));

    int mid = s + (e - s) / 2;

    while (s <= e)
    {

        if (ispossible(arr, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << ans;
}