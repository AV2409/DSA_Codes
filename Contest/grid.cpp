#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=3;
    int r=0,c=0;
    vector<string> commands={"DOWN","RIGHT","UP"};

    for(auto i:commands){
        if(i=="RIGHT") c++;

        if(i=="DOWN") r++;

        if(i=="LEFT") c--;

        if(i=="UP") r--;

    }

    cout<<(r*n)+c;

    return 0;

}