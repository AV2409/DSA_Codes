#include <iostream>
using namespace std;

void reverse(string& st,int s,int e)
{

    if(s>e) return;

    swap(st[s],st[e]);

    reverse(st, ++s, --e);
}

int main()
{
    string st="NooM";

    cout<<st<<endl;
    reverse(st,0,st.length()-1);
    cout<<st<<endl;
}