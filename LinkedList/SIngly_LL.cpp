#include <iostream>
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

Node *convertToLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);

    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;
}

int isPresent(Node *head, int key)
{
    Node *temp = head;

    while (temp)
    {
        if (key == temp->data)
            return 1;

        temp = temp->next;
    }

    return 0;
}

void insertAtHead(Node *&head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int x)
{
    if (head == nullptr)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            Node *y = new Node(x);
            temp->next = y;
            break;
        }

        temp = temp->next;
    }
}

void insertAtPosition(Node *&head, int x, int k)
{

    Node *temp = head;
    if (k == 1)
    {
        insertAtHead(head, x);
        return;
    }

    int count = 1;

    while (temp)
    {
        count++;

        if (count == k)
        {
            Node *newnode = new Node(x);
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    head = head->next;

    delete temp;
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        return;
    }

    Node *temp = head;
    Node *p = NULL;

    while (temp->next != NULL)
    {
        p = temp;
        temp = temp->next;
    }

    p->next = NULL;
    delete temp;
}

void deleteAtPosition(Node *&head, int k)
{

    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        return;
    }

    if (k == 1)
    {
        Node *tem = head;
        head = head->next;
        delete tem;
        return;
    }

    Node *temp = head;
    Node *p = NULL;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            p->next = temp->next;
            delete temp;
            break;
        }
        p = temp;
        temp = temp->next;
    }
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *x = new Node(2, nullptr);

    cout << x->data << " " << x->next;

    int arr[5] = {1, 2, 3, 4, 5};

    Node *head = convertToLL(arr, 5);

    cout << endl
         << head->data;

    Node *temp = convertToLL(arr, 5);
    cout << endl;

    printLL(head);

    cout << endl
         << isPresent(head, 7);
    cout << endl
         << isPresent(head, 5);
    cout << endl
         << isPresent(head, 4);

    cout << endl;
    insertAtHead(head, 10);
    printLL(head);

    cout << endl;
    insertAtTail(head, 10);
    printLL(head);

    cout << endl;
    insertAtPosition(head, 111, 3);
    printLL(head);

    cout << endl;
    insertAtPosition(head, 111, 9);
    printLL(head);

    // cout << endl;
    // Node *test = NULL;
    // insertAtHead(test, 7);
    // printLL(test);

    // cout << endl;
    // Node *test1 = NULL;
    // insertAtHead(test1, 8);
    // printLL(test1);

    // cout << endl;
    // insertAtPosition(test1, 6, 1);
    // printLL(test1);

    // cout << endl;
    // insertAtPosition(test1, 6, 5);
    // printLL(test1);

    cout << endl;
    deleteAtHead(head);
    printLL(head);

    cout << endl;
    deleteAtTail(head);
    printLL(head);

    cout << endl;
    deleteAtPosition(head, 6);
    printLL(head);

    return 0;
}