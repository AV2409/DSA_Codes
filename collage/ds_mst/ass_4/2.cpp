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
    string str = "akshansh";
    str = string_rev(str);
    cout << str;

    return 0;
}