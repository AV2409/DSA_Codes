#include <iostream>
using namespace std;

int pow(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    int ans;

    if(n&1) ans=2*pow((n/2))*pow((n/2));
    else ans=pow((n/2))*pow((n/2));
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<pow(n)<<endl;
    
}