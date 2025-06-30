#include <bits/stdc++.h>
using namespace std;
vector<int> computePrefixFunction(const string &P)
{
    int m = P.length();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
        {
            k = pi[k - 1];
        }
        if (P[k] == P[q])
        {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}
void KMPMatcher(const string &T, const string &P)
{
    int n = T.length();
    int m = P.length();
    vector<int> pi = computePrefixFunction(P);
    int q = 0;

    for (int i = 0; i < n; i++)
    {
        while (q > 0 && P[q] != T[i])
        {
            q = pi[q - 1];
        }
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m)
        {
            cout << "Pattern occurs with shift " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}
int main()
{
    string T1 = "THIS IS A TEST TEXT";
    string P1 = "TEST";

    string T2 = "AABAACAADAABAABA";
    string P2 = "AABA";

    KMPMatcher(T1, P1);
    cout << endl;
    KMPMatcher(T2, P2);

    return 0;
}
