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

int main()
{
    Node *root = buildTree(root);
    // 1 2 5 -1 -1 7 -1 -1 3 10 -1 -1 11 -1 -1
    vector<int> x = spiralTraversal(root);
    cout << endl;
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    // round robin code?
    return 0;
}