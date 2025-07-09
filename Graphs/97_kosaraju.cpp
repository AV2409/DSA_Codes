#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs1(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
{
    vis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, adj, vis, path);
        }
    }
}

int kosaraju(vector<vector<int>> &adj)
{
    int n = adj.size();
    stack<int> st;
    vector<int> vis(n, 0);

    // sort acc to finish time
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    // reverse edges
    vector<vector<int>> adj_rev(n);
    for (int i = 0; i < n; i++)
    {
        for (int j : adj[i])
        {
            adj_rev[j].push_back(i);
        }
    }

    vector<int> visited(n, 0);
    vector<vector<int>> ans;
    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            vector<int> path;
            dfs1(node, adj_rev, visited, path);
            cnt++;
            ans.push_back(path);
        }
    }
    return cnt;
}

int main()
{

    return 0;
}