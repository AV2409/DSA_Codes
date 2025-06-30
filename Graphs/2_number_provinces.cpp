#include <bits/stdc++.h>
using namespace std;

// void dfs_traversal(vector<int> adj[], int node, vector<int> &visited)
// {
//     visited[node] = 1;
//     for (int i : adj[node])
//     {
//         if (!visited[i])
//             dfs_traversal(adj, i, visited);
//     }
// }
// int dfs(vector<int> adj[], int n)
// {
//     vector<int> visited(n, 0);
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             dfs_traversal(adj, i, visited);
//             cnt++;
//         }
//     }
//     return cnt;
// }

// int findPro(vector<vector<int>> &isConnected)
// {
//     int n = isConnected.size();
//     int m = isConnected[0].size();
//     vector<int> adj[n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if ((isConnected[i][j] == 1) && i != j)
//                 adj[i].push_back(j);
//         }
//     }

//     int cnt = dfs(adj, n);

//     return cnt;
// }

void dfs_traversal(vector<vector<int>> isConnected, int node, vector<int> &visited, int n)
{
    visited[node] = 1;
    for (int i = 0; i < n; i++)
    {
        if ((isConnected[node][i] == 1) && (!visited[i]))
            dfs_traversal(isConnected, i, visited, n);
    }
}

int findPro(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    int m = isConnected[0].size();
    vector<int> visited(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs_traversal(isConnected, i, visited, n);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findPro(v);

    return 0;
}