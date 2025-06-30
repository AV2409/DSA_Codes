#include <bits/stdc++.h>
using namespace std;

void buildAdjacencyList(vector<int> adj[], int m)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
}

void printAdjacencyList(vector<int> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<int> bfs(vector<int> adj[], int start, int n)
{
    vector<int> ans;
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        for (auto i : adj[ele])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}

void dfs_traversal(vector<int> adj[], int st, vector<int> &ans, vector<int> &visited)
{
    visited[st] = 1;
    ans.push_back(st);

    for (int i : adj[st])
    {
        if (!visited[i])
        {
            dfs_traversal(adj, i, ans, visited);
        }
    }
}

vector<int> dfs(vector<int> adj[], int start, int n)
{
    vector<int> ans;
    vector<int> visited(n + 1, 0);
    dfs_traversal(adj, 0, ans, visited);
    return ans;
}

int main()
{
    int n = 8;
    int m = 8;
    vector<int> adj[n + 1];
    buildAdjacencyList(adj, m);
    printAdjacencyList(adj, n);

    vector<int> ans = bfs(adj, 6, n);
    cout << endl;
    for (int i : ans)
    {
        cout << i << "\t";
    }
    return 0;
}