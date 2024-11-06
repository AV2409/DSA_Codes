#include <bits/stdc++.h>
using namespace std;

vector<int> maxSub(int arr[], int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(arr[dq.front()]);
    for (int i = k; i < n; i++)
    {

        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main()
{
    int arr[9] = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int k = 3;
    int n = 9;
    vector<int> res = maxSub(arr, n, k);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}