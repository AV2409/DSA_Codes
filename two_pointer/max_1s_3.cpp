#include<iostream>
#include<vector>
using namespace std;

//brute-force

/*
int maxSum(vector<int>& nums,int k){
    int n=nums.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int zeros=0;
        int len;
        for(int j=i;j<n;j++){
            if(nums[j]==0) zeros++;

            if(zeros>k) break;

            len=j-i+1;
            maxlen=max(maxlen,len);


        }
    }
    
    
    return maxlen;
}

*/

int maxSum(vector<int>& nums,int k){
    int n=nums.size();
    int maxlen=0;
    int l=0;
    int r=0;
    int zeros=0;
    
    while(r<n){
        if(nums[r]==0) zeros++;

        while(zeros>k){
            if(nums[l]==0) zeros--;
            l++;
        }
        
        int len=r-l+1;
        maxlen=max(maxlen,len);
        r++;

        
    }
    
    
    return maxlen;
}
int main(){
    vector<int> arr={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};

    int ans=maxSum(arr,3);

    cout<<ans;

}