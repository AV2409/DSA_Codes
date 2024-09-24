#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1 = "abcdefghigklmnopqrstuvwxyz";
    string s3;

    for (int i = 0; i < s1.length(); i++)
    {
        if ((s1[i] >= 'a') && (s1[i] <= 'z'))
        {
            s1[i] = s1[i] - 'a' + 'A';
        }

        s3 += s1[i];
    }

    cout << s3;
    return 0;
}