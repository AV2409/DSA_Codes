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

bool isLeaf(Node *temp)
{
    if (temp == NULL)
    {
        return false;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return true;
    }
    return false;
}

vector<int> leftTra(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    while (root)
    {
        if (!isLeaf(root))
        {
            ans.push_back(root->data);
        }
        if (root->left)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}

vector<int> rightTra(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    while (root)
    {

        if (!isLeaf(root))
        {
            ans.push_back(root->data);
        }

        if (root->right)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}

vector<int> leafTra(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        if (isLeaf(curr))
        {
            ans.push_back(curr->data);
        }
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }

    return ans;
}
vector<int> boundaryTraversal(Node *root)
{
    vector<int> left = leftTra(root->left);
    vector<int> right = rightTra(root->right);
    vector<int> leaf = leafTra(root);

    reverse(right.begin(), right.end());

    vector<int> ans;
    int n1 = left.size();
    int n2 = right.size();
    int n3 = leaf.size();
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    for (int i = 0; i < n1; i++)
    {
        ans.push_back(left[i]);
    }

    for (int i = 0; i < n3; i++)
    {
        ans.push_back(leaf[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        ans.push_back(right[i]);
    }
    return ans;
}

vector<int> boundry(Node *root)
{
    vector<int> left = leftTra(root);
    vector<int> right = rightTra(root);
    vector<int> leaf = leafTra(root);

    reverse(right.begin(), right.end());

    vector<int> ans;
    int n1 = left.size();
    int n2 = right.size();
    int n3 = leaf.size();
    for (int i = 0; i < n1; i++)
    {
        ans.push_back(left[i]);
    }

    for (int i = 0; i < n3; i++)
    {
        ans.push_back(leaf[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        ans.push_back(right[i]);
    }
    return ans;
}

int main()
{
    Node *root = buildTree();
    vector<int> ans = boundry(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}