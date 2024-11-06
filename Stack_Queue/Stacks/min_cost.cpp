#include <bits/stdc++.h>
using namespace std;

int minCost(string str)
{
    int x = str.length();
    if (x % 2)
    {
        return -1;
    }

    stack<char> st;

    for (int i = 0; i < x; i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }

        else if (!st.empty() && ch == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }

    stack<char> temp = st;
    int a = 0;
    int b = 0;
    while (!temp.empty())
    {
        if (temp.top() == '{')
        {
            a++;
        }
        else if (temp.top() == '}')
        {
            b++;
        }
        temp.pop();
    }
    int ans = ((a + 1) / 2) + ((b + 1) / 2);
    return ans;
}

int main()
{
    string str = "{{}}}{";
    cout << minCost(str);

    return 0;
}