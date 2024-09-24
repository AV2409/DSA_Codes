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

void insertion_at_head(Node *&head, int val)
{
    Node *n_node = new Node(val);
    if (head == NULL)
    {
        head = n_node;
        return;
    }

    n_node->next = head;
    head = n_node;
}

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

void insertion_after_value(Node *&head, int key, int val)
{
    Node *n_node = new Node(val);
    if (head == NULL)
    {
        cout << "EMpty";
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp)
    {
        n_node->next = temp->next;
        temp->next = n_node;

        return;
    }
    else
    {
        cout << "key doesnt exist" << endl;
        return;
    }
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        head = NULL;
        return;
    }

    Node *to_del = head;

    head = head->next;

    delete to_del;
}

void delete_at_tail(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *to_del = temp->next;
    temp->next = NULL;
    delete to_del;
}

void delete_from_ll(Node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    if (temp->data == val)
    {
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next && temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next)
    {
        Node *to_del = temp->next;
        temp->next = to_del->next;
        delete to_del;
    }

    else
    {
        cout << "key not found";
    }
}

int length(Node *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void delete_from_posi(Node *&head, int posi)
{
    if (head == NULL)
    {
        return;
    }

    if (posi >= length(head))
    {
        cout << "posi not availaible";
        return;
    }

    if (posi == 0)
    {
        Node *to_del = head;
        head = head->next;
        delete to_del;
    }

    Node *temp = head;
    Node *prev = head;
    int i = 0;
    while (temp && i < posi)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp)
    {
        Node *to_del = temp;
        prev->next = temp->next;
        delete to_del;
    }

    else
    {
        delete temp;
        head = NULL;
    }
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

int count_delete(Node *&head, int key)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        if (temp->data == key)
        {
            cnt++;
        }
        temp = temp->next;
    }

    for (int i = 0; i < cnt; i++)
    {
        delete_from_ll(head, key);
    }
    return cnt;
}

int main()
{
    Node *head = NULL;

    insertion_at_tail(head, 1);
    insertion_at_tail(head, 2);
    insertion_at_tail(head, 1);
    insertion_at_tail(head, 2);
    insertion_at_tail(head, 1);
    insertion_at_tail(head, 3);
    insertion_at_tail(head, 1);

    // delete_at_head(head);
    // delete_at_tail(head);
    printll(head);
    // delete_from_ll(head, 1);
    // delete_from_posi(head, 5);

    cout << endl
         << count_delete(head, 1) << endl;
    printll(head);

    return 0;
}