#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}

int main()
{

    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    print(nums, n);

    // int nonZeroIndex = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (nums[i] != 0)
    //     {
    //         swap(nums[i], nums[nonZeroIndex++]);
    //     }
    // }

    int i = 0;

    while (i < n)
    {
        int j = i;
        while (nums[j] == 0 && j < n)
            j++;
        while (nums[i] != 0 && i < n)
            i++;

        if (i < j && j < n)

            swap(nums[i], nums[j]);
        i++;
        j++;
    }

    print(nums, n);

    return 0;
}