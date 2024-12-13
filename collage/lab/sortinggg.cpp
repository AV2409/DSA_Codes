#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }

    cout << "\nNumber of iterations: " << count;
}

void selection_sort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[minindex] > arr[j])
                minindex = j;
        }

        swap(arr[minindex], arr[i]);
    }
    cout << "\nNumber of iterations: " << count;
}

void insertion_sort(int arr[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0)
        {
            count++;
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                j--;
            }

            else
                break;
        }
    }
    cout << "\nNumber of iterations: " << count;
}

void merge(vector<int> &arr, int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    vector<int> v;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }

        else
        {
            v.push_back(arr[j]);
            j++;
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

    for (i = st; i <= end; i++)
    {
        arr[i] = v[i - st];
    }
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void print(int arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// code for merge sort?
int main()
{

    int n = 6;

    // Bubble Sort
    //  cout << "\nBest case  scenario: " << n;
    //  cout << "\nAvg case  scenario: " << n * n;
    //  cout << "\nWorst case  scenario: " << n * n;
    //  int avg[6] = {1, 2, 9, 5, 5, 6};
    //  bubble_sort(avg, n);
    //  print(avg, n);

    // int worst[6] = {9, 6, 5, 4, 3, 2};
    // bubble_sort(worst, n);
    // print(worst, n);

    // int best[6] = {1, 2, 5, 5, 6, 9};
    // bubble_sort(best, n);
    // print(best, n);

    // // selection Sort
    // cout << "\nBest case  scenario: " << n * n;
    // cout << "\nAvg case  scenario: " << n * n;
    // cout << "\nWorst case  scenario: " << n * n;
    // int avg[6] = {1, 2, 9, 5, 5, 6};
    // selection_sort(avg, n);
    // print(avg, n);

    // int worst[6] = {9, 6, 5, 4, 3, 2};
    // selection_sort(worst, n);
    // print(worst, n);

    // int best[6] = {1, 2, 5, 5, 6, 9};
    // selection_sort(best, n);
    // print(best, n);

    // insertion sort
    cout << "\nBest case  scenario: " << n;
    cout << "\nAvg case  scenario: " << n * n;
    cout << "\nWorst case  scenario: " << n * n;
    int avg[6] = {1, 2, 9, 5, 5, 6};
    insertion_sort(avg, n);
    print(avg, n);

    int worst[6] = {9, 6, 5, 4, 3, 2};
    insertion_sort(worst, n);
    print(worst, n);

    int best[6] = {1, 2, 5, 5, 6, 9};
    insertion_sort(best, n);
    print(best, n);
    return 0;
}