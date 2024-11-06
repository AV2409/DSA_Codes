#include <bits/stdc++.h>
using namespace std;

bool isPossible(int x, vector<vector<int>> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == x)
        {
            continue;
        }

        if ((arr[i][x] != 1) || arr[x][i] != 0)
        {
            return 0;
        }
    }
    return -1;
}

int celebrity(vector<vector<int>> arr)
{
    int n = arr.size();
    int top = 0;
    int down = n - 1;

    while (top < down)
    {
        if (arr[top][down])
        {
            top++;
        }
        else if (arr[down][top])
        {
            down--;
        }

        else
        {
            top++;
            down--;
        }
    }
    if (top > down)
    {
        return -1;
    }

    if (isPossible(top, arr))
    {
        return top;
    }

    return -1;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << celebrity(arr);
    return 0;
}