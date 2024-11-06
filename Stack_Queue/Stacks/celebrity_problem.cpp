#include <bits/stdc++.h>
using namespace std;

bool isPossible(int x, vector<vector<int>> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == x)
        {
            continue;
        }

        if ((arr[i][x] != 1) || arr[x][i] != 0)
        {
            return 0;
        }
    }
    return -1;
}

int celebrity(vector<vector<int>> arr)
{
    int n = arr.size();

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (arr[a][b])
        {
            st.push(b);
        }

        else if (arr[b][a])
        {
            st.push(a);
        }
    }

    if (isPossible(st.top(), arr))
    {
        return st.top();
    }

    return -1;
}

int main()
{
    vector<vector<int>> arr = {{0, 1}, {1, 0}};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << celebrity(arr);
    return 0;
}