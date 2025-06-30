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

vector<vector<int>> verticalOrder(Node *root)
{
    map<int, map<int, multiset<int>>> m;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        Node *node = curr.first;
        int hd = curr.second.first;
        int lvl = curr.second.second;
        m[hd][lvl].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {hd - 1, lvl + 1}});
        }

        if (node->right)
        {
            q.push({node->right, {hd + 1, lvl + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto i : m)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> verticalOrder2(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    map<int, vector<int>> mp;
    int hd = 0;
    q.push({root, hd});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        hd = q.front().second;
        q.pop();
        mp[hd].push_back(temp->data);
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
        vector<int> temp;
        for (auto j : i.second)
        {
            temp.push_back(j);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    Node *root = buildTree();
    levelOrder(root);

    cout << endl
         << endl;
    vector<vector<int>> ans = verticalOrder(root);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}