#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Queue
{
    int front = -1;
    int rear = -1;
    char arr[MAX];
    int cnt = 0;

public:
    void enqueue(char n)
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

    char peek()
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

    string s = "aabc";

    int hash[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
        que.enqueue(s[i]);

        // Remove all characters with frequency > 1 from the front of the queue
        while (!que.isEmpty() && hash[que.peek() - 'a'] > 1)
        {
            que.dequeue();
        }

        if (que.isEmpty())
        {
            // q.enqueue('-1');
            cout << -1 << " ";
        }
        else
        {
            // q.enqueue(que.peek());
            cout << que.peek() << " ";
        }
    }

    // q.print();

    return 0;
}