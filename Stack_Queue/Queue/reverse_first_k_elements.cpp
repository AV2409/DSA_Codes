#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.size() <= 1)
    {
        return;
    }

    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

queue<int> modifyQueue(queue<int> q, int k)
{
    if (k == 0)
    {
        return q;
    }

    if (k == 5)
    {
        reverse(q);
        return q;
    }
    queue<int> temp_q;

    for (int i = 0; i < k; i++)
    {
        temp_q.push(q.front());
        q.pop();
    }

    reverse(temp_q);

    while (!q.empty())
    {
        temp_q.push(q.front());
        q.pop();
    }
    return temp_q;
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
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    print(q);

    q = modifyQueue(q, 3);
    print(q);

    return 0;
}