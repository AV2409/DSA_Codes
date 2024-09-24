#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void insert_at_tail(Node *&tail, int val)
{
    Node *n_node = new Node(val);
    if (tail == NULL)
    {
        tail = n_node;
        tail->next = tail;
        return;
    }
    n_node->next = tail->next;
    tail->next = n_node;
    tail = tail->next;
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == head)
    {
        head = NULL;
        return;
    }
    Node *to_del = head;
    head = head->next;
    delete to_del;
}

class Queue
{
    Node *front = NULL;
    Node *rear = NULL;
    int cnt = 0;

public:
    void enqueue(int n)
    {
        cnt++;
        if (front == NULL && rear == NULL)
        {
            insert_at_tail(front, n);
            rear = front;
        }

        else
        {
            insert_at_tail(rear, n);
        }
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
            front = NULL;
            rear = NULL;
        }
        else
        {
            delete_at_head(front);
        }
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
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

        return front->data;
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
    void print()
    {
        if (isEmpty())
        {
            cout << "Empty list";
            return;
        }
        Node *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
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
}