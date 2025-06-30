#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], vector<int> &visited, int i)
{
    visited[i] = 1;

    queue<pair<int, int>> q;
    q.push({i, -1});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int parent = p.second;
        for (int it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
            {
                // Found a visited node that is not the parent => cycle exists
                return true;
            }
        }
    }
    return false;
}

bool isCycle_BFS(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (bfs(adj, visited, i))
            {
                return true;
            }
        }
    }
    return false;
}

bool dfs(vector<int> adj[], vector<int> &visited, int i, int parent)
{
    visited[i] = 1;
    for (int it : adj[i])
    {
        if (!visited[it])
        {
            if (dfs(adj, visited, it, i))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle_DFS(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    int v = 4;
    bool x = isCycle_DFS(v, edges);
    cout << x;
    return 0;
}