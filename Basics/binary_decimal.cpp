#include <iostream>
#include<math.h>
using namespace std;


int main()
{
    int n=1000000000;
    string st="1111111111111111111111111111";
    int i=0;
    int ans=0;
    int sol=0;

    int j=st.length()-1;
    int k=0;

    while(j>=0){
        if(st[k]=='1'){
            sol=sol+pow(2,j);
        }
        k++;
        j--;
    }

    while(n!=0){
        int bit=n%10;

        if(bit==1){
            ans=ans+pow(2,i);
        }
        n=n/10;

        i++;

    }

    cout<<sol;

}