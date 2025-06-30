#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj, visited, st);
    }

    st.push(u);
}

void dfsTopologicalSort(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    cout << "Topological Sort (DFS Method): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    cout << endl;
    int V = 6;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

    for (auto [u, v] : edges)
    {
        adj[u].push_back(v);
    }

    dfsTopologicalSort(V, adj);
    cout << endl;
    return 0;
}
