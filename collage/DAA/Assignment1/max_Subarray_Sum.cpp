#include <iostream>
#include <algorithm>
using namespace std;

int max_subarray_sum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Max Subarray Sum: " << max_subarray_sum(arr, n);
    return 0;
}
