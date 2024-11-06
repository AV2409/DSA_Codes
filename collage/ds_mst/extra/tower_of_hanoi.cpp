#include <bits/stdc++.h>
using namespace std;

int x = 0;
void toh(int n, char from, char to, char aux)
{
    if (n > 0)
    {
        toh(n - 1, from, aux, to);
        cout << "Moving from " << from << " to " << to << endl;
        x++;
        toh(n - 1, aux, to, from);
    }
}

int main()
{
    int n;
    cin >> n;

    toh(n, 'A', 'C', 'B');
    cout << x;

    return 0;
}