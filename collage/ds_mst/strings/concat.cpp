#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1 = "abcd";

    string s2 = "zyx";

    string s3 = "";
    // int k = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        s3 += s1[i];
    }

    for (int i = 0; i < s2.length(); i++)
    {
        s1 += s2[i];
    }

    cout << s1;

    return 0;
}