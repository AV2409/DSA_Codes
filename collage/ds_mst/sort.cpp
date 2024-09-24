#include <iostream>
#include <string.h>
using namespace std;

void bubble_sort(string &s)
{
    int cnt = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            cnt++;
            if (s[j] > s[j + 1])
            {
                flag = false;
                swap(s[j], s[j + 1]);
            }
        }

        if (flag)
        {
            break;
        }
    }
    cout << endl
         << "Number of iterations: " << cnt << endl;
}

int main()
{
    string s1 = "zbjbugkasierh";

    bubble_sort(s1);

    cout << s1;
    return 0;
}
