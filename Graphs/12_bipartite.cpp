#include <bits/stdc++.h>
using namespace std;

bool bfs(int i, int col, vector<int> &color, vector<vector<int>> &graph)
{
    color[i] = col;
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        int c = color[node];
        q.pop();

        for (int it : graph[node])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = !c;
            }
            else if (color[it] == c)
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite_BFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (bfs(i, 0, color, graph) == false)
            {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
{
    color[node] = col;
    for (int it : graph[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, !col, color, graph) == false)
            {
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}
bool isBipartite_DFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0, color, graph) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    cout << isBipartite_DFS(graph);

    return 0;
}