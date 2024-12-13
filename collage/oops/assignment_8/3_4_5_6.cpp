#include <bits/stdc++.h>
using namespace std;
template <class T>
T myMax(T a, T b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

template <class T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <class T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void show(int a, int b)
{
    cout << "In non-template: ";
    cout << a << ", " << b << endl;
}
template <class T1, class T2>
void show(T1 a, T2 b)
{
    cout << "In template: ";
    cout << a << ", " << b << endl;
}

template <class T, int n>
void display(T a)
{
    cout << "a = " << a << ", n = " << n << endl;
}

int main()
{
    cout << myMax(1, 7) << endl;
    cout << myMax('e', 'b') << endl;
    cout << myMax(1.17, 7.66) << endl;

    int arr1[7] = {3, 5, 6, 2, 55, 23, 1};
    char arr2[7] = {'a', 'c', 'g', 'e', 'd', 'b', 'f'};
    float arr3[7] = {3.4, 5.33, 6.12, 2.2, 5.15, 2.3, 1.233};

    bubbleSort(arr1, 7);
    bubbleSort(arr2, 7);
    bubbleSort(arr3, 7);

    printArray(arr1, 7);
    printArray(arr2, 7);
    printArray(arr3, 7);

    show(100, "hello hello");
    show('k', 1500);
    show(1.23, 2987);
    show(100, "hello hello");
    show(3, 3);
    show('a', 100);
    show(3, 3);

    display<int, 6>(5);
    display<double, 6>(5.55);
    display<char, 6>('a');
    display<string, 6>("ancd");

    return 0;
}