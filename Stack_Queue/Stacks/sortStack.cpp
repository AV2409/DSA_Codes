#include <bits/stdc++.h>
using namespace std;
void sort(stack<int> &st)
{
    stack<int> temp;
    stack<int> temp1;

    while (!st.empty())
    {
        int x = st.top();
        while (!temp.empty() && x >= temp.top())
        {
            temp1.push(temp.top());
            temp.pop();
        }

        temp.push(x);

        while (!temp1.empty())
        {
            temp.push(temp1.top());
            temp1.pop();
        }

        st.pop();
    }
    st = temp;
}

void sort_rec(stack<int> &st)
{
    if (st.size() < 2)
        return;

    int x = st.top();
    st.pop();
    sort_rec(st);

    stack<int> temp;
    while (!st.empty() && x >= st.top())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(8);
    st.push(1);
    st.push(6);
    st.push(2);

    stack<int> temp1 = st;

    while (!temp1.empty())
    {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    sort_rec(st);
    stack<int> temp = st;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    cout << st.top();

    return 0;
}