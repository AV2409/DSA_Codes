#include <bits/stdc++.h>
using namespace std;

void bankers(vector<vector<int>> alloc, vector<vector<int>> max, vector<int> avail, int nPro, int nRes)
{
    vector<int> finished(nPro, false);
    vector<int> ans;

    int need[nPro][nRes];
    for (int i = 0; i < nPro; i++)
    {
        for (int j = 0; j < nRes; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    for (int k = 0; k < nPro; k++)
    {
        for (int i = 0; i < nPro; i++)
        {
            if (!finished[i])
            {
                int flag = 0;
                for (int j = 0; j < nRes; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans.push_back(i);
                    for (int y = 0; y < nRes; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    finished[i] = true;
                }
            }
        }
    }

    int foundSafe = 1;

    for (int i = 0; i < nPro; i++)
    {
        if (!finished[i])
        {
            foundSafe = 0;
            cout << "No Safe Sequence Exists" << endl;
            break;
        }
    }

    if (foundSafe == 1)
    {
        cout << "Safe Sequence-->" << endl;
        for (int i = 0; i < nPro; i++)
        {
            cout << "P" << ans[i] << "\t";
        }
    }
}

int main()
{
    int n, m;
    n = 5;
    m = 3;
    vector<vector<int>> alloc = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    vector<vector<int>> max = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    vector<int> avail = {3, 3, 2};
    bankers(alloc, max, avail, n, m);

    int n1, m1;
    n1 = 3;
    m1 = 2;
    vector<vector<int>> alloc1 = {{1, 2}, {2, 0}, {3, 1}};
    vector<vector<int>> max1 = {{3, 3}, {2, 2}, {4, 3}};
    vector<int> avail1 = {1, 1};
    cout << endl;
    bankers(alloc1, max1, avail1, n1, m1);

    return 0;
}