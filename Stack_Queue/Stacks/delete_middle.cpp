#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int n)
{
    int x = n / 2;
    stack<int> temp;
    for (int i = 0; i < x; i++)
    {
        temp.push(st.top());
        st.pop();
    }

    st.pop();
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
    st.push(7);
    st.push(6);
    st.push(5);

    deleteMiddle(st, 3);
    stack<int> temp = st;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    return 0;
}