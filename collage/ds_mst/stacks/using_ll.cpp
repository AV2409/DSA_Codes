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

void insertion_at_head(Node *&head, int val)
{
    Node *n_node = new Node(val);
    if (head == NULL)
    {
        head = n_node;
        return;
    }

    n_node->next = head;
    head = n_node;
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *to_del = head;
    head = head->next;
    delete to_del;
}

class Stack
{
    Node *top = NULL;
    int cnt = 0;

public:
    void push(int n)
    {
        // Node* temp=new Node(n);
        insertion_at_head(top, n);
        cnt++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "underflow";
            return;
        }
        delete_at_head(top);
        cnt--;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return 1;
        }
        else
            return 0;
    }

    int size()
    {
        return cnt;
    }

    int peak()
    {
        if (top == NULL)
        {
            cout << "empty";
            return -1;
        }
        return top->data;
    }

    void print()
    {
        cout << endl;
        Node *temp = top;
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
        cout << "\n1. push()\n2. pop()\n3. isEmpty()\n4. size()\n5. display()\n6. peek()\n7. exit\n";

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

        case 4:
        {
            cout << "size: " << st.size();
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
                 << st.peak();
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