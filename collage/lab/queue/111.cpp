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
    Queue st;
    bool x = true;
    while (x)
    {
        cout << "\n1. enqueue()\n2. dequeue()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. exit\n8. size\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ele;
            int n;
            cout << "\nEnter the number of element: ";
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                cout << "\nEnter the element: ";
                cin >> ele;
                st.enqueue(ele);
            }
            break;
        }

        case 2:
        {
            st.dequeue();
            break;
        }

        case 3:
        {
            cout << "empty: " << st.isEmpty();
            break;
        }

        case 4:
        {
            cout << "full: " << st.isFull();
            break;
        }

        case 5:
        {
            st.print();
            break;
        }

        case 6:
        {
            cout << endl
                 << st.peek();
            break;
        }

        case 7:
        {
            x = false;
            break;
        }

        case 8:
        {
            cout << "Size: " << st.size();
            break;
        }
        }
    }

    return 0;

    return 0;
}