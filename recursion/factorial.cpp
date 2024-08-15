#include <iostream>
using namespace std;

int fact(int n){
    if(n==0||n==1) return 1;
    int ans=n*fact(n-1);
    return ans;
}

int main(){
    int n=5;
    cout<<fact(n)<<endl;
    n=1;
    cout<<fact(n)<<endl;
    n=4;
    cout<<fact(n)<<endl;
    n=3;
    cout<<fact(n)<<endl;
    n=7;
    cout<<fact(n)<<endl;
}