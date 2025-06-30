#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int d = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            ans[x][y] = d;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 0) && (!visited[nx][ny]))
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        d++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 0, 0}};

    vector<vector<int>> ans = nearest(grid);
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}