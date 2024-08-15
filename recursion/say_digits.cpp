#include <iostream>
using namespace std;

void say(int n)
{
    string st[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n==0) return;
    int digit=n%10;
    n=n/10;
    
    say(n);
    cout<<st[digit]<<" ";
}



int main()
{
    int n;
    cin>>n;

    say(n);
    cout<<endl;
    
}