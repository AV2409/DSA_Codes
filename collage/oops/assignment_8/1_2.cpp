#include <bits/stdc++.h>
using namespace std;

void divide(float x, float y)
{
    if (y == 0)
    {
        throw y;
    }

    cout << (x / y) << endl;
}

void handler(int x)
{
    if (x == 1)
    {
        throw 1;
    }

    if (x == 2)
    {
        throw 'a';
    }

    if (x == 3)
    {
        throw "hello";
    }

    if (x == 4)
    {
        throw 1.1;
    }
}

int main()
{
    try
    {
        divide(10, 7);
        divide(20, 5);
        divide(30, 0);
        divide(2, 3); // never runs
    }
    catch (float x)
    {
        cout << "Error: Division by zero is not allowed" << endl;
    }

    try
    {
        // handler(1);
        // handler(2);
        // handler(3);
        handler(4);
    }
    catch (int x)
    {
        cout << "Error: " << x << endl;
    }
    catch (char x)
    {
        cout << "Error: " << x << endl;
    }
    catch (const char *x)
    {
        cout << "Error: " << x << endl;
    }
    catch (...)
    {
        cout << "Unexpected Error" << endl;
    }
    cout << "end of program";

    return 0;
}