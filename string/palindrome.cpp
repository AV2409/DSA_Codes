#include <bits/stdc++.h>
using namespace std;

// void tolowercase(string s)
// {
//     int i = 0;

//     while (s[i] != '\0')
//     {

//         if (s[i] >= 'A' && s[i] <= 'Z')
//         {
//             s[i] = s[i] - 'A' + 'a';
//         }
//         i++;
//     }
// }

int check_char(char c){
    if((c>='a'&&c<='z')||(c>='0'&&c<='9')) return 1;

    return 0;
}

bool check_palindrome(string st)
{
    int start=0;
    int end=st.size()-1;

    while(start<=end){

        if(check_char(st[start])==0){
            start++;
            continue;
        }

        if(check_char(st[end])==0){
            end--;
            continue;
        }
        
        if(st[start]!=st[end]) return false;

        start++;
        end--;
    }


    return true;
}
int main()
{
    // char s[20];
    string st;

    cout << "Enter the string: ";

    cin >> st;

    int i = 0;

    

    while (i<st.size())
    {

        if (st[i] >= 'A' && st[i] <= 'Z')
        {
            st[i] = st[i] - 'A' + 'a';
        }

        

        
        i++;
    }

    cout << endl
         << st;

    cout<<endl<<check_palindrome(st);

    
}