#include<iostream>
using namespace std;

//bruteforce
// int longest_substr(string s){
//     int maxlen=0;
//     int n=s.length();
//     for(int i=0;i<n;i++){

//         string sub;
//         int len;
        
//         int hash[255]={0};
        
//         for(int j=i;j<n;j++){

//             if(hash[s[j]]==1) break;

//             sub=sub+s[j];
//             len=j-i+1;
//             maxlen=max(maxlen,len);
//             hash[s[j]]=1;
//         }

//     }
//     return maxlen;
    
// }

//optimal

int longest_substr(string s){
    int maxlen=0;
    int n=s.length();
    int l=0;
    int r=0;
    int len=0;
    int hash[255]={0};
    while(r<n){

        while(hash[s[r]]==1){
            hash[s[l]]--;
            l++;
        }

        // if(hash[s[r]]!=1){
        //     if(hash[s[r]]>=l) l=hash[s[r]]+1;
        // }

        // hash[s[r]]=r;

        len=r-l+1;
        maxlen=max(maxlen,len);

        r++;
    }

    return maxlen;
    
    
}
int main(){
    
    string s="cadbzabcd";

    int ans=longest_substr(s);

    cout<<ans;

}