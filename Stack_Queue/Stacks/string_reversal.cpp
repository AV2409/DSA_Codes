#include <bits/stdc++.h>
using namespace std;
string stringReversal(string str)
{
    string rev_str;
    stack<char> st;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        st.push(str[i]);
    }

    while (!st.empty())
    {
        rev_str += st.top();
        st.pop();
    }
    return rev_str;
}
int main()
{
    string str;
    cin >> str;

    cout << "\n"
         << str;
    string rev = stringReversal(str);
    cout << "\n"
         << rev;

    return 0;
}