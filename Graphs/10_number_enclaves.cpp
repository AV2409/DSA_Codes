#include <bits/stdc++.h>
using namespace std;

int numEnclaves_bfs(vector<vector<int>> &grid)
{
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    for (int x = 0; x < m; x++)
    {
        // 1st row
        if (grid[0][x] == 1)
        {
            q.push({0, x});
        }
        // last row
        if (grid[n - 1][x] == 1)
        {
            q.push({n - 1, x});
        }
    }

    for (int x = 0; x < n; x++)
    {
        // 1st col
        if (grid[x][0] == 1)
        {
            q.push({x, 0});
        }

        // last col
        if (grid[x][m - 1] == 1)
        {
            q.push({x, m - 1});
        }
    }

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        visited[x][y] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 1) && (!visited[nx][ny]))
            {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    visited[x][y] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 1) && (!visited[nx][ny]))
        {
            dfs(grid, visited, nx, ny);
        }
    }
}

int numEnclaves_dfs(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int x = 0; x < m; x++)
    {
        // 1st row
        if (grid[0][x] == 1)
        {
            dfs(grid, visited, 0, x);
        }
        // last row
        if (grid[n - 1][x] == 1)
        {
            dfs(grid, visited, n - 1, x);
        }
    }

    for (int x = 0; x < n; x++)
    {
        // 1st col
        if (grid[x][0] == 1)
        {
            dfs(grid, visited, x, 0);
        }

        // last col
        if (grid[x][m - 1] == 1)
        {
            dfs(grid, visited, x, m - 1);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    cout << numEnclaves_dfs(grid);

    return 0;
}