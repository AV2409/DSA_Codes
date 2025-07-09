#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    queue<pair<int, int>> q;
    q.push(source);
    dist[source.first][source.second] = 0;
    while (!q.empty())
    {

        pair<int, int> node = q.front();
        q.pop();

        int x = node.first;
        int y = node.second;
        int dis = dist[x][y];
        if (node == destination)
        {
            return dist[x][y];
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] == 1) && (dis + 1 < dist[nx][ny]))
            {
                dist[nx][ny] = dis + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

// striver vala upr vala jada shi h
int shortestPath1(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    int dr[] = {-1, 0, 1, 0}; // up, right, down, left
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if (r == destination.first && c == destination.second)
        {
            return dis;
        }

        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];

            // Valid cell and not visited with a shorter path
            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
            {

                dist[newr][newc] = dis + 1;
                q.push({dis + 1, {newr, newc}});
            }
        }
    }

    return -1; // Destination unreachable
}

int main()
{

    return 0;
}