#include <bits/stdc++.h>
using namespace std;
void RabinKarpMatcher(string &T, string &P, int d, int q)
{
    int n = T.length();
    int m = P.length();
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p = 0;
    int t = 0;

    for (int i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for (int s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            if (T.substr(s, m) == P)
            {
                cout << "Pattern occurs with shift " << s << endl;
            }
        }
        if (s < n - m)
        {
            t = (d * (t - T[s] * h) + T[s + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string T1 = "THIS IS A TEST TEXT";
    string P1 = "TEST";

    string T2 = "AABAACAADAABAABA";
    string P2 = "AABA";
    int d = 256;
    int q = 101;

    RabinKarpMatcher(T1, P1, d, q);
    cout << endl;
    RabinKarpMatcher(T2, P2, d, q);

    return 0;
}
