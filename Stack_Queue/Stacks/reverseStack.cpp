#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int x)
{
    stack<int> temp;
    while (!st.empty())
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

void reversal(stack<int> &st)
{
    if (st.size() < 2)
        return;
    int temp = st.top();
    st.pop();

    reversal(st);

    insertAtBottom(st, temp);
}
int main()
{
    stack<int> st;
    st.push(8);
    st.push(7);
    st.push(6);
    st.push(5);

    stack<int> temp1 = st;

    while (!temp1.empty())
    {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    reversal(st);
    stack<int> temp = st;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    cout << st.top();
    return 0;

    return 0;
}