#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int coeff1, int exp1, Node *next1)
    {
        coeff = coeff1;
        exp = exp1;
        next = next1;
    }

    Node(int coeff1 = 0, int exp1 = 0)
    {
        coeff = coeff1;
        exp = exp1;
        next = nullptr;
    }
};

void insertion_at_tail(Node *&head, int coeff, int exp)
{
    if (coeff == 0)
        return;
    Node *n_node = new Node(coeff, exp);
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

void printll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->coeff << "x^" << temp->exp << " + ";
        temp = temp->next;
    }
    cout << endl;
}

Node *add(Node *poly1, Node *poly2)
{
    Node *res = NULL;
    if (poly1 == NULL || poly2 == NULL)
    {
        if (poly1 == NULL)
        {
            return poly2;
        }
        else
        {
            return poly1;
        }
    }

    while (poly1 && poly2)
    {
        if (poly1->exp == poly2->exp)
        {
            int x = poly1->coeff + poly2->coeff;
            int y = poly1->exp;
            insertion_at_tail(res, x, y);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        else if (poly1->exp > poly2->exp)
        {
            int x = poly1->coeff;
            int y = poly1->exp;
            insertion_at_tail(res, x, y);
            poly1 = poly1->next;
        }

        else
        {
            int x = poly2->coeff;
            int y = poly2->exp;
            insertion_at_tail(res, x, y);
            poly2 = poly2->next;
        }
    }

    while (poly1)
    {
        int x = poly1->coeff;
        int y = poly1->exp;
        insertion_at_tail(res, x, y);
        poly1 = poly1->next;
    }

    while (poly2)
    {
        int x = poly2->coeff;
        int y = poly2->exp;
        insertion_at_tail(res, x, y);
        poly2 = poly2->next;
    }
    return res;
}

Node *multiply(Node *poly1, Node *poly2)
{
    Node *p2 = poly2;
    Node *res = NULL;
    while (poly1)
    {
        Node *temp = NULL;
        poly2 = p2;
        while (poly2)
        {
            int coeff = poly1->coeff * poly2->coeff;
            int exp = poly1->exp + poly2->exp;
            insertion_at_tail(temp, coeff, exp);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
        res = add(res, temp);
    }
    return res;
}

int main()
{
    Node *poly1 = NULL;
    int x, y;
    cin >> x >> y;
    insertion_at_tail(poly1, x, y);

    cin >> x >> y;
    insertion_at_tail(poly1, x, y);

    cin >> x >> y;
    insertion_at_tail(poly1, x, y);
    printll(poly1);

    Node *poly2 = NULL;
    cin >> x >> y;
    insertion_at_tail(poly2, x, y);

    cin >> x >> y;
    insertion_at_tail(poly2, x, y);

    cin >> x >> y;
    insertion_at_tail(poly2, x, y);

    printll(poly2);

    Node *res = add(poly1, poly2);
    Node *res1 = multiply(poly1, poly2);
    printll(res);
    printll(res1);
    return 0;
}