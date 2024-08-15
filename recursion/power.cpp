#include <iostream>
using namespace std;

long long pow(int n,int p){
    if(p==0) return 1;
    if(p==1) return n;
    long long ans;

    if(p&1) ans=n*pow(n,(p/2))*pow(n,(p/2));
    else ans=pow(n,(p/2))*pow(n,(p/2));
    return ans;
}

int main(){
    
    cout<<pow(2,10)<<endl;
    
}