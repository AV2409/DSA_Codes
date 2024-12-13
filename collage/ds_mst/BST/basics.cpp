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

bool search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    if (key == root->data)
    {
        return 1;
    }

    else if (key > root->data)
    {
        return search(root->right, key);
    }

    else
    {
        return search(root->left, key);
    }
    return 0;
}

bool search_itr(TreeNode *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    if (root)
    {
        return 1;
    }
    return 0;
}

int findMax(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

TreeNode *search1(TreeNode *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root;
}

int findPred(TreeNode *root, int x)
{
    TreeNode *pred = NULL;

    while (root != NULL)
    {
        if (x <= root->data)
        {
            root = root->left;
        }

        else if (x > root->data)
        {
            pred = root;
            root = root->right;
        }
    }
    if (pred)
        return pred->data;

    else
        return -1;
}

int findSucc(TreeNode *root, int x)
{
    TreeNode *succ = NULL;

    while (root != NULL)
    {
        if (x < root->data)
        {
            succ = root;
            root = root->left;
        }

        else if (x >= root->data)
        {
            root = root->right;
        }
    }
    if (succ)
        return succ->data;

    else
        return -1;
}

int findMin(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

void deleteFromBST(TreeNode *&root, int x)
{
    if (root == NULL)
    {
        cout << "Empty tree or element not found.\n";
        return;
    }

    if (x < root->data)
    {
        // Key is in the left subtree
        deleteFromBST(root->left, x);
    }
    else if (x > root->data)
    {
        // Key is in the right subtree
        deleteFromBST(root->right, x);
    }
    else
    {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL)
        {
            // Case 0: Leaf node
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            // Case 1: Only right child
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            // Case 1: Only left child
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            // Case 2: Two children
            int minValue = findMin(root->right);  // Find inorder successor
            root->data = minValue;                // Replace with successor's value
            deleteFromBST(root->right, minValue); // Recursively delete successor
        }
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

    if (search_itr(root, 80))
    {
        cout << "Element found" << endl;
    }

    else
    {
        cout << "Element not found" << endl;
    }

    cout << "Max: " << findMax(root) << endl;
    cout << "Min: " << findMin(root) << endl;

    cout << "Pred: " << findPred(root, 20) << endl;

    cout << "Succ: " << findSucc(root, 80) << endl;

    deleteFromBST(root, 4);
    inorder(root);
    cout << endl;

    deleteFromBST(root, 7);
    inorder(root);
    cout << endl;

    deleteFromBST(root, 15);
    inorder(root);
    cout << endl;

    return 0;
}