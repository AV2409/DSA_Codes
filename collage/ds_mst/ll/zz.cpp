#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void insert_at_head(Node *&tail, int val)
{
    Node *n_node = new Node(val);
    if (tail == NULL)
    {
        tail = n_node;
        tail->next = tail;
        return;
    }
    n_node->next = tail->next;
    tail->next = n_node;
}

void insert_at_tail(Node *&tail, int val)
{
    Node *n_node = new Node(val);
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

void insert(Node *&tail, int key, int val)
{
    if (tail == NULL)
    {
        cout << "List is empty, cannot insert after key" << endl;
        return;
    }

    Node *n_node = new Node(val);

    // If the key is the tail's value, insert after tail and move the tail
    if (tail->data == key)
    {
        n_node->next = tail->next;
        tail->next = n_node;
        tail = n_node;
        return;
    }

    // Otherwise, traverse the list to find the key
    Node *temp = tail->next;
    while (temp != tail && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp->data == key)
    {
        n_node->next = temp->next;
        temp->next = n_node;
    }
    else
    {
        cout << "Key doesn't exist" << endl;
    }
}

void delete_at_head(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (tail->next == tail) // Single node in the list
    {
        delete tail;
        tail = NULL;
        return;
    }
    Node *to_del = tail->next;
    tail->next = to_del->next;
    delete to_del;
}

void delete_at_tail(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (tail->next == tail) // Single node in the list
    {
        delete tail;
        tail = NULL;
        return;
    }

    Node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    delete tail;
    tail = temp;
}

void delete_from_ll(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (tail->next->data == val) // Handle the case where head node is to be deleted
    {
        delete_at_head(tail);
        return;
    }

    Node *temp = tail->next;
    while (temp->next != tail && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next->data == val)
    {
        Node *to_del = temp->next;
        temp->next = to_del->next;
        if (to_del == tail) // If the node to delete is the tail
        {
            tail = temp;
        }
        delete to_del;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

void display(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int size(Node *tail)
{
    if (tail == NULL)
    {
        return 0;
    }

    int cnt = 1; // Start counting from 1 because there's at least one node
    Node *temp = tail->next;

    // Loop through all nodes until we reach back to the head (tail->next)
    while (temp != tail)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

int main()
{
    Node *tail = NULL;

    insert_at_head(tail, 5);
    insert_at_head(tail, 6);
    insert_at_tail(tail, 11);
    insert(tail, 11, 111);

    display(tail);                          // Should print: 6 5 11 111
    delete_from_ll(tail, 111);              // Remove node with value 111
    display(tail);                          // Should print: 6 5 11
    cout << "Size: " << size(tail) << endl; // Should print: Size: 3

    return 0;
}
