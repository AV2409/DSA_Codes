#include<iostream>
#include<limits.h>
using namespace std;


int bitwiseComplement(int n) {

        int mask=0;
        int m=n;

        while(m!=0){
            m=m>>1;
            mask=mask<<1;
            mask= mask|1;
        }

        int ans=(~n)&mask;
        return ans;
        
    }

int main(){

    cout<<bitwiseComplement(5);

}

