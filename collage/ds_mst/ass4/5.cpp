#include <bits/stdc++.h>
using namespace std;

class Stack2
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int n)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(n);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        q1.pop();
    }

    void print()
    {
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

class Stack1
{
    queue<int> q1;

public:
    void push(int n)
    {
        q1.push(n);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    void pop()
    {
        q1.pop();
    }

    void print()
    {
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

int main()
{
    Stack1 s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    // s1.pop();
    s1.print();

    return 0;
}