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

void reverseDfs(int u, vector<vector<int>> &transpose, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : transpose[u])
    {
        if (!visited[v])
            reverseDfs(v, transpose, visited);
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<vector<int>> transpose(V);
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            transpose[v].push_back(u);
        }
    }

    for (int i = 0; i < V; i++)
        visited[i] = false;

    int sccCount = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            reverseDfs(u, transpose, visited);
            sccCount++;
        }
    }
    return sccCount;
}

int main()
{
    cout << endl;
    int V = 5;
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    int scc = kosaraju(V, adj);
    cout << "Number of Strongly Connected Components: " << scc << endl;
    cout << endl;
    return 0;
}
