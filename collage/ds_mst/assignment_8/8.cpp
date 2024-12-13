#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

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

void insertLL(Node *&head, Node *&tail, int x)
{
    Node *temp = new Node(x);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = tail->next;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insert(TreeNode *&root, int data)
{
    if (root == NULL)
    {
        root = new TreeNode(data);
        return;
    }

    if (data < root->data)
    {
        insert(root->left, data);
    }

    if (data > root->data)
    {
        insert(root->right, data);
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder_itr(TreeNode *root)
{
    stack<TreeNode *> s;
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

void pre_itr(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        cout << node->data << " ";

        // Push right child first so that the left child is processed first
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

void postorder_itr(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(root);

    while (!s1.empty())
    {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left child first so that right child is processed first
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print nodes in postorder
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    TreeNode *root = nullptr;
    insert(root, 15);
    insert(root, 18);
    insert(root, 6);
    insert(root, 7);
    insert(root, 17);
    insert(root, 3);
    insert(root, 4);
    insert(root, 13);
    insert(root, 9);
    insert(root, 20);
    insert(root, 2);

    inorder(root);
    cout << endl;
    inorder_itr(root);
    cout << endl
         << endl;

    preorder(root);
    cout << endl;
    pre_itr(root);
    cout << endl
         << endl;

    postorder(root);
    cout << endl;
    postorder_itr(root);
    cout << endl
         << endl;

    return 0;
}