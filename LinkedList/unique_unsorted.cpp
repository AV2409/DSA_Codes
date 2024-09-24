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

void printll(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insert_at_tail(Node *&head, int x)
{
    if (head == NULL)
    {
        head = new Node(x);
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(x);
    temp->next = newnode;
}

int main()
{
    unordered_map<int, bool> visited;
    Node *head = NULL;

    insert_at_tail(head, 5);
    insert_at_tail(head, 2);
    insert_at_tail(head, 2);
    insert_at_tail(head, 4);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    printll(head);
    cout << endl;

    // Node *curr = head;
    // Node *prev = head;

    // while (curr)
    // {
    //     if (visited[curr->data])
    //     {
    //         while (curr->next && curr->data == curr->next->data)
    //         {
    //             curr = curr->next;
    //         }
    //         Node *to_Delete = curr;
    //         prev->next = curr->next;
    //         delete to_Delete;
    //         prev = prev->next;
    //         curr = curr->next;
    //     }
    //     else
    //     {
    //         visited[curr->data] = true;
    //         prev=curr;
    //         curr = curr->next;

    //     }
    // }

    Node *temp = head;
    while (temp&&temp->next)
    {
        Node *prev = temp;
        Node *curr = temp->next;
        int val = temp->data;
        if (curr==NULL) break;
        while (curr)
        {
            if (val == curr->data)
            {
                Node *to_delete = curr;
                prev->next = curr->next;
                curr = curr->next;
                cout << "Deleted duplicate value: " << val << endl;
                delete to_delete;
            }

            else
            {
                cout << "Move" << endl;
                prev = curr;
                curr = curr->next;
            }
        }

        temp = temp->next;
    }
    printll(head);
    return 0;
}