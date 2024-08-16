#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << endl
             << "memory free for: " << val << endl;
    }
};

int getLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printll(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addAtHead(Node *&head, int val)
{
    if (head == NULL)
    {
        Node *temp = new Node(val);
        head = temp;
        return;
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    newNode->prev = temp;
}

void addAtIndex(Node *&head, int val, int index)
{
    if (head == NULL)
    {
        head = new Node(val);
        return;
    }
    if (index == 0)
    {
        addAtHead(head, val);
        return;
    }

    if (index == getLength(head))
    {
        addAtTail(head, val);
        return;
    }
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        i++;
        if (i == index)
            break;

        temp = temp->next;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = NULL;
    toDelete->prev = NULL;
    delete toDelete;
}

void deleteAtIndex(Node *&head, int index)
{
    if (index == 0)
    {
        deleteAtHead(head);
        return;
    }
    if (index == getLength(head) - 1)
    {
        deleteAtTail(head);
        return;
    }
    int i = 0;
    Node *temp = head;
    while (temp)
    {
        i++;
        if (i == index)
            break;

        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    toDelete->next = NULL;
    toDelete->prev = NULL;

    delete toDelete;
}

int main()
{
    Node *node1 = new Node(4);
    Node *head = NULL;
    addAtHead(head, 3);
    addAtHead(head, 2);
    addAtTail(head, 6);
    addAtIndex(head, 1, 0);
    addAtIndex(head, 77, 3);
    addAtIndex(head, 5, 4);
    addAtIndex(head, 7, 5);

    // printll(head);
    // deleteAtHead(head);

    // printll(head);
    // deleteAtTail(head);

    printll(head);
    deleteAtIndex(head, 1);

    printll(head);
    return 0;
}