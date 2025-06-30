#include <bits/stdc++.h>
using namespace std;

void dfs_traversal(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int n, int m)
{
    visited[i][j] = 1;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int dir = 0; dir < 8; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if ((nx >= 0 && ny >= 0) && (nx < n && ny < m) && (grid[nx][ny] == 'L') && (!visited[nx][ny]))
        {
            dfs_traversal(grid, visited, nx, ny, n, m);
        }
    }

    // int x = i - 1;
    // int y = j;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i - 1;
    // y = j - 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i;
    // y = j - 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i + 1;
    // y = j - 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i + 1;
    // y = j;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i + 1;
    // y = j + 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i;
    // y = j + 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }

    // x = i - 1;
    // y = j + 1;
    // if ((x >= 0 && y >= 0) && (x < n && y < m) && (grid[x][y] == 'L') && (!visited[x][y]))
    // {
    //     dfs_traversal(grid, visited, x, y, n, m);
    // }
}

int countIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((!visited[i][j]) && grid[i][j] == 'L')
            {
                dfs_traversal(grid, visited, i, j, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}

void bfs_traversal(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;

        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int dir = 0; dir < 8; dir++)
        {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            if ((nr >= 0 && nc >= 0) && (nr < n && nc < m) && (grid[nr][nc] == 'L') && (!visited[nr][nc]))
            {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
}

int countIslandsBFS(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((!visited[i][j]) && grid[i][j] == 'L')
            {
                bfs_traversal(grid, visited, i, j, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}};

    cout << countIslandsBFS(grid);

    return 0;
}