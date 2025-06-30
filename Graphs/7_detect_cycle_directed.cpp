#include <bits/stdc++.h>
using namespace std;

bool dfs_path(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &path)
{
    visited[node] = 1;
    path[node] = 1;

    for (int it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs_path(it, node, adj, visited, path))
            {
                return true;
            }
        }
        else if (path[it] == 1)
        {
            return true;
        }
    }
    path[node] = 0;
    return false;
}

bool isCyclic_DFS(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> path(V, 0);
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (dfs_path(i, -1, adj, visited, path))
        {
            return true;
        }
    }
    return false;
}

vector<int> topoSort_kahn(int V, vector<vector<int>> &edges)
{
    int m = edges.size();
    vector<int> adj[V];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> indeg(V, 0);
    for (int i = 0; i < m; i++)
    {
        int v = edges[i][1];
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        ans.push_back(ele);

        for (int it : adj[ele])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}

bool isCyclic_topo_kahn(int V, vector<vector<int>> &edges)
{
    vector<int> ans = topoSort_kahn(V, edges);
    if (ans.size() == V)
    {
        return 0;
    }
    return 1;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}};

    int V = 4;
    cout << isCyclic_DFS(V, edges);

    return 0;
}