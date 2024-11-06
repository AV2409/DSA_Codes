#include <bits/stdc++.h>
using namespace std;

vector<int> next_smaller(int arr[], int n)
{
    stack<int> st;
    vector<int> arr1(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            arr1[i] = n;
        }

        else
        {
            arr1[i] = st.top();
        }

        st.push(i);
    }

    return arr1;
}

vector<int> prev_smaller(int arr[], int n)
{
    stack<int> st;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            arr1[i] = -1;
        }

        else
        {
            arr1[i] = st.top();
        }

        st.push(i);
    }

    return arr1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> next = next_smaller(arr, n);
    vector<int> prev = prev_smaller(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << next[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << prev[i] << " ";
    }

    int area = 0;
    int temp;
    int ans;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i] * (next[i] - prev[i] - 1);
        cout<<temp<<endl;
        ans = max(area, temp);
    }
    
    cout<<endl<<ans;
    

    return 0;
}
