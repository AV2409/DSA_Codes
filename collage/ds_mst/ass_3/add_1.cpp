#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Stack
{
    int top = -1;
    int arr[MAX];

public:
    void push(int n)
    {
        if (top == MAX - 1)
        {
            cout << endl
                 << "Overflow" << endl;
        }

        else
        {
            arr[++top] = n;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << endl
                 << "Underflow" << endl;
        }

        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }

    bool isFull()
    {
        if (top == MAX - 1)
        {
            return 1;
        }
        else
            return 0;
    }

    int peak()
    {
        if (top == -1)
        {
            cout << "empty";
            return -1;
        }
        return arr[top];
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

string string_rev(string &str)
{
    Stack s1;
    int n = str.length();
    int i = 0;
    while (i < n)
    {
        s1.push(str[i++]);
    }
    string rev;
    while (!s1.isEmpty())
    {
        rev += s1.peak();
        s1.pop();
    }
    return rev;
}
int main()
{
    Stack st, st1;
    int n = 9;
    int arr[n] = {34, 35, 27, 42, 5, 28, 39, 20, 28};

    // for (int i = 0; i < n; i++)
    // {
    //     st.push(arr[i]);
    // }
    int res[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int temp = st.peak();
    //     st.pop();
    //     while (!st.isEmpty() && st.peak() >= temp)
    //     {
    //         st1.push(st.peak());
    //         st.pop();
    //     }
    //     if (st.isEmpty())
    //     {
    //         res[n - i - 1] = -1;
    //     }
    //     else
    //     {
    //         res[n - i - 1] = st.peak();
    //     }
    //     while (!st1.isEmpty())
    //     {
    //         st.push(st1.peak());
    //         st1.pop();
    //     }
    // }
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack that are greater than or equal to A[i]
        while (!st.isEmpty() && st.peak() >= arr[i]) {
            st.pop();
        }

        // If the stack is empty, no smaller element exists
        if (st.isEmpty()) {
            res[i]=-1;
        } else {
            // The element on the top of the stack is the nearest smaller element
            res[i]=st.peak();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}