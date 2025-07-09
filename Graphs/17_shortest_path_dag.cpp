#include <bits/stdc++.h>
using namespace std;

// not optimal
vector<int> shortestPath_bfs(int V, int E, vector<vector<int>> &edges)
{
    vector<int> ans(V, 1e9);
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // for (int i = 0; i < V; i++)
    // {
    //     cout << i << " - ";
    //     for (auto j : adj[i])
    //     {
    //         cout << j.first << "," << j.second << "\t";
    //     }
    //     cout << endl;
    // }
    // return ans;

    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        int wt = ans[node];
        q.pop();
        for (auto it : adj[node])
        {
            int adj_node = it.first;
            int path_cost = it.second;

            if (wt + path_cost < ans[adj_node])
            {
                q.push(adj_node);
                ans[adj_node] = wt + path_cost;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (ans[i] == 1e9)
        {
            ans[i] = -1;
        }
    }
    return ans;
}

void topoSort_dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<pair<int, int>>> &adj)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it.first])
        {
            topoSort_dfs(it.first, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    stack<int> st;
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoSort_dfs(i, visited, st, adj);
        }
    }
    vector<int> ans(V, 1e9);
    ans[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        int wt = ans[node];
        for (auto it : adj[node])
        {
            int adj_node = it.first;
            int path_cost = it.second;

            if (wt + path_cost < ans[adj_node])
            {
                ans[adj_node] = wt + path_cost;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (ans[i] == 1e9)
        {
            ans[i] = -1;
        }
    }
    return ans;
}

int main()
{
    int v = 3;
    int e = 3;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 1},
        {2, 1, 1}};

    vector<int> ans = shortestPath(v, e, edges);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}