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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *reverse_rec(Node *prev, Node *curr)
{

    if (curr == NULL)
    {
        return prev;
    }

    Node *next = curr->next;
    curr->next = prev;
    // prev = curr;
    // curr = next;
    return reverse_rec(curr, next);
}

// Node *reverse_upto(Node *head, int m, int n)
// {
//     if (head == NULL || m >= n)
//     {
//         return head; // No need to reverse if the list is empty or m >= n
//     }

//     Node *dummy = new Node(0); // Create a dummy node to simplify connections
//     dummy->next = head;
//     Node *prev = dummy;

//     // Step 1: Reach the node just before the segment to reverse
//     for (int i = 0; i < m - 1; i++)
//     {
//         prev = prev->next;
//     }

//     // Step 2: Reverse the segment from m to n
//     Node *curr = prev->next; // Start of the segment to reverse
//     Node *tail = curr;       // Tail will point to the end of the reversed segment
//     Node *next = NULL;

//     for (int i = 0; i <= n - m && curr != NULL; i++)
//     {
//         next = curr->next;       // Store the next node
//         curr->next = prev->next; // Reverse the link
//         prev->next = curr;       // Connect the previous part to the reversed segment
//         curr = next;             // Move to the next node
//     }

//     // Step 3: Connect the tail of the reversed segment to the rest of the list
//     tail->next = curr; // Connect the last node of reversed segment to the rest of the list

//     return dummy->next; // Return the new head of the modified list
// }

Node *reverseBetween(Node *head, int m, int n)
{
    Node *currNode = head, *prevNode = NULL;
    int i;

    // Move currNode to the position m
    for (i = 1; i < m; i++)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Store pointers to the start and
    // end of the reversed segment
    Node *revHead = currNode;
    Node *revTail = NULL;

    // Reverse the linked list from position m to n
    Node *nextNode = NULL;
    while (i <= n)
    {
        nextNode = currNode->next;
        currNode->next = revTail;
        revTail = currNode;
        currNode = nextNode;
        i++;
    }

    // Connect the reversed segment back to the list
    if (prevNode != NULL)
        prevNode->next = revTail;

    else
        head = revTail;

    revHead->next = currNode;

    return head;
}

Node *rotate(Node *head, int k)
{

    int n = length(head);
    k = k % n;
    if (k == 0)
    {
        return head;
    }

    head = reverse(head);
    head = reverseBetween(head, 1, k);
    head = reverseBetween(head, k + 1, n);

    return head;
}

int main()
{
    Node *head = NULL;

    insertion_at_head(head, 5);
    insertion_at_head(head, 4);
    insertion_at_head(head, 3);
    insertion_at_head(head, 2);
    insertion_at_head(head, 1);

    printll(head);

    // Node *rev_rec = reverse_rec(NULL, head);
    // Node *rev = reverse(head);
    // printll(rev);
    // printll(rev_rec);

    // Node *revv1 = reverse_upto(head, 4, 5);
    // printll(revv1);

    Node *rot = rotate(head, 3);
    printll(rot);

    return 0;
}