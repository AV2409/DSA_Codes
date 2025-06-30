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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        Node *node = curr.first;
        int hd = curr.second;
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, hd - 1});
        }
        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> topViwe2(Node *root)
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
        Node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = temp->data;
        }
        if (temp->left)
        {
            q.push({temp->left, hd - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, hd + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
}

vector<int> topView3(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    unordered_map<int, int> mp;
    int hd = 0;
    int maxi = 0;
    int mini = 0;
    q.push({root, hd});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        hd = q.front().second;
        q.pop();
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = temp->data;
        }
        if (temp->left)
        {
            q.push({temp->left, hd - 1});
            mini = min(mini, hd - 1);
        }
        if (temp->right)
        {
            q.push({temp->right, hd + 1});
            maxi = max(maxi, hd + 1);
        }
    }

    for (int i = mini; i <= maxi; i++)
    {
        ans.push_back(mp[i]);
    }
}

int main()
{
    Node *root = buildTree();
    levelOrder(root);

    cout << endl
         << endl;

    vector<int> ans = topView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}