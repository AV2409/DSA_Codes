#include <bits/stdc++.h>
using namespace std;

string calculate(string A)
{
    string ans;
    queue<char> q;
    int hash[26] = {0};
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        q.push(A[i]);

        hash[A[i] - 'a']++;

        while (!q.empty() && hash[q.front() - 'a'] > 1)
        {
            hash[q.front() - 'a'];
            q.pop();
        }

        if (q.empty())
        {
            ans += '#';
        }

        else
        {
            ans += q.front();
        }
    }

    return ans;
}

int main()
{
    string s = "blybjrzbbyivawvdesebvusjnijimtzkuzdtfkpkpuyjynzxmapwzvrxpluuzbftozbqedqwtlvvnexfvualb";

    cout << calculate(s);

    return 0;
}