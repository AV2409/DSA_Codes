#include <bits/stdc++.h>
using namespace std;

int get_pivot(vector<int> v)
{
    int size = v.size();
    int st = 0;
    int end = size - 1;
    int mid = st + (end - st) / 2;

    while (st < end)
    {

        if (v[st] <= v[end])
            return st;

        if (v[mid] >= v[0])
            st = mid + 1;

        else
            end = mid;

        mid = st + (end - st) / 2;
    }
    return st;
}

int solve(vector<int> &v, int target, int st, int end)
{
    int mid = st + (end - st) / 2;

    while (st <= end)
    {

        if (v[mid] == target)
            return mid;

        else if (v[mid] > v[0] && v[mid] > target)
            end = mid - 1;

        else
            st = mid + 1;

        mid = st + (end - st) / 2;
    }
    return -1;
}

int search(vector<int> &v, int target)
{
    int st = 0;
    int end = v.size() - 1;
    int pivot = get_pivot(v);
    if (v[pivot] == target)
        return pivot;
    
    if(v[st]<v[end]) return solve(v,target,st,end);
    if(target>=v[st]&&target<=v[pivot-1]) return solve(v,target,st,pivot-1);
    
    else return solve(v,target,pivot,end);
    
    return -1;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int pivot = get_pivot(v);
    cout << pivot;
    cout << endl;
    cout << search(v, 5);

    return 0;
}