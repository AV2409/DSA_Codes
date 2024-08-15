#include <bits/stdc++.h>
using namespace std;

string replace_space(string &str){

    string temp="";

    int i=0;

    while(str[i]!='\0'){
        if(str[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }

        else{
            temp.push_back(str[i]);
        }
        i++;
    }


    return temp;
}
int main()
{
    // char s[20];
    string st;

    cout << "Enter the string: ";

    getline(cin,st);

    replace_space(st);

    cout<<endl<<st;

    
}