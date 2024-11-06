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

bool valid(string &str)
{
    Stack s1;
    int n = str.length();
    int i = 0;
    while (i < n)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            s1.push(str[i]);
        }
        else if ((str[i] == ')') && (s1.peak() == '('))
        {
            s1.pop();
        }

        else if ((str[i] == '}') && (s1.peak() == '{'))
        {
            s1.pop();
        }

        else if ((str[i] == ']') && (s1.peak() == '['))
        {
            s1.pop();
        }

        i++;
    }
    if (s1.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (valid(str))
        {
            cout << "Valid\n";
        }
        else
        {
            cout << "Invalid\n";
        }
    }
    return 0;
}