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

vector<int> spiralTraversal(Node *root)
{
    vector<vector<int>> ans;
    vector<int> result;
    queue<Node *> q;

    if (root == NULL)
    {
        return result;
    }

    q.push(root);
    bool flag = 0;
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
        if (i % 2 == 0)
        {
            for (int j = 0; j < n1; j++)
            {
                result.push_back(ans[i][j]);
            }
        }

        else
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                result.push_back(ans[i][j]);
            }
        }
    }
    return result;
}

vector<int> spiralTraversal2(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);

    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            Node *temp = st1.top();
            st1.pop();
            ans.push_back(temp->data);
            if (temp->right)
            {
                st2.push(temp->right);
            }
            if (temp->left)
            {
                st2.push(temp->left);
            }
        }
        while (!st2.empty())
        {
            Node *temp = st2.top();
            st2.pop();
            ans.push_back(temp->data);
            if (temp->left)
            {
                st1.push(temp->left);
            }
            if (temp->right)
            {
                st1.push(temp->right);
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = buildTree(root);
    // 1 2 4 8 16 -1 -1 -1 9 17 -1 -1 18 -1 -1 5 10 -1 -1 11 -1 19 -1 -1 3 6 12 -1 -1 13 20 -1 -1 21 -1 -1 7 14 -1 -1 15 22 -1 -1 23 -1 -1
    vector<int> x = spiralTraversal2(root);
    cout << endl;
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    return 0;
}