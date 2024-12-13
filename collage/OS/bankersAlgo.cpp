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
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    while (count < nPro)
    {
        bool progress = false;

        for (int i = 0; i < nPro; i++)
        {
            if (!finished[i])
            {
                bool canFinish = true;

                for (int j = 0; j < nRes; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish)
                {
                    for (int j = 0; j < nRes; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    ans.push_back(i);
                    finished[i] = true;
                    progress = true;
                    count++;
                }
            }
        }

        if (!progress)
        {
            cout << "No Safe Sequence Exists" << endl;
            return;
        }
    }

    cout << "Safe Sequence-->" << endl;
    for (int i = 0; i < nPro; i++)
    {
        cout << "P" << ans[i] << "\t";
    }
    cout << endl;
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