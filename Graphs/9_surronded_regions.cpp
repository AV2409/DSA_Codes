#include <bits/stdc++.h>
using namespace std;

void solve_bfs(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int x = 0; x < m; x++)
    {
        // 1st row
        if (board[0][x] == 'O')
        {
            q.push({0, x});
        }
        // last row
        if (board[n - 1][x] == 'O')
        {
            q.push({n - 1, x});
        }
    }

    for (int x = 0; x < n; x++)
    {
        // 1st col
        if (board[x][0] == 'O')
        {
            q.push({x, 0});
        }

        // last col
        if (board[x][m - 1] == 'O')
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

            if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (board[nx][ny] == 'O') && (!visited[nx][ny]))
            {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
    }
}

void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int x, int y)
{
    int n = board.size();
    int m = board[0].size();
    visited[x][y] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (board[nx][ny] == 'O') && (!visited[nx][ny]))
        {
            dfs(board, visited, nx, ny);
        }
    }
}

void solve_dfs(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int x = 0; x < m; x++)
    {
        // 1st row
        if (board[0][x] == 'O')
        {
            dfs(board, visited, 0, x);
        }
        // last row
        if (board[n - 1][x] == 'O')
        {
            dfs(board, visited, n - 1, x);
        }
    }

    for (int x = 0; x < n; x++)
    {
        // 1st col
        if (board[x][0] == 'O')
        {
            dfs(board, visited, x, 0);
        }

        // last col
        if (board[x][m - 1] == 'O')
        {
            dfs(board, visited, x, m - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    solve_dfs(board);
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}