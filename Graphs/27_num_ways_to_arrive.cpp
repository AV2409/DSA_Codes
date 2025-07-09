#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : roads)
    {
        int u = it[0];
        int v = it[1];
        int t = it[2];
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    const int mod = 1e9 + 7;

    vector<int> dist(n, 1e9);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // time,node
    q.push({0, 0});

    while (!q.empty())
    {
        auto p = q.top();
        q.pop();

        int node = p.second;
        int d = p.first;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int pc = it.second;

            if (d + pc < dist[adjNode])
            {
                dist[adjNode] = d + pc;
                ways[adjNode] = ways[node];
                q.push({dist[adjNode], adjNode});
            }

            else if (d + pc == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1];
}

int countPaths_leetcode(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto &it : roads)
    {
        int u = it[0], v = it[1], t = it[2];
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    const int mod = 1e9 + 7;
    vector<long long> dist(n, 1e18); // long long!
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0}); // {distance, node}

    while (!q.empty())
    {
        auto [d, node] = q.top();
        q.pop();
        if (d > dist[node])
            continue;

        for (auto &[adjNode, pc] : adj[node])
        {
            long long newDist = d + pc; // avoid overflow
            if (newDist < dist[adjNode])
            {
                dist[adjNode] = newDist;
                ways[adjNode] = ways[node];
                q.push({dist[adjNode], adjNode});
            }
            else if (newDist == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1];
}

int main()
{

    return 0;
}