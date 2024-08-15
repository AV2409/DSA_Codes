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

int unique(int nums[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
            return nums[mid];
        }

        elseif
    }
    return ans;
}

int main()
{

    int arr[9] = {1, 2, 3, 7, 7, 7, 7, 9, 11};

    printarr(arr, 9);
    cout << endl;
    int first = first_occurance(arr, 9, 7);
    int last = last_occurence(arr, 9, 7, first);
    cout << first << " " << last;

    cout << endl;
    cout << "Total= " << last - first + 1;
}