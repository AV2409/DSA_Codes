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

bool valid(string &s)
{
    stack<int> s1;
    int n = s.length();
    int i = 0;
    if ((s[0] == ')') || (s[0] == '}') || (s[0] == ']'))
    {
        return 0;
    }
    while (i < n)
    {

        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            s1.push(s[i]);
        }
        else
        {
            if (s1.empty())
            {
                return false; // If there's no opening bracket for a closing one
            }
            char top = s1.top();
            if ((s[i] == ')' && top == '(') ||
                (s[i] == '}' && top == '{') ||
                (s[i] == ']' && top == '['))
            {
                s1.pop(); // Matching pair found, pop the stack
            }
            else
            {
                return false; // Mismatched bracket
            }
        }

        i++;
    }
    if (s1.empty())
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