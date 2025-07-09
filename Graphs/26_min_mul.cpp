#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    int n = arr.size();
    vector<int> visited(100000, 0);
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int num = p.first;
        int steps = p.second;

        if (num == end)
        {
            return steps;
        }

        for (int i = 0; i < n; i++)
        {
            int new_num = num * arr[i] % 100000;
            if (!visited[new_num])
            {
                q.push({new_num, steps + 1});
                visited[new_num] = 1;
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}