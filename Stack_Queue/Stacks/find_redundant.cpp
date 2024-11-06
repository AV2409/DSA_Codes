#include <bits/stdc++.h>
using namespace std;

bool redundant(string str)
{
    int x = str.length();
    // cout << x;
    stack<char> st;
    for (int i = 0; i < x; i++)
    {

        char ch = str[i];
        if ((ch == '(') || (ch == '+') || (ch == '*') || (ch == '/') || (ch == '-'))
        {
            st.push(ch);
        }
        // stack<char> temp = st;
        // while (!temp.empty())
        // {
        //     cout << temp.top() << endl;
        //     temp.pop();
        // }
        else if (ch == ')')
        {
            int count = 0;
            while (!st.empty() && st.top() != '(')
            {
                count++;
                st.pop();
            }
            st.pop();
            if (count < 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    string str = "(a+c*b)+(c))";
    if (redundant(str))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}