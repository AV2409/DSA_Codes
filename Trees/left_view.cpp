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

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
        int level = p.second;
        if (mp.find(level) == mp.end())
        {
            mp[level] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }

    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> leftView2(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
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

    vector<int> ans = leftView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

// 1 2 4 8 16 -1 -1 -1 9 17 -1 -1 18 -1 -1 5 10 -1 -1 11 -1 19 -1 -1 3 6 12 -1 -1 13 20 -1 -1 21 -1 -1 7 14 -1 -1 15 22 -1 -1 23 -1 -1