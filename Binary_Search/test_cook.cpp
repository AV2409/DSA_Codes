#include <iostream>
using namespace std;

bool ispossible(int arr[], int m, int mid)
{
    int time = 0;
    int cook = 0;
    int j = 1;
    int n=1;
    for (int i = 0; i < m; i++)
    {

        if (time + j * arr[cook] <= mid)
        {
            time = time + j * arr[cook];
            j++;
        }

        else
        {
            cook++;
            if (cook >= n || arr[cook]>mid)
                return false;
            time = arr[cook];
            j=2;
        }
    }

    return true;
}

int main()
{

    int arr[4] = {10};

    int n = 1, m = 1, ans = -1;

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