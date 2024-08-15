#include <iostream>

using namespace std;

void fibonacci(int n)
{
    int a = 0;
    int b = 1;

    if (n == 1)
        cout << a;
    else if (n == 2)
    {
        cout << a << " " << b;
    }

    else if (n > 2)
    {
        cout << a << " " << b << " ";

        for (int i = 2; i < n; i++)
        {
            int nextnum = a + b;

            cout << nextnum << " ";

            a = b;
            b = nextnum;
        }
    }
}
int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << endl;
    cout << "Printing fibonacci: ";

    fibonacci(n);
}