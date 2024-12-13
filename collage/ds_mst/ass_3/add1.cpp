#include <bits/stdc++.h>
using namespace std;

void find(int arr[], int n)
{
    int ans[n];
    stack<int> st;
    ans[0] = -1;
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {

        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    find(arr, n);
    return 0;
}