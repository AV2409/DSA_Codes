#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = image[i][j];
        }
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int col = image[sr][sc];
    visited[sr][sc] = 1;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        ans[r][c] = newColor;
        for (int dir = 0; dir < 4; dir++)
        {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            if ((nr >= 0 && nr < n) && (nc >= 0 && nc < m) && (image[nr][nc] == col) && (!visited[nr][nc]))
            {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};

    int sr = 1; // start row
    int sc = 2; // start column
    int newColor = 2;
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}