#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input 2 matrix and display them
    int r1, c1;
    cin >> r1 >> c1;
    int arr[r1][c1];
    int count = 0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    int r2, c2;
    cin >> r2 >> c2;
    int arr2[r2][c2];
    int count2 = 0;

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> arr2[i][j];
            if (arr2[i][j] != 0)
            {
                count2++;
            }
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    // triplet conversion of both matrix
    int trip[count + 1][3];
    trip[0][0] = r1;
    trip[0][1] = c1;
    trip[0][2] = count;

    int k = 1;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
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

    int trip2[count2 + 1][3];
    trip2[0][0] = r1;
    trip2[0][1] = c1;
    trip2[0][2] = count2;

    int k2 = 1;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if (arr2[i][j] != 0)
            {
                trip2[k2][0] = i;
                trip2[k2][1] = j;
                trip2[k2][2] = arr2[i][j];
                k2++;
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
    cout << "\n\n";
    for (int i = 0; i < count2 + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trip2[i][j] << " ";
        }
        cout << endl;
    }

    // addition
    int i1 = 0, i2 = 0, i = 0, temp = 0;
    int ans[count + count2 + 1][3];
    ans[0][0] = r1;
    ans[0][1] = c1;
    ans[0][2] = count + count2;

    for (i = 1, i1 = 1, i2 = 1; (i1 <= count && i2 <= count2);)
    {
        if ((trip[i1][0] == trip2[i2][0]) && (trip[i1][1] == trip2[i2][1]))
        {
            ans[i][0] = trip[i1][0];
            ans[i][1] = trip[i1][1];
            ans[i][2] = trip[i1][2] + trip2[i2][2];
            i++;
            i1++;
            i2++;
            temp++;
        }

        else if ((trip[i1][0] == trip2[i2][0]) && (trip[i1][1] < trip2[i2][1]))
        {
            ans[i][0] = trip[i1][0];
            ans[i][1] = trip[i1][1];
            ans[i][2] = trip[i1][2];
            i++;
            i1++;
            temp++;
        }

        else if ((trip[i1][0] == trip2[i2][0]) && (trip[i1][1] > trip2[i2][1]))
        {
            ans[i][0] = trip2[i2][0];
            ans[i][1] = trip2[i2][1];
            ans[i][2] = trip2[i2][2];
            i++;
            i2++;
            temp++;
        }

        else if (trip[i1][0] < trip2[i2][0])
        {
            ans[i][0] = trip[i1][0];
            ans[i][1] = trip[i1][1];
            ans[i][2] = trip[i1][2];
            i++;
            i1++;
            temp++;
        }

        else if (trip[i1][0] > trip2[i2][0])
        {
            ans[i][0] = trip2[i2][0];
            ans[i][1] = trip2[i2][1];
            ans[i][2] = trip2[i2][2];
            i++;
            i2++;
            temp++;
        }
    }
    cout<<endl;
    for(int i=0;i<=temp;i++){
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}