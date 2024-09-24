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

Node *middle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *head = NULL;

    insertion_at_tail(head, 1);
    insertion_at_tail(head, 2);
    insertion_at_tail(head, 3);
    insertion_at_tail(head, 4);
    insertion_at_tail(head, 5);
    // insertion_at_tail(head, 6);
    // insertion_at_tail(head, 7);

    printll(head);

    Node *mid = middle(head);
    cout << "middle ele: " << mid->data;

    return 0;
}