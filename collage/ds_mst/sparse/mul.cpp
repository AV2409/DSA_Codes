#include <bits/stdc++.h>
using namespace std;

int **transpose(int **arr, int m, int n, int count)
{
    int trip[count + 1][3];
    trip[0][0] = m;
    trip[0][1] = n;
    trip[0][2] = count;

    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = arr[i][j];
                k++;
            }
        }
    }

    int k1 = 1;
    int trans[n][m];
    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < count + 1; j++)
        {
            if (trip[j][1] == i)
            {
                trans[k1][0] = i;
                trans[k1][1] = trip[j][0];
                trans[k1][2] = trip[j][2];
                k1++;
            }
        }
    }
    // return trans;
}

int main()
{

    int m, n;
    cin >> m >> n;
    int arr[m][n];
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int trip[count + 1][3];
    trip[0][0] = m;
    trip[0][1] = n;
    trip[0][2] = count;

    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = arr[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trip[i][j] << " ";
        }
        cout << endl;
    }

    int k1 = 1;
    int trans[n][m];
    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < count + 1; j++)
        {
            if (trip[j][1] == i)
            {
                trans[k1][0] = i;
                trans[k1][1] = trip[j][0];
                trans[k1][2] = trip[j][2];
                k1++;
            }
        }
    }

    cout << endl
         << endl;
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}