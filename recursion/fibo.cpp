#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return n - 1;

    int nextNum = fibonacci(n - 1) + fibonacci(n - 2);

    return nextNum;
}

int main()
{
    cout << fibonacci(5);
}