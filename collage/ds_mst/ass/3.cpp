#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Queue
{
    int front = -1;
    int rear = -1;
    int arr[MAX];
    int cnt = 0;

public:
    void enqueue(int n)
    {
        if (rear == MAX - 1)
        {
            cout << "\nOverflow";
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }

        else
        {
            rear++;
        }

        arr[rear] = n;
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nUnderflow";
            return;
        }
        if (front > rear)
        {
            cout << "\nempty queue";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    bool isEmpty()
    {
        if ((front == -1 && rear == -1) || front > rear)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return 1;
        }
        return 0;
    }

    int peek()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nEmpty";
            return -1;
        }

        return arr[front];
    }
    int size()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nEmpty";
            return 0;
        }
        return rear - front + 1;
    }

    void print()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nEmpty";
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue que, q, res;

    que.enqueue(4);
    que.enqueue(7);
    que.enqueue(11);
    que.enqueue(20);
    que.enqueue(5);
    que.enqueue(9);
    int n = que.size();

    int a = que.size() / 2;

    for (int i = 0; i < a; i++)
    {
        q.enqueue(que.peek());
        que.dequeue();
    }

    que.print();
    q.print();

    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            res.enqueue(q.peek());
            q.dequeue();
        }

        else
        {
            res.enqueue(que.peek());
            que.dequeue();
        }
    }
    cout << endl;
    res.print();

    return 0;
}