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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void itr_preOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
}

void itr_inOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    while (true)
    {
        if (root)
        {
            st.push(root);
            root = root->left;
        }

        else
        {
            if (st.empty())
                break;
            Node *curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            root = curr->right;
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
}

void itr_postOrder(Node *root)
{
    stack<Node *> st1;
    stack<int> st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr->data);
        if (curr->left)
        {
            st1.push(curr->left);
        }
        if (curr->right)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }
}

int main()
{
    Node *root = buildTree();
    cout << endl;
    postorder(root);
    cout << endl;
    itr_postOrder(root);
    return 0;
}