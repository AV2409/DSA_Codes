#include <bits/stdc++.h>

using namespace std;
#define MAX 100
class Stack
{
private:
    int arr[MAX];
    int top = -1;

public:
    void push(int n)
    {
        top++;
        arr[top] = n;
    }

    void pop()
    {
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    bool isFull()
    {
        if (top == MAX - 1)
            return 1;
        return 0;
    }

    void display()
    {
        int x = top;
        while (x > -1)
        {
            cout << arr[x--] << " ";
        }
    }

    int peak()
    {
        return arr[top];
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform infix to postfix conversion
string infixToPostfix(string &infix)
{
    Stack s;
    string postfix;

    for (char c : infix)
    {

        if (isalnum(c))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            s.push(c);
        }

        else if (c == ')')
        {
            while (!s.isEmpty() && s.peak() != '(')
            {
                postfix += s.peak();
                s.pop();
            }
            s.pop();
        }

        else
        {

            while (!s.isEmpty() && precedence(s.peak()) >= precedence(c))
            {
                postfix += s.peak();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.peak();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << endl
         << postfix;

    return 0;
}