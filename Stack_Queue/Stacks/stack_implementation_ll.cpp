#include <bits/stdc++.h>
using namespace std;
#define MAX 10
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

void insertAtHead(Node *&head, int n)
{
    Node *newNode = new Node(n);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "\nEmpty";
        return;
    }

    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}

class Stack
{
    Node *head = NULL;

public:
    int peek()
    {
        if (!head)
        {
            cout << "\nis emplty";
            return -1;
        }

        return head->data;
    }

    void pop()
    {
        if (!head)
        {
            cout << "\nis emplty";
            return;
        }

        deleteAtHead(head);
    }

    void push(int n)
    {
        insertAtHead(head, n);
    }

    bool isEmpty()
    {
        if (!head)
        {
            return 1;
        }
        return 0;
    }

    void print()
    {
        Node *temp = head;
        cout << endl;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    bool x = true;
    while (x)
    {
        cout << "\n1. push()\n2. pop()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. exit\n";

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
                st.push(ele);
            }
            break;
        }

        case 2:
        {
            st.pop();
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
        }
    }

    return 0;
}