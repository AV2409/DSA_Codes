#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1 = "abcd";
    int i = 0;
    int j = s1.length() - 1;
    while (i < j)
    {
        swap(s1[i++], s1[j--]);
    }
    cout << s1;

    return 0;
}