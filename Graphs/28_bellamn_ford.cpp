#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != 1e8 && wt + dist[u] < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }

    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != 1e8 && wt + dist[u] < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}

int main()
{

    return 0;
}