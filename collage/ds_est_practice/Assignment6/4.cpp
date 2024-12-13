#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node *&head, int x)
{
    if (head == NULL)
    {
        head = new Node(x);
        return;
    }

    Node *nNode = new Node(x);
    nNode->next = head;
    head->prev = nNode;
    head = nNode;
}

Node *reverse(Node *head)
{

    Node *temp = head;
    Node *rev = NULL;
    while (temp)
    {
        insertAtHead(rev, temp->data);
        temp = temp->next;
    }
    return rev;
}

void print(Node *head)
{

    if (head == NULL)
    {
        return;
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

bool checkPalindromic(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *h1 = slow;
    Node *h2 = slow;
    while (h1 && h2)
    {
        if (h1->data != h2->data)
        {
            return 0;
        }
        h1 = h1->prev;
        h2 = h2->next;
    }

    return 1;
}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head);

    Node *rev = reverse(head);
    cout << endl;
    print(rev);

    if (checkPalindromic(head))
    {
        cout << "The linked list is a palindrome" << endl;
    }

    else
    {
        cout << "The linked list is not a palindrome" << endl;
    }
    return 0;
}