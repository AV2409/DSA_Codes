#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        left = NULL;
        right = NULL;
    }
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }

    else if (root->data > val)
    {
        insert(root->left, val);
    }

    else
    {
        insert(root->right, val);
    }
}

bool search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    else if (root->data > key)
    {
        return search(root->left, key);
    }

    else
    {
        return search(root->right, key);
    }
}

bool search_itr(TreeNode *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }

        else if (root->data > key)
        {
            root = root->left;
        }

        else
        {
            root = root->right;
        }
    }
    return 0;
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "   ";
        inorder(root->right);
    }
}

int findMax(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int findPred(TreeNode *root, int key)
{
    int pred = -1;
    while (root != NULL)
    {
        if (root->data < key)
        {
            pred = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return pred;
}

int findSucc(TreeNode *root, int key)
{
    int succ = -1;
    while (root != NULL)
    {
        if (root->data > key)
        {
            succ = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return succ;
}

void check_search(TreeNode *t1)
{
    cout << endl;
    cout << "50 Found: " << search(t1, 50) << endl;
    cout << "34 Found: " << search(t1, 34) << endl;
    cout << "5 Found: " << search(t1, 5) << endl;
    cout << "11 Found: " << search(t1, 11) << endl;
    cout << "12 Found: " << search(t1, 12) << endl;
    cout << "20 Found: " << search(t1, 20) << endl;
    cout << "36 Found: " << search(t1, 36) << endl;
    cout << "33 Found: " << search(t1, 33) << endl;
    cout << endl;

    cout << "50 Found: " << search_itr(t1, 50) << endl;
    cout << "34 Found: " << search_itr(t1, 34) << endl;
    cout << "5 Found: " << search_itr(t1, 5) << endl;
    cout << "11 Found: " << search_itr(t1, 11) << endl;
    cout << "12 Found: " << search_itr(t1, 12) << endl;
    cout << "20 Found: " << search_itr(t1, 20) << endl;
    cout << "36 Found: " << search_itr(t1, 36) << endl;
    cout << "33 Found: " << search_itr(t1, 33) << endl;
}

void checkPredSucc(TreeNode *root)
{
    cout << "Pred 5: " << findPred(root, 5) << endl;
    cout << "Pred 11: " << findPred(root, 11) << endl;
    cout << "Pred 20: " << findPred(root, 20) << endl;
    cout << "Pred 23: " << findPred(root, 23) << endl;
    cout << "Pred 34: " << findPred(root, 34) << endl;
    cout << "Pred 36: " << findPred(root, 36) << endl;
    cout << "Pred 40: " << findPred(root, 40) << endl;
    cout << "Pred 50: " << findPred(root, 50) << endl;
    cout << "Pred 60: " << findPred(root, 60) << endl;

    cout << "Succ 5: " << findSucc(root, 5) << endl;
    cout << "Succ 11: " << findSucc(root, 11) << endl;
    cout << "Succ 20: " << findSucc(root, 20) << endl;
    cout << "Succ 23: " << findSucc(root, 23) << endl;
    cout << "Succ 34: " << findSucc(root, 34) << endl;
    cout << "Succ 36: " << findSucc(root, 36) << endl;
    cout << "Succ 40: " << findSucc(root, 40) << endl;
    cout << "Succ 50: " << findSucc(root, 50) << endl;
    cout << "Succ 60: " << findSucc(root, 60) << endl;
}

int findMin(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->left)
    {
        root = root->left;
    }

    return root->data;
}

void deleteFromBST(TreeNode *&root, int key)
{
    if (root->data > key)
    {
        deleteFromBST(root->left, key);
    }
    else if (root->data < key)
    {
        deleteFromBST(root->right, key);
    }

    else
    {
        // No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // 1child
        else if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }

        // 2child

        else
        {
            int x = findMin(root->right);
            root->data = x;
            deleteFromBST(root->right, x);
        }
    }
}

int main()
{

    TreeNode *t1 = NULL;
    insert(t1, 50);
    insert(t1, 34);
    insert(t1, 11);
    insert(t1, 36);
    insert(t1, 23);
    insert(t1, 60);
    insert(t1, 40);
    insert(t1, 20);
    insert(t1, 5);

    inorder(t1);

    cout << endl;
    deleteFromBST(t1, 34);
    inorder(t1);
    cout << endl;
    levelOrderTraversal(t1);
    cout << endl;
    deleteFromBST(t1, 50);
    inorder(t1);
    cout << endl;

    // cout << endl;
    // deleteFromBST(t1, 34);
    // inorder(t1);
    // cout << endl;

    // cout << findMax(t1) << endl;
    // cout << findMin(t1) << endl;

    levelOrderTraversal(t1);
    cout << endl;
    // checkPredSucc(t1);

    return 0;
}