#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "\nenter the data: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "\nenter the data on left of " << data;
    root->left = buildTree(root->left);

    cout << "\nenter the data on right of " << data;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        int n1 = ans[i].size();

        for (int j = 0; j < n1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void levelOrderTraversal1(Node *root)
{
    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
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

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;

    cout << "Enter root node data: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "\nEnter data for left of " << temp->data;
        int lData;
        cin >> lData;

        if (lData == -1)
        {
            temp->left = NULL;
        }
        else
        {
            temp->left = new Node(lData);
            q.push(temp->left);
        }

        cout << "\nEnter data for right of " << temp->data;
        int rData;
        cin >> rData;

        if (rData == -1)
        {
            temp->right = NULL;
        }
        else
        {
            temp->right = new Node(rData);
            q.push(temp->right);
        }
    }
}

string inOrderTraversal_str(Node *root)
{
    string res;
    if (root == NULL)
    {
        res += "";
        return res;
    }

    res += inOrderTraversal_str(root->left);
    res += to_string(root->data);
    res += " ";
    res += inOrderTraversal_str(root->right);

    return res;
}

string preOrderTraversal_str(Node *root)
{
    string res;
    if (root == NULL)
    {
        res += "";
        return res;
    }
    res += to_string(root->data);
    res += " ";
    res += preOrderTraversal_str(root->left);
    res += preOrderTraversal_str(root->right);
    return res;
}

int main()
{
    // Node *root = buildTree(root);
    // 1 2 5 -1 -1 7 -1 -1 3 10 -1 -1 11 -1 -1

    Node *root = NULL;

    buildFromLevelOrder(root);
    cout << endl;
    levelOrderTraversal1(root);
    cout << endl;
    inOrderTraversal(root);

    cout << endl;
    preOrderTraversal(root);

    cout << endl;
    postOrderTraversal(root);

    string inorder1 = inOrderTraversal_str(root);
    cout << endl
         << inorder1;

    return 0;
}