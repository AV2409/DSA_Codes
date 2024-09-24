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

Node *sortll(Node *&head)
{
    Node *temp = head;
    Node *zeros = NULL;
    Node *ones = NULL;
    Node *twos = NULL;
    int z = 0;
    int o = 0;
    int t = 0;
    while (temp)
    {
        if (temp->data == 0)
        {
            z++;
        }
        if (temp->data == 1)
        {
            o++;
        }
        if (temp->data == 2)
        {
            t++;
        }
        temp = temp->next;
    }
    // cout << z << " " << o << " " << t;
    temp = head;

    while(temp){
        while(temp&&z){
            temp->data=0;
            z--;
            temp=temp->next;
        }
        while(temp&&o){
            temp->data=1;
            o--;
            temp=temp->next;
        }
        while(temp&&t){
            temp->data=2;
            t--;
            temp=temp->next;
        }
    }
    return head;
}

int main()
{
    Node *head = NULL;
    insert_at_tail(head, 0);
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 2);
    insert_at_tail(head, 2);
    insert_at_tail(head, 0);
    printll(head);
    cout << endl;
    head = sortll(head);
    printll(head);
    return 0;
}