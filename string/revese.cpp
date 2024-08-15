#include <bits/stdc++.h>
using namespace std;

int getlength(char c[])
{
    int count = 0;
    int i = 0;
    while (c[i++] != '\0')
    {
        count++;
        // i++;
    }
    return count;
}

void rev_string(char c[])
{
    int s = 0;
    int e = getlength(c) - 1;

    while (s <= e)
    {
        swap(c[s], c[e]);
        s++;
        e--;
    }
}
int main()
{
    char s[20];

    cout << "Enter the string: ";

    cin >> s;

    int n = getlength(s);

    rev_string(s);

    cout << endl
         << s;
}
