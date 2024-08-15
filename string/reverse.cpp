#include <bits/stdc++.h>
using namespace std;


int main()
{
    // char s[20];
    string st;

    cout << "Enter the string: ";

    getline(cin,st);

    cout<<endl<<st;

    int word=0;
    vector<string> s;

    for(int i=0;st[i]!='\0';i++){
        if(st[i]==' '){
            word++;
        }

        else{
            s[word].push_back(st[i]);
        }
    }

    // for(string j:s){
    //     cout<<j<<" ";

    // }

    
    
}