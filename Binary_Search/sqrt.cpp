#include <iostream>
using namespace std;

long long int binary_search(int n)
{

    int s = 0;
    int e = n - 1;
    // int arr[n];
    long long int mid = s + (e - s) / 2;
    long long ans = 0;

    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }

        else if (mid * mid > n)
        {
            e = mid - 1;
        }

        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
double precision(int n, int pre, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < pre; i++)
    {
        factor = factor / 10;

        for (double j = tempsol; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
cin>>n;
    int tempsol = binary_search(n);
    cout << precision(n, 4, tempsol);
}