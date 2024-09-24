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

void insertionAtHead(Node *&head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        return;
    }
    Node *toAdd = new Node(val);
    toAdd->next = head;
    head = toAdd;
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

Node *reverse(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Node *reverse_r(Node *&head,Node*curr,Node*prev)
// {
//     if (curr == NULL)
//         return prev;
//     Node *forward = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = forward;
//     return reverse_r(forward,curr,prev);
// }

void reverse1(Node *&head, Node *curr, Node *prev)
{
    if (curr == nullptr)
    {
        head = prev; // Update the head pointer
        return;
    }

    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    head = prev;
    reverse1(head, curr, prev);
}

int main()
{
    Node *head = NULL;
    // insertionAtHead(head, 10);
    insertionAtHead(head, 9);
    insertionAtHead(head, 8);
    insertionAtHead(head, 7);
    insertionAtHead(head, 6);
    insertionAtHead(head, 5);
    insertionAtHead(head, 4);
    insertionAtHead(head, 3);
    insertionAtHead(head, 2);
    insertionAtHead(head, 1);
    printll(head);
    // head = reverse1(head, head, NULL);
    reverse1(head, head, NULL);
    printll(head);

    return 0;
    return 0;
}