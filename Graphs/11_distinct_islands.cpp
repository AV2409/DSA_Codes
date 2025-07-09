#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &path)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        path.push_back({x - i, y - j});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 1) && (!vis[nx][ny]))
            {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

void dfs(int i, int j, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &path, int n, int m)
{
    vis[i][j] = 1;
    path.push_back({i - r, j - c});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 1) && (!vis[nx][ny]))
        {
            dfs(nx, ny, r, c, grid, vis, path, n, m);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vector<pair<int, int>> path;
                // bfs(i, j, grid, vis, path);
                dfs(i, j, i, j, grid, vis, path, n, m);
                ans.insert(path);
            }
        }
    }
    return ans.size();
}

int main()
{

    return 0;
}