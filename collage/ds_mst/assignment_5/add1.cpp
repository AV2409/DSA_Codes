#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertion_at_tail(Node *&head, int val)
{
    Node *n_node = new Node(val);
    if (head == NULL)
    {
        head = n_node;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n_node;
}

void printll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse2(Node *&head, int m, int n)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    for (int i = 0; i < m; i++)
    {
        next = curr->next;
        prev = curr;
        curr = next;
    }
    Node *t1 = prev;
    next = curr->next;
    prev = curr;
    curr = next;
    Node *t2 = prev;
    for (int i = m; i < n; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (t1)
        t1->next = prev;

    else
    {
        head = prev;
    }
    t2->next = curr;
}

void rotate(Node *&head, int k, int n)
{
    reverse2(head, 0, n - 1);
    reverse2(head, 0, k - 1);
    reverse2(head, k, n - 1);
}

int main()
{
    Node *head = NULL;
    insertion_at_tail(head, 1);
    insertion_at_tail(head, 2);
    insertion_at_tail(head, 3);
    insertion_at_tail(head, 4);
    insertion_at_tail(head, 5);
    insertion_at_tail(head, 6);
    insertion_at_tail(head, 7);
    insertion_at_tail(head, 8);
    insertion_at_tail(head, 9);
    insertion_at_tail(head, 10);
    printll(head);

    // reverse2(head, 0, 8);
    cout << endl;
    printll(head);

    rotate(head, 4, 10);
    printll(head);

    return 0;
}