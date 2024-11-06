#include <bits/stdc++.h>
using namespace std;
#define MAX 10
class Stack
{
    int top = -1;
    int arr[MAX];

public:
    int peek()
    {
        if (top == -1)
        {
            cout << "\nis emplty";
            return -1;
        }

        return arr[top];
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "\nis emplty";
            return;
        }

        top--;
    }

    void push(int n)
    {
        if (top == MAX - 1)
        {
            cout << "\nis full";
            return;
        }

        arr[++top] = n;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void print()
    {
        cout << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}