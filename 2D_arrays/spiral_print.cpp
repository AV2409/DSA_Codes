#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    int m, n;
    cin >> m >> n;

    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;

    int total = m * n;
    while (count < total)
    {
        // printing starting row
        for (int i = startCol; i <= endCol && count < total; i++)
        {
            cout << arr[startRow][i] << " ";
            count++;
        }
        startRow++;

        // printing ending col
        for (int i = startRow; i <= endRow && count < total; i++)
        {
            cout << arr[i][endCol] << " ";
            count++;
        }
        endCol--;

        // printing ending row
        for (int i = endCol; i >= startCol && count < total; i--)
        {
            cout << arr[endRow][i] << " ";
            count++;
        }
        endRow--;

        // printing starting col
        for (int i = endRow; i >= startRow && count < total; i--)
        {
            cout << arr[i][startCol] << " ";
            count++;
        }
        startCol++;
    }

    return 0;
}