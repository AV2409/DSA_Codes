#include <iostream>
using namespace std;

void count1(int n){
    if(n==0) return;
    //tail recursion
    cout<<n<<" ";
    count1(n-1);
    
}

void count2(int n){
    if(n==0) return;
    //head recursion
    count2(n-1);

    cout<<n<<" ";
    
}

int main(){
    int n;
    cin>>n;
    count1(n);
    cout<<endl;

    count2(n);
    
}