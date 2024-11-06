#include <bits/stdc++.h>
using namespace std;

void print(queue<int> q)
{
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

queue<int> reversal(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

queue<int> reversal_rec(queue<int> q)
{
    if (q.empty())
    {
        return q;
    }

    int temp = q.front();
    q.pop();

    q = reversal_rec(q);

    q.push(temp);
    return q;
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(7);
    q.push(16);
    q.push(9);
    q.push(20);
    q.push(5);
    print(q);

    // queue<int> q1 = reversal(q);
    // print(q1);

    queue<int> q1 = reversal_rec(q);
    print(q1);

    return 0;
}