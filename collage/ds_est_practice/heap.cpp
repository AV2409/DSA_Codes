#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    void heapify(int i)
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

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

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
            int parent = i / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
            }

            i = parent;
        }
    }

    int getMax()
    {
        return arr[1];
    }

    int extractMax()
    {
        int max = arr[1];
        arr[1] = arr[size];
        size--;
        heapify(1);
        return max;
    }

    void increaseKey(int i, int key)
    {
        arr[i] = key;

        int x = i;
        while (x > 1)
        {
            int parent = x / 2;
            if (arr[parent] < arr[x])
            {
                swap(arr[parent], arr[x]);
            }
            x = parent;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

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
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Generating maxHeap

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    // Sorting Logic

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
    // cout << h.getMax() << endl;

    // int x = h.extractMax();
    // cout << x << endl;
    // h.print();
    // x = h.extractMax();
    // cout << x << endl;

    // h.increaseKey(3, 60);
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}