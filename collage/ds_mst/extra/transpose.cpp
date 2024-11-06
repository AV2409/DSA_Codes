#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1, c1;
    cin >> r1 >> c1;
    int arr1[r1][c1];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (i < j)
            {
                swap(arr1[i][j], arr1[j][i]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
