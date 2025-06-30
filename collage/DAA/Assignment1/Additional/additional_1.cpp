#include <bits/stdc++.h>
using namespace std;
bool isPossible(unsigned long long N, unsigned long long H, unsigned long long W, unsigned long long mid)
{

    unsigned long long rows = mid / H;
    unsigned long long cols = mid / W;
    unsigned long long total = rows * cols;

    return total >= N;
}
int main()
{
    // your code goes here
    unsigned long long T;
    cin >> T;
    unsigned long long N, H, W;

    for (unsigned long long i = 0; i < T; i++)
    {
        cin >> N >> H >> W;
        unsigned long long x = max(H, W);
        unsigned long long low, high, mid, ans;
        low = 1;
        high = N * x;
        mid = low + (high - low) / 2;

        while (low <= high)
        {
            if (isPossible(N, H, W, mid))
            {
                ans = mid;
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        cout << ans << endl;
    }
}
