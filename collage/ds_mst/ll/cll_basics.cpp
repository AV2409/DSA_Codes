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
    tail = tail->next;
}

void insert(Node *&tail, int key, int val)
{
    Node *n_node = new Node(val);

    if (tail->data == key)
    {
        n_node->next = tail->next;
        tail->next = n_node;
        tail = tail->next;
        return;
    }
    Node *temp = tail->next;
    while (temp != tail && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        cout << "key doesn't exist";
        return;
    }
    n_node->next = temp->next;
    temp->next = n_node;
}

void delete_at_head(Node *&tail)
{
    if (tail == NULL)
    {
        return;
    }
    if (tail->next == tail)
    {
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
        return;
    }
    if (tail->next == tail)
    {
        tail = NULL;
        return;
    }
    Node *to_del = tail;
    Node *temp = tail;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail = temp;
    delete to_del;
}

void delete_from_ll(Node *&tail, int val)
{
    if (tail == NULL)
    {
        return;
    }
    if (tail->next->data == val)
    {
        if (tail == tail->next)
        {
            delete tail;
            tail = NULL;
            return;
        }
        Node *to_del = tail->next;
        tail->next = tail->next->next;
        delete to_del;
        return;
    }

    Node *temp = tail->next;
    while (temp != tail && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp != tail)
    {
        Node *to_del = temp->next;
        temp->next = to_del->next;
        delete to_del;
        return;
    }

    cout << "Element not found" << endl;
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
    } while (temp != tail->next); // Loop until it comes back to the head
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
    // cout << check_circular(tail) << endl;
    display(tail);
    delete_from_ll(tail, 111);
    display(tail);
    cout << "\nsize: " << size(tail);
    // cout << check_circular(tail) << endl;

    return 0;
}