#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    int data;
    Node *left;
    Node *right;
};

Node *buildTree()
{
    int x;
    cout << "\nEnter data: ";
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }
    Node *root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void levelOrder(Node *root)
{
    vector<vector<int>> ans;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<int> diagonalView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    map<int, vector<int>> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
        int level = p.second;

        mp[level].push_back(node->data);
        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level});
        }
    }

    for (auto i : mp)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

int main()
{
    Node *root = buildTree();
    levelOrder(root);

    cout << endl
         << endl;

    vector<int> ans = diagonalView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}