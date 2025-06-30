#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    for (int it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, st, visited, adj);
        }
    }
    st.push(node);
}
vector<int> topoSort_DFS(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> ans;
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, st, visited, adj);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

int main()
{
    vector<vector<int>> edges = {
        {3, 0},
        {1, 0},
        {2, 0}};

    int V = 4;
    vector<int> ans = topoSort_kahn(V, edges);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}