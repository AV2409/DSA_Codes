#include <bits/stdc++.h>
using namespace std;

void sorting(queue<int> &q)
{

    if (q.size() <= 1)
    {
        return;
    }

    int temp = q.front();
    q.pop();

    sorting(q);
    queue<int> x;

    while (!q.empty() && temp > q.front())
    {
        x.push(q.front());
        q.pop();
    }

    x.push(temp);
    while (!q.empty())
    {
        x.push(q.front());
        q.pop();
    }
    q = x;
}

void print(queue<int> q)
{
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> que, q, res;

    que.push(4);
    que.push(7);
    que.push(11);
    que.push(20);
    que.push(5);
    que.push(9);

    int n = que.size();

    int a = que.size() / 2;

    for (int i = 0; i < a; i++)
    {
        q.push(que.front());
        que.pop();
    }

    print(que);
    print(q);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            res.push(q.front());
            q.pop();
        }

        else
        {
            res.push(que.front());
            que.pop();
        }
    }
    cout << endl;
    print(res);

    queue<int> q1;
    queue<int> q2;
    stack<int> st;
    q1 = res;
    int x;
    int y;

    for (int i = 0; i < a; i++)
    {
        x = q1.front();
        q1.pop();
        y = q1.front();
    }

    int req = x + y;

    q1 = res;
    sorting(q1);
    print(q1);

    for (int i = 0; i < 5; i++)
    {
        int a = q1.front();
        q1.pop();
        q2 = q1;

        stack<int> st;
        while (!q2.empty())
        {
            st.push(q2.front());
            q2.pop();
        }

        while (!st.empty() && a + st.top() > req)
        {
            cout << endl
                 << a << "," << st.top();

            st.pop();
        }
        // if ((!st.empty()) && (a + st.top() == req))
        // {
        //     cout << endl
        //          << a << "," << st.top();
        // }
    }

    return 0;
}