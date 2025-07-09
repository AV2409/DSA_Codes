#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // {dist,node,parent}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, -1}});

    vector<pair<int, int>> mst_edges;
    int sum = 0;
    vector<int> vis(V, 0);
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        int wt = p.first;
        int node = p.second.first;
        int parent = p.second.second;
        // Skip if already visited
        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;
        if (parent != -1)
            mst_edges.push_back({node, parent});

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int cost = it[1];
            if (!vis[adjNode])
            {
                q.push({cost, {adjNode, node}});
            }
        }
    }

    for (auto i : mst_edges)
    {
        cout << "(" << i.first << ", " << i.second << ")" << endl;
    }
    return sum;
}

int main()
{

    vector<vector<int>> adj[] = {
        {{1, 5}, {2, 1}}, // adj[0]
        {{0, 5}, {2, 3}}, // adj[1]
        {{1, 3}, {0, 1}}  // adj[2]
    };

    int v = 3;

    cout << spanningTree(v, adj);
    return 0;
}