#include <bits/stdc++.h>
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

void insert_at_tail(Node *&head, int x)
{
    if (head == NULL)
    {
        head = new Node(x);
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(x);
    temp->next = newnode;
}

void printll(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *unique(Node *&head)
{
    Node *head1 = NULL;

    Node *temp = head;
    if (head1 == NULL)
    {
        insert_at_tail(head1, temp->data);
        temp = temp->next;
    }

    Node *temp1 = head1;

    while (temp)
    {
        if (temp1->data != temp->data)
        {
            insert_at_tail(head1, temp->data);
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    return head1;
}

Node *unique1(Node *&head)
{
    Node *u = head;

    while (u)
    {
        Node *temp = u->next;

        while (temp)
        {
            if (temp->data == u->data)
            {
                Node *duplicate = temp;
                temp = temp->next;
                u->next = temp;
                delete duplicate; // Free memory of the duplicate node
            }

            else
            {
                temp = temp->next;
            }
        }
        u = u->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 3);
    printll(head);

    cout << endl;
    Node *head1 = unique1(head);
    printll(head1);
}