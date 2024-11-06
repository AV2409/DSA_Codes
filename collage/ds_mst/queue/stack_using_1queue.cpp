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
        if (isFull())
        {
            cout << "\nOverflow";
            return;
        }
        cnt++;
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }

        else
        {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = n;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nUnderflow";
            return;
        }
        cnt--;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if ((rear + 1) % MAX == front)
        {
            return 1;
        }
        return 0;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nEmpty";
            return -1;
        }

        return arr[front];
    }
    int size()
    {
        if (isEmpty())
        {
            cout << "\nEmpty";
            return 0;
        }
        return cnt;
    }
};

class Stack
{
    Queue q1;

public:
    void push(int n)
    {
        q1.enqueue(n);
        int x = q1.size();
        for (int i = 0; i < x - 1; i++)
        {
            q1.enqueue(q1.peek());
            q1.dequeue();
        }
    }

    void pop()
    {
        q1.dequeue();
    }

    int top()
    {
        return q1.peek();
    }
};

int main()
{
    Stack st;

    bool x = true;
    while (x)
    {
        cout << "\n1. push()\n2. pop()\n3. top()\n4. exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ele;

            cout << "\nEnter the element: ";
            cin >> ele;
            st.push(ele);

            break;
        }

        case 2:
        {
            st.pop();
            break;
        }

        case 3:
        {
            cout << endl
                 << st.top();
            break;
        }

        case 4:
        {
            x = false;
            break;
        }
        }
    }

    return 0;
}