#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 1;
    int n;
    cin >> n;

    int arr[n][n];

    int startRow = 0;
    int startCol = 0;
    int endRow = n - 1;
    int endCol = n - 1;

    int total = n * n;
    while (count <= total)
    {
        // printing starting row
        for (int i = startCol; i <= endCol && count <= total; i++)
        {
            arr[startRow][i] = count;
            count++;
        }
        startRow++;

        // printing ending col
        for (int i = startRow; i <= endRow && count <= total; i++)
        {
            arr[i][endCol] = count;
            count++;
        }
        endCol--;

        // printing ending row
        for (int i = endCol; i >= startCol && count <= total; i--)
        {
            arr[endRow][i] = count;
            count++;
        }
        endRow--;

        // printing starting col
        for (int i = endRow; i >= startRow && count <= total; i--)
        {
            arr[i][startCol] = count;
            count++;
        }
        startCol++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}