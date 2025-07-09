#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int node = p.second;
        int dis = p.first;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int pathCost = it.second;

            if (dis + pathCost < dist[adjNode])
            {
                parent[adjNode] = node;
                q.push({dis + pathCost, adjNode});
                dist[adjNode] = dis + pathCost;
            }
        }
    }

    if (dist[n] == 1e9)
    {
        return {-1};
    }

    int x = n;
    vector<int> path;
    while (x != 1)
    {
        path.push_back(x);
        x = parent[x];
    }

    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}};

    int n = 5;
    int m = 6;
    vector<int> p = shortestPath(n, m, edges);

    return 0;
}