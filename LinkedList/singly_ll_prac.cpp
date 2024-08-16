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

int getlength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

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

void insertionAtTail(Node *&head, int val)
{
    if (head == nullptr)
        head = new Node(val);
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *toAdd = new Node(val);
    temp->next = toAdd;
}

void inserttionAtPosition(Node *&head, int val, int index)
{
    Node *temp = head;
    if (index == 0)
    {
        insertionAtHead(head, val);
        return;
    }
    if (index == getlength(head) - 1)
    {
        insertionAtTail(head, val);
        return;
    }
    int i = 0;
    while (temp != nullptr)
    {
        i++;
        if (i == index)
        {
            break;
        }
        temp = temp->next;
    }
    Node *toAdd = new Node(val);
    toAdd->next = temp->next;
    temp->next = toAdd;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(Node *&head, int index)
{
    Node *temp = head;
    if (index == 0)
    {
        deleteAtHead(head);
        return;
    }
    if (index == getlength(head) - 1)
    {
        deleteAtTail(head);
        return;
    }

    int i = 0;
    while (temp != nullptr)
    {
        i++;
        if (i == index)
            break;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    temp->next->next = NULL;
    delete temp->next;
}

int main()
{

    Node *head = new Node(5);

    int val1, val2, val3;
    cin >> val1 >> val2 >> val3;
    insertionAtTail(head, val1);

    insertionAtHead(head, val1);

    insertionAtHead(head, val2);

    insertionAtTail(head, val3);

    inserttionAtPosition(head, 8, 5);

    inserttionAtPosition(head, 57, 4);

    inserttionAtPosition(head, 88, 1);

    printll(head);

    cout << endl;

    deleteAtHead(head);

    printll(head);

    cout << endl;

    deleteAtTail(head);

    printll(head);

    cout << endl;

    deleteAtPosition(head, 0);

    printll(head);

    cout << endl;

    deleteAtPosition(head, 4);

    printll(head);

    cout << endl;

    deleteAtPosition(head, 0);

    printll(head);

    cout << endl
         << getlength(head);

    return 0;
}