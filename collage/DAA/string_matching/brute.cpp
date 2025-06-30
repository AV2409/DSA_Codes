#include <bits/stdc++.h>
using namespace std;
void NaiveStringMatcher(string &T, string &P)
{
    int n = T.length();
    int m = P.length();

    for (int s = 0; s <= n - m; ++s)
    {
        int j = 0;
        while (j < m && T[s + j] == P[j])
        {
            ++j;
        }
        if (j == m)
        {
            cout << "Pattern occurs with shift " << s << endl;
        }
    }
}

int main()
{
    string T1 = "THIS IS A TEST TEXT";
    string P1 = "TEST";

    string T2 = "AABAACAADAABAABA";
    string P2 = "AABA";

    NaiveStringMatcher(T1, P1);
    cout << endl;
    NaiveStringMatcher(T2, P2);

    return 0;
}
