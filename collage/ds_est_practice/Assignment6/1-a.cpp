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

void insertAtHead(Node *&tail, int x)
{
    Node *temp = new Node(x);
    if (tail == NULL)
    {
        tail = temp;
        tail->next = tail;
        return;
    }
    temp->next = tail->next;
    tail->next = temp;
}

void insertAtTail(Node *&tail, int x)
{
    Node *n_node = new Node(x);
    if (tail == NULL)
    {
        tail = n_node;
        tail->next = tail;
        return;
    }

    n_node->next = tail->next;
    tail->next = n_node;
    tail = n_node;
}

void insertAfter(Node *&tail, int key, int val)
{
    if (tail->data == key)
    {
        insertAtTail(tail, val);
    }

    Node *temp = tail->next;
    while (temp != tail && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp != tail)
    {
        Node *n_node = new Node(val);
        n_node->next = temp->next;
        temp->next = n_node;
    }
}

void printll(Node *tail)
{
    Node *temp = tail->next;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
}

int main()
{
    Node *tail = NULL;
    insertAtHead(tail, 10);
    insertAtHead(tail, 20);
    insertAtHead(tail, 30);
    printll(tail);
    cout << endl;
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    printll(tail);

    return 0;
}