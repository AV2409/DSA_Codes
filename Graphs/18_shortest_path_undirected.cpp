#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> ans(n, 1e9);
    ans[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int wt = ans[node];
        for (int it : adj[node])
        {
            if (wt + 1 < ans[it])
            {
                q.push(it);
                ans[it] = wt + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
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

    return 0;
}