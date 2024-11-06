#include <bits/stdc++.h>
using namespace std;

int check(queue<int> q)
{
    while (!q.empty())
    {
        if (q.front() < 0)
        {
            return q.front();
        }
        q.pop();
    }

    return 0;
}

vector<int> calculate(int arr[], int n, int k)
{
    int i = 0;
    int j = k - 1;
    vector<int> ans;
    queue<int> q;

    for (int x = 0; x < k; x++)
    {
        q.push(arr[x]);
    }

    while (j < n)
    {
        int x = check(q);
        ans.push_back(x);
        q.pop();
        q.push(arr[++j]);
    }
    return ans;
}

vector<int> calculate_efficient(int arr[], int n, int k)
{
    int i = 0;
    int j = k - 1;
    vector<int> ans;
    deque<int> q;

    for (int x = 0; x < k; x++)
    {
        if (arr[x] < 0)
        {
            q.push_back(x);
        }
    }

    while (j < n)
    {
        if (!q.empty())
        {
            ans.push_back(arr[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }

        if (!q.empty() && q.front() <= i)
        {
            q.pop_front();
        }
        i++;
        j++;
        if (j < n && arr[j] < 0)
        {
            q.push_back(j);
        }
    }
    return ans;
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = 8;
    int k = 3;
    vector<int> ans = calculate_efficient(arr, n, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}