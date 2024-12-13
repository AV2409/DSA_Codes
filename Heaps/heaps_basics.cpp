#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int x)
    {
        size++;
        arr[size] = x;
        int i = size;

        while (i > 1)
        {
            int par = i / 2;

            if (arr[par] < arr[i])
            {
                swap(arr[par], arr[i]);
            }
            i = par;
        }
    }

    void deleteAtRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }

            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest == i)
            {
                return;
            }

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void print()
    {
        cout << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i;      // Left child index
    int right = 2 * i + 1; // Right child index

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

void heapSort11(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    // Heap h;

    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // cout << endl;
    // h.deleteAtRoot();
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    // heapSort11(arr, n);
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}