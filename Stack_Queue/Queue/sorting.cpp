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

void sorting(queue<int> &q)
{
    if (q.size() <= 1)
    {
        return;
    }

    int temp = q.front();
    q.pop();
    sorting(q);
    queue<int> t_q;
    while (!q.empty() && temp > q.front())
    {
        t_q.push(q.front());
        q.pop();
    }

    t_q.push(temp);

    while (!q.empty())
    {
        t_q.push(q.front());
        q.pop();
    }
    q = t_q;
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
    sorting(q);

    print(q);

    return 0;
}