#include <bits/stdc++.h>
using namespace std;

// priority queue
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    vector<vector<pair<int, int>>> adj(V);
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> ans(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    ans[src] = 0;
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

            if (dis + pathCost < ans[adjNode])
            {
                q.push({dis + pathCost, adjNode});
                ans[adjNode] = dis + pathCost;
            }
        }
    }
    return ans;
}

// set
vector<int> dijkstra1(int V, vector<vector<int>> &edges, int src)
{
    vector<vector<pair<int, int>>> adj(V);
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> ans(V, 1e9);
    set<pair<int, int>> st;
    st.insert({0, src});
    ans[src] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        for (auto x : adj[node])
        {
            int adjNode = x.first;
            int pathCost = x.second;

            if (dis + pathCost < ans[adjNode])
            {
                if (ans[adjNode] != 1e9)
                {
                    st.erase({ans[adjNode], adjNode});
                }

                st.insert({dis + pathCost, adjNode});
                ans[adjNode] = dis + pathCost;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}