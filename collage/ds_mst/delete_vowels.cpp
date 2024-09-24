#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1 = "abcdefghigklmnopqrstuvwxyz";
    string s3;

    for (int i = 0; i < s1.length(); i++)
    {
        if ((s1[i] == 'a') || (s1[i] == 'e') || (s1[i] == 'i') || (s1[i] == 'o') || (s1[i] == 'u'))
        {
            continue;
        }

        s3 += s1[i];
    }

    cout << s3;
    return 0;
}